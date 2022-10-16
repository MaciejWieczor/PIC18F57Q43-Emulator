Disassembly Listing for C_compile_test
Generated From:
/home/maciej/MPLABXProjects/C_compile_test.X/dist/default/production/C_compile_test.X.production.elf
2022-09-12 22:19:10

---  /tmp/xcXdEDAKH.s  ----------------------------------------------------------------------------------
---  /home/maciej/MPLABXProjects/C_compile_test.X/newmain.c  --------------------------------------------

1FFA2  0100     MOVLB 0x04
1FFA4  0100     CLRF 0xD8, BANKED
1FFA6  0100     MOVLW 0x10
1FFA8  5000     MOVWF 0x00, ACCESS
1FFAA  F000     MOVLW 0x10
1FFAC  0E00     ADDWF 0x00, F, ACCESS
1FFAE  6E02     BC 0x1FFA4
1FFB0  0E8A     BRA 0x1FFAC
1FFB2  6E01     
1FFB4  0100     
1FFB6  0100     
