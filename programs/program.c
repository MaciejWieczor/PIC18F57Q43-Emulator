/* 
    (c) 2020 Microchip Technology Inc. and its subsidiaries.
    Subject to your compliance with these terms, you may use Microchip software and any
    derivatives exclusively with Microchip products. It is your responsibility to comply with third party
    license terms applicable to your use of third party software (including open source software) that
    may accompany Microchip software.
    THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
    EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
    IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
    FOR A PARTICULAR PURPOSE.
    IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
    INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
    WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
    HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
    THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
    CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
    OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
    SOFTWARE.
*/

#pragma config WDTE = OFF   /* WDT operating mode->WDT Disabled */ 
#pragma config LVP = ON     /* Low voltage programming enabled, RE3 pin is MCLR */ 

#include <xc.h>

static void CLK_Initialize(void);
static void PORT_Initialize(void);
static void TMR0_Initialize(void);
static void TMR1_Initialize(void);
static void ADC_Initialize(void);
static void INTERRUPT_Initialize(void);
static void TMR0_ISR(void);
static void UART_Initialize(void);
static void UART_SEND(void);

unsigned short adc_buffer[10];
unsigned char buffer_index;

static void UART_SEND(void) 
{
    unsigned short tmp;
    U1TXB += (adc_buffer[0] & 0xFF00) >> 8;  /* Send high byte */
    while(!U1TXIF) {} /* Wait for the first byte to get put into TSR */
    U1TXB += adc_buffer[0] & 0x00FF; /* Send low byte */
    
    for(int i = 1 ; i < 10 ; i++) {
        tmp = 0;
        tmp += adc_buffer[i];
        while(!U1TXIF) {} /* Wait for the last byte to get put into TSR */
        adc_buffer[i] /= 256; /* Send high byte */
        U1TXB += adc_buffer[i] & 0x00FF; /* Send low byte */
        while(!U1TXIF) {} /* Wait for the buffor to be emptied */
        U1TXB += tmp & 0x00FF; /* Send low byte */
    }
}

static void CLK_Initialize(void)
{
    OSCCON1 = 0x60;    /* set HFINTOSC as new oscillator source */
    OSCFRQ = 0x00;     /* set HFFRQ to 1 MHz */
}

static void PORT_Initialize(void)
{
    TRISCbits.TRISC0 = 0;    /* configure RC0 as output (uart tx)*/
    TRISAbits.TRISA0 = 1;    /* configure RA0 as input (adc read)*/
    ANSELAbits.ANSELA0 = 1;  /* Set RA0 to analog for adc read*/
    
    /* Unlock PPS to set the pin for UART */
    INTCON0bits.GIE = 0; //Suspend interrupts
    PPSLOCK = 0x55; //Required sequence
    PPSLOCK = 0xAA; //Required sequence
    PPSLOCKbits.PPSLOCKED = 0; //Clear PPSLOCKED bit
    INTCON0bits.GIE = 1; //Restore interrupts
    
    /* We set PORTC[0] pin as the transmitter pin */
    RC0PPS = 0x20;
    
    /* Lock PPS after setting the pin */
    INTCON0bits.GIE = 0; //Suspend interrupts
    PPSLOCK = 0x55; //Required sequence
    PPSLOCK = 0xAA; //Required sequence
    PPSLOCKbits.PPSLOCKED = 1; //Set PPSLOCKED bit
    INTCON0bits.GIE = 1; //Restore interrupts
}

static void UART_Initialize(void)
{
    U1CON0 = 0x20; /* Set Baud rate to normal, disable autodetect, enable transmitter, 8bit async mode */
    U1BRG = 0x0D;  /* Set baud to 4800 */
    U1CON1 = 0x80; /* Turn UART ON */
}

