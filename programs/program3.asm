Disassembly Listing for pic18f57q43-adc-periodic-sampling-mplab-mcc
Generated From:
/home/maciej/MPLABXProjects/pic18f57q43-adc-periodic-sampling-mplab-mcc.X/dist/pro/production/pic18f57q43-adc-periodic-sampling-mplab-mcc.X.production.elf
2022-10-13 23:40:46

---  /tmp/xcXgAjpDB.s  ----------------------------------------------------------------------------------
3082  EE01     LFSR 0, 0x560
3086  0E47     MOVLW 0x47
3088  6AEE     CLRF 0xFEE, ACCESS
308A  06E8     DECF 0xFE8, F, ACCESS
308C  E1FD     BNZ 0x3088
308E  6A5F     CLRF 0x5F, ACCESS
3090  6A5E     CLRF 0x5E, ACCESS
3092  6A5D     CLRF 0x5D, ACCESS
3094  0104     MOVLB 0x4
3096  0E08     MOVLW 0x8
3098  6F5D     MOVWF 0x5D, BANKED
309A  0E00     MOVLW 0x0
309C  6F5E     MOVWF 0x5E, BANKED
309E  0E00     MOVLW 0x0
30A0  6F5F     MOVWF 0x5F, BANKED
30A2  0100     MOVLB 0x0
30A4  EF13     GOTO 0x3026
---  /opt/microchip/xc8/v2.32/pic/sources/c99/common/strlen.c  ------------------------------------------
1:             #include <string.h>
2:             #include <stdint.h>
3:             #include <limits.h>
4:             
5:             size_t strlen(const char *s)
3054  C501     MOVFF __pcstackCOMRAM, a
3056  F503     NOP
3058  C502     MOVFF txData, 0x504
305A  F504     NOP
6:             {
7:             	const char *a = s;
8:             	while(*s) {
305C  D002     BRA 0x3062
3064  F404     NOP
3066  F4D9     NOP
306A  F408     NOP
306C  F4DA     NOP
306E  50DF     MOVF 0xFDF, W, ACCESS
3070  A4D8     BTFSS 0xFD8, 2, ACCESS
3072  D7F5     BRA 0x305E
9:             		s++;
305E  4A01     INFSNZ 0x1, F, ACCESS
3060  2A02     INCF 0x2, F, ACCESS
10:            	}
11:            	return (size_t)(s-a);
3074  5003     MOVF 0x3, W, ACCESS
3076  5C01     SUBWF 0x1, W, ACCESS
3078  6E01     MOVWF 0x1, ACCESS
307A  5004     MOVF 0x4, W, ACCESS
307C  5802     SUBWFB 0x2, W, ACCESS
307E  6E02     MOVWF 0x2, ACCESS
12:            }
3080  0012     RETURN 0
---  /opt/microchip/xc8/v2.32/pic/sources/c99/common/printf.c  ------------------------------------------
1:             #include <stdio.h>
2:             #include <stdarg.h>
3:             #include "stdio_impl.h"
4:             
5:             int printf(const char *restrict fmt, ...)
30F2  0E59     MOVLW 0x59
30F4  6E5B     MOVWF 0x5B, ACCESS
30F6  0E05     MOVLW 0x5
30F8  6E5C     MOVWF 0x5C, ACCESS
6:             {
7:             	int ret;
8:             	va_list ap;
9:             	va_start(ap, fmt);
10:            	ret = vfprintf(stdout, fmt, ap);
30FA  0E00     MOVLW 0x0
30FC  6E52     MOVWF 0x52, ACCESS
30FE  0E00     MOVLW 0x0
3100  6E53     MOVWF 0x53, ACCESS
3102  C558     MOVFF fmt, fmt
3104  F554     NOP
3106  0E5B     MOVLW 0x5B
3108  6E55     MOVWF 0x55, ACCESS
310A  0E05     MOVLW 0x5
310C  6E56     MOVWF 0x56, ACCESS
310E  EC6D     CALL 0x2EDA, 0
3110  F017     NOP
11:            	va_end(ap);
12:            	return ret;
13:            }
3112  0012     RETURN 0
---  /opt/microchip/xc8/v2.32/pic/sources/c99/common/nf_fputs.c  ----------------------------------------
1:             /* "No file system" fputs */
2:             #include <stdio.h>
3:             
4:             #include "stdio_impl.h"
5:             
6:             #ifdef STDIO_NO_FILE_IO
7:             
8:             int fputs(const char *s, FILE *fp)
2FBC  0E00     MOVLW 0x0
2FBE  6E12     MOVWF 0x12, ACCESS
2FC0  0E00     MOVLW 0x0
2FC2  6E11     MOVWF 0x11, ACCESS
9:             {
10:                char c;
11:                int i;
12:            
13:                i = 0;
14:                while ((c = *(s + i))) {
2FC4  D00B     BRA 0x2FDC
2FDC  5011     MOVF 0x11, W, ACCESS
15:            	fputc(c,fp);
2FC6  C510     MOVFF c, a
2FC8  F503     NOP
2FCA  6A04     CLRF 0x4, ACCESS
2FCC  C50E     MOVFF fp, fp
2FCE  F505     NOP
2FD0  C50F     MOVFF 0x50F, 0x506
2FD2  F506     NOP
2FD4  EC37     CALL 0x2E6E, 0
2FD6  F017     NOP
16:                    ++i;
2FD8  4A11     INFSNZ 0x11, F, ACCESS
2FDA  2A12     INCF 0x12, F, ACCESS
2FDC  5011     MOVF 0x11, W, ACCESS
2FDE  240C     ADDWF 0xC, W, ACCESS
2FE0  6ED9     MOVWF 0xFD9, ACCESS
2FE2  5012     MOVF 0x12, W, ACCESS
2FE4  200D     ADDWFC 0xD, W, ACCESS
2FE6  6EDA     MOVWF 0xFDA, ACCESS
2FE8  50DF     MOVF 0xFDF, W, ACCESS
2FEA  6E10     MOVWF 0x10, ACCESS
2FEC  5010     MOVF 0x10, W, ACCESS
2FEE  B4D8     BTFSC 0xFD8, 2, ACCESS
2FF0  0012     RETURN 0
2FF2  D7E9     BRA 0x2FC6
17:                }
18:                return i;
19:            }
20:            
21:            #endif
---  /opt/microchip/xc8/v2.32/pic/sources/c99/common/nf_fputc.c  ----------------------------------------
1:             #include <stdio.h>
2:             
3:             #include "stdio_impl.h"
4:             
5:             #ifdef STDIO_NO_FILE_IO
6:             /* "No file system" fputc */
7:             
8:             int fputc(int c, FILE *fp)
2E6E  5005     MOVF 0x5, W, ACCESS
2E70  1006     IORWF 0x6, W, ACCESS
2E72  B4D8     BTFSC 0xFD8, 2, ACCESS
2E74  D004     BRA 0x2E7E
2E76  5005     MOVF 0x5, W, ACCESS
2E78  1006     IORWF 0x6, W, ACCESS
2E7A  A4D8     BTFSS 0xFD8, 2, ACCESS
2E7C  D004     BRA 0x2E86
9:             {
10:                extern void putch(char);
11:            
12:                if ((fp == stdout) || (fp == stderr)) {
13:                    putch((char)c);
2E7E  5003     MOVF 0x3, W, ACCESS
2E80  EC03     CALL 0x3206, 0
2E82  F019     NOP
14:                } else {
2E84  0012     RETURN 0
15:            		if((fp->limit == 0) || (fp->count < fp->limit)) {
2E86  EE20     LFSR 2, 0x4
2E88  F004     NOP
2E8A  5005     MOVF 0x5, W, ACCESS
2E8C  26D9     ADDWF 0xFD9, F, ACCESS
2E8E  5006     MOVF 0x6, W, ACCESS
2E90  22DA     ADDWFC 0xFDA, F, ACCESS
2E92  50DE     MOVF 0xFDE, W, ACCESS
2E94  10DE     IORWF 0xFDE, W, ACCESS
2E96  B4D8     BTFSC 0xFD8, 2, ACCESS
2E98  D016     BRA 0x2EC6
2E9A  EE20     LFSR 2, 0x4
2E9C  F004     NOP
2E9E  5005     MOVF 0x5, W, ACCESS
2EA0  26D9     ADDWF 0xFD9, F, ACCESS
2EA2  5006     MOVF 0x6, W, ACCESS
2EA4  22DA     ADDWFC 0xFDA, F, ACCESS
2EA6  EE10     LFSR 1, 0x2
2EA8  F002     NOP
2EAA  5005     MOVF 0x5, W, ACCESS
2EAC  26E1     ADDWF 0xFE1, F, ACCESS
2EAE  5006     MOVF 0x6, W, ACCESS
2EB0  22E2     ADDWFC 0xFE2, F, ACCESS
2EB2  50DE     MOVF 0xFDE, W, ACCESS
2EB4  5CE6     SUBWF 0xFE6, W, ACCESS
2EB6  50E6     MOVF 0xFE6, W, ACCESS
2EB8  0A80     XORLW 0x80
2EBA  6E0B     MOVWF 0xB, ACCESS
2EBC  50DE     MOVF 0xFDE, W, ACCESS
2EBE  0A80     XORLW 0x80
2EC0  580B     SUBWFB 0xB, W, ACCESS
2EC2  B0D8     BTFSC 0xFD8, 0, ACCESS
2EC4  0012     RETURN 0
16:            #pragma warning push
17:            #pragma warning disable 1498
18:            			fp->buffer[fp->count] = (char)c;
19:            #pragma warning pop
20:            			++fp->count;
2EC6  EE20     LFSR 2, 0x2
2EC8  F002     NOP
2ECA  5005     MOVF 0x5, W, ACCESS
2ECC  26D9     ADDWF 0xFD9, F, ACCESS
2ECE  5006     MOVF 0x6, W, ACCESS
2ED0  22DA     ADDWFC 0xFDA, F, ACCESS
2ED2  2ADE     INCF 0xFDE, F, ACCESS
2ED4  0E00     MOVLW 0x0
2ED6  22DD     ADDWFC 0xFDD, F, ACCESS
21:            		}
22:                }
23:                return (unsigned char)c;
24:            }
2ED8  0012     RETURN 0
25:            
26:            #endif
---  /opt/microchip/xc8/v2.32/pic/sources/c99/common/doprnt.c  ------------------------------------------
1:             /* vfprintf with configurable support for format conversions */
2:             /* This code is specifically for XC8 */
3:             #include <ctype.h>
4:             #include <math.h>
5:             #include <stdarg.h>
6:             #include <stddef.h>
7:             #include <stdint.h>
8:             #include <stdio.h>
9:             #include <stdlib.h>
10:            #include <string.h>
11:            #include <inline.h>
12:            
13:            /* Configuration options */
14:            #ifdef _VFPF_ALL
15:            #define _VFPF_CONVERT
16:            #define _VFPF_FLAGS
17:            #define _VFPF_WIDTH
18:            #define _VFPF_PRECISION
19:            
20:            #define _VFPF_HH
21:            #define _VFPF_H
22:            #define _VFPF_L
23:            #define _VFPF_LL
24:            #define _VFPF_J
25:            #define _VFPF_T
26:            #define _VFPF_Z
27:            
28:            #define _VFPF_A
29:            #define _VFPF_C
30:            #define _VFPF_D
31:            #define _VFPF_E
32:            #define _VFPF_F
33:            #define _VFPF_G
34:            #define _VFPF_O
35:            #define _VFPF_N
36:            #define _VFPF_P
37:            #define _VFPF_S
38:            #define _VFPF_U
39:            #define _VFPF_X
40:            #endif
41:            
42:            #ifndef ARRAYSIZE
43:            #define ARRAYSIZE(a)	(sizeof(a)/sizeof(a[0]))
44:            #endif
45:            #ifndef CSTRLEN
46:            #define CSTRLEN(s)	(ARRAYSIZE(s)-1)
47:            #endif
48:            
49:            /* Flags, precision, width */
50:            #define MINUS_FLAG (1 << 0)
51:            #define ZERO_FLAG (1 << 1)
52:            #define PLUS_FLAG (1 << 2)
53:            #define SPACE_FLAG (1 << 3)
54:            #define POUND_FLAG (1 << 4)
55:            static int flags, prec, width;
56:            
57:            #ifdef _VFPF_CONVERT
58:            /* This buffer must be at least 32 bytes long for this code to be safe */
59:            /* Output that would exceed buffer capacity is truncated */
60:            #if defined(_VFPF_A) || defined(_VFPF_E) || defined(_VFPF_F) || defined(_VFPF_G)
61:            #define DBLEN 80
62:            #define EXPLEN 5
63:            #else
64:            #define DBLEN 32
65:            #endif
66:            static char dbuf[DBLEN];
67:            
68:            /* Character count */
69:            static int nout;
70:            
71:            /* Output the string in dbuf, padded on the left or right */
72:            static _INLINE int pad(FILE *fp, char *buf, int p)
2D66  A05D     BTFSS 0x5D, 0, ACCESS
2D68  D00A     BRA 0x2D7E
73:            {
74:                int i, w;
75:            
76:                /* Left justify ? Put out string */
77:                if (flags & MINUS_FLAG) {
78:                    fputs((const char *)buf, fp);
2D6A  C515     MOVFF buf, s
2D6C  F50C     NOP
2D6E  C516     MOVFF 0x516, 0x50D
2D70  F50D     NOP
2D72  C513     MOVFF fp, fp
2D74  F50E     NOP
2D76  C514     MOVFF 0x514, 0x50F
2D78  F50F     NOP
2D7A  ECDE     CALL 0x2FBC, 0
2D7C  F017     NOP
79:                }
80:            
81:                /* Put out padding */
82:                w = (p < 0) ? 0 : p;
2D7E  BE18     BTFSC 0x18, 7, ACCESS
2D80  D005     BRA 0x2D8C
2D82  C517     MOVFF p, w
2D84  F51C     NOP
2D86  C518     MOVFF 0x518, 0x51D
2D88  F51D     NOP
2D8A  D004     BRA 0x2D94
2D8C  0E00     MOVLW 0x0
2D8E  6E1D     MOVWF 0x1D, ACCESS
2D90  0E00     MOVLW 0x0
2D92  6E1C     MOVWF 0x1C, ACCESS
83:                i = 0;
2D94  0E00     MOVLW 0x0
2D96  6E1B     MOVWF 0x1B, ACCESS
2D98  0E00     MOVLW 0x0
2D9A  6E1A     MOVWF 0x1A, ACCESS
84:                while (i < w) {
2D9C  D00C     BRA 0x2DB6
2DB6  501C     MOVF 0x1C, W, ACCESS
2DB8  5C1A     SUBWF 0x1A, W, ACCESS
2DBA  501B     MOVF 0x1B, W, ACCESS
2DBC  0A80     XORLW 0x80
2DBE  6E19     MOVWF 0x19, ACCESS
2DC0  501D     MOVF 0x1D, W, ACCESS
2DC2  0A80     XORLW 0x80
2DC4  5819     SUBWFB 0x19, W, ACCESS
2DC6  A0D8     BTFSS 0xFD8, 0, ACCESS
2DC8  D7EA     BRA 0x2D9E
85:                    fputc(' ', fp);
2D9E  0E00     MOVLW 0x0
2DA0  6E04     MOVWF 0x4, ACCESS
2DA2  0E20     MOVLW 0x20
2DA4  6E03     MOVWF 0x3, ACCESS
2DA6  C513     MOVFF fp, fp
2DA8  F505     NOP
2DAA  C514     MOVFF 0x514, 0x506
2DAC  F506     NOP
2DAE  EC37     CALL 0x2E6E, 0
2DB0  F017     NOP
86:                    ++i;
2DB2  4A1A     INFSNZ 0x1A, F, ACCESS
2DB4  2A1B     INCF 0x1B, F, ACCESS
87:                }
88:            
89:                /* Right justify ? Put out string */
90:                if (!(flags & MINUS_FLAG)) {
2DCA  B05D     BTFSC 0x5D, 0, ACCESS
2DCC  D00A     BRA 0x2DE2
91:                    fputs((const char *)buf, fp);
2DCE  C515     MOVFF buf, s
2DD0  F50C     NOP
2DD2  C516     MOVFF 0x516, 0x50D
2DD4  F50D     NOP
2DD6  C513     MOVFF fp, fp
2DD8  F50E     NOP
2DDA  C514     MOVFF 0x514, 0x50F
2DDC  F50F     NOP
2DDE  ECDE     CALL 0x2FBC, 0
2DE0  F017     NOP
92:                }
93:            
94:                return (int)(strlen(buf) + (size_t)w);
2DE2  C515     MOVFF buf, __pcstackCOMRAM
2DE4  F501     NOP
2DE6  C516     MOVFF 0x516, txData
2DE8  F502     NOP
2DEA  EC2A     CALL 0x3054, 0
2DEC  F018     NOP
2DEE  501C     MOVF 0x1C, W, ACCESS
2DF0  2401     ADDWF 0x1, W, ACCESS
2DF2  6E13     MOVWF 0x13, ACCESS
2DF4  501D     MOVF 0x1D, W, ACCESS
2DF6  2002     ADDWFC 0x2, W, ACCESS
2DF8  6E14     MOVWF 0x14, ACCESS
95:            }
2DFA  0012     RETURN 0
96:            #endif
97:            
98:            #ifdef _VFPF_A
99:            static _INLINE int atoa(FILE *fp, long double f, char c)
100:           {
101:               char mode, nmode;
102:               int d, e, i, m, n, ne, p, pp, sign, t, w;
103:               long double g, h, l, ou, u;
104:           
105:               /* Record sign, get absolute value */
106:               sign = 0;
107:               g = f;
108:               if (g < 0.0) {
109:                   sign = 1;
110:                   g = -g;
111:               }
112:           
113:               /* Print sign, prefix */
114:               n = 0;
115:               w = width;
116:               if (sign || (flags & PLUS_FLAG)) {
117:                   dbuf[n] = sign ? '-' : '+';
118:                   ++n;
119:                   --w;
120:               }
121:               dbuf[n++] = '0';
122:               dbuf[n++] = isupper((int)c) ? 'X' : 'x';
123:           
124:               /* Catch infinities, NaNs here */
125:               if (isinf(g)) {
126:                   if (isupper((int)c)) {
127:                       strcpy(&dbuf[n], "INF");
128:                   } else {
129:                       strcpy(&dbuf[n], "inf");
130:                   }
131:                   w -= CSTRLEN("inf");
132:                   return pad(fp, &dbuf[0], w);
133:               }
134:               if (isnan(g)) {
135:                   if (isupper((int)c)) {
136:                       strcpy(&dbuf[n], "NAN");
137:                   } else {
138:                       strcpy(&dbuf[n], "nan");
139:                   }
140:                   w -= CSTRLEN("inf");
141:                   return pad(fp, &dbuf[0], w);
142:               }
143:           
144:               /* First find the largest power of 2 not larger than number to print */
145:               u = 1.0;
146:               e = 0;
147:               if (!(g == 0.0)) {
148:                   while (!(g < (u*2.0))) {
149:                       u = u*2.0;
150:                       ++e;
151:                   }
152:                   while (g < u) {
153:                       u = u/2.0;
154:                       --e;
155:                   }
156:               }
157:           
158:               /* Get precision */
159:               p = (prec < 0) ? 6 : prec;
160:           
161:               /* Hex places, total */
162:               m = p + 1;
163:           
164:               /* Go through the conversion once to get to the rounding step */
165:               i = 0;
166:               h = g;
167:               ou = u;
168:               while (i < m) {
169:                   l = floor(h/u);
170:                   d = (int)l;
171:                   h -= l*u;
172:                   u = u/16.0;
173:                   ++i;
174:               }
175:               
176:               /* Remainder >= halfway ? */
177:               l = u*8.0;
178:               if (h < l) {
179:                   l = 0.0;
180:               } else {
181:                   /* On tie choose even number */
182:                   if ((h == l) && !(d % 2)) {
183:                       l = 0.0;
184:                   }
185:               }
186:           
187:               /* Round */
188:               h = g + l;
189:               
190:               /* Convert again, after rounding */
191:               u = ou;
192:               ne = 0;
193:               pp = 0;
194:               t = 0;
195:               i = 0;
196:               while ((i < m) && (n < (DBLEN - EXPLEN))) {
197:                   l = floor(h/u);
198:                   d = (int)l;
199:                   if (!(flags & POUND_FLAG) && !d && (ne < 0)) {
200:                       ++t;
201:                   } else {
202:                       if (!pp && (ne < 0)) {
203:                           dbuf[n++] = '.';
204:                           --w;
205:                           pp = 1;
206:                       }
207:                       while (t) {
208:                           dbuf[n++] = '0';
209:                           --w;
210:                           --t;
211:                       }
212:                       d = (d < 10) ? (int)'0' + d : (int)'a' + (d - 10);
213:                       if (isupper((int)c) && isalpha(d)) {
214:                           d = toupper(d);
215:                       }
216:                       dbuf[n++] = (char)d;
217:                       --w;
218:                   }
219:                   h -= l*u;
220:                   u = u/16.0;
221:                   --ne;
222:                   ++i;
223:               }
224:               if (!pp && (flags & POUND_FLAG)) {
225:                   dbuf[n++] = '.';
226:               }
227:               dbuf[n] = '\0';
228:           
229:               /* Convert exponent */
230:               i = sizeof(dbuf) - 1;
231:               dbuf[i] = '\0';
232:               sign = 0;
233:               if (e < 0) {
234:                   sign = 1;
235:                   e = -e;
236:               }
237:               p = 1;
238:               while (e || (0 < p)) {
239:                   --i;
240:                   dbuf[i] = '0' + (e % 10);
241:                   e = e / 10;
242:                   --p;
243:                   --w;
244:               }
245:               --i;
246:               dbuf[i] = sign ? '-' : '+';
247:               --w;
248:               --i;
249:               dbuf[i] = isupper((int)c) ? 'P' : 'p';
250:               --w;
251:               strcpy(&dbuf[n], &dbuf[i]);
252:           
253:               /* Put out padded string */
254:               return pad(fp, &dbuf[0], w);
255:           }
256:           #endif
257:           
258:           #ifdef _VFPF_C
259:           static _INLINE int ctoa(FILE *fp, char c)
260:           {
261:               int l, w;
262:           
263:               /* Get width */
264:               w = width ? width - 1 : width;
265:           
266:               /* Left justify ? Put out character */
267:               if (flags & MINUS_FLAG) {
268:                   fputc(c, fp);
269:               }
270:               /* Put out padding */
271:               w = (w < 0) ? 0 : w;
272:               l = 0;
273:               while (l < w) {
274:                   fputc(' ', fp);
275:                   ++l;
276:               }
277:               /* Right justify ? Put out string */
278:               if (!(flags & MINUS_FLAG)) {
279:                   fputc(c, fp);
280:               }
281:           
282:               return l+1;
283:           }
284:           #endif
285:           
286:           #ifdef _VFPF_D
287:           static _INLINE int dtoa(FILE *fp, long long d)
254C  C520     MOVFF d, n
254E  F538     NOP
2550  C521     MOVFF 0x521, 0x539
2552  F539     NOP
2554  C522     MOVFF 0x522, 0x53A
2556  F53A     NOP
2558  C523     MOVFF 0x523, 0x53B
255A  F53B     NOP
255C  C524     MOVFF 0x524, 0x53C
255E  F53C     NOP
2560  C525     MOVFF 0x525, 0x53D
2562  F53D     NOP
2564  C526     MOVFF 0x526, 0x53E
2566  F53E     NOP
2568  C527     MOVFF 0x527, 0x53F
256A  F53F     NOP
288:           {
289:               int i, p, s, w;
290:               long long n;
291:           
292:               /* Record sign, get absolute value */
293:               n = d;
294:               s = n < 0 ? 1 : 0;
256C  AE3F     BTFSS 0x3F, 7, ACCESS
256E  D002     BRA 0x2574
2570  0E01     MOVLW 0x1
2572  D001     BRA 0x2576
2574  0E00     MOVLW 0x0
2576  6E36     MOVWF 0x36, ACCESS
2578  6A37     CLRF 0x37, ACCESS
295:               if (s) {
257A  5036     MOVF 0x36, W, ACCESS
257C  1037     IORWF 0x37, W, ACCESS
257E  B4D8     BTFSC 0xFD8, 2, ACCESS
2580  D010     BRA 0x25A2
296:                   n = -n;
2582  1E3F     COMF 0x3F, F, ACCESS
2584  1E3E     COMF 0x3E, F, ACCESS
2586  1E3D     COMF 0x3D, F, ACCESS
2588  1E3C     COMF 0x3C, F, ACCESS
258A  1E3B     COMF 0x3B, F, ACCESS
258C  1E3A     COMF CLKRCLK, F, ACCESS
258E  1E39     COMF CLKRCON, F, ACCESS
2590  6C38     NEGF 0x38, ACCESS
2592  0E00     MOVLW 0x0
2594  2239     ADDWFC CLKRCON, F, ACCESS
2596  223A     ADDWFC CLKRCLK, F, ACCESS
2598  223B     ADDWFC 0x3B, F, ACCESS
259A  223C     ADDWFC 0x3C, F, ACCESS
259C  223D     ADDWFC 0x3D, F, ACCESS
259E  223E     ADDWFC 0x3E, F, ACCESS
25A0  223F     ADDWFC 0x3F, F, ACCESS
297:               }
298:           
299:               /* Adjust flags, precision, width */
300:               if (!(prec < 0)) {
25A2  AF80     BTFSS SPI1RXB, 7, BANKED
301:                   flags &= ~ZERO_FLAG;
25A4  925D     BCF 0x5D, 1, ACCESS
302:               }
303:               p = (0 < prec) ? prec : 1;
25A6  BF80     BTFSC SPI1RXB, 7, BANKED
25A8  D005     BRA 0x25B4
25AA  5180     MOVF SPI1RXB, W, BANKED
25AC  E108     BNZ 0x25BE
25AE  057F     DECF DAC1CON, W, BANKED
25B0  B0D8     BTFSC 0xFD8, 0, ACCESS
25B2  D005     BRA 0x25BE
25B4  0E00     MOVLW 0x0
25B6  6E33     MOVWF 0x33, ACCESS
25B8  0E01     MOVLW 0x1
25BA  6E32     MOVWF 0x32, ACCESS
25BC  D004     BRA 0x25C6
25BE  C57F     MOVFF prec, p
25C0  F532     NOP
25C2  C580     MOVFF 0x580, 0x533
25C4  F533     NOP
304:               w = width;
25C6  C57D     MOVFF width, w
25C8  F534     NOP
25CA  C57E     MOVFF 0x57E, 0x535
25CC  F535     NOP
305:               if (s || (flags & PLUS_FLAG)) {
25CE  5036     MOVF 0x36, W, ACCESS
25D0  1037     IORWF 0x37, W, ACCESS
25D2  A4D8     BTFSS 0xFD8, 2, ACCESS
25D4  D002     BRA 0x25DA
25D6  A45D     BTFSS 0x5D, 2, ACCESS
25D8  D003     BRA 0x25E0
306:                   --w;
25DA  0634     DECF 0x34, F, ACCESS
25DC  A0D8     BTFSS 0xFD8, 0, ACCESS
25DE  0635     DECF 0x35, F, ACCESS
307:               }
308:           
309:               /* Convert to decimal, possibly filling on the left with zeroes */
310:               i = sizeof(dbuf) - 1;
25E0  0E00     MOVLW 0x0
25E2  6E41     MOVWF NVMCON1, ACCESS
25E4  0E1F     MOVLW 0x1F
25E6  6E40     MOVWF NVMCON0, ACCESS
311:               dbuf[i] = '\0';
25E8  0E00     MOVLW 0x0
25EA  6FA6     MOVWF 0xA6, BANKED
312:               while (!(i < 1) && (n || (0 < p) || ((0 < w) && (flags & ZERO_FLAG)))) {
25EC  D07C     BRA 0x26E6
26E6  BE41     BTFSC NVMCON1, 7, ACCESS
26E8  D01F     BRA 0x2728
26EA  5041     MOVF NVMCON1, W, ACCESS
26EC  E103     BNZ 0x26F4
26EE  0440     DECF NVMCON0, W, ACCESS
26F0  A0D8     BTFSS 0xFD8, 0, ACCESS
26F2  D01A     BRA 0x2728
26F4  5038     MOVF 0x38, W, ACCESS
26F6  1039     IORWF CLKRCON, W, ACCESS
26F8  103A     IORWF CLKRCLK, W, ACCESS
26FA  103B     IORWF 0x3B, W, ACCESS
26FC  103C     IORWF 0x3C, W, ACCESS
26FE  103D     IORWF 0x3D, W, ACCESS
2700  103E     IORWF 0x3E, W, ACCESS
2702  103F     IORWF 0x3F, W, ACCESS
2704  A4D8     BTFSS 0xFD8, 2, ACCESS
2706  D773     BRA 0x25EE
2708  BE33     BTFSC 0x33, 7, ACCESS
270A  D005     BRA 0x2716
270C  5033     MOVF 0x33, W, ACCESS
270E  E102     BNZ 0x2714
2710  0432     DECF 0x32, W, ACCESS
2712  B0D8     BTFSC 0xFD8, 0, ACCESS
2714  D76C     BRA 0x25EE
2716  BE35     BTFSC 0x35, 7, ACCESS
2718  D007     BRA 0x2728
271A  5035     MOVF 0x35, W, ACCESS
271C  E103     BNZ 0x2724
271E  0434     DECF 0x34, W, ACCESS
2720  A0D8     BTFSS 0xFD8, 0, ACCESS
2722  D002     BRA 0x2728
2724  B25D     BTFSC 0x5D, 1, ACCESS
2726  D763     BRA 0x25EE
313:                   --i;
25EE  0640     DECF NVMCON0, F, ACCESS
25F0  A0D8     BTFSS 0xFD8, 0, ACCESS
25F2  0641     DECF NVMCON1, F, ACCESS
314:                   dbuf[i] = (char)((int)'0' + abs(n % 10));
25F4  0E87     MOVLW 0x87
25F6  2440     ADDWF NVMCON0, W, ACCESS
25F8  6ED9     MOVWF 0xFD9, ACCESS
25FA  0E05     MOVLW 0x5
25FC  2041     ADDWFC NVMCON1, W, ACCESS
25FE  6EDA     MOVWF 0xFDA, ACCESS
2600  C538     MOVFF n, __pcstackCOMRAM
2602  F501     NOP
2604  C539     MOVFF 0x539, txData
2606  F502     NOP
2608  C53A     MOVFF 0x53A, a
260A  F503     NOP
260C  C53B     MOVFF 0x53B, 0x504
260E  F504     NOP
2610  C53C     MOVFF 0x53C, fp
2612  F505     NOP
2614  C53D     MOVFF 0x53D, 0x506
2616  F506     NOP
2618  C53E     MOVFF 0x53E, 0x507
261A  F507     NOP
261C  C53F     MOVFF 0x53F, 0x508
261E  F508     NOP
2620  0E0A     MOVLW 0xA
2622  6E09     MOVWF 0x9, ACCESS
2624  0E00     MOVLW 0x0
2626  6E0A     MOVWF 0xA, ACCESS
2628  0E00     MOVLW 0x0
262A  6E0B     MOVWF 0xB, ACCESS
262C  0E00     MOVLW 0x0
262E  6E0C     MOVWF 0xC, ACCESS
2630  0E00     MOVLW 0x0
2632  6E0D     MOVWF 0xD, ACCESS
2634  0E00     MOVLW 0x0
2636  6E0E     MOVWF 0xE, ACCESS
2638  0E00     MOVLW 0x0
263A  6E0F     MOVWF 0xF, ACCESS
263C  0E00     MOVLW 0x0
263E  6E10     MOVWF 0x10, ACCESS
2640  EC48     CALL 0x2A90, 0
2642  F015     NOP
2644  C501     MOVFF __pcstackCOMRAM, 0x528
2646  F528     NOP
2648  C502     MOVFF txData, 0x529
264A  F529     NOP
264C  C503     MOVFF a, 0x52A
264E  F52A     NOP
2650  C504     MOVFF 0x504, 0x52B
2652  F52B     NOP
2654  C505     MOVFF fp, 0x52C
2656  F52C     NOP
2658  C506     MOVFF 0x506, 0x52D
265A  F52D     NOP
265C  C507     MOVFF 0x507, 0x52E
265E  F52E     NOP
2660  C508     MOVFF 0x508, 0x52F
2662  F52F     NOP
2664  C528     MOVFF 0x528, fp
2666  F513     NOP
2668  C52A     MOVFF 0x52A, 0x514
266A  F514     NOP
266C  ECFA     CALL 0x2FF4, 0
266E  F017     NOP
2670  5013     MOVF 0x13, W, ACCESS
2672  0F30     ADDLW 0x30
2674  6EDF     MOVWF 0xFDF, ACCESS
315:                   --p;
2676  0632     DECF 0x32, F, ACCESS
2678  A0D8     BTFSS 0xFD8, 0, ACCESS
267A  0633     DECF 0x33, F, ACCESS
316:                   --w;
267C  0634     DECF 0x34, F, ACCESS
267E  A0D8     BTFSS 0xFD8, 0, ACCESS
2680  0635     DECF 0x35, F, ACCESS
317:                   n = n / 10;
2682  C538     MOVFF n, __pcstackCOMRAM
2684  F501     NOP
2686  C539     MOVFF 0x539, txData
2688  F502     NOP
268A  C53A     MOVFF 0x53A, a
268C  F503     NOP
268E  C53B     MOVFF 0x53B, 0x504
2690  F504     NOP
2692  C53C     MOVFF 0x53C, fp
2694  F505     NOP
2696  C53D     MOVFF 0x53D, 0x506
2698  F506     NOP
269A  C53E     MOVFF 0x53E, 0x507
269C  F507     NOP
269E  C53F     MOVFF 0x53F, 0x508
26A0  F508     NOP
26A2  0E0A     MOVLW 0xA
26A4  6E09     MOVWF 0x9, ACCESS
26A6  0E00     MOVLW 0x0
26A8  6E0A     MOVWF 0xA, ACCESS
26AA  0E00     MOVLW 0x0
26AC  6E0B     MOVWF 0xB, ACCESS
26AE  0E00     MOVLW 0x0
26B0  6E0C     MOVWF 0xC, ACCESS
26B2  0E00     MOVLW 0x0
26B4  6E0D     MOVWF 0xD, ACCESS
26B6  0E00     MOVLW 0x0
26B8  6E0E     MOVWF 0xE, ACCESS
26BA  0E00     MOVLW 0x0
26BC  6E0F     MOVWF 0xF, ACCESS
26BE  0E00     MOVLW 0x0
26C0  6E10     MOVWF 0x10, ACCESS
26C2  ECA4     CALL 0x2948, 0
26C4  F014     NOP
26C6  C501     MOVFF __pcstackCOMRAM, n
26C8  F538     NOP
26CA  C502     MOVFF txData, 0x539
26CC  F539     NOP
26CE  C503     MOVFF a, 0x53A
26D0  F53A     NOP
26D2  C504     MOVFF 0x504, 0x53B
26D4  F53B     NOP
26D6  C505     MOVFF fp, 0x53C
26D8  F53C     NOP
26DA  C506     MOVFF 0x506, 0x53D
26DC  F53D     NOP
26DE  C507     MOVFF 0x507, 0x53E
26E0  F53E     NOP
26E2  C508     MOVFF 0x508, 0x53F
26E4  F53F     NOP
318:               }
319:           
320:               /* Display sign if required */
321:               if (s || (flags & PLUS_FLAG)) {
2728  5036     MOVF 0x36, W, ACCESS
272A  1037     IORWF 0x37, W, ACCESS
272C  A4D8     BTFSS 0xFD8, 2, ACCESS
272E  D002     BRA 0x2734
2730  A45D     BTFSS 0x5D, 2, ACCESS
2732  D018     BRA 0x2764
322:                   --i;
2734  0640     DECF NVMCON0, F, ACCESS
2736  A0D8     BTFSS 0xFD8, 0, ACCESS
2738  0641     DECF NVMCON1, F, ACCESS
323:                   dbuf[i] = s ? '-' : '+';
273A  5036     MOVF 0x36, W, ACCESS
273C  1037     IORWF 0x37, W, ACCESS
273E  A4D8     BTFSS 0xFD8, 2, ACCESS
2740  D004     BRA 0x274A
2742  0E00     MOVLW 0x0
2744  6E31     MOVWF 0x31, ACCESS
2746  0E2B     MOVLW 0x2B
2748  D003     BRA 0x2750
274A  0E00     MOVLW 0x0
274C  6E31     MOVWF 0x31, ACCESS
274E  0E2D     MOVLW 0x2D
2750  6E30     MOVWF 0x30, ACCESS
2752  0E87     MOVLW 0x87
2754  2440     ADDWF NVMCON0, W, ACCESS
2756  6ED9     MOVWF 0xFD9, ACCESS
2758  0E05     MOVLW 0x5
275A  2041     ADDWFC NVMCON1, W, ACCESS
275C  6EDA     MOVWF 0xFDA, ACCESS
2760  F4C0     NOP
2762  F4DF     NOP
324:               }
325:           
326:               /* Put out padded string */
327:               return pad(fp, &dbuf[i], w);
2764  C51E     MOVFF fp, fp
2766  F513     NOP
2768  C51F     MOVFF 0x51F, 0x514
276A  F514     NOP
276C  0E87     MOVLW 0x87
276E  2440     ADDWF NVMCON0, W, ACCESS
2770  6E15     MOVWF 0x15, ACCESS
2772  0E05     MOVLW 0x5
2774  2041     ADDWFC NVMCON1, W, ACCESS
2776  6E16     MOVWF 0x16, ACCESS
2778  C534     MOVFF w, p
277A  F517     NOP
277C  C535     MOVFF 0x535, 0x518
277E  F518     NOP
2780  ECB3     CALL 0x2D66, 0
2782  F016     NOP
2784  C513     MOVFF fp, fp
2786  F51E     NOP
2788  C514     MOVFF 0x514, 0x51F
278A  F51F     NOP
328:           }
278C  0012     RETURN 0
329:           #endif
330:           
331:           #if defined(_VFPF_E) || defined(_VFPF_F) || defined(_VFPF_G)
332:           static _INLINE int efgtoa(FILE *fp, long double f, char c)
333:           {
334:               char mode, nmode;
335:               int d, e, i, m, n, ne, p, pp, sign, t, w;
336:               long double g, h, l, ou, u;
337:           
338:               /* Record sign, get absolute value */
339:               sign = 0;
340:               g = f;
341:               if (g < 0.0) {
342:                   sign = 1;
343:                   g = -g;
344:               }
345:           
346:               /* Print sign */
347:               n = 0;
348:               w = width;
349:               if (sign || (flags & PLUS_FLAG)) {
350:                   dbuf[n] = sign ? '-' : '+';
351:                   ++n;
352:                   --w;
353:               }
354:           
355:               /* Catch infinities, NaNs here */
356:               if (isinf(g)) {
357:                   if (isupper((int)c)) {
358:                       strcpy(&dbuf[n], "INF");
359:                   } else {
360:                       strcpy(&dbuf[n], "inf");
361:                   }
362:                   w -= CSTRLEN("inf");
363:                   return pad(fp, &dbuf[0], w);
364:               }
365:               if (isnan(g)) {
366:                   if (isupper((int)c)) {
367:                       strcpy(&dbuf[n], "NAN");
368:                   } else {
369:                       strcpy(&dbuf[n], "nan");
370:                   }
371:                   w -= CSTRLEN("inf");
372:                   return pad(fp, &dbuf[0], w);
373:               }
374:           
375:               /* First find the largest power of 10 not larger than number to print */
376:               u = 1.0;
377:               e = 0;
378:               if (!(g == 0.0)) {
379:                   while (!(g < (u*10.0))) {
380:                       u = u*10.0;
381:                       ++e;
382:                   }
383:                   while (g < u) {
384:                       u = u/10.0;
385:                       --e;
386:                   }
387:               }
388:           
389:               /* Get mode, precision */
390:               mode = (char)tolower((int)c);
391:               nmode = mode;
392:               if (mode == 'g') {
393:           		if (prec == 0) {
394:           			prec = 1;
395:           		}
396:                   p = (0 < prec) ? prec : 6;
397:               } else {
398:                   p = (prec < 0) ? 6 : prec;
399:               }
400:           
401:               /* Choose e or f mode from g mode */
402:               if (mode == 'g') {
403:                   if (!(e < -4) && !((p - 1) < e)) {
404:                       nmode = 'f';
405:                   } else {
406:                       nmode = 'e';
407:                   }
408:               }
409:           
410:               /* Decimal places or significant digits */
411:               m = p;
412:               if (!(mode == 'g') || ((nmode == 'f') && (e < 0))) {
413:                   ++m;
414:               }
415:           
416:               /* Adjust starting exponent, string length for 'f' conversions */
417:               if (nmode == 'f') {
418:                   if (e < 0) {
419:                       u = 1.0;
420:                       e = 0;
421:                   }
422:                   if (!(mode == 'g')) {
423:                       m += e;
424:                   }
425:               }
426:           
427:               /* Go through the conversion once to get to the rounding step */
428:               i = 0;
429:               h = g;
430:               ou = u;
431:               while (i < m) {
432:                   l = floor(h/u);
433:                   d = (int)l;
434:                   h -= l*u;
435:                   u = u/10.0;
436:                   ++i;
437:               }
438:               
439:               /* Remainder >= halfway ? */
440:               l = u*5.0;
441:               if (h < l) {
442:                   l = 0.0;
443:               } else {
444:                   /* On tie choose even number */
445:                   if ((h == l) && !(d % 2)) {
446:                       l = 0.0;
447:                   }
448:               }
449:           
450:               /* Round */
451:               h = g + l;
452:               /* Has rounding increased the power above 10^0? */
453:           	if (h >= (ou*10.0)) {
454:           		e++;
455:           		ou *= 10.0;
456:           		if (nmode == 'f') {
457:           			// the increase in power will only affect the number of digits in 'f' mode
458:           			m++;
459:           		}
460:           	}
461:               
462:               /* Convert again, after rounding */
463:               u = ou;
464:               ne = (nmode == 'e') ? 0 : e;
465:               pp = 0;
466:               t = 0;
467:               i = 0;
468:               while ((i < m) && (n < (DBLEN - EXPLEN))) {
469:                   l = floor(h/u);
470:                   d = (int)l;
471:                   if (!(flags & POUND_FLAG) && !d && (mode == 'g') && (ne < 0)) {
472:                       ++t;
473:                   } else {
474:                       if (!pp && (ne < 0)) {
475:                           dbuf[n++] = '.';
476:                           --w;
477:                           pp = 1;
478:                       }
479:                       while (t) {
480:                           dbuf[n++] = '0';
481:                           --w;
482:                           --t;
483:                       }
484:                       dbuf[n++] = (char)((int)'0' + d);
485:                       --w;
486:                   }
487:                   h -= l*u;
488:                   u = u/10.0;
489:                   --ne;
490:                   ++i;
491:               }
492:               if (!pp && (flags & POUND_FLAG)) {
493:                   dbuf[n++] = '.';
494:               }
495:               dbuf[n] = '\0';
496:           
497:               /* Convert exponent */
498:               if (nmode == 'e') {
499:                   i = sizeof(dbuf) - 1;
500:                   dbuf[i] = '\0';
501:                   sign = 0;
502:                   if (e < 0) {
503:                       sign = 1;
504:                       e = -e;
505:                   }
506:                   p = 2;
507:                   while (e || (0 < p)) {
508:                       --i;
509:                       dbuf[i] = '0' + (e % 10);
510:                       e = e / 10;
511:                       --p;
512:                       --w;
513:                   }
514:                   --i;
515:                   dbuf[i] = sign ? '-' : '+';
516:                   --w;
517:                   --i;
518:                   dbuf[i] = isupper((int)c) ? 'E' : 'e';
519:                   --w;
520:                   strcpy(&dbuf[n], &dbuf[i]);
521:               }
522:           
523:               /* Put out padded string */
524:               return pad(fp, &dbuf[0], w);
525:           }
526:           #endif
527:           
528:           #ifdef _VFPF_O
529:           static _INLINE int otoa(FILE *fp, unsigned long long d)
530:           {
531:               int i, p, t, w;
532:               unsigned long long n;
533:           
534:               /* Adjust flags, precision, width */
535:               if (!(prec < 0)) {
536:                   flags &= ~ZERO_FLAG;
537:               }
538:               p = (0 < prec) ? prec : 1;
539:               w = width;
540:           
541:               /* Convert to octal, possibly filling on the left with zeroes */
542:               n = d;
543:               i = sizeof(dbuf) - 1;
544:               dbuf[i] = '\0';
545:               t = 0;
546:               while (!(i < 1) && (n || (0 < p) || ((0 < w) && (flags & ZERO_FLAG)))) {
547:                   --i;
548:                   t = n & 07;
549:                   dbuf[i] = (char)((int)'0' + t);
550:                   --p;
551:                   --w;
552:                   n = n >> 3;
553:               }
554:           
555:               /* Display prefix if required */
556:               if ((flags & POUND_FLAG) && t) {
557:                   --i;
558:                   dbuf[i] = '0';
559:                   --w;
560:               }
561:           
562:               /* Put out padded string */
563:               return pad(fp, &dbuf[i], w);
564:           }
565:           #endif
566:           
567:           #ifdef _VFPF_S
568:           static _INLINE int stoa(FILE *fp, char *s)
569:           {
570:               char *cp, nuls[] = "(null)";
571:               int i, l, p, w;
572:           
573:               /* Check for null string */
574:               cp = s;
575:               if (!cp) {
576:                   cp = nuls;
577:               }
578:           
579:               /* Get length, precision, width */
580:               l = (int)strlen(cp);
581:               p = prec;
582:               l = (!(p < 0) && (p < l)) ? p : l;
583:               p = l;
584:               w = width;
585:           
586:               /* Right justify, pad on left ? */
587:               if (!(flags & MINUS_FLAG)) {
588:                   while (l < w) {
589:                       fputc(' ', fp);
590:                       ++l;
591:                   }
592:               }
593:           
594:               /* Put out string */
595:               i = 0;
596:               while (i < p) {
597:                   fputc(*cp, fp);
598:                   ++cp;
599:                   ++i;
600:               }
601:           
602:               /* Left justify, pad on right ? */
603:               if (flags & MINUS_FLAG) {
604:                   while (l < w) {
605:                       fputc(' ', fp);
606:                       ++l;
607:                   }
608:               }
609:           
610:               return l;
611:           }
612:           #endif
613:           
614:           #ifdef _VFPF_U
615:           static _INLINE int utoa(FILE *fp, unsigned long long d)
616:           {
617:               int i, p, w;
618:               unsigned long long n;
619:           
620:               /* Adjust flags, precision, width */
621:               if (!(prec < 0)) {
622:                   flags &= ~ZERO_FLAG;
623:               }
624:               p = (0 < prec) ? prec : 1;
625:               w = width;
626:           
627:               /* Convert to decimal, possibly filling on the left with zeroes */
628:               n = d;
629:               i = sizeof(dbuf) - 1;
630:               dbuf[i] = '\0';
631:               while (i && (n || (0 < p) || ((0 < w) && (flags & ZERO_FLAG)))) {
632:                   --i;
633:                   dbuf[i] = '0' + (n % 10);
634:                   --p;
635:                   --w;
636:                   n = n / 10;
637:               }
638:           
639:               /* Put out padded string */
640:               return pad(fp, &dbuf[i], w);
641:           }
642:           #endif
643:           
644:           #if defined(_VFPF_X) || defined(_VFPF_P)
645:           static _INLINE int xtoa(FILE *fp, unsigned long long d, char x)
646:           {
647:               int c, i, p, w;
648:               unsigned long long n;
649:           
650:               /* Adjust, flags, precision, width */
651:               if (!(prec < 0)) {
652:                   flags &= ~ZERO_FLAG;
653:               }
654:               p = (0 < prec) ? prec : 1;
655:               w = width;
656:               if (flags & POUND_FLAG) {
657:                   w -= 2;
658:               }
659:           
660:               /* Convert to hexadecimal, possibly filling on the left with zeroes */
661:               n = d;
662:               i = sizeof(dbuf) - 1;
663:               dbuf[i] = '\0';
664:               while (!(i < 2) && (n || (0 < p) || ((0 < w) && (flags & ZERO_FLAG)))) {
665:                   --i;
666:                   c = n & 0x0f;
667:                   c = (c < 10) ? (int)'0' + c : (int)'a' + (c - 10);
668:                   if (isupper((int)x) && isalpha(c)) {
669:                       c = toupper(c);
670:                   }
671:                   dbuf[i] = (char)c;
672:                   --p;
673:                   --w;
674:                   n = n >> 4;
675:               }
676:           
677:               /* Display prefix if required */
678:               if (flags & POUND_FLAG) {
679:                   --i;
680:                   dbuf[i] = x;
681:                   --i;
682:                   dbuf[i] = '0';
683:               }
684:           
685:               /* Put out padded string */
686:               return pad(fp, &dbuf[i], w);
687:           }
688:           #endif
689:           
690:           /* Consume and convert the next part of the format string */
691:           #ifdef _VFPF_CONVERT
692:           static _INLINE int vfpfcnvrt(FILE *fp, char *fmt[], va_list ap)
2790  F510     NOP
2792  F4D9     NOP
2796  F514     NOP
2798  F4DA     NOP
279A  C4DF     MOVFF INDF2, TBLPTR
279C  F4F6     NOP
279E  0E25     MOVLW 0x25
27A0  6EF7     MOVWF 0xFF7, ACCESS
27A2  0E00     MOVLW 0x0
27A4  6EF8     MOVWF 0xFF8, ACCESS
27A6  0008     TBLRD*
27A8  50F5     MOVF 0xFF5, W, ACCESS
27AA  0A25     XORLW 0x25
27AC  A4D8     BTFSS 0xFD8, 2, ACCESS
27AE  D0AE     BRA 0x290C
693:           {
694:               char c, *cp, ct[3];
695:               int done, i;
696:               long long ll;
697:               unsigned long long llu;
698:               long double f;
699:               void *vp;
700:           
701:               /* Conversion ? */
702:               if ((*fmt)[0] == '%') {
703:                   ++*fmt;
27B2  F510     NOP
27B4  F4D9     NOP
27B8  F514     NOP
27BA  F4DA     NOP
27BC  2ADF     INCF 0xFDF, F, ACCESS
704:           
705:                   flags = width = 0;
27BE  0E00     MOVLW 0x0
27C0  0105     MOVLB 0x5
27C2  6F7E     MOVWF 0x7E, BANKED
27C4  0E00     MOVLW 0x0
27C6  6F7D     MOVWF DAC1DAT, BANKED
27C8  C57D     MOVFF width, flags
27CA  F55D     NOP
27CC  C57E     MOVFF 0x57E, 0x55E
27CE  F55E     NOP
706:                   prec = -1;
27D0  697F     SETF DAC1CON, BANKED
27D2  6980     SETF SPI1RXB, BANKED
707:           
708:           #ifdef _VFPF_FLAGS
709:                   /* Get flags */
710:                   done = 0;
711:                   while (!done) {
712:                       switch ((*fmt)[0]) {
713:                           case '-' :
714:                               flags |= MINUS_FLAG;
715:                               ++*fmt;
716:                               break;
717:                           case '0' :
718:                               flags |= ZERO_FLAG;
719:                               ++*fmt;
720:                               break;
721:                           case '+' :
722:                               flags |= PLUS_FLAG;
723:                               ++*fmt;
724:                               break;
725:                           case ' ' :
726:                               flags |= SPACE_FLAG;
727:                               ++*fmt;
728:                               break;
729:                           case '#' :
730:                               flags |= POUND_FLAG;
731:                               ++*fmt;
732:                               break;
733:                           default:
734:                               done = 1;
735:                               break;
736:                       }
737:                   }
738:                   if (flags & MINUS_FLAG) {
739:                       flags &= ~ZERO_FLAG;
740:                   }
741:           #endif
742:           
743:           #ifdef _VFPF_WIDTH
744:                   /* Get field width */
745:                   if ((*fmt)[0] == '*') {
746:                       ++*fmt;
747:                       width = va_arg(ap, int);
748:                       if (width < 0) {
749:                           flags |= MINUS_FLAG;
750:                           width = -width;
751:                       }
752:                   } else {
753:                       width = atoi(*fmt);
754:                       while (isdigit((*fmt)[0])) {
755:                           ++*fmt;
756:                       }
757:                   }
758:           #endif
759:           
760:           #ifdef _VFPF_PRECISION
761:                   /* Get precision */
762:                   if ((*fmt)[0] == '.') {
763:                       prec = 0;
764:                       ++*fmt;
765:                       if ((*fmt)[0] == '*') {
766:                           ++*fmt;
767:                           prec = va_arg(ap, int);
768:                       } else {
769:                           prec = atoi(*fmt);
770:                           while (isdigit((*fmt)[0])) {
771:                               ++*fmt;
772:                           }
773:                       }
774:                   }
775:           #endif
776:           
777:           #if defined(_VFPF_A) || defined(_VFPF_E) || defined(_VFPF_F) || defined(_VFPF_G)
778:                   /* Case-folded conversion types */
779:                   ct[0] = (char)tolower((int)(*fmt)[0]);
780:                   if (ct[0]) {
781:                       ct[1] = (char)tolower((int)(*fmt)[1]);
782:                       if (ct[1]) {
783:                           ct[2] = (char)tolower((int)(*fmt)[2]);
784:                       }
785:                   }
786:           #endif
787:           
788:           #ifdef _VFPF_A
789:                   /* 'a' style (hex) floating point */
790:                   if (ct[0] == 'a') {
791:           
792:                       c = (*fmt)[0];
793:                       ++*fmt;
794:                       f = (long double)va_arg(ap, double);
795:                                   
796:                       return atoa(fp, f, c);
797:                   }
798:                   if (!strncmp(ct, "la", CSTRLEN("la"))) {
799:           
800:                       c = (*fmt)[1];
801:                       if (isupper((int)(*fmt)[0])) {
802:                           f = va_arg(ap, long double);
803:                       } else {
804:                           f = (long double)va_arg(ap, double);
805:                       }
806:                       *fmt += CSTRLEN("la");
807:                                   
808:                       return atoa(fp, f, c);
809:                   }
810:           #endif
811:           
812:           #ifdef _VFPF_C
813:                   /* Character */
814:                   if (*fmt[0] == 'c') {
815:                       ++*fmt;
816:                       c = (unsigned char)va_arg(ap, int);
817:                       return ctoa(fp, c);
818:                   }
819:           #endif
820:           
821:           #ifdef _VFPF_D
822:           #ifdef _VFPF_HH
823:                   /* Character decimal integer */
824:                   if (!strncmp(*fmt, "hhd", CSTRLEN("hhd")) || \
825:                       !strncmp(*fmt, "hhi", CSTRLEN("hhi"))) {
826:           
827:                       *fmt += CSTRLEN("hhd");
828:                       ll = (long long)(signed char)va_arg(ap, int);
829:                                   
830:                       return dtoa(fp, ll);
831:                   }
832:           #endif
833:           
834:           #ifdef _VFPF_H
835:                   /* Short decimal integer */
836:                   if (!strncmp(*fmt, "hd", CSTRLEN("hd")) || \
837:                       !strncmp(*fmt, "hi", CSTRLEN("hi"))) {
838:           
839:                       *fmt += CSTRLEN("hd");
840:                       ll = (long long)(short)va_arg(ap, int);
841:                                   
842:                       return dtoa(fp, ll);
843:                   }
844:           #endif
845:           
846:                   /* Decimal integer */
847:                   if ((*fmt[0] == 'd') || (*fmt[0] == 'i')) {
27D6  F510     NOP
27D8  F4D9     NOP
27DC  F514     NOP
27DE  F4DA     NOP
27E0  C4DF     MOVFF INDF2, TBLPTR
27E2  F4F6     NOP
27E4  0E25     MOVLW 0x25
27E6  6EF7     MOVWF 0xFF7, ACCESS
27E8  0E00     MOVLW 0x0
27EA  6EF8     MOVWF 0xFF8, ACCESS
27EC  0008     TBLRD*
27EE  50F5     MOVF 0xFF5, W, ACCESS
27F0  0A64     XORLW 0x64
27F2  B4D8     BTFSC 0xFD8, 2, ACCESS
27F4  D011     BRA 0x2818
27F8  F510     NOP
27FA  F4D9     NOP
27FE  F514     NOP
2800  F4DA     NOP
2802  C4DF     MOVFF INDF2, TBLPTR
2804  F4F6     NOP
2806  0E25     MOVLW 0x25
2808  6EF7     MOVWF 0xFF7, ACCESS
280A  0E00     MOVLW 0x0
280C  6EF8     MOVWF 0xFF8, ACCESS
280E  0008     TBLRD*
2810  50F5     MOVF 0xFF5, W, ACCESS
2812  0A69     XORLW 0x69
2814  A4D8     BTFSS 0xFD8, 2, ACCESS
2816  D047     BRA 0x28A6
848:           
849:                       ++*fmt;
281A  F510     NOP
281C  F4D9     NOP
2820  F514     NOP
2822  F4DA     NOP
2824  2ADF     INCF 0xFDF, F, ACCESS
850:                       ll = (long long)va_arg(ap, int);
2828  F518     NOP
282A  F4D9     NOP
282E  F51C     NOP
2830  F4DA     NOP
2834  F37C     NOP
2836  F548     NOP
2838  0E02     MOVLW 0x2
283A  26DE     ADDWF 0xFDE, F, ACCESS
283E  F37C     NOP
2840  F549     NOP
2842  0E00     MOVLW 0x0
2844  22DD     ADDWFC 0xFDD, F, ACCESS
2848  F520     NOP
284A  F4D9     NOP
284E  F524     NOP
2850  F4DA     NOP
2854  F378     NOP
2856  F54A     NOP
285A  F374     NOP
285C  F54B     NOP
285E  0E00     MOVLW 0x0
2860  BE4B     BTFSC HLVDCON1, 7, ACCESS
2862  0EFF     MOVLW 0xFF
2864  6E4C     MOVWF ZCDCON, ACCESS
2866  6E4D     MOVWF 0x4D, ACCESS
2868  6E4E     MOVWF 0x4E, ACCESS
286A  6E4F     MOVWF 0x4F, ACCESS
286C  6E50     MOVWF 0x50, ACCESS
286E  6E51     MOVWF 0x51, ACCESS
851:                                   
852:                       return dtoa(fp, ll);
2870  C542     MOVFF fp, fp
2872  F51E     NOP
2874  C543     MOVFF 0x543, 0x51F
2876  F51F     NOP
2878  C54A     MOVFF ll, d
287A  F520     NOP
287C  C54B     MOVFF 0x54B, 0x521
287E  F521     NOP
2880  C54C     MOVFF 0x54C, 0x522
2882  F522     NOP
2884  C54D     MOVFF 0x54D, 0x523
2886  F523     NOP
2888  C54E     MOVFF 0x54E, 0x524
288A  F524     NOP
288C  C54F     MOVFF 0x54F, 0x525
288E  F525     NOP
2890  C550     MOVFF 0x550, 0x526
2892  F526     NOP
2894  C551     MOVFF 0x551, 0x527
2896  F527     NOP
2898  ECA6     CALL 0x254C, 0
289A  F012     NOP
289C  C51E     MOVFF fp, fp
289E  F542     NOP
28A0  C51F     MOVFF 0x51F, 0x543
28A2  F543     NOP
28A4  0012     RETURN 0
853:                   }
854:           
855:           #ifdef _VFPF_L
856:                   /* Long decimal integer */
857:                   if (!strncmp(*fmt, "ld", CSTRLEN("ld")) || \
858:                       !strncmp(*fmt, "li", CSTRLEN("li"))) {
859:           
860:                       *fmt += CSTRLEN("ld");
861:                       ll = (long long)va_arg(ap, long);
862:                                   
863:                       return dtoa(fp, ll);
864:                   }
865:           #endif
866:           
867:           #ifdef _VFPF_LL
868:                   /* Long long decimal integer */
869:                   if (!strncmp(*fmt, "lld", CSTRLEN("lld")) || \
870:                       !strncmp(*fmt, "lli", CSTRLEN("lli"))) {
871:           
872:                       *fmt += CSTRLEN("lld");
873:                       ll = va_arg(ap, long long);
874:                                   
875:                       return dtoa(fp, ll);
876:                   }
877:           #endif
878:           
879:           #ifdef _VFPF_J
880:                   /* intmax_t decimal integer */
881:                   if (!strncmp(*fmt, "jd", CSTRLEN("jd")) || \
882:                       !strncmp(*fmt, "ji", CSTRLEN("ji"))) {
883:           
884:                       *fmt += CSTRLEN("jd");
885:                       ll = (long long)va_arg(ap, intmax_t);
886:                                   
887:                       return dtoa(fp, ll);
888:                   }
889:           #endif
890:           
891:           #ifdef _VFPF_T
892:                   /* ptrdiff_t decimal integer */
893:                   if (!strncmp(*fmt, "td", CSTRLEN("td")) || \
894:                       !strncmp(*fmt, "ti", CSTRLEN("ti"))) {
895:           
896:                       *fmt += CSTRLEN("td");
897:                       ll = (long long)va_arg(ap, ptrdiff_t);
898:                                   
899:                       return dtoa(fp, ll);
900:                   }
901:           #endif
902:           
903:           #ifdef _VFPF_Z
904:                   /* size_t decimal integer */
905:                   if (!strncmp(*fmt, "zd", CSTRLEN("zd")) || \
906:                       !strncmp(*fmt, "zi", CSTRLEN("zi"))) {
907:           
908:                       *fmt += CSTRLEN("zd");
909:                       ll = (long long)va_arg(ap, size_t);
910:                                   
911:                       return dtoa(fp, ll);
912:                   }
913:           #endif
914:           #endif
915:           
916:           #ifdef _VFPF_E
917:                   /* 'e' style floating point */
918:                   if (ct[0] == 'e') {
919:           
920:                       c = (*fmt)[0];
921:                       ++*fmt;
922:                       f = (long double)va_arg(ap, double);
923:                                   
924:                       return efgtoa(fp, f, c);
925:                   }
926:                   if (!strncmp(ct, "le", CSTRLEN("le"))) {
927:           
928:                       c = (*fmt)[1];
929:                       if (isupper((int)(*fmt)[0])) {
930:                           f = va_arg(ap, long double);
931:                       } else {
932:                           f = (long double)va_arg(ap, double);
933:                       }
934:                       *fmt += CSTRLEN("lf");
935:                                   
936:                       return efgtoa(fp, f, c);
937:                   }
938:           #endif
939:           
940:           #ifdef _VFPF_F
941:                   /* 'f' style floating point */
942:                   if (ct[0] == 'f') {
943:           
944:                       c = (*fmt)[0];
945:                       ++*fmt;
946:                       f = (long double)va_arg(ap, double);
947:                                   
948:                       return efgtoa(fp, f, c);
949:                   }
950:                   if (!strncmp(ct, "lf", CSTRLEN("lf"))) {
951:           
952:                       c = (*fmt)[1];
953:                       if (isupper((int)(*fmt)[0])) {
954:                           f = va_arg(ap, long double);
955:                       } else {
956:                           f = (long double)va_arg(ap, double);
957:                       }
958:                       *fmt += CSTRLEN("lf");
959:                                   
960:                       return efgtoa(fp, f, c);
961:                   }
962:           #endif
963:           
964:           #ifdef _VFPF_G
965:                   /* 'g' style floating point */
966:                   if (ct[0] == 'g') {
967:           
968:                       c = (*fmt)[0];
969:                       ++*fmt;
970:                       f = (long double)va_arg(ap, double);
971:                                   
972:                       return efgtoa(fp, f, c);
973:                   }
974:                   if (!strncmp(ct, "lg", CSTRLEN("lg"))) {
975:           
976:                       c = (*fmt)[1];
977:                       if (isupper((int)(*fmt)[0])) {
978:                           f = va_arg(ap, long double);
979:                       } else {
980:                           f = (long double)va_arg(ap, double);
981:                       }
982:                       *fmt += CSTRLEN("lg");
983:                                   
984:                       return efgtoa(fp, f, c);
985:                   }
986:           #endif
987:           
988:           #ifdef _VFPF_O
989:           #ifdef _VFPF_HH
990:                   /* Character octal integer */
991:                   if (!strncmp(*fmt, "hho", CSTRLEN("hho"))) {
992:           
993:                       *fmt += CSTRLEN("hho");
994:                       llu = (unsigned long long)(unsigned char)va_arg(ap, int);
995:                                   
996:                       return otoa(fp, llu);
997:                   }
998:           #endif
999:           
1000:          #ifdef _VFPF_H
1001:                  /* Short octal integer */
1002:                  if (!strncmp(*fmt, "ho", CSTRLEN("ho"))) {
1003:          
1004:                      *fmt += CSTRLEN("ho");
1005:                      llu = (unsigned long long)(unsigned short)va_arg(ap, int);
1006:                                  
1007:                      return otoa(fp, llu);
1008:                  }
1009:          #endif
1010:          
1011:                  /* Octal integer */
1012:                  if (*fmt[0] == 'o') {
1013:          
1014:                      ++*fmt;
1015:                      llu = (unsigned long long)va_arg(ap, unsigned int);
1016:                                  
1017:                      return otoa(fp, llu);
1018:                  }
1019:          
1020:          #ifdef _VFPF_L
1021:                  /* Long octal integer */
1022:                  if (!strncmp(*fmt, "lo", CSTRLEN("lo"))) {
1023:          
1024:                      *fmt += CSTRLEN("lo");
1025:                      llu = (unsigned long long)va_arg(ap, unsigned long);
1026:                                  
1027:                      return otoa(fp, llu);
1028:                  }
1029:          #endif
1030:          
1031:          #ifdef _VFPF_LL
1032:                  /* Long long octal integer */
1033:                  if (!strncmp(*fmt, "llo", CSTRLEN("llo"))) {
1034:          
1035:                      *fmt += CSTRLEN("llo");
1036:                      llu = va_arg(ap, unsigned long long);
1037:                                  
1038:                      return otoa(fp, llu);
1039:                  }
1040:          #endif
1041:          
1042:          #ifdef _VFPF_J
1043:                  /* uintmax_t octal integer */
1044:                  if (!strncmp(*fmt, "jo", CSTRLEN("jo"))) {
1045:          
1046:                      *fmt += CSTRLEN("jo");
1047:                      llu = (unsigned long long)va_arg(ap, uintmax_t);
1048:                                  
1049:                      return otoa(fp, llu);
1050:                  }
1051:          #endif
1052:          
1053:          #ifdef _VFPF_T
1054:                  /* ptrdiff_t octal integer */
1055:                  if (!strncmp(*fmt, "to", CSTRLEN("to"))) {
1056:          
1057:                      *fmt += CSTRLEN("to");
1058:                      llu = (unsigned long long)va_arg(ap, ptrdiff_t);
1059:                                  
1060:                      return otoa(fp, llu);
1061:                  }
1062:          #endif
1063:          
1064:          #ifdef _VFPF_Z
1065:                  /* size_t octal integer */
1066:                  if (!strncmp(*fmt, "zo", CSTRLEN("zo"))) {
1067:          
1068:                      *fmt += CSTRLEN("zo");
1069:                      llu = (unsigned long long)va_arg(ap, size_t);
1070:                                  
1071:                      return otoa(fp, llu);
1072:                  }
1073:          #endif
1074:          #endif
1075:          
1076:                  /* Character count */
1077:          #ifdef _VFPF_N
1078:          
1079:          #ifdef _VFPF_HH
1080:                  if (!strncmp(*fmt, "hhn", CSTRLEN("hhn"))) {
1081:          
1082:                      *fmt += CSTRLEN("hhn");
1083:                      vp = (void *)va_arg(ap, char *);
1084:                      *(char *)vp = (char)nout;
1085:                      return 0;
1086:                  }
1087:          #endif
1088:          
1089:          #ifdef _VFPF_H
1090:                  if (!strncmp(*fmt, "hn", CSTRLEN("hn"))) {
1091:          
1092:                      *fmt += CSTRLEN("hn");
1093:                      vp = (void *)va_arg(ap, short *);
1094:                      *(short *)vp = (short)nout;
1095:                      return 0;
1096:                  }
1097:          #endif
1098:          
1099:                  if (*fmt[0] == 'n') {
1100:                      ++*fmt;
1101:                      vp = (void *)va_arg(ap, int *);
1102:                      *(int *)vp = nout;
1103:                      return 0;
1104:                  }
1105:          
1106:          #ifdef _VFPF_L
1107:                  if (!strncmp(*fmt, "ln", CSTRLEN("ln"))) {
1108:          
1109:                      *fmt += CSTRLEN("ln");
1110:                      vp = (void *)va_arg(ap, long *);
1111:                      *(long *)vp = (long)nout;
1112:                      return 0;
1113:                  }
1114:          #endif
1115:          
1116:          #ifdef _VFPF_LL
1117:                  if (!strncmp(*fmt, "lln", CSTRLEN("lln"))) {
1118:          
1119:                      *fmt += CSTRLEN("lln");
1120:                      vp = (void *)va_arg(ap, long long *);
1121:                      *(long long *)vp = (long long)nout;
1122:                      return 0;
1123:                  }
1124:          #endif
1125:          
1126:          #ifdef _VFPF_J
1127:                  if (!strncmp(*fmt, "jn", CSTRLEN("jn"))) {
1128:          
1129:                      *fmt += CSTRLEN("jn");
1130:                      vp = (void *)va_arg(ap, uintmax_t *);
1131:                      *(uintmax_t *)vp = (uintmax_t)nout;
1132:                      return 0;
1133:                  }
1134:          #endif
1135:          
1136:          #ifdef _VFPF_T
1137:                  if (!strncmp(*fmt, "tn", CSTRLEN("tn"))) {
1138:          
1139:                      *fmt += CSTRLEN("tn");
1140:                      vp = (void *)va_arg(ap, ptrdiff_t *);
1141:                      *(ptrdiff_t *)vp = (ptrdiff_t)nout;
1142:                      return 0;
1143:                  }
1144:          #endif
1145:          
1146:          #ifdef _VFPF_Z
1147:                  if (!strncmp(*fmt, "zn", CSTRLEN("zn"))) {
1148:          
1149:                      *fmt += CSTRLEN("zn");
1150:                      vp = (void *)va_arg(ap, size_t *);
1151:                      *(size_t *)vp = (size_t)nout;
1152:                      return 0;
1153:                  }
1154:          #endif
1155:          
1156:          #endif
1157:          
1158:          #ifdef _VFPF_P
1159:                  /* Pointer */
1160:                  if (*fmt[0] == 'p') {
1161:          
1162:                      ++*fmt;
1163:                      llu = (unsigned long long)(uintptr_t)va_arg(ap, void *);
1164:                                  
1165:                      return xtoa(fp, llu, 'x');
1166:                  }
1167:          #endif
1168:          
1169:          #ifdef _VFPF_S
1170:                  /* String */
1171:                  if (*fmt[0] == 's') {
1172:          
1173:                      ++*fmt;
1174:                      cp = va_arg(ap, char *);
1175:          
1176:                      return stoa(fp, cp);
1177:                  }
1178:          #endif
1179:          
1180:          #ifdef _VFPF_U
1181:          #ifdef _VFPF_HH
1182:                  /* Unsigned character decimal integer */
1183:                  if (!strncmp(*fmt, "hhu", CSTRLEN("hhu"))) {
1184:          
1185:                      *fmt += CSTRLEN("hhu");
1186:                      llu = (unsigned long long)(unsigned char)va_arg(ap, int);
1187:                                  
1188:                      return utoa(fp, llu);
1189:                  }
1190:          #endif
1191:          
1192:          #ifdef _VFPF_H
1193:                  /* Unsigned short decimal integer */
1194:                  if (!strncmp(*fmt, "hu", CSTRLEN("hu"))) {
1195:          
1196:                      *fmt += CSTRLEN("hu");
1197:                      llu = (unsigned long long)(unsigned short)va_arg(ap, int);
1198:                                  
1199:                      return utoa(fp, llu);
1200:                  }
1201:          #endif
1202:          
1203:                  /* Unsigned decimal integer */
1204:                  if (*fmt[0] == 'u') {
1205:          
1206:                      ++*fmt;
1207:                      llu = (unsigned long long)va_arg(ap, unsigned int);
1208:                                  
1209:                      return utoa(fp, llu);
1210:                  }
1211:          
1212:          #ifdef _VFPF_L
1213:                  /* Unsigned long decimal integer */
1214:                  if (!strncmp(*fmt, "lu", CSTRLEN("lu"))) {
1215:          
1216:                      *fmt += CSTRLEN("lu");
1217:                      llu = (unsigned long long)va_arg(ap, unsigned long);
1218:                                  
1219:                      return utoa(fp, llu);
1220:                  }
1221:          #endif
1222:          
1223:          #ifdef _VFPF_LL
1224:                  /* Unsigned long long decimal integer */
1225:                  if (!strncmp(*fmt, "llu", CSTRLEN("llu"))) {
1226:          
1227:                      *fmt += CSTRLEN("llu");
1228:                      llu = va_arg(ap, unsigned long long);
1229:                                  
1230:                      return utoa(fp, llu);
1231:                  }
1232:          #endif
1233:          
1234:          #ifdef _VFPF_J
1235:                  /* uintmax_t decimal integer */
1236:                  if (!strncmp(*fmt, "ju", CSTRLEN("ju"))) {
1237:          
1238:                      *fmt += CSTRLEN("ju");
1239:                      llu = (unsigned long long)va_arg(ap, uintmax_t);
1240:                                  
1241:                      return utoa(fp, llu);
1242:                  }
1243:          #endif
1244:          
1245:          #ifdef _VFPF_T
1246:                  /* ptrdiff_t decimal integer */
1247:                  if (!strncmp(*fmt, "tu", CSTRLEN("tu"))) {
1248:          
1249:                      *fmt += CSTRLEN("tu");
1250:                      llu = (unsigned long long)va_arg(ap, ptrdiff_t);
1251:                                  
1252:                      return utoa(fp, llu);
1253:                  }
1254:          #endif
1255:          
1256:          #ifdef _VFPF_Z
1257:                  /* size_t decimal integer */
1258:                  if (!strncmp(*fmt, "zu", CSTRLEN("zu"))) {
1259:          
1260:                      *fmt += CSTRLEN("zu");
1261:                      llu = (unsigned long long)va_arg(ap, size_t);
1262:                                  
1263:                      return utoa(fp, llu);
1264:                  }
1265:          #endif
1266:          #endif
1267:          
1268:          #ifdef _VFPF_X
1269:          #ifdef _VFPF_HH
1270:                  /* Character hexadecimal integer */
1271:                  if (!strncmp(*fmt, "hhx", CSTRLEN("hhx")) || \
1272:                      !strncmp(*fmt, "hhX", CSTRLEN("hhX"))) {
1273:          
1274:                      c = (*fmt)[2];
1275:                      *fmt += CSTRLEN("hhx");
1276:                      llu = (unsigned long long)(unsigned char)va_arg(ap, int);
1277:                                  
1278:                      return xtoa(fp, llu, c);
1279:                  }
1280:          #endif
1281:          
1282:          #ifdef _VFPF_H
1283:                  /* Short hexadecimal integer */
1284:                  if (!strncmp(*fmt, "hx", CSTRLEN("hx")) || \
1285:                      !strncmp(*fmt, "hX", CSTRLEN("hX"))) {
1286:          
1287:                      c = (*fmt)[1];
1288:                      *fmt += CSTRLEN("hx");
1289:                      llu = (unsigned long long)(unsigned short)va_arg(ap, int);
1290:                                  
1291:                      return xtoa(fp, llu, c);
1292:                  }
1293:          #endif
1294:          
1295:                  /* Hexadecimal integer */
1296:                  if ((*fmt[0] == 'x') || (*fmt[0] == 'X')) {
1297:          
1298:                      c = (*fmt)[0];
1299:                      ++*fmt;
1300:                      llu = (unsigned long long)va_arg(ap, unsigned int);
1301:                                  
1302:                      return xtoa(fp, llu, c);
1303:                  }
1304:          
1305:          #ifdef _VFPF_L
1306:                  /* Long hexadecimal integer */
1307:                  if (!strncmp(*fmt, "lx", CSTRLEN("lx")) || \
1308:                      !strncmp(*fmt, "lX", CSTRLEN("lX"))) {
1309:          
1310:                      c = (*fmt)[1];
1311:                      *fmt += CSTRLEN("lx");
1312:                      llu = (unsigned long long)va_arg(ap, unsigned long);
1313:                                  
1314:                      return xtoa(fp, llu, c);
1315:                  }
1316:          #endif
1317:          
1318:          #ifdef _VFPF_LL
1319:                  /* Long long hexadecimal integer */
1320:                  if (!strncmp(*fmt, "llx", CSTRLEN("llx")) || \
1321:                      !strncmp(*fmt, "llX", CSTRLEN("llX"))) {
1322:          
1323:                      c = (*fmt)[2];
1324:                      *fmt += CSTRLEN("llx");
1325:                      llu = va_arg(ap, unsigned long long);
1326:                                  
1327:                      return xtoa(fp, llu, c);
1328:                  }
1329:          #endif
1330:          
1331:          #ifdef _VFPF_J
1332:                  /* uintmax_t hexadecimal integer */
1333:                  if (!strncmp(*fmt, "jx", CSTRLEN("jx")) || \
1334:                      !strncmp(*fmt, "jX", CSTRLEN("jX"))) {
1335:          
1336:                      c = (*fmt)[1];
1337:                      *fmt += CSTRLEN("jx");
1338:                      llu = (unsigned long long)va_arg(ap, uintmax_t);
1339:                                  
1340:                      return xtoa(fp, llu, c);
1341:                  }
1342:          #endif
1343:          
1344:          #ifdef _VFPF_T
1345:                  /* ptrdiff_t hexadecimal integer */
1346:                  if (!strncmp(*fmt, "tx", CSTRLEN("tx")) || \
1347:                      !strncmp(*fmt, "tX", CSTRLEN("tX"))) {
1348:          
1349:                      c = (*fmt)[1];
1350:                      *fmt += CSTRLEN("tx");
1351:                      llu = (unsigned long long)va_arg(ap, ptrdiff_t);
1352:                                  
1353:                      return xtoa(fp, llu, c);
1354:                  }
1355:          #endif
1356:          
1357:          #ifdef _VFPF_Z
1358:                  /* size_t hexadecimal integer */
1359:                  if (!strncmp(*fmt, "zx", CSTRLEN("zx")) || \
1360:                      !strncmp(*fmt, "zX", CSTRLEN("zX"))) {
1361:          
1362:                      c = (*fmt)[1];
1363:                      *fmt += CSTRLEN("zx");
1364:                      llu = (unsigned long long)va_arg(ap, size_t);
1365:                                  
1366:                      return xtoa(fp, llu, c);
1367:                  }
1368:          #endif
1369:          #endif
1370:          
1371:                  /* 'Escaped' '%' character */
1372:                  if ((*fmt)[0] == '%') {
28A8  F510     NOP
28AA  F4D9     NOP
28AE  F514     NOP
28B0  F4DA     NOP
28B2  C4DF     MOVFF INDF2, TBLPTR
28B4  F4F6     NOP
28B6  0E25     MOVLW 0x25
28B8  6EF7     MOVWF 0xFF7, ACCESS
28BA  0E00     MOVLW 0x0
28BC  6EF8     MOVWF 0xFF8, ACCESS
28BE  0008     TBLRD*
28C0  50F5     MOVF 0xFF5, W, ACCESS
28C2  0A25     XORLW 0x25
28C4  A4D8     BTFSS 0xFD8, 2, ACCESS
28C6  D016     BRA 0x28F4
1373:                      ++*fmt;
28CA  F510     NOP
28CC  F4D9     NOP
28D0  F514     NOP
28D2  F4DA     NOP
28D4  2ADF     INCF 0xFDF, F, ACCESS
1374:                      fputc((int)'%', fp);
28D6  0E00     MOVLW 0x0
28D8  6E04     MOVWF 0x4, ACCESS
28DA  0E25     MOVLW 0x25
28DC  6E03     MOVWF 0x3, ACCESS
28DE  C542     MOVFF fp, fp
28E0  F505     NOP
28E2  C543     MOVFF 0x543, 0x506
28E4  F506     NOP
28E6  EC37     CALL 0x2E6E, 0
28E8  F017     NOP
1375:                      return 1;
28EA  0E00     MOVLW 0x0
28EC  6E43     MOVWF NVMADR, ACCESS
28EE  0E01     MOVLW 0x1
28F0  6E42     MOVWF NVMLOCK, ACCESS
28F2  0012     RETURN 0
1376:                  }
1377:          
1378:                  /* Unrecognized conversion */
1379:                  ++*fmt;
28F6  F510     NOP
28F8  F4D9     NOP
28FC  F514     NOP
28FE  F4DA     NOP
2900  2ADF     INCF 0xFDF, F, ACCESS
1380:                  return 0;
2902  0E00     MOVLW 0x0
2904  6E43     MOVWF NVMADR, ACCESS
2906  0E00     MOVLW 0x0
2908  6E42     MOVWF NVMLOCK, ACCESS
290A  0012     RETURN 0
1381:              }
1382:          
1383:              /* No conversion, just intervening text */
1384:              fputc((int)(*fmt)[0], fp);
290E  F510     NOP
2910  F4D9     NOP
2914  F514     NOP
2916  F4DA     NOP
2918  C4DF     MOVFF INDF2, TBLPTR
291A  F4F6     NOP
291C  0E25     MOVLW 0x25
291E  6EF7     MOVWF 0xFF7, ACCESS
2920  0E00     MOVLW 0x0
2922  6EF8     MOVWF 0xFF8, ACCESS
2924  0008     TBLRD*
2926  50F5     MOVF 0xFF5, W, ACCESS
2928  6E03     MOVWF 0x3, ACCESS
292A  6A04     CLRF 0x4, ACCESS
292C  C542     MOVFF fp, fp
292E  F505     NOP
2930  C543     MOVFF 0x543, 0x506
2932  F506     NOP
2934  EC37     CALL 0x2E6E, 0
2936  F017     NOP
1385:              ++*fmt;
293A  F510     NOP
293C  F4D9     NOP
2940  F514     NOP
2942  F4DA     NOP
2944  2ADF     INCF 0xFDF, F, ACCESS
2946  D7D1     BRA 0x28EA
1386:              return 1;
1387:          }
1388:          #endif
1389:          
1390:          int vfprintf(FILE *fp, const char *fmt, va_list ap)
2EDA  C554     MOVFF fmt, cfmt
2EDC  F557     NOP
1391:          {
1392:          #ifdef _VFPF_CONVERT
1393:              char *cfmt;
1394:          
1395:              cfmt = (char *)fmt;
1396:              nout = 0;
2EDE  0E00     MOVLW 0x0
2EE0  0105     MOVLB 0x5
2EE2  6F7C     MOVWF WDTTMR, BANKED
2EE4  0E00     MOVLW 0x0
2EE6  6F7B     MOVWF WDTPSH, BANKED
1397:              while (*cfmt) {
2EE8  D013     BRA 0x2F10
2F12  F55C     NOP
2F14  F4F6     NOP
2F16  0E25     MOVLW 0x25
2F18  6EF7     MOVWF 0xFF7, ACCESS
2F1A  0E00     MOVLW 0x0
2F1C  6EF8     MOVWF 0xFF8, ACCESS
2F1E  0008     TBLRD*
2F20  50F5     MOVF 0xFF5, W, ACCESS
2F22  0900     IORLW 0x0
2F24  A4D8     BTFSS 0xFD8, 2, ACCESS
2F26  D7E1     BRA 0x2EEA
1398:                  nout += vfpfcnvrt(fp, &cfmt, ap);
2EEA  C552     MOVFF fp, fp
2EEC  F542     NOP
2EEE  C553     MOVFF 0x553, 0x543
2EF0  F543     NOP
2EF2  0E57     MOVLW 0x57
2EF4  6E44     MOVWF NVMADRH, ACCESS
2EF6  0E05     MOVLW 0x5
2EF8  6E45     MOVWF NVMADRU, ACCESS
2EFA  C555     MOVFF ap, ap
2EFC  F546     NOP
2EFE  C556     MOVFF 0x556, 0x547
2F00  F547     NOP
2F02  ECC7     CALL 0x278E, 0
2F04  F013     NOP
2F06  5042     MOVF NVMLOCK, W, ACCESS
2F08  0105     MOVLB 0x5
2F0A  277B     ADDWF WDTPSH, F, BANKED
2F0C  5043     MOVF NVMADR, W, ACCESS
2F0E  237C     ADDWFC WDTTMR, F, BANKED
1399:              }
1400:              return nout;
2F28  C57B     MOVFF nout, fp
2F2A  F552     NOP
2F2C  C57C     MOVFF 0x57C, 0x553
2F2E  F553     NOP
1401:          #else
1402:              return fputs(fmt, fp);
1403:          #endif
1404:          }
2F30  0012     RETURN 0
---  /opt/microchip/xc8/v2.32/pic/sources/c99/common/aomod.c  -------------------------------------------
1:             // long long signed unsigned modulus
2:             
3:             #pragma warning disable 1516
4:             
5:             signed long long int
6:             #ifdef __PICC__
7:             __aomod(signed long long int divisor, signed long long int dividend)
8:             #else
9:             __aomod(signed long long int dividend, signed long long int divisor)
2A90  0E00     MOVLW 0x0
2A92  6E12     MOVWF 0x12, ACCESS
10:            #endif
11:            {
12:            	unsigned char	counter, sign;
13:            
14:            	sign = 0;
15:            	if(dividend < 0) {
2A94  AE08     BTFSS 0x8, 7, ACCESS
2A96  D012     BRA 0x2ABC
16:            		dividend = -dividend;
2A98  1E08     COMF 0x8, F, ACCESS
2A9A  1E07     COMF 0x7, F, ACCESS
2A9C  1E06     COMF 0x6, F, ACCESS
2A9E  1E05     COMF 0x5, F, ACCESS
2AA0  1E04     COMF 0x4, F, ACCESS
2AA2  1E03     COMF 0x3, F, ACCESS
2AA4  1E02     COMF 0x2, F, ACCESS
2AA6  6C01     NEGF 0x1, ACCESS
2AA8  0E00     MOVLW 0x0
2AAA  2202     ADDWFC 0x2, F, ACCESS
2AAC  2203     ADDWFC 0x3, F, ACCESS
2AAE  2204     ADDWFC 0x4, F, ACCESS
2AB0  2205     ADDWFC 0x5, F, ACCESS
2AB2  2206     ADDWFC 0x6, F, ACCESS
2AB4  2207     ADDWFC 0x7, F, ACCESS
2AB6  2208     ADDWFC 0x8, F, ACCESS
17:            		sign = 1;
2AB8  0E01     MOVLW 0x1
2ABA  6E12     MOVWF 0x12, ACCESS
18:            	}
19:            	if(divisor < 0)
2ABC  AE10     BTFSS 0x10, 7, ACCESS
2ABE  D010     BRA 0x2AE0
20:            		divisor = -divisor;
2AC0  1E10     COMF 0x10, F, ACCESS
2AC2  1E0F     COMF 0xF, F, ACCESS
2AC4  1E0E     COMF 0xE, F, ACCESS
2AC6  1E0D     COMF 0xD, F, ACCESS
2AC8  1E0C     COMF 0xC, F, ACCESS
2ACA  1E0B     COMF 0xB, F, ACCESS
2ACC  1E0A     COMF 0xA, F, ACCESS
2ACE  6C09     NEGF 0x9, ACCESS
2AD0  0E00     MOVLW 0x0
2AD2  220A     ADDWFC 0xA, F, ACCESS
2AD4  220B     ADDWFC 0xB, F, ACCESS
2AD6  220C     ADDWFC 0xC, F, ACCESS
2AD8  220D     ADDWFC 0xD, F, ACCESS
2ADA  220E     ADDWFC 0xE, F, ACCESS
2ADC  220F     ADDWFC 0xF, F, ACCESS
2ADE  2210     ADDWFC 0x10, F, ACCESS
21:            	if(divisor != 0) {
2AE0  5009     MOVF 0x9, W, ACCESS
2AE2  100A     IORWF 0xA, W, ACCESS
2AE4  100B     IORWF 0xB, W, ACCESS
2AE6  100C     IORWF 0xC, W, ACCESS
2AE8  100D     IORWF 0xD, W, ACCESS
2AEA  100E     IORWF 0xE, W, ACCESS
2AEC  100F     IORWF 0xF, W, ACCESS
2AEE  1010     IORWF 0x10, W, ACCESS
2AF0  B4D8     BTFSC 0xFD8, 2, ACCESS
2AF2  D03C     BRA 0x2B6C
22:            		counter = 1;
2AF4  0E01     MOVLW 0x1
2AF6  6E11     MOVWF 0x11, ACCESS
23:            		while(((unsigned long long)divisor & 0x8000000000000000ULL) == 0) {
2AF8  D00A     BRA 0x2B0E
2B0E  AE10     BTFSS 0x10, 7, ACCESS
2B10  D7F4     BRA 0x2AFA
24:            			divisor <<= 1;
2AFA  90D8     BCF 0xFD8, 0, ACCESS
2AFC  3609     RLCF 0x9, F, ACCESS
2AFE  360A     RLCF 0xA, F, ACCESS
2B00  360B     RLCF 0xB, F, ACCESS
2B02  360C     RLCF 0xC, F, ACCESS
2B04  360D     RLCF 0xD, F, ACCESS
2B06  360E     RLCF 0xE, F, ACCESS
2B08  360F     RLCF 0xF, F, ACCESS
2B0A  3610     RLCF 0x10, F, ACCESS
25:            			counter++;
2B0C  2A11     INCF 0x11, F, ACCESS
26:            		}
27:            		do {
28:            			if((unsigned long long)divisor <= (unsigned long long)dividend)
2B12  5009     MOVF 0x9, W, ACCESS
2B14  5C01     SUBWF 0x1, W, ACCESS
2B16  500A     MOVF 0xA, W, ACCESS
2B18  5802     SUBWFB 0x2, W, ACCESS
2B1A  500B     MOVF 0xB, W, ACCESS
2B1C  5803     SUBWFB 0x3, W, ACCESS
2B1E  500C     MOVF 0xC, W, ACCESS
2B20  5804     SUBWFB 0x4, W, ACCESS
2B22  500D     MOVF 0xD, W, ACCESS
2B24  5805     SUBWFB 0x5, W, ACCESS
2B26  500E     MOVF 0xE, W, ACCESS
2B28  5806     SUBWFB 0x6, W, ACCESS
2B2A  500F     MOVF 0xF, W, ACCESS
2B2C  5807     SUBWFB 0x7, W, ACCESS
2B2E  5010     MOVF 0x10, W, ACCESS
2B30  5808     SUBWFB 0x8, W, ACCESS
2B32  A0D8     BTFSS 0xFD8, 0, ACCESS
2B34  D010     BRA 0x2B56
29:            				dividend -= divisor;
2B36  5009     MOVF 0x9, W, ACCESS
2B38  5E01     SUBWF 0x1, F, ACCESS
2B3A  500A     MOVF 0xA, W, ACCESS
2B3C  5A02     SUBWFB 0x2, F, ACCESS
2B3E  500B     MOVF 0xB, W, ACCESS
2B40  5A03     SUBWFB 0x3, F, ACCESS
2B42  500C     MOVF 0xC, W, ACCESS
2B44  5A04     SUBWFB 0x4, F, ACCESS
2B46  500D     MOVF 0xD, W, ACCESS
2B48  5A05     SUBWFB 0x5, F, ACCESS
2B4A  500E     MOVF 0xE, W, ACCESS
2B4C  5A06     SUBWFB 0x6, F, ACCESS
2B4E  500F     MOVF 0xF, W, ACCESS
2B50  5A07     SUBWFB 0x7, F, ACCESS
2B52  5010     MOVF 0x10, W, ACCESS
2B54  5A08     SUBWFB 0x8, F, ACCESS
30:            			*(unsigned long long int *)&divisor >>= 1;
2B56  90D8     BCF 0xFD8, 0, ACCESS
2B58  3210     RRCF 0x10, F, ACCESS
2B5A  320F     RRCF 0xF, F, ACCESS
2B5C  320E     RRCF 0xE, F, ACCESS
2B5E  320D     RRCF 0xD, F, ACCESS
2B60  320C     RRCF 0xC, F, ACCESS
2B62  320B     RRCF 0xB, F, ACCESS
2B64  320A     RRCF 0xA, F, ACCESS
2B66  3209     RRCF 0x9, F, ACCESS
31:            		} while(--counter != 0);
2B68  2E11     DECFSZ 0x11, F, ACCESS
2B6A  D7D3     BRA 0x2B12
32:            	}
33:            	if(sign)
2B6C  5012     MOVF 0x12, W, ACCESS
2B6E  B4D8     BTFSC 0xFD8, 2, ACCESS
2B70  D010     BRA 0x2B92
34:            		dividend = -dividend;
2B72  1E08     COMF 0x8, F, ACCESS
2B74  1E07     COMF 0x7, F, ACCESS
2B76  1E06     COMF 0x6, F, ACCESS
2B78  1E05     COMF 0x5, F, ACCESS
2B7A  1E04     COMF 0x4, F, ACCESS
2B7C  1E03     COMF 0x3, F, ACCESS
2B7E  1E02     COMF 0x2, F, ACCESS
2B80  6C01     NEGF 0x1, ACCESS
2B82  0E00     MOVLW 0x0
2B84  2202     ADDWFC 0x2, F, ACCESS
2B86  2203     ADDWFC 0x3, F, ACCESS
2B88  2204     ADDWFC 0x4, F, ACCESS
2B8A  2205     ADDWFC 0x5, F, ACCESS
2B8C  2206     ADDWFC 0x6, F, ACCESS
2B8E  2207     ADDWFC 0x7, F, ACCESS
2B90  2208     ADDWFC 0x8, F, ACCESS
35:            	return dividend;
2B92  C501     MOVFF __pcstackCOMRAM, __pcstackCOMRAM
2B94  F501     NOP
2B96  C502     MOVFF txData, txData
2B98  F502     NOP
2B9A  C503     MOVFF a, a
2B9C  F503     NOP
2B9E  C504     MOVFF 0x504, 0x504
2BA0  F504     NOP
2BA2  C505     MOVFF fp, fp
2BA4  F505     NOP
2BA6  C506     MOVFF 0x506, 0x506
2BA8  F506     NOP
2BAA  C507     MOVFF 0x507, 0x507
2BAC  F507     NOP
2BAE  C508     MOVFF 0x508, 0x508
2BB0  F508     NOP
36:            }
2BB2  0012     RETURN 0
---  /opt/microchip/xc8/v2.32/pic/sources/c99/common/aodiv.c  -------------------------------------------
1:             // long long signed unsigned division
2:             
3:             #pragma warning disable 1516
4:             
5:             signed long long int
6:             #ifdef __PICC__
7:             __aodiv(signed long long int divisor, signed long long int dividend)
8:             #else
9:             __aodiv(signed long long int dividend, signed long long int divisor)
2948  0E00     MOVLW 0x0
294A  6E12     MOVWF 0x12, ACCESS
10:            #endif
11:            {
12:            	signed long long int	quotient;
13:            	unsigned char	counter, sign;
14:            
15:            	sign = 0;
16:            	if(divisor < 0) {
294C  AE10     BTFSS 0x10, 7, ACCESS
294E  D012     BRA 0x2974
17:            		divisor = -divisor;
2950  1E10     COMF 0x10, F, ACCESS
2952  1E0F     COMF 0xF, F, ACCESS
2954  1E0E     COMF 0xE, F, ACCESS
2956  1E0D     COMF 0xD, F, ACCESS
2958  1E0C     COMF 0xC, F, ACCESS
295A  1E0B     COMF 0xB, F, ACCESS
295C  1E0A     COMF 0xA, F, ACCESS
295E  6C09     NEGF 0x9, ACCESS
2960  0E00     MOVLW 0x0
2962  220A     ADDWFC 0xA, F, ACCESS
2964  220B     ADDWFC 0xB, F, ACCESS
2966  220C     ADDWFC 0xC, F, ACCESS
2968  220D     ADDWFC 0xD, F, ACCESS
296A  220E     ADDWFC 0xE, F, ACCESS
296C  220F     ADDWFC 0xF, F, ACCESS
296E  2210     ADDWFC 0x10, F, ACCESS
18:            		sign = 1;
2970  0E01     MOVLW 0x1
2972  6E12     MOVWF 0x12, ACCESS
19:            	}
20:            	if(dividend < 0) {
2974  AE08     BTFSS 0x8, 7, ACCESS
2976  D012     BRA 0x299C
21:            		dividend = -dividend;
2978  1E08     COMF 0x8, F, ACCESS
297A  1E07     COMF 0x7, F, ACCESS
297C  1E06     COMF 0x6, F, ACCESS
297E  1E05     COMF 0x5, F, ACCESS
2980  1E04     COMF 0x4, F, ACCESS
2982  1E03     COMF 0x3, F, ACCESS
2984  1E02     COMF 0x2, F, ACCESS
2986  6C01     NEGF 0x1, ACCESS
2988  0E00     MOVLW 0x0
298A  2202     ADDWFC 0x2, F, ACCESS
298C  2203     ADDWFC 0x3, F, ACCESS
298E  2204     ADDWFC 0x4, F, ACCESS
2990  2205     ADDWFC 0x5, F, ACCESS
2992  2206     ADDWFC 0x6, F, ACCESS
2994  2207     ADDWFC 0x7, F, ACCESS
2996  2208     ADDWFC 0x8, F, ACCESS
22:            		sign ^= 1;
2998  0E01     MOVLW 0x1
299A  1A12     XORWF 0x12, F, ACCESS
23:            	}
24:            	quotient = 0;
299C  EE21     LFSR 2, 0x513
299E  F113     NOP
29A0  0E07     MOVLW 0x7
29A2  6ADE     CLRF 0xFDE, ACCESS
29A4  06E8     DECF 0xFE8, F, ACCESS
29A6  E2FD     BC 0x29A2
25:            	if(divisor != 0) {
29A8  5009     MOVF 0x9, W, ACCESS
29AA  100A     IORWF 0xA, W, ACCESS
29AC  100B     IORWF 0xB, W, ACCESS
29AE  100C     IORWF 0xC, W, ACCESS
29B0  100D     IORWF 0xD, W, ACCESS
29B2  100E     IORWF 0xE, W, ACCESS
29B4  100F     IORWF 0xF, W, ACCESS
29B6  1010     IORWF 0x10, W, ACCESS
29B8  B4D8     BTFSC 0xFD8, 2, ACCESS
29BA  D046     BRA 0x2A48
26:            		counter = 1;
29BC  0E01     MOVLW 0x1
29BE  6E11     MOVWF 0x11, ACCESS
27:            		while(((unsigned long long)divisor & 0x8000000000000000ULL) == 0) {
29C0  D00A     BRA 0x29D6
29D6  AE10     BTFSS 0x10, 7, ACCESS
29D8  D7F4     BRA 0x29C2
28:            			divisor <<= 1;
29C2  90D8     BCF 0xFD8, 0, ACCESS
29C4  3609     RLCF 0x9, F, ACCESS
29C6  360A     RLCF 0xA, F, ACCESS
29C8  360B     RLCF 0xB, F, ACCESS
29CA  360C     RLCF 0xC, F, ACCESS
29CC  360D     RLCF 0xD, F, ACCESS
29CE  360E     RLCF 0xE, F, ACCESS
29D0  360F     RLCF 0xF, F, ACCESS
29D2  3610     RLCF 0x10, F, ACCESS
29:            			counter++;
29D4  2A11     INCF 0x11, F, ACCESS
30:            		}
31:            		do {
32:            			quotient <<= 1;
29DA  90D8     BCF 0xFD8, 0, ACCESS
29DC  3613     RLCF 0x13, F, ACCESS
29DE  3614     RLCF 0x14, F, ACCESS
29E0  3615     RLCF 0x15, F, ACCESS
29E2  3616     RLCF 0x16, F, ACCESS
29E4  3617     RLCF 0x17, F, ACCESS
29E6  3618     RLCF 0x18, F, ACCESS
29E8  3619     RLCF 0x19, F, ACCESS
29EA  361A     RLCF 0x1A, F, ACCESS
33:            			if((unsigned long long)divisor <= (unsigned long long)dividend) {
29EC  5009     MOVF 0x9, W, ACCESS
29EE  5C01     SUBWF 0x1, W, ACCESS
29F0  500A     MOVF 0xA, W, ACCESS
29F2  5802     SUBWFB 0x2, W, ACCESS
29F4  500B     MOVF 0xB, W, ACCESS
29F6  5803     SUBWFB 0x3, W, ACCESS
29F8  500C     MOVF 0xC, W, ACCESS
29FA  5804     SUBWFB 0x4, W, ACCESS
29FC  500D     MOVF 0xD, W, ACCESS
29FE  5805     SUBWFB 0x5, W, ACCESS
2A00  500E     MOVF 0xE, W, ACCESS
2A02  5806     SUBWFB 0x6, W, ACCESS
2A04  500F     MOVF 0xF, W, ACCESS
2A06  5807     SUBWFB 0x7, W, ACCESS
2A08  5010     MOVF 0x10, W, ACCESS
2A0A  5808     SUBWFB 0x8, W, ACCESS
2A0C  A0D8     BTFSS 0xFD8, 0, ACCESS
2A0E  D011     BRA 0x2A32
34:            				dividend -= divisor;
2A10  5009     MOVF 0x9, W, ACCESS
2A12  5E01     SUBWF 0x1, F, ACCESS
2A14  500A     MOVF 0xA, W, ACCESS
2A16  5A02     SUBWFB 0x2, F, ACCESS
2A18  500B     MOVF 0xB, W, ACCESS
2A1A  5A03     SUBWFB 0x3, F, ACCESS
2A1C  500C     MOVF 0xC, W, ACCESS
2A1E  5A04     SUBWFB 0x4, F, ACCESS
2A20  500D     MOVF 0xD, W, ACCESS
2A22  5A05     SUBWFB 0x5, F, ACCESS
2A24  500E     MOVF 0xE, W, ACCESS
2A26  5A06     SUBWFB 0x6, F, ACCESS
2A28  500F     MOVF 0xF, W, ACCESS
2A2A  5A07     SUBWFB 0x7, F, ACCESS
2A2C  5010     MOVF 0x10, W, ACCESS
2A2E  5A08     SUBWFB 0x8, F, ACCESS
35:            				quotient |= 1;
2A30  8013     BSF 0x13, 0, ACCESS
36:            			}
37:            			*(unsigned long long int *)&divisor >>= 1;
2A32  90D8     BCF 0xFD8, 0, ACCESS
2A34  3210     RRCF 0x10, F, ACCESS
2A36  320F     RRCF 0xF, F, ACCESS
2A38  320E     RRCF 0xE, F, ACCESS
2A3A  320D     RRCF 0xD, F, ACCESS
2A3C  320C     RRCF 0xC, F, ACCESS
2A3E  320B     RRCF 0xB, F, ACCESS
2A40  320A     RRCF 0xA, F, ACCESS
2A42  3209     RRCF 0x9, F, ACCESS
38:            		} while(--counter != 0);
2A44  2E11     DECFSZ 0x11, F, ACCESS
2A46  D7C9     BRA 0x29DA
39:            	}
40:            	if(sign)
2A48  5012     MOVF 0x12, W, ACCESS
2A4A  B4D8     BTFSC 0xFD8, 2, ACCESS
2A4C  D010     BRA 0x2A6E
41:            		quotient = -quotient;
2A4E  1E1A     COMF 0x1A, F, ACCESS
2A50  1E19     COMF 0x19, F, ACCESS
2A52  1E18     COMF 0x18, F, ACCESS
2A54  1E17     COMF 0x17, F, ACCESS
2A56  1E16     COMF 0x16, F, ACCESS
2A58  1E15     COMF 0x15, F, ACCESS
2A5A  1E14     COMF 0x14, F, ACCESS
2A5C  6C13     NEGF 0x13, ACCESS
2A5E  0E00     MOVLW 0x0
2A60  2214     ADDWFC 0x14, F, ACCESS
2A62  2215     ADDWFC 0x15, F, ACCESS
2A64  2216     ADDWFC 0x16, F, ACCESS
2A66  2217     ADDWFC 0x17, F, ACCESS
2A68  2218     ADDWFC 0x18, F, ACCESS
2A6A  2219     ADDWFC 0x19, F, ACCESS
2A6C  221A     ADDWFC 0x1A, F, ACCESS
42:            	return quotient;
2A6E  C513     MOVFF fp, __pcstackCOMRAM
2A70  F501     NOP
2A72  C514     MOVFF 0x514, txData
2A74  F502     NOP
2A76  C515     MOVFF buf, a
2A78  F503     NOP
2A7A  C516     MOVFF 0x516, 0x504
2A7C  F504     NOP
2A7E  C517     MOVFF p, fp
2A80  F505     NOP
2A82  C518     MOVFF 0x518, 0x506
2A84  F506     NOP
2A86  C519     MOVFF 0x519, 0x507
2A88  F507     NOP
2A8A  C51A     MOVFF i, 0x508
2A8C  F508     NOP
43:            }
2A8E  0012     RETURN 0
---  /opt/microchip/xc8/v2.32/pic/sources/c99/common/abs.c  ---------------------------------------------
1:             int abs(int a)
2FF4  BE14     BTFSC 0x14, 7, ACCESS
2FF6  D005     BRA 0x3002
2FF8  5014     MOVF 0x14, W, ACCESS
2FFA  E110     BNZ 0x301C
2FFC  0413     DECF 0x13, W, ACCESS
2FFE  B0D8     BTFSC 0xFD8, 0, ACCESS
3000  D00D     BRA 0x301C
3002  C513     MOVFF fp, buf
3004  F515     NOP
3006  C514     MOVFF 0x514, 0x516
3008  F516     NOP
300A  1E15     COMF 0x15, F, ACCESS
300C  1E16     COMF 0x16, F, ACCESS
300E  4A15     INFSNZ 0x15, F, ACCESS
3010  2A16     INCF 0x16, F, ACCESS
3012  C515     MOVFF buf, fp
3014  F513     NOP
3016  C516     MOVFF 0x516, 0x514
3018  F514     NOP
301A  0012     RETURN 0
301C  C513     MOVFF fp, fp
301E  F513     NOP
3020  C514     MOVFF 0x514, 0x514
3022  F514     NOP
2:             {
3:             	return a>0 ? a : -a;
4:             }
3024  0012     RETURN 0
---  /home/maciej/MPLABXProjects/pic18f57q43-adc-periodic-sampling-mplab-mcc.X/mcc_generated_files/uart/src/uart1.c
1:             /**
2:               UART1 Generated Driver File
3:             
4:               @Company
5:                 Microchip Technology Inc.
6:             
7:               @File Name
8:                 uart1.c
9:             
10:              @Summary
11:                This is the generated driver implementation file for the UART1 driver using CCL
12:            
13:              @Description
14:                This source file provides APIs for UART1.
15:                Generation Information :
16:                    Driver Version    :  2.4.0
17:                The generated drivers are tested against the following:
18:                    Compiler          :  XC8 v2.2
19:                    MPLAB             :  Standalone
20:            */
21:            
22:            /*
23:            Copyright (c) [2012-2020] Microchip Technology Inc.  
24:            
25:                All rights reserved.
26:            
27:                You are permitted to use the accompanying software and its derivatives 
28:                with Microchip products. See the Microchip license agreement accompanying 
29:                this software, if any, for additional info regarding your rights and 
30:                obligations.
31:                
32:                MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
33:                WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
34:                LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
35:                AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
36:                LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
37:                LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
38:                THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
39:                LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
40:                OR OTHER SIMILAR COSTS. 
41:                
42:                To the fullest extend allowed by law, Microchip and its licensors 
43:                liability will not exceed the amount of fees, if any, that you paid 
44:                directly to Microchip to use this software. 
45:                
46:                THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
47:                third party software accompanying this software is subject to the terms 
48:                and conditions of the third party's license agreement.  To the extent 
49:                required by third party licenses covering such third party software, 
50:                the terms of such license will apply in lieu of the terms provided in 
51:                this notice or applicable license.  To the extent the terms of such 
52:                third party licenses prohibit any of the restrictions described here, 
53:                such restrictions will not apply to such third party software.
54:            */
55:            
56:            /**
57:              Section: Included Files
58:            */
59:            #include <xc.h>
60:            #include "../uart1.h"
61:            
62:            const struct UART_INTERFACE UART1_Interface = {
63:              .Initialize = UART1_Initialize,
64:              .Write = UART1_Write,
65:              .Read = UART1_Read,
66:              .RxCompleteCallbackRegister = NULL,
67:              .TxCompleteCallbackRegister = NULL,
68:              .ErrorCallbackRegister = UART1_SetErrorHandler,
69:              .FramingErrorCallbackRegister = UART1_SetFramingErrorHandler,
70:              .OverrunErrorCallbackRegister = UART1_SetOverrunErrorHandler,
71:              .ParityErrorCallbackRegister = NULL,
72:              .ChecksumErrorCallbackRegister = NULL,
73:              .IsRxReady = UART1_IsRxReady,
74:              .IsTxReady = UART1_IsTxReady,
75:              .IsTxDone = UART1_IsTxDone
76:            };
77:            
78:            /**
79:              Section: Macro Declarations
80:            */
81:            #define UART1_TX_BUFFER_SIZE 8
82:            #define UART1_RX_BUFFER_SIZE 8
83:            
84:            /**
85:              Section: Global Variables
86:            */
87:            
88:            static volatile uint8_t uart1TxHead = 0;
89:            static volatile uint8_t uart1TxTail = 0;
90:            static volatile uint8_t uart1TxBuffer[UART1_TX_BUFFER_SIZE];
91:            volatile uint8_t uart1TxBufferRemaining;
92:            
93:            static volatile uint8_t uart1RxHead = 0;
94:            static volatile uint8_t uart1RxTail = 0;
95:            static volatile uint8_t uart1RxBuffer[UART1_RX_BUFFER_SIZE];
96:            static volatile uart1_status_t uart1RxStatusBuffer[UART1_RX_BUFFER_SIZE];
97:            volatile uint8_t uart1RxCount;
98:            static volatile uart1_status_t uart1RxLastError;
99:            
100:           /**
101:             Section: UART1 APIs
102:           */
103:           void (*UART1_FramingErrorHandler)(void);
104:           void (*UART1_OverrunErrorHandler)(void);
105:           void (*UART1_ErrorHandler)(void);
106:           
107:           void UART1_DefaultFramingErrorHandler(void);
108:           void UART1_DefaultOverrunErrorHandler(void);
109:           void UART1_DefaultErrorHandler(void);
110:           
111:           void UART1_Initialize(void)
2C9A  90A2     BCF 0xFA2, 0, ACCESS
112:           {
113:               // Disable interrupts before changing states
114:               PIE4bits.U1RXIE = 0;
115:               UART1_SetRxInterruptHandler(UART1_Receive_ISR);
2C9C  0E00     MOVLW 0x0
2C9E  6E01     MOVWF 0x1, ACCESS
2CA0  0E00     MOVLW 0x0
2CA2  6E02     MOVWF 0x2, ACCESS
2CA4  0E00     MOVLW 0x0
2CA6  6E03     MOVWF 0x3, ACCESS
2CA8  ECB6     CALL 0x316C, 0
2CAA  F018     NOP
116:               PIE4bits.U1TXIE = 0;
2CAC  92A2     BCF 0xFA2, 1, ACCESS
117:               UART1_SetTxInterruptHandler(UART1_Transmit_ISR);
2CAE  0E00     MOVLW 0x0
2CB0  6E01     MOVWF 0x1, ACCESS
2CB2  0E00     MOVLW 0x0
2CB4  6E02     MOVWF 0x2, ACCESS
2CB6  0E00     MOVLW 0x0
2CB8  6E03     MOVWF 0x3, ACCESS
2CBA  ECAF     CALL 0x315E, 0
2CBC  F018     NOP
118:               PIE4bits.U1EIE = 0;
2CBE  94A2     BCF 0xFA2, 2, ACCESS
119:               UART1_SetFramingErrorInterruptHandler(UART1_FramingError_ISR);
2CC0  0E00     MOVLW 0x0
2CC2  6E01     MOVWF 0x1, ACCESS
2CC4  0E00     MOVLW 0x0
2CC6  6E02     MOVWF 0x2, ACCESS
2CC8  0E00     MOVLW 0x0
2CCA  6E03     MOVWF 0x3, ACCESS
2CCC  ECC4     CALL 0x3188, 0
2CCE  F018     NOP
120:               PIE4bits.U1IE = 0;
2CD0  96A2     BCF 0xFA2, 3, ACCESS
121:               UART1_SetUartInterruptHandler(UART1_UartInterrupt_ISR);
2CD2  0E00     MOVLW 0x0
2CD4  6E01     MOVWF 0x1, ACCESS
2CD6  0E00     MOVLW 0x0
2CD8  6E02     MOVWF 0x2, ACCESS
2CDA  0E00     MOVLW 0x0
2CDC  6E03     MOVWF 0x3, ACCESS
2CDE  ECA8     CALL 0x3150, 0
2CE0  F018     NOP
122:           
123:               // Set the UART1 module to the options selected in the user interface.
124:               // RXB disabled; 
125:               U1RXB = 0x0;
2CE2  0E00     MOVLW 0x0
2CE4  0102     MOVLB 0x2
2CE6  6FA1     MOVWF 0xA1, BANKED
126:               // RXCHK disabled; 
127:               U1RXCHK = 0x0;
2CE8  0E00     MOVLW 0x0
2CEA  6FA2     MOVWF 0xA2, BANKED
128:               // TXB disabled; 
129:               U1TXB = 0x0;
2CEC  0E00     MOVLW 0x0
2CEE  6FA3     MOVWF 0xA3, BANKED
130:               // TXCHK disabled; 
131:               U1TXCHK = 0x0;
2CF0  0E00     MOVLW 0x0
2CF2  6FA4     MOVWF 0xA4, BANKED
132:               // P1L 0x0; 
133:               U1P1L = 0x0;
2CF4  0E00     MOVLW 0x0
2CF6  6FA5     MOVWF 0xA5, BANKED
134:               // P1H 0x0; 
135:               U1P1H = 0x0;
2CF8  0E00     MOVLW 0x0
2CFA  6FA6     MOVWF 0xA6, BANKED
136:               // P2L 0x0; 
137:               U1P2L = 0x0;
2CFC  0E00     MOVLW 0x0
2CFE  6FA7     MOVWF 0xA7, BANKED
138:               // P2H 0x0; 
139:               U1P2H = 0x0;
2D00  0E00     MOVLW 0x0
2D02  6FA8     MOVWF 0xA8, BANKED
140:               // P3L 0x0; 
141:               U1P3L = 0x0;
2D04  0E00     MOVLW 0x0
2D06  6FA9     MOVWF 0xA9, BANKED
142:               // P3H 0x0; 
143:               U1P3H = 0x0;
2D08  0E00     MOVLW 0x0
2D0A  6FAA     MOVWF 0xAA, BANKED
144:               // MODE Asynchronous 8-bit mode; RXEN disabled; TXEN enabled; ABDEN disabled; BRGS normal speed; 
145:               U1CON0 = 0x20;
2D0C  0E20     MOVLW 0x20
2D0E  6FAB     MOVWF 0xAB, BANKED
146:               // SENDB disabled; BRKOVR disabled; RXBIMD Set RXBKIF on rising RX input; WUE disabled; ON enabled; 
147:               U1CON1 = 0x80;
2D10  0E80     MOVLW 0x80
2D12  6FAC     MOVWF ACTCON, BANKED
148:               // FLO off; TXPOL not inverted; C0EN Add all TX and RX characters; STP Transmit 1Stop bit, receiver verifies first Stop bit; RXPOL not inverted; RUNOVF RX input shifter stops all activity; 
149:               U1CON2 = 0x0;
2D14  0E00     MOVLW 0x0
2D16  6FAD     MOVWF OSCCON1, BANKED
150:               // BRGL 25; 
151:               U1BRGL = 0x19;
2D18  0E19     MOVLW 0x19
2D1A  6FAE     MOVWF OSCCON2, BANKED
152:               // BRGH 0; 
153:               U1BRGH = 0x0;
2D1C  0E00     MOVLW 0x0
2D1E  6FAF     MOVWF OSCCON3, BANKED
154:               // STPMD in middle of first Stop bit; TXWRE No error; 
155:               U1FIFO = 0x0;
2D20  0E00     MOVLW 0x0
2D22  6FB0     MOVWF OSCTUNE, BANKED
156:               // ABDIE disabled; ABDIF Auto-baud not enabled or not complete; WUIF WUE not enabled by software; 
157:               U1UIR = 0x0;
2D24  0E00     MOVLW 0x0
2D26  6FB1     MOVWF OSCFRQ, BANKED
158:               // TXCIF 0x0; RXFOIF not overflowed; RXBKIF No Break detected; CERIF No Checksum error; ABDOVF Not overflowed; 
159:               U1ERRIR = 0x0;
2D28  0E00     MOVLW 0x0
2D2A  6FB2     MOVWF OSCSTAT, BANKED
160:               // TXCIE disabled; RXFOIE disabled; RXBKIE disabled; FERIE disabled; CERIE disabled; ABDOVE disabled; PERIE disabled; TXMTIE disabled; 
161:               U1ERRIE = 0x0;
2D2C  0E00     MOVLW 0x0
2D2E  6FB3     MOVWF OSCEN, BANKED
162:           
163:               UART1_SetFramingErrorHandler(UART1_DefaultFramingErrorHandler);
2D30  0E00     MOVLW 0x0
2D32  6E01     MOVWF 0x1, ACCESS
2D34  0E00     MOVLW 0x0
2D36  6E02     MOVWF 0x2, ACCESS
2D38  0E00     MOVLW 0x0
2D3A  6E03     MOVWF 0x3, ACCESS
2D3C  ECCB     CALL 0x3196, 0
2D3E  F018     NOP
164:               UART1_SetOverrunErrorHandler(UART1_DefaultOverrunErrorHandler);
2D40  0E00     MOVLW 0x0
2D42  6E01     MOVWF 0x1, ACCESS
2D44  0E00     MOVLW 0x0
2D46  6E02     MOVWF 0x2, ACCESS
2D48  0E00     MOVLW 0x0
2D4A  6E03     MOVWF 0x3, ACCESS
2D4C  ECBD     CALL 0x317A, 0
2D4E  F018     NOP
165:               UART1_SetErrorHandler(UART1_DefaultErrorHandler);
2D50  0E00     MOVLW 0x0
2D52  6E01     MOVWF 0x1, ACCESS
2D54  0E00     MOVLW 0x0
2D56  6E02     MOVWF 0x2, ACCESS
2D58  0E00     MOVLW 0x0
2D5A  6E03     MOVWF 0x3, ACCESS
2D5C  ECD2     CALL 0x31A4, 0
2D5E  F018     NOP
166:           
167:               uart1RxLastError.status = 0;
2D60  0E00     MOVLW 0x0
2D62  6E5F     MOVWF 0x5F, ACCESS
168:           
169:           }
2D64  0012     RETURN 0
170:           
171:           bool UART1_IsRxReady(void)
172:           {
173:               return (bool)(PIR4bits.U1RXIF);
174:           }
175:           
176:           bool UART1_is_rx_ready(void)
177:           {    
178:               return UART1_IsRxReady();
179:           }
180:           
181:           bool UART1_IsTxReady(void)
182:           {
183:               return (bool)(PIR4bits.U1TXIF && U1CON0bits.TXEN);
184:           }
185:           
186:           bool UART1_is_tx_ready(void)
187:           {
188:               return UART1_IsTxReady();
189:           }
190:           
191:           bool UART1_IsTxDone(void)
192:           {
193:               return U1ERRIRbits.TXMTIF;
194:           }
195:           
196:           bool UART1_is_tx_done(void)
197:           {
198:               return UART1_IsTxDone();
199:           }
200:           
201:           uart1_status_t UART1_GetLastStatus(void){
202:               return uart1RxLastError;
203:           }
204:           
205:           uart1_status_t UART1_get_last_status(void){
206:               return UART1_GetLastStatus();
207:           }
208:           
209:           
210:           uint8_t UART1_Read(void)
211:           {
212:               while(!PIR4bits.U1RXIF)
213:               {
214:               }
215:           
216:               uart1RxLastError.status = 0;
217:           
218:               if(U1ERRIRbits.FERIF){
219:                   uart1RxLastError.ferr = 1;
220:                   UART1_FramingErrorHandler();
221:               }
222:           
223:               if(U1ERRIRbits.RXFOIF){
224:                   uart1RxLastError.oerr = 1;
225:                   UART1_OverrunErrorHandler();
226:               }
227:           
228:               if(uart1RxLastError.status){
229:                   UART1_ErrorHandler();
230:               }
231:           
232:               return U1RXB;
233:           }
234:           
235:           void UART1_Write(uint8_t txData)
3142  6E01     MOVWF 0x1, ACCESS
236:           {
237:               while(0 == PIR4bits.U1TXIF)
3144  A2B2     BTFSS 0xFB2, 1, ACCESS
3146  D7FE     BRA 0x3144
238:               {
239:               }
240:           
241:               U1TXB = txData;    // Write the data byte to the USART.
314A  F404     NOP
314C  F2A3     NOP
242:           }
314E  0012     RETURN 0
243:           
244:           char getch(void)
245:           {
246:               return UART1_Read();
247:           }
248:           
249:           void putch(char txData)
3206  6E02     MOVWF 0x2, ACCESS
250:           {
251:               UART1_Write(txData);
3208  5002     MOVF 0x2, W, ACCESS
320A  ECA1     CALL 0x3142, 0
320C  F018     NOP
252:           }
320E  0012     RETURN 0
253:           
254:           void UART1_Transmit_ISR(void)
255:           {
256:               // use this default transmit interrupt handler code
257:               if(sizeof(uart1TxBuffer) > uart1TxBufferRemaining)
258:               {
259:                   U1TXB = uart1TxBuffer[uart1TxTail++];
260:                  if(sizeof(uart1TxBuffer) <= uart1TxTail)
261:                   {
262:                       uart1TxTail = 0;
263:                   }
264:                   uart1TxBufferRemaining++;
265:               }
266:               else
267:               {
268:                   PIE4bits.U1TXIE = 0;
269:               }
270:               
271:               // or set custom function using UART1_SetTxInterruptHandler()
272:           }
273:           
274:           void UART1_Receive_ISR(void)
275:           {
276:               // use this default receive interrupt handler code
277:               uart1RxStatusBuffer[uart1RxHead].status = 0;
278:           
279:               if(U1ERRIRbits.FERIF){
280:                   uart1RxStatusBuffer[uart1RxHead].ferr = 1;
281:                   UART1_FramingErrorHandler();
282:               }
283:               
284:               if(U1ERRIRbits.RXFOIF){
285:                   uart1RxStatusBuffer[uart1RxHead].oerr = 1;
286:                   UART1_OverrunErrorHandler();
287:               }
288:               
289:               if(uart1RxStatusBuffer[uart1RxHead].status){
290:                   UART1_ErrorHandler();
291:               } else {
292:                   UART1_RxDataHandler();
293:               }
294:           
295:               // or set custom function using UART1_SetRxInterruptHandler()
296:           }
297:           
298:           void UART1_RxDataHandler(void){
299:               // use this default receive interrupt handler code
300:               uart1RxBuffer[uart1RxHead++] = U1RXB;
301:               if(sizeof(uart1RxBuffer) <= uart1RxHead)
302:               {
303:                   uart1RxHead = 0;
304:               }
305:               uart1RxCount++;
306:           }
307:           
308:           void UART1_DefaultFramingErrorHandler(void){}
309:           
310:           void UART1_DefaultOverrunErrorHandler(void){}
311:           
312:           void UART1_DefaultErrorHandler(void){
313:           }
314:           
315:           void UART1_SetFramingErrorHandler(void (* interruptHandler)(void)){
3196  C501     MOVFF __pcstackCOMRAM, UART1_FramingErrorHandler
3198  F5AD     NOP
319A  C502     MOVFF txData, 0x5AE
319C  F5AE     NOP
319E  C503     MOVFF a, 0x5AF
31A0  F5AF     NOP
316:               UART1_FramingErrorHandler = interruptHandler;
317:           }
31A2  0012     RETURN 0
318:           
319:           void UART1_SetOverrunErrorHandler(void (* interruptHandler)(void)){
317A  C501     MOVFF __pcstackCOMRAM, UART1_OverrunErrorHandler
317C  F5AA     NOP
317E  C502     MOVFF txData, 0x5AB
3180  F5AB     NOP
3182  C503     MOVFF a, 0x5AC
3184  F5AC     NOP
320:               UART1_OverrunErrorHandler = interruptHandler;
321:           }
3186  0012     RETURN 0
322:           
323:           void UART1_SetErrorHandler(void (* interruptHandler)(void)){
31A4  C501     MOVFF __pcstackCOMRAM, UART1_ErrorHandler
31A6  F5A7     NOP
31A8  C502     MOVFF txData, 0x5A8
31AA  F5A8     NOP
31AC  C503     MOVFF a, 0x5A9
31AE  F5A9     NOP
324:               UART1_ErrorHandler = interruptHandler;
325:           }
31B0  0012     RETURN 0
326:           
327:           void UART1_FramingError_ISR(void)
328:           {
329:               // To clear the interrupt condition, all bits in the UxERRIR register must be cleared
330:               U1ERRIR = 0;
331:               
332:               // add your UART1 error interrupt custom code
333:           
334:           }
335:           
336:           void UART1_UartInterrupt_ISR(void)
337:           {
338:               // WUIF must be cleared by software to clear UxIF
339:               U1UIRbits.WUIF = 0;
340:               
341:               // add your UART1 interrupt custom code
342:           }
343:           
344:           void UART1_SetRxInterruptHandler(void (* InterruptHandler)(void)){
316C  C501     MOVFF __pcstackCOMRAM, UART1_RxInterruptHandler
316E  F5C5     NOP
3170  C502     MOVFF txData, 0x5C6
3172  F5C6     NOP
3174  C503     MOVFF a, 0x5C7
3176  F5C7     NOP
345:               UART1_RxInterruptHandler = InterruptHandler;
346:           }
3178  0012     RETURN 0
347:           
348:           void UART1_SetTxInterruptHandler(void (* InterruptHandler)(void)){
315E  C501     MOVFF __pcstackCOMRAM, UART1_TxInterruptHandler
3160  F5C2     NOP
3162  C502     MOVFF txData, 0x5C3
3164  F5C3     NOP
3166  C503     MOVFF a, 0x5C4
3168  F5C4     NOP
349:               UART1_TxInterruptHandler = InterruptHandler;
350:           }
316A  0012     RETURN 0
351:           
352:           void UART1_SetFramingErrorInterruptHandler(void (* InterruptHandler)(void)){
3188  C501     MOVFF __pcstackCOMRAM, UART1_FramingErrorInterruptHandler
318A  F5BF     NOP
318C  C502     MOVFF txData, 0x5C0
318E  F5C0     NOP
3190  C503     MOVFF a, 0x5C1
3192  F5C1     NOP
353:               UART1_FramingErrorInterruptHandler = InterruptHandler;
354:           }
3194  0012     RETURN 0
355:           
356:           void UART1_SetUartInterruptHandler(void (* InterruptHandler)(void)){
3150  C501     MOVFF __pcstackCOMRAM, UART1_UARTInterruptHandler
3152  F5BC     NOP
3154  C502     MOVFF txData, 0x5BD
3156  F5BD     NOP
3158  C503     MOVFF a, 0x5BE
315A  F5BE     NOP
357:               UART1_UARTInterruptHandler = InterruptHandler;
358:           }
315C  0012     RETURN 0
359:           /**
360:             End of File
361:           */
---  /home/maciej/MPLABXProjects/pic18f57q43-adc-periodic-sampling-mplab-mcc.X/mcc_generated_files/timer/src/tmr1.c
1:             /**
2:               TMR1 Generated Driver File
3:             
4:               @Company
5:                 Microchip Technology Inc.
6:             
7:               @File Name
8:                 tmr1.c
9:             
10:              @Summary
11:                This is the generated driver implementation file for the TMR1 driver
12:            
13:              @Description
14:                This source file provides APIs for driver for TMR1.
15:                Generation Information :
16:                    Driver Version    :  3.0.0
17:                The generated drivers are tested against the following:
18:                    Compiler          :  XC8 v2.20
19:                    MPLAB             :  MPLAB X v5.40
20:            */
21:            /*
22:            Copyright (c) [2012-2020] Microchip Technology Inc.  
23:            
24:                All rights reserved.
25:            
26:                You are permitted to use the accompanying software and its derivatives 
27:                with Microchip products. See the Microchip license agreement accompanying 
28:                this software, if any, for additional info regarding your rights and 
29:                obligations.
30:                
31:                MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
32:                WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
33:                LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
34:                AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
35:                LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
36:                LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
37:                THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
38:                LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
39:                OR OTHER SIMILAR COSTS. 
40:                
41:                To the fullest extend allowed by law, Microchip and its licensors 
42:                liability will not exceed the amount of fees, if any, that you paid 
43:                directly to Microchip to use this software. 
44:                
45:                THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
46:                third party software accompanying this software is subject to the terms 
47:                and conditions of the third party's license agreement.  To the extent 
48:                required by third party licenses covering such third party software, 
49:                the terms of such license will apply in lieu of the terms provided in 
50:                this notice or applicable license.  To the extent the terms of such 
51:                third party licenses prohibit any of the restrictions described here, 
52:                such restrictions will not apply to such third party software.
53:            */
54:            
55:            /**
56:              Section: Included Files
57:            */
58:            
59:            #include <xc.h>
60:            #include "../tmr1.h"
61:            
62:            /**
63:              Section: Global Variables Definitions
64:            */
65:            volatile uint16_t timer1ReloadVal;
66:            void (*Timer1_InterruptHandler)(void);
67:            
68:            const struct TMR_INTERFACE Timer1 = {
69:                .Initialize = Timer1_Initialize,
70:                .Start = Timer1_Start,
71:                .Stop = Timer1_Stop,
72:                .PeriodCountSet = Timer1_Write,
73:                .TimeoutCallbackRegister = Timer1_OverflowCallbackRegister,
74:                .Tasks = Timer1_Tasks
75:            };
76:            static void (*Timer1_OverflowCallback)(void);
77:            static void Timer1_DefaultOverflowCallback(void);
78:            
79:            void Timer1_Initialize(void)
2F32  0E00     MOVLW 0x0
2F34  6F1F     MOVWF 0x1F, BANKED
80:            
81:            {
82:                //TGGO done; TGSPM disabled; TGTM disabled; TGPOL low; TMRGE disabled; 
83:                T1GCON = 0x0;
84:                //TGSS T1G_pin; 
85:                T1GATE = 0x0;
2F36  0E00     MOVLW 0x0
2F38  6F20     MOVWF 0x20, BANKED
86:                //TMRCS MFINTOSC_31.25kHz; 
87:                T1CLK = 0x6;
2F3A  0E06     MOVLW 0x6
2F3C  6F21     MOVWF 0x21, BANKED
88:                //TMRH 194; 
89:                TMR1H = 0xC2;
2F3E  0EC2     MOVLW 0xC2
2F40  6F1D     MOVWF 0x1D, BANKED
90:                //TMRL 247; 
91:                TMR1L = 0xF7;
2F42  0EF7     MOVLW 0xF7
2F44  6F1C     MOVWF 0x1C, BANKED
92:            
93:                // Load the TMR1 value to reload variable
94:                timer1ReloadVal=(uint16_t)((TMR1H << 8) | TMR1L);
2F46  511C     MOVF 0x1C, W, BANKED
2F4A  FC74     NOP
2F4C  F504     NOP
2F4E  6A05     CLRF 0x5, ACCESS
2F50  C504     MOVFF 0x504, fp
2F52  F505     NOP
2F54  6A04     CLRF 0x4, ACCESS
2F56  1004     IORWF 0x4, W, ACCESS
2F58  0105     MOVLB 0x5
2F5A  6FCB     MOVWF 0xCB, BANKED
2F5C  5005     MOVF 0x5, W, ACCESS
2F5E  6FCC     MOVWF 0xCC, BANKED
95:            
96:                //Set default callback for TMR1 overflow interrupt
97:                Timer1_OverflowCallbackRegister(Timer1_DefaultOverflowCallback);
2F60  0E00     MOVLW 0x0
2F62  6E01     MOVWF 0x1, ACCESS
2F64  0E00     MOVLW 0x0
2F66  6E02     MOVWF 0x2, ACCESS
2F68  0E00     MOVLW 0x0
2F6A  6E03     MOVWF 0x3, ACCESS
2F6C  ECD9     CALL 0x31B2, 0
2F6E  F018     NOP
98:            
99:                //Clear interrupt flags
100:               PIR3bits.TMR1IF = 0;
2F70  98B1     BCF 0xFB1, 4, ACCESS
101:               PIR3bits.TMR1GIF = 0;
2F72  9AB1     BCF 0xFB1, 5, ACCESS
102:               
103:               //TMRON disabled; TRD16 disabled; nTSYNC do_not_synchronize; TCKPS 1:1; 
104:               T1CON = 0x4;
2F74  0E04     MOVLW 0x4
2F76  0103     MOVLB 0x3
2F78  6F1E     MOVWF 0x1E, BANKED
105:           }
2F7A  0012     RETURN 0
106:           
107:           void Timer1_Start(void)
3210  811E     BSF 0x1E, 0, BANKED
108:           {
109:               // Start the Timer by writing to TMRxON bit
110:               T1CONbits.TMR1ON = 1;
111:           }
3212  0012     RETURN 0
112:           
113:           void Timer1_Stop(void)
114:           {
115:               // Stop the Timer by writing to TMRxON bit
116:               T1CONbits.TMR1ON = 0;
117:           }
118:           
119:           uint16_t Timer1_Read(void)
120:           {
121:               uint16_t readVal;
122:               uint8_t readValHigh;
123:               uint8_t readValLow;
124:               
125:           	
126:               readValLow = TMR1L;
127:               readValHigh = TMR1H;
128:               
129:               readVal = ((uint16_t)readValHigh << 8) | readValLow;
130:           
131:               return readVal;
132:           }
133:           
134:           void Timer1_Write(size_t timerVal)
135:           {
136:               if (T1CONbits.NOT_SYNC == 1)
137:               {
138:                   // Stop the Timer by writing to TMRxON bit
139:                   T1CONbits.TMR1ON = 0;
140:           
141:                   // Write to the Timer1 register
142:                   TMR1H = (uint8_t)(timerVal >> 8);
143:                   TMR1L = (uint8_t)timerVal;
144:           
145:                   // Start the Timer after writing to the register
146:                   T1CONbits.TMR1ON = 1;
147:               }
148:               else
149:               {
150:                   // Write to the Timer1 register
151:                   TMR1H = (uint8_t)(timerVal >> 8);
152:                   TMR1L = (uint8_t)timerVal;
153:               }
154:           }
155:           
156:           void Timer1_Reload(void)
157:           {
158:               Timer1_Write(timer1ReloadVal);
159:           }
160:           
161:           void Timer1_StartSinglePulseAcquisition(void)
162:           {
163:               T1GCONbits.T1GGO = 1;
164:           }
165:           
166:           uint8_t Timer1_CheckGateValueStatus(void)
167:           {
168:               return (T1GCONbits.T1GVAL);
169:           }
170:           
171:           
172:           void Timer1_OverflowCallbackRegister(void (* CallbackHandler)(void))
31B2  C501     MOVFF __pcstackCOMRAM, Timer1_OverflowCallback
31B4  F5B0     NOP
31B6  C502     MOVFF txData, 0x5B1
31B8  F5B1     NOP
31BA  C503     MOVFF a, 0x5B2
31BC  F5B2     NOP
173:           {
174:               Timer1_OverflowCallback = CallbackHandler;
175:           }
31BE  0012     RETURN 0
176:           
177:           static void Timer1_DefaultOverflowCallback(void)
178:           {
179:               //Add your interrupt code here or
180:               //Use Timer1_OverflowCallbackRegister function to use Custom ISR
181:           }
182:           
183:           bool Timer1_HasOverflowOccured(void)
184:           {
185:               return(PIR3bits.TMR1IF);
186:           }
187:           
188:           void Timer1_GateISR(void)
189:           {
190:               // clear the TMR1 interrupt flag
191:               PIR3bits.TMR1GIF = 0;
192:           }
193:           
194:           void Timer1_Tasks(void)
195:           {
196:               if(PIR3bits.TMR1IF)
197:               {
198:                   PIR3bits.TMR1IF = 0;
199:                   Timer1_OverflowCallback();
200:               }
201:           }
202:           
203:           /**
204:             End of File
205:           */
---  /home/maciej/MPLABXProjects/pic18f57q43-adc-periodic-sampling-mplab-mcc.X/mcc_generated_files/system/src/system.c
1:             /**
2:               @Generated CCL Source File
3:             
4:               @Company:
5:                 Microchip Technology Inc.
6:             
7:               @File Name:
8:                 system.c
9:             
10:              @Summary:
11:                This is the system.c file generated using CCL
12:            
13:              @Description:
14:                This header file provides implementations for driver APIs for all modules selected in the GUI.
15:                Generation Information :
16:                    Driver Version    :  2.00
17:                The generated drivers are tested against the following:
18:                    Compiler          :  XC8 v2.20
19:                    MPLAB             :  MPLAB X 5.40
20:            */
21:            
22:            /*
23:            Copyright (c) [2012-2020] Microchip Technology Inc.  
24:            
25:                All rights reserved.
26:            
27:                You are permitted to use the accompanying software and its derivatives 
28:                with Microchip products. See the Microchip license agreement accompanying 
29:                this software, if any, for additional info regarding your rights and 
30:                obligations.
31:                
32:                MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
33:                WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
34:                LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
35:                AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
36:                LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
37:                LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
38:                THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
39:                LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
40:                OR OTHER SIMILAR COSTS. 
41:                
42:                To the fullest extend allowed by law, Microchip and its licensors 
43:                liability will not exceed the amount of fees, if any, that you paid 
44:                directly to Microchip to use this software. 
45:                
46:                THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
47:                third party software accompanying this software is subject to the terms 
48:                and conditions of the third party's license agreement.  To the extent 
49:                required by third party licenses covering such third party software, 
50:                the terms of such license will apply in lieu of the terms provided in 
51:                this notice or applicable license.  To the extent the terms of such 
52:                third party licenses prohibit any of the restrictions described here, 
53:                such restrictions will not apply to such third party software.
54:            */
55:            
56:             /**
57:               Section: Included Files
58:             */
59:            #include "../system.h"
60:            
61:            
62:            void SYSTEM_Initialize(void)
3114  EC67     CALL 0x30CE, 0
3116  F018     NOP
63:            {
64:                CLOCK_Initialize();
65:                PIN_MANAGER_Initialize();
3118  ECDA     CALL 0x2BB4, 0
311A  F015     NOP
66:                ADCC_Initialize();
311C  ECFE     CALL 0x2DFC, 0
311E  F016     NOP
67:                Timer1_Initialize();
3120  EC99     CALL 0x2F32, 0
3122  F017     NOP
68:                UART1_Initialize();
3124  EC4D     CALL 0x2C9A, 0
3126  F016     NOP
69:                INTERRUPT_Initialize();
3128  ECBE     CALL 0x2F7C, 0
312A  F017     NOP
70:            }
312C  0012     RETURN 0
71:            
---  /home/maciej/MPLABXProjects/pic18f57q43-adc-periodic-sampling-mplab-mcc.X/mcc_generated_files/system/src/pins.c
1:             /**
2:               Generated Pins File
3:             
4:               Company:
5:                 Microchip Technology Inc.
6:             
7:               File Name:
8:                 pins.c
9:             
10:              Summary:
11:                This is generated driver implementation for pins. 
12:            
13:              Description:
14:                This file provides implementations for pin APIs for all pins selected in the GUI.
15:            
16:              Generation Information:
17:                Driver Version:  3.0.0
18:            
19:            */
20:            
21:            /*
22:                (c) 2018 Microchip Technology Inc. and its subsidiaries. 
23:                
24:                Subject to your compliance with these terms, you may use Microchip software and any 
25:                derivatives exclusively with Microchip products. It is your responsibility to comply with third party 
26:                license terms applicable to your use of third party software (including open source software) that 
27:                may accompany Microchip software.
28:                
29:                THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER 
30:                EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY 
31:                IMPLIED WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS 
32:                FOR A PARTICULAR PURPOSE.
33:                
34:                IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE, 
35:                INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND 
36:                WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP 
37:                HAS BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO 
38:                THE FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL 
39:                CLAIMS IN ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT 
40:                OF FEES, IF ANY, THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS 
41:                SOFTWARE.
42:            */
43:            
44:            #include "../pins.h"
45:            
46:            
47:            void PIN_MANAGER_Initialize(void)
2BB4  0E00     MOVLW 0x0
2BB6  6EBE     MOVWF 0xFBE, ACCESS
48:            {
49:               /**
50:                LATx registers
51:                */
52:                LATA = 0x0;
53:                LATB = 0x0;
2BB8  0E00     MOVLW 0x0
2BBA  6EBF     MOVWF 0xFBF, ACCESS
54:                LATC = 0x0;
2BBC  0E00     MOVLW 0x0
2BBE  6EC0     MOVWF 0xFC0, ACCESS
55:                LATD = 0x0;
2BC0  0E00     MOVLW 0x0
2BC2  6EC1     MOVWF 0xFC1, ACCESS
56:                LATE = 0x0;
2BC4  0E00     MOVLW 0x0
2BC6  6EC2     MOVWF 0xFC2, ACCESS
57:                LATF = 0x0;
2BC8  0E00     MOVLW 0x0
2BCA  6EC3     MOVWF 0xFC3, ACCESS
58:            
59:                /**
60:                TRISx registers
61:                */
62:                TRISA = 0xFF;
2BCC  68C6     SETF 0xFC6, ACCESS
63:                TRISB = 0xFF;
2BCE  68C7     SETF 0xFC7, ACCESS
64:                TRISC = 0xFF;
2BD0  68C8     SETF 0xFC8, ACCESS
65:                TRISD = 0xFF;
2BD2  68C9     SETF 0xFC9, ACCESS
66:                TRISE = 0xF;
2BD4  0E0F     MOVLW 0xF
2BD6  6ECA     MOVWF 0xFCA, ACCESS
67:                TRISF = 0xFE;
2BD8  0EFE     MOVLW 0xFE
2BDA  6ECB     MOVWF 0xFCB, ACCESS
68:            
69:                /**
70:                ANSELx registers
71:                */
72:                ANSELA = 0xFF;
2BDC  0104     MOVLB 0x4
2BDE  6900     SETF txData, BANKED
73:                ANSELB = 0xFF;
2BE0  6908     SETF 0x8, BANKED
74:                ANSELC = 0xFF;
2BE2  6910     SETF 0x10, BANKED
75:                ANSELD = 0xFF;
2BE4  6918     SETF 0x18, BANKED
76:                ANSELE = 0x7;
2BE6  0E07     MOVLW 0x7
2BE8  6F20     MOVWF 0x20, BANKED
77:                ANSELF = 0xFF;
2BEA  6928     SETF 0x28, BANKED
78:            
79:                /**
80:                WPUx registers
81:                */
82:                WPUA = 0x0;
2BEC  0E00     MOVLW 0x0
2BEE  6F01     MOVWF 0x1, BANKED
83:                WPUB = 0x0;
2BF0  0E00     MOVLW 0x0
2BF2  6F09     MOVWF 0x9, BANKED
84:                WPUC = 0x0;
2BF4  0E00     MOVLW 0x0
2BF6  6F11     MOVWF 0x11, BANKED
85:                WPUD = 0x0;
2BF8  0E00     MOVLW 0x0
2BFA  6F19     MOVWF 0x19, BANKED
86:                WPUE = 0x0;
2BFC  0E00     MOVLW 0x0
2BFE  6F21     MOVWF 0x21, BANKED
87:                WPUF = 0x0;
2C00  0E00     MOVLW 0x0
2C02  6F29     MOVWF 0x29, BANKED
88:            
89:                /**
90:                RxyI2C registers
91:                */
92:                RB1I2C = 0x0;
2C04  0E00     MOVLW 0x0
2C06  0102     MOVLB 0x2
2C08  6F89     MOVWF SPI1BAUD, BANKED
93:                RB2I2C = 0x0;
2C0A  0E00     MOVLW 0x0
2C0C  6F88     MOVWF SPI1TWIDTH, BANKED
94:                RC3I2C = 0x0;
2C0E  0E00     MOVLW 0x0
2C10  6F87     MOVWF SPI1STATUS, BANKED
95:                RC4I2C = 0x0;
2C12  0E00     MOVLW 0x0
2C14  6F86     MOVWF SPI1CON2, BANKED
96:            
97:                /**
98:                ODx registers
99:                */
100:               ODCONA = 0x0;
2C16  0E00     MOVLW 0x0
2C18  0104     MOVLB 0x4
2C1A  6F02     MOVWF 0x2, BANKED
101:               ODCONB = 0x0;
2C1C  0E00     MOVLW 0x0
2C1E  6F0A     MOVWF 0xA, BANKED
102:               ODCONC = 0x0;
2C20  0E00     MOVLW 0x0
2C22  6F12     MOVWF 0x12, BANKED
103:               ODCOND = 0x0;
2C24  0E00     MOVLW 0x0
2C26  6F1A     MOVWF 0x1A, BANKED
104:               ODCONE = 0x0;
2C28  0E00     MOVLW 0x0
2C2A  6F22     MOVWF 0x22, BANKED
105:               ODCONF = 0x0;
2C2C  0E00     MOVLW 0x0
2C2E  6F2A     MOVWF 0x2A, BANKED
106:           
107:               /**
108:               SLRCONx registers
109:               */
110:               SLRCONA = 0xFF;
2C30  6903     SETF 0x3, BANKED
111:               SLRCONB = 0xFF;
2C32  690B     SETF 0xB, BANKED
112:               SLRCONC = 0xFF;
2C34  6913     SETF 0x13, BANKED
113:               SLRCOND = 0xFF;
2C36  691B     SETF 0x1B, BANKED
114:               SLRCONE = 0x7;
2C38  0E07     MOVLW 0x7
2C3A  6F23     MOVWF 0x23, BANKED
115:               SLRCONF = 0xFF;
2C3C  692B     SETF 0x2B, BANKED
116:           
117:               /**
118:               INLVLx registers
119:               */
120:               INLVLA = 0xFF;
2C3E  6904     SETF 0x4, BANKED
121:               INLVLB = 0xFF;
2C40  690C     SETF 0xC, BANKED
122:               INLVLC = 0xFF;
2C42  6914     SETF 0x14, BANKED
123:               INLVLD = 0xFF;
2C44  691C     SETF 0x1C, BANKED
124:               INLVLE = 0xF;
2C46  0E0F     MOVLW 0xF
2C48  6F24     MOVWF 0x24, BANKED
125:               INLVLF = 0xFF;
2C4A  692C     SETF 0x2C, BANKED
126:               /**
127:               PPS registers
128:               */
129:               ADACTPPS = 0xC; //RB4->ADCC:ADACT;
2C4C  0E0C     MOVLW 0xC
2C4E  0102     MOVLB 0x2
2C50  6F69     MOVWF 0x69, BANKED
130:               U1CTSPPS = 0x16; //RC6->UART1:U1CTS;
2C52  0E16     MOVLW 0x16
2C54  6F73     MOVWF CM1PCH, BANKED
131:               U1RXPPS = 0x29; //RF1->UART1:U1RX;
2C56  0E29     MOVLW 0x29
2C58  6F72     MOVWF CM1NCH, BANKED
132:               T1CKIPPS = 0x10; //RC0->TMR1:T1CKI;
2C5A  0E10     MOVLW 0x10
2C5C  6F42     MOVWF NVMLOCK, BANKED
133:               T1GPPS = 0xD; //RB5->TMR1:T1G;
2C5E  0E0D     MOVLW 0xD
2C60  6F43     MOVWF NVMADR, BANKED
134:               RF0PPS = 0x20;  //RF0->UART1:TX1;
2C62  0E20     MOVLW 0x20
2C64  6F29     MOVWF 0x29, BANKED
135:           
136:              /**
137:               IOCx registers 
138:               */
139:               IOCAP = 0x0;
2C66  0E00     MOVLW 0x0
2C68  0104     MOVLB 0x4
2C6A  6F05     MOVWF 0x5, BANKED
140:               IOCAN = 0x0;
2C6C  0E00     MOVLW 0x0
2C6E  6F06     MOVWF 0x6, BANKED
141:               IOCAF = 0x0;
2C70  0E00     MOVLW 0x0
2C72  6F07     MOVWF 0x7, BANKED
142:               IOCBP = 0x0;
2C74  0E00     MOVLW 0x0
2C76  6F0D     MOVWF 0xD, BANKED
143:               IOCBN = 0x0;
2C78  0E00     MOVLW 0x0
2C7A  6F0E     MOVWF 0xE, BANKED
144:               IOCBF = 0x0;
2C7C  0E00     MOVLW 0x0
2C7E  6F0F     MOVWF 0xF, BANKED
145:               IOCCP = 0x0;
2C80  0E00     MOVLW 0x0
2C82  6F15     MOVWF 0x15, BANKED
146:               IOCCN = 0x0;
2C84  0E00     MOVLW 0x0
2C86  6F16     MOVWF 0x16, BANKED
147:               IOCCF = 0x0;
2C88  0E00     MOVLW 0x0
2C8A  6F17     MOVWF 0x17, BANKED
148:               IOCEP = 0x0;
2C8C  0E00     MOVLW 0x0
2C8E  6F25     MOVWF 0x25, BANKED
149:               IOCEN = 0x0;
2C90  0E00     MOVLW 0x0
2C92  6F26     MOVWF 0x26, BANKED
150:               IOCEF = 0x0;
2C94  0E00     MOVLW 0x0
2C96  6F27     MOVWF 0x27, BANKED
151:           
152:           
153:           }
2C98  0012     RETURN 0
154:             
155:           void PIN_MANAGER_IOC(void)
156:           {
157:           }
158:           
159:           /**
160:            End of File
161:           */
---  /home/maciej/MPLABXProjects/pic18f57q43-adc-periodic-sampling-mplab-mcc.X/mcc_generated_files/system/src/interrupt.c
1:             /**
2:               Generated Interrupt Manager Source File
3:             
4:               @Company:
5:                 Microchip Technology Inc.
6:             
7:               @File Name:
8:                 interrupt.c
9:             
10:              @Summary:
11:                This is the Interrupt Manager file generated
12:            
13:              @Description:
14:                This header file provides implementations for global interrupt handling.
15:                For individual peripheral handlers please see the peripheral driver for
16:                all modules selected in the GUI.
17:                Generation Information :
18:                    Driver Version    :  2.03
19:                The generated drivers are tested against the following:
20:                    Compiler          :  XC8 v2.20 or later
21:                    MPLAB 	          :  MPLABX v5.45
22:            */
23:            
24:            /*
25:            Copyright (c) [2012-2020] Microchip Technology Inc.  
26:            
27:                All rights reserved.
28:            
29:                You are permitted to use the accompanying software and its derivatives 
30:                with Microchip products. See the Microchip license agreement accompanying 
31:                this software, if any, for additional info regarding your rights and 
32:                obligations.
33:                
34:                MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
35:                WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
36:                LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
37:                AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
38:                LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
39:                LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
40:                THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
41:                LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
42:                OR OTHER SIMILAR COSTS. 
43:                
44:                To the fullest extend allowed by law, Microchip and its licensors 
45:                liability will not exceed the amount of fees, if any, that you paid 
46:                directly to Microchip to use this software. 
47:                
48:                THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
49:                third party software accompanying this software is subject to the terms 
50:                and conditions of the third party's license agreement.  To the extent 
51:                required by third party licenses covering such third party software, 
52:                the terms of such license will apply in lieu of the terms provided in 
53:                this notice or applicable license.  To the extent the terms of such 
54:                third party licenses prohibit any of the restrictions described here, 
55:                such restrictions will not apply to such third party software.
56:            */
57:            
58:            #include "../../system/interrupt.h"
59:            #include "../../system/system.h"
60:            
61:            void (*INT0_InterruptHandler)(void);
62:            void (*INT1_InterruptHandler)(void);
63:            void (*INT2_InterruptHandler)(void);
64:            
65:            void  INTERRUPT_Initialize (void)
2F7C  9AD6     BCF 0xFD6, 5, ACCESS
66:            {
67:                // Disable Interrupt Priority Vectors (16CXXX Compatibility Mode)
68:                INTCON0bits.IPEN = 0;
69:            
70:                // Clear the interrupt flag
71:                // Set the external interrupt edge detect
72:                EXT_INT0_InterruptFlagClear();   
2F7E  90AF     BCF 0xFAF, 0, ACCESS
73:                EXT_INT0_risingEdgeSet();    
2F80  80D6     BSF 0xFD6, 0, ACCESS
74:                // Set Default Interrupt Handler
75:                INT0_SetInterruptHandler(INT0_DefaultInterruptHandler);
2F82  0E00     MOVLW 0x0
2F84  6E01     MOVWF 0x1, ACCESS
2F86  0E00     MOVLW 0x0
2F88  6E02     MOVWF 0x2, ACCESS
2F8A  0E00     MOVLW 0x0
2F8C  6E03     MOVWF 0x3, ACCESS
2F8E  ECEE     CALL 0x31DC, 0
2F90  F018     NOP
76:                // EXT_INT0_InterruptEnable();
77:            
78:                // Clear the interrupt flag
79:                // Set the external interrupt edge detect
80:                EXT_INT1_InterruptFlagClear();   
2F92  90B4     BCF 0xFB4, 0, ACCESS
81:                EXT_INT1_risingEdgeSet();    
2F94  82D6     BSF 0xFD6, 1, ACCESS
82:                // Set Default Interrupt Handler
83:                INT1_SetInterruptHandler(INT1_DefaultInterruptHandler);
2F96  0E00     MOVLW 0x0
2F98  6E01     MOVWF 0x1, ACCESS
2F9A  0E00     MOVLW 0x0
2F9C  6E02     MOVWF 0x2, ACCESS
2F9E  0E00     MOVLW 0x0
2FA0  6E03     MOVWF 0x3, ACCESS
2FA2  ECE7     CALL 0x31CE, 0
2FA4  F018     NOP
84:                // EXT_INT1_InterruptEnable();
85:            
86:                // Clear the interrupt flag
87:                // Set the external interrupt edge detect
88:                EXT_INT2_InterruptFlagClear();   
2FA6  90B8     BCF 0xFB8, 0, ACCESS
89:                EXT_INT2_risingEdgeSet();    
2FA8  84D6     BSF 0xFD6, 2, ACCESS
90:                // Set Default Interrupt Handler
91:                INT2_SetInterruptHandler(INT2_DefaultInterruptHandler);
2FAA  0E00     MOVLW 0x0
2FAC  6E01     MOVWF 0x1, ACCESS
2FAE  0E00     MOVLW 0x0
2FB0  6E02     MOVWF 0x2, ACCESS
2FB2  0E00     MOVLW 0x0
2FB4  6E03     MOVWF 0x3, ACCESS
2FB6  ECE0     CALL 0x31C0, 0
2FB8  F018     NOP
92:                // EXT_INT2_InterruptEnable();
93:            
94:            }
2FBA  0012     RETURN 0
95:            
96:            void __interrupt() INTERRUPT_InterruptManager (void)
31F8  A49F     BTFSS 0xF9F, 2, ACCESS
31FA  0011     RETFIE 1
31FC  A4AF     BTFSS 0xFAF, 2, ACCESS
31FE  0011     RETFIE 1
97:            {
98:                // interrupt handler
99:                if(PIE1bits.ADIE == 1 && PIR1bits.ADIF == 1)
100:               {
101:                   ADCC_ISR();
3200  EC54     CALL 0x30A8, 0
3202  F018     NOP
102:               }
103:               else
104:               {
105:                   //Unhandled Interrupt
106:               }
107:           }
3204  0011     RETFIE 1
108:           
109:           void INT0_ISR(void)
110:           {
111:               EXT_INT0_InterruptFlagClear();
112:           
113:               // Callback function gets called everytime this ISR executes
114:               INT0_CallBack();    
115:           }
116:           
117:           
118:           void INT0_CallBack(void)
119:           {
120:               // Add your custom callback code here
121:               if(INT0_InterruptHandler)
122:               {
123:                   INT0_InterruptHandler();
124:               }
125:           }
126:           
127:           void INT0_SetInterruptHandler(void (* InterruptHandler)(void)){
31DC  C501     MOVFF __pcstackCOMRAM, INT0_InterruptHandler
31DE  F5B9     NOP
31E0  C502     MOVFF txData, 0x5BA
31E2  F5BA     NOP
31E4  C503     MOVFF a, 0x5BB
31E6  F5BB     NOP
128:               INT0_InterruptHandler = InterruptHandler;
129:           }
31E8  0012     RETURN 0
130:           
131:           void INT0_DefaultInterruptHandler(void){
132:               // add your INT0 interrupt custom code
133:               // or set custom function using INT0_SetInterruptHandler()
134:           }
135:           void INT1_ISR(void)
136:           {
137:               EXT_INT1_InterruptFlagClear();
138:           
139:               // Callback function gets called everytime this ISR executes
140:               INT1_CallBack();    
141:           }
142:           
143:           
144:           void INT1_CallBack(void)
145:           {
146:               // Add your custom callback code here
147:               if(INT1_InterruptHandler)
148:               {
149:                   INT1_InterruptHandler();
150:               }
151:           }
152:           
153:           void INT1_SetInterruptHandler(void (* InterruptHandler)(void)){
31CE  C501     MOVFF __pcstackCOMRAM, INT1_InterruptHandler
31D0  F5B6     NOP
31D2  C502     MOVFF txData, 0x5B7
31D4  F5B7     NOP
31D6  C503     MOVFF a, 0x5B8
31D8  F5B8     NOP
154:               INT1_InterruptHandler = InterruptHandler;
155:           }
31DA  0012     RETURN 0
156:           
157:           void INT1_DefaultInterruptHandler(void){
158:               // add your INT1 interrupt custom code
159:               // or set custom function using INT1_SetInterruptHandler()
160:           }
161:           void INT2_ISR(void)
162:           {
163:               EXT_INT2_InterruptFlagClear();
164:           
165:               // Callback function gets called everytime this ISR executes
166:               INT2_CallBack();    
167:           }
168:           
169:           
170:           void INT2_CallBack(void)
171:           {
172:               // Add your custom callback code here
173:               if(INT2_InterruptHandler)
174:               {
175:                   INT2_InterruptHandler();
176:               }
177:           }
178:           
179:           void INT2_SetInterruptHandler(void (* InterruptHandler)(void)){
31C0  C501     MOVFF __pcstackCOMRAM, INT2_InterruptHandler
31C2  F5B3     NOP
31C4  C502     MOVFF txData, 0x5B4
31C6  F5B4     NOP
31C8  C503     MOVFF a, 0x5B5
31CA  F5B5     NOP
180:               INT2_InterruptHandler = InterruptHandler;
181:           }
31CC  0012     RETURN 0
182:           
183:           void INT2_DefaultInterruptHandler(void){
184:               // add your INT2 interrupt custom code
185:               // or set custom function using INT2_SetInterruptHandler()
186:           }
187:           
188:           /**
189:            End of File
190:           */
---  /home/maciej/MPLABXProjects/pic18f57q43-adc-periodic-sampling-mplab-mcc.X/mcc_generated_files/system/src/clock.c
1:             /**
2:               @Generated CLOCK CONTROL Source File
3:             
4:               @Company:
5:                 Microchip Technology Inc.
6:             
7:               @File Name:
8:                 clock.c
9:             
10:              @Summary:
11:                This is the clock.c file generated using CCL
12:            
13:              @Description:
14:                This header file provides implementations for driver APIs for all modules selected in the GUI.
15:                Generation Information :
16:                    Driver Version    :  2.00
17:                The generated drivers are tested against the following:
18:                    Compiler          :  XC8 v2.20
19:                    MPLAB             :  MPLAB X 5.40
20:            */
21:            
22:            /*
23:            Copyright (c) [2012-2020] Microchip Technology Inc.  
24:            
25:                All rights reserved.
26:            
27:                You are permitted to use the accompanying software and its derivatives 
28:                with Microchip products. See the Microchip license agreement accompanying 
29:                this software, if any, for additional info regarding your rights and 
30:                obligations.
31:                
32:                MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
33:                WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
34:                LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
35:                AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
36:                LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
37:                LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
38:                THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
39:                LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
40:                OR OTHER SIMILAR COSTS. 
41:                
42:                To the fullest extend allowed by law, Microchip and its licensors 
43:                liability will not exceed the amount of fees, if any, that you paid 
44:                directly to Microchip to use this software. 
45:                
46:                THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
47:                third party software accompanying this software is subject to the terms 
48:                and conditions of the third party's license agreement.  To the extent 
49:                required by third party licenses covering such third party software, 
50:                the terms of such license will apply in lieu of the terms provided in 
51:                this notice or applicable license.  To the extent the terms of such 
52:                third party licenses prohibit any of the restrictions described here, 
53:                such restrictions will not apply to such third party software.
54:            */
55:            
56:            #include <xc.h>
57:            #include "../clock.h"
58:            
59:            void CLOCK_Initialize(void)
30CE  0E60     MOVLW 0x60
30D0  0100     MOVLB 0x0
30D2  6FAD     MOVWF OSCCON1, BANKED
60:            {
61:                // Set the CLOCK CONTROL module to the options selected in the user interface.
62:                // NDIV 1; NOSC HFINTOSC; 
63:                OSCCON1 = 0x60;
64:                // 
65:                OSCCON2 = 0x70;
30D4  0E70     MOVLW 0x70
30D6  6FAE     MOVWF OSCCON2, BANKED
66:                // SOSCPWR Low power; CSWHOLD may proceed; 
67:                OSCCON3 = 0x0;
30D8  0E00     MOVLW 0x0
30DA  6FAF     MOVWF OSCCON3, BANKED
68:                // EXTOEN disabled; HFOEN disabled; MFOEN disabled; LFOEN disabled; SOSCEN disabled; ADOEN disabled; 
69:                OSCEN = 0x0;
30DC  0E00     MOVLW 0x0
30DE  6FB3     MOVWF OSCEN, BANKED
70:                // HFFRQ 4_MHz; 
71:                OSCFRQ = 0x2;
30E0  0E02     MOVLW 0x2
30E2  6FB1     MOVWF OSCFRQ, BANKED
72:                // 
73:                OSCSTAT = 0x0;
30E4  0E00     MOVLW 0x0
30E6  6FB2     MOVWF OSCSTAT, BANKED
74:                // TUN undefined; 
75:                OSCTUNE = 0x0;
30E8  0E00     MOVLW 0x0
30EA  6FB0     MOVWF OSCTUNE, BANKED
76:                // ACTEN disabled; ACTUD enabled; 
77:                ACTCON = 0x0;
30EC  0E00     MOVLW 0x0
30EE  6FAC     MOVWF ACTCON, BANKED
78:            }
30F0  0012     RETURN 0
79:            /**
80:             End of File
81:            */
---  /home/maciej/MPLABXProjects/pic18f57q43-adc-periodic-sampling-mplab-mcc.X/mcc_generated_files/adc/src/adcc.c
1:             /**
2:               ADCC Generated Driver File
3:             
4:               @Company
5:                 Microchip Technology Inc.
6:             
7:               @File Name
8:                 adcc.c
9:             
10:              @Summary
11:                This is the generated driver implementation file for the ADCC driver.
12:            
13:              @Description
14:                This source file provides APIs for driver for ADCC.
15:                Generation Information :
16:                    Driver Version    :  2.1.4
17:                The generated drivers are tested against the following:
18:                    Compiler          :  XC8 v2.30
19:                    MPLAB             :  MPLABX v5.45
20:            */
21:            
22:            /*
23:            Copyright (c) [2012-2020] Microchip Technology Inc.  
24:            
25:                All rights reserved.
26:            
27:                You are permitted to use the accompanying software and its derivatives 
28:                with Microchip products. See the Microchip license agreement accompanying 
29:                this software, if any, for additional info regarding your rights and 
30:                obligations.
31:                
32:                MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
33:                WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
34:                LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
35:                AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
36:                LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
37:                LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
38:                THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
39:                LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
40:                OR OTHER SIMILAR COSTS. 
41:                
42:                To the fullest extend allowed by law, Microchip and its licensors 
43:                liability will not exceed the amount of fees, if any, that you paid 
44:                directly to Microchip to use this software. 
45:                
46:                THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
47:                third party software accompanying this software is subject to the terms 
48:                and conditions of the third party's license agreement.  To the extent 
49:                required by third party licenses covering such third party software, 
50:                the terms of such license will apply in lieu of the terms provided in 
51:                this notice or applicable license.  To the extent the terms of such 
52:                third party licenses prohibit any of the restrictions described here, 
53:                such restrictions will not apply to such third party software.
54:            */
55:            
56:            /**
57:              Section: Included Files
58:            */
59:            
60:            #include <xc.h>
61:            #include "../adcc.h"
62:            
63:            /**
64:              Section: ADCC Module Variables
65:            */
66:            static void (*ADCC_ADI_InterruptHandler)(void);
67:            static void ADCC_DefaultADI_ISR(void);
68:            
69:            /**
70:              Section: ADCC Module APIs
71:            */
72:            
73:            void ADCC_Initialize(void)
2DFC  0E00     MOVLW 0x0
2DFE  0103     MOVLB 0x3
2E00  6FD9     MOVWF CLCnSEL1, BANKED
74:            {
75:                // set the ADCC to the options selected in the User Interface
76:                //ADLTHL 0; 
77:                ADLTHL = 0x0;
78:                //ADLTHH 0; 
79:                ADLTHH = 0x0;
2E02  0E00     MOVLW 0x0
2E04  6FDA     MOVWF CLCnSEL2, BANKED
80:                //ADUTHL 0; 
81:                ADUTHL = 0x0;
2E06  0E00     MOVLW 0x0
2E08  6FDB     MOVWF CLCnSEL3, BANKED
82:                //ADUTHH 0; 
83:                ADUTHH = 0x0;
2E0A  0E00     MOVLW 0x0
2E0C  6FDC     MOVWF CLCnGLS0, BANKED
84:                //ADSTPTL 0; 
85:                ADSTPTL = 0x0;
2E0E  0E00     MOVLW 0x0
2E10  6FDF     MOVWF CLCnGLS3, BANKED
86:                //ADSTPTH 0; 
87:                ADSTPTH = 0x0;
2E12  0E00     MOVLW 0x0
2E14  6FE0     MOVWF 0xE0, BANKED
88:                //ADACCU 0x0; 
89:                ADACCU = 0x0;
2E16  0E00     MOVLW 0x0
2E18  6FE5     MOVWF 0xE5, BANKED
90:                //ADRPT 32; 
91:                ADRPT = 0x20;
2E1A  0E20     MOVLW 0x20
2E1C  6FE7     MOVWF 0xE7, BANKED
92:                //ADCHS ANA0; 
93:                ADPCH = 0x0;
2E1E  0E00     MOVLW 0x0
2E20  6FEC     MOVWF DMAnDPTR, BANKED
94:                //ADACQL 0; 
95:                ADACQL = 0x0;
2E22  0E00     MOVLW 0x0
2E24  6FEE     MOVWF DMAnDSZ, BANKED
96:                //ADACQH 0; 
97:                ADACQH = 0x0;
2E26  0E00     MOVLW 0x0
2E28  6FEF     MOVWF DMAnDSZH, BANKED
98:                //ADCAP Additional uC disabled; 
99:                ADCAP = 0x0;
2E2A  0E00     MOVLW 0x0
2E2C  6FF0     MOVWF DMAnDSA, BANKED
100:               //ADPREL 0; 
101:               ADPREL = 0x0;
2E2E  0E00     MOVLW 0x0
2E30  6FF1     MOVWF DMAnDSAH, BANKED
102:               //ADPREH 0; 
103:               ADPREH = 0x0;
2E32  0E00     MOVLW 0x0
2E34  6FF2     MOVWF DMAnSCNT, BANKED
104:               //ADDSEN disabled; ADGPOL digital_low; ADIPEN disabled; ADPPOL Vss; 
105:               ADCON1 = 0x0;
2E36  0E00     MOVLW 0x0
2E38  6FF4     MOVWF DMAnSPTR, BANKED
106:               //ADCRS 5; ADMD Burst_average_mode; ADACLR disabled; ADPSIS RES; 
107:               ADCON2 = 0x53;
2E3A  0E53     MOVLW 0x53
2E3C  6FF5     MOVWF DMAnSPTRH, BANKED
108:               //ADCALC First derivative of Single measurement; ADTMD disabled; ADSOI ADGO not cleared; 
109:               ADCON3 = 0x08;
2E3E  0E08     MOVLW 0x8
2E40  6FF6     MOVWF DMAnSPTRU, BANKED
110:               //ADMATH registers not updated; 
111:               ADSTAT = 0x0;
2E42  0E00     MOVLW 0x0
2E44  6FF7     MOVWF DMAnSSZ, BANKED
112:               //ADNREF VSS; ADPREF VDD; 
113:               ADREF = 0x0;
2E46  0E00     MOVLW 0x0
2E48  6FF8     MOVWF DMAnSSZH, BANKED
114:               //ADACT TMR1; 
115:               ADACT = 0x3;
2E4A  0E03     MOVLW 0x3
2E4C  6FF9     MOVWF DMAnSSA, BANKED
116:               //ADCCS FOSC/8; 
117:               ADCLK = 0x3;
2E4E  0E03     MOVLW 0x3
2E50  6FFA     MOVWF DMAnSSAH, BANKED
118:               //GO_nDONE undefined; ADFM right; ADON enabled; ADCS FOSC; ADCONT disabled; 
119:               ADCON0 = 0x84;
2E52  0E84     MOVLW 0x84
2E54  6FF3     MOVWF DMAnSCNTH, BANKED
120:               
121:               // Clear the ADC interrupt flag
122:               PIR1bits.ADIF = 0;
2E56  94AF     BCF 0xFAF, 2, ACCESS
123:               //Configure interrupt handlers
124:               ADCC_SetADIInterruptHandler(ADCC_DefaultADI_ISR);
2E58  0E14     MOVLW 0x14
2E5A  6E01     MOVWF 0x1, ACCESS
2E5C  0E32     MOVLW 0x32
2E5E  6E02     MOVWF 0x2, ACCESS
2E60  0E00     MOVLW 0x0
2E62  6E03     MOVWF 0x3, ACCESS
2E64  ECF5     CALL 0x31EA, 0
2E66  F018     NOP
125:               // Enabling ADCC interrupt.
126:               PIE1bits.ADIE = 1;
2E68  849F     BSF 0xF9F, 2, ACCESS
127:           
128:               // Clear the ADC Threshold interrupt flag
129:               PIR2bits.ADTIF = 0;
2E6A  90B0     BCF 0xFB0, 0, ACCESS
130:           }
2E6C  0012     RETURN 0
131:           
132:           void ADCC_StartConversion(adcc_channel_t channel)
133:           {
134:               // select the A/D channel
135:               ADPCH = channel;
136:             
137:               // Turn on the ADC module
138:               ADCON0bits.ADON = 1;
139:           
140:               // Start the conversion
141:               ADCON0bits.ADGO = 1;
142:           }
143:           
144:           bool ADCC_IsConversionDone(void)
145:           {
146:               // Start the conversion
147:               return ((unsigned char)(!ADCON0bits.ADGO));
148:           }
149:           
150:           adc_result_t ADCC_GetConversionResult(void)
151:           {
152:               // Return the result
153:               return ((adc_result_t)((ADRESH << 8) + ADRESL));
154:           }
155:           
156:           adc_result_t ADCC_GetSingleConversion(adcc_channel_t channel)
157:           {
158:               // select the A/D channel
159:               ADPCH = channel;  
160:           
161:               // Turn on the ADC module
162:               ADCON0bits.ADON = 1;
163:               
164:               //Disable the continuous mode.
165:               ADCON0bits.ADCONT = 0;
166:           
167:               // Start the conversion
168:               ADCON0bits.ADGO = 1;
169:           
170:           
171:               // Wait for the conversion to finish
172:               while (ADCON0bits.ADGO)
173:               {
174:               }
175:               
176:               
177:               // Conversion finished, return the result
178:               return ((adc_result_t)((ADRESH << 8) + ADRESL));
179:           }
180:           
181:           inline void ADCC_StopConversion(void)
182:           {
183:               //Reset the ADGO bit.
184:               ADCON0bits.ADGO = 0;
185:           }
186:           
187:           inline void ADCC_SetStopOnInterrupt(void)
188:           {
189:               //Set the ADSOI bit.
190:               ADCON3bits.ADSOI = 1;
191:           }
192:           
193:           inline void ADCC_DischargeSampleCapacitor(void)
194:           {
195:               //Set the ADC channel to AVss.
196:               ADPCH = 0x3B;   
197:           }
198:           
199:           void ADCC_LoadAcquisitionRegister(uint16_t acquisitionValue)
200:           {
201:               //Load the ADACQH and ADACQL registers.
202:               ADACQH = (uint8_t) (acquisitionValue >> 8);
203:               ADACQL = (uint8_t) acquisitionValue;  
204:           }
205:           
206:           void ADCC_SetPrechargeTime(uint16_t prechargeTime)
207:           {
208:               //Load the ADPREH and ADPREL registers.
209:               ADPREH = (uint8_t) (prechargeTime >> 8);
210:               ADPREL = (uint8_t) prechargeTime;
211:           }
212:           
213:           void ADCC_SetRepeatCount(uint8_t repeatCount)
214:           {
215:               //Load the ADRPT register.
216:               ADRPT = repeatCount;   
217:           }
218:           
219:           uint8_t ADCC_GetCurrentCountofConversions(void)
220:           {
221:               //Return the contents of ADCNT register
222:               return ADCNT;
223:           }
224:           
225:           inline void ADCC_ClearAccumulator(void)
226:           {
227:               //Reset the ADCON2bits.ADACLR bit.
228:               ADCON2bits.ADACLR = 1;
229:           }
230:           
231:           uint24_t ADCC_GetAccumulatorValue(void)
232:           {
233:               //Return the contents of ADACCU, ADACCH and ADACCL registers
234:               return (((uint24_t)ADACCU << 16)+((uint24_t)ADACCH << 8) + ADACCL);
235:           }
236:           
237:           bool ADCC_HasAccumulatorOverflowed(void)
238:           {
239:               //Return the status of ADSTATbits.ADAOV
240:               return ADSTATbits.ADAOV;
241:           }
242:           
243:           uint16_t ADCC_GetFilterValue(void)
312E  51E2     MOVF 0xE2, W, BANKED
3130  6E04     MOVWF 0x4, ACCESS
3132  6A03     CLRF 0x3, ACCESS
3134  51E1     MOVF 0xE1, W, BANKED
3136  2403     ADDWF 0x3, W, ACCESS
3138  6E01     MOVWF 0x1, ACCESS
313A  0E00     MOVLW 0x0
313C  2004     ADDWFC 0x4, W, ACCESS
313E  6E02     MOVWF 0x2, ACCESS
244:           {
245:               //Return the contents of ADFLTRH and ADFLTRL registers
246:               return ((uint16_t)((ADFLTRH << 8) + ADFLTRL));
247:           }
3140  0012     RETURN 0
248:           
249:           uint16_t ADCC_GetPreviousResult(void)
250:           {
251:               //Return the contents of ADPREVH and ADPREVL registers
252:               return ((uint16_t)((ADPREVH << 8) + ADPREVL));
253:           }
254:           
255:           void ADCC_DefineSetPoint(uint16_t setPoint)
256:           {
257:               //Sets the ADSTPTH and ADSTPTL registers
258:               ADSTPTH = (uint8_t) (setPoint >> 8);
259:               ADSTPTL = (uint8_t) setPoint;
260:           }
261:           
262:           void ADCC_SetUpperThreshold(uint16_t upperThreshold)
263:           {
264:               //Sets the ADUTHH and ADUTHL registers
265:               ADUTHH = (uint8_t) (upperThreshold >> 8);
266:               ADUTHL = (uint8_t) upperThreshold;
267:           }
268:           
269:           void ADCC_SetLowerThreshold(uint16_t lowerThreshold)
270:           {
271:               //Sets the ADLTHH and ADLTHL registers
272:               ADLTHH = (uint8_t) (lowerThreshold >> 8);
273:               ADLTHL = (uint8_t) lowerThreshold;
274:           }
275:           
276:           uint16_t ADCC_GetErrorCalculation(void)
277:           {
278:               //Return the contents of ADERRH and ADERRL registers
279:               return ((uint16_t)((ADERRH << 8) + ADERRL));
280:           }
281:           
282:           inline void ADCC_EnableDoubleSampling(void)
283:           {
284:               //Sets the ADCON1bits.ADDSEN
285:               ADCON1bits.ADDSEN = 1;
286:           }
287:           
288:           inline void ADCC_EnableContinuousConversion(void)
289:           {
290:               //Sets the ADCON0bits.ADCONT
291:               ADCON0bits.ADCONT = 1;
292:           }
293:           
294:           inline void ADCC_DisableContinuousConversion(void)
295:           {
296:               //Resets the ADCON0bits.ADCONT
297:               ADCON0bits.ADCONT = 0;
298:           }
299:           
300:           bool ADCC_HasErrorCrossedUpperThreshold(void)
301:           {
302:               //Returns the value of ADSTATbits.ADUTHR bit.
303:               return ADSTATbits.ADUTHR;
304:           }
305:           
306:           bool ADCC_HasErrorCrossedLowerThreshold(void)
307:           {
308:               //Returns the value of ADSTATbits.ADLTHR bit.
309:               return ADSTATbits.ADLTHR;
310:           }
311:           
312:           uint8_t ADCC_GetConversionStageStatus(void)
313:           {
314:               //Returns the contents of ADSTATbits.ADSTAT field.
315:               return ADSTATbits.ADSTAT;
316:           }
317:           
318:           void ADCC_ISR(void)
30A8  94AF     BCF 0xFAF, 2, ACCESS
319:           {
320:               // Clear the ADCC interrupt flag
321:               PIR1bits.ADIF = 0;
322:           
323:               if (ADCC_ADI_InterruptHandler != NULL)
30AA  0105     MOVLB 0x5
30AC  51C8     MOVF 0xC8, W, BANKED
30AE  11C9     IORWF 0xC9, W, BANKED
30B0  11CA     IORWF 0xCA, W, BANKED
30B2  B4D8     BTFSC 0xFD8, 2, ACCESS
30B4  0012     RETURN 0
324:               {
325:                   ADCC_ADI_InterruptHandler();
30B6  D801     RCALL 0x30BA
30B8  0012     RETURN 0
30BA  0005     PUSH
30BC  6EFA     MOVWF 0xFFA, ACCESS
30BE  51C8     MOVF 0xC8, W, BANKED
30C0  6EFD     MOVWF 0xFFD, ACCESS
30C2  51C9     MOVF 0xC9, W, BANKED
30C4  6EFE     MOVWF 0xFFE, ACCESS
30C6  51CA     MOVF 0xCA, W, BANKED
30C8  6EFF     MOVWF 0xFFF, ACCESS
30CA  50FA     MOVF 0xFFA, W, ACCESS
30CC  0012     RETURN 0
326:               }
327:           }
328:           
329:           void ADCC_SetADIInterruptHandler(void (* InterruptHandler)(void))
31EA  C501     MOVFF __pcstackCOMRAM, ADCC_ADI_InterruptHandler
31EC  F5C8     NOP
31EE  C502     MOVFF txData, 0x5C9
31F0  F5C9     NOP
31F2  C503     MOVFF a, 0x5CA
31F4  F5CA     NOP
330:           {
331:               ADCC_ADI_InterruptHandler = InterruptHandler;
332:           }
31F6  0012     RETURN 0
333:           
334:           static void ADCC_DefaultADI_ISR(void)
3214  0012     RETURN 0
335:           {
336:               //Add your interrupt code here or
337:               //Use ADCC_SetADIInterruptHandler() function to use Custom ISR
338:           }
339:           
---  /home/maciej/MPLABXProjects/pic18f57q43-adc-periodic-sampling-mplab-mcc.X/main.c  ------------------
1:             /*
2:             Copyright (c) [2012-2020] Microchip Technology Inc.  
3:             
4:                 All rights reserved.
5:             
6:                 You are permitted to use the accompanying software and its derivatives 
7:                 with Microchip products. See the Microchip license agreement accompanying 
8:                 this software, if any, for additional info regarding your rights and 
9:                 obligations.
10:                
11:                MICROCHIP SOFTWARE AND DOCUMENTATION ARE PROVIDED "AS IS" WITHOUT 
12:                WARRANTY OF ANY KIND, EITHER EXPRESS OR IMPLIED, INCLUDING WITHOUT 
13:                LIMITATION, ANY WARRANTY OF MERCHANTABILITY, TITLE, NON-INFRINGEMENT 
14:                AND FITNESS FOR A PARTICULAR PURPOSE. IN NO EVENT WILL MICROCHIP OR ITS
15:                LICENSORS BE LIABLE OR OBLIGATED UNDER CONTRACT, NEGLIGENCE, STRICT 
16:                LIABILITY, CONTRIBUTION, BREACH OF WARRANTY, OR OTHER LEGAL EQUITABLE 
17:                THEORY FOR ANY DIRECT OR INDIRECT DAMAGES OR EXPENSES INCLUDING BUT NOT 
18:                LIMITED TO ANY INCIDENTAL, SPECIAL, INDIRECT OR CONSEQUENTIAL DAMAGES, 
19:                OR OTHER SIMILAR COSTS. 
20:                
21:                To the fullest extend allowed by law, Microchip and its licensors 
22:                liability will not exceed the amount of fees, if any, that you paid 
23:                directly to Microchip to use this software. 
24:                
25:                THIRD PARTY SOFTWARE:  Notwithstanding anything to the contrary, any 
26:                third party software accompanying this software is subject to the terms 
27:                and conditions of the third party's license agreement.  To the extent 
28:                required by third party licenses covering such third party software, 
29:                the terms of such license will apply in lieu of the terms provided in 
30:                this notice or applicable license.  To the extent the terms of such 
31:                third party licenses prohibit any of the restrictions described here, 
32:                such restrictions will not apply to such third party software.
33:             */
34:            #include "mcc_generated_files/system/system.h"
35:            
36:            /*
37:                Main application
38:             */
39:            
40:            
41:            int main(void) {
3026  EC8A     CALL 0x3114, 0
3028  F018     NOP
42:                SYSTEM_Initialize();
43:                ADPCH = POT; // Set ADC Positive Channel to POT (RC2);
302A  0E12     MOVLW 0x12
302C  0103     MOVLB 0x3
302E  6FEC     MOVWF DMAnDPTR, BANKED
44:                Timer1_Start(); // Start Timer1 (ADC AutoConversion Trigger);
3030  EC08     CALL 0x3210, 0
3032  F019     NOP
45:            
46:                while (1) {
47:                    // Timer1 Overflow will trigger ADC conversion by setting ADGO in hardware; 
48:                    while (ADCON0bits.ADGO); // Wait here while ADC conversion and calculation is in progress;
3034  B1F3     BTFSC DMAnSCNTH, 0, BANKED
3036  D7FE     BRA 0x3034
49:                    printf("ADC Result %d \r\n", ADCC_GetFilterValue());
3038  0E3A     MOVLW 0x3A
303A  6E58     MOVWF 0x58, ACCESS
303C  EC97     CALL 0x312E, 0
303E  F018     NOP
3040  C501     MOVFF __pcstackCOMRAM, 0x559
3042  F559     NOP
3044  C502     MOVFF txData, 0x55A
3046  F55A     NOP
3048  EC79     CALL 0x30F2, 0
304A  F018     NOP
50:                    while (!ADCON0bits.ADGO); // Wait here until Timer1 triggers ADGO again;
304C  0103     MOVLB 0x3
304E  B1F3     BTFSC DMAnSCNTH, 0, BANKED
3050  D7F1     BRA 0x3034
3052  D7FC     BRA 0x304C
51:                }
52:            }
