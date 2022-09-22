Disassembly Listing for C_compile_test
Generated From:
/home/maciej/MPLABXProjects/C_compile_test.X/dist/default/production/C_compile_test.X.production.elf
2022-09-12 22:19:10

---  /tmp/xcXdEDAKH.s  ----------------------------------------------------------------------------------
---  /home/maciej/MPLABXProjects/C_compile_test.X/newmain.c  --------------------------------------------

1FFA6  0100     MOVLB 0x0
1FFA8  0100     NOP  ; append one NOP after this goto
1FFAA  F0FF     NOP
1FFAC  0E03     MOVLW 0x3
1FFAE  6E02     MOVWF 0x2, ACCESS
1FFB0  0E8A     MOVLW 0x8A
1FFB2  6E01     MOVWF 0x1, ACCESS
1FFB4  0100     GOTO 0x1FFA6
1FFB6  0100     NOP
