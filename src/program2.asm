Disassembly Listing for C_compile_test
Generated From:
/home/maciej/MPLABXProjects/C_compile_test.X/dist/default/production/C_compile_test.X.production.elf
2022-09-21 11:49:09

---  /tmp/xcXcGGGcj.s  ----------------------------------------------------------------------------------
017E  0104     MOVLB 0x4
0180  0E08     MOVLW 0x8
0182  6F5D     MOVWF 0x5D, BANKED
0184  0E00     MOVLW 0x0
0186  6F5E     MOVWF 0x5E, BANKED
0188  0E00     MOVLW 0x0
018A  6F5F     MOVWF 0x5F, BANKED
018C  0100     MOVLB 0x0
018E  EFA7     GOTO 0x14E
---  /home/maciej/MPLABXProjects/C_compile_test.X/newmain.c  --------------------------------------------
1:             /* 
2:                 (c) 2020 Microchip Technology Inc. and its subsidiaries.
3:                 Subject to your compliance with these terms, you may use Microchip software and any
4:                 derivatives exclusively with Microchip products. It is your responsibility to comply with third party
5:                 license terms applicable to your use of third party software (including open source software) that
6:                 may accompany Microchip software.
7:                 THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
8:                 EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY
9:                 IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS
10:                FOR A PARTICULAR PURPOSE.
11:                IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
12:                INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
13:                WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP
14:                HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO
15:                THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL
16:                CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT
17:                OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS
18:                SOFTWARE.
19:            */
20:            
21:            #pragma config WDTE = OFF   /* WDT operating mode->WDT Disabled */ 
22:            #pragma config LVP = ON     /* Low voltage programming enabled, RE3 pin is MCLR */ 
23:            
24:            #include <xc.h>
25:            
26:            static void CLK_Initialize(void);
27:            static void PORT_Initialize(void);
28:            static void TMR0_Initialize(void);
29:            static void INTERRUPT_Initialize(void);
30:            static void TMR0_ISR(void);
31:            
32:            static void CLK_Initialize(void)
0192  0E60     MOVLW 0x60
0194  0100     MOVLB 0x0
0196  6FAD     MOVWF OSCCON1, BANKED
33:            {
34:                OSCCON1 = 0x60;    /* set HFINTOSC as new oscillator source */
35:                OSCFRQ = 0x00;     /* set HFFRQ to 1 MHz */
0198  0E00     MOVLW 0x0
019A  6FB1     MOVWF OSCFRQ, BANKED
36:            }
012C  AEA1     BTFSS 0xFA1, 7, ACCESS
012E  EF9B     GOTO 0x136
0130  F000     NOP
0132  EF9D     GOTO 0x13A
0134  F000     NOP
0136  EFA6     GOTO 0x14C
0138  F000     NOP
013A  AEB1     BTFSS 0xFB1, 7, ACCESS
013C  EFA2     GOTO 0x144
013E  F000     NOP
0140  EFA4     GOTO 0x148
0142  F000     NOP
0144  EFA6     GOTO 0x14C
0146  F000     NOP
019C  0012     RETURN 0
37:            
38:            static void PORT_Initialize(void)
01A4  90CA     BCF 0xFCA, 0, ACCESS
39:            {
40:                TRISEbits.TRISE0 = 0;    /* configure RE0 as output */
41:            }
01A6  0012     RETURN 0
42:            
43:            static void TMR0_Initialize(void)
0166  0E94     MOVLW 0x94
0168  0103     MOVLB 0x3
016A  6F1B     MOVWF 0x1B, BANKED
44:            {
45:                T0CON1 = 0x94;        /* Select LFINTOSC, set the prescaler to 1:16, Disable TMR0 sync */
46:                TMR0H = 0xC1;         /* Load the compare value to TMR0H */ 
016C  0EC1     MOVLW 0xC1
016E  6F19     MOVWF 0x19, BANKED
47:                TMR0L = 0x00;         /* Load the reset value to TMR0L */ 
0170  0E00     MOVLW 0x0
0172  6F18     MOVWF 0x18, BANKED
48:                PIR3bits.TMR0IF = 0;  /* clear the interrupt flag */
0174  9EB1     BCF 0xFB1, 7, ACCESS
49:                PIE3bits.TMR0IE = 1;  /* enable TMR0 interrupt */
0176  8EA1     BSF 0xFA1, 7, ACCESS
50:                T0CON0 = 0x80;        /* Configure TMR0 in 8-bit mode and enable TMR0 */
0178  0E80     MOVLW 0x80
017A  6F1A     MOVWF 0x1A, BANKED
51:            }
017C  0012     RETURN 0
52:            
53:            static void INTERRUPT_Initialize (void)
019E  8ED6     BSF 0xFD6, 7, ACCESS
54:            {
55:                INTCON0bits.GIE = 1;   /* Enable the Global Interrupts */
56:                PIE3bits.TMR0IE = 1;  /* Enable the Peripheral Interrupts */
01A0  8EA1     BSF 0xFA1, 7, ACCESS
57:            }
01A2  0012     RETURN 0
58:            
59:            static void TMR0_ISR(void)
0106  9EB1     BCF 0xFB1, 7, ACCESS
60:            {
61:                PIR3bits.TMR0IF = 0;                /* clear the TMR0 interrupt flag */
62:                LATEbits.LATE0 = ~LATEbits.LATE0;   /* toggle LED0 */
0108  B0C2     BTFSC 0xFC2, 0, ACCESS
010A  EF89     GOTO 0x112
010C  F000     NOP
010E  EF8C     GOTO 0x118
0110  F000     NOP
0112  0E01     MOVLW 0x1
0114  EF8D     GOTO 0x11A
0116  F000     NOP
0118  0E00     MOVLW 0x0
011A  0AFF     XORLW 0xFF
011C  6E01     MOVWF 0x1, ACCESS
011E  50C2     MOVF 0xFC2, W, ACCESS
0120  1801     XORWF 0x1, W, ACCESS
0122  0BFE     ANDLW 0xFE
0124  1801     XORWF 0x1, W, ACCESS
0126  6EC2     MOVWF 0xFC2, ACCESS
63:            }
0128  0012     RETURN 0
64:            
65:            void __interrupt(irq(IRQ_TMR0)) INTERRUPT_InterruptManager (void)
66:            {
67:                /* Check if TMR0 interrupt is enabled and if the interrupt flag is set */
68:                if(PIE3bits.TMR0IE == 1 && PIR3bits.TMR0IF == 1)
69:                {
70:                    TMR0_ISR();
0148  EC83     CALL 0x106, 0
014A  F000     NOP
71:                }
72:            }
014C  0011     RETFIE 1
73:            
74:            void main(void) 
014E  ECC9     CALL 0x192, 0
0150  F000     NOP
75:            {   
76:                CLK_Initialize();
77:                PORT_Initialize();
0152  ECD2     CALL 0x1A4, 0
0154  F000     NOP
78:                TMR0_Initialize();
0156  ECB3     CALL 0x166, 0
0158  F000     NOP
79:                INTERRUPT_Initialize();
015A  ECCF     CALL 0x19E, 0
015C  F000     NOP
80:                
81:                while(1)
015E  EFAF     GOTO 0x15E
82:                {
83:                    ;
84:                }
85:            }
86:            

