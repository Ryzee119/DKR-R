#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void byteswap32(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C61AC: lbu         $t6, 0x1($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X1);
    // 0x800C61B0: lbu         $v1, 0x0($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X0);
    // 0x800C61B4: lbu         $t8, 0x2($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X2);
    // 0x800C61B8: lbu         $t0, 0x3($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X3);
    // 0x800C61BC: sll         $t7, $t6, 8
    ctx->r15 = S32(ctx->r14 << 8);
    // 0x800C61C0: or          $v1, $v1, $t7
    ctx->r3 = ctx->r3 | ctx->r15;
    // 0x800C61C4: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C61C8: or          $v1, $v1, $t9
    ctx->r3 = ctx->r3 | ctx->r25;
    // 0x800C61CC: sll         $t1, $t0, 24
    ctx->r9 = S32(ctx->r8 << 24);
    // 0x800C61D0: addiu       $a0, $a0, 0x3
    ctx->r4 = ADD32(ctx->r4, 0X3);
    // 0x800C61D4: jr          $ra
    // 0x800C61D8: or          $v0, $v1, $t1
    ctx->r2 = ctx->r3 | ctx->r9;
    return;
    // 0x800C61D8: or          $v0, $v1, $t1
    ctx->r2 = ctx->r3 | ctx->r9;
;}
RECOMP_FUNC void alSeqpNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A710: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8000A714: jr          $ra
    // 0x8000A718: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8000A718: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void update_car_velocity_ground(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005492C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80054930: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80054934: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80054938: sw          $a2, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r6;
    // 0x8005493C: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    // 0x80054940: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80054944: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054948: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x8005494C: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80054950: mul.s       $f2, $f12, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80054954: swc1        $f18, 0x84($a1)
    MEM_W(0X84, ctx->r5) = ctx->f18.u32l;
    // 0x80054958: bc1f        L_80054964
    if (!c1cs) {
        // 0x8005495C: swc1        $f18, 0x88($a1)
        MEM_W(0X88, ctx->r5) = ctx->f18.u32l;
            goto L_80054964;
    }
    // 0x8005495C: swc1        $f18, 0x88($a1)
    MEM_W(0X88, ctx->r5) = ctx->f18.u32l;
    // 0x80054960: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80054964:
    // 0x80054964: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x80054968: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8005496C: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80054970: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80054974: jal         0x80057220
    // 0x80054978: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    handle_racer_top_speed(rdram, ctx);
        goto after_0;
    // 0x80054978: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8005497C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80054980: swc1        $f0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f0.u32l;
    // 0x80054984: lh          $v0, 0x1A2($a1)
    ctx->r2 = MEM_H(ctx->r5, 0X1A2);
    // 0x80054988: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8005498C: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80054990: slti        $at, $v0, 0x1C01
    ctx->r1 = SIGNED(ctx->r2) < 0X1C01 ? 1 : 0;
    // 0x80054994: beq         $at, $zero, L_800549A4
    if (ctx->r1 == 0) {
        // 0x80054998: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800549A4;
    }
    // 0x80054998: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005499C: slti        $at, $v0, -0x1C00
    ctx->r1 = SIGNED(ctx->r2) < -0X1C00 ? 1 : 0;
    // 0x800549A0: beq         $at, $zero, L_800549AC
    if (ctx->r1 == 0) {
        // 0x800549A4: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_800549AC;
    }
L_800549A4:
    // 0x800549A4: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800549A8: sw          $t6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r14;
L_800549AC:
    // 0x800549AC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800549B0: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x800549B4: lw          $a0, -0x2ACC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2ACC);
    // 0x800549B8: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x800549BC: addiu       $v1, $zero, 0x6
    ctx->r3 = ADD32(0, 0X6);
    // 0x800549C0: beq         $t7, $zero, L_800549CC
    if (ctx->r15 == 0) {
        // 0x800549C4: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_800549CC;
    }
    // 0x800549C4: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x800549C8: addiu       $v1, $zero, 0xC
    ctx->r3 = ADD32(0, 0XC);
L_800549CC:
    // 0x800549CC: beq         $v0, $zero, L_800549E8
    if (ctx->r2 == 0) {
        // 0x800549D0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800549E8;
    }
    // 0x800549D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800549D4: lb          $t8, 0x1E6($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1E6);
    // 0x800549D8: nop

    // 0x800549DC: beq         $t8, $zero, L_800549E8
    if (ctx->r24 == 0) {
        // 0x800549E0: nop
    
            goto L_800549E8;
    }
    // 0x800549E0: nop

    // 0x800549E4: addiu       $v1, $zero, 0x12
    ctx->r3 = ADD32(0, 0X12);
L_800549E8:
    // 0x800549E8: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x800549EC: lwc1        $f7, 0x67E8($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X67E8);
    // 0x800549F0: lwc1        $f6, 0x67EC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X67EC);
    // 0x800549F4: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800549F8: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x800549FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80054A00: bc1f        L_80054A18
    if (!c1cs) {
        // 0x80054A04: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80054A18;
    }
    // 0x80054A04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054A08: multu       $a0, $v1
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054A0C: mflo        $v0
    ctx->r2 = lo;
    // 0x80054A10: nop

    // 0x80054A14: nop

L_80054A18:
    // 0x80054A18: lwc1        $f9, 0x67F0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X67F0);
    // 0x80054A1C: lwc1        $f8, 0x67F4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X67F4);
    // 0x80054A20: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x80054A24: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80054A28: nop

    // 0x80054A2C: bc1f        L_80054A44
    if (!c1cs) {
        // 0x80054A30: negu        $t9, $a0
        ctx->r25 = SUB32(0, ctx->r4);
            goto L_80054A44;
    }
    // 0x80054A30: negu        $t9, $a0
    ctx->r25 = SUB32(0, ctx->r4);
    // 0x80054A34: multu       $t9, $v1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054A38: mflo        $v0
    ctx->r2 = lo;
    // 0x80054A3C: nop

    // 0x80054A40: nop

L_80054A44:
    // 0x80054A44: multu       $v0, $t0
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80054A48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054A4C: lwc1        $f6, -0x2A90($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X2A90);
    // 0x80054A50: lh          $t3, 0x1A0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X1A0);
    // 0x80054A54: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80054A58: mflo        $v0
    ctx->r2 = lo;
    // 0x80054A5C: sra         $t1, $v0, 1
    ctx->r9 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80054A60: mtc1        $t1, $f10
    ctx->f10.u32l = ctx->r9;
    // 0x80054A64: nop

    // 0x80054A68: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80054A6C: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80054A70: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80054A74: nop

    // 0x80054A78: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80054A7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80054A80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80054A84: nop

    // 0x80054A88: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80054A8C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80054A90: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80054A94: subu        $t5, $t3, $t4
    ctx->r13 = SUB32(ctx->r11, ctx->r12);
    // 0x80054A98: sh          $t5, 0x1A0($a1)
    MEM_H(0X1A0, ctx->r5) = ctx->r13;
    // 0x80054A9C: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    // 0x80054AA0: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80054AA4: jal         0x80053478
    // 0x80054AA8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    handle_car_steering(rdram, ctx);
        goto after_1;
    // 0x80054AA8: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80054AAC: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80054AB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054AB4: lwc1        $f4, 0x30($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X30);
    // 0x80054AB8: lwc1        $f9, 0x67F8($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X67F8);
    // 0x80054ABC: lwc1        $f8, 0x67FC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X67FC);
    // 0x80054AC0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80054AC4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80054AC8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80054ACC: lbu         $a0, 0x1DC($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0X1DC);
    // 0x80054AD0: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80054AD4: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80054AD8: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80054ADC: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80054AE0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80054AE4: swc1        $f4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f4.u32l;
    // 0x80054AE8: beq         $a0, $at, L_80054B0C
    if (ctx->r4 == ctx->r1) {
        // 0x80054AEC: mov.s       $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
            goto L_80054B0C;
    }
    // 0x80054AEC: mov.s       $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = ctx->f18.fl;
    // 0x80054AF0: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80054AF4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054AF8: addu        $at, $at, $t6
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80054AFC: lwc1        $f6, -0x3464($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X3464);
    // 0x80054B00: blez        $a0, L_80054B0C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80054B04: add.s       $f0, $f18, $f6
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
            goto L_80054B0C;
    }
    // 0x80054B04: add.s       $f0, $f18, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80054B08: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
L_80054B0C:
    // 0x80054B0C: lwc1        $f10, 0xC0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC0);
    // 0x80054B10: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80054B14: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80054B18: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80054B1C: c.eq.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d == ctx->f4.d;
    // 0x80054B20: nop

    // 0x80054B24: bc1t        L_80054B34
    if (c1cs) {
        // 0x80054B28: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80054B34;
    }
    // 0x80054B28: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054B2C: lwc1        $f0, 0x6800($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6800);
    // 0x80054B30: nop

L_80054B34:
    // 0x80054B34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054B38: sb          $v1, -0x2A7F($at)
    MEM_B(-0X2A7F, ctx->r1) = ctx->r3;
    // 0x80054B3C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80054B40: sb          $zero, 0x1E6($a1)
    MEM_B(0X1E6, ctx->r5) = 0;
    // 0x80054B44: bne         $v1, $at, L_80054B60
    if (ctx->r3 != ctx->r1) {
        // 0x80054B48: sw          $zero, 0x10C($a1)
        MEM_W(0X10C, ctx->r5) = 0;
            goto L_80054B60;
    }
    // 0x80054B48: sw          $zero, 0x10C($a1)
    MEM_W(0X10C, ctx->r5) = 0;
    // 0x80054B4C: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80054B50: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80054B54: nop

    // 0x80054B58: swc1        $f6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f6.u32l;
    // 0x80054B5C: swc1        $f18, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->f18.u32l;
L_80054B60:
    // 0x80054B60: lb          $t7, 0x1D3($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1D3);
    // 0x80054B64: nop

    // 0x80054B68: bne         $t7, $zero, L_80054BA8
    if (ctx->r15 != 0) {
        // 0x80054B6C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80054BA8;
    }
    // 0x80054B6C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80054B70: bne         $v1, $at, L_80054BA8
    if (ctx->r3 != ctx->r1) {
        // 0x80054B74: addiu       $a0, $zero, 0x2D
        ctx->r4 = ADD32(0, 0X2D);
            goto L_80054BA8;
    }
    // 0x80054B74: addiu       $a0, $zero, 0x2D
    ctx->r4 = ADD32(0, 0X2D);
    // 0x80054B78: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80054B7C: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    // 0x80054B80: swc1        $f0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f0.u32l;
    // 0x80054B84: jal         0x8000C8B4
    // 0x80054B88: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x80054B88: swc1        $f2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80054B8C: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80054B90: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80054B94: lwc1        $f0, 0x28($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80054B98: lwc1        $f2, 0x30($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80054B9C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x80054BA0: sb          $v0, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = ctx->r2;
    // 0x80054BA4: sb          $t8, 0x203($a1)
    MEM_B(0X203, ctx->r5) = ctx->r24;
L_80054BA8:
    // 0x80054BA8: mul.s       $f8, $f2, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80054BAC: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054BB0: nop

    // 0x80054BB4: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80054BB8: swc1        $f4, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f4.u32l;
    // 0x80054BBC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80054BC0: nop

    // 0x80054BC4: beq         $t9, $zero, L_80054BE8
    if (ctx->r25 == 0) {
        // 0x80054BC8: nop
    
            goto L_80054BE8;
    }
    // 0x80054BC8: nop

    // 0x80054BCC: lbu         $v0, 0x1EE($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1EE);
    // 0x80054BD0: nop

    // 0x80054BD4: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80054BD8: beq         $at, $zero, L_80054BEC
    if (ctx->r1 == 0) {
        // 0x80054BDC: addiu       $t0, $v0, 0x1
        ctx->r8 = ADD32(ctx->r2, 0X1);
            goto L_80054BEC;
    }
    // 0x80054BDC: addiu       $t0, $v0, 0x1
    ctx->r8 = ADD32(ctx->r2, 0X1);
    // 0x80054BE0: b           L_80054BEC
    // 0x80054BE4: sb          $t0, 0x1EE($a1)
    MEM_B(0X1EE, ctx->r5) = ctx->r8;
        goto L_80054BEC;
    // 0x80054BE4: sb          $t0, 0x1EE($a1)
    MEM_B(0X1EE, ctx->r5) = ctx->r8;
L_80054BE8:
    // 0x80054BE8: sb          $zero, 0x1EE($a1)
    MEM_B(0X1EE, ctx->r5) = 0;
L_80054BEC:
    // 0x80054BEC: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80054BF0: jal         0x80066210
    // 0x80054BF4: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    cam_get_viewport_layout(rdram, ctx);
        goto after_3;
    // 0x80054BF4: sw          $a3, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r7;
    after_3:
    // 0x80054BF8: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x80054BFC: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80054C00: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x80054C04: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80054C08: beq         $at, $zero, L_80054C88
    if (ctx->r1 == 0) {
        // 0x80054C0C: nop
    
            goto L_80054C88;
    }
    // 0x80054C0C: nop

    // 0x80054C10: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80054C14: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80054C18: beq         $t1, $zero, L_80054C88
    if (ctx->r9 == 0) {
        // 0x80054C1C: nop
    
            goto L_80054C88;
    }
    // 0x80054C1C: nop

    // 0x80054C20: lwc1        $f6, 0x2C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054C24: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80054C28: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80054C2C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80054C30: c.lt.d      $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f10.d < ctx->f8.d;
    // 0x80054C34: nop

    // 0x80054C38: bc1f        L_80054C88
    if (!c1cs) {
        // 0x80054C3C: nop
    
            goto L_80054C88;
    }
    // 0x80054C3C: nop

    // 0x80054C40: lbu         $v0, 0x1DE($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1DE);
    // 0x80054C44: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80054C48: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80054C4C: beq         $at, $zero, L_80054C64
    if (ctx->r1 == 0) {
        // 0x80054C50: sll         $t3, $v0, 1
        ctx->r11 = S32(ctx->r2 << 1);
            goto L_80054C64;
    }
    // 0x80054C50: sll         $t3, $v0, 1
    ctx->r11 = S32(ctx->r2 << 1);
    // 0x80054C54: lw          $t2, 0x74($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X74);
    // 0x80054C58: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x80054C5C: or          $t6, $t2, $t5
    ctx->r14 = ctx->r10 | ctx->r13;
    // 0x80054C60: sw          $t6, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r14;
L_80054C64:
    // 0x80054C64: lbu         $v0, 0x1DF($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X1DF);
    // 0x80054C68: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80054C6C: slti        $at, $v0, 0xFF
    ctx->r1 = SIGNED(ctx->r2) < 0XFF ? 1 : 0;
    // 0x80054C70: beq         $at, $zero, L_80054C88
    if (ctx->r1 == 0) {
        // 0x80054C74: sll         $t8, $v0, 1
        ctx->r24 = S32(ctx->r2 << 1);
            goto L_80054C88;
    }
    // 0x80054C74: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x80054C78: lw          $t7, 0x74($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X74);
    // 0x80054C7C: sllv        $t0, $t9, $t8
    ctx->r8 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x80054C80: or          $t1, $t7, $t0
    ctx->r9 = ctx->r15 | ctx->r8;
    // 0x80054C84: sw          $t1, 0x74($a3)
    MEM_W(0X74, ctx->r7) = ctx->r9;
L_80054C88:
    // 0x80054C88: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054C8C: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x80054C90: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80054C94: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80054C98: bc1f        L_80054CA4
    if (!c1cs) {
        // 0x80054C9C: mov.s       $f2, $f12
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
            goto L_80054CA4;
    }
    // 0x80054C9C: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80054CA0: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
L_80054CA4:
    // 0x80054CA4: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80054CA8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80054CAC: bc1f        L_80054CB8
    if (!c1cs) {
        // 0x80054CB0: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80054CB8;
    }
    // 0x80054CB0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80054CB4: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_80054CB8:
    // 0x80054CB8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80054CBC: lw          $t3, -0x2A9C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2A9C);
    // 0x80054CC0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80054CC4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80054CC8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80054CCC: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80054CD0: cvt.w.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    ctx->f4.u32l = CVT_W_S(ctx->f2.fl);
    // 0x80054CD4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80054CD8: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x80054CDC: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80054CE0: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x80054CE4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80054CE8: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80054CEC: sll         $t2, $v0, 2
    ctx->r10 = S32(ctx->r2 << 2);
    // 0x80054CF0: addu        $v1, $t3, $t2
    ctx->r3 = ADD32(ctx->r11, ctx->r10);
    // 0x80054CF4: sub.s       $f0, $f2, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80054CF8: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80054CFC: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80054D00: sub.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d - ctx->f4.d;
    // 0x80054D04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054D08: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80054D0C: mul.d       $f4, $f8, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x80054D10: lwc1        $f10, 0x4($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80054D14: lb          $t5, 0x1D3($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X1D3);
    // 0x80054D18: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80054D1C: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80054D20: add.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f4.d + ctx->f6.d;
    // 0x80054D24: lwc1        $f4, 0x680C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X680C);
    // 0x80054D28: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80054D2C: lwc1        $f5, 0x6808($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6808);
    // 0x80054D30: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80054D34: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80054D38: lwc1        $f10, 0x18($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X18);
    // 0x80054D3C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80054D40: mul.s       $f2, $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80054D44: blez        $t5, L_80054DA0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x80054D48: nop
    
            goto L_80054DA0;
    }
    // 0x80054D48: nop

    // 0x80054D4C: lw          $t6, -0x2AC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AC0);
    // 0x80054D50: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80054D54: bne         $t6, $zero, L_80054D98
    if (ctx->r14 != 0) {
        // 0x80054D58: nop
    
            goto L_80054D98;
    }
    // 0x80054D58: nop

    // 0x80054D5C: mtc1        $zero, $f5
    ctx->f_odd[(5 - 1) * 2] = 0;
    // 0x80054D60: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80054D64: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x80054D68: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80054D6C: c.eq.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d == ctx->f6.d;
    // 0x80054D70: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80054D74: bc1t        L_80054D84
    if (c1cs) {
        // 0x80054D78: swc1        $f8, 0xB4($a1)
        MEM_W(0XB4, ctx->r5) = ctx->f8.u32l;
            goto L_80054D84;
    }
    // 0x80054D78: swc1        $f8, 0xB4($a1)
    MEM_W(0XB4, ctx->r5) = ctx->f8.u32l;
    // 0x80054D7C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80054D80: nop

L_80054D84:
    // 0x80054D84: lb          $t9, 0x1D3($a1)
    ctx->r25 = MEM_B(ctx->r5, 0X1D3);
    // 0x80054D88: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x80054D8C: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054D90: subu        $t7, $t9, $t8
    ctx->r15 = SUB32(ctx->r25, ctx->r24);
    // 0x80054D94: sb          $t7, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = ctx->r15;
L_80054D98:
    // 0x80054D98: b           L_80054DAC
    // 0x80054D9C: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
        goto L_80054DAC;
    // 0x80054D9C: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
L_80054DA0:
    // 0x80054DA0: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054DA4: sb          $zero, 0x1D3($a1)
    MEM_B(0X1D3, ctx->r5) = 0;
    // 0x80054DA8: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
L_80054DAC:
    // 0x80054DAC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x80054DB0: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80054DB4: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80054DB8: lui         $at, 0x4008
    ctx->r1 = S32(0X4008 << 16);
    // 0x80054DBC: c.lt.d      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.d < ctx->f0.d;
    // 0x80054DC0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80054DC4: bc1f        L_80054E40
    if (!c1cs) {
        // 0x80054DC8: nop
    
            goto L_80054E40;
    }
    // 0x80054DC8: nop

    // 0x80054DCC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x80054DD0: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80054DD4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054DD8: c.lt.d      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.d < ctx->f16.d;
    // 0x80054DDC: nop

    // 0x80054DE0: bc1f        L_80054E40
    if (!c1cs) {
        // 0x80054DE4: nop
    
            goto L_80054E40;
    }
    // 0x80054DE4: nop

    // 0x80054DE8: sub.d       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f16.d - ctx->f0.d;
    // 0x80054DEC: lwc1        $f5, 0x6810($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6810);
    // 0x80054DF0: lwc1        $f4, 0x6814($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6814);
    // 0x80054DF4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80054DF8: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x80054DFC: lw          $t0, -0x2AC8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AC8);
    // 0x80054E00: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80054E04: slti        $at, $t0, -0x19
    ctx->r1 = SIGNED(ctx->r8) < -0X19 ? 1 : 0;
    // 0x80054E08: beq         $at, $zero, L_80054E40
    if (ctx->r1 == 0) {
        // 0x80054E0C: cvt.s.d     $f14, $f6
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
            goto L_80054E40;
    }
    // 0x80054E0C: cvt.s.d     $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f14.fl = CVT_S_D(ctx->f6.d);
    // 0x80054E10: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x80054E14: nop

    // 0x80054E18: andi        $t1, $v0, 0x8000
    ctx->r9 = ctx->r2 & 0X8000;
    // 0x80054E1C: bne         $t1, $zero, L_80054E40
    if (ctx->r9 != 0) {
        // 0x80054E20: andi        $t4, $v0, 0x4000
        ctx->r12 = ctx->r2 & 0X4000;
            goto L_80054E40;
    }
    // 0x80054E20: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    // 0x80054E24: beq         $t4, $zero, L_80054E40
    if (ctx->r12 == 0) {
        // 0x80054E28: nop
    
            goto L_80054E40;
    }
    // 0x80054E28: nop

    // 0x80054E2C: add.s       $f10, $f12, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80054E30: swc1        $f18, 0xB8($a1)
    MEM_W(0XB8, ctx->r5) = ctx->f18.u32l;
    // 0x80054E34: swc1        $f10, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f10.u32l;
    // 0x80054E38: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054E3C: nop

L_80054E40:
    // 0x80054E40: lwc1        $f8, 0xB8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XB8);
    // 0x80054E44: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054E48: mul.s       $f4, $f8, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80054E4C: lwc1        $f11, 0x6818($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6818);
    // 0x80054E50: lwc1        $f10, 0x681C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X681C);
    // 0x80054E54: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054E58: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80054E5C: mul.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x80054E60: lwc1        $f4, 0xB4($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0XB4);
    // 0x80054E64: nop

    // 0x80054E68: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80054E6C: cvt.s.d     $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f14.fl = CVT_S_D(ctx->f8.d);
    // 0x80054E70: sub.s       $f10, $f12, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f6.fl;
    // 0x80054E74: swc1        $f10, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f10.u32l;
    // 0x80054E78: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054E7C: lwc1        $f8, 0x6824($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6824);
    // 0x80054E80: lwc1        $f9, 0x6820($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6820);
    // 0x80054E84: cvt.d.s     $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.d = CVT_D_S(ctx->f12.fl);
    // 0x80054E88: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x80054E8C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054E90: bc1f        L_80054EC0
    if (!c1cs) {
        // 0x80054E94: nop
    
            goto L_80054EC0;
    }
    // 0x80054E94: nop

    // 0x80054E98: lwc1        $f5, 0x6828($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6828);
    // 0x80054E9C: lwc1        $f4, 0x682C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X682C);
    // 0x80054EA0: nop

    // 0x80054EA4: c.lt.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d < ctx->f4.d;
    // 0x80054EA8: nop

    // 0x80054EAC: bc1f        L_80054EC0
    if (!c1cs) {
        // 0x80054EB0: nop
    
            goto L_80054EC0;
    }
    // 0x80054EB0: nop

    // 0x80054EB4: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
    // 0x80054EB8: lwc1        $f12, 0x2C($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054EBC: nop

L_80054EC0:
    // 0x80054EC0: c.lt.s      $f12, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f12.fl < ctx->f18.fl;
    // 0x80054EC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80054EC8: bc1f        L_80054EF8
    if (!c1cs) {
        // 0x80054ECC: nop
    
            goto L_80054EF8;
    }
    // 0x80054ECC: nop

    // 0x80054ED0: add.s       $f6, $f12, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x80054ED4: swc1        $f6, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f6.u32l;
    // 0x80054ED8: lwc1        $f10, 0x2C($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054EDC: nop

    // 0x80054EE0: c.lt.s      $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f18.fl < ctx->f10.fl;
    // 0x80054EE4: nop

    // 0x80054EE8: bc1f        L_80054F1C
    if (!c1cs) {
        // 0x80054EEC: nop
    
            goto L_80054F1C;
    }
    // 0x80054EEC: nop

    // 0x80054EF0: b           L_80054F1C
    // 0x80054EF4: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
        goto L_80054F1C;
    // 0x80054EF4: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
L_80054EF8:
    // 0x80054EF8: sub.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80054EFC: swc1        $f8, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f8.u32l;
    // 0x80054F00: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054F04: nop

    // 0x80054F08: c.lt.s      $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f4.fl < ctx->f18.fl;
    // 0x80054F0C: nop

    // 0x80054F10: bc1f        L_80054F1C
    if (!c1cs) {
        // 0x80054F14: nop
    
            goto L_80054F1C;
    }
    // 0x80054F14: nop

    // 0x80054F18: swc1        $f18, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f18.u32l;
L_80054F1C:
    // 0x80054F1C: lwc1        $f10, 0xC0($a1)
    ctx->f10.u32l = MEM_W(ctx->r5, 0XC0);
    // 0x80054F20: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x80054F24: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80054F28: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x80054F2C: c.eq.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d == ctx->f8.d;
    // 0x80054F30: lwc1        $f0, -0x2A94($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2A94);
    // 0x80054F34: bc1t        L_80054F50
    if (c1cs) {
        // 0x80054F38: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_80054F50;
    }
    // 0x80054F38: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80054F3C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80054F40: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80054F44: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x80054F48: mul.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x80054F4C: cvt.s.d     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f0.fl = CVT_S_D(ctx->f6.d);
L_80054F50:
    // 0x80054F50: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80054F54: lwc1        $f8, 0xB8($a1)
    ctx->f8.u32l = MEM_W(ctx->r5, 0XB8);
    // 0x80054F58: lwc1        $f11, 0x6830($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6830);
    // 0x80054F5C: lwc1        $f10, 0x6834($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6834);
    // 0x80054F60: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80054F64: c.lt.d      $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f4.d < ctx->f10.d;
    // 0x80054F68: nop

    // 0x80054F6C: bc1f        L_80054FAC
    if (!c1cs) {
        // 0x80054F70: nop
    
            goto L_80054FAC;
    }
    // 0x80054F70: nop

    // 0x80054F74: lw          $t3, -0x2AC0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AC0);
    // 0x80054F78: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80054F7C: bne         $t3, $zero, L_80054FAC
    if (ctx->r11 != 0) {
        // 0x80054F80: nop
    
            goto L_80054FAC;
    }
    // 0x80054F80: nop

    // 0x80054F84: lwc1        $f6, 0x9C($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X9C);
    // 0x80054F88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80054F8C: nop

    // 0x80054F90: div.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80054F94: lwc1        $f6, 0x54($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80054F98: mul.s       $f10, $f0, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80054F9C: lwc1        $f4, 0x2C($a1)
    ctx->f4.u32l = MEM_W(ctx->r5, 0X2C);
    // 0x80054FA0: mul.s       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x80054FA4: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80054FA8: swc1        $f10, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f10.u32l;
L_80054FAC:
    // 0x80054FAC: lwc1        $f4, 0x54($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80054FB0: lwc1        $f6, 0x20($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80054FB4: mul.s       $f8, $f0, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80054FB8: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80054FBC: swc1        $f10, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->f10.u32l;
    // 0x80054FC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80054FC4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80054FC8: jr          $ra
    // 0x80054FCC: nop

    return;
    // 0x80054FCC: nop

;}
RECOMP_FUNC void rumble_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072298: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007229C: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800722A0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800722A4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800722A8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800722AC: beq         $t6, $zero, L_800722D0
    if (ctx->r14 == 0) {
        // 0x800722B0: sb          $t6, 0x41E4($at)
        MEM_B(0X41E4, ctx->r1) = ctx->r14;
            goto L_800722D0;
    }
    // 0x800722B0: sb          $t6, 0x41E4($at)
    MEM_B(0X41E4, ctx->r1) = ctx->r14;
    // 0x800722B4: addiu       $t7, $zero, 0x79
    ctx->r15 = ADD32(0, 0X79);
    // 0x800722B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800722BC: sw          $t7, 0x41E8($at)
    MEM_W(0X41E8, ctx->r1) = ctx->r15;
    // 0x800722C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800722C4: addiu       $t8, $zero, 0xF
    ctx->r24 = ADD32(0, 0XF);
    // 0x800722C8: b           L_800722D8
    // 0x800722CC: sb          $t8, 0x41E6($at)
    MEM_B(0X41E6, ctx->r1) = ctx->r24;
        goto L_800722D8;
    // 0x800722CC: sb          $t8, 0x41E6($at)
    MEM_B(0X41E6, ctx->r1) = ctx->r24;
L_800722D0:
    // 0x800722D0: jal         0x80072708
    // 0x800722D4: nop

    rumble_kill(rdram, ctx);
        goto after_0;
    // 0x800722D4: nop

    after_0:
L_800722D8:
    // 0x800722D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800722DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800722E0: jr          $ra
    // 0x800722E4: nop

    return;
    // 0x800722E4: nop

;}
RECOMP_FUNC void hud_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ECF0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009ECF4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8009ECF8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8009ECFC: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8009ED00: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009ED04: jal         0x80066210
    // 0x8009ED08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8009ED08: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x8009ED0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009ED10: addiu       $v1, $v1, 0x6D0C
    ctx->r3 = ADD32(ctx->r3, 0X6D0C);
    // 0x8009ED14: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8009ED18: jal         0x8006652C
    // 0x8009ED1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    cam_set_layout(rdram, ctx);
        goto after_1;
    // 0x8009ED1C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8009ED20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009ED24: jal         0x8006EA90
    // 0x8009ED28: sb          $v0, 0x6D37($at)
    MEM_B(0X6D37, ctx->r1) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_2;
    // 0x8009ED28: sb          $v0, 0x6D37($at)
    MEM_B(0X6D37, ctx->r1) = ctx->r2;
    after_2:
    // 0x8009ED2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009ED30: jal         0x8000E1DC
    // 0x8009ED34: sw          $v0, 0x7184($at)
    MEM_W(0X7184, ctx->r1) = ctx->r2;
    check_if_silver_coin_race(rdram, ctx);
        goto after_3;
    // 0x8009ED34: sw          $v0, 0x7184($at)
    MEM_W(0X7184, ctx->r1) = ctx->r2;
    after_3:
    // 0x8009ED38: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009ED3C: sb          $v0, 0x7188($at)
    MEM_B(0X7188, ctx->r1) = ctx->r2;
    // 0x8009ED40: jal         0x80076C58
    // 0x8009ED44: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8009ED44: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    after_4:
    // 0x8009ED48: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009ED4C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8009ED50: addiu       $s1, $s1, 0x6CF0
    ctx->r17 = ADD32(ctx->r17, 0X6CF0);
    // 0x8009ED54: addiu       $a2, $a2, 0x6CF8
    ctx->r6 = ADD32(ctx->r6, 0X6CF8);
    // 0x8009ED58: sll         $t6, $zero, 1
    ctx->r14 = S32(0 << 1);
    // 0x8009ED5C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8009ED60: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8009ED64: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8009ED68: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8009ED6C: addiu       $s2, $zero, -0x1
    ctx->r18 = ADD32(0, -0X1);
    // 0x8009ED70: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8009ED74: beq         $s2, $t8, L_8009ED9C
    if (ctx->r18 == ctx->r24) {
        // 0x8009ED78: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8009ED9C;
    }
    // 0x8009ED78: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009ED7C: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
L_8009ED80:
    // 0x8009ED80: sll         $t0, $t9, 1
    ctx->r8 = S32(ctx->r25 << 1);
    // 0x8009ED84: addu        $t1, $v1, $t0
    ctx->r9 = ADD32(ctx->r3, ctx->r8);
    // 0x8009ED88: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8009ED8C: lh          $t2, 0x0($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X0);
    // 0x8009ED90: or          $s0, $t9, $zero
    ctx->r16 = ctx->r25 | 0;
    // 0x8009ED94: bne         $s2, $t2, L_8009ED80
    if (ctx->r18 != ctx->r10) {
        // 0x8009ED98: addiu       $t9, $s0, 0x1
        ctx->r25 = ADD32(ctx->r16, 0X1);
            goto L_8009ED80;
    }
    // 0x8009ED98: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
L_8009ED9C:
    // 0x8009ED9C: sll         $a0, $s0, 2
    ctx->r4 = S32(ctx->r16 << 2);
    // 0x8009EDA0: addu        $a0, $a0, $s0
    ctx->r4 = ADD32(ctx->r4, ctx->r16);
    // 0x8009EDA4: jal         0x80070C9C
    // 0x8009EDA8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x8009EDA8: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_5:
    // 0x8009EDAC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009EDB0: addiu       $a2, $a2, 0x6CF8
    ctx->r6 = ADD32(ctx->r6, 0X6CF8);
    // 0x8009EDB4: lw          $s0, 0x0($a2)
    ctx->r16 = MEM_W(ctx->r6, 0X0);
    // 0x8009EDB8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009EDBC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009EDC0: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x8009EDC4: addiu       $a3, $a3, 0x6CF4
    ctx->r7 = ADD32(ctx->r7, 0X6CF4);
    // 0x8009EDC8: addiu       $a0, $a0, 0x6CD8
    ctx->r4 = ADD32(ctx->r4, 0X6CD8);
    // 0x8009EDCC: addu        $t5, $t3, $v0
    ctx->r13 = ADD32(ctx->r11, ctx->r2);
    // 0x8009EDD0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
    // 0x8009EDD4: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8009EDD8: blez        $s0, L_8009EE18
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8009EDDC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8009EE18;
    }
    // 0x8009EDDC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8009EDE0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009EDE4:
    // 0x8009EDE4: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8009EDE8: nop

    // 0x8009EDEC: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8009EDF0: sb          $zero, 0x0($t7)
    MEM_B(0X0, ctx->r15) = 0;
    // 0x8009EDF4: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x8009EDF8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009EDFC: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x8009EE00: sw          $zero, 0x0($t9)
    MEM_W(0X0, ctx->r25) = 0;
    // 0x8009EE04: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x8009EE08: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8009EE0C: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8009EE10: bne         $at, $zero, L_8009EDE4
    if (ctx->r1 != 0) {
        // 0x8009EE14: nop
    
            goto L_8009EDE4;
    }
    // 0x8009EE14: nop

L_8009EE18:
    // 0x8009EE18: lw          $t1, 0x0($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X0);
    // 0x8009EE1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009EE20: lh          $a0, 0x2($t1)
    ctx->r4 = MEM_H(ctx->r9, 0X2);
    // 0x8009EE24: nop

    // 0x8009EE28: andi        $t2, $a0, 0x3FFF
    ctx->r10 = ctx->r4 & 0X3FFF;
    // 0x8009EE2C: jal         0x8007C12C
    // 0x8009EE30: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_6;
    // 0x8009EE30: or          $a0, $t2, $zero
    ctx->r4 = ctx->r10 | 0;
    after_6:
    // 0x8009EE34: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009EE38: addiu       $a3, $a3, 0x6CF4
    ctx->r7 = ADD32(ctx->r7, 0X6CF4);
    // 0x8009EE3C: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x8009EE40: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009EE44: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x8009EE48: lw          $t4, 0x0($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X0);
    // 0x8009EE4C: nop

    // 0x8009EE50: lh          $a0, 0x2E($t4)
    ctx->r4 = MEM_H(ctx->r12, 0X2E);
    // 0x8009EE54: nop

    // 0x8009EE58: andi        $t5, $a0, 0x3FFF
    ctx->r13 = ctx->r4 & 0X3FFF;
    // 0x8009EE5C: jal         0x8007C12C
    // 0x8009EE60: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_7;
    // 0x8009EE60: or          $a0, $t5, $zero
    ctx->r4 = ctx->r13 | 0;
    after_7:
    // 0x8009EE64: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009EE68: addiu       $a3, $a3, 0x6CF4
    ctx->r7 = ADD32(ctx->r7, 0X6CF4);
    // 0x8009EE6C: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x8009EE70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009EE74: sw          $v0, 0x5C($t6)
    MEM_W(0X5C, ctx->r14) = ctx->r2;
    // 0x8009EE78: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8009EE7C: nop

    // 0x8009EE80: lh          $a0, 0x10($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X10);
    // 0x8009EE84: nop

    // 0x8009EE88: andi        $t8, $a0, 0x3FFF
    ctx->r24 = ctx->r4 & 0X3FFF;
    // 0x8009EE8C: jal         0x8007C12C
    // 0x8009EE90: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_8;
    // 0x8009EE90: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_8:
    // 0x8009EE94: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009EE98: addiu       $a3, $a3, 0x6CF4
    ctx->r7 = ADD32(ctx->r7, 0X6CF4);
    // 0x8009EE9C: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x8009EEA0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8009EEA4: sw          $v0, 0x20($t9)
    MEM_W(0X20, ctx->r25) = ctx->r2;
    // 0x8009EEA8: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8009EEAC: nop

    // 0x8009EEB0: lh          $a0, 0x22($t0)
    ctx->r4 = MEM_H(ctx->r8, 0X22);
    // 0x8009EEB4: nop

    // 0x8009EEB8: andi        $t1, $a0, 0x3FFF
    ctx->r9 = ctx->r4 & 0X3FFF;
    // 0x8009EEBC: jal         0x8007C12C
    // 0x8009EEC0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    tex_load_sprite(rdram, ctx);
        goto after_9;
    // 0x8009EEC0: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_9:
    // 0x8009EEC4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8009EEC8: addiu       $a3, $a3, 0x6CF4
    ctx->r7 = ADD32(ctx->r7, 0X6CF4);
    // 0x8009EECC: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x8009EED0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EED4: sw          $v0, 0x44($t2)
    MEM_W(0X44, ctx->r10) = ctx->r2;
    // 0x8009EED8: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x8009EEDC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009EEE0: beq         $v1, $at, L_8009EEF0
    if (ctx->r3 == ctx->r1) {
        // 0x8009EEE4: ori         $a1, $zero, 0xFFFF
        ctx->r5 = 0 | 0XFFFF;
            goto L_8009EEF0;
    }
    // 0x8009EEE4: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    // 0x8009EEE8: b           L_8009EEF4
    // 0x8009EEEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8009EEF4;
    // 0x8009EEEC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009EEF0:
    // 0x8009EEF0: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_8009EEF4:
    // 0x8009EEF4: sll         $a0, $v0, 4
    ctx->r4 = S32(ctx->r2 << 4);
    // 0x8009EEF8: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8009EEFC: sll         $a0, $a0, 2
    ctx->r4 = S32(ctx->r4 << 2);
    // 0x8009EF00: subu        $a0, $a0, $v0
    ctx->r4 = SUB32(ctx->r4, ctx->r2);
    // 0x8009EF04: jal         0x80070C9C
    // 0x8009EF08: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    mempool_alloc_safe(rdram, ctx);
        goto after_10;
    // 0x8009EF08: sll         $a0, $a0, 5
    ctx->r4 = S32(ctx->r4 << 5);
    after_10:
    // 0x8009EF0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EF10: addiu       $v1, $v1, 0x6CE0
    ctx->r3 = ADD32(ctx->r3, 0X6CE0);
    // 0x8009EF14: addiu       $t4, $v0, 0x760
    ctx->r12 = ADD32(ctx->r2, 0X760);
    // 0x8009EF18: addiu       $t6, $t4, 0x760
    ctx->r14 = ADD32(ctx->r12, 0X760);
    // 0x8009EF1C: addiu       $t8, $t6, 0x760
    ctx->r24 = ADD32(ctx->r14, 0X760);
    // 0x8009EF20: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8009EF24: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8009EF28: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x8009EF2C: jal         0x8009F034
    // 0x8009EF30: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    hud_init_element(rdram, ctx);
        goto after_11;
    // 0x8009EF30: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    after_11:
    // 0x8009EF34: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF38: sb          $zero, 0x6D64($at)
    MEM_B(0X6D64, ctx->r1) = 0;
    // 0x8009EF3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF40: sw          $zero, 0x6D6C($at)
    MEM_W(0X6D6C, ctx->r1) = 0;
    // 0x8009EF44: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF48: sh          $zero, 0x6D48($at)
    MEM_H(0X6D48, ctx->r1) = 0;
    // 0x8009EF4C: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
    // 0x8009EF50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF54: sb          $v0, 0x6D66($at)
    MEM_B(0X6D66, ctx->r1) = ctx->r2;
    // 0x8009EF58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF5C: sb          $zero, 0x6D65($at)
    MEM_B(0X6D65, ctx->r1) = 0;
    // 0x8009EF60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF64: sb          $v0, 0x6D67($at)
    MEM_B(0X6D67, ctx->r1) = ctx->r2;
    // 0x8009EF68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF6C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8009EF70: sb          $t9, 0x6D69($at)
    MEM_B(0X6D69, ctx->r1) = ctx->r25;
    // 0x8009EF74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF78: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8009EF7C: sb          $t0, 0x6D68($at)
    MEM_B(0X6D68, ctx->r1) = ctx->r8;
    // 0x8009EF80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF84: sb          $zero, 0x6D70($at)
    MEM_B(0X6D70, ctx->r1) = 0;
    // 0x8009EF88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF8C: sh          $zero, 0x6D7C($at)
    MEM_H(0X6D7C, ctx->r1) = 0;
    // 0x8009EF90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF94: sw          $zero, 0x6D74($at)
    MEM_W(0X6D74, ctx->r1) = 0;
    // 0x8009EF98: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EF9C: sw          $zero, 0x6D3C($at)
    MEM_W(0X6D3C, ctx->r1) = 0;
    // 0x8009EFA0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EFA4: sw          $zero, 0x6D44($at)
    MEM_W(0X6D44, ctx->r1) = 0;
    // 0x8009EFA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009EFAC: sb          $zero, 0x6CD3($at)
    MEM_B(0X6CD3, ctx->r1) = 0;
    // 0x8009EFB0: jal         0x8001E29C
    // 0x8009EFB4: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    get_misc_asset(rdram, ctx);
        goto after_12;
    // 0x8009EFB4: addiu       $a0, $zero, 0x3A
    ctx->r4 = ADD32(0, 0X3A);
    after_12:
    // 0x8009EFB8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009EFBC: addiu       $v1, $v1, 0x7194
    ctx->r3 = ADD32(ctx->r3, 0X7194);
    // 0x8009EFC0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8009EFC4: jal         0x8007F1E8
    // 0x8009EFC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    func_8007F1E8(rdram, ctx);
        goto after_13;
    // 0x8009EFC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_13:
    // 0x8009EFCC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009EFD0: jal         0x80004A60
    // 0x8009EFD4: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_14;
    // 0x8009EFD4: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_14:
    // 0x8009EFD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8009EFDC: jal         0x80004A60
    // 0x8009EFE0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_15;
    // 0x8009EFE0: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_15:
    // 0x8009EFE4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009EFE8: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009EFEC: addiu       $s1, $s1, 0x2790
    ctx->r17 = ADD32(ctx->r17, 0X2790);
    // 0x8009EFF0: addiu       $s0, $s0, 0x2770
    ctx->r16 = ADD32(ctx->r16, 0X2770);
L_8009EFF4:
    // 0x8009EFF4: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8009EFF8: sb          $zero, 0x2($s0)
    MEM_B(0X2, ctx->r16) = 0;
    // 0x8009EFFC: sb          $zero, 0x3($s0)
    MEM_B(0X3, ctx->r16) = 0;
    // 0x8009F000: beq         $a0, $zero, L_8009F010
    if (ctx->r4 == 0) {
        // 0x8009F004: sb          $s2, 0xC($s0)
        MEM_B(0XC, ctx->r16) = ctx->r18;
            goto L_8009F010;
    }
    // 0x8009F004: sb          $s2, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r18;
    // 0x8009F008: jal         0x8000488C
    // 0x8009F00C: nop

    sndp_stop(rdram, ctx);
        goto after_16;
    // 0x8009F00C: nop

    after_16:
L_8009F010:
    // 0x8009F010: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8009F014: bne         $s0, $s1, L_8009EFF4
    if (ctx->r16 != ctx->r17) {
        // 0x8009F018: nop
    
            goto L_8009EFF4;
    }
    // 0x8009F018: nop

    // 0x8009F01C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8009F020: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009F024: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8009F028: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8009F02C: jr          $ra
    // 0x8009F030: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8009F030: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void audspat_jingle_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80008140: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80008144: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80008148: jal         0x800018E0
    // 0x8000814C: nop

    music_jingle_stop(rdram, ctx);
        goto after_0;
    // 0x8000814C: nop

    after_0:
    // 0x80008150: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80008154: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80008158: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000815C: sb          $t6, -0x53E8($at)
    MEM_B(-0X53E8, ctx->r1) = ctx->r14;
    // 0x80008160: jr          $ra
    // 0x80008164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80008164: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void normalise_time(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C8B4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8000C8B8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8000C8BC: nop

    // 0x8000C8C0: bne         $t6, $zero, L_8000C8D0
    if (ctx->r14 != 0) {
        // 0x8000C8C4: nop
    
            goto L_8000C8D0;
    }
    // 0x8000C8C4: nop

    // 0x8000C8C8: bgez        $a0, L_8000C8D8
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8000C8CC: sll         $v0, $a0, 2
        ctx->r2 = S32(ctx->r4 << 2);
            goto L_8000C8D8;
    }
    // 0x8000C8CC: sll         $v0, $a0, 2
    ctx->r2 = S32(ctx->r4 << 2);
L_8000C8D0:
    // 0x8000C8D0: jr          $ra
    // 0x8000C8D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x8000C8D4: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8000C8D8:
    // 0x8000C8D8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8000C8DC: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8000C8E0: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x8000C8E4: mflo        $v0
    ctx->r2 = lo;
    // 0x8000C8E8: nop

    // 0x8000C8EC: nop

    // 0x8000C8F0: jr          $ra
    // 0x8000C8F4: nop

    return;
    // 0x8000C8F4: nop

;}
RECOMP_FUNC void set_temp_model_transforms(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012F94: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80012F98: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80012F9C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80012FA0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80012FA4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80012FA8: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80012FAC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80012FB0: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x80012FB4: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80012FB8: bne         $t7, $zero, L_8001346C
    if (ctx->r15 != 0) {
        // 0x80012FBC: mov.s       $f14, $f2
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
            goto L_8001346C;
    }
    // 0x80012FBC: mov.s       $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    ctx->f14.fl = ctx->f2.fl;
    // 0x80012FC0: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80012FC4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80012FC8: lb          $t9, 0x54($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X54);
    // 0x80012FCC: nop

    // 0x80012FD0: bne         $t9, $at, L_8001344C
    if (ctx->r25 != ctx->r1) {
        // 0x80012FD4: nop
    
            goto L_8001344C;
    }
    // 0x80012FD4: nop

    // 0x80012FD8: lw          $t2, 0x64($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X64);
    // 0x80012FDC: addiu       $t3, $zero, 0x1E
    ctx->r11 = ADD32(0, 0X1E);
    // 0x80012FE0: lh          $v0, 0x206($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X206);
    // 0x80012FE4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80012FE8: blez        $v0, L_80013024
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80012FEC: sb          $t3, 0x201($t2)
        MEM_B(0X201, ctx->r10) = ctx->r11;
            goto L_80013024;
    }
    // 0x80012FEC: sb          $t3, 0x201($t2)
    MEM_B(0X201, ctx->r10) = ctx->r11;
    // 0x80012FF0: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x80012FF4: lwc1        $f0, 0x5554($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5554);
    // 0x80012FF8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80012FFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013000: lwc1        $f8, 0x5558($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5558);
    // 0x80013004: nop

    // 0x80013008: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8001300C: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80013010: c.lt.s      $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f14.fl < ctx->f0.fl;
    // 0x80013014: nop

    // 0x80013018: bc1f        L_80013024
    if (!c1cs) {
        // 0x8001301C: nop
    
            goto L_80013024;
    }
    // 0x8001301C: nop

    // 0x80013020: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
L_80013024:
    // 0x80013024: lh          $t4, 0x0($t2)
    ctx->r12 = MEM_H(ctx->r10, 0X0);
    // 0x80013028: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001302C: beq         $t4, $at, L_8001304C
    if (ctx->r12 == ctx->r1) {
        // 0x80013030: nop
    
            goto L_8001304C;
    }
    // 0x80013030: nop

    // 0x80013034: lb          $t5, 0x1D8($t2)
    ctx->r13 = MEM_B(ctx->r10, 0X1D8);
    // 0x80013038: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8001303C: beq         $t5, $zero, L_8001304C
    if (ctx->r13 == 0) {
        // 0x80013040: nop
    
            goto L_8001304C;
    }
    // 0x80013040: nop

    // 0x80013044: b           L_80013274
    // 0x80013048: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_80013274;
    // 0x80013048: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8001304C:
    // 0x8001304C: lh          $t6, 0x48($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X48);
    // 0x80013050: addiu       $at, $zero, 0x3A
    ctx->r1 = ADD32(0, 0X3A);
    // 0x80013054: bne         $t6, $at, L_80013064
    if (ctx->r14 != ctx->r1) {
        // 0x80013058: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80013064;
    }
    // 0x80013058: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8001305C: b           L_80013274
    // 0x80013060: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
        goto L_80013274;
    // 0x80013060: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_80013064:
    // 0x80013064: lb          $t1, 0x1D6($t2)
    ctx->r9 = MEM_B(ctx->r10, 0X1D6);
    // 0x80013068: nop

    // 0x8001306C: slti        $at, $t1, 0x3
    ctx->r1 = SIGNED(ctx->r9) < 0X3 ? 1 : 0;
    // 0x80013070: bne         $at, $zero, L_80013080
    if (ctx->r1 != 0) {
        // 0x80013074: addiu       $a0, $t1, 0x5
        ctx->r4 = ADD32(ctx->r9, 0X5);
            goto L_80013080;
    }
    // 0x80013074: addiu       $a0, $t1, 0x5
    ctx->r4 = ADD32(ctx->r9, 0X5);
    // 0x80013078: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8001307C: addiu       $a0, $t1, 0x5
    ctx->r4 = ADD32(ctx->r9, 0X5);
L_80013080:
    // 0x80013080: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80013084: sw          $zero, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = 0;
    // 0x80013088: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x8001308C: jal         0x8001E29C
    // 0x80013090: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x80013090: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x80013094: jal         0x80066210
    // 0x80013098: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    cam_get_viewport_layout(rdram, ctx);
        goto after_1;
    // 0x80013098: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001309C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800130A0: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800130A4: addu        $t7, $t7, $v0
    ctx->r15 = ADD32(ctx->r15, ctx->r2);
    // 0x800130A8: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800130AC: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x800130B0: jal         0x80066220
    // 0x800130B4: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    get_current_viewport(rdram, ctx);
        goto after_2;
    // 0x800130B4: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    after_2:
    // 0x800130B8: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x800130BC: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800130C0: lh          $t8, 0x0($t2)
    ctx->r24 = MEM_H(ctx->r10, 0X0);
    // 0x800130C4: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800130C8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800130CC: beq         $v0, $t8, L_800130D8
    if (ctx->r2 == ctx->r24) {
        // 0x800130D0: nop
    
            goto L_800130D8;
    }
    // 0x800130D0: nop

    // 0x800130D4: addiu       $a1, $a1, 0x5
    ctx->r5 = ADD32(ctx->r5, 0X5);
L_800130D8:
    // 0x800130D8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800130DC: lwc1        $f0, 0x30($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X30);
    // 0x800130E0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800130E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800130E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800130EC: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x800130F0: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x800130F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800130F8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800130FC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80013100: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80013104: sra         $t3, $v1, 3
    ctx->r11 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80013108: bc1f        L_80013118
    if (!c1cs) {
        // 0x8001310C: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80013118;
    }
    // 0x8001310C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x80013110: b           L_80013134
    // 0x80013114: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
        goto L_80013134;
    // 0x80013114: mov.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    ctx->f0.fl = ctx->f12.fl;
L_80013118:
    // 0x80013118: lwc1        $f2, 0x555C($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X555C);
    // 0x8001311C: nop

    // 0x80013120: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80013124: nop

    // 0x80013128: bc1f        L_80013134
    if (!c1cs) {
        // 0x8001312C: nop
    
            goto L_80013134;
    }
    // 0x8001312C: nop

    // 0x80013130: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_80013134:
    // 0x80013134: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013138: lwc1        $f18, 0x5560($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5560);
    // 0x8001313C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80013140: div.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f18.fl);
    // 0x80013144: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80013148: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8001314C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80013150: add.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f4.fl;
    // 0x80013154: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80013158: swc1        $f8, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f8.u32l;
    // 0x8001315C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x80013160: sw          $t2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r10;
    // 0x80013164: sw          $t1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r9;
    // 0x80013168: sw          $a1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r5;
    // 0x8001316C: jal         0x8001E29C
    // 0x80013170: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    get_misc_asset(rdram, ctx);
        goto after_3;
    // 0x80013170: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    after_3:
    // 0x80013174: lw          $t2, 0x24($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X24);
    // 0x80013178: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8001317C: lb          $t4, 0x3($t2)
    ctx->r12 = MEM_B(ctx->r10, 0X3);
    // 0x80013180: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x80013184: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013188: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8001318C: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80013190: lwc1        $f18, 0x0($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X0);
    // 0x80013194: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x80013198: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x8001319C: lw          $t1, 0x4C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X4C);
    // 0x800131A0: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800131A4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800131A8: nop

    // 0x800131AC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800131B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800131B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800131B8: nop

    // 0x800131BC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800131C0: mfc1        $v1, $f6
    ctx->r3 = (int32_t)ctx->f6.u32l;
    // 0x800131C4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800131C8: slti        $at, $v1, -0x32
    ctx->r1 = SIGNED(ctx->r3) < -0X32 ? 1 : 0;
    // 0x800131CC: beq         $at, $zero, L_800131DC
    if (ctx->r1 == 0) {
        // 0x800131D0: sra         $t8, $v1, 1
        ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
            goto L_800131DC;
    }
    // 0x800131D0: sra         $t8, $v1, 1
    ctx->r24 = S32(SIGNED(ctx->r3) >> 1);
    // 0x800131D4: b           L_80013274
    // 0x800131D8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
        goto L_80013274;
    // 0x800131D8: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
L_800131DC:
    // 0x800131DC: bgez        $t8, L_800131E8
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800131E0: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800131E8;
    }
    // 0x800131E0: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800131E4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800131E8:
    // 0x800131E8: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x800131EC: nop

    // 0x800131F0: slt         $at, $v1, $t9
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800131F4: beq         $at, $zero, L_80013204
    if (ctx->r1 == 0) {
        // 0x800131F8: nop
    
            goto L_80013204;
    }
    // 0x800131F8: nop

    // 0x800131FC: b           L_80013274
    // 0x80013200: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_80013274;
    // 0x80013200: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80013204:
    // 0x80013204: lbu         $t3, 0x1($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0X1);
    // 0x80013208: nop

    // 0x8001320C: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80013210: beq         $at, $zero, L_80013220
    if (ctx->r1 == 0) {
        // 0x80013214: nop
    
            goto L_80013220;
    }
    // 0x80013214: nop

    // 0x80013218: b           L_80013274
    // 0x8001321C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
        goto L_80013274;
    // 0x8001321C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80013220:
    // 0x80013220: lbu         $t4, 0x2($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X2);
    // 0x80013224: nop

    // 0x80013228: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8001322C: beq         $at, $zero, L_8001323C
    if (ctx->r1 == 0) {
        // 0x80013230: nop
    
            goto L_8001323C;
    }
    // 0x80013230: nop

    // 0x80013234: b           L_80013274
    // 0x80013238: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
        goto L_80013274;
    // 0x80013238: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
L_8001323C:
    // 0x8001323C: lbu         $t5, 0x3($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0X3);
    // 0x80013240: nop

    // 0x80013244: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x80013248: beq         $at, $zero, L_80013258
    if (ctx->r1 == 0) {
        // 0x8001324C: nop
    
            goto L_80013258;
    }
    // 0x8001324C: nop

    // 0x80013250: b           L_80013274
    // 0x80013254: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
        goto L_80013274;
    // 0x80013254: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_80013258:
    // 0x80013258: lbu         $t6, 0x4($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X4);
    // 0x8001325C: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80013260: slt         $at, $v1, $t6
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80013264: beq         $at, $zero, L_80013274
    if (ctx->r1 == 0) {
        // 0x80013268: nop
    
            goto L_80013274;
    }
    // 0x80013268: nop

    // 0x8001326C: b           L_80013274
    // 0x80013270: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
        goto L_80013274;
    // 0x80013270: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
L_80013274:
    // 0x80013274: lw          $a1, 0x68($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X68);
    // 0x80013278: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001327C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80013280: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x80013284: bne         $t7, $zero, L_8001329C
    if (ctx->r15 != 0) {
        // 0x80013288: nop
    
            goto L_8001329C;
    }
    // 0x80013288: nop

L_8001328C:
    // 0x8001328C: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x80013290: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80013294: beq         $t8, $zero, L_8001328C
    if (ctx->r24 == 0) {
        // 0x80013298: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8001328C;
    }
    // 0x80013298: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8001329C:
    // 0x8001329C: lw          $t9, 0x40($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X40);
    // 0x800132A0: slt         $at, $t0, $a0
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800132A4: lb          $v1, 0x55($t9)
    ctx->r3 = MEM_B(ctx->r25, 0X55);
    // 0x800132A8: nop

    // 0x800132AC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800132B0: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800132B4: addu        $v0, $a1, $t3
    ctx->r2 = ADD32(ctx->r5, ctx->r11);
    // 0x800132B8: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x800132BC: nop

    // 0x800132C0: bne         $t4, $zero, L_800132D8
    if (ctx->r12 != 0) {
        // 0x800132C4: nop
    
            goto L_800132D8;
    }
    // 0x800132C4: nop

L_800132C8:
    // 0x800132C8: lw          $t5, -0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, -0X4);
    // 0x800132CC: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x800132D0: beq         $t5, $zero, L_800132C8
    if (ctx->r13 == 0) {
        // 0x800132D4: addiu       $v0, $v0, -0x4
        ctx->r2 = ADD32(ctx->r2, -0X4);
            goto L_800132C8;
    }
    // 0x800132D4: addiu       $v0, $v0, -0x4
    ctx->r2 = ADD32(ctx->r2, -0X4);
L_800132D8:
    // 0x800132D8: beq         $at, $zero, L_800132E4
    if (ctx->r1 == 0) {
        // 0x800132DC: lui         $a3, 0x81
        ctx->r7 = S32(0X81 << 16);
            goto L_800132E4;
    }
    // 0x800132DC: lui         $a3, 0x81
    ctx->r7 = S32(0X81 << 16);
    // 0x800132E0: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
L_800132E4:
    // 0x800132E4: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800132E8: beq         $at, $zero, L_800132F4
    if (ctx->r1 == 0) {
        // 0x800132EC: lui         $a2, 0x1
        ctx->r6 = S32(0X1 << 16);
            goto L_800132F4;
    }
    // 0x800132EC: lui         $a2, 0x1
    ctx->r6 = S32(0X1 << 16);
    // 0x800132F0: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
L_800132F4:
    extern void dkr_apply_maximum_racer_detail(uint8_t*, recomp_context*); dkr_apply_maximum_racer_detail(rdram, ctx);
    // 0x800132F4: lw          $v0, 0x54($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X54);
    // 0x800132F8: sb          $t0, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r8;
    // 0x800132FC: beq         $v0, $zero, L_80013334
    if (ctx->r2 == 0) {
        // 0x80013300: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80013334;
    }
    // 0x80013300: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80013304: lwc1        $f8, 0x0($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80013308: lwc1        $f10, 0x5564($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5564);
    // 0x8001330C: nop

    // 0x80013310: c.lt.s      $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f8.fl < ctx->f10.fl;
    // 0x80013314: nop

    // 0x80013318: bc1f        L_80013334
    if (!c1cs) {
        // 0x8001331C: nop
    
            goto L_80013334;
    }
    // 0x8001331C: nop

    // 0x80013320: lbu         $t6, 0x20A($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X20A);
    // 0x80013324: nop

    // 0x80013328: ori         $t7, $t6, 0x40
    ctx->r15 = ctx->r14 | 0X40;
    // 0x8001332C: b           L_80013344
    // 0x80013330: sb          $t7, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r15;
        goto L_80013344;
    // 0x80013330: sb          $t7, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r15;
L_80013334:
    // 0x80013334: lbu         $t8, 0x20A($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X20A);
    // 0x80013338: nop

    // 0x8001333C: andi        $t9, $t8, 0xFFBF
    ctx->r25 = ctx->r24 & 0XFFBF;
    // 0x80013340: sb          $t9, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r25;
L_80013344:
    // 0x80013344: lb          $t4, 0x3A($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X3A);
    // 0x80013348: lw          $t3, 0x68($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X68);
    // 0x8001334C: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80013350: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80013354: lbu         $v0, 0x20A($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X20A);
    // 0x80013358: lw          $v1, 0x0($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X0);
    // 0x8001335C: andi        $t0, $v0, 0xF
    ctx->r8 = ctx->r2 & 0XF;
    // 0x80013360: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x80013364: beq         $t0, $zero, L_800133BC
    if (ctx->r8 == 0) {
        // 0x80013368: andi        $t7, $v0, 0x80
        ctx->r15 = ctx->r2 & 0X80;
            goto L_800133BC;
    }
    // 0x80013368: andi        $t7, $v0, 0x80
    ctx->r15 = ctx->r2 & 0X80;
    // 0x8001336C: beq         $t7, $zero, L_80013388
    if (ctx->r15 == 0) {
        // 0x80013370: addiu       $t0, $t0, -0x1
        ctx->r8 = ADD32(ctx->r8, -0X1);
            goto L_80013388;
    }
    // 0x80013370: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x80013374: andi        $t8, $v0, 0xFFEF
    ctx->r24 = ctx->r2 & 0XFFEF;
    // 0x80013378: ori         $t9, $t8, 0x20
    ctx->r25 = ctx->r24 | 0X20;
    // 0x8001337C: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x80013380: b           L_800133BC
    // 0x80013384: sb          $t9, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r25;
        goto L_800133BC;
    // 0x80013384: sb          $t9, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r25;
L_80013388:
    // 0x80013388: andi        $t4, $v0, 0x40
    ctx->r12 = ctx->r2 & 0X40;
    // 0x8001338C: beq         $t4, $zero, L_800133A8
    if (ctx->r12 == 0) {
        // 0x80013390: andi        $t6, $v0, 0x20
        ctx->r14 = ctx->r2 & 0X20;
            goto L_800133A8;
    }
    // 0x80013390: andi        $t6, $v0, 0x20
    ctx->r14 = ctx->r2 & 0X20;
    // 0x80013394: andi        $t3, $v0, 0xFFDF
    ctx->r11 = ctx->r2 & 0XFFDF;
    // 0x80013398: ori         $t5, $t3, 0x10
    ctx->r13 = ctx->r11 | 0X10;
    // 0x8001339C: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x800133A0: b           L_800133BC
    // 0x800133A4: sb          $t5, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r13;
        goto L_800133BC;
    // 0x800133A4: sb          $t5, 0x20A($t2)
    MEM_B(0X20A, ctx->r10) = ctx->r13;
L_800133A8:
    // 0x800133A8: beq         $t6, $zero, L_800133B8
    if (ctx->r14 == 0) {
        // 0x800133AC: nop
    
            goto L_800133B8;
    }
    // 0x800133AC: nop

    // 0x800133B0: b           L_800133BC
    // 0x800133B4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
        goto L_800133BC;
    // 0x800133B4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800133B8:
    // 0x800133B8: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
L_800133BC:
    // 0x800133BC: lh          $a0, 0x28($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X28);
    // 0x800133C0: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x800133C4: blez        $a0, L_80013408
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800133C8: or          $t0, $t7, $zero
        ctx->r8 = ctx->r15 | 0;
            goto L_80013408;
    }
    // 0x800133C8: or          $t0, $t7, $zero
    ctx->r8 = ctx->r15 | 0;
    // 0x800133CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800133D0:
    // 0x800133D0: lw          $t8, 0x38($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X38);
    // 0x800133D4: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800133D8: addu        $v1, $t8, $v0
    ctx->r3 = ADD32(ctx->r24, ctx->r2);
    // 0x800133DC: lw          $t9, 0x8($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X8);
    // 0x800133E0: nop

    // 0x800133E4: and         $t4, $t9, $a3
    ctx->r12 = ctx->r25 & ctx->r7;
    // 0x800133E8: bne         $a2, $t4, L_80013400
    if (ctx->r6 != ctx->r12) {
        // 0x800133EC: slt         $at, $t1, $a0
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80013400;
    }
    // 0x800133EC: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800133F0: sb          $t0, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r8;
    // 0x800133F4: lh          $a0, 0x28($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X28);
    // 0x800133F8: nop

    // 0x800133FC: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
L_80013400:
    // 0x80013400: bne         $at, $zero, L_800133D0
    if (ctx->r1 != 0) {
        // 0x80013404: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800133D0;
    }
    // 0x80013404: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_80013408:
    // 0x80013408: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001340C: lwc1        $f18, 0x78($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X78);
    // 0x80013410: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80013414: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x80013418: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8001341C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
    // 0x80013420: lwc1        $f8, 0x7C($t2)
    ctx->f8.u32l = MEM_W(ctx->r10, 0X7C);
    // 0x80013424: nop

    // 0x80013428: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001342C: swc1        $f10, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f10.u32l;
    // 0x80013430: lwc1        $f18, 0x80($t2)
    ctx->f18.u32l = MEM_W(ctx->r10, 0X80);
    // 0x80013434: nop

    // 0x80013438: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8001343C: swc1        $f4, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f4.u32l;
    // 0x80013440: lwc1        $f0, 0x8C($t2)
    ctx->f0.u32l = MEM_W(ctx->r10, 0X8C);
    // 0x80013444: b           L_8001346C
    // 0x80013448: nop

        goto L_8001346C;
    // 0x80013448: nop

L_8001344C:
    // 0x8001344C: lh          $t3, 0x48($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X48);
    // 0x80013450: addiu       $at, $zero, 0x6D
    ctx->r1 = ADD32(0, 0X6D);
    // 0x80013454: bne         $t3, $at, L_8001346C
    if (ctx->r11 != ctx->r1) {
        // 0x80013458: nop
    
            goto L_8001346C;
    }
    // 0x80013458: nop

    // 0x8001345C: lw          $t5, 0x64($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X64);
    // 0x80013460: nop

    // 0x80013464: lwc1        $f0, 0x30($t5)
    ctx->f0.u32l = MEM_W(ctx->r13, 0X30);
    // 0x80013468: nop

L_8001346C:
    // 0x8001346C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80013470: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80013474: swc1        $f0, -0x52D8($at)
    MEM_W(-0X52D8, ctx->r1) = ctx->f0.u32l;
    // 0x80013478: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001347C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80013480: swc1        $f14, -0x52D0($at)
    MEM_W(-0X52D0, ctx->r1) = ctx->f14.u32l;
    // 0x80013484: jr          $ra
    // 0x80013488: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80013488: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void default_alloc_displaylist_heap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EFDC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006EFE0: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8006EFE4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006EFE8: lw          $t5, -0x2C34($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2C34);
    // 0x8006EFEC: lw          $t9, -0x2C44($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C44);
    // 0x8006EFF0: lw          $t7, -0x2C14($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C14);
    // 0x8006EFF4: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8006EFF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EFFC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006F000: lw          $t2, -0x2C24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2C24);
    // 0x8006F004: sw          $t6, 0x350C($at)
    MEM_W(0X350C, ctx->r1) = ctx->r14;
    // 0x8006F008: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006F00C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8006F010: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8006F014: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8006F018: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8006F01C: sll         $t3, $t2, 6
    ctx->r11 = S32(ctx->r10 << 6);
    // 0x8006F020: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006F024: addu        $t4, $t1, $t3
    ctx->r12 = ADD32(ctx->r9, ctx->r11);
    // 0x8006F028: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8006F02C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006F030: addu        $a0, $t4, $t6
    ctx->r4 = ADD32(ctx->r12, ctx->r14);
    // 0x8006F034: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8006F038: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8006F03C: jal         0x80070C9C
    // 0x8006F040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8006F040: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x8006F044: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006F048: addiu       $v1, $v1, 0x11F0
    ctx->r3 = ADD32(ctx->r3, 0X11F0);
    // 0x8006F04C: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8006F050: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8006F054: lw          $t7, -0x2C44($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2C44);
    // 0x8006F058: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x8006F05C: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8006F060: lw          $t2, -0x2C24($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2C24);
    // 0x8006F064: lw          $t5, -0x2C34($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2C34);
    // 0x8006F068: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8006F06C: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8006F070: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F074: sw          $t0, 0x1200($at)
    MEM_W(0X1200, ctx->r1) = ctx->r8;
    // 0x8006F078: sll         $t1, $t2, 6
    ctx->r9 = S32(ctx->r10 << 6);
    // 0x8006F07C: sll         $t4, $t5, 2
    ctx->r12 = S32(ctx->r13 << 2);
    // 0x8006F080: addu        $t3, $t1, $t0
    ctx->r11 = ADD32(ctx->r9, ctx->r8);
    // 0x8006F084: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F088: addu        $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006F08C: sw          $t3, 0x1210($at)
    MEM_W(0X1210, ctx->r1) = ctx->r11;
    // 0x8006F090: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x8006F094: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8006F098: addu        $t6, $t4, $t3
    ctx->r14 = ADD32(ctx->r12, ctx->r11);
    // 0x8006F09C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0A0: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8006F0A4: sw          $t6, 0x1220($at)
    MEM_W(0X1220, ctx->r1) = ctx->r14;
    // 0x8006F0A8: jal         0x80070C9C
    // 0x8006F0AC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8006F0AC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_1:
    // 0x8006F0B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F0B4: lw          $a0, -0x2C44($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2C44);
    // 0x8006F0B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8006F0BC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8006F0C0: lw          $a2, -0x2C34($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X2C34);
    // 0x8006F0C4: lw          $a1, -0x2C24($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2C24);
    // 0x8006F0C8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006F0CC: addiu       $v1, $v1, 0x11F0
    ctx->r3 = ADD32(ctx->r3, 0X11F0);
    // 0x8006F0D0: sll         $t7, $a0, 3
    ctx->r15 = S32(ctx->r4 << 3);
    // 0x8006F0D4: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8006F0D8: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x8006F0DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0E0: sw          $t8, 0x1204($at)
    MEM_W(0X1204, ctx->r1) = ctx->r24;
    // 0x8006F0E4: sll         $t0, $a2, 2
    ctx->r8 = S32(ctx->r6 << 2);
    // 0x8006F0E8: sll         $t2, $a1, 6
    ctx->r10 = S32(ctx->r5 << 6);
    // 0x8006F0EC: addu        $t1, $t2, $t8
    ctx->r9 = ADD32(ctx->r10, ctx->r24);
    // 0x8006F0F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F0F4: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x8006F0F8: sw          $t1, 0x1214($at)
    MEM_W(0X1214, ctx->r1) = ctx->r9;
    // 0x8006F0FC: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x8006F100: addu        $t5, $t0, $t1
    ctx->r13 = ADD32(ctx->r8, ctx->r9);
    // 0x8006F104: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F108: sw          $t5, 0x1224($at)
    MEM_W(0X1224, ctx->r1) = ctx->r13;
    // 0x8006F10C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F110: sw          $a0, 0x3528($at)
    MEM_W(0X3528, ctx->r1) = ctx->r4;
    // 0x8006F114: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F118: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8006F11C: lw          $t4, -0x2C14($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X2C14);
    // 0x8006F120: sw          $a1, 0x352C($at)
    MEM_W(0X352C, ctx->r1) = ctx->r5;
    // 0x8006F124: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F128: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006F12C: sw          $t4, 0x3530($at)
    MEM_W(0X3530, ctx->r1) = ctx->r12;
    // 0x8006F130: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006F134: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006F138: jr          $ra
    // 0x8006F13C: sw          $a2, 0x3534($at)
    MEM_W(0X3534, ctx->r1) = ctx->r6;
    return;
    // 0x8006F13C: sw          $a2, 0x3534($at)
    MEM_W(0X3534, ctx->r1) = ctx->r6;
;}
RECOMP_FUNC void menu_missing_controller(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800829F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800829FC: addiu       $v0, $v0, -0xB94
    ctx->r2 = ADD32(ctx->r2, -0XB94);
    // 0x80082A00: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80082A04: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082A08: addu        $t7, $t6, $a1
    ctx->r15 = ADD32(ctx->r14, ctx->r5);
    // 0x80082A0C: andi        $t9, $t7, 0x10
    ctx->r25 = ctx->r15 & 0X10;
    // 0x80082A10: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082A14: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80082A18: beq         $t9, $zero, L_80082A9C
    if (ctx->r25 == 0) {
        // 0x80082A1C: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80082A9C;
    }
    // 0x80082A1C: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80082A20: jal         0x8009EB20
    // 0x80082A24: nop

    get_language(rdram, ctx);
        goto after_0;
    // 0x80082A24: nop

    after_0:
    // 0x80082A28: jal         0x8007F900
    // 0x80082A2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    load_menu_text(rdram, ctx);
        goto after_1;
    // 0x80082A2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80082A30: jal         0x800C42EC
    // 0x80082A34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_text_font(rdram, ctx);
        goto after_2;
    // 0x80082A34: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80082A38: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
    // 0x80082A3C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80082A40: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80082A44: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80082A48: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80082A4C: jal         0x800C4384
    // 0x80082A50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x80082A50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_3:
    // 0x80082A54: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082A58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082A5C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80082A60: jal         0x800C43CC
    // 0x80082A64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_4;
    // 0x80082A64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_4:
    // 0x80082A68: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80082A6C: lw          $t1, 0x300($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X300);
    // 0x80082A70: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80082A74: bne         $t1, $zero, L_80082A80
    if (ctx->r9 != 0) {
        // 0x80082A78: addiu       $a2, $zero, 0xD0
        ctx->r6 = ADD32(0, 0XD0);
            goto L_80082A80;
    }
    // 0x80082A78: addiu       $a2, $zero, 0xD0
    ctx->r6 = ADD32(0, 0XD0);
    // 0x80082A7C: addiu       $a2, $zero, 0xEA
    ctx->r6 = ADD32(0, 0XEA);
L_80082A80:
    // 0x80082A80: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80082A84: lw          $t2, -0xB60($t2)
    ctx->r10 = MEM_W(ctx->r10, -0XB60);
    // 0x80082A88: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x80082A8C: lw          $a3, 0x25C($t2)
    ctx->r7 = MEM_W(ctx->r10, 0X25C);
    // 0x80082A90: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80082A94: jal         0x800C4440
    // 0x80082A98: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    draw_text(rdram, ctx);
        goto after_5;
    // 0x80082A98: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    after_5:
L_80082A9C:
    // 0x80082A9C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80082AA0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80082AA4: jr          $ra
    // 0x80082AA8: nop

    return;
    // 0x80082AA8: nop

;}
RECOMP_FUNC void get_balloon_cutscene_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE54: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AE58: lw          $v0, -0x5238($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5238);
    // 0x8001AE5C: jr          $ra
    // 0x8001AE60: nop

    return;
    // 0x8001AE60: nop

;}
RECOMP_FUNC void menu_trophy_race_round_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009859C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800985A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800985A4: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800985A8: jal         0x8001E29C
    // 0x800985AC: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_0;
    // 0x800985AC: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_0:
    // 0x800985B0: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800985B4: addiu       $a3, $a3, 0x980
    ctx->r7 = ADD32(ctx->r7, 0X980);
    // 0x800985B8: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x800985BC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800985C0: beq         $v1, $zero, L_8009862C
    if (ctx->r3 == 0) {
        // 0x800985C4: sw          $v0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r2;
            goto L_8009862C;
    }
    // 0x800985C4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800985C8: subu        $t7, $v1, $t6
    ctx->r15 = SUB32(ctx->r3, ctx->r14);
    // 0x800985CC: bgtz        $t7, L_8009862C
    if (SIGNED(ctx->r15) > 0) {
        // 0x800985D0: sw          $t7, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r15;
            goto L_8009862C;
    }
    // 0x800985D0: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800985D4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800985D8: lw          $t9, 0xFE8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XFE8);
    // 0x800985DC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800985E0: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800985E4: lw          $t1, 0xFEC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XFEC);
    // 0x800985E8: subu        $t0, $t0, $t9
    ctx->r8 = SUB32(ctx->r8, ctx->r25);
    // 0x800985EC: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x800985F0: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800985F4: addu        $t3, $t2, $v0
    ctx->r11 = ADD32(ctx->r10, ctx->r2);
    // 0x800985F8: lb          $v1, -0x6($t3)
    ctx->r3 = MEM_B(ctx->r11, -0X6);
    // 0x800985FC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80098600: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x80098604: addu        $a2, $a2, $t4
    ctx->r6 = ADD32(ctx->r6, ctx->r12);
    // 0x80098608: lh          $a2, 0x758($a2)
    ctx->r6 = MEM_H(ctx->r6, 0X758);
    // 0x8009860C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80098610: beq         $a2, $at, L_80098628
    if (ctx->r6 == ctx->r1) {
        // 0x80098614: andi        $a0, $a2, 0xFFFF
        ctx->r4 = ctx->r6 & 0XFFFF;
            goto L_80098628;
    }
    // 0x80098614: andi        $a0, $a2, 0xFFFF
    ctx->r4 = ctx->r6 & 0XFFFF;
    // 0x80098618: jal         0x80001D04
    // 0x8009861C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8009861C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80098620: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80098624: addiu       $a3, $a3, 0x980
    ctx->r7 = ADD32(ctx->r7, 0X980);
L_80098628:
    // 0x80098628: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_8009862C:
    // 0x8009862C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098630: addiu       $v1, $v1, -0xB84
    ctx->r3 = ADD32(ctx->r3, -0XB84);
    // 0x80098634: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80098638: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x8009863C: beq         $v0, $zero, L_8009864C
    if (ctx->r2 == 0) {
        // 0x80098640: addu        $t6, $v0, $t5
        ctx->r14 = ADD32(ctx->r2, ctx->r13);
            goto L_8009864C;
    }
    // 0x80098640: addu        $t6, $v0, $t5
    ctx->r14 = ADD32(ctx->r2, ctx->r13);
    // 0x80098644: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x80098648: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_8009864C:
    // 0x8009864C: slti        $at, $v0, 0x16
    ctx->r1 = SIGNED(ctx->r2) < 0X16 ? 1 : 0;
    // 0x80098650: beq         $at, $zero, L_8009866C
    if (ctx->r1 == 0) {
        // 0x80098654: nop
    
            goto L_8009866C;
    }
    // 0x80098654: nop

    // 0x80098658: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8009865C: jal         0x800983C0
    // 0x80098660: nop

    trophyround_render(rdram, ctx);
        goto after_2;
    // 0x80098660: nop

    after_2:
    // 0x80098664: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098668: addiu       $v1, $v1, -0xB84
    ctx->r3 = ADD32(ctx->r3, -0XB84);
L_8009866C:
    // 0x8009866C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80098670: lw          $t7, 0x63C4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63C4);
    // 0x80098674: nop

    // 0x80098678: bne         $t7, $zero, L_800986CC
    if (ctx->r15 != 0) {
        // 0x8009867C: nop
    
            goto L_800986CC;
    }
    // 0x8009867C: nop

    // 0x80098680: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x80098684: nop

    // 0x80098688: bne         $t8, $zero, L_800986CC
    if (ctx->r24 != 0) {
        // 0x8009868C: nop
    
            goto L_800986CC;
    }
    // 0x8009868C: nop

    // 0x80098690: jal         0x8008E4EC
    // 0x80098694: nop

    menu_input(rdram, ctx);
        goto after_3;
    // 0x80098694: nop

    after_3:
    // 0x80098698: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009869C: lw          $t9, 0x67E8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X67E8);
    // 0x800986A0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800986A4: andi        $t0, $t9, 0x9000
    ctx->r8 = ctx->r25 & 0X9000;
    // 0x800986A8: beq         $t0, $zero, L_800986CC
    if (ctx->r8 == 0) {
        // 0x800986AC: nop
    
            goto L_800986CC;
    }
    // 0x800986AC: nop

    // 0x800986B0: jal         0x800C01D8
    // 0x800986B4: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_4;
    // 0x800986B4: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_4:
    // 0x800986B8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800986BC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800986C0: sw          $t1, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r9;
    // 0x800986C4: jal         0x80000C98
    // 0x800986C8: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    music_fade(rdram, ctx);
        goto after_5;
    // 0x800986C8: addiu       $a0, $zero, -0x80
    ctx->r4 = ADD32(0, -0X80);
    after_5:
L_800986CC:
    // 0x800986CC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800986D0: addiu       $v1, $v1, -0xB84
    ctx->r3 = ADD32(ctx->r3, -0XB84);
    // 0x800986D4: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800986D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800986DC: slti        $at, $t2, 0x1F
    ctx->r1 = SIGNED(ctx->r10) < 0X1F ? 1 : 0;
    // 0x800986E0: bne         $at, $zero, L_8009873C
    if (ctx->r1 != 0) {
        // 0x800986E4: nop
    
            goto L_8009873C;
    }
    // 0x800986E4: nop

    // 0x800986E8: jal         0x80098754
    // 0x800986EC: nop

    trophyround_free(rdram, ctx);
        goto after_6;
    // 0x800986EC: nop

    after_6:
    // 0x800986F0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800986F4: lw          $t3, 0xFE8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0XFE8);
    // 0x800986F8: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800986FC: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x80098700: lw          $t5, 0xFEC($t5)
    ctx->r13 = MEM_W(ctx->r13, 0XFEC);
    // 0x80098704: subu        $t4, $t4, $t3
    ctx->r12 = SUB32(ctx->r12, ctx->r11);
    // 0x80098708: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8009870C: sll         $t4, $t4, 1
    ctx->r12 = S32(ctx->r12 << 1);
    // 0x80098710: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80098714: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80098718: lb          $t9, -0x6($t8)
    ctx->r25 = MEM_B(ctx->r24, -0X6);
    // 0x8009871C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098720: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80098724: sw          $t9, -0xB2C($at)
    MEM_W(-0XB2C, ctx->r1) = ctx->r25;
    // 0x80098728: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009872C: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80098730: lw          $v0, -0xB44($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB44);
    // 0x80098734: b           L_80098744
    // 0x80098738: sw          $t0, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r8;
        goto L_80098744;
    // 0x80098738: sw          $t0, -0xB88($at)
    MEM_W(-0XB88, ctx->r1) = ctx->r8;
L_8009873C:
    // 0x8009873C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80098740: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
L_80098744:
    // 0x80098744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80098748: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009874C: jr          $ra
    // 0x80098750: nop

    return;
    // 0x80098750: nop

;}
RECOMP_FUNC void func_800214C4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800214C4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800214C8: lb          $t6, -0x52DF($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X52DF);
    // 0x800214CC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800214D0: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800214D4: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800214D8: lb          $v0, -0x52DD($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52DD);
    // 0x800214DC: jr          $ra
    // 0x800214E0: nop

    return;
    // 0x800214E0: nop

;}
RECOMP_FUNC void racer_enter_door(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A424: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8005A428: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005A42C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8005A430: lw          $t6, 0x108($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X108);
    // 0x8005A434: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8005A438: lw          $a3, 0x64($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X64);
    // 0x8005A43C: sh          $t7, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r15;
    // 0x8005A440: lwc1        $f14, 0x8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8005A444: lwc1        $f12, 0x0($a3)
    ctx->f12.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8005A448: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8005A44C: jal         0x80070750
    // 0x8005A450: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    arctan2_f(rdram, ctx);
        goto after_0;
    // 0x8005A450: sw          $a3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r7;
    after_0:
    // 0x8005A454: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A458: andi        $t8, $v0, 0xFFFF
    ctx->r24 = ctx->r2 & 0XFFFF;
    // 0x8005A45C: lh          $t9, 0x1A0($a2)
    ctx->r25 = MEM_H(ctx->r6, 0X1A0);
    // 0x8005A460: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005A464: andi        $t2, $t9, 0xFFFF
    ctx->r10 = ctx->r25 & 0XFFFF;
    // 0x8005A468: subu        $v1, $t8, $t2
    ctx->r3 = SUB32(ctx->r24, ctx->r10);
    // 0x8005A46C: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x8005A470: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005A474: bne         $at, $zero, L_8005A488
    if (ctx->r1 != 0) {
        // 0x8005A478: addiu       $t1, $zero, -0x1
        ctx->r9 = ADD32(0, -0X1);
            goto L_8005A488;
    }
    // 0x8005A478: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8005A47C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005A480: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005A484: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005A488:
    // 0x8005A488: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005A48C: beq         $at, $zero, L_8005A49C
    if (ctx->r1 == 0) {
        // 0x8005A490: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8005A49C;
    }
    // 0x8005A490: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005A494: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005A498: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005A49C:
    // 0x8005A49C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005A4A0: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
    // 0x8005A4A4: addiu       $a1, $a1, -0x2ACC
    ctx->r5 = ADD32(ctx->r5, -0X2ACC);
    // 0x8005A4A8: sra         $t3, $v1, 5
    ctx->r11 = S32(SIGNED(ctx->r3) >> 5);
    // 0x8005A4AC: sw          $t3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r11;
    // 0x8005A4B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A4B4: sw          $zero, -0x2AD4($at)
    MEM_W(-0X2AD4, ctx->r1) = 0;
    // 0x8005A4B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A4BC: sw          $zero, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = 0;
    // 0x8005A4C0: addiu       $a0, $a0, -0x2AD8
    ctx->r4 = ADD32(ctx->r4, -0X2AD8);
    // 0x8005A4C4: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8005A4C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005A4CC: sw          $zero, -0x2AC8($at)
    MEM_W(-0X2AC8, ctx->r1) = 0;
    // 0x8005A4D0: lwc1        $f4, 0x2C($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X2C);
    // 0x8005A4D4: lui         $at, 0xC010
    ctx->r1 = S32(0XC010 << 16);
    // 0x8005A4D8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x8005A4DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005A4E0: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x8005A4E4: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8005A4E8: lui         $at, 0xC014
    ctx->r1 = S32(0XC014 << 16);
    // 0x8005A4EC: bc1f        L_8005A508
    if (!c1cs) {
        // 0x8005A4F0: nop
    
            goto L_8005A508;
    }
    // 0x8005A4F0: nop

    // 0x8005A4F4: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8005A4F8: nop

    // 0x8005A4FC: ori         $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 | 0X8000;
    // 0x8005A500: b           L_8005A534
    // 0x8005A504: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
        goto L_8005A534;
    // 0x8005A504: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_8005A508:
    // 0x8005A508: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005A50C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005A510: nop

    // 0x8005A514: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005A518: nop

    // 0x8005A51C: bc1f        L_8005A538
    if (!c1cs) {
        // 0x8005A520: lw          $t9, 0x24($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X24);
            goto L_8005A538;
    }
    // 0x8005A520: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x8005A524: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x8005A528: nop

    // 0x8005A52C: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x8005A530: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
L_8005A534:
    // 0x8005A534: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
L_8005A538:
    // 0x8005A538: lwc1        $f4, 0x0($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X0);
    // 0x8005A53C: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x8005A540: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x8005A544: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8005A548: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x8005A54C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8005A550: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8005A554: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005A558: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x8005A55C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005A560: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005A564: mul.d       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f2.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f2.d);
    // 0x8005A568: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005A56C: addiu       $t4, $zero, -0x4B
    ctx->r12 = ADD32(0, -0X4B);
    // 0x8005A570: cvt.d.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f18.d = CVT_D_S(ctx->f16.fl);
    // 0x8005A574: add.d       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = ctx->f18.d + ctx->f10.d;
    // 0x8005A578: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x8005A57C: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x8005A580: lwc1        $f18, 0x8($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X8);
    // 0x8005A584: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8005A588: mul.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005A58C: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005A590: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8005A594: mul.d       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f2.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f2.d);
    // 0x8005A598: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8005A59C: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8005A5A0: cvt.s.d     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f18.fl = CVT_S_D(ctx->f6.d);
    // 0x8005A5A4: swc1        $f18, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f18.u32l;
    // 0x8005A5A8: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8005A5AC: nop

    // 0x8005A5B0: slti        $at, $v1, 0x4C
    ctx->r1 = SIGNED(ctx->r3) < 0X4C ? 1 : 0;
    // 0x8005A5B4: bne         $at, $zero, L_8005A5D4
    if (ctx->r1 != 0) {
        // 0x8005A5B8: slti        $at, $v1, -0x4B
        ctx->r1 = SIGNED(ctx->r3) < -0X4B ? 1 : 0;
            goto L_8005A5D4;
    }
    // 0x8005A5B8: slti        $at, $v1, -0x4B
    ctx->r1 = SIGNED(ctx->r3) < -0X4B ? 1 : 0;
    // 0x8005A5BC: lw          $t2, 0x0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X0);
    // 0x8005A5C0: addiu       $v1, $zero, 0x4B
    ctx->r3 = ADD32(0, 0X4B);
    // 0x8005A5C4: ori         $t3, $t2, 0xC000
    ctx->r11 = ctx->r10 | 0XC000;
    // 0x8005A5C8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x8005A5CC: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x8005A5D0: slti        $at, $v1, -0x4B
    ctx->r1 = SIGNED(ctx->r3) < -0X4B ? 1 : 0;
L_8005A5D4:
    // 0x8005A5D4: beq         $at, $zero, L_8005A5EC
    if (ctx->r1 == 0) {
        // 0x8005A5D8: nop
    
            goto L_8005A5EC;
    }
    // 0x8005A5D8: nop

    // 0x8005A5DC: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x8005A5E0: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8005A5E4: ori         $t6, $t5, 0xC000
    ctx->r14 = ctx->r13 | 0XC000;
    // 0x8005A5E8: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
L_8005A5EC:
    // 0x8005A5EC: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A5F0: lw          $t7, 0x24($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X24);
    // 0x8005A5F4: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
    // 0x8005A5F8: beq         $at, $zero, L_8005A620
    if (ctx->r1 == 0) {
        // 0x8005A5FC: addu        $t9, $v0, $t7
        ctx->r25 = ADD32(ctx->r2, ctx->r15);
            goto L_8005A620;
    }
    // 0x8005A5FC: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8005A600: sb          $t9, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r25;
    // 0x8005A604: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A608: nop

    // 0x8005A60C: bltz        $v0, L_8005A624
    if (SIGNED(ctx->r2) < 0) {
        // 0x8005A610: slti        $at, $v0, -0x1
        ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
            goto L_8005A624;
    }
    // 0x8005A610: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
    // 0x8005A614: sb          $t1, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r9;
    // 0x8005A618: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A61C: nop

L_8005A620:
    // 0x8005A620: slti        $at, $v0, -0x1
    ctx->r1 = SIGNED(ctx->r2) < -0X1 ? 1 : 0;
L_8005A624:
    // 0x8005A624: beq         $at, $zero, L_8005A648
    if (ctx->r1 == 0) {
        // 0x8005A628: nop
    
            goto L_8005A648;
    }
    // 0x8005A628: nop

    // 0x8005A62C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8005A630: nop

    // 0x8005A634: slti        $at, $v1, 0xA
    ctx->r1 = SIGNED(ctx->r3) < 0XA ? 1 : 0;
    // 0x8005A638: beq         $at, $zero, L_8005A648
    if (ctx->r1 == 0) {
        // 0x8005A63C: slti        $at, $v1, -0x9
        ctx->r1 = SIGNED(ctx->r3) < -0X9 ? 1 : 0;
            goto L_8005A648;
    }
    // 0x8005A63C: slti        $at, $v1, -0x9
    ctx->r1 = SIGNED(ctx->r3) < -0X9 ? 1 : 0;
    // 0x8005A640: beq         $at, $zero, L_8005A650
    if (ctx->r1 == 0) {
        // 0x8005A644: nop
    
            goto L_8005A650;
    }
    // 0x8005A644: nop

L_8005A648:
    // 0x8005A648: bne         $t1, $v0, L_8005A68C
    if (ctx->r9 != ctx->r2) {
        // 0x8005A64C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8005A68C;
    }
    // 0x8005A64C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8005A650:
    // 0x8005A650: jal         0x80066510
    // 0x8005A654: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_1;
    // 0x8005A654: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_1:
    // 0x8005A658: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A65C: bne         $v0, $zero, L_8005A678
    if (ctx->r2 != 0) {
        // 0x8005A660: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8005A678;
    }
    // 0x8005A660: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005A664: addiu       $a0, $a0, -0x322C
    ctx->r4 = ADD32(ctx->r4, -0X322C);
    // 0x8005A668: jal         0x800C01D8
    // 0x8005A66C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    transition_begin(rdram, ctx);
        goto after_2;
    // 0x8005A66C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_2:
    // 0x8005A670: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A674: nop

L_8005A678:
    // 0x8005A678: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x8005A67C: addiu       $t2, $zero, 0x3C
    ctx->r10 = ADD32(0, 0X3C);
    // 0x8005A680: subu        $t3, $t2, $t8
    ctx->r11 = SUB32(ctx->r10, ctx->r24);
    // 0x8005A684: sb          $t3, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r11;
    // 0x8005A688: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8005A68C:
    // 0x8005A68C: jal         0x8006F388
    // 0x8005A690: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    set_pause_lockout_timer(rdram, ctx);
        goto after_3;
    // 0x8005A690: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_3:
    // 0x8005A694: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A698: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8005A69C: lb          $v0, 0x200($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X200);
    // 0x8005A6A0: nop

    // 0x8005A6A4: blez        $v0, L_8005A6E0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005A6A8: subu        $t5, $v0, $t4
        ctx->r13 = SUB32(ctx->r2, ctx->r12);
            goto L_8005A6E0;
    }
    // 0x8005A6A8: subu        $t5, $v0, $t4
    ctx->r13 = SUB32(ctx->r2, ctx->r12);
    // 0x8005A6AC: sb          $t5, 0x200($a2)
    MEM_B(0X200, ctx->r6) = ctx->r13;
    // 0x8005A6B0: lb          $t6, 0x200($a2)
    ctx->r14 = MEM_B(ctx->r6, 0X200);
    // 0x8005A6B4: nop

    // 0x8005A6B8: bgtz        $t6, L_8005A6E4
    if (SIGNED(ctx->r14) > 0) {
        // 0x8005A6BC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8005A6E4;
    }
    // 0x8005A6BC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005A6C0: lw          $t7, 0x108($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X108);
    // 0x8005A6C4: nop

    // 0x8005A6C8: lw          $a0, 0x3C($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X3C);
    // 0x8005A6CC: jal         0x8006D968
    // 0x8005A6D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    func_8006D968(rdram, ctx);
        goto after_4;
    // 0x8005A6D0: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_4:
    // 0x8005A6D4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x8005A6D8: nop

    // 0x8005A6DC: sb          $zero, 0x200($a2)
    MEM_B(0X200, ctx->r6) = 0;
L_8005A6E0:
    // 0x8005A6E0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8005A6E4:
    // 0x8005A6E4: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8005A6E8: jr          $ra
    // 0x8005A6EC: nop

    return;
    // 0x8005A6EC: nop

;}
RECOMP_FUNC void racerfx_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B290: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000B294: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000B298: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000B29C: addiu       $s0, $s0, -0x38AC
    ctx->r16 = ADD32(ctx->r16, -0X38AC);
    // 0x8000B2A0: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B2A4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000B2A8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000B2AC: beq         $a0, $zero, L_8000B2D4
    if (ctx->r4 == 0) {
        // 0x8000B2B0: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_8000B2D4;
    }
    // 0x8000B2B0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000B2B4: jal         0x80071140
    // 0x8000B2B8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8000B2B8: nop

    after_0:
    // 0x8000B2BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000B2C0: addiu       $v0, $v0, -0x38B4
    ctx->r2 = ADD32(ctx->r2, -0X38B4);
    // 0x8000B2C4: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8000B2C8: sw          $zero, 0x4($s0)
    MEM_W(0X4, ctx->r16) = 0;
    // 0x8000B2CC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8000B2D0: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
L_8000B2D4:
    // 0x8000B2D4: jal         0x8001E29C
    // 0x8000B2D8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8000B2D8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_1:
    // 0x8000B2DC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000B2E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000B2E4: addiu       $s2, $zero, 0x500
    ctx->r18 = ADD32(0, 0X500);
L_8000B2E8:
    // 0x8000B2E8: lw          $a0, 0x78($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X78);
    // 0x8000B2EC: nop

    // 0x8000B2F0: beq         $a0, $zero, L_8000B304
    if (ctx->r4 == 0) {
        // 0x8000B2F4: nop
    
            goto L_8000B304;
    }
    // 0x8000B2F4: nop

    // 0x8000B2F8: jal         0x8007CCB0
    // 0x8000B2FC: nop

    sprite_free(rdram, ctx);
        goto after_2;
    // 0x8000B2FC: nop

    after_2:
    // 0x8000B300: sw          $zero, 0x78($s0)
    MEM_W(0X78, ctx->r16) = 0;
L_8000B304:
    // 0x8000B304: lw          $a0, 0x7C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X7C);
    // 0x8000B308: nop

    // 0x8000B30C: beq         $a0, $zero, L_8000B320
    if (ctx->r4 == 0) {
        // 0x8000B310: nop
    
            goto L_8000B320;
    }
    // 0x8000B310: nop

    // 0x8000B314: jal         0x8007B2BC
    // 0x8000B318: nop

    tex_free(rdram, ctx);
        goto after_3;
    // 0x8000B318: nop

    after_3:
    // 0x8000B31C: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_8000B320:
    // 0x8000B320: addiu       $s1, $s1, 0x80
    ctx->r17 = ADD32(ctx->r17, 0X80);
    // 0x8000B324: bne         $s1, $s2, L_8000B2E8
    if (ctx->r17 != ctx->r18) {
        // 0x8000B328: addiu       $s0, $s0, 0x80
        ctx->r16 = ADD32(ctx->r16, 0X80);
            goto L_8000B2E8;
    }
    // 0x8000B328: addiu       $s0, $s0, 0x80
    ctx->r16 = ADD32(ctx->r16, 0X80);
    // 0x8000B32C: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000B330: addiu       $s0, $s0, -0x38A4
    ctx->r16 = ADD32(ctx->r16, -0X38A4);
    // 0x8000B334: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000B338: nop

    // 0x8000B33C: beq         $a0, $zero, L_8000B34C
    if (ctx->r4 == 0) {
        // 0x8000B340: nop
    
            goto L_8000B34C;
    }
    // 0x8000B340: nop

    // 0x8000B344: jal         0x8000FFB8
    // 0x8000B348: nop

    free_object(rdram, ctx);
        goto after_4;
    // 0x8000B348: nop

    after_4:
L_8000B34C:
    // 0x8000B34C: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8000B350: addiu       $s1, $s1, -0x389C
    ctx->r17 = ADD32(ctx->r17, -0X389C);
    // 0x8000B354: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000B358: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8000B35C: beq         $a0, $zero, L_8000B36C
    if (ctx->r4 == 0) {
        // 0x8000B360: nop
    
            goto L_8000B36C;
    }
    // 0x8000B360: nop

    // 0x8000B364: jal         0x8000FFB8
    // 0x8000B368: nop

    free_object(rdram, ctx);
        goto after_5;
    // 0x8000B368: nop

    after_5:
L_8000B36C:
    // 0x8000B36C: jal         0x8001004C
    // 0x8000B370: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    gParticlePtrList_flush(rdram, ctx);
        goto after_6;
    // 0x8000B370: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    after_6:
    // 0x8000B374: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000B378: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000B37C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000B380: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000B384: jr          $ra
    // 0x8000B388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000B388: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void write_epc_data_to_cpak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B71B0: addiu       $sp, $sp, -0x848
    ctx->r29 = ADD32(ctx->r29, -0X848);
    // 0x800B71B4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B71B8: jal         0x800D2470
    // 0x800B71BC: nop

    __osGetActiveQueue(rdram, ctx);
        goto after_0;
    // 0x800B71BC: nop

    after_0:
    // 0x800B71C0: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x800B71C4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800B71C8: beq         $a0, $t6, L_800B721C
    if (ctx->r4 == ctx->r14) {
        // 0x800B71CC: or          $a3, $v0, $zero
        ctx->r7 = ctx->r2 | 0;
            goto L_800B721C;
    }
    // 0x800B71CC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
    // 0x800B71D0: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800B71D4: nop

L_800B71D8:
    // 0x800B71D8: blez        $v1, L_800B7204
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800B71DC: slti        $at, $v1, 0x80
        ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
            goto L_800B7204;
    }
    // 0x800B71DC: slti        $at, $v1, 0x80
    ctx->r1 = SIGNED(ctx->r3) < 0X80 ? 1 : 0;
    // 0x800B71E0: beq         $at, $zero, L_800B7204
    if (ctx->r1 == 0) {
        // 0x800B71E4: nop
    
            goto L_800B7204;
    }
    // 0x800B71E4: nop

    // 0x800B71E8: lhu         $v1, 0x12($a3)
    ctx->r3 = MEM_HU(ctx->r7, 0X12);
    // 0x800B71EC: nop

    // 0x800B71F0: andi        $t7, $v1, 0x2
    ctx->r15 = ctx->r3 & 0X2;
    // 0x800B71F4: bne         $t7, $zero, L_800B721C
    if (ctx->r15 != 0) {
        // 0x800B71F8: andi        $t8, $v1, 0x1
        ctx->r24 = ctx->r3 & 0X1;
            goto L_800B721C;
    }
    // 0x800B71F8: andi        $t8, $v1, 0x1
    ctx->r24 = ctx->r3 & 0X1;
    // 0x800B71FC: bne         $t8, $zero, L_800B721C
    if (ctx->r24 != 0) {
        // 0x800B7200: nop
    
            goto L_800B721C;
    }
    // 0x800B7200: nop

L_800B7204:
    // 0x800B7204: lw          $a3, 0xC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0XC);
    // 0x800B7208: nop

    // 0x800B720C: lw          $v1, 0x4($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X4);
    // 0x800B7210: nop

    // 0x800B7214: bne         $a0, $v1, L_800B71D8
    if (ctx->r4 != ctx->r3) {
        // 0x800B7218: nop
    
            goto L_800B71D8;
    }
    // 0x800B7218: nop

L_800B721C:
    // 0x800B721C: lw          $t9, 0x4($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4);
    // 0x800B7220: nop

    // 0x800B7224: beq         $a0, $t9, L_800B742C
    if (ctx->r4 == ctx->r25) {
        // 0x800B7228: nop
    
            goto L_800B742C;
    }
    // 0x800B7228: nop

    // 0x800B722C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B7230: addiu       $v0, $v0, -0x6050
    ctx->r2 = ADD32(ctx->r2, -0X6050);
    // 0x800B7234: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800B7238: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x800B723C: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B7240: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800B7244: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B7248: addiu       $a2, $zero, 0x1B0
    ctx->r6 = ADD32(0, 0X1B0);
    // 0x800B724C: swc1        $f6, 0x130($a3)
    MEM_W(0X130, ctx->r7) = ctx->f6.u32l;
    // 0x800B7250: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x800B7254: nop

    // 0x800B7258: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x800B725C: nop

    // 0x800B7260: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800B7264: swc1        $f10, 0x134($a3)
    MEM_W(0X134, ctx->r7) = ctx->f10.u32l;
    // 0x800B7268: lw          $t2, 0x8($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X8);
    // 0x800B726C: nop

    // 0x800B7270: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800B7274: nop

    // 0x800B7278: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B727C: swc1        $f18, 0x138($a3)
    MEM_W(0X138, ctx->r7) = ctx->f18.u32l;
    // 0x800B7280: jal         0x800C9DA0
    // 0x800B7284: sw          $a3, 0x844($sp)
    MEM_W(0X844, ctx->r29) = ctx->r7;
    _bcopy(rdram, ctx);
        goto after_1;
    // 0x800B7284: sw          $a3, 0x844($sp)
    MEM_W(0X844, ctx->r29) = ctx->r7;
    after_1:
    // 0x800B7288: lw          $a3, 0x844($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X844);
    // 0x800B728C: addiu       $a1, $sp, 0x244
    ctx->r5 = ADD32(ctx->r29, 0X244);
    // 0x800B7290: lw          $a0, 0xF4($a3)
    ctx->r4 = MEM_W(ctx->r7, 0XF4);
    // 0x800B7294: jal         0x800C9DA0
    // 0x800B7298: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    _bcopy(rdram, ctx);
        goto after_2;
    // 0x800B7298: addiu       $a2, $zero, 0x200
    ctx->r6 = ADD32(0, 0X200);
    after_2:
    // 0x800B729C: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x800B72A0: jal         0x80024594
    // 0x800B72A4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    func_80024594(rdram, ctx);
        goto after_3;
    // 0x800B72A4: addiu       $a1, $sp, 0x34
    ctx->r5 = ADD32(ctx->r29, 0X34);
    after_3:
    // 0x800B72A8: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B72AC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800B72B0: blez        $t3, L_800B7404
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800B72B4: lui         $a3, 0x800F
        ctx->r7 = S32(0X800F << 16);
            goto L_800B7404;
    }
    // 0x800B72B4: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800B72B8: andi        $a2, $t3, 0x3
    ctx->r6 = ctx->r11 & 0X3;
    // 0x800B72BC: beq         $a2, $zero, L_800B7320
    if (ctx->r6 == 0) {
        // 0x800B72C0: or          $v1, $a2, $zero
        ctx->r3 = ctx->r6 | 0;
            goto L_800B7320;
    }
    // 0x800B72C0: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800B72C4: sll         $t6, $zero, 1
    ctx->r14 = S32(0 << 1);
    // 0x800B72C8: addiu       $t7, $sp, 0x444
    ctx->r15 = ADD32(ctx->r29, 0X444);
    // 0x800B72CC: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
L_800B72D0:
    // 0x800B72D0: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B72D4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800B72D8: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B72DC: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800B72E0: lh          $t1, 0x0($t0)
    ctx->r9 = MEM_H(ctx->r8, 0X0);
    // 0x800B72E4: nop

    // 0x800B72E8: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x800B72EC: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x800B72F0: lw          $t5, 0x34($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X34);
    // 0x800B72F4: addiu       $t4, $t2, -0x1
    ctx->r12 = ADD32(ctx->r10, -0X1);
    // 0x800B72F8: bgez        $t4, L_800B7308
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800B72FC: sw          $t4, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r12;
            goto L_800B7308;
    }
    // 0x800B72FC: sw          $t4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r12;
    // 0x800B7300: addu        $a2, $t4, $t5
    ctx->r6 = ADD32(ctx->r12, ctx->r13);
    // 0x800B7304: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B7308:
    // 0x800B7308: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800B730C: bne         $v1, $a1, L_800B72D0
    if (ctx->r3 != ctx->r5) {
        // 0x800B7310: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_800B72D0;
    }
    // 0x800B7310: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x800B7314: lw          $t3, 0x34($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X34);
    // 0x800B7318: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    // 0x800B731C: beq         $a1, $t3, L_800B7404
    if (ctx->r5 == ctx->r11) {
        // 0x800B7320: sll         $t6, $a1, 1
        ctx->r14 = S32(ctx->r5 << 1);
            goto L_800B7404;
    }
L_800B7320:
    // 0x800B7320: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800B7324: addiu       $t7, $sp, 0x444
    ctx->r15 = ADD32(ctx->r29, 0X444);
    // 0x800B7328: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
L_800B732C:
    // 0x800B732C: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B7330: nop

    // 0x800B7334: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800B7338: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800B733C: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800B7340: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7344: sh          $t0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r8;
    // 0x800B7348: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B734C: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B7350: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800B7354: bgez        $t2, L_800B736C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B7358: sw          $t2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r10;
            goto L_800B736C;
    }
    // 0x800B7358: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B735C: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x800B7360: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x800B7364: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    // 0x800B7368: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B736C:
    // 0x800B736C: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x800B7370: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B7374: sh          $t3, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r11;
    // 0x800B7378: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B737C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800B7380: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B7384: bgez        $t7, L_800B739C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B7388: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_800B739C;
    }
    // 0x800B7388: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800B738C: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x800B7390: sll         $t9, $a2, 1
    ctx->r25 = S32(ctx->r6 << 1);
    // 0x800B7394: addu        $v1, $v0, $t9
    ctx->r3 = ADD32(ctx->r2, ctx->r25);
    // 0x800B7398: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B739C:
    // 0x800B739C: lh          $t0, 0x0($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X0);
    // 0x800B73A0: addiu       $v1, $v1, -0x2
    ctx->r3 = ADD32(ctx->r3, -0X2);
    // 0x800B73A4: sh          $t0, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r8;
    // 0x800B73A8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800B73AC: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x800B73B0: addiu       $t2, $t1, -0x1
    ctx->r10 = ADD32(ctx->r9, -0X1);
    // 0x800B73B4: bgez        $t2, L_800B73CC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800B73B8: sw          $t2, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r10;
            goto L_800B73CC;
    }
    // 0x800B73B8: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800B73BC: addu        $a2, $t2, $t4
    ctx->r6 = ADD32(ctx->r10, ctx->r12);
    // 0x800B73C0: sll         $t5, $a2, 1
    ctx->r13 = S32(ctx->r6 << 1);
    // 0x800B73C4: addu        $v1, $v0, $t5
    ctx->r3 = ADD32(ctx->r2, ctx->r13);
    // 0x800B73C8: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B73CC:
    // 0x800B73CC: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x800B73D0: nop

    // 0x800B73D4: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x800B73D8: lw          $t6, 0x38($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X38);
    // 0x800B73DC: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x800B73E0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B73E4: bgez        $t7, L_800B73F4
    if (SIGNED(ctx->r15) >= 0) {
        // 0x800B73E8: sw          $t7, 0x38($sp)
        MEM_W(0X38, ctx->r29) = ctx->r15;
            goto L_800B73F4;
    }
    // 0x800B73E8: sw          $t7, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r15;
    // 0x800B73EC: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
    // 0x800B73F0: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
L_800B73F4:
    // 0x800B73F4: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x800B73F8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800B73FC: bne         $a1, $t9, L_800B732C
    if (ctx->r5 != ctx->r25) {
        // 0x800B7400: addiu       $a0, $a0, 0x8
        ctx->r4 = ADD32(ctx->r4, 0X8);
            goto L_800B732C;
    }
    // 0x800B7400: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_800B7404:
    // 0x800B7404: lui         $a2, 0x800F
    ctx->r6 = S32(0X800F << 16);
    // 0x800B7408: addiu       $t0, $sp, 0x44
    ctx->r8 = ADD32(ctx->r29, 0X44);
    // 0x800B740C: addiu       $t1, $zero, 0x800
    ctx->r9 = ADD32(0, 0X800);
    // 0x800B7410: sw          $t1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r9;
    // 0x800B7414: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800B7418: addiu       $a2, $a2, -0x7124
    ctx->r6 = ADD32(ctx->r6, -0X7124);
    // 0x800B741C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800B7420: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x800B7424: jal         0x800766D4
    // 0x800B7428: addiu       $a3, $a3, -0x711C
    ctx->r7 = ADD32(ctx->r7, -0X711C);
    write_controller_pak_file(rdram, ctx);
        goto after_4;
    // 0x800B7428: addiu       $a3, $a3, -0x711C
    ctx->r7 = ADD32(ctx->r7, -0X711C);
    after_4:
L_800B742C:
    // 0x800B742C: b           L_800B742C
    pause_self(rdram);
    // 0x800B7430: nop

    // 0x800B7434: nop

    // 0x800B7438: nop

    // 0x800B743C: nop

    // 0x800B7440: nop

    // 0x800B7444: nop

    // 0x800B7448: nop

    // 0x800B744C: nop

    // 0x800B7450: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B7454: addiu       $sp, $sp, 0x848
    ctx->r29 = ADD32(ctx->r29, 0X848);
    // 0x800B7458: jr          $ra
    // 0x800B745C: nop

    return;
    // 0x800B745C: nop

;}
RECOMP_FUNC void get_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EA90: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006EA94: lw          $v0, 0x3510($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3510);
    // 0x8006EA98: jr          $ra
    // 0x8006EA9C: nop

    return;
    // 0x8006EA9C: nop

;}
RECOMP_FUNC void is_race_started_by_player_two(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000E158: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8000E15C: lb          $t6, -0x38C0($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X38C0);
    // 0x8000E160: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000E164: beq         $t6, $zero, L_8000E17C
    if (ctx->r14 == 0) {
        // 0x8000E168: nop
    
            goto L_8000E17C;
    }
    // 0x8000E168: nop

    // 0x8000E16C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000E170: lb          $v0, -0x38C4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X38C4);
    // 0x8000E174: jr          $ra
    // 0x8000E178: nop

    return;
    // 0x8000E178: nop

L_8000E17C:
    // 0x8000E17C: jr          $ra
    // 0x8000E180: nop

    return;
    // 0x8000E180: nop

;}
RECOMP_FUNC void cinematic_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009AF18: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009AF1C: lw          $t6, 0x6804($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6804);
    // 0x8009AF20: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009AF24: beq         $t6, $zero, L_8009AF38
    if (ctx->r14 == 0) {
        // 0x8009AF28: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009AF38;
    }
    // 0x8009AF28: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009AF2C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009AF30: jal         0x8009C4A8
    // 0x8009AF34: addiu       $a0, $a0, 0x1768
    ctx->r4 = ADD32(ctx->r4, 0X1768);
    menu_assetgroup_free(rdram, ctx);
        goto after_0;
    // 0x8009AF34: addiu       $a0, $a0, 0x1768
    ctx->r4 = ADD32(ctx->r4, 0X1768);
    after_0:
L_8009AF38:
    // 0x8009AF38: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009AF3C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009AF40: jr          $ra
    // 0x8009AF44: nop

    return;
    // 0x8009AF44: nop

;}
RECOMP_FUNC void obj_loop_treasuresucker(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D058: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8003D05C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003D060: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8003D064: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8003D068: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x8003D06C: jal         0x8001BAC8
    // 0x8003D070: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    get_racer_object(rdram, ctx);
        goto after_0;
    // 0x8003D070: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    after_0:
    // 0x8003D074: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003D078: beq         $v0, $zero, L_8003D29C
    if (ctx->r2 == 0) {
        // 0x8003D07C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8003D29C;
    }
    // 0x8003D07C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8003D080: lw          $a3, 0x64($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X64);
    // 0x8003D084: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8003D088: lb          $t6, 0x185($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X185);
    // 0x8003D08C: nop

    // 0x8003D090: beq         $t6, $zero, L_8003D104
    if (ctx->r14 == 0) {
        // 0x8003D094: nop
    
            goto L_8003D104;
    }
    // 0x8003D094: nop

    // 0x8003D098: lw          $t7, 0x7C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X7C);
    // 0x8003D09C: nop

    // 0x8003D0A0: bne         $t7, $zero, L_8003D104
    if (ctx->r15 != 0) {
        // 0x8003D0A4: nop
    
            goto L_8003D104;
    }
    // 0x8003D0A4: nop

    // 0x8003D0A8: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003D0AC: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003D0B0: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x8003D0B4: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003D0B8: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003D0BC: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003D0C0: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003D0C4: lwc1        $f16, 0x14($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003D0C8: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003D0CC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003D0D0: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003D0D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003D0D8: lwc1        $f16, 0x6180($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X6180);
    // 0x8003D0DC: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8003D0E0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003D0E4: addiu       $t8, $zero, 0x8
    ctx->r24 = ADD32(0, 0X8);
    // 0x8003D0E8: add.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8003D0EC: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8003D0F0: nop

    // 0x8003D0F4: bc1f        L_8003D104
    if (!c1cs) {
        // 0x8003D0F8: nop
    
            goto L_8003D104;
    }
    // 0x8003D0F8: nop

    // 0x8003D0FC: sw          $t8, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r24;
    // 0x8003D100: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003D104:
    // 0x8003D104: lw          $v0, 0x7C($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X7C);
    // 0x8003D108: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8003D10C: blez        $v0, L_8003D150
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D110: subu        $t0, $v0, $t9
        ctx->r8 = SUB32(ctx->r2, ctx->r25);
            goto L_8003D150;
    }
    // 0x8003D110: subu        $t0, $v0, $t9
    ctx->r8 = SUB32(ctx->r2, ctx->r25);
    // 0x8003D114: bgtz        $t0, L_8003D150
    if (SIGNED(ctx->r8) > 0) {
        // 0x8003D118: sw          $t0, 0x7C($a2)
        MEM_W(0X7C, ctx->r6) = ctx->r8;
            goto L_8003D150;
    }
    // 0x8003D118: sw          $t0, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r8;
    // 0x8003D11C: lb          $v0, 0x185($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X185);
    // 0x8003D120: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8003D124: blez        $v0, L_8003D14C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8003D128: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8003D14C;
    }
    // 0x8003D128: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8003D12C: sb          $t2, 0x185($a3)
    MEM_B(0X185, ctx->r7) = ctx->r10;
    // 0x8003D130: lb          $t3, 0x185($a3)
    ctx->r11 = MEM_B(ctx->r7, 0X185);
    // 0x8003D134: nop

    // 0x8003D138: beq         $t3, $zero, L_8003D144
    if (ctx->r11 == 0) {
        // 0x8003D13C: nop
    
            goto L_8003D144;
    }
    // 0x8003D13C: nop

    // 0x8003D140: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8003D144:
    // 0x8003D144: b           L_8003D150
    // 0x8003D148: sw          $t4, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r12;
        goto L_8003D150;
    // 0x8003D148: sw          $t4, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = ctx->r12;
L_8003D14C:
    // 0x8003D14C: sw          $zero, 0x7C($a2)
    MEM_W(0X7C, ctx->r6) = 0;
L_8003D150:
    // 0x8003D150: beq         $a0, $zero, L_8003D2A0
    if (ctx->r4 == 0) {
        // 0x8003D154: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003D2A0;
    }
    // 0x8003D154: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003D158: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8003D15C: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003D160: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8003D164: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D168: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D16C: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x8003D170: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x8003D174: addiu       $a0, $sp, 0x24
    ctx->r4 = ADD32(ctx->r29, 0X24);
    // 0x8003D178: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8003D17C: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x8003D180: addiu       $t5, $zero, 0x61
    ctx->r13 = ADD32(0, 0X61);
    // 0x8003D184: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003D188: sh          $t6, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r14;
    // 0x8003D18C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003D190: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D194: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D198: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x8003D19C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D1A0: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8003D1A4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003D1A8: mfc1        $t0, $f8
    ctx->r8 = (int32_t)ctx->f8.u32l;
    // 0x8003D1AC: nop

    // 0x8003D1B0: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003D1B4: addiu       $t1, $t0, 0xA
    ctx->r9 = ADD32(ctx->r8, 0XA);
    // 0x8003D1B8: sh          $t1, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r9;
    // 0x8003D1BC: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8003D1C0: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8003D1C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D1C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D1CC: sb          $t4, 0x25($sp)
    MEM_B(0X25, ctx->r29) = ctx->r12;
    // 0x8003D1D0: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8003D1D4: sb          $t5, 0x24($sp)
    MEM_B(0X24, ctx->r29) = ctx->r13;
    // 0x8003D1D8: mfc1        $t3, $f16
    ctx->r11 = (int32_t)ctx->f16.u32l;
    // 0x8003D1DC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003D1E0: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x8003D1E4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x8003D1E8: sw          $v1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r3;
    // 0x8003D1EC: jal         0x8000EA54
    // 0x8003D1F0: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_1;
    // 0x8003D1F0: sh          $t3, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r11;
    after_1:
    // 0x8003D1F4: lw          $v1, 0x44($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X44);
    // 0x8003D1F8: lw          $a2, 0x48($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X48);
    // 0x8003D1FC: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x8003D200: beq         $v0, $zero, L_8003D29C
    if (ctx->r2 == 0) {
        // 0x8003D204: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_8003D29C;
    }
    // 0x8003D204: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003D208: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003D20C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8003D210: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8003D214: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003D218: mul.s       $f4, $f2, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f18.fl);
    // 0x8003D21C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003D220: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003D224: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003D228: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8003D22C: nop

    // 0x8003D230: div.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = DIV_D(ctx->f6.d, ctx->f8.d);
    // 0x8003D234: swc1        $f2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f2.u32l;
    // 0x8003D238: lwc1        $f18, 0xC($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8003D23C: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8003D240: nop

    // 0x8003D244: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003D248: cvt.s.d     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f0.fl = CVT_S_D(ctx->f10.d);
    // 0x8003D24C: nop

    // 0x8003D250: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8003D254: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x8003D258: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x8003D25C: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x8003D260: sw          $a3, 0x7C($v0)
    MEM_W(0X7C, ctx->r2) = ctx->r7;
    // 0x8003D264: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003D268: nop

    // 0x8003D26C: div.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f0.fl);
    // 0x8003D270: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8003D274: swc1        $f18, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f18.u32l;
    // 0x8003D278: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8003D27C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D280: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D284: nop

    // 0x8003D288: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8003D28C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8003D290: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8003D294: sw          $t7, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r15;
    // 0x8003D298: nop

L_8003D29C:
    // 0x8003D29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003D2A0:
    // 0x8003D2A0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8003D2A4: jr          $ra
    // 0x8003D2A8: nop

    return;
    // 0x8003D2A8: nop

;}
RECOMP_FUNC void set_ortho_matrix_height(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067F20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80067F24: jr          $ra
    // 0x80067F28: swc1        $f12, -0x2D34($at)
    MEM_W(-0X2D34, ctx->r1) = ctx->f12.u32l;
    return;
    // 0x80067F28: swc1        $f12, -0x2D34($at)
    MEM_W(-0X2D34, ctx->r1) = ctx->f12.u32l;
;}
RECOMP_FUNC void alSynStartVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C96F0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C96F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C96F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C96FC: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800C9700: lw          $t6, 0x8($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X8);
    // 0x800C9704: beql        $t6, $zero, L_800C9770
    if (ctx->r14 == 0) {
        // 0x800C9708: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800C9770;
    }
    goto skip_0;
    // 0x800C9708: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    skip_0:
    // 0x800C970C: jal         0x80065668
    // 0x800C9710: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    __allocParam(rdram, ctx);
        goto after_0;
    // 0x800C9710: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800C9714: lw          $a3, 0x1C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X1C);
    // 0x800C9718: beq         $v0, $zero, L_800C976C
    if (ctx->r2 == 0) {
        // 0x800C971C: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800C976C;
    }
    // 0x800C971C: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800C9720: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800C9724: lw          $t9, 0x8($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X8);
    // 0x800C9728: addiu       $t2, $zero, 0xE
    ctx->r10 = ADD32(0, 0XE);
    // 0x800C972C: lw          $t8, 0x1C($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X1C);
    // 0x800C9730: lw          $t0, 0xD8($t9)
    ctx->r8 = MEM_W(ctx->r25, 0XD8);
    // 0x800C9734: sh          $t2, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r10;
    // 0x800C9738: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x800C973C: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x800C9740: sw          $t1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r9;
    // 0x800C9744: lw          $t3, 0x20($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X20);
    // 0x800C9748: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800C974C: sw          $t3, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r11;
    // 0x800C9750: lh          $t4, 0x1A($a3)
    ctx->r12 = MEM_H(ctx->r7, 0X1A);
    // 0x800C9754: sh          $t4, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r12;
    // 0x800C9758: lw          $t5, 0x8($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X8);
    // 0x800C975C: lw          $a0, 0xC($t5)
    ctx->r4 = MEM_W(ctx->r13, 0XC);
    // 0x800C9760: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800C9764: jalr        $t9
    // 0x800C9768: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800C9768: nop

    after_1:
L_800C976C:
    // 0x800C976C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800C9770:
    // 0x800C9770: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C9774: jr          $ra
    // 0x800C9778: nop

    return;
    // 0x800C9778: nop

;}
RECOMP_FUNC void mtx_perspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006807C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80068080: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80068084: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80068088: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006808C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x80068090: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068094: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    // 0x80068098: jal         0x8006FE74
    // 0x8006809C: addiu       $a1, $a1, -0x2D78
    ctx->r5 = ADD32(ctx->r5, -0X2D78);
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x8006809C: addiu       $a1, $a1, -0x2D78
    ctx->r5 = ADD32(ctx->r5, -0X2D78);
    after_0:
    // 0x800680A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800680A4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800680A8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800680AC: addiu       $a2, $a2, 0xF20
    ctx->r6 = ADD32(ctx->r6, 0XF20);
    // 0x800680B0: addiu       $a1, $a1, 0xEE0
    ctx->r5 = ADD32(ctx->r5, 0XEE0);
    // 0x800680B4: jal         0x8006F768
    // 0x800680B8: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x800680B8: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    after_1:
    // 0x800680BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800680C0: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x800680C4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800680C8: jal         0x8006FE74
    // 0x800680CC: addiu       $a1, $a1, -0x2D60
    ctx->r5 = ADD32(ctx->r5, -0X2D60);
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_2;
    // 0x800680CC: addiu       $a1, $a1, -0x2D60
    ctx->r5 = ADD32(ctx->r5, -0X2D60);
    after_2:
    // 0x800680D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800680D4: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x800680D8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800680DC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800680E0: addiu       $a2, $a2, 0x1060
    ctx->r6 = ADD32(ctx->r6, 0X1060);
    // 0x800680E4: jal         0x8006F768
    // 0x800680E8: addiu       $a1, $a1, 0xF20
    ctx->r5 = ADD32(ctx->r5, 0XF20);
    mtxf_mul(rdram, ctx);
        goto after_3;
    // 0x800680E8: addiu       $a1, $a1, 0xF20
    ctx->r5 = ADD32(ctx->r5, 0XF20);
    after_3:
    // 0x800680EC: lw          $t6, 0x1C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X1C);
    // 0x800680F0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800680F4: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x800680F8: jal         0x8006F870
    // 0x800680FC: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    mtxf_to_mtx(rdram, ctx);
        goto after_4;
    // 0x800680FC: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    after_4:
    // 0x80068100: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80068104: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    extern void dkr_presentation_perspective_matrix(uint8_t*, recomp_context*); dkr_presentation_perspective_matrix(rdram, ctx);
    // 0x80068108: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8006810C: lui         $t8, 0x100
    ctx->r24 = S32(0X100 << 16);
    // 0x80068110: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x80068114: ori         $t8, $t8, 0x40
    ctx->r24 = ctx->r24 | 0X40;
    // 0x80068118: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8006811C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80068120: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x80068124: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80068128: addu        $t0, $t9, $at
    ctx->r8 = ADD32(ctx->r25, ctx->r1);
    // 0x8006812C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x80068130: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x80068134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068138: addiu       $t2, $t1, 0x40
    ctx->r10 = ADD32(ctx->r9, 0X40);
    // 0x8006813C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80068140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80068144: sw          $zero, 0xD1C($at)
    MEM_W(0XD1C, ctx->r1) = 0;
    // 0x80068148: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006814C: sw          $zero, 0xD08($at)
    MEM_W(0XD08, ctx->r1) = 0;
    // 0x80068150: jr          $ra
    // 0x80068154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x80068154: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void func_80012C30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80012C30: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80012C34: jr          $ra
    // 0x80012C38: sh          $zero, -0x525C($at)
    MEM_H(-0X525C, ctx->r1) = 0;
    return;
    // 0x80012C38: sh          $zero, -0x525C($at)
    MEM_H(-0X525C, ctx->r1) = 0;
;}
RECOMP_FUNC void mtxs_transform_dir(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FB60: lw          $t3, 0x0($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X0);
    // 0x8006FB64: lh          $t0, 0x0($a1)
    ctx->r8 = MEM_H(ctx->r5, 0X0);
    // 0x8006FB68: lh          $t1, 0x2($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X2);
    // 0x8006FB6C: lh          $t2, 0x4($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X4);
    // 0x8006FB70: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FB74: lw          $t3, 0x10($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X10);
    // 0x8006FB78: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FB7C: nop

    // 0x8006FB80: nop

    // 0x8006FB84: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FB88: lw          $t3, 0x20($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X20);
    // 0x8006FB8C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FB90: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FB94: nop

    // 0x8006FB98: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FB9C: lw          $t3, 0x4($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4);
    // 0x8006FBA0: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FBA4: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FBA8: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FBAC: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FBB0: sh          $t4, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r12;
    // 0x8006FBB4: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8006FBB8: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FBBC: nop

    // 0x8006FBC0: nop

    // 0x8006FBC4: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FBC8: lw          $t3, 0x24($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X24);
    // 0x8006FBCC: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FBD0: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FBD4: nop

    // 0x8006FBD8: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FBDC: lw          $t3, 0x8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X8);
    // 0x8006FBE0: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FBE4: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FBE8: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FBEC: mult        $t0, $t3
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FBF0: sh          $t4, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r12;
    // 0x8006FBF4: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x8006FBF8: mflo        $t4
    ctx->r12 = lo;
    // 0x8006FBFC: nop

    // 0x8006FC00: nop

    // 0x8006FC04: mult        $t1, $t3
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC08: lw          $t3, 0x28($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X28);
    // 0x8006FC0C: mflo        $t5
    ctx->r13 = lo;
    // 0x8006FC10: add         $t4, $t4, $t5
    ctx->r12 = ADD32(ctx->r12, ctx->r13);
    // 0x8006FC14: nop

    // 0x8006FC18: mult        $t2, $t3
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r11)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8006FC1C: mflo        $t6
    ctx->r14 = lo;
    // 0x8006FC20: add         $t4, $t4, $t6
    ctx->r12 = ADD32(ctx->r12, ctx->r14);
    // 0x8006FC24: sra         $t4, $t4, 16
    ctx->r12 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8006FC28: jr          $ra
    // 0x8006FC2C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
    return;
    // 0x8006FC2C: sh          $t4, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r12;
;}
RECOMP_FUNC void music_channel_fade(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800012A8: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x800012AC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800012B0: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x800012B4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800012B8: bne         $at, $zero, L_800012C8
    if (ctx->r1 != 0) {
        // 0x800012BC: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_800012C8;
    }
    // 0x800012BC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800012C0: b           L_800012D8
    // 0x800012C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800012D8;
    // 0x800012C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800012C8:
    // 0x800012C8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800012CC: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x800012D0: jal         0x80063C00
    // 0x800012D4: nop

    alCSPGetFadeIn(rdram, ctx);
        goto after_0;
    // 0x800012D4: nop

    after_0:
L_800012D8:
    // 0x800012D8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800012DC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800012E0: jr          $ra
    // 0x800012E4: nop

    return;
    // 0x800012E4: nop

;}
RECOMP_FUNC void obj_loop_buoy_pirateship(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040448: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8004044C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80040450: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80040454: lw          $a3, 0x64($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X64);
    // 0x80040458: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8004045C: beq         $a3, $zero, L_80040478
    if (ctx->r7 == 0) {
        // 0x80040460: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_80040478;
    }
    // 0x80040460: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80040464: jal         0x800BEEB4
    // 0x80040468: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    obj_wave_height(rdram, ctx);
        goto after_0;
    // 0x80040468: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    after_0:
    // 0x8004046C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80040470: nop

    // 0x80040474: swc1        $f0, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f0.u32l;
L_80040478:
    // 0x80040478: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8004047C: lh          $t6, 0x18($a2)
    ctx->r14 = MEM_H(ctx->r6, 0X18);
    // 0x80040480: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80040484: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80040488: sh          $t9, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r25;
    // 0x8004048C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040490: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040494: jr          $ra
    // 0x80040498: nop

    return;
    // 0x80040498: nop

;}
RECOMP_FUNC void obj_loop_hittester(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800381C0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800381C4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800381C8: jal         0x8001F460
    // 0x800381CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    func_8001F460(rdram, ctx);
        goto after_0;
    // 0x800381CC: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    after_0:
    // 0x800381D0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800381D4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800381D8: jr          $ra
    // 0x800381DC: nop

    return;
    // 0x800381DC: nop

;}
RECOMP_FUNC void set_texture_colour_tag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B374: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007B378: jr          $ra
    // 0x8007B37C: sw          $a0, -0x1840($at)
    MEM_W(-0X1840, ctx->r1) = ctx->r4;
    return;
    // 0x8007B37C: sw          $a0, -0x1840($at)
    MEM_W(-0X1840, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void sprite_cache_asset_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C8A0: bltz        $a0, L_8007C8BC
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007C8A4: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007C8BC;
    }
    // 0x8007C8A4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C8A8: lw          $t6, 0x6358($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6358);
    // 0x8007C8AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007C8B0: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007C8B4: bne         $at, $zero, L_8007C8C4
    if (ctx->r1 != 0) {
        // 0x8007C8B8: nop
    
            goto L_8007C8C4;
    }
    // 0x8007C8B8: nop

L_8007C8BC:
    // 0x8007C8BC: jr          $ra
    // 0x8007C8C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8007C8C0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007C8C4:
    // 0x8007C8C4: lw          $t7, 0x634C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X634C);
    // 0x8007C8C8: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007C8CC: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007C8D0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8007C8D4: nop

    // 0x8007C8D8: jr          $ra
    // 0x8007C8DC: nop

    return;
    // 0x8007C8DC: nop

;}
RECOMP_FUNC void obj_init_char_select(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038330: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80038334: jr          $ra
    // 0x80038338: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x80038338: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void wave_load_material(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BA4B8: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BA4BC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800BA4C0: lbu         $t0, 0x0($a0)
    ctx->r8 = MEM_BU(ctx->r4, 0X0);
    // 0x800BA4C4: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800BA4C8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BA4CC: bne         $t0, $at, L_800BA4E8
    if (ctx->r8 != ctx->r1) {
        // 0x800BA4D0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800BA4E8;
    }
    // 0x800BA4D0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BA4D4: beq         $a1, $zero, L_800BA4E0
    if (ctx->r5 == 0) {
        // 0x800BA4D8: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_800BA4E0;
    }
    // 0x800BA4D8: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800BA4DC: addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
L_800BA4E0:
    // 0x800BA4E0: b           L_800BA524
    // 0x800BA4E4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
        goto L_800BA524;
    // 0x800BA4E4: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
L_800BA4E8:
    // 0x800BA4E8: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x800BA4EC: bne         $t0, $at, L_800BA514
    if (ctx->r8 != ctx->r1) {
        // 0x800BA4F0: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_800BA514;
    }
    // 0x800BA4F0: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800BA4F4: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x800BA4F8: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x800BA4FC: beq         $t7, $zero, L_800BA508
    if (ctx->r15 == 0) {
        // 0x800BA500: nop
    
            goto L_800BA508;
    }
    // 0x800BA500: nop

    // 0x800BA504: addiu       $a2, $zero, 0x100
    ctx->r6 = ADD32(0, 0X100);
L_800BA508:
    // 0x800BA508: b           L_800BA524
    // 0x800BA50C: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
        goto L_800BA524;
    // 0x800BA50C: sw          $t4, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r12;
    // 0x800BA510: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_800BA514:
    // 0x800BA514: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800BA518: beq         $t8, $zero, L_800BA524
    if (ctx->r24 == 0) {
        // 0x800BA51C: nop
    
            goto L_800BA524;
    }
    // 0x800BA51C: nop

    // 0x800BA520: addiu       $a2, $zero, 0x180
    ctx->r6 = ADD32(0, 0X180);
L_800BA524:
    // 0x800BA524: lbu         $t9, 0x2($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X2);
    // 0x800BA528: lw          $t4, 0x5C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X5C);
    // 0x800BA52C: andi        $t6, $t9, 0xF
    ctx->r14 = ctx->r25 & 0XF;
    // 0x800BA530: bne         $t6, $zero, L_800BA700
    if (ctx->r14 != 0) {
        // 0x800BA534: lui         $v1, 0x8013
        ctx->r3 = S32(0X8013 << 16);
            goto L_800BA700;
    }
    // 0x800BA534: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA538: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BA53C: addiu       $v1, $v1, -0x6040
    ctx->r3 = ADD32(ctx->r3, -0X6040);
    // 0x800BA540: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA544: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BA548: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BA54C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA550: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800BA554: sw          $v0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r2;
    // 0x800BA558: addu        $t6, $a3, $at
    ctx->r14 = ADD32(ctx->r7, ctx->r1);
    // 0x800BA55C: lui         $t8, 0xFD18
    ctx->r24 = S32(0XFD18 << 16);
    // 0x800BA560: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BA564: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800BA568: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA56C: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x800BA570: andi        $t1, $a2, 0x1FF
    ctx->r9 = ctx->r6 & 0X1FF;
    // 0x800BA574: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x800BA578: andi        $a0, $t4, 0xF
    ctx->r4 = ctx->r12 & 0XF;
    // 0x800BA57C: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BA580: multu       $t0, $t0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA584: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA588: sll         $t2, $a0, 14
    ctx->r10 = S32(ctx->r4 << 14);
    // 0x800BA58C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BA590: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x800BA594: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x800BA598: sw          $v0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r2;
    // 0x800BA59C: or          $t7, $t9, $t3
    ctx->r15 = ctx->r25 | ctx->r11;
    // 0x800BA5A0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BA5A4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BA5A8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA5AC: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800BA5B0: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800BA5B4: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BA5B8: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x800BA5BC: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BA5C0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BA5C4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800BA5C8: mflo        $a1
    ctx->r5 = lo;
    // 0x800BA5CC: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800BA5D0: addiu       $t6, $t5, 0x8
    ctx->r14 = ADD32(ctx->r13, 0X8);
    // 0x800BA5D4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BA5D8: sltiu       $at, $a1, 0x7FF
    ctx->r1 = ctx->r5 < 0X7FF ? 1 : 0;
    // 0x800BA5DC: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x800BA5E0: beq         $at, $zero, L_800BA5F0
    if (ctx->r1 == 0) {
        // 0x800BA5E4: sw          $t8, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->r24;
            goto L_800BA5F0;
    }
    // 0x800BA5E4: sw          $t8, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r24;
    // 0x800BA5E8: b           L_800BA5F4
    // 0x800BA5EC: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
        goto L_800BA5F4;
    // 0x800BA5EC: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_800BA5F0:
    // 0x800BA5F0: addiu       $t4, $zero, 0x7FF
    ctx->r12 = ADD32(0, 0X7FF);
L_800BA5F4:
    // 0x800BA5F4: sll         $v0, $t0, 2
    ctx->r2 = S32(ctx->r8 << 2);
    // 0x800BA5F8: srl         $t9, $v0, 3
    ctx->r25 = S32(U32(ctx->r2) >> 3);
    // 0x800BA5FC: bne         $t9, $zero, L_800BA60C
    if (ctx->r25 != 0) {
        // 0x800BA600: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_800BA60C;
    }
    // 0x800BA600: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x800BA604: b           L_800BA610
    // 0x800BA608: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800BA610;
    // 0x800BA608: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800BA60C:
    // 0x800BA60C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800BA610:
    // 0x800BA610: bne         $v0, $zero, L_800BA620
    if (ctx->r2 != 0) {
        // 0x800BA614: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_800BA620;
    }
    // 0x800BA614: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x800BA618: b           L_800BA624
    // 0x800BA61C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800BA624;
    // 0x800BA61C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800BA620:
    // 0x800BA620: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800BA624:
    // 0x800BA624: divu        $zero, $t7, $a2
    lo = S32(U32(ctx->r15) / U32(ctx->r6)); hi = S32(U32(ctx->r15) % U32(ctx->r6));
    // 0x800BA628: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x800BA62C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BA630: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x800BA634: bne         $a2, $zero, L_800BA640
    if (ctx->r6 != 0) {
        // 0x800BA638: nop
    
            goto L_800BA640;
    }
    // 0x800BA638: nop

    // 0x800BA63C: break       7
    do_break(2148247100);
L_800BA640:
    // 0x800BA640: mflo        $t6
    ctx->r14 = lo;
    // 0x800BA644: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x800BA648: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800BA64C: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x800BA650: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x800BA654: sw          $t8, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r24;
    // 0x800BA658: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA65C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x800BA660: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BA664: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA668: sw          $v0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r2;
    // 0x800BA66C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800BA670: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BA674: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA678: sll         $t7, $t0, 1
    ctx->r15 = S32(ctx->r8 << 1);
    // 0x800BA67C: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x800BA680: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800BA684: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BA688: srl         $t6, $t9, 3
    ctx->r14 = S32(U32(ctx->r25) >> 3);
    // 0x800BA68C: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x800BA690: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x800BA694: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x800BA698: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x800BA69C: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x800BA6A0: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x800BA6A4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BA6A8: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800BA6AC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800BA6B0: andi        $t7, $a0, 0x7
    ctx->r15 = ctx->r4 & 0X7;
    // 0x800BA6B4: sll         $t9, $t7, 24
    ctx->r25 = S32(ctx->r15 << 24);
    // 0x800BA6B8: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x800BA6BC: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800BA6C0: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BA6C4: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA6C8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800BA6CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800BA6D0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BA6D4: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800BA6D8: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800BA6DC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800BA6E0: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BA6E4: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800BA6E8: or          $t8, $a0, $t6
    ctx->r24 = ctx->r4 | ctx->r14;
    // 0x800BA6EC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800BA6F0: or          $t9, $t8, $t9
    ctx->r25 = ctx->r24 | ctx->r25;
    // 0x800BA6F4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800BA6F8: b           L_800BA8DC
    // 0x800BA6FC: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
        goto L_800BA8DC;
    // 0x800BA6FC: or          $t7, $v0, $zero
    ctx->r15 = ctx->r2 | 0;
L_800BA700:
    // 0x800BA700: addiu       $v1, $v1, -0x6040
    ctx->r3 = ADD32(ctx->r3, -0X6040);
    // 0x800BA704: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA708: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BA70C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800BA710: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BA714: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x800BA718: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x800BA71C: addu        $t7, $a3, $at
    ctx->r15 = ADD32(ctx->r7, ctx->r1);
    // 0x800BA720: lui         $t8, 0xFD10
    ctx->r24 = S32(0XFD10 << 16);
    // 0x800BA724: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BA728: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800BA72C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA730: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800BA734: andi        $t1, $a2, 0x1FF
    ctx->r9 = ctx->r6 & 0X1FF;
    // 0x800BA738: or          $t8, $t1, $at
    ctx->r24 = ctx->r9 | ctx->r1;
    // 0x800BA73C: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800BA740: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BA744: andi        $a0, $t4, 0xF
    ctx->r4 = ctx->r12 & 0XF;
    // 0x800BA748: sw          $v0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r2;
    // 0x800BA74C: sll         $t2, $a0, 14
    ctx->r10 = S32(ctx->r4 << 14);
    // 0x800BA750: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BA754: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BA758: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800BA75C: or          $t9, $t2, $at
    ctx->r25 = ctx->r10 | ctx->r1;
    // 0x800BA760: sll         $t3, $a0, 4
    ctx->r11 = S32(ctx->r4 << 4);
    // 0x800BA764: multu       $t0, $t0
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r8)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BA768: or          $t6, $t9, $t3
    ctx->r14 = ctx->r25 | ctx->r11;
    // 0x800BA76C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x800BA770: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA774: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x800BA778: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BA77C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA780: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800BA784: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800BA788: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800BA78C: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x800BA790: sw          $zero, 0x4($t8)
    MEM_W(0X4, ctx->r24) = 0;
    // 0x800BA794: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800BA798: mflo        $a1
    ctx->r5 = lo;
    // 0x800BA79C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    // 0x800BA7A0: addiu       $t7, $t5, 0x8
    ctx->r15 = ADD32(ctx->r13, 0X8);
    // 0x800BA7A4: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA7A8: sltiu       $at, $a1, 0x7FF
    ctx->r1 = ctx->r5 < 0X7FF ? 1 : 0;
    // 0x800BA7AC: beq         $at, $zero, L_800BA7BC
    if (ctx->r1 == 0) {
        // 0x800BA7B0: sw          $t9, 0x0($t5)
        MEM_W(0X0, ctx->r13) = ctx->r25;
            goto L_800BA7BC;
    }
    // 0x800BA7B0: sw          $t9, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r25;
    // 0x800BA7B4: b           L_800BA7C0
    // 0x800BA7B8: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
        goto L_800BA7C0;
    // 0x800BA7B8: or          $t4, $a1, $zero
    ctx->r12 = ctx->r5 | 0;
L_800BA7BC:
    // 0x800BA7BC: addiu       $t4, $zero, 0x7FF
    ctx->r12 = ADD32(0, 0X7FF);
L_800BA7C0:
    // 0x800BA7C0: sll         $t6, $t0, 1
    ctx->r14 = S32(ctx->r8 << 1);
    // 0x800BA7C4: srl         $t8, $t6, 3
    ctx->r24 = S32(U32(ctx->r14) >> 3);
    // 0x800BA7C8: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
    // 0x800BA7CC: bne         $t8, $zero, L_800BA7DC
    if (ctx->r24 != 0) {
        // 0x800BA7D0: sw          $t6, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r14;
            goto L_800BA7DC;
    }
    // 0x800BA7D0: sw          $t6, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r14;
    // 0x800BA7D4: b           L_800BA7E0
    // 0x800BA7D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
        goto L_800BA7E0;
    // 0x800BA7D8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
L_800BA7DC:
    // 0x800BA7DC: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_800BA7E0:
    // 0x800BA7E0: bne         $v0, $zero, L_800BA7F0
    if (ctx->r2 != 0) {
        // 0x800BA7E4: addiu       $t7, $a3, 0x7FF
        ctx->r15 = ADD32(ctx->r7, 0X7FF);
            goto L_800BA7F0;
    }
    // 0x800BA7E4: addiu       $t7, $a3, 0x7FF
    ctx->r15 = ADD32(ctx->r7, 0X7FF);
    // 0x800BA7E8: b           L_800BA7F4
    // 0x800BA7EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_800BA7F4;
    // 0x800BA7EC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_800BA7F0:
    // 0x800BA7F0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800BA7F4:
    // 0x800BA7F4: divu        $zero, $t7, $a2
    lo = S32(U32(ctx->r15) / U32(ctx->r6)); hi = S32(U32(ctx->r15) % U32(ctx->r6));
    // 0x800BA7F8: andi        $t7, $t4, 0xFFF
    ctx->r15 = ctx->r12 & 0XFFF;
    // 0x800BA7FC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BA800: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x800BA804: bne         $a2, $zero, L_800BA810
    if (ctx->r6 != 0) {
        // 0x800BA808: nop
    
            goto L_800BA810;
    }
    // 0x800BA808: nop

    // 0x800BA80C: break       7
    do_break(2148247564);
L_800BA810:
    // 0x800BA810: mflo        $t9
    ctx->r25 = lo;
    // 0x800BA814: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x800BA818: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x800BA81C: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x800BA820: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x800BA824: sw          $t6, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r14;
    // 0x800BA828: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA82C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x800BA830: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BA834: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA838: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x800BA83C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800BA840: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800BA844: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x800BA848: sw          $zero, 0x4($t6)
    MEM_W(0X4, ctx->r14) = 0;
    // 0x800BA84C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA850: lw          $t8, 0x0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X0);
    // 0x800BA854: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800BA858: addiu       $t9, $t8, 0x7
    ctx->r25 = ADD32(ctx->r24, 0X7);
    // 0x800BA85C: srl         $t6, $t9, 3
    ctx->r14 = S32(U32(ctx->r25) >> 3);
    // 0x800BA860: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800BA864: andi        $t7, $t6, 0x1FF
    ctx->r15 = ctx->r14 & 0X1FF;
    // 0x800BA868: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x800BA86C: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800BA870: or          $t6, $t9, $t1
    ctx->r14 = ctx->r25 | ctx->r9;
    // 0x800BA874: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x800BA878: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BA87C: lw          $a0, 0x64($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X64);
    // 0x800BA880: nop

    // 0x800BA884: andi        $t8, $a0, 0x7
    ctx->r24 = ctx->r4 & 0X7;
    // 0x800BA888: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800BA88C: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800BA890: or          $t6, $t9, $t2
    ctx->r14 = ctx->r25 | ctx->r10;
    // 0x800BA894: or          $t7, $t6, $t3
    ctx->r15 = ctx->r14 | ctx->r11;
    // 0x800BA898: sw          $t7, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r15;
    // 0x800BA89C: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800BA8A0: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
    // 0x800BA8A4: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800BA8A8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BA8AC: sll         $t8, $a1, 2
    ctx->r24 = S32(ctx->r5 << 2);
    // 0x800BA8B0: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x800BA8B4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x800BA8B8: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x800BA8BC: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x800BA8C0: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x800BA8C4: or          $t7, $a0, $t6
    ctx->r15 = ctx->r4 | ctx->r14;
    // 0x800BA8C8: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x800BA8CC: or          $a1, $t9, $zero
    ctx->r5 = ctx->r25 | 0;
    // 0x800BA8D0: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800BA8D4: nop

    // 0x800BA8D8: sw          $t8, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r24;
L_800BA8DC:
    // 0x800BA8DC: jr          $ra
    // 0x800BA8E0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BA8E0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void func_800BCC70(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BCC70: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x800BCC74: sw          $fp, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r30;
    // 0x800BCC78: lui         $fp, 0x8013
    ctx->r30 = S32(0X8013 << 16);
    // 0x800BCC7C: addiu       $fp, $fp, -0x6038
    ctx->r30 = ADD32(ctx->r30, -0X6038);
    // 0x800BCC80: lw          $t6, 0x28($fp)
    ctx->r14 = MEM_W(ctx->r30, 0X28);
    // 0x800BCC84: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x800BCC88: lw          $s4, 0x0($fp)
    ctx->r20 = MEM_W(ctx->r30, 0X0);
    // 0x800BCC8C: sw          $ra, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r31;
    // 0x800BCC90: sw          $s7, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r23;
    // 0x800BCC94: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x800BCC98: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x800BCC9C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x800BCCA0: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800BCCA4: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800BCCA8: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800BCCAC: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800BCCB0: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x800BCCB4: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800BCCB8: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x800BCCBC: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BCCC0: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x800BCCC4: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BCCC8: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x800BCCCC: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BCCD0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800BCCD4: beq         $t6, $zero, L_800BCCE4
    if (ctx->r14 == 0) {
        // 0x800BCCD8: sw          $a0, 0x190($sp)
        MEM_W(0X190, ctx->r29) = ctx->r4;
            goto L_800BCCE4;
    }
    // 0x800BCCD8: sw          $a0, 0x190($sp)
    MEM_W(0X190, ctx->r29) = ctx->r4;
    // 0x800BCCDC: sll         $t7, $s4, 1
    ctx->r15 = S32(ctx->r20 << 1);
    // 0x800BCCE0: or          $s4, $t7, $zero
    ctx->r20 = ctx->r15 | 0;
L_800BCCE4:
    // 0x800BCCE4: addiu       $t8, $s4, 0x1
    ctx->r24 = ADD32(ctx->r20, 0X1);
    // 0x800BCCE8: multu       $t8, $t8
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCCEC: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x800BCCF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BCCF4: addiu       $s1, $s1, 0x3178
    ctx->r17 = ADD32(ctx->r17, 0X3178);
    // 0x800BCCF8: sw          $t8, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r24;
    // 0x800BCCFC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BCD00: sw          $t6, 0x317C($at)
    MEM_W(0X317C, ctx->r1) = ctx->r14;
    // 0x800BCD04: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BCD08: nop

    // 0x800BCD0C: beq         $a0, $zero, L_800BCD20
    if (ctx->r4 == 0) {
        // 0x800BCD10: lw          $t7, 0x190($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X190);
            goto L_800BCD20;
    }
    // 0x800BCD10: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800BCD14: jal         0x80071140
    // 0x800BCD18: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800BCD18: nop

    after_0:
    // 0x800BCD1C: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
L_800BCD20:
    // 0x800BCD20: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BCD24: lw          $t9, 0x317C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X317C);
    // 0x800BCD28: lh          $t8, 0x1A($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X1A);
    // 0x800BCD2C: lui         $s0, 0xFF
    ctx->r16 = S32(0XFF << 16);
    // 0x800BCD30: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCD34: ori         $s0, $s0, 0xFFFF
    ctx->r16 = ctx->r16 | 0XFFFF;
    // 0x800BCD38: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BCD3C: mflo        $a0
    ctx->r4 = lo;
    // 0x800BCD40: jal         0x80070C9C
    // 0x800BCD44: nop

    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x800BCD44: nop

    after_1:
    // 0x800BCD48: lw          $t6, 0x190($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X190);
    // 0x800BCD4C: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x800BCD50: lh          $a0, 0x1A($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X1A);
    // 0x800BCD54: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BCD58: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800BCD5C: jal         0x80070C9C
    // 0x800BCD60: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800BCD60: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x800BCD64: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BCD68: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BCD6C: lw          $t9, -0x5F24($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5F24);
    // 0x800BCD70: lw          $t8, -0x5F28($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5F28);
    // 0x800BCD74: sw          $v0, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r2;
    // 0x800BCD78: multu       $t8, $t9
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCD7C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x800BCD80: mflo        $a0
    ctx->r4 = lo;
    // 0x800BCD84: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BCD88: jal         0x80070C9C
    // 0x800BCD8C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x800BCD8C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    after_3:
    // 0x800BCD90: sll         $a0, $s4, 2
    ctx->r4 = S32(ctx->r20 << 2);
    // 0x800BCD94: sw          $v0, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r2;
    // 0x800BCD98: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800BCD9C: jal         0x80070C9C
    // 0x800BCDA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800BCDA0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800BCDA4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BCDA8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BCDAC: lw          $t8, -0x5F24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5F24);
    // 0x800BCDB0: lw          $t7, -0x5F28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5F28);
    // 0x800BCDB4: lw          $v1, 0xA4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA4);
    // 0x800BCDB8: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCDBC: sw          $v0, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r2;
    // 0x800BCDC0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BCDC4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800BCDC8: addiu       $a1, $s4, 0x1
    ctx->r5 = ADD32(ctx->r20, 0X1);
    // 0x800BCDCC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BCDD0: blez        $t9, L_800BCE0C
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BCDD4: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_800BCE0C;
    }
    // 0x800BCDD4: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_800BCDD8:
    // 0x800BCDD8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800BCDDC: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800BCDE0: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BCDE4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BCDE8: lw          $t8, -0x5F24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5F24);
    // 0x800BCDEC: lw          $t7, -0x5F28($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5F28);
    // 0x800BCDF0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BCDF4: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCDF8: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x800BCDFC: mflo        $t9
    ctx->r25 = lo;
    // 0x800BCE00: slt         $at, $a3, $t9
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BCE04: bne         $at, $zero, L_800BCDD8
    if (ctx->r1 != 0) {
        // 0x800BCE08: addiu       $t6, $zero, -0x1
        ctx->r14 = ADD32(0, -0X1);
            goto L_800BCDD8;
    }
    // 0x800BCE08: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
L_800BCE0C:
    // 0x800BCE0C: bltz        $s4, L_800BCF4C
    if (SIGNED(ctx->r20) < 0) {
        // 0x800BCE10: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800BCF4C;
    }
    // 0x800BCE10: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BCE14: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x800BCE18: beq         $t6, $zero, L_800BCEA4
    if (ctx->r14 == 0) {
        // 0x800BCE1C: or          $a0, $t6, $zero
        ctx->r4 = ctx->r14 | 0;
            goto L_800BCEA4;
    }
    // 0x800BCE1C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x800BCE20: mtc1        $s4, $f4
    ctx->f4.u32l = ctx->r20;
    // 0x800BCE24: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800BCE28: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800BCE2C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800BCE30: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x800BCE34: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BCE38: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800BCE3C: subu        $t9, $s4, $t8
    ctx->r25 = SUB32(ctx->r20, ctx->r24);
    // 0x800BCE40: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BCE44: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x800BCE48: beq         $a0, $t2, L_800BCE7C
    if (ctx->r4 == ctx->r10) {
        // 0x800BCE4C: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800BCE7C;
    }
    // 0x800BCE4C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
L_800BCE50:
    // 0x800BCE50: nop

    // 0x800BCE54: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800BCE58: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BCE5C: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800BCE60: subu        $t9, $s4, $t8
    ctx->r25 = SUB32(ctx->r20, ctx->r24);
    // 0x800BCE64: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BCE68: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BCE6C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BCE70: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BCE74: bne         $a0, $t2, L_800BCE50
    if (ctx->r4 != ctx->r10) {
        // 0x800BCE78: swc1        $f16, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
            goto L_800BCE50;
    }
    // 0x800BCE78: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
L_800BCE7C:
    // 0x800BCE7C: nop

    // 0x800BCE80: div.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = DIV_S(ctx->f8.fl, ctx->f0.fl);
    // 0x800BCE84: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BCE88: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BCE8C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800BCE90: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BCE94: swc1        $f16, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f16.u32l;
    // 0x800BCE98: addiu       $t6, $s4, 0x1
    ctx->r14 = ADD32(ctx->r20, 0X1);
    // 0x800BCE9C: beq         $t6, $t2, L_800BCF4C
    if (ctx->r14 == ctx->r10) {
        // 0x800BCEA0: nop
    
            goto L_800BCF4C;
    }
    // 0x800BCEA0: nop

L_800BCEA4:
    // 0x800BCEA4: mtc1        $s4, $f18
    ctx->f18.u32l = ctx->r20;
    // 0x800BCEA8: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x800BCEAC: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x800BCEB0: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800BCEB4: addu        $v1, $v0, $t7
    ctx->r3 = ADD32(ctx->r2, ctx->r15);
    // 0x800BCEB8: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
L_800BCEBC:
    // 0x800BCEBC: sll         $t8, $t2, 1
    ctx->r24 = S32(ctx->r10 << 1);
    // 0x800BCEC0: subu        $t9, $s4, $t8
    ctx->r25 = SUB32(ctx->r20, ctx->r24);
    // 0x800BCEC4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BCEC8: addiu       $t6, $t2, 0x1
    ctx->r14 = ADD32(ctx->r10, 0X1);
    // 0x800BCECC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BCED0: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x800BCED4: subu        $t8, $s4, $t7
    ctx->r24 = SUB32(ctx->r20, ctx->r15);
    // 0x800BCED8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800BCEDC: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BCEE0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BCEE4: addiu       $t9, $t2, 0x2
    ctx->r25 = ADD32(ctx->r10, 0X2);
    // 0x800BCEE8: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800BCEEC: subu        $t7, $s4, $t6
    ctx->r15 = SUB32(ctx->r20, ctx->r14);
    // 0x800BCEF0: addiu       $t8, $t2, 0x3
    ctx->r24 = ADD32(ctx->r10, 0X3);
    // 0x800BCEF4: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BCEF8: subu        $t6, $s4, $t9
    ctx->r14 = SUB32(ctx->r20, ctx->r25);
    // 0x800BCEFC: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800BCF00: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800BCF04: div.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BCF08: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BCF0C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800BCF10: addiu       $t7, $s4, 0x1
    ctx->r15 = ADD32(ctx->r20, 0X1);
    // 0x800BCF14: swc1        $f10, -0x10($v1)
    MEM_W(-0X10, ctx->r3) = ctx->f10.u32l;
    // 0x800BCF18: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BCF1C: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BCF20: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800BCF24: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BCF28: swc1        $f6, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->f6.u32l;
    // 0x800BCF2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BCF30: nop

    // 0x800BCF34: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BCF38: mul.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f2.fl);
    // 0x800BCF3C: swc1        $f18, -0x8($v1)
    MEM_W(-0X8, ctx->r3) = ctx->f18.u32l;
    // 0x800BCF40: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x800BCF44: bne         $t7, $t2, L_800BCEBC
    if (ctx->r15 != ctx->r10) {
        // 0x800BCF48: swc1        $f10, -0x4($v1)
        MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
            goto L_800BCEBC;
    }
    // 0x800BCF48: swc1        $f10, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = ctx->f10.u32l;
L_800BCF4C:
    // 0x800BCF4C: mtc1        $s4, $f16
    ctx->f16.u32l = ctx->r20;
    // 0x800BCF50: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BCF54: lwc1        $f18, -0x5F60($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X5F60);
    // 0x800BCF58: lw          $t8, 0x190($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X190);
    // 0x800BCF5C: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BCF60: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BCF64: sw          $zero, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = 0;
    // 0x800BCF68: lwc1        $f4, -0x5F5C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5F5C);
    // 0x800BCF6C: lh          $v0, 0x1A($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X1A);
    // 0x800BCF70: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800BCF74: div.s       $f26, $f18, $f0
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f26.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BCF78: blez        $v0, L_800BD274
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BCF7C: div.s       $f28, $f4, $f0
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
            goto L_800BD274;
    }
    // 0x800BCF7C: div.s       $f28, $f4, $f0
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f28.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800BCF80: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800BCF84: addiu       $a2, $a2, 0x30D8
    ctx->r6 = ADD32(ctx->r6, 0X30D8);
    // 0x800BCF88: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800BCF8C: addiu       $s0, $sp, 0xAC
    ctx->r16 = ADD32(ctx->r29, 0XAC);
L_800BCF90:
    // 0x800BCF90: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BCF94: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BCF98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BCF9C: addu        $a1, $t9, $t6
    ctx->r5 = ADD32(ctx->r25, ctx->r14);
    // 0x800BCFA0: lbu         $a0, 0xB($a1)
    ctx->r4 = MEM_BU(ctx->r5, 0XB);
    // 0x800BCFA4: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BCFA8: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BCFAC: lbu         $v1, 0xA($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XA);
    // 0x800BCFB0: addu        $t6, $t6, $t9
    ctx->r14 = ADD32(ctx->r14, ctx->r25);
    // 0x800BCFB4: lw          $t6, -0x5F18($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5F18);
    // 0x800BCFB8: sllv        $t8, $t7, $v1
    ctx->r24 = S32(ctx->r15 << (ctx->r3 & 31));
    // 0x800BCFBC: and         $t7, $t8, $t6
    ctx->r15 = ctx->r24 & ctx->r14;
    // 0x800BCFC0: beq         $t7, $zero, L_800BD208
    if (ctx->r15 == 0) {
        // 0x800BCFC4: lui         $t6, 0x800E
        ctx->r14 = S32(0X800E << 16);
            goto L_800BD208;
    }
    // 0x800BCFC4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BCFC8: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BCFCC: lw          $t6, -0x5F28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5F28);
    // 0x800BCFD0: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x800BCFD4: multu       $a0, $t6
    result = U64(U32(ctx->r4)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BCFD8: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800BCFDC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BCFE0: mflo        $t7
    ctx->r15 = lo;
    // 0x800BCFE4: sll         $t6, $t7, 3
    ctx->r14 = S32(ctx->r15 << 3);
    // 0x800BCFE8: addu        $t7, $t8, $t6
    ctx->r15 = ADD32(ctx->r24, ctx->r14);
    // 0x800BCFEC: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x800BCFF0: addu        $t6, $t7, $t8
    ctx->r14 = ADD32(ctx->r15, ctx->r24);
    // 0x800BCFF4: sw          $t9, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r25;
    // 0x800BCFF8: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x800BCFFC: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BD000: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BD004: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800BD008: lbu         $t9, 0xB($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XB);
    // 0x800BD00C: lw          $t6, -0x5F28($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5F28);
    // 0x800BD010: nop

    // 0x800BD014: multu       $t9, $t6
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD018: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD01C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD020: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x800BD024: lbu         $t7, 0xA($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD028: addu        $t6, $t9, $t8
    ctx->r14 = ADD32(ctx->r25, ctx->r24);
    // 0x800BD02C: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x800BD030: addu        $t8, $t6, $t9
    ctx->r24 = ADD32(ctx->r14, ctx->r25);
    // 0x800BD034: sw          $s5, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r21;
    // 0x800BD038: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD03C: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BD040: nop

    // 0x800BD044: addu        $a1, $t7, $t6
    ctx->r5 = ADD32(ctx->r15, ctx->r14);
    // 0x800BD048: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    // 0x800BD04C: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
    // 0x800BD050: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BD054: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800BD058: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BD05C: bltz        $s4, L_800BD1F4
    if (SIGNED(ctx->r20) < 0) {
        // 0x800BD060: cvt.s.w     $f24, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BD1F4;
    }
    // 0x800BD060: cvt.s.w     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
L_800BD064:
    // 0x800BD064: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x800BD068: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD06C: nop

    // 0x800BD070: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800BD074: lh          $t8, 0x4($t9)
    ctx->r24 = MEM_H(ctx->r25, 0X4);
    // 0x800BD078: nop

    // 0x800BD07C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BD080: bltz        $s4, L_800BD1E4
    if (SIGNED(ctx->r20) < 0) {
        // 0x800BD084: cvt.s.w     $f22, $f10
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800BD1E4;
    }
    // 0x800BD084: cvt.s.w     $f22, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    ctx->f22.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BD088: sw          $v0, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r2;
    // 0x800BD08C: lw          $t7, 0x184($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X184);
    // 0x800BD090: lw          $s7, 0x90($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X90);
    // 0x800BD094: lw          $s3, 0xA8($sp)
    ctx->r19 = MEM_W(ctx->r29, 0XA8);
    // 0x800BD098: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800BD09C: sll         $t9, $s7, 2
    ctx->r25 = S32(ctx->r23 << 2);
    // 0x800BD0A0: or          $s7, $t9, $zero
    ctx->r23 = ctx->r25 | 0;
    // 0x800BD0A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800BD0A8: addu        $s6, $s3, $t6
    ctx->r22 = ADD32(ctx->r19, ctx->r14);
L_800BD0AC:
    // 0x800BD0AC: lwc1        $f16, 0x0($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X0);
    // 0x800BD0B0: lwc1        $f4, 0x0($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X0);
    // 0x800BD0B4: add.s       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f22.fl;
    // 0x800BD0B8: lw          $a0, 0x18C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18C);
    // 0x800BD0BC: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x800BD0C0: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x800BD0C4: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BD0C8: jal         0x8002BAB0
    // 0x800BD0CC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    collision_get_y(rdram, ctx);
        goto after_5;
    // 0x800BD0CC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_5:
    // 0x800BD0D0: bne         $v0, $zero, L_800BD0E0
    if (ctx->r2 != 0) {
        // 0x800BD0D4: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_800BD0E0;
    }
    // 0x800BD0D4: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x800BD0D8: b           L_800BD1BC
    // 0x800BD0DC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
        goto L_800BD1BC;
    // 0x800BD0DC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_800BD0E0:
    // 0x800BD0E0: addiu       $a0, $v0, -0x1
    ctx->r4 = ADD32(ctx->r2, -0X1);
    // 0x800BD0E4: blez        $a0, L_800BD130
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BD0E8: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BD130;
    }
    // 0x800BD0E8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BD0EC: lwc1        $f8, 0xAC($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x800BD0F0: nop

    // 0x800BD0F4: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x800BD0F8: nop

    // 0x800BD0FC: bc1f        L_800BD134
    if (!c1cs) {
        // 0x800BD100: sll         $t6, $v1, 2
        ctx->r14 = S32(ctx->r3 << 2);
            goto L_800BD134;
    }
    // 0x800BD100: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_800BD104:
    // 0x800BD104: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD108: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BD10C: beq         $at, $zero, L_800BD130
    if (ctx->r1 == 0) {
        // 0x800BD110: sll         $t8, $v1, 2
        ctx->r24 = S32(ctx->r3 << 2);
            goto L_800BD130;
    }
    // 0x800BD110: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800BD114: addu        $t7, $s0, $t8
    ctx->r15 = ADD32(ctx->r16, ctx->r24);
    // 0x800BD118: lwc1        $f10, 0x0($t7)
    ctx->f10.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BD11C: nop

    // 0x800BD120: c.le.s      $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f20.fl <= ctx->f10.fl;
    // 0x800BD124: nop

    // 0x800BD128: bc1t        L_800BD104
    if (c1cs) {
        // 0x800BD12C: nop
    
            goto L_800BD104;
    }
    // 0x800BD12C: nop

L_800BD130:
    // 0x800BD130: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
L_800BD134:
    // 0x800BD134: addu        $t9, $s0, $t6
    ctx->r25 = ADD32(ctx->r16, ctx->r14);
    // 0x800BD138: lwc1        $f0, 0x0($t9)
    ctx->f0.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BD13C: nop

    // 0x800BD140: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800BD144: nop

    // 0x800BD148: bc1f        L_800BD158
    if (!c1cs) {
        // 0x800BD14C: nop
    
            goto L_800BD158;
    }
    // 0x800BD14C: nop

    // 0x800BD150: b           L_800BD1BC
    // 0x800BD154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_800BD1BC;
    // 0x800BD154: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_800BD158:
    // 0x800BD158: c.eq.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl == ctx->f0.fl;
    // 0x800BD15C: nop

    // 0x800BD160: bc1f        L_800BD170
    if (!c1cs) {
        // 0x800BD164: nop
    
            goto L_800BD170;
    }
    // 0x800BD164: nop

    // 0x800BD168: b           L_800BD1BC
    // 0x800BD16C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
        goto L_800BD1BC;
    // 0x800BD16C: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_800BD170:
    // 0x800BD170: sub.s       $f16, $f20, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f20.fl - ctx->f0.fl;
    // 0x800BD174: lwc1        $f18, 0x48($fp)
    ctx->f18.u32l = MEM_W(ctx->r30, 0X48);
    // 0x800BD178: nop

    // 0x800BD17C: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800BD180: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BD184: nop

    // 0x800BD188: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BD18C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BD190: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BD194: nop

    // 0x800BD198: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BD19C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800BD1A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BD1A4: slti        $at, $a2, 0x200
    ctx->r1 = SIGNED(ctx->r6) < 0X200 ? 1 : 0;
    // 0x800BD1A8: bne         $at, $zero, L_800BD1B8
    if (ctx->r1 != 0) {
        // 0x800BD1AC: sra         $t7, $a2, 1
        ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
            goto L_800BD1B8;
    }
    // 0x800BD1AC: sra         $t7, $a2, 1
    ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD1B0: addiu       $a2, $zero, 0x1FF
    ctx->r6 = ADD32(0, 0X1FF);
    // 0x800BD1B4: sra         $t7, $a2, 1
    ctx->r15 = S32(SIGNED(ctx->r6) >> 1);
L_800BD1B8:
    // 0x800BD1B8: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
L_800BD1BC:
    // 0x800BD1BC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD1C0: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x800BD1C4: addu        $t9, $t6, $s5
    ctx->r25 = ADD32(ctx->r14, ctx->r21);
    // 0x800BD1C8: sb          $a2, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r6;
    // 0x800BD1CC: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800BD1D0: bne         $s7, $s2, L_800BD0AC
    if (ctx->r23 != ctx->r18) {
        // 0x800BD1D4: add.s       $f22, $f22, $f26
        CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
            goto L_800BD0AC;
    }
    // 0x800BD1D4: add.s       $f22, $f22, $f26
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f22.fl = ctx->f22.fl + ctx->f26.fl;
    // 0x800BD1D8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800BD1DC: lw          $v0, 0x184($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X184);
    // 0x800BD1E0: addiu       $a2, $a2, 0x30D8
    ctx->r6 = ADD32(ctx->r6, 0X30D8);
L_800BD1E4:
    // 0x800BD1E4: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800BD1E8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BD1EC: bne         $t8, $v0, L_800BD064
    if (ctx->r24 != ctx->r2) {
        // 0x800BD1F0: add.s       $f24, $f24, $f28
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f28.fl;
            goto L_800BD064;
    }
    // 0x800BD1F0: add.s       $f24, $f24, $f28
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f24.fl = ctx->f24.fl + ctx->f28.fl;
L_800BD1F4:
    // 0x800BD1F4: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800BD1F8: nop

    // 0x800BD1FC: lh          $v0, 0x1A($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X1A);
    // 0x800BD200: b           L_800BD254
    // 0x800BD204: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
        goto L_800BD254;
    // 0x800BD204: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
L_800BD208:
    // 0x800BD208: lw          $t6, 0x317C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X317C);
    // 0x800BD20C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BD210: blez        $t6, L_800BD254
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BD214: lw          $t9, 0x18C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X18C);
            goto L_800BD254;
    }
    // 0x800BD214: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
L_800BD218:
    // 0x800BD218: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800BD21C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800BD220: addu        $t7, $t8, $s5
    ctx->r15 = ADD32(ctx->r24, ctx->r21);
    // 0x800BD224: sb          $t9, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r25;
    // 0x800BD228: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BD22C: lw          $t6, 0x317C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X317C);
    // 0x800BD230: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BD234: slt         $at, $t2, $t6
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BD238: bne         $at, $zero, L_800BD218
    if (ctx->r1 != 0) {
        // 0x800BD23C: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_800BD218;
    }
    // 0x800BD23C: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x800BD240: lw          $t8, 0x190($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X190);
    // 0x800BD244: nop

    // 0x800BD248: lh          $v0, 0x1A($t8)
    ctx->r2 = MEM_H(ctx->r24, 0X1A);
    // 0x800BD24C: nop

    // 0x800BD250: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
L_800BD254:
    // 0x800BD254: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800BD258: addiu       $t7, $t9, 0x1
    ctx->r15 = ADD32(ctx->r25, 0X1);
    // 0x800BD25C: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BD260: addiu       $t8, $t6, 0x1C
    ctx->r24 = ADD32(ctx->r14, 0X1C);
    // 0x800BD264: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x800BD268: bne         $at, $zero, L_800BCF90
    if (ctx->r1 != 0) {
        // 0x800BD26C: sw          $t7, 0x18C($sp)
        MEM_W(0X18C, ctx->r29) = ctx->r15;
            goto L_800BCF90;
    }
    // 0x800BD26C: sw          $t7, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r15;
    // 0x800BD270: sw          $zero, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = 0;
L_800BD274:
    // 0x800BD274: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BD278: lw          $v1, -0x5F24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5F24);
    // 0x800BD27C: sw          $zero, 0x184($sp)
    MEM_W(0X184, ctx->r29) = 0;
    // 0x800BD280: blez        $v1, L_800BD674
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BD284: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800BD674;
    }
    // 0x800BD284: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD288: lw          $a0, -0x5F28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5F28);
    // 0x800BD28C: nop

L_800BD290:
    // 0x800BD290: blez        $a0, L_800BD64C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BD294: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800BD64C;
    }
    // 0x800BD294: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BD298: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD29C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x800BD2A0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800BD2A4:
    // 0x800BD2A4: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800BD2A8: nop

    // 0x800BD2AC: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD2B0: mflo        $t6
    ctx->r14 = lo;
    // 0x800BD2B4: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800BD2B8: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x800BD2BC: addu        $t6, $t7, $t3
    ctx->r14 = ADD32(ctx->r15, ctx->r11);
    // 0x800BD2C0: lw          $t4, 0x4($t6)
    ctx->r12 = MEM_W(ctx->r14, 0X4);
    // 0x800BD2C4: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BD2C8: beq         $t4, $a2, L_800BD62C
    if (ctx->r12 == ctx->r6) {
        // 0x800BD2CC: nop
    
            goto L_800BD62C;
    }
    // 0x800BD2CC: nop

    // 0x800BD2D0: lw          $t8, -0x5F24($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5F24);
    // 0x800BD2D4: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BD2D8: addiu       $t7, $t8, -0x1
    ctx->r15 = ADD32(ctx->r24, -0X1);
    // 0x800BD2DC: slt         $at, $t9, $t7
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BD2E0: beq         $at, $zero, L_800BD47C
    if (ctx->r1 == 0) {
        // 0x800BD2E4: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_800BD47C;
    }
    // 0x800BD2E4: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800BD2E8: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD2EC: mflo        $t8
    ctx->r24 = lo;
    // 0x800BD2F0: sll         $t7, $t8, 3
    ctx->r15 = S32(ctx->r24 << 3);
    // 0x800BD2F4: addu        $t9, $a1, $t7
    ctx->r25 = ADD32(ctx->r5, ctx->r15);
    // 0x800BD2F8: addu        $t6, $t9, $t3
    ctx->r14 = ADD32(ctx->r25, ctx->r11);
    // 0x800BD2FC: lw          $v0, 0x4($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X4);
    // 0x800BD300: lw          $t8, 0x90($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X90);
    // 0x800BD304: beq         $v0, $a2, L_800BD47C
    if (ctx->r2 == ctx->r6) {
        // 0x800BD308: addiu       $t7, $a0, -0x1
        ctx->r15 = ADD32(ctx->r4, -0X1);
            goto L_800BD47C;
    }
    // 0x800BD308: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
    // 0x800BD30C: multu       $t8, $s4
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD310: addiu       $v1, $v0, 0x1
    ctx->r3 = ADD32(ctx->r2, 0X1);
    // 0x800BD314: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x800BD318: addiu       $t1, $s4, -0x1
    ctx->r9 = ADD32(ctx->r20, -0X1);
    // 0x800BD31C: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x800BD320: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BD324: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD328: addu        $a1, $t7, $t4
    ctx->r5 = ADD32(ctx->r15, ctx->r12);
    // 0x800BD32C: blez        $t1, L_800BD478
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800BD330: addiu       $a1, $a1, 0x1
        ctx->r5 = ADD32(ctx->r5, 0X1);
            goto L_800BD478;
    }
    // 0x800BD330: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD334: beq         $t9, $zero, L_800BD384
    if (ctx->r25 == 0) {
        // 0x800BD338: or          $t0, $t9, $zero
        ctx->r8 = ctx->r25 | 0;
            goto L_800BD384;
    }
    // 0x800BD338: or          $t0, $t9, $zero
    ctx->r8 = ctx->r25 | 0;
L_800BD33C:
    // 0x800BD33C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD340: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BD344: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD348: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD34C: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD350: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD354: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD358: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD35C: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD360: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD364: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD368: nop

    // 0x800BD36C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD370: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD374: bne         $t0, $a3, L_800BD33C
    if (ctx->r8 != ctx->r7) {
        // 0x800BD378: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BD33C;
    }
    // 0x800BD378: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD37C: beq         $a3, $t1, L_800BD46C
    if (ctx->r7 == ctx->r9) {
        // 0x800BD380: nop
    
            goto L_800BD46C;
    }
    // 0x800BD380: nop

L_800BD384:
    // 0x800BD384: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD388: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800BD38C: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD390: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD394: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BD398: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD39C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD3A0: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD3A4: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD3A8: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BD3AC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BD3B0: nop

    // 0x800BD3B4: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BD3B8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BD3BC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD3C0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD3C4: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD3C8: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD3CC: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD3D0: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD3D4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD3D8: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD3DC: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD3E0: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD3E4: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD3E8: nop

    // 0x800BD3EC: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD3F0: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD3F4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD3F8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD3FC: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD400: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD404: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD408: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BD40C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD410: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD414: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD418: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BD41C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BD420: nop

    // 0x800BD424: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BD428: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BD42C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD430: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD434: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD438: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD43C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD440: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD444: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD448: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD44C: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD450: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD454: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD458: nop

    // 0x800BD45C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD460: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD464: bne         $a3, $t1, L_800BD384
    if (ctx->r7 != ctx->r9) {
        // 0x800BD468: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BD384;
    }
    // 0x800BD468: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_800BD46C:
    // 0x800BD46C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD470: lw          $a0, -0x5F28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5F28);
    // 0x800BD474: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800BD478:
    // 0x800BD478: addiu       $t7, $a0, -0x1
    ctx->r15 = ADD32(ctx->r4, -0X1);
L_800BD47C:
    // 0x800BD47C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD480: slt         $at, $t2, $t7
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BD484: beq         $at, $zero, L_800BD62C
    if (ctx->r1 == 0) {
        // 0x800BD488: nop
    
            goto L_800BD62C;
    }
    // 0x800BD488: nop

    // 0x800BD48C: lw          $t9, 0x184($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X184);
    // 0x800BD490: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BD494: multu       $t9, $a0
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD498: addiu       $t1, $s4, -0x1
    ctx->r9 = ADD32(ctx->r20, -0X1);
    // 0x800BD49C: mflo        $t6
    ctx->r14 = lo;
    // 0x800BD4A0: sll         $t8, $t6, 3
    ctx->r24 = S32(ctx->r14 << 3);
    // 0x800BD4A4: addu        $t7, $a1, $t8
    ctx->r15 = ADD32(ctx->r5, ctx->r24);
    // 0x800BD4A8: addu        $t9, $t7, $t3
    ctx->r25 = ADD32(ctx->r15, ctx->r11);
    // 0x800BD4AC: lw          $v0, 0xC($t9)
    ctx->r2 = MEM_W(ctx->r25, 0XC);
    // 0x800BD4B0: sll         $t6, $s4, 1
    ctx->r14 = S32(ctx->r20 << 1);
    // 0x800BD4B4: beq         $v0, $a2, L_800BD62C
    if (ctx->r2 == ctx->r6) {
        // 0x800BD4B8: addu        $a1, $t6, $t4
        ctx->r5 = ADD32(ctx->r14, ctx->r12);
            goto L_800BD62C;
    }
    // 0x800BD4B8: addu        $a1, $t6, $t4
    ctx->r5 = ADD32(ctx->r14, ctx->r12);
    // 0x800BD4BC: addu        $v1, $v0, $s4
    ctx->r3 = ADD32(ctx->r2, ctx->r20);
    // 0x800BD4C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD4C4: blez        $t1, L_800BD62C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800BD4C8: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800BD62C;
    }
    // 0x800BD4C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD4CC: addiu       $v0, $s4, -0x1
    ctx->r2 = ADD32(ctx->r20, -0X1);
    // 0x800BD4D0: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x800BD4D4: beq         $t8, $zero, L_800BD528
    if (ctx->r24 == 0) {
        // 0x800BD4D8: or          $t0, $t8, $zero
        ctx->r8 = ctx->r24 | 0;
            goto L_800BD528;
    }
    // 0x800BD4D8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
L_800BD4DC:
    // 0x800BD4DC: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD4E0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BD4E4: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD4E8: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD4EC: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BD4F0: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD4F4: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BD4F8: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD4FC: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD500: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BD504: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BD508: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD50C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BD510: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BD514: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD518: bne         $t0, $a3, L_800BD4DC
    if (ctx->r8 != ctx->r7) {
        // 0x800BD51C: sb          $t8, 0x0($t9)
        MEM_B(0X0, ctx->r25) = ctx->r24;
            goto L_800BD4DC;
    }
    // 0x800BD51C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BD520: beq         $a3, $t1, L_800BD620
    if (ctx->r7 == ctx->r9) {
        // 0x800BD524: nop
    
            goto L_800BD620;
    }
    // 0x800BD524: nop

L_800BD528:
    // 0x800BD528: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD52C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800BD530: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD534: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD538: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD53C: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD540: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BD544: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD548: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD54C: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD550: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD554: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD558: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD55C: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD560: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD564: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BD568: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD56C: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD570: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD574: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD578: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BD57C: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BD580: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD584: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD588: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BD58C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BD590: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD594: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BD598: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BD59C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD5A0: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BD5A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD5A8: addu        $t6, $a0, $v1
    ctx->r14 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD5AC: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD5B0: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD5B4: lbu         $t8, 0x0($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X0);
    // 0x800BD5B8: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BD5BC: addu        $a2, $t8, $t7
    ctx->r6 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD5C0: sra         $t9, $a2, 1
    ctx->r25 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD5C4: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x800BD5C8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD5CC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD5D0: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x800BD5D4: sb          $t9, 0x0($t8)
    MEM_B(0X0, ctx->r24) = ctx->r25;
    // 0x800BD5D8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800BD5DC: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BD5E0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD5E4: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x800BD5E8: addu        $v0, $a0, $a1
    ctx->r2 = ADD32(ctx->r4, ctx->r5);
    // 0x800BD5EC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800BD5F0: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BD5F4: addu        $a1, $a1, $s4
    ctx->r5 = ADD32(ctx->r5, ctx->r20);
    // 0x800BD5F8: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD5FC: sra         $t8, $a2, 1
    ctx->r24 = S32(SIGNED(ctx->r6) >> 1);
    // 0x800BD600: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800BD604: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BD608: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BD60C: addu        $t9, $t7, $v1
    ctx->r25 = ADD32(ctx->r15, ctx->r3);
    // 0x800BD610: addu        $v1, $v1, $s4
    ctx->r3 = ADD32(ctx->r3, ctx->r20);
    // 0x800BD614: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BD618: bne         $a3, $t1, L_800BD528
    if (ctx->r7 != ctx->r9) {
        // 0x800BD61C: sb          $t8, 0x0($t9)
        MEM_B(0X0, ctx->r25) = ctx->r24;
            goto L_800BD528;
    }
    // 0x800BD61C: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
L_800BD620:
    // 0x800BD620: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD624: lw          $a0, -0x5F28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5F28);
    // 0x800BD628: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
L_800BD62C:
    // 0x800BD62C: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
    // 0x800BD630: slt         $at, $t2, $a0
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BD634: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD638: bne         $at, $zero, L_800BD2A4
    if (ctx->r1 != 0) {
        // 0x800BD63C: addiu       $t3, $t3, 0x8
        ctx->r11 = ADD32(ctx->r11, 0X8);
            goto L_800BD2A4;
    }
    // 0x800BD63C: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800BD640: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BD644: lw          $v1, -0x5F24($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5F24);
    // 0x800BD648: nop

L_800BD64C:
    // 0x800BD64C: lw          $t6, 0x184($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X184);
    // 0x800BD650: nop

    // 0x800BD654: addiu       $t8, $t6, 0x1
    ctx->r24 = ADD32(ctx->r14, 0X1);
    // 0x800BD658: slt         $at, $t8, $v1
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BD65C: bne         $at, $zero, L_800BD290
    if (ctx->r1 != 0) {
        // 0x800BD660: sw          $t8, 0x184($sp)
        MEM_W(0X184, ctx->r29) = ctx->r24;
            goto L_800BD290;
    }
    // 0x800BD660: sw          $t8, 0x184($sp)
    MEM_W(0X184, ctx->r29) = ctx->r24;
    // 0x800BD664: lw          $t7, 0x190($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X190);
    // 0x800BD668: nop

    // 0x800BD66C: lh          $v0, 0x1A($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X1A);
    // 0x800BD670: nop

L_800BD674:
    // 0x800BD674: blez        $v0, L_800BD73C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BD678: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_800BD73C;
    }
    // 0x800BD678: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x800BD67C: lw          $t9, 0x90($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X90);
    // 0x800BD680: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BD684: multu       $t9, $t9
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r25)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD688: lw          $t0, 0xA0($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XA0);
    // 0x800BD68C: lw          $a0, 0x190($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X190);
    // 0x800BD690: addiu       $v1, $v1, 0x317C
    ctx->r3 = ADD32(ctx->r3, 0X317C);
    // 0x800BD694: mflo        $ra
    ctx->r31 = lo;
    // 0x800BD698: nop

    // 0x800BD69C: nop

    // 0x800BD6A0: multu       $t9, $s4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD6A4: mflo        $t5
    ctx->r13 = lo;
    // 0x800BD6A8: nop

    // 0x800BD6AC: nop

L_800BD6B0:
    // 0x800BD6B0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD6B4: addu        $t9, $t4, $s4
    ctx->r25 = ADD32(ctx->r12, ctx->r20);
    // 0x800BD6B8: addu        $t8, $t6, $t4
    ctx->r24 = ADD32(ctx->r14, ctx->r12);
    // 0x800BD6BC: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800BD6C0: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800BD6C4: sb          $t7, -0x4($t0)
    MEM_B(-0X4, ctx->r8) = ctx->r15;
    // 0x800BD6C8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD6CC: nop

    // 0x800BD6D0: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD6D4: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800BD6D8: addu        $t9, $t5, $t4
    ctx->r25 = ADD32(ctx->r13, ctx->r12);
    // 0x800BD6DC: sb          $t7, -0x3($t0)
    MEM_B(-0X3, ctx->r8) = ctx->r15;
    // 0x800BD6E0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD6E4: nop

    // 0x800BD6E8: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD6EC: lbu         $t7, 0x0($t8)
    ctx->r15 = MEM_BU(ctx->r24, 0X0);
    // 0x800BD6F0: addu        $t9, $ra, $t4
    ctx->r25 = ADD32(ctx->r31, ctx->r12);
    // 0x800BD6F4: sb          $t7, -0x2($t0)
    MEM_B(-0X2, ctx->r8) = ctx->r15;
    // 0x800BD6F8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BD6FC: nop

    // 0x800BD700: addu        $t8, $t9, $t6
    ctx->r24 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD704: lbu         $t7, -0x1($t8)
    ctx->r15 = MEM_BU(ctx->r24, -0X1);
    // 0x800BD708: nop

    // 0x800BD70C: sb          $t7, -0x1($t0)
    MEM_B(-0X1, ctx->r8) = ctx->r15;
    // 0x800BD710: lw          $t9, 0x18C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X18C);
    // 0x800BD714: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800BD718: addiu       $t6, $t9, 0x1
    ctx->r14 = ADD32(ctx->r25, 0X1);
    // 0x800BD71C: sw          $t6, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r14;
    // 0x800BD720: lh          $v0, 0x1A($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X1A);
    // 0x800BD724: addu        $t4, $t4, $t8
    ctx->r12 = ADD32(ctx->r12, ctx->r24);
    // 0x800BD728: slt         $at, $t6, $v0
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BD72C: bne         $at, $zero, L_800BD6B0
    if (ctx->r1 != 0) {
        // 0x800BD730: nop
    
            goto L_800BD6B0;
    }
    // 0x800BD730: nop

    // 0x800BD734: sw          $zero, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = 0;
    // 0x800BD738: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_800BD73C:
    // 0x800BD73C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BD740: blez        $v0, L_800BDC04
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800BD744: addiu       $v1, $v1, 0x317C
        ctx->r3 = ADD32(ctx->r3, 0X317C);
            goto L_800BDC04;
    }
    // 0x800BD744: addiu       $v1, $v1, 0x317C
    ctx->r3 = ADD32(ctx->r3, 0X317C);
    // 0x800BD748: sw          $zero, 0x80($sp)
    MEM_W(0X80, ctx->r29) = 0;
    // 0x800BD74C: addiu       $t1, $sp, 0x160
    ctx->r9 = ADD32(ctx->r29, 0X160);
L_800BD750:
    // 0x800BD750: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BD754: lw          $t7, 0x30D8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30D8);
    // 0x800BD758: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800BD75C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BD760: addu        $a1, $t7, $t9
    ctx->r5 = ADD32(ctx->r15, ctx->r25);
    // 0x800BD764: lbu         $t6, 0xB($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XB);
    // 0x800BD768: lw          $a0, -0x5F28($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5F28);
    // 0x800BD76C: lbu         $t8, 0xA($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD770: multu       $t6, $a0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r4)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD774: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD778: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD77C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BD780: addu        $s5, $t8, $t7
    ctx->r21 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD784: sll         $t6, $s5, 3
    ctx->r14 = S32(ctx->r21 << 3);
    // 0x800BD788: addu        $a2, $t9, $t6
    ctx->r6 = ADD32(ctx->r25, ctx->r14);
    // 0x800BD78C: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x800BD790: lw          $t7, 0x90($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X90);
    // 0x800BD794: beq         $t8, $at, L_800BDBDC
    if (ctx->r24 == ctx->r1) {
        // 0x800BD798: nop
    
            goto L_800BDBDC;
    }
    // 0x800BD798: nop

    // 0x800BD79C: multu       $t7, $t7
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD7A0: lw          $t6, 0x18C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18C);
    // 0x800BD7A4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800BD7A8: lw          $t3, -0x5F24($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X5F24);
    // 0x800BD7AC: lw          $t9, 0xA0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA0);
    // 0x800BD7B0: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x800BD7B4: addiu       $t2, $a0, -0x1
    ctx->r10 = ADD32(ctx->r4, -0X1);
    // 0x800BD7B8: addiu       $v0, $sp, 0x140
    ctx->r2 = ADD32(ctx->r29, 0X140);
    // 0x800BD7BC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x800BD7C0: addiu       $t3, $t3, -0x1
    ctx->r11 = ADD32(ctx->r11, -0X1);
    // 0x800BD7C4: addu        $t0, $t9, $t8
    ctx->r8 = ADD32(ctx->r25, ctx->r24);
    // 0x800BD7C8: mflo        $ra
    ctx->r31 = lo;
    // 0x800BD7CC: nop

    // 0x800BD7D0: nop

    // 0x800BD7D4: multu       $t7, $s4
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BD7D8: mflo        $t5
    ctx->r13 = lo;
    // 0x800BD7DC: nop

    // 0x800BD7E0: nop

L_800BD7E4:
    // 0x800BD7E4: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800BD7E8: sltu        $at, $v0, $t1
    ctx->r1 = ctx->r2 < ctx->r9 ? 1 : 0;
    // 0x800BD7EC: bne         $at, $zero, L_800BD7E4
    if (ctx->r1 != 0) {
        // 0x800BD7F0: sw          $v1, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r3;
            goto L_800BD7E4;
    }
    // 0x800BD7F0: sw          $v1, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r3;
    // 0x800BD7F4: lbu         $t7, 0xB($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0XB);
    // 0x800BD7F8: nop

    // 0x800BD7FC: blez        $t7, L_800BD874
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800BD800: nop
    
            goto L_800BD874;
    }
    // 0x800BD800: nop

    // 0x800BD804: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD808: lw          $t9, 0xA4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD80C: blez        $t6, L_800BD830
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800BD810: sll         $t8, $s5, 3
        ctx->r24 = S32(ctx->r21 << 3);
            goto L_800BD830;
    }
    // 0x800BD810: sll         $t8, $s5, 3
    ctx->r24 = S32(ctx->r21 << 3);
    // 0x800BD814: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800BD818: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BD81C: negu        $t9, $t6
    ctx->r25 = SUB32(0, ctx->r14);
    // 0x800BD820: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800BD824: lw          $t6, -0x8($t8)
    ctx->r14 = MEM_W(ctx->r24, -0X8);
    // 0x800BD828: nop

    // 0x800BD82C: sw          $t6, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r14;
L_800BD830:
    // 0x800BD830: lw          $t7, 0xA4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD834: sll         $t9, $s5, 3
    ctx->r25 = S32(ctx->r21 << 3);
    // 0x800BD838: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x800BD83C: addu        $t8, $t7, $t9
    ctx->r24 = ADD32(ctx->r15, ctx->r25);
    // 0x800BD840: negu        $t7, $t6
    ctx->r15 = SUB32(0, ctx->r14);
    // 0x800BD844: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD848: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800BD84C: nop

    // 0x800BD850: sw          $t9, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r25;
    // 0x800BD854: lbu         $t6, 0xA($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD858: nop

    // 0x800BD85C: slt         $at, $t6, $t2
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BD860: beq         $at, $zero, L_800BD874
    if (ctx->r1 == 0) {
        // 0x800BD864: nop
    
            goto L_800BD874;
    }
    // 0x800BD864: nop

    // 0x800BD868: lw          $t8, 0x8($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X8);
    // 0x800BD86C: nop

    // 0x800BD870: sw          $t8, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r24;
L_800BD874:
    // 0x800BD874: lbu         $v1, 0xA($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD878: nop

    // 0x800BD87C: blez        $v1, L_800BD89C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800BD880: slt         $at, $v1, $t2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_800BD89C;
    }
    // 0x800BD880: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BD884: lw          $t7, -0x8($a2)
    ctx->r15 = MEM_W(ctx->r6, -0X8);
    // 0x800BD888: nop

    // 0x800BD88C: sw          $t7, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r15;
    // 0x800BD890: lbu         $v1, 0xA($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD894: nop

    // 0x800BD898: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
L_800BD89C:
    // 0x800BD89C: beq         $at, $zero, L_800BD8B0
    if (ctx->r1 == 0) {
        // 0x800BD8A0: sll         $v1, $a0, 3
        ctx->r3 = S32(ctx->r4 << 3);
            goto L_800BD8B0;
    }
    // 0x800BD8A0: sll         $v1, $a0, 3
    ctx->r3 = S32(ctx->r4 << 3);
    // 0x800BD8A4: lw          $t9, 0x8($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X8);
    // 0x800BD8A8: nop

    // 0x800BD8AC: sw          $t9, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r25;
L_800BD8B0:
    // 0x800BD8B0: lbu         $t6, 0xB($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0XB);
    // 0x800BD8B4: lw          $t8, 0xA4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XA4);
    // 0x800BD8B8: slt         $at, $t6, $t3
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800BD8BC: beq         $at, $zero, L_800BD914
    if (ctx->r1 == 0) {
        // 0x800BD8C0: nop
    
            goto L_800BD914;
    }
    // 0x800BD8C0: nop

    // 0x800BD8C4: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD8C8: sll         $t7, $s5, 3
    ctx->r15 = S32(ctx->r21 << 3);
    // 0x800BD8CC: blez        $t9, L_800BD8E4
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BD8D0: addu        $v0, $t8, $t7
        ctx->r2 = ADD32(ctx->r24, ctx->r15);
            goto L_800BD8E4;
    }
    // 0x800BD8D0: addu        $v0, $t8, $t7
    ctx->r2 = ADD32(ctx->r24, ctx->r15);
    // 0x800BD8D4: addu        $t6, $v0, $v1
    ctx->r14 = ADD32(ctx->r2, ctx->r3);
    // 0x800BD8D8: lw          $t8, -0x8($t6)
    ctx->r24 = MEM_W(ctx->r14, -0X8);
    // 0x800BD8DC: nop

    // 0x800BD8E0: sw          $t8, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r24;
L_800BD8E4:
    // 0x800BD8E4: addu        $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x800BD8E8: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800BD8EC: nop

    // 0x800BD8F0: sw          $t7, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r15;
    // 0x800BD8F4: lbu         $t9, 0xA($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0XA);
    // 0x800BD8F8: nop

    // 0x800BD8FC: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800BD900: beq         $at, $zero, L_800BD918
    if (ctx->r1 == 0) {
        // 0x800BD904: lw          $t8, 0x140($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X140);
            goto L_800BD918;
    }
    // 0x800BD904: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x800BD908: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x800BD90C: nop

    // 0x800BD910: sw          $t6, 0x15C($sp)
    MEM_W(0X15C, ctx->r29) = ctx->r14;
L_800BD914:
    // 0x800BD914: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
L_800BD918:
    // 0x800BD918: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x800BD91C: lbu         $a2, 0x0($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X0);
    // 0x800BD920: beq         $a0, $t8, L_800BD940
    if (ctx->r4 == ctx->r24) {
        // 0x800BD924: addiu       $a3, $zero, 0x1
        ctx->r7 = ADD32(0, 0X1);
            goto L_800BD940;
    }
    // 0x800BD924: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BD928: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x800BD92C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BD930: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x800BD934: lbu         $t6, 0x3($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X3);
    // 0x800BD938: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BD93C: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_800BD940:
    // 0x800BD940: lw          $t8, 0x144($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X144);
    // 0x800BD944: lw          $v1, 0xA0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA0);
    // 0x800BD948: beq         $a0, $t8, L_800BD964
    if (ctx->r4 == ctx->r24) {
        // 0x800BD94C: nop
    
            goto L_800BD964;
    }
    // 0x800BD94C: nop

    // 0x800BD950: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BD954: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x800BD958: lbu         $t6, 0x2($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2);
    // 0x800BD95C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BD960: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_800BD964:
    // 0x800BD964: lw          $t8, 0x14C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X14C);
    // 0x800BD968: nop

    // 0x800BD96C: beq         $a0, $t8, L_800BD988
    if (ctx->r4 == ctx->r24) {
        // 0x800BD970: nop
    
            goto L_800BD988;
    }
    // 0x800BD970: nop

    // 0x800BD974: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x800BD978: addu        $t9, $v1, $t7
    ctx->r25 = ADD32(ctx->r3, ctx->r15);
    // 0x800BD97C: lbu         $t6, 0x1($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X1);
    // 0x800BD980: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BD984: addu        $a2, $a2, $t6
    ctx->r6 = ADD32(ctx->r6, ctx->r14);
L_800BD988:
    // 0x800BD988: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BD98C: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BD990: bne         $a3, $zero, L_800BD99C
    if (ctx->r7 != 0) {
        // 0x800BD994: nop
    
            goto L_800BD99C;
    }
    // 0x800BD994: nop

    // 0x800BD998: break       7
    do_break(2148260248);
L_800BD99C:
    // 0x800BD99C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BD9A0: bne         $a3, $at, L_800BD9B4
    if (ctx->r7 != ctx->r1) {
        // 0x800BD9A4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BD9B4;
    }
    // 0x800BD9A4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BD9A8: bne         $a2, $at, L_800BD9B4
    if (ctx->r6 != ctx->r1) {
        // 0x800BD9AC: nop
    
            goto L_800BD9B4;
    }
    // 0x800BD9AC: nop

    // 0x800BD9B0: break       6
    do_break(2148260272);
L_800BD9B4:
    // 0x800BD9B4: addu        $t9, $t7, $t4
    ctx->r25 = ADD32(ctx->r15, ctx->r12);
    // 0x800BD9B8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BD9BC: mflo        $t8
    ctx->r24 = lo;
    // 0x800BD9C0: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x800BD9C4: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x800BD9C8: lbu         $a2, 0x1($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X1);
    // 0x800BD9CC: beq         $a0, $t6, L_800BD9E8
    if (ctx->r4 == ctx->r14) {
        // 0x800BD9D0: nop
    
            goto L_800BD9E8;
    }
    // 0x800BD9D0: nop

    // 0x800BD9D4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BD9D8: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800BD9DC: lbu         $t9, 0x3($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3);
    // 0x800BD9E0: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BD9E4: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BD9E8:
    // 0x800BD9E8: lw          $t6, 0x148($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X148);
    // 0x800BD9EC: nop

    // 0x800BD9F0: beq         $a0, $t6, L_800BDA0C
    if (ctx->r4 == ctx->r14) {
        // 0x800BD9F4: nop
    
            goto L_800BDA0C;
    }
    // 0x800BD9F4: nop

    // 0x800BD9F8: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BD9FC: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDA00: lbu         $t9, 0x2($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X2);
    // 0x800BDA04: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDA08: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDA0C:
    // 0x800BDA0C: lw          $t6, 0x150($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X150);
    // 0x800BDA10: nop

    // 0x800BDA14: beq         $a0, $t6, L_800BDA30
    if (ctx->r4 == ctx->r14) {
        // 0x800BDA18: nop
    
            goto L_800BDA30;
    }
    // 0x800BDA18: nop

    // 0x800BDA1C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BDA20: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x800BDA24: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800BDA28: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDA2C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDA30:
    // 0x800BDA30: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BDA34: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x800BDA38: bne         $a3, $zero, L_800BDA44
    if (ctx->r7 != 0) {
        // 0x800BDA3C: nop
    
            goto L_800BDA44;
    }
    // 0x800BDA3C: nop

    // 0x800BDA40: break       7
    do_break(2148260416);
L_800BDA44:
    // 0x800BDA44: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDA48: bne         $a3, $at, L_800BDA5C
    if (ctx->r7 != ctx->r1) {
        // 0x800BDA4C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDA5C;
    }
    // 0x800BDA4C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDA50: bne         $a2, $at, L_800BDA5C
    if (ctx->r6 != ctx->r1) {
        // 0x800BDA54: nop
    
            goto L_800BDA5C;
    }
    // 0x800BDA54: nop

    // 0x800BDA58: break       6
    do_break(2148260440);
L_800BDA5C:
    // 0x800BDA5C: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x800BDA60: addu        $t9, $t8, $s4
    ctx->r25 = ADD32(ctx->r24, ctx->r20);
    // 0x800BDA64: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BDA68: mflo        $t6
    ctx->r14 = lo;
    // 0x800BDA6C: sb          $t6, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r14;
    // 0x800BDA70: lw          $t7, 0x14C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14C);
    // 0x800BDA74: lbu         $a2, 0x2($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X2);
    // 0x800BDA78: beq         $a0, $t7, L_800BDA94
    if (ctx->r4 == ctx->r15) {
        // 0x800BDA7C: nop
    
            goto L_800BDA94;
    }
    // 0x800BDA7C: nop

    // 0x800BDA80: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDA84: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800BDA88: lbu         $t9, 0x3($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X3);
    // 0x800BDA8C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BDA90: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDA94:
    // 0x800BDA94: lw          $t7, 0x154($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X154);
    // 0x800BDA98: nop

    // 0x800BDA9C: beq         $a0, $t7, L_800BDAB8
    if (ctx->r4 == ctx->r15) {
        // 0x800BDAA0: nop
    
            goto L_800BDAB8;
    }
    // 0x800BDAA0: nop

    // 0x800BDAA4: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDAA8: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800BDAAC: lbu         $t9, 0x1($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X1);
    // 0x800BDAB0: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDAB4: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDAB8:
    // 0x800BDAB8: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x800BDABC: nop

    // 0x800BDAC0: beq         $a0, $t7, L_800BDADC
    if (ctx->r4 == ctx->r15) {
        // 0x800BDAC4: nop
    
            goto L_800BDADC;
    }
    // 0x800BDAC4: nop

    // 0x800BDAC8: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BDACC: addu        $t6, $v1, $t8
    ctx->r14 = ADD32(ctx->r3, ctx->r24);
    // 0x800BDAD0: lbu         $t9, 0x0($t6)
    ctx->r25 = MEM_BU(ctx->r14, 0X0);
    // 0x800BDAD4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDAD8: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDADC:
    // 0x800BDADC: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BDAE0: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x800BDAE4: bne         $a3, $zero, L_800BDAF0
    if (ctx->r7 != 0) {
        // 0x800BDAE8: nop
    
            goto L_800BDAF0;
    }
    // 0x800BDAE8: nop

    // 0x800BDAEC: break       7
    do_break(2148260588);
L_800BDAF0:
    // 0x800BDAF0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDAF4: bne         $a3, $at, L_800BDB08
    if (ctx->r7 != ctx->r1) {
        // 0x800BDAF8: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDB08;
    }
    // 0x800BDAF8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDAFC: bne         $a2, $at, L_800BDB08
    if (ctx->r6 != ctx->r1) {
        // 0x800BDB00: nop
    
            goto L_800BDB08;
    }
    // 0x800BDB00: nop

    // 0x800BDB04: break       6
    do_break(2148260612);
L_800BDB08:
    // 0x800BDB08: addu        $t6, $t8, $t4
    ctx->r14 = ADD32(ctx->r24, ctx->r12);
    // 0x800BDB0C: addu        $t9, $t6, $t5
    ctx->r25 = ADD32(ctx->r14, ctx->r13);
    // 0x800BDB10: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800BDB14: mflo        $t7
    ctx->r15 = lo;
    // 0x800BDB18: sb          $t7, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r15;
    // 0x800BDB1C: lw          $t8, 0x150($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X150);
    // 0x800BDB20: lbu         $a2, 0x3($t0)
    ctx->r6 = MEM_BU(ctx->r8, 0X3);
    // 0x800BDB24: beq         $a0, $t8, L_800BDB40
    if (ctx->r4 == ctx->r24) {
        // 0x800BDB28: nop
    
            goto L_800BDB40;
    }
    // 0x800BDB28: nop

    // 0x800BDB2C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800BDB30: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800BDB34: lbu         $t9, 0x2($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X2);
    // 0x800BDB38: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x800BDB3C: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDB40:
    // 0x800BDB40: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x800BDB44: nop

    // 0x800BDB48: beq         $a0, $t8, L_800BDB64
    if (ctx->r4 == ctx->r24) {
        // 0x800BDB4C: nop
    
            goto L_800BDB64;
    }
    // 0x800BDB4C: nop

    // 0x800BDB50: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800BDB54: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800BDB58: lbu         $t9, 0x1($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X1);
    // 0x800BDB5C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDB60: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDB64:
    // 0x800BDB64: lw          $t8, 0x15C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X15C);
    // 0x800BDB68: nop

    // 0x800BDB6C: beq         $a0, $t8, L_800BDB88
    if (ctx->r4 == ctx->r24) {
        // 0x800BDB70: nop
    
            goto L_800BDB88;
    }
    // 0x800BDB70: nop

    // 0x800BDB74: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x800BDB78: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x800BDB7C: lbu         $t9, 0x0($t7)
    ctx->r25 = MEM_BU(ctx->r15, 0X0);
    // 0x800BDB80: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BDB84: addu        $a2, $a2, $t9
    ctx->r6 = ADD32(ctx->r6, ctx->r25);
L_800BDB88:
    // 0x800BDB88: div         $zero, $a2, $a3
    lo = S32(S64(S32(ctx->r6)) / S64(S32(ctx->r7))); hi = S32(S64(S32(ctx->r6)) % S64(S32(ctx->r7)));
    // 0x800BDB8C: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BDB90: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BDB94: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x800BDB98: addu        $t9, $t7, $ra
    ctx->r25 = ADD32(ctx->r15, ctx->r31);
    // 0x800BDB9C: addiu       $v1, $v1, 0x317C
    ctx->r3 = ADD32(ctx->r3, 0X317C);
    // 0x800BDBA0: bne         $a3, $zero, L_800BDBAC
    if (ctx->r7 != 0) {
        // 0x800BDBA4: nop
    
            goto L_800BDBAC;
    }
    // 0x800BDBA4: nop

    // 0x800BDBA8: break       7
    do_break(2148260776);
L_800BDBAC:
    // 0x800BDBAC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800BDBB0: bne         $a3, $at, L_800BDBC4
    if (ctx->r7 != ctx->r1) {
        // 0x800BDBB4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800BDBC4;
    }
    // 0x800BDBB4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BDBB8: bne         $a2, $at, L_800BDBC4
    if (ctx->r6 != ctx->r1) {
        // 0x800BDBBC: nop
    
            goto L_800BDBC4;
    }
    // 0x800BDBBC: nop

    // 0x800BDBC0: break       6
    do_break(2148260800);
L_800BDBC4:
    // 0x800BDBC4: mflo        $t8
    ctx->r24 = lo;
    // 0x800BDBC8: sb          $t8, -0x1($t9)
    MEM_B(-0X1, ctx->r25) = ctx->r24;
    // 0x800BDBCC: lw          $t6, 0x190($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X190);
    // 0x800BDBD0: nop

    // 0x800BDBD4: lh          $v0, 0x1A($t6)
    ctx->r2 = MEM_H(ctx->r14, 0X1A);
    // 0x800BDBD8: nop

L_800BDBDC:
    // 0x800BDBDC: lw          $t7, 0x18C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18C);
    // 0x800BDBE0: lw          $t9, 0x80($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X80);
    // 0x800BDBE4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BDBE8: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800BDBEC: slt         $at, $t8, $v0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800BDBF0: addiu       $t6, $t9, 0x1C
    ctx->r14 = ADD32(ctx->r25, 0X1C);
    // 0x800BDBF4: sw          $t6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r14;
    // 0x800BDBF8: sw          $t8, 0x18C($sp)
    MEM_W(0X18C, ctx->r29) = ctx->r24;
    // 0x800BDBFC: bne         $at, $zero, L_800BD750
    if (ctx->r1 != 0) {
        // 0x800BDC00: addu        $t4, $t4, $t7
        ctx->r12 = ADD32(ctx->r12, ctx->r15);
            goto L_800BD750;
    }
    // 0x800BDC00: addu        $t4, $t4, $t7
    ctx->r12 = ADD32(ctx->r12, ctx->r15);
L_800BDC04:
    // 0x800BDC04: lw          $a0, 0xA8($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA8);
    // 0x800BDC08: jal         0x80071140
    // 0x800BDC0C: nop

    mempool_free(rdram, ctx);
        goto after_6;
    // 0x800BDC0C: nop

    after_6:
    // 0x800BDC10: lw          $a0, 0xA4($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA4);
    // 0x800BDC14: jal         0x80071140
    // 0x800BDC18: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x800BDC18: nop

    after_7:
    // 0x800BDC1C: lw          $a0, 0xA0($sp)
    ctx->r4 = MEM_W(ctx->r29, 0XA0);
    // 0x800BDC20: jal         0x80071140
    // 0x800BDC24: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x800BDC24: nop

    after_8:
    // 0x800BDC28: lw          $ra, 0x64($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X64);
    // 0x800BDC2C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BDC30: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BDC34: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BDC38: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BDC3C: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BDC40: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BDC44: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BDC48: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BDC4C: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BDC50: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BDC54: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x800BDC58: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x800BDC5C: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x800BDC60: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x800BDC64: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800BDC68: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800BDC6C: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800BDC70: lw          $s7, 0x5C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X5C);
    // 0x800BDC74: lw          $fp, 0x60($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X60);
    // 0x800BDC78: jr          $ra
    // 0x800BDC7C: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    return;
    // 0x800BDC7C: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
;}
RECOMP_FUNC void music_channel_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001114: andi        $a1, $a0, 0xFF
    ctx->r5 = ctx->r4 & 0XFF;
    // 0x80001118: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000111C: slti        $at, $a1, 0x10
    ctx->r1 = SIGNED(ctx->r5) < 0X10 ? 1 : 0;
    // 0x80001120: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001124: beq         $at, $zero, L_8000113C
    if (ctx->r1 == 0) {
        // 0x80001128: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_8000113C;
    }
    // 0x80001128: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8000112C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80001130: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80001134: jal         0x80063AF0
    // 0x80001138: nop

    alSeqChOff(rdram, ctx);
        goto after_0;
    // 0x80001138: nop

    after_0:
L_8000113C:
    // 0x8000113C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001140: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001144: jr          $ra
    // 0x80001148: nop

    return;
    // 0x80001148: nop

;}
RECOMP_FUNC void obj_loop_setuppoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800391BC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800391C0: jr          $ra
    // 0x800391C4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x800391C4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void hud_wrong_way(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A5A64: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A5A68: lw          $t6, 0x6D0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D0C);
    // 0x800A5A6C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800A5A70: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A5A74: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A5A78: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800A5A7C: bne         $a2, $t6, L_800A5A8C
    if (ctx->r6 != ctx->r14) {
        // 0x800A5A80: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_800A5A8C;
    }
    // 0x800A5A80: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800A5A84: jal         0x8007BF1C
    // 0x800A5A88: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    sprite_opaque(rdram, ctx);
        goto after_0;
    // 0x800A5A88: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
L_800A5A8C:
    // 0x800A5A8C: lw          $t7, 0x18($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X18);
    // 0x800A5A90: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A5A94: lbu         $t8, 0x1FC($t7)
    ctx->r24 = MEM_BU(ctx->r15, 0X1FC);
    // 0x800A5A98: nop

    // 0x800A5A9C: slti        $at, $t8, 0x79
    ctx->r1 = SIGNED(ctx->r24) < 0X79 ? 1 : 0;
    // 0x800A5AA0: bne         $at, $zero, L_800A5BC0
    if (ctx->r1 != 0) {
        // 0x800A5AA4: nop
    
            goto L_800A5BC0;
    }
    // 0x800A5AA4: nop

    // 0x800A5AA8: lw          $t9, 0x6D0C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D0C);
    // 0x800A5AAC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5AB0: bne         $t9, $zero, L_800A5AE4
    if (ctx->r25 != 0) {
        // 0x800A5AB4: addiu       $t0, $t0, 0x6CDC
        ctx->r8 = ADD32(ctx->r8, 0X6CDC);
            goto L_800A5AE4;
    }
    // 0x800A5AB4: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5AB8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5ABC: nop

    // 0x800A5AC0: lb          $t1, 0x47C($v0)
    ctx->r9 = MEM_B(ctx->r2, 0X47C);
    // 0x800A5AC4: lwc1        $f4, 0x46C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A5AC8: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800A5ACC: nop

    // 0x800A5AD0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5AD4: c.eq.s      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.fl == ctx->f8.fl;
    // 0x800A5AD8: nop

    // 0x800A5ADC: bc1f        L_800A5BC0
    if (!c1cs) {
        // 0x800A5AE0: nop
    
            goto L_800A5BC0;
    }
    // 0x800A5AE0: nop

L_800A5AE4:
    // 0x800A5AE4: jal         0x8006EAA0
    // 0x800A5AE8: nop

    is_game_paused(rdram, ctx);
        goto after_1;
    // 0x800A5AE8: nop

    after_1:
    // 0x800A5AEC: bne         $v0, $zero, L_800A5BC0
    if (ctx->r2 != 0) {
        // 0x800A5AF0: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800A5BC0;
    }
    // 0x800A5AF0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A5AF4: addiu       $v1, $v1, 0x6D38
    ctx->r3 = ADD32(ctx->r3, 0X6D38);
    // 0x800A5AF8: lbu         $v0, 0x0($v1)
    ctx->r2 = MEM_BU(ctx->r3, 0X0);
    // 0x800A5AFC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A5B00: bne         $v0, $zero, L_800A5B14
    if (ctx->r2 != 0) {
        // 0x800A5B04: addiu       $a3, $a3, 0x6D6C
        ctx->r7 = ADD32(ctx->r7, 0X6D6C);
            goto L_800A5B14;
    }
    // 0x800A5B04: addiu       $a3, $a3, 0x6D6C
    ctx->r7 = ADD32(ctx->r7, 0X6D6C);
    // 0x800A5B08: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800A5B0C: nop

    // 0x800A5B10: bne         $t2, $zero, L_800A5BA4
    if (ctx->r10 != 0) {
        // 0x800A5B14: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_800A5BA4;
    }
L_800A5B14:
    // 0x800A5B14: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5B18: addiu       $a2, $a2, 0x6D40
    ctx->r6 = ADD32(ctx->r6, 0X6D40);
    // 0x800A5B1C: lw          $t3, 0x0($a2)
    ctx->r11 = MEM_W(ctx->r6, 0X0);
    // 0x800A5B20: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A5B24: bne         $t3, $zero, L_800A5BA4
    if (ctx->r11 != 0) {
        // 0x800A5B28: addiu       $a3, $a3, 0x6D6C
        ctx->r7 = ADD32(ctx->r7, 0X6D6C);
            goto L_800A5BA4;
    }
    // 0x800A5B28: addiu       $a3, $a3, 0x6D6C
    ctx->r7 = ADD32(ctx->r7, 0X6D6C);
    // 0x800A5B2C: bne         $v0, $zero, L_800A5B54
    if (ctx->r2 != 0) {
        // 0x800A5B30: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A5B54;
    }
    // 0x800A5B30: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A5B34: jal         0x8006F94C
    // 0x800A5B38: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800A5B38: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    after_2:
    // 0x800A5B3C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A5B40: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5B44: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x800A5B48: addiu       $a2, $a2, 0x6D40
    ctx->r6 = ADD32(ctx->r6, 0X6D40);
    // 0x800A5B4C: bne         $at, $zero, L_800A5B88
    if (ctx->r1 != 0) {
        // 0x800A5B50: addiu       $v1, $v1, 0x6D38
        ctx->r3 = ADD32(ctx->r3, 0X6D38);
            goto L_800A5B88;
    }
    // 0x800A5B50: addiu       $v1, $v1, 0x6D38
    ctx->r3 = ADD32(ctx->r3, 0X6D38);
L_800A5B54:
    // 0x800A5B54: sb          $zero, 0x0($v1)
    MEM_B(0X0, ctx->r3) = 0;
    // 0x800A5B58: addiu       $a0, $zero, 0x66
    ctx->r4 = ADD32(0, 0X66);
    // 0x800A5B5C: jal         0x80001D04
    // 0x800A5B60: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A5B60: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_3:
    // 0x800A5B64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A5B68: jal         0x8006F94C
    // 0x800A5B6C: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800A5B6C: addiu       $a1, $zero, 0x1E0
    ctx->r5 = ADD32(0, 0X1E0);
    after_4:
    // 0x800A5B70: addiu       $t4, $v0, 0x78
    ctx->r12 = ADD32(ctx->r2, 0X78);
    // 0x800A5B74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A5B78: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A5B7C: addiu       $a3, $a3, 0x6D6C
    ctx->r7 = ADD32(ctx->r7, 0X6D6C);
    // 0x800A5B80: b           L_800A5BA4
    // 0x800A5B84: sw          $t4, 0x6D6C($at)
    MEM_W(0X6D6C, ctx->r1) = ctx->r12;
        goto L_800A5BA4;
    // 0x800A5B84: sw          $t4, 0x6D6C($at)
    MEM_W(0X6D6C, ctx->r1) = ctx->r12;
L_800A5B88:
    // 0x800A5B88: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800A5B8C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x800A5B90: addiu       $a0, $zero, 0x67
    ctx->r4 = ADD32(0, 0X67);
    // 0x800A5B94: jal         0x80001D04
    // 0x800A5B98: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x800A5B98: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    after_5:
    // 0x800A5B9C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A5BA0: addiu       $a3, $a3, 0x6D6C
    ctx->r7 = ADD32(ctx->r7, 0X6D6C);
L_800A5BA4:
    // 0x800A5BA4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800A5BA8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5BAC: nop

    // 0x800A5BB0: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x800A5BB4: bgez        $t8, L_800A5BC0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A5BB8: sw          $t8, 0x0($a3)
        MEM_W(0X0, ctx->r7) = ctx->r24;
            goto L_800A5BC0;
    }
    // 0x800A5BB8: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800A5BBC: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_800A5BC0:
    // 0x800A5BC0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5BC4: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5BC8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5BCC: lw          $t8, 0x18($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X18);
    // 0x800A5BD0: lb          $v1, 0x47A($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X47A);
    // 0x800A5BD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x800A5BD8: beq         $v1, $zero, L_800A5DEC
    if (ctx->r3 == 0) {
        // 0x800A5BDC: nop
    
            goto L_800A5DEC;
    }
    // 0x800A5BDC: nop

    // 0x800A5BE0: bne         $a2, $v1, L_800A5F00
    if (ctx->r6 != ctx->r3) {
        // 0x800A5BE4: nop
    
            goto L_800A5F00;
    }
    // 0x800A5BE4: nop

    // 0x800A5BE8: lb          $v1, 0x47B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X47B);
    // 0x800A5BEC: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5BF0: bne         $a2, $v1, L_800A5CD0
    if (ctx->r6 != ctx->r3) {
        // 0x800A5BF4: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800A5CD0;
    }
    // 0x800A5BF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A5BF8: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800A5BFC: subu        $t2, $t2, $t1
    ctx->r10 = SUB32(ctx->r10, ctx->r9);
    // 0x800A5C00: sll         $t2, $t2, 2
    ctx->r10 = S32(ctx->r10 << 2);
    // 0x800A5C04: addu        $t2, $t2, $t1
    ctx->r10 = ADD32(ctx->r10, ctx->r9);
    // 0x800A5C08: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800A5C0C: lwc1        $f16, 0x46C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A5C10: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5C14: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A5C18: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A5C1C: add.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A5C20: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5C24: swc1        $f18, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f18.u32l;
    // 0x800A5C28: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5C2C: nop

    // 0x800A5C30: lb          $t3, 0x47C($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X47C);
    // 0x800A5C34: lwc1        $f4, 0x46C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A5C38: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800A5C3C: nop

    // 0x800A5C40: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5C44: c.lt.s      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.fl < ctx->f4.fl;
    // 0x800A5C48: nop

    // 0x800A5C4C: bc1f        L_800A5C60
    if (!c1cs) {
        // 0x800A5C50: nop
    
            goto L_800A5C60;
    }
    // 0x800A5C50: nop

    // 0x800A5C54: swc1        $f2, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f2.u32l;
    // 0x800A5C58: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5C5C: nop

L_800A5C60:
    // 0x800A5C60: lwc1        $f8, 0x48C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X48C);
    // 0x800A5C64: nop

    // 0x800A5C68: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A5C6C: swc1        $f10, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f10.u32l;
    // 0x800A5C70: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5C74: nop

    // 0x800A5C78: lb          $t4, 0x49C($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X49C);
    // 0x800A5C7C: lwc1        $f18, 0x48C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48C);
    // 0x800A5C80: mtc1        $t4, $f16
    ctx->f16.u32l = ctx->r12;
    // 0x800A5C84: nop

    // 0x800A5C88: cvt.s.w     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    ctx->f2.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A5C8C: c.lt.s      $f18, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f18.fl < ctx->f2.fl;
    // 0x800A5C90: nop

    // 0x800A5C94: bc1f        L_800A5CA4
    if (!c1cs) {
        // 0x800A5C98: lw          $t5, 0x18($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X18);
            goto L_800A5CA4;
    }
    // 0x800A5C98: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
    // 0x800A5C9C: swc1        $f2, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f2.u32l;
    // 0x800A5CA0: lw          $t5, 0x18($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X18);
L_800A5CA4:
    // 0x800A5CA4: nop

    // 0x800A5CA8: lbu         $t6, 0x1FC($t5)
    ctx->r14 = MEM_BU(ctx->r13, 0X1FC);
    // 0x800A5CAC: nop

    // 0x800A5CB0: slti        $at, $t6, 0x5B
    ctx->r1 = SIGNED(ctx->r14) < 0X5B ? 1 : 0;
    // 0x800A5CB4: beq         $at, $zero, L_800A5D44
    if (ctx->r1 == 0) {
        // 0x800A5CB8: nop
    
            goto L_800A5D44;
    }
    // 0x800A5CB8: nop

    // 0x800A5CBC: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A5CC0: jal         0x80001D04
    // 0x800A5CC4: sb          $t7, 0x47B($t8)
    MEM_B(0X47B, ctx->r24) = ctx->r15;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x800A5CC4: sb          $t7, 0x47B($t8)
    MEM_B(0X47B, ctx->r24) = ctx->r15;
    after_6:
    // 0x800A5CC8: b           L_800A5D44
    // 0x800A5CCC: nop

        goto L_800A5D44;
    // 0x800A5CCC: nop

L_800A5CD0:
    // 0x800A5CD0: bne         $v1, $at, L_800A5D44
    if (ctx->r3 != ctx->r1) {
        // 0x800A5CD4: nop
    
            goto L_800A5D44;
    }
    // 0x800A5CD4: nop

    // 0x800A5CD8: lw          $t9, 0x1C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1C);
    // 0x800A5CDC: lwc1        $f4, 0x46C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A5CE0: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x800A5CE4: subu        $t1, $t1, $t9
    ctx->r9 = SUB32(ctx->r9, ctx->r25);
    // 0x800A5CE8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800A5CEC: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x800A5CF0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800A5CF4: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A5CF8: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A5CFC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A5D00: sub.s       $f8, $f4, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A5D04: swc1        $f8, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f8.u32l;
    // 0x800A5D08: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5D0C: nop

    // 0x800A5D10: lwc1        $f10, 0x48C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X48C);
    // 0x800A5D14: nop

    // 0x800A5D18: add.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f0.fl;
    // 0x800A5D1C: swc1        $f16, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f16.u32l;
    // 0x800A5D20: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5D24: nop

    // 0x800A5D28: lwc1        $f18, 0x46C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X46C);
    // 0x800A5D2C: nop

    // 0x800A5D30: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800A5D34: nop

    // 0x800A5D38: bc1f        L_800A5D44
    if (!c1cs) {
        // 0x800A5D3C: nop
    
            goto L_800A5D44;
    }
    // 0x800A5D3C: nop

    // 0x800A5D40: sb          $zero, 0x47A($v0)
    MEM_B(0X47A, ctx->r2) = 0;
L_800A5D44:
    // 0x800A5D44: jal         0x8006EAA0
    // 0x800A5D48: nop

    is_game_paused(rdram, ctx);
        goto after_7;
    // 0x800A5D48: nop

    after_7:
    // 0x800A5D4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5D50: bne         $v0, $zero, L_800A5F00
    if (ctx->r2 != 0) {
        // 0x800A5D54: addiu       $t0, $t0, 0x6CDC
        ctx->r8 = ADD32(ctx->r8, 0X6CDC);
            goto L_800A5F00;
    }
    // 0x800A5D54: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5D58: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5D5C: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5D60: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A5D64: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A5D68: addiu       $t2, $v1, 0x8
    ctx->r10 = ADD32(ctx->r3, 0X8);
    // 0x800A5D6C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x800A5D70: addiu       $t4, $zero, -0x60
    ctx->r12 = ADD32(0, -0X60);
    // 0x800A5D74: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800A5D78: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x800A5D7C: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5D80: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5D84: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5D88: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A5D8C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A5D90: jal         0x800AA600
    // 0x800A5D94: addiu       $a3, $a3, 0x460
    ctx->r7 = ADD32(ctx->r7, 0X460);
    hud_element_render(rdram, ctx);
        goto after_8;
    // 0x800A5D94: addiu       $a3, $a3, 0x460
    ctx->r7 = ADD32(ctx->r7, 0X460);
    after_8:
    // 0x800A5D98: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A5D9C: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A5DA0: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A5DA4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5DA8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A5DAC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A5DB0: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5DB4: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A5DB8: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A5DBC: jal         0x800AA600
    // 0x800A5DC0: addiu       $a3, $a3, 0x480
    ctx->r7 = ADD32(ctx->r7, 0X480);
    hud_element_render(rdram, ctx);
        goto after_9;
    // 0x800A5DC0: addiu       $a3, $a3, 0x480
    ctx->r7 = ADD32(ctx->r7, 0X480);
    after_9:
    // 0x800A5DC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A5DC8: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A5DCC: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800A5DD0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A5DD4: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800A5DD8: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x800A5DDC: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A5DE0: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x800A5DE4: b           L_800A5F00
    // 0x800A5DE8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
        goto L_800A5F00;
    // 0x800A5DE8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
L_800A5DEC:
    // 0x800A5DEC: lbu         $t9, 0x1FC($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X1FC);
    // 0x800A5DF0: nop

    // 0x800A5DF4: slti        $at, $t9, 0x79
    ctx->r1 = SIGNED(ctx->r25) < 0X79 ? 1 : 0;
    // 0x800A5DF8: bne         $at, $zero, L_800A5F00
    if (ctx->r1 != 0) {
        // 0x800A5DFC: nop
    
            goto L_800A5F00;
    }
    // 0x800A5DFC: nop

    // 0x800A5E00: sb          $a2, 0x47A($v0)
    MEM_B(0X47A, ctx->r2) = ctx->r6;
    // 0x800A5E04: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E08: addiu       $t2, $zero, -0x1F
    ctx->r10 = ADD32(0, -0X1F);
    // 0x800A5E0C: sb          $a2, 0x47B($t1)
    MEM_B(0X47B, ctx->r9) = ctx->r6;
    // 0x800A5E10: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E14: addiu       $t4, $zero, 0x34
    ctx->r12 = ADD32(0, 0X34);
    // 0x800A5E18: sb          $t2, 0x47C($t3)
    MEM_B(0X47C, ctx->r11) = ctx->r10;
    // 0x800A5E1C: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E20: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A5E24: sb          $t4, 0x49C($t5)
    MEM_B(0X49C, ctx->r13) = ctx->r12;
    // 0x800A5E28: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E2C: addiu       $t7, $zero, -0x15
    ctx->r15 = ADD32(0, -0X15);
    // 0x800A5E30: sb          $zero, 0x47D($t6)
    MEM_B(0X47D, ctx->r14) = 0;
    // 0x800A5E34: lw          $v1, 0x6D0C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6D0C);
    // 0x800A5E38: nop

    // 0x800A5E3C: bne         $a2, $v1, L_800A5E5C
    if (ctx->r6 != ctx->r3) {
        // 0x800A5E40: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_800A5E5C;
    }
    // 0x800A5E40: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800A5E44: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E48: addiu       $t9, $zero, 0x2A
    ctx->r25 = ADD32(0, 0X2A);
    // 0x800A5E4C: sb          $t7, 0x47C($t8)
    MEM_B(0X47C, ctx->r24) = ctx->r15;
    // 0x800A5E50: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E54: b           L_800A5EB4
    // 0x800A5E58: sb          $t9, 0x49C($t1)
    MEM_B(0X49C, ctx->r9) = ctx->r25;
        goto L_800A5EB4;
    // 0x800A5E58: sb          $t9, 0x49C($t1)
    MEM_B(0X49C, ctx->r9) = ctx->r25;
L_800A5E5C:
    // 0x800A5E5C: bne         $at, $zero, L_800A5EB4
    if (ctx->r1 != 0) {
        // 0x800A5E60: nop
    
            goto L_800A5EB4;
    }
    // 0x800A5E60: nop

    // 0x800A5E64: lw          $t2, 0x18($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X18);
    // 0x800A5E68: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A5E6C: lh          $v0, 0x0($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X0);
    // 0x800A5E70: addiu       $t3, $zero, -0x64
    ctx->r11 = ADD32(0, -0X64);
    // 0x800A5E74: beq         $v0, $zero, L_800A5E84
    if (ctx->r2 == 0) {
        // 0x800A5E78: nop
    
            goto L_800A5E84;
    }
    // 0x800A5E78: nop

    // 0x800A5E7C: bne         $v0, $at, L_800A5E9C
    if (ctx->r2 != ctx->r1) {
        // 0x800A5E80: nop
    
            goto L_800A5E9C;
    }
    // 0x800A5E80: nop

L_800A5E84:
    // 0x800A5E84: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E88: addiu       $t5, $zero, -0x37
    ctx->r13 = ADD32(0, -0X37);
    // 0x800A5E8C: sb          $t3, 0x47C($t4)
    MEM_B(0X47C, ctx->r12) = ctx->r11;
    // 0x800A5E90: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A5E94: b           L_800A5EB4
    // 0x800A5E98: sb          $t5, 0x49C($t6)
    MEM_B(0X49C, ctx->r14) = ctx->r13;
        goto L_800A5EB4;
    // 0x800A5E98: sb          $t5, 0x49C($t6)
    MEM_B(0X49C, ctx->r14) = ctx->r13;
L_800A5E9C:
    // 0x800A5E9C: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A5EA0: addiu       $t7, $zero, 0x3B
    ctx->r15 = ADD32(0, 0X3B);
    // 0x800A5EA4: sb          $t7, 0x47C($t8)
    MEM_B(0X47C, ctx->r24) = ctx->r15;
    // 0x800A5EA8: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x800A5EAC: addiu       $t9, $zero, 0x68
    ctx->r25 = ADD32(0, 0X68);
    // 0x800A5EB0: sb          $t9, 0x49C($t1)
    MEM_B(0X49C, ctx->r9) = ctx->r25;
L_800A5EB4:
    // 0x800A5EB4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5EB8: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A5EBC: lb          $t2, 0x49C($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X49C);
    // 0x800A5EC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A5EC4: addiu       $t3, $t2, 0xC8
    ctx->r11 = ADD32(ctx->r10, 0XC8);
    // 0x800A5EC8: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800A5ECC: nop

    // 0x800A5ED0: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A5ED4: swc1        $f8, 0x48C($v0)
    MEM_W(0X48C, ctx->r2) = ctx->f8.u32l;
    // 0x800A5ED8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A5EDC: nop

    // 0x800A5EE0: lb          $t4, 0x49C($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X49C);
    // 0x800A5EE4: nop

    // 0x800A5EE8: addiu       $t5, $t4, -0xC8
    ctx->r13 = ADD32(ctx->r12, -0XC8);
    // 0x800A5EEC: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A5EF0: nop

    // 0x800A5EF4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A5EF8: jal         0x80001D04
    // 0x800A5EFC: swc1        $f16, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f16.u32l;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x800A5EFC: swc1        $f16, 0x46C($v0)
    MEM_W(0X46C, ctx->r2) = ctx->f16.u32l;
    after_10:
L_800A5F00:
    // 0x800A5F00: jal         0x8007BF1C
    // 0x800A5F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_11;
    // 0x800A5F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A5F08: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A5F0C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800A5F10: jr          $ra
    // 0x800A5F14: nop

    return;
    // 0x800A5F14: nop

;}
RECOMP_FUNC void alCents2Ratio(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C99E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C99E4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800C99E8: bltz        $a0, L_800C99FC
    if (SIGNED(ctx->r4) < 0) {
        // 0x800C99EC: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800C99FC;
    }
    // 0x800C99EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C99F0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C99F4: b           L_800C9A04
    // 0x800C99F8: lwc1        $f0, -0x6B40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B40);
        goto L_800C9A04;
    // 0x800C99F8: lwc1        $f0, -0x6B40($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B40);
L_800C99FC:
    // 0x800C99FC: lwc1        $f0, -0x6B3C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X6B3C);
    // 0x800C9A00: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
L_800C9A04:
    // 0x800C9A04: beq         $a0, $zero, L_800C9A28
    if (ctx->r4 == 0) {
        // 0x800C9A08: andi        $t6, $a0, 0x1
        ctx->r14 = ctx->r4 & 0X1;
            goto L_800C9A28;
    }
L_800C9A08:
    // 0x800C9A08: andi        $t6, $a0, 0x1
    ctx->r14 = ctx->r4 & 0X1;
    // 0x800C9A0C: beq         $t6, $zero, L_800C9A1C
    if (ctx->r14 == 0) {
        // 0x800C9A10: sra         $t7, $a0, 1
        ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
            goto L_800C9A1C;
    }
    // 0x800C9A10: sra         $t7, $a0, 1
    ctx->r15 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800C9A14: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800C9A18: nop

L_800C9A1C:
    // 0x800C9A1C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C9A20: bne         $t7, $zero, L_800C9A08
    if (ctx->r15 != 0) {
        // 0x800C9A24: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800C9A08;
    }
    // 0x800C9A24: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
L_800C9A28:
    // 0x800C9A28: jr          $ra
    // 0x800C9A2C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    return;
    // 0x800C9A2C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
;}
RECOMP_FUNC void check_viewport_background_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066910: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066914: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066918: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006691C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066920: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066924: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80066928: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8006692C: lw          $v0, -0x2F6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2F6C);
    // 0x80066930: nop

    // 0x80066934: andi        $t7, $v0, 0x1
    ctx->r15 = ctx->r2 & 0X1;
    // 0x80066938: jr          $ra
    // 0x8006693C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    return;
    // 0x8006693C: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
;}
RECOMP_FUNC void savemenu_check_space(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800860A8: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800860AC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800860B0: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800860B4: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800860B8: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800860BC: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x800860C0: beq         $t7, $zero, L_800861B8
    if (ctx->r15 == 0) {
        // 0x800860C4: sll         $t2, $a0, 2
        ctx->r10 = S32(ctx->r4 << 2);
            goto L_800861B8;
    }
    // 0x800860C4: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x800860C8: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x800860CC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800860D0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800860D4: addu        $a1, $t9, $a2
    ctx->r5 = ADD32(ctx->r25, ctx->r6);
    // 0x800860D8: addiu       $t3, $t3, 0x6A20
    ctx->r11 = ADD32(ctx->r11, 0X6A20);
    // 0x800860DC: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x800860E0: sw          $a2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r6;
    // 0x800860E4: addiu       $a1, $a1, 0xC
    ctx->r5 = ADD32(ctx->r5, 0XC);
    // 0x800860E8: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x800860EC: jal         0x80076194
    // 0x800860F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    get_free_space(rdram, ctx);
        goto after_0;
    // 0x800860F0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    after_0:
    // 0x800860F4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800860F8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800860FC: lw          $a1, 0x30($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X30);
    // 0x80086100: lw          $a2, 0x1C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X1C);
    // 0x80086104: lw          $a3, 0x34($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X34);
    // 0x80086108: bne         $v0, $zero, L_80086170
    if (ctx->r2 != 0) {
        // 0x8008610C: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_80086170;
    }
    // 0x8008610C: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80086110: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80086114: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80086118: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x8008611C: addu        $v0, $a1, $t5
    ctx->r2 = ADD32(ctx->r5, ctx->r13);
    // 0x80086120: lw          $t6, 0xC($v0)
    ctx->r14 = MEM_W(ctx->r2, 0XC);
    // 0x80086124: nop

    // 0x80086128: slt         $at, $t6, $t7
    ctx->r1 = SIGNED(ctx->r14) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008612C: bne         $at, $zero, L_800861BC
    if (ctx->r1 != 0) {
        // 0x80086130: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800861BC;
    }
    // 0x80086130: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086134: lw          $t8, 0x0($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X0);
    // 0x80086138: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8008613C: blez        $t8, L_800861BC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80086140: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800861BC;
    }
    // 0x80086140: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80086144: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x80086148: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x8008614C: nop

    // 0x80086150: sll         $t2, $t1, 4
    ctx->r10 = S32(ctx->r9 << 4);
    // 0x80086154: addu        $t3, $a1, $t2
    ctx->r11 = ADD32(ctx->r5, ctx->r10);
    // 0x80086158: sb          $a0, 0x6($t3)
    MEM_B(0X6, ctx->r11) = ctx->r4;
    // 0x8008615C: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80086160: nop

    // 0x80086164: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x80086168: b           L_800861B8
    // 0x8008616C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
        goto L_800861B8;
    // 0x8008616C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_80086170:
    // 0x80086170: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80086174: andi        $t7, $v0, 0xFF
    ctx->r15 = ctx->r2 & 0XFF;
    // 0x80086178: bgez        $t6, L_80086194
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8008617C: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80086194;
    }
    // 0x8008617C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80086180: bne         $t7, $at, L_80086194
    if (ctx->r15 != ctx->r1) {
        // 0x80086184: nop
    
            goto L_80086194;
    }
    // 0x80086184: nop

    // 0x80086188: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8008618C: b           L_800861B8
    // 0x80086190: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
        goto L_800861B8;
    // 0x80086190: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_80086194:
    // 0x80086194: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80086198: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8008619C: beq         $v1, $at, L_800861B8
    if (ctx->r3 == ctx->r1) {
        // 0x800861A0: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800861B8;
    }
    // 0x800861A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800861A4: beq         $v1, $at, L_800861B8
    if (ctx->r3 == ctx->r1) {
        // 0x800861A8: addiu       $at, $zero, 0x9
        ctx->r1 = ADD32(0, 0X9);
            goto L_800861B8;
    }
    // 0x800861A8: addiu       $at, $zero, 0x9
    ctx->r1 = ADD32(0, 0X9);
    // 0x800861AC: beq         $v1, $at, L_800861BC
    if (ctx->r3 == ctx->r1) {
        // 0x800861B0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800861BC;
    }
    // 0x800861B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800861B4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_800861B8:
    // 0x800861B8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800861BC:
    // 0x800861BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800861C0: jr          $ra
    // 0x800861C4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    return;
    // 0x800861C4: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
;}
RECOMP_FUNC void __osBlockSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D0D88: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800D0D8C: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x800D0D90: sw          $a3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r7;
    // 0x800D0D94: lbu         $t6, 0x4F($sp)
    ctx->r14 = MEM_BU(ctx->r29, 0X4F);
    // 0x800D0D98: lw          $t7, 0x40($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X40);
    // 0x800D0D9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800D0DA0: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800D0DA4: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800D0DA8: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x800D0DAC: sb          $t6, 0x65($t7)
    MEM_B(0X65, ctx->r15) = ctx->r14;
    // 0x800D0DB0: jal         0x800D5FDC
    // 0x800D0DB4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_0;
    // 0x800D0DB4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_0:
    // 0x800D0DB8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D0DBC: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800D0DC0: beq         $t8, $zero, L_800D0DD0
    if (ctx->r24 == 0) {
        // 0x800D0DC4: nop
    
            goto L_800D0DD0;
    }
    // 0x800D0DC4: nop

    // 0x800D0DC8: b           L_800D0E68
    // 0x800D0DCC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
        goto L_800D0E68;
    // 0x800D0DCC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800D0DD0:
    // 0x800D0DD0: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
L_800D0DD4:
    // 0x800D0DD4: lbu         $t0, 0x47($sp)
    ctx->r8 = MEM_BU(ctx->r29, 0X47);
    // 0x800D0DD8: lw          $t9, 0x40($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X40);
    // 0x800D0DDC: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x800D0DE0: sll         $t1, $t0, 3
    ctx->r9 = S32(ctx->r8 << 3);
    // 0x800D0DE4: addiu       $a3, $sp, 0x18
    ctx->r7 = ADD32(ctx->r29, 0X18);
    // 0x800D0DE8: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x800D0DEC: lw          $a1, 0x8($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X8);
    // 0x800D0DF0: jal         0x800CDCA0
    // 0x800D0DF4: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    __osContRamRead_recomp(rdram, ctx);
        goto after_1;
    // 0x800D0DF4: addu        $a2, $t1, $t2
    ctx->r6 = ADD32(ctx->r9, ctx->r10);
    after_1:
    // 0x800D0DF8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D0DFC: lw          $t3, 0x38($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X38);
    // 0x800D0E00: beq         $t3, $zero, L_800D0E20
    if (ctx->r11 == 0) {
        // 0x800D0E04: nop
    
            goto L_800D0E20;
    }
    // 0x800D0E04: nop

    // 0x800D0E08: lw          $t4, 0x40($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X40);
    // 0x800D0E0C: sb          $zero, 0x65($t4)
    MEM_B(0X65, ctx->r12) = 0;
    // 0x800D0E10: jal         0x800D5FDC
    // 0x800D0E14: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_2;
    // 0x800D0E14: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_2:
    // 0x800D0E18: b           L_800D0E68
    // 0x800D0E1C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
        goto L_800D0E68;
    // 0x800D0E1C: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800D0E20:
    // 0x800D0E20: addiu       $a0, $sp, 0x18
    ctx->r4 = ADD32(ctx->r29, 0X18);
    // 0x800D0E24: jal         0x800D52F0
    // 0x800D0E28: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    __osSumcalc(rdram, ctx);
        goto after_3;
    // 0x800D0E28: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_3:
    // 0x800D0E2C: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x800D0E30: lhu         $t6, 0x0($t5)
    ctx->r14 = MEM_HU(ctx->r13, 0X0);
    // 0x800D0E34: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800D0E38: sh          $t7, 0x0($t5)
    MEM_H(0X0, ctx->r13) = ctx->r15;
    // 0x800D0E3C: lw          $t8, 0x3C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X3C);
    // 0x800D0E40: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800D0E44: slti        $at, $t9, 0x8
    ctx->r1 = SIGNED(ctx->r25) < 0X8 ? 1 : 0;
    // 0x800D0E48: bne         $at, $zero, L_800D0DD4
    if (ctx->r1 != 0) {
        // 0x800D0E4C: sw          $t9, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r25;
            goto L_800D0DD4;
    }
    // 0x800D0E4C: sw          $t9, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r25;
    // 0x800D0E50: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800D0E54: sb          $zero, 0x65($t0)
    MEM_B(0X65, ctx->r8) = 0;
    // 0x800D0E58: jal         0x800D5FDC
    // 0x800D0E5C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    __osPfsSelectBank_recomp(rdram, ctx);
        goto after_4;
    // 0x800D0E5C: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    after_4:
    // 0x800D0E60: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800D0E64: lw          $v0, 0x38($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X38);
L_800D0E68:
    // 0x800D0E68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800D0E6C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800D0E70: jr          $ra
    // 0x800D0E74: nop

    return;
    // 0x800D0E74: nop

;}
RECOMP_FUNC void load_menu_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F900: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F904: addiu       $t1, $t1, -0xB64
    ctx->r9 = ADD32(ctx->r9, -0XB64);
    // 0x8007F908: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8007F90C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8007F910: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007F914: bne         $v1, $zero, L_8007F93C
    if (ctx->r3 != 0) {
        // 0x8007F918: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_8007F93C;
    }
    // 0x8007F918: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8007F91C: addiu       $a0, $zero, 0x9
    ctx->r4 = ADD32(0, 0X9);
    // 0x8007F920: jal         0x80076C58
    // 0x8007F924: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x8007F924: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8007F928: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F92C: addiu       $t1, $t1, -0xB64
    ctx->r9 = ADD32(ctx->r9, -0XB64);
    // 0x8007F930: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8007F934: sw          $v0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r2;
    // 0x8007F938: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8007F93C:
    // 0x8007F93C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007F940: beq         $a1, $at, L_8007F970
    if (ctx->r5 == ctx->r1) {
        // 0x8007F944: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_8007F970;
    }
    // 0x8007F944: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007F948: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007F94C: beq         $a1, $at, L_8007F978
    if (ctx->r5 == ctx->r1) {
        // 0x8007F950: addiu       $a2, $zero, 0x2
        ctx->r6 = ADD32(0, 0X2);
            goto L_8007F978;
    }
    // 0x8007F950: addiu       $a2, $zero, 0x2
    ctx->r6 = ADD32(0, 0X2);
    // 0x8007F954: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007F958: beq         $a1, $at, L_8007F968
    if (ctx->r5 == ctx->r1) {
        // 0x8007F95C: nop
    
            goto L_8007F968;
    }
    // 0x8007F95C: nop

    // 0x8007F960: b           L_8007F978
    // 0x8007F964: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
        goto L_8007F978;
    // 0x8007F964: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_8007F968:
    // 0x8007F968: b           L_8007F978
    // 0x8007F96C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
        goto L_8007F978;
    // 0x8007F96C: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
L_8007F970:
    // 0x8007F970: b           L_8007F978
    // 0x8007F974: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
        goto L_8007F978;
    // 0x8007F974: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
L_8007F978:
    // 0x8007F978: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8007F97C: addu        $v0, $v1, $t6
    ctx->r2 = ADD32(ctx->r3, ctx->r14);
    // 0x8007F980: addiu       $t0, $t0, -0xB60
    ctx->r8 = ADD32(ctx->r8, -0XB60);
    // 0x8007F984: lw          $a3, 0x4($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X4);
    // 0x8007F988: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007F98C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8007F990: subu        $a3, $a3, $a2
    ctx->r7 = SUB32(ctx->r7, ctx->r6);
    // 0x8007F994: beq         $a1, $zero, L_8007FF7C
    if (ctx->r5 == 0) {
        // 0x8007F998: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8007FF7C;
    }
    // 0x8007F998: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007F99C: jal         0x80076E68
    // 0x8007F9A0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    asset_load(rdram, ctx);
        goto after_1;
    // 0x8007F9A0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_1:
    // 0x8007F9A4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007F9A8: addiu       $t1, $t1, -0xB64
    ctx->r9 = ADD32(ctx->r9, -0XB64);
    // 0x8007F9AC: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x8007F9B0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007F9B4: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007F9B8: addiu       $t0, $t0, -0xB60
    ctx->r8 = ADD32(ctx->r8, -0XB60);
    // 0x8007F9BC: blez        $t8, L_8007FA10
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8007F9C0: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_8007FA10;
    }
    // 0x8007F9C0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007F9C4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8007F9C8: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
L_8007F9CC:
    // 0x8007F9CC: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8007F9D0: nop

    // 0x8007F9D4: addu        $v0, $a1, $v1
    ctx->r2 = ADD32(ctx->r5, ctx->r3);
    // 0x8007F9D8: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x8007F9DC: nop

    // 0x8007F9E0: bne         $a3, $a0, L_8007F9F0
    if (ctx->r7 != ctx->r4) {
        // 0x8007F9E4: addu        $t9, $a0, $a1
        ctx->r25 = ADD32(ctx->r4, ctx->r5);
            goto L_8007F9F0;
    }
    // 0x8007F9E4: addu        $t9, $a0, $a1
    ctx->r25 = ADD32(ctx->r4, ctx->r5);
    // 0x8007F9E8: b           L_8007F9F4
    // 0x8007F9EC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_8007F9F4;
    // 0x8007F9EC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_8007F9F0:
    // 0x8007F9F0: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_8007F9F4:
    // 0x8007F9F4: lw          $t2, 0x0($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X0);
    // 0x8007F9F8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8007F9FC: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007FA00: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8007FA04: slt         $at, $a2, $t3
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8007FA08: bne         $at, $zero, L_8007F9CC
    if (ctx->r1 != 0) {
        // 0x8007FA0C: nop
    
            goto L_8007F9CC;
    }
    // 0x8007FA0C: nop

L_8007FA10:
    // 0x8007FA10: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x8007FA14: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007FA18: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x8007FA1C: addiu       $a1, $a1, 0x69D0
    ctx->r5 = ADD32(ctx->r5, 0X69D0);
    // 0x8007FA20: sw          $t4, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r12;
    // 0x8007FA24: lw          $t5, 0x4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4);
    // 0x8007FA28: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FA2C: sw          $t5, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r13;
    // 0x8007FA30: lw          $t6, 0x8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X8);
    // 0x8007FA34: addiu       $v0, $v0, -0x5C4
    ctx->r2 = ADD32(ctx->r2, -0X5C4);
    // 0x8007FA38: sw          $t6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r14;
    // 0x8007FA3C: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x8007FA40: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007FA44: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x8007FA48: lw          $t8, 0x10($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X10);
    // 0x8007FA4C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FA50: sw          $t8, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r24;
    // 0x8007FA54: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x8007FA58: addiu       $v1, $v1, -0x260
    ctx->r3 = ADD32(ctx->r3, -0X260);
    // 0x8007FA5C: sw          $t9, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r25;
    // 0x8007FA60: lw          $t2, 0x18($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X18);
    // 0x8007FA64: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007FA68: sw          $t2, 0x4C($v0)
    MEM_W(0X4C, ctx->r2) = ctx->r10;
    // 0x8007FA6C: lw          $t3, 0x18($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X18);
    // 0x8007FA70: addiu       $a3, $a3, 0xBEC
    ctx->r7 = ADD32(ctx->r7, 0XBEC);
    // 0x8007FA74: sw          $t3, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->r11;
    // 0x8007FA78: lw          $t4, 0x1C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1C);
    // 0x8007FA7C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007FA80: sw          $t4, 0x69E0($at)
    MEM_W(0X69E0, ctx->r1) = ctx->r12;
    // 0x8007FA84: lw          $t5, 0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X38);
    // 0x8007FA88: addiu       $t1, $t1, 0xCEC
    ctx->r9 = ADD32(ctx->r9, 0XCEC);
    // 0x8007FA8C: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8007FA90: lw          $t6, 0x3C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X3C);
    // 0x8007FA94: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007FA98: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007FA9C: lw          $t7, 0x40($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X40);
    // 0x8007FAA0: addiu       $a2, $a2, 0xE4C
    ctx->r6 = ADD32(ctx->r6, 0XE4C);
    // 0x8007FAA4: sw          $t7, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r15;
    // 0x8007FAA8: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x8007FAAC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FAB0: sw          $t8, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r24;
    // 0x8007FAB4: lw          $t9, 0x74($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X74);
    // 0x8007FAB8: addiu       $v0, $v0, -0x5F0
    ctx->r2 = ADD32(ctx->r2, -0X5F0);
    // 0x8007FABC: sw          $t9, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r25;
    // 0x8007FAC0: lw          $t2, 0x78($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X78);
    // 0x8007FAC4: lui         $at, 0x200
    ctx->r1 = S32(0X200 << 16);
    // 0x8007FAC8: sw          $t2, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r10;
    // 0x8007FACC: lw          $t3, 0x7C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X7C);
    // 0x8007FAD0: nop

    // 0x8007FAD4: sw          $t3, 0x114($t1)
    MEM_W(0X114, ctx->r9) = ctx->r11;
    // 0x8007FAD8: lw          $t4, 0x7C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X7C);
    // 0x8007FADC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8007FAE0: sw          $t4, 0x134($t1)
    MEM_W(0X134, ctx->r9) = ctx->r12;
    // 0x8007FAE4: lw          $t5, 0x80($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X80);
    // 0x8007FAE8: nop

    // 0x8007FAEC: sw          $t5, 0x14($a2)
    MEM_W(0X14, ctx->r6) = ctx->r13;
    // 0x8007FAF0: lw          $t6, 0x80($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X80);
    // 0x8007FAF4: nop

    // 0x8007FAF8: sw          $t6, 0x34($a2)
    MEM_W(0X34, ctx->r6) = ctx->r14;
    // 0x8007FAFC: lw          $t7, 0x24($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X24);
    // 0x8007FB00: nop

    // 0x8007FB04: sw          $t7, 0x54($a2)
    MEM_W(0X54, ctx->r6) = ctx->r15;
    // 0x8007FB08: lw          $t8, 0x28($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X28);
    // 0x8007FB0C: nop

    // 0x8007FB10: sw          $t8, 0xB4($a2)
    MEM_W(0XB4, ctx->r6) = ctx->r24;
    // 0x8007FB14: lw          $t9, 0x88($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X88);
    // 0x8007FB18: nop

    // 0x8007FB1C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007FB20: lw          $t3, 0x644C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X644C);
    // 0x8007FB24: nop

    // 0x8007FB28: and         $t5, $t3, $at
    ctx->r13 = ctx->r11 & ctx->r1;
    // 0x8007FB2C: beq         $t5, $zero, L_8007FB40
    if (ctx->r13 == 0) {
        // 0x8007FB30: nop
    
            goto L_8007FB40;
    }
    // 0x8007FB30: nop

    // 0x8007FB34: lw          $t6, 0x2D8($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2D8);
    // 0x8007FB38: b           L_8007FB4C
    // 0x8007FB3C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
        goto L_8007FB4C;
    // 0x8007FB3C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
L_8007FB40:
    // 0x8007FB40: lw          $t7, 0x2DC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X2DC);
    // 0x8007FB44: nop

    // 0x8007FB48: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
L_8007FB4C:
    // 0x8007FB4C: lw          $t8, 0x18($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X18);
    // 0x8007FB50: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007FB54: sw          $t8, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r24;
    // 0x8007FB58: lw          $t9, 0x294($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X294);
    // 0x8007FB5C: addiu       $a2, $a2, 0x3B0
    ctx->r6 = ADD32(ctx->r6, 0X3B0);
    // 0x8007FB60: sw          $t9, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r25;
    // 0x8007FB64: lw          $t2, 0x44($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X44);
    // 0x8007FB68: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007FB6C: sw          $t2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r10;
    // 0x8007FB70: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x8007FB74: addiu       $a3, $a3, -0x51C
    ctx->r7 = ADD32(ctx->r7, -0X51C);
    // 0x8007FB78: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x8007FB7C: lw          $t4, 0x120($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X120);
    // 0x8007FB80: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FB84: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x8007FB88: lw          $t5, 0x124($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X124);
    // 0x8007FB8C: addiu       $v1, $v1, -0x504
    ctx->r3 = ADD32(ctx->r3, -0X504);
    // 0x8007FB90: sw          $t5, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r13;
    // 0x8007FB94: lw          $t6, 0x128($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X128);
    // 0x8007FB98: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007FB9C: sw          $t6, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r14;
    // 0x8007FBA0: lw          $t7, 0x168($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X168);
    // 0x8007FBA4: addiu       $a1, $a1, -0x4EC
    ctx->r5 = ADD32(ctx->r5, -0X4EC);
    // 0x8007FBA8: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x8007FBAC: lw          $t8, 0x16C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X16C);
    // 0x8007FBB0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007FBB4: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x8007FBB8: lw          $t9, 0x154($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X154);
    // 0x8007FBBC: addiu       $t0, $t0, -0x4D4
    ctx->r8 = ADD32(ctx->r8, -0X4D4);
    // 0x8007FBC0: sw          $t9, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r25;
    // 0x8007FBC4: lw          $t2, 0x168($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X168);
    // 0x8007FBC8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FBCC: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8007FBD0: lw          $t3, 0x174($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X174);
    // 0x8007FBD4: addiu       $v0, $v0, -0x4C0
    ctx->r2 = ADD32(ctx->r2, -0X4C0);
    // 0x8007FBD8: sw          $t3, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r11;
    // 0x8007FBDC: lw          $t4, 0x178($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X178);
    // 0x8007FBE0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007FBE4: sw          $t4, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r12;
    // 0x8007FBE8: lw          $t5, 0x154($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X154);
    // 0x8007FBEC: addiu       $a2, $a2, -0x474
    ctx->r6 = ADD32(ctx->r6, -0X474);
    // 0x8007FBF0: sw          $t5, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r13;
    // 0x8007FBF4: lw          $t6, 0x168($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X168);
    // 0x8007FBF8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FBFC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007FC00: lw          $t7, 0x17C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X17C);
    // 0x8007FC04: addiu       $v1, $v1, -0x4A4
    ctx->r3 = ADD32(ctx->r3, -0X4A4);
    // 0x8007FC08: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007FC0C: lw          $t8, 0x180($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X180);
    // 0x8007FC10: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007FC14: sw          $t8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r24;
    // 0x8007FC18: lw          $t9, 0x154($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X154);
    // 0x8007FC1C: addiu       $a3, $a3, -0x45C
    ctx->r7 = ADD32(ctx->r7, -0X45C);
    // 0x8007FC20: sw          $t9, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r25;
    // 0x8007FC24: lw          $t2, 0x168($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X168);
    // 0x8007FC28: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007FC2C: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x8007FC30: lw          $t3, 0x184($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X184);
    // 0x8007FC34: addiu       $a1, $a1, -0x48C
    ctx->r5 = ADD32(ctx->r5, -0X48C);
    // 0x8007FC38: sw          $t3, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r11;
    // 0x8007FC3C: lw          $t4, 0x188($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X188);
    // 0x8007FC40: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007FC44: sw          $t4, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r12;
    // 0x8007FC48: lw          $t5, 0x168($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X168);
    // 0x8007FC4C: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8007FC50: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007FC54: lw          $t6, 0x18C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X18C);
    // 0x8007FC58: addiu       $t1, $t1, 0x9EC
    ctx->r9 = ADD32(ctx->r9, 0X9EC);
    // 0x8007FC5C: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8007FC60: lw          $t7, 0x190($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X190);
    // 0x8007FC64: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8007FC68: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8007FC6C: lw          $t8, 0x154($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X154);
    // 0x8007FC70: addiu       $t0, $t0, 0x9F8
    ctx->r8 = ADD32(ctx->r8, 0X9F8);
    // 0x8007FC74: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x8007FC78: lw          $t9, 0x168($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X168);
    // 0x8007FC7C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FC80: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007FC84: lw          $t2, 0x198($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X198);
    // 0x8007FC88: addiu       $v0, $v0, -0x444
    ctx->r2 = ADD32(ctx->r2, -0X444);
    // 0x8007FC8C: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x8007FC90: lw          $t3, 0x19C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X19C);
    // 0x8007FC94: nop

    // 0x8007FC98: sw          $t3, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r11;
    // 0x8007FC9C: lw          $t4, 0x188($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X188);
    // 0x8007FCA0: nop

    // 0x8007FCA4: sw          $t4, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->r12;
    // 0x8007FCA8: lw          $t5, 0x168($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X168);
    // 0x8007FCAC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FCB0: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x8007FCB4: lw          $t6, 0x2E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2E0);
    // 0x8007FCB8: addiu       $v1, $v1, 0x278
    ctx->r3 = ADD32(ctx->r3, 0X278);
    // 0x8007FCBC: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007FCC0: lw          $t7, 0x5C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X5C);
    // 0x8007FCC4: nop

    // 0x8007FCC8: sw          $t7, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->r15;
    // 0x8007FCCC: lw          $t8, 0x154($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X154);
    // 0x8007FCD0: nop

    // 0x8007FCD4: sw          $t8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r24;
    // 0x8007FCD8: lw          $t9, 0x264($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X264);
    // 0x8007FCDC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007FCE0: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007FCE4: lw          $t2, 0x268($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X268);
    // 0x8007FCE8: addiu       $a1, $a1, 0x198
    ctx->r5 = ADD32(ctx->r5, 0X198);
    // 0x8007FCEC: sw          $t2, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r10;
    // 0x8007FCF0: lw          $t3, 0x26C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X26C);
    // 0x8007FCF4: nop

    // 0x8007FCF8: sw          $t3, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->r11;
    // 0x8007FCFC: lw          $t4, 0x188($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X188);
    // 0x8007FD00: nop

    // 0x8007FD04: sw          $t4, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->r12;
    // 0x8007FD08: lw          $t5, 0x270($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X270);
    // 0x8007FD0C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007FD10: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x8007FD14: lw          $t6, 0x274($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X274);
    // 0x8007FD18: addiu       $a2, $a2, -0x85C
    ctx->r6 = ADD32(ctx->r6, -0X85C);
    // 0x8007FD1C: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x8007FD20: lw          $t7, 0x278($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X278);
    // 0x8007FD24: nop

    // 0x8007FD28: sw          $t7, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r15;
    // 0x8007FD2C: lw          $t8, 0x188($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X188);
    // 0x8007FD30: nop

    // 0x8007FD34: sw          $t8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r24;
    // 0x8007FD38: lw          $t9, 0x1A0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X1A0);
    // 0x8007FD3C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8007FD40: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007FD44: lw          $t2, 0x1A4($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X1A4);
    // 0x8007FD48: addiu       $a3, $a3, 0x9D8
    ctx->r7 = ADD32(ctx->r7, 0X9D8);
    // 0x8007FD4C: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x8007FD50: lw          $t3, 0x1A8($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X1A8);
    // 0x8007FD54: nop

    // 0x8007FD58: sw          $t3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r11;
    // 0x8007FD5C: lw          $t4, 0x1AC($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X1AC);
    // 0x8007FD60: nop

    // 0x8007FD64: sw          $t4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r12;
    // 0x8007FD68: lw          $t5, 0x1B0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X1B0);
    // 0x8007FD6C: nop

    // 0x8007FD70: sw          $t5, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r13;
    // 0x8007FD74: lw          $t6, 0x1B4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X1B4);
    // 0x8007FD78: nop

    // 0x8007FD7C: sw          $t6, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r14;
    // 0x8007FD80: lw          $t7, 0x188($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X188);
    // 0x8007FD84: nop

    // 0x8007FD88: sw          $t7, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r15;
    // 0x8007FD8C: lw          $t8, 0x224($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X224);
    // 0x8007FD90: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8007FD94: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8007FD98: lw          $t9, 0x90($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X90);
    // 0x8007FD9C: nop

    // 0x8007FDA0: sw          $t9, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r25;
    // 0x8007FDA4: lw          $t2, 0x130($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X130);
    // 0x8007FDA8: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x8007FDAC: sw          $t2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r10;
    // 0x8007FDB0: lw          $t3, 0x130($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X130);
    // 0x8007FDB4: addiu       $a2, $a2, 0x9C4
    ctx->r6 = ADD32(ctx->r6, 0X9C4);
    // 0x8007FDB8: sw          $t3, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r11;
    // 0x8007FDBC: lw          $t4, 0x238($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X238);
    // 0x8007FDC0: nop

    // 0x8007FDC4: sw          $t4, 0x74($a1)
    MEM_W(0X74, ctx->r5) = ctx->r12;
    // 0x8007FDC8: lw          $t5, 0x240($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X240);
    // 0x8007FDCC: nop

    // 0x8007FDD0: sw          $t5, 0xB4($a1)
    MEM_W(0XB4, ctx->r5) = ctx->r13;
    // 0x8007FDD4: lw          $t6, 0x130($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X130);
    // 0x8007FDD8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007FDDC: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x8007FDE0: lw          $t7, 0x130($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X130);
    // 0x8007FDE4: addiu       $a1, $a1, 0x9B0
    ctx->r5 = ADD32(ctx->r5, 0X9B0);
    // 0x8007FDE8: sw          $t7, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r15;
    // 0x8007FDEC: lw          $t8, 0x238($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X238);
    // 0x8007FDF0: nop

    // 0x8007FDF4: sw          $t8, 0x74($v1)
    MEM_W(0X74, ctx->r3) = ctx->r24;
    // 0x8007FDF8: lw          $t9, 0x23C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X23C);
    // 0x8007FDFC: nop

    // 0x8007FE00: sw          $t9, 0xB4($v1)
    MEM_W(0XB4, ctx->r3) = ctx->r25;
    // 0x8007FE04: lw          $t2, 0x240($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X240);
    // 0x8007FE08: nop

    // 0x8007FE0C: sw          $t2, 0xF4($v1)
    MEM_W(0XF4, ctx->r3) = ctx->r10;
    // 0x8007FE10: lw          $t3, 0x114($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X114);
    // 0x8007FE14: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FE18: sw          $t3, 0x9B0($at)
    MEM_W(0X9B0, ctx->r1) = ctx->r11;
    // 0x8007FE1C: lw          $t4, 0x110($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X110);
    // 0x8007FE20: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007FE24: sw          $t4, 0x9C4($at)
    MEM_W(0X9C4, ctx->r1) = ctx->r12;
    // 0x8007FE28: lw          $t5, 0x10C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X10C);
    // 0x8007FE2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007FE30: sw          $t5, 0x9D8($at)
    MEM_W(0X9D8, ctx->r1) = ctx->r13;
    // 0x8007FE34: lw          $t6, 0x2E0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X2E0);
    // 0x8007FE38: sw          $zero, 0x10($t1)
    MEM_W(0X10, ctx->r9) = 0;
    // 0x8007FE3C: sw          $zero, 0x14($t1)
    MEM_W(0X14, ctx->r9) = 0;
    // 0x8007FE40: addiu       $v1, $v1, 0x9EC
    ctx->r3 = ADD32(ctx->r3, 0X9EC);
    // 0x8007FE44: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
L_8007FE48:
    // 0x8007FE48: lw          $t7, 0x2C4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X2C4);
    // 0x8007FE4C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8007FE50: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007FE54: lw          $t8, 0x2C4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C4);
    // 0x8007FE58: sltu        $at, $v1, $t0
    ctx->r1 = ctx->r3 < ctx->r8 ? 1 : 0;
    // 0x8007FE5C: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8007FE60: lw          $t9, 0x2C4($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X2C4);
    // 0x8007FE64: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8007FE68: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x8007FE6C: lw          $t2, 0x2C4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X2C4);
    // 0x8007FE70: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8007FE74: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x8007FE78: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x8007FE7C: bne         $at, $zero, L_8007FE48
    if (ctx->r1 != 0) {
        // 0x8007FE80: sw          $t2, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r10;
            goto L_8007FE48;
    }
    // 0x8007FE80: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8007FE84: lw          $t3, 0x0($t1)
    ctx->r11 = MEM_W(ctx->r9, 0X0);
    // 0x8007FE88: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007FE8C: beq         $t3, $zero, L_8007FEAC
    if (ctx->r11 == 0) {
        // 0x8007FE90: lui         $v0, 0x800E
        ctx->r2 = S32(0X800E << 16);
            goto L_8007FEAC;
    }
    // 0x8007FE90: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8007FE94: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FE98: addiu       $v1, $v1, 0x9EC
    ctx->r3 = ADD32(ctx->r3, 0X9EC);
L_8007FE9C:
    // 0x8007FE9C: lw          $t4, 0x4($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X4);
    // 0x8007FEA0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8007FEA4: bne         $t4, $zero, L_8007FE9C
    if (ctx->r12 != 0) {
        // 0x8007FEA8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8007FE9C;
    }
    // 0x8007FEA8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8007FEAC:
    // 0x8007FEAC: lw          $t5, 0x2E4($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X2E4);
    // 0x8007FEB0: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x8007FEB4: addu        $t7, $t1, $t6
    ctx->r15 = ADD32(ctx->r9, ctx->r14);
    // 0x8007FEB8: sw          $t5, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r13;
    // 0x8007FEBC: lw          $t8, 0x27C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X27C);
    // 0x8007FEC0: addiu       $v0, $v0, 0xA04
    ctx->r2 = ADD32(ctx->r2, 0XA04);
    // 0x8007FEC4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007FEC8: lw          $t9, 0x280($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X280);
    // 0x8007FECC: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FED0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007FED4: lw          $t2, 0x288($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X288);
    // 0x8007FED8: addiu       $v1, $v1, 0xA14
    ctx->r3 = ADD32(ctx->r3, 0XA14);
    // 0x8007FEDC: sw          $t2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r10;
    // 0x8007FEE0: lw          $t3, 0x27C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X27C);
    // 0x8007FEE4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007FEE8: sw          $t3, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r11;
    // 0x8007FEEC: lw          $t4, 0x284($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X284);
    // 0x8007FEF0: addiu       $a1, $a1, -0x28
    ctx->r5 = ADD32(ctx->r5, -0X28);
    // 0x8007FEF4: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x8007FEF8: lw          $t6, 0x288($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X288);
    // 0x8007FEFC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007FF00: sw          $t6, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r14;
    // 0x8007FF04: lw          $t5, 0x260($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X260);
    // 0x8007FF08: addiu       $v0, $a0, 0xC
    ctx->r2 = ADD32(ctx->r4, 0XC);
    // 0x8007FF0C: sw          $t5, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r13;
    // 0x8007FF10: lw          $t7, 0x260($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X260);
    // 0x8007FF14: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007FF18: sw          $t7, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r15;
    // 0x8007FF1C: lw          $t8, 0x298($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X298);
    // 0x8007FF20: addiu       $v1, $v1, 0x38
    ctx->r3 = ADD32(ctx->r3, 0X38);
    // 0x8007FF24: sw          $t8, 0x2C($at)
    MEM_W(0X2C, ctx->r1) = ctx->r24;
    // 0x8007FF28: lw          $t9, 0x29C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X29C);
    // 0x8007FF2C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007FF30: sw          $t9, 0x4C($at)
    MEM_W(0X4C, ctx->r1) = ctx->r25;
    // 0x8007FF34: lw          $t2, 0x2A0($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X2A0);
    // 0x8007FF38: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8007FF3C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8007FF40: addiu       $a0, $a0, 0x138
    ctx->r4 = ADD32(ctx->r4, 0X138);
    // 0x8007FF44: sw          $t2, 0x6C($at)
    MEM_W(0X6C, ctx->r1) = ctx->r10;
L_8007FF48:
    // 0x8007FF48: lw          $t3, 0x298($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X298);
    // 0x8007FF4C: addiu       $v1, $v1, 0x80
    ctx->r3 = ADD32(ctx->r3, 0X80);
    // 0x8007FF50: sw          $t3, -0x2C($v1)
    MEM_W(-0X2C, ctx->r3) = ctx->r11;
    // 0x8007FF54: lw          $t4, 0x29C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X29C);
    // 0x8007FF58: addiu       $v0, $v0, 0x10
    ctx->r2 = ADD32(ctx->r2, 0X10);
    // 0x8007FF5C: sw          $t4, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = ctx->r12;
    // 0x8007FF60: lw          $t6, 0x290($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X290);
    // 0x8007FF64: nop

    // 0x8007FF68: sw          $t6, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->r14;
    // 0x8007FF6C: lw          $t5, 0x294($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X294);
    // 0x8007FF70: bne         $v1, $a0, L_8007FF48
    if (ctx->r3 != ctx->r4) {
        // 0x8007FF74: sw          $t5, 0x34($v1)
        MEM_W(0X34, ctx->r3) = ctx->r13;
            goto L_8007FF48;
    }
    // 0x8007FF74: sw          $t5, 0x34($v1)
    MEM_W(0X34, ctx->r3) = ctx->r13;
    // 0x8007FF78: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8007FF7C:
    // 0x8007FF7C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8007FF80: jr          $ra
    // 0x8007FF84: nop

    return;
    // 0x8007FF84: nop

;}
RECOMP_FUNC void weather_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AB4A8: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800AB4AC: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800AB4B0: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AB4B4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AB4B8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AB4BC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AB4C0: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800AB4C4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800AB4C8: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800AB4CC: or          $s4, $a1, $zero
    ctx->r20 = ctx->r5 | 0;
    // 0x800AB4D0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AB4D4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AB4D8: jal         0x800AB35C
    // 0x800AB4DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    weather_free(rdram, ctx);
        goto after_0;
    // 0x800AB4DC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    after_0:
    // 0x800AB4E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800AB4E4: addiu       $v0, $v0, 0x7BB8
    ctx->r2 = ADD32(ctx->r2, 0X7BB8);
    // 0x800AB4E8: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x800AB4EC: lw          $a2, 0x4C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X4C);
    // 0x800AB4F0: lw          $a3, 0x50($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X50);
    // 0x800AB4F4: slti        $at, $s1, 0x2
    ctx->r1 = SIGNED(ctx->r17) < 0X2 ? 1 : 0;
    // 0x800AB4F8: sw          $s0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r16;
    // 0x800AB4FC: sw          $zero, 0x10($v0)
    MEM_W(0X10, ctx->r2) = 0;
    // 0x800AB500: sw          $s0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r16;
    // 0x800AB504: sw          $s2, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r18;
    // 0x800AB508: sw          $zero, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = 0;
    // 0x800AB50C: sw          $s2, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r18;
    // 0x800AB510: sw          $zero, 0x28($v0)
    MEM_W(0X28, ctx->r2) = 0;
    // 0x800AB514: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x800AB518: sw          $zero, 0x34($v0)
    MEM_W(0X34, ctx->r2) = 0;
    // 0x800AB51C: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800AB520: sw          $v1, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r3;
    // 0x800AB524: sw          $v1, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r3;
    // 0x800AB528: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x800AB52C: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // 0x800AB530: sw          $a3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r7;
    // 0x800AB534: bne         $at, $zero, L_800AB540
    if (ctx->r1 != 0) {
        // 0x800AB538: sw          $a3, 0x38($v0)
        MEM_W(0X38, ctx->r2) = ctx->r7;
            goto L_800AB540;
    }
    // 0x800AB538: sw          $a3, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r7;
    // 0x800AB53C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800AB540:
    // 0x800AB540: sll         $t6, $s1, 2
    ctx->r14 = S32(ctx->r17 << 2);
    // 0x800AB544: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800AB548: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AB54C: subu        $t6, $t6, $s1
    ctx->r14 = SUB32(ctx->r14, ctx->r17);
    // 0x800AB550: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800AB554: addiu       $t7, $t7, 0x2850
    ctx->r15 = ADD32(ctx->r15, 0X2850);
    // 0x800AB558: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800AB55C: addu        $s0, $t6, $t7
    ctx->r16 = ADD32(ctx->r14, ctx->r15);
    // 0x800AB560: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x800AB564: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AB568: bne         $t8, $at, L_800AB584
    if (ctx->r24 != ctx->r1) {
        // 0x800AB56C: lui         $s6, 0xFFAA
        ctx->r22 = S32(0XFFAA << 16);
            goto L_800AB584;
    }
    // 0x800AB56C: lui         $s6, 0xFFAA
    ctx->r22 = S32(0XFFAA << 16);
    // 0x800AB570: addiu       $a0, $a2, 0x1
    ctx->r4 = ADD32(ctx->r6, 0X1);
    // 0x800AB574: jal         0x800AD144
    // 0x800AB578: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    rain_init(rdram, ctx);
        goto after_1;
    // 0x800AB578: addiu       $a1, $a3, 0x1
    ctx->r5 = ADD32(ctx->r7, 0X1);
    after_1:
    // 0x800AB57C: b           L_800ABB10
    // 0x800AB580: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
        goto L_800ABB10;
    // 0x800AB580: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800AB584:
    // 0x800AB584: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x800AB588: ori         $s6, $s6, 0x55FF
    ctx->r22 = ctx->r22 | 0X55FF;
    // 0x800AB58C: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800AB590: subu        $t9, $t9, $a0
    ctx->r25 = SUB32(ctx->r25, ctx->r4);
    // 0x800AB594: sll         $a0, $t9, 2
    ctx->r4 = S32(ctx->r25 << 2);
    // 0x800AB598: jal         0x80070C9C
    // 0x800AB59C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800AB59C: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_2:
    // 0x800AB5A0: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AB5A4: addiu       $s5, $s5, 0x28D8
    ctx->r21 = ADD32(ctx->r21, 0X28D8);
    // 0x800AB5A8: lw          $t1, 0x4($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4);
    // 0x800AB5AC: lw          $t3, 0x10($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X10);
    // 0x800AB5B0: lh          $t8, 0x24($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X24);
    // 0x800AB5B4: lh          $t9, 0x26($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X26);
    // 0x800AB5B8: lw          $t5, 0x18($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X18);
    // 0x800AB5BC: lw          $t2, 0xC($s0)
    ctx->r10 = MEM_W(ctx->r16, 0XC);
    // 0x800AB5C0: lw          $t4, 0x14($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X14);
    // 0x800AB5C4: sw          $t1, 0x4($s5)
    MEM_W(0X4, ctx->r21) = ctx->r9;
    // 0x800AB5C8: sw          $t3, 0x10($s5)
    MEM_W(0X10, ctx->r21) = ctx->r11;
    // 0x800AB5CC: sh          $t8, 0x24($s5)
    MEM_H(0X24, ctx->r21) = ctx->r24;
    // 0x800AB5D0: sh          $t9, 0x26($s5)
    MEM_H(0X26, ctx->r21) = ctx->r25;
    // 0x800AB5D4: lh          $t1, 0x24($s5)
    ctx->r9 = MEM_H(ctx->r21, 0X24);
    // 0x800AB5D8: lh          $t3, 0x26($s5)
    ctx->r11 = MEM_H(ctx->r21, 0X26);
    // 0x800AB5DC: sw          $t5, 0x18($s5)
    MEM_W(0X18, ctx->r21) = ctx->r13;
    // 0x800AB5E0: lw          $t6, 0x1C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X1C);
    // 0x800AB5E4: lw          $t7, 0x20($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X20);
    // 0x800AB5E8: lw          $t5, 0x8($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X8);
    // 0x800AB5EC: sw          $t2, 0xC($s5)
    MEM_W(0XC, ctx->r21) = ctx->r10;
    // 0x800AB5F0: sw          $t4, 0x14($s5)
    MEM_W(0X14, ctx->r21) = ctx->r12;
    // 0x800AB5F4: sll         $t2, $t1, 1
    ctx->r10 = S32(ctx->r9 << 1);
    // 0x800AB5F8: sll         $t4, $t3, 1
    ctx->r12 = S32(ctx->r11 << 1);
    // 0x800AB5FC: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800AB600: sh          $t2, 0x28($s5)
    MEM_H(0X28, ctx->r21) = ctx->r10;
    // 0x800AB604: sh          $t4, 0x2A($s5)
    MEM_H(0X2A, ctx->r21) = ctx->r12;
    // 0x800AB608: sw          $t6, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = ctx->r14;
    // 0x800AB60C: bne         $t5, $zero, L_800AB61C
    if (ctx->r13 != 0) {
        // 0x800AB610: sw          $t7, 0x20($s5)
        MEM_W(0X20, ctx->r21) = ctx->r15;
            goto L_800AB61C;
    }
    // 0x800AB610: sw          $t7, 0x20($s5)
    MEM_W(0X20, ctx->r21) = ctx->r15;
    // 0x800AB614: jal         0x800ABB34
    // 0x800AB618: nop

    snow_init(rdram, ctx);
        goto after_3;
    // 0x800AB618: nop

    after_3:
L_800AB61C:
    // 0x800AB61C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800AB620: addiu       $s3, $s3, 0x7BB0
    ctx->r19 = ADD32(ctx->r19, 0X7BB0);
    // 0x800AB624: sw          $s4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r20;
    // 0x800AB628: sll         $a0, $s4, 1
    ctx->r4 = S32(ctx->r20 << 1);
    // 0x800AB62C: jal         0x80070C9C
    // 0x800AB630: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800AB630: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_4:
    // 0x800AB634: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AB638: sw          $v0, 0x2910($at)
    MEM_W(0X2910, ctx->r1) = ctx->r2;
    // 0x800AB63C: sll         $a0, $s4, 4
    ctx->r4 = S32(ctx->r20 << 4);
    // 0x800AB640: jal         0x80070C9C
    // 0x800AB644: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_5;
    // 0x800AB644: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_5:
    // 0x800AB648: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800AB64C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AB650: addiu       $s2, $s2, 0x28D4
    ctx->r18 = ADD32(ctx->r18, 0X28D4);
    // 0x800AB654: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800AB658: blez        $t6, L_800AB758
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AB65C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800AB758;
    }
    // 0x800AB65C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AB660: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AB664:
    // 0x800AB664: lw          $a1, 0x18($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X18);
    // 0x800AB668: jal         0x8006F94C
    // 0x800AB66C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rand_range(rdram, ctx);
        goto after_6;
    // 0x800AB66C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_6:
    // 0x800AB670: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AB674: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB678: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AB67C: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x800AB680: lw          $a1, 0x1C($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X1C);
    // 0x800AB684: jal         0x8006F94C
    // 0x800AB688: nop

    rand_range(rdram, ctx);
        goto after_7;
    // 0x800AB688: nop

    after_7:
    // 0x800AB68C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AB690: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB694: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800AB698: sw          $v0, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r2;
    // 0x800AB69C: lw          $a1, 0x20($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X20);
    // 0x800AB6A0: jal         0x8006F94C
    // 0x800AB6A4: nop

    rand_range(rdram, ctx);
        goto after_8;
    // 0x800AB6A4: nop

    after_8:
    // 0x800AB6A8: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800AB6AC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB6B0: addu        $t3, $t2, $s0
    ctx->r11 = ADD32(ctx->r10, ctx->r16);
    // 0x800AB6B4: sw          $v0, 0x8($t3)
    MEM_W(0X8, ctx->r11) = ctx->r2;
    // 0x800AB6B8: jal         0x8006F94C
    // 0x800AB6BC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    rand_range(rdram, ctx);
        goto after_9;
    // 0x800AB6BC: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_9:
    // 0x800AB6C0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AB6C4: addiu       $t4, $v0, 0x5
    ctx->r12 = ADD32(ctx->r2, 0X5);
    // 0x800AB6C8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800AB6CC: sllv        $t6, $t5, $t4
    ctx->r14 = S32(ctx->r13 << (ctx->r12 & 31));
    // 0x800AB6D0: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x800AB6D4: sb          $t6, 0xC($t8)
    MEM_B(0XC, ctx->r24) = ctx->r14;
    // 0x800AB6D8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB6DC: jal         0x8006F94C
    // 0x800AB6E0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    rand_range(rdram, ctx);
        goto after_10;
    // 0x800AB6E0: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_10:
    // 0x800AB6E4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800AB6E8: addiu       $t9, $v0, 0x5
    ctx->r25 = ADD32(ctx->r2, 0X5);
    // 0x800AB6EC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800AB6F0: sllv        $t2, $t1, $t9
    ctx->r10 = S32(ctx->r9 << (ctx->r25 & 31));
    // 0x800AB6F4: addu        $t5, $t3, $s0
    ctx->r13 = ADD32(ctx->r11, ctx->r16);
    // 0x800AB6F8: sb          $t2, 0xD($t5)
    MEM_B(0XD, ctx->r13) = ctx->r10;
    // 0x800AB6FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB700: jal         0x8006F94C
    // 0x800AB704: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    rand_range(rdram, ctx);
        goto after_11;
    // 0x800AB704: addiu       $a1, $zero, 0x20
    ctx->r5 = ADD32(0, 0X20);
    after_11:
    // 0x800AB708: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AB70C: addiu       $t4, $v0, 0x5
    ctx->r12 = ADD32(ctx->r2, 0X5);
    // 0x800AB710: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AB714: sllv        $t6, $t7, $t4
    ctx->r14 = S32(ctx->r15 << (ctx->r12 & 31));
    // 0x800AB718: addu        $t1, $t8, $s0
    ctx->r9 = ADD32(ctx->r24, ctx->r16);
    // 0x800AB71C: sb          $t6, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r14;
    // 0x800AB720: lw          $a1, 0x4($s5)
    ctx->r5 = MEM_W(ctx->r21, 0X4);
    // 0x800AB724: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AB728: jal         0x8006F94C
    // 0x800AB72C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    rand_range(rdram, ctx);
        goto after_12;
    // 0x800AB72C: addiu       $a1, $a1, -0x1
    ctx->r5 = ADD32(ctx->r5, -0X1);
    after_12:
    // 0x800AB730: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AB734: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AB738: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800AB73C: sb          $v0, 0xF($t3)
    MEM_B(0XF, ctx->r11) = ctx->r2;
    // 0x800AB740: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800AB744: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x800AB748: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x800AB74C: bne         $at, $zero, L_800AB664
    if (ctx->r1 != 0) {
        // 0x800AB750: nop
    
            goto L_800AB664;
    }
    // 0x800AB750: nop

    // 0x800AB754: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AB758:
    // 0x800AB758: sll         $s0, $s4, 2
    ctx->r16 = S32(ctx->r20 << 2);
    // 0x800AB75C: sll         $s2, $s0, 2
    ctx->r18 = S32(ctx->r16 << 2);
    // 0x800AB760: addu        $s2, $s2, $s0
    ctx->r18 = ADD32(ctx->r18, ctx->r16);
    // 0x800AB764: sll         $s2, $s2, 1
    ctx->r18 = S32(ctx->r18 << 1);
    // 0x800AB768: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AB76C: jal         0x80070C9C
    // 0x800AB770: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_13;
    // 0x800AB770: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_13:
    // 0x800AB774: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AB778: addiu       $s3, $s3, 0x2914
    ctx->r19 = ADD32(ctx->r19, 0X2914);
    // 0x800AB77C: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800AB780: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AB784: jal         0x80070C9C
    // 0x800AB788: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_14;
    // 0x800AB788: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_14:
    // 0x800AB78C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800AB790: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AB794: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AB798: sw          $v0, 0x4($s3)
    MEM_W(0X4, ctx->r19) = ctx->r2;
    // 0x800AB79C: addiu       $v1, $v1, 0x2904
    ctx->r3 = ADD32(ctx->r3, 0X2904);
    // 0x800AB7A0: addiu       $t0, $t0, 0x291C
    ctx->r8 = ADD32(ctx->r8, 0X291C);
    // 0x800AB7A4: addiu       $a3, $a3, 0x2914
    ctx->r7 = ADD32(ctx->r7, 0X2914);
    // 0x800AB7A8: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
L_800AB7AC:
    // 0x800AB7AC: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x800AB7B0: blez        $s0, L_800AB940
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800AB7B4: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_800AB940;
    }
    // 0x800AB7B4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800AB7B8: andi        $a2, $s0, 0x3
    ctx->r6 = ctx->r16 & 0X3;
    // 0x800AB7BC: beq         $a2, $zero, L_800AB81C
    if (ctx->r6 == 0) {
        // 0x800AB7C0: or          $a1, $a2, $zero
        ctx->r5 = ctx->r6 | 0;
            goto L_800AB81C;
    }
    // 0x800AB7C0: or          $a1, $a2, $zero
    ctx->r5 = ctx->r6 | 0;
    // 0x800AB7C4: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800AB7C8: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800AB7CC: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_800AB7D0:
    // 0x800AB7D0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AB7D4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AB7D8: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800AB7DC: sb          $a0, 0x6($t4)
    MEM_B(0X6, ctx->r12) = ctx->r4;
    // 0x800AB7E0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800AB7E4: nop

    // 0x800AB7E8: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800AB7EC: sb          $a0, 0x7($t6)
    MEM_B(0X7, ctx->r14) = ctx->r4;
    // 0x800AB7F0: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800AB7F4: nop

    // 0x800AB7F8: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x800AB7FC: sb          $a0, 0x8($t9)
    MEM_B(0X8, ctx->r25) = ctx->r4;
    // 0x800AB800: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800AB804: nop

    // 0x800AB808: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x800AB80C: sb          $a0, 0x9($t2)
    MEM_B(0X9, ctx->r10) = ctx->r4;
    // 0x800AB810: bne         $a1, $s1, L_800AB7D0
    if (ctx->r5 != ctx->r17) {
        // 0x800AB814: addiu       $v0, $v0, 0xA
        ctx->r2 = ADD32(ctx->r2, 0XA);
            goto L_800AB7D0;
    }
    // 0x800AB814: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800AB818: beq         $s1, $s0, L_800AB93C
    if (ctx->r17 == ctx->r16) {
        // 0x800AB81C: sll         $v0, $s1, 2
        ctx->r2 = S32(ctx->r17 << 2);
            goto L_800AB93C;
    }
L_800AB81C:
    // 0x800AB81C: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800AB820: sll         $a1, $s0, 2
    ctx->r5 = S32(ctx->r16 << 2);
    // 0x800AB824: addu        $a1, $a1, $s0
    ctx->r5 = ADD32(ctx->r5, ctx->r16);
    // 0x800AB828: addu        $v0, $v0, $s1
    ctx->r2 = ADD32(ctx->r2, ctx->r17);
    // 0x800AB82C: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
    // 0x800AB830: sll         $a1, $a1, 1
    ctx->r5 = S32(ctx->r5 << 1);
L_800AB834:
    // 0x800AB834: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800AB838: nop

    // 0x800AB83C: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800AB840: sb          $a0, 0x6($t7)
    MEM_B(0X6, ctx->r15) = ctx->r4;
    // 0x800AB844: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800AB848: nop

    // 0x800AB84C: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800AB850: sb          $a0, 0x7($t8)
    MEM_B(0X7, ctx->r24) = ctx->r4;
    // 0x800AB854: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AB858: nop

    // 0x800AB85C: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x800AB860: sb          $a0, 0x8($t1)
    MEM_B(0X8, ctx->r9) = ctx->r4;
    // 0x800AB864: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800AB868: nop

    // 0x800AB86C: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800AB870: sb          $a0, 0x9($t3)
    MEM_B(0X9, ctx->r11) = ctx->r4;
    // 0x800AB874: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800AB878: nop

    // 0x800AB87C: addu        $t5, $t2, $v0
    ctx->r13 = ADD32(ctx->r10, ctx->r2);
    // 0x800AB880: sb          $a0, 0x10($t5)
    MEM_B(0X10, ctx->r13) = ctx->r4;
    // 0x800AB884: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AB888: nop

    // 0x800AB88C: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800AB890: sb          $a0, 0x11($t4)
    MEM_B(0X11, ctx->r12) = ctx->r4;
    // 0x800AB894: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800AB898: nop

    // 0x800AB89C: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800AB8A0: sb          $a0, 0x12($t6)
    MEM_B(0X12, ctx->r14) = ctx->r4;
    // 0x800AB8A4: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800AB8A8: nop

    // 0x800AB8AC: addu        $t9, $t1, $v0
    ctx->r25 = ADD32(ctx->r9, ctx->r2);
    // 0x800AB8B0: sb          $a0, 0x13($t9)
    MEM_B(0X13, ctx->r25) = ctx->r4;
    // 0x800AB8B4: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800AB8B8: nop

    // 0x800AB8BC: addu        $t2, $t3, $v0
    ctx->r10 = ADD32(ctx->r11, ctx->r2);
    // 0x800AB8C0: sb          $a0, 0x1A($t2)
    MEM_B(0X1A, ctx->r10) = ctx->r4;
    // 0x800AB8C4: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800AB8C8: nop

    // 0x800AB8CC: addu        $t7, $t5, $v0
    ctx->r15 = ADD32(ctx->r13, ctx->r2);
    // 0x800AB8D0: sb          $a0, 0x1B($t7)
    MEM_B(0X1B, ctx->r15) = ctx->r4;
    // 0x800AB8D4: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800AB8D8: nop

    // 0x800AB8DC: addu        $t8, $t4, $v0
    ctx->r24 = ADD32(ctx->r12, ctx->r2);
    // 0x800AB8E0: sb          $a0, 0x1C($t8)
    MEM_B(0X1C, ctx->r24) = ctx->r4;
    // 0x800AB8E4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AB8E8: nop

    // 0x800AB8EC: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x800AB8F0: sb          $a0, 0x1D($t1)
    MEM_B(0X1D, ctx->r9) = ctx->r4;
    // 0x800AB8F4: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800AB8F8: nop

    // 0x800AB8FC: addu        $t3, $t9, $v0
    ctx->r11 = ADD32(ctx->r25, ctx->r2);
    // 0x800AB900: sb          $a0, 0x24($t3)
    MEM_B(0X24, ctx->r11) = ctx->r4;
    // 0x800AB904: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800AB908: nop

    // 0x800AB90C: addu        $t5, $t2, $v0
    ctx->r13 = ADD32(ctx->r10, ctx->r2);
    // 0x800AB910: sb          $a0, 0x25($t5)
    MEM_B(0X25, ctx->r13) = ctx->r4;
    // 0x800AB914: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AB918: nop

    // 0x800AB91C: addu        $t4, $t7, $v0
    ctx->r12 = ADD32(ctx->r15, ctx->r2);
    // 0x800AB920: sb          $a0, 0x26($t4)
    MEM_B(0X26, ctx->r12) = ctx->r4;
    // 0x800AB924: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800AB928: nop

    // 0x800AB92C: addu        $t6, $t8, $v0
    ctx->r14 = ADD32(ctx->r24, ctx->r2);
    // 0x800AB930: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
    // 0x800AB934: bne         $v0, $a1, L_800AB834
    if (ctx->r2 != ctx->r5) {
        // 0x800AB938: sb          $a0, 0x27($t6)
        MEM_B(0X27, ctx->r14) = ctx->r4;
            goto L_800AB834;
    }
    // 0x800AB938: sb          $a0, 0x27($t6)
    MEM_B(0X27, ctx->r14) = ctx->r4;
L_800AB93C:
    // 0x800AB93C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AB940:
    // 0x800AB940: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800AB944: sltu        $at, $a3, $t0
    ctx->r1 = ctx->r7 < ctx->r8 ? 1 : 0;
    // 0x800AB948: bne         $at, $zero, L_800AB7AC
    if (ctx->r1 != 0) {
        // 0x800AB94C: nop
    
            goto L_800AB7AC;
    }
    // 0x800AB94C: nop

    // 0x800AB950: lw          $v0, 0x8($s5)
    ctx->r2 = MEM_W(ctx->r21, 0X8);
    // 0x800AB954: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800AB958: lbu         $s2, 0x0($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X0);
    // 0x800AB95C: lbu         $s3, 0x1($v0)
    ctx->r19 = MEM_BU(ctx->r2, 0X1);
    // 0x800AB960: addiu       $s4, $s4, 0x7C04
    ctx->r20 = ADD32(ctx->r20, 0X7C04);
    // 0x800AB964: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800AB968: sll         $t1, $s2, 5
    ctx->r9 = S32(ctx->r18 << 5);
    // 0x800AB96C: sll         $t2, $s3, 5
    ctx->r10 = S32(ctx->r19 << 5);
    // 0x800AB970: addiu       $s2, $t1, -0x1
    ctx->r18 = ADD32(ctx->r9, -0X1);
    // 0x800AB974: addiu       $s3, $t2, -0x1
    ctx->r19 = ADD32(ctx->r10, -0X1);
    // 0x800AB978: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x800AB97C: sll         $t5, $s3, 16
    ctx->r13 = S32(ctx->r19 << 16);
    // 0x800AB980: sll         $t4, $a0, 4
    ctx->r12 = S32(ctx->r4 << 4);
    // 0x800AB984: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800AB988: sra         $s3, $t5, 16
    ctx->r19 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800AB98C: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x800AB990: jal         0x80070C9C
    // 0x800AB994: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_15;
    // 0x800AB994: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    after_15:
    // 0x800AB998: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x800AB99C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AB9A0: addiu       $v1, $v1, 0x290C
    ctx->r3 = ADD32(ctx->r3, 0X290C);
    // 0x800AB9A4: blez        $t8, L_800ABB04
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800AB9A8: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800ABB04;
    }
    // 0x800AB9A8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800AB9AC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AB9B0:
    // 0x800AB9B0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AB9B4: sll         $a0, $s1, 1
    ctx->r4 = S32(ctx->r17 << 1);
    // 0x800AB9B8: addu        $t1, $t6, $s0
    ctx->r9 = ADD32(ctx->r14, ctx->r16);
    // 0x800AB9BC: sb          $zero, 0x0($t1)
    MEM_B(0X0, ctx->r9) = 0;
    // 0x800AB9C0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800AB9C4: addiu       $v0, $a0, 0x3
    ctx->r2 = ADD32(ctx->r4, 0X3);
    // 0x800AB9C8: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800AB9CC: sb          $v0, 0x1($t3)
    MEM_B(0X1, ctx->r11) = ctx->r2;
    // 0x800AB9D0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800AB9D4: addiu       $a1, $a0, 0x1
    ctx->r5 = ADD32(ctx->r4, 0X1);
    // 0x800AB9D8: addu        $t5, $t2, $s0
    ctx->r13 = ADD32(ctx->r10, ctx->r16);
    // 0x800AB9DC: sh          $zero, 0x4($t5)
    MEM_H(0X4, ctx->r13) = 0;
    // 0x800AB9E0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800AB9E4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800AB9E8: addu        $t4, $t7, $s0
    ctx->r12 = ADD32(ctx->r15, ctx->r16);
    // 0x800AB9EC: sh          $s3, 0x6($t4)
    MEM_H(0X6, ctx->r12) = ctx->r19;
    // 0x800AB9F0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800AB9F4: nop

    // 0x800AB9F8: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800AB9FC: sb          $a1, 0x2($t6)
    MEM_B(0X2, ctx->r14) = ctx->r5;
    // 0x800ABA00: lw          $t1, 0x0($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X0);
    // 0x800ABA04: nop

    // 0x800ABA08: addu        $t9, $t1, $s0
    ctx->r25 = ADD32(ctx->r9, ctx->r16);
    // 0x800ABA0C: sh          $s2, 0x8($t9)
    MEM_H(0X8, ctx->r25) = ctx->r18;
    // 0x800ABA10: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800ABA14: nop

    // 0x800ABA18: addu        $t2, $t3, $s0
    ctx->r10 = ADD32(ctx->r11, ctx->r16);
    // 0x800ABA1C: sh          $zero, 0xA($t2)
    MEM_H(0XA, ctx->r10) = 0;
    // 0x800ABA20: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800ABA24: nop

    // 0x800ABA28: addu        $t7, $t5, $s0
    ctx->r15 = ADD32(ctx->r13, ctx->r16);
    // 0x800ABA2C: sb          $a0, 0x3($t7)
    MEM_B(0X3, ctx->r15) = ctx->r4;
    // 0x800ABA30: lw          $t4, 0x0($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X0);
    // 0x800ABA34: nop

    // 0x800ABA38: addu        $t8, $t4, $s0
    ctx->r24 = ADD32(ctx->r12, ctx->r16);
    // 0x800ABA3C: sh          $zero, 0xC($t8)
    MEM_H(0XC, ctx->r24) = 0;
    // 0x800ABA40: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800ABA44: nop

    // 0x800ABA48: addu        $t1, $t6, $s0
    ctx->r9 = ADD32(ctx->r14, ctx->r16);
    // 0x800ABA4C: sh          $zero, 0xE($t1)
    MEM_H(0XE, ctx->r9) = 0;
    // 0x800ABA50: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABA54: addiu       $t1, $a0, 0x2
    ctx->r9 = ADD32(ctx->r4, 0X2);
    // 0x800ABA58: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABA5C: sb          $zero, 0x10($t3)
    MEM_B(0X10, ctx->r11) = 0;
    // 0x800ABA60: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800ABA64: nop

    // 0x800ABA68: addu        $t5, $t2, $s0
    ctx->r13 = ADD32(ctx->r10, ctx->r16);
    // 0x800ABA6C: sb          $v0, 0x11($t5)
    MEM_B(0X11, ctx->r13) = ctx->r2;
    // 0x800ABA70: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABA74: nop

    // 0x800ABA78: addu        $t4, $t7, $s0
    ctx->r12 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABA7C: sh          $zero, 0x14($t4)
    MEM_H(0X14, ctx->r12) = 0;
    // 0x800ABA80: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABA84: nop

    // 0x800ABA88: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800ABA8C: sh          $s3, 0x16($t6)
    MEM_H(0X16, ctx->r14) = ctx->r19;
    // 0x800ABA90: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABA94: nop

    // 0x800ABA98: addu        $t3, $t9, $s0
    ctx->r11 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABA9C: sb          $t1, 0x12($t3)
    MEM_B(0X12, ctx->r11) = ctx->r9;
    // 0x800ABAA0: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x800ABAA4: nop

    // 0x800ABAA8: addu        $t5, $t2, $s0
    ctx->r13 = ADD32(ctx->r10, ctx->r16);
    // 0x800ABAAC: sh          $s2, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r18;
    // 0x800ABAB0: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x800ABAB4: nop

    // 0x800ABAB8: addu        $t4, $t7, $s0
    ctx->r12 = ADD32(ctx->r15, ctx->r16);
    // 0x800ABABC: sh          $s3, 0x1A($t4)
    MEM_H(0X1A, ctx->r12) = ctx->r19;
    // 0x800ABAC0: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x800ABAC4: nop

    // 0x800ABAC8: addu        $t6, $t8, $s0
    ctx->r14 = ADD32(ctx->r24, ctx->r16);
    // 0x800ABACC: sb          $a1, 0x13($t6)
    MEM_B(0X13, ctx->r14) = ctx->r5;
    // 0x800ABAD0: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x800ABAD4: nop

    // 0x800ABAD8: addu        $t1, $t9, $s0
    ctx->r9 = ADD32(ctx->r25, ctx->r16);
    // 0x800ABADC: sh          $s2, 0x1C($t1)
    MEM_H(0X1C, ctx->r9) = ctx->r18;
    // 0x800ABAE0: lw          $t3, 0x0($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X0);
    // 0x800ABAE4: nop

    // 0x800ABAE8: addu        $t2, $t3, $s0
    ctx->r10 = ADD32(ctx->r11, ctx->r16);
    // 0x800ABAEC: sh          $zero, 0x1E($t2)
    MEM_H(0X1E, ctx->r10) = 0;
    // 0x800ABAF0: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x800ABAF4: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x800ABAF8: slt         $at, $s1, $t5
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800ABAFC: bne         $at, $zero, L_800AB9B0
    if (ctx->r1 != 0) {
        // 0x800ABB00: nop
    
            goto L_800AB9B0;
    }
    // 0x800ABB00: nop

L_800ABB04:
    // 0x800ABB04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800ABB08: sw          $zero, 0x7C08($at)
    MEM_W(0X7C08, ctx->r1) = 0;
    // 0x800ABB0C: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
L_800ABB10:
    // 0x800ABB10: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ABB14: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800ABB18: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800ABB1C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800ABB20: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800ABB24: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800ABB28: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800ABB2C: jr          $ra
    // 0x800ABB30: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800ABB30: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void get_memory_pool_address(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071774: sll         $t6, $a0, 4
    ctx->r14 = S32(ctx->r4 << 4);
    // 0x80071778: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007177C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x80071780: lw          $v0, 0x3588($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3588);
    // 0x80071784: jr          $ra
    // 0x80071788: nop

    return;
    // 0x80071788: nop

;}
RECOMP_FUNC void free_rain_memory(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AD220: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD224: lw          $a0, 0x2C38($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C38);
    // 0x800AD228: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AD22C: beq         $a0, $zero, L_800AD244
    if (ctx->r4 == 0) {
        // 0x800AD230: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AD244;
    }
    // 0x800AD230: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AD234: jal         0x8007B2BC
    // 0x800AD238: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x800AD238: nop

    after_0:
    // 0x800AD23C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD240: sw          $zero, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = 0;
L_800AD244:
    // 0x800AD244: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD248: lw          $a0, 0x2C50($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C50);
    // 0x800AD24C: nop

    // 0x800AD250: beq         $a0, $zero, L_800AD268
    if (ctx->r4 == 0) {
        // 0x800AD254: nop
    
            goto L_800AD268;
    }
    // 0x800AD254: nop

    // 0x800AD258: jal         0x8007B2BC
    // 0x800AD25C: nop

    tex_free(rdram, ctx);
        goto after_1;
    // 0x800AD25C: nop

    after_1:
    // 0x800AD260: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD264: sw          $zero, 0x2C88($at)
    MEM_W(0X2C88, ctx->r1) = 0;
L_800AD268:
    // 0x800AD268: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD26C: lw          $a0, 0x2C8C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C8C);
    // 0x800AD270: nop

    // 0x800AD274: beq         $a0, $zero, L_800AD28C
    if (ctx->r4 == 0) {
        // 0x800AD278: nop
    
            goto L_800AD28C;
    }
    // 0x800AD278: nop

    // 0x800AD27C: jal         0x8007CCB0
    // 0x800AD280: nop

    sprite_free(rdram, ctx);
        goto after_2;
    // 0x800AD280: nop

    after_2:
    // 0x800AD284: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD288: sw          $zero, 0x2C8C($at)
    MEM_W(0X2C8C, ctx->r1) = 0;
L_800AD28C:
    // 0x800AD28C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AD290: lw          $a0, 0x2C94($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2C94);
    // 0x800AD294: nop

    // 0x800AD298: beq         $a0, $zero, L_800AD2B4
    if (ctx->r4 == 0) {
        // 0x800AD29C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AD2B4;
    }
    // 0x800AD29C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AD2A0: jal         0x800096F8
    // 0x800AD2A4: nop

    audspat_point_stop(rdram, ctx);
        goto after_3;
    // 0x800AD2A4: nop

    after_3:
    // 0x800AD2A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD2AC: sw          $zero, 0x2C94($at)
    MEM_W(0X2C94, ctx->r1) = 0;
    // 0x800AD2B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AD2B4:
    // 0x800AD2B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AD2B8: sw          $zero, 0x2C5C($at)
    MEM_W(0X2C5C, ctx->r1) = 0;
    // 0x800AD2BC: jr          $ra
    // 0x800AD2C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800AD2C0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void get_camera_matrix(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069DBC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80069DC0: jr          $ra
    // 0x80069DC4: addiu       $v0, $v0, 0xF60
    ctx->r2 = ADD32(ctx->r2, 0XF60);
    return;
    // 0x80069DC4: addiu       $v0, $v0, 0xF60
    ctx->r2 = ADD32(ctx->r2, 0XF60);
;}
RECOMP_FUNC void obj_init_rampswitch(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CE64: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CE68: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003CE6C: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003CE70: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CE74: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8003CE78: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003CE7C: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CE80: nop

    // 0x8003CE84: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003CE88: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CE8C: nop

    // 0x8003CE90: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003CE94: lbu         $t2, 0x8($a1)
    ctx->r10 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CE98: jr          $ra
    // 0x8003CE9C: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
    return;
    // 0x8003CE9C: sw          $t2, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r10;
;}
RECOMP_FUNC void func_800C38B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C38B4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800C38B8: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800C38BC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C38C0: addiu       $s3, $s3, -0x5860
    ctx->r19 = ADD32(ctx->r19, -0X5860);
    // 0x800C38C4: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800C38C8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800C38CC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800C38D0: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800C38D4: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800C38D8: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800C38DC: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800C38E0: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800C38E4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800C38E8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800C38EC: addu        $s0, $t6, $a0
    ctx->r16 = ADD32(ctx->r14, ctx->r4);
    // 0x800C38F0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C38F4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800C38F8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x800C38FC: bne         $at, $zero, L_800C3BC8
    if (ctx->r1 != 0) {
        // 0x800C3900: or          $s2, $a1, $zero
        ctx->r18 = ctx->r5 | 0;
            goto L_800C3BC8;
    }
    // 0x800C3900: or          $s2, $a1, $zero
    ctx->r18 = ctx->r5 | 0;
    // 0x800C3904: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x800C3908: beq         $at, $zero, L_800C3BC8
    if (ctx->r1 == 0) {
        // 0x800C390C: addiu       $fp, $zero, 0x4
        ctx->r30 = ADD32(0, 0X4);
            goto L_800C3BC8;
    }
    // 0x800C390C: addiu       $fp, $zero, 0x4
    ctx->r30 = ADD32(0, 0X4);
    // 0x800C3910: lui         $s7, 0x8013
    ctx->r23 = S32(0X8013 << 16);
    // 0x800C3914: lui         $s6, 0x8013
    ctx->r22 = S32(0X8013 << 16);
    // 0x800C3918: lui         $s5, 0x8013
    ctx->r21 = S32(0X8013 << 16);
    // 0x800C391C: lui         $s4, 0x8013
    ctx->r20 = S32(0X8013 << 16);
    // 0x800C3920: addiu       $s4, $s4, -0x587A
    ctx->r20 = ADD32(ctx->r20, -0X587A);
    // 0x800C3924: addiu       $s5, $s5, -0x5878
    ctx->r21 = ADD32(ctx->r21, -0X5878);
    // 0x800C3928: addiu       $s6, $s6, -0x5879
    ctx->r22 = ADD32(ctx->r22, -0X5879);
    // 0x800C392C: addiu       $s7, $s7, -0x587B
    ctx->r23 = ADD32(ctx->r23, -0X587B);
    // 0x800C3930: addiu       $t7, $v0, -0x3
    ctx->r15 = ADD32(ctx->r2, -0X3);
L_800C3934:
    // 0x800C3934: sltiu       $at, $t7, 0xA
    ctx->r1 = ctx->r15 < 0XA ? 1 : 0;
    // 0x800C3938: beq         $at, $zero, L_800C3BB4
    if (ctx->r1 == 0) {
        // 0x800C393C: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_800C3BB4;
    }
    // 0x800C393C: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800C3940: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800C3944: addu        $at, $at, $t7
    gpr jr_addend_800C3950 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800C3948: lw          $t7, -0x6CD0($at)
    ctx->r15 = ADD32(ctx->r1, -0X6CD0);
    // 0x800C394C: nop

    // 0x800C3950: jr          $t7
    // 0x800C3954: nop

    switch (jr_addend_800C3950 >> 2) {
        case 0: goto L_800C3958; break;
        case 1: goto L_800C3984; break;
        case 2: goto L_800C3A30; break;
        case 3: goto L_800C3AA8; break;
        case 4: goto L_800C3ADC; break;
        case 5: goto L_800C3B00; break;
        case 6: goto L_800C3B2C; break;
        case 7: goto L_800C3B50; break;
        case 8: goto L_800C3B88; break;
        case 9: goto L_800C3BA0; break;
        default: switch_error(__func__, 0x800C3950, 0x800E9330);
    }
    // 0x800C3954: nop

L_800C3958:
    // 0x800C3958: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800C395C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C3960: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3964: jal         0x800C4F7C
    // 0x800C3968: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    set_dialogue_font(rdram, ctx);
        goto after_0;
    // 0x800C3968: sw          $a1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r5;
    after_0:
    // 0x800C396C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800C3970: nop

    // 0x800C3974: addu        $s0, $t9, $s1
    ctx->r16 = ADD32(ctx->r25, ctx->r17);
    // 0x800C3978: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C397C: b           L_800C3BB8
    // 0x800C3980: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C3BB8;
    // 0x800C3980: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3984:
    // 0x800C3984: lbu         $t1, 0x1($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3988: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800C398C: sw          $t1, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r9;
    // 0x800C3990: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800C3994: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x800C3998: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x800C399C: lbu         $t5, 0x2($t3)
    ctx->r13 = MEM_BU(ctx->r11, 0X2);
    // 0x800C39A0: nop

    // 0x800C39A4: sw          $t5, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r13;
    // 0x800C39A8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800C39AC: sll         $t7, $t5, 5
    ctx->r15 = S32(ctx->r13 << 5);
    // 0x800C39B0: bne         $t6, $zero, L_800C39D0
    if (ctx->r14 != 0) {
        // 0x800C39B4: addu        $t7, $t7, $t5
        ctx->r15 = ADD32(ctx->r15, ctx->r13);
            goto L_800C39D0;
    }
    // 0x800C39B4: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x800C39B8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C39BC: div         $zero, $t7, $at
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r1)));
    // 0x800C39C0: mflo        $a2
    ctx->r6 = lo;
    // 0x800C39C4: sw          $a2, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r6;
    // 0x800C39C8: b           L_800C39D8
    // 0x800C39CC: subu        $v0, $a2, $t5
    ctx->r2 = SUB32(ctx->r6, ctx->r13);
        goto L_800C39D8;
    // 0x800C39CC: subu        $v0, $a2, $t5
    ctx->r2 = SUB32(ctx->r6, ctx->r13);
L_800C39D0:
    // 0x800C39D0: lw          $a2, 0x8($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X8);
    // 0x800C39D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800C39D8:
    // 0x800C39D8: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800C39DC: lw          $a1, 0x4($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X4);
    // 0x800C39E0: addu        $t0, $s1, $t9
    ctx->r8 = ADD32(ctx->r17, ctx->r25);
    // 0x800C39E4: lbu         $t2, 0x3($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X3);
    // 0x800C39E8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C39EC: addiu       $a3, $t2, 0x41
    ctx->r7 = ADD32(ctx->r10, 0X41);
    // 0x800C39F0: sw          $a3, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r7;
    // 0x800C39F4: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800C39F8: nop

    // 0x800C39FC: addu        $t5, $s1, $t4
    ctx->r13 = ADD32(ctx->r17, ctx->r12);
    // 0x800C3A00: lbu         $t7, 0x4($t5)
    ctx->r15 = MEM_BU(ctx->r13, 0X4);
    // 0x800C3A04: addiu       $s1, $s1, 0x5
    ctx->r17 = ADD32(ctx->r17, 0X5);
    // 0x800C3A08: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800C3A0C: sw          $t8, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r24;
    // 0x800C3A10: jal         0x800C4EDC
    // 0x800C3A14: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x800C3A14: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x800C3A18: lw          $t0, 0x0($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X0);
    // 0x800C3A1C: nop

    // 0x800C3A20: addu        $s0, $t0, $s1
    ctx->r16 = ADD32(ctx->r8, ctx->r17);
    // 0x800C3A24: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3A28: b           L_800C3BB8
    // 0x800C3A2C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C3BB8;
    // 0x800C3A2C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3A30:
    // 0x800C3A30: lbu         $a1, 0x1($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3A34: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3A38: sw          $a1, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r5;
    // 0x800C3A3C: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x800C3A40: nop

    // 0x800C3A44: addu        $t3, $s1, $t2
    ctx->r11 = ADD32(ctx->r17, ctx->r10);
    // 0x800C3A48: lbu         $a2, 0x2($t3)
    ctx->r6 = MEM_BU(ctx->r11, 0X2);
    // 0x800C3A4C: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C3A50: sw          $a2, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->r6;
    // 0x800C3A54: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800C3A58: nop

    // 0x800C3A5C: addu        $t6, $s1, $t5
    ctx->r14 = ADD32(ctx->r17, ctx->r13);
    // 0x800C3A60: lbu         $a3, 0x3($t6)
    ctx->r7 = MEM_BU(ctx->r14, 0X3);
    // 0x800C3A64: nop

    // 0x800C3A68: sw          $a3, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r7;
    // 0x800C3A6C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800C3A70: nop

    // 0x800C3A74: addu        $t9, $s1, $t8
    ctx->r25 = ADD32(ctx->r17, ctx->r24);
    // 0x800C3A78: lbu         $t0, 0x4($t9)
    ctx->r8 = MEM_BU(ctx->r25, 0X4);
    // 0x800C3A7C: addiu       $s1, $s1, 0x5
    ctx->r17 = ADD32(ctx->r17, 0X5);
    // 0x800C3A80: sw          $t0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->r8;
    // 0x800C3A84: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x800C3A88: jal         0x800C5000
    // 0x800C3A8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    set_current_text_colour(rdram, ctx);
        goto after_2;
    // 0x800C3A8C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C3A90: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800C3A94: nop

    // 0x800C3A98: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
    // 0x800C3A9C: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3AA0: b           L_800C3BB8
    // 0x800C3AA4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C3BB8;
    // 0x800C3AA4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3AA8:
    // 0x800C3AA8: lbu         $t4, 0x1($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3AAC: nop

    // 0x800C3AB0: bne         $t4, $zero, L_800C3AC0
    if (ctx->r12 != 0) {
        // 0x800C3AB4: nop
    
            goto L_800C3AC0;
    }
    // 0x800C3AB4: nop

    // 0x800C3AB8: b           L_800C3AC4
    // 0x800C3ABC: sw          $fp, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r30;
        goto L_800C3AC4;
    // 0x800C3ABC: sw          $fp, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->r30;
L_800C3AC0:
    // 0x800C3AC0: sw          $zero, 0x24($s2)
    MEM_W(0X24, ctx->r18) = 0;
L_800C3AC4:
    // 0x800C3AC4: lw          $t5, 0x0($s3)
    ctx->r13 = MEM_W(ctx->r19, 0X0);
    // 0x800C3AC8: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C3ACC: addu        $s0, $t5, $s1
    ctx->r16 = ADD32(ctx->r13, ctx->r17);
    // 0x800C3AD0: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3AD4: b           L_800C3BB8
    // 0x800C3AD8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C3BB8;
    // 0x800C3AD8: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3ADC:
    // 0x800C3ADC: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3AE0: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C3AE4: sw          $t6, 0x28($s2)
    MEM_W(0X28, ctx->r18) = ctx->r14;
    // 0x800C3AE8: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800C3AEC: nop

    // 0x800C3AF0: addu        $s0, $t7, $s1
    ctx->r16 = ADD32(ctx->r15, ctx->r17);
    // 0x800C3AF4: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3AF8: b           L_800C3BB8
    // 0x800C3AFC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C3BB8;
    // 0x800C3AFC: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3B00:
    // 0x800C3B00: lw          $t8, 0x2C($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X2C);
    // 0x800C3B04: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3B08: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C3B0C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800C3B10: sw          $t0, 0x2C($s2)
    MEM_W(0X2C, ctx->r18) = ctx->r8;
    // 0x800C3B14: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800C3B18: nop

    // 0x800C3B1C: addu        $s0, $t1, $s1
    ctx->r16 = ADD32(ctx->r9, ctx->r17);
    // 0x800C3B20: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3B24: b           L_800C3BB8
    // 0x800C3B28: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C3BB8;
    // 0x800C3B28: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3B2C:
    // 0x800C3B2C: lbu         $t2, 0x1($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3B30: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C3B34: sw          $t2, 0x30($s2)
    MEM_W(0X30, ctx->r18) = ctx->r10;
    // 0x800C3B38: lw          $t3, 0x0($s3)
    ctx->r11 = MEM_W(ctx->r19, 0X0);
    // 0x800C3B3C: nop

    // 0x800C3B40: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
    // 0x800C3B44: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3B48: b           L_800C3BB8
    // 0x800C3B4C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
        goto L_800C3BB8;
    // 0x800C3B4C: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3B50:
    // 0x800C3B50: lb          $t4, 0x0($s4)
    ctx->r12 = MEM_B(ctx->r20, 0X0);
    // 0x800C3B54: addiu       $a0, $zero, 0x3C
    ctx->r4 = ADD32(0, 0X3C);
    // 0x800C3B58: bne         $t4, $zero, L_800C3B78
    if (ctx->r12 != 0) {
        // 0x800C3B5C: nop
    
            goto L_800C3B78;
    }
    // 0x800C3B5C: nop

    // 0x800C3B60: lbu         $t6, 0x1($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3B64: jal         0x8000C8B4
    // 0x800C3B68: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
    normalise_time(rdram, ctx);
        goto after_3;
    // 0x800C3B68: sb          $t6, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r14;
    after_3:
    // 0x800C3B6C: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800C3B70: sb          $v0, 0x0($s7)
    MEM_B(0X0, ctx->r23) = ctx->r2;
    // 0x800C3B74: addu        $s0, $t7, $s1
    ctx->r16 = ADD32(ctx->r15, ctx->r17);
L_800C3B78:
    // 0x800C3B78: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800C3B7C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C3B80: b           L_800C3BB4
    // 0x800C3B84: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_800C3BB4;
    // 0x800C3B84: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800C3B88:
    // 0x800C3B88: lbu         $t8, 0x1($s0)
    ctx->r24 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3B8C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C3B90: sb          $t8, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r24;
    // 0x800C3B94: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800C3B98: b           L_800C3BB4
    // 0x800C3B9C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
        goto L_800C3BB4;
    // 0x800C3B9C: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800C3BA0:
    // 0x800C3BA0: lbu         $t9, 0x1($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X1);
    // 0x800C3BA4: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x800C3BA8: sb          $t9, 0x0($s5)
    MEM_B(0X0, ctx->r21) = ctx->r25;
    // 0x800C3BAC: lbu         $v0, 0x2($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X2);
    // 0x800C3BB0: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
L_800C3BB4:
    // 0x800C3BB4: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
L_800C3BB8:
    // 0x800C3BB8: bne         $at, $zero, L_800C3BC8
    if (ctx->r1 != 0) {
        // 0x800C3BBC: slti        $at, $v0, 0xD
        ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
            goto L_800C3BC8;
    }
    // 0x800C3BBC: slti        $at, $v0, 0xD
    ctx->r1 = SIGNED(ctx->r2) < 0XD ? 1 : 0;
    // 0x800C3BC0: bne         $at, $zero, L_800C3934
    if (ctx->r1 != 0) {
        // 0x800C3BC4: addiu       $t7, $v0, -0x3
        ctx->r15 = ADD32(ctx->r2, -0X3);
            goto L_800C3934;
    }
    // 0x800C3BC4: addiu       $t7, $v0, -0x3
    ctx->r15 = ADD32(ctx->r2, -0X3);
L_800C3BC8:
    // 0x800C3BC8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800C3BCC: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x800C3BD0: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800C3BD4: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800C3BD8: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800C3BDC: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800C3BE0: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800C3BE4: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800C3BE8: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800C3BEC: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800C3BF0: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800C3BF4: jr          $ra
    // 0x800C3BF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800C3BF8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void render_level_geometry_and_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028FAC: addiu       $sp, $sp, -0x170
    ctx->r29 = ADD32(ctx->r29, -0X170);
    // 0x80028FB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80028FB4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x80028FB8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x80028FBC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80028FC0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80028FC4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80028FC8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x80028FCC: jal         0x80012C30
    // 0x80028FD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    func_80012C30(rdram, ctx);
        goto after_0;
    // 0x80028FD0: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x80028FD4: jal         0x8006EA90
    // 0x80028FD8: nop

    get_settings(rdram, ctx);
        goto after_1;
    // 0x80028FD8: nop

    after_1:
    // 0x80028FDC: lbu         $t6, 0x49($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X49);
    // 0x80028FE0: addiu       $at, $zero, 0x24
    ctx->r1 = ADD32(0, 0X24);
    // 0x80028FE4: bne         $t6, $at, L_80028FF4
    if (ctx->r14 != ctx->r1) {
        // 0x80028FE8: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80028FF4;
    }
    // 0x80028FE8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80028FEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028FF0: sw          $t7, -0x4F04($at)
    MEM_W(-0X4F04, ctx->r1) = ctx->r15;
L_80028FF4:
    // 0x80028FF4: jal         0x80014814
    // 0x80028FF8: addiu       $a0, $sp, 0x16C
    ctx->r4 = ADD32(ctx->r29, 0X16C);
    get_first_active_object(rdram, ctx);
        goto after_2;
    // 0x80028FF8: addiu       $a0, $sp, 0x16C
    ctx->r4 = ADD32(ctx->r29, 0X16C);
    after_2:
    // 0x80028FFC: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80029000: lw          $s0, -0x36E8($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X36E8);
    // 0x80029004: sw          $v0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r2;
    // 0x80029008: lh          $t8, 0x1A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A);
    // 0x8002900C: nop

    // 0x80029010: slti        $at, $t8, 0x2
    ctx->r1 = SIGNED(ctx->r24) < 0X2 ? 1 : 0;
    // 0x80029014: bne         $at, $zero, L_80029054
    if (ctx->r1 != 0) {
        // 0x80029018: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80029054;
    }
    // 0x80029018: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8002901C: sw          $zero, 0x168($sp)
    MEM_W(0X168, ctx->r29) = 0;
    // 0x80029020: lh          $a2, 0x1A($s0)
    ctx->r6 = MEM_H(ctx->r16, 0X1A);
    // 0x80029024: addiu       $t9, $sp, 0x168
    ctx->r25 = ADD32(ctx->r29, 0X168);
    // 0x80029028: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8002902C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80029030: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029034: addiu       $a3, $sp, 0xD8
    ctx->r7 = ADD32(ctx->r29, 0XD8);
    // 0x80029038: jal         0x80029AF8
    // 0x8002903C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    traverse_segments_bsp_tree(rdram, ctx);
        goto after_3;
    // 0x8002903C: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    after_3:
    // 0x80029040: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x80029044: lw          $s0, -0x36E8($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X36E8);
    // 0x80029048: b           L_80029060
    // 0x8002904C: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
        goto L_80029060;
    // 0x8002904C: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
    // 0x80029050: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80029054:
    // 0x80029054: sw          $t0, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r8;
    // 0x80029058: sb          $zero, 0xD8($sp)
    MEM_B(0XD8, ctx->r29) = 0;
    // 0x8002905C: lh          $t1, 0x1A($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X1A);
L_80029060:
    // 0x80029060: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80029064: blez        $t1, L_80029088
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80029068: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_80029088;
    }
    // 0x80029068: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8002906C: addiu       $v0, $sp, 0x59
    ctx->r2 = ADD32(ctx->r29, 0X59);
L_80029070:
    // 0x80029070: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x80029074: lh          $t2, 0x1A($s0)
    ctx->r10 = MEM_H(ctx->r16, 0X1A);
    // 0x80029078: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8002907C: slt         $at, $t2, $s2
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x80029080: beq         $at, $zero, L_80029070
    if (ctx->r1 == 0) {
        // 0x80029084: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_80029070;
    }
    // 0x80029084: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_80029088:
    // 0x80029088: lb          $t4, -0x4F20($t4)
    ctx->r12 = MEM_B(ctx->r12, -0X4F20);
    // 0x8002908C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80029090: beq         $t4, $zero, L_800290EC
    if (ctx->r12 == 0) {
        // 0x80029094: sb          $t3, 0x58($sp)
        MEM_B(0X58, ctx->r29) = ctx->r11;
            goto L_800290EC;
    }
    // 0x80029094: sb          $t3, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r11;
    // 0x80029098: lw          $t5, 0x168($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X168);
    // 0x8002909C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800290A0: blez        $t5, L_800290EC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800290A4: addiu       $s6, $sp, 0x58
        ctx->r22 = ADD32(ctx->r29, 0X58);
            goto L_800290EC;
    }
    // 0x800290A4: addiu       $s6, $sp, 0x58
    ctx->r22 = ADD32(ctx->r29, 0X58);
    // 0x800290A8: addiu       $s0, $sp, 0xD8
    ctx->r16 = ADD32(ctx->r29, 0XD8);
    // 0x800290AC: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_800290B0:
    // 0x800290B0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800290B4: jal         0x80029658
    // 0x800290B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    render_level_segment(rdram, ctx);
        goto after_4;
    // 0x800290B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800290BC: lbu         $t6, 0x0($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X0);
    // 0x800290C0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800290C4: addu        $t7, $s6, $t6
    ctx->r15 = ADD32(ctx->r22, ctx->r14);
    // 0x800290C8: sb          $s1, 0x1($t7)
    MEM_B(0X1, ctx->r15) = ctx->r17;
    // 0x800290CC: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800290D0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800290D4: slt         $at, $s2, $t8
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800290D8: bne         $at, $zero, L_800290B0
    if (ctx->r1 != 0) {
        // 0x800290DC: nop
    
            goto L_800290B0;
    }
    // 0x800290DC: nop

    // 0x800290E0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x800290E4: lw          $s0, -0x36E8($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X36E8);
    // 0x800290E8: nop

L_800290EC:
    // 0x800290EC: lh          $t9, 0x1A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A);
    // 0x800290F0: addiu       $s6, $sp, 0x58
    ctx->r22 = ADD32(ctx->r29, 0X58);
    // 0x800290F4: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x800290F8: beq         $at, $zero, L_80029108
    if (ctx->r1 == 0) {
        // 0x800290FC: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_80029108;
    }
    // 0x800290FC: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80029100: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x80029104: sb          $t0, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r8;
L_80029108:
    // 0x80029108: addiu       $s3, $s3, -0x4F60
    ctx->r19 = ADD32(ctx->r19, -0X4F60);
    // 0x8002910C: jal         0x8007B3D0
    // 0x80029110: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_5;
    // 0x80029110: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x80029114: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x80029118: lw          $a0, 0x160($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X160);
    // 0x8002911C: jal         0x80015348
    // 0x80029120: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    sort_objects_by_dist(rdram, ctx);
        goto after_6;
    // 0x80029120: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    after_6:
    // 0x80029124: jal         0x80066220
    // 0x80029128: nop

    get_current_viewport(rdram, ctx);
        goto after_7;
    // 0x80029128: nop

    after_7:
    // 0x8002912C: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x80029130: lw          $s2, 0x160($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X160);
    // 0x80029134: andi        $t1, $v0, 0x1
    ctx->r9 = ctx->r2 & 0X1;
    // 0x80029138: addiu       $t2, $zero, 0x200
    ctx->r10 = ADD32(0, 0X200);
    // 0x8002913C: sllv        $t3, $t2, $t1
    ctx->r11 = S32(ctx->r10 << (ctx->r9 & 31));
    // 0x80029140: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029144: beq         $at, $zero, L_800292A0
    if (ctx->r1 == 0) {
        // 0x80029148: sw          $t3, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r11;
            goto L_800292A0;
    }
    // 0x80029148: sw          $t3, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r11;
    // 0x8002914C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x80029150: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80029154: addiu       $s4, $s4, -0x4F5C
    ctx->r20 = ADD32(ctx->r20, -0X4F5C);
    // 0x80029158: addiu       $s5, $s5, -0x4F58
    ctx->r21 = ADD32(ctx->r21, -0X4F58);
    // 0x8002915C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80029160:
    // 0x80029160: jal         0x8000E948
    // 0x80029164: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    get_object(rdram, ctx);
        goto after_8;
    // 0x80029164: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    after_8:
    // 0x80029168: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x8002916C: lw          $t7, 0x158($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X158);
    // 0x80029170: andi        $t5, $v1, 0x80
    ctx->r13 = ctx->r3 & 0X80;
    // 0x80029174: beq         $t5, $zero, L_80029184
    if (ctx->r13 == 0) {
        // 0x80029178: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_80029184;
    }
    // 0x80029178: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8002917C: b           L_80029198
    // 0x80029180: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_80029198;
    // 0x80029180: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80029184:
    // 0x80029184: andi        $t6, $v1, 0x8000
    ctx->r14 = ctx->r3 & 0X8000;
    // 0x80029188: bne         $t6, $zero, L_8002919C
    if (ctx->r14 != 0) {
        // 0x8002918C: and         $t8, $v1, $t7
        ctx->r24 = ctx->r3 & ctx->r15;
            goto L_8002919C;
    }
    // 0x8002918C: and         $t8, $v1, $t7
    ctx->r24 = ctx->r3 & ctx->r15;
    // 0x80029190: lbu         $s0, 0x39($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X39);
    // 0x80029194: nop

L_80029198:
    // 0x80029198: and         $t8, $v1, $t7
    ctx->r24 = ctx->r3 & ctx->r15;
L_8002919C:
    // 0x8002919C: beq         $t8, $zero, L_800291A8
    if (ctx->r24 == 0) {
        // 0x800291A0: addiu       $at, $zero, 0xFF
        ctx->r1 = ADD32(0, 0XFF);
            goto L_800291A8;
    }
    // 0x800291A0: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800291A4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800291A8:
    // 0x800291A8: beq         $v0, $zero, L_80029290
    if (ctx->r2 == 0) {
        // 0x800291AC: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_80029290;
    }
    // 0x800291AC: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800291B0: bne         $s0, $at, L_80029290
    if (ctx->r16 != ctx->r1) {
        // 0x800291B4: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_80029290;
    }
    // 0x800291B4: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800291B8: jal         0x8002A900
    // 0x800291BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    check_if_in_draw_range(rdram, ctx);
        goto after_9;
    // 0x800291BC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_9:
    // 0x800291C0: beq         $v0, $zero, L_80029290
    if (ctx->r2 == 0) {
        // 0x800291C4: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_80029290;
    }
    // 0x800291C4: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x800291C8: lh          $t9, 0x2E($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X2E);
    // 0x800291CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800291D0: addu        $t0, $s6, $t9
    ctx->r8 = ADD32(ctx->r22, ctx->r25);
    // 0x800291D4: lbu         $t2, 0x1($t0)
    ctx->r10 = MEM_BU(ctx->r8, 0X1);
    // 0x800291D8: nop

    // 0x800291DC: bne         $t2, $zero, L_80029204
    if (ctx->r10 != 0) {
        // 0x800291E0: nop
    
            goto L_80029204;
    }
    // 0x800291E0: nop

    // 0x800291E4: lwc1        $f6, 0x34($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X34);
    // 0x800291E8: lwc1        $f5, 0x5EA0($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X5EA0);
    // 0x800291EC: lwc1        $f4, 0x5EA4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5EA4);
    // 0x800291F0: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800291F4: c.lt.d      $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f4.d < ctx->f8.d;
    // 0x800291F8: nop

    // 0x800291FC: bc1f        L_80029290
    if (!c1cs) {
        // 0x80029200: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_80029290;
    }
    // 0x80029200: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
L_80029204:
    // 0x80029204: lh          $t1, 0x6($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X6);
    // 0x80029208: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002920C: andi        $t3, $t1, 0x8000
    ctx->r11 = ctx->r9 & 0X8000;
    // 0x80029210: beq         $t3, $zero, L_8002922C
    if (ctx->r11 == 0) {
        // 0x80029214: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_8002922C;
    }
    // 0x80029214: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029218: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002921C: jal         0x80012D5C
    // 0x80029220: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_10;
    // 0x80029220: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_10:
    // 0x80029224: b           L_80029290
    // 0x80029228: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
        goto L_80029290;
    // 0x80029228: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
L_8002922C:
    // 0x8002922C: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    // 0x80029230: nop

    // 0x80029234: beq         $a1, $zero, L_80029248
    if (ctx->r5 == 0) {
        // 0x80029238: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80029248;
    }
    // 0x80029238: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002923C: jal         0x8002D384
    // 0x80029240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_render(rdram, ctx);
        goto after_11;
    // 0x80029240: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x80029244: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80029248:
    // 0x80029248: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002924C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029250: jal         0x80012D5C
    // 0x80029254: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_12;
    // 0x80029254: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_12:
    // 0x80029258: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    // 0x8002925C: nop

    // 0x80029260: beq         $a1, $zero, L_80029290
    if (ctx->r5 == 0) {
        // 0x80029264: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_80029290;
    }
    // 0x80029264: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x80029268: lw          $t4, 0x40($s1)
    ctx->r12 = MEM_W(ctx->r17, 0X40);
    // 0x8002926C: nop

    // 0x80029270: lhu         $t5, 0x30($t4)
    ctx->r13 = MEM_HU(ctx->r12, 0X30);
    // 0x80029274: nop

    // 0x80029278: andi        $t6, $t5, 0x10
    ctx->r14 = ctx->r13 & 0X10;
    // 0x8002927C: beq         $t6, $zero, L_80029290
    if (ctx->r14 == 0) {
        // 0x80029280: lw          $v1, 0x16C($sp)
        ctx->r3 = MEM_W(ctx->r29, 0X16C);
            goto L_80029290;
    }
    // 0x80029280: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x80029284: jal         0x8002D670
    // 0x80029288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    watereffect_render(rdram, ctx);
        goto after_13;
    // 0x80029288: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x8002928C: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
L_80029290:
    // 0x80029290: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80029294: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80029298: bne         $at, $zero, L_80029160
    if (ctx->r1 != 0) {
        // 0x8002929C: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80029160;
    }
    // 0x8002929C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800292A0:
    // 0x800292A0: lw          $t7, 0x160($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X160);
    // 0x800292A4: addiu       $s2, $v1, -0x1
    ctx->r18 = ADD32(ctx->r3, -0X1);
    // 0x800292A8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800292AC: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x800292B0: slt         $at, $s2, $t7
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800292B4: addiu       $s5, $s5, -0x4F58
    ctx->r21 = ADD32(ctx->r21, -0X4F58);
    // 0x800292B8: bne         $at, $zero, L_800293CC
    if (ctx->r1 != 0) {
        // 0x800292BC: addiu       $s4, $s4, -0x4F5C
        ctx->r20 = ADD32(ctx->r20, -0X4F5C);
            goto L_800293CC;
    }
    // 0x800292BC: addiu       $s4, $s4, -0x4F5C
    ctx->r20 = ADD32(ctx->r20, -0X4F5C);
    // 0x800292C0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800292C4: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
L_800292C8:
    // 0x800292C8: jal         0x8000E948
    // 0x800292CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    get_object(rdram, ctx);
        goto after_14;
    // 0x800292CC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_14:
    // 0x800292D0: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x800292D4: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800292D8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800292DC: and         $t0, $v1, $t9
    ctx->r8 = ctx->r3 & ctx->r25;
    // 0x800292E0: beq         $t0, $zero, L_800292F0
    if (ctx->r8 == 0) {
        // 0x800292E4: addiu       $s0, $zero, 0x1
        ctx->r16 = ADD32(0, 0X1);
            goto L_800292F0;
    }
    // 0x800292E4: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x800292E8: b           L_800292F0
    // 0x800292EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_800292F0;
    // 0x800292EC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800292F0:
    // 0x800292F0: beq         $v0, $zero, L_800293C0
    if (ctx->r2 == 0) {
        // 0x800292F4: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_800293C0;
    }
    // 0x800292F4: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800292F8: beq         $s0, $zero, L_800293BC
    if (ctx->r16 == 0) {
        // 0x800292FC: andi        $t2, $v1, 0x100
        ctx->r10 = ctx->r3 & 0X100;
            goto L_800293BC;
    }
    // 0x800292FC: andi        $t2, $v1, 0x100
    ctx->r10 = ctx->r3 & 0X100;
    // 0x80029300: beq         $t2, $zero, L_800293C0
    if (ctx->r10 == 0) {
        // 0x80029304: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_800293C0;
    }
    // 0x80029304: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029308: lh          $t1, 0x2E($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2E);
    // 0x8002930C: nop

    // 0x80029310: addu        $t3, $s6, $t1
    ctx->r11 = ADD32(ctx->r22, ctx->r9);
    // 0x80029314: lbu         $t4, 0x1($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X1);
    // 0x80029318: nop

    // 0x8002931C: beq         $t4, $zero, L_800293C0
    if (ctx->r12 == 0) {
        // 0x80029320: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_800293C0;
    }
    // 0x80029320: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029324: jal         0x8002A900
    // 0x80029328: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    check_if_in_draw_range(rdram, ctx);
        goto after_15;
    // 0x80029328: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_15:
    // 0x8002932C: beq         $v0, $zero, L_800293C0
    if (ctx->r2 == 0) {
        // 0x80029330: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_800293C0;
    }
    // 0x80029330: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029334: lh          $t5, 0x6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X6);
    // 0x80029338: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002933C: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x80029340: beq         $t6, $zero, L_8002935C
    if (ctx->r14 == 0) {
        // 0x80029344: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_8002935C;
    }
    // 0x80029344: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029348: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002934C: jal         0x80012D5C
    // 0x80029350: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_16;
    // 0x80029350: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_16:
    // 0x80029354: b           L_800293C0
    // 0x80029358: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
        goto L_800293C0;
    // 0x80029358: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_8002935C:
    // 0x8002935C: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    // 0x80029360: nop

    // 0x80029364: beq         $a1, $zero, L_80029378
    if (ctx->r5 == 0) {
        // 0x80029368: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80029378;
    }
    // 0x80029368: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002936C: jal         0x8002D384
    // 0x80029370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_render(rdram, ctx);
        goto after_17;
    // 0x80029370: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_17:
    // 0x80029374: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80029378:
    // 0x80029378: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8002937C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029380: jal         0x80012D5C
    // 0x80029384: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_18;
    // 0x80029384: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_18:
    // 0x80029388: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    // 0x8002938C: nop

    // 0x80029390: beq         $a1, $zero, L_800293C0
    if (ctx->r5 == 0) {
        // 0x80029394: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_800293C0;
    }
    // 0x80029394: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029398: lw          $t7, 0x40($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X40);
    // 0x8002939C: nop

    // 0x800293A0: lhu         $t8, 0x30($t7)
    ctx->r24 = MEM_HU(ctx->r15, 0X30);
    // 0x800293A4: nop

    // 0x800293A8: andi        $t9, $t8, 0x10
    ctx->r25 = ctx->r24 & 0X10;
    // 0x800293AC: beq         $t9, $zero, L_800293C0
    if (ctx->r25 == 0) {
        // 0x800293B0: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_800293C0;
    }
    // 0x800293B0: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800293B4: jal         0x8002D670
    // 0x800293B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    watereffect_render(rdram, ctx);
        goto after_19;
    // 0x800293B8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_19:
L_800293BC:
    // 0x800293BC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_800293C0:
    // 0x800293C0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800293C4: bne         $s2, $t0, L_800292C8
    if (ctx->r18 != ctx->r8) {
        // 0x800293C8: nop
    
            goto L_800292C8;
    }
    // 0x800293C8: nop

L_800293CC:
    // 0x800293CC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800293D0: lb          $t2, -0x4F20($t2)
    ctx->r10 = MEM_B(ctx->r10, -0X4F20);
    // 0x800293D4: lw          $v0, 0x168($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X168);
    // 0x800293D8: beq         $t2, $zero, L_8002940C
    if (ctx->r10 == 0) {
        // 0x800293DC: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_8002940C;
    }
    // 0x800293DC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800293E0: bltz        $v0, L_8002940C
    if (SIGNED(ctx->r2) < 0) {
        // 0x800293E4: addiu       $t1, $sp, 0xD8
        ctx->r9 = ADD32(ctx->r29, 0XD8);
            goto L_8002940C;
    }
    // 0x800293E4: addiu       $t1, $sp, 0xD8
    ctx->r9 = ADD32(ctx->r29, 0XD8);
    // 0x800293E8: addu        $s0, $v0, $t1
    ctx->r16 = ADD32(ctx->r2, ctx->r9);
    // 0x800293EC: addiu       $s1, $sp, 0xD8
    ctx->r17 = ADD32(ctx->r29, 0XD8);
L_800293F0:
    // 0x800293F0: lbu         $a0, 0x0($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0X0);
    // 0x800293F4: jal         0x80029658
    // 0x800293F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    render_level_segment(rdram, ctx);
        goto after_20;
    // 0x800293F8: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_20:
    // 0x800293FC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    // 0x80029400: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80029404: beq         $at, $zero, L_800293F0
    if (ctx->r1 == 0) {
        // 0x80029408: nop
    
            goto L_800293F0;
    }
    // 0x80029408: nop

L_8002940C:
    // 0x8002940C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80029410: lw          $t3, -0x2C7C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2C7C);
    // 0x80029414: nop

    // 0x80029418: beq         $t3, $zero, L_80029438
    if (ctx->r11 == 0) {
        // 0x8002941C: nop
    
            goto L_80029438;
    }
    // 0x8002941C: nop

    // 0x80029420: jal         0x80066220
    // 0x80029424: nop

    get_current_viewport(rdram, ctx);
        goto after_21;
    // 0x80029424: nop

    after_21:
    // 0x80029428: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8002942C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029430: jal         0x800BA8E4
    // 0x80029434: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    waves_render(rdram, ctx);
        goto after_22;
    // 0x80029434: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_22:
L_80029438:
    // 0x80029438: jal         0x8007B3D0
    // 0x8002943C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_23;
    // 0x8002943C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_23:
    // 0x80029440: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80029444: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80029448: jal         0x8007B4C8
    // 0x8002944C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    material_set_no_tex_offset(rdram, ctx);
        goto after_24;
    // 0x8002944C: addiu       $a2, $zero, 0xA
    ctx->r6 = ADD32(0, 0XA);
    after_24:
    // 0x80029450: jal         0x80012C3C
    // 0x80029454: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    func_80012C3C(rdram, ctx);
        goto after_25;
    // 0x80029454: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_25:
    // 0x80029458: lw          $v1, 0x16C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X16C);
    // 0x8002945C: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x80029460: addiu       $s2, $v1, -0x1
    ctx->r18 = ADD32(ctx->r3, -0X1);
    // 0x80029464: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80029468: bne         $at, $zero, L_800295EC
    if (ctx->r1 != 0) {
        // 0x8002946C: addiu       $t5, $t4, -0x1
        ctx->r13 = ADD32(ctx->r12, -0X1);
            goto L_800295EC;
    }
    // 0x8002946C: addiu       $t5, $t4, -0x1
    ctx->r13 = ADD32(ctx->r12, -0X1);
    // 0x80029470: sw          $t5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r13;
    // 0x80029474: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_80029478:
    // 0x80029478: jal         0x8000E948
    // 0x8002947C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    get_object(rdram, ctx);
        goto after_26;
    // 0x8002947C: addiu       $s0, $zero, 0xFF
    ctx->r16 = ADD32(0, 0XFF);
    after_26:
    // 0x80029480: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80029484: lw          $t8, 0x158($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X158);
    // 0x80029488: andi        $t6, $v1, 0x80
    ctx->r14 = ctx->r3 & 0X80;
    // 0x8002948C: beq         $t6, $zero, L_8002949C
    if (ctx->r14 == 0) {
        // 0x80029490: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8002949C;
    }
    // 0x80029490: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80029494: b           L_800294B0
    // 0x80029498: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
        goto L_800294B0;
    // 0x80029498: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8002949C:
    // 0x8002949C: andi        $t7, $v1, 0x8000
    ctx->r15 = ctx->r3 & 0X8000;
    // 0x800294A0: bne         $t7, $zero, L_800294B4
    if (ctx->r15 != 0) {
        // 0x800294A4: and         $t9, $v1, $t8
        ctx->r25 = ctx->r3 & ctx->r24;
            goto L_800294B4;
    }
    // 0x800294A4: and         $t9, $v1, $t8
    ctx->r25 = ctx->r3 & ctx->r24;
    // 0x800294A8: lbu         $s0, 0x39($v0)
    ctx->r16 = MEM_BU(ctx->r2, 0X39);
    // 0x800294AC: nop

L_800294B0:
    // 0x800294B0: and         $t9, $v1, $t8
    ctx->r25 = ctx->r3 & ctx->r24;
L_800294B4:
    // 0x800294B4: beq         $t9, $zero, L_800294C0
    if (ctx->r25 == 0) {
        // 0x800294B8: nop
    
            goto L_800294C0;
    }
    // 0x800294B8: nop

    // 0x800294BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800294C0:
    // 0x800294C0: lh          $t0, 0x48($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X48);
    // 0x800294C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800294C8: bne         $t0, $at, L_800294DC
    if (ctx->r8 != ctx->r1) {
        // 0x800294CC: slti        $at, $s0, 0xFF
        ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
            goto L_800294DC;
    }
    // 0x800294CC: slti        $at, $s0, 0xFF
    ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
    // 0x800294D0: bne         $at, $zero, L_800294DC
    if (ctx->r1 != 0) {
        // 0x800294D4: nop
    
            goto L_800294DC;
    }
    // 0x800294D4: nop

    // 0x800294D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800294DC:
    // 0x800294DC: beq         $v0, $zero, L_800295DC
    if (ctx->r2 == 0) {
        // 0x800294E0: slti        $at, $s0, 0xFF
        ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
            goto L_800295DC;
    }
    // 0x800294E0: slti        $at, $s0, 0xFF
    ctx->r1 = SIGNED(ctx->r16) < 0XFF ? 1 : 0;
    // 0x800294E4: beq         $at, $zero, L_800295E0
    if (ctx->r1 == 0) {
        // 0x800294E8: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_800295E0;
    }
    // 0x800294E8: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800294EC: lh          $t2, 0x2E($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X2E);
    // 0x800294F0: nop

    // 0x800294F4: addu        $t1, $s6, $t2
    ctx->r9 = ADD32(ctx->r22, ctx->r10);
    // 0x800294F8: lbu         $t3, 0x1($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X1);
    // 0x800294FC: nop

    // 0x80029500: beq         $t3, $zero, L_800295E0
    if (ctx->r11 == 0) {
        // 0x80029504: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_800295E0;
    }
    // 0x80029504: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029508: jal         0x8002A900
    // 0x8002950C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    check_if_in_draw_range(rdram, ctx);
        goto after_27;
    // 0x8002950C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_27:
    // 0x80029510: beq         $v0, $zero, L_800295E0
    if (ctx->r2 == 0) {
        // 0x80029514: lw          $t0, 0x44($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X44);
            goto L_800295E0;
    }
    // 0x80029514: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x80029518: blez        $s0, L_800295A8
    if (SIGNED(ctx->r16) <= 0) {
        // 0x8002951C: nop
    
            goto L_800295A8;
    }
    // 0x8002951C: nop

    // 0x80029520: lh          $t4, 0x6($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X6);
    // 0x80029524: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80029528: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8002952C: beq         $t5, $zero, L_80029548
    if (ctx->r13 == 0) {
        // 0x80029530: or          $a1, $s4, $zero
        ctx->r5 = ctx->r20 | 0;
            goto L_80029548;
    }
    // 0x80029530: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029534: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x80029538: jal         0x80012D5C
    // 0x8002953C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_28;
    // 0x8002953C: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_28:
    // 0x80029540: b           L_800295AC
    // 0x80029544: lh          $t9, 0x48($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X48);
        goto L_800295AC;
    // 0x80029544: lh          $t9, 0x48($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X48);
L_80029548:
    // 0x80029548: lw          $a1, 0x50($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X50);
    // 0x8002954C: nop

    // 0x80029550: beq         $a1, $zero, L_80029564
    if (ctx->r5 == 0) {
        // 0x80029554: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_80029564;
    }
    // 0x80029554: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80029558: jal         0x8002D384
    // 0x8002955C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    shadow_render(rdram, ctx);
        goto after_29;
    // 0x8002955C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_29:
    // 0x80029560: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_80029564:
    // 0x80029564: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x80029568: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x8002956C: jal         0x80012D5C
    // 0x80029570: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_object(rdram, ctx);
        goto after_30;
    // 0x80029570: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_30:
    // 0x80029574: lw          $a1, 0x58($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X58);
    // 0x80029578: nop

    // 0x8002957C: beq         $a1, $zero, L_800295A8
    if (ctx->r5 == 0) {
        // 0x80029580: nop
    
            goto L_800295A8;
    }
    // 0x80029580: nop

    // 0x80029584: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x80029588: nop

    // 0x8002958C: lhu         $t7, 0x30($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0X30);
    // 0x80029590: nop

    // 0x80029594: andi        $t8, $t7, 0x10
    ctx->r24 = ctx->r15 & 0X10;
    // 0x80029598: beq         $t8, $zero, L_800295A8
    if (ctx->r24 == 0) {
        // 0x8002959C: nop
    
            goto L_800295A8;
    }
    // 0x8002959C: nop

    // 0x800295A0: jal         0x8002D670
    // 0x800295A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    watereffect_render(rdram, ctx);
        goto after_31;
    // 0x800295A4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_31:
L_800295A8:
    // 0x800295A8: lh          $t9, 0x48($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X48);
L_800295AC:
    // 0x800295AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800295B0: bne         $t9, $at, L_800295DC
    if (ctx->r25 != ctx->r1) {
        // 0x800295B4: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800295DC;
    }
    // 0x800295B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800295B8: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800295BC: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800295C0: jal         0x80013A0C
    // 0x800295C4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_racer_shield(rdram, ctx);
        goto after_32;
    // 0x800295C4: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_32:
    // 0x800295C8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800295CC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x800295D0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800295D4: jal         0x80013DCC
    // 0x800295D8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    render_racer_magnet(rdram, ctx);
        goto after_33;
    // 0x800295D8: or          $a3, $s1, $zero
    ctx->r7 = ctx->r17 | 0;
    after_33:
L_800295DC:
    // 0x800295DC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
L_800295E0:
    // 0x800295E0: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x800295E4: bne         $s2, $t0, L_80029478
    if (ctx->r18 != ctx->r8) {
        // 0x800295E8: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_80029478;
    }
    // 0x800295E8: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
L_800295EC:
    // 0x800295EC: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800295F0: lw          $t2, -0x36DC($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X36DC);
    // 0x800295F4: nop

    // 0x800295F8: beq         $t2, $zero, L_8002962C
    if (ctx->r10 == 0) {
        // 0x800295FC: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002962C;
    }
    // 0x800295FC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80029600: jal         0x80027568
    // 0x80029604: nop

    func_80027568(rdram, ctx);
        goto after_34;
    // 0x80029604: nop

    after_34:
    // 0x80029608: beq         $v0, $zero, L_8002962C
    if (ctx->r2 == 0) {
        // 0x8002960C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002962C;
    }
    // 0x8002960C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80029610: jal         0x80066220
    // 0x80029614: nop

    get_current_viewport(rdram, ctx);
        goto after_35;
    // 0x80029614: nop

    after_35:
    // 0x80029618: lw          $a1, 0x168($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X168);
    // 0x8002961C: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x80029620: jal         0x8002581C
    // 0x80029624: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    void_check(rdram, ctx);
        goto after_36;
    // 0x80029624: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_36:
    // 0x80029628: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8002962C:
    // 0x8002962C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80029630: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80029634: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80029638: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x8002963C: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80029640: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80029644: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x80029648: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x8002964C: sw          $zero, -0x4F04($at)
    MEM_W(-0X4F04, ctx->r1) = 0;
    // 0x80029650: jr          $ra
    // 0x80029654: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
    return;
    // 0x80029654: addiu       $sp, $sp, 0x170
    ctx->r29 = ADD32(ctx->r29, 0X170);
;}
RECOMP_FUNC void obj_loop_butterfly(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040C54: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80040C58: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80040C5C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80040C60: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80040C64: lw          $t1, 0x3C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X3C);
    // 0x80040C68: lw          $t0, 0x64($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X64);
    // 0x80040C6C: lbu         $t6, 0xA($t1)
    ctx->r14 = MEM_BU(ctx->r9, 0XA);
    // 0x80040C70: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x80040C74: xori        $t7, $t6, 0x2
    ctx->r15 = ctx->r14 ^ 0X2;
    // 0x80040C78: sltiu       $t7, $t7, 0x1
    ctx->r15 = ctx->r15 < 0X1 ? 1 : 0;
    // 0x80040C7C: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
    // 0x80040C80: lh          $v1, 0x106($t0)
    ctx->r3 = MEM_H(ctx->r8, 0X106);
    // 0x80040C84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80040C88: sll         $t2, $v1, 16
    ctx->r10 = S32(ctx->r3 << 16);
    // 0x80040C8C: sra         $t8, $t2, 16
    ctx->r24 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80040C90: bgez        $t8, L_80040CA4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80040C94: or          $t2, $t8, $zero
        ctx->r10 = ctx->r24 | 0;
            goto L_80040CA4;
    }
    // 0x80040C94: or          $t2, $t8, $zero
    ctx->r10 = ctx->r24 | 0;
    // 0x80040C98: negu        $t2, $t8
    ctx->r10 = SUB32(0, ctx->r24);
    // 0x80040C9C: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x80040CA0: sra         $t2, $t9, 16
    ctx->r10 = S32(SIGNED(ctx->r25) >> 16);
L_80040CA4:
    // 0x80040CA4: multu       $t2, $t4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040CA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80040CAC: lwc1        $f0, 0x621C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X621C);
    // 0x80040CB0: lw          $t7, 0x64($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X64);
    // 0x80040CB4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80040CB8: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x80040CBC: mflo        $t2
    ctx->r10 = lo;
    // 0x80040CC0: sll         $t5, $t2, 16
    ctx->r13 = S32(ctx->r10 << 16);
    // 0x80040CC4: beq         $t7, $zero, L_80040CDC
    if (ctx->r15 == 0) {
        // 0x80040CC8: sra         $t2, $t5, 16
        ctx->r10 = S32(SIGNED(ctx->r13) >> 16);
            goto L_80040CDC;
    }
    // 0x80040CC8: sra         $t2, $t5, 16
    ctx->r10 = S32(SIGNED(ctx->r13) >> 16);
    // 0x80040CCC: lwc1        $f4, 0x6220($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X6220);
    // 0x80040CD0: nop

    // 0x80040CD4: mul.s       $f16, $f0, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80040CD8: nop

L_80040CDC:
    // 0x80040CDC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x80040CE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80040CE4: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80040CE8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80040CEC: beq         $t8, $zero, L_80040D04
    if (ctx->r24 == 0) {
        // 0x80040CF0: swc1        $f0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
            goto L_80040D04;
    }
    // 0x80040CF0: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80040CF4: lwc1        $f6, 0x6224($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6224);
    // 0x80040CF8: nop

    // 0x80040CFC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80040D00: swc1        $f8, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f8.u32l;
L_80040D04:
    // 0x80040D04: lbu         $v0, 0xFD($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XFD);
    // 0x80040D08: nop

    // 0x80040D0C: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x80040D10: beq         $at, $zero, L_80041838
    if (ctx->r1 == 0) {
        // 0x80040D14: sll         $t9, $v0, 2
        ctx->r25 = S32(ctx->r2 << 2);
            goto L_80041838;
    }
    // 0x80040D14: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80040D18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80040D1C: addu        $at, $at, $t9
    gpr jr_addend_80040D28 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80040D20: lw          $t9, 0x6228($at)
    ctx->r25 = ADD32(ctx->r1, 0X6228);
    // 0x80040D24: nop

    // 0x80040D28: jr          $t9
    // 0x80040D2C: nop

    switch (jr_addend_80040D28 >> 2) {
        case 0: goto L_80040D30; break;
        case 1: goto L_80040E54; break;
        case 2: goto L_80040E54; break;
        case 3: goto L_800411E4; break;
        case 4: goto L_8004153C; break;
        default: switch_error(__func__, 0x80040D28, 0x800E6228);
    }
    // 0x80040D2C: nop

L_80040D30:
    // 0x80040D30: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80040D34: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80040D38: swc1        $f14, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f14.u32l;
    // 0x80040D3C: lhu         $t3, 0x8($t1)
    ctx->r11 = MEM_HU(ctx->r9, 0X8);
    // 0x80040D40: addiu       $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x80040D44: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x80040D48: bgez        $t3, L_80040D60
    if (SIGNED(ctx->r11) >= 0) {
        // 0x80040D4C: cvt.s.w     $f0, $f10
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80040D60;
    }
    // 0x80040D4C: cvt.s.w     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    ctx->f0.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80040D50: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80040D54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80040D58: nop

    // 0x80040D5C: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_80040D60:
    // 0x80040D60: lh          $t5, 0x6($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X6);
    // 0x80040D64: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80040D68: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80040D6C: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80040D70: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80040D74: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80040D78: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x80040D7C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80040D80: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80040D84: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80040D88: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x80040D8C: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80040D90: jal         0x80016DE8
    // 0x80040D94: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    obj_dist_racer(rdram, ctx);
        goto after_0;
    // 0x80040D94: cvt.s.w     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    ctx->f12.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x80040D98: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x80040D9C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80040DA0: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80040DA4: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80040DA8: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80040DAC: blez        $t9, L_80040DD0
    if (SIGNED(ctx->r25) <= 0) {
        // 0x80040DB0: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_80040DD0;
    }
    // 0x80040DB0: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80040DB4: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x80040DB8: addiu       $t4, $zero, 0xF0
    ctx->r12 = ADD32(0, 0XF0);
    // 0x80040DBC: addiu       $t5, $zero, 0x3
    ctx->r13 = ADD32(0, 0X3);
    // 0x80040DC0: sh          $t4, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r12;
    // 0x80040DC4: sb          $t5, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r13;
    // 0x80040DC8: b           L_80040E1C
    // 0x80040DCC: sw          $t3, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r11;
        goto L_80040E1C;
    // 0x80040DCC: sw          $t3, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r11;
L_80040DD0:
    // 0x80040DD0: lh          $t7, 0x6($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X6);
    // 0x80040DD4: lh          $t6, 0x2($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X2);
    // 0x80040DD8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80040DDC: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x80040DE0: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80040DE4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80040DE8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80040DEC: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80040DF0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80040DF4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80040DF8: jal         0x80016C68
    // 0x80040DFC: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    obj_butterfly_node(rdram, ctx);
        goto after_1;
    // 0x80040DFC: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_1:
    // 0x80040E00: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80040E04: beq         $v0, $zero, L_80040E1C
    if (ctx->r2 == 0) {
        // 0x80040E08: sw          $v0, 0x100($t0)
        MEM_W(0X100, ctx->r8) = ctx->r2;
            goto L_80040E1C;
    }
    // 0x80040E08: sw          $v0, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r2;
    // 0x80040E0C: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x80040E10: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80040E14: sh          $t9, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r25;
    // 0x80040E18: sb          $t3, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r11;
L_80040E1C:
    // 0x80040E1C: lh          $t4, 0x18($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X18);
    // 0x80040E20: lw          $t5, 0x9C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X9C);
    // 0x80040E24: addiu       $t9, $zero, 0x78
    ctx->r25 = ADD32(0, 0X78);
    // 0x80040E28: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x80040E2C: andi        $t7, $t6, 0xFF
    ctx->r15 = ctx->r14 & 0XFF;
    // 0x80040E30: sh          $t7, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r15;
    // 0x80040E34: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80040E38: nop

    // 0x80040E3C: beq         $t8, $zero, L_80040E48
    if (ctx->r24 == 0) {
        // 0x80040E40: nop
    
            goto L_80040E48;
    }
    // 0x80040E40: nop

    // 0x80040E44: sh          $t9, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r25;
L_80040E48:
    // 0x80040E48: lbu         $v0, 0xFD($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XFD);
    // 0x80040E4C: b           L_80041838
    // 0x80040E50: nop

        goto L_80041838;
    // 0x80040E50: nop

L_80040E54:
    // 0x80040E54: slti        $at, $v1, 0x480
    ctx->r1 = SIGNED(ctx->r3) < 0X480 ? 1 : 0;
    // 0x80040E58: beq         $at, $zero, L_80040E8C
    if (ctx->r1 == 0) {
        // 0x80040E5C: nop
    
            goto L_80040E8C;
    }
    // 0x80040E5C: nop

    // 0x80040E60: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80040E64: addiu       $t7, $zero, 0x480
    ctx->r15 = ADD32(0, 0X480);
    // 0x80040E68: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80040E6C: addu        $t5, $v1, $t4
    ctx->r13 = ADD32(ctx->r3, ctx->r12);
    // 0x80040E70: sh          $t5, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r13;
    // 0x80040E74: lh          $t6, 0x106($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X106);
    // 0x80040E78: nop

    // 0x80040E7C: slti        $at, $t6, 0x481
    ctx->r1 = SIGNED(ctx->r14) < 0X481 ? 1 : 0;
    // 0x80040E80: bne         $at, $zero, L_80040E8C
    if (ctx->r1 != 0) {
        // 0x80040E84: nop
    
            goto L_80040E8C;
    }
    // 0x80040E84: nop

    // 0x80040E88: sh          $t7, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r15;
L_80040E8C:
    // 0x80040E8C: lh          $t8, 0x2($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X2);
    // 0x80040E90: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80040E94: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80040E98: lh          $t9, 0x6($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X6);
    // 0x80040E9C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80040EA0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80040EA4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040EA8: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x80040EAC: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x80040EB0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80040EB4: sll         $t4, $t3, 4
    ctx->r12 = S32(ctx->r11 << 4);
    // 0x80040EB8: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x80040EBC: sub.s       $f12, $f18, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80040EC0: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80040EC4: sub.s       $f14, $f8, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80040EC8: swc1        $f12, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f12.u32l;
    // 0x80040ECC: swc1        $f14, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f14.u32l;
    // 0x80040ED0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80040ED4: jal         0x80070750
    // 0x80040ED8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    arctan2_f(rdram, ctx);
        goto after_2;
    // 0x80040ED8: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_2:
    // 0x80040EDC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80040EE0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80040EE4: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x80040EE8: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x80040EEC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80040EF0: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x80040EF4: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80040EF8: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80040EFC: bgez        $t8, L_80040F28
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80040F00: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_80040F28;
    }
    // 0x80040F00: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x80040F04: negu        $t9, $t2
    ctx->r25 = SUB32(0, ctx->r10);
    // 0x80040F08: slt         $at, $t9, $t8
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80040F0C: beq         $at, $zero, L_80040F20
    if (ctx->r1 == 0) {
        // 0x80040F10: subu        $t4, $a0, $t2
        ctx->r12 = SUB32(ctx->r4, ctx->r10);
            goto L_80040F20;
    }
    // 0x80040F10: subu        $t4, $a0, $t2
    ctx->r12 = SUB32(ctx->r4, ctx->r10);
    // 0x80040F14: addu        $t3, $a0, $t8
    ctx->r11 = ADD32(ctx->r4, ctx->r24);
    // 0x80040F18: b           L_80040F48
    // 0x80040F1C: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
        goto L_80040F48;
    // 0x80040F1C: sh          $t3, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r11;
L_80040F20:
    // 0x80040F20: b           L_80040F48
    // 0x80040F24: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
        goto L_80040F48;
    // 0x80040F24: sh          $t4, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r12;
L_80040F28:
    // 0x80040F28: blez        $v1, L_80040F48
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80040F2C: slt         $at, $v1, $t2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80040F48;
    }
    // 0x80040F2C: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80040F30: beq         $at, $zero, L_80040F44
    if (ctx->r1 == 0) {
        // 0x80040F34: addu        $t6, $a0, $t2
        ctx->r14 = ADD32(ctx->r4, ctx->r10);
            goto L_80040F44;
    }
    // 0x80040F34: addu        $t6, $a0, $t2
    ctx->r14 = ADD32(ctx->r4, ctx->r10);
    // 0x80040F38: addu        $t5, $a0, $v1
    ctx->r13 = ADD32(ctx->r4, ctx->r3);
    // 0x80040F3C: b           L_80040F48
    // 0x80040F40: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
        goto L_80040F48;
    // 0x80040F40: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
L_80040F44:
    // 0x80040F44: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
L_80040F48:
    // 0x80040F48: lh          $t7, 0x4($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X4);
    // 0x80040F4C: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80040F50: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x80040F54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80040F58: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80040F5C: lw          $t8, 0x9C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X9C);
    // 0x80040F60: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80040F64: sub.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x80040F68: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80040F6C: nop

    // 0x80040F70: bc1f        L_80040FB0
    if (!c1cs) {
        // 0x80040F74: nop
    
            goto L_80040FB0;
    }
    // 0x80040F74: nop

    // 0x80040F78: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80040F7C: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80040F80: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80040F84: mul.s       $f10, $f16, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f6.fl);
    // 0x80040F88: sub.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80040F8C: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x80040F90: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80040F94: nop

    // 0x80040F98: c.lt.s      $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f18.fl < ctx->f0.fl;
    // 0x80040F9C: nop

    // 0x80040FA0: bc1f        L_8004100C
    if (!c1cs) {
        // 0x80040FA4: nop
    
            goto L_8004100C;
    }
    // 0x80040FA4: nop

    // 0x80040FA8: b           L_8004100C
    // 0x80040FAC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
        goto L_8004100C;
    // 0x80040FAC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_80040FB0:
    // 0x80040FB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80040FB4: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x80040FB8: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80040FBC: nop

    // 0x80040FC0: bc1f        L_80041000
    if (!c1cs) {
        // 0x80040FC4: nop
    
            goto L_80041000;
    }
    // 0x80040FC4: nop

    // 0x80040FC8: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80040FCC: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80040FD0: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80040FD4: mul.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x80040FD8: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80040FDC: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
    // 0x80040FE0: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80040FE4: nop

    // 0x80040FE8: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80040FEC: nop

    // 0x80040FF0: bc1f        L_8004100C
    if (!c1cs) {
        // 0x80040FF4: nop
    
            goto L_8004100C;
    }
    // 0x80040FF4: nop

    // 0x80040FF8: b           L_8004100C
    // 0x80040FFC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
        goto L_8004100C;
    // 0x80040FFC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_80041000:
    // 0x80041000: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80041004: nop

    // 0x80041008: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
L_8004100C:
    // 0x8004100C: lbu         $t3, 0xFD($t0)
    ctx->r11 = MEM_BU(ctx->r8, 0XFD);
    // 0x80041010: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80041014: bne         $t3, $at, L_80041104
    if (ctx->r11 != ctx->r1) {
        // 0x80041018: addiu       $t8, $sp, 0x44
        ctx->r24 = ADD32(ctx->r29, 0X44);
            goto L_80041104;
    }
    // 0x80041018: addiu       $t8, $sp, 0x44
    ctx->r24 = ADD32(ctx->r29, 0X44);
    // 0x8004101C: lhu         $t4, 0x8($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X8);
    // 0x80041020: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80041024: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x80041028: bgez        $t4, L_80041040
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8004102C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80041040;
    }
    // 0x8004102C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041030: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80041034: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80041038: nop

    // 0x8004103C: add.s       $f0, $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f18.fl;
L_80041040:
    // 0x80041040: lh          $t6, 0x6($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X6);
    // 0x80041044: lh          $t5, 0x2($t1)
    ctx->r13 = MEM_H(ctx->r9, 0X2);
    // 0x80041048: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8004104C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80041050: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80041054: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80041058: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x8004105C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x80041060: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x80041064: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041068: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8004106C: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80041070: jal         0x80016DE8
    // 0x80041074: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    obj_dist_racer(rdram, ctx);
        goto after_3;
    // 0x80041074: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    after_3:
    // 0x80041078: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x8004107C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041080: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80041084: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80041088: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8004108C: blez        $t3, L_800410B0
    if (SIGNED(ctx->r11) <= 0) {
        // 0x80041090: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_800410B0;
    }
    // 0x80041090: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80041094: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x80041098: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x8004109C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800410A0: sh          $t5, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r13;
    // 0x800410A4: sb          $t6, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r14;
    // 0x800410A8: b           L_80041104
    // 0x800410AC: sw          $t4, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r12;
        goto L_80041104;
    // 0x800410AC: sw          $t4, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r12;
L_800410B0:
    // 0x800410B0: lh          $t8, 0x6($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X6);
    // 0x800410B4: lh          $t7, 0x2($t1)
    ctx->r15 = MEM_H(ctx->r9, 0X2);
    // 0x800410B8: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800410BC: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800410C0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800410C4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800410C8: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800410CC: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800410D0: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800410D4: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800410D8: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x800410DC: jal         0x80016C68
    // 0x800410E0: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    obj_butterfly_node(rdram, ctx);
        goto after_4;
    // 0x800410E0: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_4:
    // 0x800410E4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800410E8: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x800410EC: beq         $v0, $zero, L_80041104
    if (ctx->r2 == 0) {
        // 0x800410F0: sw          $v0, 0x100($t0)
        MEM_W(0X100, ctx->r8) = ctx->r2;
            goto L_80041104;
    }
    // 0x800410F0: sw          $v0, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r2;
    // 0x800410F4: addiu       $t3, $zero, 0xF0
    ctx->r11 = ADD32(0, 0XF0);
    // 0x800410F8: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x800410FC: sh          $t3, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r11;
    // 0x80041100: sb          $t4, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r12;
L_80041104:
    // 0x80041104: lbu         $t5, 0xFD($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XFD);
    // 0x80041108: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8004110C: beq         $t5, $at, L_800411C0
    if (ctx->r13 == ctx->r1) {
        // 0x80041110: nop
    
            goto L_800411C0;
    }
    // 0x80041110: nop

    // 0x80041114: lh          $t6, 0x4($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X4);
    // 0x80041118: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8004111C: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80041120: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80041124: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041128: lwc1        $f14, 0x8C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8004112C: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041130: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80041134: sub.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80041138: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    // 0x8004113C: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80041140: nop

    // 0x80041144: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80041148: add.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x8004114C: jal         0x800C9AD0
    // 0x80041150: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80041150: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_5:
    // 0x80041154: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80041158: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8004115C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041160: c.lt.s      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.fl < ctx->f10.fl;
    // 0x80041164: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80041168: bc1f        L_800411C0
    if (!c1cs) {
        // 0x8004116C: nop
    
            goto L_800411C0;
    }
    // 0x8004116C: nop

    // 0x80041170: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041174: jal         0x80011560
    // 0x80041178: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    ignore_bounds_check(rdram, ctx);
        goto after_6;
    // 0x80041178: swc1        $f2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f2.u32l;
    after_6:
    // 0x8004117C: lwc1        $f2, 0x90($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X90);
    // 0x80041180: lwc1        $f8, 0x94($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X94);
    // 0x80041184: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x80041188: neg.s       $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = -ctx->f2.fl;
    // 0x8004118C: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x80041190: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x80041194: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x80041198: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8004119C: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x800411A0: jal         0x80011570
    // 0x800411A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    move_object(rdram, ctx);
        goto after_7;
    // 0x800411A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x800411A8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800411AC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800411B0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800411B4: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x800411B8: sb          $zero, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = 0;
    // 0x800411BC: swc1        $f4, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f4.u32l;
L_800411C0:
    // 0x800411C0: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x800411C4: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x800411C8: nop

    // 0x800411CC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800411D0: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x800411D4: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
    // 0x800411D8: lbu         $v0, 0xFD($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XFD);
    // 0x800411DC: b           L_80041838
    // 0x800411E0: nop

        goto L_80041838;
    // 0x800411E0: nop

L_800411E4:
    // 0x800411E4: slti        $at, $v1, 0x480
    ctx->r1 = SIGNED(ctx->r3) < 0X480 ? 1 : 0;
    // 0x800411E8: beq         $at, $zero, L_8004121C
    if (ctx->r1 == 0) {
        // 0x800411EC: nop
    
            goto L_8004121C;
    }
    // 0x800411EC: nop

    // 0x800411F0: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x800411F4: addiu       $t8, $zero, 0x480
    ctx->r24 = ADD32(0, 0X480);
    // 0x800411F8: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x800411FC: addu        $t6, $v1, $t5
    ctx->r14 = ADD32(ctx->r3, ctx->r13);
    // 0x80041200: sh          $t6, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r14;
    // 0x80041204: lh          $t7, 0x106($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X106);
    // 0x80041208: nop

    // 0x8004120C: slti        $at, $t7, 0x481
    ctx->r1 = SIGNED(ctx->r15) < 0X481 ? 1 : 0;
    // 0x80041210: bne         $at, $zero, L_8004121C
    if (ctx->r1 != 0) {
        // 0x80041214: nop
    
            goto L_8004121C;
    }
    // 0x80041214: nop

    // 0x80041218: sh          $t8, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r24;
L_8004121C:
    // 0x8004121C: lh          $t9, 0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X2);
    // 0x80041220: lw          $v0, 0x100($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X100);
    // 0x80041224: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80041228: lhu         $t4, 0x8($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X8);
    // 0x8004122C: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80041230: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80041234: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x80041238: sub.s       $f2, $f6, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8004123C: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80041240: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x80041244: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041248: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x8004124C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80041250: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80041254: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x80041258: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x8004125C: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80041260: cvt.s.w     $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    ctx->f18.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80041264: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x80041268: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8004126C: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80041270: sub.s       $f12, $f8, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x80041274: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x80041278: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8004127C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80041280: nop

    // 0x80041284: bc1f        L_80041380
    if (!c1cs) {
        // 0x80041288: nop
    
            goto L_80041380;
    }
    // 0x80041288: nop

    // 0x8004128C: sw          $zero, 0x100($t0)
    MEM_W(0X100, ctx->r8) = 0;
    // 0x80041290: lhu         $t8, 0x8($t1)
    ctx->r24 = MEM_HU(ctx->r9, 0X8);
    // 0x80041294: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80041298: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x8004129C: bgez        $t8, L_800412B4
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800412A0: cvt.s.w     $f0, $f18
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800412B4;
    }
    // 0x800412A0: cvt.s.w     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    ctx->f0.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800412A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800412A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800412AC: nop

    // 0x800412B0: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_800412B4:
    // 0x800412B4: lh          $t9, 0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X2);
    // 0x800412B8: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x800412BC: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800412C0: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800412C4: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x800412C8: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800412CC: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x800412D0: swc1        $f0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f0.u32l;
    // 0x800412D4: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x800412D8: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x800412DC: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x800412E0: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x800412E4: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x800412E8: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800412EC: jal         0x80016DE8
    // 0x800412F0: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    obj_dist_racer(rdram, ctx);
        goto after_8;
    // 0x800412F0: cvt.s.w     $f12, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    ctx->f12.fl = CVT_S_W(ctx->f10.u32l);
    after_8:
    // 0x800412F4: sll         $t6, $v0, 16
    ctx->r14 = S32(ctx->r2 << 16);
    // 0x800412F8: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800412FC: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80041300: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x80041304: lwc1        $f0, 0x84($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X84);
    // 0x80041308: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8004130C: sra         $t7, $t6, 16
    ctx->r15 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80041310: blez        $t7, L_8004132C
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80041314: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8004132C;
    }
    // 0x80041314: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80041318: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8004131C: addiu       $t9, $zero, 0xF0
    ctx->r25 = ADD32(0, 0XF0);
    // 0x80041320: sh          $t9, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r25;
    // 0x80041324: b           L_80041380
    // 0x80041328: sw          $t8, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r24;
        goto L_80041380;
    // 0x80041328: sw          $t8, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r24;
L_8004132C:
    // 0x8004132C: lh          $t4, 0x6($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X6);
    // 0x80041330: lh          $t3, 0x2($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X2);
    // 0x80041334: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80041338: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x8004133C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80041340: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80041344: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80041348: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8004134C: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x80041350: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x80041354: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041358: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8004135C: jal         0x80016C68
    // 0x80041360: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    obj_butterfly_node(rdram, ctx);
        goto after_9;
    // 0x80041360: cvt.s.w     $f12, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    ctx->f12.fl = CVT_S_W(ctx->f8.u32l);
    after_9:
    // 0x80041364: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041368: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x8004136C: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80041370: beq         $v0, $zero, L_80041380
    if (ctx->r2 == 0) {
        // 0x80041374: sw          $v0, 0x100($t0)
        MEM_W(0X100, ctx->r8) = ctx->r2;
            goto L_80041380;
    }
    // 0x80041374: sw          $v0, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r2;
    // 0x80041378: addiu       $t6, $zero, 0xF0
    ctx->r14 = ADD32(0, 0XF0);
    // 0x8004137C: sh          $t6, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r14;
L_80041380:
    // 0x80041380: lw          $v0, 0x100($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X100);
    // 0x80041384: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80041388: beq         $v0, $zero, L_80041514
    if (ctx->r2 == 0) {
        // 0x8004138C: nop
    
            goto L_80041514;
    }
    // 0x8004138C: nop

    // 0x80041390: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80041394: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80041398: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8004139C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800413A0: sub.s       $f12, $f6, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800413A4: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x800413A8: sub.s       $f14, $f4, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800413AC: swc1        $f12, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f12.u32l;
    // 0x800413B0: swc1        $f14, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f14.u32l;
    // 0x800413B4: sh          $t2, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r10;
    // 0x800413B8: jal         0x80070750
    // 0x800413BC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    arctan2_f(rdram, ctx);
        goto after_10;
    // 0x800413BC: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_10:
    // 0x800413C0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800413C4: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800413C8: subu        $v1, $v0, $a0
    ctx->r3 = SUB32(ctx->r2, ctx->r4);
    // 0x800413CC: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x800413D0: lh          $t2, 0x72($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X72);
    // 0x800413D4: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800413D8: sra         $t3, $t9, 16
    ctx->r11 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800413DC: bgez        $t3, L_80041408
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800413E0: or          $v1, $t3, $zero
        ctx->r3 = ctx->r11 | 0;
            goto L_80041408;
    }
    // 0x800413E0: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
    // 0x800413E4: negu        $t4, $t2
    ctx->r12 = SUB32(0, ctx->r10);
    // 0x800413E8: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800413EC: beq         $at, $zero, L_80041400
    if (ctx->r1 == 0) {
        // 0x800413F0: subu        $t6, $a0, $t2
        ctx->r14 = SUB32(ctx->r4, ctx->r10);
            goto L_80041400;
    }
    // 0x800413F0: subu        $t6, $a0, $t2
    ctx->r14 = SUB32(ctx->r4, ctx->r10);
    // 0x800413F4: addu        $t5, $a0, $t3
    ctx->r13 = ADD32(ctx->r4, ctx->r11);
    // 0x800413F8: b           L_80041428
    // 0x800413FC: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
        goto L_80041428;
    // 0x800413FC: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
L_80041400:
    // 0x80041400: b           L_80041428
    // 0x80041404: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
        goto L_80041428;
    // 0x80041404: sh          $t6, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r14;
L_80041408:
    // 0x80041408: blez        $v1, L_80041428
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8004140C: slt         $at, $v1, $t2
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
            goto L_80041428;
    }
    // 0x8004140C: slt         $at, $v1, $t2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80041410: beq         $at, $zero, L_80041424
    if (ctx->r1 == 0) {
        // 0x80041414: addu        $t8, $a0, $t2
        ctx->r24 = ADD32(ctx->r4, ctx->r10);
            goto L_80041424;
    }
    // 0x80041414: addu        $t8, $a0, $t2
    ctx->r24 = ADD32(ctx->r4, ctx->r10);
    // 0x80041418: addu        $t7, $a0, $v1
    ctx->r15 = ADD32(ctx->r4, ctx->r3);
    // 0x8004141C: b           L_80041428
    // 0x80041420: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
        goto L_80041428;
    // 0x80041420: sh          $t7, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r15;
L_80041424:
    // 0x80041424: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_80041428:
    // 0x80041428: lw          $t9, 0x100($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X100);
    // 0x8004142C: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80041430: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80041434: lwc1        $f18, 0x10($t9)
    ctx->f18.u32l = MEM_W(ctx->r25, 0X10);
    // 0x80041438: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8004143C: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80041440: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80041444: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80041448: lw          $t3, 0x9C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X9C);
    // 0x8004144C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80041450: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x80041454: bc1f        L_80041494
    if (!c1cs) {
        // 0x80041458: nop
    
            goto L_80041494;
    }
    // 0x80041458: nop

    // 0x8004145C: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80041460: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041464: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80041468: mul.s       $f4, $f16, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x8004146C: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80041470: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x80041474: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041478: nop

    // 0x8004147C: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x80041480: nop

    // 0x80041484: bc1f        L_800414E0
    if (!c1cs) {
        // 0x80041488: nop
    
            goto L_800414E0;
    }
    // 0x80041488: nop

    // 0x8004148C: b           L_800414E0
    // 0x80041490: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
        goto L_800414E0;
    // 0x80041490: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_80041494:
    // 0x80041494: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80041498: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x8004149C: c.lt.s      $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f10.fl < ctx->f0.fl;
    // 0x800414A0: nop

    // 0x800414A4: bc1f        L_800414E0
    if (!c1cs) {
        // 0x800414A8: nop
    
            goto L_800414E0;
    }
    // 0x800414A8: nop

    // 0x800414AC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800414B0: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800414B4: cvt.s.w     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    ctx->f8.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800414B8: mul.s       $f6, $f16, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800414BC: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x800414C0: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800414C4: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800414C8: nop

    // 0x800414CC: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800414D0: nop

    // 0x800414D4: bc1f        L_800414E0
    if (!c1cs) {
        // 0x800414D8: nop
    
            goto L_800414E0;
    }
    // 0x800414D8: nop

    // 0x800414DC: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_800414E0:
    // 0x800414E0: lwc1        $f0, 0x94($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800414E4: lwc1        $f2, 0x8C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x800414E8: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800414EC: lui         $at, 0x4380
    ctx->r1 = S32(0X4380 << 16);
    // 0x800414F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800414F4: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800414F8: add.s       $f6, $f8, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x800414FC: c.lt.s      $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f6.fl < ctx->f10.fl;
    // 0x80041500: nop

    // 0x80041504: bc1f        L_80041518
    if (!c1cs) {
        // 0x80041508: nop
    
            goto L_80041518;
    }
    // 0x80041508: nop

    // 0x8004150C: b           L_80041518
    // 0x80041510: sb          $t5, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r13;
        goto L_80041518;
    // 0x80041510: sb          $t5, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r13;
L_80041514:
    // 0x80041514: sb          $t6, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r14;
L_80041518:
    // 0x80041518: lh          $t7, 0x18($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X18);
    // 0x8004151C: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80041520: nop

    // 0x80041524: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x80041528: andi        $t3, $t9, 0xFF
    ctx->r11 = ctx->r25 & 0XFF;
    // 0x8004152C: sh          $t3, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r11;
    // 0x80041530: lbu         $v0, 0xFD($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XFD);
    // 0x80041534: b           L_80041838
    // 0x80041538: nop

        goto L_80041838;
    // 0x80041538: nop

L_8004153C:
    // 0x8004153C: slti        $at, $v1, 0x181
    ctx->r1 = SIGNED(ctx->r3) < 0X181 ? 1 : 0;
    // 0x80041540: bne         $at, $zero, L_80041574
    if (ctx->r1 != 0) {
        // 0x80041544: nop
    
            goto L_80041574;
    }
    // 0x80041544: nop

    // 0x80041548: lw          $t4, 0x9C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X9C);
    // 0x8004154C: addiu       $t8, $zero, 0x180
    ctx->r24 = ADD32(0, 0X180);
    // 0x80041550: sll         $t5, $t4, 4
    ctx->r13 = S32(ctx->r12 << 4);
    // 0x80041554: subu        $t6, $v1, $t5
    ctx->r14 = SUB32(ctx->r3, ctx->r13);
    // 0x80041558: sh          $t6, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r14;
    // 0x8004155C: lh          $t7, 0x106($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X106);
    // 0x80041560: nop

    // 0x80041564: slti        $at, $t7, 0x180
    ctx->r1 = SIGNED(ctx->r15) < 0X180 ? 1 : 0;
    // 0x80041568: beq         $at, $zero, L_80041574
    if (ctx->r1 == 0) {
        // 0x8004156C: nop
    
            goto L_80041574;
    }
    // 0x8004156C: nop

    // 0x80041570: sh          $t8, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r24;
L_80041574:
    // 0x80041574: lh          $t9, 0x2($t1)
    ctx->r25 = MEM_H(ctx->r9, 0X2);
    // 0x80041578: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8004157C: mtc1        $t9, $f8
    ctx->f8.u32l = ctx->r25;
    // 0x80041580: lhu         $t4, 0x8($t1)
    ctx->r12 = MEM_HU(ctx->r9, 0X8);
    // 0x80041584: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80041588: sll         $t5, $t4, 1
    ctx->r13 = S32(ctx->r12 << 1);
    // 0x8004158C: lh          $t3, 0x6($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X6);
    // 0x80041590: sub.s       $f2, $f4, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80041594: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x80041598: mtc1        $t3, $f10
    ctx->f10.u32l = ctx->r11;
    // 0x8004159C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800415A0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800415A4: lw          $t6, 0x9C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X9C);
    // 0x800415A8: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800415AC: lw          $t9, 0x9C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X9C);
    // 0x800415B0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800415B4: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x800415B8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800415BC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800415C0: mul.s       $f18, $f2, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800415C4: sub.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800415C8: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800415CC: add.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x800415D0: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800415D4: nop

    // 0x800415D8: bc1f        L_800415E8
    if (!c1cs) {
        // 0x800415DC: nop
    
            goto L_800415E8;
    }
    // 0x800415DC: nop

    // 0x800415E0: b           L_80041818
    // 0x800415E4: sb          $t8, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r24;
        goto L_80041818;
    // 0x800415E4: sb          $t8, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r24;
L_800415E8:
    // 0x800415E8: lhu         $v0, 0x104($t0)
    ctx->r2 = MEM_HU(ctx->r8, 0X104);
    // 0x800415EC: lui         $a3, 0x4316
    ctx->r7 = S32(0X4316 << 16);
    // 0x800415F0: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800415F4: beq         $at, $zero, L_80041608
    if (ctx->r1 == 0) {
        // 0x800415F8: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80041608;
    }
    // 0x800415F8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800415FC: subu        $t3, $v0, $t9
    ctx->r11 = SUB32(ctx->r2, ctx->r25);
    // 0x80041600: b           L_800416B4
    // 0x80041604: sh          $t3, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r11;
        goto L_800416B4;
    // 0x80041604: sh          $t3, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r11;
L_80041608:
    // 0x80041608: sh          $zero, 0x104($t0)
    MEM_H(0X104, ctx->r8) = 0;
    // 0x8004160C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80041610: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80041614: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80041618: addiu       $t5, $sp, 0x44
    ctx->r13 = ADD32(ctx->r29, 0X44);
    // 0x8004161C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80041620: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    // 0x80041624: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041628: jal         0x80016DE8
    // 0x8004162C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    obj_dist_racer(rdram, ctx);
        goto after_11;
    // 0x8004162C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_11:
    // 0x80041630: sll         $a1, $v0, 16
    ctx->r5 = S32(ctx->r2 << 16);
    // 0x80041634: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80041638: sra         $t6, $a1, 16
    ctx->r14 = S32(SIGNED(ctx->r5) >> 16);
    // 0x8004163C: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041640: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80041644: sra         $t7, $v1, 16
    ctx->r15 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80041648: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8004164C: bne         $t7, $zero, L_80041664
    if (ctx->r15 != 0) {
        // 0x80041650: or          $v1, $t7, $zero
        ctx->r3 = ctx->r15 | 0;
            goto L_80041664;
    }
    // 0x80041650: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
    // 0x80041654: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80041658: sw          $zero, 0x100($t0)
    MEM_W(0X100, ctx->r8) = 0;
    // 0x8004165C: b           L_800416B4
    // 0x80041660: sb          $t8, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r24;
        goto L_800416B4;
    // 0x80041660: sb          $t8, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r24;
L_80041664:
    // 0x80041664: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80041668: bne         $at, $zero, L_80041690
    if (ctx->r1 != 0) {
        // 0x8004166C: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_80041690;
    }
    // 0x8004166C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80041670: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x80041674: jal         0x8006F94C
    // 0x80041678: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    rand_range(rdram, ctx);
        goto after_12;
    // 0x80041678: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x8004167C: sll         $v1, $v0, 16
    ctx->r3 = S32(ctx->r2 << 16);
    // 0x80041680: sra         $t3, $v1, 16
    ctx->r11 = S32(SIGNED(ctx->r3) >> 16);
    // 0x80041684: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041688: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8004168C: or          $v1, $t3, $zero
    ctx->r3 = ctx->r11 | 0;
L_80041690:
    // 0x80041690: addiu       $a1, $v1, -0x1
    ctx->r5 = ADD32(ctx->r3, -0X1);
    // 0x80041694: sll         $t4, $a1, 16
    ctx->r12 = S32(ctx->r5 << 16);
    // 0x80041698: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8004169C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x800416A0: addu        $t7, $sp, $t6
    ctx->r15 = ADD32(ctx->r29, ctx->r14);
    // 0x800416A4: lw          $t7, 0x44($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X44);
    // 0x800416A8: addiu       $t8, $zero, 0xF0
    ctx->r24 = ADD32(0, 0XF0);
    // 0x800416AC: sh          $t8, 0x104($t0)
    MEM_H(0X104, ctx->r8) = ctx->r24;
    // 0x800416B0: sw          $t7, 0x100($t0)
    MEM_W(0X100, ctx->r8) = ctx->r15;
L_800416B4:
    // 0x800416B4: lbu         $t9, 0xFD($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0XFD);
    // 0x800416B8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800416BC: bne         $t9, $at, L_80041818
    if (ctx->r25 != ctx->r1) {
        // 0x800416C0: nop
    
            goto L_80041818;
    }
    // 0x800416C0: nop

    // 0x800416C4: lw          $v0, 0x100($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X100);
    // 0x800416C8: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800416CC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800416D0: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800416D4: sub.s       $f0, $f8, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x800416D8: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800416DC: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800416E0: sub.s       $f2, $f18, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800416E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800416E8: lwc1        $f6, 0x623C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X623C);
    // 0x800416EC: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800416F0: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x800416F4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800416F8: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x800416FC: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80041700: c.lt.s      $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f6.fl < ctx->f18.fl;
    // 0x80041704: nop

    // 0x80041708: bc1f        L_80041718
    if (!c1cs) {
        // 0x8004170C: nop
    
            goto L_80041718;
    }
    // 0x8004170C: nop

    // 0x80041710: b           L_80041818
    // 0x80041714: sb          $t3, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r11;
        goto L_80041818;
    // 0x80041714: sb          $t3, 0xFD($t0)
    MEM_B(0XFD, ctx->r8) = ctx->r11;
L_80041718:
    // 0x80041718: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    // 0x8004171C: jal         0x8006F94C
    // 0x80041720: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    rand_range(rdram, ctx);
        goto after_13;
    // 0x80041720: swc1        $f16, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f16.u32l;
    after_13:
    // 0x80041724: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041728: lwc1        $f16, 0x7C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8004172C: slti        $at, $v0, 0x63
    ctx->r1 = SIGNED(ctx->r2) < 0X63 ? 1 : 0;
    // 0x80041730: bne         $at, $zero, L_8004174C
    if (ctx->r1 != 0) {
        // 0x80041734: lw          $v0, 0x9C($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X9C);
            goto L_8004174C;
    }
    // 0x80041734: lw          $v0, 0x9C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X9C);
    // 0x80041738: lh          $t4, 0x106($t0)
    ctx->r12 = MEM_H(ctx->r8, 0X106);
    // 0x8004173C: nop

    // 0x80041740: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x80041744: sh          $t5, 0x106($t0)
    MEM_H(0X106, ctx->r8) = ctx->r13;
    // 0x80041748: lw          $v0, 0x9C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X9C);
L_8004174C:
    // 0x8004174C: lh          $t7, 0x106($t0)
    ctx->r15 = MEM_H(ctx->r8, 0X106);
    // 0x80041750: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x80041754: multu       $v0, $t7
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80041758: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8004175C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80041760: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80041764: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80041768: mflo        $t8
    ctx->r24 = lo;
    // 0x8004176C: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80041770: sh          $t9, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r25;
    // 0x80041774: lw          $t3, 0x100($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X100);
    // 0x80041778: nop

    // 0x8004177C: lwc1        $f2, 0x10($t3)
    ctx->f2.u32l = MEM_W(ctx->r11, 0X10);
    // 0x80041780: nop

    // 0x80041784: add.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f10.fl;
    // 0x80041788: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x8004178C: nop

    // 0x80041790: bc1f        L_800417A0
    if (!c1cs) {
        // 0x80041794: nop
    
            goto L_800417A0;
    }
    // 0x80041794: nop

    // 0x80041798: b           L_800417C0
    // 0x8004179C: sb          $zero, 0xFE($t0)
    MEM_B(0XFE, ctx->r8) = 0;
        goto L_800417C0;
    // 0x8004179C: sb          $zero, 0xFE($t0)
    MEM_B(0XFE, ctx->r8) = 0;
L_800417A0:
    // 0x800417A0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800417A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800417A8: add.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f4.fl;
    // 0x800417AC: c.lt.s      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.fl < ctx->f6.fl;
    // 0x800417B0: nop

    // 0x800417B4: bc1f        L_800417C0
    if (!c1cs) {
        // 0x800417B8: nop
    
            goto L_800417C0;
    }
    // 0x800417B8: nop

    // 0x800417BC: sb          $t4, 0xFE($t0)
    MEM_B(0XFE, ctx->r8) = ctx->r12;
L_800417C0:
    // 0x800417C0: lbu         $t5, 0xFE($t0)
    ctx->r13 = MEM_BU(ctx->r8, 0XFE);
    // 0x800417C4: nop

    // 0x800417C8: beq         $t5, $zero, L_800417EC
    if (ctx->r13 == 0) {
        // 0x800417CC: nop
    
            goto L_800417EC;
    }
    // 0x800417CC: nop

    // 0x800417D0: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800417D4: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800417D8: cvt.s.w     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800417DC: mul.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f8.fl);
    // 0x800417E0: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x800417E4: b           L_80041804
    // 0x800417E8: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
        goto L_80041804;
    // 0x800417E8: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_800417EC:
    // 0x800417EC: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x800417F0: lwc1        $f10, 0x20($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800417F4: cvt.s.w     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    ctx->f18.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800417F8: mul.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f18.fl);
    // 0x800417FC: sub.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80041800: swc1        $f6, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f6.u32l;
L_80041804:
    // 0x80041804: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x80041808: lh          $t6, 0x106($t0)
    ctx->r14 = MEM_H(ctx->r8, 0X106);
    // 0x8004180C: nop

    // 0x80041810: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x80041814: sh          $t8, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r24;
L_80041818:
    // 0x80041818: lh          $t9, 0x18($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X18);
    // 0x8004181C: lw          $t3, 0x2C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X2C);
    // 0x80041820: nop

    // 0x80041824: addu        $t4, $t9, $t3
    ctx->r12 = ADD32(ctx->r25, ctx->r11);
    // 0x80041828: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x8004182C: sh          $t5, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r13;
    // 0x80041830: lbu         $v0, 0xFD($t0)
    ctx->r2 = MEM_BU(ctx->r8, 0XFD);
    // 0x80041834: nop

L_80041838:
    // 0x80041838: beq         $v0, $zero, L_8004189C
    if (ctx->r2 == 0) {
        // 0x8004183C: nop
    
            goto L_8004189C;
    }
    // 0x8004183C: nop

    // 0x80041840: lwc1        $f0, 0x108($t0)
    ctx->f0.u32l = MEM_W(ctx->r8, 0X108);
    // 0x80041844: lwc1        $f8, 0x78($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80041848: lw          $t7, 0x9C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X9C);
    // 0x8004184C: c.lt.s      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.fl < ctx->f8.fl;
    // 0x80041850: nop

    // 0x80041854: bc1f        L_8004189C
    if (!c1cs) {
        // 0x80041858: nop
    
            goto L_8004189C;
    }
    // 0x80041858: nop

    // 0x8004185C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80041860: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x80041864: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80041868: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004186C: nop

    // 0x80041870: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x80041874: add.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f6.fl;
    // 0x80041878: swc1        $f8, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f8.u32l;
    // 0x8004187C: lwc1        $f18, 0x108($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X108);
    // 0x80041880: lwc1        $f10, 0x78($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X78);
    // 0x80041884: nop

    // 0x80041888: c.lt.s      $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f10.fl < ctx->f18.fl;
    // 0x8004188C: nop

    // 0x80041890: bc1f        L_8004189C
    if (!c1cs) {
        // 0x80041894: nop
    
            goto L_8004189C;
    }
    // 0x80041894: nop

    // 0x80041898: swc1        $f10, 0x108($t0)
    MEM_W(0X108, ctx->r8) = ctx->f10.u32l;
L_8004189C:
    // 0x8004189C: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800418A0: lwc1        $f4, 0x108($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X108);
    // 0x800418A4: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800418A8: c.eq.s      $f14, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f14.fl == ctx->f4.fl;
    // 0x800418AC: nop

    // 0x800418B0: bc1t        L_800419A8
    if (c1cs) {
        // 0x800418B4: nop
    
            goto L_800419A8;
    }
    // 0x800418B4: nop

    // 0x800418B8: lbu         $t6, 0xFD($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0XFD);
    // 0x800418BC: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800418C0: beq         $t6, $at, L_800418D4
    if (ctx->r14 == ctx->r1) {
        // 0x800418C4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800418D4;
    }
    // 0x800418C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800418C8: lwc1        $f0, 0x6240($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6240);
    // 0x800418CC: b           L_800418E0
    // 0x800418D0: nop

        goto L_800418E0;
    // 0x800418D0: nop

L_800418D4:
    // 0x800418D4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800418D8: lwc1        $f0, 0x6244($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6244);
    // 0x800418DC: nop

L_800418E0:
    // 0x800418E0: beq         $t8, $zero, L_800418F8
    if (ctx->r24 == 0) {
        // 0x800418E4: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800418F8;
    }
    // 0x800418E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800418E8: lwc1        $f6, 0x6248($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6248);
    // 0x800418EC: nop

    // 0x800418F0: mul.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800418F4: nop

L_800418F8:
    // 0x800418F8: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800418FC: neg.s       $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = -ctx->f0.fl;
    // 0x80041900: c.lt.s      $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f2.fl < ctx->f12.fl;
    // 0x80041904: nop

    // 0x80041908: bc1f        L_8004191C
    if (!c1cs) {
        // 0x8004190C: nop
    
            goto L_8004191C;
    }
    // 0x8004190C: nop

    // 0x80041910: swc1        $f12, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f12.u32l;
    // 0x80041914: lwc1        $f2, 0x20($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80041918: nop

L_8004191C:
    // 0x8004191C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80041920: nop

    // 0x80041924: bc1f        L_80041930
    if (!c1cs) {
        // 0x80041928: nop
    
            goto L_80041930;
    }
    // 0x80041928: nop

    // 0x8004192C: swc1        $f0, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f0.u32l;
L_80041930:
    // 0x80041930: lwc1        $f8, 0x108($t0)
    ctx->f8.u32l = MEM_W(ctx->r8, 0X108);
    // 0x80041934: nop

    // 0x80041938: c.eq.s      $f14, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f14.fl == ctx->f8.fl;
    // 0x8004193C: nop

    // 0x80041940: bc1t        L_800419A8
    if (c1cs) {
        // 0x80041944: nop
    
            goto L_800419A8;
    }
    // 0x80041944: nop

    // 0x80041948: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004194C: jal         0x800707C4
    // 0x80041950: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    sins_f(rdram, ctx);
        goto after_14;
    // 0x80041950: sw          $t0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r8;
    after_14:
    // 0x80041954: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041958: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8004195C: lwc1        $f18, 0x108($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X108);
    // 0x80041960: nop

    // 0x80041964: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x80041968: mul.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8004196C: jal         0x800707F8
    // 0x80041970: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    coss_f(rdram, ctx);
        goto after_15;
    // 0x80041970: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    after_15:
    // 0x80041974: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x80041978: lw          $a1, 0x1C($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X1C);
    // 0x8004197C: lwc1        $f6, 0x108($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X108);
    // 0x80041980: lw          $a2, 0x20($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X20);
    // 0x80041984: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80041988: mul.s       $f18, $f0, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8004198C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80041990: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
    // 0x80041994: lw          $a3, 0x24($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X24);
    // 0x80041998: jal         0x80011570
    // 0x8004199C: nop

    move_object(rdram, ctx);
        goto after_16;
    // 0x8004199C: nop

    after_16:
    // 0x800419A0: lw          $t0, 0x3C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X3C);
    // 0x800419A4: nop

L_800419A8:
    // 0x800419A8: lbu         $t9, 0xFC($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0XFC);
    // 0x800419AC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800419B0: subu        $t4, $t3, $t9
    ctx->r12 = SUB32(ctx->r11, ctx->r25);
    // 0x800419B4: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800419B8: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800419BC: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800419C0: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800419C4: sll         $t6, $t7, 2
    ctx->r14 = S32(ctx->r15 << 2);
    // 0x800419C8: sb          $t4, 0xFC($t0)
    MEM_B(0XFC, ctx->r8) = ctx->r12;
    // 0x800419CC: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x800419D0: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800419D4: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x800419D8: addu        $a2, $t0, $t6
    ctx->r6 = ADD32(ctx->r8, ctx->r14);
    // 0x800419DC: bne         $t8, $zero, L_800419EC
    if (ctx->r24 != 0) {
        // 0x800419E0: addiu       $a2, $a2, 0x80
        ctx->r6 = ADD32(ctx->r6, 0X80);
            goto L_800419EC;
    }
    // 0x800419E0: addiu       $a2, $a2, 0x80
    ctx->r6 = ADD32(ctx->r6, 0X80);
    // 0x800419E4: b           L_800419F0
    // 0x800419E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
        goto L_800419F0;
    // 0x800419E8: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
L_800419EC:
    // 0x800419EC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
L_800419F0:
    // 0x800419F0: lh          $t3, 0x18($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X18);
    // 0x800419F4: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x800419F8: sllv        $a0, $t3, $a1
    ctx->r4 = S32(ctx->r11 << (ctx->r5 & 31));
    // 0x800419FC: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x80041A00: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80041A04: jal         0x80070830
    // 0x80041A08: sh          $a1, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r5;
    sins_s16(rdram, ctx);
        goto after_17;
    // 0x80041A08: sh          $a1, 0x76($sp)
    MEM_H(0X76, ctx->r29) = ctx->r5;
    after_17:
    // 0x80041A0C: lh          $a1, 0x76($sp)
    ctx->r5 = MEM_H(ctx->r29, 0X76);
    // 0x80041A10: lh          $t5, 0x18($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18);
    // 0x80041A14: sra         $v1, $v0, 10
    ctx->r3 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80041A18: sllv        $a0, $t5, $a1
    ctx->r4 = S32(ctx->r13 << (ctx->r5 & 31));
    // 0x80041A1C: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80041A20: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x80041A24: jal         0x8007082C
    // 0x80041A28: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    coss_s16(rdram, ctx);
        goto after_18;
    // 0x80041A28: sw          $v1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r3;
    after_18:
    // 0x80041A2C: lw          $v1, 0x6C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X6C);
    // 0x80041A30: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x80041A34: sra         $a0, $v0, 10
    ctx->r4 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80041A38: bgez        $v1, L_80041A44
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80041A3C: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_80041A44;
    }
    // 0x80041A3C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x80041A40: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_80041A44:
    // 0x80041A44: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x80041A48: negu        $v0, $v1
    ctx->r2 = SUB32(0, ctx->r3);
    // 0x80041A4C: bne         $t8, $zero, L_80041A60
    if (ctx->r24 != 0) {
        // 0x80041A50: nop
    
            goto L_80041A60;
    }
    // 0x80041A50: nop

    // 0x80041A54: bgez        $a0, L_80041A60
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80041A58: nop
    
            goto L_80041A60;
    }
    // 0x80041A58: nop

    // 0x80041A5C: negu        $a1, $a0
    ctx->r5 = SUB32(0, ctx->r4);
L_80041A60:
    // 0x80041A60: sh          $v0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r2;
    // 0x80041A64: sh          $a1, 0x2($a2)
    MEM_H(0X2, ctx->r6) = ctx->r5;
    // 0x80041A68: sh          $v0, 0xA($a2)
    MEM_H(0XA, ctx->r6) = ctx->r2;
    // 0x80041A6C: sh          $a1, 0xC($a2)
    MEM_H(0XC, ctx->r6) = ctx->r5;
    // 0x80041A70: sh          $v1, 0x28($a2)
    MEM_H(0X28, ctx->r6) = ctx->r3;
    // 0x80041A74: sh          $a1, 0x2A($a2)
    MEM_H(0X2A, ctx->r6) = ctx->r5;
    // 0x80041A78: sh          $v1, 0x32($a2)
    MEM_H(0X32, ctx->r6) = ctx->r3;
    // 0x80041A7C: sh          $a1, 0x34($a2)
    MEM_H(0X34, ctx->r6) = ctx->r5;
    // 0x80041A80: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80041A84: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80041A88: jr          $ra
    // 0x80041A8C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80041A8C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void func_80001358(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001358: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000135C: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x80001360: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x80001364: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001368: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8000136C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80001370: beq         $a3, $at, L_800013C0
    if (ctx->r7 == ctx->r1) {
        // 0x80001374: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_800013C0;
    }
    // 0x80001374: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80001378: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000137C: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80001380: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x80001384: jal         0x800C79A0
    // 0x80001388: sb          $a3, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r7;
    alCSPGetChlVol(rdram, ctx);
        goto after_0;
    // 0x80001388: sb          $a3, 0x23($sp)
    MEM_B(0X23, ctx->r29) = ctx->r7;
    after_0:
    // 0x8000138C: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x80001390: lbu         $a3, 0x23($sp)
    ctx->r7 = MEM_BU(ctx->r29, 0X23);
    // 0x80001394: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x80001398: andi        $t7, $v1, 0xFF
    ctx->r15 = ctx->r3 & 0XFF;
    // 0x8000139C: slti        $at, $t7, 0x80
    ctx->r1 = SIGNED(ctx->r15) < 0X80 ? 1 : 0;
    // 0x800013A0: bne         $at, $zero, L_800013AC
    if (ctx->r1 != 0) {
        // 0x800013A4: andi        $a2, $v1, 0xFF
        ctx->r6 = ctx->r3 & 0XFF;
            goto L_800013AC;
    }
    // 0x800013A4: andi        $a2, $v1, 0xFF
    ctx->r6 = ctx->r3 & 0XFF;
    // 0x800013A8: addiu       $a2, $zero, 0x7F
    ctx->r6 = ADD32(0, 0X7F);
L_800013AC:
    // 0x800013AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800013B0: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x800013B4: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    // 0x800013B8: jal         0x800C7940
    // 0x800013BC: sb          $a2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r6;
    alCSPSetChlVol(rdram, ctx);
        goto after_1;
    // 0x800013BC: sb          $a2, 0x1F($sp)
    MEM_B(0X1F, ctx->r29) = ctx->r6;
    after_1:
L_800013C0:
    // 0x800013C0: lbu         $t8, 0x27($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X27);
    // 0x800013C4: addiu       $at, $zero, 0x64
    ctx->r1 = ADD32(0, 0X64);
    // 0x800013C8: beq         $t8, $at, L_8000141C
    if (ctx->r24 == ctx->r1) {
        // 0x800013CC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8000141C;
    }
    // 0x800013CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800013D0: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x800013D4: jal         0x800C79A0
    // 0x800013D8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    alCSPGetChlVol(rdram, ctx);
        goto after_2;
    // 0x800013D8: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_2:
    // 0x800013DC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x800013E0: lbu         $a1, 0x27($sp)
    ctx->r5 = MEM_BU(ctx->r29, 0X27);
    // 0x800013E4: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800013E8: beq         $at, $zero, L_80001400
    if (ctx->r1 == 0) {
        // 0x800013EC: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_80001400;
    }
    // 0x800013EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800013F0: subu        $a2, $v0, $t9
    ctx->r6 = SUB32(ctx->r2, ctx->r25);
    // 0x800013F4: andi        $t0, $a2, 0xFF
    ctx->r8 = ctx->r6 & 0XFF;
    // 0x800013F8: b           L_80001404
    // 0x800013FC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
        goto L_80001404;
    // 0x800013FC: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
L_80001400:
    // 0x80001400: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80001404:
    // 0x80001404: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80001408: jal         0x800C7940
    // 0x8000140C: sb          $a2, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r6;
    alCSPSetChlVol(rdram, ctx);
        goto after_3;
    // 0x8000140C: sb          $a2, 0x1E($sp)
    MEM_B(0X1E, ctx->r29) = ctx->r6;
    after_3:
    // 0x80001410: lbu         $v0, 0x1E($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X1E);
    // 0x80001414: b           L_80001434
    // 0x80001418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80001434;
    // 0x80001418: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8000141C:
    // 0x8000141C: lbu         $t1, 0x1F($sp)
    ctx->r9 = MEM_BU(ctx->r29, 0X1F);
    // 0x80001420: addiu       $t2, $zero, 0x7F
    ctx->r10 = ADD32(0, 0X7F);
    // 0x80001424: subu        $v0, $t2, $t1
    ctx->r2 = SUB32(ctx->r10, ctx->r9);
    // 0x80001428: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8000142C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
    // 0x80001430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001434:
    // 0x80001434: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80001438: jr          $ra
    // 0x8000143C: nop

    return;
    // 0x8000143C: nop

;}
