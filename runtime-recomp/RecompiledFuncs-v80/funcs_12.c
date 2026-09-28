#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void transition_render_barndoor_hor(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C13E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C13E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C13EC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C13F0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C13F4: jal         0x8007B3D0
    // 0x800C13F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C13F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C13FC: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C1400: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C1404: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1408: addiu       $t8, $t8, 0x3648
    ctx->r24 = ADD32(ctx->r24, 0X3648);
    // 0x800C140C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800C1410: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C1414: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C1418: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800C141C: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800C1420: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1424: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C1428: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800C142C: addiu       $a3, $a3, 0x31D0
    ctx->r7 = ADD32(ctx->r7, 0X31D0);
    // 0x800C1430: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C1434: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800C1438: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800C143C: addiu       $t1, $t1, 0x31C0
    ctx->r9 = ADD32(ctx->r9, 0X31C0);
    // 0x800C1440: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800C1444: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x800C1448: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800C144C: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x800C1450: addu        $t6, $t5, $t0
    ctx->r14 = ADD32(ctx->r13, ctx->r8);
    // 0x800C1454: andi        $t7, $t6, 0x6
    ctx->r15 = ctx->r14 & 0X6;
    // 0x800C1458: ori         $t8, $t7, 0x58
    ctx->r24 = ctx->r15 | 0X58;
    // 0x800C145C: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x800C1460: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800C1464: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800C1468: or          $t3, $t2, $at
    ctx->r11 = ctx->r10 | ctx->r1;
    // 0x800C146C: ori         $t4, $t3, 0xE0
    ctx->r12 = ctx->r11 | 0XE0;
    // 0x800C1470: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800C1474: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800C1478: lui         $t3, 0x570
    ctx->r11 = S32(0X570 << 16);
    // 0x800C147C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800C1480: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x800C1484: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800C1488: ori         $t3, $t3, 0x80
    ctx->r11 = ctx->r11 | 0X80;
    // 0x800C148C: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800C1490: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C1494: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800C1498: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800C149C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800C14A0: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800C14A4: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x800C14A8: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x800C14AC: nop

    // 0x800C14B0: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C14B4: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800C14B8: lw          $t6, 0x31C8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X31C8);
    // 0x800C14BC: nop

    // 0x800C14C0: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800C14C4: jal         0x8007B3D0
    // 0x800C14C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C14C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    after_1:
    // 0x800C14CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C14D0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C14D4: jr          $ra
    // 0x800C14D8: nop

    return;
    // 0x800C14D8: nop

;}
RECOMP_FUNC void get_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076924: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80076928: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8007692C: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80076930: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076934: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076938: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x8007693C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80076940: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80076944: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x80076948: addiu       $t8, $t8, 0x4018
    ctx->r24 = ADD32(ctx->r24, 0X4018);
    // 0x8007694C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80076950: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x80076954: jal         0x800D0580
    // 0x80076958: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    osPfsFileState_recomp(rdram, ctx);
        goto after_0;
    // 0x80076958: addiu       $a2, $sp, 0x18
    ctx->r6 = ADD32(ctx->r29, 0X18);
    after_0:
    // 0x8007695C: bne         $v0, $zero, L_8007697C
    if (ctx->r2 != 0) {
        // 0x80076960: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_8007697C;
    }
    // 0x80076960: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x80076964: lw          $t9, 0x18($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18);
    // 0x80076968: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x8007696C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80076970: b           L_8007697C
    // 0x80076974: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
        goto L_8007697C;
    // 0x80076974: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x80076978: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_8007697C:
    // 0x8007697C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076980: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x80076984: jr          $ra
    // 0x80076988: nop

    return;
    // 0x80076988: nop

;}
RECOMP_FUNC void __setInstChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AD98: sll         $v0, $a2, 2
    ctx->r2 = S32(ctx->r6 << 2);
    // 0x8000AD9C: lw          $t6, 0x60($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADA0: addu        $v0, $v0, $a2
    ctx->r2 = ADD32(ctx->r2, ctx->r6);
    // 0x8000ADA4: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
    // 0x8000ADA8: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8000ADAC: sw          $a1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r5;
    // 0x8000ADB0: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADB4: lbu         $t8, 0x1($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X1);
    // 0x8000ADB8: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8000ADBC: sb          $t8, 0x7($t0)
    MEM_B(0X7, ctx->r8) = ctx->r24;
    // 0x8000ADC0: lw          $t2, 0x60($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADC4: lbu         $t1, 0x0($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X0);
    // 0x8000ADC8: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x8000ADCC: sb          $t1, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r9;
    // 0x8000ADD0: lw          $t5, 0x60($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADD4: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x8000ADD8: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000ADDC: sb          $t4, 0x8($t6)
    MEM_B(0X8, ctx->r14) = ctx->r12;
    // 0x8000ADE0: lw          $t9, 0x60($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X60);
    // 0x8000ADE4: lh          $t7, 0xC($a1)
    ctx->r15 = MEM_H(ctx->r5, 0XC);
    // 0x8000ADE8: addu        $t8, $t9, $v0
    ctx->r24 = ADD32(ctx->r25, ctx->r2);
    // 0x8000ADEC: jr          $ra
    // 0x8000ADF0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
    return;
    // 0x8000ADF0: sh          $t7, 0x4($t8)
    MEM_H(0X4, ctx->r24) = ctx->r15;
;}
RECOMP_FUNC void hud_timer_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7FBC: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800A7FC0: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800A7FC4: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800A7FC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A7FCC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A7FD0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A7FD4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A7FD8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A7FDC: lw          $t6, 0x94($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X94);
    // 0x800A7FE0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800A7FE4: sw          $s5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r21;
    // 0x800A7FE8: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800A7FEC: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800A7FF0: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800A7FF4: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800A7FF8: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800A7FFC: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800A8000: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800A8004: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800A8008: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800A800C: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800A8010: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800A8014: sh          $zero, 0x64($sp)
    MEM_H(0X64, ctx->r29) = 0;
    // 0x800A8018: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x800A801C: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x800A8020: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
    // 0x800A8024: bne         $t6, $zero, L_800A8050
    if (ctx->r14 != 0) {
        // 0x800A8028: swc1        $f18, 0x74($sp)
        MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
            goto L_800A8050;
    }
    // 0x800A8028: swc1        $f18, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f18.u32l;
    // 0x800A802C: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800A8030: addiu       $t8, $zero, 0xB
    ctx->r24 = ADD32(0, 0XB);
    // 0x800A8034: addiu       $v0, $zero, 0xB
    ctx->r2 = ADD32(0, 0XB);
    // 0x800A8038: addiu       $v1, $zero, 0xA
    ctx->r3 = ADD32(0, 0XA);
    // 0x800A803C: sw          $t7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r15;
    // 0x800A8040: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800A8044: addiu       $s4, $zero, 0x9
    ctx->r20 = ADD32(0, 0X9);
    // 0x800A8048: b           L_800A8070
    // 0x800A804C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
        goto L_800A8070;
    // 0x800A804C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
L_800A8050:
    // 0x800A8050: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x800A8054: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x800A8058: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800A805C: addiu       $v1, $zero, 0x8
    ctx->r3 = ADD32(0, 0X8);
    // 0x800A8060: sw          $t9, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r25;
    // 0x800A8064: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800A8068: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x800A806C: sw          $t1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r9;
L_800A8070:
    // 0x800A8070: lw          $t2, 0x88($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X88);
    // 0x800A8074: addiu       $s5, $zero, 0xA
    ctx->r21 = ADD32(0, 0XA);
    // 0x800A8078: div         $zero, $t2, $s5
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r21)));
    // 0x800A807C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A8080: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A8084: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A8088: addiu       $s2, $s2, 0x6D04
    ctx->r18 = ADD32(ctx->r18, 0X6D04);
    // 0x800A808C: addiu       $s1, $s1, 0x6D00
    ctx->r17 = ADD32(ctx->r17, 0X6D00);
    // 0x800A8090: addiu       $s0, $s0, 0x6CFC
    ctx->r16 = ADD32(ctx->r16, 0X6CFC);
    // 0x800A8094: addiu       $s3, $sp, 0x60
    ctx->r19 = ADD32(ctx->r29, 0X60);
    // 0x800A8098: sh          $s4, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r20;
    // 0x800A809C: bne         $s5, $zero, L_800A80A8
    if (ctx->r21 != 0) {
        // 0x800A80A0: nop
    
            goto L_800A80A8;
    }
    // 0x800A80A0: nop

    // 0x800A80A4: break       7
    do_break(2148171940);
L_800A80A8:
    // 0x800A80A8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A80AC: bne         $s5, $at, L_800A80C0
    if (ctx->r21 != ctx->r1) {
        // 0x800A80B0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A80C0;
    }
    // 0x800A80B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A80B4: bne         $t2, $at, L_800A80C0
    if (ctx->r10 != ctx->r1) {
        // 0x800A80B8: nop
    
            goto L_800A80C0;
    }
    // 0x800A80B8: nop

    // 0x800A80BC: break       6
    do_break(2148171964);
L_800A80C0:
    // 0x800A80C0: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A80C4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A80C8: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A80CC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A80D0: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x800A80D4: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    // 0x800A80D8: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800A80DC: mflo        $t3
    ctx->r11 = lo;
    // 0x800A80E0: sh          $t3, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r11;
    // 0x800A80E4: jal         0x800AA600
    // 0x800A80E8: nop

    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A80E8: nop

    after_0:
    // 0x800A80EC: lw          $t4, 0x88($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X88);
    // 0x800A80F0: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800A80F4: div         $zero, $t4, $s5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r21)));
    // 0x800A80F8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A80FC: lwc1        $f6, 0x6C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8100: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8104: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800A8108: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A810C: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A8110: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x800A8114: swc1        $f8, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f8.u32l;
    // 0x800A8118: bne         $s5, $zero, L_800A8124
    if (ctx->r21 != 0) {
        // 0x800A811C: nop
    
            goto L_800A8124;
    }
    // 0x800A811C: nop

    // 0x800A8120: break       7
    do_break(2148172064);
L_800A8124:
    // 0x800A8124: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8128: bne         $s5, $at, L_800A813C
    if (ctx->r21 != ctx->r1) {
        // 0x800A812C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A813C;
    }
    // 0x800A812C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8130: bne         $t4, $at, L_800A813C
    if (ctx->r12 != ctx->r1) {
        // 0x800A8134: nop
    
            goto L_800A813C;
    }
    // 0x800A8134: nop

    // 0x800A8138: break       6
    do_break(2148172088);
L_800A813C:
    // 0x800A813C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8140: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A8144: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8148: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A814C: mfhi        $t5
    ctx->r13 = hi;
    // 0x800A8150: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x800A8154: jal         0x800AA600
    // 0x800A8158: nop

    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A8158: nop

    after_1:
    // 0x800A815C: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800A8160: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800A8164: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A8168: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800A816C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A8170: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8174: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A8178: cvt.s.w     $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    ctx->f20.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A817C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800A8180: sh          $zero, 0x78($sp)
    MEM_H(0X78, ctx->r29) = 0;
    // 0x800A8184: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A8188: swc1        $f0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f0.u32l;
    // 0x800A818C: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x800A8190: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800A8194: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800A8198: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A819C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A81A0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A81A4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A81A8: jal         0x800AA600
    // 0x800A81AC: sh          $t6, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r14;
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A81AC: sh          $t6, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r14;
    after_2:
    // 0x800A81B0: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x800A81B4: lw          $t7, 0x54($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X54);
    // 0x800A81B8: div         $zero, $t8, $s5
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r21)));
    // 0x800A81BC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800A81C0: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A81C4: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A81C8: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A81CC: sh          $s4, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r20;
    // 0x800A81D0: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A81D4: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x800A81D8: sub.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x800A81DC: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800A81E0: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x800A81E4: bne         $s5, $zero, L_800A81F0
    if (ctx->r21 != 0) {
        // 0x800A81E8: nop
    
            goto L_800A81F0;
    }
    // 0x800A81E8: nop

    // 0x800A81EC: break       7
    do_break(2148172268);
L_800A81F0:
    // 0x800A81F0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A81F4: bne         $s5, $at, L_800A8208
    if (ctx->r21 != ctx->r1) {
        // 0x800A81F8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8208;
    }
    // 0x800A81F8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A81FC: bne         $t8, $at, L_800A8208
    if (ctx->r24 != ctx->r1) {
        // 0x800A8200: nop
    
            goto L_800A8208;
    }
    // 0x800A8200: nop

    // 0x800A8204: break       6
    do_break(2148172292);
L_800A8208:
    // 0x800A8208: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A820C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A8210: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8214: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8218: mflo        $t9
    ctx->r25 = lo;
    // 0x800A821C: sh          $t9, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r25;
    // 0x800A8220: jal         0x800AA600
    // 0x800A8224: nop

    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A8224: nop

    after_3:
    // 0x800A8228: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x800A822C: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8230: div         $zero, $t1, $s5
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r21)));
    // 0x800A8234: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A8238: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A823C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800A8240: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A8244: swc1        $f16, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f16.u32l;
    // 0x800A8248: bne         $s5, $zero, L_800A8254
    if (ctx->r21 != 0) {
        // 0x800A824C: nop
    
            goto L_800A8254;
    }
    // 0x800A824C: nop

    // 0x800A8250: break       7
    do_break(2148172368);
L_800A8254:
    // 0x800A8254: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A8258: bne         $s5, $at, L_800A826C
    if (ctx->r21 != ctx->r1) {
        // 0x800A825C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A826C;
    }
    // 0x800A825C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8260: bne         $t1, $at, L_800A826C
    if (ctx->r9 != ctx->r1) {
        // 0x800A8264: nop
    
            goto L_800A826C;
    }
    // 0x800A8264: nop

    // 0x800A8268: break       6
    do_break(2148172392);
L_800A826C:
    // 0x800A826C: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8270: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8274: mfhi        $t2
    ctx->r10 = hi;
    // 0x800A8278: sh          $t2, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r10;
    // 0x800A827C: jal         0x800AA600
    // 0x800A8280: nop

    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A8280: nop

    after_4:
    // 0x800A8284: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8288: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800A828C: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A8290: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x800A8294: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800A8298: sh          $zero, 0x78($sp)
    MEM_H(0X78, ctx->r29) = 0;
    // 0x800A829C: add.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f20.fl;
    // 0x800A82A0: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x800A82A4: swc1        $f10, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f10.u32l;
    // 0x800A82A8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A82AC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A82B0: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A82B4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A82B8: jal         0x800AA600
    // 0x800A82BC: sh          $t3, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r11;
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A82BC: sh          $t3, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r11;
    after_5:
    // 0x800A82C0: lw          $t4, 0x90($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X90);
    // 0x800A82C4: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A82C8: div         $zero, $t4, $s5
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r21)));
    // 0x800A82CC: lwc1        $f18, 0x38($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800A82D0: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800A82D4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800A82D8: sh          $s4, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r20;
    // 0x800A82DC: sub.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f20.fl;
    // 0x800A82E0: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x800A82E4: swc1        $f8, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f8.u32l;
    // 0x800A82E8: bne         $s5, $zero, L_800A82F4
    if (ctx->r21 != 0) {
        // 0x800A82EC: nop
    
            goto L_800A82F4;
    }
    // 0x800A82EC: nop

    // 0x800A82F0: break       7
    do_break(2148172528);
L_800A82F4:
    // 0x800A82F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A82F8: bne         $s5, $at, L_800A830C
    if (ctx->r21 != ctx->r1) {
        // 0x800A82FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A830C;
    }
    // 0x800A82FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8300: bne         $t4, $at, L_800A830C
    if (ctx->r12 != ctx->r1) {
        // 0x800A8304: nop
    
            goto L_800A830C;
    }
    // 0x800A8304: nop

    // 0x800A8308: break       6
    do_break(2148172552);
L_800A830C:
    // 0x800A830C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8310: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A8314: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8318: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A831C: mflo        $t5
    ctx->r13 = lo;
    // 0x800A8320: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x800A8324: jal         0x800AA600
    // 0x800A8328: nop

    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A8328: nop

    after_6:
    // 0x800A832C: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x800A8330: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800A8334: div         $zero, $t6, $s5
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r21))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r21)));
    // 0x800A8338: lwc1        $f16, 0x44($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A833C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8340: add.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x800A8344: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800A8348: swc1        $f18, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f18.u32l;
    // 0x800A834C: bne         $s5, $zero, L_800A8358
    if (ctx->r21 != 0) {
        // 0x800A8350: nop
    
            goto L_800A8358;
    }
    // 0x800A8350: nop

    // 0x800A8354: break       7
    do_break(2148172628);
L_800A8358:
    // 0x800A8358: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A835C: bne         $s5, $at, L_800A8370
    if (ctx->r21 != ctx->r1) {
        // 0x800A8360: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A8370;
    }
    // 0x800A8360: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A8364: bne         $t6, $at, L_800A8370
    if (ctx->r14 != ctx->r1) {
        // 0x800A8368: nop
    
            goto L_800A8370;
    }
    // 0x800A8368: nop

    // 0x800A836C: break       6
    do_break(2148172652);
L_800A8370:
    // 0x800A8370: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800A8374: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800A8378: mfhi        $t7
    ctx->r15 = hi;
    // 0x800A837C: sh          $t7, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r15;
    // 0x800A8380: jal         0x800AA600
    // 0x800A8384: nop

    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A8384: nop

    after_7:
    // 0x800A8388: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800A838C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800A8390: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800A8394: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800A8398: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800A839C: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800A83A0: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800A83A4: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800A83A8: lw          $s5, 0x30($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X30);
    extern void dkr_hud_timer_end(uint8_t*, recomp_context*); dkr_hud_timer_end(rdram, ctx);
    // 0x800A83AC: jr          $ra
    // 0x800A83B0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800A83B0: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void particle_allocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B1CB8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B1CBC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B1CC0: beq         $a0, $a1, L_800B1D9C
    if (ctx->r4 == ctx->r5) {
        // 0x800B1CC4: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800B1D9C;
    }
    // 0x800B1CC4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B1CC8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800B1CCC: beq         $a0, $a3, L_800B1E44
    if (ctx->r4 == ctx->r7) {
        // 0x800B1CD0: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800B1E44;
    }
    // 0x800B1CD0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B1CD4: addiu       $a3, $zero, 0x3
    ctx->r7 = ADD32(0, 0X3);
    // 0x800B1CD8: beq         $a0, $a3, L_800B1EE8
    if (ctx->r4 == ctx->r7) {
        // 0x800B1CDC: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800B1EE8;
    }
    // 0x800B1CDC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B1CE0: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x800B1CE4: beq         $a0, $a2, L_800B1F8C
    if (ctx->r4 == ctx->r6) {
        // 0x800B1CE8: lui         $a3, 0x800E
        ctx->r7 = S32(0X800E << 16);
            goto L_800B1F8C;
    }
    // 0x800B1CE8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B1CEC: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    // 0x800B1CF0: bne         $a0, $a3, L_800B202C
    if (ctx->r4 != ctx->r7) {
        // 0x800B1CF4: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800B202C;
    }
    // 0x800B1CF4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B1CF8: addiu       $t0, $t0, 0x2CC0
    ctx->r8 = ADD32(ctx->r8, 0X2CC0);
    // 0x800B1CFC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B1D00: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B1D04: beq         $a0, $zero, L_800B202C
    if (ctx->r4 == 0) {
        // 0x800B1D08: addiu       $t1, $t1, 0x2CB8
        ctx->r9 = ADD32(ctx->r9, 0X2CB8);
            goto L_800B202C;
    }
    // 0x800B1D08: addiu       $t1, $t1, 0x2CB8
    ctx->r9 = ADD32(ctx->r9, 0X2CB8);
    // 0x800B1D0C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800B1D10: lw          $t7, 0x2E54($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X2E54);
    // 0x800B1D14: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800B1D18: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800B1D1C: slt         $at, $t6, $t8
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800B1D20: bne         $at, $zero, L_800B1D48
    if (ctx->r1 != 0) {
        // 0x800B1D24: nop
    
            goto L_800B1D48;
    }
    // 0x800B1D24: nop

    // 0x800B1D28: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B1D2C: addiu       $v0, $v0, 0x2CBC
    ctx->r2 = ADD32(ctx->r2, 0X2CBC);
    // 0x800B1D30: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B1D34: nop

    // 0x800B1D38: bne         $t9, $zero, L_800B202C
    if (ctx->r25 != 0) {
        // 0x800B1D3C: nop
    
            goto L_800B202C;
    }
    // 0x800B1D3C: nop

    // 0x800B1D40: b           L_800B202C
    // 0x800B1D44: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B202C;
    // 0x800B1D44: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B1D48:
    // 0x800B1D48: lh          $t2, 0x2C($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X2C);
    // 0x800B1D4C: sll         $t3, $v0, 3
    ctx->r11 = S32(ctx->r2 << 3);
    // 0x800B1D50: beq         $t2, $zero, L_800B1D70
    if (ctx->r10 == 0) {
        // 0x800B1D54: subu        $t3, $t3, $v0
        ctx->r11 = SUB32(ctx->r11, ctx->r2);
            goto L_800B1D70;
    }
    // 0x800B1D54: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800B1D58: sll         $t3, $t3, 4
    ctx->r11 = S32(ctx->r11 << 4);
    // 0x800B1D5C: addu        $v1, $a0, $t3
    ctx->r3 = ADD32(ctx->r4, ctx->r11);
L_800B1D60:
    // 0x800B1D60: lh          $t4, 0x9C($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X9C);
    // 0x800B1D64: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B1D68: bne         $t4, $zero, L_800B1D60
    if (ctx->r12 != 0) {
        // 0x800B1D6C: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B1D60;
    }
    // 0x800B1D6C: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B1D70:
    // 0x800B1D70: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B1D74: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B1D78: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B1D7C: addu        $t5, $a0, $a2
    ctx->r13 = ADD32(ctx->r4, ctx->r6);
    // 0x800B1D80: sh          $a3, 0x2C($t5)
    MEM_H(0X2C, ctx->r13) = ctx->r7;
    // 0x800B1D84: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800B1D88: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800B1D8C: addiu       $t6, $t7, 0x1
    ctx->r14 = ADD32(ctx->r15, 0X1);
    // 0x800B1D90: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800B1D94: b           L_800B202C
    // 0x800B1D98: addu        $v1, $a2, $t8
    ctx->r3 = ADD32(ctx->r6, ctx->r24);
        goto L_800B202C;
    // 0x800B1D98: addu        $v1, $a2, $t8
    ctx->r3 = ADD32(ctx->r6, ctx->r24);
L_800B1D9C:
    // 0x800B1D9C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800B1DA0: addiu       $a3, $a3, 0x2CA8
    ctx->r7 = ADD32(ctx->r7, 0X2CA8);
    // 0x800B1DA4: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800B1DA8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B1DAC: beq         $a0, $zero, L_800B202C
    if (ctx->r4 == 0) {
        // 0x800B1DB0: addiu       $t0, $t0, 0x2CA0
        ctx->r8 = ADD32(ctx->r8, 0X2CA0);
            goto L_800B202C;
    }
    // 0x800B1DB0: addiu       $t0, $t0, 0x2CA0
    ctx->r8 = ADD32(ctx->r8, 0X2CA0);
    // 0x800B1DB4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B1DB8: lw          $t2, 0x2E4C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X2E4C);
    // 0x800B1DBC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800B1DC0: addiu       $t3, $t2, -0x1
    ctx->r11 = ADD32(ctx->r10, -0X1);
    // 0x800B1DC4: slt         $at, $t9, $t3
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800B1DC8: bne         $at, $zero, L_800B1DF0
    if (ctx->r1 != 0) {
        // 0x800B1DCC: nop
    
            goto L_800B1DF0;
    }
    // 0x800B1DCC: nop

    // 0x800B1DD0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B1DD4: addiu       $v0, $v0, 0x2CA4
    ctx->r2 = ADD32(ctx->r2, 0X2CA4);
    // 0x800B1DD8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B1DDC: nop

    // 0x800B1DE0: bne         $t4, $zero, L_800B202C
    if (ctx->r12 != 0) {
        // 0x800B1DE4: nop
    
            goto L_800B202C;
    }
    // 0x800B1DE4: nop

    // 0x800B1DE8: b           L_800B202C
    // 0x800B1DEC: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B202C;
    // 0x800B1DEC: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B1DF0:
    // 0x800B1DF0: lh          $t5, 0x2C($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2C);
    // 0x800B1DF4: sll         $t7, $v0, 3
    ctx->r15 = S32(ctx->r2 << 3);
    // 0x800B1DF8: beq         $t5, $zero, L_800B1E18
    if (ctx->r13 == 0) {
        // 0x800B1DFC: subu        $t7, $t7, $v0
        ctx->r15 = SUB32(ctx->r15, ctx->r2);
            goto L_800B1E18;
    }
    // 0x800B1DFC: subu        $t7, $t7, $v0
    ctx->r15 = SUB32(ctx->r15, ctx->r2);
    // 0x800B1E00: sll         $t7, $t7, 4
    ctx->r15 = S32(ctx->r15 << 4);
    // 0x800B1E04: addu        $v1, $a0, $t7
    ctx->r3 = ADD32(ctx->r4, ctx->r15);
L_800B1E08:
    // 0x800B1E08: lh          $t6, 0x9C($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X9C);
    // 0x800B1E0C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B1E10: bne         $t6, $zero, L_800B1E08
    if (ctx->r14 != 0) {
        // 0x800B1E14: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B1E08;
    }
    // 0x800B1E14: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B1E18:
    // 0x800B1E18: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B1E1C: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B1E20: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B1E24: addu        $t8, $a0, $a2
    ctx->r24 = ADD32(ctx->r4, ctx->r6);
    // 0x800B1E28: sh          $a1, 0x2C($t8)
    MEM_H(0X2C, ctx->r24) = ctx->r5;
    // 0x800B1E2C: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800B1E30: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800B1E34: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x800B1E38: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B1E3C: b           L_800B202C
    // 0x800B1E40: addu        $v1, $a2, $t3
    ctx->r3 = ADD32(ctx->r6, ctx->r11);
        goto L_800B202C;
    // 0x800B1E40: addu        $v1, $a2, $t3
    ctx->r3 = ADD32(ctx->r6, ctx->r11);
L_800B1E44:
    // 0x800B1E44: addiu       $t0, $t0, 0x2CB4
    ctx->r8 = ADD32(ctx->r8, 0X2CB4);
    // 0x800B1E48: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B1E4C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B1E50: beq         $a0, $zero, L_800B202C
    if (ctx->r4 == 0) {
        // 0x800B1E54: addiu       $t1, $t1, 0x2CAC
        ctx->r9 = ADD32(ctx->r9, 0X2CAC);
            goto L_800B202C;
    }
    // 0x800B1E54: addiu       $t1, $t1, 0x2CAC
    ctx->r9 = ADD32(ctx->r9, 0X2CAC);
    // 0x800B1E58: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B1E5C: lw          $t5, 0x2E50($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X2E50);
    // 0x800B1E60: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800B1E64: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x800B1E68: slt         $at, $t4, $t7
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800B1E6C: bne         $at, $zero, L_800B1E94
    if (ctx->r1 != 0) {
        // 0x800B1E70: nop
    
            goto L_800B1E94;
    }
    // 0x800B1E70: nop

    // 0x800B1E74: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B1E78: addiu       $v0, $v0, 0x2CB0
    ctx->r2 = ADD32(ctx->r2, 0X2CB0);
    // 0x800B1E7C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B1E80: nop

    // 0x800B1E84: bne         $t6, $zero, L_800B202C
    if (ctx->r14 != 0) {
        // 0x800B1E88: nop
    
            goto L_800B202C;
    }
    // 0x800B1E88: nop

    // 0x800B1E8C: b           L_800B202C
    // 0x800B1E90: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B202C;
    // 0x800B1E90: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B1E94:
    // 0x800B1E94: lh          $t8, 0x2C($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X2C);
    // 0x800B1E98: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x800B1E9C: beq         $t8, $zero, L_800B1EBC
    if (ctx->r24 == 0) {
        // 0x800B1EA0: subu        $t2, $t2, $v0
        ctx->r10 = SUB32(ctx->r10, ctx->r2);
            goto L_800B1EBC;
    }
    // 0x800B1EA0: subu        $t2, $t2, $v0
    ctx->r10 = SUB32(ctx->r10, ctx->r2);
    // 0x800B1EA4: sll         $t2, $t2, 4
    ctx->r10 = S32(ctx->r10 << 4);
    // 0x800B1EA8: addu        $v1, $a0, $t2
    ctx->r3 = ADD32(ctx->r4, ctx->r10);
L_800B1EAC:
    // 0x800B1EAC: lh          $t9, 0x9C($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X9C);
    // 0x800B1EB0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B1EB4: bne         $t9, $zero, L_800B1EAC
    if (ctx->r25 != 0) {
        // 0x800B1EB8: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B1EAC;
    }
    // 0x800B1EB8: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B1EBC:
    // 0x800B1EBC: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B1EC0: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B1EC4: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B1EC8: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
    // 0x800B1ECC: sh          $a3, 0x2C($t3)
    MEM_H(0X2C, ctx->r11) = ctx->r7;
    // 0x800B1ED0: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800B1ED4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800B1ED8: addiu       $t4, $t5, 0x1
    ctx->r12 = ADD32(ctx->r13, 0X1);
    // 0x800B1EDC: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x800B1EE0: b           L_800B202C
    // 0x800B1EE4: addu        $v1, $a2, $t7
    ctx->r3 = ADD32(ctx->r6, ctx->r15);
        goto L_800B202C;
    // 0x800B1EE4: addu        $v1, $a2, $t7
    ctx->r3 = ADD32(ctx->r6, ctx->r15);
L_800B1EE8:
    // 0x800B1EE8: addiu       $t0, $t0, 0x2CCC
    ctx->r8 = ADD32(ctx->r8, 0X2CCC);
    // 0x800B1EEC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B1EF0: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800B1EF4: beq         $a0, $zero, L_800B202C
    if (ctx->r4 == 0) {
        // 0x800B1EF8: addiu       $t1, $t1, 0x2CC4
        ctx->r9 = ADD32(ctx->r9, 0X2CC4);
            goto L_800B202C;
    }
    // 0x800B1EF8: addiu       $t1, $t1, 0x2CC4
    ctx->r9 = ADD32(ctx->r9, 0X2CC4);
    // 0x800B1EFC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800B1F00: lw          $t8, 0x2E58($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X2E58);
    // 0x800B1F04: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800B1F08: addiu       $t2, $t8, -0x1
    ctx->r10 = ADD32(ctx->r24, -0X1);
    // 0x800B1F0C: slt         $at, $t6, $t2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800B1F10: bne         $at, $zero, L_800B1F38
    if (ctx->r1 != 0) {
        // 0x800B1F14: nop
    
            goto L_800B1F38;
    }
    // 0x800B1F14: nop

    // 0x800B1F18: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B1F1C: addiu       $v0, $v0, 0x2CC8
    ctx->r2 = ADD32(ctx->r2, 0X2CC8);
    // 0x800B1F20: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800B1F24: nop

    // 0x800B1F28: bne         $t9, $zero, L_800B202C
    if (ctx->r25 != 0) {
        // 0x800B1F2C: nop
    
            goto L_800B202C;
    }
    // 0x800B1F2C: nop

    // 0x800B1F30: b           L_800B202C
    // 0x800B1F34: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B202C;
    // 0x800B1F34: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B1F38:
    // 0x800B1F38: lh          $t3, 0x2C($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X2C);
    // 0x800B1F3C: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800B1F40: beq         $t3, $zero, L_800B1F60
    if (ctx->r11 == 0) {
        // 0x800B1F44: subu        $t5, $t5, $v0
        ctx->r13 = SUB32(ctx->r13, ctx->r2);
            goto L_800B1F60;
    }
    // 0x800B1F44: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x800B1F48: sll         $t5, $t5, 4
    ctx->r13 = S32(ctx->r13 << 4);
    // 0x800B1F4C: addu        $v1, $a0, $t5
    ctx->r3 = ADD32(ctx->r4, ctx->r13);
L_800B1F50:
    // 0x800B1F50: lh          $t4, 0x9C($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X9C);
    // 0x800B1F54: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B1F58: bne         $t4, $zero, L_800B1F50
    if (ctx->r12 != 0) {
        // 0x800B1F5C: addiu       $v1, $v1, 0x70
        ctx->r3 = ADD32(ctx->r3, 0X70);
            goto L_800B1F50;
    }
    // 0x800B1F5C: addiu       $v1, $v1, 0x70
    ctx->r3 = ADD32(ctx->r3, 0X70);
L_800B1F60:
    // 0x800B1F60: sll         $a2, $v0, 3
    ctx->r6 = S32(ctx->r2 << 3);
    // 0x800B1F64: subu        $a2, $a2, $v0
    ctx->r6 = SUB32(ctx->r6, ctx->r2);
    // 0x800B1F68: sll         $a2, $a2, 4
    ctx->r6 = S32(ctx->r6 << 4);
    // 0x800B1F6C: addu        $t7, $a0, $a2
    ctx->r15 = ADD32(ctx->r4, ctx->r6);
    // 0x800B1F70: sh          $a3, 0x2C($t7)
    MEM_H(0X2C, ctx->r15) = ctx->r7;
    // 0x800B1F74: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800B1F78: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800B1F7C: addiu       $t6, $t8, 0x1
    ctx->r14 = ADD32(ctx->r24, 0X1);
    // 0x800B1F80: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x800B1F84: b           L_800B202C
    // 0x800B1F88: addu        $v1, $a2, $t2
    ctx->r3 = ADD32(ctx->r6, ctx->r10);
        goto L_800B202C;
    // 0x800B1F88: addu        $v1, $a2, $t2
    ctx->r3 = ADD32(ctx->r6, ctx->r10);
L_800B1F8C:
    // 0x800B1F8C: addiu       $a3, $a3, 0x2CD8
    ctx->r7 = ADD32(ctx->r7, 0X2CD8);
    // 0x800B1F90: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800B1F94: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B1F98: beq         $a0, $zero, L_800B202C
    if (ctx->r4 == 0) {
        // 0x800B1F9C: addiu       $t0, $t0, 0x2CD0
        ctx->r8 = ADD32(ctx->r8, 0X2CD0);
            goto L_800B202C;
    }
    // 0x800B1F9C: addiu       $t0, $t0, 0x2CD0
    ctx->r8 = ADD32(ctx->r8, 0X2CD0);
    // 0x800B1FA0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800B1FA4: lw          $t3, 0x2E5C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X2E5C);
    // 0x800B1FA8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800B1FAC: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x800B1FB0: slt         $at, $t9, $t5
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800B1FB4: bne         $at, $zero, L_800B1FDC
    if (ctx->r1 != 0) {
        // 0x800B1FB8: nop
    
            goto L_800B1FDC;
    }
    // 0x800B1FB8: nop

    // 0x800B1FBC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B1FC0: addiu       $v0, $v0, 0x2CD4
    ctx->r2 = ADD32(ctx->r2, 0X2CD4);
    // 0x800B1FC4: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800B1FC8: nop

    // 0x800B1FCC: bne         $t4, $zero, L_800B202C
    if (ctx->r12 != 0) {
        // 0x800B1FD0: nop
    
            goto L_800B202C;
    }
    // 0x800B1FD0: nop

    // 0x800B1FD4: b           L_800B202C
    // 0x800B1FD8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
        goto L_800B202C;
    // 0x800B1FD8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
L_800B1FDC:
    // 0x800B1FDC: lh          $t7, 0x2C($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2C);
    // 0x800B1FE0: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x800B1FE4: beq         $t7, $zero, L_800B2004
    if (ctx->r15 == 0) {
        // 0x800B1FE8: subu        $t8, $t8, $v0
        ctx->r24 = SUB32(ctx->r24, ctx->r2);
            goto L_800B2004;
    }
    // 0x800B1FE8: subu        $t8, $t8, $v0
    ctx->r24 = SUB32(ctx->r24, ctx->r2);
    // 0x800B1FEC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800B1FF0: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
L_800B1FF4:
    // 0x800B1FF4: lh          $t6, 0xA4($v1)
    ctx->r14 = MEM_H(ctx->r3, 0XA4);
    // 0x800B1FF8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B1FFC: bne         $t6, $zero, L_800B1FF4
    if (ctx->r14 != 0) {
        // 0x800B2000: addiu       $v1, $v1, 0x78
        ctx->r3 = ADD32(ctx->r3, 0X78);
            goto L_800B1FF4;
    }
    // 0x800B2000: addiu       $v1, $v1, 0x78
    ctx->r3 = ADD32(ctx->r3, 0X78);
L_800B2004:
    // 0x800B2004: sll         $a1, $v0, 4
    ctx->r5 = S32(ctx->r2 << 4);
    // 0x800B2008: subu        $a1, $a1, $v0
    ctx->r5 = SUB32(ctx->r5, ctx->r2);
    // 0x800B200C: sll         $a1, $a1, 3
    ctx->r5 = S32(ctx->r5 << 3);
    // 0x800B2010: addu        $t2, $a0, $a1
    ctx->r10 = ADD32(ctx->r4, ctx->r5);
    // 0x800B2014: sh          $a2, 0x2C($t2)
    MEM_H(0X2C, ctx->r10) = ctx->r6;
    // 0x800B2018: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800B201C: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800B2020: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x800B2024: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800B2028: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
L_800B202C:
    // 0x800B202C: beq         $v1, $zero, L_800B2038
    if (ctx->r3 == 0) {
        // 0x800B2030: addiu       $t4, $zero, -0x1
        ctx->r12 = ADD32(0, -0X1);
            goto L_800B2038;
    }
    // 0x800B2030: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800B2034: sh          $t4, 0x48($v1)
    MEM_H(0X48, ctx->r3) = ctx->r12;
L_800B2038:
    // 0x800B2038: jr          $ra
    // 0x800B203C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B203C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void sndp_get_group_volume(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004A3C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80004A40: lw          $t7, -0x63D8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X63D8);
    // 0x80004A44: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80004A48: sll         $t8, $t6, 1
    ctx->r24 = S32(ctx->r14 << 1);
    // 0x80004A4C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80004A50: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80004A54: lhu         $v0, 0x0($t9)
    ctx->r2 = MEM_HU(ctx->r25, 0X0);
    // 0x80004A58: jr          $ra
    // 0x80004A5C: nop

    return;
    // 0x80004A5C: nop

;}
RECOMP_FUNC void stop_all_threads_except_main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7144: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800B7148: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B714C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B7150: jal         0x800D2470
    // 0x800B7154: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x800B7154: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B7158: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800B715C: addiu       $s1, $zero, -0x1
    ctx->r17 = ADD32(0, -0X1);
    // 0x800B7160: beq         $s1, $t6, L_800B719C
    if (ctx->r17 == ctx->r14) {
        // 0x800B7164: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800B719C;
    }
    // 0x800B7164: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B7168: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_800B716C:
    // 0x800B716C: blez        $v0, L_800B7184
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B7170: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_800B7184;
    }
    // 0x800B7170: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800B7174: beq         $at, $zero, L_800B7184
    if (ctx->r1 == 0) {
        // 0x800B7178: nop
    
            goto L_800B7184;
    }
    // 0x800B7178: nop

    // 0x800B717C: jal         0x800C8AF0
    // 0x800B7180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    osStopThread_recomp(rdram, ctx);
        goto after_1;
    // 0x800B7180: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
L_800B7184:
    // 0x800B7184: lw          $s0, 0xC($s0)
    ctx->r16 = MEM_W(ctx->r16, 0XC);
    // 0x800B7188: nop

    // 0x800B718C: lw          $v0, 0x4($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4);
    // 0x800B7190: nop

    // 0x800B7194: bne         $s1, $v0, L_800B716C
    if (ctx->r17 != ctx->r2) {
        // 0x800B7198: nop
    
            goto L_800B716C;
    }
    // 0x800B7198: nop

L_800B719C:
    // 0x800B719C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B71A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B71A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B71A8: jr          $ra
    // 0x800B71AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800B71AC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void waves_alloc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7EB4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800B7EB8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800B7EBC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B7EC0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B7EC4: jal         0x800B7D20
    // 0x800B7EC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    waves_free(rdram, ctx);
        goto after_0;
    // 0x800B7EC8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B7ECC: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B7ED0: addiu       $s2, $s2, -0x6038
    ctx->r18 = ADD32(ctx->r18, -0X6038);
    // 0x800B7ED4: lw          $a0, 0x20($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X20);
    // 0x800B7ED8: lui         $s1, 0xFF
    ctx->r17 = S32(0XFF << 16);
    // 0x800B7EDC: ori         $s1, $s1, 0xFFFF
    ctx->r17 = ctx->r17 | 0XFFFF;
    // 0x800B7EE0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800B7EE4: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800B7EE8: jal         0x80070C9C
    // 0x800B7EEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800B7EEC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_1:
    // 0x800B7EF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7EF4: sw          $v0, 0x3040($at)
    MEM_W(0X3040, ctx->r1) = ctx->r2;
    // 0x800B7EF8: lw          $v1, 0x4($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X4);
    // 0x800B7EFC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B7F00: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800B7F04: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7F08: mflo        $a0
    ctx->r4 = lo;
    // 0x800B7F0C: jal         0x80070C9C
    // 0x800B7F10: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800B7F10: nop

    after_2:
    // 0x800B7F14: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7F18: sw          $v0, 0x3044($at)
    MEM_W(0X3044, ctx->r1) = ctx->r2;
    // 0x800B7F1C: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B7F20: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B7F24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B7F28: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800B7F2C: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7F30: mflo        $a0
    ctx->r4 = lo;
    // 0x800B7F34: jal         0x80070C9C
    // 0x800B7F38: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800B7F38: nop

    after_3:
    // 0x800B7F3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B7F40: sw          $v0, 0x3048($at)
    MEM_W(0X3048, ctx->r1) = ctx->r2;
    // 0x800B7F44: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B7F48: addiu       $ra, $zero, 0x9
    ctx->r31 = ADD32(0, 0X9);
    // 0x800B7F4C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B7F50: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x800B7F54: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7F58: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B7F5C: mflo        $s0
    ctx->r16 = lo;
    // 0x800B7F60: nop

    // 0x800B7F64: nop

    // 0x800B7F68: multu       $s0, $ra
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B7F6C: mflo        $a0
    ctx->r4 = lo;
    // 0x800B7F70: jal         0x80070C9C
    // 0x800B7F74: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800B7F74: nop

    after_4:
    // 0x800B7F78: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800B7F7C: addiu       $a0, $a0, 0x304C
    ctx->r4 = ADD32(ctx->r4, 0X304C);
    // 0x800B7F80: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B7F84: sll         $t0, $s0, 2
    ctx->r8 = S32(ctx->r16 << 2);
    // 0x800B7F88: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800B7F8C: addiu       $ra, $zero, 0x9
    ctx->r31 = ADD32(0, 0X9);
    // 0x800B7F90: subu        $t0, $t0, $s0
    ctx->r8 = SUB32(ctx->r8, ctx->r16);
    // 0x800B7F94: addiu       $v1, $v1, 0x3050
    ctx->r3 = ADD32(ctx->r3, 0X3050);
    // 0x800B7F98: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800B7F9C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x800B7FA0: sll         $t2, $s0, 2
    ctx->r10 = S32(ctx->r16 << 2);
    // 0x800B7FA4: sll         $a3, $s0, 1
    ctx->r7 = S32(ctx->r16 << 1);
    // 0x800B7FA8: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x800B7FAC: sll         $t4, $s0, 2
    ctx->r12 = S32(ctx->r16 << 2);
    // 0x800B7FB0: sll         $t1, $s0, 2
    ctx->r9 = S32(ctx->r16 << 2);
    // 0x800B7FB4: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
L_800B7FB8:
    // 0x800B7FB8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B7FBC: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B7FC0: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x800B7FC4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800B7FC8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B7FCC: addu        $a2, $a2, $t2
    ctx->r6 = ADD32(ctx->r6, ctx->r10);
    // 0x800B7FD0: addu        $t9, $t8, $a3
    ctx->r25 = ADD32(ctx->r24, ctx->r7);
    // 0x800B7FD4: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800B7FD8: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800B7FDC: addu        $a3, $a3, $t3
    ctx->r7 = ADD32(ctx->r7, ctx->r11);
    // 0x800B7FE0: addu        $t7, $t6, $t0
    ctx->r15 = ADD32(ctx->r14, ctx->r8);
    // 0x800B7FE4: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800B7FE8: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800B7FEC: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x800B7FF0: addu        $t9, $t8, $t1
    ctx->r25 = ADD32(ctx->r24, ctx->r9);
    // 0x800B7FF4: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
    // 0x800B7FF8: addu        $t1, $t1, $t5
    ctx->r9 = ADD32(ctx->r9, ctx->r13);
    // 0x800B7FFC: bne         $a1, $ra, L_800B7FB8
    if (ctx->r5 != ctx->r31) {
        // 0x800B8000: addiu       $v1, $v1, 0x10
        ctx->r3 = ADD32(ctx->r3, 0X10);
            goto L_800B7FB8;
    }
    // 0x800B8000: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800B8004: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800B8008: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800B800C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B8010: sll         $t6, $v1, 5
    ctx->r14 = S32(ctx->r3 << 5);
    // 0x800B8014: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800B8018: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800B801C: addu        $t6, $t6, $v1
    ctx->r14 = ADD32(ctx->r14, ctx->r3);
    // 0x800B8020: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800B8024: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B8028: lw          $t7, -0x5F88($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5F88);
    // 0x800B802C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B8030: mflo        $s0
    ctx->r16 = lo;
    // 0x800B8034: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    // 0x800B8038: beq         $t7, $at, L_800B8060
    if (ctx->r15 == ctx->r1) {
        // 0x800B803C: nop
    
            goto L_800B8060;
    }
    // 0x800B803C: nop

    // 0x800B8040: jal         0x80070C9C
    // 0x800B8044: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800B8044: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_5:
    // 0x800B8048: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B804C: addiu       $v1, $v1, 0x3070
    ctx->r3 = ADD32(ctx->r3, 0X3070);
    // 0x800B8050: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x800B8054: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B8058: b           L_800B8090
    // 0x800B805C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
        goto L_800B8090;
    // 0x800B805C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
L_800B8060:
    // 0x800B8060: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x800B8064: jal         0x80070C9C
    // 0x800B8068: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_6;
    // 0x800B8068: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_6:
    // 0x800B806C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B8070: addiu       $v1, $v1, 0x3070
    ctx->r3 = ADD32(ctx->r3, 0X3070);
    // 0x800B8074: addu        $t7, $v0, $s0
    ctx->r15 = ADD32(ctx->r2, ctx->r16);
    // 0x800B8078: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800B807C: addu        $t9, $t7, $s0
    ctx->r25 = ADD32(ctx->r15, ctx->r16);
    // 0x800B8080: addu        $t7, $t9, $s0
    ctx->r15 = ADD32(ctx->r25, ctx->r16);
    // 0x800B8084: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B8088: sw          $t9, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r25;
    // 0x800B808C: sw          $t7, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r15;
L_800B8090:
    // 0x800B8090: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800B8094: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800B8098: sll         $t8, $v0, 5
    ctx->r24 = S32(ctx->r2 << 5);
    // 0x800B809C: multu       $t8, $v0
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B80A0: lw          $t9, -0x5F88($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5F88);
    // 0x800B80A4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800B80A8: mflo        $s0
    ctx->r16 = lo;
    // 0x800B80AC: sll         $a0, $s0, 1
    ctx->r4 = S32(ctx->r16 << 1);
    // 0x800B80B0: beq         $t9, $at, L_800B80D8
    if (ctx->r25 == ctx->r1) {
        // 0x800B80B4: nop
    
            goto L_800B80D8;
    }
    // 0x800B80B4: nop

    // 0x800B80B8: jal         0x80070C9C
    // 0x800B80BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_7;
    // 0x800B80BC: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_7:
    // 0x800B80C0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B80C4: addiu       $v1, $v1, 0x3080
    ctx->r3 = ADD32(ctx->r3, 0X3080);
    // 0x800B80C8: addu        $t7, $v0, $s0
    ctx->r15 = ADD32(ctx->r2, ctx->r16);
    // 0x800B80CC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B80D0: b           L_800B8108
    // 0x800B80D4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
        goto L_800B8108;
    // 0x800B80D4: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
L_800B80D8:
    // 0x800B80D8: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x800B80DC: jal         0x80070C9C
    // 0x800B80E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_8;
    // 0x800B80E0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800B80E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B80E8: addiu       $v1, $v1, 0x3080
    ctx->r3 = ADD32(ctx->r3, 0X3080);
    // 0x800B80EC: addu        $t9, $v0, $s0
    ctx->r25 = ADD32(ctx->r2, ctx->r16);
    // 0x800B80F0: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x800B80F4: addu        $t7, $t9, $s0
    ctx->r15 = ADD32(ctx->r25, ctx->r16);
    // 0x800B80F8: addu        $t9, $t7, $s0
    ctx->r25 = ADD32(ctx->r15, ctx->r16);
    // 0x800B80FC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800B8100: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x800B8104: sw          $t9, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r25;
L_800B8108:
    // 0x800B8108: lw          $a0, 0x2C($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X2C);
    // 0x800B810C: jal         0x8007AE74
    // 0x800B8110: nop

    load_texture(rdram, ctx);
        goto after_9;
    // 0x800B8110: nop

    after_9:
    // 0x800B8114: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800B8118: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B811C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B8120: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B8124: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B8128: sw          $v0, 0x30D0($at)
    MEM_W(0X30D0, ctx->r1) = ctx->r2;
    // 0x800B812C: jr          $ra
    // 0x800B8130: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800B8130: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void move_particle_basic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B34B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B34B4: addiu       $a1, $a1, 0x7C80
    ctx->r5 = ADD32(ctx->r5, 0X7C80);
    // 0x800B34B8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800B34BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B34C0: slt         $t6, $zero, $v0
    ctx->r14 = SIGNED(0) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800B34C4: beq         $t6, $zero, L_800B355C
    if (ctx->r14 == 0) {
        // 0x800B34C8: nop
    
            goto L_800B355C;
    }
    // 0x800B34C8: nop

L_800B34CC:
    // 0x800B34CC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800B34D0: lwc1        $f6, 0x1C($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X1C);
    // 0x800B34D4: lwc1        $f0, 0x20($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X20);
    // 0x800B34D8: lwc1        $f10, 0x10($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800B34DC: lwc1        $f18, 0x68($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X68);
    // 0x800B34E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B34E4: lwc1        $f6, 0x14($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800B34E8: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800B34EC: swc1        $f8, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->f8.u32l;
    // 0x800B34F0: sub.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x800B34F4: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x800B34F8: lwc1        $f8, 0x24($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X24);
    // 0x800B34FC: lwc1        $f16, 0x8($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800B3500: lwc1        $f18, 0x28($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X28);
    // 0x800B3504: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800B3508: lh          $t8, 0x62($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X62);
    // 0x800B350C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x800B3510: lh          $t1, 0x64($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X64);
    // 0x800B3514: lh          $t3, 0x4($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X4);
    // 0x800B3518: lh          $t4, 0x66($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X66);
    // 0x800B351C: swc1        $f4, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f4.u32l;
    // 0x800B3520: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800B3524: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800B3528: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B352C: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B3530: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800B3534: swc1        $f10, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->f10.u32l;
    // 0x800B3538: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    // 0x800B353C: sh          $t9, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r25;
    // 0x800B3540: sh          $t2, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r10;
    // 0x800B3544: sh          $t5, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r13;
    // 0x800B3548: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800B354C: nop

    // 0x800B3550: slt         $v0, $v1, $t6
    ctx->r2 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B3554: bne         $v0, $zero, L_800B34CC
    if (ctx->r2 != 0) {
        // 0x800B3558: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800B34CC;
    }
    // 0x800B3558: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800B355C:
    // 0x800B355C: jr          $ra
    // 0x800B3560: nop

    return;
    // 0x800B3560: nop

;}
RECOMP_FUNC void racer_sound_plane(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800063EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800063F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800063F4: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    // 0x800063F8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800063FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x80006400: jal         0x8001139C
    // 0x80006404: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x80006404: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80006408: bne         $v0, $zero, L_80006448
    if (ctx->r2 != 0) {
        // 0x8000640C: nop
    
            goto L_80006448;
    }
    // 0x8000640C: nop

    // 0x80006410: lw          $v0, 0x30($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X30);
    // 0x80006414: nop

    // 0x80006418: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8000641C: lwc1        $f2, 0x24($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80006420: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80006424: lwc1        $f14, 0x20($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80006428: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000642C: nop

    // 0x80006430: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80006434: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80006438: jal         0x800C9AD0
    // 0x8000643C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8000643C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x80006440: b           L_80006450
    // 0x80006444: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
        goto L_80006450;
    // 0x80006444: mov.s       $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.fl = ctx->f0.fl;
L_80006448:
    // 0x80006448: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8000644C: nop

L_80006450:
    // 0x80006450: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80006454: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80006458: nop

    // 0x8000645C: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80006460: nop

    // 0x80006464: bc1f        L_800064B8
    if (!c1cs) {
        // 0x80006468: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_800064B8;
    }
    // 0x80006468: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000646C: addiu       $t1, $t1, -0x63C8
    ctx->r9 = ADD32(ctx->r9, -0X63C8);
    // 0x80006470: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006474: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80006478: lbu         $t6, 0x37($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X37);
    // 0x8000647C: lwc1        $f0, 0x54($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X54);
    // 0x80006480: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80006484: bgez        $t6, L_80006498
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80006488: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80006498;
    }
    // 0x80006488: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000648C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80006490: nop

    // 0x80006494: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_80006498:
    // 0x80006498: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8000649C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800064A0: sub.s       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800064A4: nop

    // 0x800064A8: div.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800064AC: add.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f10.fl;
    // 0x800064B0: b           L_800066FC
    // 0x800064B4: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
        goto L_800066FC;
    // 0x800064B4: swc1        $f8, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f8.u32l;
L_800064B8:
    // 0x800064B8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800064BC: addiu       $t1, $t1, -0x63C8
    ctx->r9 = ADD32(ctx->r9, -0X63C8);
    // 0x800064C0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800064C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800064C8: lwc1        $f6, 0x4C78($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4C78);
    // 0x800064CC: lwc1        $f4, 0x5C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x800064D0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800064D4: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800064D8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800064DC: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800064E0: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x800064E4: nop

    // 0x800064E8: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800064EC: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x800064F0: nop

    // 0x800064F4: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x800064F8: beq         $a1, $zero, L_80006544
    if (ctx->r5 == 0) {
        // 0x800064FC: nop
    
            goto L_80006544;
    }
    // 0x800064FC: nop

    // 0x80006500: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80006504: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80006508: sub.s       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8000650C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006510: ctc1        $a1, $FpcCsr
    set_cop1_cs(ctx->r5);
    // 0x80006514: nop

    // 0x80006518: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000651C: cfc1        $a1, $FpcCsr
    ctx->r5 = get_cop1_cs();
    // 0x80006520: nop

    // 0x80006524: andi        $a1, $a1, 0x78
    ctx->r5 = ctx->r5 & 0X78;
    // 0x80006528: bne         $a1, $zero, L_8000653C
    if (ctx->r5 != 0) {
        // 0x8000652C: nop
    
            goto L_8000653C;
    }
    // 0x8000652C: nop

    // 0x80006530: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006534: b           L_80006554
    // 0x80006538: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
        goto L_80006554;
    // 0x80006538: or          $a1, $a1, $at
    ctx->r5 = ctx->r5 | ctx->r1;
L_8000653C:
    // 0x8000653C: b           L_80006554
    // 0x80006540: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
        goto L_80006554;
    // 0x80006540: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80006544:
    // 0x80006544: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80006548: nop

    // 0x8000654C: bltz        $a1, L_8000653C
    if (SIGNED(ctx->r5) < 0) {
        // 0x80006550: nop
    
            goto L_8000653C;
    }
    // 0x80006550: nop

L_80006554:
    // 0x80006554: lhu         $t9, 0x18($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0X18);
    // 0x80006558: andi        $a0, $a1, 0xFFFF
    ctx->r4 = ctx->r5 & 0XFFFF;
    // 0x8000655C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80006560: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80006564: bne         $at, $zero, L_80006598
    if (ctx->r1 != 0) {
        // 0x80006568: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80006598;
    }
    // 0x80006568: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000656C:
    // 0x8000656C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80006570: andi        $t2, $v0, 0xFF
    ctx->r10 = ctx->r2 & 0XFF;
    // 0x80006574: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x80006578: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x8000657C: lhu         $t5, 0x18($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X18);
    // 0x80006580: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x80006584: slt         $at, $a0, $t5
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80006588: bne         $at, $zero, L_80006598
    if (ctx->r1 != 0) {
        // 0x8000658C: slti        $at, $t2, 0x4
        ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
            goto L_80006598;
    }
    // 0x8000658C: slti        $at, $t2, 0x4
    ctx->r1 = SIGNED(ctx->r10) < 0X4 ? 1 : 0;
    // 0x80006590: bne         $at, $zero, L_8000656C
    if (ctx->r1 != 0) {
        // 0x80006594: nop
    
            goto L_8000656C;
    }
    // 0x80006594: nop

L_80006598:
    // 0x80006598: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000659C: bne         $v0, $at, L_800065B4
    if (ctx->r2 != ctx->r1) {
        // 0x800065A0: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_800065B4;
    }
    // 0x800065A0: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800065A4: addu        $t6, $v1, $v0
    ctx->r14 = ADD32(ctx->r3, ctx->r2);
    // 0x800065A8: lbu         $t0, 0x2C($t6)
    ctx->r8 = MEM_BU(ctx->r14, 0X2C);
    // 0x800065AC: b           L_800066C4
    // 0x800065B0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
        goto L_800066C4;
    // 0x800065B0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
L_800065B4:
    // 0x800065B4: beq         $a1, $zero, L_800065C8
    if (ctx->r5 == 0) {
        // 0x800065B8: lui         $at, 0x4F80
        ctx->r1 = S32(0X4F80 << 16);
            goto L_800065C8;
    }
    // 0x800065B8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800065BC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800065C0: andi        $a1, $v0, 0xFF
    ctx->r5 = ctx->r2 & 0XFF;
    // 0x800065C4: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800065C8:
    // 0x800065C8: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800065CC: addu        $t9, $v1, $t8
    ctx->r25 = ADD32(ctx->r3, ctx->r24);
    // 0x800065D0: sll         $t3, $a1, 1
    ctx->r11 = S32(ctx->r5 << 1);
    // 0x800065D4: lhu         $a2, 0x18($t9)
    ctx->r6 = MEM_HU(ctx->r25, 0X18);
    // 0x800065D8: addu        $t4, $v1, $t3
    ctx->r12 = ADD32(ctx->r3, ctx->r11);
    // 0x800065DC: lhu         $t5, 0x1A($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X1A);
    // 0x800065E0: subu        $t2, $a0, $a2
    ctx->r10 = SUB32(ctx->r4, ctx->r6);
    // 0x800065E4: subu        $t6, $t5, $a2
    ctx->r14 = SUB32(ctx->r13, ctx->r6);
    // 0x800065E8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800065EC: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800065F0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800065F4: addu        $t8, $v1, $a1
    ctx->r24 = ADD32(ctx->r3, ctx->r5);
    // 0x800065F8: addu        $t7, $v1, $v0
    ctx->r15 = ADD32(ctx->r3, ctx->r2);
    // 0x800065FC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80006600: lbu         $a3, 0x2C($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X2C);
    // 0x80006604: lbu         $t9, 0x2D($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2D);
    // 0x80006608: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8000660C: subu        $t2, $t9, $a3
    ctx->r10 = SUB32(ctx->r25, ctx->r7);
    // 0x80006610: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80006614: mtc1        $a3, $f8
    ctx->f8.u32l = ctx->r7;
    // 0x80006618: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000661C: mul.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80006620: bgez        $a3, L_80006634
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80006624: cvt.s.w     $f4, $f8
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80006634;
    }
    // 0x80006624: cvt.s.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80006628: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000662C: nop

    // 0x80006630: add.s       $f4, $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f10.fl;
L_80006634:
    // 0x80006634: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80006638: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8000663C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80006640: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80006644: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80006648: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000664C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006650: nop

    // 0x80006654: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006658: beq         $t0, $zero, L_800066A4
    if (ctx->r8 == 0) {
        // 0x8000665C: nop
    
            goto L_800066A4;
    }
    // 0x8000665C: nop

    // 0x80006660: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80006664: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80006668: sub.s       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000666C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80006670: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x80006674: nop

    // 0x80006678: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000667C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80006680: nop

    // 0x80006684: andi        $t0, $t0, 0x78
    ctx->r8 = ctx->r8 & 0X78;
    // 0x80006688: bne         $t0, $zero, L_8000669C
    if (ctx->r8 != 0) {
        // 0x8000668C: nop
    
            goto L_8000669C;
    }
    // 0x8000668C: nop

    // 0x80006690: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80006694: b           L_800066B4
    // 0x80006698: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
        goto L_800066B4;
    // 0x80006698: or          $t0, $t0, $at
    ctx->r8 = ctx->r8 | ctx->r1;
L_8000669C:
    // 0x8000669C: b           L_800066B4
    // 0x800066A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
        goto L_800066B4;
    // 0x800066A0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800066A4:
    // 0x800066A4: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x800066A8: nop

    // 0x800066AC: bltz        $t0, L_8000669C
    if (SIGNED(ctx->r8) < 0) {
        // 0x800066B0: nop
    
            goto L_8000669C;
    }
    // 0x800066B0: nop

L_800066B4:
    // 0x800066B4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800066B8: andi        $t4, $t0, 0xFF
    ctx->r12 = ctx->r8 & 0XFF;
    // 0x800066BC: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x800066C0: mtc1        $t0, $f6
    ctx->f6.u32l = ctx->r8;
L_800066C4:
    // 0x800066C4: lwc1        $f0, 0x54($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X54);
    // 0x800066C8: bgez        $t0, L_800066E0
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800066CC: cvt.s.w     $f4, $f6
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800066E0;
    }
    // 0x800066CC: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800066D0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800066D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800066D8: nop

    // 0x800066DC: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800066E0:
    // 0x800066E0: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800066E4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800066E8: sub.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800066EC: nop

    // 0x800066F0: div.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800066F4: add.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f8.fl;
    // 0x800066F8: swc1        $f4, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->f4.u32l;
L_800066FC:
    // 0x800066FC: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006700: lw          $t5, 0x38($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X38);
    // 0x80006704: lwc1        $f14, 0xD4($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XD4);
    // 0x80006708: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x8000670C: beq         $t6, $zero, L_80006778
    if (ctx->r14 == 0) {
        // 0x80006710: lw          $t8, 0x3C($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X3C);
            goto L_80006778;
    }
    // 0x80006710: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x80006714: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x80006718: lwc1        $f10, 0xB0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XB0);
    // 0x8000671C: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x80006720: nop

    // 0x80006724: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80006728: lwc1        $f6, 0xA4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x8000672C: mul.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80006730: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x80006734: swc1        $f10, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f10.u32l;
    // 0x80006738: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000673C: nop

    // 0x80006740: lwc1        $f2, 0xC8($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80006744: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x80006748: nop

    // 0x8000674C: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80006750: nop

    // 0x80006754: bc1f        L_800067A8
    if (!c1cs) {
        // 0x80006758: nop
    
            goto L_800067A8;
    }
    // 0x80006758: nop

    // 0x8000675C: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
    // 0x80006760: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006764: nop

    // 0x80006768: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x8000676C: b           L_800067AC
    // 0x80006770: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
        goto L_800067AC;
    // 0x80006770: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80006774: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
L_80006778:
    // 0x80006778: lwc1        $f8, 0xB4($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0XB4);
    // 0x8000677C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80006780: nop

    // 0x80006784: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80006788: lwc1        $f6, 0xA4($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x8000678C: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80006790: sub.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80006794: swc1        $f8, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f8.u32l;
    // 0x80006798: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000679C: nop

    // 0x800067A0: lwc1        $f0, 0xA4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0XA4);
    // 0x800067A4: nop

L_800067A8:
    // 0x800067A8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
L_800067AC:
    // 0x800067AC: nop

    // 0x800067B0: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800067B4: nop

    // 0x800067B8: bc1f        L_800067C4
    if (!c1cs) {
        // 0x800067BC: nop
    
            goto L_800067C4;
    }
    // 0x800067BC: nop

    // 0x800067C0: swc1        $f2, 0xA4($v1)
    MEM_W(0XA4, ctx->r3) = ctx->f2.u32l;
L_800067C4:
    // 0x800067C4: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    // 0x800067C8: jal         0x800A0190
    // 0x800067CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    race_starting(rdram, ctx);
        goto after_2;
    // 0x800067CC: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x800067D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800067D4: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800067D8: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800067DC: bne         $v0, $zero, L_800067F4
    if (ctx->r2 != 0) {
        // 0x800067E0: addiu       $t1, $t1, -0x63C8
        ctx->r9 = ADD32(ctx->r9, -0X63C8);
            goto L_800067F4;
    }
    // 0x800067E0: addiu       $t1, $t1, -0x63C8
    ctx->r9 = ADD32(ctx->r9, -0X63C8);
    // 0x800067E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800067E8: lw          $t9, 0x0($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X0);
    // 0x800067EC: nop

    // 0x800067F0: swc1        $f4, 0xA4($t9)
    MEM_W(0XA4, ctx->r25) = ctx->f4.u32l;
L_800067F4:
    // 0x800067F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x800067F8: lw          $t3, 0x30($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X30);
    // 0x800067FC: lwc1        $f6, 0xA4($t2)
    ctx->f6.u32l = MEM_W(ctx->r10, 0XA4);
    // 0x80006800: lh          $a0, 0x2($t3)
    ctx->r4 = MEM_H(ctx->r11, 0X2);
    // 0x80006804: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x80006808: swc1        $f18, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f18.u32l;
    // 0x8000680C: jal         0x800707C4
    // 0x80006810: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80006810: swc1        $f14, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f14.u32l;
    after_3:
    // 0x80006814: lw          $t4, 0x30($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X30);
    // 0x80006818: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x8000681C: lh          $a0, 0x4($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X4);
    // 0x80006820: jal         0x800707C4
    // 0x80006824: nop

    sins_f(rdram, ctx);
        goto after_4;
    // 0x80006824: nop

    after_4:
    // 0x80006828: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000682C: addiu       $t1, $t1, -0x63C8
    ctx->r9 = ADD32(ctx->r9, -0X63C8);
    // 0x80006830: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006834: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80006838: lwc1        $f10, 0xC4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC4);
    // 0x8000683C: lwc1        $f4, 0xC0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC0);
    // 0x80006840: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x80006844: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80006848: lwc1        $f18, 0x2C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000684C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80006850: mul.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80006854: lwc1        $f14, 0x18($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80006858: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8000685C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80006860: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x80006864: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80006868: bc1f        L_80006874
    if (!c1cs) {
        // 0x8000686C: cvt.d.s     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
            goto L_80006874;
    }
    // 0x8000686C: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80006870: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80006874:
    // 0x80006874: c.lt.d      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.d < ctx->f0.d;
    // 0x80006878: add.s       $f10, $f12, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x8000687C: bc1f        L_80006890
    if (!c1cs) {
        // 0x80006880: add.s       $f14, $f14, $f10
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
            goto L_80006890;
    }
    // 0x80006880: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
    // 0x80006884: sub.d       $f8, $f0, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f16.d); 
    ctx->f8.d = ctx->f0.d - ctx->f16.d;
    // 0x80006888: b           L_80006898
    // 0x8000688C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
        goto L_80006898;
    // 0x8000688C: cvt.s.d     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f18.fl = CVT_S_D(ctx->f8.d);
L_80006890:
    // 0x80006890: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80006894: nop

L_80006898:
    // 0x80006898: lwc1        $f4, 0xCC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XCC);
    // 0x8000689C: mtc1        $zero, $f11
    ctx->f_odd[(11 - 1) * 2] = 0;
    // 0x800068A0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800068A4: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x800068A8: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800068AC: c.eq.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d == ctx->f8.d;
    // 0x800068B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068B4: bc1t        L_80006980
    if (c1cs) {
        // 0x800068B8: add.s       $f14, $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
            goto L_80006980;
    }
    // 0x800068B8: add.s       $f14, $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f6.fl;
    // 0x800068BC: lw          $t5, -0x63C4($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X63C4);
    // 0x800068C0: nop

    // 0x800068C4: lb          $v0, 0x185($t5)
    ctx->r2 = MEM_B(ctx->r13, 0X185);
    // 0x800068C8: nop

    // 0x800068CC: beq         $v0, $zero, L_80006980
    if (ctx->r2 == 0) {
        // 0x800068D0: nop
    
            goto L_80006980;
    }
    // 0x800068D0: nop

    // 0x800068D4: slti        $at, $v0, 0xB
    ctx->r1 = SIGNED(ctx->r2) < 0XB ? 1 : 0;
    // 0x800068D8: beq         $at, $zero, L_800068E8
    if (ctx->r1 == 0) {
        // 0x800068DC: addiu       $a0, $zero, 0xA
        ctx->r4 = ADD32(0, 0XA);
            goto L_800068E8;
    }
    // 0x800068DC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800068E0: b           L_800068E8
    // 0x800068E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
        goto L_800068E8;
    // 0x800068E4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800068E8:
    // 0x800068E8: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800068EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800068F0: cvt.d.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.d = CVT_D_W(ctx->f6.u32l);
    // 0x800068F4: lwc1        $f5, 0x4C80($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X4C80);
    // 0x800068F8: lwc1        $f4, 0x4C84($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X4C84);
    // 0x800068FC: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006900: mul.d       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f0.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80006904: cvt.d.s     $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f2.d = CVT_D_S(ctx->f12.fl);
    // 0x80006908: sll         $t6, $a0, 6
    ctx->r14 = S32(ctx->r4 << 6);
    // 0x8000690C: c.lt.d      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.d < ctx->f0.d;
    // 0x80006910: nop

    // 0x80006914: bc1f        L_80006950
    if (!c1cs) {
        // 0x80006918: nop
    
            goto L_80006950;
    }
    // 0x80006918: nop

    // 0x8000691C: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80006920: nop

    // 0x80006924: cvt.d.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.d = CVT_D_W(ctx->f8.u32l);
    // 0x80006928: nop

    // 0x8000692C: div.d       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = DIV_D(ctx->f0.d, ctx->f6.d);
    // 0x80006930: add.d       $f10, $f2, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f2.d + ctx->f4.d;
    // 0x80006934: cvt.s.d     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f8.fl = CVT_S_D(ctx->f10.d);
    // 0x80006938: swc1        $f8, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f8.u32l;
    // 0x8000693C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006940: nop

    // 0x80006944: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006948: b           L_800069B0
    // 0x8000694C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800069B0;
    // 0x8000694C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_80006950:
    // 0x80006950: c.lt.d      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.d < ctx->f2.d;
    // 0x80006954: nop

    // 0x80006958: bc1f        L_80006978
    if (!c1cs) {
        // 0x8000695C: nop
    
            goto L_80006978;
    }
    // 0x8000695C: nop

    // 0x80006960: cvt.s.d     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); 
    ctx->f6.fl = CVT_S_D(ctx->f0.d);
    // 0x80006964: swc1        $f6, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f6.u32l;
    // 0x80006968: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8000696C: nop

    // 0x80006970: lwc1        $f12, 0x3C($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006974: nop

L_80006978:
    // 0x80006978: b           L_800069B0
    // 0x8000697C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
        goto L_800069B0;
    // 0x8000697C: add.s       $f14, $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f12.fl;
L_80006980:
    // 0x80006980: lwc1        $f4, 0x3C($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x80006984: lwc1        $f9, 0x4C88($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X4C88);
    // 0x80006988: lwc1        $f8, 0x4C8C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C8C);
    // 0x8000698C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80006990: mul.d       $f6, $f10, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f8.d);
    // 0x80006994: cvt.s.d     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f4.fl = CVT_S_D(ctx->f6.d);
    // 0x80006998: swc1        $f4, 0x3C($v1)
    MEM_W(0X3C, ctx->r3) = ctx->f4.u32l;
    // 0x8000699C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800069A0: nop

    // 0x800069A4: lwc1        $f10, 0x3C($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X3C);
    // 0x800069A8: nop

    // 0x800069AC: add.s       $f14, $f14, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f10.fl;
L_800069B0:
    // 0x800069B0: lwc1        $f0, 0x5C($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x800069B4: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800069B8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800069BC: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800069C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069C4: div.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800069C8: add.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x800069CC: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
    // 0x800069D0: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x800069D4: lwc1        $f8, 0x4C94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X4C94);
    // 0x800069D8: lwc1        $f6, 0x5C($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X5C);
    // 0x800069DC: lwc1        $f9, 0x4C90($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X4C90);
    // 0x800069E0: cvt.d.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.d = CVT_D_S(ctx->f6.fl);
    // 0x800069E4: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x800069E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800069EC: bc1f        L_80006A08
    if (!c1cs) {
        // 0x800069F0: nop
    
            goto L_80006A08;
    }
    // 0x800069F0: nop

    // 0x800069F4: lwc1        $f10, 0x4C98($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X4C98);
    // 0x800069F8: nop

    // 0x800069FC: swc1        $f10, 0x5C($v1)
    MEM_W(0X5C, ctx->r3) = ctx->f10.u32l;
    // 0x80006A00: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006A04: nop

L_80006A08:
    // 0x80006A08: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80006A0C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80006A10: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80006A14: swc1        $f6, 0x60($v1)
    MEM_W(0X60, ctx->r3) = ctx->f6.u32l;
    // 0x80006A18: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80006A1C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80006A20: swc1        $f8, 0x58($t7)
    MEM_W(0X58, ctx->r15) = ctx->f8.u32l;
    // 0x80006A24: lw          $v0, -0x63C4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X63C4);
    // 0x80006A28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80006A2C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x80006A30: nop

    // 0x80006A34: beq         $t8, $at, L_80006A7C
    if (ctx->r24 == ctx->r1) {
        // 0x80006A38: nop
    
            goto L_80006A7C;
    }
    // 0x80006A38: nop

    // 0x80006A3C: lb          $t9, 0x1DB($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1DB);
    // 0x80006A40: nop

    // 0x80006A44: beq         $t9, $zero, L_80006A7C
    if (ctx->r25 == 0) {
        // 0x80006A48: nop
    
            goto L_80006A7C;
    }
    // 0x80006A48: nop

    // 0x80006A4C: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80006A50: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80006A54: lbu         $t2, 0xD8($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XD8);
    // 0x80006A58: addiu       $a0, $zero, 0x13D
    ctx->r4 = ADD32(0, 0X13D);
    // 0x80006A5C: bne         $t2, $zero, L_80006A7C
    if (ctx->r10 != 0) {
        // 0x80006A60: nop
    
            goto L_80006A7C;
    }
    // 0x80006A60: nop

    // 0x80006A64: sb          $t3, 0xD8($v1)
    MEM_B(0XD8, ctx->r3) = ctx->r11;
    // 0x80006A68: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80006A6C: jal         0x80001D04
    // 0x80006A70: addiu       $a1, $a1, 0xDC
    ctx->r5 = ADD32(ctx->r5, 0XDC);
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80006A70: addiu       $a1, $a1, 0xDC
    ctx->r5 = ADD32(ctx->r5, 0XDC);
    after_5:
    // 0x80006A74: b           L_80006ABC
    // 0x80006A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80006ABC;
    // 0x80006A78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006A7C:
    // 0x80006A7C: lb          $t4, 0x1DB($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X1DB);
    // 0x80006A80: nop

    // 0x80006A84: bne         $t4, $zero, L_80006ABC
    if (ctx->r12 != 0) {
        // 0x80006A88: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006ABC;
    }
    // 0x80006A88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006A8C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x80006A90: nop

    // 0x80006A94: sb          $zero, 0xD8($t5)
    MEM_B(0XD8, ctx->r13) = 0;
    // 0x80006A98: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x80006A9C: nop

    // 0x80006AA0: lw          $a0, 0xDC($t6)
    ctx->r4 = MEM_W(ctx->r14, 0XDC);
    // 0x80006AA4: nop

    // 0x80006AA8: beq         $a0, $zero, L_80006ABC
    if (ctx->r4 == 0) {
        // 0x80006AAC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80006ABC;
    }
    // 0x80006AAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80006AB0: jal         0x8000488C
    // 0x80006AB4: nop

    sndp_stop(rdram, ctx);
        goto after_6;
    // 0x80006AB4: nop

    after_6:
    // 0x80006AB8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80006ABC:
    // 0x80006ABC: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x80006AC0: jr          $ra
    // 0x80006AC4: nop

    return;
    // 0x80006AC4: nop

;}
RECOMP_FUNC void free_model_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80060058: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8006005C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80060060: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80060064: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80060068: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006006C: lh          $v0, 0x22($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X22);
    // 0x80060070: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80060074: blez        $v0, L_800600BC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80060078: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800600BC;
    }
    // 0x80060078: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006007C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80060080:
    // 0x80060080: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80060084: nop

    // 0x80060088: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x8006008C: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x80060090: nop

    // 0x80060094: beq         $a0, $zero, L_800600AC
    if (ctx->r4 == 0) {
        // 0x80060098: nop
    
            goto L_800600AC;
    }
    // 0x80060098: nop

    // 0x8006009C: jal         0x8007B2BC
    // 0x800600A0: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800600A0: nop

    after_0:
    // 0x800600A4: lh          $v0, 0x22($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X22);
    // 0x800600A8: nop

L_800600AC:
    // 0x800600AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800600B0: slt         $at, $s0, $v0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800600B4: bne         $at, $zero, L_80060080
    if (ctx->r1 != 0) {
        // 0x800600B8: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80060080;
    }
    // 0x800600B8: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
L_800600BC:
    // 0x800600BC: lw          $a0, 0xC($s2)
    ctx->r4 = MEM_W(ctx->r18, 0XC);
    // 0x800600C0: nop

    // 0x800600C4: beq         $a0, $zero, L_800600D4
    if (ctx->r4 == 0) {
        // 0x800600C8: nop
    
            goto L_800600D4;
    }
    // 0x800600C8: nop

    // 0x800600CC: jal         0x80071140
    // 0x800600D0: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800600D0: nop

    after_1:
L_800600D4:
    // 0x800600D4: lw          $a0, 0x10($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X10);
    // 0x800600D8: nop

    // 0x800600DC: beq         $a0, $zero, L_800600EC
    if (ctx->r4 == 0) {
        // 0x800600E0: nop
    
            goto L_800600EC;
    }
    // 0x800600E0: nop

    // 0x800600E4: jal         0x80071140
    // 0x800600E8: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800600E8: nop

    after_2:
L_800600EC:
    // 0x800600EC: lw          $a0, 0x40($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X40);
    // 0x800600F0: nop

    // 0x800600F4: beq         $a0, $zero, L_80060104
    if (ctx->r4 == 0) {
        // 0x800600F8: nop
    
            goto L_80060104;
    }
    // 0x800600F8: nop

    // 0x800600FC: jal         0x80071140
    // 0x80060100: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x80060100: nop

    after_3:
L_80060104:
    // 0x80060104: lw          $t8, 0x44($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X44);
    // 0x80060108: nop

    // 0x8006010C: beq         $t8, $zero, L_8006015C
    if (ctx->r24 == 0) {
        // 0x80060110: nop
    
            goto L_8006015C;
    }
    // 0x80060110: nop

    // 0x80060114: lh          $t9, 0x48($s2)
    ctx->r25 = MEM_H(ctx->r18, 0X48);
    // 0x80060118: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8006011C: beq         $t9, $zero, L_8006015C
    if (ctx->r25 == 0) {
        // 0x80060120: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8006015C;
    }
    // 0x80060120: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80060124:
    // 0x80060124: lw          $t0, 0x44($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X44);
    // 0x80060128: nop

    // 0x8006012C: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80060130: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x80060134: jal         0x80071140
    // 0x80060138: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80060138: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    after_4:
    // 0x8006013C: lh          $t2, 0x48($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X48);
    // 0x80060140: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80060144: slt         $at, $s0, $t2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80060148: bne         $at, $zero, L_80060124
    if (ctx->r1 != 0) {
        // 0x8006014C: addiu       $s1, $s1, 0x8
        ctx->r17 = ADD32(ctx->r17, 0X8);
            goto L_80060124;
    }
    // 0x8006014C: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80060150: lw          $a0, 0x44($s2)
    ctx->r4 = MEM_W(ctx->r18, 0X44);
    // 0x80060154: jal         0x80071140
    // 0x80060158: nop

    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80060158: nop

    after_5:
L_8006015C:
    // 0x8006015C: jal         0x80071140
    // 0x80060160: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_6;
    // 0x80060160: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x80060164: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80060168: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006016C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80060170: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80060174: jr          $ra
    // 0x80060178: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80060178: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sound_channel_volume_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001C5C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001C60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80001C64: sll         $s1, $a0, 8
    ctx->r17 = S32(ctx->r4 << 8);
    // 0x80001C68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80001C6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80001C70: andi        $t7, $s1, 0xFFFF
    ctx->r15 = ctx->r17 & 0XFFFF;
    // 0x80001C74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80001C78: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001C7C: or          $s1, $t7, $zero
    ctx->r17 = ctx->r15 | 0;
    // 0x80001C80: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80001C84: addiu       $s2, $zero, 0x40
    ctx->r18 = ADD32(0, 0X40);
    // 0x80001C88: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
L_80001C8C:
    // 0x80001C8C: jal         0x80004A60
    // 0x80001C90: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    sndp_set_group_volume(rdram, ctx);
        goto after_0;
    // 0x80001C90: andi        $a1, $s1, 0xFFFF
    ctx->r5 = ctx->r17 & 0XFFFF;
    after_0:
    // 0x80001C94: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80001C98: bne         $s0, $s2, L_80001C8C
    if (ctx->r16 != ctx->r18) {
        // 0x80001C9C: andi        $a0, $s0, 0xFF
        ctx->r4 = ctx->r16 & 0XFF;
            goto L_80001C8C;
    }
    // 0x80001C9C: andi        $a0, $s0, 0xFF
    ctx->r4 = ctx->r16 & 0XFF;
    // 0x80001CA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80001CA4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80001CA8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80001CAC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80001CB0: jr          $ra
    // 0x80001CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80001CB4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void minimap_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB194: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AB198: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB19C: sb          $t6, 0x6CD1($at)
    MEM_B(0X6CD1, ctx->r1) = ctx->r14;
    // 0x800AB1A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800AB1A4: jr          $ra
    // 0x800AB1A8: sb          $a0, 0x6CD3($at)
    MEM_B(0X6CD3, ctx->r1) = ctx->r4;
    return;
    // 0x800AB1A8: sb          $a0, 0x6CD3($at)
    MEM_B(0X6CD3, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_init_animator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800376E0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800376E4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800376E8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800376EC: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x800376F0: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800376F4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800376F8: jal         0x8002C7C4
    // 0x800376FC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x800376FC: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    after_0:
    // 0x80037700: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80037704: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    // 0x80037708: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x8003770C: lb          $t6, 0x8($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X8);
    // 0x80037710: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x80037714: sh          $t6, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r14;
    // 0x80037718: lb          $t7, 0x9($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X9);
    // 0x8003771C: nop

    // 0x80037720: sh          $t7, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r15;
    // 0x80037724: lb          $t8, 0xA($a1)
    ctx->r24 = MEM_B(ctx->r5, 0XA);
    // 0x80037728: nop

    // 0x8003772C: sh          $t8, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r24;
    // 0x80037730: lw          $a2, 0x14($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X14);
    // 0x80037734: lwc1        $f14, 0x10($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80037738: lwc1        $f12, 0xC($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0XC);
    // 0x8003773C: jal         0x80029F18
    // 0x80037740: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_1;
    // 0x80037740: nop

    after_1:
    // 0x80037744: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80037748: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8003774C: sh          $v0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r2;
    // 0x80037750: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80037754: nop

    // 0x80037758: bne         $t9, $zero, L_80037768
    if (ctx->r25 != 0) {
        // 0x8003775C: nop
    
            goto L_80037768;
    }
    // 0x8003775C: nop

    // 0x80037760: sh          $zero, 0x8($v1)
    MEM_H(0X8, ctx->r3) = 0;
    // 0x80037764: sh          $zero, 0xA($v1)
    MEM_H(0XA, ctx->r3) = 0;
L_80037768:
    // 0x80037768: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8003776C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80037770: beq         $v0, $at, L_800377CC
    if (ctx->r2 == ctx->r1) {
        // 0x80037774: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_800377CC;
    }
    // 0x80037774: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80037778: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x8003777C: nop

    // 0x80037780: bgez        $a0, L_8003779C
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80037784: lw          $t0, 0x18($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X18);
            goto L_8003779C;
    }
    // 0x80037784: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x80037788: sh          $zero, 0x2($v1)
    MEM_H(0X2, ctx->r3) = 0;
    // 0x8003778C: lh          $a0, 0x2($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X2);
    // 0x80037790: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x80037794: nop

    // 0x80037798: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
L_8003779C:
    // 0x8003779C: sll         $t2, $v0, 4
    ctx->r10 = S32(ctx->r2 << 4);
    // 0x800377A0: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800377A4: addu        $t2, $t2, $v0
    ctx->r10 = ADD32(ctx->r10, ctx->r2);
    // 0x800377A8: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800377AC: addu        $t3, $t1, $t2
    ctx->r11 = ADD32(ctx->r9, ctx->r10);
    // 0x800377B0: lh          $a1, 0x20($t3)
    ctx->r5 = MEM_H(ctx->r11, 0X20);
    // 0x800377B4: nop

    // 0x800377B8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800377BC: bne         $at, $zero, L_800377C8
    if (ctx->r1 != 0) {
        // 0x800377C0: addiu       $t4, $a1, -0x1
        ctx->r12 = ADD32(ctx->r5, -0X1);
            goto L_800377C8;
    }
    // 0x800377C0: addiu       $t4, $a1, -0x1
    ctx->r12 = ADD32(ctx->r5, -0X1);
    // 0x800377C4: sh          $t4, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r12;
L_800377C8:
    // 0x800377C8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_800377CC:
    // 0x800377CC: jal         0x800377E4
    // 0x800377D0: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    obj_loop_animator(rdram, ctx);
        goto after_2;
    // 0x800377D0: lui         $a1, 0x2
    ctx->r5 = S32(0X2 << 16);
    after_2:
    // 0x800377D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800377D8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800377DC: jr          $ra
    // 0x800377E0: nop

    return;
    // 0x800377E0: nop

;}
RECOMP_FUNC void sndp_get_state_counts(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800042CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800042D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800042D4: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800042D8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800042DC: jal         0x800C9A30
    // 0x800042E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    osSetIntMask_recomp(rdram, ctx);
        goto after_0;
    // 0x800042E0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x800042E4: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800042E8: addiu       $a3, $a3, -0x3950
    ctx->r7 = ADD32(ctx->r7, -0X3950);
    // 0x800042EC: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800042F0: lw          $a0, 0x8($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X8);
    // 0x800042F4: lw          $a1, 0x4($a3)
    ctx->r5 = MEM_W(ctx->r7, 0X4);
    // 0x800042F8: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800042FC: beq         $v1, $zero, L_80004318
    if (ctx->r3 == 0) {
        // 0x80004300: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80004318;
    }
    // 0x80004300: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80004304:
    // 0x80004304: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x80004308: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8000430C: andi        $t6, $a2, 0xFFFF
    ctx->r14 = ctx->r6 & 0XFFFF;
    // 0x80004310: bne         $v1, $zero, L_80004304
    if (ctx->r3 != 0) {
        // 0x80004314: or          $a2, $t6, $zero
        ctx->r6 = ctx->r14 | 0;
            goto L_80004304;
    }
    // 0x80004314: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
L_80004318:
    // 0x80004318: beq         $a0, $zero, L_80004334
    if (ctx->r4 == 0) {
        // 0x8000431C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80004334;
    }
    // 0x8000431C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80004320:
    // 0x80004320: lw          $a0, 0x0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X0);
    // 0x80004324: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80004328: andi        $t7, $v0, 0xFFFF
    ctx->r15 = ctx->r2 & 0XFFFF;
    // 0x8000432C: bne         $a0, $zero, L_80004320
    if (ctx->r4 != 0) {
        // 0x80004330: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_80004320;
    }
    // 0x80004330: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_80004334:
    // 0x80004334: beq         $a1, $zero, L_80004350
    if (ctx->r5 == 0) {
        // 0x80004338: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80004350;
    }
    // 0x80004338: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000433C:
    // 0x8000433C: lw          $a1, 0x4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4);
    // 0x80004340: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80004344: andi        $t8, $v1, 0xFFFF
    ctx->r24 = ctx->r3 & 0XFFFF;
    // 0x80004348: bne         $a1, $zero, L_8000433C
    if (ctx->r5 != 0) {
        // 0x8000434C: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8000433C;
    }
    // 0x8000434C: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_80004350:
    // 0x80004350: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x80004354: nop

    // 0x80004358: sh          $v0, 0x0($t9)
    MEM_H(0X0, ctx->r25) = ctx->r2;
    // 0x8000435C: lw          $t0, 0x2C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X2C);
    // 0x80004360: nop

    // 0x80004364: sh          $a2, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r6;
    // 0x80004368: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8000436C: jal         0x800C9A30
    // 0x80004370: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    osSetIntMask_recomp(rdram, ctx);
        goto after_1;
    // 0x80004370: sh          $v1, 0x1E($sp)
    MEM_H(0X1E, ctx->r29) = ctx->r3;
    after_1:
    // 0x80004374: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80004378: lhu         $v0, 0x1E($sp)
    ctx->r2 = MEM_HU(ctx->r29, 0X1E);
    // 0x8000437C: jr          $ra
    // 0x80004380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80004380: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void timetrial_ghost_write(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059BF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80059BF4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059BF8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80059BFC: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x80059C00: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80059C04: lh          $a0, 0x164($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X164);
    // 0x80059C08: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80059C0C: jal         0x800707F8
    // 0x80059C10: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    coss_f(rdram, ctx);
        goto after_0;
    // 0x80059C10: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    after_0:
    // 0x80059C14: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80059C18: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80059C1C: lh          $t7, 0x166($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X166);
    // 0x80059C20: lh          $t6, 0x162($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X162);
    // 0x80059C24: nop

    // 0x80059C28: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x80059C2C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80059C30: jal         0x800707F8
    // 0x80059C34: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80059C34: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x80059C38: lwc1        $f4, 0x18($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80059C3C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80059C40: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80059C44: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80059C48: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x80059C4C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80059C50: c.lt.s      $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f12.fl < ctx->f6.fl;
    // 0x80059C54: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80059C58: bc1f        L_80059C78
    if (!c1cs) {
        // 0x80059C5C: addiu       $t1, $t1, -0x2A62
        ctx->r9 = ADD32(ctx->r9, -0X2A62);
            goto L_80059C78;
    }
    // 0x80059C5C: addiu       $t1, $t1, -0x2A62
    ctx->r9 = ADD32(ctx->r9, -0X2A62);
    // 0x80059C60: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80059C64: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80059C68: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80059C6C: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80059C70: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80059C74: cvt.s.d     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f2.fl = CVT_S_D(ctx->f16.d);
L_80059C78:
    // 0x80059C78: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x80059C7C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80059C80: lui         $at, 0x4188
    ctx->r1 = S32(0X4188 << 16);
    // 0x80059C84: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80059C88: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80059C8C: mul.s       $f18, $f2, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80059C90: sh          $t8, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r24;
    // 0x80059C94: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80059C98: nop

    // 0x80059C9C: bgtz        $a0, L_80059E10
    if (SIGNED(ctx->r4) > 0) {
        // 0x80059CA0: sub.s       $f2, $f0, $f18
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
            goto L_80059E10;
    }
    // 0x80059CA0: sub.s       $f2, $f0, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f0.fl - ctx->f18.fl;
    // 0x80059CA4: bgtz        $a0, L_80059E10
    if (SIGNED(ctx->r4) > 0) {
        // 0x80059CA8: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80059E10;
    }
    // 0x80059CA8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80059CAC: lb          $a1, -0x2A64($a1)
    ctx->r5 = MEM_B(ctx->r5, -0X2A64);
    // 0x80059CB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80059CB4: addiu       $t6, $t6, -0x2A60
    ctx->r14 = ADD32(ctx->r14, -0X2A60);
    // 0x80059CB8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80059CBC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80059CC0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059CC4: sll         $t9, $a1, 1
    ctx->r25 = S32(ctx->r5 << 1);
    // 0x80059CC8: addu        $v1, $t9, $t6
    ctx->r3 = ADD32(ctx->r25, ctx->r14);
    // 0x80059CCC: addiu       $t2, $t2, -0x2A64
    ctx->r10 = ADD32(ctx->r10, -0X2A64);
    // 0x80059CD0: addiu       $t4, $t4, -0x2A70
    ctx->r12 = ADD32(ctx->r12, -0X2A70);
    // 0x80059CD4: addiu       $t5, $t5, -0x2A60
    ctx->r13 = ADD32(ctx->r13, -0X2A60);
    // 0x80059CD8: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
L_80059CDC:
    // 0x80059CDC: lh          $a3, 0x0($v1)
    ctx->r7 = MEM_H(ctx->r3, 0X0);
    // 0x80059CE0: addiu       $t7, $a0, 0x1E
    ctx->r15 = ADD32(ctx->r4, 0X1E);
    // 0x80059CE4: slti        $at, $a3, 0x168
    ctx->r1 = SIGNED(ctx->r7) < 0X168 ? 1 : 0;
    // 0x80059CE8: bne         $at, $zero, L_80059D20
    if (ctx->r1 != 0) {
        // 0x80059CEC: sh          $t7, 0x0($t1)
        MEM_H(0X0, ctx->r9) = ctx->r15;
            goto L_80059D20;
    }
    // 0x80059CEC: sh          $t7, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r15;
    // 0x80059CF0: jal         0x8006EAB0
    // 0x80059CF4: nop

    is_postrace_viewport_active(rdram, ctx);
        goto after_2;
    // 0x80059CF4: nop

    after_2:
    // 0x80059CF8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80059CFC: bne         $v0, $zero, L_80059E10
    if (ctx->r2 != 0) {
        // 0x80059D00: addiu       $t2, $t2, -0x2A64
        ctx->r10 = ADD32(ctx->r10, -0X2A64);
            goto L_80059E10;
    }
    // 0x80059D00: addiu       $t2, $t2, -0x2A64
    ctx->r10 = ADD32(ctx->r10, -0X2A64);
    // 0x80059D04: lb          $t9, 0x0($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X0);
    // 0x80059D08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059D0C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80059D10: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80059D14: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80059D18: b           L_80059E10
    // 0x80059D1C: sh          $t8, -0x2A58($at)
    MEM_H(-0X2A58, ctx->r1) = ctx->r24;
        goto L_80059E10;
    // 0x80059D1C: sh          $t8, -0x2A58($at)
    MEM_H(-0X2A58, ctx->r1) = ctx->r24;
L_80059D20:
    // 0x80059D20: multu       $a3, $t3
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80059D24: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x80059D28: addu        $t8, $t4, $t9
    ctx->r24 = ADD32(ctx->r12, ctx->r25);
    // 0x80059D2C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80059D30: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80059D34: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80059D38: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059D3C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059D40: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x80059D44: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80059D48: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80059D4C: mflo        $t7
    ctx->r15 = lo;
    // 0x80059D50: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x80059D54: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80059D58: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80059D5C: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80059D60: nop

    // 0x80059D64: add.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f2.fl;
    // 0x80059D68: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80059D6C: nop

    // 0x80059D70: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80059D74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059D78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059D7C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80059D80: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80059D84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80059D88: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x80059D8C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80059D90: sh          $t6, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r14;
    // 0x80059D94: lwc1        $f18, 0x14($a2)
    ctx->f18.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80059D98: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80059D9C: nop

    // 0x80059DA0: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80059DA4: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80059DA8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80059DAC: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x80059DB0: lh          $t6, 0x160($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X160);
    // 0x80059DB4: lh          $t7, 0x0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X0);
    // 0x80059DB8: nop

    // 0x80059DBC: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x80059DC0: sh          $t9, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r25;
    // 0x80059DC4: lh          $t7, 0x162($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X162);
    // 0x80059DC8: lh          $t8, 0x2($a2)
    ctx->r24 = MEM_H(ctx->r6, 0X2);
    // 0x80059DCC: nop

    // 0x80059DD0: addu        $t6, $t8, $t7
    ctx->r14 = ADD32(ctx->r24, ctx->r15);
    // 0x80059DD4: sh          $t6, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r14;
    // 0x80059DD8: lh          $t8, 0x164($t0)
    ctx->r24 = MEM_H(ctx->r8, 0X164);
    // 0x80059DDC: lh          $t9, 0x4($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X4);
    // 0x80059DE0: nop

    // 0x80059DE4: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x80059DE8: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x80059DEC: lb          $a1, 0x0($t2)
    ctx->r5 = MEM_B(ctx->r10, 0X0);
    // 0x80059DF0: lh          $a0, 0x0($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X0);
    // 0x80059DF4: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x80059DF8: addu        $v1, $t5, $t6
    ctx->r3 = ADD32(ctx->r13, ctx->r14);
    // 0x80059DFC: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x80059E00: nop

    // 0x80059E04: addiu       $t8, $t9, 0x1
    ctx->r24 = ADD32(ctx->r25, 0X1);
    // 0x80059E08: blez        $a0, L_80059CDC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80059E0C: sh          $t8, 0x0($v1)
        MEM_H(0X0, ctx->r3) = ctx->r24;
            goto L_80059CDC;
    }
    // 0x80059E0C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
L_80059E10:
    // 0x80059E10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059E14: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80059E18: jr          $ra
    // 0x80059E1C: nop

    return;
    // 0x80059E1C: nop

;}
RECOMP_FUNC void handle_base_steering(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800579B0: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800579B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800579B8: lw          $t6, -0x2ACC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2ACC);
    // 0x800579BC: lb          $v1, 0x1E1($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X1E1);
    // 0x800579C0: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800579C4: subu        $v0, $t6, $v1
    ctx->r2 = SUB32(ctx->r14, ctx->r3);
    // 0x800579C8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800579CC: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800579D0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800579D4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800579D8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800579DC: mul.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800579E0: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800579E4: mul.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x800579E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800579EC: nop

    // 0x800579F0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800579F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800579F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800579FC: nop

    // 0x80057A00: cvt.w.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_D(ctx->f18.d);
    // 0x80057A04: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80057A08: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80057A0C: beq         $v0, $zero, L_80057A34
    if (ctx->r2 == 0) {
        // 0x80057A10: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_80057A34;
    }
    // 0x80057A10: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x80057A14: bne         $a2, $zero, L_80057A38
    if (ctx->r6 != 0) {
        // 0x80057A18: addu        $t8, $v1, $a1
        ctx->r24 = ADD32(ctx->r3, ctx->r5);
            goto L_80057A38;
    }
    // 0x80057A18: addu        $t8, $v1, $a1
    ctx->r24 = ADD32(ctx->r3, ctx->r5);
    // 0x80057A1C: blez        $v0, L_80057A28
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80057A20: nop
    
            goto L_80057A28;
    }
    // 0x80057A20: nop

    // 0x80057A24: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80057A28:
    // 0x80057A28: bgez        $v0, L_80057A38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80057A2C: addu        $t8, $v1, $a1
        ctx->r24 = ADD32(ctx->r3, ctx->r5);
            goto L_80057A38;
    }
    // 0x80057A2C: addu        $t8, $v1, $a1
    ctx->r24 = ADD32(ctx->r3, ctx->r5);
    // 0x80057A30: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
L_80057A34:
    // 0x80057A34: addu        $t8, $v1, $a1
    ctx->r24 = ADD32(ctx->r3, ctx->r5);
L_80057A38:
    // 0x80057A38: jr          $ra
    // 0x80057A3C: sb          $t8, 0x1E1($a0)
    MEM_B(0X1E1, ctx->r4) = ctx->r24;
    return;
    // 0x80057A3C: sb          $t8, 0x1E1($a0)
    MEM_B(0X1E1, ctx->r4) = ctx->r24;
;}
RECOMP_FUNC void disable_racer_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A3B0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8005A3B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A3B8: jr          $ra
    // 0x8005A3BC: sb          $t6, -0x2A7C($at)
    MEM_B(-0X2A7C, ctx->r1) = ctx->r14;
    return;
    // 0x8005A3BC: sb          $t6, -0x2A7C($at)
    MEM_B(-0X2A7C, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void sound_is_looped(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800021B0: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800021B4: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800021B8: blez        $t6, L_800021F0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800021BC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800021F0;
    }
    // 0x800021BC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800021C0: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x800021C4: lw          $t7, 0x5D14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5D14);
    // 0x800021C8: sll         $t0, $v1, 2
    ctx->r8 = S32(ctx->r3 << 2);
    // 0x800021CC: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800021D0: nop

    // 0x800021D4: lw          $a0, 0xC($t8)
    ctx->r4 = MEM_W(ctx->r24, 0XC);
    // 0x800021D8: nop

    // 0x800021DC: lh          $t9, 0xE($a0)
    ctx->r25 = MEM_H(ctx->r4, 0XE);
    // 0x800021E0: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800021E4: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800021E8: beq         $at, $zero, L_800021F8
    if (ctx->r1 == 0) {
        // 0x800021EC: nop
    
            goto L_800021F8;
    }
    // 0x800021EC: nop

L_800021F0:
    // 0x800021F0: jr          $ra
    // 0x800021F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800021F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800021F8:
    // 0x800021F8: lw          $t2, 0xC($t1)
    ctx->r10 = MEM_W(ctx->r9, 0XC);
    // 0x800021FC: nop

    // 0x80002200: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x80002204: nop

    // 0x80002208: lw          $v0, 0x4($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X4);
    // 0x8000220C: nop

    // 0x80002210: addiu       $t4, $v0, 0x1
    ctx->r12 = ADD32(ctx->r2, 0X1);
    // 0x80002214: sltiu       $t4, $t4, 0x1
    ctx->r12 = ctx->r12 < 0X1 ? 1 : 0;
    // 0x80002218: andi        $v0, $t4, 0xFF
    ctx->r2 = ctx->r12 & 0XFF;
    // 0x8000221C: jr          $ra
    // 0x80002220: nop

    return;
    // 0x80002220: nop

;}
RECOMP_FUNC void timetrial_ghost_staff(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001B640: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8001B644: lw          $v0, -0x38E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X38E8);
    // 0x8001B648: jr          $ra
    // 0x8001B64C: nop

    return;
    // 0x8001B64C: nop

;}
RECOMP_FUNC void charselect_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C274: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C278: jr          $ra
    // 0x8009C27C: addiu       $v0, $v0, 0x63DC
    ctx->r2 = ADD32(ctx->r2, 0X63DC);
    return;
    // 0x8009C27C: addiu       $v0, $v0, 0x63DC
    ctx->r2 = ADD32(ctx->r2, 0X63DC);
;}
RECOMP_FUNC void gzip_huft_build(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C6274: addiu       $sp, $sp, -0x5F8
    ctx->r29 = ADD32(ctx->r29, -0X5F8);
    // 0x800C6278: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800C627C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800C6280: addiu       $s1, $sp, 0x5B0
    ctx->r17 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6284: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800C6288: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800C628C: sw          $a1, 0x5FC($sp)
    MEM_W(0X5FC, ctx->r29) = ctx->r5;
    // 0x800C6290: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800C6294: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800C6298: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800C629C: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800C62A0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800C62A4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800C62A8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C62AC: sw          $a2, 0x600($sp)
    MEM_W(0X600, ctx->r29) = ctx->r6;
    // 0x800C62B0: sw          $a3, 0x604($sp)
    MEM_W(0X604, ctx->r29) = ctx->r7;
    // 0x800C62B4: addiu       $a1, $zero, 0x44
    ctx->r5 = ADD32(0, 0X44);
    // 0x800C62B8: jal         0x800D04E0
    // 0x800C62BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    _bzero(rdram, ctx);
        goto after_0;
    // 0x800C62BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_0:
    // 0x800C62C0: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C62C4: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x800C62C8: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x800C62CC: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800C62D0: beq         $v0, $zero, L_800C6308
    if (ctx->r2 == 0) {
        // 0x800C62D4: or          $ra, $t6, $zero
        ctx->r31 = ctx->r14 | 0;
            goto L_800C6308;
    }
    // 0x800C62D4: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x800C62D8: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
L_800C62DC:
    // 0x800C62DC: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C62E0: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C62E4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C62E8: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C62EC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C62F0: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C62F4: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C62F8: bne         $v1, $ra, L_800C62DC
    if (ctx->r3 != ctx->r31) {
        // 0x800C62FC: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_800C62DC;
    }
    // 0x800C62FC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C6300: beq         $ra, $zero, L_800C6390
    if (ctx->r31 == 0) {
        // 0x800C6304: lw          $t7, 0x5FC($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5FC);
            goto L_800C6390;
    }
    // 0x800C6304: lw          $t7, 0x5FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5FC);
L_800C6308:
    // 0x800C6308: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C630C: addiu       $ra, $ra, -0x4
    ctx->r31 = ADD32(ctx->r31, -0X4);
    // 0x800C6310: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6314: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C6318: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C631C: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    // 0x800C6320: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C6324: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C6328: lw          $t7, -0xC($fp)
    ctx->r15 = MEM_W(ctx->r30, -0XC);
    // 0x800C632C: nop

    // 0x800C6330: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6334: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C6338: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C633C: nop

    // 0x800C6340: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C6344: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C6348: lw          $t7, -0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X8);
    // 0x800C634C: nop

    // 0x800C6350: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6354: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C6358: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C635C: nop

    // 0x800C6360: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C6364: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C6368: lw          $t7, -0x4($fp)
    ctx->r15 = MEM_W(ctx->r30, -0X4);
    // 0x800C636C: nop

    // 0x800C6370: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800C6374: addu        $v0, $s1, $t8
    ctx->r2 = ADD32(ctx->r17, ctx->r24);
    // 0x800C6378: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C637C: nop

    // 0x800C6380: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800C6384: bne         $ra, $zero, L_800C6308
    if (ctx->r31 != 0) {
        // 0x800C6388: sw          $t6, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r14;
            goto L_800C6308;
    }
    // 0x800C6388: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800C638C: lw          $t7, 0x5FC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5FC);
L_800C6390:
    // 0x800C6390: lw          $t8, 0x5B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5B0);
    // 0x800C6394: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x800C6398: bne         $t7, $t8, L_800C63B8
    if (ctx->r15 != ctx->r24) {
        // 0x800C639C: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800C63B8;
    }
    // 0x800C639C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800C63A0: lw          $a1, 0x610($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X610);
    // 0x800C63A4: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x800C63A8: nop

    // 0x800C63AC: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800C63B0: b           L_800C688C
    // 0x800C63B4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_800C688C;
    // 0x800C63B4: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_800C63B8:
    // 0x800C63B8: lw          $s0, 0x0($a1)
    ctx->r16 = MEM_W(ctx->r5, 0X0);
    // 0x800C63BC: addiu       $a0, $sp, 0x5B4
    ctx->r4 = ADD32(ctx->r29, 0X5B4);
    // 0x800C63C0: addiu       $v0, $zero, 0x11
    ctx->r2 = ADD32(0, 0X11);
L_800C63C4:
    // 0x800C63C4: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x800C63C8: nop

    // 0x800C63CC: bne         $t9, $zero, L_800C63E4
    if (ctx->r25 != 0) {
        // 0x800C63D0: sltu        $at, $s0, $a3
        ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
            goto L_800C63E4;
    }
    // 0x800C63D0: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
    // 0x800C63D4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C63D8: bne         $a3, $v0, L_800C63C4
    if (ctx->r7 != ctx->r2) {
        // 0x800C63DC: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800C63C4;
    }
    // 0x800C63DC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C63E0: sltu        $at, $s0, $a3
    ctx->r1 = ctx->r16 < ctx->r7 ? 1 : 0;
L_800C63E4:
    // 0x800C63E4: beq         $at, $zero, L_800C63F0
    if (ctx->r1 == 0) {
        // 0x800C63E8: or          $s4, $a3, $zero
        ctx->r20 = ctx->r7 | 0;
            goto L_800C63F0;
    }
    // 0x800C63E8: or          $s4, $a3, $zero
    ctx->r20 = ctx->r7 | 0;
    // 0x800C63EC: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
L_800C63F0:
    // 0x800C63F0: addiu       $ra, $zero, 0x10
    ctx->r31 = ADD32(0, 0X10);
    // 0x800C63F4: addiu       $v1, $sp, 0x5F0
    ctx->r3 = ADD32(ctx->r29, 0X5F0);
L_800C63F8:
    // 0x800C63F8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C63FC: nop

    // 0x800C6400: bne         $t6, $zero, L_800C6418
    if (ctx->r14 != 0) {
        // 0x800C6404: sltu        $at, $ra, $s0
        ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
            goto L_800C6418;
    }
    // 0x800C6404: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
    // 0x800C6408: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C640C: bne         $ra, $zero, L_800C63F8
    if (ctx->r31 != 0) {
        // 0x800C6410: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800C63F8;
    }
    // 0x800C6410: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C6414: sltu        $at, $ra, $s0
    ctx->r1 = ctx->r31 < ctx->r16 ? 1 : 0;
L_800C6418:
    // 0x800C6418: beq         $at, $zero, L_800C6424
    if (ctx->r1 == 0) {
        // 0x800C641C: sw          $ra, 0x5A8($sp)
        MEM_W(0X5A8, ctx->r29) = ctx->r31;
            goto L_800C6424;
    }
    // 0x800C641C: sw          $ra, 0x5A8($sp)
    MEM_W(0X5A8, ctx->r29) = ctx->r31;
    // 0x800C6420: or          $s0, $ra, $zero
    ctx->r16 = ctx->r31 | 0;
L_800C6424:
    // 0x800C6424: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C6428: sltu        $at, $a3, $ra
    ctx->r1 = ctx->r7 < ctx->r31 ? 1 : 0;
    // 0x800C642C: sw          $s0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r16;
    // 0x800C6430: beq         $at, $zero, L_800C6460
    if (ctx->r1 == 0) {
        // 0x800C6434: sllv        $v0, $t7, $a3
        ctx->r2 = S32(ctx->r15 << (ctx->r7 & 31));
            goto L_800C6460;
    }
    // 0x800C6434: sllv        $v0, $t7, $a3
    ctx->r2 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x800C6438: sll         $t8, $ra, 2
    ctx->r24 = S32(ctx->r31 << 2);
    // 0x800C643C: addiu       $t9, $sp, 0x5B0
    ctx->r25 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6440: addu        $a1, $t8, $t9
    ctx->r5 = ADD32(ctx->r24, ctx->r25);
L_800C6444:
    // 0x800C6444: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800C6448: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800C644C: subu        $v0, $v0, $t6
    ctx->r2 = SUB32(ctx->r2, ctx->r14);
    // 0x800C6450: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800C6454: sltu        $at, $a0, $a1
    ctx->r1 = ctx->r4 < ctx->r5 ? 1 : 0;
    // 0x800C6458: bne         $at, $zero, L_800C6444
    if (ctx->r1 != 0) {
        // 0x800C645C: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800C6444;
    }
    // 0x800C645C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
L_800C6460:
    // 0x800C6460: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800C6464: addiu       $ra, $ra, -0x1
    ctx->r31 = ADD32(ctx->r31, -0X1);
    // 0x800C6468: subu        $v0, $v0, $a0
    ctx->r2 = SUB32(ctx->r2, ctx->r4);
    // 0x800C646C: addu        $t8, $a0, $v0
    ctx->r24 = ADD32(ctx->r4, ctx->r2);
    // 0x800C6470: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C6474: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800C6478: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800C647C: addiu       $fp, $sp, 0x5B4
    ctx->r30 = ADD32(ctx->r29, 0X5B4);
    // 0x800C6480: addiu       $a2, $sp, 0x84
    ctx->r6 = ADD32(ctx->r29, 0X84);
    // 0x800C6484: beq         $ra, $zero, L_800C6514
    if (ctx->r31 == 0) {
        // 0x800C6488: addiu       $v1, $v1, -0x4
        ctx->r3 = ADD32(ctx->r3, -0X4);
            goto L_800C6514;
    }
    // 0x800C6488: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C648C: andi        $a1, $ra, 0x3
    ctx->r5 = ctx->r31 & 0X3;
    // 0x800C6490: negu        $a1, $a1
    ctx->r5 = SUB32(0, ctx->r5);
    // 0x800C6494: beq         $a1, $zero, L_800C64CC
    if (ctx->r5 == 0) {
        // 0x800C6498: addu        $v0, $a1, $ra
        ctx->r2 = ADD32(ctx->r5, ctx->r31);
            goto L_800C64CC;
    }
    // 0x800C6498: addu        $v0, $a1, $ra
    ctx->r2 = ADD32(ctx->r5, ctx->r31);
    // 0x800C649C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x800C64A0: addiu       $t6, $sp, 0x5B0
    ctx->r14 = ADD32(ctx->r29, 0X5B0);
    // 0x800C64A4: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
L_800C64A8:
    // 0x800C64A8: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x800C64AC: addiu       $v1, $v1, -0x4
    ctx->r3 = ADD32(ctx->r3, -0X4);
    // 0x800C64B0: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C64B4: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x800C64B8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C64BC: bne         $a0, $v1, L_800C64A8
    if (ctx->r4 != ctx->r3) {
        // 0x800C64C0: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_800C64A8;
    }
    // 0x800C64C0: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C64C4: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800C64C8: beq         $v1, $t8, L_800C6514
    if (ctx->r3 == ctx->r24) {
        // 0x800C64CC: addiu       $v0, $sp, 0x5B0
        ctx->r2 = ADD32(ctx->r29, 0X5B0);
            goto L_800C6514;
    }
L_800C64CC:
    // 0x800C64CC: addiu       $v0, $sp, 0x5B0
    ctx->r2 = ADD32(ctx->r29, 0X5B0);
L_800C64D0:
    // 0x800C64D0: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800C64D4: addiu       $v1, $v1, -0x10
    ctx->r3 = ADD32(ctx->r3, -0X10);
    // 0x800C64D8: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x800C64DC: sw          $a3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r7;
    // 0x800C64E0: lw          $t6, 0x4($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X4);
    // 0x800C64E4: addiu       $a2, $a2, 0x10
    ctx->r6 = ADD32(ctx->r6, 0X10);
    // 0x800C64E8: addu        $a3, $a3, $t6
    ctx->r7 = ADD32(ctx->r7, ctx->r14);
    // 0x800C64EC: sw          $a3, -0xC($a2)
    MEM_W(-0XC, ctx->r6) = ctx->r7;
    // 0x800C64F0: lw          $t7, 0x8($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X8);
    // 0x800C64F4: addiu       $fp, $fp, 0x10
    ctx->r30 = ADD32(ctx->r30, 0X10);
    // 0x800C64F8: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C64FC: sw          $a3, -0x8($a2)
    MEM_W(-0X8, ctx->r6) = ctx->r7;
    // 0x800C6500: lw          $t8, -0x4($fp)
    ctx->r24 = MEM_W(ctx->r30, -0X4);
    // 0x800C6504: nop

    // 0x800C6508: addu        $a3, $a3, $t8
    ctx->r7 = ADD32(ctx->r7, ctx->r24);
    // 0x800C650C: bne         $v1, $v0, L_800C64D0
    if (ctx->r3 != ctx->r2) {
        // 0x800C6510: sw          $a3, -0x4($a2)
        MEM_W(-0X4, ctx->r6) = ctx->r7;
            goto L_800C64D0;
    }
    // 0x800C6510: sw          $a3, -0x4($a2)
    MEM_W(-0X4, ctx->r6) = ctx->r7;
L_800C6514:
    // 0x800C6514: or          $fp, $s2, $zero
    ctx->r30 = ctx->r18 | 0;
    // 0x800C6518: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800C651C: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x800C6520: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
L_800C6524:
    // 0x800C6524: lw          $a3, 0x0($fp)
    ctx->r7 = MEM_W(ctx->r30, 0X0);
    // 0x800C6528: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C652C: beq         $a3, $zero, L_800C6554
    if (ctx->r7 == 0) {
        // 0x800C6530: sll         $t9, $a3, 2
        ctx->r25 = S32(ctx->r7 << 2);
            goto L_800C6554;
    }
    // 0x800C6530: sll         $t9, $a3, 2
    ctx->r25 = S32(ctx->r7 << 2);
    // 0x800C6534: addu        $v0, $a1, $t9
    ctx->r2 = ADD32(ctx->r5, ctx->r25);
    // 0x800C6538: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800C653C: nop

    // 0x800C6540: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800C6544: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800C6548: sw          $ra, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r31;
    // 0x800C654C: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800C6550: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
L_800C6554:
    // 0x800C6554: lw          $t9, 0x5FC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C6558: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x800C655C: sltu        $at, $ra, $t9
    ctx->r1 = ctx->r31 < ctx->r25 ? 1 : 0;
    // 0x800C6560: bne         $at, $zero, L_800C6524
    if (ctx->r1 != 0) {
        // 0x800C6564: nop
    
            goto L_800C6524;
    }
    // 0x800C6564: nop

    // 0x800C6568: lw          $t6, 0x5A8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5A8);
    // 0x800C656C: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800C6570: slt         $at, $t6, $s4
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6574: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x800C6578: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x800C657C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800C6580: negu        $t2, $s0
    ctx->r10 = SUB32(0, ctx->r16);
    // 0x800C6584: sw          $zero, 0x544($sp)
    MEM_W(0X544, ctx->r29) = 0;
    // 0x800C6588: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C658C: bne         $at, $zero, L_800C688C
    if (ctx->r1 != 0) {
        // 0x800C6590: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_800C688C;
    }
    // 0x800C6590: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800C6594: sll         $t7, $s4, 2
    ctx->r15 = S32(ctx->r20 << 2);
    // 0x800C6598: addiu       $t8, $sp, 0x5B0
    ctx->r24 = ADD32(ctx->r29, 0X5B0);
    // 0x800C659C: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800C65A0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C65A4: lw          $s5, 0x60C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X60C);
    // 0x800C65A8: addiu       $s2, $s2, -0x5528
    ctx->r18 = ADD32(ctx->r18, -0X5528);
    // 0x800C65AC: addiu       $s7, $s7, 0x3760
    ctx->r23 = ADD32(ctx->r23, 0X3760);
    // 0x800C65B0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800C65B4: addiu       $s3, $sp, 0x584
    ctx->r19 = ADD32(ctx->r29, 0X584);
L_800C65B8:
    // 0x800C65B8: lw          $s6, 0x0($v0)
    ctx->r22 = MEM_W(ctx->r2, 0X0);
    // 0x800C65BC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x800C65C0: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x800C65C4: beq         $s6, $zero, L_800C6874
    if (ctx->r22 == 0) {
        // 0x800C65C8: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800C6874;
    }
    // 0x800C65C8: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800C65CC: lw          $t6, 0x5FC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5FC);
    // 0x800C65D0: addiu       $t9, $sp, 0x7C
    ctx->r25 = ADD32(ctx->r29, 0X7C);
    // 0x800C65D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800C65D8: addu        $t3, $t5, $t9
    ctx->r11 = ADD32(ctx->r13, ctx->r25);
    // 0x800C65DC: addiu       $t8, $sp, 0xC4
    ctx->r24 = ADD32(ctx->r29, 0XC4);
    // 0x800C65E0: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C65E4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C65E8: addiu       $t6, $s4, 0x1F
    ctx->r14 = ADD32(ctx->r20, 0X1F);
    // 0x800C65EC: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x800C65F0: sw          $t8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r24;
    // 0x800C65F4: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800C65F8: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
L_800C65FC:
    // 0x800C65FC: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800C6600: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6604: beq         $at, $zero, L_800C6724
    if (ctx->r1 == 0) {
        // 0x800C6608: addiu       $s1, $s6, 0x1
        ctx->r17 = ADD32(ctx->r22, 0X1);
            goto L_800C6724;
    }
    // 0x800C6608: addiu       $s1, $s6, 0x1
    ctx->r17 = ADD32(ctx->r22, 0X1);
    // 0x800C660C: addiu       $t9, $sp, 0x544
    ctx->r25 = ADD32(ctx->r29, 0X544);
    // 0x800C6610: addu        $t1, $t5, $t9
    ctx->r9 = ADD32(ctx->r13, ctx->r25);
    // 0x800C6614: lw          $t7, 0x5A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A8);
L_800C6618:
    // 0x800C6618: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C661C: subu        $t0, $t7, $v1
    ctx->r8 = SUB32(ctx->r15, ctx->r3);
    // 0x800C6620: sltu        $at, $s0, $t0
    ctx->r1 = ctx->r16 < ctx->r8 ? 1 : 0;
    // 0x800C6624: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x800C6628: addiu       $t1, $t1, 0x4
    ctx->r9 = ADD32(ctx->r9, 0X4);
    // 0x800C662C: addiu       $t3, $t3, 0x4
    ctx->r11 = ADD32(ctx->r11, 0X4);
    // 0x800C6630: beq         $at, $zero, L_800C663C
    if (ctx->r1 == 0) {
        // 0x800C6634: or          $t2, $v1, $zero
        ctx->r10 = ctx->r3 | 0;
            goto L_800C663C;
    }
    // 0x800C6634: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
    // 0x800C6638: or          $t0, $s0, $zero
    ctx->r8 = ctx->r16 | 0;
L_800C663C:
    // 0x800C663C: subu        $v0, $s4, $t2
    ctx->r2 = SUB32(ctx->r20, ctx->r10);
    // 0x800C6640: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C6644: sllv        $a0, $t6, $v0
    ctx->r4 = S32(ctx->r14 << (ctx->r2 & 31));
    // 0x800C6648: sltu        $at, $s1, $a0
    ctx->r1 = ctx->r17 < ctx->r4 ? 1 : 0;
    // 0x800C664C: beq         $at, $zero, L_800C6698
    if (ctx->r1 == 0) {
        // 0x800C6650: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800C6698;
    }
    // 0x800C6650: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800C6654: addiu       $a3, $v0, 0x1
    ctx->r7 = ADD32(ctx->r2, 0X1);
    // 0x800C6658: subu        $v1, $a0, $s6
    ctx->r3 = SUB32(ctx->r4, ctx->r22);
    // 0x800C665C: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x800C6660: addiu       $t9, $sp, 0x5B0
    ctx->r25 = ADD32(ctx->r29, 0X5B0);
    // 0x800C6664: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6668: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800C666C: beq         $at, $zero, L_800C6698
    if (ctx->r1 == 0) {
        // 0x800C6670: addu        $a2, $t8, $t9
        ctx->r6 = ADD32(ctx->r24, ctx->r25);
            goto L_800C6698;
    }
    // 0x800C6670: addu        $a2, $t8, $t9
    ctx->r6 = ADD32(ctx->r24, ctx->r25);
L_800C6674:
    // 0x800C6674: lw          $a0, 0x4($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X4);
    // 0x800C6678: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800C667C: sltu        $at, $a0, $v0
    ctx->r1 = ctx->r4 < ctx->r2 ? 1 : 0;
    // 0x800C6680: beq         $at, $zero, L_800C6698
    if (ctx->r1 == 0) {
        // 0x800C6684: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800C6698;
    }
    // 0x800C6684: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800C6688: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800C668C: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6690: bne         $at, $zero, L_800C6674
    if (ctx->r1 != 0) {
        // 0x800C6694: subu        $v1, $v0, $a0
        ctx->r3 = SUB32(ctx->r2, ctx->r4);
            goto L_800C6674;
    }
    // 0x800C6694: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
L_800C6698:
    // 0x800C6698: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800C669C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800C66A0: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800C66A4: sllv        $t0, $t7, $a3
    ctx->r8 = S32(ctx->r15 << (ctx->r7 & 31));
    // 0x800C66A8: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800C66AC: addu        $t9, $v1, $t0
    ctx->r25 = ADD32(ctx->r3, ctx->r8);
    // 0x800C66B0: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800C66B4: addu        $a2, $t6, $t8
    ctx->r6 = ADD32(ctx->r14, ctx->r24);
    // 0x800C66B8: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800C66BC: addiu       $a0, $a2, 0x8
    ctx->r4 = ADD32(ctx->r6, 0X8);
    // 0x800C66C0: sw          $a0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r4;
    // 0x800C66C4: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x800C66C8: addiu       $s5, $a2, 0x4
    ctx->r21 = ADD32(ctx->r6, 0X4);
    // 0x800C66CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800C66D0: beq         $t4, $zero, L_800C6714
    if (ctx->r12 == 0) {
        // 0x800C66D4: sw          $a0, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r4;
            goto L_800C6714;
    }
    // 0x800C66D4: sw          $a0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r4;
    // 0x800C66D8: sw          $ra, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r31;
    // 0x800C66DC: addiu       $t6, $a3, 0x10
    ctx->r14 = ADD32(ctx->r7, 0X10);
    // 0x800C66E0: sb          $t6, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r14;
    // 0x800C66E4: sb          $s0, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r16;
    // 0x800C66E8: sw          $a0, 0x588($sp)
    MEM_W(0X588, ctx->r29) = ctx->r4;
    // 0x800C66EC: subu        $t9, $t2, $s0
    ctx->r25 = SUB32(ctx->r10, ctx->r16);
    // 0x800C66F0: lw          $t8, -0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, -0X4);
    // 0x800C66F4: srlv        $t7, $ra, $t9
    ctx->r15 = S32(U32(ctx->r31) >> (ctx->r25 & 31));
    // 0x800C66F8: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x800C66FC: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800C6700: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x800C6704: sw          $at, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r1;
    // 0x800C6708: lw          $t6, 0x4($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X4);
    // 0x800C670C: nop

    // 0x800C6710: sw          $t6, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r14;
L_800C6714:
    // 0x800C6714: addu        $v1, $t2, $s0
    ctx->r3 = ADD32(ctx->r10, ctx->r16);
    // 0x800C6718: slt         $at, $v1, $s4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C671C: bne         $at, $zero, L_800C6618
    if (ctx->r1 != 0) {
        // 0x800C6720: lw          $t7, 0x5A8($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X5A8);
            goto L_800C6618;
    }
    // 0x800C6720: lw          $t7, 0x5A8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X5A8);
L_800C6724:
    // 0x800C6724: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800C6728: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C672C: subu        $v1, $s4, $t2
    ctx->r3 = SUB32(ctx->r20, ctx->r10);
    // 0x800C6730: sllv        $a1, $t8, $t2
    ctx->r5 = S32(ctx->r24 << (ctx->r10 & 31));
    // 0x800C6734: sltu        $at, $fp, $t7
    ctx->r1 = ctx->r30 < ctx->r15 ? 1 : 0;
    // 0x800C6738: sb          $v1, 0x585($sp)
    MEM_B(0X585, ctx->r29) = ctx->r3;
    // 0x800C673C: bne         $at, $zero, L_800C6750
    if (ctx->r1 != 0) {
        // 0x800C6740: addiu       $a1, $a1, -0x1
        ctx->r5 = ADD32(ctx->r5, -0X1);
            goto L_800C6750;
    }
    // 0x800C6740: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800C6744: addiu       $t9, $zero, 0x63
    ctx->r25 = ADD32(0, 0X63);
    // 0x800C6748: b           L_800C67D0
    // 0x800C674C: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
        goto L_800C67D0;
    // 0x800C674C: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
L_800C6750:
    // 0x800C6750: lw          $v0, 0x0($fp)
    ctx->r2 = MEM_W(ctx->r30, 0X0);
    // 0x800C6754: lw          $t6, 0x600($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X600);
    // 0x800C6758: lw          $a0, 0x600($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X600);
    // 0x800C675C: sltu        $at, $v0, $t6
    ctx->r1 = ctx->r2 < ctx->r14 ? 1 : 0;
    // 0x800C6760: beq         $at, $zero, L_800C6790
    if (ctx->r1 == 0) {
        // 0x800C6764: sltiu       $at, $v0, 0x100
        ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
            goto L_800C6790;
    }
    // 0x800C6764: sltiu       $at, $v0, 0x100
    ctx->r1 = ctx->r2 < 0X100 ? 1 : 0;
    // 0x800C6768: beq         $at, $zero, L_800C677C
    if (ctx->r1 == 0) {
        // 0x800C676C: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_800C677C;
    }
    // 0x800C676C: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x800C6770: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x800C6774: b           L_800C6780
    // 0x800C6778: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
        goto L_800C6780;
    // 0x800C6778: sb          $t8, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r24;
L_800C677C:
    // 0x800C677C: sb          $t7, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r15;
L_800C6780:
    // 0x800C6780: lw          $t9, 0x0($fp)
    ctx->r25 = MEM_W(ctx->r30, 0X0);
    // 0x800C6784: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C6788: b           L_800C67D0
    // 0x800C678C: sh          $t9, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r25;
        goto L_800C67D0;
    // 0x800C678C: sh          $t9, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r25;
L_800C6790:
    // 0x800C6790: lw          $t8, 0x608($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X608);
    // 0x800C6794: subu        $t6, $v0, $a0
    ctx->r14 = SUB32(ctx->r2, ctx->r4);
    // 0x800C6798: addu        $t7, $t6, $t8
    ctx->r15 = ADD32(ctx->r14, ctx->r24);
    // 0x800C679C: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800C67A0: lw          $t6, 0x604($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X604);
    // 0x800C67A4: sb          $t9, 0x584($sp)
    MEM_B(0X584, ctx->r29) = ctx->r25;
    // 0x800C67A8: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x800C67AC: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x800C67B0: sll         $t7, $t8, 1
    ctx->r15 = S32(ctx->r24 << 1);
    // 0x800C67B4: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800C67B8: addu        $t9, $t6, $t7
    ctx->r25 = ADD32(ctx->r14, ctx->r15);
    // 0x800C67BC: negu        $t6, $t8
    ctx->r14 = SUB32(0, ctx->r24);
    // 0x800C67C0: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x800C67C4: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x800C67C8: nop

    // 0x800C67CC: sh          $t8, 0x588($sp)
    MEM_H(0X588, ctx->r29) = ctx->r24;
L_800C67D0:
    // 0x800C67D0: srlv        $a3, $ra, $t2
    ctx->r7 = S32(U32(ctx->r31) >> (ctx->r10 & 31));
    // 0x800C67D4: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C67D8: beq         $at, $zero, L_800C6808
    if (ctx->r1 == 0) {
        // 0x800C67DC: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800C6808;
    }
    // 0x800C67DC: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800C67E0: sllv        $v0, $t9, $v1
    ctx->r2 = S32(ctx->r25 << (ctx->r3 & 31));
L_800C67E4:
    // 0x800C67E4: lw          $at, 0x0($s3)
    ctx->r1 = MEM_W(ctx->r19, 0X0);
    // 0x800C67E8: sll         $t6, $a3, 3
    ctx->r14 = S32(ctx->r7 << 3);
    // 0x800C67EC: addu        $t7, $a2, $t6
    ctx->r15 = ADD32(ctx->r6, ctx->r14);
    // 0x800C67F0: sw          $at, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r1;
    // 0x800C67F4: lw          $t9, 0x4($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X4);
    // 0x800C67F8: addu        $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
    // 0x800C67FC: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800C6800: bne         $at, $zero, L_800C67E4
    if (ctx->r1 != 0) {
        // 0x800C6804: sw          $t9, 0x4($t7)
        MEM_W(0X4, ctx->r15) = ctx->r25;
            goto L_800C67E4;
    }
    // 0x800C6804: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
L_800C6808:
    // 0x800C6808: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x800C680C: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x800C6810: and         $t6, $ra, $a3
    ctx->r14 = ctx->r31 & ctx->r7;
    // 0x800C6814: beq         $t6, $zero, L_800C682C
    if (ctx->r14 == 0) {
        // 0x800C6818: srl         $t8, $a3, 1
        ctx->r24 = S32(U32(ctx->r7) >> 1);
            goto L_800C682C;
    }
L_800C6818:
    // 0x800C6818: srl         $t8, $a3, 1
    ctx->r24 = S32(U32(ctx->r7) >> 1);
    // 0x800C681C: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x800C6820: and         $t7, $ra, $t8
    ctx->r15 = ctx->r31 & ctx->r24;
    // 0x800C6824: bne         $t7, $zero, L_800C6818
    if (ctx->r15 != 0) {
        // 0x800C6828: or          $a3, $t8, $zero
        ctx->r7 = ctx->r24 | 0;
            goto L_800C6818;
    }
    // 0x800C6828: or          $a3, $t8, $zero
    ctx->r7 = ctx->r24 | 0;
L_800C682C:
    // 0x800C682C: xor         $ra, $ra, $a3
    ctx->r31 = ctx->r31 ^ ctx->r7;
    // 0x800C6830: and         $t9, $ra, $a1
    ctx->r25 = ctx->r31 & ctx->r5;
    // 0x800C6834: beq         $t9, $v0, L_800C6864
    if (ctx->r25 == ctx->r2) {
        // 0x800C6838: or          $a1, $s6, $zero
        ctx->r5 = ctx->r22 | 0;
            goto L_800C6864;
    }
    // 0x800C6838: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
L_800C683C:
    // 0x800C683C: subu        $t2, $t2, $s0
    ctx->r10 = SUB32(ctx->r10, ctx->r16);
    // 0x800C6840: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800C6844: sllv        $t8, $t6, $t2
    ctx->r24 = S32(ctx->r14 << (ctx->r10 & 31));
    // 0x800C6848: lw          $t6, -0x4($t3)
    ctx->r14 = MEM_W(ctx->r11, -0X4);
    // 0x800C684C: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x800C6850: and         $t9, $ra, $t7
    ctx->r25 = ctx->r31 & ctx->r15;
    // 0x800C6854: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800C6858: addiu       $t5, $t5, -0x4
    ctx->r13 = ADD32(ctx->r13, -0X4);
    // 0x800C685C: bne         $t9, $t6, L_800C683C
    if (ctx->r25 != ctx->r14) {
        // 0x800C6860: addiu       $t3, $t3, -0x4
        ctx->r11 = ADD32(ctx->r11, -0X4);
            goto L_800C683C;
    }
    // 0x800C6860: addiu       $t3, $t3, -0x4
    ctx->r11 = ADD32(ctx->r11, -0X4);
L_800C6864:
    // 0x800C6864: bne         $s6, $zero, L_800C65FC
    if (ctx->r22 != 0) {
        // 0x800C6868: addiu       $s6, $s6, -0x1
        ctx->r22 = ADD32(ctx->r22, -0X1);
            goto L_800C65FC;
    }
    // 0x800C6868: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x800C686C: lw          $v0, 0x5C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X5C);
    // 0x800C6870: nop

L_800C6874:
    // 0x800C6874: lw          $t8, 0x5A8($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X5A8);
    // 0x800C6878: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C687C: slt         $at, $t8, $s4
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r20) ? 1 : 0;
    // 0x800C6880: beq         $at, $zero, L_800C65B8
    if (ctx->r1 == 0) {
        // 0x800C6884: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800C65B8;
    }
    // 0x800C6884: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800C6888: sw          $s5, 0x60C($sp)
    MEM_W(0X60C, ctx->r29) = ctx->r21;
L_800C688C:
    // 0x800C688C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800C6890: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C6894: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6898: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800C689C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800C68A0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800C68A4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800C68A8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800C68AC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800C68B0: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800C68B4: jr          $ra
    // 0x800C68B8: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
    return;
    // 0x800C68B8: addiu       $sp, $sp, 0x5F8
    ctx->r29 = ADD32(ctx->r29, 0X5F8);
;}
RECOMP_FUNC void material_load_simple(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007BF34: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8007BF38: addiu       $a3, $a3, 0x6374
    ctx->r7 = ADD32(ctx->r7, 0X6374);
    // 0x8007BF3C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8007BF40: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007BF44: bne         $a1, $t6, L_8007BF5C
    if (ctx->r5 != ctx->r14) {
        // 0x8007BF48: addiu       $t0, $t0, 0x6382
        ctx->r8 = ADD32(ctx->r8, 0X6382);
            goto L_8007BF5C;
    }
    // 0x8007BF48: addiu       $t0, $t0, 0x6382
    ctx->r8 = ADD32(ctx->r8, 0X6382);
    // 0x8007BF4C: lh          $t7, 0x0($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X0);
    // 0x8007BF50: nop

    // 0x8007BF54: beq         $t7, $zero, L_8007C124
    if (ctx->r15 == 0) {
        // 0x8007BF58: nop
    
            goto L_8007C124;
    }
    // 0x8007BF58: nop

L_8007BF5C:
    // 0x8007BF5C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF60: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007BF64: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007BF68: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007BF6C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007BF70: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007BF74: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8007BF78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007BF7C: sll         $t1, $v1, 4
    ctx->r9 = S32(ctx->r3 << 4);
    // 0x8007BF80: bltz        $t1, L_8007BF98
    if (SIGNED(ctx->r9) < 0) {
        // 0x8007BF84: addiu       $t0, $t0, 0x6382
        ctx->r8 = ADD32(ctx->r8, 0X6382);
            goto L_8007BF98;
    }
    // 0x8007BF84: addiu       $t0, $t0, 0x6382
    ctx->r8 = ADD32(ctx->r8, 0X6382);
    // 0x8007BF88: lh          $t2, 0x0($t0)
    ctx->r10 = MEM_H(ctx->r8, 0X0);
    // 0x8007BF8C: nop

    // 0x8007BF90: beq         $t2, $zero, L_8007BFBC
    if (ctx->r10 == 0) {
        // 0x8007BF94: nop
    
            goto L_8007BFBC;
    }
    // 0x8007BF94: nop

L_8007BF98:
    // 0x8007BF98: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007BF9C: lui         $t4, 0xB700
    ctx->r12 = S32(0XB700 << 16);
    // 0x8007BFA0: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007BFA4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8007BFA8: lui         $t5, 0x1
    ctx->r13 = S32(0X1 << 16);
    // 0x8007BFAC: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007BFB0: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x8007BFB4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x8007BFB8: nop

L_8007BFBC:
    // 0x8007BFBC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007BFC0: lw          $t7, 0x6378($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6378);
    // 0x8007BFC4: lui         $at, 0xF7FF
    ctx->r1 = S32(0XF7FF << 16);
    // 0x8007BFC8: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x8007BFCC: and         $t6, $a1, $at
    ctx->r14 = ctx->r5 & ctx->r1;
    // 0x8007BFD0: nor         $t8, $t7, $zero
    ctx->r24 = ~(ctx->r15 | 0);
    // 0x8007BFD4: and         $a1, $t6, $t8
    ctx->r5 = ctx->r14 & ctx->r24;
    // 0x8007BFD8: andi        $v0, $a1, 0x2
    ctx->r2 = ctx->r5 & 0X2;
    // 0x8007BFDC: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x8007BFE0: bne         $t9, $v0, L_8007BFF8
    if (ctx->r25 != ctx->r2) {
        // 0x8007BFE4: addiu       $at, $zero, -0x801
        ctx->r1 = ADD32(0, -0X801);
            goto L_8007BFF8;
    }
    // 0x8007BFE4: addiu       $at, $zero, -0x801
    ctx->r1 = ADD32(0, -0X801);
    // 0x8007BFE8: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x8007BFEC: nop

    // 0x8007BFF0: beq         $t1, $zero, L_8007C038
    if (ctx->r9 == 0) {
        // 0x8007BFF4: nop
    
            goto L_8007C038;
    }
    // 0x8007BFF4: nop

L_8007BFF8:
    // 0x8007BFF8: beq         $v0, $zero, L_8007C020
    if (ctx->r2 == 0) {
        // 0x8007BFFC: lui         $t6, 0xB600
        ctx->r14 = S32(0XB600 << 16);
            goto L_8007C020;
    }
    // 0x8007BFFC: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x8007C000: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C004: lui         $t3, 0xB700
    ctx->r11 = S32(0XB700 << 16);
    // 0x8007C008: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007C00C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8007C010: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8007C014: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8007C018: b           L_8007C038
    // 0x8007C01C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8007C038;
    // 0x8007C01C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8007C020:
    // 0x8007C020: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C024: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8007C028: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x8007C02C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8007C030: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007C034: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8007C038:
    // 0x8007C038: sh          $zero, 0x0($t0)
    MEM_H(0X0, ctx->r8) = 0;
    // 0x8007C03C: sw          $a1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r5;
    // 0x8007C040: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007C044: lw          $t9, -0x183C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X183C);
    // 0x8007C048: and         $t8, $a1, $at
    ctx->r24 = ctx->r5 & ctx->r1;
    // 0x8007C04C: bne         $t9, $zero, L_8007C0DC
    if (ctx->r25 != 0) {
        // 0x8007C050: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_8007C0DC;
    }
    // 0x8007C050: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8007C054: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8007C058: lui         $t3, 0x702
    ctx->r11 = S32(0X702 << 16);
    // 0x8007C05C: andi        $t2, $t1, 0x200
    ctx->r10 = ctx->r9 & 0X200;
    // 0x8007C060: beq         $t2, $zero, L_8007C0A8
    if (ctx->r10 == 0) {
        // 0x8007C064: ori         $t3, $t3, 0x10
        ctx->r11 = ctx->r11 | 0X10;
            goto L_8007C0A8;
    }
    // 0x8007C064: ori         $t3, $t3, 0x10
    ctx->r11 = ctx->r11 | 0X10;
    // 0x8007C068: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C06C: sra         $t5, $t8, 1
    ctx->r13 = S32(SIGNED(ctx->r24) >> 1);
    // 0x8007C070: andi        $t6, $t5, 0x1
    ctx->r14 = ctx->r13 & 0X1;
    // 0x8007C074: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x8007C078: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C07C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8007C080: addiu       $t9, $t9, -0x17B8
    ctx->r25 = ADD32(ctx->r25, -0X17B8);
    // 0x8007C084: addu        $t8, $t7, $at
    ctx->r24 = ADD32(ctx->r15, ctx->r1);
    // 0x8007C088: lui         $t4, 0x702
    ctx->r12 = S32(0X702 << 16);
    // 0x8007C08C: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x8007C090: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8007C094: ori         $t4, $t4, 0x10
    ctx->r12 = ctx->r12 | 0X10;
    // 0x8007C098: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x8007C09C: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x8007C0A0: b           L_8007C110
    // 0x8007C0A4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_8007C110;
    // 0x8007C0A4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8007C0A8:
    // 0x8007C0A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C0AC: addiu       $t4, $a1, -0x10
    ctx->r12 = ADD32(ctx->r5, -0X10);
    // 0x8007C0B0: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8007C0B4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C0B8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007C0BC: addiu       $t7, $t7, -0x1798
    ctx->r15 = ADD32(ctx->r15, -0X1798);
    // 0x8007C0C0: addu        $t6, $t5, $at
    ctx->r14 = ADD32(ctx->r13, ctx->r1);
    // 0x8007C0C4: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8007C0C8: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x8007C0CC: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8007C0D0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007C0D4: b           L_8007C110
    // 0x8007C0D8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
        goto L_8007C110;
    // 0x8007C0D8: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8007C0DC:
    // 0x8007C0DC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007C0E0: sll         $t2, $a1, 4
    ctx->r10 = S32(ctx->r5 << 4);
    // 0x8007C0E4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007C0E8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8007C0EC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007C0F0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007C0F4: addiu       $t4, $t4, -0x1718
    ctx->r12 = ADD32(ctx->r12, -0X1718);
    // 0x8007C0F8: addu        $t3, $t2, $at
    ctx->r11 = ADD32(ctx->r10, ctx->r1);
    // 0x8007C0FC: lui         $t1, 0x702
    ctx->r9 = S32(0X702 << 16);
    // 0x8007C100: ori         $t1, $t1, 0x10
    ctx->r9 = ctx->r9 | 0X10;
    // 0x8007C104: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x8007C108: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x8007C10C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_8007C110:
    // 0x8007C110: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C114: sw          $zero, 0x637C($at)
    MEM_W(0X637C, ctx->r1) = 0;
    // 0x8007C118: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007C11C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8007C120: sh          $t6, 0x6380($at)
    MEM_H(0X6380, ctx->r1) = ctx->r14;
L_8007C124:
    // 0x8007C124: jr          $ra
    // 0x8007C128: nop

    return;
    // 0x8007C128: nop

;}
RECOMP_FUNC void trackmenu_render_2D(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FA54: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8008FA58: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008FA5C: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x8008FA60: lw          $t6, 0x6478($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6478);
    // 0x8008FA64: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x8008FA68: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x8008FA6C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x8008FA70: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8008FA74: or          $s2, $a2, $zero
    ctx->r18 = ctx->r6 | 0;
    // 0x8008FA78: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008FA7C: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x8008FA80: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8008FA84: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8008FA88: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x8008FA8C: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x8008FA90: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x8008FA94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8008FA98: addiu       $s4, $a0, 0xA0
    ctx->r20 = ADD32(ctx->r4, 0XA0);
    // 0x8008FA9C: bne         $t8, $zero, L_8008FAA8
    if (ctx->r24 != 0) {
        // 0x8008FAA0: subu        $s5, $t6, $a1
        ctx->r21 = SUB32(ctx->r14, ctx->r5);
            goto L_8008FAA8;
    }
    // 0x8008FAA0: subu        $s5, $t6, $a1
    ctx->r21 = SUB32(ctx->r14, ctx->r5);
    // 0x8008FAA4: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_8008FAA8:
    // 0x8008FAA8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8008FAAC: jal         0x800C42EC
    // 0x8008FAB0: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x8008FAB0: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8008FAB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008FAB8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008FABC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008FAC0: jal         0x800C43CC
    // 0x8008FAC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x8008FAC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8008FAC8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008FACC: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8008FAD0: addiu       $s1, $zero, 0xFF
    ctx->r17 = ADD32(0, 0XFF);
    // 0x8008FAD4: blez        $v0, L_8008FAF8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008FAD8: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8008FAF8;
    }
    // 0x8008FAD8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008FADC: sll         $t9, $v0, 4
    ctx->r25 = S32(ctx->r2 << 4);
    // 0x8008FAE0: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8008FAE4: subu        $s1, $t0, $t9
    ctx->r17 = SUB32(ctx->r8, ctx->r25);
    // 0x8008FAE8: bgez        $s1, L_8008FAF8
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8008FAEC: nop
    
            goto L_8008FAF8;
    }
    // 0x8008FAEC: nop

    // 0x8008FAF0: b           L_8008FAF8
    // 0x8008FAF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_8008FAF8;
    // 0x8008FAF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8008FAF8:
    // 0x8008FAF8: lw          $t1, 0x69F0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X69F0);
    // 0x8008FAFC: nop

    // 0x8008FB00: beq         $s2, $t1, L_8008FBC0
    if (ctx->r18 == ctx->r9) {
        // 0x8008FB04: nop
    
            goto L_8008FBC0;
    }
    // 0x8008FB04: nop

    // 0x8008FB08: jal         0x8006B1D4
    // 0x8008FB0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_world_id(rdram, ctx);
        goto after_2;
    // 0x8008FB0C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_2:
    // 0x8008FB10: jal         0x8006BDDC
    // 0x8008FB14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    level_name(rdram, ctx);
        goto after_3;
    // 0x8008FB14: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x8008FB18: bne         $s2, $v0, L_8008FB2C
    if (ctx->r18 != ctx->r2) {
        // 0x8008FB1C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8008FB2C;
    }
    // 0x8008FB1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008FB20: jal         0x800C4164
    // 0x8008FB24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_kerning(rdram, ctx);
        goto after_4;
    // 0x8008FB24: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8008FB28: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8008FB2C:
    // 0x8008FB2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008FB30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008FB34: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8008FB38: bgez        $s1, L_8008FB48
    if (SIGNED(ctx->r17) >= 0) {
        // 0x8008FB3C: sra         $t2, $s1, 1
        ctx->r10 = S32(SIGNED(ctx->r17) >> 1);
            goto L_8008FB48;
    }
    // 0x8008FB3C: sra         $t2, $s1, 1
    ctx->r10 = S32(SIGNED(ctx->r17) >> 1);
    // 0x8008FB40: addiu       $at, $s1, 0x1
    ctx->r1 = ADD32(ctx->r17, 0X1);
    // 0x8008FB44: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_8008FB48:
    // 0x8008FB48: jal         0x800C4384
    // 0x8008FB4C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x8008FB4C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_5:
    // 0x8008FB50: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8008FB54: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8008FB58: addiu       $s3, $s3, 0x63A0
    ctx->r19 = ADD32(ctx->r19, 0X63A0);
    // 0x8008FB5C: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8008FB60: subu        $s0, $s5, $t3
    ctx->r16 = SUB32(ctx->r21, ctx->r11);
    // 0x8008FB64: addiu       $a2, $s0, -0x55
    ctx->r6 = ADD32(ctx->r16, -0X55);
    // 0x8008FB68: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008FB6C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008FB70: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8008FB74: jal         0x800C4440
    // 0x8008FB78: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_6;
    // 0x8008FB78: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_6:
    // 0x8008FB7C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008FB80: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008FB84: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008FB88: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008FB8C: jal         0x800C4384
    // 0x8008FB90: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x8008FB90: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_7:
    // 0x8008FB94: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x8008FB98: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8008FB9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008FBA0: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008FBA4: addiu       $a2, $s0, -0x58
    ctx->r6 = ADD32(ctx->r16, -0X58);
    // 0x8008FBA8: jal         0x800C4440
    // 0x8008FBAC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    draw_text(rdram, ctx);
        goto after_8;
    // 0x8008FBAC: or          $a3, $s2, $zero
    ctx->r7 = ctx->r18 | 0;
    after_8:
    // 0x8008FBB0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008FBB4: sw          $s2, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = ctx->r18;
    // 0x8008FBB8: jal         0x800C4164
    // 0x8008FBBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_kerning(rdram, ctx);
        goto after_9;
    // 0x8008FBBC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_9:
L_8008FBC0:
    // 0x8008FBC0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8008FBC4: addiu       $s3, $s3, 0x63A0
    ctx->r19 = ADD32(ctx->r19, 0X63A0);
    // 0x8008FBC8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008FBCC: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008FBD0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008FBD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8008FBD8: jal         0x800C4384
    // 0x8008FBDC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    set_text_colour(rdram, ctx);
        goto after_10;
    // 0x8008FBDC: sw          $s1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r17;
    after_10:
    // 0x8008FBE0: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8008FBE4: lw          $a3, 0x8C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X8C);
    // 0x8008FBE8: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x8008FBEC: addu        $a2, $t6, $s5
    ctx->r6 = ADD32(ctx->r14, ctx->r21);
    // 0x8008FBF0: addiu       $a2, $a2, 0x58
    ctx->r6 = ADD32(ctx->r6, 0X58);
    // 0x8008FBF4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8008FBF8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008FBFC: jal         0x800C4440
    // 0x8008FC00: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    draw_text(rdram, ctx);
        goto after_11;
    // 0x8008FC00: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_11:
    // 0x8008FC04: lw          $s0, 0x90($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X90);
    // 0x8008FC08: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008FC0C: blez        $s0, L_8008FDA4
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8008FC10: lw          $t5, 0x80($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X80);
            goto L_8008FDA4;
    }
    // 0x8008FC10: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
    // 0x8008FC14: lw          $v0, 0x6480($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6480);
    // 0x8008FC18: nop

    // 0x8008FC1C: sra         $v1, $v0, 2
    ctx->r3 = S32(SIGNED(ctx->r2) >> 2);
    // 0x8008FC20: subu        $t8, $s5, $v1
    ctx->r24 = SUB32(ctx->r21, ctx->r3);
    // 0x8008FC24: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8008FC28: beq         $at, $zero, L_8008FDA0
    if (ctx->r1 == 0) {
        // 0x8008FC2C: addu        $t0, $v1, $s5
        ctx->r8 = ADD32(ctx->r3, ctx->r21);
            goto L_8008FDA0;
    }
    // 0x8008FC2C: addu        $t0, $v1, $s5
    ctx->r8 = ADD32(ctx->r3, ctx->r21);
    // 0x8008FC30: blez        $t0, L_8008FDA0
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8008FC34: lui         $at, 0x3FA0
        ctx->r1 = S32(0X3FA0 << 16);
            goto L_8008FDA0;
    }
    // 0x8008FC34: lui         $at, 0x3FA0
    ctx->r1 = S32(0X3FA0 << 16);
    // 0x8008FC38: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008FC3C: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8008FC40: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x8008FC44: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x8008FC48: bne         $t9, $zero, L_8008FC68
    if (ctx->r25 != 0) {
        // 0x8008FC4C: mov.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
            goto L_8008FC68;
    }
    // 0x8008FC4C: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    // 0x8008FC50: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008FC54: lwc1        $f7, -0x7B30($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X7B30);
    // 0x8008FC58: lwc1        $f6, -0x7B2C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7B2C);
    // 0x8008FC5C: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x8008FC60: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8008FC64: cvt.s.d     $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f0.fl = CVT_S_D(ctx->f8.d);
L_8008FC68:
    // 0x8008FC68: lw          $t1, 0x98($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X98);
    // 0x8008FC6C: addiu       $v0, $s4, -0x50
    ctx->r2 = ADD32(ctx->r20, -0X50);
    // 0x8008FC70: beq         $t1, $zero, L_8008FCD8
    if (ctx->r9 == 0) {
        // 0x8008FC74: addiu       $t8, $s4, 0x50
        ctx->r24 = ADD32(ctx->r20, 0X50);
            goto L_8008FCD8;
    }
    // 0x8008FC74: addiu       $t8, $s4, 0x50
    ctx->r24 = ADD32(ctx->r20, 0X50);
    // 0x8008FC78: addiu       $t2, $sp, 0x5C
    ctx->r10 = ADD32(ctx->r29, 0X5C);
    // 0x8008FC7C: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8008FC80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008FC84: addiu       $a1, $sp, 0x68
    ctx->r5 = ADD32(ctx->r29, 0X68);
    // 0x8008FC88: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8008FC8C: jal         0x80066C2C
    // 0x8008FC90: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    copy_viewport_frame_size_to_coords(rdram, ctx);
        goto after_12;
    // 0x8008FC90: addiu       $a3, $sp, 0x60
    ctx->r7 = ADD32(ctx->r29, 0X60);
    after_12:
    // 0x8008FC94: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x8008FC98: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x8008FC9C: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x8008FCA0: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8008FCA4: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x8008FCA8: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x8008FCAC: lui         $at, 0x3C00
    ctx->r1 = S32(0X3C00 << 16);
    // 0x8008FCB0: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x8008FCB4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008FCB8: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8008FCBC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8008FCC0: lui         $at, 0x42C0
    ctx->r1 = S32(0X42C0 << 16);
    // 0x8008FCC4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008FCC8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8008FCCC: mul.s       $f2, $f16, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8008FCD0: b           L_8008FCDC
    // 0x8008FCD4: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
        goto L_8008FCDC;
    // 0x8008FCD4: div.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
L_8008FCD8:
    // 0x8008FCD8: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
L_8008FCDC:
    // 0x8008FCDC: slti        $at, $v0, 0x140
    ctx->r1 = SIGNED(ctx->r2) < 0X140 ? 1 : 0;
    // 0x8008FCE0: beq         $at, $zero, L_8008FD44
    if (ctx->r1 == 0) {
        // 0x8008FCE4: sw          $v0, 0x68($sp)
        MEM_W(0X68, ctx->r29) = ctx->r2;
            goto L_8008FD44;
    }
    // 0x8008FCE4: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8008FCE8: blez        $s4, L_8008FD44
    if (SIGNED(ctx->r20) <= 0) {
        // 0x8008FCEC: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8008FD44;
    }
    // 0x8008FCEC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008FCF0: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x8008FCF4: mtc1        $s5, $f16
    ctx->f16.u32l = ctx->r21;
    // 0x8008FCF8: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008FCFC: andi        $t0, $s0, 0xFF
    ctx->r8 = ctx->r16 & 0XFF;
    // 0x8008FD00: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8008FD04: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8008FD08: or          $t9, $t0, $at
    ctx->r25 = ctx->r8 | ctx->r1;
    // 0x8008FD0C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x8008FD10: mfc1        $a3, $f16
    ctx->r7 = (int32_t)ctx->f16.u32l;
    // 0x8008FD14: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8008FD18: addiu       $t1, $zero, 0x1000
    ctx->r9 = ADD32(0, 0X1000);
    // 0x8008FD1C: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8008FD20: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8008FD24: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8008FD28: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8008FD2C: swc1        $f0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f0.u32l;
    // 0x8008FD30: jal         0x80078D00
    // 0x8008FD34: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_13;
    // 0x8008FD34: swc1        $f2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x8008FD38: lwc1        $f0, 0x54($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8008FD3C: lwc1        $f2, 0x58($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X58);
    // 0x8008FD40: nop

L_8008FD44:
    // 0x8008FD44: slti        $at, $s4, 0x140
    ctx->r1 = SIGNED(ctx->r20) < 0X140 ? 1 : 0;
    // 0x8008FD48: beq         $at, $zero, L_8008FD98
    if (ctx->r1 == 0) {
        // 0x8008FD4C: nop
    
            goto L_8008FD98;
    }
    // 0x8008FD4C: nop

    // 0x8008FD50: lw          $t2, 0x60($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X60);
    // 0x8008FD54: lw          $a1, 0x9C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X9C);
    // 0x8008FD58: blez        $t2, L_8008FD98
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8008FD5C: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8008FD98;
    }
    // 0x8008FD5C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008FD60: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x8008FD64: mtc1        $s5, $f4
    ctx->f4.u32l = ctx->r21;
    // 0x8008FD68: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8008FD6C: andi        $t3, $s0, 0xFF
    ctx->r11 = ctx->r16 & 0XFF;
    // 0x8008FD70: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8008FD74: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8008FD78: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x8008FD7C: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8008FD80: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8008FD84: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8008FD88: swc1        $f2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f2.u32l;
    // 0x8008FD8C: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    // 0x8008FD90: jal         0x80078D00
    // 0x8008FD94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    texrect_draw_scaled(rdram, ctx);
        goto after_14;
    // 0x8008FD94: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    after_14:
L_8008FD98:
    // 0x8008FD98: jal         0x8007B3D0
    // 0x8008FD9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_15;
    // 0x8008FD9C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_15:
L_8008FDA0:
    // 0x8008FDA0: lw          $t5, 0x80($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X80);
L_8008FDA4:
    // 0x8008FDA4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008FDA8: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8008FDAC: lw          $a0, 0x94($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X94);
    // 0x8008FDB0: addiu       $v1, $v1, -0x8A4
    ctx->r3 = ADD32(ctx->r3, -0X8A4);
    // 0x8008FDB4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8008FDB8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8008FDBC: sll         $v0, $a0, 5
    ctx->r2 = S32(ctx->r4 << 5);
    // 0x8008FDC0: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x8008FDC4: swc1        $f8, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f8.u32l;
    // 0x8008FDC8: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8008FDCC: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8008FDD0: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x8008FDD4: addu        $t9, $t0, $v0
    ctx->r25 = ADD32(ctx->r8, ctx->r2);
    // 0x8008FDD8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8008FDDC: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x8008FDE0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x8008FDE4: swc1        $f16, 0x10($t9)
    MEM_W(0X10, ctx->r25) = ctx->f16.u32l;
    // 0x8008FDE8: lw          $t1, 0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X300);
    // 0x8008FDEC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008FDF0: bne         $t1, $zero, L_8008FE14
    if (ctx->r9 != 0) {
        // 0x8008FDF4: addiu       $t3, $t3, 0x6C4
        ctx->r11 = ADD32(ctx->r11, 0X6C4);
            goto L_8008FE14;
    }
    // 0x8008FDF4: addiu       $t3, $t3, 0x6C4
    ctx->r11 = ADD32(ctx->r11, 0X6C4);
    // 0x8008FDF8: lwc1        $f18, -0x7B28($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7B28);
    // 0x8008FDFC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008FE00: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008FE04: addiu       $t2, $t2, 0x6D4
    ctx->r10 = ADD32(ctx->r10, 0X6D4);
    // 0x8008FE08: sw          $t2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r10;
    // 0x8008FE0C: b           L_8008FE18
    // 0x8008FE10: swc1        $f18, -0xBAC($at)
    MEM_W(-0XBAC, ctx->r1) = ctx->f18.u32l;
        goto L_8008FE18;
    // 0x8008FE10: swc1        $f18, -0xBAC($at)
    MEM_W(-0XBAC, ctx->r1) = ctx->f18.u32l;
L_8008FE14:
    // 0x8008FE14: sw          $t3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r11;
L_8008FE18:
    // 0x8008FE18: jal         0x8009CA60
    // 0x8008FE1C: nop

    menu_element_render(rdram, ctx);
        goto after_16;
    // 0x8008FE1C: nop

    after_16:
    // 0x8008FE20: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8008FE24: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8008FE28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008FE2C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8008FE30: swc1        $f4, -0xBAC($at)
    MEM_W(-0XBAC, ctx->r1) = ctx->f4.u32l;
    // 0x8008FE34: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
L_8008FE38:
    // 0x8008FE38: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8008FE3C: sllv        $t5, $t4, $s1
    ctx->r13 = S32(ctx->r12 << (ctx->r17 & 31));
    // 0x8008FE40: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x8008FE44: beq         $t7, $zero, L_8008FEE0
    if (ctx->r15 == 0) {
        // 0x8008FE48: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_8008FEE0;
    }
    // 0x8008FE48: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008FE4C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8008FE50: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8008FE54: addu        $s0, $t9, $t2
    ctx->r16 = ADD32(ctx->r25, ctx->r10);
    // 0x8008FE58: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x8008FE5C: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x8008FE60: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008FE64: addiu       $t0, $t0, 0x678
    ctx->r8 = ADD32(ctx->r8, 0X678);
    // 0x8008FE68: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8008FE6C: addu        $s2, $t8, $t0
    ctx->r18 = ADD32(ctx->r24, ctx->r8);
    // 0x8008FE70: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8008FE74: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8008FE78: addu        $a2, $t3, $s4
    ctx->r6 = ADD32(ctx->r11, ctx->r20);
    // 0x8008FE7C: addu        $a3, $t4, $s5
    ctx->r7 = ADD32(ctx->r12, ctx->r21);
    // 0x8008FE80: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8008FE84: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8008FE88: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8008FE8C: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8008FE90: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8008FE94: jal         0x80078AB8
    // 0x8008FE98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    texrect_draw(rdram, ctx);
        goto after_17;
    // 0x8008FE98: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_17:
    // 0x8008FE9C: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8008FEA0: lh          $t7, 0x2($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X2);
    // 0x8008FEA4: lw          $a1, 0x0($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X0);
    // 0x8008FEA8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8008FEAC: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x8008FEB0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8008FEB4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008FEB8: addu        $a2, $t6, $s4
    ctx->r6 = ADD32(ctx->r14, ctx->r20);
    // 0x8008FEBC: addu        $a3, $t7, $s5
    ctx->r7 = ADD32(ctx->r15, ctx->r21);
    // 0x8008FEC0: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    // 0x8008FEC4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8008FEC8: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8008FECC: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8008FED0: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8008FED4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008FED8: jal         0x80078AB8
    // 0x8008FEDC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    texrect_draw(rdram, ctx);
        goto after_18;
    // 0x8008FEDC: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_18:
L_8008FEE0:
    // 0x8008FEE0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8008FEE4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8008FEE8: bne         $s1, $at, L_8008FE38
    if (ctx->r17 != ctx->r1) {
        // 0x8008FEEC: lw          $t6, 0xA0($sp)
        ctx->r14 = MEM_W(ctx->r29, 0XA0);
            goto L_8008FE38;
    }
    // 0x8008FEEC: lw          $t6, 0xA0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XA0);
    // 0x8008FEF0: jal         0x8007B3D0
    // 0x8008FEF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_19;
    // 0x8008FEF4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_19:
    // 0x8008FEF8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008FEFC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8008FF00: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8008FF04: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x8008FF08: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x8008FF0C: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x8008FF10: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x8008FF14: jr          $ra
    // 0x8008FF18: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x8008FF18: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void alResampleParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC090: addiu       $t6, $a1, -0x1
    ctx->r14 = ADD32(ctx->r5, -0X1);
    // 0x800CC094: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800CC098: sltiu       $at, $t6, 0x9
    ctx->r1 = ctx->r14 < 0X9 ? 1 : 0;
    // 0x800CC09C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800CC0A0: beq         $at, $zero, L_800CC150
    if (ctx->r1 == 0) {
        // 0x800CC0A4: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800CC150;
    }
    // 0x800CC0A4: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800CC0A8: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800CC0AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CC0B0: addu        $at, $at, $t6
    gpr jr_addend_800CC0B8 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800CC0B4: lw          $t6, -0x6A00($at)
    ctx->r14 = ADD32(ctx->r1, -0X6A00);
    // 0x800CC0B8: jr          $t6
    // 0x800CC0BC: nop

    switch (jr_addend_800CC0B8 >> 2) {
        case 0: goto L_800CC0C0; break;
        case 1: goto L_800CC150; break;
        case 2: goto L_800CC150; break;
        case 3: goto L_800CC0C8; break;
        case 4: goto L_800CC150; break;
        case 5: goto L_800CC150; break;
        case 6: goto L_800CC134; break;
        case 7: goto L_800CC144; break;
        case 8: goto L_800CC104; break;
        default: switch_error(__func__, 0x800CC0B8, 0x800E9600);
    }
    // 0x800CC0BC: nop

L_800CC0C0:
    // 0x800CC0C0: b           L_800CC168
    // 0x800CC0C4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
        goto L_800CC168;
    // 0x800CC0C4: sw          $a2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r6;
L_800CC0C8:
    // 0x800CC0C8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800CC0CC: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800CC0D0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800CC0D4: sw          $t7, 0x24($a3)
    MEM_W(0X24, ctx->r7) = ctx->r15;
    // 0x800CC0D8: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x800CC0DC: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x800CC0E0: beq         $a0, $zero, L_800CC168
    if (ctx->r4 == 0) {
        // 0x800CC0E4: swc1        $f4, 0x20($a3)
        MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
            goto L_800CC168;
    }
    // 0x800CC0E4: swc1        $f4, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f4.u32l;
    // 0x800CC0E8: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800CC0EC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800CC0F0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CC0F4: jalr        $t9
    // 0x800CC0F8: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC0F8: nop

    after_0:
    // 0x800CC0FC: b           L_800CC16C
    // 0x800CC100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CC16C;
    // 0x800CC100: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CC104:
    // 0x800CC104: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800CC108: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800CC10C: sw          $t8, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r24;
    // 0x800CC110: beql        $a0, $zero, L_800CC16C
    if (ctx->r4 == 0) {
        // 0x800CC114: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CC16C;
    }
    goto skip_0;
    // 0x800CC114: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800CC118: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800CC11C: addiu       $a1, $zero, 0x9
    ctx->r5 = ADD32(0, 0X9);
    // 0x800CC120: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800CC124: jalr        $t9
    // 0x800CC128: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CC128: nop

    after_1:
    // 0x800CC12C: b           L_800CC16C
    // 0x800CC130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800CC16C;
    // 0x800CC130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CC134:
    // 0x800CC134: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800CC138: lwc1        $f6, 0x1C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800CC13C: b           L_800CC168
    // 0x800CC140: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
        goto L_800CC168;
    // 0x800CC140: swc1        $f6, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->f6.u32l;
L_800CC144:
    // 0x800CC144: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800CC148: b           L_800CC168
    // 0x800CC14C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
        goto L_800CC168;
    // 0x800CC14C: sw          $t0, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r8;
L_800CC150:
    // 0x800CC150: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x800CC154: beql        $a0, $zero, L_800CC16C
    if (ctx->r4 == 0) {
        // 0x800CC158: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800CC16C;
    }
    goto skip_1;
    // 0x800CC158: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_1:
    // 0x800CC15C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800CC160: jalr        $t9
    // 0x800CC164: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_2;
    // 0x800CC164: nop

    after_2:
L_800CC168:
    // 0x800CC168: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800CC16C:
    // 0x800CC16C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800CC170: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800CC174: jr          $ra
    // 0x800CC178: nop

    return;
    // 0x800CC178: nop

;}
RECOMP_FUNC void obj_init_worldkey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003DE74: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003DE78: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003DE7C: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DE80: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003DE84: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003DE88: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DE8C: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x8003DE90: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003DE94: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003DE98: nop

    // 0x8003DE9C: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003DEA0: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003DEA4: nop

    // 0x8003DEA8: andi        $t2, $t1, 0xF
    ctx->r10 = ctx->r9 & 0XF;
    // 0x8003DEAC: sb          $t2, 0x8($a1)
    MEM_B(0X8, ctx->r5) = ctx->r10;
    // 0x8003DEB0: andi        $t3, $t2, 0xFF
    ctx->r11 = ctx->r10 & 0XFF;
    // 0x8003DEB4: sw          $t3, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r11;
    // 0x8003DEB8: jal         0x8006EA90
    // 0x8003DEBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003DEBC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x8003DEC0: jal         0x8009C2D0
    // 0x8003DEC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    is_in_tracks_mode(rdram, ctx);
        goto after_1;
    // 0x8003DEC4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8003DEC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8003DECC: bne         $v0, $zero, L_8003DEF0
    if (ctx->r2 != 0) {
        // 0x8003DED0: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003DEF0;
    }
    // 0x8003DED0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8003DED4: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x8003DED8: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x8003DEDC: lhu         $t5, 0x8($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X8);
    // 0x8003DEE0: sllv        $t8, $t7, $t6
    ctx->r24 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8003DEE4: and         $t9, $t5, $t8
    ctx->r25 = ctx->r13 & ctx->r24;
    // 0x8003DEE8: beq         $t9, $zero, L_8003DEFC
    if (ctx->r25 == 0) {
        // 0x8003DEEC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003DEFC;
    }
    // 0x8003DEEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DEF0:
    // 0x8003DEF0: jal         0x8000FFB8
    // 0x8003DEF4: nop

    free_object(rdram, ctx);
        goto after_2;
    // 0x8003DEF4: nop

    after_2:
    // 0x8003DEF8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003DEFC:
    // 0x8003DEFC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003DF00: jr          $ra
    // 0x8003DF04: nop

    return;
    // 0x8003DF04: nop

;}
RECOMP_FUNC void rain_fog(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD40C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AD410: lw          $t6, 0x2C5C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2C5C);
    // 0x800AD414: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800AD418: beq         $t6, $zero, L_800AD49C
    if (ctx->r14 == 0) {
        // 0x800AD41C: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800AD49C;
    }
    // 0x800AD41C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800AD420: jal         0x80066210
    // 0x800AD424: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x800AD424: nop

    after_0:
    // 0x800AD428: bne         $v0, $zero, L_800AD49C
    if (ctx->r2 != 0) {
        // 0x800AD42C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800AD49C;
    }
    // 0x800AD42C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AD430: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800AD434: lw          $v0, 0x2C60($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2C60);
    // 0x800AD438: addiu       $t2, $zero, 0xF
    ctx->r10 = ADD32(0, 0XF);
    // 0x800AD43C: negu        $at, $v0
    ctx->r1 = SUB32(0, ctx->r2);
    // 0x800AD440: sll         $v1, $at, 2
    ctx->r3 = S32(ctx->r1 << 2);
    // 0x800AD444: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x800AD448: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800AD44C: sll         $t0, $at, 2
    ctx->r8 = S32(ctx->r1 << 2);
    // 0x800AD450: subu        $v1, $v1, $at
    ctx->r3 = SUB32(ctx->r3, ctx->r1);
    // 0x800AD454: addu        $t0, $t0, $at
    ctx->r8 = ADD32(ctx->r8, ctx->r1);
    // 0x800AD458: sll         $v1, $v1, 1
    ctx->r3 = S32(ctx->r3 << 1);
    // 0x800AD45C: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800AD460: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x800AD464: sra         $t8, $t0, 16
    ctx->r24 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800AD468: addiu       $v1, $t7, 0x3FA
    ctx->r3 = ADD32(ctx->r15, 0X3FA);
    // 0x800AD46C: addiu       $t0, $t8, 0x3FF
    ctx->r8 = ADD32(ctx->r24, 0X3FF);
    // 0x800AD470: sll         $a2, $t0, 16
    ctx->r6 = S32(ctx->r8 << 16);
    // 0x800AD474: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x800AD478: sra         $t9, $a1, 16
    ctx->r25 = S32(SIGNED(ctx->r5) >> 16);
    // 0x800AD47C: sra         $t1, $a2, 16
    ctx->r9 = S32(SIGNED(ctx->r6) >> 16);
    // 0x800AD480: addiu       $t3, $zero, 0x24
    ctx->r11 = ADD32(0, 0X24);
    // 0x800AD484: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x800AD488: or          $a2, $t1, $zero
    ctx->r6 = ctx->r9 | 0;
    // 0x800AD48C: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800AD490: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800AD494: jal         0x80030664
    // 0x800AD498: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    set_fog(rdram, ctx);
        goto after_1;
    // 0x800AD498: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    after_1:
L_800AD49C:
    // 0x800AD49C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800AD4A0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800AD4A4: jr          $ra
    // 0x800AD4A8: nop

    return;
    // 0x800AD4A8: nop

;}
RECOMP_FUNC void menu_title_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C49C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C4A0: jr          $ra
    // 0x8009C4A4: sw          $zero, -0xB78($at)
    MEM_W(-0XB78, ctx->r1) = 0;
    return;
    // 0x8009C4A4: sw          $zero, -0xB78($at)
    MEM_W(-0XB78, ctx->r1) = 0;
;}
RECOMP_FUNC void alCSPSetChlVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7940: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7944: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x800C7948: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C794C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C7950: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800C7954: or          $t0, $a2, $zero
    ctx->r8 = ctx->r6 | 0;
    // 0x800C7958: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800C795C: ori         $t7, $a3, 0xB0
    ctx->r15 = ctx->r7 | 0XB0;
    // 0x800C7960: addiu       $t8, $zero, 0x7
    ctx->r24 = ADD32(0, 0X7);
    // 0x800C7964: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7968: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x800C796C: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x800C7970: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x800C7974: sb          $t0, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r8;
    // 0x800C7978: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C797C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7980: jal         0x800C91AC
    // 0x800C7984: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7984: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    after_0:
    // 0x800C7988: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C798C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7990: jr          $ra
    // 0x800C7994: nop

    return;
    // 0x800C7994: nop

;}
RECOMP_FUNC void trackmenu_staff_beaten(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80092BE0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80092BE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80092BE8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80092BEC: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80092BF0: jal         0x8001E29C
    // 0x80092BF4: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80092BF4: addiu       $a0, $zero, 0x1C
    ctx->r4 = ADD32(0, 0X1C);
    after_0:
    // 0x80092BF8: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80092BFC: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80092C00: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80092C04: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80092C08: beq         $t0, $t6, L_80092C3C
    if (ctx->r8 == ctx->r14) {
        // 0x80092C0C: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_80092C3C;
    }
    // 0x80092C0C: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x80092C10: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x80092C14: addu        $v1, $v0, $zero
    ctx->r3 = ADD32(ctx->r2, 0);
L_80092C18:
    // 0x80092C18: bne         $a3, $a0, L_80092C24
    if (ctx->r7 != ctx->r4) {
        // 0x80092C1C: nop
    
            goto L_80092C24;
    }
    // 0x80092C1C: nop

    // 0x80092C20: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_80092C24:
    // 0x80092C24: lb          $a0, 0x1($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X1);
    // 0x80092C28: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80092C2C: beq         $t0, $a0, L_80092C3C
    if (ctx->r8 == ctx->r4) {
        // 0x80092C30: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80092C3C;
    }
    // 0x80092C30: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80092C34: bltz        $a2, L_80092C18
    if (SIGNED(ctx->r6) < 0) {
        // 0x80092C38: nop
    
            goto L_80092C18;
    }
    // 0x80092C38: nop

L_80092C3C:
    // 0x80092C3C: bltz        $a2, L_80092C74
    if (SIGNED(ctx->r6) < 0) {
        // 0x80092C40: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_80092C74;
    }
    // 0x80092C40: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80092C44: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80092C48: lw          $t4, 0x6448($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6448);
    // 0x80092C4C: sllv        $t8, $t7, $a2
    ctx->r24 = S32(ctx->r15 << (ctx->r6 & 31));
    // 0x80092C50: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80092C54: lw          $t5, 0x644C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X644C);
    // 0x80092C58: sra         $t2, $t8, 31
    ctx->r10 = S32(SIGNED(ctx->r24) >> 31);
    // 0x80092C5C: and         $t6, $t2, $t4
    ctx->r14 = ctx->r10 & ctx->r12;
    // 0x80092C60: bne         $t6, $zero, L_80092C74
    if (ctx->r14 != 0) {
        // 0x80092C64: and         $t7, $t8, $t5
        ctx->r15 = ctx->r24 & ctx->r13;
            goto L_80092C74;
    }
    // 0x80092C64: and         $t7, $t8, $t5
    ctx->r15 = ctx->r24 & ctx->r13;
    // 0x80092C68: bne         $t7, $zero, L_80092C78
    if (ctx->r15 != 0) {
        // 0x80092C6C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80092C78;
    }
    // 0x80092C6C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80092C70: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_80092C74:
    // 0x80092C74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80092C78:
    // 0x80092C78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80092C7C: jr          $ra
    // 0x80092C80: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    return;
    // 0x80092C80: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
;}
RECOMP_FUNC void racer_spinout_car(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052B64: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80052B68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80052B6C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80052B70: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80052B74: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80052B78: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80052B7C: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80052B80: lwc1        $f9, 0x66F0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X66F0);
    // 0x80052B84: lwc1        $f8, 0x66F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X66F4);
    // 0x80052B88: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80052B8C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80052B90: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80052B94: lb          $t6, 0x1D8($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X1D8);
    // 0x80052B98: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80052B9C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80052BA0: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80052BA4: swc1        $f18, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f18.u32l;
    // 0x80052BA8: bne         $t6, $zero, L_80052BD0
    if (ctx->r14 != 0) {
        // 0x80052BAC: swc1        $f16, 0x2C($a1)
        MEM_W(0X2C, ctx->r5) = ctx->f16.u32l;
            goto L_80052BD0;
    }
    // 0x80052BAC: swc1        $f16, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f16.u32l;
    // 0x80052BB0: lh          $a0, 0x0($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X0);
    // 0x80052BB4: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    // 0x80052BB8: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80052BBC: jal         0x80072348
    // 0x80052BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    rumble_set(rdram, ctx);
        goto after_0;
    // 0x80052BC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80052BC4: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x80052BC8: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x80052BCC: nop

L_80052BD0:
    // 0x80052BD0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80052BD4: lw          $t7, -0x2AA4($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2AA4);
    // 0x80052BD8: lh          $v1, 0x1A2($a3)
    ctx->r3 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052BDC: bltz        $t7, L_80052C58
    if (SIGNED(ctx->r15) < 0) {
        // 0x80052BE0: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_80052C58;
    }
    // 0x80052BE0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80052BE4: lw          $t8, -0x3468($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3468);
    // 0x80052BE8: nop

    // 0x80052BEC: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x80052BF0: beq         $at, $zero, L_80052C10
    if (ctx->r1 == 0) {
        // 0x80052BF4: nop
    
            goto L_80052C10;
    }
    // 0x80052BF4: nop

    // 0x80052BF8: lw          $t9, 0x74($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X74);
    // 0x80052BFC: lui         $at, 0x4
    ctx->r1 = S32(0X4 << 16);
    // 0x80052C00: ori         $at, $at, 0xFC00
    ctx->r1 = ctx->r1 | 0XFC00;
    // 0x80052C04: or          $t0, $t9, $at
    ctx->r8 = ctx->r25 | ctx->r1;
    // 0x80052C08: b           L_80052C58
    // 0x80052C0C: sw          $t0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r8;
        goto L_80052C58;
    // 0x80052C0C: sw          $t0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r8;
L_80052C10:
    // 0x80052C10: lbu         $v0, 0x1DE($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1DE);
    // 0x80052C14: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80052C18: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80052C1C: beq         $at, $zero, L_80052C34
    if (ctx->r1 == 0) {
        // 0x80052C20: sll         $t2, $v0, 1
        ctx->r10 = S32(ctx->r2 << 1);
            goto L_80052C34;
    }
    // 0x80052C20: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x80052C24: lw          $t1, 0x74($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X74);
    // 0x80052C28: sllv        $t4, $t3, $t2
    ctx->r12 = S32(ctx->r11 << (ctx->r10 & 31));
    // 0x80052C2C: or          $t5, $t1, $t4
    ctx->r13 = ctx->r9 | ctx->r12;
    // 0x80052C30: sw          $t5, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r13;
L_80052C34:
    // 0x80052C34: lbu         $v0, 0x1DF($a3)
    ctx->r2 = MEM_BU(ctx->r7, 0X1DF);
    // 0x80052C38: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80052C3C: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80052C40: beq         $at, $zero, L_80052C58
    if (ctx->r1 == 0) {
        // 0x80052C44: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_80052C58;
    }
    // 0x80052C44: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x80052C48: lw          $t6, 0x74($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X74);
    // 0x80052C4C: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x80052C50: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x80052C54: sw          $t0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r8;
L_80052C58:
    // 0x80052C58: lb          $v0, 0x1DB($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X1DB);
    // 0x80052C5C: sll         $t2, $a2, 2
    ctx->r10 = S32(ctx->r6 << 2);
    // 0x80052C60: blez        $v0, L_80052CCC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80052C64: addu        $t2, $t2, $a2
        ctx->r10 = ADD32(ctx->r10, ctx->r6);
            goto L_80052CCC;
    }
    // 0x80052C64: addu        $t2, $t2, $a2
    ctx->r10 = ADD32(ctx->r10, ctx->r6);
    // 0x80052C68: lh          $t3, 0x1A2($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052C6C: sll         $t2, $t2, 8
    ctx->r10 = S32(ctx->r10 << 8);
    // 0x80052C70: addu        $t1, $t3, $t2
    ctx->r9 = ADD32(ctx->r11, ctx->r10);
    // 0x80052C74: sh          $t1, 0x1A2($a3)
    MEM_H(0X1A2, ctx->r7) = ctx->r9;
    // 0x80052C78: lh          $t4, 0x1A2($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052C7C: nop

    // 0x80052C80: blez        $t4, L_80052D38
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80052C84: nop
    
            goto L_80052D38;
    }
    // 0x80052C84: nop

    // 0x80052C88: bgez        $v1, L_80052D38
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80052C8C: nop
    
            goto L_80052D38;
    }
    // 0x80052C8C: nop

    // 0x80052C90: lb          $t5, 0x1DB($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X1DB);
    // 0x80052C94: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80052C98: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x80052C9C: sb          $t8, 0x1DB($a3)
    MEM_B(0X1DB, ctx->r7) = ctx->r24;
    // 0x80052CA0: lw          $t7, -0x2ACC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2ACC);
    // 0x80052CA4: nop

    // 0x80052CA8: slti        $at, $t7, 0x33
    ctx->r1 = SIGNED(ctx->r15) < 0X33 ? 1 : 0;
    // 0x80052CAC: bne         $at, $zero, L_80052D38
    if (ctx->r1 != 0) {
        // 0x80052CB0: nop
    
            goto L_80052D38;
    }
    // 0x80052CB0: nop

    // 0x80052CB4: lb          $t6, 0x1DB($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1DB);
    // 0x80052CB8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80052CBC: bne         $t6, $at, L_80052D38
    if (ctx->r14 != ctx->r1) {
        // 0x80052CC0: nop
    
            goto L_80052D38;
    }
    // 0x80052CC0: nop

    // 0x80052CC4: b           L_80052D38
    // 0x80052CC8: sb          $zero, 0x1DB($a3)
    MEM_B(0X1DB, ctx->r7) = 0;
        goto L_80052D38;
    // 0x80052CC8: sb          $zero, 0x1DB($a3)
    MEM_B(0X1DB, ctx->r7) = 0;
L_80052CCC:
    // 0x80052CCC: bgez        $v0, L_80052D38
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80052CD0: sll         $t0, $a2, 2
        ctx->r8 = S32(ctx->r6 << 2);
            goto L_80052D38;
    }
    // 0x80052CD0: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x80052CD4: lh          $t9, 0x1A2($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052CD8: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x80052CDC: sll         $t0, $t0, 8
    ctx->r8 = S32(ctx->r8 << 8);
    // 0x80052CE0: subu        $t3, $t9, $t0
    ctx->r11 = SUB32(ctx->r25, ctx->r8);
    // 0x80052CE4: sh          $t3, 0x1A2($a3)
    MEM_H(0X1A2, ctx->r7) = ctx->r11;
    // 0x80052CE8: lh          $t2, 0x1A2($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052CEC: nop

    // 0x80052CF0: bgez        $t2, L_80052D38
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80052CF4: nop
    
            goto L_80052D38;
    }
    // 0x80052CF4: nop

    // 0x80052CF8: blez        $v1, L_80052D38
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80052CFC: nop
    
            goto L_80052D38;
    }
    // 0x80052CFC: nop

    // 0x80052D00: lb          $t1, 0x1DB($a3)
    ctx->r9 = MEM_B(ctx->r7, 0X1DB);
    // 0x80052D04: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80052D08: addiu       $t4, $t1, 0x1
    ctx->r12 = ADD32(ctx->r9, 0X1);
    // 0x80052D0C: sb          $t4, 0x1DB($a3)
    MEM_B(0X1DB, ctx->r7) = ctx->r12;
    // 0x80052D10: lw          $t5, -0x2ACC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2ACC);
    // 0x80052D14: nop

    // 0x80052D18: slti        $at, $t5, -0x32
    ctx->r1 = SIGNED(ctx->r13) < -0X32 ? 1 : 0;
    // 0x80052D1C: beq         $at, $zero, L_80052D38
    if (ctx->r1 == 0) {
        // 0x80052D20: nop
    
            goto L_80052D38;
    }
    // 0x80052D20: nop

    // 0x80052D24: lb          $t8, 0x1DB($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X1DB);
    // 0x80052D28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80052D2C: bne         $t8, $at, L_80052D38
    if (ctx->r24 != ctx->r1) {
        // 0x80052D30: nop
    
            goto L_80052D38;
    }
    // 0x80052D30: nop

    // 0x80052D34: sb          $zero, 0x1DB($a3)
    MEM_B(0X1DB, ctx->r7) = 0;
L_80052D38:
    // 0x80052D38: lh          $t7, 0x1A2($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X1A2);
    // 0x80052D3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052D40: sw          $t7, -0x2AAC($at)
    MEM_W(-0X2AAC, ctx->r1) = ctx->r15;
    // 0x80052D44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052D48: lwc1        $f4, -0x2A94($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x80052D4C: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80052D50: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80052D54: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80052D58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80052D5C: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80052D60: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x80052D64: sw          $zero, -0x2ACC($at)
    MEM_W(-0X2ACC, ctx->r1) = 0;
    // 0x80052D68: sb          $zero, 0x1E1($a3)
    MEM_B(0X1E1, ctx->r7) = 0;
    // 0x80052D6C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80052D70: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80052D74: jr          $ra
    // 0x80052D78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80052D78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void read_eeprom_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800745D0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800745D4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800745D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800745DC: andi        $s0, $a1, 0xFF
    ctx->r16 = ctx->r5 & 0XFF;
    // 0x800745E0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800745E4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800745E8: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800745EC: jal         0x8006A100
    // 0x800745F0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x800745F0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x800745F4: jal         0x800CE210
    // 0x800745F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x800745F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x800745FC: bne         $v0, $zero, L_8007460C
    if (ctx->r2 != 0) {
        // 0x80074600: addiu       $a0, $zero, 0x200
        ctx->r4 = ADD32(0, 0X200);
            goto L_8007460C;
    }
    // 0x80074600: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x80074604: b           L_800746D8
    // 0x80074608: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800746D8;
    // 0x80074608: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007460C:
    // 0x8007460C: jal         0x80070C9C
    // 0x80074610: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80074610: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x80074614: andi        $t7, $s0, 0x1
    ctx->r15 = ctx->r16 & 0X1;
    // 0x80074618: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8007461C: beq         $t7, $zero, L_80074670
    if (ctx->r15 == 0) {
        // 0x80074620: sw          $s0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r16;
            goto L_80074670;
    }
    // 0x80074620: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80074624: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x80074628: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007462C:
    // 0x8007462C: jal         0x8006A100
    // 0x80074630: nop

    si_mesg(rdram, ctx);
        goto after_3;
    // 0x80074630: nop

    after_3:
    // 0x80074634: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x80074638: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x8007463C: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x80074640: addu        $a2, $t9, $s2
    ctx->r6 = ADD32(ctx->r25, ctx->r18);
    // 0x80074644: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80074648: jal         0x800CE280
    // 0x8007464C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromRead_recomp(rdram, ctx);
        goto after_4;
    // 0x8007464C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80074650: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074654: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80074658: bne         $at, $zero, L_8007462C
    if (ctx->r1 != 0) {
        // 0x8007465C: nop
    
            goto L_8007462C;
    }
    // 0x8007465C: nop

    // 0x80074660: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x80074664: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80074668: jal         0x80073588
    // 0x8007466C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    func_80073588(rdram, ctx);
        goto after_5;
    // 0x8007466C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
L_80074670:
    // 0x80074670: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80074674: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    // 0x80074678: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x8007467C: beq         $t1, $zero, L_800746CC
    if (ctx->r9 == 0) {
        // 0x80074680: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800746CC;
    }
    // 0x80074680: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074684:
    // 0x80074684: jal         0x8006A100
    // 0x80074688: nop

    si_mesg(rdram, ctx);
        goto after_6;
    // 0x80074688: nop

    after_6:
    // 0x8007468C: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x80074690: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x80074694: addu        $a2, $s2, $t3
    ctx->r6 = ADD32(ctx->r18, ctx->r11);
    // 0x80074698: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x8007469C: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800746A0: addiu       $a2, $a2, 0xC0
    ctx->r6 = ADD32(ctx->r6, 0XC0);
    // 0x800746A4: jal         0x800CE280
    // 0x800746A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromRead_recomp(rdram, ctx);
        goto after_7;
    // 0x800746A8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_7:
    // 0x800746AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800746B0: slt         $at, $s0, $s1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x800746B4: bne         $at, $zero, L_80074684
    if (ctx->r1 != 0) {
        // 0x800746B8: nop
    
            goto L_80074684;
    }
    // 0x800746B8: nop

    // 0x800746BC: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800746C0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x800746C4: jal         0x80073588
    // 0x800746C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    func_80073588(rdram, ctx);
        goto after_8;
    // 0x800746C8: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_8:
L_800746CC:
    // 0x800746CC: jal         0x80071140
    // 0x800746D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_9;
    // 0x800746D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x800746D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800746D8:
    // 0x800746D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800746DC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800746E0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800746E4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800746E8: jr          $ra
    // 0x800746EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800746EC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void func_800304C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800304C8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800304CC: lw          $a2, -0x2F3C($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2F3C);
    // 0x800304D0: lwc1        $f14, 0x0($a0)
    ctx->f14.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800304D4: lwc1        $f16, 0x18($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X18);
    // 0x800304D8: lwc1        $f18, 0x8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X8);
    // 0x800304DC: lwc1        $f0, 0xC($a2)
    ctx->f0.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800304E0: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800304E4: sub.s       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800304E8: lwc1        $f2, 0x14($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800304EC: sub.s       $f6, $f0, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x800304F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800304F4: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800304F8: swc1        $f4, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->f4.u32l;
    // 0x800304FC: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x80030500: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80030504: sub.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80030508: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8003050C: sub.s       $f8, $f6, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f14.fl;
    // 0x80030510: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80030514: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80030518: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003051C: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80030520: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80030524: nop

    // 0x80030528: bc1f        L_80030534
    if (!c1cs) {
        // 0x8003052C: nop
    
            goto L_80030534;
    }
    // 0x8003052C: nop

    // 0x80030530: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80030534:
    // 0x80030534: lwc1        $f8, 0x28($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X28);
    // 0x80030538: lwc1        $f6, 0xC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XC);
    // 0x8003053C: swc1        $f8, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->f8.u32l;
    // 0x80030540: lwc1        $f10, 0x20($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X20);
    // 0x80030544: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x80030548: swc1        $f10, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->f10.u32l;
    // 0x8003054C: sub.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x80030550: sub.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80030554: mul.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80030558: lwc1        $f4, 0x4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4);
    // 0x8003055C: nop

    // 0x80030560: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80030564: sub.s       $f4, $f2, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f16.fl;
    // 0x80030568: mul.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8003056C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80030570: lwc1        $f10, 0x4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4);
    // 0x80030574: sub.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x80030578: lwc1        $f6, 0x8($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X8);
    // 0x8003057C: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x80030580: nop

    // 0x80030584: bc1f        L_80030590
    if (!c1cs) {
        // 0x80030588: nop
    
            goto L_80030590;
    }
    // 0x80030588: nop

    // 0x8003058C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80030590:
    // 0x80030590: bne         $v0, $v1, L_8003065C
    if (ctx->r2 != ctx->r3) {
        // 0x80030594: nop
    
            goto L_8003065C;
    }
    // 0x80030594: nop

    // 0x80030598: sub.s       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x8003059C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800305A0: sub.s       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800305A4: mul.s       $f8, $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x800305A8: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800305AC: sub.s       $f6, $f14, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x800305B0: mul.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800305B4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800305B8: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800305BC: c.le.s      $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f4.fl <= ctx->f12.fl;
    // 0x800305C0: nop

    // 0x800305C4: bc1f        L_800305D0
    if (!c1cs) {
        // 0x800305C8: nop
    
            goto L_800305D0;
    }
    // 0x800305C8: nop

    // 0x800305CC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_800305D0:
    // 0x800305D0: bne         $v1, $a1, L_8003065C
    if (ctx->r3 != ctx->r5) {
        // 0x800305D4: nop
    
            goto L_8003065C;
    }
    // 0x800305D4: nop

    // 0x800305D8: lw          $v0, -0x2F44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2F44);
    // 0x800305DC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800305E0: lwc1        $f6, 0x0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800305E4: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800305E8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800305EC: addiu       $v1, $v1, -0x2F30
    ctx->r3 = ADD32(ctx->r3, -0X2F30);
    // 0x800305F0: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800305F4: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800305F8: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800305FC: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80030600: add.s       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x80030604: lwc1        $f6, 0x4($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80030608: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x8003060C: nop

    // 0x80030610: div.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80030614: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80030618: nop

    // 0x8003061C: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80030620: c.lt.s      $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f8.fl < ctx->f12.fl;
    // 0x80030624: nop

    // 0x80030628: bc1f        L_8003065C
    if (!c1cs) {
        // 0x8003062C: nop
    
            goto L_8003065C;
    }
    // 0x8003062C: nop

    // 0x80030630: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80030634: nop

    // 0x80030638: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003063C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80030640: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80030644: nop

    // 0x80030648: cvt.w.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    ctx->f4.u32l = CVT_W_S(ctx->f12.fl);
    // 0x8003064C: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80030650: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80030654: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x80030658: nop

L_8003065C:
    // 0x8003065C: jr          $ra
    // 0x80030660: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80030660: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_init_goldenballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B368: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003B36C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003B370: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003B374: lb          $a3, 0x8($a1)
    ctx->r7 = MEM_B(ctx->r5, 0X8);
    // 0x8003B378: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B37C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B380: bne         $a3, $at, L_8003B39C
    if (ctx->r7 != ctx->r1) {
        // 0x8003B384: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8003B39C;
    }
    // 0x8003B384: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003B388: jal         0x8000CC20
    // 0x8003B38C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    func_8000CC20(rdram, ctx);
        goto after_0;
    // 0x8003B38C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003B390: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B394: b           L_8003B3B4
    // 0x8003B398: sb          $v0, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r2;
        goto L_8003B3B4;
    // 0x8003B398: sb          $v0, 0x8($a2)
    MEM_B(0X8, ctx->r6) = ctx->r2;
L_8003B39C:
    // 0x8003B39C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B3A0: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8003B3A4: jal         0x8000CBF0
    // 0x8003B3A8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    func_8000CBF0(rdram, ctx);
        goto after_1;
    // 0x8003B3A8: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003B3AC: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B3B0: nop

L_8003B3B4:
    // 0x8003B3B4: lb          $t6, 0x8($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X8);
    // 0x8003B3B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B3BC: bne         $t6, $at, L_8003B3D8
    if (ctx->r14 != ctx->r1) {
        // 0x8003B3C0: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8003B3D8;
    }
    // 0x8003B3C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003B3C4: addiu       $a0, $a0, 0x5FA0
    ctx->r4 = ADD32(ctx->r4, 0X5FA0);
    // 0x8003B3C8: jal         0x800C9D54
    // 0x8003B3CC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003B3CC: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_2:
    // 0x8003B3D0: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B3D4: nop

L_8003B3D8:
    // 0x8003B3D8: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B3DC: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003B3E0: sh          $t7, 0x14($t8)
    MEM_H(0X14, ctx->r24) = ctx->r15;
    // 0x8003B3E4: lw          $t0, 0x4C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B3E8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8003B3EC: sb          $t9, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r25;
    // 0x8003B3F0: lw          $t2, 0x4C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B3F4: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x8003B3F8: sb          $t1, 0x10($t2)
    MEM_B(0X10, ctx->r10) = ctx->r9;
    // 0x8003B3FC: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B400: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003B404: sb          $zero, 0x12($t3)
    MEM_B(0X12, ctx->r11) = 0;
    // 0x8003B408: lbu         $t5, 0x9($a2)
    ctx->r13 = MEM_BU(ctx->r6, 0X9);
    // 0x8003B40C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B410: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8003B414: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003B418: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B41C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003B420: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B424: nop

    // 0x8003B428: bc1f        L_8003B438
    if (!c1cs) {
        // 0x8003B42C: nop
    
            goto L_8003B438;
    }
    // 0x8003B42C: nop

    // 0x8003B430: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003B434: nop

L_8003B438:
    // 0x8003B438: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003B43C: lw          $t6, 0x40($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X40);
    // 0x8003B440: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8003B444: lwc1        $f8, 0xC($t6)
    ctx->f8.u32l = MEM_W(ctx->r14, 0XC);
    // 0x8003B448: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8003B44C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8003B450: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8003B454: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8003B458: sb          $t7, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r15;
    // 0x8003B45C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
    // 0x8003B460: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8003B464: lb          $t8, 0xA($a2)
    ctx->r24 = MEM_B(ctx->r6, 0XA);
    // 0x8003B468: nop

    // 0x8003B46C: beq         $t8, $zero, L_8003B4B0
    if (ctx->r24 == 0) {
        // 0x8003B470: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003B4B0;
    }
    // 0x8003B470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B474: jal         0x8006EA90
    // 0x8003B478: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    get_settings(rdram, ctx);
        goto after_3;
    // 0x8003B478: sw          $a2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r6;
    after_3:
    // 0x8003B47C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x8003B480: lhu         $t9, 0x14($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0X14);
    // 0x8003B484: lb          $t0, 0xA($a2)
    ctx->r8 = MEM_B(ctx->r6, 0XA);
    // 0x8003B488: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003B48C: addiu       $t1, $t0, 0x2
    ctx->r9 = ADD32(ctx->r8, 0X2);
    // 0x8003B490: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x8003B494: and         $t4, $t9, $t3
    ctx->r12 = ctx->r25 & ctx->r11;
    // 0x8003B498: beq         $t4, $zero, L_8003B4A8
    if (ctx->r12 == 0) {
        // 0x8003B49C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8003B4A8;
    }
    // 0x8003B49C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8003B4A0: b           L_8003B4AC
    // 0x8003B4A4: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
        goto L_8003B4AC;
    // 0x8003B4A4: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8003B4A8:
    // 0x8003B4A8: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
L_8003B4AC:
    // 0x8003B4AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003B4B0:
    // 0x8003B4B0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003B4B4: jr          $ra
    // 0x8003B4B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8003B4B8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void ghostmenu_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ABAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009ABB0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009ABB4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009ABB8: jal         0x8009C4A8
    // 0x8009ABBC: addiu       $a0, $a0, 0x1708
    ctx->r4 = ADD32(ctx->r4, 0X1708);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8009ABBC: addiu       $a0, $a0, 0x1708
    ctx->r4 = ADD32(ctx->r4, 0X1708);
    after_0:
    // 0x8009ABC0: jal         0x800C422C
    // 0x8009ABC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_1;
    // 0x8009ABC4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_1:
    // 0x8009ABC8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009ABCC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009ABD0: jr          $ra
    // 0x8009ABD4: nop

    return;
    // 0x8009ABD4: nop

;}
RECOMP_FUNC void dmacopy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076F78: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80076F7C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80076F80: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x80076F84: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80076F88: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x80076F8C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80076F90: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80076F94: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80076F98: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x80076F9C: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80076FA0: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80076FA4: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80076FA8: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80076FAC: jal         0x800D17F0
    // 0x80076FB0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    osInvalDCache_recomp(rdram, ctx);
        goto after_0;
    // 0x80076FB0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x80076FB4: blez        $s1, L_8007701C
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80076FB8: addiu       $s0, $zero, 0x5000
        ctx->r16 = ADD32(0, 0X5000);
            goto L_8007701C;
    }
    // 0x80076FB8: addiu       $s0, $zero, 0x5000
    ctx->r16 = ADD32(0, 0X5000);
    // 0x80076FBC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80076FC0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80076FC4: addiu       $s4, $s4, 0x4220
    ctx->r20 = ADD32(ctx->r20, 0X4220);
    // 0x80076FC8: addiu       $s5, $s5, 0x4200
    ctx->r21 = ADD32(ctx->r21, 0X4200);
    // 0x80076FCC: addiu       $s6, $sp, 0x4C
    ctx->r22 = ADD32(ctx->r29, 0X4C);
L_80076FD0:
    // 0x80076FD0: slt         $at, $s1, $s0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x80076FD4: beq         $at, $zero, L_80076FE0
    if (ctx->r1 == 0) {
        // 0x80076FD8: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_80076FE0;
    }
    // 0x80076FD8: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80076FDC: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
L_80076FE0:
    // 0x80076FE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80076FE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80076FE8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x80076FEC: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x80076FF0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80076FF4: nop

    // 0x80076FF8: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    extern void dkr_legacy_pi_start_dma(uint8_t*, recomp_context*); dkr_legacy_pi_start_dma(rdram, ctx);
    // 0x80076FFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x80077000: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80077004: jal         0x800C8BB0
    // 0x80077008: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077008: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x8007700C: subu        $s1, $s1, $s0
    ctx->r17 = SUB32(ctx->r17, ctx->r16);
    // 0x80077010: addu        $s3, $s3, $s0
    ctx->r19 = ADD32(ctx->r19, ctx->r16);
    // 0x80077014: bgtz        $s1, L_80076FD0
    if (SIGNED(ctx->r17) > 0) {
        // 0x80077018: addu        $s2, $s2, $s0
        ctx->r18 = ADD32(ctx->r18, ctx->r16);
            goto L_80076FD0;
    }
    // 0x80077018: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
L_8007701C:
    // 0x8007701C: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x80077020: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80077024: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80077028: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8007702C: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80077030: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80077034: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80077038: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8007703C: jr          $ra
    // 0x80077040: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80077040: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void compute_scene_camera_transform_matrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80031018: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8003101C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80031020: lui         $at, 0xC780
    ctx->r1 = S32(0XC780 << 16);
    // 0x80031024: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80031028: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8003102C: lw          $v0, -0x4F50($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X4F50);
    // 0x80031030: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80031034: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x80031038: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x8003103C: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80031040: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x80031044: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80031048: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x8003104C: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80031050: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80031054: sh          $t7, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r15;
    // 0x80031058: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x8003105C: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    // 0x80031060: addiu       $a1, $sp, 0x38
    ctx->r5 = ADD32(ctx->r29, 0X38);
    // 0x80031064: swc1        $f0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f0.u32l;
    // 0x80031068: swc1        $f0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f0.u32l;
    // 0x8003106C: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x80031070: swc1        $f6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f6.u32l;
    // 0x80031074: jal         0x8006FC30
    // 0x80031078: sh          $t8, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r24;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x80031078: sh          $t8, 0x38($sp)
    MEM_H(0X38, ctx->r29) = ctx->r24;
    after_0:
    // 0x8003107C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x80031080: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80031084: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80031088: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x8003108C: addiu       $t0, $sp, 0x30
    ctx->r8 = ADD32(ctx->r29, 0X30);
    // 0x80031090: addiu       $t1, $sp, 0x2C
    ctx->r9 = ADD32(ctx->r29, 0X2C);
    // 0x80031094: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x80031098: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x8003109C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800310A0: jal         0x8006F64C
    // 0x800310A4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    mtxf_transform_point(rdram, ctx);
        goto after_1;
    // 0x800310A4: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_1:
    // 0x800310A8: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800310AC: lwc1        $f8, 0x34($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800310B0: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800310B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800310B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800310BC: lwc1        $f16, 0x30($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800310C0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800310C4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800310C8: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800310CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800310D0: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800310D4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800310D8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800310DC: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800310E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800310E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800310E8: addiu       $v0, $v0, -0x2B98
    ctx->r2 = ADD32(ctx->r2, -0X2B98);
    // 0x800310EC: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800310F0: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    // 0x800310F4: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800310F8: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800310FC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x80031100: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80031104: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80031108: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003110C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80031110: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80031114: nop

    // 0x80031118: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003111C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80031120: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80031124: jr          $ra
    // 0x80031128: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    return;
    // 0x80031128: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void savemenu_input_dest(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800875E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800875E8: andi        $t6, $a0, 0x4000
    ctx->r14 = ctx->r4 & 0X4000;
    // 0x800875EC: beq         $t6, $zero, L_80087610
    if (ctx->r14 == 0) {
        // 0x800875F0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80087610;
    }
    // 0x800875F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800875F4: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x800875F8: jal         0x80001D04
    // 0x800875FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x800875FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80087600: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x80087604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087608: b           L_800876BC
    // 0x8008760C: sw          $t7, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r15;
        goto L_800876BC;
    // 0x8008760C: sw          $t7, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r15;
L_80087610:
    // 0x80087610: andi        $t8, $a0, 0x9000
    ctx->r24 = ctx->r4 & 0X9000;
    // 0x80087614: beq         $t8, $zero, L_80087634
    if (ctx->r24 == 0) {
        // 0x80087618: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80087634;
    }
    // 0x80087618: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8008761C: jal         0x80001D04
    // 0x80087620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80087620: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80087624: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x80087628: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008762C: b           L_800876BC
    // 0x80087630: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
        goto L_800876BC;
    // 0x80087630: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
L_80087634:
    // 0x80087634: bgez        $a1, L_80087674
    if (SIGNED(ctx->r5) >= 0) {
        // 0x80087638: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80087674;
    }
    // 0x80087638: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008763C: addiu       $v0, $v0, 0x6BE4
    ctx->r2 = ADD32(ctx->r2, 0X6BE4);
    // 0x80087640: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80087644: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80087648: blez        $t0, L_80087674
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8008764C: nop
    
            goto L_80087674;
    }
    // 0x8008764C: nop

    // 0x80087650: jal         0x80001D04
    // 0x80087654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x80087654: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80087658: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008765C: addiu       $v0, $v0, 0x6BE4
    ctx->r2 = ADD32(ctx->r2, 0X6BE4);
    // 0x80087660: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x80087664: nop

    // 0x80087668: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x8008766C: b           L_800876BC
    // 0x80087670: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
        goto L_800876BC;
    // 0x80087670: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
L_80087674:
    // 0x80087674: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087678: blez        $a1, L_800876BC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8008767C: addiu       $v0, $v0, 0x6BE4
        ctx->r2 = ADD32(ctx->r2, 0X6BE4);
            goto L_800876BC;
    }
    // 0x8008767C: addiu       $v0, $v0, 0x6BE4
    ctx->r2 = ADD32(ctx->r2, 0X6BE4);
    // 0x80087680: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80087684: lw          $t4, 0x6A00($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6A00);
    // 0x80087688: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8008768C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80087690: slt         $at, $t3, $t5
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80087694: beq         $at, $zero, L_800876BC
    if (ctx->r1 == 0) {
        // 0x80087698: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_800876BC;
    }
    // 0x80087698: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8008769C: jal         0x80001D04
    // 0x800876A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800876A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800876A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800876A8: addiu       $v0, $v0, 0x6BE4
    ctx->r2 = ADD32(ctx->r2, 0X6BE4);
    // 0x800876AC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800876B0: nop

    // 0x800876B4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800876B8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_800876BC:
    // 0x800876BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800876C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800876C4: jr          $ra
    // 0x800876C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800876C8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void set_text_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C43CC: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C43D0: addiu       $v0, $v0, -0x5818
    ctx->r2 = ADD32(ctx->r2, -0X5818);
    // 0x800C43D4: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800C43D8: nop

    // 0x800C43DC: sb          $a0, 0x18($t6)
    MEM_B(0X18, ctx->r14) = ctx->r4;
    // 0x800C43E0: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800C43E4: nop

    // 0x800C43E8: sb          $a1, 0x19($t7)
    MEM_B(0X19, ctx->r15) = ctx->r5;
    // 0x800C43EC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800C43F0: nop

    // 0x800C43F4: sb          $a2, 0x1A($t8)
    MEM_B(0X1A, ctx->r24) = ctx->r6;
    // 0x800C43F8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800C43FC: jr          $ra
    // 0x800C4400: sb          $a3, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = ctx->r7;
    return;
    // 0x800C4400: sb          $a3, 0x1B($t9)
    MEM_B(0X1B, ctx->r25) = ctx->r7;
;}
RECOMP_FUNC void spawn_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000EA54: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x8000EA58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000EA5C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000EA60: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000EA64: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000EA68: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8000EA6C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x8000EA70: jal         0x8006EA90
    // 0x8000EA74: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8000EA74: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000EA78: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x8000EA7C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000EA80: lbu         $t7, 0x1($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X1);
    // 0x8000EA84: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x8000EA88: andi        $t8, $t7, 0x80
    ctx->r24 = ctx->r15 & 0X80;
    // 0x8000EA8C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8000EA90: or          $a1, $t6, $t9
    ctx->r5 = ctx->r14 | ctx->r25;
    // 0x8000EA94: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8000EA98: jal         0x800B76B8
    // 0x8000EA9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    update_object_stack_trace(rdram, ctx);
        goto after_1;
    // 0x8000EA9C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8000EAA0: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EAA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000EAA8: andi        $t0, $v1, 0x2
    ctx->r8 = ctx->r3 & 0X2;
    // 0x8000EAAC: beq         $t0, $zero, L_8000EAC0
    if (ctx->r8 == 0) {
        // 0x8000EAB0: or          $v1, $t0, $zero
        ctx->r3 = ctx->r8 | 0;
            goto L_8000EAC0;
    }
    // 0x8000EAB0: or          $v1, $t0, $zero
    ctx->r3 = ctx->r8 | 0;
    // 0x8000EAB4: lh          $a0, 0x66($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X66);
    // 0x8000EAB8: b           L_8000EAE0
    // 0x8000EABC: nop

        goto L_8000EAE0;
    // 0x8000EABC: nop

L_8000EAC0:
    // 0x8000EAC0: lw          $t2, 0x64($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X64);
    // 0x8000EAC4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8000EAC8: lw          $t1, -0x5148($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X5148);
    // 0x8000EACC: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x8000EAD0: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8000EAD4: lh          $a0, 0x0($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X0);
    // 0x8000EAD8: nop

    // 0x8000EADC: sh          $a0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r4;
L_8000EAE0:
    // 0x8000EAE0: lw          $t7, -0x5298($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5298);
    // 0x8000EAE4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000EAE8: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8000EAEC: bne         $at, $zero, L_8000EAF8
    if (ctx->r1 != 0) {
        // 0x8000EAF0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8000EAF8;
    }
    // 0x8000EAF0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000EAF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000EAF8:
    // 0x8000EAF8: addiu       $v0, $v0, -0x52A8
    ctx->r2 = ADD32(ctx->r2, -0X52A8);
L_8000EAFC:
    // 0x8000EAFC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8000EB00: nop

    // 0x8000EB04: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x8000EB08: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000EB0C: slti        $at, $s0, 0x800
    ctx->r1 = SIGNED(ctx->r16) < 0X800 ? 1 : 0;
    // 0x8000EB10: bne         $at, $zero, L_8000EAFC
    if (ctx->r1 != 0) {
        // 0x8000EB14: sw          $zero, 0x0($t6)
        MEM_W(0X0, ctx->r14) = 0;
            goto L_8000EAFC;
    }
    // 0x8000EB14: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x8000EB18: lw          $s2, 0x0($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X0);
    // 0x8000EB1C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000EB20: sh          $t9, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r25;
    extern void dkr_legacy_character_event(uint8_t*, recomp_context*, unsigned, uint32_t); dkr_legacy_character_event(rdram, ctx, 0U, 0x801263f0U);
    // 0x8000EB24: sh          $a0, 0x4E($sp)
    MEM_H(0X4E, ctx->r29) = ctx->r4;
    // 0x8000EB28: jal         0x8000C718
    // 0x8000EB2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    load_object_header(rdram, ctx);
        goto after_2;
    // 0x8000EB2C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_2:
    // 0x8000EB30: bne         $v0, $zero, L_8000EB40
    if (ctx->r2 != 0) {
        // 0x8000EB34: sw          $v0, 0x40($s2)
        MEM_W(0X40, ctx->r18) = ctx->r2;
            goto L_8000EB40;
    }
    // 0x8000EB34: sw          $v0, 0x40($s2)
    MEM_W(0X40, ctx->r18) = ctx->r2;
    // 0x8000EB38: b           L_8000F62C
    // 0x8000EB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000EB3C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000EB40:
    // 0x8000EB40: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EB44: nop

    // 0x8000EB48: lhu         $t0, 0x30($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X30);
    // 0x8000EB4C: nop

    // 0x8000EB50: andi        $t2, $t0, 0x80
    ctx->r10 = ctx->r8 & 0X80;
    // 0x8000EB54: beq         $t2, $zero, L_8000EB6C
    if (ctx->r10 == 0) {
        // 0x8000EB58: nop
    
            goto L_8000EB6C;
    }
    // 0x8000EB58: nop

    // 0x8000EB5C: lh          $t1, 0x6($s2)
    ctx->r9 = MEM_H(ctx->r18, 0X6);
    // 0x8000EB60: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EB64: ori         $t3, $t1, 0x80
    ctx->r11 = ctx->r9 | 0X80;
    // 0x8000EB68: sh          $t3, 0x6($s2)
    MEM_H(0X6, ctx->r18) = ctx->r11;
L_8000EB6C:
    // 0x8000EB6C: lb          $t4, 0x54($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X54);
    // 0x8000EB70: addiu       $at, $zero, 0x63
    ctx->r1 = ADD32(0, 0X63);
    // 0x8000EB74: bne         $t4, $at, L_8000EBA4
    if (ctx->r12 != ctx->r1) {
        // 0x8000EB78: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_8000EBA4;
    }
    // 0x8000EB78: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x8000EB7C: lw          $t5, 0x10($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X10);
    // 0x8000EB80: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000EB84: andi        $t7, $t5, 0x1
    ctx->r15 = ctx->r13 & 0X1;
    // 0x8000EB88: beq         $t7, $zero, L_8000EBA4
    if (ctx->r15 == 0) {
        // 0x8000EB8C: lw          $v0, 0x68($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X68);
            goto L_8000EBA4;
    }
    // 0x8000EB8C: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
    // 0x8000EB90: jal         0x800B76B8
    // 0x8000EB94: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_3;
    // 0x8000EB94: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_3:
    // 0x8000EB98: b           L_8000F62C
    // 0x8000EB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000EB9C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000EBA0: lw          $v0, 0x68($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X68);
L_8000EBA4:
    // 0x8000EBA4: nop

    // 0x8000EBA8: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8000EBAC: nop

    // 0x8000EBB0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x8000EBB4: nop

    // 0x8000EBB8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8000EBBC: swc1        $f6, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f6.u32l;
    // 0x8000EBC0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x8000EBC4: lwc1        $f12, 0xC($s2)
    ctx->f12.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000EBC8: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8000EBCC: nop

    // 0x8000EBD0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8000EBD4: swc1        $f10, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f10.u32l;
    // 0x8000EBD8: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8000EBDC: lwc1        $f14, 0x10($s2)
    ctx->f14.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000EBE0: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x8000EBE4: nop

    // 0x8000EBE8: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8000EBEC: swc1        $f18, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f18.u32l;
    // 0x8000EBF0: lw          $a2, 0x14($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X14);
    // 0x8000EBF4: jal         0x80029F18
    // 0x8000EBF8: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_4;
    // 0x8000EBF8: nop

    after_4:
    // 0x8000EBFC: sh          $v0, 0x2E($s2)
    MEM_H(0X2E, ctx->r18) = ctx->r2;
    // 0x8000EC00: lh          $t0, 0x4E($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X4E);
    // 0x8000EC04: nop

    // 0x8000EC08: sh          $t0, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r8;
    // 0x8000EC0C: lw          $t2, 0x68($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X68);
    // 0x8000EC10: nop

    // 0x8000EC14: sw          $t2, 0x3C($s2)
    MEM_W(0X3C, ctx->r18) = ctx->r10;
    // 0x8000EC18: lw          $t1, 0x64($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X64);
    // 0x8000EC1C: nop

    // 0x8000EC20: sh          $t1, 0x4A($s2)
    MEM_H(0X4A, ctx->r18) = ctx->r9;
    // 0x8000EC24: lh          $a0, 0x66($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X66);
    // 0x8000EC28: jal         0x800245B4
    // 0x8000EC2C: nop

    func_800245B4(rdram, ctx);
        goto after_5;
    // 0x8000EC2C: nop

    after_5:
    // 0x8000EC30: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EC34: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000EC38: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000EC3C: nop

    // 0x8000EC40: swc1        $f4, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f4.u32l;
    // 0x8000EC44: lh          $t3, 0x50($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X50);
    // 0x8000EC48: lwc1        $f10, 0x8($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8000EC4C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x8000EC50: sb          $t4, 0x39($s2)
    MEM_B(0X39, ctx->r18) = ctx->r12;
    // 0x8000EC54: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000EC58: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000EC5C: swc1        $f16, 0x34($s2)
    MEM_W(0X34, ctx->r18) = ctx->f16.u32l;
    // 0x8000EC60: lb          $a0, 0x54($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X54);
    // 0x8000EC64: jal         0x80023E30
    // 0x8000EC68: nop

    obj_init_property_flags(rdram, ctx);
        goto after_6;
    // 0x8000EC68: nop

    after_6:
    // 0x8000EC6C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x8000EC70: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EC74: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EC78: lb          $t5, 0x52($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X52);
    // 0x8000EC7C: addiu       $t6, $s2, 0x80
    ctx->r14 = ADD32(ctx->r18, 0X80);
    // 0x8000EC80: addiu       $t7, $t5, 0x1
    ctx->r15 = ADD32(ctx->r13, 0X1);
    // 0x8000EC84: sb          $t7, 0x52($s0)
    MEM_B(0X52, ctx->r16) = ctx->r15;
    // 0x8000EC88: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000EC8C: andi        $t9, $a3, 0x10
    ctx->r25 = ctx->r7 & 0X10;
    // 0x8000EC90: lb          $t8, 0x53($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X53);
    // 0x8000EC94: lb          $s3, 0x55($s0)
    ctx->r19 = MEM_B(ctx->r16, 0X55);
    // 0x8000EC98: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x8000EC9C: beq         $t9, $zero, L_8000ECA8
    if (ctx->r25 == 0) {
        // 0x8000ECA0: sw          $t6, 0x68($s2)
        MEM_W(0X68, ctx->r18) = ctx->r14;
            goto L_8000ECA8;
    }
    // 0x8000ECA0: sw          $t6, 0x68($s2)
    MEM_W(0X68, ctx->r18) = ctx->r14;
    // 0x8000ECA4: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
L_8000ECA8:
    // 0x8000ECA8: lb          $t0, 0x54($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X54);
    // 0x8000ECAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000ECB0: addiu       $t2, $t0, -0x3E
    ctx->r10 = ADD32(ctx->r8, -0X3E);
    // 0x8000ECB4: sltiu       $at, $t2, 0x27
    ctx->r1 = ctx->r10 < 0X27 ? 1 : 0;
    // 0x8000ECB8: beq         $at, $zero, L_8000EDE0
    if (ctx->r1 == 0) {
        // 0x8000ECBC: sll         $t2, $t2, 2
        ctx->r10 = S32(ctx->r10 << 2);
            goto L_8000EDE0;
    }
    // 0x8000ECBC: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x8000ECC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000ECC4: addu        $at, $at, $t2
    gpr jr_addend_8000ECD0 = ctx->r10;
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x8000ECC8: lw          $t2, 0x51B4($at)
    ctx->r10 = ADD32(ctx->r1, 0X51B4);
    // 0x8000ECCC: nop

    // 0x8000ECD0: jr          $t2
    // 0x8000ECD4: nop

    switch (jr_addend_8000ECD0 >> 2) {
        case 0: goto L_8000ECD8; break;
        case 1: goto L_8000EDE0; break;
        case 2: goto L_8000EDE0; break;
        case 3: goto L_8000EDE0; break;
        case 4: goto L_8000EDE0; break;
        case 5: goto L_8000EDE0; break;
        case 6: goto L_8000EDE0; break;
        case 7: goto L_8000EDE0; break;
        case 8: goto L_8000EDE0; break;
        case 9: goto L_8000EDE0; break;
        case 10: goto L_8000EDE0; break;
        case 11: goto L_8000EDE0; break;
        case 12: goto L_8000EDE0; break;
        case 13: goto L_8000EDE0; break;
        case 14: goto L_8000EDE0; break;
        case 15: goto L_8000ED98; break;
        case 16: goto L_8000EDE0; break;
        case 17: goto L_8000EDE0; break;
        case 18: goto L_8000EDE0; break;
        case 19: goto L_8000EDE0; break;
        case 20: goto L_8000EDE0; break;
        case 21: goto L_8000EDE0; break;
        case 22: goto L_8000EDE0; break;
        case 23: goto L_8000EDE0; break;
        case 24: goto L_8000ECF4; break;
        case 25: goto L_8000EDE0; break;
        case 26: goto L_8000EDE0; break;
        case 27: goto L_8000EDE0; break;
        case 28: goto L_8000EDE0; break;
        case 29: goto L_8000ED10; break;
        case 30: goto L_8000EDE0; break;
        case 31: goto L_8000EDE0; break;
        case 32: goto L_8000EDE0; break;
        case 33: goto L_8000ED40; break;
        case 34: goto L_8000EDE0; break;
        case 35: goto L_8000EDE0; break;
        case 36: goto L_8000EDE0; break;
        case 37: goto L_8000EDE0; break;
        case 38: goto L_8000ED54; break;
        default: switch_error(__func__, 0x8000ECD0, 0x800E51B4);
    }
    // 0x8000ECD4: nop

L_8000ECD8:
    // 0x8000ECD8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8000ECDC: jal         0x800619F4
    // 0x8000ECE0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    model_anim_offset(rdram, ctx);
        goto after_7;
    // 0x8000ECE0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_7:
    // 0x8000ECE4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8000ECE8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000ECEC: b           L_8000EDE4
    // 0x8000ECF0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
        goto L_8000EDE4;
    // 0x8000ECF0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_8000ECF4:
    // 0x8000ECF4: jal         0x8009C228
    // 0x8000ECF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_character_id_from_slot(rdram, ctx);
        goto after_8;
    // 0x8000ECF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x8000ECFC: sb          $v0, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r2;
    // 0x8000ED00: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000ED04: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000ED08: b           L_8000EDE0
    // 0x8000ED0C: addiu       $s3, $v0, 0x1
    ctx->r19 = ADD32(ctx->r2, 0X1);
        goto L_8000EDE0;
    // 0x8000ED0C: addiu       $s3, $v0, 0x1
    ctx->r19 = ADD32(ctx->r2, 0X1);
L_8000ED10:
    // 0x8000ED10: lbu         $t3, 0x48($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0X48);
    // 0x8000ED14: lhu         $t1, 0xE($s1)
    ctx->r9 = MEM_HU(ctx->r17, 0XE);
    // 0x8000ED18: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8000ED1C: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8000ED20: srav        $a2, $t1, $t5
    ctx->r6 = S32(SIGNED(ctx->r9) >> (ctx->r13 & 31));
    // 0x8000ED24: andi        $t7, $a2, 0x3
    ctx->r15 = ctx->r6 & 0X3;
    // 0x8000ED28: beq         $t7, $zero, L_8000EDE0
    if (ctx->r15 == 0) {
        // 0x8000ED2C: or          $a2, $t7, $zero
        ctx->r6 = ctx->r15 | 0;
            goto L_8000EDE0;
    }
    // 0x8000ED2C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8000ED30: addiu       $a2, $t7, -0x1
    ctx->r6 = ADD32(ctx->r15, -0X1);
    // 0x8000ED34: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
    // 0x8000ED38: b           L_8000EDE0
    // 0x8000ED3C: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
        goto L_8000EDE0;
    // 0x8000ED3C: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
L_8000ED40:
    // 0x8000ED40: lbu         $a2, 0x17($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X17);
    // 0x8000ED44: nop

    // 0x8000ED48: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
    // 0x8000ED4C: b           L_8000EDE0
    // 0x8000ED50: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
        goto L_8000EDE0;
    // 0x8000ED50: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
L_8000ED54:
    // 0x8000ED54: lhu         $t8, 0xE($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0XE);
    // 0x8000ED58: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8000ED5C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x8000ED60: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
L_8000ED64:
    // 0x8000ED64: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8000ED68: lw          $t0, 0x64($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X64);
    // 0x8000ED6C: andi        $t9, $t6, 0x3
    ctx->r25 = ctx->r14 & 0X3;
    // 0x8000ED70: bne         $v0, $t9, L_8000ED7C
    if (ctx->r2 != ctx->r25) {
        // 0x8000ED74: sra         $t2, $t0, 2
        ctx->r10 = S32(SIGNED(ctx->r8) >> 2);
            goto L_8000ED7C;
    }
    // 0x8000ED74: sra         $t2, $t0, 2
    ctx->r10 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8000ED78: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_8000ED7C:
    // 0x8000ED7C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8000ED80: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8000ED84: bne         $at, $zero, L_8000ED64
    if (ctx->r1 != 0) {
        // 0x8000ED88: sw          $t2, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r10;
            goto L_8000ED64;
    }
    // 0x8000ED88: sw          $t2, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r10;
    // 0x8000ED8C: sb          $a2, 0x3A($s2)
    MEM_B(0X3A, ctx->r18) = ctx->r6;
    // 0x8000ED90: b           L_8000EDE0
    // 0x8000ED94: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
        goto L_8000EDE0;
    // 0x8000ED94: addiu       $s3, $a2, 0x1
    ctx->r19 = ADD32(ctx->r6, 0X1);
L_8000ED98:
    // 0x8000ED98: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000ED9C: jal         0x8009EC70
    // 0x8000EDA0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    is_in_adventure_two(rdram, ctx);
        goto after_9;
    // 0x8000EDA0: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_9:
    // 0x8000EDA4: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8000EDA8: beq         $v0, $zero, L_8000EDCC
    if (ctx->r2 == 0) {
        // 0x8000EDAC: nop
    
            goto L_8000EDCC;
    }
    // 0x8000EDAC: nop

    // 0x8000EDB0: lw          $t3, 0x40($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X40);
    // 0x8000EDB4: nop

    // 0x8000EDB8: lw          $v0, 0x10($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X10);
    // 0x8000EDBC: nop

    // 0x8000EDC0: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8000EDC4: nop

    // 0x8000EDC8: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_8000EDCC:
    // 0x8000EDCC: lw          $t5, 0x40($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X40);
    // 0x8000EDD0: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000EDD4: sb          $t1, 0x55($t5)
    MEM_B(0X55, ctx->r13) = ctx->r9;
    // 0x8000EDD8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EDDC: nop

L_8000EDE0:
    // 0x8000EDE0: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
L_8000EDE4:
    // 0x8000EDE4: nop

    // 0x8000EDE8: bne         $t7, $zero, L_8000EF18
    if (ctx->r15 != 0) {
        // 0x8000EDEC: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_8000EF18;
    }
    // 0x8000EDEC: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8000EDF0: lh          $v0, 0x4A($s2)
    ctx->r2 = MEM_H(ctx->r18, 0X4A);
    // 0x8000EDF4: addiu       $at, $zero, 0x19
    ctx->r1 = ADD32(0, 0X19);
    // 0x8000EDF8: beq         $v0, $at, L_8000EE54
    if (ctx->r2 == ctx->r1) {
        // 0x8000EDFC: addiu       $at, $zero, 0xCB
        ctx->r1 = ADD32(0, 0XCB);
            goto L_8000EE54;
    }
    // 0x8000EDFC: addiu       $at, $zero, 0xCB
    ctx->r1 = ADD32(0, 0XCB);
    // 0x8000EE00: bne         $v0, $at, L_8000EF18
    if (ctx->r2 != ctx->r1) {
        // 0x8000EE04: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_8000EF18;
    }
    // 0x8000EE04: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8000EE08: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8000EE0C: jal         0x8009EC70
    // 0x8000EE10: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    is_in_adventure_two(rdram, ctx);
        goto after_10;
    // 0x8000EE10: sw          $a2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r6;
    after_10:
    // 0x8000EE14: lw          $a2, 0x5C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X5C);
    // 0x8000EE18: beq         $v0, $zero, L_8000EE3C
    if (ctx->r2 == 0) {
        // 0x8000EE1C: nop
    
            goto L_8000EE3C;
    }
    // 0x8000EE1C: nop

    // 0x8000EE20: lw          $t8, 0x40($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE24: nop

    // 0x8000EE28: lw          $v0, 0x10($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X10);
    // 0x8000EE2C: nop

    // 0x8000EE30: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8000EE34: nop

    // 0x8000EE38: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_8000EE3C:
    // 0x8000EE3C: lw          $t0, 0x40($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE40: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000EE44: sb          $t9, 0x55($t0)
    MEM_B(0X55, ctx->r8) = ctx->r25;
    // 0x8000EE48: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EE4C: b           L_8000EF18
    // 0x8000EE50: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
        goto L_8000EF18;
    // 0x8000EE50: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_8000EE54:
    // 0x8000EE54: jal         0x8009EC70
    // 0x8000EE58: nop

    is_in_adventure_two(rdram, ctx);
        goto after_11;
    // 0x8000EE58: nop

    after_11:
    // 0x8000EE5C: beq         $v0, $zero, L_8000EF00
    if (ctx->r2 == 0) {
        // 0x8000EE60: addiu       $s3, $zero, 0x5
        ctx->r19 = ADD32(0, 0X5);
            goto L_8000EF00;
    }
    // 0x8000EE60: addiu       $s3, $zero, 0x5
    ctx->r19 = ADD32(0, 0X5);
    // 0x8000EE64: lw          $t2, 0x40($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE68: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8000EE6C: lw          $v0, 0x10($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X10);
    // 0x8000EE70: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
    // 0x8000EE74: lw          $t3, 0x14($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X14);
    // 0x8000EE78: nop

    // 0x8000EE7C: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8000EE80: lw          $t4, 0x40($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X40);
    // 0x8000EE84: nop

    // 0x8000EE88: lw          $t1, 0x10($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X10);
    // 0x8000EE8C: nop

    // 0x8000EE90: addu        $v0, $t1, $s0
    ctx->r2 = ADD32(ctx->r9, ctx->r16);
    // 0x8000EE94: lw          $t5, 0x14($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X14);
    // 0x8000EE98: nop

    // 0x8000EE9C: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8000EEA0: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x8000EEA4: nop

    // 0x8000EEA8: lw          $t8, 0x10($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X10);
    // 0x8000EEAC: nop

    // 0x8000EEB0: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x8000EEB4: lw          $t6, 0x18($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X18);
    // 0x8000EEB8: nop

    // 0x8000EEBC: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8000EEC0: lw          $t9, 0x40($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X40);
    // 0x8000EEC4: nop

    // 0x8000EEC8: lw          $t0, 0x10($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X10);
    // 0x8000EECC: nop

    // 0x8000EED0: addu        $v0, $t0, $s0
    ctx->r2 = ADD32(ctx->r8, ctx->r16);
    // 0x8000EED4: lw          $t2, 0x1C($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X1C);
    // 0x8000EED8: nop

    // 0x8000EEDC: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8000EEE0: lw          $t3, 0x40($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X40);
    // 0x8000EEE4: nop

    // 0x8000EEE8: lw          $t4, 0x10($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X10);
    // 0x8000EEEC: nop

    // 0x8000EEF0: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x8000EEF4: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x8000EEF8: nop

    // 0x8000EEFC: sw          $t1, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r9;
L_8000EF00:
    // 0x8000EF00: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x8000EF04: addiu       $t5, $zero, 0x5
    ctx->r13 = ADD32(0, 0X5);
    // 0x8000EF08: sb          $t5, 0x55($t7)
    MEM_B(0X55, ctx->r15) = ctx->r13;
    // 0x8000EF0C: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EF10: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000EF14: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_8000EF18:
    // 0x8000EF18: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x8000EF1C: bne         $t8, $zero, L_8000EFEC
    if (ctx->r24 != 0) {
        // 0x8000EF20: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8000EFEC;
    }
    // 0x8000EF20: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000EF24: slt         $at, $a2, $s3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000EF28: beq         $at, $zero, L_8000F0C4
    if (ctx->r1 == 0) {
        // 0x8000EF2C: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F0C4;
    }
    // 0x8000EF2C: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
L_8000EF30:
    // 0x8000EF30: bne         $a2, $zero, L_8000EF58
    if (ctx->r6 != 0) {
        // 0x8000EF34: addiu       $s1, $a2, 0x1
        ctx->r17 = ADD32(ctx->r6, 0X1);
            goto L_8000EF58;
    }
    // 0x8000EF34: addiu       $s1, $a2, 0x1
    ctx->r17 = ADD32(ctx->r6, 0X1);
    // 0x8000EF38: andi        $t6, $a3, 0x4
    ctx->r14 = ctx->r7 & 0X4;
    // 0x8000EF3C: beq         $t6, $zero, L_8000EF5C
    if (ctx->r14 == 0) {
        // 0x8000EF40: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000EF5C;
    }
    // 0x8000EF40: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000EF44: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000EF48: nop

    // 0x8000EF4C: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000EF50: b           L_8000EFD0
    // 0x8000EF54: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_8000EFD0;
    // 0x8000EF54: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_8000EF58:
    // 0x8000EF58: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_8000EF5C:
    // 0x8000EF5C: bne         $a2, $at, L_8000EF80
    if (ctx->r6 != ctx->r1) {
        // 0x8000EF60: andi        $t2, $a3, 0x8
        ctx->r10 = ctx->r7 & 0X8;
            goto L_8000EF80;
    }
    // 0x8000EF60: andi        $t2, $a3, 0x8
    ctx->r10 = ctx->r7 & 0X8;
    // 0x8000EF64: beq         $t2, $zero, L_8000EF80
    if (ctx->r10 == 0) {
        // 0x8000EF68: nop
    
            goto L_8000EF80;
    }
    // 0x8000EF68: nop

    // 0x8000EF6C: lw          $t3, 0x68($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X68);
    // 0x8000EF70: nop

    // 0x8000EF74: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8000EF78: b           L_8000EFD0
    // 0x8000EF7C: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
        goto L_8000EFD0;
    // 0x8000EF7C: sw          $zero, 0x0($t4)
    MEM_W(0X0, ctx->r12) = 0;
L_8000EF80:
    // 0x8000EF80: lw          $t1, 0x40($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X40);
    // 0x8000EF84: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x8000EF88: lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X10);
    // 0x8000EF8C: nop

    // 0x8000EF90: addu        $t7, $t5, $s0
    ctx->r15 = ADD32(ctx->r13, ctx->r16);
    // 0x8000EF94: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8000EF98: jal         0x8005F99C
    // 0x8000EF9C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    object_model_init(rdram, ctx);
        goto after_12;
    // 0x8000EF9C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    after_12:
    // 0x8000EFA0: lw          $t8, 0x68($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X68);
    // 0x8000EFA4: lb          $v1, 0x37($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X37);
    // 0x8000EFA8: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x8000EFAC: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000EFB0: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000EFB4: nop

    // 0x8000EFB8: addu        $t0, $t9, $s0
    ctx->r8 = ADD32(ctx->r25, ctx->r16);
    // 0x8000EFBC: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x8000EFC0: nop

    // 0x8000EFC4: bne         $t2, $zero, L_8000EFD4
    if (ctx->r10 != 0) {
        // 0x8000EFC8: lw          $a3, 0x6C($sp)
        ctx->r7 = MEM_W(ctx->r29, 0X6C);
            goto L_8000EFD4;
    }
    // 0x8000EFC8: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
    // 0x8000EFCC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000EFD0:
    // 0x8000EFD0: lw          $a3, 0x6C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X6C);
L_8000EFD4:
    // 0x8000EFD4: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000EFD8: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000EFDC: bne         $at, $zero, L_8000EF30
    if (ctx->r1 != 0) {
        // 0x8000EFE0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000EF30;
    }
    // 0x8000EFE0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000EFE4: b           L_8000F0C4
    // 0x8000EFE8: nop

        goto L_8000F0C4;
    // 0x8000EFE8: nop

L_8000EFEC:
    // 0x8000EFEC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000EFF0: bne         $t3, $at, L_8000F060
    if (ctx->r11 != ctx->r1) {
        // 0x8000EFF4: slt         $at, $a2, $s3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
            goto L_8000F060;
    }
    // 0x8000EFF4: slt         $at, $a2, $s3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000EFF8: beq         $at, $zero, L_8000F0C4
    if (ctx->r1 == 0) {
        // 0x8000EFFC: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F0C4;
    }
    // 0x8000EFFC: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
L_8000F000:
    // 0x8000F000: lw          $t4, 0x40($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X40);
    // 0x8000F004: addiu       $s1, $a2, 0x1
    ctx->r17 = ADD32(ctx->r6, 0X1);
    // 0x8000F008: lw          $t1, 0x10($t4)
    ctx->r9 = MEM_W(ctx->r12, 0X10);
    // 0x8000F00C: nop

    // 0x8000F010: addu        $t5, $t1, $s0
    ctx->r13 = ADD32(ctx->r9, ctx->r16);
    // 0x8000F014: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x8000F018: jal         0x8007AE74
    // 0x8000F01C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    load_texture(rdram, ctx);
        goto after_13;
    // 0x8000F01C: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    after_13:
    // 0x8000F020: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8000F024: lb          $v1, 0x37($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X37);
    // 0x8000F028: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8000F02C: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8000F030: lw          $t6, 0x68($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X68);
    // 0x8000F034: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000F038: addu        $t9, $t6, $s0
    ctx->r25 = ADD32(ctx->r14, ctx->r16);
    // 0x8000F03C: lw          $t0, 0x0($t9)
    ctx->r8 = MEM_W(ctx->r25, 0X0);
    // 0x8000F040: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000F044: bne         $t0, $zero, L_8000F050
    if (ctx->r8 != 0) {
        // 0x8000F048: nop
    
            goto L_8000F050;
    }
    // 0x8000F048: nop

    // 0x8000F04C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000F050:
    // 0x8000F050: bne         $at, $zero, L_8000F000
    if (ctx->r1 != 0) {
        // 0x8000F054: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F000;
    }
    // 0x8000F054: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F058: b           L_8000F0C4
    // 0x8000F05C: nop

        goto L_8000F0C4;
    // 0x8000F05C: nop

L_8000F060:
    // 0x8000F060: slt         $at, $a2, $s3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000F064: beq         $at, $zero, L_8000F0C4
    if (ctx->r1 == 0) {
        // 0x8000F068: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F0C4;
    }
    // 0x8000F068: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
L_8000F06C:
    // 0x8000F06C: lw          $t2, 0x40($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X40);
    // 0x8000F070: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x8000F074: lw          $t3, 0x10($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X10);
    // 0x8000F078: addiu       $s1, $a2, 0x1
    ctx->r17 = ADD32(ctx->r6, 0X1);
    // 0x8000F07C: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x8000F080: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8000F084: jal         0x8007C12C
    // 0x8000F088: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    tex_load_sprite(rdram, ctx);
        goto after_14;
    // 0x8000F088: sb          $v1, 0x37($sp)
    MEM_B(0X37, ctx->r29) = ctx->r3;
    after_14:
    // 0x8000F08C: lw          $t1, 0x68($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X68);
    // 0x8000F090: lb          $v1, 0x37($sp)
    ctx->r3 = MEM_B(ctx->r29, 0X37);
    // 0x8000F094: addu        $t5, $t1, $s0
    ctx->r13 = ADD32(ctx->r9, ctx->r16);
    // 0x8000F098: sw          $v0, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r2;
    // 0x8000F09C: lw          $t7, 0x68($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X68);
    // 0x8000F0A0: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8000F0A4: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8000F0A8: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8000F0AC: slt         $at, $s1, $s3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x8000F0B0: bne         $t6, $zero, L_8000F0BC
    if (ctx->r14 != 0) {
        // 0x8000F0B4: nop
    
            goto L_8000F0BC;
    }
    // 0x8000F0B4: nop

    // 0x8000F0B8: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8000F0BC:
    // 0x8000F0BC: bne         $at, $zero, L_8000F06C
    if (ctx->r1 != 0) {
        // 0x8000F0C0: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_8000F06C;
    }
    // 0x8000F0C0: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_8000F0C4:
    // 0x8000F0C4: beq         $v1, $zero, L_8000F0EC
    if (ctx->r3 == 0) {
        // 0x8000F0C8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8000F0EC;
    }
    // 0x8000F0C8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F0CC: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F0D0: jal         0x8000F648
    // 0x8000F0D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_15;
    // 0x8000F0D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_15:
    // 0x8000F0D8: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F0DC: jal         0x8000C844
    // 0x8000F0E0: nop

    try_free_object_header(rdram, ctx);
        goto after_16;
    // 0x8000F0E0: nop

    after_16:
    // 0x8000F0E4: b           L_8000F62C
    // 0x8000F0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F0E8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F0EC:
    // 0x8000F0EC: lw          $t0, 0x40($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X40);
    // 0x8000F0F0: lw          $t9, 0x68($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X68);
    // 0x8000F0F4: lb          $t2, 0x55($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X55);
    // 0x8000F0F8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F0FC: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x8000F100: addu        $a1, $t9, $t3
    ctx->r5 = ADD32(ctx->r25, ctx->r11);
    // 0x8000F104: jal         0x800235DC
    // 0x8000F108: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    get_object_property_size(rdram, ctx);
        goto after_17;
    // 0x8000F108: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_17:
    // 0x8000F10C: lw          $t4, 0x50($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X50);
    // 0x8000F110: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000F114: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F118: sw          $zero, -0x51B0($at)
    MEM_W(-0X51B0, ctx->r1) = 0;
    // 0x8000F11C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000F120: andi        $t1, $t4, 0x1
    ctx->r9 = ctx->r12 & 0X1;
    // 0x8000F124: sw          $zero, -0x51AC($at)
    MEM_W(-0X51AC, ctx->r1) = 0;
    // 0x8000F128: beq         $t1, $zero, L_8000F14C
    if (ctx->r9 == 0) {
        // 0x8000F12C: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_8000F14C;
    }
    // 0x8000F12C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000F130: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F134: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F138: jal         0x8000F7EC
    // 0x8000F13C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_shading(rdram, ctx);
        goto after_18;
    // 0x8000F13C: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_18:
    // 0x8000F140: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F144: nop

    // 0x8000F148: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F14C:
    // 0x8000F14C: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8000F150: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F154: andi        $t7, $t5, 0x2
    ctx->r15 = ctx->r13 & 0X2;
    // 0x8000F158: beq         $t7, $zero, L_8000F198
    if (ctx->r15 == 0) {
        // 0x8000F15C: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F198;
    }
    // 0x8000F15C: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F160: jal         0x8000FBCC
    // 0x8000F164: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_shadow(rdram, ctx);
        goto after_19;
    // 0x8000F164: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_19:
    // 0x8000F168: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F16C: bne         $v0, $zero, L_8000F198
    if (ctx->r2 != 0) {
        // 0x8000F170: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_8000F198;
    }
    // 0x8000F170: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000F174: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F178: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F17C: jal         0x8000F648
    // 0x8000F180: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_20;
    // 0x8000F180: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_20:
    // 0x8000F184: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F188: jal         0x8000C844
    // 0x8000F18C: nop

    try_free_object_header(rdram, ctx);
        goto after_21;
    // 0x8000F18C: nop

    after_21:
    // 0x8000F190: b           L_8000F62C
    // 0x8000F194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F194: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F198:
    // 0x8000F198: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x8000F19C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F1A0: andi        $t6, $t8, 0x4
    ctx->r14 = ctx->r24 & 0X4;
    // 0x8000F1A4: beq         $t6, $zero, L_8000F200
    if (ctx->r14 == 0) {
        // 0x8000F1A8: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F200;
    }
    // 0x8000F1A8: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F1AC: jal         0x8000FC6C
    // 0x8000F1B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_water_effect(rdram, ctx);
        goto after_22;
    // 0x8000F1B0: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_22:
    // 0x8000F1B4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F1B8: bne         $v0, $zero, L_8000F200
    if (ctx->r2 != 0) {
        // 0x8000F1BC: addu        $a2, $a2, $v0
        ctx->r6 = ADD32(ctx->r6, ctx->r2);
            goto L_8000F200;
    }
    // 0x8000F1BC: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
    // 0x8000F1C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F1C4: lw          $v0, -0x51B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51B0);
    // 0x8000F1C8: nop

    // 0x8000F1CC: beq         $v0, $zero, L_8000F1E0
    if (ctx->r2 == 0) {
        // 0x8000F1D0: lw          $a2, 0x64($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X64);
            goto L_8000F1E0;
    }
    // 0x8000F1D0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F1D4: jal         0x8007B2BC
    // 0x8000F1D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_23;
    // 0x8000F1D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_23:
    // 0x8000F1DC: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_8000F1E0:
    // 0x8000F1E0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F1E4: jal         0x8000F648
    // 0x8000F1E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_24;
    // 0x8000F1E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_24:
    // 0x8000F1EC: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F1F0: jal         0x8000C844
    // 0x8000F1F4: nop

    try_free_object_header(rdram, ctx);
        goto after_25;
    // 0x8000F1F4: nop

    after_25:
    // 0x8000F1F8: b           L_8000F62C
    // 0x8000F1FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F1FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F200:
    // 0x8000F200: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x8000F204: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F208: andi        $t2, $t0, 0x10
    ctx->r10 = ctx->r8 & 0X10;
    // 0x8000F20C: beq         $t2, $zero, L_8000F228
    if (ctx->r10 == 0) {
        // 0x8000F210: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F228;
    }
    // 0x8000F210: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F214: jal         0x8000FD20
    // 0x8000F218: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    init_object_interaction_data(rdram, ctx);
        goto after_26;
    // 0x8000F218: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_26:
    // 0x8000F21C: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F220: nop

    // 0x8000F224: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F228:
    // 0x8000F228: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x8000F22C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F230: andi        $t3, $t9, 0x20
    ctx->r11 = ctx->r25 & 0X20;
    // 0x8000F234: beq         $t3, $zero, L_8000F250
    if (ctx->r11 == 0) {
        // 0x8000F238: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_8000F250;
    }
    // 0x8000F238: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F23C: jal         0x8000FD34
    // 0x8000F240: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    obj_init_collision(rdram, ctx);
        goto after_27;
    // 0x8000F240: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_27:
    // 0x8000F244: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F248: nop

    // 0x8000F24C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F250:
    // 0x8000F250: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F254: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F258: lb          $v0, 0x56($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X56);
    // 0x8000F25C: nop

    // 0x8000F260: blez        $v0, L_8000F27C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F264: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8000F27C;
    }
    // 0x8000F264: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8000F268: beq         $at, $zero, L_8000F27C
    if (ctx->r1 == 0) {
        // 0x8000F26C: nop
    
            goto L_8000F27C;
    }
    // 0x8000F26C: nop

    // 0x8000F270: sw          $a2, 0x60($s2)
    MEM_W(0X60, ctx->r18) = ctx->r6;
    // 0x8000F274: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F278: addiu       $a2, $a2, 0x30
    ctx->r6 = ADD32(ctx->r6, 0X30);
L_8000F27C:
    // 0x8000F27C: lb          $t4, 0x57($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X57);
    // 0x8000F280: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x8000F284: blez        $t4, L_8000F2A0
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000F288: nop
    
            goto L_8000F2A0;
    }
    // 0x8000F288: nop

    // 0x8000F28C: jal         0x8000FAC4
    // 0x8000F290: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    obj_init_emitter(rdram, ctx);
        goto after_28;
    // 0x8000F290: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_28:
    // 0x8000F294: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8000F298: lw          $s0, 0x40($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X40);
    // 0x8000F29C: addu        $a2, $a2, $v0
    ctx->r6 = ADD32(ctx->r6, ctx->r2);
L_8000F2A0:
    // 0x8000F2A0: lb          $t1, 0x5A($s0)
    ctx->r9 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F2A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000F2A8: blez        $t1, L_8000F2C8
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8000F2AC: subu        $a1, $a2, $s2
        ctx->r5 = SUB32(ctx->r6, ctx->r18);
            goto L_8000F2C8;
    }
    // 0x8000F2AC: subu        $a1, $a2, $s2
    ctx->r5 = SUB32(ctx->r6, ctx->r18);
    // 0x8000F2B0: sw          $a2, 0x70($s2)
    MEM_W(0X70, ctx->r18) = ctx->r6;
    // 0x8000F2B4: lb          $t5, 0x5A($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X5A);
    // 0x8000F2B8: nop

    // 0x8000F2BC: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x8000F2C0: addu        $a2, $a2, $t7
    ctx->r6 = ADD32(ctx->r6, ctx->r15);
    // 0x8000F2C4: subu        $a1, $a2, $s2
    ctx->r5 = SUB32(ctx->r6, ctx->r18);
L_8000F2C8:
    // 0x8000F2C8: lw          $a0, -0x5198($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5198);
    // 0x8000F2CC: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8000F2D0: jal         0x80070E90
    // 0x8000F2D4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    mempool_alloc_pool(rdram, ctx);
        goto after_29;
    // 0x8000F2D4: or          $s0, $s2, $zero
    ctx->r16 = ctx->r18 | 0;
    after_29:
    // 0x8000F2D8: bne         $v0, $zero, L_8000F33C
    if (ctx->r2 != 0) {
        // 0x8000F2DC: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8000F33C;
    }
    // 0x8000F2DC: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000F2E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F2E4: lw          $v0, -0x51B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51B0);
    // 0x8000F2E8: nop

    // 0x8000F2EC: beq         $v0, $zero, L_8000F2FC
    if (ctx->r2 == 0) {
        // 0x8000F2F0: nop
    
            goto L_8000F2FC;
    }
    // 0x8000F2F0: nop

    // 0x8000F2F4: jal         0x8007B2BC
    // 0x8000F2F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_30;
    // 0x8000F2F8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
L_8000F2FC:
    // 0x8000F2FC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F300: lw          $v0, -0x51AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51AC);
    // 0x8000F304: nop

    // 0x8000F308: beq         $v0, $zero, L_8000F31C
    if (ctx->r2 == 0) {
        // 0x8000F30C: lw          $a2, 0x64($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X64);
            goto L_8000F31C;
    }
    // 0x8000F30C: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F310: jal         0x8007B2BC
    // 0x8000F314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_31;
    // 0x8000F314: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_31:
    // 0x8000F318: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_8000F31C:
    // 0x8000F31C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8000F320: jal         0x8000F648
    // 0x8000F324: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_32;
    // 0x8000F324: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_32:
    // 0x8000F328: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F32C: jal         0x8000C844
    // 0x8000F330: nop

    try_free_object_header(rdram, ctx);
        goto after_33;
    // 0x8000F330: nop

    after_33:
    // 0x8000F334: b           L_8000F62C
    // 0x8000F338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F338: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F33C:
    // 0x8000F33C: andi        $t8, $s1, 0xF
    ctx->r24 = ctx->r17 & 0XF;
    // 0x8000F340: beq         $t8, $zero, L_8000F354
    if (ctx->r24 == 0) {
        // 0x8000F344: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000F354;
    }
    // 0x8000F344: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F348: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x8000F34C: and         $t6, $s1, $at
    ctx->r14 = ctx->r17 & ctx->r1;
    // 0x8000F350: addiu       $s1, $t6, 0x10
    ctx->r17 = ADD32(ctx->r14, 0X10);
L_8000F354:
    // 0x8000F354: sra         $t0, $s1, 2
    ctx->r8 = S32(SIGNED(ctx->r17) >> 2);
    // 0x8000F358: blez        $t0, L_8000F390
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000F35C: sll         $s0, $a2, 2
        ctx->r16 = S32(ctx->r6 << 2);
            goto L_8000F390;
    }
    // 0x8000F35C: sll         $s0, $a2, 2
    ctx->r16 = S32(ctx->r6 << 2);
    // 0x8000F360: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000F364: addiu       $a1, $a1, -0x52A8
    ctx->r5 = ADD32(ctx->r5, -0X52A8);
    // 0x8000F368: addu        $v1, $v0, $s0
    ctx->r3 = ADD32(ctx->r2, ctx->r16);
    // 0x8000F36C: sll         $a0, $t0, 2
    ctx->r4 = S32(ctx->r8 << 2);
L_8000F370:
    // 0x8000F370: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8000F374: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000F378: addu        $t9, $t2, $s0
    ctx->r25 = ADD32(ctx->r10, ctx->r16);
    // 0x8000F37C: lw          $t3, 0x0($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X0);
    // 0x8000F380: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000F384: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000F388: bne         $at, $zero, L_8000F370
    if (ctx->r1 != 0) {
        // 0x8000F38C: sw          $t3, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->r11;
            goto L_8000F370;
    }
    // 0x8000F38C: sw          $t3, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->r11;
L_8000F390:
    // 0x8000F390: lw          $v1, 0x58($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X58);
    // 0x8000F394: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000F398: beq         $v1, $zero, L_8000F3B0
    if (ctx->r3 == 0) {
        // 0x8000F39C: addiu       $a1, $a1, -0x52A8
        ctx->r5 = ADD32(ctx->r5, -0X52A8);
            goto L_8000F3B0;
    }
    // 0x8000F39C: addiu       $a1, $a1, -0x52A8
    ctx->r5 = ADD32(ctx->r5, -0X52A8);
    // 0x8000F3A0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x8000F3A4: addu        $t4, $v0, $v1
    ctx->r12 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F3A8: subu        $t5, $t4, $t1
    ctx->r13 = SUB32(ctx->r12, ctx->r9);
    // 0x8000F3AC: sw          $t5, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->r13;
L_8000F3B0:
    // 0x8000F3B0: lw          $v1, 0x50($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X50);
    // 0x8000F3B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F3B8: beq         $v1, $zero, L_8000F3D0
    if (ctx->r3 == 0) {
        // 0x8000F3BC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8000F3D0;
    }
    // 0x8000F3BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8000F3C0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000F3C4: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F3C8: subu        $t6, $t7, $t8
    ctx->r14 = SUB32(ctx->r15, ctx->r24);
    // 0x8000F3CC: sw          $t6, 0x50($v0)
    MEM_W(0X50, ctx->r2) = ctx->r14;
L_8000F3D0:
    // 0x8000F3D0: lw          $v1, 0x54($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X54);
    // 0x8000F3D4: nop

    // 0x8000F3D8: beq         $v1, $zero, L_8000F3F0
    if (ctx->r3 == 0) {
        // 0x8000F3DC: nop
    
            goto L_8000F3F0;
    }
    // 0x8000F3DC: nop

    // 0x8000F3E0: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8000F3E4: addu        $t0, $v0, $v1
    ctx->r8 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F3E8: subu        $t9, $t0, $t2
    ctx->r25 = SUB32(ctx->r8, ctx->r10);
    // 0x8000F3EC: sw          $t9, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->r25;
L_8000F3F0:
    // 0x8000F3F0: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8000F3F4: nop

    // 0x8000F3F8: beq         $v1, $zero, L_8000F410
    if (ctx->r3 == 0) {
        // 0x8000F3FC: nop
    
            goto L_8000F410;
    }
    // 0x8000F3FC: nop

    // 0x8000F400: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x8000F404: addu        $t3, $v0, $v1
    ctx->r11 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F408: subu        $t1, $t3, $t4
    ctx->r9 = SUB32(ctx->r11, ctx->r12);
    // 0x8000F40C: sw          $t1, 0x64($v0)
    MEM_W(0X64, ctx->r2) = ctx->r9;
L_8000F410:
    // 0x8000F410: lw          $v1, 0x4C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4C);
    // 0x8000F414: nop

    // 0x8000F418: beq         $v1, $zero, L_8000F430
    if (ctx->r3 == 0) {
        // 0x8000F41C: nop
    
            goto L_8000F430;
    }
    // 0x8000F41C: nop

    // 0x8000F420: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8000F424: addu        $t5, $v0, $v1
    ctx->r13 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F428: subu        $t8, $t5, $t7
    ctx->r24 = SUB32(ctx->r13, ctx->r15);
    // 0x8000F42C: sw          $t8, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r24;
L_8000F430:
    // 0x8000F430: lw          $v1, 0x5C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X5C);
    // 0x8000F434: nop

    // 0x8000F438: beq         $v1, $zero, L_8000F450
    if (ctx->r3 == 0) {
        // 0x8000F43C: nop
    
            goto L_8000F450;
    }
    // 0x8000F43C: nop

    // 0x8000F440: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x8000F444: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F448: subu        $t2, $t6, $t0
    ctx->r10 = SUB32(ctx->r14, ctx->r8);
    // 0x8000F44C: sw          $t2, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r10;
L_8000F450:
    // 0x8000F450: lw          $v1, 0x60($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X60);
    // 0x8000F454: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000F458: beq         $v1, $zero, L_8000F470
    if (ctx->r3 == 0) {
        // 0x8000F45C: addiu       $s0, $s0, -0x51A4
        ctx->r16 = ADD32(ctx->r16, -0X51A4);
            goto L_8000F470;
    }
    // 0x8000F45C: addiu       $s0, $s0, -0x51A4
    ctx->r16 = ADD32(ctx->r16, -0X51A4);
    // 0x8000F460: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8000F464: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x8000F468: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x8000F46C: sw          $t4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->r12;
L_8000F470:
    // 0x8000F470: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8000F474: nop

    // 0x8000F478: lb          $t1, 0x57($v1)
    ctx->r9 = MEM_B(ctx->r3, 0X57);
    // 0x8000F47C: nop

    // 0x8000F480: blez        $t1, L_8000F4A0
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8000F484: nop
    
            goto L_8000F4A0;
    }
    // 0x8000F484: nop

    // 0x8000F488: lw          $t5, 0x6C($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X6C);
    // 0x8000F48C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000F490: addu        $t7, $v0, $t5
    ctx->r15 = ADD32(ctx->r2, ctx->r13);
    // 0x8000F494: subu        $t6, $t7, $t8
    ctx->r14 = SUB32(ctx->r15, ctx->r24);
    // 0x8000F498: lw          $v1, 0x40($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X40);
    // 0x8000F49C: sw          $t6, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->r14;
L_8000F4A0:
    // 0x8000F4A0: lb          $t0, 0x5A($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X5A);
    // 0x8000F4A4: addiu       $t1, $v0, 0x80
    ctx->r9 = ADD32(ctx->r2, 0X80);
    // 0x8000F4A8: blez        $t0, L_8000F4C4
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8000F4AC: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_8000F4C4;
    }
    // 0x8000F4AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000F4B0: lw          $t2, 0x70($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X70);
    // 0x8000F4B4: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8000F4B8: addu        $t9, $v0, $t2
    ctx->r25 = ADD32(ctx->r2, ctx->r10);
    // 0x8000F4BC: subu        $t4, $t9, $t3
    ctx->r12 = SUB32(ctx->r25, ctx->r11);
    // 0x8000F4C0: sw          $t4, 0x70($v0)
    MEM_W(0X70, ctx->r2) = ctx->r12;
L_8000F4C4:
    // 0x8000F4C4: sw          $t1, 0x68($v0)
    MEM_W(0X68, ctx->r2) = ctx->r9;
    // 0x8000F4C8: lw          $s1, 0x6C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X6C);
    // 0x8000F4CC: nop

    // 0x8000F4D0: andi        $t5, $s1, 0x1
    ctx->r13 = ctx->r17 & 0X1;
    // 0x8000F4D4: beq         $t5, $zero, L_8000F500
    if (ctx->r13 == 0) {
        // 0x8000F4D8: or          $s1, $t5, $zero
        ctx->r17 = ctx->r13 | 0;
            goto L_8000F500;
    }
    // 0x8000F4D8: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
    // 0x8000F4DC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x8000F4E0: lw          $t7, -0x51A8($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X51A8);
    // 0x8000F4E4: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000F4E8: addu        $t0, $t7, $t6
    ctx->r8 = ADD32(ctx->r15, ctx->r14);
    // 0x8000F4EC: sw          $v0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r2;
    // 0x8000F4F0: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8000F4F4: nop

    // 0x8000F4F8: addiu       $t9, $t2, 0x1
    ctx->r25 = ADD32(ctx->r10, 0X1);
    // 0x8000F4FC: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_8000F500:
    // 0x8000F500: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000F504: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x8000F508: jal         0x800238BC
    // 0x8000F50C: addiu       $s0, $s0, -0x51A4
    ctx->r16 = ADD32(ctx->r16, -0X51A4);
    run_object_init_func(rdram, ctx);
        goto after_34;
    // 0x8000F50C: addiu       $s0, $s0, -0x51A4
    ctx->r16 = ADD32(ctx->r16, -0X51A4);
    after_34:
    // 0x8000F510: lw          $v0, 0x4C($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4C);
    // 0x8000F514: nop

    // 0x8000F518: beq         $v0, $zero, L_8000F54C
    if (ctx->r2 == 0) {
        // 0x8000F51C: nop
    
            goto L_8000F54C;
    }
    // 0x8000F51C: nop

    // 0x8000F520: lwc1        $f18, 0xC($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8000F524: nop

    // 0x8000F528: swc1        $f18, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f18.u32l;
    // 0x8000F52C: lw          $t3, 0x4C($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4C);
    // 0x8000F530: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8000F534: nop

    // 0x8000F538: swc1        $f4, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->f4.u32l;
    // 0x8000F53C: lw          $t4, 0x4C($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4C);
    // 0x8000F540: lwc1        $f6, 0x14($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8000F544: nop

    // 0x8000F548: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
L_8000F54C:
    // 0x8000F54C: lw          $t1, 0x40($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X40);
    // 0x8000F550: nop

    // 0x8000F554: lb          $v0, 0x56($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X56);
    // 0x8000F558: nop

    // 0x8000F55C: blez        $v0, L_8000F5F4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000F560: slti        $at, $v0, 0xA
        ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
            goto L_8000F5F4;
    }
    // 0x8000F560: slti        $at, $v0, 0xA
    ctx->r1 = SIGNED(ctx->r2) < 0XA ? 1 : 0;
    // 0x8000F564: beq         $at, $zero, L_8000F5F4
    if (ctx->r1 == 0) {
        // 0x8000F568: nop
    
            goto L_8000F5F4;
    }
    // 0x8000F568: nop

    // 0x8000F56C: jal         0x8000F99C
    // 0x8000F570: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_init_attachpoint(rdram, ctx);
        goto after_35;
    // 0x8000F570: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_35:
    // 0x8000F574: beq         $v0, $zero, L_8000F5F4
    if (ctx->r2 == 0) {
        // 0x8000F578: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8000F5F4;
    }
    // 0x8000F578: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F57C: lw          $v0, -0x51B0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51B0);
    // 0x8000F580: nop

    // 0x8000F584: beq         $v0, $zero, L_8000F594
    if (ctx->r2 == 0) {
        // 0x8000F588: nop
    
            goto L_8000F594;
    }
    // 0x8000F588: nop

    // 0x8000F58C: jal         0x8007B2BC
    // 0x8000F590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_36;
    // 0x8000F590: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_36:
L_8000F594:
    // 0x8000F594: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000F598: lw          $v0, -0x51AC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51AC);
    // 0x8000F59C: nop

    // 0x8000F5A0: beq         $v0, $zero, L_8000F5B4
    if (ctx->r2 == 0) {
        // 0x8000F5A4: lw          $a2, 0x64($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X64);
            goto L_8000F5B4;
    }
    // 0x8000F5A4: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
    // 0x8000F5A8: jal         0x8007B2BC
    // 0x8000F5AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tex_free(rdram, ctx);
        goto after_37;
    // 0x8000F5AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_37:
    // 0x8000F5B0: lw          $a2, 0x64($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X64);
L_8000F5B4:
    // 0x8000F5B4: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8000F5B8: jal         0x8000F648
    // 0x8000F5BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    objFreeAssets(rdram, ctx);
        goto after_38;
    // 0x8000F5BC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_38:
    // 0x8000F5C0: lh          $a0, 0x4E($sp)
    ctx->r4 = MEM_H(ctx->r29, 0X4E);
    // 0x8000F5C4: jal         0x8000C844
    // 0x8000F5C8: nop

    try_free_object_header(rdram, ctx);
        goto after_39;
    // 0x8000F5C8: nop

    after_39:
    // 0x8000F5CC: jal         0x80071140
    // 0x8000F5D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_40;
    // 0x8000F5D0: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_40:
    // 0x8000F5D4: beq         $s1, $zero, L_8000F5EC
    if (ctx->r17 == 0) {
        // 0x8000F5D8: nop
    
            goto L_8000F5EC;
    }
    // 0x8000F5D8: nop

    // 0x8000F5DC: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8000F5E0: nop

    // 0x8000F5E4: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8000F5E8: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_8000F5EC:
    // 0x8000F5EC: b           L_8000F62C
    // 0x8000F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000F62C;
    // 0x8000F5F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8000F5F4:
    // 0x8000F5F4: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x8000F5F8: nop

    // 0x8000F5FC: lb          $t6, 0x5A($t7)
    ctx->r14 = MEM_B(ctx->r15, 0X5A);
    // 0x8000F600: nop

    // 0x8000F604: blez        $t6, L_8000F614
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000F608: nop
    
            goto L_8000F614;
    }
    // 0x8000F608: nop

    // 0x8000F60C: jal         0x8000F758
    // 0x8000F610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    light_setup_light_sources(rdram, ctx);
        goto after_41;
    // 0x8000F610: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_41:
L_8000F614:
    // 0x8000F614: jal         0x800619F4
    // 0x8000F618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    model_anim_offset(rdram, ctx);
        goto after_42;
    // 0x8000F618: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_42:
    // 0x8000F61C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000F620: jal         0x800B76B8
    // 0x8000F624: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    update_object_stack_trace(rdram, ctx);
        goto after_43;
    // 0x8000F624: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_43:
    // 0x8000F628: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8000F62C:
    extern void dkr_presentation_object_spawned(uint8_t*, recomp_context*); dkr_presentation_object_spawned(rdram, ctx);
    // 0x8000F62C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000F630: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000F634: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000F638: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000F63C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000F640: jr          $ra
    // 0x8000F644: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x8000F644: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void sprite_cache_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C52C: bltz        $a0, L_8007C548
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007C530: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007C548;
    }
    // 0x8007C530: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C534: lw          $t6, 0x6358($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6358);
    // 0x8007C538: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007C53C: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007C540: bne         $at, $zero, L_8007C550
    if (ctx->r1 != 0) {
        // 0x8007C544: nop
    
            goto L_8007C550;
    }
    // 0x8007C544: nop

L_8007C548:
    // 0x8007C548: jr          $ra
    // 0x8007C54C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007C54C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C550:
    // 0x8007C550: lw          $t7, 0x634C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X634C);
    // 0x8007C554: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007C558: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007C55C: lw          $v1, 0x4($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X4);
    // 0x8007C560: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007C564: bne         $v1, $at, L_8007C574
    if (ctx->r3 != ctx->r1) {
        // 0x8007C568: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_8007C574;
    }
    // 0x8007C568: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8007C56C: jr          $ra
    // 0x8007C570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8007C570: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C574:
    // 0x8007C574: jr          $ra
    // 0x8007C578: nop

    return;
    // 0x8007C578: nop

;}
RECOMP_FUNC void obj_init_modechange(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AD34: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8003AD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003AD3C: lbu         $t7, 0x8($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X8);
    // 0x8003AD40: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x8003AD44: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x8003AD48: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003AD4C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003AD50: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x8003AD54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003AD58: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003AD5C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003AD60: bc1f        L_8003AD70
    if (!c1cs) {
        // 0x8003AD64: nop
    
            goto L_8003AD70;
    }
    // 0x8003AD64: nop

    // 0x8003AD68: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003AD6C: nop

L_8003AD70:
    // 0x8003AD70: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8003AD74: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x8003AD78: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x8003AD7C: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x8003AD80: nop

    // 0x8003AD84: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x8003AD88: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x8003AD8C: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003AD90: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8003AD94: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8003AD98: jal         0x800707C4
    // 0x8003AD9C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x8003AD9C: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x8003ADA0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003ADA4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003ADA8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003ADAC: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x8003ADB0: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x8003ADB4: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x8003ADB8: jal         0x800707F8
    // 0x8003ADBC: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x8003ADBC: nop

    after_1:
    // 0x8003ADC0: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x8003ADC4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8003ADC8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8003ADCC: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x8003ADD0: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8003ADD4: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003ADD8: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003ADDC: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003ADE0: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x8003ADE4: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x8003ADE8: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x8003ADEC: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8003ADF0: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x8003ADF4: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x8003ADF8: nop

    // 0x8003ADFC: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x8003AE00: lbu         $t2, 0xA($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XA);
    // 0x8003AE04: nop

    // 0x8003AE08: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
    // 0x8003AE0C: lw          $t4, 0x4C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE10: nop

    // 0x8003AE14: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x8003AE18: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE1C: nop

    // 0x8003AE20: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x8003AE24: lw          $t7, 0x4C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE28: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003AE2C: nop

    // 0x8003AE30: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x8003AE34: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x8003AE38: nop

    // 0x8003AE3C: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x8003AE40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003AE44: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8003AE48: jr          $ra
    // 0x8003AE4C: nop

    return;
    // 0x8003AE4C: nop

;}
RECOMP_FUNC void gParticlePtrList_flush(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001004C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80010050: sw          $s7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r23;
    // 0x80010054: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80010058: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001005C: addiu       $s7, $s7, -0x5138
    ctx->r23 = ADD32(ctx->r23, -0X5138);
    // 0x80010060: sw          $zero, -0x5178($at)
    MEM_W(-0X5178, ctx->r1) = 0;
    // 0x80010064: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x80010068: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001006C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80010070: sw          $s6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r22;
    // 0x80010074: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x80010078: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001007C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80010080: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80010084: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80010088: blez        $t6, L_8001017C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8001008C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001017C;
    }
    // 0x8001008C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80010090: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80010094: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80010098: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001009C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800100A0: addiu       $s0, $s0, -0x51A4
    ctx->r16 = ADD32(ctx->r16, -0X51A4);
    // 0x800100A4: addiu       $s1, $s1, -0x51A8
    ctx->r17 = ADD32(ctx->r17, -0X51A8);
    // 0x800100A8: addiu       $s4, $s4, -0x5184
    ctx->r20 = ADD32(ctx->r20, -0X5184);
    // 0x800100AC: addiu       $s5, $s5, -0x513C
    ctx->r21 = ADD32(ctx->r21, -0X513C);
    // 0x800100B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800100B4: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_800100B8:
    // 0x800100B8: lw          $t7, 0x0($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X0);
    // 0x800100BC: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x800100C0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800100C4: lw          $a2, 0x0($t8)
    ctx->r6 = MEM_W(ctx->r24, 0X0);
    // 0x800100C8: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x800100CC: blez        $a1, L_80010100
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800100D0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80010100;
    }
    // 0x800100D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800100D4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800100D8: nop

L_800100DC:
    // 0x800100DC: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800100E0: nop

    // 0x800100E4: bne         $a2, $t9, L_800100F0
    if (ctx->r6 != ctx->r25) {
        // 0x800100E8: nop
    
            goto L_800100F0;
    }
    // 0x800100E8: nop

    // 0x800100EC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_800100F0:
    // 0x800100F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800100F4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800100F8: bne         $at, $zero, L_800100DC
    if (ctx->r1 != 0) {
        // 0x800100FC: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_800100DC;
    }
    // 0x800100FC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80010100:
    // 0x80010100: beq         $a0, $s6, L_8001015C
    if (ctx->r4 == ctx->r22) {
        // 0x80010104: addiu       $t1, $a1, -0x1
        ctx->r9 = ADD32(ctx->r5, -0X1);
            goto L_8001015C;
    }
    // 0x80010104: addiu       $t1, $a1, -0x1
    ctx->r9 = ADD32(ctx->r5, -0X1);
    // 0x80010108: lh          $v0, 0x0($s4)
    ctx->r2 = MEM_H(ctx->r20, 0X0);
    // 0x8001010C: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80010110: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80010114: beq         $at, $zero, L_80010120
    if (ctx->r1 == 0) {
        // 0x80010118: addiu       $t0, $v0, -0x1
        ctx->r8 = ADD32(ctx->r2, -0X1);
            goto L_80010120;
    }
    // 0x80010118: addiu       $t0, $v0, -0x1
    ctx->r8 = ADD32(ctx->r2, -0X1);
    // 0x8001011C: sh          $t0, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r8;
L_80010120:
    // 0x80010120: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80010124: beq         $at, $zero, L_8001015C
    if (ctx->r1 == 0) {
        // 0x80010128: sw          $t1, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r9;
            goto L_8001015C;
    }
    // 0x80010128: sw          $t1, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r9;
    // 0x8001012C: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
L_80010130:
    // 0x80010130: lw          $t3, 0x0($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X0);
    // 0x80010134: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80010138: addu        $v0, $t3, $a0
    ctx->r2 = ADD32(ctx->r11, ctx->r4);
    // 0x8001013C: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x80010140: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80010144: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80010148: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8001014C: nop

    // 0x80010150: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80010154: bne         $at, $zero, L_80010130
    if (ctx->r1 != 0) {
        // 0x80010158: nop
    
            goto L_80010130;
    }
    // 0x80010158: nop

L_8001015C:
    // 0x8001015C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80010160: jal         0x800101AC
    // 0x80010164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    obj_destroy(rdram, ctx);
        goto after_0;
    // 0x80010164: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x80010168: lw          $t6, 0x0($s7)
    ctx->r14 = MEM_W(ctx->r23, 0X0);
    // 0x8001016C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80010170: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80010174: bne         $at, $zero, L_800100B8
    if (ctx->r1 != 0) {
        // 0x80010178: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800100B8;
    }
    // 0x80010178: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_8001017C:
    // 0x8001017C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80010180: sw          $zero, 0x0($s7)
    MEM_W(0X0, ctx->r23) = 0;
    // 0x80010184: lw          $s7, 0x30($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X30);
    // 0x80010188: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001018C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80010190: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80010194: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80010198: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001019C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800101A0: lw          $s6, 0x2C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X2C);
    // 0x800101A4: jr          $ra
    // 0x800101A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800101A8: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void video_delta_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007A974: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A978: sb          $zero, 0x6308($at)
    MEM_B(0X6308, ctx->r1) = 0;
    // 0x8007A97C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007A980: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8007A984: jr          $ra
    // 0x8007A988: sb          $t6, 0x6309($at)
    MEM_B(0X6309, ctx->r1) = ctx->r14;
    return;
    // 0x8007A988: sb          $t6, 0x6309($at)
    MEM_B(0X6309, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void mtx_cam_push(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_presentation_wave_matrix(uint8_t*, recomp_context*); dkr_presentation_wave_matrix(rdram, ctx);
    // 0x80069484: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80069488: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8006948C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80069490: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x80069494: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069498: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8006949C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800694A0: sw          $a2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r6;
    // 0x800694A4: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    // 0x800694A8: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    // 0x800694AC: jal         0x8006FC30
    // 0x800694B0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x800694B0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_0:
    // 0x800694B4: lwc1        $f0, 0x60($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X60);
    // 0x800694B8: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800694BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800694C0: c.eq.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl == ctx->f20.fl;
    // 0x800694C4: nop

    // 0x800694C8: bc1t        L_800694E0
    if (c1cs) {
        // 0x800694CC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800694E0;
    }
    // 0x800694CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800694D0: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x800694D4: jal         0x8006FE30
    // 0x800694D8: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    mtxf_translate_y(rdram, ctx);
        goto after_1;
    // 0x800694D8: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    after_1:
    // 0x800694DC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800694E0:
    // 0x800694E0: lwc1        $f0, 0x5C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800694E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800694E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800694EC: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x800694F0: nop

    // 0x800694F4: bc1t        L_80069508
    if (c1cs) {
        // 0x800694F8: nop
    
            goto L_80069508;
    }
    // 0x800694F8: nop

    // 0x800694FC: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x80069500: jal         0x8006FE04
    // 0x80069504: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    mtxf_scale_y(rdram, ctx);
        goto after_2;
    // 0x80069504: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    after_2:
L_80069508:
    // 0x80069508: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006950C: lw          $t6, 0xD1C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XD1C);
    // 0x80069510: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069514: addiu       $t8, $t8, 0xD70
    ctx->r24 = ADD32(ctx->r24, 0XD70);
    // 0x80069518: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8006951C: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80069520: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80069524: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x80069528: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006952C: jal         0x8006F768
    // 0x80069530: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    mtxf_mul(rdram, ctx);
        goto after_3;
    // 0x80069530: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    after_3:
    // 0x80069534: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80069538: addiu       $t0, $t0, 0xD1C
    ctx->r8 = ADD32(ctx->r8, 0XD1C);
    // 0x8006953C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80069540: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80069544: sll         $t3, $t9, 2
    ctx->r11 = S32(ctx->r25 << 2);
    // 0x80069548: addu        $a0, $a0, $t3
    ctx->r4 = ADD32(ctx->r4, ctx->r11);
    // 0x8006954C: lw          $a0, 0xD74($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD74);
    // 0x80069550: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069554: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80069558: addiu       $a2, $a2, 0x10A0
    ctx->r6 = ADD32(ctx->r6, 0X10A0);
    // 0x8006955C: jal         0x8006F768
    // 0x80069560: addiu       $a1, $a1, 0xF20
    ctx->r5 = ADD32(ctx->r5, 0XF20);
    mtxf_mul(rdram, ctx);
        goto after_4;
    // 0x80069560: addiu       $a1, $a1, 0xF20
    ctx->r5 = ADD32(ctx->r5, 0XF20);
    after_4:
    // 0x80069564: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80069568: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006956C: lw          $a1, 0x0($t4)
    ctx->r5 = MEM_W(ctx->r12, 0X0);
    // 0x80069570: jal         0x8006F870
    // 0x80069574: addiu       $a0, $a0, 0x10A0
    ctx->r4 = ADD32(ctx->r4, 0X10A0);
    mtxf_to_mtx(rdram, ctx);
        goto after_5;
    // 0x80069574: addiu       $a0, $a0, 0x10A0
    ctx->r4 = ADD32(ctx->r4, 0X10A0);
    after_5:
    // 0x80069578: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006957C: addiu       $t0, $t0, 0xD1C
    ctx->r8 = ADD32(ctx->r8, 0XD1C);
    // 0x80069580: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x80069584: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80069588: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8006958C: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x80069590: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x80069594: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x80069598: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006959C: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x800695A0: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800695A4: sw          $t7, 0xD88($at)
    MEM_W(0XD88, ctx->r1) = ctx->r15;
    // 0x800695A8: lw          $v1, 0x0($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X0);
    // 0x800695AC: lui         $t3, 0x140
    ctx->r11 = S32(0X140 << 16);
    // 0x800695B0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800695B4: ori         $t3, $t3, 0x40
    ctx->r11 = ctx->r11 | 0X40;
    // 0x800695B8: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800695BC: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800695C0: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x800695C4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800695C8: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800695CC: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800695D0: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800695D4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800695D8: addiu       $t7, $t6, 0x40
    ctx->r15 = ADD32(ctx->r14, 0X40);
    // 0x800695DC: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x800695E0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800695E4: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x800695E8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800695EC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x800695F0: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x800695F4: addiu       $t4, $sp, 0x48
    ctx->r12 = ADD32(ctx->r29, 0X48);
    // 0x800695F8: addiu       $t3, $sp, 0x4C
    ctx->r11 = ADD32(ctx->r29, 0X4C);
    // 0x800695FC: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80069600: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80069604: mfc1        $a3, $f20
    ctx->r7 = (int32_t)ctx->f20.u32l;
    // 0x80069608: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8006960C: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x80069610: jal         0x8006F64C
    // 0x80069614: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    mtxf_transform_point(rdram, ctx);
        goto after_6;
    // 0x80069614: sw          $t5, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r13;
    after_6:
    // 0x80069618: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006961C: lb          $t6, 0xD14($t6)
    ctx->r14 = MEM_B(ctx->r14, 0XD14);
    // 0x80069620: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80069624: lw          $v1, 0xCE4($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XCE4);
    // 0x80069628: beq         $t6, $zero, L_80069634
    if (ctx->r14 == 0) {
        // 0x8006962C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_80069634;
    }
    // 0x8006962C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80069630: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80069634:
    // 0x80069634: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80069638: addu        $t7, $t7, $v1
    ctx->r15 = ADD32(ctx->r15, ctx->r3);
    // 0x8006963C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069640: addiu       $t8, $t8, 0xAC0
    ctx->r24 = ADD32(ctx->r24, 0XAC0);
    // 0x80069644: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069648: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x8006964C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80069650: lwc1        $f8, 0x4C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80069654: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80069658: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8006965C: lwc1        $f18, 0x48($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80069660: lwc1        $f8, 0x44($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80069664: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80069668: swc1        $f10, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f10.u32l;
    // 0x8006966C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80069670: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x80069674: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80069678: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x8006967C: swc1        $f10, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f10.u32l;
    // 0x80069680: lh          $t9, 0x0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X0);
    // 0x80069684: addiu       $a1, $a1, 0xCF0
    ctx->r5 = ADD32(ctx->r5, 0XCF0);
    // 0x80069688: negu        $t3, $t9
    ctx->r11 = SUB32(0, ctx->r25);
    // 0x8006968C: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x80069690: lh          $t4, 0x2($a2)
    ctx->r12 = MEM_H(ctx->r6, 0X2);
    // 0x80069694: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069698: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x8006969C: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x800696A0: lh          $t6, 0x4($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X4);
    // 0x800696A4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800696A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800696AC: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800696B0: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
    // 0x800696B4: swc1        $f20, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f20.u32l;
    // 0x800696B8: swc1        $f20, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f20.u32l;
    // 0x800696BC: swc1        $f20, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f20.u32l;
    // 0x800696C0: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    // 0x800696C4: jal         0x8006FE74
    // 0x800696C8: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_7;
    // 0x800696C8: swc1        $f16, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f16.u32l;
    after_7:
    // 0x800696CC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800696D0: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800696D4: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x800696D8: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x800696DC: addiu       $t8, $sp, 0x4C
    ctx->r24 = ADD32(ctx->r29, 0X4C);
    // 0x800696E0: addiu       $t9, $sp, 0x48
    ctx->r25 = ADD32(ctx->r29, 0X48);
    // 0x800696E4: addiu       $t3, $sp, 0x44
    ctx->r11 = ADD32(ctx->r29, 0X44);
    // 0x800696E8: sw          $t3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r11;
    // 0x800696EC: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x800696F0: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800696F4: jal         0x8006F64C
    // 0x800696F8: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    mtxf_transform_point(rdram, ctx);
        goto after_8;
    // 0x800696F8: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    after_8:
    // 0x800696FC: lw          $t4, 0x58($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X58);
    // 0x80069700: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80069704: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80069708: lwc1        $f4, 0x8($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X8);
    // 0x8006970C: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80069710: div.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80069714: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80069718: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006971C: addiu       $a0, $a0, 0xD20
    ctx->r4 = ADD32(ctx->r4, 0XD20);
    // 0x80069720: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80069724: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80069728: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8006972C: sll         $v0, $t6, 2
    ctx->r2 = S32(ctx->r14 << 2);
    // 0x80069730: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069734: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80069738: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x8006973C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80069740: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80069744: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80069748: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8006974C: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80069750: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    // 0x80069754: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80069758: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8006975C: swc1        $f16, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f16.u32l;
    // 0x80069760: swc1        $f6, 0xD28($at)
    MEM_W(0XD28, ctx->r1) = ctx->f6.u32l;
    // 0x80069764: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80069768: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006976C: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80069770: swc1        $f4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f4.u32l;
    // 0x80069774: swc1        $f8, 0xD40($at)
    MEM_W(0XD40, ctx->r1) = ctx->f8.u32l;
    // 0x80069778: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x8006977C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069780: addu        $at, $at, $v0
    ctx->r1 = ADD32(ctx->r1, ctx->r2);
    // 0x80069784: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x80069788: jr          $ra
    // 0x8006978C: swc1        $f10, 0xD58($at)
    MEM_W(0XD58, ctx->r1) = ctx->f10.u32l;
    return;
    // 0x8006978C: swc1        $f10, 0xD58($at)
    MEM_W(0XD58, ctx->r1) = ctx->f10.u32l;
;}
RECOMP_FUNC void func_8000E4E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E4E8: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x8000E4EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000E4F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000E4F4: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8000E4F8: addiu       $t6, $t6, -0x5160
    ctx->r14 = ADD32(ctx->r14, -0X5160);
    // 0x8000E4FC: lw          $v0, -0x5150($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5150);
    // 0x8000E500: addu        $a1, $v1, $t6
    ctx->r5 = ADD32(ctx->r3, ctx->r14);
    // 0x8000E504: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8000E508: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000E50C: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8000E510: sw          $zero, 0x8($v0)
    MEM_W(0X8, ctx->r2) = 0;
    // 0x8000E514: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000E518: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8000E51C: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8000E520: lw          $t9, -0x5168($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5168);
    // 0x8000E524: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8000E528: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
    // 0x8000E52C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8000E530: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
L_8000E534:
    // 0x8000E534: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8000E538: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x8000E53C: sb          $zero, 0x1($t0)
    MEM_B(0X1, ctx->r8) = 0;
    // 0x8000E540: sb          $zero, 0x2($t0)
    MEM_B(0X2, ctx->r8) = 0;
    // 0x8000E544: sb          $zero, 0x3($t0)
    MEM_B(0X3, ctx->r8) = 0;
    // 0x8000E548: bne         $a3, $v0, L_8000E534
    if (ctx->r7 != ctx->r2) {
        // 0x8000E54C: addiu       $t0, $t0, 0x4
        ctx->r8 = ADD32(ctx->r8, 0X4);
            goto L_8000E534;
    }
    // 0x8000E54C: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x8000E550: jr          $ra
    // 0x8000E554: nop

    return;
    // 0x8000E554: nop

;}
RECOMP_FUNC void func_800BC6C8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BC6C8: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BC6CC: addiu       $t2, $t2, -0x6038
    ctx->r10 = ADD32(ctx->r10, -0X6038);
    // 0x800BC6D0: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BC6D4: addiu       $t6, $zero, 0x4000
    ctx->r14 = ADD32(0, 0X4000);
    // 0x800BC6D8: div         $zero, $t6, $a2
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r6)));
    // 0x800BC6DC: addiu       $sp, $sp, -0x248
    ctx->r29 = ADD32(ctx->r29, -0X248);
    // 0x800BC6E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BC6E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BC6E8: bne         $a2, $zero, L_800BC6F4
    if (ctx->r6 != 0) {
        // 0x800BC6EC: nop
    
            goto L_800BC6F4;
    }
    // 0x800BC6EC: nop

    // 0x800BC6F0: break       7
    do_break(2148255472);
L_800BC6F4:
    // 0x800BC6F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BC6F8: bne         $a2, $at, L_800BC70C
    if (ctx->r6 != ctx->r1) {
        // 0x800BC6FC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BC70C;
    }
    // 0x800BC6FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BC700: bne         $t6, $at, L_800BC70C
    if (ctx->r14 != ctx->r1) {
        // 0x800BC704: nop
    
            goto L_800BC70C;
    }
    // 0x800BC704: nop

    // 0x800BC708: break       6
    do_break(2148255496);
L_800BC70C:
    // 0x800BC70C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BC710: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BC714: mflo        $v0
    ctx->r2 = lo;
    // 0x800BC718: blez        $a2, L_800BC770
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BC71C: addiu       $a1, $sp, 0x34
        ctx->r5 = ADD32(ctx->r29, 0X34);
            goto L_800BC770;
    }
    // 0x800BC71C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
L_800BC720:
    // 0x800BC720: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800BC724: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800BC728: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800BC72C: sw          $v0, 0x234($sp)
    MEM_W(0X234, ctx->r29) = ctx->r2;
    // 0x800BC730: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x800BC734: jal         0x800707C4
    // 0x800BC738: sw          $t3, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r11;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x800BC738: sw          $t3, 0x244($sp)
    MEM_W(0X244, ctx->r29) = ctx->r11;
    after_0:
    // 0x800BC73C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800BC740: lw          $t3, 0x244($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X244);
    // 0x800BC744: addiu       $t2, $t2, -0x6038
    ctx->r10 = ADD32(ctx->r10, -0X6038);
    // 0x800BC748: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BC74C: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x800BC750: lw          $v0, 0x234($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X234);
    // 0x800BC754: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BC758: slt         $at, $t3, $a2
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BC75C: swc1        $f0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f0.u32l;
    // 0x800BC760: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800BC764: bne         $at, $zero, L_800BC720
    if (ctx->r1 != 0) {
        // 0x800BC768: addu        $s0, $s0, $v0
        ctx->r16 = ADD32(ctx->r16, ctx->r2);
            goto L_800BC720;
    }
    // 0x800BC768: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800BC76C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BC770:
    // 0x800BC770: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800BC774: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BC778: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BC77C: addiu       $t4, $sp, 0x34
    ctx->r12 = ADD32(ctx->r29, 0X34);
    // 0x800BC780: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800BC784: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800BC788: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x800BC78C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800BC790: bltz        $a2, L_800BC7E8
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC794: swc1        $f0, 0x0($t9)
        MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
            goto L_800BC7E8;
    }
    // 0x800BC794: swc1        $f0, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f0.u32l;
    // 0x800BC798: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BC79C: addiu       $t1, $t1, 0x304C
    ctx->r9 = ADD32(ctx->r9, 0X304C);
L_800BC7A0:
    // 0x800BC7A0: bltz        $a2, L_800BC7D0
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC7A4: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BC7D0;
    }
    // 0x800BC7A4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BC7A8: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
L_800BC7AC:
    // 0x800BC7AC: lw          $t5, 0x10($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X10);
    // 0x800BC7B0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BC7B4: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800BC7B8: swc1        $f0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f0.u32l;
    // 0x800BC7BC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BC7C0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC7C4: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC7C8: beq         $at, $zero, L_800BC7AC
    if (ctx->r1 == 0) {
        // 0x800BC7CC: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BC7AC;
    }
    // 0x800BC7CC: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BC7D0:
    // 0x800BC7D0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BC7D4: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BC7D8: beq         $at, $zero, L_800BC7A0
    if (ctx->r1 == 0) {
        // 0x800BC7DC: nop
    
            goto L_800BC7A0;
    }
    // 0x800BC7DC: nop

    // 0x800BC7E0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BC7E4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BC7E8:
    // 0x800BC7E8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BC7EC: bltz        $a2, L_800BC848
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC7F0: addiu       $t1, $t1, 0x304C
        ctx->r9 = ADD32(ctx->r9, 0X304C);
            goto L_800BC848;
    }
    // 0x800BC7F0: addiu       $t1, $t1, 0x304C
    ctx->r9 = ADD32(ctx->r9, 0X304C);
L_800BC7F4:
    // 0x800BC7F4: bltz        $a2, L_800BC830
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC7F8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BC830;
    }
    // 0x800BC7F8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BC7FC: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800BC800: addu        $a1, $t4, $t7
    ctx->r5 = ADD32(ctx->r12, ctx->r15);
    // 0x800BC804: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
L_800BC808:
    // 0x800BC808: lw          $t8, 0x4($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X4);
    // 0x800BC80C: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BC810: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800BC814: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x800BC818: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BC81C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BC820: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC824: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC828: beq         $at, $zero, L_800BC808
    if (ctx->r1 == 0) {
        // 0x800BC82C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BC808;
    }
    // 0x800BC82C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BC830:
    // 0x800BC830: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BC834: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BC838: beq         $at, $zero, L_800BC7F4
    if (ctx->r1 == 0) {
        // 0x800BC83C: nop
    
            goto L_800BC7F4;
    }
    // 0x800BC83C: nop

    // 0x800BC840: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BC844: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BC848:
    // 0x800BC848: bltz        $a2, L_800BC8A4
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC84C: nop
    
            goto L_800BC8A4;
    }
    // 0x800BC84C: nop

L_800BC850:
    // 0x800BC850: bltz        $a2, L_800BC88C
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC854: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BC88C;
    }
    // 0x800BC854: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BC858: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800BC85C: addiu       $a0, $sp, 0x34
    ctx->r4 = ADD32(ctx->r29, 0X34);
L_800BC860:
    // 0x800BC860: lw          $t5, 0xC($t1)
    ctx->r13 = MEM_W(ctx->r9, 0XC);
    // 0x800BC864: lwc1        $f8, 0x0($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X0);
    // 0x800BC868: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800BC86C: swc1        $f8, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f8.u32l;
    // 0x800BC870: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BC874: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BC878: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC87C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC880: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800BC884: beq         $at, $zero, L_800BC860
    if (ctx->r1 == 0) {
        // 0x800BC888: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800BC860;
    }
    // 0x800BC888: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
L_800BC88C:
    // 0x800BC88C: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BC890: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BC894: beq         $at, $zero, L_800BC850
    if (ctx->r1 == 0) {
        // 0x800BC898: nop
    
            goto L_800BC850;
    }
    // 0x800BC898: nop

    // 0x800BC89C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BC8A0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BC8A4:
    // 0x800BC8A4: bltz        $a2, L_800BC910
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC8A8: nop
    
            goto L_800BC910;
    }
    // 0x800BC8A8: nop

L_800BC8AC:
    // 0x800BC8AC: bltz        $a2, L_800BC8F8
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC8B0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BC8F8;
    }
    // 0x800BC8B0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BC8B4: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800BC8B8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BC8BC:
    // 0x800BC8BC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800BC8C0: addu        $t8, $t4, $t7
    ctx->r24 = ADD32(ctx->r12, ctx->r15);
    // 0x800BC8C4: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
    // 0x800BC8C8: lw          $t6, 0x14($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X14);
    // 0x800BC8CC: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x800BC8D0: lwc1        $f10, 0x0($t5)
    ctx->f10.u32l = MEM_W(ctx->r13, 0X0);
    // 0x800BC8D4: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x800BC8D8: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x800BC8DC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BC8E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BC8E4: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC8E8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC8EC: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BC8F0: beq         $at, $zero, L_800BC8BC
    if (ctx->r1 == 0) {
        // 0x800BC8F4: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BC8BC;
    }
    // 0x800BC8F4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BC8F8:
    // 0x800BC8F8: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BC8FC: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BC900: beq         $at, $zero, L_800BC8AC
    if (ctx->r1 == 0) {
        // 0x800BC904: nop
    
            goto L_800BC8AC;
    }
    // 0x800BC904: nop

    // 0x800BC908: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BC90C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800BC910:
    // 0x800BC910: bltz        $a2, L_800BC974
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC914: nop
    
            goto L_800BC974;
    }
    // 0x800BC914: nop

L_800BC918:
    // 0x800BC918: bltz        $a2, L_800BC960
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC91C: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BC960;
    }
    // 0x800BC91C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BC920: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BC924: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
L_800BC928:
    // 0x800BC928: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800BC92C: addu        $t9, $t4, $t8
    ctx->r25 = ADD32(ctx->r12, ctx->r24);
    // 0x800BC930: negu        $t5, $a3
    ctx->r13 = SUB32(0, ctx->r7);
    // 0x800BC934: lw          $t7, 0x1C($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X1C);
    // 0x800BC938: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800BC93C: lwc1        $f16, 0x0($t6)
    ctx->f16.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BC940: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800BC944: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800BC948: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BC94C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BC950: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC954: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BC958: beq         $at, $zero, L_800BC928
    if (ctx->r1 == 0) {
        // 0x800BC95C: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BC928;
    }
    // 0x800BC95C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BC960:
    // 0x800BC960: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BC964: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BC968: beq         $at, $zero, L_800BC918
    if (ctx->r1 == 0) {
        // 0x800BC96C: nop
    
            goto L_800BC918;
    }
    // 0x800BC96C: nop

    // 0x800BC970: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BC974:
    // 0x800BC974: bltz        $a2, L_800BCA10
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BC978: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCA10;
    }
    // 0x800BC978: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BC97C:
    // 0x800BC97C: bne         $at, $zero, L_800BC9FC
    if (ctx->r1 != 0) {
        // 0x800BC980: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BC9FC;
    }
    // 0x800BC980: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BC984: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BC988: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800BC98C: addu        $a1, $a3, $t9
    ctx->r5 = ADD32(ctx->r7, ctx->r25);
    // 0x800BC990: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BC994: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BC998:
    // 0x800BC998: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC99C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800BC9A0: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BC9A4: mflo        $t7
    ctx->r15 = lo;
    // 0x800BC9A8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BC9AC: addu        $t9, $t5, $t8
    ctx->r25 = ADD32(ctx->r13, ctx->r24);
    // 0x800BC9B0: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x800BC9B4: swc1        $f18, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f18.u32l;
    // 0x800BC9B8: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x800BC9BC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BC9C0: addiu       $t8, $t5, 0x1
    ctx->r24 = ADD32(ctx->r13, 0X1);
    // 0x800BC9C4: multu       $v1, $t8
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BC9C8: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BC9CC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BC9D0: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BC9D4: mflo        $t9
    ctx->r25 = lo;
    // 0x800BC9D8: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BC9DC: addu        $t5, $t7, $t6
    ctx->r13 = ADD32(ctx->r15, ctx->r14);
    // 0x800BC9E0: addu        $t8, $t5, $a3
    ctx->r24 = ADD32(ctx->r13, ctx->r7);
    // 0x800BC9E4: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800BC9E8: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BC9EC: nop

    // 0x800BC9F0: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BC9F4: beq         $at, $zero, L_800BC998
    if (ctx->r1 == 0) {
        // 0x800BC9F8: addiu       $t6, $a2, 0x1
        ctx->r14 = ADD32(ctx->r6, 0X1);
            goto L_800BC998;
    }
    // 0x800BC9F8: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BC9FC:
    // 0x800BC9FC: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCA00: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCA04: beq         $at, $zero, L_800BC97C
    if (ctx->r1 == 0) {
        // 0x800BCA08: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BC97C;
    }
    // 0x800BCA08: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCA0C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCA10:
    // 0x800BCA10: bltz        $a2, L_800BCAC4
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCA14: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCAC4;
    }
    // 0x800BCA14: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BCA18:
    // 0x800BCA18: bne         $at, $zero, L_800BCAB0
    if (ctx->r1 != 0) {
        // 0x800BCA1C: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BCAB0;
    }
    // 0x800BCA1C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BCA20: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCA24: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800BCA28: addu        $a1, $a3, $t9
    ctx->r5 = ADD32(ctx->r7, ctx->r25);
    // 0x800BCA2C: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BCA30: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BCA34:
    // 0x800BCA34: multu       $t3, $t6
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCA38: lw          $t7, 0x8($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X8);
    // 0x800BCA3C: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800BCA40: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCA44: mflo        $t5
    ctx->r13 = lo;
    // 0x800BCA48: sll         $t8, $t5, 2
    ctx->r24 = S32(ctx->r13 << 2);
    // 0x800BCA4C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800BCA50: addu        $t5, $t9, $t6
    ctx->r13 = ADD32(ctx->r25, ctx->r14);
    // 0x800BCA54: negu        $t7, $a0
    ctx->r15 = SUB32(0, ctx->r4);
    // 0x800BCA58: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800BCA5C: swc1        $f6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f6.u32l;
    // 0x800BCA60: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCA64: lw          $t9, 0x8($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X8);
    // 0x800BCA68: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
    // 0x800BCA6C: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCA70: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800BCA74: lwc1        $f8, 0x0($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCA78: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCA7C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BCA80: mflo        $t5
    ctx->r13 = lo;
    // 0x800BCA84: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800BCA88: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x800BCA8C: addu        $t5, $t8, $t6
    ctx->r13 = ADD32(ctx->r24, ctx->r14);
    // 0x800BCA90: negu        $t9, $a3
    ctx->r25 = SUB32(0, ctx->r7);
    // 0x800BCA94: addu        $t7, $t5, $t9
    ctx->r15 = ADD32(ctx->r13, ctx->r25);
    // 0x800BCA98: swc1        $f8, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f8.u32l;
    // 0x800BCA9C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCAA0: nop

    // 0x800BCAA4: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCAA8: beq         $at, $zero, L_800BCA34
    if (ctx->r1 == 0) {
        // 0x800BCAAC: addiu       $t6, $a2, 0x1
        ctx->r14 = ADD32(ctx->r6, 0X1);
            goto L_800BCA34;
    }
    // 0x800BCAAC: addiu       $t6, $a2, 0x1
    ctx->r14 = ADD32(ctx->r6, 0X1);
L_800BCAB0:
    // 0x800BCAB0: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCAB4: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCAB8: beq         $at, $zero, L_800BCA18
    if (ctx->r1 == 0) {
        // 0x800BCABC: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCA18;
    }
    // 0x800BCABC: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCAC0: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCAC4:
    // 0x800BCAC4: bltz        $a2, L_800BCB88
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCAC8: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCB88;
    }
    // 0x800BCAC8: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BCACC:
    // 0x800BCACC: bne         $at, $zero, L_800BCB74
    if (ctx->r1 != 0) {
        // 0x800BCAD0: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BCB74;
    }
    // 0x800BCAD0: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BCAD4: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCAD8: addiu       $t8, $sp, 0x34
    ctx->r24 = ADD32(ctx->r29, 0X34);
    // 0x800BCADC: addu        $a1, $a3, $t8
    ctx->r5 = ADD32(ctx->r7, ctx->r24);
    // 0x800BCAE0: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BCAE4: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BCAE8:
    // 0x800BCAE8: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCAEC: lw          $t6, 0x18($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X18);
    // 0x800BCAF0: lwc1        $f10, 0x0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCAF4: mflo        $t5
    ctx->r13 = lo;
    // 0x800BCAF8: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x800BCAFC: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800BCB00: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCB04: mflo        $t8
    ctx->r24 = lo;
    // 0x800BCB08: negu        $at, $t8
    ctx->r1 = SUB32(0, ctx->r24);
    // 0x800BCB0C: sll         $t5, $at, 2
    ctx->r13 = S32(ctx->r1 << 2);
    // 0x800BCB10: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x800BCB14: addu        $t9, $t6, $a0
    ctx->r25 = ADD32(ctx->r14, ctx->r4);
    // 0x800BCB18: swc1        $f10, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f10.u32l;
    // 0x800BCB1C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCB20: lw          $t8, 0x18($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X18);
    // 0x800BCB24: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800BCB28: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCB2C: lwc1        $f16, 0x0($a1)
    ctx->f16.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCB30: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BCB34: mflo        $t7
    ctx->r15 = lo;
    // 0x800BCB38: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x800BCB3C: addu        $t6, $t8, $t5
    ctx->r14 = ADD32(ctx->r24, ctx->r13);
    // 0x800BCB40: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCB44: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCB48: mflo        $t9
    ctx->r25 = lo;
    // 0x800BCB4C: negu        $at, $t9
    ctx->r1 = SUB32(0, ctx->r25);
    // 0x800BCB50: sll         $t7, $at, 2
    ctx->r15 = S32(ctx->r1 << 2);
    // 0x800BCB54: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800BCB58: addu        $t5, $t8, $a3
    ctx->r13 = ADD32(ctx->r24, ctx->r7);
    // 0x800BCB5C: swc1        $f16, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->f16.u32l;
    // 0x800BCB60: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCB64: nop

    // 0x800BCB68: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCB6C: beq         $at, $zero, L_800BCAE8
    if (ctx->r1 == 0) {
        // 0x800BCB70: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_800BCAE8;
    }
    // 0x800BCB70: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BCB74:
    // 0x800BCB74: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCB78: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCB7C: beq         $at, $zero, L_800BCACC
    if (ctx->r1 == 0) {
        // 0x800BCB80: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCACC;
    }
    // 0x800BCB80: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCB84: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_800BCB88:
    // 0x800BCB88: bltz        $a2, L_800BCC60
    if (SIGNED(ctx->r6) < 0) {
        // 0x800BCB8C: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCC60;
    }
    // 0x800BCB8C: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BCB90:
    // 0x800BCB90: bne         $at, $zero, L_800BCC50
    if (ctx->r1 != 0) {
        // 0x800BCB94: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_800BCC50;
    }
    // 0x800BCB94: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800BCB98: sll         $a3, $t3, 2
    ctx->r7 = S32(ctx->r11 << 2);
    // 0x800BCB9C: addiu       $t9, $sp, 0x34
    ctx->r25 = ADD32(ctx->r29, 0X34);
    // 0x800BCBA0: addu        $a1, $a3, $t9
    ctx->r5 = ADD32(ctx->r7, ctx->r25);
    // 0x800BCBA4: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x800BCBA8: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BCBAC:
    // 0x800BCBAC: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCBB0: lw          $t6, 0x20($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X20);
    // 0x800BCBB4: lwc1        $f18, 0x0($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCBB8: mflo        $t7
    ctx->r15 = lo;
    // 0x800BCBBC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BCBC0: addu        $t5, $t6, $t8
    ctx->r13 = ADD32(ctx->r14, ctx->r24);
    // 0x800BCBC4: multu       $t3, $v0
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCBC8: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x800BCBCC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BCBD0: negu        $at, $t9
    ctx->r1 = SUB32(0, ctx->r25);
    // 0x800BCBD4: sll         $t7, $at, 2
    ctx->r15 = S32(ctx->r1 << 2);
    // 0x800BCBD8: addu        $t6, $t5, $t7
    ctx->r14 = ADD32(ctx->r13, ctx->r15);
    // 0x800BCBDC: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800BCBE0: negu        $t5, $a0
    ctx->r13 = SUB32(0, ctx->r4);
    // 0x800BCBE4: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x800BCBE8: swc1        $f18, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f18.u32l;
    // 0x800BCBEC: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCBF0: lw          $t6, 0x20($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X20);
    // 0x800BCBF4: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
    // 0x800BCBF8: multu       $a2, $v0
    result = U64(U32(ctx->r6)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCBFC: lwc1        $f4, 0x0($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BCC00: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BCC04: mflo        $t8
    ctx->r24 = lo;
    // 0x800BCC08: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BCC0C: addu        $t5, $t6, $t9
    ctx->r13 = ADD32(ctx->r14, ctx->r25);
    // 0x800BCC10: multu       $v1, $v0
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCC14: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800BCC18: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BCC1C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BCC20: negu        $at, $t7
    ctx->r1 = SUB32(0, ctx->r15);
    // 0x800BCC24: sll         $t8, $at, 2
    ctx->r24 = S32(ctx->r1 << 2);
    // 0x800BCC28: addu        $t6, $t5, $t8
    ctx->r14 = ADD32(ctx->r13, ctx->r24);
    // 0x800BCC2C: addu        $t7, $t6, $t9
    ctx->r15 = ADD32(ctx->r14, ctx->r25);
    // 0x800BCC30: negu        $t5, $a3
    ctx->r13 = SUB32(0, ctx->r7);
    // 0x800BCC34: addu        $t8, $t7, $t5
    ctx->r24 = ADD32(ctx->r15, ctx->r13);
    // 0x800BCC38: swc1        $f4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f4.u32l;
    // 0x800BCC3C: lw          $a2, 0x0($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X0);
    // 0x800BCC40: nop

    // 0x800BCC44: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BCC48: beq         $at, $zero, L_800BCBAC
    if (ctx->r1 == 0) {
        // 0x800BCC4C: addiu       $v0, $a2, 0x1
        ctx->r2 = ADD32(ctx->r6, 0X1);
            goto L_800BCBAC;
    }
    // 0x800BCC4C: addiu       $v0, $a2, 0x1
    ctx->r2 = ADD32(ctx->r6, 0X1);
L_800BCC50:
    // 0x800BCC50: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x800BCC54: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BCC58: beq         $at, $zero, L_800BCB90
    if (ctx->r1 == 0) {
        // 0x800BCC5C: slt         $at, $a2, $t3
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
            goto L_800BCB90;
    }
    // 0x800BCC5C: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
L_800BCC60:
    // 0x800BCC60: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800BCC64: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800BCC68: jr          $ra
    // 0x800BCC6C: addiu       $sp, $sp, 0x248
    ctx->r29 = ADD32(ctx->r29, 0X248);
    return;
    // 0x800BCC6C: addiu       $sp, $sp, 0x248
    ctx->r29 = ADD32(ctx->r29, 0X248);
;}
RECOMP_FUNC void search_level_properties_forwards(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006AC00: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8006AC04: sll         $t6, $a1, 24
    ctx->r14 = S32(ctx->r5 << 24);
    // 0x8006AC08: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8006AC0C: sll         $t8, $a2, 24
    ctx->r24 = S32(ctx->r6 << 24);
    // 0x8006AC10: sra         $a2, $t8, 24
    ctx->r6 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8006AC14: bgez        $a0, L_8006AC24
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006AC18: sra         $a1, $t6, 24
        ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
            goto L_8006AC24;
    }
    // 0x8006AC18: sra         $a1, $t6, 24
    ctx->r5 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006AC1C: b           L_8006AC28
    // 0x8006AC20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
        goto L_8006AC28;
    // 0x8006AC20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8006AC24:
    // 0x8006AC24: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
L_8006AC28:
    // 0x8006AC28: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8006AC2C: beq         $a1, $at, L_8006AD5C
    if (ctx->r5 == ctx->r1) {
        // 0x8006AC30: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8006AD5C;
    }
    // 0x8006AC30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006AC34: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8006AC38: bne         $a2, $v0, L_8006AC98
    if (ctx->r6 != ctx->r2) {
        // 0x8006AC3C: nop
    
            goto L_8006AC98;
    }
    // 0x8006AC3C: nop

    // 0x8006AC40: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AC44: lw          $v0, 0x1170($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1170);
    // 0x8006AC48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AC4C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AC50: beq         $at, $zero, L_8006AE20
    if (ctx->r1 == 0) {
        // 0x8006AC54: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_8006AE20;
    }
    // 0x8006AC54: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006AC58: lw          $t0, 0x117C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X117C);
    // 0x8006AC5C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006AC60: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006AC64: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8006AC68:
    // 0x8006AC68: lb          $t2, 0x1($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X1);
    // 0x8006AC6C: nop

    // 0x8006AC70: bne         $a1, $t2, L_8006AC80
    if (ctx->r5 != ctx->r10) {
        // 0x8006AC74: nop
    
            goto L_8006AC80;
    }
    // 0x8006AC74: nop

    // 0x8006AC78: jr          $ra
    // 0x8006AC7C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AC7C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AC80:
    // 0x8006AC80: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AC84: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AC88: bne         $at, $zero, L_8006AC68
    if (ctx->r1 != 0) {
        // 0x8006AC8C: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AC68;
    }
    // 0x8006AC8C: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AC90: b           L_8006AE24
    // 0x8006AC94: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006AE24;
    // 0x8006AC94: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AC98:
    // 0x8006AC98: bne         $a1, $v0, L_8006ACF4
    if (ctx->r5 != ctx->r2) {
        // 0x8006AC9C: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006ACF4;
    }
    // 0x8006AC9C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ACA0: lw          $v0, 0x1170($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1170);
    // 0x8006ACA4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8006ACA8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006ACAC: beq         $at, $zero, L_8006AE20
    if (ctx->r1 == 0) {
        // 0x8006ACB0: sll         $t4, $a0, 2
        ctx->r12 = S32(ctx->r4 << 2);
            goto L_8006AE20;
    }
    // 0x8006ACB0: sll         $t4, $a0, 2
    ctx->r12 = S32(ctx->r4 << 2);
    // 0x8006ACB4: lw          $t3, 0x117C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X117C);
    // 0x8006ACB8: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x8006ACBC: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006ACC0: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
L_8006ACC4:
    // 0x8006ACC4: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x8006ACC8: nop

    // 0x8006ACCC: bne         $a2, $t5, L_8006ACDC
    if (ctx->r6 != ctx->r13) {
        // 0x8006ACD0: nop
    
            goto L_8006ACDC;
    }
    // 0x8006ACD0: nop

    // 0x8006ACD4: jr          $ra
    // 0x8006ACD8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006ACD8: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006ACDC:
    // 0x8006ACDC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006ACE0: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006ACE4: bne         $at, $zero, L_8006ACC4
    if (ctx->r1 != 0) {
        // 0x8006ACE8: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006ACC4;
    }
    // 0x8006ACE8: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006ACEC: b           L_8006AE24
    // 0x8006ACF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006AE24;
    // 0x8006ACF0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006ACF4:
    // 0x8006ACF4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ACF8: lw          $v0, 0x1170($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1170);
    // 0x8006ACFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006AD00: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AD04: beq         $at, $zero, L_8006AE20
    if (ctx->r1 == 0) {
        // 0x8006AD08: sll         $t7, $a0, 2
        ctx->r15 = S32(ctx->r4 << 2);
            goto L_8006AE20;
    }
    // 0x8006AD08: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x8006AD0C: lw          $t6, 0x117C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X117C);
    // 0x8006AD10: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8006AD14: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x8006AD18: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
L_8006AD1C:
    // 0x8006AD1C: lb          $t8, 0x1($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X1);
    // 0x8006AD20: nop

    // 0x8006AD24: bne         $a1, $t8, L_8006AD44
    if (ctx->r5 != ctx->r24) {
        // 0x8006AD28: nop
    
            goto L_8006AD44;
    }
    // 0x8006AD28: nop

    // 0x8006AD2C: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x8006AD30: nop

    // 0x8006AD34: bne         $a2, $t9, L_8006AD44
    if (ctx->r6 != ctx->r25) {
        // 0x8006AD38: nop
    
            goto L_8006AD44;
    }
    // 0x8006AD38: nop

    // 0x8006AD3C: jr          $ra
    // 0x8006AD40: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AD40: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AD44:
    // 0x8006AD44: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AD48: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AD4C: bne         $at, $zero, L_8006AD1C
    if (ctx->r1 != 0) {
        // 0x8006AD50: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AD1C;
    }
    // 0x8006AD50: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006AD54: b           L_8006AE24
    // 0x8006AD58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006AE24;
    // 0x8006AD58: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AD5C:
    // 0x8006AD5C: bne         $a2, $v0, L_8006ADBC
    if (ctx->r6 != ctx->r2) {
        // 0x8006AD60: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8006ADBC;
    }
    // 0x8006AD60: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006AD64: lw          $v0, 0x1170($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1170);
    // 0x8006AD68: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8006AD6C: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AD70: beq         $at, $zero, L_8006AE20
    if (ctx->r1 == 0) {
        // 0x8006AD74: sll         $t1, $a0, 2
        ctx->r9 = S32(ctx->r4 << 2);
            goto L_8006AE20;
    }
    // 0x8006AD74: sll         $t1, $a0, 2
    ctx->r9 = S32(ctx->r4 << 2);
    // 0x8006AD78: lw          $t0, 0x117C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X117C);
    // 0x8006AD7C: subu        $t1, $t1, $a0
    ctx->r9 = SUB32(ctx->r9, ctx->r4);
    // 0x8006AD80: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8006AD84: addu        $v1, $t0, $t1
    ctx->r3 = ADD32(ctx->r8, ctx->r9);
L_8006AD88:
    // 0x8006AD88: lb          $t2, 0x1($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X1);
    // 0x8006AD8C: nop

    // 0x8006AD90: andi        $t3, $t2, 0x40
    ctx->r11 = ctx->r10 & 0X40;
    // 0x8006AD94: beq         $t3, $zero, L_8006ADA4
    if (ctx->r11 == 0) {
        // 0x8006AD98: nop
    
            goto L_8006ADA4;
    }
    // 0x8006AD98: nop

    // 0x8006AD9C: jr          $ra
    // 0x8006ADA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006ADA0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006ADA4:
    // 0x8006ADA4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006ADA8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006ADAC: bne         $at, $zero, L_8006AD88
    if (ctx->r1 != 0) {
        // 0x8006ADB0: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006AD88;
    }
    // 0x8006ADB0: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
    // 0x8006ADB4: b           L_8006AE24
    // 0x8006ADB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_8006AE24;
    // 0x8006ADB8: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006ADBC:
    // 0x8006ADBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006ADC0: lw          $v0, 0x1170($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1170);
    // 0x8006ADC4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8006ADC8: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006ADCC: beq         $at, $zero, L_8006AE20
    if (ctx->r1 == 0) {
        // 0x8006ADD0: sll         $t5, $a0, 2
        ctx->r13 = S32(ctx->r4 << 2);
            goto L_8006AE20;
    }
    // 0x8006ADD0: sll         $t5, $a0, 2
    ctx->r13 = S32(ctx->r4 << 2);
    // 0x8006ADD4: lw          $t4, 0x117C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X117C);
    // 0x8006ADD8: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x8006ADDC: sll         $t5, $t5, 1
    ctx->r13 = S32(ctx->r13 << 1);
    // 0x8006ADE0: addu        $v1, $t4, $t5
    ctx->r3 = ADD32(ctx->r12, ctx->r13);
L_8006ADE4:
    // 0x8006ADE4: lb          $t6, 0x1($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1);
    // 0x8006ADE8: nop

    // 0x8006ADEC: andi        $t7, $t6, 0x40
    ctx->r15 = ctx->r14 & 0X40;
    // 0x8006ADF0: beq         $t7, $zero, L_8006AE10
    if (ctx->r15 == 0) {
        // 0x8006ADF4: nop
    
            goto L_8006AE10;
    }
    // 0x8006ADF4: nop

    // 0x8006ADF8: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x8006ADFC: nop

    // 0x8006AE00: bne         $a2, $t8, L_8006AE10
    if (ctx->r6 != ctx->r24) {
        // 0x8006AE04: nop
    
            goto L_8006AE10;
    }
    // 0x8006AE04: nop

    // 0x8006AE08: jr          $ra
    // 0x8006AE0C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8006AE0C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006AE10:
    // 0x8006AE10: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8006AE14: slt         $at, $a0, $v0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8006AE18: bne         $at, $zero, L_8006ADE4
    if (ctx->r1 != 0) {
        // 0x8006AE1C: addiu       $v1, $v1, 0x6
        ctx->r3 = ADD32(ctx->r3, 0X6);
            goto L_8006ADE4;
    }
    // 0x8006AE1C: addiu       $v1, $v1, 0x6
    ctx->r3 = ADD32(ctx->r3, 0X6);
L_8006AE20:
    // 0x8006AE20: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8006AE24:
    // 0x8006AE24: jr          $ra
    // 0x8006AE28: nop

    return;
    // 0x8006AE28: nop

;}
RECOMP_FUNC void render_active_particles(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3678: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800B367C: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800B3680: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800B3684: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800B3688: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800B368C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B3690: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800B3694: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800B3698: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800B369C: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    // 0x800B36A0: jal         0x8000E988
    // 0x800B36A4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    objGetObjList(rdram, ctx);
        goto after_0;
    // 0x800B36A4: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_0:
    // 0x800B36A8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B36AC: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800B36B0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800B36B4: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800B36B8: beq         $at, $zero, L_800B3728
    if (ctx->r1 == 0) {
        // 0x800B36BC: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800B3728;
    }
    // 0x800B36BC: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B36C0:
    // 0x800B36C0: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x800B36C4: nop

    // 0x800B36C8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800B36CC: addu        $t9, $s0, $t8
    ctx->r25 = ADD32(ctx->r16, ctx->r24);
    // 0x800B36D0: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x800B36D4: nop

    // 0x800B36D8: lh          $t0, 0x6($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X6);
    // 0x800B36DC: nop

    // 0x800B36E0: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x800B36E4: beq         $t1, $zero, L_800B3710
    if (ctx->r9 == 0) {
        // 0x800B36E8: lw          $v1, 0x38($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X38);
            goto L_800B3710;
    }
    // 0x800B36E8: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
    // 0x800B36EC: lw          $t2, 0x40($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X40);
    // 0x800B36F0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B36F4: andi        $t3, $t2, 0x8000
    ctx->r11 = ctx->r10 & 0X8000;
    // 0x800B36F8: beq         $t3, $zero, L_800B370C
    if (ctx->r11 == 0) {
        // 0x800B36FC: or          $a2, $s2, $zero
        ctx->r6 = ctx->r18 | 0;
            goto L_800B370C;
    }
    // 0x800B36FC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x800B3700: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x800B3704: jal         0x800B3740
    // 0x800B3708: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    render_particle(rdram, ctx);
        goto after_1;
    // 0x800B3708: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_1:
L_800B370C:
    // 0x800B370C: lw          $v1, 0x38($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X38);
L_800B3710:
    // 0x800B3710: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B3714: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B3718: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800B371C: bne         $at, $zero, L_800B36C0
    if (ctx->r1 != 0) {
        // 0x800B3720: sw          $v1, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r3;
            goto L_800B36C0;
    }
    // 0x800B3720: sw          $v1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r3;
    // 0x800B3724: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800B3728:
    // 0x800B3728: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800B372C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800B3730: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800B3734: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800B3738: jr          $ra
    // 0x800B373C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800B373C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void savemenu_blank_save_destination(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800861C8: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800861CC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800861D0: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800861D4: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800861D8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800861DC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800861E0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800861E4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800861E8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800861EC: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800861F0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800861F4: addiu       $s3, $s3, 0x6530
    ctx->r19 = ADD32(ctx->r19, 0X6530);
    // 0x800861F8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800861FC: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x80086200: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
L_80086204:
    // 0x80086204: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80086208: nop

    // 0x8008620C: lbu         $t7, 0x4B($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X4B);
    // 0x80086210: nop

    // 0x80086214: beq         $t7, $zero, L_80086294
    if (ctx->r15 == 0) {
        // 0x80086218: nop
    
            goto L_80086294;
    }
    // 0x80086218: nop

    // 0x8008621C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x80086220: nop

    // 0x80086224: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x80086228: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x8008622C: sb          $s4, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r20;
    // 0x80086230: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x80086234: nop

    // 0x80086238: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x8008623C: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x80086240: sb          $zero, 0x1($t3)
    MEM_B(0X1, ctx->r11) = 0;
    // 0x80086244: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x80086248: nop

    // 0x8008624C: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80086250: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x80086254: sb          $zero, 0x2($t6)
    MEM_B(0X2, ctx->r14) = 0;
    // 0x80086258: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8008625C: nop

    // 0x80086260: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80086264: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x80086268: jal         0x80073C4C
    // 0x8008626C: sb          $s2, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r18;
    get_game_data_file_size(rdram, ctx);
        goto after_0;
    // 0x8008626C: sb          $s2, 0x6($t9)
    MEM_B(0X6, ctx->r25) = ctx->r18;
    after_0:
    // 0x80086270: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80086274: nop

    // 0x80086278: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x8008627C: addu        $t2, $s1, $t1
    ctx->r10 = ADD32(ctx->r17, ctx->r9);
    // 0x80086280: sw          $v0, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->r2;
    // 0x80086284: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x80086288: nop

    // 0x8008628C: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x80086290: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
L_80086294:
    // 0x80086294: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80086298: bne         $s2, $s5, L_80086204
    if (ctx->r18 != ctx->r21) {
        // 0x8008629C: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80086204;
    }
    // 0x8008629C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800862A0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800862A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800862A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800862AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800862B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800862B4: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800862B8: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800862BC: jr          $ra
    // 0x800862C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800862C0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
