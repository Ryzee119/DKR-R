#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void __initChanState(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000AE90: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000AE94: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000AE98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000AE9C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000AEA0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000AEA4: lbu         $t6, 0x34($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X34);
    // 0x8000AEA8: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8000AEAC: blez        $t6, L_8000AEE4
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000AEB0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000AEE4;
    }
    // 0x8000AEB0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000AEB4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000AEB8:
    // 0x8000AEB8: lw          $t7, 0x60($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X60);
    // 0x8000AEBC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000AEC0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8000AEC4: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8000AEC8: jal         0x8000ADF4
    // 0x8000AECC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    __resetPerfChanState(rdram, ctx);
        goto after_0;
    // 0x8000AECC: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x8000AED0: lbu         $t9, 0x34($s1)
    ctx->r25 = MEM_BU(ctx->r17, 0X34);
    // 0x8000AED4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000AED8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8000AEDC: bne         $at, $zero, L_8000AEB8
    if (ctx->r1 != 0) {
        // 0x8000AEE0: addiu       $s2, $s2, 0x14
        ctx->r18 = ADD32(ctx->r18, 0X14);
            goto L_8000AEB8;
    }
    // 0x8000AEE0: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
L_8000AEE4:
    // 0x8000AEE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000AEE8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000AEEC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000AEF0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000AEF4: jr          $ra
    // 0x8000AEF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000AEF8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alCSeqSetLoc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7B40: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800C7B44: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800C7B48: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800C7B4C: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x800C7B50: lw          $t7, 0x4($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X4);
    // 0x800C7B54: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800C7B58: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x800C7B5C: sw          $t7, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r15;
    // 0x800C7B60: lw          $t8, 0x8($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X8);
    // 0x800C7B64: or          $t0, $a1, $zero
    ctx->r8 = ctx->r5 | 0;
    // 0x800C7B68: sw          $t8, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r24;
    // 0x800C7B6C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
L_800C7B70:
    // 0x800C7B70: lw          $t9, 0xC($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XC);
    // 0x800C7B74: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x800C7B78: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800C7B7C: sw          $t9, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r25;
    // 0x800C7B80: lw          $t1, 0x4C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4C);
    // 0x800C7B84: addiu       $a2, $a2, 0x8
    ctx->r6 = ADD32(ctx->r6, 0X8);
    // 0x800C7B88: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x800C7B8C: sw          $t1, 0x50($v1)
    MEM_W(0X50, ctx->r3) = ctx->r9;
    // 0x800C7B90: lbu         $t2, 0x8C($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X8C);
    // 0x800C7B94: addiu       $t0, $t0, 0x2
    ctx->r8 = ADD32(ctx->r8, 0X2);
    // 0x800C7B98: sb          $t2, 0x96($a3)
    MEM_B(0X96, ctx->r7) = ctx->r10;
    // 0x800C7B9C: lbu         $t3, 0x9A($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0X9A);
    // 0x800C7BA0: sb          $t3, 0xA6($a3)
    MEM_B(0XA6, ctx->r7) = ctx->r11;
    // 0x800C7BA4: lw          $t4, 0xA4($a2)
    ctx->r12 = MEM_W(ctx->r6, 0XA4);
    // 0x800C7BA8: sw          $t4, 0xB0($v1)
    MEM_W(0XB0, ctx->r3) = ctx->r12;
    // 0x800C7BAC: lw          $t5, 0x8($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X8);
    // 0x800C7BB0: sw          $t5, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r13;
    // 0x800C7BB4: lw          $t6, 0x48($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X48);
    // 0x800C7BB8: sw          $t6, 0x54($v1)
    MEM_W(0X54, ctx->r3) = ctx->r14;
    // 0x800C7BBC: lbu         $t7, 0x8B($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X8B);
    // 0x800C7BC0: sb          $t7, 0x97($a3)
    MEM_B(0X97, ctx->r7) = ctx->r15;
    // 0x800C7BC4: lbu         $t8, 0x9B($t0)
    ctx->r24 = MEM_BU(ctx->r8, 0X9B);
    // 0x800C7BC8: sb          $t8, 0xA7($a3)
    MEM_B(0XA7, ctx->r7) = ctx->r24;
    // 0x800C7BCC: lw          $t9, 0xA8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0XA8);
    // 0x800C7BD0: bne         $v0, $a0, L_800C7B70
    if (ctx->r2 != ctx->r4) {
        // 0x800C7BD4: sw          $t9, 0xB4($v1)
        MEM_W(0XB4, ctx->r3) = ctx->r25;
            goto L_800C7B70;
    }
    // 0x800C7BD4: sw          $t9, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r25;
    // 0x800C7BD8: jr          $ra
    // 0x800C7BDC: nop

    return;
    // 0x800C7BDC: nop

;}
RECOMP_FUNC void menu_cinematic_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AC98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009AC9C: lw          $t6, 0x6804($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6804);
    // 0x8009ACA0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009ACA4: beq         $t6, $zero, L_8009ACC0
    if (ctx->r14 == 0) {
        // 0x8009ACA8: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009ACC0;
    }
    // 0x8009ACA8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009ACAC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009ACB0: jal         0x8009C674
    // 0x8009ACB4: addiu       $a0, $a0, 0x1768
    ctx->r4 = ADD32(ctx->r4, 0X1768);
    menu_assetgroup_load(rdram, ctx);
        goto after_0;
    // 0x8009ACB4: addiu       $a0, $a0, 0x1768
    ctx->r4 = ADD32(ctx->r4, 0X1768);
    after_0:
    // 0x8009ACB8: jal         0x80094604
    // 0x8009ACBC: nop

    menu_racer_portraits(rdram, ctx);
        goto after_1;
    // 0x8009ACBC: nop

    after_1:
L_8009ACC0:
    // 0x8009ACC0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009ACC4: lw          $v0, 0x67EC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X67EC);
    // 0x8009ACC8: nop

    // 0x8009ACCC: lb          $a0, 0x0($v0)
    ctx->r4 = MEM_B(ctx->r2, 0X0);
    // 0x8009ACD0: lb          $a1, 0x1($v0)
    ctx->r5 = MEM_B(ctx->r2, 0X1);
    // 0x8009ACD4: lb          $a2, 0x2($v0)
    ctx->r6 = MEM_B(ctx->r2, 0X2);
    // 0x8009ACD8: jal         0x8006E2E8
    // 0x8009ACDC: nop

    load_level_for_menu(rdram, ctx);
        goto after_2;
    // 0x8009ACDC: nop

    after_2:
    // 0x8009ACE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009ACE4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009ACE8: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x8009ACEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009ACF0: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x8009ACF4: jr          $ra
    // 0x8009ACF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x8009ACF8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void set_render_printf_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B635C: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B6360: addiu       $a2, $a2, -0x7A28
    ctx->r6 = ADD32(ctx->r6, -0X7A28);
    // 0x800B6364: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B6368: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800B636C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800B6370: addiu       $t8, $zero, 0x82
    ctx->r24 = ADD32(0, 0X82);
    // 0x800B6374: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800B6378: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x800B637C: or          $t7, $a1, $zero
    ctx->r15 = ctx->r5 | 0;
    // 0x800B6380: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800B6384: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x800B6388: sb          $a0, 0x0($t1)
    MEM_B(0X0, ctx->r9) = ctx->r4;
    // 0x800B638C: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800B6390: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x800B6394: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800B6398: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800B639C: sra         $t7, $a0, 8
    ctx->r15 = S32(SIGNED(ctx->r4) >> 8);
    // 0x800B63A0: sb          $t7, 0x0($t5)
    MEM_B(0X0, ctx->r13) = ctx->r15;
    // 0x800B63A4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B63A8: sra         $t6, $a1, 8
    ctx->r14 = S32(SIGNED(ctx->r5) >> 8);
    // 0x800B63AC: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x800B63B0: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x800B63B4: sb          $a1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r5;
    // 0x800B63B8: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800B63BC: nop

    // 0x800B63C0: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800B63C4: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B63C8: sb          $t6, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r14;
    // 0x800B63CC: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800B63D0: nop

    // 0x800B63D4: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800B63D8: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800B63DC: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x800B63E0: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800B63E4: nop

    // 0x800B63E8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800B63EC: jr          $ra
    // 0x800B63F0: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
    return;
    // 0x800B63F0: sw          $t2, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r10;
;}
RECOMP_FUNC void render_3d_billboard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011C94: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x80011C98: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80011C9C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80011CA0: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80011CA4: lw          $v1, 0x54($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X54);
    // 0x80011CA8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80011CAC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80011CB0: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80011CB4: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80011CB8: beq         $v1, $zero, L_80011D00
    if (ctx->r3 == 0) {
        // 0x80011CBC: ori         $t2, $t6, 0x108
        ctx->r10 = ctx->r14 | 0X108;
            goto L_80011D00;
    }
    // 0x80011CBC: ori         $t2, $t6, 0x108
    ctx->r10 = ctx->r14 | 0X108;
    // 0x80011CC0: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x80011CC4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011CC8: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80011CCC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011CD0: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80011CD4: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80011CD8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80011CDC: nop

    // 0x80011CE0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80011CE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80011CE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80011CEC: nop

    // 0x80011CF0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80011CF4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80011CF8: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80011CFC: nop

L_80011D00:
    // 0x80011D00: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011D04: addiu       $at, $zero, 0x16
    ctx->r1 = ADD32(0, 0X16);
    // 0x80011D08: bne         $v0, $at, L_80011D50
    if (ctx->r2 != ctx->r1) {
        // 0x80011D0C: addiu       $t3, $zero, 0x5
        ctx->r11 = ADD32(0, 0X5);
            goto L_80011D50;
    }
    // 0x80011D0C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x80011D10: lbu         $v1, 0x39($a3)
    ctx->r3 = MEM_BU(ctx->r7, 0X39);
    // 0x80011D14: nop

    // 0x80011D18: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80011D1C: bne         $at, $zero, L_80011D34
    if (ctx->r1 != 0) {
        // 0x80011D20: nop
    
            goto L_80011D34;
    }
    // 0x80011D20: nop

    // 0x80011D24: lw          $t4, 0x7C($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X7C);
    // 0x80011D28: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011D2C: b           L_80011D50
    // 0x80011D30: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
        goto L_80011D50;
    // 0x80011D30: sb          $t4, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r12;
L_80011D34:
    // 0x80011D34: lw          $t5, 0x7C($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X7C);
    // 0x80011D38: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011D3C: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x80011D40: multu       $v1, $t6
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80011D44: mflo        $t7
    ctx->r15 = lo;
    // 0x80011D48: sra         $t8, $t7, 8
    ctx->r24 = S32(SIGNED(ctx->r15) >> 8);
    // 0x80011D4C: sb          $t8, 0x39($a3)
    MEM_B(0X39, ctx->r7) = ctx->r24;
L_80011D50:
    // 0x80011D50: lbu         $a1, 0x39($a3)
    ctx->r5 = MEM_BU(ctx->r7, 0X39);
    // 0x80011D54: addiu       $v1, $zero, 0x77
    ctx->r3 = ADD32(0, 0X77);
    // 0x80011D58: slti        $at, $a1, 0x100
    ctx->r1 = SIGNED(ctx->r5) < 0X100 ? 1 : 0;
    // 0x80011D5C: bne         $at, $zero, L_80011D68
    if (ctx->r1 != 0) {
        // 0x80011D60: ori         $t4, $t2, 0x4
        ctx->r12 = ctx->r10 | 0X4;
            goto L_80011D68;
    }
    // 0x80011D60: ori         $t4, $t2, 0x4
    ctx->r12 = ctx->r10 | 0X4;
    // 0x80011D64: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
L_80011D68:
    // 0x80011D68: bne         $v1, $v0, L_80011D74
    if (ctx->r3 != ctx->r2) {
        // 0x80011D6C: sra         $t9, $a1, 1
        ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
            goto L_80011D74;
    }
    // 0x80011D6C: sra         $t9, $a1, 1
    ctx->r25 = S32(SIGNED(ctx->r5) >> 1);
    // 0x80011D70: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
L_80011D74:
    // 0x80011D74: slti        $at, $a1, 0xFF
    ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
    // 0x80011D78: beq         $at, $zero, L_80011D88
    if (ctx->r1 == 0) {
        // 0x80011D7C: nop
    
            goto L_80011D88;
    }
    // 0x80011D7C: nop

    // 0x80011D80: or          $t2, $t4, $zero
    ctx->r10 = ctx->r12 | 0;
    // 0x80011D84: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80011D88:
    // 0x80011D88: bne         $t3, $v0, L_80011DFC
    if (ctx->r11 != ctx->r2) {
        // 0x80011D8C: lui         $at, 0x40C0
        ctx->r1 = S32(0X40C0 << 16);
            goto L_80011DFC;
    }
    // 0x80011D8C: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x80011D90: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80011D94: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80011D98: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80011D9C: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x80011DA0: addiu       $s0, $s0, -0x5174
    ctx->r16 = ADD32(ctx->r16, -0X5174);
    // 0x80011DA4: bc1f        L_80011DFC
    if (!c1cs) {
        // 0x80011DA8: lui         $t6, 0xFA00
        ctx->r14 = S32(0XFA00 << 16);
            goto L_80011DFC;
    }
    // 0x80011DA8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80011DAC: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011DB0: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x80011DB4: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80011DB8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x80011DBC: subu        $t7, $t7, $a2
    ctx->r15 = SUB32(ctx->r15, ctx->r6);
    // 0x80011DC0: sra         $t9, $t7, 2
    ctx->r25 = S32(SIGNED(ctx->r15) >> 2);
    // 0x80011DC4: sll         $t4, $t9, 24
    ctx->r12 = S32(ctx->r25 << 24);
    // 0x80011DC8: andi        $t5, $a2, 0xFF
    ctx->r13 = ctx->r6 & 0XFF;
    // 0x80011DCC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80011DD0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x80011DD4: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x80011DD8: andi        $t9, $t8, 0xFF
    ctx->r25 = ctx->r24 & 0XFF;
    // 0x80011DDC: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x80011DE0: sll         $t5, $t9, 8
    ctx->r13 = S32(ctx->r25 << 8);
    // 0x80011DE4: or          $t4, $t7, $t5
    ctx->r12 = ctx->r15 | ctx->r13;
    // 0x80011DE8: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x80011DEC: or          $t8, $t4, $t6
    ctx->r24 = ctx->r12 | ctx->r14;
    // 0x80011DF0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011DF4: b           L_80011EAC
    // 0x80011DF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
        goto L_80011EAC;
    // 0x80011DF8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
L_80011DFC:
    // 0x80011DFC: bne         $v1, $v0, L_80011E38
    if (ctx->r3 != ctx->r2) {
        // 0x80011E00: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80011E38;
    }
    // 0x80011E00: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80011E04: addiu       $s0, $s0, -0x5174
    ctx->r16 = ADD32(ctx->r16, -0X5174);
    // 0x80011E08: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011E0C: lui         $at, 0x96E6
    ctx->r1 = S32(0X96E6 << 16);
    // 0x80011E10: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x80011E14: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x80011E18: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x80011E1C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x80011E20: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x80011E24: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x80011E28: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80011E2C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80011E30: b           L_80011EAC
    // 0x80011E34: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_80011EAC;
    // 0x80011E34: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_80011E38:
    // 0x80011E38: bne         $t0, $zero, L_80011E48
    if (ctx->r8 != 0) {
        // 0x80011E3C: slti        $at, $a1, 0xFF
        ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
            goto L_80011E48;
    }
    // 0x80011E3C: slti        $at, $a1, 0xFF
    ctx->r1 = SIGNED(ctx->r5) < 0XFF ? 1 : 0;
    // 0x80011E40: beq         $at, $zero, L_80011E8C
    if (ctx->r1 == 0) {
        // 0x80011E44: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_80011E8C;
    }
    // 0x80011E44: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
L_80011E48:
    // 0x80011E48: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80011E4C: addiu       $s0, $s0, -0x5174
    ctx->r16 = ADD32(ctx->r16, -0X5174);
    // 0x80011E50: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011E54: andi        $v1, $a2, 0xFF
    ctx->r3 = ctx->r6 & 0XFF;
    // 0x80011E58: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011E5C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80011E60: sll         $t9, $v1, 24
    ctx->r25 = S32(ctx->r3 << 24);
    // 0x80011E64: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80011E68: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x80011E6C: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
    // 0x80011E70: sll         $t4, $v1, 8
    ctx->r12 = S32(ctx->r3 << 8);
    // 0x80011E74: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011E78: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80011E7C: or          $t6, $t5, $t4
    ctx->r14 = ctx->r13 | ctx->r12;
    // 0x80011E80: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80011E84: b           L_80011EAC
    // 0x80011E88: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
        goto L_80011EAC;
    // 0x80011E88: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_80011E8C:
    // 0x80011E8C: addiu       $s0, $s0, -0x5174
    ctx->r16 = ADD32(ctx->r16, -0X5174);
    // 0x80011E90: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011E94: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x80011E98: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80011E9C: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80011EA0: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x80011EA4: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x80011EA8: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_80011EAC:
    // 0x80011EAC: beq         $t1, $zero, L_80011F00
    if (ctx->r9 == 0) {
        // 0x80011EB0: nop
    
            goto L_80011F00;
    }
    // 0x80011EB0: nop

    // 0x80011EB4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011EB8: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80011EBC: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011EC0: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80011EC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011EC8: lw          $v1, 0x54($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X54);
    // 0x80011ECC: nop

    // 0x80011ED0: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x80011ED4: lbu         $t6, 0x5($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X5);
    // 0x80011ED8: lbu         $t4, 0x6($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0X6);
    // 0x80011EDC: sll         $t5, $t7, 24
    ctx->r13 = S32(ctx->r15 << 24);
    // 0x80011EE0: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x80011EE4: lbu         $t7, 0x7($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X7);
    // 0x80011EE8: or          $t9, $t5, $t8
    ctx->r25 = ctx->r13 | ctx->r24;
    // 0x80011EEC: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x80011EF0: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x80011EF4: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x80011EF8: b           L_80011F50
    // 0x80011EFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
        goto L_80011F50;
    // 0x80011EFC: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
L_80011F00:
    // 0x80011F00: lh          $t9, 0x48($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X48);
    // 0x80011F04: addiu       $at, $zero, 0x44
    ctx->r1 = ADD32(0, 0X44);
    // 0x80011F08: bne         $t9, $at, L_80011F38
    if (ctx->r25 != ctx->r1) {
        // 0x80011F0C: lui         $t4, 0xFB00
        ctx->r12 = S32(0XFB00 << 16);
            goto L_80011F38;
    }
    // 0x80011F0C: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x80011F10: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011F14: lui         $t5, 0xFFFF
    ctx->r13 = S32(0XFFFF << 16);
    // 0x80011F18: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011F1C: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80011F20: ori         $t5, $t5, 0xFF
    ctx->r13 = ctx->r13 | 0XFF;
    // 0x80011F24: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x80011F28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80011F2C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011F30: b           L_80011F50
    // 0x80011F34: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_80011F50;
    // 0x80011F34: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
L_80011F38:
    // 0x80011F38: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x80011F3C: addiu       $t9, $zero, -0x100
    ctx->r25 = ADD32(0, -0X100);
    // 0x80011F40: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x80011F44: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x80011F48: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x80011F4C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
L_80011F50:
    // 0x80011F50: lb          $t8, 0x3A($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X3A);
    // 0x80011F54: lw          $t6, 0x68($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X68);
    // 0x80011F58: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x80011F5C: addu        $t7, $t6, $t5
    ctx->r15 = ADD32(ctx->r14, ctx->r13);
    // 0x80011F60: lw          $t4, 0x0($t7)
    ctx->r12 = MEM_W(ctx->r15, 0X0);
    // 0x80011F64: addiu       $at, $zero, 0x74
    ctx->r1 = ADD32(0, 0X74);
    // 0x80011F68: sw          $t4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r12;
    // 0x80011F6C: lh          $v0, 0x48($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X48);
    // 0x80011F70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80011F74: bne         $v0, $at, L_80011F90
    if (ctx->r2 != ctx->r1) {
        // 0x80011F78: nop
    
            goto L_80011F90;
    }
    // 0x80011F78: nop

    // 0x80011F7C: lw          $t9, 0x7C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X7C);
    // 0x80011F80: lw          $a0, 0x78($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X78);
    // 0x80011F84: blez        $t9, L_80011F90
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80011F88: nop
    
            goto L_80011F90;
    }
    // 0x80011F88: nop

    // 0x80011F8C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80011F90:
    // 0x80011F90: bne         $a0, $zero, L_80011FB8
    if (ctx->r4 != 0) {
        // 0x80011F94: nop
    
            goto L_80011FB8;
    }
    // 0x80011F94: nop

    // 0x80011F98: bne         $t3, $v0, L_8001203C
    if (ctx->r11 != ctx->r2) {
        // 0x80011F9C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001203C;
    }
    // 0x80011F9C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80011FA0: lw          $t8, 0x64($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X64);
    // 0x80011FA4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80011FA8: lbu         $t6, 0x18($t8)
    ctx->r14 = MEM_BU(ctx->r24, 0X18);
    // 0x80011FAC: nop

    // 0x80011FB0: bne         $t6, $at, L_80012040
    if (ctx->r14 != ctx->r1) {
        // 0x80011FB4: lw          $t9, 0x58($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X58);
            goto L_80012040;
    }
    // 0x80011FB4: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80011FB8:
    // 0x80011FB8: sh          $zero, 0x64($sp)
    MEM_H(0X64, ctx->r29) = 0;
    // 0x80011FBC: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x80011FC0: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x80011FC4: lwc1        $f4, 0x8($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80011FC8: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80011FCC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80011FD0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80011FD4: swc1        $f4, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f4.u32l;
    // 0x80011FD8: swc1        $f0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f0.u32l;
    // 0x80011FDC: swc1        $f0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f0.u32l;
    // 0x80011FE0: swc1        $f6, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f6.u32l;
    // 0x80011FE4: lh          $t5, 0x18($a3)
    ctx->r13 = MEM_H(ctx->r7, 0X18);
    // 0x80011FE8: addiu       $t7, $zero, 0x20
    ctx->r15 = ADD32(0, 0X20);
    // 0x80011FEC: sh          $t7, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r15;
    // 0x80011FF0: bne         $a0, $zero, L_80012014
    if (ctx->r4 != 0) {
        // 0x80011FF4: sh          $t5, 0x78($sp)
        MEM_H(0X78, ctx->r29) = ctx->r13;
            goto L_80012014;
    }
    // 0x80011FF4: sh          $t5, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r13;
    // 0x80011FF8: lw          $t4, 0x64($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X64);
    // 0x80011FFC: nop

    // 0x80012000: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x80012004: nop

    // 0x80012008: bne         $a0, $zero, L_80012018
    if (ctx->r4 != 0) {
        // 0x8001200C: lw          $a1, 0x58($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X58);
            goto L_80012018;
    }
    // 0x8001200C: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
    // 0x80012010: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
L_80012014:
    // 0x80012014: lw          $a1, 0x58($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X58);
L_80012018:
    // 0x80012018: addiu       $a2, $sp, 0x60
    ctx->r6 = ADD32(ctx->r29, 0X60);
    // 0x8001201C: addiu       $a3, $zero, 0x106
    ctx->r7 = ADD32(0, 0X106);
    // 0x80012020: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x80012024: jal         0x800138A8
    // 0x80012028: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    render_bubble_trap(rdram, ctx);
        goto after_0;
    // 0x80012028: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    after_0:
    // 0x8001202C: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80012030: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80012034: b           L_80012070
    // 0x80012038: nop

        goto L_80012070;
    // 0x80012038: nop

L_8001203C:
    // 0x8001203C: lw          $t9, 0x58($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X58);
L_80012040:
    // 0x80012040: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80012044: addiu       $a2, $a2, -0x516C
    ctx->r6 = ADD32(ctx->r6, -0X516C);
    // 0x80012048: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8001204C: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x80012050: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x80012054: sw          $t0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r8;
    // 0x80012058: sw          $t1, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r9;
    // 0x8001205C: jal         0x80068514
    // 0x80012060: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    render_sprite_billboard(rdram, ctx);
        goto after_1;
    // 0x80012060: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_1:
    // 0x80012064: lw          $t0, 0x80($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X80);
    // 0x80012068: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x8001206C: nop

L_80012070:
    // 0x80012070: beq         $t0, $zero, L_80012094
    if (ctx->r8 == 0) {
        // 0x80012074: nop
    
            goto L_80012094;
    }
    // 0x80012074: nop

    // 0x80012078: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8001207C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x80012080: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x80012084: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80012088: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x8001208C: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x80012090: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80012094:
    // 0x80012094: beq         $t1, $zero, L_800120BC
    if (ctx->r9 == 0) {
        // 0x80012098: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800120BC;
    }
    // 0x80012098: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001209C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800120A0: lui         $t4, 0xFB00
    ctx->r12 = S32(0XFB00 << 16);
    // 0x800120A4: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800120A8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    // 0x800120AC: addiu       $t9, $zero, -0x100
    ctx->r25 = ADD32(0, -0X100);
    // 0x800120B0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800120B4: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800120B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800120BC:
    // 0x800120BC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800120C0: jr          $ra
    // 0x800120C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800120C4: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void music_channel_get_mask(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000105C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001060: lw          $t6, -0x39D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X39D0);
    // 0x80001064: nop

    // 0x80001068: lhu         $v0, 0x30($t6)
    ctx->r2 = MEM_HU(ctx->r14, 0X30);
    // 0x8000106C: jr          $ra
    // 0x80001070: nop

    return;
    // 0x80001070: nop

;}
RECOMP_FUNC void get_game_data_file_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073C4C: jr          $ra
    // 0x80073C50: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
    return;
    // 0x80073C50: addiu       $v0, $zero, 0x100
    ctx->r2 = ADD32(0, 0X100);
;}
RECOMP_FUNC void get_racer_objects_by_port(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001BA94: lw          $t6, -0x5110($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5110);
    // 0x8001BA98: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BA9C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8001BAA0: lw          $v0, -0x5114($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5114);
    // 0x8001BAA4: jr          $ra
    // 0x8001BAA8: nop

    return;
    // 0x8001BAA8: nop

;}
RECOMP_FUNC void timetrial_free_staff_ghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80059B4C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80059B50: lw          $a0, -0x2A68($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2A68);
    // 0x80059B54: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80059B58: beq         $a0, $zero, L_80059B68
    if (ctx->r4 == 0) {
        // 0x80059B5C: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_80059B68;
    }
    // 0x80059B5C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80059B60: jal         0x80071140
    // 0x80059B64: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x80059B64: nop

    after_0:
L_80059B68:
    // 0x80059B68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80059B6C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059B70: sw          $zero, -0x2A68($at)
    MEM_W(-0X2A68, ctx->r1) = 0;
    // 0x80059B74: jr          $ra
    // 0x80059B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059B78: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_checkpoint_node(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA00: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x8001BA04: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001BA08: lw          $t7, -0x5134($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5134);
    // 0x8001BA0C: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x8001BA10: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8001BA14: jr          $ra
    // 0x8001BA18: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    return;
    // 0x8001BA18: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
;}
RECOMP_FUNC void get_track_id_to_load(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C1B0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009C1B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009C1B8: jal         0x8006EA90
    // 0x8009C1BC: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x8009C1BC: nop

    after_0:
    // 0x8009C1C0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8009C1C4: lw          $t6, -0xB48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB48);
    // 0x8009C1C8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009C1CC: bne         $t6, $zero, L_8009C208
    if (ctx->r14 != 0) {
        // 0x8009C1D0: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8009C208;
    }
    // 0x8009C1D0: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8009C1D4: lw          $t7, -0xB88($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB88);
    // 0x8009C1D8: nop

    // 0x8009C1DC: bne         $t7, $zero, L_8009C208
    if (ctx->r15 != 0) {
        // 0x8009C1E0: nop
    
            goto L_8009C208;
    }
    // 0x8009C1E0: nop

    // 0x8009C1E4: lbu         $t8, 0x4B($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X4B);
    // 0x8009C1E8: nop

    // 0x8009C1EC: beq         $t8, $zero, L_8009C1FC
    if (ctx->r24 == 0) {
        // 0x8009C1F0: nop
    
            goto L_8009C1FC;
    }
    // 0x8009C1F0: nop

    // 0x8009C1F4: b           L_8009C218
    // 0x8009C1F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009C218;
    // 0x8009C1F8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009C1FC:
    // 0x8009C1FC: lbu         $v0, 0x49($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X49);
    // 0x8009C200: b           L_8009C21C
    // 0x8009C204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_8009C21C;
    // 0x8009C204: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C208:
    // 0x8009C208: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009C20C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009C210: lw          $v0, -0xB2C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB2C);
    // 0x8009C214: sw          $zero, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = 0;
L_8009C218:
    // 0x8009C218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8009C21C:
    extern void dkr_custom_tracks_track_id_override(uint8_t*, recomp_context*); dkr_custom_tracks_track_id_override(rdram, ctx);
    // 0x8009C21C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009C220: jr          $ra
    // 0x8009C224: nop

    return;
    // 0x8009C224: nop

;}
RECOMP_FUNC void race_starting(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A0190: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A0194: lbu         $v0, 0x6D34($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6D34);
    // 0x800A0198: jr          $ra
    // 0x800A019C: nop

    return;
    // 0x800A019C: nop

;}
RECOMP_FUNC void viewport_menu_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066940: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80066944: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80066948: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8006694C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80066950: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80066954: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80066958: jal         0x8007A520
    // 0x8006695C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x8006695C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80066960: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80066964: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80066968: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8006696C: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80066970: slt         $at, $a3, $a1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80066974: beq         $at, $zero, L_80066988
    if (ctx->r1 == 0) {
        // 0x80066978: andi        $a0, $v0, 0xFFFF
        ctx->r4 = ctx->r2 & 0XFFFF;
            goto L_80066988;
    }
    // 0x80066978: andi        $a0, $v0, 0xFFFF
    ctx->r4 = ctx->r2 & 0XFFFF;
    // 0x8006697C: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
    // 0x80066980: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80066984: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_80066988:
    // 0x80066988: slt         $at, $a2, $s0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8006698C: beq         $at, $zero, L_8006699C
    if (ctx->r1 == 0) {
        // 0x80066990: or          $v1, $s0, $zero
        ctx->r3 = ctx->r16 | 0;
            goto L_8006699C;
    }
    // 0x80066990: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
    // 0x80066994: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x80066998: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8006699C:
    // 0x8006699C: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800669A0: beq         $at, $zero, L_800669C4
    if (ctx->r1 == 0) {
        // 0x800669A4: sll         $t7, $t0, 2
        ctx->r15 = S32(ctx->r8 << 2);
            goto L_800669C4;
    }
    // 0x800669A4: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800669A8: bltz        $a3, L_800669C4
    if (SIGNED(ctx->r7) < 0) {
        // 0x800669AC: sra         $v1, $v0, 16
        ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
            goto L_800669C4;
    }
    // 0x800669AC: sra         $v1, $v0, 16
    ctx->r3 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800669B0: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800669B4: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800669B8: beq         $at, $zero, L_800669C4
    if (ctx->r1 == 0) {
        // 0x800669BC: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800669C4;
    }
    // 0x800669BC: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800669C0: bgez        $a2, L_800669F4
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800669C4: subu        $t7, $t7, $t0
        ctx->r15 = SUB32(ctx->r15, ctx->r8);
            goto L_800669F4;
    }
L_800669C4:
    // 0x800669C4: subu        $t7, $t7, $t0
    ctx->r15 = SUB32(ctx->r15, ctx->r8);
    // 0x800669C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800669CC: addu        $t7, $t7, $t0
    ctx->r15 = ADD32(ctx->r15, ctx->r8);
    // 0x800669D0: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800669D4: addiu       $t8, $t8, -0x2F9C
    ctx->r24 = ADD32(ctx->r24, -0X2F9C);
    // 0x800669D8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800669DC: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x800669E0: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
    // 0x800669E4: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
    // 0x800669E8: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x800669EC: b           L_80066A88
    // 0x800669F0: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
        goto L_80066A88;
    // 0x800669F0: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
L_800669F4:
    // 0x800669F4: bgez        $a1, L_80066A24
    if (SIGNED(ctx->r5) >= 0) {
        // 0x800669F8: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80066A24;
    }
    // 0x800669F8: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800669FC: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x80066A00: subu        $t9, $t9, $t0
    ctx->r25 = SUB32(ctx->r25, ctx->r8);
    // 0x80066A04: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80066A08: addu        $t9, $t9, $t0
    ctx->r25 = ADD32(ctx->r25, ctx->r8);
    // 0x80066A0C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80066A10: addiu       $t1, $t1, -0x2F9C
    ctx->r9 = ADD32(ctx->r9, -0X2F9C);
    // 0x80066A14: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80066A18: addu        $v0, $t9, $t1
    ctx->r2 = ADD32(ctx->r25, ctx->r9);
    // 0x80066A1C: b           L_80066A48
    // 0x80066A20: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
        goto L_80066A48;
    // 0x80066A20: sw          $zero, 0x20($v0)
    MEM_W(0X20, ctx->r2) = 0;
L_80066A24:
    // 0x80066A24: sll         $t2, $t0, 2
    ctx->r10 = S32(ctx->r8 << 2);
    // 0x80066A28: subu        $t2, $t2, $t0
    ctx->r10 = SUB32(ctx->r10, ctx->r8);
    // 0x80066A2C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80066A30: addu        $t2, $t2, $t0
    ctx->r10 = ADD32(ctx->r10, ctx->r8);
    // 0x80066A34: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x80066A38: addiu       $t3, $t3, -0x2F9C
    ctx->r11 = ADD32(ctx->r11, -0X2F9C);
    // 0x80066A3C: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x80066A40: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80066A44: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
L_80066A48:
    // 0x80066A48: bgez        $s0, L_80066A58
    if (SIGNED(ctx->r16) >= 0) {
        // 0x80066A4C: nop
    
            goto L_80066A58;
    }
    // 0x80066A4C: nop

    // 0x80066A50: b           L_80066A5C
    // 0x80066A54: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
        goto L_80066A5C;
    // 0x80066A54: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
L_80066A58:
    // 0x80066A58: sw          $s0, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r16;
L_80066A5C:
    // 0x80066A5C: bne         $at, $zero, L_80066A6C
    if (ctx->r1 != 0) {
        // 0x80066A60: addiu       $t4, $a0, -0x1
        ctx->r12 = ADD32(ctx->r4, -0X1);
            goto L_80066A6C;
    }
    // 0x80066A60: addiu       $t4, $a0, -0x1
    ctx->r12 = ADD32(ctx->r4, -0X1);
    // 0x80066A64: b           L_80066A70
    // 0x80066A68: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
        goto L_80066A70;
    // 0x80066A68: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
L_80066A6C:
    // 0x80066A6C: sw          $a3, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r7;
L_80066A70:
    // 0x80066A70: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80066A74: bne         $at, $zero, L_80066A84
    if (ctx->r1 != 0) {
        // 0x80066A78: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_80066A84;
    }
    // 0x80066A78: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80066A7C: b           L_80066A88
    // 0x80066A80: sw          $t5, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r13;
        goto L_80066A88;
    // 0x80066A80: sw          $t5, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r13;
L_80066A84:
    // 0x80066A84: sw          $a2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r6;
L_80066A88:
    // 0x80066A88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80066A8C: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x80066A90: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80066A94: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x80066A98: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x80066A9C: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x80066AA0: jr          $ra
    // 0x80066AA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80066AA4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void minimap_marker_pos(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AA3EC: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AA3F0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AA3F4: swc1        $f12, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f12.u32l;
    // 0x800AA3F8: swc1        $f14, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f14.u32l;
    // 0x800AA3FC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800AA400: jal         0x8002C7C4
    // 0x800AA404: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x800AA404: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_0:
    // 0x800AA408: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800AA40C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800AA410: lwc1        $f6, 0x40($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800AA414: lh          $v1, 0x3C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X3C);
    // 0x800AA418: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x800AA41C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800AA420: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x800AA424: lh          $t6, 0x3E($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X3E);
    // 0x800AA428: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA42C: lwc1        $f18, 0x30($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800AA430: subu        $a2, $t6, $v1
    ctx->r6 = SUB32(ctx->r14, ctx->r3);
    // 0x800AA434: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800AA438: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x800AA43C: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800AA440: lh          $a0, 0x44($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X44);
    // 0x800AA444: mul.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800AA448: lui         $at, 0xC270
    ctx->r1 = S32(0XC270 << 16);
    // 0x800AA44C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800AA450: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x800AA454: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA458: lh          $t7, 0x46($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X46);
    // 0x800AA45C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800AA460: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800AA464: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x800AA468: mul.s       $f8, $f6, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800AA46C: subu        $a3, $t7, $a0
    ctx->r7 = SUB32(ctx->r15, ctx->r4);
    // 0x800AA470: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800AA474: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA478: mtc1        $a3, $f10
    ctx->f10.u32l = ctx->r7;
    // 0x800AA47C: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x800AA480: swc1        $f0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f0.u32l;
    // 0x800AA484: mul.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800AA488: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA48C: nop

    // 0x800AA490: div.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800AA494: jal         0x8009C30C
    // 0x800AA498: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_1;
    // 0x800AA498: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_1:
    // 0x800AA49C: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800AA4A0: lwc1        $f0, 0x20($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800AA4A4: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800AA4A8: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800AA4AC: lwc1        $f14, 0x38($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800AA4B0: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x800AA4B4: beq         $t8, $zero, L_800AA558
    if (ctx->r24 == 0) {
        // 0x800AA4B8: nop
    
            goto L_800AA558;
    }
    // 0x800AA4B8: nop

    // 0x800AA4BC: mul.s       $f18, $f0, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AA4C0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800AA4C4: lw          $t9, 0x6D58($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D58);
    // 0x800AA4C8: lh          $t0, 0x34($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X34);
    // 0x800AA4CC: mul.s       $f8, $f2, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800AA4D0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800AA4D4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800AA4D8: lw          $t1, 0x6D1C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6D1C);
    // 0x800AA4DC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA4E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AA4E4: addiu       $v0, $v0, 0x6CDC
    ctx->r2 = ADD32(ctx->r2, 0X6CDC);
    // 0x800AA4E8: add.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800AA4EC: mtc1        $t0, $f18
    ctx->f18.u32l = ctx->r8;
    // 0x800AA4F0: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x800AA4F4: mtc1        $t1, $f16
    ctx->f16.u32l = ctx->r9;
    // 0x800AA4F8: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AA4FC: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x800AA500: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800AA504: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AA508: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AA50C: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800AA510: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800AA514: swc1        $f18, 0x1EC($t2)
    MEM_W(0X1EC, ctx->r10) = ctx->f18.u32l;
    // 0x800AA518: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800AA51C: lw          $t4, 0x6D5C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D5C);
    // 0x800AA520: lh          $t3, 0x36($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X36);
    // 0x800AA524: lw          $t6, 0x6D20($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D20);
    // 0x800AA528: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800AA52C: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800AA530: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x800AA534: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800AA538: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA53C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800AA540: sub.s       $f6, $f16, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800AA544: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800AA548: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800AA54C: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800AA550: b           L_800AA5F0
    // 0x800AA554: swc1        $f10, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f10.u32l;
        goto L_800AA5F0;
    // 0x800AA554: swc1        $f10, 0x1F0($t7)
    MEM_W(0X1F0, ctx->r15) = ctx->f10.u32l;
L_800AA558:
    // 0x800AA558: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800AA55C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800AA560: lw          $t8, 0x6D58($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D58);
    // 0x800AA564: lh          $t9, 0x30($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X30);
    // 0x800AA568: mul.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f14.fl);
    // 0x800AA56C: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800AA570: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800AA574: lw          $t0, 0x6D1C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6D1C);
    // 0x800AA578: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800AA57C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AA580: addiu       $v0, $v0, 0x6CDC
    ctx->r2 = ADD32(ctx->r2, 0X6CDC);
    // 0x800AA584: add.s       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x800AA588: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x800AA58C: add.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800AA590: mtc1        $t0, $f16
    ctx->f16.u32l = ctx->r8;
    // 0x800AA594: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800AA598: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800AA59C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800AA5A0: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800AA5A4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800AA5A8: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800AA5AC: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800AA5B0: swc1        $f8, 0x1EC($t1)
    MEM_W(0X1EC, ctx->r9) = ctx->f8.u32l;
    // 0x800AA5B4: mul.s       $f16, $f0, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800AA5B8: lw          $t3, 0x6D5C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6D5C);
    // 0x800AA5BC: lh          $t2, 0x32($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X32);
    // 0x800AA5C0: lw          $t5, 0x6D20($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D20);
    // 0x800AA5C4: mul.s       $f18, $f2, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800AA5C8: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800AA5CC: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800AA5D0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800AA5D4: cvt.s.w     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA5D8: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800AA5DC: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800AA5E0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800AA5E4: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x800AA5E8: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800AA5EC: swc1        $f18, 0x1F0($t6)
    MEM_W(0X1F0, ctx->r14) = ctx->f18.u32l;
L_800AA5F0:
    // 0x800AA5F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AA5F4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800AA5F8: jr          $ra
    // 0x800AA5FC: nop

    return;
    // 0x800AA5FC: nop

;}
RECOMP_FUNC void titlescreen_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008411C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80084120: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80084124: jal         0x8009C4A8
    // 0x80084128: addiu       $a0, $a0, -0x83C
    ctx->r4 = ADD32(ctx->r4, -0X83C);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x80084128: addiu       $a0, $a0, -0x83C
    ctx->r4 = ADD32(ctx->r4, -0X83C);
    after_0:
    // 0x8008412C: jal         0x80000BE0
    // 0x80084130: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    music_voicelimit_set(rdram, ctx);
        goto after_1;
    // 0x80084130: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_1:
    // 0x80084134: jal         0x800660D0
    // 0x80084138: nop

    cam_shake_on(rdram, ctx);
        goto after_2;
    // 0x80084138: nop

    after_2:
    // 0x8008413C: jal         0x800C422C
    // 0x80084140: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_3;
    // 0x80084140: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x80084144: jal         0x80000890
    // 0x80084148: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sound_volume_reset(rdram, ctx);
        goto after_4;
    // 0x80084148: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8008414C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084150: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80084154: jr          $ra
    // 0x80084158: nop

    return;
    // 0x80084158: nop

;}
RECOMP_FUNC void transition_render_blank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C28E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C28EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C28F0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C28F4: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C28F8: jal         0x8007A520
    // 0x800C28FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    fb_size(rdram, ctx);
        goto after_0;
    // 0x800C28FC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x800C2900: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C2904: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C2908: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C290C: addiu       $t8, $t8, 0x31D8
    ctx->r24 = ADD32(ctx->r24, 0X31D8);
    // 0x800C2910: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x800C2914: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800C2918: lui         $t7, 0x600
    ctx->r15 = S32(0X600 << 16);
    // 0x800C291C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C2920: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C2924: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C2928: lui         $t1, 0xFA00
    ctx->r9 = S32(0XFA00 << 16);
    // 0x800C292C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800C2930: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C2934: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C2938: sw          $t1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r9;
    // 0x800C293C: lw          $t2, -0x58C8($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X58C8);
    // 0x800C2940: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C2944: sra         $t4, $t2, 16
    ctx->r12 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800C2948: lw          $t6, -0x58C4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X58C4);
    // 0x800C294C: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C2950: lw          $t2, -0x58C0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X58C0);
    // 0x800C2954: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800C2958: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x800C295C: sll         $t5, $t4, 24
    ctx->r13 = S32(ctx->r12 << 24);
    // 0x800C2960: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x800C2964: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800C2968: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C296C: or          $t1, $t5, $t9
    ctx->r9 = ctx->r13 | ctx->r25;
    // 0x800C2970: sll         $t6, $t4, 8
    ctx->r14 = S32(ctx->r12 << 8);
    // 0x800C2974: or          $t7, $t1, $t6
    ctx->r15 = ctx->r9 | ctx->r14;
    // 0x800C2978: ori         $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 | 0XFF;
    // 0x800C297C: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x800C2980: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C2984: lui         $t9, 0xFCFF
    ctx->r25 = S32(0XFCFF << 16);
    // 0x800C2988: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800C298C: lui         $t2, 0xFFFD
    ctx->r10 = S32(0XFFFD << 16);
    // 0x800C2990: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800C2994: ori         $t2, $t2, 0xF6FB
    ctx->r10 = ctx->r10 | 0XF6FB;
    // 0x800C2998: ori         $t9, $t9, 0xFFFF
    ctx->r25 = ctx->r25 | 0XFFFF;
    // 0x800C299C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800C29A0: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800C29A4: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800C29A8: sra         $t5, $v0, 16
    ctx->r13 = S32(SIGNED(ctx->r2) >> 16);
    // 0x800C29AC: andi        $t1, $v0, 0x3FF
    ctx->r9 = ctx->r2 & 0X3FF;
    // 0x800C29B0: sll         $t6, $t1, 14
    ctx->r14 = S32(ctx->r9 << 14);
    // 0x800C29B4: andi        $t9, $t5, 0x3FF
    ctx->r25 = ctx->r13 & 0X3FF;
    // 0x800C29B8: lui         $at, 0xF600
    ctx->r1 = S32(0XF600 << 16);
    // 0x800C29BC: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800C29C0: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800C29C4: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800C29C8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800C29CC: or          $t3, $t7, $t2
    ctx->r11 = ctx->r15 | ctx->r10;
    // 0x800C29D0: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800C29D4: jal         0x8007B3D0
    // 0x800C29D8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C29D8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    after_1:
    // 0x800C29DC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C29E0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C29E4: jr          $ra
    // 0x800C29E8: nop

    return;
    // 0x800C29E8: nop

;}
RECOMP_FUNC void menu_results_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80096848: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009684C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80096850: jal         0x8006EA90
    // 0x80096854: nop

    get_settings(rdram, ctx);
        goto after_0;
    // 0x80096854: nop

    after_0:
    // 0x80096858: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009685C: lw          $v1, -0xB60($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB60);
    // 0x80096860: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80096864: lw          $t6, 0x60($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X60);
    // 0x80096868: addiu       $a0, $a0, 0x6BF0
    ctx->r4 = ADD32(ctx->r4, 0X6BF0);
    // 0x8009686C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80096870: lw          $t7, 0x5C($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X5C);
    // 0x80096874: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80096878: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8009687C: lw          $t8, 0x70($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X70);
    // 0x80096880: addiu       $t9, $zero, 0x3
    ctx->r25 = ADD32(0, 0X3);
    // 0x80096884: sw          $t8, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r24;
    // 0x80096888: lw          $a3, -0xB44($a3)
    ctx->r7 = MEM_W(ctx->r7, -0XB44);
    // 0x8009688C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096890: sw          $t9, 0x6C14($at)
    MEM_W(0X6C14, ctx->r1) = ctx->r25;
    // 0x80096894: blez        $a3, L_800968DC
    if (SIGNED(ctx->r7) <= 0) {
        // 0x80096898: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800968DC;
    }
    // 0x80096898: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009689C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
L_800968A0:
    // 0x800968A0: lb          $a2, 0x5A($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X5A);
    // 0x800968A4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800968A8: slti        $at, $a2, 0x4
    ctx->r1 = SIGNED(ctx->r6) < 0X4 ? 1 : 0;
    // 0x800968AC: beq         $at, $zero, L_800968D0
    if (ctx->r1 == 0) {
        // 0x800968B0: sll         $t0, $a2, 1
        ctx->r8 = S32(ctx->r6 << 1);
            goto L_800968D0;
    }
    // 0x800968B0: sll         $t0, $a2, 1
    ctx->r8 = S32(ctx->r6 << 1);
    // 0x800968B4: addu        $v1, $a0, $t0
    ctx->r3 = ADD32(ctx->r4, ctx->r8);
    // 0x800968B8: lhu         $t1, 0x5C($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X5C);
    // 0x800968BC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800968C0: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x800968C4: sh          $t2, 0x5C($v1)
    MEM_H(0X5C, ctx->r3) = ctx->r10;
    // 0x800968C8: lw          $a3, -0xB44($a3)
    ctx->r7 = MEM_W(ctx->r7, -0XB44);
    // 0x800968CC: nop

L_800968D0:
    // 0x800968D0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800968D4: bne         $at, $zero, L_800968A0
    if (ctx->r1 != 0) {
        // 0x800968D8: addiu       $a0, $a0, 0x18
        ctx->r4 = ADD32(ctx->r4, 0X18);
            goto L_800968A0;
    }
    // 0x800968D8: addiu       $a0, $a0, 0x18
    ctx->r4 = ADD32(ctx->r4, 0X18);
L_800968DC:
    // 0x800968DC: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800968E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800968E4: sw          $t3, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r11;
    // 0x800968E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800968EC: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x800968F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800968F4: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    // 0x800968F8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800968FC: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x80096900: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80096904: sw          $zero, 0x6A68($at)
    MEM_W(0X6A68, ctx->r1) = 0;
    // 0x80096908: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009690C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80096910: sw          $t4, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = ctx->r12;
    // 0x80096914: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80096918: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009691C: sw          $zero, 0x988($at)
    MEM_W(0X988, ctx->r1) = 0;
    // 0x80096920: jal         0x8009C674
    // 0x80096924: addiu       $a0, $a0, 0xA24
    ctx->r4 = ADD32(ctx->r4, 0XA24);
    menu_assetgroup_load(rdram, ctx);
        goto after_1;
    // 0x80096924: addiu       $a0, $a0, 0xA24
    ctx->r4 = ADD32(ctx->r4, 0XA24);
    after_1:
    // 0x80096928: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009692C: jal         0x8009C8A4
    // 0x80096930: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    menu_imagegroup_load(rdram, ctx);
        goto after_2;
    // 0x80096930: addiu       $a0, $a0, 0xA40
    ctx->r4 = ADD32(ctx->r4, 0XA40);
    after_2:
    // 0x80096934: jal         0x80094604
    // 0x80096938: nop

    menu_racer_portraits(rdram, ctx);
        goto after_3;
    // 0x80096938: nop

    after_3:
    // 0x8009693C: jal         0x800C4170
    // 0x80096940: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_4;
    // 0x80096940: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80096944: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80096948: jal         0x800C01D8
    // 0x8009694C: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_5;
    // 0x8009694C: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_5:
    // 0x80096950: jal         0x80000BE0
    // 0x80096954: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_6;
    // 0x80096954: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_6:
    // 0x80096958: jal         0x80000B34
    // 0x8009695C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_7;
    // 0x8009695C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_7:
    // 0x80096960: jal         0x80000C98
    // 0x80096964: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    music_fade(rdram, ctx);
        goto after_8;
    // 0x80096964: addiu       $a0, $zero, 0x80
    ctx->r4 = ADD32(0, 0X80);
    after_8:
    // 0x80096968: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009696C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80096970: jr          $ra
    // 0x80096974: nop

    return;
    // 0x80096974: nop

;}
RECOMP_FUNC void charselect_render_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008B20C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008B210: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8008B214: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8008B218: slti        $at, $v0, -0x16
    ctx->r1 = SIGNED(ctx->r2) < -0X16 ? 1 : 0;
    // 0x8008B21C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8008B220: bne         $at, $zero, L_8008B348
    if (ctx->r1 != 0) {
        // 0x8008B224: sw          $a0, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r4;
            goto L_8008B348;
    }
    // 0x8008B224: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8008B228: slti        $at, $v0, 0x17
    ctx->r1 = SIGNED(ctx->r2) < 0X17 ? 1 : 0;
    // 0x8008B22C: beq         $at, $zero, L_8008B34C
    if (ctx->r1 == 0) {
        // 0x8008B230: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8008B34C;
    }
    // 0x8008B230: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8008B234: jal         0x800C42EC
    // 0x8008B238: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_text_font(rdram, ctx);
        goto after_0;
    // 0x8008B238: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008B23C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008B240: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B244: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008B248: jal         0x800C43CC
    // 0x8008B24C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_1;
    // 0x8008B24C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_1:
    // 0x8008B250: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8008B254: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8008B258: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008B25C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008B260: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008B264: jal         0x800C4384
    // 0x8008B268: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_2;
    // 0x8008B268: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_2:
    // 0x8008B26C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8008B270: lw          $t7, -0xB60($t7)
    ctx->r15 = MEM_W(ctx->r15, -0XB60);
    // 0x8008B274: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B278: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8008B27C: lw          $a3, 0x21C($t7)
    ctx->r7 = MEM_W(ctx->r15, 0X21C);
    // 0x8008B280: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8008B284: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8008B288: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x8008B28C: jal         0x800C4440
    // 0x8008B290: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_3;
    // 0x8008B290: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_3:
    // 0x8008B294: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8008B298: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8008B29C: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x8008B2A0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8008B2A4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8008B2A8: jal         0x800C4384
    // 0x8008B2AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_4;
    // 0x8008B2AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x8008B2B0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8008B2B4: lw          $t0, -0xB60($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB60);
    // 0x8008B2B8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B2BC: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x8008B2C0: lw          $a3, 0x21C($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X21C);
    // 0x8008B2C4: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8008B2C8: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8008B2CC: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x8008B2D0: jal         0x800C4440
    // 0x8008B2D4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x8008B2D4: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_5:
    // 0x8008B2D8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8008B2DC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8008B2E0: lw          $t2, -0xB80($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB80);
    // 0x8008B2E4: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x8008B2E8: nop

    // 0x8008B2EC: bne         $v0, $t2, L_8008B32C
    if (ctx->r2 != ctx->r10) {
        // 0x8008B2F0: nop
    
            goto L_8008B32C;
    }
    // 0x8008B2F0: nop

    // 0x8008B2F4: blez        $v0, L_8008B32C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8008B2F8: lui         $t3, 0x8000
        ctx->r11 = S32(0X8000 << 16);
            goto L_8008B32C;
    }
    // 0x8008B2F8: lui         $t3, 0x8000
    ctx->r11 = S32(0X8000 << 16);
    // 0x8008B2FC: lw          $t3, 0x300($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X300);
    // 0x8008B300: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // 0x8008B304: bne         $t3, $zero, L_8008B310
    if (ctx->r11 != 0) {
        // 0x8008B308: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8008B310;
    }
    // 0x8008B308: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B30C: addiu       $a2, $zero, 0xEA
    ctx->r6 = ADD32(0, 0XEA);
L_8008B310:
    // 0x8008B310: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x8008B314: addiu       $t4, $zero, 0xC
    ctx->r12 = ADD32(0, 0XC);
    // 0x8008B318: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8008B31C: addiu       $a3, $a3, -0x7DD0
    ctx->r7 = ADD32(ctx->r7, -0X7DD0);
    // 0x8008B320: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    // 0x8008B324: jal         0x800C4440
    // 0x8008B328: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x8008B328: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    after_6:
L_8008B32C:
    // 0x8008B32C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008B330: jal         0x8007B3D0
    // 0x8008B334: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    rendermode_reset(rdram, ctx);
        goto after_7;
    // 0x8008B334: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_7:
    // 0x8008B338: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8008B33C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8008B340: jal         0x800660EC
    // 0x8008B344: nop

    cam_set_fov(rdram, ctx);
        goto after_8;
    // 0x8008B344: nop

    after_8:
L_8008B348:
    // 0x8008B348: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8008B34C:
    // 0x8008B34C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    { extern int dkr_legacy_character_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*); static const uint32_t dkr_character_menu_fields[] = { 0x801263d4U, 0x801263dcU, 0x801263e8U, 0x801263f0U, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df480U, 0x800df4bcU, 0x800df47cU, 0x801263a0U, 0x801263ccU, 0x800e3690U, 0x800e36c8U, 0x80126808U, 0x801263c0U, 0x8011ae5cU, 0x8011aec8U }; dkr_legacy_character_menu(rdram, ctx, 2U, dkr_character_menu_fields); }
    // 0x8008B350: jr          $ra
    // 0x8008B354: nop

    return;
    // 0x8008B354: nop

;}
RECOMP_FUNC void sound_reverb_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002608: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000260C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80002610: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80002614: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x80002618: jal         0x8006492C
    // 0x8000261C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    alFxReverbSet(rdram, ctx);
        goto after_0;
    // 0x8000261C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_0:
    // 0x80002620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80002624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80002628: jr          $ra
    // 0x8000262C: nop

    return;
    // 0x8000262C: nop

;}
RECOMP_FUNC void get_ingame_map_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EB14: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006EB18: lw          $v0, 0x34F4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X34F4);
    // 0x8006EB1C: jr          $ra
    // 0x8006EB20: nop

    return;
    // 0x8006EB20: nop

;}
RECOMP_FUNC void light_toggle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032224: lbu         $t6, 0x4($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X4);
    // 0x80032228: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003222C: bne         $t6, $at, L_8003223C
    if (ctx->r14 != ctx->r1) {
        // 0x80032230: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8003223C;
    }
    // 0x80032230: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80032234: jr          $ra
    // 0x80032238: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
    return;
    // 0x80032238: sb          $zero, 0x4($a0)
    MEM_B(0X4, ctx->r4) = 0;
L_8003223C:
    // 0x8003223C: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x80032240: jr          $ra
    // 0x80032244: nop

    return;
    // 0x80032244: nop

;}
RECOMP_FUNC void spectate_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BC54: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001BC58: addiu       $a3, $a3, -0x5120
    ctx->r7 = ADD32(ctx->r7, -0X5120);
    // 0x8001BC5C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x8001BC60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001BC64: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x8001BC68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BC6C: blez        $v1, L_8001BD08
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001BC70: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001BD08;
    }
    // 0x8001BC70: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8001BC74: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001BC78: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8001BC7C: addiu       $t0, $t0, -0x51A8
    ctx->r8 = ADD32(ctx->r8, -0X51A8);
    // 0x8001BC80: addiu       $t2, $t2, -0x5124
    ctx->r10 = ADD32(ctx->r10, -0X5124);
    // 0x8001BC84: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
L_8001BC88:
    // 0x8001BC88: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x8001BC8C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001BC90: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x8001BC94: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8001BC98: nop

    // 0x8001BC9C: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x8001BCA0: nop

    // 0x8001BCA4: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x8001BCA8: bne         $t9, $zero, L_8001BD00
    if (ctx->r25 != 0) {
        // 0x8001BCAC: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001BD00;
    }
    // 0x8001BCAC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001BCB0: lh          $t3, 0x48($a0)
    ctx->r11 = MEM_H(ctx->r4, 0X48);
    // 0x8001BCB4: nop

    // 0x8001BCB8: bne         $t1, $t3, L_8001BD00
    if (ctx->r9 != ctx->r11) {
        // 0x8001BCBC: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001BD00;
    }
    // 0x8001BCBC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001BCC0: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x8001BCC4: nop

    // 0x8001BCC8: slti        $at, $a2, 0x14
    ctx->r1 = SIGNED(ctx->r6) < 0X14 ? 1 : 0;
    // 0x8001BCCC: beq         $at, $zero, L_8001BD00
    if (ctx->r1 == 0) {
        // 0x8001BCD0: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001BD00;
    }
    // 0x8001BCD0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001BCD4: lw          $t4, 0x0($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X0);
    // 0x8001BCD8: sll         $t5, $a2, 2
    ctx->r13 = S32(ctx->r6 << 2);
    // 0x8001BCDC: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8001BCE0: sw          $a0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r4;
    // 0x8001BCE4: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x8001BCE8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001BCEC: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x8001BCF0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x8001BCF4: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x8001BCF8: nop

    // 0x8001BCFC: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001BD00:
    // 0x8001BD00: bne         $at, $zero, L_8001BC88
    if (ctx->r1 != 0) {
        // 0x8001BD04: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001BC88;
    }
    // 0x8001BD04: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001BD08:
    // 0x8001BD08: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001BD0C: lw          $a2, -0x5120($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5120);
    // 0x8001BD10: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001BD14: addiu       $t2, $t2, -0x5124
    ctx->r10 = ADD32(ctx->r10, -0X5124);
    // 0x8001BD18: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001BD1C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8001BD20:
    // 0x8001BD20: blez        $a2, L_8001BD84
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001BD24: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001BD84;
    }
    // 0x8001BD24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001BD28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_8001BD2C:
    // 0x8001BD2C: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8001BD30: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001BD34: addu        $a3, $t9, $a1
    ctx->r7 = ADD32(ctx->r25, ctx->r5);
    // 0x8001BD38: lw          $t0, 0x4($a3)
    ctx->r8 = MEM_W(ctx->r7, 0X4);
    // 0x8001BD3C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8001BD40: lw          $t3, 0x78($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X78);
    // 0x8001BD44: lw          $t4, 0x78($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X78);
    // 0x8001BD48: nop

    // 0x8001BD4C: slt         $at, $t3, $t4
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001BD50: beq         $at, $zero, L_8001BD7C
    if (ctx->r1 == 0) {
        // 0x8001BD54: slt         $at, $v0, $a2
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001BD7C;
    }
    // 0x8001BD54: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001BD58: sw          $t0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r8;
    // 0x8001BD5C: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x8001BD60: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001BD64: addu        $t6, $t5, $a1
    ctx->r14 = ADD32(ctx->r13, ctx->r5);
    // 0x8001BD68: sw          $t1, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r9;
    // 0x8001BD6C: lw          $a2, -0x5120($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X5120);
    // 0x8001BD70: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8001BD74: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x8001BD78: slt         $at, $v0, $a2
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r6) ? 1 : 0;
L_8001BD7C:
    // 0x8001BD7C: bne         $at, $zero, L_8001BD2C
    if (ctx->r1 != 0) {
        // 0x8001BD80: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001BD2C;
    }
    // 0x8001BD80: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001BD84:
    // 0x8001BD84: beq         $v1, $zero, L_8001BD20
    if (ctx->r3 == 0) {
        // 0x8001BD88: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8001BD20;
    }
    // 0x8001BD88: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8001BD8C: jr          $ra
    // 0x8001BD90: nop

    return;
    // 0x8001BD90: nop

;}
RECOMP_FUNC void hud_race_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4C44: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800A4C48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4C4C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800A4C50: lb          $t6, 0x1D8($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A4C54: nop

    // 0x800A4C58: bne         $t6, $zero, L_800A4F44
    if (ctx->r14 != 0) {
        // 0x800A4C5C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A4F44;
    }
    // 0x800A4C5C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4C60: lh          $v1, 0x1AE($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X1AE);
    // 0x800A4C64: jal         0x8001139C
    // 0x800A4C68: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    get_race_countdown(rdram, ctx);
        goto after_0;
    // 0x800A4C68: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    after_0:
    // 0x800A4C6C: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800A4C70: beq         $v0, $zero, L_800A4CE0
    if (ctx->r2 == 0) {
        // 0x800A4C74: nop
    
            goto L_800A4CE0;
    }
    // 0x800A4C74: nop

    // 0x800A4C78: jal         0x8006BD98
    // 0x800A4C7C: nop

    level_type(rdram, ctx);
        goto after_1;
    // 0x800A4C7C: nop

    after_1:
    // 0x800A4C80: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800A4C84: beq         $v0, $at, L_800A4C9C
    if (ctx->r2 == ctx->r1) {
        // 0x800A4C88: nop
    
            goto L_800A4C9C;
    }
    // 0x800A4C88: nop

    // 0x800A4C8C: jal         0x8002341C
    // 0x800A4C90: nop

    is_taj_challenge(rdram, ctx);
        goto after_2;
    // 0x800A4C90: nop

    after_2:
    // 0x800A4C94: beq         $v0, $zero, L_800A4CA4
    if (ctx->r2 == 0) {
        // 0x800A4C98: nop
    
            goto L_800A4CA4;
    }
    // 0x800A4C98: nop

L_800A4C9C:
    // 0x800A4C9C: b           L_800A4CE0
    // 0x800A4CA0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
        goto L_800A4CE0;
    // 0x800A4CA0: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
L_800A4CA4:
    // 0x800A4CA4: jal         0x8006EA90
    // 0x800A4CA8: nop

    get_settings(rdram, ctx);
        goto after_3;
    // 0x800A4CA8: nop

    after_3:
    // 0x800A4CAC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A4CB0: lw          $t7, 0x6D10($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D10);
    // 0x800A4CB4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4CB8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A4CBC: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A4CC0: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800A4CC4: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A4CC8: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800A4CCC: lb          $v1, 0x5A($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X5A);
    // 0x800A4CD0: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A4CD4: nop

    // 0x800A4CD8: sh          $v1, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r3;
    // 0x800A4CDC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800A4CE0:
    // 0x800A4CE0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A4CE4: lw          $t2, 0x6D0C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D0C);
    // 0x800A4CE8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4CEC: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x800A4CF0: beq         $at, $zero, L_800A4D50
    if (ctx->r1 == 0) {
        // 0x800A4CF4: addiu       $t0, $t0, 0x6CDC
        ctx->r8 = ADD32(ctx->r8, 0X6CDC);
            goto L_800A4D50;
    }
    // 0x800A4CF4: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A4CF8: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800A4CFC: beq         $at, $zero, L_800A4D14
    if (ctx->r1 == 0) {
        // 0x800A4D00: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A4D14;
    }
    // 0x800A4D00: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4D04: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A4D08: addiu       $t3, $v1, -0x1
    ctx->r11 = ADD32(ctx->r3, -0X1);
    // 0x800A4D0C: b           L_800A4D20
    // 0x800A4D10: sh          $t3, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r11;
        goto L_800A4D20;
    // 0x800A4D10: sh          $t3, 0x38($t4)
    MEM_H(0X38, ctx->r12) = ctx->r11;
L_800A4D14:
    // 0x800A4D14: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A4D18: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x800A4D1C: sh          $t5, 0x38($t6)
    MEM_H(0X38, ctx->r14) = ctx->r13;
L_800A4D20:
    // 0x800A4D20: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A4D24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4D28: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4D2C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A4D30: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A4D34: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4D38: sw          $v1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r3;
    // 0x800A4D3C: jal         0x800AA600
    // 0x800A4D40: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A4D40: addiu       $a3, $a3, 0x20
    ctx->r7 = ADD32(ctx->r7, 0X20);
    after_4:
    // 0x800A4D44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4D48: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x800A4D4C: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
L_800A4D50:
    // 0x800A4D50: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A4D54: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800A4D58: lb          $t8, 0x1B($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X1B);
    // 0x800A4D5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A4D60: addiu       $t9, $t8, 0x81
    ctx->r25 = ADD32(ctx->r24, 0X81);
    // 0x800A4D64: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800A4D68: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x800A4D6C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A4D70: sw          $t4, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r12;
    // 0x800A4D74: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800A4D78: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800A4D7C: nop

    // 0x800A4D80: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800A4D84: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A4D88: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A4D8C: nop

    // 0x800A4D90: cvt.w.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800A4D94: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800A4D98: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800A4D9C: sll         $t2, $a0, 16
    ctx->r10 = S32(ctx->r4 << 16);
    // 0x800A4DA0: jal         0x800707C4
    // 0x800A4DA4: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    sins_f(rdram, ctx);
        goto after_5;
    // 0x800A4DA4: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_5:
    // 0x800A4DA8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4DAC: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A4DB0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A4DB4: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800A4DB8: lb          $t5, 0x1C($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X1C);
    // 0x800A4DBC: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A4DC0: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A4DC4: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A4DC8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A4DCC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A4DD0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A4DD4: div.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = DIV_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800A4DD8: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x800A4DDC: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800A4DE0: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A4DE4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800A4DE8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800A4DEC: lui         $at, 0x41C0
    ctx->r1 = S32(0X41C0 << 16);
    // 0x800A4DF0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A4DF4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A4DF8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A4DFC: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A4E00: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A4E04: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A4E08: add.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = ctx->f18.d + ctx->f16.d;
    // 0x800A4E0C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A4E10: add.d       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f8.d = ctx->f6.d + ctx->f4.d;
    // 0x800A4E14: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A4E18: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800A4E1C: swc1        $f10, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f10.u32l;
    // 0x800A4E20: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A4E24: nop

    // 0x800A4E28: lwc1        $f2, 0xC($v0)
    ctx->f2.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A4E2C: nop

    // 0x800A4E30: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x800A4E34: lwc1        $f16, 0x8($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X8);
    // 0x800A4E38: nop

    // 0x800A4E3C: mul.s       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f16.fl);
    // 0x800A4E40: sub.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f6.fl;
    // 0x800A4E44: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800A4E48: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A4E4C: jal         0x800AA600
    // 0x800A4E50: nop

    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A4E50: nop

    after_6:
    // 0x800A4E54: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4E58: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A4E5C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A4E60: lwc1        $f8, 0x30($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800A4E64: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800A4E68: swc1        $f8, 0xC($t6)
    MEM_W(0XC, ctx->r14) = ctx->f8.u32l;
    // 0x800A4E6C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A4E70: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x800A4E74: lb          $t7, 0x1A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1A);
    // 0x800A4E78: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800A4E7C: beq         $t7, $zero, L_800A4EB4
    if (ctx->r15 == 0) {
        // 0x800A4E80: nop
    
            goto L_800A4EB4;
    }
    // 0x800A4E80: nop

    // 0x800A4E84: lb          $v1, 0x1B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1B);
    // 0x800A4E88: subu        $t9, $a1, $t8
    ctx->r25 = SUB32(ctx->r5, ctx->r24);
    // 0x800A4E8C: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A4E90: beq         $at, $zero, L_800A4EA8
    if (ctx->r1 == 0) {
        // 0x800A4E94: addu        $t1, $v1, $t8
        ctx->r9 = ADD32(ctx->r3, ctx->r24);
            goto L_800A4EA8;
    }
    // 0x800A4E94: addu        $t1, $v1, $t8
    ctx->r9 = ADD32(ctx->r3, ctx->r24);
    // 0x800A4E98: sb          $t1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r9;
    // 0x800A4E9C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A4EA0: b           L_800A4EB8
    // 0x800A4EA4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_800A4EB8;
    // 0x800A4EA4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800A4EA8:
    // 0x800A4EA8: sb          $a1, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r5;
    // 0x800A4EAC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A4EB0: nop

L_800A4EB4:
    // 0x800A4EB4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800A4EB8:
    // 0x800A4EB8: lh          $t2, 0x18($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X18);
    // 0x800A4EBC: addiu       $a1, $zero, 0x7F
    ctx->r5 = ADD32(0, 0X7F);
    // 0x800A4EC0: beq         $a0, $t2, L_800A4F10
    if (ctx->r4 == ctx->r10) {
        // 0x800A4EC4: nop
    
            goto L_800A4F10;
    }
    // 0x800A4EC4: nop

    // 0x800A4EC8: lb          $t3, 0x1A($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X1A);
    // 0x800A4ECC: addiu       $t5, $zero, -0x7F
    ctx->r13 = ADD32(0, -0X7F);
    // 0x800A4ED0: beq         $t3, $zero, L_800A4EF8
    if (ctx->r11 == 0) {
        // 0x800A4ED4: nop
    
            goto L_800A4EF8;
    }
    // 0x800A4ED4: nop

    // 0x800A4ED8: lb          $v1, 0x1B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X1B);
    // 0x800A4EDC: nop

    // 0x800A4EE0: blez        $v1, L_800A4EF8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A4EE4: negu        $t4, $v1
        ctx->r12 = SUB32(0, ctx->r3);
            goto L_800A4EF8;
    }
    // 0x800A4EE4: negu        $t4, $v1
    ctx->r12 = SUB32(0, ctx->r3);
    // 0x800A4EE8: sb          $t4, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r12;
    // 0x800A4EEC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A4EF0: b           L_800A4F14
    // 0x800A4EF4: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
        goto L_800A4F14;
    // 0x800A4EF4: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
L_800A4EF8:
    // 0x800A4EF8: sb          $t5, 0x1B($v0)
    MEM_B(0X1B, ctx->r2) = ctx->r13;
    // 0x800A4EFC: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A4F00: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A4F04: sb          $t6, 0x1A($t7)
    MEM_B(0X1A, ctx->r15) = ctx->r14;
    // 0x800A4F08: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A4F0C: nop

L_800A4F10:
    // 0x800A4F10: sh          $a0, 0x18($v0)
    MEM_H(0X18, ctx->r2) = ctx->r4;
L_800A4F14:
    // 0x800A4F14: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A4F18: nop

    // 0x800A4F1C: lb          $t8, 0x1A($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1A);
    // 0x800A4F20: nop

    // 0x800A4F24: beq         $t8, $zero, L_800A4F44
    if (ctx->r24 == 0) {
        // 0x800A4F28: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A4F44;
    }
    // 0x800A4F28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4F2C: lb          $t9, 0x1B($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1B);
    // 0x800A4F30: nop

    // 0x800A4F34: bne         $a1, $t9, L_800A4F44
    if (ctx->r5 != ctx->r25) {
        // 0x800A4F38: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A4F44;
    }
    // 0x800A4F38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A4F3C: sb          $zero, 0x1A($v0)
    MEM_B(0X1A, ctx->r2) = 0;
    // 0x800A4F40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A4F44:
    // 0x800A4F44: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800A4F48: jr          $ra
    // 0x800A4F4C: nop

    return;
    // 0x800A4F4C: nop

;}
RECOMP_FUNC void racer_sound_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_enter_vehicle_audio_scope(uint8_t*, recomp_context*); dkr_enter_vehicle_audio_scope(rdram, ctx);
    // 0x80006FC8: addiu       $sp, $sp, -0xC8
    ctx->r29 = ADD32(ctx->r29, -0XC8);
    // 0x80006FCC: sw          $s7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r23;
    // 0x80006FD0: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80006FD4: or          $s7, $a2, $zero
    ctx->r23 = ctx->r6 | 0;
    // 0x80006FD8: sw          $ra, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r31;
    // 0x80006FDC: sw          $fp, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r30;
    // 0x80006FE0: sw          $s6, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r22;
    // 0x80006FE4: sw          $s5, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r21;
    // 0x80006FE8: sw          $s4, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r20;
    // 0x80006FEC: sw          $s3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r19;
    // 0x80006FF0: sw          $s2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r18;
    // 0x80006FF4: sw          $s1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r17;
    // 0x80006FF8: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80006FFC: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80007000: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x80007004: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80007008: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x8000700C: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80007010: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80007014: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80007018: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x8000701C: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80007020: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80007024: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80007028: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8000702C: sw          $a0, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r4;
    // 0x80007030: sw          $a1, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->r5;
    // 0x80007034: sw          $a3, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->r7;
    // 0x80007038: sw          $t6, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r14;
    // 0x8000703C: blez        $t6, L_80007750
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80007040: sw          $zero, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = 0;
            goto L_80007750;
    }
    // 0x80007040: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80007044: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007048: lwc1        $f30, 0x4CC4($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X4CC4);
    // 0x8000704C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007050: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80007054: lwc1        $f29, 0x4CC8($at)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r1, 0X4CC8);
    // 0x80007058: lwc1        $f28, 0x4CCC($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X4CCC);
    // 0x8000705C: mtc1        $zero, $f25
    ctx->f_odd[(25 - 1) * 2] = 0;
    // 0x80007060: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80007064: lw          $fp, 0xD8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XD8);
    // 0x80007068: addiu       $s4, $s4, -0x63C8
    ctx->r20 = ADD32(ctx->r20, -0X63C8);
    // 0x8000706C: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
L_80007070:
    // 0x80007070: lw          $t8, 0x0($s6)
    ctx->r24 = MEM_W(ctx->r22, 0X0);
    // 0x80007074: nop

    // 0x80007078: lw          $s1, 0x64($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X64);
    // 0x8000707C: nop

    // 0x80007080: beq         $s1, $zero, L_80007094
    if (ctx->r17 == 0) {
        // 0x80007084: nop
    
            goto L_80007094;
    }
    // 0x80007084: nop

    // 0x80007088: lw          $t9, 0x118($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X118);
    // 0x8000708C: b           L_80007098
    // 0x80007090: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
        goto L_80007098;
    // 0x80007090: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
L_80007094:
    // 0x80007094: sw          $zero, 0x0($s4)
    MEM_W(0X0, ctx->r20) = 0;
L_80007098:
    // 0x80007098: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x8000709C: nop

    // 0x800070A0: beq         $s0, $zero, L_8000773C
    if (ctx->r16 == 0) {
        // 0x800070A4: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x800070A4: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800070A8: lhu         $t0, 0x0($s0)
    ctx->r8 = MEM_HU(ctx->r16, 0X0);
    // 0x800070AC: nop

    // 0x800070B0: beq         $t0, $zero, L_8000773C
    if (ctx->r8 == 0) {
        // 0x800070B4: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x800070B4: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800070B8: lb          $t1, 0x1D8($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D8);
    // 0x800070BC: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800070C0: bne         $t1, $zero, L_800070DC
    if (ctx->r9 != 0) {
        // 0x800070C4: lw          $t2, 0xAC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XAC);
            goto L_800070DC;
    }
    // 0x800070C4: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x800070C8: jal         0x80066510
    // 0x800070CC: nop

    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_0;
    // 0x800070CC: nop

    after_0:
    // 0x800070D0: beq         $v0, $zero, L_800071F0
    if (ctx->r2 == 0) {
        // 0x800070D4: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800071F0;
    }
    // 0x800070D4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800070D8: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
L_800070DC:
    // 0x800070DC: lw          $a2, 0x0($s6)
    ctx->r6 = MEM_W(ctx->r22, 0X0);
    // 0x800070E0: sll         $t3, $t2, 4
    ctx->r11 = S32(ctx->r10 << 4);
    // 0x800070E4: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800070E8: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800070EC: addu        $v1, $s7, $t3
    ctx->r3 = ADD32(ctx->r23, ctx->r11);
    // 0x800070F0: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x800070F4: lwc1        $f10, 0x10($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800070F8: lwc1        $f18, 0x14($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800070FC: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80007100: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80007104: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80007108: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8000710C: sw          $v1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r3;
    // 0x80007110: swc1        $f0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f0.u32l;
    // 0x80007114: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x80007118: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x8000711C: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80007120: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80007124: jal         0x80006BFC
    // 0x80007128: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    racer_sound_doppler_effect(rdram, ctx);
        goto after_1;
    // 0x80007128: sub.s       $f22, $f16, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f22.fl = ctx->f16.fl - ctx->f18.fl;
    after_1:
    // 0x8000712C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x80007130: lwc1        $f0, 0xC0($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0XC0);
    // 0x80007134: nop

    // 0x80007138: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000713C: nop

    // 0x80007140: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x80007144: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80007148: jal         0x800C9AD0
    // 0x8000714C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8000714C: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80007150: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80007154: lw          $v1, 0x70($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X70);
    // 0x80007158: swc1        $f0, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->f0.u32l;
    // 0x8000715C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007160: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007164: lwc1        $f16, 0x4CD0($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4CD0);
    // 0x80007168: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x8000716C: nop

    // 0x80007170: c.lt.s      $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f2.fl < ctx->f16.fl;
    // 0x80007174: nop

    // 0x80007178: bc1f        L_800071C0
    if (!c1cs) {
        // 0x8000717C: nop
    
            goto L_800071C0;
    }
    // 0x8000717C: nop

    // 0x80007180: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80007184: lh          $a2, 0x0($v1)
    ctx->r6 = MEM_H(ctx->r3, 0X0);
    // 0x80007188: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x8000718C: sub.s       $f4, $f30, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f30.fl - ctx->f18.fl;
    // 0x80007190: nop

    // 0x80007194: div.s       $f26, $f4, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = DIV_S(ctx->f4.fl, ctx->f30.fl);
    // 0x80007198: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    // 0x8000719C: mul.s       $f26, $f26, $f26
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f26.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x800071A0: jal         0x800090C0
    // 0x800071A4: nop

    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_3;
    // 0x800071A4: nop

    after_3:
    // 0x800071A8: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800071AC: nop

    // 0x800071B0: sb          $v0, 0x91($t5)
    MEM_B(0X91, ctx->r13) = ctx->r2;
    // 0x800071B4: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800071B8: b           L_800071CC
    // 0x800071BC: lb          $t6, 0x1D8($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D8);
        goto L_800071CC;
    // 0x800071BC: lb          $t6, 0x1D8($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D8);
L_800071C0:
    // 0x800071C0: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800071C4: nop

    // 0x800071C8: lb          $t6, 0x1D8($s1)
    ctx->r14 = MEM_B(ctx->r17, 0X1D8);
L_800071CC:
    // 0x800071CC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800071D0: bne         $t6, $zero, L_80007214
    if (ctx->r14 != 0) {
        // 0x800071D4: nop
    
            goto L_80007214;
    }
    // 0x800071D4: nop

    // 0x800071D8: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800071DC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800071E0: cvt.d.s     $f6, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f6.d = CVT_D_S(ctx->f26.fl);
    // 0x800071E4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800071E8: b           L_80007214
    // 0x800071EC: cvt.s.d     $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f26.fl = CVT_S_D(ctx->f10.d);
        goto L_80007214;
    // 0x800071EC: cvt.s.d     $f26, $f10
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f26.fl = CVT_S_D(ctx->f10.d);
L_800071F0:
    // 0x800071F0: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800071F4: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x800071F8: sb          $t7, 0x91($t8)
    MEM_B(0X91, ctx->r24) = ctx->r15;
    // 0x800071FC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80007200: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80007204: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80007208: swc1        $f16, 0x68($t9)
    MEM_W(0X68, ctx->r25) = ctx->f16.u32l;
    // 0x8000720C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007210: nop

L_80007214:
    // 0x80007214: lbu         $v0, 0xA0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XA0);
    // 0x80007218: nop

    // 0x8000721C: slti        $at, $v0, 0x46
    ctx->r1 = SIGNED(ctx->r2) < 0X46 ? 1 : 0;
    // 0x80007220: beq         $at, $zero, L_80007498
    if (ctx->r1 == 0) {
        // 0x80007224: nop
    
            goto L_80007498;
    }
    // 0x80007224: nop

    // 0x80007228: lbu         $a0, 0x36($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X36);
    // 0x8000722C: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80007230: beq         $a0, $zero, L_80007498
    if (ctx->r4 == 0) {
        // 0x80007234: slti        $at, $t0, 0x3
        ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
            goto L_80007498;
    }
    // 0x80007234: slti        $at, $t0, 0x3
    ctx->r1 = SIGNED(ctx->r8) < 0X3 ? 1 : 0;
    // 0x80007238: beq         $at, $zero, L_80007498
    if (ctx->r1 == 0) {
        // 0x8000723C: nop
    
            goto L_80007498;
    }
    // 0x8000723C: nop

    // 0x80007240: cvt.d.s     $f18, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f18.d = CVT_D_S(ctx->f26.fl);
    // 0x80007244: c.eq.d      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.d == ctx->f18.d;
    // 0x80007248: nop

    // 0x8000724C: bc1t        L_80007498
    if (c1cs) {
        // 0x80007250: nop
    
            goto L_80007498;
    }
    // 0x80007250: nop

    // 0x80007254: lbu         $t1, 0x44($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X44);
    // 0x80007258: nop

    // 0x8000725C: andi        $t2, $t1, 0x1
    ctx->r10 = ctx->r9 & 0X1;
    // 0x80007260: bne         $t2, $zero, L_80007498
    if (ctx->r10 != 0) {
        // 0x80007264: nop
    
            goto L_80007498;
    }
    // 0x80007264: nop

    // 0x80007268: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8000726C: bgez        $v0, L_80007284
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80007270: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80007284;
    }
    // 0x80007270: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80007274: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80007278: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000727C: nop

    // 0x80007280: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80007284:
    // 0x80007284: lbu         $t3, 0x37($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X37);
    // 0x80007288: lui         $at, 0x428C
    ctx->r1 = S32(0X428C << 16);
    // 0x8000728C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80007290: mtc1        $t3, $f16
    ctx->f16.u32l = ctx->r11;
    // 0x80007294: div.s       $f20, $f6, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80007298: bgez        $t3, L_800072B0
    if (SIGNED(ctx->r11) >= 0) {
        // 0x8000729C: cvt.s.w     $f0, $f16
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800072B0;
    }
    // 0x8000729C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800072A0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800072A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800072A8: nop

    // 0x800072AC: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_800072B0:
    // 0x800072B0: mul.s       $f4, $f0, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x800072B4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800072B8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800072BC: sub.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800072C0: mul.s       $f6, $f8, $f26
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f26.fl);
    // 0x800072C4: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800072C8: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800072CC: nop

    // 0x800072D0: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800072D4: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x800072D8: nop

    // 0x800072DC: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x800072E0: beq         $s2, $zero, L_8000732C
    if (ctx->r18 == 0) {
        // 0x800072E4: nop
    
            goto L_8000732C;
    }
    // 0x800072E4: nop

    // 0x800072E8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800072EC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800072F0: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800072F4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800072F8: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x800072FC: nop

    // 0x80007300: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80007304: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x80007308: nop

    // 0x8000730C: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x80007310: bne         $s2, $zero, L_80007324
    if (ctx->r18 != 0) {
        // 0x80007314: nop
    
            goto L_80007324;
    }
    // 0x80007314: nop

    // 0x80007318: mfc1        $s2, $f10
    ctx->r18 = (int32_t)ctx->f10.u32l;
    // 0x8000731C: b           L_8000733C
    // 0x80007320: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
        goto L_8000733C;
    // 0x80007320: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
L_80007324:
    // 0x80007324: b           L_8000733C
    // 0x80007328: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
        goto L_8000733C;
    // 0x80007328: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_8000732C:
    // 0x8000732C: mfc1        $s2, $f10
    ctx->r18 = (int32_t)ctx->f10.u32l;
    // 0x80007330: nop

    // 0x80007334: bltz        $s2, L_80007324
    if (SIGNED(ctx->r18) < 0) {
        // 0x80007338: nop
    
            goto L_80007324;
    }
    // 0x80007338: nop

L_8000733C:
    // 0x8000733C: andi        $s3, $s2, 0xFF
    ctx->r19 = ctx->r18 & 0XFF;
    // 0x80007340: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80007344: slti        $at, $s3, 0x10
    ctx->r1 = SIGNED(ctx->r19) < 0X10 ? 1 : 0;
    // 0x80007348: bne         $at, $zero, L_80007468
    if (ctx->r1 != 0) {
        // 0x8000734C: nop
    
            goto L_80007468;
    }
    // 0x8000734C: nop

    // 0x80007350: lw          $t6, 0x50($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X50);
    // 0x80007354: nop

    // 0x80007358: bne         $t6, $zero, L_80007370
    if (ctx->r14 != 0) {
        // 0x8000735C: nop
    
            goto L_80007370;
    }
    // 0x8000735C: nop

    // 0x80007360: jal         0x80001F14
    // 0x80007364: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    sound_play_direct(rdram, ctx);
        goto after_4;
    // 0x80007364: addiu       $a1, $s0, 0x50
    ctx->r5 = ADD32(ctx->r16, 0X50);
    after_4:
    // 0x80007368: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x8000736C: nop

L_80007370:
    // 0x80007370: lbu         $t7, 0x38($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X38);
    // 0x80007374: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80007378: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x8000737C: bgez        $t7, L_80007390
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80007380: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80007390;
    }
    // 0x80007380: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80007384: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80007388: nop

    // 0x8000738C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80007390:
    // 0x80007390: lbu         $t8, 0x39($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X39);
    // 0x80007394: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80007398: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8000739C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800073A0: div.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800073A4: bgez        $t8, L_800073BC
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800073A8: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800073BC;
    }
    // 0x800073A8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800073AC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800073B0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800073B4: nop

    // 0x800073B8: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800073BC:
    // 0x800073BC: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800073C0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800073C4: nop

    // 0x800073C8: div.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800073CC: sub.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x800073D0: mul.s       $f6, $f8, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800073D4: add.s       $f16, $f0, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800073D8: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
    // 0x800073DC: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x800073E0: nop

    // 0x800073E4: beq         $a0, $zero, L_800074C4
    if (ctx->r4 == 0) {
        // 0x800073E8: nop
    
            goto L_800074C4;
    }
    // 0x800073E8: nop

    // 0x800073EC: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x800073F0: nop

    // 0x800073F4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800073F8: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x800073FC: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80007400: jal         0x80009B7C
    // 0x80007404: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_5;
    // 0x80007404: nop

    after_5:
    // 0x80007408: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8000740C: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80007410: lw          $a0, 0x50($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X50);
    // 0x80007414: jal         0x800049F8
    // 0x80007418: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    sndp_set_param(rdram, ctx);
        goto after_6;
    // 0x80007418: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    after_6:
    // 0x8000741C: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80007420: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x80007424: lw          $a0, 0x50($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X50);
    // 0x80007428: jal         0x800049F8
    // 0x8000742C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_7;
    // 0x8000742C: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_7:
    // 0x80007430: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80007434: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x80007438: lw          $a0, 0x50($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X50);
    // 0x8000743C: jal         0x80004604
    // 0x80007440: nop

    sndp_set_priority(rdram, ctx);
        goto after_8;
    // 0x80007440: nop

    after_8:
    // 0x80007444: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007448: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8000744C: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x80007450: lbu         $a2, 0x91($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X91);
    // 0x80007454: jal         0x800049F8
    // 0x80007458: nop

    sndp_set_param(rdram, ctx);
        goto after_9;
    // 0x80007458: nop

    after_9:
    // 0x8000745C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007460: b           L_800074C8
    // 0x80007464: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
        goto L_800074C8;
    // 0x80007464: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
L_80007468:
    // 0x80007468: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000746C: nop

    // 0x80007470: beq         $a0, $zero, L_800074C4
    if (ctx->r4 == 0) {
        // 0x80007474: nop
    
            goto L_800074C4;
    }
    // 0x80007474: nop

    // 0x80007478: jal         0x8000488C
    // 0x8000747C: nop

    sndp_stop(rdram, ctx);
        goto after_10;
    // 0x8000747C: nop

    after_10:
    // 0x80007480: lw          $t2, 0x0($s4)
    ctx->r10 = MEM_W(ctx->r20, 0X0);
    // 0x80007484: nop

    // 0x80007488: sw          $zero, 0x50($t2)
    MEM_W(0X50, ctx->r10) = 0;
    // 0x8000748C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007490: b           L_800074C8
    // 0x80007494: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
        goto L_800074C8;
    // 0x80007494: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
L_80007498:
    // 0x80007498: lw          $a0, 0x50($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X50);
    // 0x8000749C: nop

    // 0x800074A0: beq         $a0, $zero, L_800074C4
    if (ctx->r4 == 0) {
        // 0x800074A4: nop
    
            goto L_800074C4;
    }
    // 0x800074A4: nop

    // 0x800074A8: jal         0x8000488C
    // 0x800074AC: nop

    sndp_stop(rdram, ctx);
        goto after_11;
    // 0x800074AC: nop

    after_11:
    // 0x800074B0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800074B4: nop

    // 0x800074B8: sw          $zero, 0x50($t3)
    MEM_W(0X50, ctx->r11) = 0;
    // 0x800074BC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800074C0: nop

L_800074C4:
    // 0x800074C4: lhu         $t4, 0x0($s0)
    ctx->r12 = MEM_HU(ctx->r16, 0X0);
L_800074C8:
    // 0x800074C8: nop

    // 0x800074CC: beq         $t4, $zero, L_8000773C
    if (ctx->r12 == 0) {
        // 0x800074D0: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x800074D0: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x800074D4: cvt.d.s     $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); 
    ctx->f20.d = CVT_D_S(ctx->f26.fl);
    // 0x800074D8: c.eq.d      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.d == ctx->f20.d;
    // 0x800074DC: sll         $s1, $s5, 2
    ctx->r17 = S32(ctx->r21 << 2);
    // 0x800074E0: bc1t        L_80007738
    if (c1cs) {
        // 0x800074E4: addu        $v0, $s0, $s1
        ctx->r2 = ADD32(ctx->r16, ctx->r17);
            goto L_80007738;
    }
    // 0x800074E4: addu        $v0, $s0, $s1
    ctx->r2 = ADD32(ctx->r16, ctx->r17);
L_800074E8:
    // 0x800074E8: lwc1        $f10, 0x54($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X54);
    // 0x800074EC: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x800074F0: mul.s       $f4, $f10, $f26
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f26.fl);
    // 0x800074F4: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800074F8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800074FC: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x80007500: nop

    // 0x80007504: cvt.w.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80007508: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x8000750C: nop

    // 0x80007510: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x80007514: beq         $s2, $zero, L_80007560
    if (ctx->r18 == 0) {
        // 0x80007518: nop
    
            goto L_80007560;
    }
    // 0x80007518: nop

    // 0x8000751C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80007520: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80007524: sub.s       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80007528: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000752C: ctc1        $s2, $FpcCsr
    set_cop1_cs(ctx->r18);
    // 0x80007530: nop

    // 0x80007534: cvt.w.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80007538: cfc1        $s2, $FpcCsr
    ctx->r18 = get_cop1_cs();
    // 0x8000753C: nop

    // 0x80007540: andi        $s2, $s2, 0x78
    ctx->r18 = ctx->r18 & 0X78;
    // 0x80007544: bne         $s2, $zero, L_80007558
    if (ctx->r18 != 0) {
        // 0x80007548: nop
    
            goto L_80007558;
    }
    // 0x80007548: nop

    // 0x8000754C: mfc1        $s2, $f18
    ctx->r18 = (int32_t)ctx->f18.u32l;
    // 0x80007550: b           L_80007570
    // 0x80007554: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
        goto L_80007570;
    // 0x80007554: or          $s2, $s2, $at
    ctx->r18 = ctx->r18 | ctx->r1;
L_80007558:
    // 0x80007558: b           L_80007570
    // 0x8000755C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
        goto L_80007570;
    // 0x8000755C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
L_80007560:
    // 0x80007560: mfc1        $s2, $f18
    ctx->r18 = (int32_t)ctx->f18.u32l;
    // 0x80007564: nop

    // 0x80007568: bltz        $s2, L_80007558
    if (SIGNED(ctx->r18) < 0) {
        // 0x8000756C: nop
    
            goto L_80007558;
    }
    // 0x8000756C: nop

L_80007570:
    // 0x80007570: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80007574: lwc1        $f8, 0x5C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X5C);
    // 0x80007578: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x8000757C: lwc1        $f10, 0x94($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X94);
    // 0x80007580: add.s       $f16, $f8, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80007584: lwc1        $f18, 0x68($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80007588: add.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8000758C: andi        $t6, $s2, 0xFF
    ctx->r14 = ctx->r18 & 0XFF;
    // 0x80007590: add.s       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80007594: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x80007598: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8000759C: c.lt.d      $f6, $f28
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f6.d < ctx->f28.d;
    // 0x800075A0: swc1        $f8, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f8.u32l;
    // 0x800075A4: bc1f        L_800075B8
    if (!c1cs) {
        // 0x800075A8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800075B8;
    }
    // 0x800075A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800075AC: lwc1        $f16, 0x4CD4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X4CD4);
    // 0x800075B0: nop

    // 0x800075B4: swc1        $f16, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f16.u32l;
L_800075B8:
    // 0x800075B8: bne         $s5, $zero, L_800075F8
    if (ctx->r21 != 0) {
        // 0x800075BC: nop
    
            goto L_800075F8;
    }
    // 0x800075BC: nop

    // 0x800075C0: lbu         $t7, 0x44($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X44);
    // 0x800075C4: nop

    // 0x800075C8: andi        $t8, $t7, 0x1
    ctx->r24 = ctx->r15 & 0X1;
    // 0x800075CC: beq         $t8, $zero, L_800075F8
    if (ctx->r24 == 0) {
        // 0x800075D0: nop
    
            goto L_800075F8;
    }
    // 0x800075D0: nop

    // 0x800075D4: lw          $a0, 0x48($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X48);
    // 0x800075D8: nop

    // 0x800075DC: beq         $a0, $zero, L_800076FC
    if (ctx->r4 == 0) {
        // 0x800075E0: nop
    
            goto L_800076FC;
    }
    // 0x800075E0: nop

    // 0x800075E4: jal         0x8000488C
    // 0x800075E8: nop

    sndp_stop(rdram, ctx);
        goto after_12;
    // 0x800075E8: nop

    after_12:
    // 0x800075EC: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800075F0: b           L_800076FC
    // 0x800075F4: sw          $zero, 0x48($t9)
    MEM_W(0X48, ctx->r25) = 0;
        goto L_800076FC;
    // 0x800075F4: sw          $zero, 0x48($t9)
    MEM_W(0X48, ctx->r25) = 0;
L_800075F8:
    // 0x800075F8: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x800075FC: nop

    // 0x80007600: beq         $a0, $zero, L_8000762C
    if (ctx->r4 == 0) {
        // 0x80007604: nop
    
            goto L_8000762C;
    }
    // 0x80007604: nop

    // 0x80007608: bne         $s2, $zero, L_8000762C
    if (ctx->r18 != 0) {
        // 0x8000760C: nop
    
            goto L_8000762C;
    }
    // 0x8000760C: nop

    // 0x80007610: jal         0x8000488C
    // 0x80007614: nop

    sndp_stop(rdram, ctx);
        goto after_13;
    // 0x80007614: nop

    after_13:
    // 0x80007618: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x8000761C: nop

    // 0x80007620: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x80007624: b           L_800076FC
    // 0x80007628: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
        goto L_800076FC;
    // 0x80007628: sw          $zero, 0x48($t1)
    MEM_W(0X48, ctx->r9) = 0;
L_8000762C:
    // 0x8000762C: bne         $a0, $zero, L_80007658
    if (ctx->r4 != 0) {
        // 0x80007630: sll         $t2, $s5, 1
        ctx->r10 = S32(ctx->r21 << 1);
            goto L_80007658;
    }
    // 0x80007630: sll         $t2, $s5, 1
    ctx->r10 = S32(ctx->r21 << 1);
    // 0x80007634: addu        $t3, $s0, $t2
    ctx->r11 = ADD32(ctx->r16, ctx->r10);
    // 0x80007638: lhu         $a0, 0x0($t3)
    ctx->r4 = MEM_HU(ctx->r11, 0X0);
    // 0x8000763C: jal         0x80001F14
    // 0x80007640: addiu       $a1, $v0, 0x48
    ctx->r5 = ADD32(ctx->r2, 0X48);
    sound_play_direct(rdram, ctx);
        goto after_14;
    // 0x80007640: addiu       $a1, $v0, 0x48
    ctx->r5 = ADD32(ctx->r2, 0X48);
    after_14:
    // 0x80007644: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x80007648: nop

    // 0x8000764C: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80007650: lw          $a0, 0x48($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X48);
    // 0x80007654: nop

L_80007658:
    // 0x80007658: beq         $a0, $zero, L_800076FC
    if (ctx->r4 == 0) {
        // 0x8000765C: nop
    
            goto L_800076FC;
    }
    // 0x8000765C: nop

    // 0x80007660: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x80007664: or          $s3, $s2, $zero
    ctx->r19 = ctx->r18 | 0;
    // 0x80007668: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8000766C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80007670: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80007674: jal         0x80009B7C
    // 0x80007678: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_15;
    // 0x80007678: nop

    after_15:
    // 0x8000767C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80007680: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80007684: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80007688: lw          $a0, 0x48($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X48);
    // 0x8000768C: jal         0x800049F8
    // 0x80007690: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    sndp_set_param(rdram, ctx);
        goto after_16;
    // 0x80007690: sll         $a2, $s3, 8
    ctx->r6 = S32(ctx->r19 << 8);
    after_16:
    // 0x80007694: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80007698: lw          $a2, 0x8C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X8C);
    // 0x8000769C: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x800076A0: lw          $a0, 0x48($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X48);
    // 0x800076A4: jal         0x800049F8
    // 0x800076A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_17;
    // 0x800076A8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_17:
    // 0x800076AC: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800076B0: addiu       $a1, $zero, 0x50
    ctx->r5 = ADD32(0, 0X50);
    // 0x800076B4: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800076B8: lw          $a0, 0x48($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X48);
    // 0x800076BC: jal         0x80004604
    // 0x800076C0: nop

    sndp_set_priority(rdram, ctx);
        goto after_18;
    // 0x800076C0: nop

    after_18:
    // 0x800076C4: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800076C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800076CC: beq         $t2, $at, L_800076E0
    if (ctx->r10 == ctx->r1) {
        // 0x800076D0: nop
    
            goto L_800076E0;
    }
    // 0x800076D0: nop

    // 0x800076D4: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x800076D8: addiu       $t3, $zero, 0x40
    ctx->r11 = ADD32(0, 0X40);
    // 0x800076DC: sb          $t3, 0x91($t4)
    MEM_B(0X91, ctx->r12) = ctx->r11;
L_800076E0:
    // 0x800076E0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800076E4: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x800076E8: addu        $t5, $s0, $s1
    ctx->r13 = ADD32(ctx->r16, ctx->r17);
    // 0x800076EC: lw          $a0, 0x48($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X48);
    // 0x800076F0: lbu         $a2, 0x91($s0)
    ctx->r6 = MEM_BU(ctx->r16, 0X91);
    // 0x800076F4: jal         0x800049F8
    // 0x800076F8: nop

    sndp_set_param(rdram, ctx);
        goto after_19;
    // 0x800076F8: nop

    after_19:
L_800076FC:
    // 0x800076FC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80007700: slti        $at, $s5, 0x2
    ctx->r1 = SIGNED(ctx->r21) < 0X2 ? 1 : 0;
    // 0x80007704: beq         $at, $zero, L_80007738
    if (ctx->r1 == 0) {
        // 0x80007708: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_80007738;
    }
    // 0x80007708: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8000770C: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007710: sll         $t6, $s5, 1
    ctx->r14 = S32(ctx->r21 << 1);
    // 0x80007714: addu        $t7, $s0, $t6
    ctx->r15 = ADD32(ctx->r16, ctx->r14);
    // 0x80007718: lhu         $t8, 0x0($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X0);
    // 0x8000771C: nop

    // 0x80007720: beq         $t8, $zero, L_8000773C
    if (ctx->r24 == 0) {
        // 0x80007724: lw          $t9, 0xAC($sp)
        ctx->r25 = MEM_W(ctx->r29, 0XAC);
            goto L_8000773C;
    }
    // 0x80007724: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
    // 0x80007728: c.eq.d      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.d == ctx->f20.d;
    // 0x8000772C: nop

    // 0x80007730: bc1f        L_800074E8
    if (!c1cs) {
        // 0x80007734: addu        $v0, $s0, $s1
        ctx->r2 = ADD32(ctx->r16, ctx->r17);
            goto L_800074E8;
    }
    // 0x80007734: addu        $v0, $s0, $s1
    ctx->r2 = ADD32(ctx->r16, ctx->r17);
L_80007738:
    // 0x80007738: lw          $t9, 0xAC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XAC);
L_8000773C:
    // 0x8000773C: lw          $t1, 0x7C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X7C);
    // 0x80007740: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80007744: sw          $t0, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r8;
    // 0x80007748: bne         $t0, $t1, L_80007070
    if (ctx->r8 != ctx->r9) {
        // 0x8000774C: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_80007070;
    }
    // 0x8000774C: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80007750:
    // 0x80007750: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007754: lwc1        $f29, 0x4CD8($at)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r1, 0X4CD8);
    // 0x80007758: lwc1        $f28, 0x4CDC($at)
    ctx->f28.u32l = MEM_W(ctx->r1, 0X4CDC);
    // 0x8000775C: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x80007760: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007764: lwc1        $f30, 0x4CE0($at)
    ctx->f30.u32l = MEM_W(ctx->r1, 0X4CE0);
    // 0x80007768: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8000776C: lw          $fp, 0xD8($sp)
    ctx->r30 = MEM_W(ctx->r29, 0XD8);
    // 0x80007770: slti        $at, $t2, 0x3
    ctx->r1 = SIGNED(ctx->r10) < 0X3 ? 1 : 0;
    // 0x80007774: beq         $at, $zero, L_80007F18
    if (ctx->r1 == 0) {
        // 0x80007778: addiu       $s4, $s4, -0x63C8
        ctx->r20 = ADD32(ctx->r20, -0X63C8);
            goto L_80007F18;
    }
    // 0x80007778: addiu       $s4, $s4, -0x63C8
    ctx->r20 = ADD32(ctx->r20, -0X63C8);
    // 0x8000777C: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80007780: or          $s5, $t2, $zero
    ctx->r21 = ctx->r10 | 0;
    // 0x80007784: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80007788: beq         $at, $zero, L_800078C0
    if (ctx->r1 == 0) {
        // 0x8000778C: sw          $zero, 0xAC($sp)
        MEM_W(0XAC, ctx->r29) = 0;
            goto L_800078C0;
    }
    // 0x8000778C: sw          $zero, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = 0;
    // 0x80007790: subu        $v1, $t4, $t2
    ctx->r3 = SUB32(ctx->r12, ctx->r10);
    // 0x80007794: andi        $t5, $v1, 0x3
    ctx->r13 = ctx->r3 & 0X3;
    // 0x80007798: beq         $t5, $zero, L_800077F0
    if (ctx->r13 == 0) {
        // 0x8000779C: addu        $v0, $t5, $t2
        ctx->r2 = ADD32(ctx->r13, ctx->r10);
            goto L_800077F0;
    }
    // 0x8000779C: addu        $v0, $t5, $t2
    ctx->r2 = ADD32(ctx->r13, ctx->r10);
    // 0x800077A0: lw          $t6, 0xC8($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC8);
    // 0x800077A4: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800077A8: addu        $s2, $t6, $t7
    ctx->r18 = ADD32(ctx->r14, ctx->r15);
L_800077AC:
    // 0x800077AC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800077B0: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800077B4: lw          $s1, 0x64($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X64);
    // 0x800077B8: nop

    // 0x800077BC: beq         $s1, $zero, L_800077D8
    if (ctx->r17 == 0) {
        // 0x800077C0: nop
    
            goto L_800077D8;
    }
    // 0x800077C0: nop

    // 0x800077C4: lw          $t9, 0x118($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X118);
    // 0x800077C8: nop

    // 0x800077CC: beq         $t9, $zero, L_800077D8
    if (ctx->r25 == 0) {
        // 0x800077D0: sw          $t9, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r25;
            goto L_800077D8;
    }
    // 0x800077D0: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800077D4: sb          $zero, 0x88($t9)
    MEM_B(0X88, ctx->r25) = 0;
L_800077D8:
    // 0x800077D8: bne         $v0, $s5, L_800077AC
    if (ctx->r2 != ctx->r21) {
        // 0x800077DC: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800077AC;
    }
    // 0x800077DC: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800077E0: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x800077E4: nop

    // 0x800077E8: beq         $s5, $v1, L_800078C4
    if (ctx->r21 == ctx->r3) {
        // 0x800077EC: lw          $t2, 0x7C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X7C);
            goto L_800078C4;
    }
    // 0x800077EC: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
L_800077F0:
    // 0x800077F0: lw          $v1, 0xCC($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XCC);
    // 0x800077F4: lw          $t0, 0xC8($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XC8);
    // 0x800077F8: sll         $t1, $s5, 2
    ctx->r9 = S32(ctx->r21 << 2);
    // 0x800077FC: sll         $t2, $v1, 2
    ctx->r10 = S32(ctx->r3 << 2);
    // 0x80007800: addu        $v0, $t2, $t0
    ctx->r2 = ADD32(ctx->r10, ctx->r8);
    // 0x80007804: addu        $s2, $t0, $t1
    ctx->r18 = ADD32(ctx->r8, ctx->r9);
L_80007808:
    // 0x80007808: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8000780C: nop

    // 0x80007810: lw          $s1, 0x64($t4)
    ctx->r17 = MEM_W(ctx->r12, 0X64);
    // 0x80007814: nop

    // 0x80007818: beq         $s1, $zero, L_80007834
    if (ctx->r17 == 0) {
        // 0x8000781C: nop
    
            goto L_80007834;
    }
    // 0x8000781C: nop

    // 0x80007820: lw          $t5, 0x118($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X118);
    // 0x80007824: nop

    // 0x80007828: beq         $t5, $zero, L_80007834
    if (ctx->r13 == 0) {
        // 0x8000782C: sw          $t5, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r13;
            goto L_80007834;
    }
    // 0x8000782C: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x80007830: sb          $zero, 0x88($t5)
    MEM_B(0X88, ctx->r13) = 0;
L_80007834:
    // 0x80007834: lw          $t3, 0x4($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4);
    // 0x80007838: nop

    // 0x8000783C: lw          $s1, 0x64($t3)
    ctx->r17 = MEM_W(ctx->r11, 0X64);
    // 0x80007840: nop

    // 0x80007844: beq         $s1, $zero, L_80007860
    if (ctx->r17 == 0) {
        // 0x80007848: nop
    
            goto L_80007860;
    }
    // 0x80007848: nop

    // 0x8000784C: lw          $t6, 0x118($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X118);
    // 0x80007850: nop

    // 0x80007854: beq         $t6, $zero, L_80007860
    if (ctx->r14 == 0) {
        // 0x80007858: sw          $t6, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r14;
            goto L_80007860;
    }
    // 0x80007858: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8000785C: sb          $zero, 0x88($t6)
    MEM_B(0X88, ctx->r14) = 0;
L_80007860:
    // 0x80007860: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x80007864: nop

    // 0x80007868: lw          $s1, 0x64($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X64);
    // 0x8000786C: nop

    // 0x80007870: beq         $s1, $zero, L_8000788C
    if (ctx->r17 == 0) {
        // 0x80007874: nop
    
            goto L_8000788C;
    }
    // 0x80007874: nop

    // 0x80007878: lw          $t8, 0x118($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X118);
    // 0x8000787C: nop

    // 0x80007880: beq         $t8, $zero, L_8000788C
    if (ctx->r24 == 0) {
        // 0x80007884: sw          $t8, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r24;
            goto L_8000788C;
    }
    // 0x80007884: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x80007888: sb          $zero, 0x88($t8)
    MEM_B(0X88, ctx->r24) = 0;
L_8000788C:
    // 0x8000788C: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x80007890: addiu       $s2, $s2, 0x10
    ctx->r18 = ADD32(ctx->r18, 0X10);
    // 0x80007894: lw          $s1, 0x64($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X64);
    // 0x80007898: nop

    // 0x8000789C: beq         $s1, $zero, L_800078B8
    if (ctx->r17 == 0) {
        // 0x800078A0: nop
    
            goto L_800078B8;
    }
    // 0x800078A0: nop

    // 0x800078A4: lw          $t1, 0x118($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X118);
    // 0x800078A8: nop

    // 0x800078AC: beq         $t1, $zero, L_800078B8
    if (ctx->r9 == 0) {
        // 0x800078B0: sw          $t1, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r9;
            goto L_800078B8;
    }
    // 0x800078B0: sw          $t1, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r9;
    // 0x800078B4: sb          $zero, 0x88($t1)
    MEM_B(0X88, ctx->r9) = 0;
L_800078B8:
    // 0x800078B8: bne         $s2, $v0, L_80007808
    if (ctx->r18 != ctx->r2) {
        // 0x800078BC: nop
    
            goto L_80007808;
    }
    // 0x800078BC: nop

L_800078C0:
    // 0x800078C0: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
L_800078C4:
    // 0x800078C4: lw          $s6, 0xC8($sp)
    ctx->r22 = MEM_W(ctx->r29, 0XC8);
    // 0x800078C8: blez        $t2, L_80007C28
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800078CC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80007C28;
    }
    // 0x800078CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800078D0: lwc1        $f25, 0x4CE8($at)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r1, 0X4CE8);
    // 0x800078D4: lwc1        $f24, 0x4CEC($at)
    ctx->f24.u32l = MEM_W(ctx->r1, 0X4CEC);
    // 0x800078D8: nop

L_800078DC:
    // 0x800078DC: lw          $t0, 0x0($s6)
    ctx->r8 = MEM_W(ctx->r22, 0X0);
    // 0x800078E0: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x800078E4: lw          $t5, 0xCC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XCC);
    // 0x800078E8: lw          $s1, 0x64($t0)
    ctx->r17 = MEM_W(ctx->r8, 0X64);
    // 0x800078EC: slt         $at, $t4, $t5
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800078F0: beq         $at, $zero, L_80007C10
    if (ctx->r1 == 0) {
        // 0x800078F4: or          $s5, $t4, $zero
        ctx->r21 = ctx->r12 | 0;
            goto L_80007C10;
    }
    // 0x800078F4: or          $s5, $t4, $zero
    ctx->r21 = ctx->r12 | 0;
    // 0x800078F8: lw          $t3, 0xC8($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XC8);
    // 0x800078FC: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80007900: addu        $s2, $t3, $t6
    ctx->r18 = ADD32(ctx->r11, ctx->r14);
L_80007904:
    // 0x80007904: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80007908: nop

    // 0x8000790C: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    // 0x80007910: nop

    // 0x80007914: beq         $v0, $zero, L_80007C04
    if (ctx->r2 == 0) {
        // 0x80007918: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x80007918: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x8000791C: lw          $t8, 0x118($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X118);
    // 0x80007920: nop

    // 0x80007924: beq         $t8, $zero, L_80007C00
    if (ctx->r24 == 0) {
        // 0x80007928: sw          $t8, 0x0($s4)
        MEM_W(0X0, ctx->r20) = ctx->r24;
            goto L_80007C00;
    }
    // 0x80007928: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x8000792C: lb          $t1, 0x1D8($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D8);
    // 0x80007930: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80007934: beq         $t1, $zero, L_80007974
    if (ctx->r9 == 0) {
        // 0x80007938: sll         $t0, $t2, 4
        ctx->r8 = S32(ctx->r10 << 4);
            goto L_80007974;
    }
    // 0x80007938: sll         $t0, $t2, 4
    ctx->r8 = S32(ctx->r10 << 4);
    // 0x8000793C: addu        $t0, $t0, $t2
    ctx->r8 = ADD32(ctx->r8, ctx->r10);
    // 0x80007940: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80007944: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x80007948: addu        $v1, $s7, $t0
    ctx->r3 = ADD32(ctx->r23, ctx->r8);
    // 0x8000794C: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80007950: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80007954: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80007958: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8000795C: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80007960: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80007964: sub.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80007968: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8000796C: b           L_800079A0
    // 0x80007970: sub.s       $f22, $f6, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f16.fl;
        goto L_800079A0;
    // 0x80007970: sub.s       $f22, $f6, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f16.fl;
L_80007974:
    // 0x80007974: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x80007978: lw          $s0, 0x0($s6)
    ctx->r16 = MEM_W(ctx->r22, 0X0);
    // 0x8000797C: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80007980: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80007984: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80007988: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8000798C: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80007990: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80007994: sub.s       $f20, $f10, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80007998: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x8000799C: sub.s       $f22, $f6, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f6.fl - ctx->f16.fl;
L_800079A0:
    // 0x800079A0: mul.s       $f10, $f20, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800079A4: nop

    // 0x800079A8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800079AC: nop

    // 0x800079B0: mul.s       $f8, $f22, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800079B4: add.s       $f18, $f10, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800079B8: jal         0x800C9AD0
    // 0x800079BC: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_20;
    // 0x800079BC: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_20:
    // 0x800079C0: lw          $t4, 0x0($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X0);
    // 0x800079C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800079C8: swc1        $f0, 0x84($t4)
    MEM_W(0X84, ctx->r12) = ctx->f0.u32l;
    // 0x800079CC: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800079D0: lwc1        $f6, 0x4CF0($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X4CF0);
    // 0x800079D4: lwc1        $f2, 0x84($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X84);
    // 0x800079D8: nop

    // 0x800079DC: c.lt.s      $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f2.fl < ctx->f6.fl;
    // 0x800079E0: nop

    // 0x800079E4: bc1f        L_80007C04
    if (!c1cs) {
        // 0x800079E8: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x800079E8: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x800079EC: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800079F0: lwc1        $f4, 0x54($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X54);
    // 0x800079F4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800079F8: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x800079FC: sub.s       $f10, $f30, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x80007A00: nop

    // 0x80007A04: div.s       $f26, $f10, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = DIV_S(ctx->f10.fl, ctx->f30.fl);
    // 0x80007A08: mul.s       $f18, $f4, $f26
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f26.fl);
    // 0x80007A0C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80007A10: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007A14: nop

    // 0x80007A18: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80007A1C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007A20: nop

    // 0x80007A24: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007A28: beq         $v0, $zero, L_80007A74
    if (ctx->r2 == 0) {
        // 0x80007A2C: nop
    
            goto L_80007A74;
    }
    // 0x80007A2C: nop

    // 0x80007A30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80007A34: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007A38: sub.s       $f8, $f18, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80007A3C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007A40: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007A44: nop

    // 0x80007A48: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80007A4C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007A50: nop

    // 0x80007A54: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007A58: bne         $v0, $zero, L_80007A6C
    if (ctx->r2 != 0) {
        // 0x80007A5C: nop
    
            goto L_80007A6C;
    }
    // 0x80007A5C: nop

    // 0x80007A60: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80007A64: b           L_80007A84
    // 0x80007A68: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80007A84;
    // 0x80007A68: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80007A6C:
    // 0x80007A6C: b           L_80007A84
    // 0x80007A70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80007A84;
    // 0x80007A70: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80007A74:
    // 0x80007A74: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80007A78: nop

    // 0x80007A7C: bltz        $v0, L_80007A6C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80007A80: nop
    
            goto L_80007A6C;
    }
    // 0x80007A80: nop

L_80007A84:
    // 0x80007A84: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x80007A88: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80007A8C: slti        $at, $t3, 0x80
    ctx->r1 = SIGNED(ctx->r11) < 0X80 ? 1 : 0;
    // 0x80007A90: bne         $at, $zero, L_80007A9C
    if (ctx->r1 != 0) {
        // 0x80007A94: or          $v0, $t3, $zero
        ctx->r2 = ctx->r11 | 0;
            goto L_80007A9C;
    }
    // 0x80007A94: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80007A98: addiu       $v0, $zero, 0x7F
    ctx->r2 = ADD32(0, 0X7F);
L_80007A9C:
    // 0x80007A9C: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80007AA0: bgez        $v0, L_80007ABC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80007AA4: cvt.d.w     $f16, $f6
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
            goto L_80007ABC;
    }
    // 0x80007AA4: cvt.d.w     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.d = CVT_D_W(ctx->f6.u32l);
    // 0x80007AA8: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80007AAC: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80007AB0: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80007AB4: nop

    // 0x80007AB8: add.d       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f16.d + ctx->f10.d;
L_80007ABC:
    // 0x80007ABC: mul.d       $f4, $f16, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f24.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f24.d);
    // 0x80007AC0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007AC4: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80007AC8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80007ACC: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007AD0: nop

    // 0x80007AD4: cvt.w.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.u32l = CVT_W_D(ctx->f4.d);
    // 0x80007AD8: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007ADC: nop

    // 0x80007AE0: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007AE4: beq         $v0, $zero, L_80007B34
    if (ctx->r2 == 0) {
        // 0x80007AE8: nop
    
            goto L_80007B34;
    }
    // 0x80007AE8: nop

    // 0x80007AEC: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80007AF0: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80007AF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80007AF8: sub.d       $f18, $f4, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f4.d - ctx->f18.d;
    // 0x80007AFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80007B00: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80007B04: nop

    // 0x80007B08: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x80007B0C: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80007B10: nop

    // 0x80007B14: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x80007B18: bne         $v0, $zero, L_80007B2C
    if (ctx->r2 != 0) {
        // 0x80007B1C: nop
    
            goto L_80007B2C;
    }
    // 0x80007B1C: nop

    // 0x80007B20: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80007B24: b           L_80007B44
    // 0x80007B28: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
        goto L_80007B44;
    // 0x80007B28: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
L_80007B2C:
    // 0x80007B2C: b           L_80007B44
    // 0x80007B30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80007B44;
    // 0x80007B30: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_80007B34:
    // 0x80007B34: mfc1        $v0, $f18
    ctx->r2 = (int32_t)ctx->f18.u32l;
    // 0x80007B38: nop

    // 0x80007B3C: bltz        $v0, L_80007B2C
    if (SIGNED(ctx->r2) < 0) {
        // 0x80007B40: nop
    
            goto L_80007B2C;
    }
    // 0x80007B40: nop

L_80007B44:
    // 0x80007B44: lbu         $t8, 0x88($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X88);
    // 0x80007B48: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80007B4C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80007B50: slt         $at, $t8, $t7
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80007B54: beq         $at, $zero, L_80007C04
    if (ctx->r1 == 0) {
        // 0x80007B58: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x80007B58: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x80007B5C: sb          $t7, 0x88($s0)
    MEM_B(0X88, ctx->r16) = ctx->r15;
    // 0x80007B60: lh          $a2, 0x0($s7)
    ctx->r6 = MEM_H(ctx->r23, 0X0);
    // 0x80007B64: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    // 0x80007B68: jal         0x800090C0
    // 0x80007B6C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    audspat_calculate_spatial_pan(rdram, ctx);
        goto after_21;
    // 0x80007B6C: mov.s       $f14, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 22);
    ctx->f14.fl = ctx->f22.fl;
    after_21:
    // 0x80007B70: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80007B74: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x80007B78: sb          $v0, 0x91($t9)
    MEM_B(0X91, ctx->r25) = ctx->r2;
    // 0x80007B7C: lb          $t1, 0x1D8($s1)
    ctx->r9 = MEM_B(ctx->r17, 0X1D8);
    // 0x80007B80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80007B84: beq         $t1, $zero, L_80007BA4
    if (ctx->r9 == 0) {
        // 0x80007B88: nop
    
            goto L_80007BA4;
    }
    // 0x80007B88: nop

    // 0x80007B8C: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80007B90: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80007B94: jal         0x80006BFC
    // 0x80007B98: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    racer_sound_doppler_effect(rdram, ctx);
        goto after_22;
    // 0x80007B98: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    after_22:
    // 0x80007B9C: b           L_80007BB8
    // 0x80007BA0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
        goto L_80007BB8;
    // 0x80007BA0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
L_80007BA4:
    // 0x80007BA4: lw          $a0, 0x0($s6)
    ctx->r4 = MEM_W(ctx->r22, 0X0);
    // 0x80007BA8: lw          $a2, 0x0($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X0);
    // 0x80007BAC: jal         0x80006BFC
    // 0x80007BB0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    racer_sound_doppler_effect(rdram, ctx);
        goto after_23;
    // 0x80007BB0: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    after_23:
    // 0x80007BB4: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
L_80007BB8:
    // 0x80007BB8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007BBC: lwc1        $f8, 0x5C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X5C);
    // 0x80007BC0: lwc1        $f6, 0x68($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X68);
    // 0x80007BC4: nop

    // 0x80007BC8: add.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80007BCC: swc1        $f10, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f10.u32l;
    // 0x80007BD0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80007BD4: nop

    // 0x80007BD8: lwc1        $f16, 0x8C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8C);
    // 0x80007BDC: nop

    // 0x80007BE0: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80007BE4: c.lt.d      $f4, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    c1cs = ctx->f4.d < ctx->f28.d;
    // 0x80007BE8: nop

    // 0x80007BEC: bc1f        L_80007C04
    if (!c1cs) {
        // 0x80007BF0: lw          $t2, 0xCC($sp)
        ctx->r10 = MEM_W(ctx->r29, 0XCC);
            goto L_80007C04;
    }
    // 0x80007BF0: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
    // 0x80007BF4: lwc1        $f18, 0x4CF4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X4CF4);
    // 0x80007BF8: nop

    // 0x80007BFC: swc1        $f18, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f18.u32l;
L_80007C00:
    // 0x80007C00: lw          $t2, 0xCC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XCC);
L_80007C04:
    // 0x80007C04: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80007C08: bne         $s5, $t2, L_80007904
    if (ctx->r21 != ctx->r10) {
        // 0x80007C0C: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80007904;
    }
    // 0x80007C0C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80007C10:
    // 0x80007C10: lw          $t0, 0xAC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XAC);
    // 0x80007C14: lw          $t5, 0x7C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X7C);
    // 0x80007C18: addiu       $t4, $t0, 0x1
    ctx->r12 = ADD32(ctx->r8, 0X1);
    // 0x80007C1C: sw          $t4, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r12;
    // 0x80007C20: bne         $t4, $t5, L_800078DC
    if (ctx->r12 != ctx->r13) {
        // 0x80007C24: addiu       $s6, $s6, 0x4
        ctx->r22 = ADD32(ctx->r22, 0X4);
            goto L_800078DC;
    }
    // 0x80007C24: addiu       $s6, $s6, 0x4
    ctx->r22 = ADD32(ctx->r22, 0X4);
L_80007C28:
    // 0x80007C28: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80007C2C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80007C30: addiu       $s0, $s0, -0x63C8
    ctx->r16 = ADD32(ctx->r16, -0X63C8);
    // 0x80007C34: addiu       $s3, $s3, -0x63D0
    ctx->r19 = ADD32(ctx->r19, -0X63D0);
L_80007C38:
    // 0x80007C38: lw          $v0, 0x0($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X0);
    // 0x80007C3C: nop

    // 0x80007C40: beq         $v0, $zero, L_80007C90
    if (ctx->r2 == 0) {
        // 0x80007C44: nop
    
            goto L_80007C90;
    }
    // 0x80007C44: nop

    // 0x80007C48: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x80007C4C: nop

    // 0x80007C50: beq         $a0, $zero, L_80007C90
    if (ctx->r4 == 0) {
        // 0x80007C54: nop
    
            goto L_80007C90;
    }
    // 0x80007C54: nop

    // 0x80007C58: lbu         $t3, 0x88($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X88);
    // 0x80007C5C: nop

    // 0x80007C60: slti        $at, $t3, 0x8
    ctx->r1 = SIGNED(ctx->r11) < 0X8 ? 1 : 0;
    // 0x80007C64: beq         $at, $zero, L_80007C90
    if (ctx->r1 == 0) {
        // 0x80007C68: nop
    
            goto L_80007C90;
    }
    // 0x80007C68: nop

    // 0x80007C6C: jal         0x8000488C
    // 0x80007C70: nop

    sndp_stop(rdram, ctx);
        goto after_24;
    // 0x80007C70: nop

    after_24:
    // 0x80007C74: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80007C78: nop

    // 0x80007C7C: sw          $zero, 0x48($t6)
    MEM_W(0X48, ctx->r14) = 0;
    // 0x80007C80: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x80007C84: nop

    // 0x80007C88: sb          $zero, 0x74($t7)
    MEM_B(0X74, ctx->r15) = 0;
    // 0x80007C8C: sw          $zero, 0x0($s3)
    MEM_W(0X0, ctx->r19) = 0;
L_80007C90:
    // 0x80007C90: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80007C94: bne         $s3, $s0, L_80007C38
    if (ctx->r19 != ctx->r16) {
        // 0x80007C98: nop
    
            goto L_80007C38;
    }
    // 0x80007C98: nop

    // 0x80007C9C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80007CA0: addiu       $a3, $a3, -0x392C
    ctx->r7 = ADD32(ctx->r7, -0X392C);
    // 0x80007CA4: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80007CA8: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    // 0x80007CAC: slt         $at, $fp, $v0
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80007CB0: beq         $at, $zero, L_80007CC0
    if (ctx->r1 == 0) {
        // 0x80007CB4: subu        $t8, $v0, $fp
        ctx->r24 = SUB32(ctx->r2, ctx->r30);
            goto L_80007CC0;
    }
    // 0x80007CB4: subu        $t8, $v0, $fp
    ctx->r24 = SUB32(ctx->r2, ctx->r30);
    // 0x80007CB8: b           L_80007CC4
    // 0x80007CBC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
        goto L_80007CC4;
    // 0x80007CBC: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_80007CC0:
    // 0x80007CC0: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80007CC4:
    // 0x80007CC4: lw          $t9, 0xCC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XCC);
    // 0x80007CC8: lw          $s2, 0xC8($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC8);
    // 0x80007CCC: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x80007CD0: bne         $at, $zero, L_80007E24
    if (ctx->r1 != 0) {
        // 0x80007CD4: addiu       $s5, $zero, 0x1
        ctx->r21 = ADD32(0, 0X1);
            goto L_80007E24;
    }
    // 0x80007CD4: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80007CD8: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80007CDC: addiu       $fp, $zero, -0x1
    ctx->r30 = ADD32(0, -0X1);
    // 0x80007CE0: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
L_80007CE4:
    // 0x80007CE4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80007CE8: nop

    // 0x80007CEC: lw          $v0, 0x64($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X64);
    // 0x80007CF0: nop

    // 0x80007CF4: beq         $v0, $zero, L_80007E18
    if (ctx->r2 == 0) {
        // 0x80007CF8: lw          $t4, 0xCC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XCC);
            goto L_80007E18;
    }
    // 0x80007CF8: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80007CFC: lw          $t2, 0x118($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X118);
    // 0x80007D00: nop

    // 0x80007D04: sw          $t2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r10;
    // 0x80007D08: beq         $t2, $zero, L_80007E14
    if (ctx->r10 == 0) {
        // 0x80007D0C: or          $s0, $t2, $zero
        ctx->r16 = ctx->r10 | 0;
            goto L_80007E14;
    }
    // 0x80007D0C: or          $s0, $t2, $zero
    ctx->r16 = ctx->r10 | 0;
    // 0x80007D10: lbu         $t0, 0x74($t2)
    ctx->r8 = MEM_BU(ctx->r10, 0X74);
    // 0x80007D14: nop

    // 0x80007D18: bne         $t0, $zero, L_80007E18
    if (ctx->r8 != 0) {
        // 0x80007D1C: lw          $t4, 0xCC($sp)
        ctx->r12 = MEM_W(ctx->r29, 0XCC);
            goto L_80007E18;
    }
    // 0x80007D1C: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x80007D20: lhu         $t4, 0x0($t2)
    ctx->r12 = MEM_HU(ctx->r10, 0X0);
    // 0x80007D24: addiu       $a2, $zero, 0x14
    ctx->r6 = ADD32(0, 0X14);
    // 0x80007D28: beq         $t4, $zero, L_80007E14
    if (ctx->r12 == 0) {
        // 0x80007D2C: or          $a0, $fp, $zero
        ctx->r4 = ctx->r30 | 0;
            goto L_80007E14;
    }
    // 0x80007D2C: or          $a0, $fp, $zero
    ctx->r4 = ctx->r30 | 0;
    // 0x80007D30: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80007D34: lbu         $a1, 0x88($t2)
    ctx->r5 = MEM_BU(ctx->r10, 0X88);
    // 0x80007D38: addiu       $s3, $s3, -0x63D0
    ctx->r19 = ADD32(ctx->r19, -0X63D0);
    // 0x80007D3C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80007D40:
    // 0x80007D40: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80007D44: slti        $at, $a1, 0x9
    ctx->r1 = SIGNED(ctx->r5) < 0X9 ? 1 : 0;
    // 0x80007D48: beq         $s1, $zero, L_80007D84
    if (ctx->r17 == 0) {
        // 0x80007D4C: nop
    
            goto L_80007D84;
    }
    // 0x80007D4C: nop

    // 0x80007D50: lbu         $t5, 0x88($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X88);
    // 0x80007D54: nop

    // 0x80007D58: subu        $v0, $a1, $t5
    ctx->r2 = SUB32(ctx->r5, ctx->r13);
    // 0x80007D5C: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80007D60: beq         $at, $zero, L_80007D90
    if (ctx->r1 == 0) {
        // 0x80007D64: nop
    
            goto L_80007D90;
    }
    // 0x80007D64: nop

    // 0x80007D68: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x80007D6C: nop

    // 0x80007D70: bne         $t3, $zero, L_80007D90
    if (ctx->r11 != 0) {
        // 0x80007D74: nop
    
            goto L_80007D90;
    }
    // 0x80007D74: nop

    // 0x80007D78: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80007D7C: b           L_80007D90
    // 0x80007D80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
        goto L_80007D90;
    // 0x80007D80: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80007D84:
    // 0x80007D84: bne         $at, $zero, L_80007D90
    if (ctx->r1 != 0) {
        // 0x80007D88: nop
    
            goto L_80007D90;
    }
    // 0x80007D88: nop

    // 0x80007D8C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
L_80007D90:
    // 0x80007D90: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80007D94: bne         $v1, $s6, L_80007D40
    if (ctx->r3 != ctx->r22) {
        // 0x80007D98: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_80007D40;
    }
    // 0x80007D98: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80007D9C: beq         $a0, $fp, L_80007E14
    if (ctx->r4 == ctx->r30) {
        // 0x80007DA0: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_80007E14;
    }
    // 0x80007DA0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80007DA4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80007DA8: addiu       $t7, $t7, -0x63D0
    ctx->r15 = ADD32(ctx->r15, -0X63D0);
    // 0x80007DAC: sb          $s7, 0x74($s0)
    MEM_B(0X74, ctx->r16) = ctx->r23;
    // 0x80007DB0: addu        $s1, $t6, $t7
    ctx->r17 = ADD32(ctx->r14, ctx->r15);
    // 0x80007DB4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80007DB8: nop

    // 0x80007DBC: beq         $v0, $zero, L_80007E08
    if (ctx->r2 == 0) {
        // 0x80007DC0: nop
    
            goto L_80007E08;
    }
    // 0x80007DC0: nop

    // 0x80007DC4: lw          $a0, 0x48($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X48);
    // 0x80007DC8: nop

    // 0x80007DCC: beq         $a0, $zero, L_80007E00
    if (ctx->r4 == 0) {
        // 0x80007DD0: addiu       $t2, $zero, 0x3C
        ctx->r10 = ADD32(0, 0X3C);
            goto L_80007E00;
    }
    // 0x80007DD0: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x80007DD4: jal         0x8000488C
    // 0x80007DD8: nop

    sndp_stop(rdram, ctx);
        goto after_25;
    // 0x80007DD8: nop

    after_25:
    // 0x80007DDC: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x80007DE0: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80007DE4: sw          $zero, 0x48($t8)
    MEM_W(0X48, ctx->r24) = 0;
    // 0x80007DE8: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x80007DEC: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80007DF0: sb          $t9, 0x74($t1)
    MEM_B(0X74, ctx->r9) = ctx->r25;
    // 0x80007DF4: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x80007DF8: addiu       $a3, $a3, -0x392C
    ctx->r7 = ADD32(ctx->r7, -0X392C);
    // 0x80007DFC: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
L_80007E00:
    // 0x80007E00: sw          $t2, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r10;
    // 0x80007E04: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
L_80007E08:
    // 0x80007E08: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x80007E0C: nop

    // 0x80007E10: sw          $t0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r8;
L_80007E14:
    // 0x80007E14: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
L_80007E18:
    // 0x80007E18: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x80007E1C: bne         $s5, $t4, L_80007CE4
    if (ctx->r21 != ctx->r12) {
        // 0x80007E20: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80007CE4;
    }
    // 0x80007E20: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80007E24:
    // 0x80007E24: jal         0x8001139C
    // 0x80007E28: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    get_race_countdown(rdram, ctx);
        goto after_26;
    // 0x80007E28: addiu       $s7, $zero, 0x2
    ctx->r23 = ADD32(0, 0X2);
    after_26:
    // 0x80007E2C: bgtz        $v0, L_80007F18
    if (SIGNED(ctx->r2) > 0) {
        // 0x80007E30: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_80007F18;
    }
    // 0x80007E30: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80007E34: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80007E38: addiu       $s0, $s0, -0x63C8
    ctx->r16 = ADD32(ctx->r16, -0X63C8);
    // 0x80007E3C: addiu       $s3, $s3, -0x63D0
    ctx->r19 = ADD32(ctx->r19, -0X63D0);
L_80007E40:
    // 0x80007E40: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80007E44: nop

    // 0x80007E48: beq         $s1, $zero, L_80007F0C
    if (ctx->r17 == 0) {
        // 0x80007E4C: nop
    
            goto L_80007F0C;
    }
    // 0x80007E4C: nop

    // 0x80007E50: lhu         $a2, 0x0($s1)
    ctx->r6 = MEM_HU(ctx->r17, 0X0);
    // 0x80007E54: nop

    // 0x80007E58: beq         $a2, $zero, L_80007F0C
    if (ctx->r6 == 0) {
        // 0x80007E5C: nop
    
            goto L_80007F0C;
    }
    // 0x80007E5C: nop

    // 0x80007E60: lbu         $t5, 0x74($s1)
    ctx->r13 = MEM_BU(ctx->r17, 0X74);
    // 0x80007E64: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007E68: bne         $t5, $at, L_80007E78
    if (ctx->r13 != ctx->r1) {
        // 0x80007E6C: nop
    
            goto L_80007E78;
    }
    // 0x80007E6C: nop

    // 0x80007E70: b           L_80007F0C
    // 0x80007E74: sb          $s7, 0x74($s1)
    MEM_B(0X74, ctx->r17) = ctx->r23;
        goto L_80007F0C;
    // 0x80007E74: sb          $s7, 0x74($s1)
    MEM_B(0X74, ctx->r17) = ctx->r23;
L_80007E78:
    // 0x80007E78: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007E7C: addiu       $a1, $s1, 0x48
    ctx->r5 = ADD32(ctx->r17, 0X48);
    // 0x80007E80: bne         $a0, $zero, L_80007E98
    if (ctx->r4 != 0) {
        // 0x80007E84: nop
    
            goto L_80007E98;
    }
    // 0x80007E84: nop

    // 0x80007E88: jal         0x80001F14
    // 0x80007E8C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    sound_play_direct(rdram, ctx);
        goto after_27;
    // 0x80007E8C: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    after_27:
    // 0x80007E90: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007E94: nop

L_80007E98:
    // 0x80007E98: beq         $a0, $zero, L_80007F0C
    if (ctx->r4 == 0) {
        // 0x80007E9C: nop
    
            goto L_80007F0C;
    }
    // 0x80007E9C: nop

    // 0x80007EA0: lw          $a1, 0x78($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X78);
    // 0x80007EA4: lw          $a2, 0x7C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X7C);
    // 0x80007EA8: lw          $a3, 0x80($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X80);
    // 0x80007EAC: jal         0x80009B7C
    // 0x80007EB0: nop

    audspat_calculate_echo(rdram, ctx);
        goto after_28;
    // 0x80007EB0: nop

    after_28:
    // 0x80007EB4: lbu         $a2, 0x88($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X88);
    // 0x80007EB8: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007EBC: sll         $t3, $a2, 8
    ctx->r11 = S32(ctx->r6 << 8);
    // 0x80007EC0: or          $a2, $t3, $zero
    ctx->r6 = ctx->r11 | 0;
    // 0x80007EC4: jal         0x800049F8
    // 0x80007EC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    sndp_set_param(rdram, ctx);
        goto after_29;
    // 0x80007EC8: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_29:
    // 0x80007ECC: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007ED0: lw          $a2, 0x8C($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X8C);
    // 0x80007ED4: jal         0x800049F8
    // 0x80007ED8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_30;
    // 0x80007ED8: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_30:
    // 0x80007EDC: lw          $t6, 0x7C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X7C);
    // 0x80007EE0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80007EE4: beq         $t6, $at, L_80007EF0
    if (ctx->r14 == ctx->r1) {
        // 0x80007EE8: addiu       $t7, $zero, 0x40
        ctx->r15 = ADD32(0, 0X40);
            goto L_80007EF0;
    }
    // 0x80007EE8: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80007EEC: sb          $t7, 0x91($s1)
    MEM_B(0X91, ctx->r17) = ctx->r15;
L_80007EF0:
    // 0x80007EF0: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007EF4: lbu         $a2, 0x91($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X91);
    // 0x80007EF8: jal         0x800049F8
    // 0x80007EFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    sndp_set_param(rdram, ctx);
        goto after_31;
    // 0x80007EFC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    after_31:
    // 0x80007F00: lw          $a0, 0x48($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X48);
    // 0x80007F04: jal         0x80004604
    // 0x80007F08: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    sndp_set_priority(rdram, ctx);
        goto after_32;
    // 0x80007F08: addiu       $a1, $zero, 0x46
    ctx->r5 = ADD32(0, 0X46);
    after_32:
L_80007F0C:
    // 0x80007F0C: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80007F10: bne         $s3, $s0, L_80007E40
    if (ctx->r19 != ctx->r16) {
        // 0x80007F14: nop
    
            goto L_80007E40;
    }
    // 0x80007F14: nop

L_80007F18:
    // 0x80007F18: lw          $ra, 0x6C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X6C);
    // 0x80007F1C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80007F20: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80007F24: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80007F28: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80007F2C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80007F30: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80007F34: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80007F38: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80007F3C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80007F40: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80007F44: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80007F48: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80007F4C: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80007F50: lw          $s1, 0x4C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X4C);
    // 0x80007F54: lw          $s2, 0x50($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X50);
    // 0x80007F58: lw          $s3, 0x54($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X54);
    // 0x80007F5C: lw          $s4, 0x58($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X58);
    // 0x80007F60: lw          $s5, 0x5C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X5C);
    // 0x80007F64: lw          $s6, 0x60($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X60);
    // 0x80007F68: lw          $s7, 0x64($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X64);
    // 0x80007F6C: lw          $fp, 0x68($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X68);
    extern void dkr_leave_vehicle_audio_scope(uint8_t*, recomp_context*); dkr_leave_vehicle_audio_scope(rdram, ctx);
    // 0x80007F70: jr          $ra
    // 0x80007F74: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
    return;
    // 0x80007F74: addiu       $sp, $sp, 0xC8
    ctx->r29 = ADD32(ctx->r29, 0XC8);
;}
RECOMP_FUNC void hud_lap_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4F50: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A4F54: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A4F58: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A4F5C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A4F60: lb          $t7, 0x1D8($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A4F64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A4F68: bne         $t7, $zero, L_800A5190
    if (ctx->r15 != 0) {
        // 0x800A4F6C: nop
    
            goto L_800A5190;
    }
    // 0x800A4F6C: nop

    // 0x800A4F70: lw          $v0, 0x6D0C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D0C);
    // 0x800A4F74: nop

    // 0x800A4F78: blez        $v0, L_800A4FA8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A4F7C: nop
    
            goto L_800A4FA8;
    }
    // 0x800A4F7C: nop

    // 0x800A4F80: lb          $v1, 0x193($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X193);
    // 0x800A4F84: nop

    // 0x800A4F88: blez        $v1, L_800A4FA8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A4F8C: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_800A4FA8;
    }
    // 0x800A4F8C: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800A4F90: addu        $t9, $a0, $t8
    ctx->r25 = ADD32(ctx->r4, ctx->r24);
    // 0x800A4F94: lw          $t3, 0x128($t9)
    ctx->r11 = MEM_W(ctx->r25, 0X128);
    // 0x800A4F98: nop

    // 0x800A4F9C: slti        $at, $t3, 0xB4
    ctx->r1 = SIGNED(ctx->r11) < 0XB4 ? 1 : 0;
    // 0x800A4FA0: bne         $at, $zero, L_800A5190
    if (ctx->r1 != 0) {
        // 0x800A4FA4: nop
    
            goto L_800A5190;
    }
    // 0x800A4FA4: nop

L_800A4FA8:
    // 0x800A4FA8: blez        $v0, L_800A4FD8
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A4FAC: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A4FD8;
    }
    // 0x800A4FAC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A4FB0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A4FB4: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800A4FB8: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x800A4FBC: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800A4FC0: addu        $t6, $t4, $t7
    ctx->r14 = ADD32(ctx->r12, ctx->r15);
    // 0x800A4FC4: addu        $t8, $t8, $t6
    ctx->r24 = ADD32(ctx->r24, ctx->r14);
    // 0x800A4FC8: lbu         $t8, 0x2794($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X2794);
    // 0x800A4FCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A4FD0: bne         $t8, $at, L_800A5190
    if (ctx->r24 != ctx->r1) {
        // 0x800A4FD4: nop
    
            goto L_800A5190;
    }
    // 0x800A4FD4: nop

L_800A4FD8:
    // 0x800A4FD8: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A4FDC: lw          $t9, 0x6D60($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D60);
    // 0x800A4FE0: lb          $t4, 0x194($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X194);
    // 0x800A4FE4: lb          $t3, 0x4B($t9)
    ctx->r11 = MEM_B(ctx->r25, 0X4B);
    // 0x800A4FE8: addiu       $t7, $t4, 0x1
    ctx->r15 = ADD32(ctx->r12, 0X1);
    // 0x800A4FEC: bne         $t3, $t7, L_800A5094
    if (ctx->r11 != ctx->r15) {
        // 0x800A4FF0: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_800A5094;
    }
    // 0x800A4FF0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800A4FF4: beq         $at, $zero, L_800A5094
    if (ctx->r1 == 0) {
        // 0x800A4FF8: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800A5094;
    }
    // 0x800A4FF8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A4FFC: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5000: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5004: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5008: lb          $t6, 0x21A($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X21A);
    // 0x800A500C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5010: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800A5014: sb          $t9, 0x21A($v0)
    MEM_B(0X21A, ctx->r2) = ctx->r25;
    // 0x800A5018: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A501C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5020: lb          $t5, 0x21A($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X21A);
    // 0x800A5024: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A5028: slti        $at, $t5, 0x7
    ctx->r1 = SIGNED(ctx->r13) < 0X7 ? 1 : 0;
    // 0x800A502C: bne         $at, $zero, L_800A5084
    if (ctx->r1 != 0) {
        // 0x800A5030: addiu       $a0, $a0, 0x6CFC
        ctx->r4 = ADD32(ctx->r4, 0X6CFC);
            goto L_800A5084;
    }
    // 0x800A5030: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5034: lh          $t4, 0x218($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X218);
    // 0x800A5038: nop

    // 0x800A503C: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x800A5040: sh          $t3, 0x218($v0)
    MEM_H(0X218, ctx->r2) = ctx->r11;
    // 0x800A5044: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5048: nop

    // 0x800A504C: lb          $t7, 0x21A($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X21A);
    // 0x800A5050: nop

    // 0x800A5054: addiu       $t6, $t7, -0x6
    ctx->r14 = ADD32(ctx->r15, -0X6);
    // 0x800A5058: sb          $t6, 0x21A($v0)
    MEM_B(0X21A, ctx->r2) = ctx->r14;
    // 0x800A505C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5060: nop

    // 0x800A5064: lh          $t8, 0x218($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X218);
    // 0x800A5068: nop

    // 0x800A506C: slti        $at, $t8, 0x5
    ctx->r1 = SIGNED(ctx->r24) < 0X5 ? 1 : 0;
    // 0x800A5070: bne         $at, $zero, L_800A5084
    if (ctx->r1 != 0) {
        // 0x800A5074: nop
    
            goto L_800A5084;
    }
    // 0x800A5074: nop

    // 0x800A5078: sh          $zero, 0x218($v0)
    MEM_H(0X218, ctx->r2) = 0;
    // 0x800A507C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5080: nop

L_800A5084:
    // 0x800A5084: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5088: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A508C: jal         0x800AA600
    // 0x800A5090: addiu       $a3, $v0, 0x200
    ctx->r7 = ADD32(ctx->r2, 0X200);
    hud_element_render(rdram, ctx);
        goto after_0;
    // 0x800A5090: addiu       $a3, $v0, 0x200
    ctx->r7 = ADD32(ctx->r2, 0X200);
    after_0:
L_800A5094:
    // 0x800A5094: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5098: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A509C: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A50A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A50A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A50A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A50AC: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A50B0: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A50B4: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A50B8: jal         0x800AA600
    // 0x800A50BC: addiu       $a3, $a3, 0x60
    ctx->r7 = ADD32(ctx->r7, 0X60);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A50BC: addiu       $a3, $a3, 0x60
    ctx->r7 = ADD32(ctx->r7, 0X60);
    after_1:
    // 0x800A50C0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A50C4: addiu       $t2, $t2, 0x6D60
    ctx->r10 = ADD32(ctx->r10, 0X6D60);
    // 0x800A50C8: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x800A50CC: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A50D0: lb          $v0, 0x4B($t9)
    ctx->r2 = MEM_B(ctx->r25, 0X4B);
    // 0x800A50D4: lb          $v1, 0x194($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X194);
    // 0x800A50D8: addiu       $t5, $v0, -0x1
    ctx->r13 = ADD32(ctx->r2, -0X1);
    // 0x800A50DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A50E0: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800A50E4: bne         $at, $zero, L_800A50F8
    if (ctx->r1 != 0) {
        // 0x800A50E8: addiu       $t0, $t0, 0x6CDC
        ctx->r8 = ADD32(ctx->r8, 0X6CDC);
            goto L_800A50F8;
    }
    // 0x800A50E8: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A50EC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A50F0: b           L_800A5104
    // 0x800A50F4: sh          $v0, 0x98($t4)
    MEM_H(0X98, ctx->r12) = ctx->r2;
        goto L_800A5104;
    // 0x800A50F4: sh          $v0, 0x98($t4)
    MEM_H(0X98, ctx->r12) = ctx->r2;
L_800A50F8:
    // 0x800A50F8: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A50FC: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x800A5100: sh          $t3, 0x98($t7)
    MEM_H(0X98, ctx->r15) = ctx->r11;
L_800A5104:
    // 0x800A5104: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800A5108: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A510C: lb          $t8, 0x4B($t6)
    ctx->r24 = MEM_B(ctx->r14, 0X4B);
    // 0x800A5110: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5114: sh          $t8, 0xD8($t9)
    MEM_H(0XD8, ctx->r25) = ctx->r24;
    // 0x800A5118: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A511C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5120: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5124: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A5128: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A512C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5130: jal         0x800AA600
    // 0x800A5134: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A5134: addiu       $a3, $a3, 0x80
    ctx->r7 = ADD32(ctx->r7, 0X80);
    after_2:
    // 0x800A5138: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A513C: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5140: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5144: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5148: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A514C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5150: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A5154: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A5158: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A515C: jal         0x800AA600
    // 0x800A5160: addiu       $a3, $a3, 0xA0
    ctx->r7 = ADD32(ctx->r7, 0XA0);
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A5160: addiu       $a3, $a3, 0xA0
    ctx->r7 = ADD32(ctx->r7, 0XA0);
    after_3:
    // 0x800A5164: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5168: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A516C: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5170: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5174: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5178: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A517C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A5180: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A5184: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5188: jal         0x800AA600
    // 0x800A518C: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
    hud_element_render(rdram, ctx);
        goto after_4;
    // 0x800A518C: addiu       $a3, $a3, 0xC0
    ctx->r7 = ADD32(ctx->r7, 0XC0);
    after_4:
L_800A5190:
    // 0x800A5190: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A5194: lw          $t5, 0x6D0C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D0C);
    // 0x800A5198: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A519C: bne         $t5, $at, L_800A51AC
    if (ctx->r13 != ctx->r1) {
        // 0x800A51A0: nop
    
            goto L_800A51AC;
    }
    // 0x800A51A0: nop

    // 0x800A51A4: jal         0x8007BF1C
    // 0x800A51A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_5;
    // 0x800A51A8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
L_800A51AC:
    // 0x800A51AC: jal         0x8006EAA0
    // 0x800A51B0: nop

    is_game_paused(rdram, ctx);
        goto after_6;
    // 0x800A51B0: nop

    after_6:
    // 0x800A51B4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A51B8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A51BC: bne         $v0, $zero, L_800A5A4C
    if (ctx->r2 != 0) {
        // 0x800A51C0: addiu       $t0, $t0, 0x6CDC
        ctx->r8 = ADD32(ctx->r8, 0X6CDC);
            goto L_800A5A4C;
    }
    // 0x800A51C0: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A51C4: lb          $v1, 0x193($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X193);
    // 0x800A51C8: nop

    // 0x800A51CC: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x800A51D0: addu        $t3, $t1, $t4
    ctx->r11 = ADD32(ctx->r9, ctx->r12);
    // 0x800A51D4: lw          $t7, 0x128($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X128);
    // 0x800A51D8: nop

    // 0x800A51DC: slti        $at, $t7, 0x1E
    ctx->r1 = SIGNED(ctx->r15) < 0X1E ? 1 : 0;
    // 0x800A51E0: beq         $at, $zero, L_800A54E0
    if (ctx->r1 == 0) {
        // 0x800A51E4: nop
    
            goto L_800A54E0;
    }
    // 0x800A51E4: nop

    // 0x800A51E8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A51EC: nop

    // 0x800A51F0: lb          $t6, 0x3DA($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X3DA);
    // 0x800A51F4: nop

    // 0x800A51F8: bne         $t6, $zero, L_800A54E0
    if (ctx->r14 != 0) {
        // 0x800A51FC: nop
    
            goto L_800A54E0;
    }
    // 0x800A51FC: nop

    // 0x800A5200: lb          $t8, 0x1D8($t1)
    ctx->r24 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A5204: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A5208: bne         $t8, $zero, L_800A54E0
    if (ctx->r24 != 0) {
        // 0x800A520C: nop
    
            goto L_800A54E0;
    }
    // 0x800A520C: nop

    // 0x800A5210: bne         $a2, $v1, L_800A5374
    if (ctx->r6 != ctx->r3) {
        // 0x800A5214: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A5374;
    }
    // 0x800A5214: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A5218: lw          $t9, 0x6D60($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D60);
    // 0x800A521C: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800A5220: lb          $t5, 0x4B($t9)
    ctx->r13 = MEM_B(ctx->r25, 0X4B);
    // 0x800A5224: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A5228: slti        $at, $t5, 0x3
    ctx->r1 = SIGNED(ctx->r13) < 0X3 ? 1 : 0;
    // 0x800A522C: bne         $at, $zero, L_800A5374
    if (ctx->r1 != 0) {
        // 0x800A5230: nop
    
            goto L_800A5374;
    }
    // 0x800A5230: nop

    // 0x800A5234: sb          $t4, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = ctx->r12;
    // 0x800A5238: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A523C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5240: sb          $a2, 0x3DB($t3)
    MEM_B(0X3DB, ctx->r11) = ctx->r6;
    // 0x800A5244: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5248: jal         0x80001D04
    // 0x800A524C: sb          $zero, 0x3DD($t7)
    MEM_B(0X3DD, ctx->r15) = 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x800A524C: sb          $zero, 0x3DD($t7)
    MEM_B(0X3DD, ctx->r15) = 0;
    after_7:
    // 0x800A5250: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A5254: lw          $v0, 0x6D0C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D0C);
    // 0x800A5258: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A525C: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A5260: beq         $v0, $zero, L_800A527C
    if (ctx->r2 == 0) {
        // 0x800A5264: addiu       $t0, $t0, 0x6CDC
        ctx->r8 = ADD32(ctx->r8, 0X6CDC);
            goto L_800A527C;
    }
    // 0x800A5264: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5268: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A526C: beq         $v0, $at, L_800A52B8
    if (ctx->r2 == ctx->r1) {
        // 0x800A5270: addiu       $t7, $zero, -0x10
        ctx->r15 = ADD32(0, -0X10);
            goto L_800A52B8;
    }
    // 0x800A5270: addiu       $t7, $zero, -0x10
    ctx->r15 = ADD32(0, -0X10);
    // 0x800A5274: b           L_800A52F0
    // 0x800A5278: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_800A52F0;
    // 0x800A5278: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800A527C:
    // 0x800A527C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A5280: addiu       $t6, $zero, -0x15
    ctx->r14 = ADD32(0, -0X15);
    // 0x800A5284: sb          $t6, 0x3DC($t8)
    MEM_B(0X3DC, ctx->r24) = ctx->r14;
    // 0x800A5288: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A528C: addiu       $t9, $zero, 0x20
    ctx->r25 = ADD32(0, 0X20);
    // 0x800A5290: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5294: sb          $t9, 0x3FC($t5)
    MEM_B(0X3FC, ctx->r13) = ctx->r25;
    // 0x800A5298: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A529C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A52A0: lui         $at, 0x4353
    ctx->r1 = S32(0X4353 << 16);
    // 0x800A52A4: swc1        $f4, 0x3CC($t4)
    MEM_W(0X3CC, ctx->r12) = ctx->f4.u32l;
    // 0x800A52A8: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A52AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A52B0: b           L_800A54E0
    // 0x800A52B4: swc1        $f6, 0x3EC($t3)
    MEM_W(0X3EC, ctx->r11) = ctx->f6.u32l;
        goto L_800A54E0;
    // 0x800A52B4: swc1        $f6, 0x3EC($t3)
    MEM_W(0X3EC, ctx->r11) = ctx->f6.u32l;
L_800A52B8:
    // 0x800A52B8: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A52BC: addiu       $t8, $zero, 0x1B
    ctx->r24 = ADD32(0, 0X1B);
    // 0x800A52C0: sb          $t7, 0x3DC($t6)
    MEM_B(0X3DC, ctx->r14) = ctx->r15;
    // 0x800A52C4: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A52C8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A52CC: sb          $t8, 0x3FC($t9)
    MEM_B(0X3FC, ctx->r25) = ctx->r24;
    // 0x800A52D0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A52D4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A52D8: lui         $at, 0x4353
    ctx->r1 = S32(0X4353 << 16);
    // 0x800A52DC: swc1        $f8, 0x3CC($t5)
    MEM_W(0X3CC, ctx->r13) = ctx->f8.u32l;
    // 0x800A52E0: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A52E4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A52E8: b           L_800A54E0
    // 0x800A52EC: swc1        $f10, 0x3EC($t4)
    MEM_W(0X3EC, ctx->r12) = ctx->f10.u32l;
        goto L_800A54E0;
    // 0x800A52EC: swc1        $f10, 0x3EC($t4)
    MEM_W(0X3EC, ctx->r12) = ctx->f10.u32l;
L_800A52F0:
    // 0x800A52F0: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x800A52F4: addiu       $t4, $zero, -0x5A
    ctx->r12 = ADD32(0, -0X5A);
    // 0x800A52F8: beq         $v0, $zero, L_800A5340
    if (ctx->r2 == 0) {
        // 0x800A52FC: addiu       $t7, $zero, -0x3B
        ctx->r15 = ADD32(0, -0X3B);
            goto L_800A5340;
    }
    // 0x800A52FC: addiu       $t7, $zero, -0x3B
    ctx->r15 = ADD32(0, -0X3B);
    // 0x800A5300: beq         $v0, $at, L_800A5340
    if (ctx->r2 == ctx->r1) {
        // 0x800A5304: addiu       $t3, $zero, 0x3C
        ctx->r11 = ADD32(0, 0X3C);
            goto L_800A5340;
    }
    // 0x800A5304: addiu       $t3, $zero, 0x3C
    ctx->r11 = ADD32(0, 0X3C);
    // 0x800A5308: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A530C: addiu       $t6, $zero, 0x5B
    ctx->r14 = ADD32(0, 0X5B);
    // 0x800A5310: sb          $t3, 0x3DC($t7)
    MEM_B(0X3DC, ctx->r15) = ctx->r11;
    // 0x800A5314: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A5318: lui         $at, 0xC28C
    ctx->r1 = S32(0XC28C << 16);
    // 0x800A531C: sb          $t6, 0x3FC($t8)
    MEM_B(0X3FC, ctx->r24) = ctx->r14;
    // 0x800A5320: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A5324: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A5328: lui         $at, 0x435D
    ctx->r1 = S32(0X435D << 16);
    // 0x800A532C: swc1        $f16, 0x3CC($t9)
    MEM_W(0X3CC, ctx->r25) = ctx->f16.u32l;
    // 0x800A5330: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A5334: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A5338: b           L_800A54E0
    // 0x800A533C: swc1        $f18, 0x3EC($t5)
    MEM_W(0X3EC, ctx->r13) = ctx->f18.u32l;
        goto L_800A54E0;
    // 0x800A533C: swc1        $f18, 0x3EC($t5)
    MEM_W(0X3EC, ctx->r13) = ctx->f18.u32l;
L_800A5340:
    // 0x800A5340: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A5344: lui         $at, 0xC35C
    ctx->r1 = S32(0XC35C << 16);
    // 0x800A5348: sb          $t4, 0x3DC($t3)
    MEM_B(0X3DC, ctx->r11) = ctx->r12;
    // 0x800A534C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5350: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A5354: sb          $t7, 0x3FC($t6)
    MEM_B(0X3FC, ctx->r14) = ctx->r15;
    // 0x800A5358: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A535C: lui         $at, 0x428E
    ctx->r1 = S32(0X428E << 16);
    // 0x800A5360: swc1        $f4, 0x3CC($t8)
    MEM_W(0X3CC, ctx->r24) = ctx->f4.u32l;
    // 0x800A5364: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A5368: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A536C: b           L_800A54E0
    // 0x800A5370: swc1        $f6, 0x3EC($t9)
    MEM_W(0X3EC, ctx->r25) = ctx->f6.u32l;
        goto L_800A54E0;
    // 0x800A5370: swc1        $f6, 0x3EC($t9)
    MEM_W(0X3EC, ctx->r25) = ctx->f6.u32l;
L_800A5374:
    // 0x800A5374: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A5378: lw          $t5, 0x6D60($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D60);
    // 0x800A537C: addiu       $t3, $v1, 0x1
    ctx->r11 = ADD32(ctx->r3, 0X1);
    // 0x800A5380: lb          $t4, 0x4B($t5)
    ctx->r12 = MEM_B(ctx->r13, 0X4B);
    // 0x800A5384: nop

    // 0x800A5388: bne         $t4, $t3, L_800A54E0
    if (ctx->r12 != ctx->r11) {
        // 0x800A538C: nop
    
            goto L_800A54E0;
    }
    // 0x800A538C: nop

    // 0x800A5390: beq         $v1, $zero, L_800A54E0
    if (ctx->r3 == 0) {
        // 0x800A5394: addiu       $t7, $zero, 0x3
        ctx->r15 = ADD32(0, 0X3);
            goto L_800A54E0;
    }
    // 0x800A5394: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x800A5398: sb          $t7, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = ctx->r15;
    // 0x800A539C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A53A0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A53A4: sb          $t6, 0x3DB($t8)
    MEM_B(0X3DB, ctx->r24) = ctx->r14;
    // 0x800A53A8: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A53AC: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A53B0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A53B4: jal         0x80001D04
    // 0x800A53B8: sb          $zero, 0x3DD($t9)
    MEM_B(0X3DD, ctx->r25) = 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800A53B8: sb          $zero, 0x3DD($t9)
    MEM_B(0X3DD, ctx->r25) = 0;
    after_8:
    // 0x800A53BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A53C0: lw          $v0, 0x6D0C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D0C);
    // 0x800A53C4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A53C8: lw          $t1, 0x18($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X18);
    // 0x800A53CC: beq         $v0, $zero, L_800A53E8
    if (ctx->r2 == 0) {
        // 0x800A53D0: addiu       $t0, $t0, 0x6CDC
        ctx->r8 = ADD32(ctx->r8, 0X6CDC);
            goto L_800A53E8;
    }
    // 0x800A53D0: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A53D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A53D8: beq         $v0, $at, L_800A5424
    if (ctx->r2 == ctx->r1) {
        // 0x800A53DC: addiu       $t9, $zero, 0x29
        ctx->r25 = ADD32(0, 0X29);
            goto L_800A5424;
    }
    // 0x800A53DC: addiu       $t9, $zero, 0x29
    ctx->r25 = ADD32(0, 0X29);
    // 0x800A53E0: b           L_800A545C
    // 0x800A53E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
        goto L_800A545C;
    // 0x800A53E4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_800A53E8:
    // 0x800A53E8: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A53EC: addiu       $t5, $zero, 0x33
    ctx->r13 = ADD32(0, 0X33);
    // 0x800A53F0: sb          $t5, 0x3DC($t4)
    MEM_B(0X3DC, ctx->r12) = ctx->r13;
    // 0x800A53F4: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A53F8: addiu       $t3, $zero, -0x29
    ctx->r11 = ADD32(0, -0X29);
    // 0x800A53FC: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x800A5400: sb          $t3, 0x3BC($t7)
    MEM_B(0X3BC, ctx->r15) = ctx->r11;
    // 0x800A5404: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5408: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A540C: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5410: swc1        $f8, 0x3CC($t6)
    MEM_W(0X3CC, ctx->r14) = ctx->f8.u32l;
    // 0x800A5414: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A5418: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A541C: b           L_800A54E0
    // 0x800A5420: swc1        $f10, 0x3AC($t8)
    MEM_W(0X3AC, ctx->r24) = ctx->f10.u32l;
        goto L_800A54E0;
    // 0x800A5420: swc1        $f10, 0x3AC($t8)
    MEM_W(0X3AC, ctx->r24) = ctx->f10.u32l;
L_800A5424:
    // 0x800A5424: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A5428: addiu       $t4, $zero, -0x1F
    ctx->r12 = ADD32(0, -0X1F);
    // 0x800A542C: sb          $t9, 0x3DC($t5)
    MEM_B(0X3DC, ctx->r13) = ctx->r25;
    // 0x800A5430: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A5434: lui         $at, 0x4352
    ctx->r1 = S32(0X4352 << 16);
    // 0x800A5438: sb          $t4, 0x3BC($t3)
    MEM_B(0X3BC, ctx->r11) = ctx->r12;
    // 0x800A543C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A5440: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A5444: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5448: swc1        $f16, 0x3CC($t7)
    MEM_W(0X3CC, ctx->r15) = ctx->f16.u32l;
    // 0x800A544C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5450: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A5454: b           L_800A54E0
    // 0x800A5458: swc1        $f18, 0x3AC($t6)
    MEM_W(0X3AC, ctx->r14) = ctx->f18.u32l;
        goto L_800A54E0;
    // 0x800A5458: swc1        $f18, 0x3AC($t6)
    MEM_W(0X3AC, ctx->r14) = ctx->f18.u32l;
L_800A545C:
    // 0x800A545C: lh          $v0, 0x0($t1)
    ctx->r2 = MEM_H(ctx->r9, 0X0);
    // 0x800A5460: addiu       $t6, $zero, -0x32
    ctx->r14 = ADD32(0, -0X32);
    // 0x800A5464: beq         $v0, $zero, L_800A54AC
    if (ctx->r2 == 0) {
        // 0x800A5468: addiu       $t9, $zero, -0x64
        ctx->r25 = ADD32(0, -0X64);
            goto L_800A54AC;
    }
    // 0x800A5468: addiu       $t9, $zero, -0x64
    ctx->r25 = ADD32(0, -0X64);
    // 0x800A546C: beq         $v0, $at, L_800A54AC
    if (ctx->r2 == ctx->r1) {
        // 0x800A5470: addiu       $t8, $zero, 0x64
        ctx->r24 = ADD32(0, 0X64);
            goto L_800A54AC;
    }
    // 0x800A5470: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x800A5474: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A5478: addiu       $t5, $zero, 0x32
    ctx->r13 = ADD32(0, 0X32);
    // 0x800A547C: sb          $t8, 0x3DC($t9)
    MEM_B(0X3DC, ctx->r25) = ctx->r24;
    // 0x800A5480: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A5484: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A5488: sb          $t5, 0x3BC($t4)
    MEM_B(0X3BC, ctx->r12) = ctx->r13;
    // 0x800A548C: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A5490: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A5494: lui         $at, 0xC248
    ctx->r1 = S32(0XC248 << 16);
    // 0x800A5498: swc1        $f4, 0x3CC($t3)
    MEM_W(0X3CC, ctx->r11) = ctx->f4.u32l;
    // 0x800A549C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A54A0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A54A4: b           L_800A54E0
    // 0x800A54A8: swc1        $f6, 0x3AC($t7)
    MEM_W(0X3AC, ctx->r15) = ctx->f6.u32l;
        goto L_800A54E0;
    // 0x800A54A8: swc1        $f6, 0x3AC($t7)
    MEM_W(0X3AC, ctx->r15) = ctx->f6.u32l;
L_800A54AC:
    // 0x800A54AC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A54B0: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800A54B4: sb          $t6, 0x3DC($t8)
    MEM_B(0X3DC, ctx->r24) = ctx->r14;
    // 0x800A54B8: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A54BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A54C0: sb          $t9, 0x3BC($t5)
    MEM_B(0X3BC, ctx->r13) = ctx->r25;
    // 0x800A54C4: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A54C8: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A54CC: swc1        $f8, 0x3CC($t4)
    MEM_W(0X3CC, ctx->r12) = ctx->f8.u32l;
    // 0x800A54D0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A54D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A54D8: nop

    // 0x800A54DC: swc1        $f10, 0x3AC($t3)
    MEM_W(0X3AC, ctx->r11) = ctx->f10.u32l;
L_800A54E0:
    // 0x800A54E0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A54E4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A54E8: lb          $v1, 0x3DA($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DA);
    // 0x800A54EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A54F0: beq         $v1, $zero, L_800A5A4C
    if (ctx->r3 == 0) {
        // 0x800A54F4: nop
    
            goto L_800A5A4C;
    }
    // 0x800A54F4: nop

    // 0x800A54F8: bne         $v1, $at, L_800A57A4
    if (ctx->r3 != ctx->r1) {
        // 0x800A54FC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A57A4;
    }
    // 0x800A54FC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A5500: lb          $v1, 0x3DB($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DB);
    // 0x800A5504: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5508: bne         $a2, $v1, L_800A5698
    if (ctx->r6 != ctx->r3) {
        // 0x800A550C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A5698;
    }
    // 0x800A550C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A5510: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A5514: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A5518: lb          $v1, 0x3DC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A551C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A5520: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A5524: subu        $t6, $v1, $t7
    ctx->r14 = SUB32(ctx->r3, ctx->r15);
    // 0x800A5528: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x800A552C: lwc1        $f0, 0x3CC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5530: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5534: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A5538: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A553C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x800A5540: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5544: bc1f        L_800A5564
    if (!c1cs) {
        // 0x800A5548: nop
    
            goto L_800A5564;
    }
    // 0x800A5548: nop

    // 0x800A554C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x800A5550: nop

    // 0x800A5554: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5558: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x800A555C: b           L_800A5574
    // 0x800A5560: swc1        $f8, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f8.u32l;
        goto L_800A5574;
    // 0x800A5560: swc1        $f8, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f8.u32l;
L_800A5564:
    // 0x800A5564: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A5568: nop

    // 0x800A556C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5570: swc1        $f16, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f16.u32l;
L_800A5574:
    // 0x800A5574: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5578: nop

    // 0x800A557C: lb          $v1, 0x3FC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3FC);
    // 0x800A5580: lwc1        $f0, 0x3EC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x800A5584: addu        $t8, $v1, $a0
    ctx->r24 = ADD32(ctx->r3, ctx->r4);
    // 0x800A5588: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x800A558C: nop

    // 0x800A5590: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A5594: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800A5598: nop

    // 0x800A559C: bc1f        L_800A55BC
    if (!c1cs) {
        // 0x800A55A0: nop
    
            goto L_800A55BC;
    }
    // 0x800A55A0: nop

    // 0x800A55A4: mtc1        $a0, $f6
    ctx->f6.u32l = ctx->r4;
    // 0x800A55A8: nop

    // 0x800A55AC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A55B0: sub.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800A55B4: b           L_800A55CC
    // 0x800A55B8: swc1        $f10, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f10.u32l;
        goto L_800A55CC;
    // 0x800A55B8: swc1        $f10, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f10.u32l;
L_800A55BC:
    // 0x800A55BC: mtc1        $v1, $f16
    ctx->f16.u32l = ctx->r3;
    // 0x800A55C0: nop

    // 0x800A55C4: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A55C8: swc1        $f18, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f18.u32l;
L_800A55CC:
    // 0x800A55CC: lb          $t9, 0x193($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X193);
    // 0x800A55D0: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A55D4: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800A55D8: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x800A55DC: lw          $t3, 0x128($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X128);
    // 0x800A55E0: nop

    // 0x800A55E4: slti        $at, $t3, 0x3C
    ctx->r1 = SIGNED(ctx->r11) < 0X3C ? 1 : 0;
    // 0x800A55E8: bne         $at, $zero, L_800A5608
    if (ctx->r1 != 0) {
        // 0x800A55EC: nop
    
            goto L_800A5608;
    }
    // 0x800A55EC: nop

    // 0x800A55F0: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A55F4: jal         0x80001D04
    // 0x800A55F8: sb          $t7, 0x3DB($t6)
    MEM_B(0X3DB, ctx->r14) = ctx->r15;
    sound_play(rdram, ctx);
        goto after_9;
    // 0x800A55F8: sb          $t7, 0x3DB($t6)
    MEM_B(0X3DB, ctx->r14) = ctx->r15;
    after_9:
    // 0x800A55FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5600: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5604: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5608:
    // 0x800A5608: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A560C: nop

    // 0x800A5610: lb          $t8, 0x3DC($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A5614: lwc1        $f4, 0x3CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5618: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x800A561C: nop

    // 0x800A5620: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5624: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800A5628: nop

    // 0x800A562C: bc1f        L_800A570C
    if (!c1cs) {
        // 0x800A5630: nop
    
            goto L_800A570C;
    }
    // 0x800A5630: nop

    // 0x800A5634: lb          $t9, 0x3FC($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3FC);
    // 0x800A5638: lwc1        $f10, 0x3EC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x800A563C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A5640: nop

    // 0x800A5644: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5648: c.eq.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl == ctx->f18.fl;
    // 0x800A564C: nop

    // 0x800A5650: bc1f        L_800A570C
    if (!c1cs) {
        // 0x800A5654: nop
    
            goto L_800A570C;
    }
    // 0x800A5654: nop

    // 0x800A5658: lb          $t5, 0x3DD($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X3DD);
    // 0x800A565C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5660: bne         $t5, $zero, L_800A570C
    if (ctx->r13 != 0) {
        // 0x800A5664: addiu       $a1, $a1, 0x6D40
        ctx->r5 = ADD32(ctx->r5, 0X6D40);
            goto L_800A570C;
    }
    // 0x800A5664: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    // 0x800A5668: lw          $t4, 0x0($a1)
    ctx->r12 = MEM_W(ctx->r5, 0X0);
    // 0x800A566C: nop

    // 0x800A5670: bne         $t4, $zero, L_800A5690
    if (ctx->r12 != 0) {
        // 0x800A5674: nop
    
            goto L_800A5690;
    }
    // 0x800A5674: nop

    // 0x800A5678: jal         0x80001D04
    // 0x800A567C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A567C: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_10:
    // 0x800A5680: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5684: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5688: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A568C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5690:
    // 0x800A5690: b           L_800A570C
    // 0x800A5694: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
        goto L_800A570C;
    // 0x800A5694: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
L_800A5698:
    // 0x800A5698: bne         $v1, $at, L_800A570C
    if (ctx->r3 != ctx->r1) {
        // 0x800A569C: nop
    
            goto L_800A570C;
    }
    // 0x800A569C: nop

    // 0x800A56A0: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x800A56A4: lwc1        $f4, 0x3CC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A56A8: sll         $t7, $t3, 2
    ctx->r15 = S32(ctx->r11 << 2);
    // 0x800A56AC: subu        $t7, $t7, $t3
    ctx->r15 = SUB32(ctx->r15, ctx->r11);
    // 0x800A56B0: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A56B4: addu        $t7, $t7, $t3
    ctx->r15 = ADD32(ctx->r15, ctx->r11);
    // 0x800A56B8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800A56BC: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A56C0: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A56C4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A56C8: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A56CC: swc1        $f8, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f8.u32l;
    // 0x800A56D0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A56D4: nop

    // 0x800A56D8: lwc1        $f16, 0x3EC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3EC);
    // 0x800A56DC: nop

    // 0x800A56E0: add.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A56E4: swc1        $f10, 0x3EC($v0)
    MEM_W(0X3EC, ctx->r2) = ctx->f10.u32l;
    // 0x800A56E8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A56EC: nop

    // 0x800A56F0: lwc1        $f18, 0x3CC($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A56F4: nop

    // 0x800A56F8: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800A56FC: nop

    // 0x800A5700: bc1f        L_800A570C
    if (!c1cs) {
        // 0x800A5704: nop
    
            goto L_800A570C;
    }
    // 0x800A5704: nop

    // 0x800A5708: sb          $zero, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = 0;
L_800A570C:
    // 0x800A570C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5710: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5714: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A5718: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800A571C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800A5720: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800A5724: addiu       $t9, $zero, -0x60
    ctx->r25 = ADD32(0, -0X60);
    // 0x800A5728: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A572C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A5730: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5734: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5738: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A573C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A5740: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A5744: jal         0x800AA600
    // 0x800A5748: addiu       $a3, $a3, 0x3E0
    ctx->r7 = ADD32(ctx->r7, 0X3E0);
    hud_element_render(rdram, ctx);
        goto after_11;
    // 0x800A5748: addiu       $a3, $a3, 0x3E0
    ctx->r7 = ADD32(ctx->r7, 0X3E0);
    after_11:
    // 0x800A574C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5750: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5754: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5758: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A575C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5760: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5764: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A5768: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A576C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5770: jal         0x800AA600
    // 0x800A5774: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    hud_element_render(rdram, ctx);
        goto after_12;
    // 0x800A5774: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    after_12:
    // 0x800A5778: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A577C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5780: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A5784: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800A5788: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800A578C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800A5790: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800A5794: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800A5798: b           L_800A5A4C
    // 0x800A579C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
        goto L_800A5A4C;
    // 0x800A579C: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800A57A0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800A57A4:
    // 0x800A57A4: bne         $v1, $at, L_800A5A4C
    if (ctx->r3 != ctx->r1) {
        // 0x800A57A8: nop
    
            goto L_800A5A4C;
    }
    // 0x800A57A8: nop

    // 0x800A57AC: lb          $v1, 0x3DB($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DB);
    // 0x800A57B0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A57B4: bne         $v1, $at, L_800A5948
    if (ctx->r3 != ctx->r1) {
        // 0x800A57B8: nop
    
            goto L_800A5948;
    }
    // 0x800A57B8: nop

    // 0x800A57BC: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A57C0: lb          $v1, 0x3DC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A57C4: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800A57C8: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x800A57CC: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800A57D0: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800A57D4: addu        $t6, $v1, $t7
    ctx->r14 = ADD32(ctx->r3, ctx->r15);
    // 0x800A57D8: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800A57DC: lwc1        $f0, 0x3CC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A57E0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A57E4: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800A57E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A57EC: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x800A57F0: nop

    // 0x800A57F4: bc1f        L_800A5814
    if (!c1cs) {
        // 0x800A57F8: nop
    
            goto L_800A5814;
    }
    // 0x800A57F8: nop

    // 0x800A57FC: mtc1        $a0, $f16
    ctx->f16.u32l = ctx->r4;
    // 0x800A5800: nop

    // 0x800A5804: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5808: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A580C: b           L_800A5824
    // 0x800A5810: swc1        $f18, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f18.u32l;
        goto L_800A5824;
    // 0x800A5810: swc1        $f18, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f18.u32l;
L_800A5814:
    // 0x800A5814: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x800A5818: nop

    // 0x800A581C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5820: swc1        $f4, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f4.u32l;
L_800A5824:
    // 0x800A5824: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5828: nop

    // 0x800A582C: lb          $v1, 0x3BC($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X3BC);
    // 0x800A5830: lwc1        $f0, 0x3AC($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X3AC);
    // 0x800A5834: subu        $t8, $v1, $a0
    ctx->r24 = SUB32(ctx->r3, ctx->r4);
    // 0x800A5838: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800A583C: nop

    // 0x800A5840: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A5844: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x800A5848: nop

    // 0x800A584C: bc1f        L_800A586C
    if (!c1cs) {
        // 0x800A5850: nop
    
            goto L_800A586C;
    }
    // 0x800A5850: nop

    // 0x800A5854: mtc1        $a0, $f10
    ctx->f10.u32l = ctx->r4;
    // 0x800A5858: nop

    // 0x800A585C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5860: add.s       $f6, $f0, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f0.fl + ctx->f18.fl;
    // 0x800A5864: b           L_800A587C
    // 0x800A5868: swc1        $f6, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f6.u32l;
        goto L_800A587C;
    // 0x800A5868: swc1        $f6, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f6.u32l;
L_800A586C:
    // 0x800A586C: mtc1        $v1, $f4
    ctx->f4.u32l = ctx->r3;
    // 0x800A5870: nop

    // 0x800A5874: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5878: swc1        $f8, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f8.u32l;
L_800A587C:
    // 0x800A587C: lb          $t9, 0x193($t1)
    ctx->r25 = MEM_B(ctx->r9, 0X193);
    // 0x800A5880: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A5884: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x800A5888: addu        $t4, $t1, $t5
    ctx->r12 = ADD32(ctx->r9, ctx->r13);
    // 0x800A588C: lw          $t3, 0x128($t4)
    ctx->r11 = MEM_W(ctx->r12, 0X128);
    // 0x800A5890: nop

    // 0x800A5894: slti        $at, $t3, 0x3C
    ctx->r1 = SIGNED(ctx->r11) < 0X3C ? 1 : 0;
    // 0x800A5898: bne         $at, $zero, L_800A58B8
    if (ctx->r1 != 0) {
        // 0x800A589C: nop
    
            goto L_800A58B8;
    }
    // 0x800A589C: nop

    // 0x800A58A0: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A58A4: jal         0x80001D04
    // 0x800A58A8: sb          $a2, 0x3DB($t7)
    MEM_B(0X3DB, ctx->r15) = ctx->r6;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x800A58A8: sb          $a2, 0x3DB($t7)
    MEM_B(0X3DB, ctx->r15) = ctx->r6;
    after_13:
    // 0x800A58AC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A58B0: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A58B4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A58B8:
    // 0x800A58B8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A58BC: nop

    // 0x800A58C0: lb          $t6, 0x3DC($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X3DC);
    // 0x800A58C4: lwc1        $f16, 0x3CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A58C8: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x800A58CC: nop

    // 0x800A58D0: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A58D4: c.eq.s      $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f16.fl == ctx->f18.fl;
    // 0x800A58D8: nop

    // 0x800A58DC: bc1f        L_800A59BC
    if (!c1cs) {
        // 0x800A58E0: nop
    
            goto L_800A59BC;
    }
    // 0x800A58E0: nop

    // 0x800A58E4: lb          $t8, 0x3BC($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X3BC);
    // 0x800A58E8: lwc1        $f6, 0x3AC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X3AC);
    // 0x800A58EC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800A58F0: nop

    // 0x800A58F4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A58F8: c.eq.s      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.fl == ctx->f8.fl;
    // 0x800A58FC: nop

    // 0x800A5900: bc1f        L_800A59BC
    if (!c1cs) {
        // 0x800A5904: nop
    
            goto L_800A59BC;
    }
    // 0x800A5904: nop

    // 0x800A5908: lb          $t9, 0x3DD($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X3DD);
    // 0x800A590C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5910: bne         $t9, $zero, L_800A59BC
    if (ctx->r25 != 0) {
        // 0x800A5914: addiu       $a1, $a1, 0x6D40
        ctx->r5 = ADD32(ctx->r5, 0X6D40);
            goto L_800A59BC;
    }
    // 0x800A5914: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    // 0x800A5918: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800A591C: nop

    // 0x800A5920: bne         $t5, $zero, L_800A5940
    if (ctx->r13 != 0) {
        // 0x800A5924: nop
    
            goto L_800A5940;
    }
    // 0x800A5924: nop

    // 0x800A5928: jal         0x80001D04
    // 0x800A592C: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    sound_play(rdram, ctx);
        goto after_14;
    // 0x800A592C: addiu       $a0, $zero, 0x101
    ctx->r4 = ADD32(0, 0X101);
    after_14:
    // 0x800A5930: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5934: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5938: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A593C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800A5940:
    // 0x800A5940: b           L_800A59BC
    // 0x800A5944: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
        goto L_800A59BC;
    // 0x800A5944: sb          $a2, 0x3DD($v0)
    MEM_B(0X3DD, ctx->r2) = ctx->r6;
L_800A5948:
    // 0x800A5948: bne         $a2, $v1, L_800A59BC
    if (ctx->r6 != ctx->r3) {
        // 0x800A594C: nop
    
            goto L_800A59BC;
    }
    // 0x800A594C: nop

    // 0x800A5950: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5954: lwc1        $f16, 0x3CC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A5958: sll         $t3, $t4, 2
    ctx->r11 = S32(ctx->r12 << 2);
    // 0x800A595C: subu        $t3, $t3, $t4
    ctx->r11 = SUB32(ctx->r11, ctx->r12);
    // 0x800A5960: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x800A5964: addu        $t3, $t3, $t4
    ctx->r11 = ADD32(ctx->r11, ctx->r12);
    // 0x800A5968: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x800A596C: lui         $at, 0x4348
    ctx->r1 = S32(0X4348 << 16);
    // 0x800A5970: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5974: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A5978: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A597C: swc1        $f18, 0x3CC($v0)
    MEM_W(0X3CC, ctx->r2) = ctx->f18.u32l;
    // 0x800A5980: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5984: nop

    // 0x800A5988: lwc1        $f4, 0x3AC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X3AC);
    // 0x800A598C: nop

    // 0x800A5990: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A5994: swc1        $f6, 0x3AC($v0)
    MEM_W(0X3AC, ctx->r2) = ctx->f6.u32l;
    // 0x800A5998: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A599C: nop

    // 0x800A59A0: lwc1        $f10, 0x3CC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X3CC);
    // 0x800A59A4: nop

    // 0x800A59A8: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x800A59AC: nop

    // 0x800A59B0: bc1f        L_800A59BC
    if (!c1cs) {
        // 0x800A59B4: nop
    
            goto L_800A59BC;
    }
    // 0x800A59B4: nop

    // 0x800A59B8: sb          $zero, 0x3DA($v0)
    MEM_B(0X3DA, ctx->r2) = 0;
L_800A59BC:
    // 0x800A59BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A59C0: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A59C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A59C8: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A59CC: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A59D0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A59D4: addiu       $t8, $zero, -0x60
    ctx->r24 = ADD32(0, -0X60);
    // 0x800A59D8: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800A59DC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800A59E0: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A59E4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A59E8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A59EC: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A59F0: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A59F4: jal         0x800AA600
    // 0x800A59F8: addiu       $a3, $a3, 0x3A0
    ctx->r7 = ADD32(ctx->r7, 0X3A0);
    hud_element_render(rdram, ctx);
        goto after_15;
    // 0x800A59F8: addiu       $a3, $a3, 0x3A0
    ctx->r7 = ADD32(ctx->r7, 0X3A0);
    after_15:
    // 0x800A59FC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5A00: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5A04: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5A08: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5A0C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5A10: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5A14: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A5A18: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A5A1C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5A20: jal         0x800AA600
    // 0x800A5A24: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    hud_element_render(rdram, ctx);
        goto after_16;
    // 0x800A5A24: addiu       $a3, $a3, 0x3C0
    ctx->r7 = ADD32(ctx->r7, 0X3C0);
    after_16:
    // 0x800A5A28: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A5A2C: lw          $v0, 0x6CFC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CFC);
    // 0x800A5A30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A5A34: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A5A38: sw          $t9, 0x6CFC($at)
    MEM_W(0X6CFC, ctx->r1) = ctx->r25;
    // 0x800A5A3C: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A5A40: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800A5A44: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A5A48: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800A5A4C:
    // 0x800A5A4C: jal         0x8007BF1C
    // 0x800A5A50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_17;
    // 0x800A5A50: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_17:
    // 0x800A5A54: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5A58: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5A5C: jr          $ra
    // 0x800A5A60: nop

    return;
    // 0x800A5A60: nop

;}
RECOMP_FUNC void obj_init_audio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003FD68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003FD6C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8003FD70: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8003FD74: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8003FD78: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8003FD7C: lhu         $t7, 0x8($a1)
    ctx->r15 = MEM_HU(ctx->r5, 0X8);
    // 0x8003FD80: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8003FD84: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x8003FD88: lhu         $t8, 0xA($a1)
    ctx->r24 = MEM_HU(ctx->r5, 0XA);
    // 0x8003FD8C: andi        $a0, $t7, 0xFFFF
    ctx->r4 = ctx->r15 & 0XFFFF;
    // 0x8003FD90: sh          $t8, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r24;
    // 0x8003FD94: lbu         $t9, 0xF($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XF);
    // 0x8003FD98: nop

    // 0x8003FD9C: sb          $t9, 0xC($v1)
    MEM_B(0XC, ctx->r3) = ctx->r25;
    // 0x8003FDA0: lbu         $t0, 0xE($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XE);
    // 0x8003FDA4: nop

    // 0x8003FDA8: sb          $t0, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r8;
    // 0x8003FDAC: lbu         $t1, 0xC($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0XC);
    // 0x8003FDB0: nop

    // 0x8003FDB4: sb          $t1, 0x4($v1)
    MEM_B(0X4, ctx->r3) = ctx->r9;
    // 0x8003FDB8: lbu         $t2, 0xD($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0XD);
    // 0x8003FDBC: nop

    // 0x8003FDC0: sb          $t2, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r10;
    // 0x8003FDC4: lbu         $t3, 0x10($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X10);
    // 0x8003FDC8: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8003FDCC: sb          $t3, 0xD($v1)
    MEM_B(0XD, ctx->r3) = ctx->r11;
    // 0x8003FDD0: jal         0x800021B0
    // 0x8003FDD4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    sound_is_looped(rdram, ctx);
        goto after_0;
    // 0x8003FDD4: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_0:
    // 0x8003FDD8: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8003FDDC: beq         $v0, $zero, L_8003FE64
    if (ctx->r2 == 0) {
        // 0x8003FDE0: addiu       $t8, $zero, 0xA
        ctx->r24 = ADD32(0, 0XA);
            goto L_8003FE64;
    }
    // 0x8003FDE0: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8003FDE4: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x8003FDE8: lh          $t5, 0x4($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4);
    // 0x8003FDEC: lh          $t6, 0x6($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X6);
    // 0x8003FDF0: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8003FDF4: addiu       $t7, $zero, 0x9
    ctx->r15 = ADD32(0, 0X9);
    // 0x8003FDF8: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8003FDFC: lbu         $t8, 0x5($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X5);
    // 0x8003FE00: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x8003FE04: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8003FE08: lbu         $t9, 0x4($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X4);
    // 0x8003FE0C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x8003FE10: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8003FE14: lhu         $t0, 0x2($v1)
    ctx->r8 = MEM_HU(ctx->r3, 0X2);
    // 0x8003FE18: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x8003FE1C: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x8003FE20: lbu         $t1, 0xC($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0XC);
    // 0x8003FE24: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003FE28: sw          $t1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r9;
    // 0x8003FE2C: lbu         $t2, 0x6($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X6);
    // 0x8003FE30: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003FE34: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8003FE38: lbu         $t3, 0xD($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0XD);
    // 0x8003FE3C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8003FE40: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x8003FE44: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8003FE48: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8003FE4C: addiu       $t4, $v1, 0x8
    ctx->r12 = ADD32(ctx->r3, 0X8);
    // 0x8003FE50: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8003FE54: jal         0x8000974C
    // 0x8003FE58: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    audspat_point_create(rdram, ctx);
        goto after_1;
    // 0x8003FE58: sw          $t3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r11;
    after_1:
    // 0x8003FE5C: b           L_8003FEDC
    // 0x8003FE60: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
        goto L_8003FEDC;
    // 0x8003FE60: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8003FE64:
    // 0x8003FE64: lh          $t5, 0x2($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X2);
    // 0x8003FE68: lh          $t6, 0x4($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X4);
    // 0x8003FE6C: lh          $t7, 0x6($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X6);
    // 0x8003FE70: lhu         $a0, 0x0($v1)
    ctx->r4 = MEM_HU(ctx->r3, 0X0);
    // 0x8003FE74: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8003FE78: lbu         $t9, 0x5($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X5);
    // 0x8003FE7C: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x8003FE80: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8003FE84: lbu         $t0, 0x4($v1)
    ctx->r8 = MEM_BU(ctx->r3, 0X4);
    // 0x8003FE88: mtc1        $t6, $f16
    ctx->f16.u32l = ctx->r14;
    // 0x8003FE8C: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    // 0x8003FE90: lhu         $t1, 0x2($v1)
    ctx->r9 = MEM_HU(ctx->r3, 0X2);
    // 0x8003FE94: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x8003FE98: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8003FE9C: lbu         $t2, 0xC($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0XC);
    // 0x8003FEA0: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8003FEA4: sw          $t2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r10;
    // 0x8003FEA8: lbu         $t3, 0x6($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X6);
    // 0x8003FEAC: cvt.s.w     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003FEB0: sw          $t3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r11;
    // 0x8003FEB4: lbu         $t4, 0xD($v1)
    ctx->r12 = MEM_BU(ctx->r3, 0XD);
    // 0x8003FEB8: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8003FEBC: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x8003FEC0: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003FEC4: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x8003FEC8: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x8003FECC: sw          $t5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r13;
    // 0x8003FED0: jal         0x8000974C
    // 0x8003FED4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    audspat_point_create(rdram, ctx);
        goto after_2;
    // 0x8003FED4: sw          $t4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r12;
    after_2:
    // 0x8003FED8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_8003FEDC:
    // 0x8003FEDC: jal         0x8000FFB8
    // 0x8003FEE0: nop

    free_object(rdram, ctx);
        goto after_3;
    // 0x8003FEE0: nop

    after_3:
    // 0x8003FEE4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8003FEE8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8003FEEC: jr          $ra
    // 0x8003FEF0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8003FEF0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void allocate_ghost_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800598D0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800598D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800598D8: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x800598DC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800598E0: jal         0x80070C9C
    // 0x800598E4: addiu       $a0, $zero, 0x21C0
    ctx->r4 = ADD32(0, 0X21C0);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800598E4: addiu       $a0, $zero, 0x21C0
    ctx->r4 = ADD32(0, 0X21C0);
    after_0:
    // 0x800598E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800598EC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800598F0: addiu       $a0, $a0, -0x2A60
    ctx->r4 = ADD32(ctx->r4, -0X2A60);
    // 0x800598F4: addiu       $v1, $v1, -0x2A70
    ctx->r3 = ADD32(ctx->r3, -0X2A70);
    // 0x800598F8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800598FC: addiu       $a1, $a1, -0x2A58
    ctx->r5 = ADD32(ctx->r5, -0X2A58);
    // 0x80059900: addiu       $t7, $v0, 0x10E0
    ctx->r15 = ADD32(ctx->r2, 0X10E0);
    // 0x80059904: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80059908: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8005990C: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x80059910: sh          $zero, 0x0($a0)
    MEM_H(0X0, ctx->r4) = 0;
    // 0x80059914: sh          $zero, 0x2($a0)
    MEM_H(0X2, ctx->r4) = 0;
    // 0x80059918: sh          $zero, 0x4($a0)
    MEM_H(0X4, ctx->r4) = 0;
    // 0x8005991C: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
    // 0x80059920: sh          $zero, 0x2($a1)
    MEM_H(0X2, ctx->r5) = 0;
    // 0x80059924: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059928: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005992C: sb          $zero, -0x2A63($at)
    MEM_B(-0X2A63, ctx->r1) = 0;
    // 0x80059930: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80059934: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80059938: sh          $t8, -0x2A54($at)
    MEM_H(-0X2A54, ctx->r1) = ctx->r24;
    // 0x8005993C: jr          $ra
    // 0x80059940: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80059940: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void render_mesh(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800143A8: addiu       $sp, $sp, -0xB0
    ctx->r29 = ADD32(ctx->r29, -0XB0);
    // 0x800143AC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800143B0: lw          $t6, -0x5174($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5174);
    // 0x800143B4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800143B8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800143BC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800143C0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800143C4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800143C8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800143CC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800143D0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800143D4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800143D8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800143DC: sw          $a1, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->r5;
    // 0x800143E0: sw          $a3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r7;
    // 0x800143E4: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x800143E8: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x800143EC: or          $s7, $a0, $zero
    ctx->r23 = ctx->r4 | 0;
    // 0x800143F0: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800143F4: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800143F8: beq         $at, $zero, L_800147C4
    if (ctx->r1 == 0) {
        // 0x800143FC: or          $ra, $zero, $zero
        ctx->r31 = 0 | 0;
            goto L_800147C4;
    }
    // 0x800143FC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x80014400: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x80014404: subu        $t3, $t3, $a2
    ctx->r11 = SUB32(ctx->r11, ctx->r6);
    // 0x80014408: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8001440C: lui         $fp, 0x400
    ctx->r30 = S32(0X400 << 16);
    // 0x80014410: lui         $s4, 0x8000
    ctx->r20 = S32(0X8000 << 16);
    // 0x80014414: or          $t5, $a3, $zero
    ctx->r13 = ctx->r7 | 0;
L_80014418:
    // 0x80014418: lw          $t7, 0x38($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X38);
    // 0x8001441C: andi        $t9, $t5, 0x4
    ctx->r25 = ctx->r13 & 0X4;
    // 0x80014420: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x80014424: lw          $t0, 0x8($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X8);
    // 0x80014428: nop

    // 0x8001442C: andi        $t8, $t0, 0x4
    ctx->r24 = ctx->r8 & 0X4;
    // 0x80014430: beq         $t8, $zero, L_80014440
    if (ctx->r24 == 0) {
        // 0x80014434: andi        $v1, $t0, 0x100
        ctx->r3 = ctx->r8 & 0X100;
            goto L_80014440;
    }
    // 0x80014434: andi        $v1, $t0, 0x100
    ctx->r3 = ctx->r8 & 0X100;
    // 0x80014438: beq         $t9, $zero, L_800147AC
    if (ctx->r25 == 0) {
        // 0x8001443C: nop
    
            goto L_800147AC;
    }
    // 0x8001443C: nop

L_80014440:
    // 0x80014440: bne         $v1, $zero, L_800147A0
    if (ctx->r3 != 0) {
        // 0x80014444: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_800147A0;
    }
    // 0x80014444: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80014448: lh          $a0, 0x2($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X2);
    // 0x8001444C: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x80014450: lw          $t7, 0xC0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC0);
    // 0x80014454: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x80014458: andi        $t1, $t5, 0x4
    ctx->r9 = ctx->r13 & 0X4;
    // 0x8001445C: beq         $t7, $zero, L_80014470
    if (ctx->r15 == 0) {
        // 0x80014460: subu        $s1, $t6, $a0
        ctx->r17 = SUB32(ctx->r14, ctx->r4);
            goto L_80014470;
    }
    // 0x80014460: subu        $s1, $t6, $a0
    ctx->r17 = SUB32(ctx->r14, ctx->r4);
    // 0x80014464: lb          $s0, 0x1($v0)
    ctx->r16 = MEM_B(ctx->r2, 0X1);
    // 0x80014468: b           L_80014478
    // 0x8001446C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
        goto L_80014478;
    // 0x8001446C: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
L_80014470:
    // 0x80014470: or          $s0, $s1, $zero
    ctx->r16 = ctx->r17 | 0;
    // 0x80014474: lh          $t8, 0x10($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X10);
L_80014478:
    // 0x80014478: lw          $t9, 0x8($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X8);
    // 0x8001447C: sll         $t6, $a1, 4
    ctx->r14 = S32(ctx->r5 << 4);
    // 0x80014480: subu        $s5, $t8, $a1
    ctx->r21 = SUB32(ctx->r24, ctx->r5);
    // 0x80014484: addu        $t7, $t9, $t6
    ctx->r15 = ADD32(ctx->r25, ctx->r14);
    // 0x80014488: lw          $t8, 0xB4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XB4);
    // 0x8001448C: sw          $t7, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r15;
    // 0x80014490: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80014494: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x80014498: lw          $t9, 0x44($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X44);
    // 0x8001449C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800144A0: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800144A4: bne         $v1, $at, L_800144BC
    if (ctx->r3 != ctx->r1) {
        // 0x800144A8: addu        $s3, $t9, $t6
        ctx->r19 = ADD32(ctx->r25, ctx->r14);
            goto L_800144BC;
    }
    // 0x800144A8: addu        $s3, $t9, $t6
    ctx->r19 = ADD32(ctx->r25, ctx->r14);
    // 0x800144AC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800144B0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800144B4: b           L_800144DC
    // 0x800144B8: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
        goto L_800144DC;
    // 0x800144B8: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_800144BC:
    // 0x800144BC: lw          $t8, 0x0($s7)
    ctx->r24 = MEM_W(ctx->r23, 0X0);
    // 0x800144C0: lbu         $a3, 0x7($v0)
    ctx->r7 = MEM_BU(ctx->r2, 0X7);
    // 0x800144C4: sll         $t9, $v1, 3
    ctx->r25 = S32(ctx->r3 << 3);
    // 0x800144C8: addu        $t6, $t8, $t9
    ctx->r14 = ADD32(ctx->r24, ctx->r25);
    // 0x800144CC: sll         $t7, $a3, 14
    ctx->r15 = S32(ctx->r7 << 14);
    // 0x800144D0: lw          $s2, 0x0($t6)
    ctx->r18 = MEM_W(ctx->r14, 0X0);
    // 0x800144D4: or          $a3, $t7, $zero
    ctx->r7 = ctx->r15 | 0;
    // 0x800144D8: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
L_800144DC:
    // 0x800144DC: beq         $t1, $zero, L_800144FC
    if (ctx->r9 == 0) {
        // 0x800144E0: ori         $a2, $t0, 0x8
        ctx->r6 = ctx->r8 | 0X8;
            goto L_800144FC;
    }
    // 0x800144E0: ori         $a2, $t0, 0x8
    ctx->r6 = ctx->r8 | 0X8;
    // 0x800144E4: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x800144E8: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x800144EC: and         $t8, $t0, $t7
    ctx->r24 = ctx->r8 & ctx->r15;
    // 0x800144F0: bne         $t8, $zero, L_800144FC
    if (ctx->r24 != 0) {
        // 0x800144F4: ori         $t9, $a2, 0x4
        ctx->r25 = ctx->r6 | 0X4;
            goto L_800144FC;
    }
    // 0x800144F4: ori         $t9, $a2, 0x4
    ctx->r25 = ctx->r6 | 0X4;
    // 0x800144F8: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
L_800144FC:
    // 0x800144FC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80014500: lw          $t6, -0x38E0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X38E0);
    // 0x80014504: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x80014508: bne         $t6, $zero, L_80014544
    if (ctx->r14 != 0) {
        // 0x8001450C: or          $a1, $a3, $zero
        ctx->r5 = ctx->r7 | 0;
            goto L_80014544;
    }
    // 0x8001450C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80014510: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x80014514: addiu       $a0, $sp, 0x74
    ctx->r4 = ADD32(ctx->r29, 0X74);
    // 0x80014518: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x8001451C: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
    extern void dkr_fix_car_steering_wheel_material(uint8_t*, recomp_context*); dkr_fix_car_steering_wheel_material(rdram, ctx);
    // 0x80014520: jal         0x8007B4E8
    // 0x80014524: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    material_set(rdram, ctx);
        goto after_0;
    // 0x80014524: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_0:
    // 0x80014528: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x8001452C: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80014530: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x80014534: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x80014538: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x8001453C: b           L_800145B0
    // 0x80014540: ori         $t4, $t4, 0xA
    ctx->r12 = ctx->r12 | 0XA;
        goto L_800145B0;
    // 0x80014540: ori         $t4, $t4, 0xA
    ctx->r12 = ctx->r12 | 0XA;
L_80014544:
    // 0x80014544: sw          $ra, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r31;
    // 0x80014548: sw          $t2, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r10;
    // 0x8001454C: jal         0x8007B46C
    // 0x80014550: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    set_animated_texture_header(rdram, ctx);
        goto after_1;
    // 0x80014550: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    after_1:
    // 0x80014554: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80014558: addiu       $a2, $a2, -0x5174
    ctx->r6 = ADD32(ctx->r6, -0X5174);
    // 0x8001455C: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x80014560: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x80014564: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80014568: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8001456C: lh          $a1, 0xA($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XA);
    // 0x80014570: lw          $t2, 0xAC($sp)
    ctx->r10 = MEM_W(ctx->r29, 0XAC);
    // 0x80014574: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80014578: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x8001457C: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x80014580: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x80014584: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x80014588: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x8001458C: lw          $t5, 0xBC($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XBC);
    // 0x80014590: lw          $ra, 0x9C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X9C);
    // 0x80014594: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x80014598: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8001459C: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800145A0: lui         $t4, 0xBC00
    ctx->r12 = S32(0XBC00 << 16);
    // 0x800145A4: addu        $t6, $t7, $s4
    ctx->r14 = ADD32(ctx->r15, ctx->r20);
    // 0x800145A8: ori         $t4, $t4, 0xA
    ctx->r12 = ctx->r12 | 0XA;
    // 0x800145AC: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
L_800145B0:
    // 0x800145B0: bne         $s0, $s1, L_80014608
    if (ctx->r16 != ctx->r17) {
        // 0x800145B4: lui         $at, 0x500
        ctx->r1 = S32(0X500 << 16);
            goto L_80014608;
    }
    // 0x800145B4: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800145B8: lw          $v1, 0x74($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X74);
    // 0x800145BC: addu        $v0, $s3, $s4
    ctx->r2 = ADD32(ctx->r19, ctx->r20);
    // 0x800145C0: addiu       $t7, $s1, -0x1
    ctx->r15 = ADD32(ctx->r17, -0X1);
    // 0x800145C4: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800145C8: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x800145CC: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800145D0: andi        $t8, $v0, 0x6
    ctx->r24 = ctx->r2 & 0X6;
    // 0x800145D4: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x800145D8: andi        $t7, $t9, 0xFF
    ctx->r15 = ctx->r25 & 0XFF;
    // 0x800145DC: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800145E0: sll         $t9, $s1, 3
    ctx->r25 = S32(ctx->r17 << 3);
    // 0x800145E4: addu        $t7, $t9, $s1
    ctx->r15 = ADD32(ctx->r25, ctx->r17);
    // 0x800145E8: or          $t8, $t6, $fp
    ctx->r24 = ctx->r14 | ctx->r30;
    // 0x800145EC: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x800145F0: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x800145F4: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800145F8: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800145FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80014600: b           L_80014754
    // 0x80014604: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
        goto L_80014754;
    // 0x80014604: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
L_80014608:
    // 0x80014608: blez        $s0, L_800146DC
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8001460C: addiu       $t8, $zero, 0x80
        ctx->r24 = ADD32(0, 0X80);
            goto L_800146DC;
    }
    // 0x8001460C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80014610: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x80014614: addu        $v0, $s3, $s4
    ctx->r2 = ADD32(ctx->r19, ctx->r20);
    // 0x80014618: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8001461C: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x80014620: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80014624: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x80014628: andi        $t9, $v0, 0x6
    ctx->r25 = ctx->r2 & 0X6;
    // 0x8001462C: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x80014630: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x80014634: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x80014638: sll         $t8, $s0, 3
    ctx->r24 = S32(ctx->r16 << 3);
    // 0x8001463C: addu        $t7, $t8, $s0
    ctx->r15 = ADD32(ctx->r24, ctx->r16);
    // 0x80014640: or          $t9, $t6, $fp
    ctx->r25 = ctx->r14 | ctx->r30;
    // 0x80014644: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x80014648: addiu       $t8, $t6, 0x8
    ctx->r24 = ADD32(ctx->r14, 0X8);
    // 0x8001464C: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x80014650: or          $t6, $t9, $t7
    ctx->r14 = ctx->r25 | ctx->r15;
    // 0x80014654: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80014658: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
    // 0x8001465C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x80014660: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x80014664: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x80014668: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8001466C: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x80014670: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x80014674: sw          $t4, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r12;
    // 0x80014678: lw          $a2, 0x74($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X74);
    // 0x8001467C: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x80014680: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80014684: addu        $t7, $s3, $t9
    ctx->r15 = ADD32(ctx->r19, ctx->r25);
    // 0x80014688: subu        $v1, $s1, $s0
    ctx->r3 = SUB32(ctx->r17, ctx->r16);
    // 0x8001468C: addiu       $t8, $a2, 0x8
    ctx->r24 = ADD32(ctx->r6, 0X8);
    // 0x80014690: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x80014694: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x80014698: addu        $a3, $t7, $s4
    ctx->r7 = ADD32(ctx->r15, ctx->r20);
    // 0x8001469C: andi        $t9, $a3, 0x6
    ctx->r25 = ctx->r7 & 0X6;
    // 0x800146A0: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800146A4: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x800146A8: ori         $t6, $t7, 0x1
    ctx->r14 = ctx->r15 | 0X1;
    // 0x800146AC: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800146B0: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800146B4: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800146B8: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800146BC: or          $t7, $t9, $fp
    ctx->r15 = ctx->r25 | ctx->r30;
    // 0x800146C0: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800146C4: addiu       $t6, $t9, 0x8
    ctx->r14 = ADD32(ctx->r25, 0X8);
    // 0x800146C8: andi        $t8, $t6, 0xFFFF
    ctx->r24 = ctx->r14 & 0XFFFF;
    // 0x800146CC: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800146D0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800146D4: b           L_8001473C
    // 0x800146D8: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
        goto L_8001473C;
    // 0x800146D8: sw          $a3, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r7;
L_800146DC:
    // 0x800146DC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800146E0: addu        $v0, $s3, $s4
    ctx->r2 = ADD32(ctx->r19, ctx->r20);
    // 0x800146E4: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x800146E8: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x800146EC: sw          $t8, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r24;
    // 0x800146F0: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
    // 0x800146F4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800146F8: addiu       $t7, $s1, -0x1
    ctx->r15 = ADD32(ctx->r17, -0X1);
    // 0x800146FC: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x80014700: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x80014704: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80014708: andi        $t9, $v0, 0x6
    ctx->r25 = ctx->r2 & 0X6;
    // 0x8001470C: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x80014710: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80014714: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x80014718: sll         $t6, $s1, 3
    ctx->r14 = S32(ctx->r17 << 3);
    // 0x8001471C: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80014720: or          $t9, $t8, $fp
    ctx->r25 = ctx->r24 | ctx->r30;
    // 0x80014724: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x80014728: addiu       $t6, $t8, 0x8
    ctx->r14 = ADD32(ctx->r24, 0X8);
    // 0x8001472C: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x80014730: or          $t8, $t9, $t7
    ctx->r24 = ctx->r25 | ctx->r15;
    // 0x80014734: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x80014738: sw          $v0, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r2;
L_8001473C:
    // 0x8001473C: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x80014740: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x80014744: addiu       $t9, $t6, 0x8
    ctx->r25 = ADD32(ctx->r14, 0X8);
    // 0x80014748: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8001474C: sw          $t7, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r15;
    // 0x80014750: sw          $t4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r12;
L_80014754:
    // 0x80014754: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80014758: addiu       $t9, $s5, -0x1
    ctx->r25 = ADD32(ctx->r21, -0X1);
    // 0x8001475C: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x80014760: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80014764: sw          $t6, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r14;
    // 0x80014768: or          $t8, $t7, $s6
    ctx->r24 = ctx->r15 | ctx->r22;
    // 0x8001476C: andi        $t6, $t8, 0xFF
    ctx->r14 = ctx->r24 & 0XFF;
    // 0x80014770: sll         $t9, $t6, 16
    ctx->r25 = S32(ctx->r14 << 16);
    // 0x80014774: sll         $t8, $s5, 4
    ctx->r24 = S32(ctx->r21 << 4);
    // 0x80014778: andi        $t6, $t8, 0xFFFF
    ctx->r14 = ctx->r24 & 0XFFFF;
    // 0x8001477C: or          $t7, $t9, $at
    ctx->r15 = ctx->r25 | ctx->r1;
    // 0x80014780: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x80014784: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x80014788: lw          $t8, 0x7C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X7C);
    // 0x8001478C: nop

    // 0x80014790: addu        $t7, $t8, $s4
    ctx->r15 = ADD32(ctx->r24, ctx->r20);
    // 0x80014794: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x80014798: lh          $t1, 0x28($s7)
    ctx->r9 = MEM_H(ctx->r23, 0X28);
    // 0x8001479C: nop

L_800147A0:
    // 0x800147A0: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800147A4: b           L_800147B0
    // 0x800147A8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
        goto L_800147B0;
    // 0x800147A8: addiu       $t3, $t3, 0xC
    ctx->r11 = ADD32(ctx->r11, 0XC);
L_800147AC:
    // 0x800147AC: addiu       $ra, $zero, 0x1
    ctx->r31 = ADD32(0, 0X1);
L_800147B0:
    // 0x800147B0: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800147B4: beq         $at, $zero, L_800147C8
    if (ctx->r1 == 0) {
        // 0x800147B8: slt         $at, $t2, $t1
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_800147C8;
    }
    // 0x800147B8: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800147BC: beq         $ra, $zero, L_80014418
    if (ctx->r31 == 0) {
        // 0x800147C0: nop
    
            goto L_80014418;
    }
    // 0x800147C0: nop

L_800147C4:
    // 0x800147C4: slt         $at, $t2, $t1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r9) ? 1 : 0;
L_800147C8:
    // 0x800147C8: bne         $at, $zero, L_800147D8
    if (ctx->r1 != 0) {
        // 0x800147CC: lw          $t6, 0x74($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X74);
            goto L_800147D8;
    }
    // 0x800147CC: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
    // 0x800147D0: addiu       $t2, $zero, -0x1
    ctx->r10 = ADD32(0, -0X1);
    // 0x800147D4: lw          $t6, 0x74($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X74);
L_800147D8:
    // 0x800147D8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800147DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800147E0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800147E4: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800147E8: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800147EC: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800147F0: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800147F4: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800147F8: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800147FC: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80014800: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80014804: addiu       $sp, $sp, 0xB0
    ctx->r29 = ADD32(ctx->r29, 0XB0);
    // 0x80014808: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8001480C: jr          $ra
    // 0x80014810: sw          $t6, -0x5174($at)
    MEM_W(-0X5174, ctx->r1) = ctx->r14;
    return;
    // 0x80014810: sw          $t6, -0x5174($at)
    MEM_W(-0X5174, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void write_to_object_render_stack(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066488: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8006648C: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80066490: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066494: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80066498: addiu       $t7, $t7, 0xAC0
    ctx->r15 = ADD32(ctx->r15, 0XAC0);
    // 0x8006649C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800664A0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800664A4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800664A8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800664AC: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800664B0: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800664B4: lwc1        $f4, 0x2C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800664B8: lh          $t8, 0x32($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X32);
    // 0x800664BC: lh          $t9, 0x36($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X36);
    // 0x800664C0: lh          $t0, 0x3A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X3A);
    // 0x800664C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800664C8: sh          $zero, 0x38($v1)
    MEM_H(0X38, ctx->r3) = 0;
    // 0x800664CC: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x800664D0: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x800664D4: swc1        $f12, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f12.u32l;
    // 0x800664D8: swc1        $f14, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f14.u32l;
    // 0x800664DC: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    // 0x800664E0: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x800664E4: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x800664E8: jal         0x80029F18
    // 0x800664EC: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    get_level_segment_index_from_position(rdram, ctx);
        goto after_0;
    // 0x800664EC: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    after_0:
    // 0x800664F0: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800664F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800664F8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800664FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066500: sh          $v0, 0x34($v1)
    MEM_H(0X34, ctx->r3) = ctx->r2;
    // 0x80066504: sb          $t1, 0xD14($at)
    MEM_B(0XD14, ctx->r1) = ctx->r9;
    // 0x80066508: jr          $ra
    // 0x8006650C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006650C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void light_direction_calc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033C08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C0C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80033C10: lwc1        $f12, -0x2B40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B40);
    // 0x80033C14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80033C18: c.lt.s      $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f14.fl < ctx->f12.fl;
    // 0x80033C1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80033C20: bc1f        L_80033CA4
    if (!c1cs) {
        // 0x80033C24: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_80033CA4;
    }
    // 0x80033C24: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033C28: jal         0x800C9AD0
    // 0x80033C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80033C2C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80033C30: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033C34: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80033C38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C3C: div.s       $f2, $f4, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80033C40: lwc1        $f6, -0x2B3C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2B3C);
    // 0x80033C44: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80033C48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C4C: lwc1        $f10, 0x7C($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X7C);
    // 0x80033C50: lwc1        $f18, -0x2B38($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B38);
    // 0x80033C54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033C58: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80033C5C: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80033C60: lwc1        $f6, 0x80($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X80);
    // 0x80033C64: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80033C68: nop

    // 0x80033C6C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80033C70: lwc1        $f18, -0x2B34($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X2B34);
    // 0x80033C74: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80033C78: lwc1        $f6, 0x84($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X84);
    // 0x80033C7C: mul.s       $f4, $f18, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80033C80: add.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80033C84: mul.s       $f16, $f4, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80033C88: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x80033C8C: c.lt.s      $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f12.fl < ctx->f14.fl;
    // 0x80033C90: nop

    // 0x80033C94: bc1f        L_80033CAC
    if (!c1cs) {
        // 0x80033C98: nop
    
            goto L_80033CAC;
    }
    // 0x80033C98: nop

    // 0x80033C9C: b           L_80033CAC
    // 0x80033CA0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
        goto L_80033CAC;
    // 0x80033CA0: mov.s       $f12, $f14
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    ctx->f12.fl = ctx->f14.fl;
L_80033CA4:
    // 0x80033CA4: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80033CA8: nop

L_80033CAC:
    // 0x80033CAC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80033CB0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80033CB4: jr          $ra
    // 0x80033CB8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
    return;
    // 0x80033CB8: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
;}
RECOMP_FUNC void transition_update_blank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C27A0: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x800C27A4: sw          $s2, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r18;
    // 0x800C27A8: sw          $s0, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r16;
    // 0x800C27AC: sw          $s1, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r17;
    // 0x800C27B0: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C27B4: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800C27B8: lui         $t5, 0x8013
    ctx->r13 = S32(0X8013 << 16);
    // 0x800C27BC: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800C27C0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C27C4: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C27C8: lui         $t1, 0x8013
    ctx->r9 = S32(0X8013 << 16);
    // 0x800C27CC: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C27D0: lui         $a3, 0x8013
    ctx->r7 = S32(0X8013 << 16);
    // 0x800C27D4: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800C27D8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800C27DC: addiu       $a1, $a1, 0x31B0
    ctx->r5 = ADD32(ctx->r5, 0X31B0);
    // 0x800C27E0: addiu       $a2, $a2, -0x58C8
    ctx->r6 = ADD32(ctx->r6, -0X58C8);
    // 0x800C27E4: addiu       $a3, $a3, -0x58BC
    ctx->r7 = ADD32(ctx->r7, -0X58BC);
    // 0x800C27E8: addiu       $t0, $t0, -0x58C4
    ctx->r8 = ADD32(ctx->r8, -0X58C4);
    // 0x800C27EC: addiu       $t1, $t1, -0x58B8
    ctx->r9 = ADD32(ctx->r9, -0X58B8);
    // 0x800C27F0: addiu       $t2, $t2, -0x58C0
    ctx->r10 = ADD32(ctx->r10, -0X58C0);
    // 0x800C27F4: addiu       $t3, $t3, -0x58B4
    ctx->r11 = ADD32(ctx->r11, -0X58B4);
    // 0x800C27F8: addiu       $t4, $t4, -0x58CC
    ctx->r12 = ADD32(ctx->r12, -0X58CC);
    // 0x800C27FC: addiu       $t5, $t5, -0x58CB
    ctx->r13 = ADD32(ctx->r13, -0X58CB);
    // 0x800C2800: addiu       $s2, $s2, 0x31B4
    ctx->r18 = ADD32(ctx->r18, 0X31B4);
    // 0x800C2804: addiu       $s0, $s0, -0x58CA
    ctx->r16 = ADD32(ctx->r16, -0X58CA);
    // 0x800C2808: ori         $s1, $zero, 0xFFFF
    ctx->r17 = 0 | 0XFFFF;
    // 0x800C280C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_800C2810:
    // 0x800C2810: lhu         $v1, 0x0($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X0);
    // 0x800C2814: nop

    // 0x800C2818: blez        $v1, L_800C28AC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C281C: nop
    
            goto L_800C28AC;
    }
    // 0x800C281C: nop

    // 0x800C2820: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800C2824: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800C2828: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C282C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800C2830: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800C2834: mflo        $t8
    ctx->r24 = lo;
    // 0x800C2838: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800C283C: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800C2840: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x800C2844: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2848: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x800C284C: mflo        $t8
    ctx->r24 = lo;
    // 0x800C2850: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800C2854: lw          $t7, 0x0($t3)
    ctx->r15 = MEM_W(ctx->r11, 0X0);
    // 0x800C2858: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C285C: multu       $t7, $a0
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800C2860: mflo        $t8
    ctx->r24 = lo;
    // 0x800C2864: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800C2868: bne         $at, $zero, L_800C28A0
    if (ctx->r1 != 0) {
        // 0x800C286C: sw          $t9, 0x0($t2)
        MEM_W(0X0, ctx->r10) = ctx->r25;
            goto L_800C28A0;
    }
    // 0x800C286C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x800C2870: lbu         $t7, 0x0($t4)
    ctx->r15 = MEM_BU(ctx->r12, 0X0);
    // 0x800C2874: lbu         $t8, 0x0($t5)
    ctx->r24 = MEM_BU(ctx->r13, 0X0);
    // 0x800C2878: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800C287C: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x800C2880: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x800C2884: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2888: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800C288C: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800C2890: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x800C2894: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800C2898: b           L_800C28CC
    // 0x800C289C: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
        goto L_800C28CC;
    // 0x800C289C: sh          $zero, 0x0($a1)
    MEM_H(0X0, ctx->r5) = 0;
L_800C28A0:
    // 0x800C28A0: subu        $t8, $v1, $a0
    ctx->r24 = SUB32(ctx->r3, ctx->r4);
    // 0x800C28A4: b           L_800C28CC
    // 0x800C28A8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
        goto L_800C28CC;
    // 0x800C28A8: sh          $t8, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r24;
L_800C28AC:
    // 0x800C28AC: lhu         $v1, 0x0($s2)
    ctx->r3 = MEM_HU(ctx->r18, 0X0);
    // 0x800C28B0: nop

    // 0x800C28B4: beq         $s1, $v1, L_800C28CC
    if (ctx->r17 == ctx->r3) {
        // 0x800C28B8: subu        $t9, $v1, $a0
        ctx->r25 = SUB32(ctx->r3, ctx->r4);
            goto L_800C28CC;
    }
    // 0x800C28B8: subu        $t9, $v1, $a0
    ctx->r25 = SUB32(ctx->r3, ctx->r4);
    // 0x800C28BC: andi        $t7, $t9, 0xFFFF
    ctx->r15 = ctx->r25 & 0XFFFF;
    // 0x800C28C0: bgtz        $t7, L_800C28CC
    if (SIGNED(ctx->r15) > 0) {
        // 0x800C28C4: sh          $t9, 0x0($s2)
        MEM_H(0X0, ctx->r18) = ctx->r25;
            goto L_800C28CC;
    }
    // 0x800C28C4: sh          $t9, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r25;
    // 0x800C28C8: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
L_800C28CC:
    // 0x800C28CC: beq         $v0, $zero, L_800C2810
    if (ctx->r2 == 0) {
        // 0x800C28D0: nop
    
            goto L_800C2810;
    }
    // 0x800C28D0: nop

    // 0x800C28D4: lw          $s0, 0x4($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X4);
    // 0x800C28D8: lw          $s1, 0x8($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X8);
    // 0x800C28DC: lw          $s2, 0xC($sp)
    ctx->r18 = MEM_W(ctx->r29, 0XC);
    // 0x800C28E0: jr          $ra
    // 0x800C28E4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x800C28E4: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
RECOMP_FUNC void obj_dist_racer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016DE8: addiu       $sp, $sp, -0xB8
    ctx->r29 = ADD32(ctx->r29, -0XB8);
    // 0x80016DEC: sw          $s6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r22;
    // 0x80016DF0: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80016DF4: addiu       $s6, $s6, -0x5110
    ctx->r22 = ADD32(ctx->r22, -0X5110);
    // 0x80016DF8: lw          $v0, 0x0($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X0);
    // 0x80016DFC: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x80016E00: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80016E04: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x80016E08: mtc1        $a3, $f26
    ctx->f26.u32l = ctx->r7;
    // 0x80016E0C: sw          $s4, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r20;
    // 0x80016E10: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80016E14: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80016E18: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80016E1C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80016E20: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x80016E24: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x80016E28: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x80016E2C: sw          $s7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r23;
    // 0x80016E30: sw          $s5, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r21;
    // 0x80016E34: sw          $s3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r19;
    // 0x80016E38: sw          $s2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r18;
    // 0x80016E3C: sw          $s1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r17;
    // 0x80016E40: sw          $s0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r16;
    // 0x80016E44: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80016E48: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80016E4C: blez        $v0, L_8001704C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80016E50: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8001704C;
    }
    // 0x80016E50: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80016E54: blez        $v0, L_80016F48
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80016E58: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80016F48;
    }
    // 0x80016E58: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80016E5C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80016E60: lw          $s5, 0xC8($sp)
    ctx->r21 = MEM_W(ctx->r29, 0XC8);
    // 0x80016E64: lw          $s0, 0xCC($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XCC);
    // 0x80016E68: addiu       $s3, $s3, -0x511C
    ctx->r19 = ADD32(ctx->r19, -0X511C);
    // 0x80016E6C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80016E70: addiu       $s7, $sp, 0x98
    ctx->r23 = ADD32(ctx->r29, 0X98);
L_80016E74:
    // 0x80016E74: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80016E78: nop

    // 0x80016E7C: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x80016E80: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x80016E84: nop

    // 0x80016E88: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x80016E8C: nop

    // 0x80016E90: lh          $a0, 0x0($v1)
    ctx->r4 = MEM_H(ctx->r3, 0X0);
    // 0x80016E94: nop

    // 0x80016E98: bltz        $a0, L_80016F34
    if (SIGNED(ctx->r4) < 0) {
        // 0x80016E9C: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_80016F34;
    }
    // 0x80016E9C: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80016EA0: beq         $at, $zero, L_80016F34
    if (ctx->r1 == 0) {
        // 0x80016EA4: nop
    
            goto L_80016F34;
    }
    // 0x80016EA4: nop

    // 0x80016EA8: beq         $s5, $zero, L_80016ED8
    if (ctx->r21 == 0) {
        // 0x80016EAC: nop
    
            goto L_80016ED8;
    }
    // 0x80016EAC: nop

    // 0x80016EB0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80016EB4: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80016EB8: sub.s       $f0, $f4, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f20.fl;
    // 0x80016EBC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016EC0: sub.s       $f2, $f6, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x80016EC4: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016EC8: jal         0x800C9AD0
    // 0x80016ECC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80016ECC: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80016ED0: b           L_80016F0C
    // 0x80016ED4: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
        goto L_80016F0C;
    // 0x80016ED4: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016ED8:
    // 0x80016ED8: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80016EDC: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80016EE0: sub.s       $f0, $f16, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f0.fl = ctx->f16.fl - ctx->f20.fl;
    // 0x80016EE4: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80016EE8: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80016EEC: sub.s       $f14, $f18, $f24
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f24.fl;
    // 0x80016EF0: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80016EF4: sub.s       $f2, $f4, $f22
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80016EF8: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80016EFC: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80016F00: jal         0x800C9AD0
    // 0x80016F04: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80016F04: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_1:
    // 0x80016F08: c.lt.s      $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f0.fl < ctx->f26.fl;
L_80016F0C:
    // 0x80016F0C: sll         $v0, $s4, 2
    ctx->r2 = S32(ctx->r20 << 2);
    // 0x80016F10: bc1f        L_80016F34
    if (!c1cs) {
        // 0x80016F14: addu        $t8, $s7, $v0
        ctx->r24 = ADD32(ctx->r23, ctx->r2);
            goto L_80016F34;
    }
    // 0x80016F14: addu        $t8, $s7, $v0
    ctx->r24 = ADD32(ctx->r23, ctx->r2);
    // 0x80016F18: swc1        $f0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f0.u32l;
    // 0x80016F1C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x80016F20: addu        $t2, $s0, $v0
    ctx->r10 = ADD32(ctx->r16, ctx->r2);
    // 0x80016F24: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x80016F28: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80016F2C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x80016F30: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
L_80016F34:
    // 0x80016F34: lw          $t3, 0x0($s6)
    ctx->r11 = MEM_W(ctx->r22, 0X0);
    // 0x80016F38: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80016F3C: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80016F40: bne         $at, $zero, L_80016E74
    if (ctx->r1 != 0) {
        // 0x80016F44: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_80016E74;
    }
    // 0x80016F44: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80016F48:
    // 0x80016F48: lw          $s0, 0xCC($sp)
    ctx->r16 = MEM_W(ctx->r29, 0XCC);
    // 0x80016F4C: slti        $at, $s4, 0x2
    ctx->r1 = SIGNED(ctx->r20) < 0X2 ? 1 : 0;
    // 0x80016F50: bne         $at, $zero, L_8001704C
    if (ctx->r1 != 0) {
        // 0x80016F54: addiu       $s1, $s4, -0x1
        ctx->r17 = ADD32(ctx->r20, -0X1);
            goto L_8001704C;
    }
    // 0x80016F54: addiu       $s1, $s4, -0x1
    ctx->r17 = ADD32(ctx->r20, -0X1);
    // 0x80016F58: blez        $s1, L_80017050
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80016F5C: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_80017050;
    }
    // 0x80016F5C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80016F60:
    // 0x80016F60: blez        $s1, L_80017040
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80016F64: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_80017040;
    }
    // 0x80016F64: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80016F68: andi        $v1, $s1, 0x1
    ctx->r3 = ctx->r17 & 0X1;
    // 0x80016F6C: beq         $v1, $zero, L_80016FB0
    if (ctx->r3 == 0) {
        // 0x80016F70: addiu       $t5, $sp, 0x98
        ctx->r13 = ADD32(ctx->r29, 0X98);
            goto L_80016FB0;
    }
    // 0x80016F70: addiu       $t5, $sp, 0x98
    ctx->r13 = ADD32(ctx->r29, 0X98);
    // 0x80016F74: lwc1        $f18, 0x9C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80016F78: lwc1        $f4, 0x98($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X98);
    // 0x80016F7C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80016F80: c.lt.s      $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f18.fl < ctx->f4.fl;
    // 0x80016F84: nop

    // 0x80016F88: bc1f        L_80016FAC
    if (!c1cs) {
        // 0x80016F8C: nop
    
            goto L_80016FAC;
    }
    // 0x80016F8C: nop

    // 0x80016F90: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x80016F94: swc1        $f18, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->f18.u32l;
    // 0x80016F98: lw          $t4, 0x4($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X4);
    // 0x80016F9C: nop

    // 0x80016FA0: sw          $t4, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r12;
    // 0x80016FA4: swc1        $f4, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f4.u32l;
    // 0x80016FA8: sw          $a0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r4;
L_80016FAC:
    // 0x80016FAC: beq         $v0, $s1, L_80017040
    if (ctx->r2 == ctx->r17) {
        // 0x80016FB0: sll         $a1, $v0, 2
        ctx->r5 = S32(ctx->r2 << 2);
            goto L_80017040;
    }
L_80016FB0:
    // 0x80016FB0: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x80016FB4: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x80016FB8: addu        $a2, $t6, $t5
    ctx->r6 = ADD32(ctx->r14, ctx->r13);
    // 0x80016FBC: addu        $v1, $a1, $t5
    ctx->r3 = ADD32(ctx->r5, ctx->r13);
L_80016FC0:
    // 0x80016FC0: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80016FC4: lwc1        $f12, 0x0($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80016FC8: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x80016FCC: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80016FD0: nop

    // 0x80016FD4: bc1f        L_80017000
    if (!c1cs) {
        // 0x80016FD8: nop
    
            goto L_80017000;
    }
    // 0x80016FD8: nop

    // 0x80016FDC: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80016FE0: swc1        $f0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f0.u32l;
    // 0x80016FE4: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x80016FE8: nop

    // 0x80016FEC: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80016FF0: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    // 0x80016FF4: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80016FF8: lwc1        $f0, 0x4($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80016FFC: nop

L_80017000:
    // 0x80017000: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80017004: addu        $v0, $s0, $a1
    ctx->r2 = ADD32(ctx->r16, ctx->r5);
    // 0x80017008: c.lt.s      $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f12.fl < ctx->f0.fl;
    // 0x8001700C: nop

    // 0x80017010: bc1f        L_80017034
    if (!c1cs) {
        // 0x80017014: nop
    
            goto L_80017034;
    }
    // 0x80017014: nop

    // 0x80017018: lw          $a0, 0x4($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X4);
    // 0x8001701C: swc1        $f12, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->f12.u32l;
    // 0x80017020: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x80017024: nop

    // 0x80017028: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8001702C: swc1        $f0, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->f0.u32l;
    // 0x80017030: sw          $a0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r4;
L_80017034:
    // 0x80017034: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x80017038: bne         $v1, $a2, L_80016FC0
    if (ctx->r3 != ctx->r6) {
        // 0x8001703C: addiu       $a1, $a1, 0x8
        ctx->r5 = ADD32(ctx->r5, 0X8);
            goto L_80016FC0;
    }
    // 0x8001703C: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
L_80017040:
    // 0x80017040: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80017044: bne         $s1, $zero, L_80016F60
    if (ctx->r17 != 0) {
        // 0x80017048: nop
    
            goto L_80016F60;
    }
    // 0x80017048: nop

L_8001704C:
    // 0x8001704C: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_80017050:
    // 0x80017050: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80017054: lw          $s4, 0x44($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X44);
    // 0x80017058: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001705C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80017060: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80017064: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80017068: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8001706C: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80017070: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80017074: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80017078: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x8001707C: lw          $s1, 0x38($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X38);
    // 0x80017080: lw          $s2, 0x3C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X3C);
    // 0x80017084: lw          $s3, 0x40($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X40);
    // 0x80017088: lw          $s5, 0x48($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X48);
    // 0x8001708C: lw          $s6, 0x4C($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X4C);
    // 0x80017090: lw          $s7, 0x50($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X50);
    // 0x80017094: jr          $ra
    // 0x80017098: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
    return;
    // 0x80017098: addiu       $sp, $sp, 0xB8
    ctx->r29 = ADD32(ctx->r29, 0XB8);
;}
RECOMP_FUNC void menu_close_dialogue(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800945E4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800945E8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800945EC: jal         0x800945B0
    // 0x800945F0: nop

    menu_dialogue_end(rdram, ctx);
        goto after_0;
    // 0x800945F0: nop

    after_0:
    // 0x800945F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800945F8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800945FC: jr          $ra
    // 0x80094600: nop

    return;
    // 0x80094600: nop

;}
RECOMP_FUNC void model_instance_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    if (ctx->r4 == 0) { ctx->r2 = 0; return; }
    // 0x8005FCD0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005FCD4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005FCD8: lh          $t6, 0x48($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X48);
    // 0x8005FCDC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005FCE0: beq         $t6, $zero, L_8005FD7C
    if (ctx->r14 == 0) {
        // 0x8005FCE4: andi        $t7, $a1, 0x8
        ctx->r15 = ctx->r5 & 0X8;
            goto L_8005FD7C;
    }
    // 0x8005FCE4: andi        $t7, $a1, 0x8
    ctx->r15 = ctx->r5 & 0X8;
    // 0x8005FCE8: beq         $t7, $zero, L_8005FD7C
    if (ctx->r15 == 0) {
        // 0x8005FCEC: nop
    
            goto L_8005FD7C;
    }
    // 0x8005FCEC: nop

    // 0x8005FCF0: lh          $a2, 0x24($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X24);
    // 0x8005FCF4: lh          $t0, 0x4A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X4A);
    // 0x8005FCF8: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8005FCFC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8005FD00: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8005FD04: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8005FD08: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8005FD0C: subu        $t1, $t1, $t0
    ctx->r9 = SUB32(ctx->r9, ctx->r8);
    // 0x8005FD10: addiu       $a2, $t9, 0x24
    ctx->r6 = ADD32(ctx->r25, 0X24);
    // 0x8005FD14: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005FD18: addu        $a0, $t1, $a2
    ctx->r4 = ADD32(ctx->r9, ctx->r6);
    // 0x8005FD1C: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x8005FD20: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8005FD24: jal         0x80070D10
    // 0x8005FD28: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc(rdram, ctx);
        goto after_0;
    // 0x8005FD28: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_0:
    // 0x8005FD2C: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FD30: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005FD34: bne         $v0, $zero, L_8005FD44
    if (ctx->r2 != 0) {
        // 0x8005FD38: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8005FD44;
    }
    // 0x8005FD38: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005FD3C: b           L_8005FF30
    // 0x8005FD40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005FF30;
    // 0x8005FD40: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FD44:
    // 0x8005FD44: addiu       $t2, $v0, 0x24
    ctx->r10 = ADD32(ctx->r2, 0X24);
    // 0x8005FD48: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8005FD4C: lh          $t3, 0x24($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X24);
    // 0x8005FD50: addu        $t7, $v0, $a2
    ctx->r15 = ADD32(ctx->r2, ctx->r6);
    // 0x8005FD54: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8005FD58: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x8005FD5C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8005FD60: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8005FD64: addiu       $t6, $t5, 0x24
    ctx->r14 = ADD32(ctx->r13, 0X24);
    // 0x8005FD68: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8005FD6C: sw          $t6, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r14;
    // 0x8005FD70: sw          $t7, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r15;
    // 0x8005FD74: b           L_8005FE1C
    // 0x8005FD78: sb          $t8, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r24;
        goto L_8005FE1C;
    // 0x8005FD78: sb          $t8, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r24;
L_8005FD7C:
    // 0x8005FD7C: lw          $t9, 0x40($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X40);
    // 0x8005FD80: andi        $t0, $a1, 0x1
    ctx->r8 = ctx->r5 & 0X1;
    // 0x8005FD84: beq         $t9, $zero, L_8005FDE0
    if (ctx->r25 == 0) {
        // 0x8005FD88: addiu       $a0, $zero, 0x24
        ctx->r4 = ADD32(0, 0X24);
            goto L_8005FDE0;
    }
    // 0x8005FD88: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x8005FD8C: beq         $t0, $zero, L_8005FDE0
    if (ctx->r8 == 0) {
        // 0x8005FD90: ori         $a1, $zero, 0xFFFF
        ctx->r5 = 0 | 0XFFFF;
            goto L_8005FDE0;
    }
    // 0x8005FD90: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8005FD94: lh          $a2, 0x24($a3)
    ctx->r6 = MEM_H(ctx->r7, 0X24);
    // 0x8005FD98: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    // 0x8005FD9C: sll         $t1, $a2, 2
    ctx->r9 = S32(ctx->r6 << 2);
    // 0x8005FDA0: addu        $t1, $t1, $a2
    ctx->r9 = ADD32(ctx->r9, ctx->r6);
    // 0x8005FDA4: sll         $t1, $t1, 1
    ctx->r9 = S32(ctx->r9 << 1);
    // 0x8005FDA8: jal         0x80070D10
    // 0x8005FDAC: addiu       $a0, $t1, 0x24
    ctx->r4 = ADD32(ctx->r9, 0X24);
    mempool_alloc(rdram, ctx);
        goto after_1;
    // 0x8005FDAC: addiu       $a0, $t1, 0x24
    ctx->r4 = ADD32(ctx->r9, 0X24);
    after_1:
    // 0x8005FDB0: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005FDB4: bne         $v0, $zero, L_8005FDC4
    if (ctx->r2 != 0) {
        // 0x8005FDB8: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8005FDC4;
    }
    // 0x8005FDB8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005FDBC: b           L_8005FF30
    // 0x8005FDC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005FF30;
    // 0x8005FDC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FDC4:
    // 0x8005FDC4: addiu       $v1, $v0, 0x24
    ctx->r3 = ADD32(ctx->r2, 0X24);
    // 0x8005FDC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8005FDCC: sw          $v1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r3;
    // 0x8005FDD0: sw          $v1, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r3;
    // 0x8005FDD4: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8005FDD8: b           L_8005FE1C
    // 0x8005FDDC: sb          $t2, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r10;
        goto L_8005FE1C;
    // 0x8005FDDC: sb          $t2, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = ctx->r10;
L_8005FDE0:
    // 0x8005FDE0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8005FDE4: jal         0x80070D10
    // 0x8005FDE8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    mempool_alloc(rdram, ctx);
        goto after_2;
    // 0x8005FDE8: sw          $a3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r7;
    after_2:
    // 0x8005FDEC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8005FDF0: bne         $v0, $zero, L_8005FE00
    if (ctx->r2 != 0) {
        // 0x8005FDF4: or          $a1, $v0, $zero
        ctx->r5 = ctx->r2 | 0;
            goto L_8005FE00;
    }
    // 0x8005FDF4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005FDF8: b           L_8005FF30
    // 0x8005FDFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005FF30;
    // 0x8005FDFC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FE00:
    // 0x8005FE00: lw          $t3, 0x4($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X4);
    // 0x8005FE04: nop

    // 0x8005FE08: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8005FE0C: lw          $t4, 0x4($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X4);
    // 0x8005FE10: sw          $zero, 0xC($v0)
    MEM_W(0XC, ctx->r2) = 0;
    // 0x8005FE14: sb          $zero, 0x1E($v0)
    MEM_B(0X1E, ctx->r2) = 0;
    // 0x8005FE18: sw          $t4, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r12;
L_8005FE1C:
    // 0x8005FE1C: lb          $t5, 0x1E($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X1E);
    // 0x8005FE20: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8005FE24: sh          $zero, 0x16($v0)
    MEM_H(0X16, ctx->r2) = 0;
    // 0x8005FE28: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
    // 0x8005FE2C: sh          $zero, 0x1A($v0)
    MEM_H(0X1A, ctx->r2) = 0;
    // 0x8005FE30: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x8005FE34: sh          $v1, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r3;
    // 0x8005FE38: sh          $v1, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r3;
    // 0x8005FE3C: beq         $t5, $zero, L_8005FF2C
    if (ctx->r13 == 0) {
        // 0x8005FE40: sb          $zero, 0x1F($v0)
        MEM_B(0X1F, ctx->r2) = 0;
            goto L_8005FF2C;
    }
    // 0x8005FE40: sb          $zero, 0x1F($v0)
    MEM_B(0X1F, ctx->r2) = 0;
    // 0x8005FE44: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x8005FE48: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x8005FE4C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8005FE50:
    // 0x8005FE50: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8005FE54: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005FE58: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x8005FE5C: lh          $t7, 0x2($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X2);
    // 0x8005FE60: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x8005FE64: sh          $t7, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r15;
    // 0x8005FE68: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8005FE6C: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x8005FE70: sh          $t8, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r24;
    // 0x8005FE74: lbu         $t9, -0x4($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X4);
    // 0x8005FE78: nop

    // 0x8005FE7C: sb          $t9, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r25;
    // 0x8005FE80: lbu         $t0, -0x3($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X3);
    // 0x8005FE84: nop

    // 0x8005FE88: sb          $t0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r8;
    // 0x8005FE8C: lbu         $t1, -0x2($a0)
    ctx->r9 = MEM_BU(ctx->r4, -0X2);
    // 0x8005FE90: nop

    // 0x8005FE94: sb          $t1, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r9;
    // 0x8005FE98: lbu         $t2, -0x1($a0)
    ctx->r10 = MEM_BU(ctx->r4, -0X1);
    // 0x8005FE9C: nop

    // 0x8005FEA0: sb          $t2, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r10;
    // 0x8005FEA4: lh          $t3, 0x24($a3)
    ctx->r11 = MEM_H(ctx->r7, 0X24);
    // 0x8005FEA8: nop

    // 0x8005FEAC: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8005FEB0: bne         $at, $zero, L_8005FE50
    if (ctx->r1 != 0) {
        // 0x8005FEB4: nop
    
            goto L_8005FE50;
    }
    // 0x8005FEB4: nop

    // 0x8005FEB8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8005FEBC: lw          $a0, 0x4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X4);
    // 0x8005FEC0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_8005FEC4:
    // 0x8005FEC4: lh          $t4, 0x0($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X0);
    // 0x8005FEC8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8005FECC: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
    // 0x8005FED0: lh          $t5, 0x2($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X2);
    // 0x8005FED4: addiu       $v1, $v1, 0xA
    ctx->r3 = ADD32(ctx->r3, 0XA);
    // 0x8005FED8: sh          $t5, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r13;
    // 0x8005FEDC: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8005FEE0: addiu       $a0, $a0, 0xA
    ctx->r4 = ADD32(ctx->r4, 0XA);
    // 0x8005FEE4: sh          $t6, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r14;
    // 0x8005FEE8: lbu         $t7, -0x4($a0)
    ctx->r15 = MEM_BU(ctx->r4, -0X4);
    // 0x8005FEEC: nop

    // 0x8005FEF0: sb          $t7, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r15;
    // 0x8005FEF4: lbu         $t8, -0x3($a0)
    ctx->r24 = MEM_BU(ctx->r4, -0X3);
    // 0x8005FEF8: nop

    // 0x8005FEFC: sb          $t8, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r24;
    // 0x8005FF00: lbu         $t9, -0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, -0X2);
    // 0x8005FF04: nop

    // 0x8005FF08: sb          $t9, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r25;
    // 0x8005FF0C: lbu         $t0, -0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X1);
    // 0x8005FF10: nop

    // 0x8005FF14: sb          $t0, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r8;
    // 0x8005FF18: lh          $t1, 0x24($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X24);
    // 0x8005FF1C: nop

    // 0x8005FF20: slt         $at, $a2, $t1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8005FF24: bne         $at, $zero, L_8005FEC4
    if (ctx->r1 != 0) {
        // 0x8005FF28: nop
    
            goto L_8005FEC4;
    }
    // 0x8005FF28: nop

L_8005FF2C:
    // 0x8005FF2C: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_8005FF30:
    // 0x8005FF30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005FF34: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005FF38: jr          $ra
    // 0x8005FF3C: nop

    return;
    // 0x8005FF3C: nop

;}
RECOMP_FUNC void hud_race_time(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7B68: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7B6C: lw          $a3, 0x6D0C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6D0C);
    // 0x800A7B70: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A7B74: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A7B78: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800A7B7C: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800A7B80: beq         $a3, $zero, L_800A7BDC
    if (ctx->r7 == 0) {
        // 0x800A7B84: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_800A7BDC;
    }
    // 0x800A7B84: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800A7B88: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800A7B8C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x800A7B90: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800A7B94: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A7B98: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x800A7B9C: lbu         $t9, 0x2794($t9)
    ctx->r25 = MEM_BU(ctx->r25, 0X2794);
    // 0x800A7BA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7BA4: beq         $t9, $at, L_800A7BDC
    if (ctx->r25 == ctx->r1) {
        // 0x800A7BA8: nop
    
            goto L_800A7BDC;
    }
    // 0x800A7BA8: nop

    // 0x800A7BAC: blez        $a3, L_800A7FB0
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800A7BB0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A7FB0;
    }
    // 0x800A7BB0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A7BB4: lb          $v0, 0x193($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X193);
    // 0x800A7BB8: nop

    // 0x800A7BBC: blez        $v0, L_800A7FAC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A7BC0: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_800A7FAC;
    }
    // 0x800A7BC0: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x800A7BC4: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x800A7BC8: lw          $t5, 0x128($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X128);
    // 0x800A7BCC: nop

    // 0x800A7BD0: slti        $at, $t5, 0xB4
    ctx->r1 = SIGNED(ctx->r13) < 0XB4 ? 1 : 0;
    // 0x800A7BD4: beq         $at, $zero, L_800A7FB0
    if (ctx->r1 == 0) {
        // 0x800A7BD8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A7FB0;
    }
    // 0x800A7BD8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A7BDC:
    // 0x800A7BDC: lb          $t2, 0x1D8($a2)
    ctx->r10 = MEM_B(ctx->r6, 0X1D8);
    // 0x800A7BE0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7BE4: bne         $t2, $zero, L_800A7FB0
    if (ctx->r10 != 0) {
        // 0x800A7BE8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800A7FB0;
    }
    // 0x800A7BE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A7BEC: lw          $t0, 0x6CDC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6CDC);
    // 0x800A7BF0: lb          $v0, 0x193($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X193);
    // 0x800A7BF4: lb          $t1, 0x15A($t0)
    ctx->r9 = MEM_B(ctx->r8, 0X15A);
    // 0x800A7BF8: blez        $v0, L_800A7C4C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800A7BFC: addiu       $t1, $t1, 0x7F
        ctx->r9 = ADD32(ctx->r9, 0X7F);
            goto L_800A7C4C;
    }
    // 0x800A7BFC: addiu       $t1, $t1, 0x7F
    ctx->r9 = ADD32(ctx->r9, 0X7F);
    // 0x800A7C00: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800A7C04: addu        $v1, $a2, $t6
    ctx->r3 = ADD32(ctx->r6, ctx->r14);
    // 0x800A7C08: lw          $t7, 0x128($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X128);
    // 0x800A7C0C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A7C10: slti        $at, $t7, 0xB4
    ctx->r1 = SIGNED(ctx->r15) < 0XB4 ? 1 : 0;
    // 0x800A7C14: beq         $at, $zero, L_800A7C4C
    if (ctx->r1 == 0) {
        // 0x800A7C18: nop
    
            goto L_800A7C4C;
    }
    // 0x800A7C18: nop

    // 0x800A7C1C: lw          $t8, 0x6D60($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D60);
    // 0x800A7C20: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800A7C24: lb          $t9, 0x4B($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X4B);
    // 0x800A7C28: nop

    // 0x800A7C2C: slt         $at, $v0, $t9
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800A7C30: beq         $at, $zero, L_800A7C4C
    if (ctx->r1 == 0) {
        // 0x800A7C34: nop
    
            goto L_800A7C4C;
    }
    // 0x800A7C34: nop

    // 0x800A7C38: lw          $s0, 0x124($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X124);
    // 0x800A7C3C: bne         $t1, $zero, L_800A7CE0
    if (ctx->r9 != 0) {
        // 0x800A7C40: sw          $t3, 0x48($sp)
        MEM_W(0X48, ctx->r29) = ctx->r11;
            goto L_800A7CE0;
    }
    // 0x800A7C40: sw          $t3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r11;
    // 0x800A7C44: b           L_800A7CE0
    // 0x800A7C48: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
        goto L_800A7CE0;
    // 0x800A7C48: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
L_800A7C4C:
    // 0x800A7C4C: lb          $a1, 0x194($a2)
    ctx->r5 = MEM_B(ctx->r6, 0X194);
    // 0x800A7C50: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A7C54: bltz        $a1, L_800A7C9C
    if (SIGNED(ctx->r5) < 0) {
        // 0x800A7C58: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_800A7C9C;
    }
    // 0x800A7C58: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800A7C5C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A7C60: lw          $t4, 0x6D60($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D60);
    // 0x800A7C64: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800A7C68: lb          $a0, 0x4B($t4)
    ctx->r4 = MEM_B(ctx->r12, 0X4B);
    // 0x800A7C6C: addu        $v1, $a2, $t5
    ctx->r3 = ADD32(ctx->r6, ctx->r13);
    // 0x800A7C70: blez        $a0, L_800A7C9C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800A7C74: nop
    
            goto L_800A7C9C;
    }
    // 0x800A7C74: nop

L_800A7C78:
    // 0x800A7C78: lw          $t6, 0x128($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X128);
    // 0x800A7C7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800A7C80: slt         $at, $a1, $v0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800A7C84: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800A7C88: bne         $at, $zero, L_800A7C9C
    if (ctx->r1 != 0) {
        // 0x800A7C8C: addu        $s0, $s0, $t6
        ctx->r16 = ADD32(ctx->r16, ctx->r14);
            goto L_800A7C9C;
    }
    // 0x800A7C8C: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
    // 0x800A7C90: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800A7C94: bne         $at, $zero, L_800A7C78
    if (ctx->r1 != 0) {
        // 0x800A7C98: nop
    
            goto L_800A7C78;
    }
    // 0x800A7C98: nop

L_800A7C9C:
    // 0x800A7C9C: sltiu       $v1, $s0, 0x1
    ctx->r3 = ctx->r16 < 0X1 ? 1 : 0;
    // 0x800A7CA0: bne         $v1, $zero, L_800A7CC8
    if (ctx->r3 != 0) {
        // 0x800A7CA4: nop
    
            goto L_800A7CC8;
    }
    // 0x800A7CA4: nop

    // 0x800A7CA8: sltu        $v1, $zero, $t2
    ctx->r3 = 0 < ctx->r10 ? 1 : 0;
    // 0x800A7CAC: bne         $v1, $zero, L_800A7CC8
    if (ctx->r3 != 0) {
        // 0x800A7CB0: nop
    
            goto L_800A7CC8;
    }
    // 0x800A7CB0: nop

    // 0x800A7CB4: jal         0x8006EAA0
    // 0x800A7CB8: nop

    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800A7CB8: nop

    after_0:
    // 0x800A7CBC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7CC0: lw          $t0, 0x6CDC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6CDC);
    // 0x800A7CC4: sltu        $v1, $zero, $v0
    ctx->r3 = 0 < ctx->r2 ? 1 : 0;
L_800A7CC8:
    // 0x800A7CC8: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    // 0x800A7CCC: addiu       $t7, $zero, -0x7F
    ctx->r15 = ADD32(0, -0X7F);
    // 0x800A7CD0: sb          $t7, 0x15A($t0)
    MEM_B(0X15A, ctx->r8) = ctx->r15;
    // 0x800A7CD4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7CD8: lw          $a3, 0x6D0C($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6D0C);
    // 0x800A7CDC: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800A7CE0:
    // 0x800A7CE0: bne         $a3, $zero, L_800A7D18
    if (ctx->r7 != 0) {
        // 0x800A7CE4: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A7D18;
    }
    // 0x800A7CE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7CE8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7CEC: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A7CF0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7CF4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7CF8: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A7CFC: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A7D00: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A7D04: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    // 0x800A7D08: jal         0x800AA600
    // 0x800A7D0C: addiu       $a3, $a3, 0x140
    ctx->r7 = ADD32(ctx->r7, 0X140);
    hud_element_render(rdram, ctx);
        goto after_1;
    // 0x800A7D0C: addiu       $a3, $a3, 0x140
    ctx->r7 = ADD32(ctx->r7, 0X140);
    after_1:
    // 0x800A7D10: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A7D14: nop

L_800A7D18:
    // 0x800A7D18: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A7D1C: jal         0x8000C8B4
    // 0x800A7D20: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x800A7D20: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_2:
    // 0x800A7D24: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A7D28: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x800A7D2C: beq         $at, $zero, L_800A7D44
    if (ctx->r1 == 0) {
        // 0x800A7D30: ori         $a0, $zero, 0x8CA0
        ctx->r4 = 0 | 0X8CA0;
            goto L_800A7D44;
    }
    // 0x800A7D30: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A7D34: jal         0x8000C8B4
    // 0x800A7D38: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_3;
    // 0x800A7D38: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_3:
    // 0x800A7D3C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A7D40: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
L_800A7D44:
    // 0x800A7D44: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A7D48: addiu       $a1, $sp, 0x54
    ctx->r5 = ADD32(ctx->r29, 0X54);
    // 0x800A7D4C: addiu       $a2, $sp, 0x50
    ctx->r6 = ADD32(ctx->r29, 0X50);
    // 0x800A7D50: addiu       $a3, $sp, 0x4C
    ctx->r7 = ADD32(ctx->r29, 0X4C);
    // 0x800A7D54: jal         0x80059790
    // 0x800A7D58: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    get_timestamp_from_frames(rdram, ctx);
        goto after_4;
    // 0x800A7D58: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_4:
    // 0x800A7D5C: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800A7D60: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A7D64: bne         $t8, $zero, L_800A7D80
    if (ctx->r24 != 0) {
        // 0x800A7D68: ori         $a0, $zero, 0x8CA0
        ctx->r4 = 0 | 0X8CA0;
            goto L_800A7D80;
    }
    // 0x800A7D68: ori         $a0, $zero, 0x8CA0
    ctx->r4 = 0 | 0X8CA0;
    // 0x800A7D6C: jal         0x8000C8B4
    // 0x800A7D70: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    normalise_time(rdram, ctx);
        goto after_5;
    // 0x800A7D70: sw          $t1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r9;
    after_5:
    // 0x800A7D74: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800A7D78: bne         $v0, $s0, L_800A7E1C
    if (ctx->r2 != ctx->r16) {
        // 0x800A7D7C: lw          $t3, 0x4C($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X4C);
            goto L_800A7E1C;
    }
    // 0x800A7D7C: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
L_800A7D80:
    // 0x800A7D80: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800A7D84: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A7D88: slt         $at, $t9, $t1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800A7D8C: beq         $at, $zero, L_800A7D9C
    if (ctx->r1 == 0) {
        // 0x800A7D90: addiu       $s0, $s0, 0x6D36
        ctx->r16 = ADD32(ctx->r16, 0X6D36);
            goto L_800A7D9C;
    }
    // 0x800A7D90: addiu       $s0, $s0, 0x6D36
    ctx->r16 = ADD32(ctx->r16, 0X6D36);
    // 0x800A7D94: b           L_800A7DA0
    // 0x800A7D98: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
        goto L_800A7DA0;
    // 0x800A7D98: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
L_800A7D9C:
    // 0x800A7D9C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_800A7DA0:
    // 0x800A7DA0: addiu       $at, $zero, 0x1E
    ctx->r1 = ADD32(0, 0X1E);
    // 0x800A7DA4: div         $zero, $t1, $at
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r1)));
    // 0x800A7DA8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A7DAC: lw          $t4, 0x6CDC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6CDC);
    // 0x800A7DB0: addiu       $t3, $t1, -0x7F
    ctx->r11 = ADD32(ctx->r9, -0X7F);
    // 0x800A7DB4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800A7DB8: sb          $t3, 0x15A($t4)
    MEM_B(0X15A, ctx->r12) = ctx->r11;
    // 0x800A7DBC: mfhi        $t5
    ctx->r13 = hi;
    // 0x800A7DC0: slti        $at, $t5, 0x15
    ctx->r1 = SIGNED(ctx->r13) < 0X15 ? 1 : 0;
    // 0x800A7DC4: bne         $at, $zero, L_800A7DDC
    if (ctx->r1 != 0) {
        // 0x800A7DC8: nop
    
            goto L_800A7DDC;
    }
    // 0x800A7DC8: nop

    // 0x800A7DCC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A7DD0: addiu       $s0, $s0, 0x6D36
    ctx->r16 = ADD32(ctx->r16, 0X6D36);
    // 0x800A7DD4: b           L_800A7FAC
    // 0x800A7DD8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
        goto L_800A7FAC;
    // 0x800A7DD8: sb          $t6, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r14;
L_800A7DDC:
    // 0x800A7DDC: lbu         $t7, 0x0($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X0);
    // 0x800A7DE0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A7DE4: beq         $t7, $zero, L_800A7E08
    if (ctx->r15 == 0) {
        // 0x800A7DE8: nop
    
            goto L_800A7E08;
    }
    // 0x800A7DE8: nop

    // 0x800A7DEC: lw          $t8, 0x6D0C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6D0C);
    // 0x800A7DF0: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800A7DF4: bne         $t8, $zero, L_800A7E04
    if (ctx->r24 != 0) {
        // 0x800A7DF8: nop
    
            goto L_800A7E04;
    }
    // 0x800A7DF8: nop

    // 0x800A7DFC: jal         0x80001D04
    // 0x800A7E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x800A7E00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
L_800A7E04:
    // 0x800A7E04: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_800A7E08:
    // 0x800A7E08: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7E0C: lw          $t0, 0x6CDC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6CDC);
    // 0x800A7E10: b           L_800A7EB4
    // 0x800A7E14: nop

        goto L_800A7EB4;
    // 0x800A7E14: nop

    // 0x800A7E18: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
L_800A7E1C:
    // 0x800A7E1C: addiu       $v0, $zero, 0xA
    ctx->r2 = ADD32(0, 0XA);
    // 0x800A7E20: div         $zero, $t3, $v0
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r2)));
    // 0x800A7E24: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7E28: lw          $t0, 0x6CDC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6CDC);
    // 0x800A7E2C: nop

    // 0x800A7E30: lb          $t9, 0x15B($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X15B);
    // 0x800A7E34: bne         $v0, $zero, L_800A7E40
    if (ctx->r2 != 0) {
        // 0x800A7E38: nop
    
            goto L_800A7E40;
    }
    // 0x800A7E38: nop

    // 0x800A7E3C: break       7
    do_break(2148171324);
L_800A7E40:
    // 0x800A7E40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7E44: bne         $v0, $at, L_800A7E58
    if (ctx->r2 != ctx->r1) {
        // 0x800A7E48: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A7E58;
    }
    // 0x800A7E48: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A7E4C: bne         $t3, $at, L_800A7E58
    if (ctx->r11 != ctx->r1) {
        // 0x800A7E50: nop
    
            goto L_800A7E58;
    }
    // 0x800A7E50: nop

    // 0x800A7E54: break       6
    do_break(2148171348);
L_800A7E58:
    // 0x800A7E58: mflo        $t4
    ctx->r12 = lo;
    // 0x800A7E5C: nop

    // 0x800A7E60: nop

    // 0x800A7E64: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800A7E68: mflo        $t5
    ctx->r13 = lo;
    // 0x800A7E6C: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x800A7E70: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800A7E74: lb          $t7, 0x15B($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X15B);
    // 0x800A7E78: nop

    // 0x800A7E7C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A7E80: sb          $t8, 0x15B($t0)
    MEM_B(0X15B, ctx->r8) = ctx->r24;
    // 0x800A7E84: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7E88: lw          $t0, 0x6CDC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6CDC);
    // 0x800A7E8C: nop

    // 0x800A7E90: lb          $t3, 0x15B($t0)
    ctx->r11 = MEM_B(ctx->r8, 0X15B);
    // 0x800A7E94: nop

    // 0x800A7E98: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x800A7E9C: bne         $at, $zero, L_800A7EB4
    if (ctx->r1 != 0) {
        // 0x800A7EA0: nop
    
            goto L_800A7EB4;
    }
    // 0x800A7EA0: nop

    // 0x800A7EA4: sb          $zero, 0x15B($t0)
    MEM_B(0X15B, ctx->r8) = 0;
    // 0x800A7EA8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7EAC: lw          $t0, 0x6CDC($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6CDC);
    // 0x800A7EB0: nop

L_800A7EB4:
    // 0x800A7EB4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A7EB8: lbu         $t4, 0x6D37($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X6D37);
    // 0x800A7EBC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7EC0: bne         $t4, $at, L_800A7F2C
    if (ctx->r12 != ctx->r1) {
        // 0x800A7EC4: nop
    
            goto L_800A7F2C;
    }
    // 0x800A7EC4: nop

    // 0x800A7EC8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A7ECC: lwc1        $f4, 0x16C($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X16C);
    // 0x800A7ED0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A7ED4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7ED8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7EDC: lwc1        $f8, 0x170($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X170);
    // 0x800A7EE0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A7EE4: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x800A7EE8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A7EEC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800A7EF0: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800A7EF4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A7EF8: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800A7EFC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A7F00: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7F04: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7F08: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x800A7F0C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A7F10: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x800A7F14: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800A7F18: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    extern void dkr_hud_timer_select(uint8_t*, recomp_context*, int); dkr_hud_timer_select(rdram, ctx, 0);
    // 0x800A7F1C: jal         0x800A7FBC
    // 0x800A7F20: nop

    hud_timer_render(rdram, ctx);
        goto after_7;
    // 0x800A7F20: nop

    after_7:
    // 0x800A7F24: b           L_800A7F88
    // 0x800A7F28: nop

        goto L_800A7F88;
    // 0x800A7F28: nop

L_800A7F2C:
    // 0x800A7F2C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A7F30: lwc1        $f16, 0x16C($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X16C);
    // 0x800A7F34: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A7F38: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7F3C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7F40: lwc1        $f4, 0x170($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X170);
    // 0x800A7F44: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A7F48: lw          $t3, 0x4C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X4C);
    // 0x800A7F4C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A7F50: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800A7F54: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800A7F58: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A7F5C: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800A7F60: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A7F64: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7F68: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A7F6C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A7F70: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A7F74: sw          $t4, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r12;
    // 0x800A7F78: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A7F7C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    extern void dkr_hud_timer_select(uint8_t*, recomp_context*, int); dkr_hud_timer_select(rdram, ctx, 0);
    // 0x800A7F80: jal         0x800A7FBC
    // 0x800A7F84: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    hud_timer_render(rdram, ctx);
        goto after_8;
    // 0x800A7F84: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_8:
L_800A7F88:
    // 0x800A7F88: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A7F8C: lw          $v1, 0x6CFC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6CFC);
    // 0x800A7F90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A7F94: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800A7F98: sw          $t9, 0x6CFC($at)
    MEM_W(0X6CFC, ctx->r1) = ctx->r25;
    // 0x800A7F9C: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A7FA0: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800A7FA4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800A7FA8: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
L_800A7FAC:
    // 0x800A7FAC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800A7FB0:
    // 0x800A7FB0: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800A7FB4: jr          $ra
    // 0x800A7FB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800A7FB8: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void audspat_debug_render_lines(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A184: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8000A188: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8000A18C: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8000A190: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8000A194: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8000A198: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000A19C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000A1A0: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8000A1A4: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8000A1A8: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8000A1AC: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8000A1B0: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x8000A1B4: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x8000A1B8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8000A1BC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000A1C0: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000A1C4: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000A1C8: addiu       $fp, $fp, -0x5924
    ctx->r30 = ADD32(ctx->r30, -0X5924);
    // 0x8000A1CC: addiu       $s7, $s7, -0x63A4
    ctx->r23 = ADD32(ctx->r23, -0X63A4);
    // 0x8000A1D0: addiu       $s6, $s6, -0x63A8
    ctx->r22 = ADD32(ctx->r22, -0X63A8);
L_8000A1D4:
    // 0x8000A1D4: lw          $t6, 0x16C($s6)
    ctx->r14 = MEM_W(ctx->r22, 0X16C);
    // 0x8000A1D8: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x8000A1DC: beq         $t6, $zero, L_8000A22C
    if (ctx->r14 == 0) {
        // 0x8000A1E0: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_8000A22C;
    }
    // 0x8000A1E0: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x8000A1E4: lb          $t7, 0x17C($s6)
    ctx->r15 = MEM_B(ctx->r22, 0X17C);
    // 0x8000A1E8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000A1EC: blez        $t7, L_8000A22C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8000A1F0: addiu       $t8, $zero, 0xFF
        ctx->r24 = ADD32(0, 0XFF);
            goto L_8000A22C;
    }
L_8000A1F0:
    // 0x8000A1F0: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8000A1F4: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8000A1F8: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8000A1FC: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8000A200: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000A204: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000A208: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8000A20C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8000A210: jal         0x8000A414
    // 0x8000A214: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    audspat_debug_render_line(rdram, ctx);
        goto after_0;
    // 0x8000A214: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_0:
    // 0x8000A218: lb          $t0, 0x17C($s2)
    ctx->r8 = MEM_B(ctx->r18, 0X17C);
    // 0x8000A21C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000A220: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8000A224: bne         $at, $zero, L_8000A1F0
    if (ctx->r1 != 0) {
        // 0x8000A228: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8000A1F0;
    }
    // 0x8000A228: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8000A22C:
    // 0x8000A22C: addiu       $s7, $s7, 0x180
    ctx->r23 = ADD32(ctx->r23, 0X180);
    // 0x8000A230: sltu        $at, $s7, $fp
    ctx->r1 = ctx->r23 < ctx->r30 ? 1 : 0;
    // 0x8000A234: bne         $at, $zero, L_8000A1D4
    if (ctx->r1 != 0) {
        // 0x8000A238: addiu       $s6, $s6, 0x180
        ctx->r22 = ADD32(ctx->r22, 0X180);
            goto L_8000A1D4;
    }
    // 0x8000A238: addiu       $s6, $s6, 0x180
    ctx->r22 = ADD32(ctx->r22, 0X180);
    // 0x8000A23C: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8000A240: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8000A244: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x8000A248: addiu       $fp, $fp, -0x53E4
    ctx->r30 = ADD32(ctx->r30, -0X53E4);
    // 0x8000A24C: addiu       $s7, $s7, -0x5924
    ctx->r23 = ADD32(ctx->r23, -0X5924);
    // 0x8000A250: addiu       $s6, $s6, -0x5928
    ctx->r22 = ADD32(ctx->r22, -0X5928);
L_8000A254:
    // 0x8000A254: lbu         $t1, 0x0($s6)
    ctx->r9 = MEM_BU(ctx->r22, 0X0);
    // 0x8000A258: or          $s2, $s6, $zero
    ctx->r18 = ctx->r22 | 0;
    // 0x8000A25C: beq         $t1, $zero, L_8000A2AC
    if (ctx->r9 == 0) {
        // 0x8000A260: or          $s1, $s7, $zero
        ctx->r17 = ctx->r23 | 0;
            goto L_8000A2AC;
    }
    // 0x8000A260: or          $s1, $s7, $zero
    ctx->r17 = ctx->r23 | 0;
    // 0x8000A264: lb          $t2, 0xB8($s6)
    ctx->r10 = MEM_B(ctx->r22, 0XB8);
    // 0x8000A268: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000A26C: blez        $t2, L_8000A2AC
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8000A270: addiu       $t3, $zero, 0xFF
        ctx->r11 = ADD32(0, 0XFF);
            goto L_8000A2AC;
    }
L_8000A270:
    // 0x8000A270: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8000A274: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8000A278: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8000A27C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8000A280: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000A284: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8000A288: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8000A28C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    // 0x8000A290: jal         0x8000A414
    // 0x8000A294: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_debug_render_line(rdram, ctx);
        goto after_1;
    // 0x8000A294: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x8000A298: lb          $t5, 0xB8($s2)
    ctx->r13 = MEM_B(ctx->r18, 0XB8);
    // 0x8000A29C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000A2A0: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000A2A4: bne         $at, $zero, L_8000A270
    if (ctx->r1 != 0) {
        // 0x8000A2A8: addiu       $s1, $s1, 0xC
        ctx->r17 = ADD32(ctx->r17, 0XC);
            goto L_8000A270;
    }
    // 0x8000A2A8: addiu       $s1, $s1, 0xC
    ctx->r17 = ADD32(ctx->r17, 0XC);
L_8000A2AC:
    // 0x8000A2AC: addiu       $s7, $s7, 0xC0
    ctx->r23 = ADD32(ctx->r23, 0XC0);
    // 0x8000A2B0: bne         $s7, $fp, L_8000A254
    if (ctx->r23 != ctx->r30) {
        // 0x8000A2B4: addiu       $s6, $s6, 0xC0
        ctx->r22 = ADD32(ctx->r22, 0XC0);
            goto L_8000A254;
    }
    // 0x8000A2B4: addiu       $s6, $s6, 0xC0
    ctx->r22 = ADD32(ctx->r22, 0XC0);
    // 0x8000A2B8: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000A2BC: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000A2C0: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000A2C4: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000A2C8: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000A2CC: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000A2D0: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000A2D4: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8000A2D8: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8000A2DC: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8000A2E0: jr          $ra
    // 0x8000A2E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8000A2E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void func_8009BE54(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BE54: jr          $ra
    // 0x8009BE58: nop

    return;
    // 0x8009BE58: nop

;}
RECOMP_FUNC void get_lockup_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B76DC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B76E0: addiu       $v0, $v0, 0x3020
    ctx->r2 = ADD32(ctx->r2, 0X3020);
    // 0x800B76E4: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800B76E8: addiu       $sp, $sp, -0x828
    ctx->r29 = ADD32(ctx->r29, -0X828);
    // 0x800B76EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800B76F0: beq         $v1, $at, L_800B7700
    if (ctx->r3 == ctx->r1) {
        // 0x800B76F4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800B7700;
    }
    // 0x800B76F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B76F8: b           L_800B77C4
    // 0x800B76FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_800B77C4;
    // 0x800B76FC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B7700:
    // 0x800B7700: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800B7704: jal         0x800758DC
    // 0x800B7708: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800B7708: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800B770C: bne         $v0, $zero, L_800B7790
    if (ctx->r2 != 0) {
        // 0x800B7710: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B7790;
    }
    // 0x800B7710: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7714: lui         $a1, 0x800F
    ctx->r5 = S32(0X800F << 16);
    // 0x800B7718: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800B771C: addiu       $a2, $a2, -0x7104
    ctx->r6 = ADD32(ctx->r6, -0X7104);
    // 0x800B7720: addiu       $a1, $a1, -0x710C
    ctx->r5 = ADD32(ctx->r5, -0X710C);
    // 0x800B7724: jal         0x800764E8
    // 0x800B7728: addiu       $a3, $sp, 0x824
    ctx->r7 = ADD32(ctx->r29, 0X824);
    get_file_number(rdram, ctx);
        goto after_1;
    // 0x800B7728: addiu       $a3, $sp, 0x824
    ctx->r7 = ADD32(ctx->r29, 0X824);
    after_1:
    // 0x800B772C: bne         $v0, $zero, L_800B7790
    if (ctx->r2 != 0) {
        // 0x800B7730: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800B7790;
    }
    // 0x800B7730: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7734: lw          $a1, 0x824($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X824);
    // 0x800B7738: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    // 0x800B773C: jal         0x80076610
    // 0x800B7740: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    read_data_from_controller_pak(rdram, ctx);
        goto after_2;
    // 0x800B7740: addiu       $a3, $zero, 0x800
    ctx->r7 = ADD32(0, 0X800);
    after_2:
    // 0x800B7744: bne         $v0, $zero, L_800B7790
    if (ctx->r2 != 0) {
        // 0x800B7748: addiu       $a0, $sp, 0x20
        ctx->r4 = ADD32(ctx->r29, 0X20);
            goto L_800B7790;
    }
    // 0x800B7748: addiu       $a0, $sp, 0x20
    ctx->r4 = ADD32(ctx->r29, 0X20);
    // 0x800B774C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7750: addiu       $a1, $a1, -0x6800
    ctx->r5 = ADD32(ctx->r5, -0X6800);
    // 0x800B7754: jal         0x800C9DA0
    // 0x800B7758: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    _bcopy(rdram, ctx);
        goto after_3;
    // 0x800B7758: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    after_3:
    // 0x800B775C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7760: addiu       $a1, $a1, -0x6650
    ctx->r5 = ADD32(ctx->r5, -0X6650);
    // 0x800B7764: addiu       $a0, $sp, 0x220
    ctx->r4 = ADD32(ctx->r29, 0X220);
    // 0x800B7768: jal         0x800C9DA0
    // 0x800B776C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    _bcopy(rdram, ctx);
        goto after_4;
    // 0x800B776C: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_4:
    // 0x800B7770: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7774: addiu       $a1, $a1, -0x6450
    ctx->r5 = ADD32(ctx->r5, -0X6450);
    // 0x800B7778: addiu       $a0, $sp, 0x420
    ctx->r4 = ADD32(ctx->r29, 0X420);
    // 0x800B777C: jal         0x800C9DA0
    // 0x800B7780: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    _bcopy(rdram, ctx);
        goto after_5;
    // 0x800B7780: addiu       $a2, $zero, 0x400
    ctx->r6 = ADD32(0, 0X400);
    after_5:
    // 0x800B7784: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800B7788: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B778C: sw          $t6, 0x3020($at)
    MEM_W(0X3020, ctx->r1) = ctx->r14;
L_800B7790:
    // 0x800B7790: jal         0x80075AEC
    // 0x800B7794: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_6;
    // 0x800B7794: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800B7798: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B779C: lw          $v1, 0x3020($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3020);
    // 0x800B77A0: lw          $a1, 0x824($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X824);
    // 0x800B77A4: beq         $v1, $zero, L_800B77C4
    if (ctx->r3 == 0) {
        // 0x800B77A8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_800B77C4;
    }
    // 0x800B77A8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x800B77AC: jal         0x800762C8
    // 0x800B77B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    delete_file(rdram, ctx);
        goto after_7;
    // 0x800B77B0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800B77B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800B77B8: lw          $v1, 0x3020($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3020);
    // 0x800B77BC: nop

    // 0x800B77C0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800B77C4:
    // 0x800B77C4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B77C8: addiu       $sp, $sp, 0x828
    ctx->r29 = ADD32(ctx->r29, 0X828);
    // 0x800B77CC: jr          $ra
    // 0x800B77D0: nop

    return;
    // 0x800B77D0: nop

;}
RECOMP_FUNC void obj_loop_wardensmoke(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038AD4: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80038AD8: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80038ADC: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80038AE0: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80038AE4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80038AE8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038AEC: bne         $t6, $zero, L_80038B0C
    if (ctx->r14 != 0) {
        // 0x80038AF0: mov.s       $f0, $f2
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
            goto L_80038B0C;
    }
    // 0x80038AF0: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80038AF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80038AF8: lwc1        $f9, 0x6058($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6058);
    // 0x80038AFC: lwc1        $f8, 0x605C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X605C);
    // 0x80038B00: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80038B04: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80038B08: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
L_80038B0C:
    // 0x80038B0C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80038B10: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x80038B14: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80038B18: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x80038B1C: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x80038B20: lh          $t7, 0x18($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X18);
    // 0x80038B24: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80038B28: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x80038B2C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80038B30: sh          $t9, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r25;
    // 0x80038B34: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80038B38: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x80038B3C: lh          $t0, 0x18($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X18);
    // 0x80038B40: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80038B44: slti        $at, $t0, 0x100
    ctx->r1 = SIGNED(ctx->r8) < 0X100 ? 1 : 0;
    // 0x80038B48: bne         $at, $zero, L_80038B64
    if (ctx->r1 != 0) {
        // 0x80038B4C: swc1        $f16, 0x10($a0)
        MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
            goto L_80038B64;
    }
    // 0x80038B4C: swc1        $f16, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->f16.u32l;
    // 0x80038B50: jal         0x8000FFB8
    // 0x80038B54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    free_object(rdram, ctx);
        goto after_0;
    // 0x80038B54: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80038B58: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80038B5C: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80038B60: sh          $t1, 0x18($a0)
    MEM_H(0X18, ctx->r4) = ctx->r9;
L_80038B64:
    // 0x80038B64: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038B68: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80038B6C: jr          $ra
    // 0x80038B70: nop

    return;
    // 0x80038B70: nop

;}
RECOMP_FUNC void obj_loop_stopwatchman(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800361E0: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x800361E4: mtc1        $a1, $f6
    ctx->f6.u32l = ctx->r5;
    // 0x800361E8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800361EC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x800361F0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x800361F4: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800361F8: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800361FC: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80036200: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x80036204: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80036208: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003620C: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x80036210: bne         $t7, $zero, L_80036230
    if (ctx->r15 != 0) {
        // 0x80036214: swc1        $f4, 0x6C($sp)
        MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
            goto L_80036230;
    }
    // 0x80036214: swc1        $f4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f4.u32l;
    // 0x80036218: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003621C: lwc1        $f11, 0x6028($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6028);
    // 0x80036220: lwc1        $f10, 0x602C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X602C);
    // 0x80036224: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x80036228: mul.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x8003622C: cvt.s.d     $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f2.fl = CVT_S_D(ctx->f18.d);
L_80036230:
    // 0x80036230: lh          $t8, 0x18($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X18);
    // 0x80036234: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x80036238: bne         $t8, $zero, L_80036270
    if (ctx->r24 != 0) {
        // 0x8003623C: nop
    
            goto L_80036270;
    }
    // 0x8003623C: nop

    // 0x80036240: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036244: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80036248: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003624C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036250: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80036254: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x80036258: nop

    // 0x8003625C: bc1f        L_80036270
    if (!c1cs) {
        // 0x80036260: nop
    
            goto L_80036270;
    }
    // 0x80036260: nop

    // 0x80036264: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80036268: nop

    // 0x8003626C: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
L_80036270:
    // 0x80036270: jal         0x8006BDB0
    // 0x80036274: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    level_header(rdram, ctx);
        goto after_0;
    // 0x80036274: swc1        $f2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x80036278: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8003627C: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x80036280: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80036284: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036288: swc1        $f0, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f0.u32l;
    // 0x8003628C: jal         0x8001BAC8
    // 0x80036290: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x80036290: swc1        $f0, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f0.u32l;
    after_1:
    // 0x80036294: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80036298: beq         $v0, $zero, L_800363A4
    if (ctx->r2 == 0) {
        // 0x8003629C: sw          $v0, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r2;
            goto L_800363A4;
    }
    // 0x8003629C: sw          $v0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r2;
    // 0x800362A0: lw          $v0, 0x64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64);
    // 0x800362A4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800362A8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800362AC: lwc1        $f6, 0x38($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X38);
    // 0x800362B0: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800362B4: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800362B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800362BC: lwc1        $f10, 0x50($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X50);
    // 0x800362C0: lwc1        $f18, 0xC($a1)
    ctx->f18.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800362C4: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800362C8: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800362CC: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800362D0: lwc1        $f10, 0x14($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X14);
    // 0x800362D4: sub.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800362D8: lwc1        $f8, 0x40($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40);
    // 0x800362DC: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x800362E0: lwc1        $f4, 0x58($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X58);
    // 0x800362E4: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800362E8: nop

    // 0x800362EC: mul.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800362F0: sub.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800362F4: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800362F8: swc1        $f14, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f14.u32l;
    // 0x800362FC: sub.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80036300: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x80036304: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80036308: sub.s       $f16, $f10, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8003630C: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x80036310: swc1        $f16, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f16.u32l;
    // 0x80036314: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80036318: jal         0x800C9AD0
    // 0x8003631C: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003631C: add.s       $f12, $f4, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f18.fl;
    after_2:
    // 0x80036320: swc1        $f0, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f0.u32l;
    // 0x80036324: lw          $v0, 0x64($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X64);
    // 0x80036328: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003632C: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036330: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80036334: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80036338: sub.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003633C: jal         0x80070750
    // 0x80036340: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x80036340: sub.s       $f14, $f6, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f4.fl;
    after_3:
    // 0x80036344: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80036348: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8003634C: lh          $t0, 0x0($t9)
    ctx->r8 = MEM_H(ctx->r25, 0X0);
    // 0x80036350: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80036354: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x80036358: subu        $v1, $v0, $t1
    ctx->r3 = SUB32(ctx->r2, ctx->r9);
    // 0x8003635C: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80036360: bne         $at, $zero, L_80036374
    if (ctx->r1 != 0) {
        // 0x80036364: slti        $at, $v1, -0x8000
        ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
            goto L_80036374;
    }
    // 0x80036364: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80036368: lui         $v1, 0xFFFF
    ctx->r3 = S32(0XFFFF << 16);
    // 0x8003636C: ori         $v1, $v1, 0x1
    ctx->r3 = ctx->r3 | 0X1;
    // 0x80036370: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
L_80036374:
    // 0x80036374: beq         $at, $zero, L_80036384
    if (ctx->r1 == 0) {
        // 0x80036378: lw          $t2, 0x50($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X50);
            goto L_80036384;
    }
    // 0x80036378: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
    // 0x8003637C: ori         $v1, $zero, 0xFFFF
    ctx->r3 = 0 | 0XFFFF;
    // 0x80036380: lw          $t2, 0x50($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X50);
L_80036384:
    // 0x80036384: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x80036388: lw          $t3, 0x108($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X108);
    // 0x8003638C: nop

    // 0x80036390: beq         $t3, $zero, L_800363A4
    if (ctx->r11 == 0) {
        // 0x80036394: nop
    
            goto L_800363A4;
    }
    // 0x80036394: nop

    // 0x80036398: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x8003639C: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x800363A0: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
L_800363A4:
    // 0x800363A4: jal         0x8006A554
    // 0x800363A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_4;
    // 0x800363A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800363AC: lw          $t5, 0x78($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X78);
    // 0x800363B0: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x800363B4: bne         $t5, $zero, L_800364D4
    if (ctx->r13 != 0) {
        // 0x800363B8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800364D4;
    }
    // 0x800363B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800363BC: lwc1        $f18, 0x70($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800363C0: lwc1        $f11, 0x6030($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6030);
    // 0x800363C4: lwc1        $f10, 0x6034($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6034);
    // 0x800363C8: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800363CC: c.lt.d      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.d < ctx->f10.d;
    // 0x800363D0: nop

    // 0x800363D4: bc1f        L_800364D4
    if (!c1cs) {
        // 0x800363D8: nop
    
            goto L_800364D4;
    }
    // 0x800363D8: nop

    // 0x800363DC: lw          $t6, 0x7C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X7C);
    // 0x800363E0: slti        $at, $v1, -0x1FFF
    ctx->r1 = SIGNED(ctx->r3) < -0X1FFF ? 1 : 0;
    // 0x800363E4: bne         $t6, $zero, L_800364D4
    if (ctx->r14 != 0) {
        // 0x800363E8: nop
    
            goto L_800364D4;
    }
    // 0x800363E8: nop

    // 0x800363EC: bne         $at, $zero, L_800364D4
    if (ctx->r1 != 0) {
        // 0x800363F0: slti        $at, $v1, 0x2000
        ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
            goto L_800364D4;
    }
    // 0x800363F0: slti        $at, $v1, 0x2000
    ctx->r1 = SIGNED(ctx->r3) < 0X2000 ? 1 : 0;
    // 0x800363F4: beq         $at, $zero, L_800364D4
    if (ctx->r1 == 0) {
        // 0x800363F8: nop
    
            goto L_800364D4;
    }
    // 0x800363F8: nop

    // 0x800363FC: lw          $v1, 0x4C($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X4C);
    // 0x80036400: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x80036404: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x80036408: andi        $t1, $v0, 0x2000
    ctx->r9 = ctx->r2 & 0X2000;
    // 0x8003640C: andi        $t8, $t7, 0x8
    ctx->r24 = ctx->r15 & 0X8;
    // 0x80036410: beq         $t8, $zero, L_80036428
    if (ctx->r24 == 0) {
        // 0x80036414: nop
    
            goto L_80036428;
    }
    // 0x80036414: nop

    // 0x80036418: lw          $t0, 0x0($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X0);
    // 0x8003641C: nop

    // 0x80036420: beq         $t9, $t0, L_80036430
    if (ctx->r25 == ctx->r8) {
        // 0x80036424: andi        $t2, $v0, 0x2000
        ctx->r10 = ctx->r2 & 0X2000;
            goto L_80036430;
    }
    // 0x80036424: andi        $t2, $v0, 0x2000
    ctx->r10 = ctx->r2 & 0X2000;
L_80036428:
    // 0x80036428: beq         $t1, $zero, L_800364D4
    if (ctx->r9 == 0) {
        // 0x8003642C: andi        $t2, $v0, 0x2000
        ctx->r10 = ctx->r2 & 0X2000;
            goto L_800364D4;
    }
    // 0x8003642C: andi        $t2, $v0, 0x2000
    ctx->r10 = ctx->r2 & 0X2000;
L_80036430:
    // 0x80036430: beq         $t2, $zero, L_8003644C
    if (ctx->r10 == 0) {
        // 0x80036434: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8003644C;
    }
    // 0x80036434: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80036438: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x8003643C: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x80036440: jal         0x80056930
    // 0x80036444: nop

    play_char_horn_sound(rdram, ctx);
        goto after_5;
    // 0x80036444: nop

    after_5:
    // 0x80036448: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
L_8003644C:
    // 0x8003644C: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x80036450: addiu       $t4, $s1, 0x12
    ctx->r12 = ADD32(ctx->r17, 0X12);
    // 0x80036454: addiu       $t5, $s1, 0x13
    ctx->r13 = ADD32(ctx->r17, 0X13);
    // 0x80036458: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8003645C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80036460: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036464: addiu       $a1, $s1, 0x20
    ctx->r5 = ADD32(ctx->r17, 0X20);
    // 0x80036468: addiu       $a2, $s1, 0x22
    ctx->r6 = ADD32(ctx->r17, 0X22);
    // 0x8003646C: jal         0x80030750
    // 0x80036470: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    get_fog_settings(rdram, ctx);
        goto after_6;
    // 0x80036470: addiu       $a3, $s1, 0x11
    ctx->r7 = ADD32(ctx->r17, 0X11);
    after_6:
    // 0x80036474: addiu       $t6, $zero, 0x384
    ctx->r14 = ADD32(0, 0X384);
    // 0x80036478: addiu       $t7, $zero, 0x3E6
    ctx->r15 = ADD32(0, 0X3E6);
    // 0x8003647C: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x80036480: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80036484: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80036488: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8003648C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036490: addiu       $a1, $zero, 0x80
    ctx->r5 = ADD32(0, 0X80);
    // 0x80036494: addiu       $a2, $zero, 0x80
    ctx->r6 = ADD32(0, 0X80);
    // 0x80036498: jal         0x80030DE0
    // 0x8003649C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    slowly_change_fog(rdram, ctx);
        goto after_7;
    // 0x8003649C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_7:
    // 0x800364A0: jal         0x800012E8
    // 0x800364A4: nop

    music_channel_reset_all(rdram, ctx);
        goto after_8;
    // 0x800364A4: nop

    after_8:
    // 0x800364A8: jal         0x80000B34
    // 0x800364AC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    music_play(rdram, ctx);
        goto after_9;
    // 0x800364AC: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    after_9:
    // 0x800364B0: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x800364B4: nop

    // 0x800364B8: beq         $t9, $zero, L_800364D4
    if (ctx->r25 == 0) {
        // 0x800364BC: nop
    
            goto L_800364D4;
    }
    // 0x800364BC: nop

    // 0x800364C0: jal         0x80006AC8
    // 0x800364C4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    racer_sound_free(rdram, ctx);
        goto after_10;
    // 0x800364C4: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    after_10:
    // 0x800364C8: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800364CC: nop

    // 0x800364D0: sw          $zero, 0x118($t0)
    MEM_W(0X118, ctx->r8) = 0;
L_800364D4:
    // 0x800364D4: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800364D8: nop

    // 0x800364DC: beq         $v0, $zero, L_80036500
    if (ctx->r2 == 0) {
        // 0x800364E0: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80036500;
    }
    // 0x800364E0: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800364E4: jal         0x8005A3B0
    // 0x800364E8: nop

    disable_racer_input(rdram, ctx);
        goto after_11;
    // 0x800364E8: nop

    after_11:
    // 0x800364EC: jal         0x800AB194
    // 0x800364F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    minimap_fade(rdram, ctx);
        goto after_12;
    // 0x800364F0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_12:
    // 0x800364F4: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x800364F8: nop

    // 0x800364FC: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
L_80036500:
    // 0x80036500: bne         $at, $zero, L_80036518
    if (ctx->r1 != 0) {
        // 0x80036504: nop
    
            goto L_80036518;
    }
    // 0x80036504: nop

    // 0x80036508: jal         0x8009CFEC
    // 0x8003650C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    npc_dialogue_loop(rdram, ctx);
        goto after_13;
    // 0x8003650C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_13:
    // 0x80036510: b           L_80036524
    // 0x80036514: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_80036524;
    // 0x80036514: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80036518:
    // 0x80036518: jal         0x8009CF68
    // 0x8003651C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    dialogue_npc_finish(rdram, ctx);
        goto after_14;
    // 0x8003651C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_14:
    // 0x80036520: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80036524:
    // 0x80036524: lw          $v0, 0x78($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X78);
    // 0x80036528: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8003652C: beq         $v0, $at, L_80036558
    if (ctx->r2 == ctx->r1) {
        // 0x80036530: addiu       $t1, $zero, 0xFF
        ctx->r9 = ADD32(0, 0XFF);
            goto L_80036558;
    }
    // 0x80036530: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x80036534: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80036538: beq         $v0, $at, L_8003671C
    if (ctx->r2 == ctx->r1) {
        // 0x8003653C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8003671C;
    }
    // 0x8003653C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80036540: beq         $v0, $at, L_80036854
    if (ctx->r2 == ctx->r1) {
        // 0x80036544: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80036854;
    }
    // 0x80036544: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80036548: beq         $v0, $at, L_800369AC
    if (ctx->r2 == ctx->r1) {
        // 0x8003654C: nop
    
            goto L_800369AC;
    }
    // 0x8003654C: nop

    // 0x80036550: b           L_800369F0
    // 0x80036554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
        goto L_800369F0;
    // 0x80036554: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80036558:
    // 0x80036558: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x8003655C: sb          $t1, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r9;
    // 0x80036560: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80036564: lui         $at, 0x4059
    ctx->r1 = S32(0X4059 << 16);
    // 0x80036568: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8003656C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80036570: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80036574: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80036578: nop

    // 0x8003657C: bc1f        L_800365A0
    if (!c1cs) {
        // 0x80036580: lui         $at, 0x4024
        ctx->r1 = S32(0X4024 << 16);
            goto L_800365A0;
    }
    // 0x80036580: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80036584: swc1        $f1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(1 - 1) * 2];
    // 0x80036588: jal         0x8005A3C0
    // 0x8003658C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_15;
    // 0x8003658C: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x80036590: lwc1        $f1, 0x38($sp)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80036594: lwc1        $f0, 0x3C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80036598: nop

    // 0x8003659C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
L_800365A0:
    // 0x800365A0: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800365A4: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800365A8: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800365AC: c.lt.d      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.d < ctx->f0.d;
    // 0x800365B0: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800365B4: bc1f        L_800366D0
    if (!c1cs) {
        // 0x800365B8: addiu       $t5, $zero, 0x2
        ctx->r13 = ADD32(0, 0X2);
            goto L_800366D0;
    }
    // 0x800365B8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x800365BC: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800365C0: div.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800365C4: jal         0x80070750
    // 0x800365C8: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    arctan2_f(rdram, ctx);
        goto after_16;
    // 0x800365C8: div.s       $f14, $f6, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    after_16:
    // 0x800365CC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800365D0: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800365D4: andi        $t2, $a0, 0xFFFF
    ctx->r10 = ctx->r4 & 0XFFFF;
    // 0x800365D8: subu        $v1, $v0, $t2
    ctx->r3 = SUB32(ctx->r2, ctx->r10);
    // 0x800365DC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x800365E0: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x800365E4: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800365E8: bne         $at, $zero, L_800365F8
    if (ctx->r1 != 0) {
        // 0x800365EC: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800365F8;
    }
    // 0x800365EC: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800365F0: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800365F4: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800365F8:
    // 0x800365F8: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800365FC: beq         $at, $zero, L_80036608
    if (ctx->r1 == 0) {
        // 0x80036600: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80036608;
    }
    // 0x80036600: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80036604: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80036608:
    // 0x80036608: blez        $v1, L_8003661C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8003660C: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_8003661C;
    }
    // 0x8003660C: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x80036610: beq         $at, $zero, L_80036620
    if (ctx->r1 == 0) {
        // 0x80036614: lui         $at, 0xC000
        ctx->r1 = S32(0XC000 << 16);
            goto L_80036620;
    }
    // 0x80036614: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80036618: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_8003661C:
    // 0x8003661C: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
L_80036620:
    // 0x80036620: sra         $t3, $v1, 4
    ctx->r11 = S32(SIGNED(ctx->r3) >> 4);
    // 0x80036624: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80036628: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x8003662C: slti        $at, $v1, 0x801
    ctx->r1 = SIGNED(ctx->r3) < 0X801 ? 1 : 0;
    // 0x80036630: beq         $at, $zero, L_80036640
    if (ctx->r1 == 0) {
        // 0x80036634: sh          $t4, 0x0($s0)
        MEM_H(0X0, ctx->r16) = ctx->r12;
            goto L_80036640;
    }
    // 0x80036634: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
    // 0x80036638: slti        $at, $v1, -0x800
    ctx->r1 = SIGNED(ctx->r3) < -0X800 ? 1 : 0;
    // 0x8003663C: beq         $at, $zero, L_8003664C
    if (ctx->r1 == 0) {
        // 0x80036640: lui         $at, 0xBF00
        ctx->r1 = S32(0XBF00 << 16);
            goto L_8003664C;
    }
L_80036640:
    // 0x80036640: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x80036644: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80036648: nop

L_8003664C:
    // 0x8003664C: lwc1        $f0, 0x14($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80036650: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80036654: sub.s       $f4, $f2, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x80036658: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003665C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80036660: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80036664: mul.d       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x80036668: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x8003666C: add.d       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f10.d + ctx->f6.d;
    // 0x80036670: cvt.s.d     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f18.fl = CVT_S_D(ctx->f4.d);
    // 0x80036674: swc1        $f18, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f18.u32l;
    // 0x80036678: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003667C: jal         0x800707C4
    // 0x80036680: nop

    sins_f(rdram, ctx);
        goto after_17;
    // 0x80036680: nop

    after_17:
    // 0x80036684: lwc1        $f8, 0x14($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X14);
    // 0x80036688: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8003668C: mul.s       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80036690: jal         0x800707F8
    // 0x80036694: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    coss_f(rdram, ctx);
        goto after_18;
    // 0x80036694: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    after_18:
    // 0x80036698: lwc1        $f6, 0x14($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8003669C: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800366A0: mul.s       $f4, $f0, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800366A4: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800366A8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800366AC: swc1        $f4, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f4.u32l;
    // 0x800366B0: lwc1        $f18, 0x14($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800366B4: lwc1        $f4, 0x4($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800366B8: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800366BC: nop

    // 0x800366C0: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800366C4: sub.s       $f18, $f4, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800366C8: b           L_800366DC
    // 0x800366CC: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
        goto L_800366DC;
    // 0x800366CC: swc1        $f18, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f18.u32l;
L_800366D0:
    // 0x800366D0: sw          $t5, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r13;
    // 0x800366D4: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800366D8: nop

L_800366DC:
    // 0x800366DC: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800366E0: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800366E4: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800366E8: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800366EC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800366F0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800366F4: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800366F8: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x800366FC: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80036700: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x80036704: jal         0x80011570
    // 0x80036708: nop

    move_object(rdram, ctx);
        goto after_19;
    // 0x80036708: nop

    after_19:
    // 0x8003670C: jal         0x8006F388
    // 0x80036710: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_20;
    // 0x80036710: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_20:
    // 0x80036714: b           L_80036AB4
    // 0x80036718: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
        goto L_80036AB4;
    // 0x80036718: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_8003671C:
    // 0x8003671C: jal         0x8005A3C0
    // 0x80036720: nop

    racer_set_dialogue_camera(rdram, ctx);
        goto after_21;
    // 0x80036720: nop

    after_21:
    // 0x80036724: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80036728: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x8003672C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80036730: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80036734: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x80036738: mul.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f10.d, ctx->f4.d);
    // 0x8003673C: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x80036740: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036744: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80036748: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8003674C: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x80036750: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80036754: swc1        $f4, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f4.u32l;
    // 0x80036758: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8003675C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80036760: lh          $t7, 0x0($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X0);
    // 0x80036764: andi        $t8, $a0, 0xFFFF
    ctx->r24 = ctx->r4 & 0XFFFF;
    // 0x80036768: subu        $v1, $t7, $t8
    ctx->r3 = SUB32(ctx->r15, ctx->r24);
    // 0x8003676C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80036770: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80036774: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80036778: bne         $at, $zero, L_80036788
    if (ctx->r1 != 0) {
        // 0x8003677C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80036788;
    }
    // 0x8003677C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80036780: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80036784: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80036788:
    // 0x80036788: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8003678C: beq         $at, $zero, L_80036798
    if (ctx->r1 == 0) {
        // 0x80036790: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80036798;
    }
    // 0x80036790: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80036794: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80036798:
    // 0x80036798: blez        $v1, L_800367AC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8003679C: slti        $at, $v1, 0x10
        ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
            goto L_800367AC;
    }
    // 0x8003679C: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800367A0: beq         $at, $zero, L_800367AC
    if (ctx->r1 == 0) {
        // 0x800367A4: nop
    
            goto L_800367AC;
    }
    // 0x800367A4: nop

    // 0x800367A8: addiu       $v1, $zero, 0x10
    ctx->r3 = ADD32(0, 0X10);
L_800367AC:
    // 0x800367AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800367B0: sra         $t9, $v1, 4
    ctx->r25 = S32(SIGNED(ctx->r3) >> 4);
    // 0x800367B4: lwc1        $f1, 0x6038($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6038);
    // 0x800367B8: lwc1        $f0, 0x603C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X603C);
    // 0x800367BC: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x800367C0: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x800367C4: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800367C8: slti        $at, $v1, 0x500
    ctx->r1 = SIGNED(ctx->r3) < 0X500 ? 1 : 0;
    // 0x800367CC: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800367D0: mul.d       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800367D4: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x800367D8: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800367DC: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800367E0: nop

    // 0x800367E4: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800367E8: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x800367EC: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800367F0: beq         $at, $zero, L_8003681C
    if (ctx->r1 == 0) {
        // 0x800367F4: swc1        $f6, 0x24($s0)
        MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
            goto L_8003681C;
    }
    // 0x800367F4: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800367F8: slti        $at, $v1, -0x4FF
    ctx->r1 = SIGNED(ctx->r3) < -0X4FF ? 1 : 0;
    // 0x800367FC: bne         $at, $zero, L_8003681C
    if (ctx->r1 != 0) {
        // 0x80036800: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_8003681C;
    }
    // 0x80036800: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80036804: sw          $t1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r9;
    // 0x80036808: addiu       $a0, $zero, 0x141
    ctx->r4 = ADD32(0, 0X141);
    // 0x8003680C: jal         0x80036BCC
    // 0x80036810: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_22;
    // 0x80036810: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_22:
    // 0x80036814: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80036818: nop

L_8003681C:
    // 0x8003681C: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80036820: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80036824: mul.s       $f4, $f10, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x80036828: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003682C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80036830: mul.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f2.fl);
    // 0x80036834: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x80036838: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8003683C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80036840: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80036844: jal         0x80011570
    // 0x80036848: nop

    move_object(rdram, ctx);
        goto after_23;
    // 0x80036848: nop

    after_23:
    // 0x8003684C: b           L_80036AB4
    // 0x80036850: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
        goto L_80036AB4;
    // 0x80036850: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_80036854:
    // 0x80036854: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80036858: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x8003685C: lwc1        $f1, 0x6040($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6040);
    // 0x80036860: lwc1        $f0, 0x6044($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6044);
    // 0x80036864: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x80036868: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8003686C: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80036870: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x80036874: swc1        $f6, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f6.u32l;
    // 0x80036878: lwc1        $f10, 0x74($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X74);
    // 0x8003687C: sb          $t2, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = ctx->r10;
    // 0x80036880: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80036884: mul.d       $f18, $f4, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80036888: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x8003688C: swc1        $f8, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f8.u32l;
    // 0x80036890: lwc1        $f6, 0x4($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036894: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80036898: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8003689C: cvt.d.s     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f18.d = CVT_D_S(ctx->f4.fl);
    // 0x800368A0: add.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f10.d + ctx->f18.d;
    // 0x800368A4: cvt.s.d     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f6.fl = CVT_S_D(ctx->f8.d);
    // 0x800368A8: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
    // 0x800368AC: jal         0x8005A3C0
    // 0x800368B0: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_24;
    // 0x800368B0: sw          $v1, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r3;
    after_24:
    // 0x800368B4: lw          $v1, 0x58($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X58);
    // 0x800368B8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800368BC: bne         $v1, $at, L_80036968
    if (ctx->r3 != ctx->r1) {
        // 0x800368C0: addiu       $t3, $zero, 0x4
        ctx->r11 = ADD32(0, 0X4);
            goto L_80036968;
    }
    // 0x800368C0: addiu       $t3, $zero, 0x4
    ctx->r11 = ADD32(0, 0X4);
    // 0x800368C4: jal         0x8000E4C8
    // 0x800368C8: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    is_time_trial_enabled(rdram, ctx);
        goto after_25;
    // 0x800368C8: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    after_25:
    // 0x800368CC: beq         $v0, $zero, L_800368E8
    if (ctx->r2 == 0) {
        // 0x800368D0: addiu       $a0, $zero, 0x143
        ctx->r4 = ADD32(0, 0X143);
            goto L_800368E8;
    }
    // 0x800368D0: addiu       $a0, $zero, 0x143
    ctx->r4 = ADD32(0, 0X143);
    // 0x800368D4: addiu       $a0, $zero, 0x142
    ctx->r4 = ADD32(0, 0X142);
    // 0x800368D8: jal         0x80036BCC
    // 0x800368DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_26;
    // 0x800368DC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_26:
    // 0x800368E0: b           L_800368F4
    // 0x800368E4: lh          $t4, 0x20($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X20);
        goto L_800368F4;
    // 0x800368E4: lh          $t4, 0x20($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X20);
L_800368E8:
    // 0x800368E8: jal         0x80036BCC
    // 0x800368EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    play_tt_voice_clip(rdram, ctx);
        goto after_27;
    // 0x800368EC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_27:
    // 0x800368F0: lh          $t4, 0x20($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X20);
L_800368F4:
    // 0x800368F4: lbu         $a1, 0x11($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0X11);
    // 0x800368F8: lbu         $a2, 0x12($s1)
    ctx->r6 = MEM_BU(ctx->r17, 0X12);
    // 0x800368FC: lbu         $a3, 0x13($s1)
    ctx->r7 = MEM_BU(ctx->r17, 0X13);
    // 0x80036900: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x80036904: lh          $t5, 0x22($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X22);
    // 0x80036908: addiu       $t6, $zero, 0xB4
    ctx->r14 = ADD32(0, 0XB4);
    // 0x8003690C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x80036910: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80036914: jal         0x80030DE0
    // 0x80036918: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    slowly_change_fog(rdram, ctx);
        goto after_28;
    // 0x80036918: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_28:
    // 0x8003691C: lw          $t7, 0x4C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X4C);
    // 0x80036920: nop

    // 0x80036924: lbu         $a0, 0x52($t7)
    ctx->r4 = MEM_BU(ctx->r15, 0X52);
    // 0x80036928: jal         0x80000B34
    // 0x8003692C: nop

    music_play(rdram, ctx);
        goto after_29;
    // 0x8003692C: nop

    after_29:
    // 0x80036930: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x80036934: nop

    // 0x80036938: lhu         $a0, 0x54($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X54);
    // 0x8003693C: jal         0x80001074
    // 0x80036940: nop

    music_dynamic_set(rdram, ctx);
        goto after_30;
    // 0x80036940: nop

    after_30:
    // 0x80036944: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
    // 0x80036948: nop

    // 0x8003694C: lb          $a0, 0x3($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X3);
    // 0x80036950: lb          $a1, 0x1D6($t9)
    ctx->r5 = MEM_B(ctx->r25, 0X1D6);
    // 0x80036954: jal         0x80004B40
    // 0x80036958: nop

    racer_sound_init(rdram, ctx);
        goto after_31;
    // 0x80036958: nop

    after_31:
    // 0x8003695C: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80036960: nop

    // 0x80036964: sw          $v0, 0x118($t0)
    MEM_W(0X118, ctx->r8) = ctx->r2;
L_80036968:
    // 0x80036968: lwc1        $f0, 0x7C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8003696C: lwc1        $f4, 0x1C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80036970: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80036974: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80036978: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x8003697C: addiu       $t1, $zero, 0xB4
    ctx->r9 = ADD32(0, 0XB4);
    // 0x80036980: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x80036984: mul.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80036988: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8003698C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80036990: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80036994: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x80036998: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8003699C: jal         0x80011570
    // 0x800369A0: nop

    move_object(rdram, ctx);
        goto after_32;
    // 0x800369A0: nop

    after_32:
    // 0x800369A4: b           L_80036AB4
    // 0x800369A8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
        goto L_80036AB4;
    // 0x800369A8: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_800369AC:
    // 0x800369AC: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800369B0: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800369B4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800369B8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800369BC: add.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = ctx->f18.d + ctx->f6.d;
    // 0x800369C0: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800369C4: jal         0x8005A3C0
    // 0x800369C8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    racer_set_dialogue_camera(rdram, ctx);
        goto after_33;
    // 0x800369C8: swc1        $f10, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f10.u32l;
    after_33:
    // 0x800369CC: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x800369D0: nop

    // 0x800369D4: slti        $at, $v0, 0x8C
    ctx->r1 = SIGNED(ctx->r2) < 0X8C ? 1 : 0;
    // 0x800369D8: beq         $at, $zero, L_80036AB0
    if (ctx->r1 == 0) {
        // 0x800369DC: addiu       $t2, $v0, 0x3C
        ctx->r10 = ADD32(ctx->r2, 0X3C);
            goto L_80036AB0;
    }
    // 0x800369DC: addiu       $t2, $v0, 0x3C
    ctx->r10 = ADD32(ctx->r2, 0X3C);
    // 0x800369E0: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x800369E4: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
    // 0x800369E8: b           L_80036AB0
    // 0x800369EC: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
        goto L_80036AB0;
    // 0x800369EC: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
L_800369F0:
    // 0x800369F0: sb          $zero, 0x3B($s0)
    MEM_B(0X3B, ctx->r16) = 0;
    // 0x800369F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800369F8: lbu         $t3, 0xD($s1)
    ctx->r11 = MEM_BU(ctx->r17, 0XD);
    // 0x800369FC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80036A00: bne         $t3, $at, L_80036A70
    if (ctx->r11 != ctx->r1) {
        // 0x80036A04: swc1        $f8, 0x14($s1)
        MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
            goto L_80036A70;
    }
    // 0x80036A04: swc1        $f8, 0x14($s1)
    MEM_W(0X14, ctx->r17) = ctx->f8.u32l;
    // 0x80036A08: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80036A0C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80036A10: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80036A14: jal         0x8001C524
    // 0x80036A18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_34;
    // 0x80036A18: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_34:
    // 0x80036A1C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80036A20: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80036A24: beq         $a0, $at, L_80036AB0
    if (ctx->r4 == ctx->r1) {
        // 0x80036A28: sb          $v0, 0xD($s1)
        MEM_B(0XD, ctx->r17) = ctx->r2;
            goto L_80036AB0;
    }
    // 0x80036A28: sb          $v0, 0xD($s1)
    MEM_B(0XD, ctx->r17) = ctx->r2;
    // 0x80036A2C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80036A30: jal         0x8001CC48
    // 0x80036A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_35;
    // 0x80036A34: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_35:
    // 0x80036A38: lbu         $a1, 0xD($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XD);
    // 0x80036A3C: sb          $v0, 0xE($s1)
    MEM_B(0XE, ctx->r17) = ctx->r2;
    // 0x80036A40: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80036A44: jal         0x8001CC48
    // 0x80036A48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_36;
    // 0x80036A48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_36:
    // 0x80036A4C: lbu         $a1, 0xE($s1)
    ctx->r5 = MEM_BU(ctx->r17, 0XE);
    // 0x80036A50: sb          $v0, 0xF($s1)
    MEM_B(0XF, ctx->r17) = ctx->r2;
    // 0x80036A54: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x80036A58: jal         0x8001CC48
    // 0x80036A5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_37;
    // 0x80036A5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_37:
    // 0x80036A60: lbu         $t4, 0xD($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0XD);
    // 0x80036A64: sb          $v0, 0x10($s1)
    MEM_B(0X10, ctx->r17) = ctx->r2;
    // 0x80036A68: b           L_80036AB0
    // 0x80036A6C: sb          $t4, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r12;
        goto L_80036AB0;
    // 0x80036A6C: sb          $t4, 0xC($s1)
    MEM_B(0XC, ctx->r17) = ctx->r12;
L_80036A70:
    // 0x80036A70: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x80036A74: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80036A78: lui         $a3, 0x3F80
    ctx->r7 = S32(0X3F80 << 16);
    // 0x80036A7C: jal         0x8001C6C4
    // 0x80036A80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001C6C4(rdram, ctx);
        goto after_38;
    // 0x80036A80: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_38:
    // 0x80036A84: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80036A88: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80036A8C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80036A90: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x80036A94: mul.d       $f4, $f18, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f6.d);
    // 0x80036A98: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036A9C: nop

    // 0x80036AA0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80036AA4: add.d       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f18.d = ctx->f8.d + ctx->f4.d;
    // 0x80036AA8: cvt.s.d     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f6.fl = CVT_S_D(ctx->f18.d);
    // 0x80036AAC: swc1        $f6, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->f6.u32l;
L_80036AB0:
    // 0x80036AB0: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
L_80036AB4:
    // 0x80036AB4: lh          $a0, 0x2E($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2E);
    // 0x80036AB8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80036ABC: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80036AC0: addiu       $a3, $sp, 0x48
    ctx->r7 = ADD32(ctx->r29, 0X48);
    // 0x80036AC4: jal         0x8002B0F4
    // 0x80036AC8: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    get_level_segment_waves(rdram, ctx);
        goto after_39;
    // 0x80036AC8: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    after_39:
    // 0x80036ACC: beq         $v0, $zero, L_80036B48
    if (ctx->r2 == 0) {
        // 0x80036AD0: addiu       $v1, $v0, -0x1
        ctx->r3 = ADD32(ctx->r2, -0X1);
            goto L_80036B48;
    }
    // 0x80036AD0: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x80036AD4: bltz        $v1, L_80036B48
    if (SIGNED(ctx->r3) < 0) {
        // 0x80036AD8: sll         $a0, $v1, 2
        ctx->r4 = S32(ctx->r3 << 2);
            goto L_80036B48;
    }
    // 0x80036AD8: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
    // 0x80036ADC: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80036AE0: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80036AE4: addiu       $a2, $zero, 0xE
    ctx->r6 = ADD32(0, 0XE);
    // 0x80036AE8: addiu       $a1, $zero, 0xB
    ctx->r5 = ADD32(0, 0XB);
    // 0x80036AEC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
L_80036AF0:
    // 0x80036AF0: nop

    // 0x80036AF4: addu        $t6, $t5, $a0
    ctx->r14 = ADD32(ctx->r13, ctx->r4);
    // 0x80036AF8: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80036AFC: addiu       $a0, $a0, -0x4
    ctx->r4 = ADD32(ctx->r4, -0X4);
    // 0x80036B00: lb          $v1, 0x10($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X10);
    // 0x80036B04: nop

    // 0x80036B08: beq         $a1, $v1, L_80036B40
    if (ctx->r5 == ctx->r3) {
        // 0x80036B0C: nop
    
            goto L_80036B40;
    }
    // 0x80036B0C: nop

    // 0x80036B10: beq         $a2, $v1, L_80036B40
    if (ctx->r6 == ctx->r3) {
        // 0x80036B14: nop
    
            goto L_80036B40;
    }
    // 0x80036B14: nop

    // 0x80036B18: lwc1        $f8, 0x8($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80036B1C: nop

    // 0x80036B20: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80036B24: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80036B28: nop

    // 0x80036B2C: bc1f        L_80036B40
    if (!c1cs) {
        // 0x80036B30: nop
    
            goto L_80036B40;
    }
    // 0x80036B30: nop

    // 0x80036B34: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80036B38: nop

    // 0x80036B3C: swc1        $f18, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f18.u32l;
L_80036B40:
    // 0x80036B40: bgez        $a0, L_80036AF0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80036B44: lw          $t5, 0x48($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X48);
            goto L_80036AF0;
    }
    // 0x80036B44: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
L_80036B48:
    // 0x80036B48: lw          $t7, 0x78($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X78);
    // 0x80036B4C: sh          $zero, 0x2($s0)
    MEM_H(0X2, ctx->r16) = 0;
    // 0x80036B50: beq         $t7, $zero, L_80036B64
    if (ctx->r15 == 0) {
        // 0x80036B54: sh          $zero, 0x4($s0)
        MEM_H(0X4, ctx->r16) = 0;
            goto L_80036B64;
    }
    // 0x80036B54: sh          $zero, 0x4($s0)
    MEM_H(0X4, ctx->r16) = 0;
    // 0x80036B58: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80036B5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80036B60: swc1        $f6, -0x2B30($at)
    MEM_W(-0X2B30, ctx->r1) = ctx->f6.u32l;
L_80036B64:
    // 0x80036B64: lwc1        $f10, 0x4($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X4);
    // 0x80036B68: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80036B6C: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80036B70: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80036B74: nop

    // 0x80036B78: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80036B7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80036B80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80036B84: nop

    // 0x80036B88: cvt.w.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_D(ctx->f8.d);
    // 0x80036B8C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x80036B90: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80036B94: jal         0x80061C0C
    // 0x80036B98: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    func_80061C0C(rdram, ctx);
        goto after_40;
    // 0x80036B98: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
    after_40:
    // 0x80036B9C: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x80036BA0: lw          $t0, 0x84($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X84);
    // 0x80036BA4: blez        $v0, L_80036BB4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80036BA8: subu        $t1, $v0, $t0
        ctx->r9 = SUB32(ctx->r2, ctx->r8);
            goto L_80036BB4;
    }
    // 0x80036BA8: subu        $t1, $v0, $t0
    ctx->r9 = SUB32(ctx->r2, ctx->r8);
    // 0x80036BAC: b           L_80036BB8
    // 0x80036BB0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
        goto L_80036BB8;
    // 0x80036BB0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
L_80036BB4:
    // 0x80036BB4: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_80036BB8:
    // 0x80036BB8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80036BBC: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x80036BC0: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x80036BC4: jr          $ra
    // 0x80036BC8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80036BC8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void obj_init_collision(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000FD34: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000FD38: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000FD3C: jal         0x80016BC4
    // 0x8000FD40: sw          $a1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r5;
    func_80016BC4(rdram, ctx);
        goto after_0;
    // 0x8000FD40: sw          $a1, 0x5C($a0)
    MEM_W(0X5C, ctx->r4) = ctx->r5;
    after_0:
    // 0x8000FD44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000FD48: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8000FD4C: jr          $ra
    // 0x8000FD50: addiu       $v0, $zero, 0x10C
    ctx->r2 = ADD32(0, 0X10C);
    return;
    // 0x8000FD50: addiu       $v0, $zero, 0x10C
    ctx->r2 = ADD32(0, 0X10C);
;}
RECOMP_FUNC void asset_table_load_addr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_asset_api(uint8_t*, recomp_context*, unsigned); if (dkr_legacy_asset_api(rdram, ctx, 4U)) return;
    // 0x80076DFC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80076E00: lw          $t0, 0x4290($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X4290);
    // 0x80076E04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80076E08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076E0C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x80076E10: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80076E14: sltu        $at, $t6, $a0
    ctx->r1 = ctx->r14 < ctx->r4 ? 1 : 0;
    // 0x80076E18: beq         $at, $zero, L_80076E28
    if (ctx->r1 == 0) {
        // 0x80076E1C: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_80076E28;
    }
    // 0x80076E1C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x80076E20: b           L_80076E58
    // 0x80076E24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80076E58;
    // 0x80076E24: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076E28:
    // 0x80076E28: sll         $t7, $a3, 2
    ctx->r15 = S32(ctx->r7 << 2);
    // 0x80076E2C: addu        $v0, $t7, $t0
    ctx->r2 = ADD32(ctx->r15, ctx->r8);
    // 0x80076E30: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x80076E34: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80076E38: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x80076E3C: addiu       $t9, $t9, -0x33D0
    ctx->r25 = ADD32(ctx->r25, -0X33D0);
    // 0x80076E40: subu        $a2, $t8, $v1
    ctx->r6 = SUB32(ctx->r24, ctx->r3);
    // 0x80076E44: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x80076E48: jal         0x80076F78
    // 0x80076E4C: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    dmacopy(rdram, ctx);
        goto after_0;
    // 0x80076E4C: addu        $a0, $v1, $t9
    ctx->r4 = ADD32(ctx->r3, ctx->r25);
    after_0:
    // 0x80076E50: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80076E54: nop

L_80076E58:
    // 0x80076E58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076E5C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80076E60: jr          $ra
    // 0x80076E64: nop

    return;
    // 0x80076E64: nop

;}
RECOMP_FUNC void func_800732E8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800732E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800732EC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800732F0: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x800732F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800732F8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x800732FC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80073300: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80073304: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    // 0x80073308: jal         0x8006B224
    // 0x8007330C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    level_count(rdram, ctx);
        goto after_0;
    // 0x8007330C: addiu       $a0, $sp, 0x40
    ctx->r4 = ADD32(ctx->r29, 0X40);
    after_0:
    // 0x80073310: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x80073314: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073318: sw          $t6, 0x41EC($at)
    MEM_W(0X41EC, ctx->r1) = ctx->r14;
    // 0x8007331C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073320: sw          $zero, 0x41F0($at)
    MEM_W(0X41F0, ctx->r1) = 0;
    // 0x80073324: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073328: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x8007332C: sw          $t7, 0x41F4($at)
    MEM_W(0X41F4, ctx->r1) = ctx->r15;
    // 0x80073330: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073334: jal         0x80072E28
    // 0x80073338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_1;
    // 0x80073338: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8007333C: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x80073340: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80073344: blez        $t8, L_800733DC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80073348: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800733DC;
    }
    // 0x80073348: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8007334C:
    // 0x8007334C: jal         0x8006B14C
    // 0x80073350: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_2;
    // 0x80073350: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80073354: beq         $v0, $zero, L_8007336C
    if (ctx->r2 == 0) {
        // 0x80073358: andi        $t9, $v0, 0x40
        ctx->r25 = ctx->r2 & 0X40;
            goto L_8007336C;
    }
    // 0x80073358: andi        $t9, $v0, 0x40
    ctx->r25 = ctx->r2 & 0X40;
    // 0x8007335C: bne         $t9, $zero, L_8007336C
    if (ctx->r25 != 0) {
        // 0x80073360: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8007336C;
    }
    // 0x80073360: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80073364: bne         $v0, $at, L_800733C8
    if (ctx->r2 != ctx->r1) {
        // 0x80073368: lw          $t8, 0x40($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X40);
            goto L_800733C8;
    }
    // 0x80073368: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_8007336C:
    // 0x8007336C: lw          $t0, 0x4($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X4);
    // 0x80073370: sll         $t1, $s1, 2
    ctx->r9 = S32(ctx->r17 << 2);
    // 0x80073374: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x80073378: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x8007337C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80073380: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x80073384: beq         $t3, $zero, L_80073390
    if (ctx->r11 == 0) {
        // 0x80073388: andi        $t4, $v0, 0x2
        ctx->r12 = ctx->r2 & 0X2;
            goto L_80073390;
    }
    // 0x80073388: andi        $t4, $v0, 0x2
    ctx->r12 = ctx->r2 & 0X2;
    // 0x8007338C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_80073390:
    // 0x80073390: beq         $t4, $zero, L_800733A4
    if (ctx->r12 == 0) {
        // 0x80073394: andi        $t6, $v0, 0x4
        ctx->r14 = ctx->r2 & 0X4;
            goto L_800733A4;
    }
    // 0x80073394: andi        $t6, $v0, 0x4
    ctx->r14 = ctx->r2 & 0X4;
    // 0x80073398: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007339C: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x800733A0: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
L_800733A4:
    // 0x800733A4: beq         $t6, $zero, L_800733B8
    if (ctx->r14 == 0) {
        // 0x800733A8: nop
    
            goto L_800733B8;
    }
    // 0x800733A8: nop

    // 0x800733AC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800733B0: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x800733B4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_800733B8:
    // 0x800733B8: jal         0x80072E28
    // 0x800733BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80072E28(rdram, ctx);
        goto after_3;
    // 0x800733BC: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_3:
    // 0x800733C0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x800733C4: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
L_800733C8:
    // 0x800733C8: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800733CC: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800733D0: bne         $at, $zero, L_8007334C
    if (ctx->r1 != 0) {
        // 0x800733D4: nop
    
            goto L_8007334C;
    }
    // 0x800733D4: nop

    // 0x800733D8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800733DC:
    // 0x800733DC: addiu       $t9, $zero, 0x44
    ctx->r25 = ADD32(0, 0X44);
    // 0x800733E0: subu        $a0, $t9, $s0
    ctx->r4 = SUB32(ctx->r25, ctx->r16);
    // 0x800733E4: jal         0x80072E28
    // 0x800733E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_4;
    // 0x800733E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800733EC: lhu         $a1, 0x14($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X14);
    // 0x800733F0: jal         0x80072E28
    // 0x800733F4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80072E28(rdram, ctx);
        goto after_5;
    // 0x800733F4: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_5:
    // 0x800733F8: lhu         $a1, 0xE($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XE);
    // 0x800733FC: jal         0x80072E28
    // 0x80073400: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80072E28(rdram, ctx);
        goto after_6;
    // 0x80073400: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_6:
    // 0x80073404: lhu         $a1, 0xC($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0XC);
    // 0x80073408: jal         0x80072E28
    // 0x8007340C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80072E28(rdram, ctx);
        goto after_7;
    // 0x8007340C: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_7:
    // 0x80073410: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80073414: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80073418: blez        $t0, L_80073450
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8007341C: nop
    
            goto L_80073450;
    }
    // 0x8007341C: nop

L_80073420:
    // 0x80073420: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80073424: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80073428: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x8007342C: lh          $a1, 0x0($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X0);
    // 0x80073430: jal         0x80072E28
    // 0x80073434: nop

    func_80072E28(rdram, ctx);
        goto after_8;
    // 0x80073434: nop

    after_8:
    // 0x80073438: lw          $t3, 0x3C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X3C);
    // 0x8007343C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073440: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80073444: bne         $at, $zero, L_80073420
    if (ctx->r1 != 0) {
        // 0x80073448: addiu       $s0, $s0, 0x2
        ctx->r16 = ADD32(ctx->r16, 0X2);
            goto L_80073420;
    }
    // 0x80073448: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8007344C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80073450:
    // 0x80073450: lbu         $a1, 0x16($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X16);
    // 0x80073454: jal         0x80072E28
    // 0x80073458: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80072E28(rdram, ctx);
        goto after_9;
    // 0x80073458: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_9:
    // 0x8007345C: lbu         $a1, 0x17($s2)
    ctx->r5 = MEM_BU(ctx->r18, 0X17);
    // 0x80073460: jal         0x80072E28
    // 0x80073464: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80072E28(rdram, ctx);
        goto after_10;
    // 0x80073464: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
    // 0x80073468: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x8007346C: nop

    // 0x80073470: blez        $t4, L_800734B4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80073474: nop
    
            goto L_800734B4;
    }
    // 0x80073474: nop

L_80073478:
    // 0x80073478: jal         0x8006B1D4
    // 0x8007347C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    level_world_id(rdram, ctx);
        goto after_11;
    // 0x8007347C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80073480: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x80073484: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x80073488: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x8007348C: lw          $a1, 0x0($t7)
    ctx->r5 = MEM_W(ctx->r15, 0X0);
    // 0x80073490: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073494: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80073498: jal         0x80072E28
    // 0x8007349C: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    func_80072E28(rdram, ctx);
        goto after_12;
    // 0x8007349C: andi        $a1, $t8, 0xFFFF
    ctx->r5 = ctx->r24 & 0XFFFF;
    after_12:
    // 0x800734A0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800734A4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800734A8: slt         $at, $s1, $t0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800734AC: bne         $at, $zero, L_80073478
    if (ctx->r1 != 0) {
        // 0x800734B0: nop
    
            goto L_80073478;
    }
    // 0x800734B0: nop

L_800734B4:
    // 0x800734B4: lhu         $a1, 0x8($s2)
    ctx->r5 = MEM_HU(ctx->r18, 0X8);
    // 0x800734B8: jal         0x80072E28
    // 0x800734BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80072E28(rdram, ctx);
        goto after_13;
    // 0x800734BC: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_13:
    // 0x800734C0: lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10);
    // 0x800734C4: jal         0x80072E28
    // 0x800734C8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80072E28(rdram, ctx);
        goto after_14;
    // 0x800734C8: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_14:
    // 0x800734CC: lw          $a1, 0x50($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X50);
    // 0x800734D0: jal         0x80072E28
    // 0x800734D4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_15;
    // 0x800734D4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_15:
    // 0x800734D8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x800734DC: jal         0x80072E28
    // 0x800734E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_16;
    // 0x800734E0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_16:
    // 0x800734E4: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800734E8: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
    // 0x800734EC: addiu       $a0, $a2, 0x2
    ctx->r4 = ADD32(ctx->r6, 0X2);
    // 0x800734F0: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800734F4: lbu         $t3, 0x1($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X1);
    // 0x800734F8: addiu       $t2, $v0, 0x5
    ctx->r10 = ADD32(ctx->r2, 0X5);
    // 0x800734FC: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80073500: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x80073504: sra         $v0, $t4, 16
    ctx->r2 = S32(SIGNED(ctx->r12) >> 16);
    // 0x80073508: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    // 0x8007350C: addiu       $v1, $a2, 0x4
    ctx->r3 = ADD32(ctx->r6, 0X4);
L_80073510:
    // 0x80073510: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x80073514: lbu         $t9, 0x1($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X1);
    // 0x80073518: lbu         $t2, 0x2($v1)
    ctx->r10 = MEM_BU(ctx->r3, 0X2);
    // 0x8007351C: addu        $t8, $v0, $t6
    ctx->r24 = ADD32(ctx->r2, ctx->r14);
    // 0x80073520: lbu         $t5, 0x3($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X3);
    // 0x80073524: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80073528: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8007352C: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x80073530: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x80073534: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80073538: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x8007353C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x80073540: bne         $s1, $a0, L_80073510
    if (ctx->r17 != ctx->r4) {
        // 0x80073544: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80073510;
    }
    // 0x80073544: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80073548: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007354C: sw          $a2, 0x41EC($at)
    MEM_W(0X41EC, ctx->r1) = ctx->r6;
    // 0x80073550: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073554: sw          $zero, 0x41F0($at)
    MEM_W(0X41F0, ctx->r1) = 0;
    // 0x80073558: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007355C: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x80073560: sw          $t8, 0x41F4($at)
    MEM_W(0X41F4, ctx->r1) = ctx->r24;
    // 0x80073564: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073568: jal         0x80072E28
    // 0x8007356C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    func_80072E28(rdram, ctx);
        goto after_17;
    // 0x8007356C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_17:
    // 0x80073570: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80073574: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80073578: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8007357C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80073580: jr          $ra
    // 0x80073584: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80073584: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void debug_text_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5E88: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B5E8C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B5E90: jal         0x8007AE74
    // 0x800B5E94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    load_texture(rdram, ctx);
        goto after_0;
    // 0x800B5E94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x800B5E98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5E9C: sw          $v0, 0x7CA0($at)
    MEM_W(0X7CA0, ctx->r1) = ctx->r2;
    // 0x800B5EA0: jal         0x8007AE74
    // 0x800B5EA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    load_texture(rdram, ctx);
        goto after_1;
    // 0x800B5EA4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800B5EA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5EAC: sw          $v0, 0x7CA4($at)
    MEM_W(0X7CA4, ctx->r1) = ctx->r2;
    // 0x800B5EB0: jal         0x8007AE74
    // 0x800B5EB4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_texture(rdram, ctx);
        goto after_2;
    // 0x800B5EB4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_2:
    // 0x800B5EB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B5EBC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B5EC0: sw          $v0, 0x7CA8($at)
    MEM_W(0X7CA8, ctx->r1) = ctx->r2;
    // 0x800B5EC4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B5EC8: addiu       $t6, $t6, 0x7CD8
    ctx->r14 = ADD32(ctx->r14, 0X7CD8);
    // 0x800B5ECC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B5ED0: sw          $t6, -0x7A28($at)
    MEM_W(-0X7A28, ctx->r1) = ctx->r14;
    // 0x800B5ED4: jr          $ra
    // 0x800B5ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800B5ED8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void sort_objects_by_dist(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80015348: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8001534C: sw          $s4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r20;
    // 0x80015350: sw          $s3, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r19;
    // 0x80015354: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80015358: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8001535C: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x80015360: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80015364: sw          $s5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r21;
    // 0x80015368: sw          $s2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r18;
    // 0x8001536C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80015370: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x80015374: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80015378: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8001537C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80015380: bne         $at, $zero, L_80015584
    if (ctx->r1 != 0) {
        // 0x80015384: swc1        $f20, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
            goto L_80015584;
    }
    // 0x80015384: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80015388: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001538C: bne         $at, $zero, L_80015460
    if (ctx->r1 != 0) {
        // 0x80015390: sll         $s1, $a0, 2
        ctx->r17 = S32(ctx->r4 << 2);
            goto L_80015460;
    }
    // 0x80015390: sll         $s1, $a0, 2
    ctx->r17 = S32(ctx->r4 << 2);
    // 0x80015394: lui         $at, 0xC67A
    ctx->r1 = S32(0XC67A << 16);
    // 0x80015398: sll         $s5, $a1, 2
    ctx->r21 = S32(ctx->r5 << 2);
    // 0x8001539C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800153A0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800153A4: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800153A8: addiu       $s2, $s2, -0x51A8
    ctx->r18 = ADD32(ctx->r18, -0X51A8);
    // 0x800153AC: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_800153B0:
    // 0x800153B0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800153B4: nop

    // 0x800153B8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x800153BC: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x800153C0: nop

    // 0x800153C4: beq         $a0, $zero, L_80015450
    if (ctx->r4 == 0) {
        // 0x800153C8: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80015450;
    }
    // 0x800153C8: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800153CC: lh          $t8, 0x6($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X6);
    // 0x800153D0: nop

    // 0x800153D4: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x800153D8: beq         $t9, $zero, L_80015400
    if (ctx->r25 == 0) {
        // 0x800153DC: nop
    
            goto L_80015400;
    }
    // 0x800153DC: nop

    // 0x800153E0: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800153E4: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800153E8: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x800153EC: jal         0x80069DC8
    // 0x800153F0: nop

    get_distance_to_camera(rdram, ctx);
        goto after_0;
    // 0x800153F0: nop

    after_0:
    // 0x800153F4: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800153F8: b           L_80015454
    // 0x800153FC: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
        goto L_80015454;
    // 0x800153FC: swc1        $f4, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f4.u32l;
L_80015400:
    // 0x80015400: lw          $t0, 0x40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X40);
    // 0x80015404: nop

    // 0x80015408: lhu         $t1, 0x30($t0)
    ctx->r9 = MEM_HU(ctx->r8, 0X30);
    // 0x8001540C: nop

    // 0x80015410: andi        $t2, $t1, 0x80
    ctx->r10 = ctx->r9 & 0X80;
    // 0x80015414: beq         $t2, $zero, L_80015430
    if (ctx->r10 == 0) {
        // 0x80015418: nop
    
            goto L_80015430;
    }
    // 0x80015418: nop

    // 0x8001541C: lwc1        $f6, 0x30($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X30);
    // 0x80015420: nop

    // 0x80015424: add.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f20.fl;
    // 0x80015428: b           L_80015454
    // 0x8001542C: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
        goto L_80015454;
    // 0x8001542C: swc1        $f8, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f8.u32l;
L_80015430:
    // 0x80015430: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80015434: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80015438: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8001543C: jal         0x80069DC8
    // 0x80015440: nop

    get_distance_to_camera(rdram, ctx);
        goto after_1;
    // 0x80015440: nop

    after_1:
    // 0x80015444: neg.s       $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = -ctx->f0.fl;
    // 0x80015448: b           L_80015454
    // 0x8001544C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
        goto L_80015454;
    // 0x8001544C: swc1        $f10, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f10.u32l;
L_80015450:
    // 0x80015450: swc1        $f22, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f22.u32l;
L_80015454:
    // 0x80015454: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80015458: bne         $s5, $s1, L_800153B0
    if (ctx->r21 != ctx->r17) {
        // 0x8001545C: nop
    
            goto L_800153B0;
    }
    // 0x8001545C: nop

L_80015460:
    // 0x80015460: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80015464: addiu       $s2, $s2, -0x51A8
    ctx->r18 = ADD32(ctx->r18, -0X51A8);
    // 0x80015468: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
L_8001546C:
    // 0x8001546C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80015470: beq         $at, $zero, L_8001557C
    if (ctx->r1 == 0) {
        // 0x80015474: or          $v0, $s3, $zero
        ctx->r2 = ctx->r19 | 0;
            goto L_8001557C;
    }
    // 0x80015474: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x80015478: subu        $v1, $s4, $s3
    ctx->r3 = SUB32(ctx->r20, ctx->r19);
    // 0x8001547C: andi        $t3, $v1, 0x1
    ctx->r11 = ctx->r3 & 0X1;
    // 0x80015480: beq         $t3, $zero, L_800154D8
    if (ctx->r11 == 0) {
        // 0x80015484: sll         $s1, $v0, 2
        ctx->r17 = S32(ctx->r2 << 2);
            goto L_800154D8;
    }
    // 0x80015484: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x80015488: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8001548C: sll         $v1, $s3, 2
    ctx->r3 = S32(ctx->r19 << 2);
    // 0x80015490: addu        $v0, $t4, $v1
    ctx->r2 = ADD32(ctx->r12, ctx->r3);
    // 0x80015494: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80015498: lw          $a2, 0x4($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X4);
    // 0x8001549C: lwc1        $f0, 0x30($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800154A0: lwc1        $f2, 0x30($a2)
    ctx->f2.u32l = MEM_W(ctx->r6, 0X30);
    // 0x800154A4: addiu       $a3, $s3, 0x1
    ctx->r7 = ADD32(ctx->r19, 0X1);
    // 0x800154A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x800154AC: nop

    // 0x800154B0: bc1f        L_800154CC
    if (!c1cs) {
        // 0x800154B4: nop
    
            goto L_800154CC;
    }
    // 0x800154B4: nop

    // 0x800154B8: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800154BC: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800154C0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800154C4: addu        $t6, $t5, $v1
    ctx->r14 = ADD32(ctx->r13, ctx->r3);
    // 0x800154C8: sw          $a0, 0x4($t6)
    MEM_W(0X4, ctx->r14) = ctx->r4;
L_800154CC:
    // 0x800154CC: beq         $a3, $s4, L_8001557C
    if (ctx->r7 == ctx->r20) {
        // 0x800154D0: or          $v0, $a3, $zero
        ctx->r2 = ctx->r7 | 0;
            goto L_8001557C;
    }
    // 0x800154D0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x800154D4: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
L_800154D8:
    // 0x800154D8: sll         $a2, $s4, 2
    ctx->r6 = S32(ctx->r20 << 2);
L_800154DC:
    // 0x800154DC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800154E0: nop

    // 0x800154E4: addu        $v0, $t7, $s1
    ctx->r2 = ADD32(ctx->r15, ctx->r17);
    // 0x800154E8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800154EC: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800154F0: lwc1        $f16, 0x30($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X30);
    // 0x800154F4: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x800154F8: nop

    // 0x800154FC: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x80015500: nop

    // 0x80015504: bc1f        L_8001553C
    if (!c1cs) {
        // 0x80015508: nop
    
            goto L_8001553C;
    }
    // 0x80015508: nop

    // 0x8001550C: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x80015510: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x80015514: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015518: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x8001551C: sw          $a0, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r4;
    // 0x80015520: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80015524: nop

    // 0x80015528: addu        $v0, $t0, $s1
    ctx->r2 = ADD32(ctx->r8, ctx->r17);
    // 0x8001552C: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x80015530: nop

    // 0x80015534: lwc1        $f0, 0x30($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X30);
    // 0x80015538: nop

L_8001553C:
    // 0x8001553C: lw          $a0, 0x8($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X8);
    // 0x80015540: nop

    // 0x80015544: lwc1        $f18, 0x30($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0X30);
    // 0x80015548: nop

    // 0x8001554C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x80015550: nop

    // 0x80015554: bc1f        L_80015570
    if (!c1cs) {
        // 0x80015558: nop
    
            goto L_80015570;
    }
    // 0x80015558: nop

    // 0x8001555C: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x80015560: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x80015564: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80015568: addu        $t2, $t1, $s1
    ctx->r10 = ADD32(ctx->r9, ctx->r17);
    // 0x8001556C: sw          $v1, 0x8($t2)
    MEM_W(0X8, ctx->r10) = ctx->r3;
L_80015570:
    // 0x80015570: addiu       $s1, $s1, 0x8
    ctx->r17 = ADD32(ctx->r17, 0X8);
    // 0x80015574: bne         $s1, $a2, L_800154DC
    if (ctx->r17 != ctx->r6) {
        // 0x80015578: nop
    
            goto L_800154DC;
    }
    // 0x80015578: nop

L_8001557C:
    // 0x8001557C: beq         $a1, $zero, L_8001546C
    if (ctx->r5 == 0) {
        // 0x80015580: slt         $at, $s3, $s4
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
            goto L_8001546C;
    }
    // 0x80015580: slt         $at, $s3, $s4
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r20) ? 1 : 0;
L_80015584:
    // 0x80015584: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80015588: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001558C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80015590: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80015594: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80015598: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8001559C: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x800155A0: lw          $s2, 0x2C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X2C);
    // 0x800155A4: lw          $s3, 0x30($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X30);
    // 0x800155A8: lw          $s4, 0x34($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X34);
    // 0x800155AC: lw          $s5, 0x38($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X38);
    // 0x800155B0: jr          $ra
    // 0x800155B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800155B4: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void mark_to_read_course_times(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EB40: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EB44: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006EB48: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EB4C: nop

    // 0x8006EB50: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x8006EB54: jr          $ra
    // 0x8006EB58: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EB58: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void obj_init_eggcreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035640: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80035644: jr          $ra
    // 0x80035648: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80035648: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void add_segment_to_order(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80029D14: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80029D18: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80029D1C: lw          $t0, -0x36E8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X36E8);
    // 0x80029D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80029D24: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80029D28: lh          $t6, 0x1A($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X1A);
    // 0x80029D2C: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80029D30: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80029D34: beq         $at, $zero, L_80029DD0
    if (ctx->r1 == 0) {
        // 0x80029D38: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80029DD0;
    }
    // 0x80029D38: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80029D3C: lw          $v1, -0x4F2C($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X4F2C);
    // 0x80029D40: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80029D44: beq         $v1, $at, L_80029D74
    if (ctx->r3 == ctx->r1) {
        // 0x80029D48: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80029D74;
    }
    // 0x80029D48: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80029D4C: lw          $t7, 0x10($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X10);
    // 0x80029D50: sra         $t9, $a0, 3
    ctx->r25 = S32(SIGNED(ctx->r4) >> 3);
    // 0x80029D54: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80029D58: addu        $t1, $t8, $t9
    ctx->r9 = ADD32(ctx->r24, ctx->r25);
    // 0x80029D5C: lbu         $v0, 0x0($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X0);
    // 0x80029D60: andi        $t2, $a0, 0x7
    ctx->r10 = ctx->r4 & 0X7;
    // 0x80029D64: srlv        $v0, $v0, $t2
    ctx->r2 = S32(U32(ctx->r2) >> (ctx->r10 & 31));
    // 0x80029D68: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x80029D6C: b           L_80029D74
    // 0x80029D70: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80029D74;
    // 0x80029D70: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80029D74:
    // 0x80029D74: andi        $t4, $v0, 0x1
    ctx->r12 = ctx->r2 & 0X1;
    extern void dkr_extend_hub_segment_bitfield(uint8_t*, recomp_context*); dkr_extend_hub_segment_bitfield(rdram, ctx);
    // 0x80029D78: beq         $t4, $zero, L_80029DD0
    if (ctx->r12 == 0) {
        // 0x80029D7C: sll         $t6, $a3, 2
        ctx->r14 = S32(ctx->r7 << 2);
            goto L_80029DD0;
    }
    // 0x80029D7C: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x80029D80: lw          $t5, 0x8($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X8);
    // 0x80029D84: subu        $t6, $t6, $a3
    ctx->r14 = SUB32(ctx->r14, ctx->r7);
    // 0x80029D88: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80029D8C: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    // 0x80029D90: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80029D94: jal         0x8002A5F8
    // 0x80029D98: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    block_visible(rdram, ctx);
        goto after_0;
    // 0x80029D98: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    after_0:
    extern void dkr_keep_hub_segment_visible(uint8_t*, recomp_context*); dkr_keep_hub_segment_visible(rdram, ctx);
    // 0x80029D9C: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x80029DA0: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x80029DA4: beq         $v0, $zero, L_80029DD4
    if (ctx->r2 == 0) {
        // 0x80029DA8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80029DD4;
    }
    // 0x80029DA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80029DAC: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80029DB0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80029DB4: nop

    // 0x80029DB8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80029DBC: sb          $a3, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r7;
    // 0x80029DC0: lw          $t1, 0x0($a1)
    ctx->r9 = MEM_W(ctx->r5, 0X0);
    // 0x80029DC4: nop

    // 0x80029DC8: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x80029DCC: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
L_80029DD0:
    // 0x80029DD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80029DD4:
    // 0x80029DD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80029DD8: jr          $ra
    // 0x80029DDC: nop

    return;
    // 0x80029DDC: nop

;}
RECOMP_FUNC void thread0_Main(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6FC4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B6FC8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800B6FCC: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800B6FD0: addiu       $s4, $s4, -0x6870
    ctx->r20 = ADD32(ctx->r20, -0X6870);
    // 0x800B6FD4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800B6FD8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800B6FDC: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B6FE0: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B6FE4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800B6FE8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800B6FEC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800B6FF0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800B6FF4: addiu       $a1, $a1, -0x6858
    ctx->r5 = ADD32(ctx->r5, -0X6858);
    // 0x800B6FF8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B6FFC: jal         0x800C8820
    // 0x800B7000: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x800B7000: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_0:
    // 0x800B7004: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800B7008: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800B700C: jal         0x800CCBB0
    // 0x800B7010: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x800B7010: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_1:
    // 0x800B7014: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    // 0x800B7018: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800B701C: jal         0x800CCBB0
    // 0x800B7020: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    osSetEventMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x800B7020: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    after_2:
    // 0x800B7024: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B7028: lui         $a2, 0x8013
    ctx->r6 = S32(0X8013 << 16);
    // 0x800B702C: addiu       $a2, $a2, -0x6838
    ctx->r6 = ADD32(ctx->r6, -0X6838);
    // 0x800B7030: addiu       $a1, $a1, -0x6818
    ctx->r5 = ADD32(ctx->r5, -0X6818);
    // 0x800B7034: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x800B7038: jal         0x800C6000
    // 0x800B703C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_3;
    // 0x800B703C: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_3:
    // 0x800B7040: addiu       $s3, $zero, -0x9
    ctx->r19 = ADD32(0, -0X9);
    // 0x800B7044: lui         $s2, 0x800
    ctx->r18 = S32(0X800 << 16);
    // 0x800B7048: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x800B704C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800B7050:
    // 0x800B7050: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B7054: jal         0x800C8BB0
    // 0x800B7058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_4;
    // 0x800B7058: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_4:
    // 0x800B705C: jal         0x8009C30C
    // 0x800B7060: nop

    get_filtered_cheats(rdram, ctx);
        goto after_5;
    // 0x800B7060: nop

    after_5:
    // 0x800B7064: and         $t6, $v0, $s2
    ctx->r14 = ctx->r2 & ctx->r18;
    // 0x800B7068: beq         $t6, $zero, L_800B7050
    if (ctx->r14 == 0) {
        // 0x800B706C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800B7050;
    }
    // 0x800B706C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B7070: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x800B7074: nop

    // 0x800B7078: or          $s0, $s0, $t7
    ctx->r16 = ctx->r16 | ctx->r15;
    // 0x800B707C: andi        $t8, $s0, 0x8
    ctx->r24 = ctx->r16 & 0X8;
    // 0x800B7080: bne         $t8, $zero, L_800B7090
    if (ctx->r24 != 0) {
        // 0x800B7084: andi        $t9, $s0, 0x2
        ctx->r25 = ctx->r16 & 0X2;
            goto L_800B7090;
    }
    // 0x800B7084: andi        $t9, $s0, 0x2
    ctx->r25 = ctx->r16 & 0X2;
    // 0x800B7088: beq         $t9, $zero, L_800B7050
    if (ctx->r25 == 0) {
        // 0x800B708C: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800B7050;
    }
    // 0x800B708C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
L_800B7090:
    // 0x800B7090: jal         0x800B70D0
    // 0x800B7094: and         $s0, $s0, $s3
    ctx->r16 = ctx->r16 & ctx->r19;
    enable_interupts_on_main(rdram, ctx);
        goto after_6;
    // 0x800B7094: and         $s0, $s0, $s3
    ctx->r16 = ctx->r16 & ctx->r19;
    after_6:
    // 0x800B7098: jal         0x800B7144
    // 0x800B709C: nop

    stop_all_threads_except_main(rdram, ctx);
        goto after_7;
    // 0x800B709C: nop

    after_7:
    // 0x800B70A0: jal         0x800B71B0
    // 0x800B70A4: nop

    write_epc_data_to_cpak(rdram, ctx);
        goto after_8;
    // 0x800B70A4: nop

    after_8:
    // 0x800B70A8: b           L_800B7050
    // 0x800B70AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
        goto L_800B7050;
    // 0x800B70AC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800B70B0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800B70B4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800B70B8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800B70BC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800B70C0: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800B70C4: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800B70C8: jr          $ra
    // 0x800B70CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B70CC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void hud_sound_play_delayed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7484: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7488: addiu       $v0, $v0, 0x6D74
    ctx->r2 = ADD32(ctx->r2, 0X6D74);
    // 0x800A748C: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800A7490: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800A7494: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A7498: bne         $t7, $zero, L_800A74E4
    if (ctx->r15 != 0) {
        // 0x800A749C: andi        $t6, $a0, 0xFFFF
        ctx->r14 = ctx->r4 & 0XFFFF;
            goto L_800A74E4;
    }
    // 0x800A749C: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x800A74A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A74A4: sh          $t6, 0x6D7C($at)
    MEM_H(0X6D7C, ctx->r1) = ctx->r14;
    // 0x800A74A8: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800A74AC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A74B0: nop

    // 0x800A74B4: mul.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f12.fl, ctx->f4.fl);
    // 0x800A74B8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A74BC: nop

    // 0x800A74C0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A74C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A74C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A74CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A74D0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A74D4: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800A74D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A74DC: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A74E0: sw          $a2, 0x6D78($at)
    MEM_W(0X6D78, ctx->r1) = ctx->r6;
L_800A74E4:
    // 0x800A74E4: jr          $ra
    // 0x800A74E8: nop

    return;
    // 0x800A74E8: nop

;}
