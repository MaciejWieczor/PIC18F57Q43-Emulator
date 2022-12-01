Disassembly Listing for C_compile_test
Generated From:
/home/maciej/MPLABXProjects/C_compile_test.X/dist/default/production/C_compile_test.X.production.elf
2022-11-28 14:43:51

---  /tmp/xcXdkInHN.s  ----------------------------------------------------------------------------------
038E  EE01     LFSR 0, 0x501
0392  0E15     MOVLW 0x15
0394  6AEE     CLRF 0xFEE, ACCESS
0396  06E8     DECF 0xFE8, F, ACCESS
0398  E1FD     BNZ 0x394
039A  0104     MOVLB 0x4
039C  0E08     MOVLW 0x8
039E  6F5D     MOVWF 0x5D, BANKED
03A0  0E00     MOVLW 0x0
03A2  6F5E     MOVWF 0x5E, BANKED
03A4  0E00     MOVLW 0x0
03A6  6F5F     MOVWF 0x5F, BANKED
03A8  0100     MOVLB 0x0
03AA  EF16     GOTO 0x22C
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
29:            static void TMR1_Initialize(void);
30:            static void ADC_Initialize(void);
31:            static void INTERRUPT_Initialize(void);
32:            static void TMR0_ISR(void);
33:            static void UART_Initialize(void);
34:            static void UART_SEND(void);
35:            
36:            unsigned short adc_buffer[10];
37:            unsigned char buffer_index;
38:            
39:            static void UART_SEND(void) 
0106  5002     MOVF 0x2, W, ACCESS
0108  0102     MOVLB 0x2
010A  27A3     ADDWF 0xA3, F, BANKED
40:            {
41:                unsigned short tmp;
42:                U1TXB += (adc_buffer[0] & 0xFF00) >> 8;  /* Send high byte */
43:                while(!U1TXIF) {} /* Wait for the first byte to get put into TSR */
010C  A2B2     BTFSS 0xFB2, 1, ACCESS
010E  EF8B     GOTO 0x116
0110  F000     NOP
0112  EF8D     GOTO 0x11A
0114  F000     NOP
0116  EF86     GOTO 0x10C
0118  F000     NOP
44:                U1TXB += adc_buffer[0] & 0x00FF; /* Send low byte */
011A  5001     MOVF 0x1, W, ACCESS
011C  0102     MOVLB 0x2
011E  27A3     ADDWF 0xA3, F, BANKED
45:                
46:                for(int i = 1 ; i < 10 ; i++) {
0120  0E00     MOVLW 0x0
0122  6E19     MOVWF 0x19, ACCESS
0124  0E01     MOVLW 0x1
0126  6E18     MOVWF 0x18, ACCESS
47:                    tmp = 0;
0128  0E00     MOVLW 0x0
012A  6E17     MOVWF 0x17, ACCESS
012C  0E00     MOVLW 0x0
012E  6E16     MOVWF 0x16, ACCESS
48:                    tmp += adc_buffer[i];
0130  90D8     BCF 0xFD8, 0, ACCESS
0132  3418     RLCF 0x18, W, ACCESS
0134  6ED9     MOVWF 0xFD9, ACCESS
0136  3419     RLCF 0x19, W, ACCESS
0138  6EDA     MOVWF 0xFDA, ACCESS
013A  0E01     MOVLW 0x1
013C  26D9     ADDWF 0xFD9, F, ACCESS
013E  0E05     MOVLW 0x5
0140  22DA     ADDWFC 0xFDA, F, ACCESS
0142  50DE     MOVF 0xFDE, W, ACCESS
0144  2616     ADDWF 0x16, F, ACCESS
0146  50DD     MOVF 0xFDD, W, ACCESS
0148  2217     ADDWFC 0x17, F, ACCESS
49:                    while(!U1TXIF) {} /* Wait for the last byte to get put into TSR */
014A  A2B2     BTFSS 0xFB2, 1, ACCESS
014C  EFAA     GOTO 0x154
014E  F000     NOP
0150  EFAC     GOTO 0x158
0152  F000     NOP
0154  EFA5     GOTO 0x14A
0156  F000     NOP
50:                    adc_buffer[i] /= 256; /* Send high byte */
0158  90D8     BCF 0xFD8, 0, ACCESS
015A  3418     RLCF 0x18, W, ACCESS
015C  6ED9     MOVWF 0xFD9, ACCESS
015E  3419     RLCF 0x19, W, ACCESS
0160  6EDA     MOVWF 0xFDA, ACCESS
0162  0E01     MOVLW 0x1
0164  26D9     ADDWF 0xFD9, F, ACCESS
0166  0E05     MOVLW 0x5
0168  22DA     ADDWFC 0xFDA, F, ACCESS
016A  50DC     MOVF 0xFDC, W, ACCESS
016C  6ADD     CLRF 0xFDD, ACCESS
016E  6EDF     MOVWF 0xFDF, ACCESS
51:                    U1TXB += adc_buffer[i] & 0x00FF; /* Send low byte */
0170  90D8     BCF 0xFD8, 0, ACCESS
0172  3418     RLCF 0x18, W, ACCESS
0174  6ED9     MOVWF 0xFD9, ACCESS
0176  3419     RLCF 0x19, W, ACCESS
0178  6EDA     MOVWF 0xFDA, ACCESS
017A  0E01     MOVLW 0x1
017C  26D9     ADDWF 0xFD9, F, ACCESS
017E  0E05     MOVLW 0x5
0180  22DA     ADDWFC 0xFDA, F, ACCESS
0182  50DF     MOVF 0xFDF, W, ACCESS
0184  0102     MOVLB 0x2
0186  27A3     ADDWF 0xA3, F, BANKED
52:                    while(!U1TXIF) {} /* Wait for the buffor to be emptied */
0188  A2B2     BTFSS 0xFB2, 1, ACCESS
018A  EFC9     GOTO 0x192
018C  F000     NOP
018E  EFCB     GOTO 0x196
0190  F000     NOP
0192  EFC4     GOTO 0x188
0194  F000     NOP
53:                    U1TXB += tmp & 0x00FF; /* Send low byte */
0196  5016     MOVF 0x16, W, ACCESS
0198  0102     MOVLB 0x2
019A  27A3     ADDWF 0xA3, F, BANKED
54:                }
019C  4A18     INFSNZ 0x18, F, ACCESS
019E  2A19     INCF 0x19, F, ACCESS
01A0  BE19     BTFSC 0x19, 7, ACCESS
01A2  EFDC     GOTO 0x1B8
01A4  F000     NOP
01A6  5019     MOVF 0x19, W, ACCESS
01A8  E109     BNZ 0x1BC
01AA  0E0A     MOVLW 0xA
01AC  5C18     SUBWF 0x18, W, ACCESS
01AE  A0D8     BTFSS 0xFD8, 0, ACCESS
01B0  EFDC     GOTO 0x1B8
01B2  F000     NOP
01B4  EFDE     GOTO 0x1BC
01B6  F000     NOP
01B8  EF94     GOTO 0x128
01BA  F000     NOP
55:            }
01BC  0012     RETURN 0
036C  AEA1     BTFSS 0xFA1, 7, ACCESS
036E  EFBB     GOTO 0x376
0370  F001     NOP
0372  EFBD     GOTO 0x37A
0374  F001     NOP
0376  EFC6     GOTO 0x38C
0378  F001     NOP
037A  AEB1     BTFSS 0xFB1, 7, ACCESS
037C  EFC2     GOTO 0x384
037E  F001     NOP
0380  EFC4     GOTO 0x388
0382  F001     NOP
0384  EFC6     GOTO 0x38C
0386  F001     NOP
56:            
57:            static void CLK_Initialize(void)
03FC  0E60     MOVLW 0x60
03FE  0100     MOVLB 0x0
0400  6FAD     MOVWF OSCCON1, BANKED
58:            {
59:                OSCCON1 = 0x60;    /* set HFINTOSC as new oscillator source */
60:                OSCFRQ = 0x00;     /* set HFFRQ to 1 MHz */
0402  0E00     MOVLW 0x0
0404  6FB1     MOVWF OSCFRQ, BANKED
61:            }
0406  0012     RETURN 0
62:            
63:            static void PORT_Initialize(void)
02F6  90C8     BCF 0xFC8, 0, ACCESS
64:            {
65:                TRISCbits.TRISC0 = 0;    /* configure RC0 as output (uart tx)*/
66:                TRISAbits.TRISA0 = 1;    /* configure RA0 as input (adc read)*/
02F8  80C6     BSF 0xFC6, 0, ACCESS
67:                ANSELAbits.ANSELA0 = 1;  /* Set RA0 to analog for adc read*/
02FA  0104     MOVLB 0x4
02FC  8100     BSF 0x0, 0, BANKED
68:                
69:                /* Unlock PPS to set the pin for UART */
70:                INTCON0bits.GIE = 0; //Suspend interrupts
02FE  9ED6     BCF 0xFD6, 7, ACCESS
71:                PPSLOCK = 0x55; //Required sequence
0300  0E55     MOVLW 0x55
0302  0102     MOVLB 0x2
0304  6F00     MOVWF 0x0, BANKED
72:                PPSLOCK = 0xAA; //Required sequence
0306  0EAA     MOVLW 0xAA
0308  6F00     MOVWF 0x0, BANKED
73:                PPSLOCKbits.PPSLOCKED = 0; //Clear PPSLOCKED bit
030A  9100     BCF 0x0, 0, BANKED
74:                INTCON0bits.GIE = 1; //Restore interrupts
030C  8ED6     BSF 0xFD6, 7, ACCESS
75:                
76:                /* We set PORTC[0] pin as the transmitter pin */
77:                RC0PPS = 0x20;
030E  0E20     MOVLW 0x20
0310  6F11     MOVWF 0x11, BANKED
78:                
79:                /* Lock PPS after setting the pin */
80:                INTCON0bits.GIE = 0; //Suspend interrupts
0312  9ED6     BCF 0xFD6, 7, ACCESS
81:                PPSLOCK = 0x55; //Required sequence
0314  0E55     MOVLW 0x55
0316  6F00     MOVWF 0x0, BANKED
82:                PPSLOCK = 0xAA; //Required sequence
0318  0EAA     MOVLW 0xAA
031A  6F00     MOVWF 0x0, BANKED
83:                PPSLOCKbits.PPSLOCKED = 1; //Set PPSLOCKED bit
031C  8100     BSF 0x0, 0, BANKED
84:                INTCON0bits.GIE = 1; //Restore interrupts
031E  8ED6     BSF 0xFD6, 7, ACCESS
85:            }
0320  0012     RETURN 0
86:            
87:            static void UART_Initialize(void)
03C6  0E20     MOVLW 0x20
03C8  0102     MOVLB 0x2
03CA  6FAB     MOVWF 0xAB, BANKED
88:            {
89:                U1CON0 = 0x20; /* Set Baud rate to normal, disable autodetect, enable transmitter, 8bit async mode */
90:                U1BRG = 0x0D;  /* Set baud to 4800 */
03CC  0E00     MOVLW 0x0
03CE  6FAF     MOVWF OSCCON3, BANKED
03D0  0E0D     MOVLW 0xD
03D2  6FAE     MOVWF OSCCON2, BANKED
91:                U1CON1 = 0x80; /* Turn UART ON */
03D4  0E80     MOVLW 0x80
03D6  6FAC     MOVWF ACTCON, BANKED
92:            }
03D8  0012     RETURN 0
93:            
94:            static void TMR0_Initialize(void)
03AE  0E40     MOVLW 0x40
03B0  0103     MOVLB 0x3
03B2  6F1B     MOVWF 0x1B, BANKED
95:            {
96:                T0CON1 = 0x40;        /* Select Fosc/4, set the prescaler to 1:1, Enable TMR0 sync */
97:                /* The period is 1ms - with Fosc/4 = 250kHz thsi means 250 ticks in 8 bit mode*/
98:                TMR0H = 0xFA;         /* Load the compare value to TMR0H */ 
03B4  0EFA     MOVLW 0xFA
03B6  6F19     MOVWF 0x19, BANKED
99:                TMR0L = 0x00;         /* Load the reset value to TMR0L */ 
03B8  0E00     MOVLW 0x0
03BA  6F18     MOVWF 0x18, BANKED
100:               PIR3bits.TMR0IF = 0;  /* clear the interrupt flag */
03BC  9EB1     BCF 0xFB1, 7, ACCESS
101:               PIE3bits.TMR0IE = 1;  /* enable TMR0 interrupt */
03BE  8EA1     BSF 0xFA1, 7, ACCESS
102:               T0CON0 = 0x80;        /* Configure TMR0 in 8-bit mode and enable TMR0 */
03C0  0E80     MOVLW 0x80
03C2  6F1A     MOVWF 0x1A, BANKED
103:           }
03C4  0012     RETURN 0
104:           
105:           static void TMR1_Initialize(void)
03DA  0E01     MOVLW 0x1
03DC  0103     MOVLB 0x3
03DE  6F1E     MOVWF 0x1E, BANKED
106:           {
107:               T1CON = 0x01;       /* ON bit set to enable timer */
108:               T1CLK = 0x0A;       /* Clk source is T0 output */
03E0  0E0A     MOVLW 0xA
03E2  6F21     MOVWF 0x21, BANKED
109:               TMR1H = 0xFF; /* Overflow after 10 impulses */
03E4  691D     SETF 0x1D, BANKED
110:               TMR1L = 0xFF - 0x05;
03E6  0EFA     MOVLW 0xFA
03E8  6F1C     MOVWF 0x1C, BANKED
111:           }
03EA  0012     RETURN 0
112:           
113:           static void ADC_Initialize(void)
0322  0103     MOVLB 0x3
0324  51F3     MOVF DMAnSCNTH, W, BANKED
0326  0BF3     ANDLW 0xF3
0328  0904     IORLW 0x4
032A  6FF3     MOVWF DMAnSCNTH, BANKED
114:           {
115:                //Setup ADC
116:               ADCON0bits.FM = 1; //right justify
117:               ADCON0bits.CS = 1; //ADCRC Clock
032C  89F3     BSF DMAnSCNTH, 4, BANKED
118:               ADACQ = 0x0A;
032E  0E00     MOVLW 0x0
0330  6FEF     MOVWF DMAnDSZH, BANKED
0332  0E0A     MOVLW 0xA
0334  6FEE     MOVWF DMAnDSZ, BANKED
119:               ADPRE = 0x0A;
0336  0E00     MOVLW 0x0
0338  6FF2     MOVWF DMAnSCNT, BANKED
033A  0E0A     MOVLW 0xA
033C  6FF1     MOVWF DMAnDSAH, BANKED
120:               ADPCH = 0x00; //RA0 is Analog channel
033E  0E00     MOVLW 0x0
0340  6FEC     MOVWF DMAnDPTR, BANKED
121:               ADCON0bits.ON = 1; //Turn ADC On
0342  8FF3     BSF DMAnSCNTH, 7, BANKED
122:           }
0344  0012     RETURN 0
0348  A8A1     BTFSS 0xFA1, 4, ACCESS
034A  EFA9     GOTO 0x352
034C  F001     NOP
034E  EFAB     GOTO 0x356
0350  F001     NOP
0352  EFB4     GOTO 0x368
0354  F001     NOP
0356  A8B1     BTFSS 0xFB1, 4, ACCESS
0358  EFB0     GOTO 0x360
035A  F001     NOP
035C  EFB2     GOTO 0x364
035E  F001     NOP
0360  EFB4     GOTO 0x368
0362  F001     NOP
123:           
124:           static void INTERRUPT_Initialize (void)
03EC  8AD6     BSF 0xFD6, 5, ACCESS
125:           {
126:               INTCON0bits.IPEN = 1;    /* Set high/low priority levels for timer interrupts */
127:               IPR3bits.TMR0IP = 0;     /* TMR0 has lower priority */
03EE  0103     MOVLB 0x3
03F0  9F65     BCF PMD5, 7, BANKED
128:               IPR3bits.TMR1IP = 1;     /* TMR1 has higher priority */
03F2  8965     BSF PMD5, 4, BANKED
129:               INTCON0bits.GIE = 1;     /* Enable the Global Interrupts */
03F4  8ED6     BSF 0xFD6, 7, ACCESS
130:               PIE3bits.TMR0IE = 1;     /* Enable the Peripheral Interrupts */
03F6  8EA1     BSF 0xFA1, 7, ACCESS
131:               PIE3bits.TMR1IE = 1;     /* Enable TMR1 PI */
03F8  88A1     BSF 0xFA1, 4, ACCESS
132:           }
03FA  0012     RETURN 0
133:           
134:           static void TMR0_ISR(void)
01BE  9EB1     BCF 0xFB1, 7, ACCESS
135:           {
136:               PIR3bits.TMR0IF = 0;                /* clear the TMR0 interrupt flag */
137:               if(buffer_index < 10) {
01C0  0E0A     MOVLW 0xA
01C2  6015     CPFSLT 0x15, ACCESS
01C4  EFE6     GOTO 0x1CC
01C6  F000     NOP
01C8  EFE8     GOTO 0x1D0
01CA  F000     NOP
01CC  EF15     GOTO 0x22A
01CE  F001     NOP
138:                   ADCON0bits.GO = 1; //Start conversion
01D0  0103     MOVLB 0x3
01D2  81F3     BSF DMAnSCNTH, 0, BANKED
139:                   while (ADCON0bits.GO); //Wait for conversion done
01D4  B1F3     BTFSC DMAnSCNTH, 0, BANKED
01D6  EFEF     GOTO 0x1DE
01D8  F000     NOP
01DA  EFF1     GOTO 0x1E2
01DC  F000     NOP
01DE  EFEA     GOTO 0x1D4
01E0  F000     NOP
140:                   adc_buffer[buffer_index] += ADRESH;
01E2  5015     MOVF 0x15, W, ACCESS
01E4  0D02     MULLW 0x2
01E6  0E01     MOVLW 0x1
01E8  24F3     ADDWF 0xFF3, W, ACCESS
01EA  6ED9     MOVWF 0xFD9, ACCESS
01EC  0E05     MOVLW 0x5
01EE  20F4     ADDWFC 0xFF4, W, ACCESS
01F0  6EDA     MOVWF 0xFDA, ACCESS
01F2  51EB     MOVF DMAnDCNTH, W, BANKED
01F4  26DE     ADDWF 0xFDE, F, ACCESS
01F6  0E00     MOVLW 0x0
01F8  22DD     ADDWFC 0xFDD, F, ACCESS
141:                   adc_buffer[buffer_index] *= 256;
01FA  5015     MOVF 0x15, W, ACCESS
01FC  0D02     MULLW 0x2
01FE  0E01     MOVLW 0x1
0200  24F3     ADDWF 0xFF3, W, ACCESS
0202  6ED9     MOVWF 0xFD9, ACCESS
0204  0E05     MOVLW 0x5
0206  20F4     ADDWFC 0xFF4, W, ACCESS
0208  6EDA     MOVWF 0xFDA, ACCESS
020A  50DE     MOVF 0xFDE, W, ACCESS
020C  6EDD     MOVWF 0xFDD, ACCESS
020E  6ADF     CLRF 0xFDF, ACCESS
142:                   adc_buffer[buffer_index] += ADRESL;
0210  5015     MOVF 0x15, W, ACCESS
0212  0D02     MULLW 0x2
0214  0E01     MOVLW 0x1
0216  24F3     ADDWF 0xFF3, W, ACCESS
0218  6ED9     MOVWF 0xFD9, ACCESS
021A  0E05     MOVLW 0x5
021C  20F4     ADDWFC 0xFF4, W, ACCESS
021E  6EDA     MOVWF 0xFDA, ACCESS
0220  51EA     MOVF DMAnDCNT, W, BANKED
0222  26DE     ADDWF 0xFDE, F, ACCESS
0224  0E00     MOVLW 0x0
0226  22DD     ADDWFC 0xFDD, F, ACCESS
143:                   buffer_index++; //Increment buffer index
0228  2A15     INCF 0x15, F, ACCESS
144:               }
145:           }
022A  0012     RETURN 0
146:           
147:           static void TMR1_ISR(void)
0296  98B1     BCF 0xFB1, 4, ACCESS
148:           {
149:               PIR3bits.TMR1IF = 0;                /* clear the TMR0 interrupt flag */
150:               T0CON0 = 0x00;        /* Stop TMR0 */
0298  0E00     MOVLW 0x0
029A  0103     MOVLB 0x3
029C  6F1A     MOVWF 0x1A, BANKED
151:               
152:               UART_SEND();
029E  EC83     CALL 0x106, 0
02A0  F000     NOP
153:               
154:               T0CON0 = 0x80;        /* Start TMR0 again */
02A2  0E80     MOVLW 0x80
02A4  0103     MOVLB 0x3
02A6  6F1A     MOVWF 0x1A, BANKED
155:               
156:               TMR1H = 0xFF; /* Overflow after 10 impulses */
02A8  691D     SETF 0x1D, BANKED
157:               TMR1L = 0xFF - 0x05;
02AA  0EFA     MOVLW 0xFA
02AC  6F1C     MOVWF 0x1C, BANKED
158:               for(int i= 0 ; i < 10 ; i++){
02AE  0E00     MOVLW 0x0
02B0  6E1B     MOVWF 0x1B, ACCESS
02B2  0E00     MOVLW 0x0
02B4  6E1A     MOVWF 0x1A, ACCESS
159:                       adc_buffer[i] = 0;
02B6  90D8     BCF 0xFD8, 0, ACCESS
02B8  341A     RLCF 0x1A, W, ACCESS
02BA  6ED9     MOVWF 0xFD9, ACCESS
02BC  341B     RLCF 0x1B, W, ACCESS
02BE  6EDA     MOVWF 0xFDA, ACCESS
02C0  0E01     MOVLW 0x1
02C2  26D9     ADDWF 0xFD9, F, ACCESS
02C4  0E05     MOVLW 0x5
02C6  22DA     ADDWFC 0xFDA, F, ACCESS
02C8  0E00     MOVLW 0x0
02CA  6EDE     MOVWF 0xFDE, ACCESS
02CC  0E00     MOVLW 0x0
02CE  6EDD     MOVWF 0xFDD, ACCESS
160:               }
02D0  4A1A     INFSNZ 0x1A, F, ACCESS
02D2  2A1B     INCF 0x1B, F, ACCESS
02D4  BE1B     BTFSC 0x1B, 7, ACCESS
02D6  EF76     GOTO 0x2EC
02D8  F001     NOP
02DA  501B     MOVF 0x1B, W, ACCESS
02DC  E109     BNZ 0x2F0
02DE  0E0A     MOVLW 0xA
02E0  5C1A     SUBWF 0x1A, W, ACCESS
02E2  A0D8     BTFSS 0xFD8, 0, ACCESS
02E4  EF76     GOTO 0x2EC
02E6  F001     NOP
02E8  EF78     GOTO 0x2F0
02EA  F001     NOP
02EC  EF5B     GOTO 0x2B6
02EE  F001     NOP
161:               buffer_index = 0;
02F0  0E00     MOVLW 0x0
02F2  6E15     MOVWF 0x15, ACCESS
162:           }
02F4  0012     RETURN 0
163:           
164:           void __interrupt(irq(IRQ_TMR1)) INTERRUPT_InterruptManager_TMR1 (void)
165:           {
166:               /* Check if TMR0 interrupt is enabled and if the interrupt flag is set */
167:               if(PIE3bits.TMR1IE == 1 && PIR3bits.TMR1IF == 1)
168:               {
169:                   TMR1_ISR();
0364  EC4B     CALL 0x296, 0
0366  F001     NOP
170:               }
171:           }
0368  0011     RETFIE 1
172:           
173:           void __interrupt(irq(IRQ_TMR0)) INTERRUPT_InterruptManager_TMR0 (void)
174:           {
175:               /* Check if TMR0 interrupt is enabled and if the interrupt flag is set */
176:               if(PIE3bits.TMR0IE == 1 && PIR3bits.TMR0IF == 1)
177:               {
178:                   TMR0_ISR();
0388  ECDF     CALL 0x1BE, 0
038A  F000     NOP
179:               }
180:           }
038C  0011     RETFIE 1
181:           
182:           void main(void) 
022C  0E00     MOVLW 0x0
022E  6E1D     MOVWF 0x1D, ACCESS
0230  0E00     MOVLW 0x0
0232  6E1C     MOVWF 0x1C, ACCESS
183:           {   
184:               for(int i= 0 ; i < 10 ; i++){
185:                   adc_buffer[i] = 0;
0234  90D8     BCF 0xFD8, 0, ACCESS
0236  341C     RLCF 0x1C, W, ACCESS
0238  6ED9     MOVWF 0xFD9, ACCESS
023A  341D     RLCF 0x1D, W, ACCESS
023C  6EDA     MOVWF 0xFDA, ACCESS
023E  0E01     MOVLW 0x1
0240  26D9     ADDWF 0xFD9, F, ACCESS
0242  0E05     MOVLW 0x5
0244  22DA     ADDWFC 0xFDA, F, ACCESS
0246  0E00     MOVLW 0x0
0248  6EDE     MOVWF 0xFDE, ACCESS
024A  0E00     MOVLW 0x0
024C  6EDD     MOVWF 0xFDD, ACCESS
186:               }
024E  4A1C     INFSNZ 0x1C, F, ACCESS
0250  2A1D     INCF 0x1D, F, ACCESS
0252  BE1D     BTFSC 0x1D, 7, ACCESS
0254  EF35     GOTO 0x26A
0256  F001     NOP
0258  501D     MOVF 0x1D, W, ACCESS
025A  E109     BNZ 0x26E
025C  0E0A     MOVLW 0xA
025E  5C1C     SUBWF 0x1C, W, ACCESS
0260  A0D8     BTFSS 0xFD8, 0, ACCESS
0262  EF35     GOTO 0x26A
0264  F001     NOP
0266  EF37     GOTO 0x26E
0268  F001     NOP
026A  EF1A     GOTO 0x234
026C  F001     NOP
187:               
188:               UART_Initialize();
026E  ECE3     CALL 0x3C6, 0
0270  F001     NOP
189:               CLK_Initialize();
0272  ECFE     CALL 0x3FC, 0
0274  F001     NOP
190:               PORT_Initialize();
0276  EC7B     CALL 0x2F6, 0
0278  F001     NOP
191:               TMR0_Initialize();
027A  ECD7     CALL 0x3AE, 0
027C  F001     NOP
192:               TMR1_Initialize();
027E  ECED     CALL 0x3DA, 0
0280  F001     NOP
193:               ADC_Initialize();
0282  EC91     CALL 0x322, 0
0284  F001     NOP
194:               INTERRUPT_Initialize();
0286  ECF6     CALL 0x3EC, 0
0288  F001     NOP
195:               
196:               buffer_index = 0;
028A  0E00     MOVLW 0x0
028C  6E15     MOVWF 0x15, ACCESS
197:               
198:               while(1)
028E  EF47     GOTO 0x28E
199:               {
200:                   ;
201:               }
202:           }
203:           