static void TMR0_Initialize(void)
{
    T0CON1 = 0x40;        /* Select Fosc/4, set the prescaler to 1:1, Enable TMR0 sync */
    /* The period is 1ms - with Fosc/4 = 250kHz thsi means 250 ticks in 8 bit mode*/
    TMR0H = 0xFA;         /* Load the compare value to TMR0H */ 
    TMR0L = 0x00;         /* Load the reset value to TMR0L */ 
    PIR3bits.TMR0IF = 0;  /* clear the interrupt flag */
    PIE3bits.TMR0IE = 1;  /* enable TMR0 interrupt */
    T0CON0 = 0x80;        /* Configure TMR0 in 8-bit mode and enable TMR0 */
}

static void TMR1_Initialize(void)
{
    T1CON = 0x01;       /* ON bit set to enable timer */
    T1CLK = 0x0A;       /* Clk source is T0 output */
    TMR1H = 0xFF; /* Overflow after 10 impulses */
    TMR1L = 0xFF - 0x05;
}

static void ADC_Initialize(void)
{
     //Setup ADC
    ADCON0bits.FM = 1; //right justify
    ADCON0bits.CS = 1; //ADCRC Clock
    ADACQ = 0x0A;
    ADPRE = 0x0A;
    ADPCH = 0x00; //RA0 is Analog channel
    ADCON0bits.ON = 1; //Turn ADC On
}

static void INTERRUPT_Initialize (void)
{
    INTCON0bits.IPEN = 1;    /* Set high/low priority levels for timer interrupts */
    IPR3bits.TMR0IP = 0;     /* TMR0 has lower priority */
    IPR3bits.TMR1IP = 1;     /* TMR1 has higher priority */
    INTCON0bits.GIE = 1;     /* Enable the Global Interrupts */
    PIE3bits.TMR0IE = 1;     /* Enable the Peripheral Interrupts */
    PIE3bits.TMR1IE = 1;     /* Enable TMR1 PI */
}

static void TMR0_ISR(void)
{
    PIR3bits.TMR0IF = 0;                /* clear the TMR0 interrupt flag */
    if(buffer_index < 10) {
        ADCON0bits.GO = 1; //Start conversion
        while (ADCON0bits.GO); //Wait for conversion done
        adc_buffer[buffer_index] += ADRESH;
        adc_buffer[buffer_index] *= 256;
        adc_buffer[buffer_index] += ADRESL;
        buffer_index++; //Increment buffer index
    }
}

static void TMR1_ISR(void)
{
    PIR3bits.TMR1IF = 0;                /* clear the TMR0 interrupt flag */
    T0CON0 = 0x00;        /* Stop TMR0 */
    
    UART_SEND();
    
    T0CON0 = 0x80;        /* Start TMR0 again */
    
    TMR1H = 0xFF; /* Overflow after 10 impulses */
    TMR1L = 0xFF - 0x05;
        for(int i= 0 ; i < 10 ; i++){
            adc_buffer[i] = 0;
    }
}

void __interrupt(irq(IRQ_TMR1)) INTERRUPT_InterruptManager_TMR1 (void)
{
    /* Check if TMR0 interrupt is enabled and if the interrupt flag is set */
    if(PIE3bits.TMR1IE == 1 && PIR3bits.TMR1IF == 1)
    {
        TMR1_ISR();
    }
}

void __interrupt(irq(IRQ_TMR0)) INTERRUPT_InterruptManager_TMR0 (void)
{
    /* Check if TMR0 interrupt is enabled and if the interrupt flag is set */
    if(PIE3bits.TMR0IE == 1 && PIR3bits.TMR0IF == 1)
    {
        TMR0_ISR();
    }
}

void main(void) 
{   
    for(int i= 0 ; i < 10 ; i++){
        adc_buffer[i] = 0;
    }
    
    UART_Initialize();
    CLK_Initialize();
    PORT_Initialize();
    TMR0_Initialize();
    TMR1_Initialize();
    ADC_Initialize();
    INTERRUPT_Initialize();
    
    buffer_index = 0;
    
    while(1)
    {
        ;
    }
}
