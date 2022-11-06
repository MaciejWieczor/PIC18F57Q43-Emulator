Disassembly Listing for C_compile_test
Generated From:
/home/maciej/MPLABXProjects/C_compile_test.X/dist/default/production/C_compile_test.X.production.elf
2022-11-06 13:45:45

---  /tmp/xcXniAclD.s  ----------------------------------------------------------------------------------
0296  EE01     LFSR 0, 0x501
029A  0E15     MOVLW 0x15
029C  6AEE     CLRF 0xFEE, ACCESS
029E  06E8     DECF 0xFE8, F, ACCESS
02A0  E1FD     BNZ 0x29C
02A2  0104     MOVLB 0x4
02A4  0E08     MOVLW 0x8
02A6  6F5D     MOVWF 0x5D, BANKED
02A8  0E00     MOVLW 0x0
02AA  6F5E     MOVWF 0x5E, BANKED
02AC  0E00     MOVLW 0x0
02AE  6F5F     MOVWF 0x5F, BANKED
02B0  0100     MOVLB 0x0
02B2  EFCA     GOTO 0x194
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
031E  0012     RETURN 0
40:            {
41:                
42:            }
0274  AEA1     BTFSS 0xFA1, 7, ACCESS
0276  EF3F     GOTO 0x27E
0278  F001     NOP
027A  EF41     GOTO 0x282
027C  F001     NOP
027E  EF4A     GOTO 0x294
0280  F001     NOP
0282  AEB1     BTFSS 0xFB1, 7, ACCESS
0284  EF46     GOTO 0x28C
0286  F001     NOP
0288  EF48     GOTO 0x290
028A  F001     NOP
028C  EF4A     GOTO 0x294
028E  F001     NOP
43:            
44:            static void CLK_Initialize(void)
030C  0E60     MOVLW 0x60
030E  0100     MOVLB 0x0
0310  6FAD     MOVWF OSCCON1, BANKED
45:            {
46:                OSCCON1 = 0x60;    /* set HFINTOSC as new oscillator source */
47:                OSCFRQ = 0x00;     /* set HFFRQ to 1 MHz */
0312  0E00     MOVLW 0x0
0314  6FB1     MOVWF OSCFRQ, BANKED
48:            }
0316  0012     RETURN 0
49:            
50:            static void PORT_Initialize(void)
0318  90CA     BCF 0xFCA, 0, ACCESS
51:            {
52:                TRISEbits.TRISE0 = 0;    /* configure RE0 as output */
53:            }
031A  0012     RETURN 0
54:            
55:            static void UART_Initialize(void)
031C  0012     RETURN 0
56:            {
57:                
58:            }
59:            
60:            static void TMR0_Initialize(void)
02D2  0E40     MOVLW 0x40
02D4  0103     MOVLB 0x3
02D6  6F1B     MOVWF 0x1B, BANKED
61:            {
62:                T0CON1 = 0x40;        /* Select Fosc/4, set the prescaler to 1:1, Enable TMR0 sync */
63:                /* The period is 1ms - with Fosc/4 = 250kHz thsi means 250 ticks in 8 bit mode*/
64:                TMR0H = 0xFA;         /* Load the compare value to TMR0H */ 
02D8  0EFA     MOVLW 0xFA
02DA  6F19     MOVWF 0x19, BANKED
65:                TMR0L = 0x00;         /* Load the reset value to TMR0L */ 
02DC  0E00     MOVLW 0x0
02DE  6F18     MOVWF 0x18, BANKED
66:                PIR3bits.TMR0IF = 0;  /* clear the interrupt flag */
02E0  9EB1     BCF 0xFB1, 7, ACCESS
67:                PIE3bits.TMR0IE = 1;  /* enable TMR0 interrupt */
02E2  8EA1     BSF 0xFA1, 7, ACCESS
68:                T0CON0 = 0x80;        /* Configure TMR0 in 8-bit mode and enable TMR0 */
02E4  0E80     MOVLW 0x80
02E6  6F1A     MOVWF 0x1A, BANKED
69:            }
02E8  0012     RETURN 0
70:            
71:            static void TMR1_Initialize(void)
02EA  0E01     MOVLW 0x1
02EC  0103     MOVLB 0x3
02EE  6F1E     MOVWF 0x1E, BANKED
72:            {
73:                T1CON = 0x01;       /* ON bit set to enable timer */
74:                T1CLK = 0x0A;       /* Clk source is T0 output */
02F0  0E0A     MOVLW 0xA
02F2  6F21     MOVWF 0x21, BANKED
75:                TMR1H = 0xFF; /* Overflow after 10 impulses */
02F4  691D     SETF 0x1D, BANKED
76:                TMR1L = 0xFF - 0x0A;
02F6  0EF5     MOVLW 0xF5
02F8  6F1C     MOVWF 0x1C, BANKED
77:            }
02FA  0012     RETURN 0
78:            
79:            static void ADC_Initialize(void)
02B6  0103     MOVLB 0x3
02B8  51F3     MOVF DMAnSCNTH, W, BANKED
02BA  0BF3     ANDLW 0xF3
02BC  0904     IORLW 0x4
02BE  6FF3     MOVWF DMAnSCNTH, BANKED
80:            {
81:                 //Setup ADC
82:                ADCON0bits.FM = 1; //right justify
83:                ADCON0bits.CS = 1; //ADCRC Clock
02C0  89F3     BSF DMAnSCNTH, 4, BANKED
84:                ADPCH = 0x00; //RA0 is Analog channel
02C2  0E00     MOVLW 0x0
02C4  6FEC     MOVWF DMAnDPTR, BANKED
85:                TRISAbits.TRISA0 = 1; //Set RA0 to input
02C6  80C6     BSF 0xFC6, 0, ACCESS
86:                ANSELAbits.ANSELA0 = 1; //Set RA0 to analog
02C8  0104     MOVLB 0x4
02CA  8100     BSF 0x0, 0, BANKED
87:                ADCON0bits.ON = 1; //Turn ADC On
02CC  0103     MOVLB 0x3
02CE  8FF3     BSF DMAnSCNTH, 7, BANKED
88:            }
0250  A8A1     BTFSS 0xFA1, 4, ACCESS
0252  EF2D     GOTO 0x25A
0254  F001     NOP
0256  EF2F     GOTO 0x25E
0258  F001     NOP
025A  EF38     GOTO 0x270
025C  F001     NOP
025E  A8B1     BTFSS 0xFB1, 4, ACCESS
0260  EF34     GOTO 0x268
0262  F001     NOP
0264  EF36     GOTO 0x26C
0266  F001     NOP
0268  EF38     GOTO 0x270
026A  F001     NOP
02D0  0012     RETURN 0
89:            
90:            static void INTERRUPT_Initialize (void)
02FC  8AD6     BSF 0xFD6, 5, ACCESS
91:            {
92:                INTCON0bits.IPEN = 1;    /* Set high/low priority levels for timer interrupts */
93:                IPR3bits.TMR0IP = 0;     /* TMR0 has lower priority */
02FE  0103     MOVLB 0x3
0300  9F65     BCF PMD5, 7, BANKED
94:                IPR3bits.TMR1IP = 1;     /* TMR1 has higher priority */
0302  8965     BSF PMD5, 4, BANKED
95:                INTCON0bits.GIE = 1;     /* Enable the Global Interrupts */
0304  8ED6     BSF 0xFD6, 7, ACCESS
96:                PIE3bits.TMR0IE = 1;     /* Enable the Peripheral Interrupts */
0306  8EA1     BSF 0xFA1, 7, ACCESS
97:                PIE3bits.TMR1IE = 1;     /* Enable TMR1 PI */
0308  88A1     BSF 0xFA1, 4, ACCESS
98:            }
030A  0012     RETURN 0
99:            
100:           static void TMR0_ISR(void)
0106  9EB1     BCF 0xFB1, 7, ACCESS
101:           {
102:               PIR3bits.TMR0IF = 0;                /* clear the TMR0 interrupt flag */
103:               LATEbits.LATE0 = ~LATEbits.LATE0;   /* toggle LED0 */
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
011C  6E18     MOVWF 0x18, ACCESS
011E  50C2     MOVF 0xFC2, W, ACCESS
0120  1818     XORWF 0x18, W, ACCESS
0122  0BFE     ANDLW 0xFE
0124  1818     XORWF 0x18, W, ACCESS
0126  6EC2     MOVWF 0xFC2, ACCESS
104:               if(buffer_index < 10) {
0128  0E0A     MOVLW 0xA
012A  6015     CPFSLT 0x15, ACCESS
012C  EF9A     GOTO 0x134
012E  F000     NOP
0130  EF9C     GOTO 0x138
0132  F000     NOP
0134  EFC9     GOTO 0x192
0136  F000     NOP
105:                   ADCON0bits.GO = 1; //Start conversion
0138  0103     MOVLB 0x3
013A  81F3     BSF DMAnSCNTH, 0, BANKED
106:                   while (ADCON0bits.GO); //Wait for conversion done
013C  B1F3     BTFSC DMAnSCNTH, 0, BANKED
013E  EFA3     GOTO 0x146
0140  F000     NOP
0142  EFA5     GOTO 0x14A
0144  F000     NOP
0146  EF9E     GOTO 0x13C
0148  F000     NOP
107:                   adc_buffer[buffer_index] += ADRESH;
014A  5015     MOVF 0x15, W, ACCESS
014C  0D02     MULLW 0x2
014E  0E01     MOVLW 0x1
0150  24F3     ADDWF 0xFF3, W, ACCESS
0152  6ED9     MOVWF 0xFD9, ACCESS
0154  0E05     MOVLW 0x5
0156  20F4     ADDWFC 0xFF4, W, ACCESS
0158  6EDA     MOVWF 0xFDA, ACCESS
015A  51EB     MOVF DMAnDCNTH, W, BANKED
015C  26DE     ADDWF 0xFDE, F, ACCESS
015E  0E00     MOVLW 0x0
0160  22DD     ADDWFC 0xFDD, F, ACCESS
108:                   adc_buffer[buffer_index] *= 256;
0162  5015     MOVF 0x15, W, ACCESS
0164  0D02     MULLW 0x2
0166  0E01     MOVLW 0x1
0168  24F3     ADDWF 0xFF3, W, ACCESS
016A  6ED9     MOVWF 0xFD9, ACCESS
016C  0E05     MOVLW 0x5
016E  20F4     ADDWFC 0xFF4, W, ACCESS
0170  6EDA     MOVWF 0xFDA, ACCESS
0172  50DE     MOVF 0xFDE, W, ACCESS
0174  6EDD     MOVWF 0xFDD, ACCESS
0176  6ADF     CLRF 0xFDF, ACCESS
109:                   adc_buffer[buffer_index] += ADRESL;
0178  5015     MOVF 0x15, W, ACCESS
017A  0D02     MULLW 0x2
017C  0E01     MOVLW 0x1
017E  24F3     ADDWF 0xFF3, W, ACCESS
0180  6ED9     MOVWF 0xFD9, ACCESS
0182  0E05     MOVLW 0x5
0184  20F4     ADDWFC 0xFF4, W, ACCESS
0186  6EDA     MOVWF 0xFDA, ACCESS
0188  51EA     MOVF DMAnDCNT, W, BANKED
018A  26DE     ADDWF 0xFDE, F, ACCESS
018C  0E00     MOVLW 0x0
018E  22DD     ADDWFC 0xFDD, F, ACCESS
110:                   buffer_index++; //Increment buffer index
0190  2A15     INCF 0x15, F, ACCESS
111:               }
112:           }
0192  0012     RETURN 0
113:           
114:           static void TMR1_ISR(void)
01FE  98B1     BCF 0xFB1, 4, ACCESS
115:           {
116:               PIR3bits.TMR1IF = 0;                /* clear the TMR0 interrupt flag */
117:               
118:               UART_SEND();
0200  EC8F     CALL 0x31E, 0
0202  F001     NOP
119:               
120:               TMR1H = 0xFF; /* Overflow after 10 impulses */
0204  0103     MOVLB 0x3
0206  691D     SETF 0x1D, BANKED
121:               TMR1L = 0xFF - 0x0A;
0208  0EF5     MOVLW 0xF5
020A  6F1C     MOVWF 0x1C, BANKED
122:                   for(int i= 0 ; i < 10 ; i++){
020C  0E00     MOVLW 0x0
020E  6E17     MOVWF 0x17, ACCESS
0210  0E00     MOVLW 0x0
0212  6E16     MOVWF 0x16, ACCESS
123:                       adc_buffer[i] = 0;
0214  90D8     BCF 0xFD8, 0, ACCESS
0216  3416     RLCF 0x16, W, ACCESS
0218  6ED9     MOVWF 0xFD9, ACCESS
021A  3417     RLCF 0x17, W, ACCESS
021C  6EDA     MOVWF 0xFDA, ACCESS
021E  0E01     MOVLW 0x1
0220  26D9     ADDWF 0xFD9, F, ACCESS
0222  0E05     MOVLW 0x5
0224  22DA     ADDWFC 0xFDA, F, ACCESS
0226  0E00     MOVLW 0x0
0228  6EDE     MOVWF 0xFDE, ACCESS
022A  0E00     MOVLW 0x0
022C  6EDD     MOVWF 0xFDD, ACCESS
124:               }
022E  4A16     INFSNZ 0x16, F, ACCESS
0230  2A17     INCF 0x17, F, ACCESS
0232  BE17     BTFSC 0x17, 7, ACCESS
0234  EF25     GOTO 0x24A
0236  F001     NOP
0238  5017     MOVF 0x17, W, ACCESS
023A  E109     BNZ 0x24E
023C  0E0A     MOVLW 0xA
023E  5C16     SUBWF 0x16, W, ACCESS
0240  A0D8     BTFSS 0xFD8, 0, ACCESS
0242  EF25     GOTO 0x24A
0244  F001     NOP
0246  EF27     GOTO 0x24E
0248  F001     NOP
024A  EF0A     GOTO 0x214
024C  F001     NOP
125:           }
024E  0012     RETURN 0
126:           
127:           void __interrupt(irq(IRQ_TMR1)) INTERRUPT_InterruptManager_TMR1 (void)
128:           {
129:               /* Check if TMR0 interrupt is enabled and if the interrupt flag is set */
130:               if(PIE3bits.TMR1IE == 1 && PIR3bits.TMR1IF == 1)
131:               {
132:                   TMR1_ISR();
026C  ECFF     CALL 0x1FE, 0
026E  F000     NOP
133:               }
134:           }
0270  0011     RETFIE 1
135:           
136:           void __interrupt(irq(IRQ_TMR0)) INTERRUPT_InterruptManager_TMR0 (void)
137:           {
138:               /* Check if TMR0 interrupt is enabled and if the interrupt flag is set */
139:               if(PIE3bits.TMR0IE == 1 && PIR3bits.TMR0IF == 1)
140:               {
141:                   TMR0_ISR();
0290  EC83     CALL 0x106, 0
0292  F000     NOP
142:               }
143:           }
0294  0011     RETFIE 1
144:           
145:           void main(void) 
0194  0E00     MOVLW 0x0
0196  6E1A     MOVWF 0x1A, ACCESS
0198  0E00     MOVLW 0x0
019A  6E19     MOVWF 0x19, ACCESS
146:           {   
147:               for(int i= 0 ; i < 10 ; i++){
148:                   adc_buffer[i] = 0;
019C  90D8     BCF 0xFD8, 0, ACCESS
019E  3419     RLCF 0x19, W, ACCESS
01A0  6ED9     MOVWF 0xFD9, ACCESS
01A2  341A     RLCF 0x1A, W, ACCESS
01A4  6EDA     MOVWF 0xFDA, ACCESS
01A6  0E01     MOVLW 0x1
01A8  26D9     ADDWF 0xFD9, F, ACCESS
01AA  0E05     MOVLW 0x5
01AC  22DA     ADDWFC 0xFDA, F, ACCESS
01AE  0E00     MOVLW 0x0
01B0  6EDE     MOVWF 0xFDE, ACCESS
01B2  0E00     MOVLW 0x0
01B4  6EDD     MOVWF 0xFDD, ACCESS
149:               }
01B6  4A19     INFSNZ 0x19, F, ACCESS
01B8  2A1A     INCF 0x1A, F, ACCESS
01BA  BE1A     BTFSC 0x1A, 7, ACCESS
01BC  EFE9     GOTO 0x1D2
01BE  F000     NOP
01C0  501A     MOVF 0x1A, W, ACCESS
01C2  E109     BNZ 0x1D6
01C4  0E0A     MOVLW 0xA
01C6  5C19     SUBWF 0x19, W, ACCESS
01C8  A0D8     BTFSS 0xFD8, 0, ACCESS
01CA  EFE9     GOTO 0x1D2
01CC  F000     NOP
01CE  EFEB     GOTO 0x1D6
01D0  F000     NOP
01D2  EFCE     GOTO 0x19C
01D4  F000     NOP
150:               
151:               UART_Initialize();
01D6  EC8E     CALL 0x31C, 0
01D8  F001     NOP
152:               CLK_Initialize();
01DA  EC86     CALL 0x30C, 0
01DC  F001     NOP
153:               PORT_Initialize();
01DE  EC8C     CALL 0x318, 0
01E0  F001     NOP
154:               TMR0_Initialize();
01E2  EC69     CALL 0x2D2, 0
01E4  F001     NOP
155:               TMR1_Initialize();
01E6  EC75     CALL 0x2EA, 0
01E8  F001     NOP
156:               ADC_Initialize();
01EA  EC5B     CALL 0x2B6, 0
01EC  F001     NOP
157:               INTERRUPT_Initialize();
01EE  EC7E     CALL 0x2FC, 0
01F0  F001     NOP
158:               
159:               buffer_index = 0;
01F2  0E00     MOVLW 0x0
01F4  6E15     MOVWF 0x15, ACCESS
160:               
161:               while(1)
01F6  EFFB     GOTO 0x1F6
162:               {
163:                   ;
164:               }
165:           }
166:           
