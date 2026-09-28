#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void drop_bananas(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800576E0: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800576E4: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800576E8: sw          $s2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r18;
    // 0x800576EC: sw          $s1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r17;
    // 0x800576F0: sw          $s0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r16;
    // 0x800576F4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800576F8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800576FC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80057700: sw          $s6, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r22;
    // 0x80057704: sw          $s5, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r21;
    // 0x80057708: sw          $s4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r20;
    // 0x8005770C: sw          $s3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r19;
    // 0x80057710: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80057714: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80057718: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x8005771C: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80057720: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80057724: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80057728: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8005772C: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80057730: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80057734: jal         0x8009C30C
    // 0x80057738: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80057738: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    after_0:
    // 0x8005773C: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x80057740: bne         $t6, $zero, L_80057964
    if (ctx->r14 != 0) {
        // 0x80057744: lw          $ra, 0x5C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X5C);
            goto L_80057964;
    }
    // 0x80057744: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x80057748: lb          $v0, 0x185($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X185);
    // 0x8005774C: sb          $zero, 0x188($s0)
    MEM_B(0X188, ctx->r16) = 0;
    // 0x80057750: slt         $at, $v0, $s1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r17) ? 1 : 0;
    // 0x80057754: beq         $at, $zero, L_80057760
    if (ctx->r1 == 0) {
        // 0x80057758: nop
    
            goto L_80057760;
    }
    // 0x80057758: nop

    // 0x8005775C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_80057760:
    // 0x80057760: blez        $s1, L_80057960
    if (SIGNED(ctx->r17) <= 0) {
        // 0x80057764: slti        $at, $s1, 0x3
        ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
            goto L_80057960;
    }
    // 0x80057764: slti        $at, $s1, 0x3
    ctx->r1 = SIGNED(ctx->r17) < 0X3 ? 1 : 0;
    // 0x80057768: beq         $at, $zero, L_80057960
    if (ctx->r1 == 0) {
        // 0x8005776C: addiu       $t0, $zero, 0x8
        ctx->r8 = ADD32(0, 0X8);
            goto L_80057960;
    }
    // 0x8005776C: addiu       $t0, $zero, 0x8
    ctx->r8 = ADD32(0, 0X8);
    // 0x80057770: lh          $t7, 0x1A4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X1A4);
    // 0x80057774: addiu       $t1, $zero, 0xC
    ctx->r9 = ADD32(0, 0XC);
    // 0x80057778: sh          $t7, 0x78($sp)
    MEM_H(0X78, ctx->r29) = ctx->r15;
    // 0x8005777C: lh          $t8, 0x2($s2)
    ctx->r24 = MEM_H(ctx->r18, 0X2);
    // 0x80057780: addiu       $a0, $sp, 0x78
    ctx->r4 = ADD32(ctx->r29, 0X78);
    // 0x80057784: sh          $t8, 0x7A($sp)
    MEM_H(0X7A, ctx->r29) = ctx->r24;
    // 0x80057788: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x8005778C: sh          $zero, 0x70($sp)
    MEM_H(0X70, ctx->r29) = 0;
    // 0x80057790: sh          $t0, 0x72($sp)
    MEM_H(0X72, ctx->r29) = ctx->r8;
    // 0x80057794: sh          $t1, 0x74($sp)
    MEM_H(0X74, ctx->r29) = ctx->r9;
    // 0x80057798: addiu       $a1, $sp, 0x70
    ctx->r5 = ADD32(ctx->r29, 0X70);
    // 0x8005779C: jal         0x800701E4
    // 0x800577A0: sh          $t9, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r25;
    vec3s_rotate_rpy(rdram, ctx);
        goto after_1;
    // 0x800577A0: sh          $t9, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r25;
    after_1:
    // 0x800577A4: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800577A8: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x800577AC: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800577B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800577B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800577B8: lh          $t2, 0x70($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X70);
    // 0x800577BC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800577C0: lh          $t6, 0x72($sp)
    ctx->r14 = MEM_H(ctx->r29, 0X72);
    // 0x800577C4: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800577C8: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x800577CC: lh          $t0, 0x74($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X74);
    // 0x800577D0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800577D4: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800577D8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800577DC: sh          $t5, 0x8A($sp)
    MEM_H(0X8A, ctx->r29) = ctx->r13;
    // 0x800577E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800577E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800577E8: lwc1        $f8, 0x10($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X10);
    // 0x800577EC: addiu       $t4, $zero, 0x8
    ctx->r12 = ADD32(0, 0X8);
    // 0x800577F0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800577F4: addiu       $t5, $zero, 0x53
    ctx->r13 = ADD32(0, 0X53);
    // 0x800577F8: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800577FC: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x80057800: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80057804: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80057808: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8005780C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80057810: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80057814: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80057818: sh          $t9, 0x8C($sp)
    MEM_H(0X8C, ctx->r29) = ctx->r25;
    // 0x8005781C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x80057820: lwc1        $f16, 0x14($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80057824: mtc1        $at, $f28
    ctx->f28.u32l = ctx->r1;
    // 0x80057828: lui         $at, 0xBF00
    ctx->r1 = S32(0XBF00 << 16);
    // 0x8005782C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80057830: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x80057834: lui         $at, 0x4014
    ctx->r1 = S32(0X4014 << 16);
    // 0x80057838: mfc1        $t3, $f18
    ctx->r11 = (int32_t)ctx->f18.u32l;
    // 0x8005783C: mtc1        $at, $f23
    ctx->f_odd[(23 - 1) * 2] = ctx->r1;
    // 0x80057840: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80057844: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x80057848: addu        $t2, $t0, $t3
    ctx->r10 = ADD32(ctx->r8, ctx->r11);
    // 0x8005784C: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x80057850: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x80057854: sh          $t2, 0x8E($sp)
    MEM_H(0X8E, ctx->r29) = ctx->r10;
    // 0x80057858: sb          $t4, 0x89($sp)
    MEM_B(0X89, ctx->r29) = ctx->r12;
    // 0x8005785C: sb          $t5, 0x88($sp)
    MEM_B(0X88, ctx->r29) = ctx->r13;
    // 0x80057860: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x80057864: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x80057868: addiu       $s6, $zero, 0x2
    ctx->r22 = ADD32(0, 0X2);
    // 0x8005786C: addiu       $s5, $sp, 0x88
    ctx->r21 = ADD32(ctx->r29, 0X88);
    // 0x80057870: addiu       $s4, $zero, 0x40
    ctx->r20 = ADD32(0, 0X40);
L_80057874:
    // 0x80057874: jal         0x8006BD98
    // 0x80057878: nop

    level_type(rdram, ctx);
        goto after_2;
    // 0x80057878: nop

    after_2:
    // 0x8005787C: beq         $s4, $v0, L_8005794C
    if (ctx->r20 == ctx->r2) {
        // 0x80057880: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8005794C;
    }
    // 0x80057880: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80057884: jal         0x8000EA54
    // 0x80057888: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    spawn_object(rdram, ctx);
        goto after_3;
    // 0x80057888: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x8005788C: beq         $v0, $zero, L_8005794C
    if (ctx->r2 == 0) {
        // 0x80057890: nop
    
            goto L_8005794C;
    }
    // 0x80057890: nop

    // 0x80057894: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80057898: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8005789C: lb          $t7, 0x1D6($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D6);
    // 0x800578A0: nop

    // 0x800578A4: sb          $t7, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r15;
    // 0x800578A8: lwc1        $f4, 0x38($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800578AC: nop

    // 0x800578B0: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800578B4: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
    // 0x800578B8: lwc1        $f8, 0x3C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800578BC: nop

    // 0x800578C0: sub.s       $f10, $f24, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f24.fl - ctx->f8.fl;
    // 0x800578C4: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800578C8: add.d       $f18, $f16, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f22.d); 
    ctx->f18.d = ctx->f16.d + ctx->f22.d;
    // 0x800578CC: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800578D0: swc1        $f4, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f4.u32l;
    // 0x800578D4: lwc1        $f6, 0x40($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800578D8: nop

    // 0x800578DC: mul.s       $f8, $f6, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800578E0: bne         $s3, $s6, L_80057948
    if (ctx->r19 != ctx->r22) {
        // 0x800578E4: swc1        $f8, 0x24($v0)
        MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
            goto L_80057948;
    }
    // 0x800578E4: swc1        $f8, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f8.u32l;
    // 0x800578E8: bne         $s1, $s2, L_800578F4
    if (ctx->r17 != ctx->r18) {
        // 0x800578EC: mov.s       $f0, $f26
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    ctx->f0.fl = ctx->f26.fl;
            goto L_800578F4;
    }
    // 0x800578EC: mov.s       $f0, $f26
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 26);
    ctx->f0.fl = ctx->f26.fl;
    // 0x800578F0: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_800578F4:
    // 0x800578F4: lwc1        $f10, 0x50($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X50);
    // 0x800578F8: lwc1        $f16, 0x38($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X38);
    // 0x800578FC: lwc1        $f6, 0x1C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80057900: sub.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80057904: lwc1        $f10, 0x20($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X20);
    // 0x80057908: mul.s       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8005790C: sub.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f4.fl;
    // 0x80057910: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x80057914: lwc1        $f16, 0x54($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X54);
    // 0x80057918: nop

    // 0x8005791C: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80057920: sub.s       $f6, $f10, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80057924: lwc1        $f18, 0x24($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X24);
    // 0x80057928: swc1        $f6, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f6.u32l;
    // 0x8005792C: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80057930: lwc1        $f4, 0x58($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X58);
    // 0x80057934: nop

    // 0x80057938: sub.s       $f16, $f4, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x8005793C: mul.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80057940: sub.s       $f6, $f18, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x80057944: swc1        $f6, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f6.u32l;
L_80057948:
    // 0x80057948: sw          $s2, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r18;
L_8005794C:
    // 0x8005794C: lb          $t6, 0x185($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X185);
    // 0x80057950: addiu       $s1, $s1, -0x1
    ctx->r17 = ADD32(ctx->r17, -0X1);
    // 0x80057954: addiu       $t8, $t6, -0x1
    ctx->r24 = ADD32(ctx->r14, -0X1);
    // 0x80057958: bgtz        $s1, L_80057874
    if (SIGNED(ctx->r17) > 0) {
        // 0x8005795C: sb          $t8, 0x185($s0)
        MEM_B(0X185, ctx->r16) = ctx->r24;
            goto L_80057874;
    }
    // 0x8005795C: sb          $t8, 0x185($s0)
    MEM_B(0X185, ctx->r16) = ctx->r24;
L_80057960:
    // 0x80057960: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80057964:
    // 0x80057964: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80057968: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005796C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80057970: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80057974: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80057978: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8005797C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80057980: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80057984: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80057988: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8005798C: lw          $s0, 0x40($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X40);
    // 0x80057990: lw          $s1, 0x44($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X44);
    // 0x80057994: lw          $s2, 0x48($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X48);
    // 0x80057998: lw          $s3, 0x4C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X4C);
    // 0x8005799C: lw          $s4, 0x50($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X50);
    // 0x800579A0: lw          $s5, 0x54($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X54);
    // 0x800579A4: lw          $s6, 0x58($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X58);
    // 0x800579A8: jr          $ra
    // 0x800579AC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800579AC: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void find_furthest_telepoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002342C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80023430: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x80023434: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80023438: addiu       $s3, $s3, -0x51A4
    ctx->r19 = ADD32(ctx->r19, -0X51A4);
    // 0x8002343C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x80023440: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80023444: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x80023448: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002344C: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80023450: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80023454: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80023458: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8002345C: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x80023460: mov.s       $f22, $f12
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 12);
    ctx->f22.fl = ctx->f12.fl;
    // 0x80023464: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
    // 0x80023468: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8002346C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x80023470: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x80023474: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x80023478: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002347C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80023480: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80023484: blez        $t6, L_80023524
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80023488: or          $s6, $zero, $zero
        ctx->r22 = 0 | 0;
            goto L_80023524;
    }
    // 0x80023488: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
    // 0x8002348C: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80023490: addiu       $s4, $s4, -0x51A8
    ctx->r20 = ADD32(ctx->r20, -0X51A8);
    // 0x80023494: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80023498: addiu       $s5, $zero, 0x57
    ctx->r21 = ADD32(0, 0X57);
L_8002349C:
    // 0x8002349C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x800234A0: nop

    // 0x800234A4: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800234A8: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x800234AC: nop

    // 0x800234B0: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x800234B4: nop

    // 0x800234B8: andi        $t0, $t9, 0x8000
    ctx->r8 = ctx->r25 & 0X8000;
    // 0x800234BC: bne         $t0, $zero, L_80023510
    if (ctx->r8 != 0) {
        // 0x800234C0: nop
    
            goto L_80023510;
    }
    // 0x800234C0: nop

    // 0x800234C4: lh          $t1, 0x48($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X48);
    // 0x800234C8: nop

    // 0x800234CC: bne         $s5, $t1, L_80023510
    if (ctx->r21 != ctx->r9) {
        // 0x800234D0: nop
    
            goto L_80023510;
    }
    // 0x800234D0: nop

    // 0x800234D4: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800234D8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800234DC: sub.s       $f0, $f4, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x800234E0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800234E4: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800234E8: sub.s       $f2, $f6, $f24
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f24.fl;
    // 0x800234EC: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800234F0: jal         0x800C9AD0
    // 0x800234F4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800234F4: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x800234F8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x800234FC: nop

    // 0x80023500: bc1f        L_80023510
    if (!c1cs) {
        // 0x80023504: nop
    
            goto L_80023510;
    }
    // 0x80023504: nop

    // 0x80023508: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8002350C: or          $s6, $s0, $zero
    ctx->r22 = ctx->r16 | 0;
L_80023510:
    // 0x80023510: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x80023514: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80023518: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8002351C: bne         $at, $zero, L_8002349C
    if (ctx->r1 != 0) {
        // 0x80023520: addiu       $s2, $s2, 0x4
        ctx->r18 = ADD32(ctx->r18, 0X4);
            goto L_8002349C;
    }
    // 0x80023520: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
L_80023524:
    // 0x80023524: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80023528: or          $v0, $s6, $zero
    ctx->r2 = ctx->r22 | 0;
    // 0x8002352C: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x80023530: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80023534: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80023538: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002353C: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80023540: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80023544: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80023548: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002354C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x80023550: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x80023554: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x80023558: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002355C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x80023560: jr          $ra
    // 0x80023564: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80023564: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void sound_clear_delayed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001050: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80001054: jr          $ra
    // 0x80001058: sw          $zero, -0x39A8($at)
    MEM_W(-0X39A8, ctx->r1) = 0;
    return;
    // 0x80001058: sw          $zero, -0x39A8($at)
    MEM_W(-0X39A8, ctx->r1) = 0;
;}
RECOMP_FUNC void alAuxBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065024: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065028: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006502C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80065030: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065034: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80065038: lui         $a1, 0x8006
    ctx->r5 = S32(0X8006 << 16);
    // 0x8006503C: addiu       $a1, $a1, 0x5900
    ctx->r5 = ADD32(ctx->r5, 0X5900);
    // 0x80065040: addiu       $a2, $a2, 0x59D4
    ctx->r6 = ADD32(ctx->r6, 0X59D4);
    // 0x80065044: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065048: jal         0x800CA0B0
    // 0x8006504C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x8006504C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_0:
    // 0x80065050: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80065054: nop

    // 0x80065058: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x8006505C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80065060: nop

    // 0x80065064: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x80065068: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x8006506C: nop

    // 0x80065070: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x80065074: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065078: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006507C: jr          $ra
    // 0x80065080: nop

    return;
    // 0x80065080: nop

;}
RECOMP_FUNC void dialogue_clear(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5494: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C5498: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C549C: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C54A0: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C54A4: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C54A8: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C54AC: lw          $v1, 0x24($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X24);
    // 0x800C54B0: nop

    // 0x800C54B4: beq         $v1, $zero, L_800C54E0
    if (ctx->r3 == 0) {
        // 0x800C54B8: nop
    
            goto L_800C54E0;
    }
    // 0x800C54B8: nop

    // 0x800C54BC: beq         $v1, $zero, L_800C54DC
    if (ctx->r3 == 0) {
        // 0x800C54C0: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800C54DC;
    }
    // 0x800C54C0: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x800C54C4: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
L_800C54C8:
    // 0x800C54C8: sb          $v1, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r3;
    // 0x800C54CC: lw          $a0, 0x1C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X1C);
    // 0x800C54D0: nop

    // 0x800C54D4: bne         $a0, $zero, L_800C54C8
    if (ctx->r4 != 0) {
        // 0x800C54D8: nop
    
            goto L_800C54C8;
    }
    // 0x800C54D8: nop

L_800C54DC:
    // 0x800C54DC: sw          $zero, 0x24($v0)
    MEM_W(0X24, ctx->r2) = 0;
L_800C54E0:
    // 0x800C54E0: jr          $ra
    // 0x800C54E4: nop

    return;
    // 0x800C54E4: nop

;}
RECOMP_FUNC void bgdraw_set_func(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80078AAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80078AB0: jr          $ra
    // 0x80078AB4: sw          $a0, -0x1B30($at)
    MEM_W(-0X1B30, ctx->r1) = ctx->r4;
    return;
    // 0x80078AB4: sw          $a0, -0x1B30($at)
    MEM_W(-0X1B30, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void alSeqChOn(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063B44: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80063B48: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063B4C: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80063B50: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80063B54: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80063B58: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80063B5C: addiu       $t7, $zero, 0xB0
    ctx->r15 = ADD32(0, 0XB0);
    // 0x80063B60: addiu       $t8, $zero, 0x6C
    ctx->r24 = ADD32(0, 0X6C);
    // 0x80063B64: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x80063B68: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x80063B6C: sb          $t7, 0x20($sp)
    MEM_B(0X20, ctx->r29) = ctx->r15;
    // 0x80063B70: sb          $t8, 0x21($sp)
    MEM_B(0X21, ctx->r29) = ctx->r24;
    // 0x80063B74: sb          $a3, 0x22($sp)
    MEM_B(0X22, ctx->r29) = ctx->r7;
    // 0x80063B78: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x80063B7C: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x80063B80: jal         0x800C91AC
    // 0x80063B84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x80063B84: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x80063B88: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80063B8C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80063B90: jr          $ra
    // 0x80063B94: nop

    return;
    // 0x80063B94: nop

;}
RECOMP_FUNC void hud_weapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A7520: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800A7524: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7528: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800A752C: lw          $t1, 0x64($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X64);
    // 0x800A7530: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A7534: lb          $t6, 0x1D8($t1)
    ctx->r14 = MEM_B(ctx->r9, 0X1D8);
    // 0x800A7538: nop

    // 0x800A753C: bne         $t6, $zero, L_800A7A54
    if (ctx->r14 != 0) {
        // 0x800A7540: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A7A54;
    }
    // 0x800A7540: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7544: jal         0x80066098
    // 0x800A7548: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_0;
    // 0x800A7548: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_0:
    // 0x800A754C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7550: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7554: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A7558: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A755C: lb          $t7, 0x172($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X172);
    // 0x800A7560: lb          $v1, 0x174($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X174);
    // 0x800A7564: lb          $t9, 0x5D($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X5D);
    // 0x800A7568: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800A756C: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x800A7570: beq         $v1, $t9, L_800A75C0
    if (ctx->r3 == ctx->r25) {
        // 0x800A7574: addu        $a0, $t8, $v1
        ctx->r4 = ADD32(ctx->r24, ctx->r3);
            goto L_800A75C0;
    }
    // 0x800A7574: addu        $a0, $t8, $v1
    ctx->r4 = ADD32(ctx->r24, ctx->r3);
    // 0x800A7578: bne         $v1, $zero, L_800A758C
    if (ctx->r3 != 0) {
        // 0x800A757C: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800A758C;
    }
    // 0x800A757C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A7580: addiu       $t2, $zero, 0x78
    ctx->r10 = ADD32(0, 0X78);
    // 0x800A7584: b           L_800A75A8
    // 0x800A7588: sb          $t2, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r10;
        goto L_800A75A8;
    // 0x800A7588: sb          $t2, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r10;
L_800A758C:
    // 0x800A758C: lbu         $t3, 0x6D37($t3)
    ctx->r11 = MEM_BU(ctx->r11, 0X6D37);
    // 0x800A7590: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A7594: bne         $t3, $at, L_800A75A4
    if (ctx->r11 != ctx->r1) {
        // 0x800A7598: addiu       $t4, $zero, 0x78
        ctx->r12 = ADD32(0, 0X78);
            goto L_800A75A4;
    }
    // 0x800A7598: addiu       $t4, $zero, 0x78
    ctx->r12 = ADD32(0, 0X78);
    // 0x800A759C: b           L_800A75A8
    // 0x800A75A0: sb          $zero, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = 0;
        goto L_800A75A8;
    // 0x800A75A0: sb          $zero, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = 0;
L_800A75A4:
    // 0x800A75A4: sb          $t4, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r12;
L_800A75A8:
    // 0x800A75A8: lb          $t5, 0x174($t1)
    ctx->r13 = MEM_B(ctx->r9, 0X174);
    // 0x800A75AC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A75B0: nop

    // 0x800A75B4: sb          $t5, 0x5D($t6)
    MEM_B(0X5D, ctx->r14) = ctx->r13;
    // 0x800A75B8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A75BC: nop

L_800A75C0:
    // 0x800A75C0: lb          $t7, 0x173($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X173);
    // 0x800A75C4: nop

    // 0x800A75C8: blez        $t7, L_800A7940
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A75CC: nop
    
            goto L_800A7940;
    }
    // 0x800A75CC: nop

    // 0x800A75D0: lb          $v1, 0x5B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5B);
    // 0x800A75D4: nop

    // 0x800A75D8: slti        $at, $v1, 0x10
    ctx->r1 = SIGNED(ctx->r3) < 0X10 ? 1 : 0;
    // 0x800A75DC: beq         $at, $zero, L_800A7638
    if (ctx->r1 == 0) {
        // 0x800A75E0: nop
    
            goto L_800A7638;
    }
    // 0x800A75E0: nop

    // 0x800A75E4: lh          $t8, 0x170($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X170);
    // 0x800A75E8: sll         $t9, $v1, 12
    ctx->r25 = S32(ctx->r3 << 12);
    // 0x800A75EC: bne         $t8, $zero, L_800A7638
    if (ctx->r24 != 0) {
        // 0x800A75F0: nop
    
            goto L_800A7638;
    }
    // 0x800A75F0: nop

    // 0x800A75F4: sh          $t9, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r25;
    // 0x800A75F8: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A75FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A7600: lb          $t2, 0x5B($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7604: lwc1        $f9, -0x7880($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, -0X7880);
    // 0x800A7608: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x800A760C: lwc1        $f8, -0x787C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X787C);
    // 0x800A7610: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A7614: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800A7618: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A761C: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A7620: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7624: nop

    // 0x800A7628: add.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f10.d + ctx->f16.d;
    // 0x800A762C: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800A7630: b           L_800A7650
    // 0x800A7634: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
        goto L_800A7650;
    // 0x800A7634: swc1        $f4, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f4.u32l;
L_800A7638:
    // 0x800A7638: sh          $zero, 0x44($v0)
    MEM_H(0X44, ctx->r2) = 0;
    // 0x800A763C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A7640: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A7644: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A7648: nop

    // 0x800A764C: swc1        $f6, 0x48($t3)
    MEM_W(0X48, ctx->r11) = ctx->f6.u32l;
L_800A7650:
    // 0x800A7650: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A7654: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x800A7658: sh          $a0, 0x58($t4)
    MEM_H(0X58, ctx->r12) = ctx->r4;
    // 0x800A765C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7660: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800A7664: lb          $t5, 0x5B($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7668: nop

    // 0x800A766C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800A7670: sb          $t7, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r15;
    // 0x800A7674: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7678: nop

    // 0x800A767C: lb          $t8, 0x5B($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7680: nop

    // 0x800A7684: slti        $at, $t8, 0x11
    ctx->r1 = SIGNED(ctx->r24) < 0X11 ? 1 : 0;
    // 0x800A7688: bne         $at, $zero, L_800A778C
    if (ctx->r1 != 0) {
        // 0x800A768C: nop
    
            goto L_800A778C;
    }
    // 0x800A768C: nop

    // 0x800A7690: sb          $t9, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r25;
    // 0x800A7694: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7698: lw          $t3, 0x24($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X24);
    // 0x800A769C: lb          $t2, 0x5C($v0)
    ctx->r10 = MEM_B(ctx->r2, 0X5C);
    // 0x800A76A0: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x800A76A4: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800A76A8: sb          $t4, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r12;
    // 0x800A76AC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A76B0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A76B4: lb          $v1, 0x5C($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5C);
    // 0x800A76B8: nop

    // 0x800A76BC: slti        $at, $v1, 0x79
    ctx->r1 = SIGNED(ctx->r3) < 0X79 ? 1 : 0;
    // 0x800A76C0: bne         $at, $zero, L_800A76D8
    if (ctx->r1 != 0) {
        // 0x800A76C4: nop
    
            goto L_800A76D8;
    }
    // 0x800A76C4: nop

    // 0x800A76C8: sb          $t5, 0x5C($v0)
    MEM_B(0X5C, ctx->r2) = ctx->r13;
    // 0x800A76CC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A76D0: b           L_800A778C
    // 0x800A76D4: nop

        goto L_800A778C;
    // 0x800A76D4: nop

L_800A76D8:
    // 0x800A76D8: lw          $t6, 0x6D0C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D0C);
    // 0x800A76DC: nop

    // 0x800A76E0: bne         $t6, $zero, L_800A778C
    if (ctx->r14 != 0) {
        // 0x800A76E4: nop
    
            goto L_800A778C;
    }
    // 0x800A76E4: nop

    // 0x800A76E8: mtc1        $v1, $f8
    ctx->f8.u32l = ctx->r3;
    // 0x800A76EC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A76F0: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A76F4: lwc1        $f19, -0x7878($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X7878);
    // 0x800A76F8: lwc1        $f18, -0x7874($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7874);
    // 0x800A76FC: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x800A7700: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800A7704: lui         $at, 0x4010
    ctx->r1 = S32(0X4010 << 16);
    // 0x800A7708: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800A770C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800A7710: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800A7714: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x800A7718: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A771C: nop

    // 0x800A7720: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A7724: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A7728: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A772C: nop

    // 0x800A7730: cvt.w.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_D(ctx->f8.d);
    // 0x800A7734: mfc1        $a0, $f10
    ctx->r4 = (int32_t)ctx->f10.u32l;
    // 0x800A7738: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A773C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x800A7740: jal         0x800707C4
    // 0x800A7744: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    sins_f(rdram, ctx);
        goto after_1;
    // 0x800A7744: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_1:
    // 0x800A7748: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A774C: lwc1        $f17, -0x7870($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X7870);
    // 0x800A7750: lwc1        $f16, -0x786C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X786C);
    // 0x800A7754: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7758: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A775C: cvt.d.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f18.d = CVT_D_S(ctx->f0.fl);
    // 0x800A7760: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800A7764: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7768: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A776C: lwc1        $f6, 0x48($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A7770: nop

    // 0x800A7774: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800A7778: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x800A777C: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800A7780: swc1        $f16, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f16.u32l;
    // 0x800A7784: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7788: nop

L_800A778C:
    // 0x800A778C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A7790: lw          $t2, 0x6D0C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D0C);
    // 0x800A7794: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7798: blez        $t2, L_800A77C4
    if (SIGNED(ctx->r10) <= 0) {
        // 0x800A779C: lui         $at, 0x3FE8
        ctx->r1 = S32(0X3FE8 << 16);
            goto L_800A77C4;
    }
    // 0x800A779C: lui         $at, 0x3FE8
    ctx->r1 = S32(0X3FE8 << 16);
    // 0x800A77A0: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A77A4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A77A8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A77AC: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800A77B0: mul.d       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A77B4: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800A77B8: swc1        $f10, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f10.u32l;
    // 0x800A77BC: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A77C0: nop

L_800A77C4:
    // 0x800A77C4: lwc1        $f18, 0x48($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A77C8: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800A77CC: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A77D0: cvt.d.s     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f6.d = CVT_D_S(ctx->f18.fl);
    // 0x800A77D4: c.eq.d      $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f16.d == ctx->f6.d;
    // 0x800A77D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A77DC: bc1t        L_800A7800
    if (c1cs) {
        // 0x800A77E0: nop
    
            goto L_800A7800;
    }
    // 0x800A77E0: nop

    // 0x800A77E4: jal         0x8007BF1C
    // 0x800A77E8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    sprite_opaque(rdram, ctx);
        goto after_2;
    // 0x800A77E8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_2:
    // 0x800A77EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A77F0: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A77F4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A77F8: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A77FC: nop

L_800A7800:
    // 0x800A7800: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7804: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7808: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A780C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A7810: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A7814: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A7818: addiu       $a3, $v0, 0x40
    ctx->r7 = ADD32(ctx->r2, 0X40);
    // 0x800A781C: jal         0x800AA600
    // 0x800A7820: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    hud_element_render(rdram, ctx);
        goto after_3;
    // 0x800A7820: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    after_3:
    // 0x800A7824: jal         0x8007BF1C
    // 0x800A7828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_4;
    // 0x800A7828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x800A782C: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7830: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A7834: lb          $v1, 0x173($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X173);
    // 0x800A7838: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A783C: slti        $at, $v1, 0x4
    ctx->r1 = SIGNED(ctx->r3) < 0X4 ? 1 : 0;
    // 0x800A7840: bne         $at, $zero, L_800A785C
    if (ctx->r1 != 0) {
        // 0x800A7844: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_800A785C;
    }
    // 0x800A7844: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7848: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800A784C: addiu       $t3, $zero, -0x80
    ctx->r11 = ADD32(0, -0X80);
    // 0x800A7850: sb          $t3, 0x63A($t4)
    MEM_B(0X63A, ctx->r12) = ctx->r11;
    // 0x800A7854: lb          $v1, 0x173($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X173);
    // 0x800A7858: nop

L_800A785C:
    // 0x800A785C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A7860: beq         $at, $zero, L_800A7888
    if (ctx->r1 == 0) {
        // 0x800A7864: addiu       $a0, $a0, 0x6CFC
        ctx->r4 = ADD32(ctx->r4, 0X6CFC);
            goto L_800A7888;
    }
    // 0x800A7864: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A7868: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A786C: lw          $t6, 0x24($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X24);
    // 0x800A7870: lb          $t5, 0x63A($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X63A);
    // 0x800A7874: nop

    // 0x800A7878: subu        $t7, $t5, $t6
    ctx->r15 = SUB32(ctx->r13, ctx->r14);
    // 0x800A787C: sb          $t7, 0x63A($v0)
    MEM_B(0X63A, ctx->r2) = ctx->r15;
    // 0x800A7880: lb          $v1, 0x173($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X173);
    // 0x800A7884: nop

L_800A7888:
    // 0x800A7888: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A788C: beq         $at, $zero, L_800A78D0
    if (ctx->r1 == 0) {
        // 0x800A7890: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_800A78D0;
    }
    // 0x800A7890: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x800A7894: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x800A7898: nop

    // 0x800A789C: lb          $t9, 0x63A($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X63A);
    // 0x800A78A0: nop

    // 0x800A78A4: addiu       $t2, $t9, 0x80
    ctx->r10 = ADD32(ctx->r25, 0X80);
    // 0x800A78A8: bgez        $t2, L_800A78BC
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A78AC: andi        $t3, $t2, 0x1F
        ctx->r11 = ctx->r10 & 0X1F;
            goto L_800A78BC;
    }
    // 0x800A78AC: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x800A78B0: beq         $t3, $zero, L_800A78BC
    if (ctx->r11 == 0) {
        // 0x800A78B4: nop
    
            goto L_800A78BC;
    }
    // 0x800A78B4: nop

    // 0x800A78B8: addiu       $t3, $t3, -0x20
    ctx->r11 = ADD32(ctx->r11, -0X20);
L_800A78BC:
    // 0x800A78BC: slti        $at, $t3, 0x14
    ctx->r1 = SIGNED(ctx->r11) < 0X14 ? 1 : 0;
    // 0x800A78C0: beq         $at, $zero, L_800A7938
    if (ctx->r1 == 0) {
        // 0x800A78C4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800A7938;
    }
    // 0x800A78C4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A78C8: beq         $v1, $at, L_800A7938
    if (ctx->r3 == ctx->r1) {
        // 0x800A78CC: nop
    
            goto L_800A7938;
    }
    // 0x800A78CC: nop

L_800A78D0:
    // 0x800A78D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A78D4: addiu       $t6, $zero, -0x60
    ctx->r14 = ADD32(0, -0X60);
    // 0x800A78D8: addiu       $t4, $v0, 0x8
    ctx->r12 = ADD32(ctx->r2, 0X8);
    // 0x800A78DC: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x800A78E0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A78E4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800A78E8: lb          $t7, 0x173($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X173);
    // 0x800A78EC: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800A78F0: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x800A78F4: sh          $t8, 0x638($t9)
    MEM_H(0X638, ctx->r25) = ctx->r24;
    // 0x800A78F8: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A78FC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7900: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7904: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A7908: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A790C: jal         0x800AA600
    // 0x800A7910: addiu       $a3, $a3, 0x620
    ctx->r7 = ADD32(ctx->r7, 0X620);
    hud_element_render(rdram, ctx);
        goto after_5;
    // 0x800A7910: addiu       $a3, $a3, 0x620
    ctx->r7 = ADD32(ctx->r7, 0X620);
    after_5:
    // 0x800A7914: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7918: addiu       $a1, $a1, 0x6CFC
    ctx->r5 = ADD32(ctx->r5, 0X6CFC);
    // 0x800A791C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A7920: lui         $t3, 0xFA00
    ctx->r11 = S32(0XFA00 << 16);
    // 0x800A7924: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x800A7928: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800A792C: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800A7930: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x800A7934: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_800A7938:
    // 0x800A7938: b           L_800A7A24
    // 0x800A793C: nop

        goto L_800A7A24;
    // 0x800A793C: nop

L_800A7940:
    // 0x800A7940: lb          $v1, 0x5B($v0)
    ctx->r3 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7944: nop

    // 0x800A7948: blez        $v1, L_800A7A24
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800A794C: sll         $t5, $v1, 12
        ctx->r13 = S32(ctx->r3 << 12);
            goto L_800A7A24;
    }
    // 0x800A794C: sll         $t5, $v1, 12
    ctx->r13 = S32(ctx->r3 << 12);
    // 0x800A7950: sh          $t5, 0x44($v0)
    MEM_H(0X44, ctx->r2) = ctx->r13;
    // 0x800A7954: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A7958: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A795C: lb          $t6, 0x5B($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X5B);
    // 0x800A7960: lwc1        $f11, -0x7868($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X7868);
    // 0x800A7964: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800A7968: lwc1        $f10, -0x7864($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7864);
    // 0x800A796C: cvt.d.w     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.d = CVT_D_W(ctx->f8.u32l);
    // 0x800A7970: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800A7974: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A7978: mul.d       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f4.d, ctx->f10.d);
    // 0x800A797C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A7980: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7984: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7988: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A798C: add.d       $f6, $f18, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f18.d + ctx->f16.d;
    // 0x800A7990: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800A7994: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800A7998: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A799C: swc1        $f8, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f8.u32l;
    // 0x800A79A0: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A79A4: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800A79A8: lb          $t7, 0x5B($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X5B);
    // 0x800A79AC: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A79B0: subu        $t9, $t7, $t8
    ctx->r25 = SUB32(ctx->r15, ctx->r24);
    // 0x800A79B4: sb          $t9, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = ctx->r25;
    // 0x800A79B8: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x800A79BC: nop

    // 0x800A79C0: sh          $a0, 0x58($t2)
    MEM_H(0X58, ctx->r10) = ctx->r4;
    // 0x800A79C4: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800A79C8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A79CC: lb          $t3, 0x5B($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X5B);
    // 0x800A79D0: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A79D4: bgez        $t3, L_800A79EC
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A79D8: nop
    
            goto L_800A79EC;
    }
    // 0x800A79D8: nop

    // 0x800A79DC: sb          $zero, 0x5B($v0)
    MEM_B(0X5B, ctx->r2) = 0;
    // 0x800A79E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A79E4: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A79E8: nop

L_800A79EC:
    // 0x800A79EC: lw          $t4, 0x6D0C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D0C);
    // 0x800A79F0: nop

    // 0x800A79F4: beq         $t4, $zero, L_800A7A1C
    if (ctx->r12 == 0) {
        // 0x800A79F8: nop
    
            goto L_800A7A1C;
    }
    // 0x800A79F8: nop

    // 0x800A79FC: lwc1        $f4, 0x48($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X48);
    // 0x800A7A00: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A7A04: nop

    // 0x800A7A08: div.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800A7A0C: swc1        $f18, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->f18.u32l;
    // 0x800A7A10: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A7A14: lw          $v0, 0x6CDC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6CDC);
    // 0x800A7A18: nop

L_800A7A1C:
    // 0x800A7A1C: jal         0x800AA600
    // 0x800A7A20: addiu       $a3, $v0, 0x40
    ctx->r7 = ADD32(ctx->r2, 0X40);
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A7A20: addiu       $a3, $v0, 0x40
    ctx->r7 = ADD32(ctx->r2, 0X40);
    after_6:
L_800A7A24:
    // 0x800A7A24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7A28: addiu       $a1, $a1, 0x6CFC
    ctx->r5 = ADD32(ctx->r5, 0X6CFC);
    // 0x800A7A2C: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800A7A30: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A7A34: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x800A7A38: sw          $t5, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r13;
    // 0x800A7A3C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x800A7A40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A7A44: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800A7A48: jal         0x80066098
    // 0x800A7A4C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_7;
    // 0x800A7A4C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    after_7:
    // 0x800A7A50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A7A54:
    // 0x800A7A54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800A7A58: jr          $ra
    // 0x800A7A5C: nop

    return;
    // 0x800A7A5C: nop

;}
RECOMP_FUNC void audspat_calculate_spatial_pan(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800090C0: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800090C4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800090C8: swc1        $f12, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f12.u32l;
    // 0x800090CC: lwc1        $f16, 0x28($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800090D0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800090D4: mul.s       $f16, $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800090D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800090DC: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x800090E0: jal         0x800C9AD0
    // 0x800090E4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800090E4: add.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f18.fl;
    after_0:
    // 0x800090E8: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800090EC: lwc1        $f12, 0x28($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800090F0: jal         0x80070750
    // 0x800090F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x800090F4: swc1        $f0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f0.u32l;
    after_1:
    // 0x800090F8: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x800090FC: ori         $t6, $zero, 0xFFFF
    ctx->r14 = 0 | 0XFFFF;
    // 0x80009100: subu        $v1, $t6, $v0
    ctx->r3 = SUB32(ctx->r14, ctx->r2);
    // 0x80009104: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009108: slt         $at, $v1, $a2
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8000910C: beq         $at, $zero, L_800091CC
    if (ctx->r1 == 0) {
        // 0x80009110: or          $a1, $v1, $zero
        ctx->r5 = ctx->r3 | 0;
            goto L_800091CC;
    }
    // 0x80009110: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x80009114: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009118: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000911C: subu        $a0, $a2, $a1
    ctx->r4 = SUB32(ctx->r6, ctx->r5);
    // 0x80009120: c.le.s      $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f2.fl <= ctx->f10.fl;
    // 0x80009124: sll         $t1, $a0, 16
    ctx->r9 = S32(ctx->r4 << 16);
    // 0x80009128: bc1f        L_800091A8
    if (!c1cs) {
        // 0x8000912C: nop
    
            goto L_800091A8;
    }
    // 0x8000912C: nop

    // 0x80009130: subu        $a0, $a2, $v1
    ctx->r4 = SUB32(ctx->r6, ctx->r3);
    // 0x80009134: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80009138: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000913C: jal         0x80070830
    // 0x80009140: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    sins_s16(rdram, ctx);
        goto after_2;
    // 0x80009140: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_2:
    // 0x80009144: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009148: bgez        $v0, L_80009158
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000914C: sra         $t9, $v0, 10
        ctx->r25 = S32(SIGNED(ctx->r2) >> 10);
            goto L_80009158;
    }
    // 0x8000914C: sra         $t9, $v0, 10
    ctx->r25 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80009150: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x80009154: sra         $t9, $at, 10
    ctx->r25 = S32(SIGNED(ctx->r1) >> 10);
L_80009158:
    // 0x80009158: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000915C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80009160: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x80009164: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x80009168: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8000916C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80009170: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80009174: mul.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80009178: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x8000917C: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x80009180: nop

    // 0x80009184: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x80009188: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000918C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80009190: nop

    // 0x80009194: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80009198: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x8000919C: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800091A0: b           L_8000927C
    // 0x800091A4: nop

        goto L_8000927C;
    // 0x800091A4: nop

L_800091A8:
    // 0x800091A8: jal         0x80070890
    // 0x800091AC: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    static_3_80070890(rdram, ctx);
        goto after_3;
    // 0x800091AC: sra         $a0, $t1, 16
    ctx->r4 = S32(SIGNED(ctx->r9) >> 16);
    after_3:
    // 0x800091B0: bgez        $v0, L_800091C0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800091B4: sra         $t3, $v0, 10
        ctx->r11 = S32(SIGNED(ctx->r2) >> 10);
            goto L_800091C0;
    }
    // 0x800091B4: sra         $t3, $v0, 10
    ctx->r11 = S32(SIGNED(ctx->r2) >> 10);
    // 0x800091B8: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x800091BC: sra         $t3, $at, 10
    ctx->r11 = S32(SIGNED(ctx->r1) >> 10);
L_800091C0:
    // 0x800091C0: addiu       $t4, $zero, 0x40
    ctx->r12 = ADD32(0, 0X40);
    // 0x800091C4: b           L_8000927C
    // 0x800091C8: subu        $v1, $t4, $t3
    ctx->r3 = SUB32(ctx->r12, ctx->r11);
        goto L_8000927C;
    // 0x800091C8: subu        $v1, $t4, $t3
    ctx->r3 = SUB32(ctx->r12, ctx->r11);
L_800091CC:
    // 0x800091CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800091D0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800091D4: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800091D8: c.le.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl <= ctx->f18.fl;
    // 0x800091DC: sll         $t9, $a0, 16
    ctx->r25 = S32(ctx->r4 << 16);
    // 0x800091E0: bc1f        L_80009260
    if (!c1cs) {
        // 0x800091E4: nop
    
            goto L_80009260;
    }
    // 0x800091E4: nop

    // 0x800091E8: subu        $a0, $a1, $a2
    ctx->r4 = SUB32(ctx->r5, ctx->r6);
    // 0x800091EC: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800091F0: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800091F4: jal         0x80070830
    // 0x800091F8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    sins_s16(rdram, ctx);
        goto after_4;
    // 0x800091F8: swc1        $f2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f2.u32l;
    after_4:
    // 0x800091FC: lwc1        $f2, 0x1C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009200: bgez        $v0, L_80009210
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80009204: sra         $t7, $v0, 10
        ctx->r15 = S32(SIGNED(ctx->r2) >> 10);
            goto L_80009210;
    }
    // 0x80009204: sra         $t7, $v0, 10
    ctx->r15 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80009208: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x8000920C: sra         $t7, $at, 10
    ctx->r15 = S32(SIGNED(ctx->r1) >> 10);
L_80009210:
    // 0x80009210: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009214: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80009218: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x8000921C: mul.s       $f16, $f2, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f8.fl);
    // 0x80009220: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80009224: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80009228: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000922C: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80009230: add.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f18.fl;
    // 0x80009234: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80009238: nop

    // 0x8000923C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80009240: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80009244: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80009248: nop

    // 0x8000924C: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80009250: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x80009254: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80009258: b           L_8000927C
    // 0x8000925C: nop

        goto L_8000927C;
    // 0x8000925C: nop

L_80009260:
    // 0x80009260: jal         0x80070890
    // 0x80009264: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    static_3_80070890(rdram, ctx);
        goto after_5;
    // 0x80009264: sra         $a0, $t9, 16
    ctx->r4 = S32(SIGNED(ctx->r25) >> 16);
    after_5:
    // 0x80009268: bgez        $v0, L_80009278
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8000926C: sra         $v1, $v0, 10
        ctx->r3 = S32(SIGNED(ctx->r2) >> 10);
            goto L_80009278;
    }
    // 0x8000926C: sra         $v1, $v0, 10
    ctx->r3 = S32(SIGNED(ctx->r2) >> 10);
    // 0x80009270: addiu       $at, $v0, 0x3FF
    ctx->r1 = ADD32(ctx->r2, 0X3FF);
    // 0x80009274: sra         $v1, $at, 10
    ctx->r3 = S32(SIGNED(ctx->r1) >> 10);
L_80009278:
    // 0x80009278: addiu       $v1, $v1, 0x40
    ctx->r3 = ADD32(ctx->r3, 0X40);
L_8000927C:
    // 0x8000927C: jal         0x8009C30C
    // 0x80009280: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    get_filtered_cheats(rdram, ctx);
        goto after_6;
    // 0x80009280: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    after_6:
    // 0x80009284: lw          $v1, 0x20($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X20);
    // 0x80009288: andi        $t1, $v0, 0x4
    ctx->r9 = ctx->r2 & 0X4;
    // 0x8000928C: beq         $t1, $zero, L_80009298
    if (ctx->r9 == 0) {
        // 0x80009290: addiu       $t2, $zero, 0x80
        ctx->r10 = ADD32(0, 0X80);
            goto L_80009298;
    }
    // 0x80009290: addiu       $t2, $zero, 0x80
    ctx->r10 = ADD32(0, 0X80);
    // 0x80009294: subu        $v1, $t2, $v1
    ctx->r3 = SUB32(ctx->r10, ctx->r3);
L_80009298:
    // 0x80009298: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000929C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800092A0: jr          $ra
    // 0x800092A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800092A4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void get_modelmatrix_vector(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800699E4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800699E8: addiu       $v0, $v0, 0xD20
    ctx->r2 = ADD32(ctx->r2, 0XD20);
    // 0x800699EC: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800699F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800699F4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800699F8: addu        $at, $at, $t7
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x800699FC: lwc1        $f4, 0xD28($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0XD28);
    // 0x80069A00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069A04: swc1        $f4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f4.u32l;
    // 0x80069A08: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80069A0C: nop

    // 0x80069A10: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80069A14: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x80069A18: lwc1        $f6, 0xD40($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0XD40);
    // 0x80069A1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80069A20: swc1        $f6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f6.u32l;
    // 0x80069A24: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80069A28: nop

    // 0x80069A2C: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x80069A30: addu        $at, $at, $t1
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x80069A34: lwc1        $f8, 0xD58($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0XD58);
    // 0x80069A38: jr          $ra
    // 0x80069A3C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
    return;
    // 0x80069A3C: swc1        $f8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f8.u32l;
;}
RECOMP_FUNC void mtx_to_mtxs_2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006FA40: ori         $t2, $zero, 0x10
    ctx->r10 = 0 | 0X10;
    // 0x8006FA44: xor         $t3, $t3, $t3
    ctx->r11 = ctx->r11 ^ ctx->r11;
L_8006FA48:
    // 0x8006FA48: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x8006FA4C: lhu         $t1, 0x20($a0)
    ctx->r9 = MEM_HU(ctx->r4, 0X20);
    // 0x8006FA50: addi        $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x8006FA54: sll         $t0, $t0, 16
    ctx->r8 = S32(ctx->r8 << 16);
    // 0x8006FA58: or          $t0, $t0, $t1
    ctx->r8 = ctx->r8 | ctx->r9;
    // 0x8006FA5C: sw          $t0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r8;
    // 0x8006FA60: addi        $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8006FA64: addiu       $t3, $t3, 0x1
    ctx->r11 = ADD32(ctx->r11, 0X1);
    // 0x8006FA68: bnel        $t3, $t2, L_8006FA48
    if (ctx->r11 != ctx->r10) {
        // 0x8006FA6C: nop
    
            goto L_8006FA48;
    }
    goto skip_0;
    // 0x8006FA6C: nop

    skip_0:
    // 0x8006FA70: jr          $ra
    // 0x8006FA74: nop

    return;
    // 0x8006FA74: nop

;}
RECOMP_FUNC void obj_loop_bonus(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B174: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x8003B178: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8003B17C: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x8003B180: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x8003B184: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x8003B188: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x8003B18C: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x8003B190: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x8003B194: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x8003B198: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8003B19C: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x8003B1A0: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8003B1A4: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8003B1A8: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003B1AC: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8003B1B0: sw          $a1, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r5;
    // 0x8003B1B4: lw          $s4, 0x64($a0)
    ctx->r20 = MEM_W(ctx->r4, 0X64);
    // 0x8003B1B8: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003B1BC: lw          $v0, 0x10($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X10);
    // 0x8003B1C0: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003B1C4: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x8003B1C8: slt         $at, $t7, $v0
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8003B1CC: beq         $at, $zero, L_8003B328
    if (ctx->r1 == 0) {
        // 0x8003B1D0: addiu       $a0, $sp, 0x84
        ctx->r4 = ADD32(ctx->r29, 0X84);
            goto L_8003B328;
    }
    // 0x8003B1D0: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x8003B1D4: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8003B1D8: jal         0x8001BA74
    // 0x8003B1DC: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x8003B1DC: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_0:
    // 0x8003B1E0: lw          $t8, 0x84($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X84);
    // 0x8003B1E4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8003B1E8: blez        $t8, L_8003B328
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003B1EC: lui         $at, 0x3FE0
        ctx->r1 = S32(0X3FE0 << 16);
            goto L_8003B328;
    }
    // 0x8003B1EC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003B1F0: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8003B1F4: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8003B1F8: cvt.d.s     $f6, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f6.d = CVT_D_S(ctx->f22.fl);
    // 0x8003B1FC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003B200: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x8003B204: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
    // 0x8003B208: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x8003B20C: cvt.s.d     $f20, $f10
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f20.fl = CVT_S_D(ctx->f10.d);
L_8003B210:
    // 0x8003B210: lw          $s0, 0x0($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X0);
    // 0x8003B214: lwc1        $f18, 0x10($s5)
    ctx->f18.u32l = MEM_W(ctx->r21, 0X10);
    // 0x8003B218: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003B21C: lw          $s1, 0x64($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X64);
    // 0x8003B220: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003B224: c.lt.s      $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f14.fl < ctx->f20.fl;
    // 0x8003B228: nop

    // 0x8003B22C: bc1f        L_8003B318
    if (!c1cs) {
        // 0x8003B230: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B318;
    }
    // 0x8003B230: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B234: neg.s       $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = -ctx->f20.fl;
    // 0x8003B238: c.lt.s      $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f4.fl < ctx->f14.fl;
    // 0x8003B23C: nop

    // 0x8003B240: bc1f        L_8003B318
    if (!c1cs) {
        // 0x8003B244: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B318;
    }
    // 0x8003B244: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B248: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B24C: lwc1        $f8, 0xC($s5)
    ctx->f8.u32l = MEM_W(ctx->r21, 0XC);
    // 0x8003B250: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B254: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003B258: lwc1        $f16, 0x14($s5)
    ctx->f16.u32l = MEM_W(ctx->r21, 0X14);
    // 0x8003B25C: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003B260: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003B264: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003B268: nop

    // 0x8003B26C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003B270: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003B274: jal         0x800C9AD0
    // 0x8003B278: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003B278: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    after_1:
    // 0x8003B27C: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8003B280: nop

    // 0x8003B284: bc1f        L_8003B318
    if (!c1cs) {
        // 0x8003B288: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B318;
    }
    // 0x8003B288: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B28C: lwc1        $f10, 0x0($s4)
    ctx->f10.u32l = MEM_W(ctx->r20, 0X0);
    // 0x8003B290: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003B294: lwc1        $f4, 0x8($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X8);
    // 0x8003B298: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x8003B29C: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003B2A0: lwc1        $f16, 0xC($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8003B2A4: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8003B2A8: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8003B2AC: add.s       $f0, $f10, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f16.fl;
    // 0x8003B2B0: c.lt.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl < ctx->f24.fl;
    // 0x8003B2B4: nop

    // 0x8003B2B8: bc1f        L_8003B318
    if (!c1cs) {
        // 0x8003B2BC: lw          $t2, 0x84($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X84);
            goto L_8003B318;
    }
    // 0x8003B2BC: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
    // 0x8003B2C0: lb          $t9, 0x185($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X185);
    // 0x8003B2C4: addiu       $a0, $zero, 0x22
    ctx->r4 = ADD32(0, 0X22);
    // 0x8003B2C8: slti        $at, $t9, 0xA
    ctx->r1 = SIGNED(ctx->r25) < 0XA ? 1 : 0;
    // 0x8003B2CC: beq         $at, $zero, L_8003B314
    if (ctx->r1 == 0) {
        // 0x8003B2D0: addiu       $t0, $zero, 0x4
        ctx->r8 = ADD32(0, 0X4);
            goto L_8003B314;
    }
    // 0x8003B2D0: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x8003B2D4: sb          $s6, 0x185($s1)
    MEM_B(0X185, ctx->r17) = ctx->r22;
    // 0x8003B2D8: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B2DC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003B2E0: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003B2E4: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8003B2E8: jal         0x80009558
    // 0x8003B2EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_2;
    // 0x8003B2EC: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    after_2:
    // 0x8003B2F0: lb          $a0, 0x3($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X3);
    // 0x8003B2F4: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x8003B2F8: addiu       $a0, $a0, 0x7B
    ctx->r4 = ADD32(ctx->r4, 0X7B);
    // 0x8003B2FC: andi        $t1, $a0, 0xFFFF
    ctx->r9 = ctx->r4 & 0XFFFF;
    // 0x8003B300: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x8003B304: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x8003B308: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    { extern unsigned dkr_legacy_character_race_sound(uint8_t*, recomp_context*, uint32_t, unsigned); ctx->r9 = dkr_legacy_character_race_sound(rdram, ctx, (uint32_t)ctx->r17, (unsigned)ctx->r9); }
    // 0x8003B30C: jal         0x80001EA8
    // 0x8003B310: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    sound_play_spatial(rdram, ctx);
        goto after_3;
    // 0x8003B310: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    after_3:
L_8003B314:
    // 0x8003B314: lw          $t2, 0x84($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X84);
L_8003B318:
    // 0x8003B318: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8003B31C: slt         $at, $s2, $t2
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8003B320: bne         $at, $zero, L_8003B210
    if (ctx->r1 != 0) {
        // 0x8003B324: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_8003B210;
    }
    // 0x8003B324: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
L_8003B328:
    // 0x8003B328: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8003B32C: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8003B330: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003B334: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8003B338: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8003B33C: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8003B340: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8003B344: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8003B348: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8003B34C: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8003B350: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8003B354: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8003B358: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8003B35C: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8003B360: jr          $ra
    // 0x8003B364: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x8003B364: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void obj_loop_fireball_octoweapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033F60: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80033F64: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x80033F68: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80033F6C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80033F70: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x80033F74: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80033F78: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80033F7C: sw          $a1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r5;
    // 0x80033F80: lw          $v1, 0x78($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X78);
    // 0x80033F84: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80033F88: bne         $t7, $zero, L_80033FAC
    if (ctx->r15 != 0) {
        // 0x80033F8C: swc1        $f0, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
            goto L_80033FAC;
    }
    // 0x80033F8C: swc1        $f0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f0.u32l;
    // 0x80033F90: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033F94: lwc1        $f9, 0x5FE0($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5FE0);
    // 0x80033F98: lwc1        $f8, 0x5FE4($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5FE4);
    // 0x80033F9C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80033FA0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x80033FA4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x80033FA8: swc1        $f4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f4.u32l;
L_80033FAC:
    // 0x80033FAC: lh          $t8, 0x48($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X48);
    // 0x80033FB0: addiu       $at, $zero, 0x74
    ctx->r1 = ADD32(0, 0X74);
    // 0x80033FB4: bne         $t8, $at, L_8003400C
    if (ctx->r24 != ctx->r1) {
        // 0x80033FB8: nop
    
            goto L_8003400C;
    }
    // 0x80033FB8: nop

    // 0x80033FBC: lw          $t9, 0x7C($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X7C);
    // 0x80033FC0: nop

    // 0x80033FC4: bgez        $t9, L_8003400C
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80033FC8: nop
    
            goto L_8003400C;
    }
    // 0x80033FC8: nop

    // 0x80033FCC: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80033FD0: nop

    // 0x80033FD4: swc1        $f0, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f0.u32l;
    // 0x80033FD8: swc1        $f0, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f0.u32l;
    // 0x80033FDC: swc1        $f0, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f0.u32l;
    // 0x80033FE0: jal         0x80011560
    // 0x80033FE4: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    ignore_bounds_check(rdram, ctx);
        goto after_0;
    // 0x80033FE4: sw          $v1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r3;
    after_0:
    // 0x80033FE8: lw          $v1, 0x84($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X84);
    // 0x80033FEC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033FF0: lw          $a1, 0xC($v1)
    ctx->r5 = MEM_W(ctx->r3, 0XC);
    // 0x80033FF4: lw          $a2, 0x10($v1)
    ctx->r6 = MEM_W(ctx->r3, 0X10);
    // 0x80033FF8: lw          $a3, 0x14($v1)
    ctx->r7 = MEM_W(ctx->r3, 0X14);
    // 0x80033FFC: jal         0x80011570
    // 0x80034000: nop

    move_object(rdram, ctx);
        goto after_1;
    // 0x80034000: nop

    after_1:
    // 0x80034004: b           L_800342B8
    // 0x80034008: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
        goto L_800342B8;
    // 0x80034008: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
L_8003400C:
    // 0x8003400C: lwc1        $f6, 0xC($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80034010: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034014: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034018: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003401C: lwc1        $f19, 0x5FE8($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, 0X5FE8);
    // 0x80034020: lwc1        $f18, 0x5FEC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X5FEC);
    // 0x80034024: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80034028: mul.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x8003402C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80034030: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80034034: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80034038: lwc1        $f4, 0x7C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8003403C: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80034040: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80034044: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80034048: c.lt.d      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.d < ctx->f0.d;
    // 0x8003404C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80034050: bc1f        L_80034064
    if (!c1cs) {
        // 0x80034054: cvt.d.s     $f16, $f4
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
            goto L_80034064;
    }
    // 0x80034054: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x80034058: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003405C: nop

    // 0x80034060: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80034064:
    // 0x80034064: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x80034068: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x8003406C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80034070: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80034074: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80034078: bc1f        L_80034088
    if (!c1cs) {
        // 0x8003407C: nop
    
            goto L_80034088;
    }
    // 0x8003407C: nop

    // 0x80034080: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034084: nop

L_80034088:
    // 0x80034088: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003408C: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x80034090: sub.s       $f6, $f2, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f14.fl;
    // 0x80034094: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80034098: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x8003409C: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800340A0: cvt.d.s     $f8, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f8.d = CVT_D_S(ctx->f14.fl);
    // 0x800340A4: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x800340A8: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800340AC: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x800340B0: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800340B4: cvt.s.d     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f4.fl = CVT_S_D(ctx->f10.d);
    // 0x800340B8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800340BC: swc1        $f4, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f4.u32l;
    // 0x800340C0: lwc1        $f8, 0x10($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800340C4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800340C8: sub.s       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f6.fl;
    // 0x800340CC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800340D0: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x800340D4: mul.d       $f8, $f4, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f18.d);
    // 0x800340D8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800340DC: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x800340E0: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x800340E4: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x800340E8: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800340EC: bc1f        L_80034100
    if (!c1cs) {
        // 0x800340F0: nop
    
            goto L_80034100;
    }
    // 0x800340F0: nop

    // 0x800340F4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800340F8: nop

    // 0x800340FC: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_80034100:
    // 0x80034100: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x80034104: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80034108: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x8003410C: c.lt.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d < ctx->f10.d;
    // 0x80034110: nop

    // 0x80034114: bc1f        L_80034124
    if (!c1cs) {
        // 0x80034118: nop
    
            goto L_80034124;
    }
    // 0x80034118: nop

    // 0x8003411C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034120: nop

L_80034124:
    // 0x80034124: lwc1        $f12, 0x20($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X20);
    // 0x80034128: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8003412C: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80034130: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80034134: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x80034138: mul.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f6.d);
    // 0x8003413C: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x80034140: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80034144: mul.d       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f16.d);
    // 0x80034148: add.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f8.d + ctx->f4.d;
    // 0x8003414C: lwc1        $f4, 0x14($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80034150: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80034154: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80034158: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x8003415C: lwc1        $f8, 0x14($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80034160: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80034164: sub.s       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80034168: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8003416C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80034170: mul.d       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x80034174: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80034178: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8003417C: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
    // 0x80034180: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80034184: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80034188: bc1f        L_8003419C
    if (!c1cs) {
        // 0x8003418C: nop
    
            goto L_8003419C;
    }
    // 0x8003418C: nop

    // 0x80034190: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80034194: nop

    // 0x80034198: cvt.d.s     $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f0.d = CVT_D_S(ctx->f2.fl);
L_8003419C:
    // 0x8003419C: lui         $at, 0xC024
    ctx->r1 = S32(0XC024 << 16);
    // 0x800341A0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800341A4: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x800341A8: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x800341AC: nop

    // 0x800341B0: bc1f        L_800341C0
    if (!c1cs) {
        // 0x800341B4: nop
    
            goto L_800341C0;
    }
    // 0x800341B4: nop

    // 0x800341B8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800341BC: nop

L_800341C0:
    // 0x800341C0: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800341C4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800341C8: sub.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800341CC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800341D0: cvt.d.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f8.d = CVT_D_S(ctx->f10.fl);
    // 0x800341D4: mul.d       $f6, $f8, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x800341D8: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800341DC: lwc1        $f14, 0x1C($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800341E0: mul.d       $f10, $f6, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f16.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f16.d);
    // 0x800341E4: add.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d + ctx->f10.d;
    // 0x800341E8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800341EC: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800341F0: swc1        $f6, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f6.u32l;
    // 0x800341F4: lwc1        $f0, 0x24($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800341F8: nop

    // 0x800341FC: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80034200: jal         0x800C9AD0
    // 0x80034204: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80034204: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_2:
    // 0x80034208: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8003420C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80034210: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80034214: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80034218: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x8003421C: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80034220: bc1f        L_80034254
    if (!c1cs) {
        // 0x80034224: nop
    
            goto L_80034254;
    }
    // 0x80034224: nop

    // 0x80034228: lwc1        $f12, 0x1C($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x8003422C: lwc1        $f14, 0x24($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80034230: jal         0x80070750
    // 0x80034234: nop

    arctan2_f(rdram, ctx);
        goto after_3;
    // 0x80034234: nop

    after_3:
    // 0x80034238: lwc1        $f2, 0x7C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x8003423C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80034240: lw          $t1, 0x8C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X8C);
    // 0x80034244: lh          $t0, 0x2($s0)
    ctx->r8 = MEM_H(ctx->r16, 0X2);
    // 0x80034248: sll         $t2, $t1, 9
    ctx->r10 = S32(ctx->r9 << 9);
    // 0x8003424C: subu        $t3, $t0, $t2
    ctx->r11 = SUB32(ctx->r8, ctx->r10);
    // 0x80034250: sh          $t3, 0x2($s0)
    MEM_H(0X2, ctx->r16) = ctx->r11;
L_80034254:
    // 0x80034254: lwc1        $f8, 0x1C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x80034258: lwc1        $f4, 0x20($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X20);
    // 0x8003425C: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80034260: lwc1        $f8, 0x24($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X24);
    // 0x80034264: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80034268: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8003426C: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80034270: mul.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f2.fl);
    // 0x80034274: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80034278: mfc1        $a3, $f10
    ctx->r7 = (int32_t)ctx->f10.u32l;
    // 0x8003427C: jal         0x80011570
    // 0x80034280: nop

    move_object(rdram, ctx);
        goto after_4;
    // 0x80034280: nop

    after_4:
    // 0x80034284: lh          $t4, 0x4A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X4A);
    // 0x80034288: addiu       $at, $zero, 0x12A
    ctx->r1 = ADD32(0, 0X12A);
    // 0x8003428C: bne         $t4, $at, L_800342B4
    if (ctx->r12 != ctx->r1) {
        // 0x80034290: addiu       $a1, $sp, 0x4C
        ctx->r5 = ADD32(ctx->r29, 0X4C);
            goto L_800342B4;
    }
    // 0x80034290: addiu       $a1, $sp, 0x4C
    ctx->r5 = ADD32(ctx->r29, 0X4C);
    // 0x80034294: lwc1        $f12, 0x10($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034298: jal         0x8002AD08
    // 0x8003429C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    get_wave_properties(rdram, ctx);
        goto after_5;
    // 0x8003429C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_5:
    // 0x800342A0: beq         $v0, $zero, L_800342B8
    if (ctx->r2 == 0) {
        // 0x800342A4: lw          $t6, 0x8C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X8C);
            goto L_800342B8;
    }
    // 0x800342A4: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
    // 0x800342A8: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800342AC: nop

    // 0x800342B0: swc1        $f4, 0x10($s0)
    MEM_W(0X10, ctx->r16) = ctx->f4.u32l;
L_800342B4:
    // 0x800342B4: lw          $t6, 0x8C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X8C);
L_800342B8:
    // 0x800342B8: lh          $t5, 0x18($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X18);
    // 0x800342BC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800342C0: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x800342C4: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800342C8: lw          $t9, 0x64($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X64);
    // 0x800342CC: addu        $t8, $t5, $t7
    ctx->r24 = ADD32(ctx->r13, ctx->r15);
    // 0x800342D0: sh          $t8, 0x18($s0)
    MEM_H(0X18, ctx->r16) = ctx->r24;
    // 0x800342D4: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x800342D8: lw          $v0, 0x4C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X4C);
    // 0x800342DC: nop

    // 0x800342E0: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x800342E4: nop

    // 0x800342E8: beq         $a0, $zero, L_800343B4
    if (ctx->r4 == 0) {
        // 0x800342EC: nop
    
            goto L_800343B4;
    }
    // 0x800342EC: nop

    // 0x800342F0: lbu         $t1, 0x13($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X13);
    // 0x800342F4: nop

    // 0x800342F8: slti        $at, $t1, 0x3C
    ctx->r1 = SIGNED(ctx->r9) < 0X3C ? 1 : 0;
    // 0x800342FC: beq         $at, $zero, L_800343B4
    if (ctx->r1 == 0) {
        // 0x80034300: nop
    
            goto L_800343B4;
    }
    // 0x80034300: nop

    // 0x80034304: lw          $t0, 0x40($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X40);
    // 0x80034308: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003430C: lb          $t2, 0x54($t0)
    ctx->r10 = MEM_B(ctx->r8, 0X54);
    // 0x80034310: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x80034314: bne         $a1, $t2, L_800343B4
    if (ctx->r5 != ctx->r10) {
        // 0x80034318: nop
    
            goto L_800343B4;
    }
    // 0x80034318: nop

    // 0x8003431C: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x80034320: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80034324: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80034328: nop

    // 0x8003432C: beq         $t3, $at, L_800343B4
    if (ctx->r11 == ctx->r1) {
        // 0x80034330: nop
    
            goto L_800343B4;
    }
    // 0x80034330: nop

    // 0x80034334: lh          $t4, 0x48($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X48);
    // 0x80034338: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x8003433C: bne         $t4, $at, L_80034388
    if (ctx->r12 != ctx->r1) {
        // 0x80034340: addiu       $t6, $zero, 0x14
        ctx->r14 = ADD32(0, 0X14);
            goto L_80034388;
    }
    // 0x80034340: addiu       $t6, $zero, 0x14
    ctx->r14 = ADD32(0, 0X14);
    // 0x80034344: sb          $a1, 0x187($v0)
    MEM_B(0X187, ctx->r2) = ctx->r5;
    // 0x80034348: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003434C: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80034350: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034354: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034358: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003435C: sw          $t6, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r14;
    // 0x80034360: addiu       $t5, $zero, 0x11
    ctx->r13 = ADD32(0, 0X11);
    // 0x80034364: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80034368: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8003436C: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x80034370: jal         0x8003FC44
    // 0x80034374: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_6;
    // 0x80034374: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    after_6:
    // 0x80034378: jal         0x8000FFB8
    // 0x8003437C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_7;
    // 0x8003437C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_7:
    // 0x80034380: b           L_800343B8
    // 0x80034384: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
        goto L_800343B8;
    // 0x80034384: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
L_80034388:
    // 0x80034388: lw          $t7, 0x7C($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X7C);
    // 0x8003438C: addiu       $t8, $zero, 0x3C
    ctx->r24 = ADD32(0, 0X3C);
    // 0x80034390: blez        $t7, L_800343B4
    if (SIGNED(ctx->r15) <= 0) {
        // 0x80034394: addiu       $t9, $zero, -0x3C
        ctx->r25 = ADD32(0, -0X3C);
            goto L_800343B4;
    }
    // 0x80034394: addiu       $t9, $zero, -0x3C
    ctx->r25 = ADD32(0, -0X3C);
    // 0x80034398: sh          $t8, 0x204($v0)
    MEM_H(0X204, ctx->r2) = ctx->r24;
    // 0x8003439C: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x800343A0: sw          $v1, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r3;
    // 0x800343A4: lw          $a1, 0x74($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X74);
    // 0x800343A8: addiu       $a0, $zero, 0x24A
    ctx->r4 = ADD32(0, 0X24A);
    // 0x800343AC: jal         0x80001D04
    // 0x800343B0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800343B0: addiu       $a1, $a1, 0x1C
    ctx->r5 = ADD32(ctx->r5, 0X1C);
    after_8:
L_800343B4:
    // 0x800343B4: lh          $t1, 0x48($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X48);
L_800343B8:
    // 0x800343B8: addiu       $at, $zero, 0x6C
    ctx->r1 = ADD32(0, 0X6C);
    // 0x800343BC: bne         $t1, $at, L_80034488
    if (ctx->r9 != ctx->r1) {
        // 0x800343C0: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80034488;
    }
    // 0x800343C0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800343C4: sw          $t0, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r8;
    // 0x800343C8: lw          $a1, 0x8C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X8C);
    // 0x800343CC: jal         0x800AFC3C
    // 0x800343D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_9;
    // 0x800343D0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_9:
    // 0x800343D4: lw          $t2, 0x7C($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X7C);
    // 0x800343D8: lw          $t3, 0x8C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X8C);
    // 0x800343DC: nop

    // 0x800343E0: subu        $t4, $t2, $t3
    ctx->r12 = SUB32(ctx->r10, ctx->r11);
    // 0x800343E4: bgez        $t4, L_80034520
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800343E8: sw          $t4, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r12;
            goto L_80034520;
    }
    // 0x800343E8: sw          $t4, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r12;
    // 0x800343EC: lh          $t5, 0x4A($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X4A);
    // 0x800343F0: addiu       $at, $zero, 0x12A
    ctx->r1 = ADD32(0, 0X12A);
    // 0x800343F4: bne         $t5, $at, L_80034434
    if (ctx->r13 != ctx->r1) {
        // 0x800343F8: nop
    
            goto L_80034434;
    }
    // 0x800343F8: nop

    // 0x800343FC: jal         0x8000FFB8
    // 0x80034400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_10;
    // 0x80034400: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_10:
    // 0x80034404: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80034408: lwc1        $f14, 0x10($s0)
    ctx->f14.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003440C: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x80034410: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80034414: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034418: addiu       $t7, $zero, 0x11
    ctx->r15 = ADD32(0, 0X11);
    // 0x8003441C: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80034420: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x80034424: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80034428: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003442C: jal         0x8003FC44
    // 0x80034430: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_11;
    // 0x80034430: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_11:
L_80034434:
    // 0x80034434: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80034438: lwc1        $f10, 0x8($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X8);
    // 0x8003443C: lwc1        $f7, 0x5FF0($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5FF0);
    // 0x80034440: lwc1        $f6, 0x5FF4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5FF4);
    // 0x80034444: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80034448: mul.d       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x8003444C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x80034450: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80034454: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80034458: swc1        $f10, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f10.u32l;
    // 0x8003445C: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80034460: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80034464: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80034468: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8003446C: nop

    // 0x80034470: bc1f        L_80034524
    if (!c1cs) {
        // 0x80034474: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80034524;
    }
    // 0x80034474: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80034478: jal         0x8000FFB8
    // 0x8003447C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_12;
    // 0x8003447C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_12:
    // 0x80034480: b           L_80034524
    // 0x80034484: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
        goto L_80034524;
    // 0x80034484: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80034488:
    // 0x80034488: lw          $v0, 0x7C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X7C);
    // 0x8003448C: lw          $t0, 0x8C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X8C);
    // 0x80034490: bgez        $v0, L_800344BC
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80034494: subu        $t2, $v0, $t0
        ctx->r10 = SUB32(ctx->r2, ctx->r8);
            goto L_800344BC;
    }
    // 0x80034494: subu        $t2, $v0, $t0
    ctx->r10 = SUB32(ctx->r2, ctx->r8);
    // 0x80034498: lw          $t9, 0x8C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X8C);
    // 0x8003449C: nop

    // 0x800344A0: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x800344A4: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x800344A8: bltz        $t1, L_800344D0
    if (SIGNED(ctx->r9) < 0) {
        // 0x800344AC: or          $v0, $t1, $zero
        ctx->r2 = ctx->r9 | 0;
            goto L_800344D0;
    }
    // 0x800344AC: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
    // 0x800344B0: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x800344B4: b           L_800344D0
    // 0x800344B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800344D0;
    // 0x800344B8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800344BC:
    // 0x800344BC: sw          $t2, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r10;
    // 0x800344C0: bgtz        $t2, L_800344D0
    if (SIGNED(ctx->r10) > 0) {
        // 0x800344C4: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_800344D0;
    }
    // 0x800344C4: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x800344C8: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
    // 0x800344CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800344D0:
    // 0x800344D0: bne         $v0, $zero, L_80034524
    if (ctx->r2 != 0) {
        // 0x800344D4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_80034524;
    }
    // 0x800344D4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800344D8: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x800344DC: nop

    // 0x800344E0: lw          $a0, 0x1C($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X1C);
    // 0x800344E4: nop

    // 0x800344E8: beq         $a0, $zero, L_800344F8
    if (ctx->r4 == 0) {
        // 0x800344EC: nop
    
            goto L_800344F8;
    }
    // 0x800344EC: nop

    // 0x800344F0: jal         0x8000488C
    // 0x800344F4: nop

    sndp_stop(rdram, ctx);
        goto after_13;
    // 0x800344F4: nop

    after_13:
L_800344F8:
    // 0x800344F8: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x800344FC: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80034500: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80034504: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x80034508: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8003450C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80034510: jal         0x80009558
    // 0x80034514: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    audspat_play_sound_at_position(rdram, ctx);
        goto after_14;
    // 0x80034514: addiu       $a0, $zero, 0x155
    ctx->r4 = ADD32(0, 0X155);
    after_14:
    // 0x80034518: jal         0x8000FFB8
    // 0x8003451C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    free_object(rdram, ctx);
        goto after_15;
    // 0x8003451C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_15:
L_80034520:
    // 0x80034520: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_80034524:
    // 0x80034524: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80034528: jr          $ra
    // 0x8003452C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8003452C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void mark_read_all_save_files(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EBA8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8006EBAC: addiu       $v0, $v0, -0x2C84
    ctx->r2 = ADD32(ctx->r2, -0X2C84);
    // 0x8006EBB0: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8006EBB4: nop

    // 0x8006EBB8: ori         $t7, $t6, 0x8
    ctx->r15 = ctx->r14 | 0X8;
    // 0x8006EBBC: jr          $ra
    // 0x8006EBC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    return;
    // 0x8006EBC0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
;}
RECOMP_FUNC void obj_init_parkwarden(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800392B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800392BC: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x800392C0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800392C4: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800392C8: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x800392CC: addiu       $t9, $zero, 0x1E
    ctx->r25 = ADD32(0, 0X1E);
    // 0x800392D0: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x800392D4: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x800392D8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800392DC: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x800392E0: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x800392E4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800392E8: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x800392EC: lw          $v0, 0x64($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X64);
    // 0x800392F0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800392F4: sb          $t2, 0xD($v0)
    MEM_B(0XD, ctx->r2) = ctx->r10;
    // 0x800392F8: swc1        $f4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f4.u32l;
    // 0x800392FC: sh          $zero, 0x28($v0)
    MEM_H(0X28, ctx->r2) = 0;
    // 0x80039300: sw          $zero, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = 0;
    // 0x80039304: sh          $zero, 0x34($v0)
    MEM_H(0X34, ctx->r2) = 0;
    // 0x80039308: sb          $zero, 0x36($v0)
    MEM_B(0X36, ctx->r2) = 0;
    // 0x8003930C: sw          $zero, -0x2B2C($at)
    MEM_W(-0X2B2C, ctx->r1) = 0;
    // 0x80039310: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80039314: addiu       $t3, $zero, 0x10F
    ctx->r11 = ADD32(0, 0X10F);
    // 0x80039318: jr          $ra
    // 0x8003931C: sh          $t3, -0x2B1E($at)
    MEM_H(-0X2B1E, ctx->r1) = ctx->r11;
    return;
    // 0x8003931C: sh          $t3, -0x2B1E($at)
    MEM_H(-0X2B1E, ctx->r1) = ctx->r11;
;}
RECOMP_FUNC void align8(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007186C: andi        $v1, $a0, 0x7
    ctx->r3 = ctx->r4 & 0X7;
    // 0x80071870: blez        $v1, L_80071880
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80071874: nop
    
            goto L_80071880;
    }
    // 0x80071874: nop

    // 0x80071878: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x8007187C: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
L_80071880:
    // 0x80071880: jr          $ra
    // 0x80071884: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    return;
    // 0x80071884: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
;}
RECOMP_FUNC void get_trophy_race_world_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009962C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80099630: lw          $v0, 0xFE8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0XFE8);
    // 0x80099634: jr          $ra
    // 0x80099638: nop

    return;
    // 0x80099638: nop

;}
RECOMP_FUNC void sndp_play_with_priority(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004668: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8000466C: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004670: sll         $s1, $a1, 16
    ctx->r17 = S32(ctx->r5 << 16);
    // 0x80004674: sra         $t6, $s1, 16
    ctx->r14 = S32(SIGNED(ctx->r17) >> 16);
    // 0x80004678: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000467C: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x80004680: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004684: andi        $fp, $a2, 0xFF
    ctx->r30 = ctx->r6 & 0XFF;
    // 0x80004688: or          $s1, $t6, $zero
    ctx->r17 = ctx->r14 | 0;
    // 0x8000468C: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x80004690: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80004694: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80004698: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000469C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800046A0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800046A4: sw          $a1, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r5;
    // 0x800046A8: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
    // 0x800046AC: sw          $a3, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r7;
    // 0x800046B0: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800046B4: sh          $zero, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = 0;
    // 0x800046B8: bne         $t6, $zero, L_800046C8
    if (ctx->r14 != 0) {
        // 0x800046BC: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_800046C8;
    }
    // 0x800046BC: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x800046C0: b           L_8000485C
    // 0x800046C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8000485C;
    // 0x800046C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800046C8:
    // 0x800046C8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800046CC: lw          $s3, 0x64($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X64);
    // 0x800046D0: addiu       $s5, $s5, -0x3944
    ctx->r21 = ADD32(ctx->r21, -0X3944);
    // 0x800046D4: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    // 0x800046D8: addiu       $s6, $sp, 0x50
    ctx->r22 = ADD32(ctx->r29, 0X50);
    // 0x800046DC: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
L_800046E0:
    // 0x800046E0: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x800046E4: lw          $t7, 0xC($a0)
    ctx->r15 = MEM_W(ctx->r4, 0XC);
    // 0x800046E8: nop

    // 0x800046EC: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800046F0: lw          $s2, 0xC($t9)
    ctx->r18 = MEM_W(ctx->r25, 0XC);
    // 0x800046F4: jal         0x80004384
    // 0x800046F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    sndp_allocate(rdram, ctx);
        goto after_0;
    // 0x800046F8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_0:
    // 0x800046FC: beq         $v0, $zero, L_800047B0
    if (ctx->r2 == 0) {
        // 0x80004700: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800047B0;
    }
    // 0x80004700: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x80004704: lw          $t0, 0x0($s5)
    ctx->r8 = MEM_W(ctx->r21, 0X0);
    // 0x80004708: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8000470C: sw          $v0, 0x3C($t0)
    MEM_W(0X3C, ctx->r8) = ctx->r2;
    // 0x80004710: sh          $t1, 0x50($sp)
    MEM_H(0X50, ctx->r29) = ctx->r9;
    // 0x80004714: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80004718: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x8000471C: addiu       $a2, $s4, 0x1
    ctx->r6 = ADD32(ctx->r20, 0X1);
    // 0x80004720: lbu         $s3, 0x1($t2)
    ctx->r19 = MEM_BU(ctx->r10, 0X1);
    // 0x80004724: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80004728: sll         $t3, $s3, 6
    ctx->r11 = S32(ctx->r19 << 6);
    // 0x8000472C: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004730: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80004734: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004738: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000473C: subu        $t3, $t3, $s3
    ctx->r11 = SUB32(ctx->r11, ctx->r19);
    // 0x80004740: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80004744: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004748: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8000474C: addu        $t3, $t3, $s3
    ctx->r11 = ADD32(ctx->r11, ctx->r19);
    // 0x80004750: beq         $fp, $zero, L_8000475C
    if (ctx->r30 == 0) {
        // 0x80004754: or          $s3, $t3, $zero
        ctx->r19 = ctx->r11 | 0;
            goto L_8000475C;
    }
    // 0x80004754: or          $s3, $t3, $zero
    ctx->r19 = ctx->r11 | 0;
    // 0x80004758: sb          $fp, 0x36($v0)
    MEM_B(0X36, ctx->r2) = ctx->r30;
L_8000475C:
    // 0x8000475C: lbu         $t4, 0x3E($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X3E);
    // 0x80004760: nop

    // 0x80004764: andi        $t5, $t4, 0x10
    ctx->r13 = ctx->r12 & 0X10;
    // 0x80004768: beq         $t5, $zero, L_8000479C
    if (ctx->r13 == 0) {
        // 0x8000476C: nop
    
            goto L_8000479C;
    }
    // 0x8000476C: nop

    // 0x80004770: lbu         $t6, 0x3E($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X3E);
    // 0x80004774: or          $a1, $s6, $zero
    ctx->r5 = ctx->r22 | 0;
    // 0x80004778: andi        $t7, $t6, 0xFFEF
    ctx->r15 = ctx->r14 & 0XFFEF;
    // 0x8000477C: sb          $t7, 0x3E($s0)
    MEM_B(0X3E, ctx->r16) = ctx->r15;
    // 0x80004780: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x80004784: jal         0x800C91AC
    // 0x80004788: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_1;
    // 0x80004788: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_1:
    // 0x8000478C: addiu       $t8, $s3, 0x1
    ctx->r24 = ADD32(ctx->r19, 0X1);
    // 0x80004790: sw          $t8, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r24;
    // 0x80004794: b           L_800047AC
    // 0x80004798: sh          $s1, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r17;
        goto L_800047AC;
    // 0x80004798: sh          $s1, 0x6E($sp)
    MEM_H(0X6E, ctx->r29) = ctx->r17;
L_8000479C:
    // 0x8000479C: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x800047A0: addiu       $a2, $s3, 0x1
    ctx->r6 = ADD32(ctx->r19, 0X1);
    // 0x800047A4: jal         0x800C91AC
    // 0x800047A8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_2;
    // 0x800047A8: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_2:
L_800047AC:
    // 0x800047AC: or          $s7, $s0, $zero
    ctx->r23 = ctx->r16 | 0;
L_800047B0:
    // 0x800047B0: lw          $v0, 0x4($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X4);
    // 0x800047B4: addu        $s4, $s4, $s3
    ctx->r20 = ADD32(ctx->r20, ctx->r19);
    // 0x800047B8: lbu         $t0, 0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2);
    // 0x800047BC: lbu         $t9, 0x0($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X0);
    // 0x800047C0: andi        $t1, $t0, 0xC0
    ctx->r9 = ctx->r8 & 0XC0;
    // 0x800047C4: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800047C8: addu        $s1, $t9, $t2
    ctx->r17 = ADD32(ctx->r25, ctx->r10);
    // 0x800047CC: sll         $t3, $s1, 16
    ctx->r11 = S32(ctx->r17 << 16);
    // 0x800047D0: sra         $s1, $t3, 16
    ctx->r17 = S32(SIGNED(ctx->r11) >> 16);
    // 0x800047D4: beq         $s1, $zero, L_800047E8
    if (ctx->r17 == 0) {
        // 0x800047D8: nop
    
            goto L_800047E8;
    }
    // 0x800047D8: nop

    // 0x800047DC: bne         $s0, $zero, L_800046E0
    if (ctx->r16 != 0) {
        // 0x800047E0: lw          $a0, 0x80($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X80);
            goto L_800046E0;
    }
    // 0x800047E0: lw          $a0, 0x80($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X80);
    // 0x800047E4: sw          $s3, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r19;
L_800047E8:
    // 0x800047E8: beq         $s7, $zero, L_8000484C
    if (ctx->r23 == 0) {
        // 0x800047EC: lw          $t4, 0x8C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X8C);
            goto L_8000484C;
    }
    // 0x800047EC: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x800047F0: lbu         $t5, 0x3E($s7)
    ctx->r13 = MEM_BU(ctx->r23, 0X3E);
    // 0x800047F4: addiu       $t9, $zero, 0x200
    ctx->r25 = ADD32(0, 0X200);
    // 0x800047F8: ori         $t6, $t5, 0x1
    ctx->r14 = ctx->r13 | 0X1;
    // 0x800047FC: sb          $t6, 0x3E($s7)
    MEM_B(0X3E, ctx->r23) = ctx->r14;
    // 0x80004800: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x80004804: ori         $t1, $t6, 0x10
    ctx->r9 = ctx->r14 | 0X10;
    // 0x80004808: sw          $t7, 0x30($s7)
    MEM_W(0X30, ctx->r23) = ctx->r15;
    // 0x8000480C: lh          $t8, 0x6E($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X6E);
    // 0x80004810: addiu       $a1, $sp, 0x40
    ctx->r5 = ADD32(ctx->r29, 0X40);
    // 0x80004814: beq         $t8, $zero, L_8000484C
    if (ctx->r24 == 0) {
        // 0x80004818: lw          $t4, 0x8C($sp)
        ctx->r12 = MEM_W(ctx->r29, 0X8C);
            goto L_8000484C;
    }
    // 0x80004818: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
    // 0x8000481C: sb          $t1, 0x3E($s7)
    MEM_B(0X3E, ctx->r23) = ctx->r9;
    // 0x80004820: lh          $t2, 0x6E($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X6E);
    // 0x80004824: lw          $t3, 0x80($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X80);
    // 0x80004828: lw          $a0, 0x0($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X0);
    // 0x8000482C: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x80004830: sh          $t9, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r25;
    // 0x80004834: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80004838: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8000483C: sw          $t3, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r11;
    // 0x80004840: jal         0x800C91AC
    // 0x80004844: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_3;
    // 0x80004844: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_3:
    // 0x80004848: lw          $t4, 0x8C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X8C);
L_8000484C:
    // 0x8000484C: or          $v0, $s7, $zero
    ctx->r2 = ctx->r23 | 0;
    // 0x80004850: beq         $t4, $zero, L_8000485C
    if (ctx->r12 == 0) {
        // 0x80004854: nop
    
            goto L_8000485C;
    }
    // 0x80004854: nop

    // 0x80004858: sw          $s7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r23;
L_8000485C:
    // 0x8000485C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x80004860: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80004864: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80004868: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000486C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80004870: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80004874: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80004878: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000487C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x80004880: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x80004884: jr          $ra
    // 0x80004888: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80004888: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void gameselect_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008CACC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008CAD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008CAD4: jal         0x800C422C
    // 0x8008CAD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x8008CAD8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008CADC: jal         0x8007FF88
    // 0x8008CAE0: nop

    menu_button_free(rdram, ctx);
        goto after_1;
    // 0x8008CAE0: nop

    after_1:
    // 0x8008CAE4: jal         0x8009C508
    // 0x8008CAE8: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    menu_asset_free(rdram, ctx);
        goto after_2;
    // 0x8008CAE8: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    after_2:
    // 0x8008CAEC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008CAF0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008CAF4: jr          $ra
    // 0x8008CAF8: nop

    return;
    // 0x8008CAF8: nop

;}
RECOMP_FUNC void racer_sound_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80004B40: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x80004B44: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80004B48: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80004B4C: slti        $at, $a0, 0xB
    ctx->r1 = SIGNED(ctx->r4) < 0XB ? 1 : 0;
    // 0x80004B50: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80004B54: or          $s3, $a1, $zero
    ctx->r19 = ctx->r5 | 0;
    // 0x80004B58: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80004B5C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80004B60: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80004B64: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80004B68: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80004B6C: bne         $at, $zero, L_80004B78
    if (ctx->r1 != 0) {
        // 0x80004B70: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80004B78;
    }
    // 0x80004B70: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80004B74: addiu       $s0, $zero, 0xB
    ctx->r16 = ADD32(0, 0XB);
L_80004B78:
    // 0x80004B78: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80004B7C: lw          $t6, -0x3928($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X3928);
    // 0x80004B80: nop

    // 0x80004B84: beq         $t6, $zero, L_80004BAC
    if (ctx->r14 == 0) {
        // 0x80004B88: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80004BAC;
    }
    // 0x80004B88: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80004B8C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80004B90: addiu       $v1, $v1, -0x63C8
    ctx->r3 = ADD32(ctx->r3, -0X63C8);
    // 0x80004B94: addiu       $v0, $v0, -0x63D0
    ctx->r2 = ADD32(ctx->r2, -0X63D0);
L_80004B98:
    // 0x80004B98: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80004B9C: bne         $v0, $v1, L_80004B98
    if (ctx->r2 != ctx->r3) {
        // 0x80004BA0: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_80004B98;
    }
    // 0x80004BA0: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x80004BA4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004BA8: sw          $zero, -0x3928($at)
    MEM_W(-0X3928, ctx->r1) = 0;
L_80004BAC:
    // 0x80004BAC: jal         0x80076C58
    // 0x80004BB0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    asset_table_load(rdram, ctx);
        goto after_0;
    // 0x80004BB0: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_0:
    // 0x80004BB4: sll         $s6, $s3, 2
    ctx->r22 = S32(ctx->r19 << 2);
    // 0x80004BB8: addu        $s6, $s6, $s3
    ctx->r22 = ADD32(ctx->r22, ctx->r19);
    // 0x80004BBC: sll         $s6, $s6, 1
    ctx->r22 = S32(ctx->r22 << 1);
    // 0x80004BC0: addu        $t8, $s6, $s0
    ctx->r24 = ADD32(ctx->r22, ctx->r16);
    // 0x80004BC4: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80004BC8: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80004BCC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    // 0x80004BD0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80004BD4: lw          $t7, 0x1C($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X1C);
    // 0x80004BD8: lui         $s2, 0xFF
    ctx->r18 = S32(0XFF << 16);
    // 0x80004BDC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x80004BE0: ori         $s2, $s2, 0xFFFF
    ctx->r18 = ctx->r18 | 0XFFFF;
    // 0x80004BE4: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80004BE8: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    // 0x80004BEC: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x80004BF0: jal         0x80070C9C
    // 0x80004BF4: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80004BF4: addu        $s1, $t7, $t9
    ctx->r17 = ADD32(ctx->r15, ctx->r25);
    after_1:
    // 0x80004BF8: or          $s5, $v0, $zero
    ctx->r21 = ctx->r2 | 0;
    // 0x80004BFC: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x80004C00: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x80004C04: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x80004C08: jal         0x80076E68
    // 0x80004C0C: addiu       $a3, $zero, 0x4C
    ctx->r7 = ADD32(0, 0X4C);
    asset_load(rdram, ctx);
        goto after_2;
    // 0x80004C0C: addiu       $a3, $zero, 0x4C
    ctx->r7 = ADD32(0, 0X4C);
    after_2:
    // 0x80004C10: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
    // 0x80004C14: jal         0x80070C9C
    // 0x80004C18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80004C18: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80004C1C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x80004C20: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80004C24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80004C28: addiu       $a0, $zero, 0xE0
    ctx->r4 = ADD32(0, 0XE0);
L_80004C2C:
    // 0x80004C2C: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x80004C30: sb          $zero, 0x1($v1)
    MEM_B(0X1, ctx->r3) = 0;
    // 0x80004C34: sb          $zero, 0x2($v1)
    MEM_B(0X2, ctx->r3) = 0;
    // 0x80004C38: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x80004C3C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80004C40: bne         $a3, $a0, L_80004C2C
    if (ctx->r7 != ctx->r4) {
        // 0x80004C44: sb          $zero, -0x4($v1)
        MEM_B(-0X4, ctx->r3) = 0;
            goto L_80004C2C;
    }
    // 0x80004C44: sb          $zero, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = 0;
    // 0x80004C48: lbu         $t6, 0x36($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X36);
    // 0x80004C4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80004C50: lwc1        $f2, 0x4BF0($at)
    ctx->f2.u32l = MEM_W(ctx->r1, 0X4BF0);
    // 0x80004C54: sb          $t6, 0x36($v0)
    MEM_B(0X36, ctx->r2) = ctx->r14;
    // 0x80004C58: lbu         $t8, 0x37($s5)
    ctx->r24 = MEM_BU(ctx->r21, 0X37);
    // 0x80004C5C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80004C60: sb          $t8, 0x37($v0)
    MEM_B(0X37, ctx->r2) = ctx->r24;
    // 0x80004C64: lbu         $t7, 0x38($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X38);
    // 0x80004C68: or          $s1, $s5, $zero
    ctx->r17 = ctx->r21 | 0;
    // 0x80004C6C: sb          $t7, 0x38($v0)
    MEM_B(0X38, ctx->r2) = ctx->r15;
    // 0x80004C70: lbu         $t9, 0x39($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X39);
    // 0x80004C74: or          $t3, $s5, $zero
    ctx->r11 = ctx->r21 | 0;
    // 0x80004C78: sb          $t9, 0x39($v0)
    MEM_B(0X39, ctx->r2) = ctx->r25;
    // 0x80004C7C: lbu         $t6, 0x3A($s5)
    ctx->r14 = MEM_BU(ctx->r21, 0X3A);
    // 0x80004C80: or          $t4, $s5, $zero
    ctx->r12 = ctx->r21 | 0;
    // 0x80004C84: sb          $t6, 0x64($v0)
    MEM_B(0X64, ctx->r2) = ctx->r14;
    // 0x80004C88: lh          $t8, 0x46($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X46);
    // 0x80004C8C: or          $t5, $v0, $zero
    ctx->r13 = ctx->r2 | 0;
    // 0x80004C90: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004C94: or          $ra, $v0, $zero
    ctx->r31 = ctx->r2 | 0;
    // 0x80004C98: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004C9C: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x80004CA0: or          $t2, $s5, $zero
    ctx->r10 = ctx->r21 | 0;
    // 0x80004CA4: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004CA8: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80004CAC: or          $s3, $s5, $zero
    ctx->r19 = ctx->r21 | 0;
    // 0x80004CB0: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x80004CB4: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x80004CB8: swc1        $f8, 0xC8($v0)
    MEM_W(0XC8, ctx->r2) = ctx->f8.u32l;
    // 0x80004CBC: lh          $t7, 0x3E($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X3E);
    // 0x80004CC0: nop

    // 0x80004CC4: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80004CC8: nop

    // 0x80004CCC: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004CD0: nop

    // 0x80004CD4: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80004CD8: swc1        $f18, 0xB0($v0)
    MEM_W(0XB0, ctx->r2) = ctx->f18.u32l;
    // 0x80004CDC: lh          $t9, 0x40($s5)
    ctx->r25 = MEM_H(ctx->r21, 0X40);
    // 0x80004CE0: nop

    // 0x80004CE4: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80004CE8: nop

    // 0x80004CEC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004CF0: nop

    // 0x80004CF4: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004CF8: swc1        $f8, 0xB4($v0)
    MEM_W(0XB4, ctx->r2) = ctx->f8.u32l;
    // 0x80004CFC: lh          $t6, 0x42($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X42);
    // 0x80004D00: nop

    // 0x80004D04: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x80004D08: nop

    // 0x80004D0C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004D10: nop

    // 0x80004D14: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80004D18: swc1        $f18, 0xC0($v0)
    MEM_W(0XC0, ctx->r2) = ctx->f18.u32l;
    // 0x80004D1C: lh          $t8, 0x44($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X44);
    // 0x80004D20: nop

    // 0x80004D24: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004D28: nop

    // 0x80004D2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004D30: nop

    // 0x80004D34: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004D38: swc1        $f8, 0xC4($v0)
    MEM_W(0XC4, ctx->r2) = ctx->f8.u32l;
    // 0x80004D3C: lh          $t7, 0x3C($s5)
    ctx->r15 = MEM_H(ctx->r21, 0X3C);
    // 0x80004D40: nop

    // 0x80004D44: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80004D48: nop

    // 0x80004D4C: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004D50: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80004D54: div.s       $f18, $f16, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = DIV_S(ctx->f16.fl, ctx->f2.fl);
    // 0x80004D58: swc1        $f18, 0xBC($v0)
    MEM_W(0XBC, ctx->r2) = ctx->f18.u32l;
    // 0x80004D5C: lbu         $t9, 0x3B($s5)
    ctx->r25 = MEM_BU(ctx->r21, 0X3B);
    // 0x80004D60: nop

    // 0x80004D64: sb          $t9, 0xB8($v0)
    MEM_B(0XB8, ctx->r2) = ctx->r25;
    // 0x80004D68: lh          $t6, 0x48($s5)
    ctx->r14 = MEM_H(ctx->r21, 0X48);
    // 0x80004D6C: sb          $zero, 0xD8($v0)
    MEM_B(0XD8, ctx->r2) = 0;
    // 0x80004D70: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80004D74: nop

    // 0x80004D78: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004D7C: nop

    // 0x80004D80: div.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004D84: swc1        $f8, 0xCC($v0)
    MEM_W(0XCC, ctx->r2) = ctx->f8.u32l;
L_80004D88:
    // 0x80004D88: lhu         $t8, 0x0($s1)
    ctx->r24 = MEM_HU(ctx->r17, 0X0);
    // 0x80004D8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80004D90: sh          $t8, 0x0($s4)
    MEM_H(0X0, ctx->r20) = ctx->r24;
    // 0x80004D94: lbu         $t7, 0x4($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X4);
    // 0x80004D98: addiu       $v1, $t3, 0x1
    ctx->r3 = ADD32(ctx->r11, 0X1);
    // 0x80004D9C: sb          $t7, 0x4($t1)
    MEM_B(0X4, ctx->r9) = ctx->r15;
    // 0x80004DA0: lhu         $t9, 0x18($s3)
    ctx->r25 = MEM_HU(ctx->r19, 0X18);
    // 0x80004DA4: addiu       $a1, $t4, 0x2
    ctx->r5 = ADD32(ctx->r12, 0X2);
    // 0x80004DA8: sh          $t9, 0x18($s2)
    MEM_H(0X18, ctx->r18) = ctx->r25;
    // 0x80004DAC: lbu         $t6, 0xE($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0XE);
    // 0x80004DB0: addiu       $a0, $t5, 0x1
    ctx->r4 = ADD32(ctx->r13, 0X1);
    // 0x80004DB4: sb          $t6, 0xE($t1)
    MEM_B(0XE, ctx->r9) = ctx->r14;
    // 0x80004DB8: lbu         $t8, 0x2C($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2C);
    // 0x80004DBC: addiu       $a2, $ra, 0x2
    ctx->r6 = ADD32(ctx->r31, 0X2);
    // 0x80004DC0: sb          $t8, 0x2C($t1)
    MEM_B(0X2C, ctx->r9) = ctx->r24;
L_80004DC4:
    // 0x80004DC4: lbu         $t7, 0x4($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X4);
    // 0x80004DC8: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x80004DCC: sb          $t7, 0x4($a0)
    MEM_B(0X4, ctx->r4) = ctx->r15;
    // 0x80004DD0: lhu         $t9, 0x18($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X18);
    // 0x80004DD4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80004DD8: sh          $t9, 0x18($a2)
    MEM_H(0X18, ctx->r6) = ctx->r25;
    // 0x80004DDC: lbu         $t6, 0xC($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XC);
    // 0x80004DE0: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80004DE4: sb          $t6, 0xE($a0)
    MEM_B(0XE, ctx->r4) = ctx->r14;
    // 0x80004DE8: lbu         $t8, 0x2A($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2A);
    // 0x80004DEC: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
    // 0x80004DF0: sb          $t8, 0x2A($a0)
    MEM_B(0X2A, ctx->r4) = ctx->r24;
    // 0x80004DF4: lbu         $t7, 0x3($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0X3);
    // 0x80004DF8: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80004DFC: sb          $t7, 0x3($a0)
    MEM_B(0X3, ctx->r4) = ctx->r15;
    // 0x80004E00: lhu         $t9, 0x16($a1)
    ctx->r25 = MEM_HU(ctx->r5, 0X16);
    // 0x80004E04: nop

    // 0x80004E08: sh          $t9, 0x16($a2)
    MEM_H(0X16, ctx->r6) = ctx->r25;
    // 0x80004E0C: lbu         $t6, 0xD($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0XD);
    // 0x80004E10: nop

    // 0x80004E14: sb          $t6, 0xD($a0)
    MEM_B(0XD, ctx->r4) = ctx->r14;
    // 0x80004E18: lbu         $t8, 0x2B($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X2B);
    // 0x80004E1C: bne         $a3, $t0, L_80004DC4
    if (ctx->r7 != ctx->r8) {
        // 0x80004E20: sb          $t8, 0x2B($a0)
        MEM_B(0X2B, ctx->r4) = ctx->r24;
            goto L_80004DC4;
    }
    // 0x80004E20: sb          $t8, 0x2B($a0)
    MEM_B(0X2B, ctx->r4) = ctx->r24;
    // 0x80004E24: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x80004E28: slti        $at, $s0, 0x4
    ctx->r1 = SIGNED(ctx->r16) < 0X4 ? 1 : 0;
    // 0x80004E2C: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80004E30: addiu       $t3, $t3, 0x5
    ctx->r11 = ADD32(ctx->r11, 0X5);
    // 0x80004E34: addiu       $t4, $t4, 0xA
    ctx->r12 = ADD32(ctx->r12, 0XA);
    // 0x80004E38: addiu       $t5, $t5, 0x5
    ctx->r13 = ADD32(ctx->r13, 0X5);
    // 0x80004E3C: addiu       $ra, $ra, 0xA
    ctx->r31 = ADD32(ctx->r31, 0XA);
    // 0x80004E40: addiu       $t1, $t1, 0x5
    ctx->r9 = ADD32(ctx->r9, 0X5);
    // 0x80004E44: addiu       $t2, $t2, 0x5
    ctx->r10 = ADD32(ctx->r10, 0X5);
    // 0x80004E48: addiu       $s2, $s2, 0xA
    ctx->r18 = ADD32(ctx->r18, 0XA);
    // 0x80004E4C: addiu       $s3, $s3, 0xA
    ctx->r19 = ADD32(ctx->r19, 0XA);
    // 0x80004E50: bne         $at, $zero, L_80004D88
    if (ctx->r1 != 0) {
        // 0x80004E54: addiu       $s4, $s4, 0x2
        ctx->r20 = ADD32(ctx->r20, 0X2);
            goto L_80004D88;
    }
    // 0x80004E54: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x80004E58: sb          $zero, 0x74($v0)
    MEM_B(0X74, ctx->r2) = 0;
    // 0x80004E5C: swc1        $f10, 0x6C($v0)
    MEM_W(0X6C, ctx->r2) = ctx->f10.u32l;
    // 0x80004E60: lbu         $t7, 0x4A($s5)
    ctx->r15 = MEM_BU(ctx->r21, 0X4A);
    // 0x80004E64: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004E68: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x80004E6C: bgez        $t7, L_80004E80
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80004E70: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_80004E80;
    }
    // 0x80004E70: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80004E74: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004E78: nop

    // 0x80004E7C: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_80004E80:
    // 0x80004E80: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80004E84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80004E88: nop

    // 0x80004E8C: div.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f18.fl, ctx->f6.fl);
    // 0x80004E90: bne         $s6, $zero, L_80004F40
    if (ctx->r22 != 0) {
        // 0x80004E94: swc1        $f8, 0xD4($v0)
        MEM_W(0XD4, ctx->r2) = ctx->f8.u32l;
            goto L_80004F40;
    }
    // 0x80004E94: swc1        $f8, 0xD4($v0)
    MEM_W(0XD4, ctx->r2) = ctx->f8.u32l;
    // 0x80004E98: lbu         $t9, 0x2C($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2C);
    // 0x80004E9C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004EA0: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x80004EA4: bgez        $t9, L_80004EB8
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80004EA8: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_80004EB8;
    }
    // 0x80004EA8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80004EAC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80004EB0: nop

    // 0x80004EB4: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_80004EB8:
    // 0x80004EB8: lhu         $t6, 0x18($v0)
    ctx->r14 = MEM_HU(ctx->r2, 0X18);
    // 0x80004EBC: swc1        $f16, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f16.u32l;
    // 0x80004EC0: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x80004EC4: bgez        $t6, L_80004EDC
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80004EC8: cvt.s.w     $f6, $f18
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
            goto L_80004EDC;
    }
    // 0x80004EC8: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80004ECC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004ED0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80004ED4: nop

    // 0x80004ED8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80004EDC:
    // 0x80004EDC: nop

    // 0x80004EE0: div.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004EE4: lbu         $t8, 0x31($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X31);
    // 0x80004EE8: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004EEC: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x80004EF0: nop

    // 0x80004EF4: cvt.s.w     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    ctx->f16.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80004EF8: bgez        $t8, L_80004F0C
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80004EFC: swc1        $f10, 0x5C($v0)
        MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
            goto L_80004F0C;
    }
    // 0x80004EFC: swc1        $f10, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f10.u32l;
    // 0x80004F00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80004F04: nop

    // 0x80004F08: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_80004F0C:
    // 0x80004F0C: lhu         $t7, 0x22($v0)
    ctx->r15 = MEM_HU(ctx->r2, 0X22);
    // 0x80004F10: swc1        $f16, 0x58($v0)
    MEM_W(0X58, ctx->r2) = ctx->f16.u32l;
    // 0x80004F14: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80004F18: bgez        $t7, L_80004F30
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80004F1C: cvt.s.w     $f6, $f8
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80004F30;
    }
    // 0x80004F1C: cvt.s.w     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80004F20: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80004F24: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80004F28: nop

    // 0x80004F2C: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_80004F30:
    // 0x80004F30: nop

    // 0x80004F34: div.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = DIV_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80004F38: b           L_80005090
    // 0x80004F3C: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
        goto L_80005090;
    // 0x80004F3C: swc1        $f4, 0x60($v0)
    MEM_W(0X60, ctx->r2) = ctx->f4.u32l;
L_80004F40:
    // 0x80004F40: lwc1        $f0, 0xD4($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0XD4);
    // 0x80004F44: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80004F48: mul.s       $f18, $f0, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80004F4C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80004F50: swc1        $f0, 0x5C($v0)
    MEM_W(0X5C, ctx->r2) = ctx->f0.u32l;
    // 0x80004F54: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80004F58: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80004F5C: nop

    // 0x80004F60: cvt.w.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80004F64: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80004F68: nop

    // 0x80004F6C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80004F70: beq         $v1, $zero, L_80004FBC
    if (ctx->r3 == 0) {
        // 0x80004F74: nop
    
            goto L_80004FBC;
    }
    // 0x80004F74: nop

    // 0x80004F78: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80004F7C: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x80004F80: sub.s       $f16, $f18, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80004F84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80004F88: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80004F8C: nop

    // 0x80004F90: cvt.w.s     $f16, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    ctx->f16.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80004F94: cfc1        $v1, $FpcCsr
    ctx->r3 = get_cop1_cs();
    // 0x80004F98: nop

    // 0x80004F9C: andi        $v1, $v1, 0x78
    ctx->r3 = ctx->r3 & 0X78;
    // 0x80004FA0: bne         $v1, $zero, L_80004FB4
    if (ctx->r3 != 0) {
        // 0x80004FA4: nop
    
            goto L_80004FB4;
    }
    // 0x80004FA4: nop

    // 0x80004FA8: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80004FAC: b           L_80004FCC
    // 0x80004FB0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
        goto L_80004FCC;
    // 0x80004FB0: or          $v1, $v1, $at
    ctx->r3 = ctx->r3 | ctx->r1;
L_80004FB4:
    // 0x80004FB4: b           L_80004FCC
    // 0x80004FB8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
        goto L_80004FCC;
    // 0x80004FB8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80004FBC:
    // 0x80004FBC: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x80004FC0: nop

    // 0x80004FC4: bltz        $v1, L_80004FB4
    if (SIGNED(ctx->r3) < 0) {
        // 0x80004FC8: nop
    
            goto L_80004FB4;
    }
    // 0x80004FC8: nop

L_80004FCC:
    // 0x80004FCC: lhu         $t8, 0x18($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X18);
    // 0x80004FD0: andi        $a1, $v1, 0xFFFF
    ctx->r5 = ctx->r3 & 0XFFFF;
    // 0x80004FD4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80004FD8: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80004FDC: bne         $at, $zero, L_80005010
    if (ctx->r1 != 0) {
        // 0x80004FE0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80005010;
    }
    // 0x80004FE0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80004FE4:
    // 0x80004FE4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80004FE8: andi        $t7, $a0, 0xFFFF
    ctx->r15 = ctx->r4 & 0XFFFF;
    // 0x80004FEC: sll         $t9, $t7, 1
    ctx->r25 = S32(ctx->r15 << 1);
    // 0x80004FF0: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x80004FF4: lhu         $t8, 0x18($t6)
    ctx->r24 = MEM_HU(ctx->r14, 0X18);
    // 0x80004FF8: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x80004FFC: slt         $at, $a1, $t8
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80005000: bne         $at, $zero, L_80005010
    if (ctx->r1 != 0) {
        // 0x80005004: slti        $at, $t7, 0x4
        ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
            goto L_80005010;
    }
    // 0x80005004: slti        $at, $t7, 0x4
    ctx->r1 = SIGNED(ctx->r15) < 0X4 ? 1 : 0;
    // 0x80005008: bne         $at, $zero, L_80004FE4
    if (ctx->r1 != 0) {
        // 0x8000500C: nop
    
            goto L_80004FE4;
    }
    // 0x8000500C: nop

L_80005010:
    // 0x80005010: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x80005014: andi        $v1, $a0, 0xFFFF
    ctx->r3 = ctx->r4 & 0XFFFF;
    // 0x80005018: sll         $t9, $v1, 1
    ctx->r25 = S32(ctx->r3 << 1);
    // 0x8000501C: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x80005020: lhu         $a2, 0x18($t6)
    ctx->r6 = MEM_HU(ctx->r14, 0X18);
    // 0x80005024: sll         $t7, $v1, 1
    ctx->r15 = S32(ctx->r3 << 1);
    // 0x80005028: addu        $t9, $v0, $t7
    ctx->r25 = ADD32(ctx->r2, ctx->r15);
    // 0x8000502C: lhu         $t6, 0x1A($t9)
    ctx->r14 = MEM_HU(ctx->r25, 0X1A);
    // 0x80005030: subu        $t8, $a1, $a2
    ctx->r24 = SUB32(ctx->r5, ctx->r6);
    // 0x80005034: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x80005038: subu        $t8, $t6, $a2
    ctx->r24 = SUB32(ctx->r14, ctx->r6);
    // 0x8000503C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80005040: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80005044: addu        $t9, $v0, $v1
    ctx->r25 = ADD32(ctx->r2, ctx->r3);
    // 0x80005048: addu        $t7, $v0, $v1
    ctx->r15 = ADD32(ctx->r2, ctx->r3);
    // 0x8000504C: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80005050: lbu         $a3, 0x2C($t7)
    ctx->r7 = MEM_BU(ctx->r15, 0X2C);
    // 0x80005054: lbu         $t6, 0x2D($t9)
    ctx->r14 = MEM_BU(ctx->r25, 0X2D);
    // 0x80005058: div.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8000505C: subu        $t8, $t6, $a3
    ctx->r24 = SUB32(ctx->r14, ctx->r7);
    // 0x80005060: mtc1        $t8, $f18
    ctx->f18.u32l = ctx->r24;
    // 0x80005064: mtc1        $a3, $f6
    ctx->f6.u32l = ctx->r7;
    // 0x80005068: cvt.s.w     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8000506C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80005070: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80005074: bgez        $a3, L_80005088
    if (SIGNED(ctx->r7) >= 0) {
        // 0x80005078: cvt.s.w     $f10, $f6
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
            goto L_80005088;
    }
    // 0x80005078: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000507C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80005080: nop

    // 0x80005084: add.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f4.fl;
L_80005088:
    // 0x80005088: add.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000508C: swc1        $f18, 0x54($v0)
    MEM_W(0X54, ctx->r2) = ctx->f18.u32l;
L_80005090:
    // 0x80005090: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80005094: jal         0x80071140
    // 0x80005098: nop

    mempool_free(rdram, ctx);
        goto after_4;
    // 0x80005098: nop

    after_4:
    // 0x8000509C: jal         0x80071140
    // 0x800050A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800050A0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_5:
    // 0x800050A4: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800050A8: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800050AC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800050B0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800050B4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800050B8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800050BC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800050C0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800050C4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800050C8: jr          $ra
    // 0x800050CC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800050CC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void obj_loop_trigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003C7A4: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8003C7A8: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x8003C7AC: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x8003C7B0: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x8003C7B4: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8003C7B8: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8003C7BC: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8003C7C0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8003C7C4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003C7C8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003C7CC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003C7D0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8003C7D4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8003C7D8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003C7DC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8003C7E0: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x8003C7E4: lw          $fp, 0x3C($a0)
    ctx->r30 = MEM_W(ctx->r4, 0X3C);
    // 0x8003C7E8: lw          $s2, 0x64($a0)
    ctx->r18 = MEM_W(ctx->r4, 0X64);
    // 0x8003C7EC: jal         0x8006EA90
    // 0x8003C7F0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003C7F0: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    after_0:
    // 0x8003C7F4: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x8003C7F8: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8003C7FC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8003C800: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8003C804: lw          $s0, 0x0($t9)
    ctx->r16 = MEM_W(ctx->r25, 0X0);
    // 0x8003C808: jal         0x8006BD98
    // 0x8003C80C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    level_type(rdram, ctx);
        goto after_1;
    // 0x8003C80C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    after_1:
    // 0x8003C810: lb          $v1, 0x9($fp)
    ctx->r3 = MEM_B(ctx->r30, 0X9);
    // 0x8003C814: nop

    // 0x8003C818: bltz        $v1, L_8003C9B0
    if (SIGNED(ctx->r3) < 0) {
        // 0x8003C81C: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8003C9B0;
    }
    // 0x8003C81C: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8003C820: lw          $t1, 0x4C($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X4C);
    // 0x8003C824: lw          $a1, 0x10($s2)
    ctx->r5 = MEM_W(ctx->r18, 0X10);
    // 0x8003C828: lbu         $t2, 0x13($t1)
    ctx->r10 = MEM_BU(ctx->r9, 0X13);
    // 0x8003C82C: lui         $t0, 0x1
    ctx->r8 = S32(0X1 << 16);
    // 0x8003C830: slt         $at, $t2, $a1
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8003C834: beq         $at, $zero, L_8003C9AC
    if (ctx->r1 == 0) {
        // 0x8003C838: sllv        $a2, $t0, $v1
        ctx->r6 = S32(ctx->r8 << (ctx->r3 & 31));
            goto L_8003C9AC;
    }
    // 0x8003C838: sllv        $a2, $t0, $v1
    ctx->r6 = S32(ctx->r8 << (ctx->r3 & 31));
    // 0x8003C83C: andi        $t3, $v0, 0xFF
    ctx->r11 = ctx->r2 & 0XFF;
    // 0x8003C840: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8003C844: bne         $t3, $at, L_8003C854
    if (ctx->r11 != ctx->r1) {
        // 0x8003C848: and         $t4, $s0, $a2
        ctx->r12 = ctx->r16 & ctx->r6;
            goto L_8003C854;
    }
    // 0x8003C848: and         $t4, $s0, $a2
    ctx->r12 = ctx->r16 & ctx->r6;
    // 0x8003C84C: bne         $t4, $zero, L_8003C9B0
    if (ctx->r12 != 0) {
        // 0x8003C850: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_8003C9B0;
    }
    // 0x8003C850: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8003C854:
    // 0x8003C854: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003C858: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    // 0x8003C85C: sw          $a2, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r6;
    // 0x8003C860: jal         0x8001BA74
    // 0x8003C864: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    get_racer_objects(rdram, ctx);
        goto after_2;
    // 0x8003C864: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    after_2:
    // 0x8003C868: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C86C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8003C870: blez        $t5, L_8003C9AC
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8003C874: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8003C9AC;
    }
    // 0x8003C874: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003C878: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x8003C87C: addiu       $s6, $zero, 0xFF
    ctx->r22 = ADD32(0, 0XFF);
    // 0x8003C880: addiu       $s5, $zero, -0x1
    ctx->r21 = ADD32(0, -0X1);
L_8003C884:
    // 0x8003C884: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8003C888: lbu         $v1, 0x14($s2)
    ctx->r3 = MEM_BU(ctx->r18, 0X14);
    // 0x8003C88C: lw          $v0, 0x64($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X64);
    // 0x8003C890: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x8003C894: bne         $t7, $zero, L_8003C8AC
    if (ctx->r15 != 0) {
        // 0x8003C898: andi        $t8, $v1, 0x2
        ctx->r24 = ctx->r3 & 0X2;
            goto L_8003C8AC;
    }
    // 0x8003C898: andi        $t8, $v1, 0x2
    ctx->r24 = ctx->r3 & 0X2;
    // 0x8003C89C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8003C8A0: nop

    // 0x8003C8A4: beq         $s5, $t6, L_8003C8C4
    if (ctx->r21 == ctx->r14) {
        // 0x8003C8A8: nop
    
            goto L_8003C8C4;
    }
    // 0x8003C8A8: nop

L_8003C8AC:
    // 0x8003C8AC: bne         $t8, $zero, L_8003C99C
    if (ctx->r24 != 0) {
        // 0x8003C8B0: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C99C;
    }
    // 0x8003C8B0: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C8B4: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x8003C8B8: nop

    // 0x8003C8BC: beq         $s5, $t9, L_8003C99C
    if (ctx->r21 == ctx->r25) {
        // 0x8003C8C0: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C99C;
    }
    // 0x8003C8C0: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
L_8003C8C4:
    // 0x8003C8C4: lwc1        $f6, 0xC($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C8C8: lwc1        $f8, 0xC($s4)
    ctx->f8.u32l = MEM_W(ctx->r20, 0XC);
    // 0x8003C8CC: lwc1        $f10, 0x10($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003C8D0: sub.s       $f0, $f6, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8003C8D4: lwc1        $f16, 0x10($s4)
    ctx->f16.u32l = MEM_W(ctx->r20, 0X10);
    // 0x8003C8D8: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003C8DC: sub.s       $f2, $f10, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x8003C8E0: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003C8E4: lwc1        $f4, 0x14($s4)
    ctx->f4.u32l = MEM_W(ctx->r20, 0X14);
    // 0x8003C8E8: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003C8EC: sub.s       $f14, $f18, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x8003C8F0: mul.s       $f16, $f14, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003C8F4: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8003C8F8: jal         0x800C9AD0
    // 0x8003C8FC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x8003C8FC: add.s       $f12, $f10, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f16.fl;
    after_3:
    // 0x8003C900: c.lt.s      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.fl < ctx->f22.fl;
    // 0x8003C904: nop

    // 0x8003C908: bc1f        L_8003C99C
    if (!c1cs) {
        // 0x8003C90C: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C99C;
    }
    // 0x8003C90C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C910: lwc1        $f18, 0x0($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8003C914: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003C918: lwc1        $f8, 0x8($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X8);
    // 0x8003C91C: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8003C920: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003C924: lwc1        $f4, 0xC($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003C928: lw          $t4, 0x60($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X60);
    // 0x8003C92C: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8003C930: add.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x8003C934: add.s       $f0, $f18, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8003C938: c.lt.s      $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f0.fl < ctx->f20.fl;
    // 0x8003C93C: nop

    // 0x8003C940: bc1f        L_8003C99C
    if (!c1cs) {
        // 0x8003C944: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C99C;
    }
    // 0x8003C944: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C948: lbu         $t1, 0x49($s7)
    ctx->r9 = MEM_BU(ctx->r23, 0X49);
    // 0x8003C94C: lw          $t0, 0x4($s7)
    ctx->r8 = MEM_W(ctx->r23, 0X4);
    // 0x8003C950: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8003C954: addu        $v0, $t0, $t2
    ctx->r2 = ADD32(ctx->r8, ctx->r10);
    // 0x8003C958: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8003C95C: nop

    // 0x8003C960: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x8003C964: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8003C968: lbu         $a0, 0xB($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0XB);
    // 0x8003C96C: nop

    // 0x8003C970: beq         $s6, $a0, L_8003C980
    if (ctx->r22 == ctx->r4) {
        // 0x8003C974: nop
    
            goto L_8003C980;
    }
    // 0x8003C974: nop

    // 0x8003C978: jal         0x800C31EC
    // 0x8003C97C: nop

    set_current_text(rdram, ctx);
        goto after_4;
    // 0x8003C97C: nop

    after_4:
L_8003C980:
    // 0x8003C980: lbu         $v0, 0xC($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0XC);
    // 0x8003C984: nop

    // 0x8003C988: beq         $s6, $v0, L_8003C99C
    if (ctx->r22 == ctx->r2) {
        // 0x8003C98C: lw          $t7, 0x8C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X8C);
            goto L_8003C99C;
    }
    // 0x8003C98C: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
    // 0x8003C990: jal         0x80021400
    // 0x8003C994: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    func_80021400(rdram, ctx);
        goto after_5;
    // 0x8003C994: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    after_5:
    // 0x8003C998: lw          $t7, 0x8C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X8C);
L_8003C99C:
    // 0x8003C99C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8003C9A0: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8003C9A4: bne         $at, $zero, L_8003C884
    if (ctx->r1 != 0) {
        // 0x8003C9A8: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8003C884;
    }
    // 0x8003C9A8: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8003C9AC:
    // 0x8003C9AC: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_8003C9B0:
    // 0x8003C9B0: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8003C9B4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8003C9B8: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8003C9BC: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003C9C0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003C9C4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003C9C8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003C9CC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8003C9D0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8003C9D4: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8003C9D8: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8003C9DC: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x8003C9E0: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x8003C9E4: jr          $ra
    // 0x8003C9E8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8003C9E8: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void get_free_space(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076194: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x80076198: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007619C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800761A0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800761A4: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x800761A8: jal         0x800758DC
    // 0x800761AC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x800761AC: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x800761B0: bne         $v0, $zero, L_8007629C
    if (ctx->r2 != 0) {
        // 0x800761B4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8007629C;
    }
    // 0x800761B4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800761B8: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800761BC: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x800761C0: beq         $t6, $zero, L_80076218
    if (ctx->r14 == 0) {
        // 0x800761C4: subu        $t7, $t7, $s0
        ctx->r15 = SUB32(ctx->r15, ctx->r16);
            goto L_80076218;
    }
    // 0x800761C4: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x800761C8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x800761CC: addu        $t7, $t7, $s0
    ctx->r15 = ADD32(ctx->r15, ctx->r16);
    // 0x800761D0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800761D4: addiu       $t8, $t8, 0x4018
    ctx->r24 = ADD32(ctx->r24, 0X4018);
    // 0x800761D8: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800761DC: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x800761E0: jal         0x800CF3E0
    // 0x800761E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_1;
    // 0x800761E4: addiu       $a1, $sp, 0x28
    ctx->r5 = ADD32(ctx->r29, 0X28);
    after_1:
    // 0x800761E8: beq         $v0, $zero, L_80076208
    if (ctx->r2 == 0) {
        // 0x800761EC: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80076208;
    }
    // 0x800761EC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800761F0: jal         0x80075AEC
    // 0x800761F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_2;
    // 0x800761F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x800761F8: sll         $v0, $s0, 30
    ctx->r2 = S32(ctx->r16 << 30);
    // 0x800761FC: ori         $t9, $v0, 0x9
    ctx->r25 = ctx->r2 | 0X9;
    // 0x80076200: b           L_800762B8
    // 0x80076204: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
        goto L_800762B8;
    // 0x80076204: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80076208:
    // 0x80076208: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x8007620C: lw          $t1, 0x34($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X34);
    // 0x80076210: nop

    // 0x80076214: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_80076218:
    // 0x80076218: lw          $t2, 0x38($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X38);
    // 0x8007621C: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80076220: beq         $t2, $zero, L_800762A4
    if (ctx->r10 == 0) {
        // 0x80076224: subu        $t3, $t3, $s0
        ctx->r11 = SUB32(ctx->r11, ctx->r16);
            goto L_800762A4;
    }
    // 0x80076224: subu        $t3, $t3, $s0
    ctx->r11 = SUB32(ctx->r11, ctx->r16);
    // 0x80076228: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x8007622C: addu        $t3, $t3, $s0
    ctx->r11 = ADD32(ctx->r11, ctx->r16);
    // 0x80076230: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80076234: addiu       $t4, $t4, 0x4018
    ctx->r12 = ADD32(ctx->r12, 0X4018);
    // 0x80076238: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x8007623C: addu        $a0, $t3, $t4
    ctx->r4 = ADD32(ctx->r11, ctx->r12);
    // 0x80076240: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    // 0x80076244: jal         0x800D0390
    // 0x80076248: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    osPfsNumFiles_recomp(rdram, ctx);
        goto after_3;
    // 0x80076248: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x8007624C: beq         $v0, $zero, L_8007626C
    if (ctx->r2 == 0) {
        // 0x80076250: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8007626C;
    }
    // 0x80076250: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80076254: jal         0x80075AEC
    // 0x80076258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    start_reading_controller_data(rdram, ctx);
        goto after_4;
    // 0x80076258: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_4:
    // 0x8007625C: sll         $v0, $s0, 30
    ctx->r2 = S32(ctx->r16 << 30);
    // 0x80076260: ori         $t5, $v0, 0x9
    ctx->r13 = ctx->r2 | 0X9;
    // 0x80076264: b           L_800762B8
    // 0x80076268: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
        goto L_800762B8;
    // 0x80076268: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
L_8007626C:
    // 0x8007626C: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x80076270: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x80076274: slti        $at, $t6, 0x10
    ctx->r1 = SIGNED(ctx->r14) < 0X10 ? 1 : 0;
    // 0x80076278: bne         $at, $zero, L_8007628C
    if (ctx->r1 != 0) {
        // 0x8007627C: addiu       $t9, $zero, 0x10
        ctx->r25 = ADD32(0, 0X10);
            goto L_8007628C;
    }
    // 0x8007627C: addiu       $t9, $zero, 0x10
    ctx->r25 = ADD32(0, 0X10);
    // 0x80076280: lw          $t7, 0x38($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X38);
    // 0x80076284: b           L_800762A4
    // 0x80076288: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
        goto L_800762A4;
    // 0x80076288: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
L_8007628C:
    // 0x8007628C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x80076290: subu        $t0, $t9, $t8
    ctx->r8 = SUB32(ctx->r25, ctx->r24);
    // 0x80076294: b           L_800762A4
    // 0x80076298: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
        goto L_800762A4;
    // 0x80076298: sw          $t0, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r8;
L_8007629C:
    // 0x8007629C: sll         $t2, $s0, 30
    ctx->r10 = S32(ctx->r16 << 30);
    // 0x800762A0: or          $v1, $v0, $t2
    ctx->r3 = ctx->r2 | ctx->r10;
L_800762A4:
    // 0x800762A4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800762A8: jal         0x80075AEC
    // 0x800762AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_5;
    // 0x800762AC: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x800762B0: lw          $v0, 0x2C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X2C);
    // 0x800762B4: nop

L_800762B8:
    // 0x800762B8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800762BC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800762C0: jr          $ra
    // 0x800762C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800762C4: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void wavegen_register(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF634: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800BF638: addiu       $v1, $v1, 0x3190
    ctx->r3 = ADD32(ctx->r3, 0X3190);
    // 0x800BF63C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BF640: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800BF644: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800BF648: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800BF64C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800BF650: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x800BF654: beq         $t6, $zero, L_800BF9EC
    if (ctx->r14 == 0) {
        // 0x800BF658: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800BF9EC;
    }
    // 0x800BF658: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BF65C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BF660: lw          $t7, 0x3194($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3194);
    // 0x800BF664: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800BF668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF66C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BF670: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
L_800BF674:
    // 0x800BF674: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BF678: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BF67C: bne         $t9, $zero, L_800BF688
    if (ctx->r25 != 0) {
        // 0x800BF680: slti        $at, $v0, 0x20
        ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
            goto L_800BF688;
    }
    // 0x800BF680: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x800BF684: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
L_800BF688:
    // 0x800BF688: beq         $at, $zero, L_800BF698
    if (ctx->r1 == 0) {
        // 0x800BF68C: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800BF698;
    }
    // 0x800BF68C: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800BF690: beq         $a0, $zero, L_800BF674
    if (ctx->r4 == 0) {
        // 0x800BF694: nop
    
            goto L_800BF674;
    }
    // 0x800BF694: nop

L_800BF698:
    // 0x800BF698: beq         $a0, $zero, L_800BF9EC
    if (ctx->r4 == 0) {
        // 0x800BF69C: addiu       $v0, $v0, -0x1
        ctx->r2 = ADD32(ctx->r2, -0X1);
            goto L_800BF9EC;
    }
    // 0x800BF69C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800BF6A0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BF6A4: lw          $t3, 0x3194($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3194);
    // 0x800BF6A8: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x800BF6AC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BF6B0: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800BF6B4: addiu       $a0, $a0, 0x3188
    ctx->r4 = ADD32(ctx->r4, 0X3188);
    // 0x800BF6B8: sw          $a3, 0x0($t5)
    MEM_W(0X0, ctx->r13) = ctx->r7;
    // 0x800BF6BC: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800BF6C0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BF6C4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800BF6C8: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800BF6CC: lw          $t8, -0x6010($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6010);
    // 0x800BF6D0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF6D4: lwc1        $f0, -0x5F48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5F48);
    // 0x800BF6D8: beq         $t8, $zero, L_800BF6F4
    if (ctx->r24 == 0) {
        // 0x800BF6DC: lui         $t9, 0x8013
        ctx->r25 = S32(0X8013 << 16);
            goto L_800BF6F4;
    }
    // 0x800BF6DC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BF6E0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BF6E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BF6E8: nop

    // 0x800BF6EC: mul.s       $f0, $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800BF6F0: nop

L_800BF6F4:
    // 0x800BF6F4: lw          $t9, -0x5F30($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5F30);
    // 0x800BF6F8: sub.s       $f8, $f12, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x800BF6FC: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800BF700: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800BF704: cvt.s.w     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    ctx->f2.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BF708: lw          $a1, 0x318C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X318C);
    // 0x800BF70C: sub.s       $f10, $f8, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800BF710: nop

    // 0x800BF714: div.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BF718: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800BF71C: nop

    // 0x800BF720: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800BF724: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF728: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF72C: nop

    // 0x800BF730: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800BF734: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x800BF738: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800BF73C: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BF740: bne         $at, $zero, L_800BF750
    if (ctx->r1 != 0) {
        // 0x800BF744: nop
    
            goto L_800BF750;
    }
    // 0x800BF744: nop

    // 0x800BF748: jr          $ra
    // 0x800BF74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800BF74C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BF750:
    // 0x800BF750: add.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f14.fl;
    // 0x800BF754: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800BF758: nop

    // 0x800BF75C: div.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800BF760: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BF764: nop

    // 0x800BF768: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BF76C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF770: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF774: nop

    // 0x800BF778: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BF77C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800BF780: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BF784: bgez        $a2, L_800BF794
    if (SIGNED(ctx->r6) >= 0) {
        // 0x800BF788: slt         $at, $a2, $a1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_800BF794;
    }
    // 0x800BF788: slt         $at, $a2, $a1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800BF78C: jr          $ra
    // 0x800BF790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800BF790: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BF794:
    // 0x800BF794: bgez        $a0, L_800BF7A0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x800BF798: sll         $t4, $v0, 6
        ctx->r12 = S32(ctx->r2 << 6);
            goto L_800BF7A0;
    }
    // 0x800BF798: sll         $t4, $v0, 6
    ctx->r12 = S32(ctx->r2 << 6);
    // 0x800BF79C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800BF7A0:
    // 0x800BF7A0: bne         $at, $zero, L_800BF7AC
    if (ctx->r1 != 0) {
        // 0x800BF7A4: addiu       $t2, $zero, 0xFF
        ctx->r10 = ADD32(0, 0XFF);
            goto L_800BF7AC;
    }
    // 0x800BF7A4: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800BF7A8: addiu       $a2, $a1, -0x1
    ctx->r6 = ADD32(ctx->r5, -0X1);
L_800BF7AC:
    // 0x800BF7AC: slt         $at, $a2, $a0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BF7B0: bne         $at, $zero, L_800BF810
    if (ctx->r1 != 0) {
        // 0x800BF7B4: or          $a1, $a0, $zero
        ctx->r5 = ctx->r4 | 0;
            goto L_800BF810;
    }
    // 0x800BF7B4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BF7B8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BF7BC: addiu       $t1, $t1, 0x3184
    ctx->r9 = ADD32(ctx->r9, 0X3184);
    // 0x800BF7C0: addiu       $t0, $a2, 0x1
    ctx->r8 = ADD32(ctx->r6, 0X1);
L_800BF7C4:
    // 0x800BF7C4: lw          $t6, 0x0($t1)
    ctx->r14 = MEM_W(ctx->r9, 0X0);
    // 0x800BF7C8: sll         $t5, $a1, 3
    ctx->r13 = S32(ctx->r5 << 3);
    // 0x800BF7CC: addu        $a0, $t5, $t6
    ctx->r4 = ADD32(ctx->r13, ctx->r14);
    // 0x800BF7D0: lbu         $t7, 0x7($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X7);
    // 0x800BF7D4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BF7D8: bne         $t2, $t7, L_800BF808
    if (ctx->r10 != ctx->r15) {
        // 0x800BF7DC: nop
    
            goto L_800BF808;
    }
    // 0x800BF7DC: nop

    // 0x800BF7E0: lbu         $t8, 0x0($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X0);
    // 0x800BF7E4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800BF7E8: beq         $t2, $t8, L_800BF800
    if (ctx->r10 == ctx->r24) {
        // 0x800BF7EC: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800BF800;
    }
    // 0x800BF7EC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_800BF7F0:
    // 0x800BF7F0: lbu         $t9, 0x1($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X1);
    // 0x800BF7F4: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BF7F8: bne         $t2, $t9, L_800BF7F0
    if (ctx->r10 != ctx->r25) {
        // 0x800BF7FC: addiu       $a3, $a3, 0x1
        ctx->r7 = ADD32(ctx->r7, 0X1);
            goto L_800BF7F0;
    }
    // 0x800BF7FC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800BF800:
    // 0x800BF800: addu        $t3, $a0, $a2
    ctx->r11 = ADD32(ctx->r4, ctx->r6);
    // 0x800BF804: sb          $v0, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r2;
L_800BF808:
    // 0x800BF808: bne         $t0, $a1, L_800BF7C4
    if (ctx->r8 != ctx->r5) {
        // 0x800BF80C: nop
    
            goto L_800BF7C4;
    }
    // 0x800BF80C: nop

L_800BF810:
    // 0x800BF810: lwc1        $f16, 0x8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BF814: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800BF818: sub.s       $f18, $f16, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f14.fl;
    // 0x800BF81C: addu        $a1, $t4, $t5
    ctx->r5 = ADD32(ctx->r12, ctx->r13);
    // 0x800BF820: swc1        $f18, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f18.u32l;
    // 0x800BF824: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BF828: swc1        $f12, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f12.u32l;
    // 0x800BF82C: add.s       $f6, $f4, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f14.fl;
    // 0x800BF830: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x800BF834: swc1        $f6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f6.u32l;
    // 0x800BF838: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800BF83C: lwc1        $f8, 0x8($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800BF840: swc1        $f14, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f14.u32l;
    // 0x800BF844: sh          $v0, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r2;
    // 0x800BF848: swc1        $f10, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f10.u32l;
    // 0x800BF84C: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x800BF850: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800BF854: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BF858: sh          $t6, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r14;
    // 0x800BF85C: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x800BF860: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BF864: bne         $t7, $zero, L_800BF914
    if (ctx->r15 != 0) {
        // 0x800BF868: nop
    
            goto L_800BF914;
    }
    // 0x800BF868: nop

    // 0x800BF86C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800BF870: lwc1        $f0, 0x14($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BF874: lwc1        $f19, -0x6D58($at)
    ctx->f_odd[(19 - 1) * 2] = MEM_W(ctx->r1, -0X6D58);
    // 0x800BF878: lwc1        $f18, -0x6D54($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X6D54);
    // 0x800BF87C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x800BF880: mul.d       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f18.d);
    // 0x800BF884: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800BF888: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800BF88C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BF890: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BF894: nop

    // 0x800BF898: cvt.w.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_D(ctx->f4.d);
    // 0x800BF89C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BF8A0: nop

    // 0x800BF8A4: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800BF8A8: beq         $t9, $zero, L_800BF8F8
    if (ctx->r25 == 0) {
        // 0x800BF8AC: nop
    
            goto L_800BF8F8;
    }
    // 0x800BF8AC: nop

    // 0x800BF8B0: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800BF8B4: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800BF8B8: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800BF8BC: sub.d       $f6, $f4, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f6.d = ctx->f4.d - ctx->f6.d;
    // 0x800BF8C0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BF8C4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BF8C8: nop

    // 0x800BF8CC: cvt.w.d     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_D(ctx->f6.d);
    // 0x800BF8D0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BF8D4: nop

    // 0x800BF8D8: andi        $t9, $t9, 0x78
    ctx->r25 = ctx->r25 & 0X78;
    // 0x800BF8DC: bne         $t9, $zero, L_800BF8F0
    if (ctx->r25 != 0) {
        // 0x800BF8E0: nop
    
            goto L_800BF8F0;
    }
    // 0x800BF8E0: nop

    // 0x800BF8E4: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800BF8E8: b           L_800BF908
    // 0x800BF8EC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
        goto L_800BF908;
    // 0x800BF8EC: or          $t9, $t9, $at
    ctx->r25 = ctx->r25 | ctx->r1;
L_800BF8F0:
    // 0x800BF8F0: b           L_800BF908
    // 0x800BF8F4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
        goto L_800BF908;
    // 0x800BF8F4: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
L_800BF8F8:
    // 0x800BF8F8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800BF8FC: nop

    // 0x800BF900: bltz        $t9, L_800BF8F0
    if (SIGNED(ctx->r25) < 0) {
        // 0x800BF904: nop
    
            goto L_800BF8F0;
    }
    // 0x800BF904: nop

L_800BF908:
    // 0x800BF908: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BF90C: b           L_800BF9B4
    // 0x800BF910: sw          $t9, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r25;
        goto L_800BF9B4;
    // 0x800BF910: sw          $t9, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r25;
L_800BF914:
    // 0x800BF914: lwc1        $f11, -0x6D50($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X6D50);
    // 0x800BF918: lwc1        $f10, -0x6D4C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X6D4C);
    // 0x800BF91C: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x800BF920: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800BF924: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800BF928: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x800BF92C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800BF930: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BF934: nop

    // 0x800BF938: cvt.w.d     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_D(ctx->f16.d);
    // 0x800BF93C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BF940: nop

    // 0x800BF944: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800BF948: beq         $t4, $zero, L_800BF998
    if (ctx->r12 == 0) {
        // 0x800BF94C: nop
    
            goto L_800BF998;
    }
    // 0x800BF94C: nop

    // 0x800BF950: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x800BF954: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800BF958: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800BF95C: sub.d       $f18, $f16, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f16.d - ctx->f18.d;
    // 0x800BF960: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800BF964: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BF968: nop

    // 0x800BF96C: cvt.w.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.u32l = CVT_W_D(ctx->f18.d);
    // 0x800BF970: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BF974: nop

    // 0x800BF978: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x800BF97C: bne         $t4, $zero, L_800BF990
    if (ctx->r12 != 0) {
        // 0x800BF980: nop
    
            goto L_800BF990;
    }
    // 0x800BF980: nop

    // 0x800BF984: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800BF988: b           L_800BF9A8
    // 0x800BF98C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_800BF9A8;
    // 0x800BF98C: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_800BF990:
    // 0x800BF990: b           L_800BF9A8
    // 0x800BF994: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_800BF9A8;
    // 0x800BF994: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_800BF998:
    // 0x800BF998: mfc1        $t4, $f18
    ctx->r12 = (int32_t)ctx->f18.u32l;
    // 0x800BF99C: nop

    // 0x800BF9A0: bltz        $t4, L_800BF990
    if (SIGNED(ctx->r12) < 0) {
        // 0x800BF9A4: nop
    
            goto L_800BF990;
    }
    // 0x800BF9A4: nop

L_800BF9A8:
    // 0x800BF9A8: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800BF9AC: sw          $t4, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r12;
    // 0x800BF9B0: nop

L_800BF9B4:
    // 0x800BF9B4: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800BF9B8: lwc1        $f2, 0x18($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800BF9BC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BF9C0: lw          $v0, 0x20($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X20);
    // 0x800BF9C4: div.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f2.fl);
    // 0x800BF9C8: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x800BF9CC: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x800BF9D0: swc1        $f6, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f6.u32l;
    // 0x800BF9D4: lwc1        $f8, 0x1C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BF9D8: swc1        $f0, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->f0.u32l;
    // 0x800BF9DC: sb          $t5, 0x30($a1)
    MEM_B(0X30, ctx->r5) = ctx->r13;
    // 0x800BF9E0: sb          $t6, 0x31($a1)
    MEM_B(0X31, ctx->r5) = ctx->r14;
    // 0x800BF9E4: swc1        $f2, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->f2.u32l;
    // 0x800BF9E8: swc1        $f8, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->f8.u32l;
L_800BF9EC:
    // 0x800BF9EC: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
    // 0x800BF9F0: jr          $ra
    // 0x800BF9F4: nop

    return;
    // 0x800BF9F4: nop

;}
RECOMP_FUNC void obj_init_weather(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040800: lh          $t6, 0x8($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X8);
    // 0x80040804: nop

    // 0x80040808: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8004080C: nop

    // 0x80040810: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040814: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80040818: jr          $ra
    // 0x8004081C: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8004081C: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void asset_rom_offset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_asset_api(uint8_t*, recomp_context*, unsigned); if (dkr_legacy_asset_api(rdram, ctx, 2U)) return;
    // 0x80076EE8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80076EEC: lw          $v1, 0x4290($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X4290);
    // 0x80076EF0: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80076EF4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80076EF8: lui         $t9, 0xF
    ctx->r25 = S32(0XF << 16);
    // 0x80076EFC: sltu        $at, $t6, $a0
    ctx->r1 = ctx->r14 < ctx->r4 ? 1 : 0;
    // 0x80076F00: beq         $at, $zero, L_80076F10
    if (ctx->r1 == 0) {
        // 0x80076F04: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_80076F10;
    }
    // 0x80076F04: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80076F08: jr          $ra
    // 0x80076F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80076F0C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076F10:
    // 0x80076F10: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80076F14: addu        $a1, $t7, $v1
    ctx->r5 = ADD32(ctx->r15, ctx->r3);
    // 0x80076F18: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x80076F1C: addiu       $t9, $t9, -0x33D0
    ctx->r25 = ADD32(ctx->r25, -0X33D0);
    // 0x80076F20: addu        $a2, $t8, $a3
    ctx->r6 = ADD32(ctx->r24, ctx->r7);
    // 0x80076F24: addu        $v0, $a2, $t9
    ctx->r2 = ADD32(ctx->r6, ctx->r25);
    // 0x80076F28: jr          $ra
    // 0x80076F2C: nop

    return;
    // 0x80076F2C: nop

;}
RECOMP_FUNC void trackbg_render_flashy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80028050: addiu       $sp, $sp, -0x158
    ctx->r29 = ADD32(ctx->r29, -0X158);
    // 0x80028054: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80028058: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002805C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80028060: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80028064: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80028068: lw          $s1, -0x4F58($s1)
    ctx->r17 = MEM_W(ctx->r17, -0X4F58);
    // 0x8002806C: lw          $s0, -0x4F54($s0)
    ctx->r16 = MEM_W(ctx->r16, -0X4F54);
    // 0x80028070: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80028074: jal         0x80069D20
    // 0x80028078: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    cam_get_active_camera(rdram, ctx);
        goto after_0;
    // 0x80028078: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    after_0:
    // 0x8002807C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80028080: lw          $t6, -0x36E4($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36E4);
    // 0x80028084: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80028088: lw          $v1, 0xA4($t6)
    ctx->r3 = MEM_W(ctx->r14, 0XA4);
    // 0x8002808C: nop

    // 0x80028090: lbu         $t8, 0x1($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X1);
    // 0x80028094: lbu         $s3, 0x0($v1)
    ctx->r19 = MEM_BU(ctx->r3, 0X0);
    // 0x80028098: sll         $t9, $t8, 5
    ctx->r25 = S32(ctx->r24 << 5);
    // 0x8002809C: addiu       $t4, $t9, -0x1
    ctx->r12 = ADD32(ctx->r25, -0X1);
    // 0x800280A0: sw          $t4, 0x14C($sp)
    MEM_W(0X14C, ctx->r29) = ctx->r12;
    // 0x800280A4: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x800280A8: sll         $t7, $s3, 5
    ctx->r15 = S32(ctx->r19 << 5);
    // 0x800280AC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800280B0: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800280B4: addiu       $s3, $t7, -0x1
    ctx->r19 = ADD32(ctx->r15, -0X1);
    // 0x800280B8: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    // 0x800280BC: jal         0x800707C4
    // 0x800280C0: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    sins_f(rdram, ctx);
        goto after_1;
    // 0x800280C0: sw          $v1, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r3;
    after_1:
    // 0x800280C4: swc1        $f0, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->f0.u32l;
    // 0x800280C8: lh          $a0, 0x0($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X0);
    // 0x800280CC: nop

    // 0x800280D0: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x800280D4: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800280D8: jal         0x800707F8
    // 0x800280DC: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_2;
    // 0x800280DC: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_2:
    // 0x800280E0: lui         $at, 0x44A0
    ctx->r1 = S32(0X44A0 << 16);
    // 0x800280E4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800280E8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800280EC: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800280F0: lwc1        $f6, 0x10C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X10C);
    // 0x800280F4: lw          $a3, 0x74($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X74);
    // 0x800280F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800280FC: mul.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80028100: neg.s       $f18, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = -ctx->f12.fl;
    // 0x80028104: lw          $a0, -0x36E4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X36E4);
    // 0x80028108: add.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x8002810C: sub.s       $f10, $f18, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f2.fl;
    // 0x80028110: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x80028114: sub.s       $f8, $f12, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f2.fl;
    // 0x80028118: swc1        $f10, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f10.u32l;
    // 0x8002811C: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80028120: swc1        $f8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f8.u32l;
    // 0x80028124: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80028128: swc1        $f4, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->f4.u32l;
    // 0x8002812C: swc1        $f4, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->f4.u32l;
    // 0x80028130: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x80028134: add.s       $f4, $f12, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f12.fl + ctx->f2.fl;
    // 0x80028138: swc1        $f8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f8.u32l;
    // 0x8002813C: swc1        $f8, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->f8.u32l;
    // 0x80028140: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80028144: swc1        $f4, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f4.u32l;
    // 0x80028148: lwc1        $f4, 0x34($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8002814C: swc1        $f10, 0xB8($sp)
    MEM_W(0XB8, ctx->r29) = ctx->f10.u32l;
    // 0x80028150: swc1        $f10, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->f10.u32l;
    // 0x80028154: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x80028158: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x8002815C: add.s       $f8, $f12, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f12.fl + ctx->f12.fl;
    // 0x80028160: swc1        $f4, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f4.u32l;
    // 0x80028164: add.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f2.fl + ctx->f2.fl;
    // 0x80028168: swc1        $f8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f8.u32l;
    // 0x8002816C: swc1        $f4, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->f4.u32l;
    // 0x80028170: swc1        $f10, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->f10.u32l;
    // 0x80028174: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80028178: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8002817C: swc1        $f4, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f4.u32l;
    // 0x80028180: sub.s       $f8, $f2, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f2.fl - ctx->f10.fl;
    // 0x80028184: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x80028188: swc1        $f8, 0xCC($sp)
    MEM_W(0XCC, ctx->r29) = ctx->f8.u32l;
    // 0x8002818C: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x80028190: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x80028194: sub.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl - ctx->f16.fl;
    // 0x80028198: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x8002819C: swc1        $f8, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->f8.u32l;
    // 0x800281A0: sub.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800281A4: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    // 0x800281A8: add.s       $f10, $f12, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f12.fl + ctx->f16.fl;
    // 0x800281AC: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800281B0: swc1        $f10, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f10.u32l;
    // 0x800281B4: swc1        $f8, 0xD4($sp)
    MEM_W(0XD4, ctx->r29) = ctx->f8.u32l;
    // 0x800281B8: add.s       $f10, $f18, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x800281BC: add.s       $f8, $f4, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800281C0: swc1        $f10, 0xFC($sp)
    MEM_W(0XFC, ctx->r29) = ctx->f10.u32l;
    // 0x800281C4: swc1        $f8, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->f8.u32l;
    // 0x800281C8: lbu         $t9, 0x0($a3)
    ctx->r25 = MEM_BU(ctx->r7, 0X0);
    // 0x800281CC: lbu         $t5, 0xA0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0XA0);
    // 0x800281D0: sll         $t4, $t9, 4
    ctx->r12 = S32(ctx->r25 << 4);
    // 0x800281D4: multu       $t4, $t5
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800281D8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800281DC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x800281E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800281E4: lbu         $t6, 0x1($a3)
    ctx->r14 = MEM_BU(ctx->r7, 0X1);
    // 0x800281E8: mul.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x800281EC: lbu         $t8, 0xA1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0XA1);
    // 0x800281F0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x800281F4: swc1        $f8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f8.u32l;
    // 0x800281F8: mflo        $a1
    ctx->r5 = lo;
    // 0x800281FC: mtc1        $a1, $f10
    ctx->f10.u32l = ctx->r5;
    // 0x80028200: nop

    // 0x80028204: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80028208: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002820C: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x80028210: lwc1        $f10, 0x38($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80028214: lh          $t5, 0xA8($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XA8);
    // 0x80028218: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8002821C: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80028220: sra         $t6, $t5, 4
    ctx->r14 = S32(SIGNED(ctx->r13) >> 4);
    // 0x80028224: mflo        $a2
    ctx->r6 = lo;
    // 0x80028228: mul.s       $f10, $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f4.fl);
    // 0x8002822C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028230: nop

    // 0x80028234: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028238: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002823C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028240: nop

    // 0x80028244: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80028248: mtc1        $a2, $f10
    ctx->f10.u32l = ctx->r6;
    // 0x8002824C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028250: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80028254: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80028258: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8002825C: and         $v0, $t7, $s3
    ctx->r2 = ctx->r15 & ctx->r19;
    // 0x80028260: swc1        $f4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f4.u32l;
    // 0x80028264: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80028268: lh          $t5, 0xAA($a0)
    ctx->r13 = MEM_H(ctx->r4, 0XAA);
    // 0x8002826C: div.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80028270: lwc1        $f8, 0x14($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X14);
    // 0x80028274: lw          $t7, 0x14C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X14C);
    // 0x80028278: sra         $t4, $t5, 4
    ctx->r12 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8002827C: sh          $v0, 0x130($sp)
    MEM_H(0X130, ctx->r29) = ctx->r2;
    // 0x80028280: mul.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f4.fl);
    // 0x80028284: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x80028288: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002828C: nop

    // 0x80028290: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80028294: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028298: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002829C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800282A0: cvt.w.s     $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    ctx->f8.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800282A4: lwc1        $f10, 0x48($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800282A8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800282AC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800282B0: mul.s       $f14, $f4, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800282B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800282B8: addu        $t6, $t9, $t4
    ctx->r14 = ADD32(ctx->r25, ctx->r12);
    // 0x800282BC: and         $v1, $t6, $t7
    ctx->r3 = ctx->r14 & ctx->r15;
    // 0x800282C0: mul.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = MUL_S(ctx->f10.fl, ctx->f6.fl);
    // 0x800282C4: neg.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = -ctx->f14.fl;
    // 0x800282C8: swc1        $f14, 0xB4($sp)
    MEM_W(0XB4, ctx->r29) = ctx->f14.u32l;
    // 0x800282CC: swc1        $f14, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->f14.u32l;
    // 0x800282D0: sub.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800282D4: sh          $v1, 0x11C($sp)
    MEM_H(0X11C, ctx->r29) = ctx->r3;
    // 0x800282D8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800282DC: nop

    // 0x800282E0: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800282E4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800282E8: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x800282EC: sub.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f14.fl;
    // 0x800282F0: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x800282F4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800282F8: sh          $t6, 0x128($sp)
    MEM_H(0X128, ctx->r29) = ctx->r14;
    // 0x800282FC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80028300: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028304: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028308: nop

    // 0x8002830C: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80028310: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028314: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80028318: sub.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8002831C: addu        $t9, $a0, $v1
    ctx->r25 = ADD32(ctx->r4, ctx->r3);
    // 0x80028320: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80028324: sh          $t9, 0x114($sp)
    MEM_H(0X114, ctx->r29) = ctx->r25;
    // 0x80028328: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8002832C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028330: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028334: nop

    // 0x80028338: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002833C: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80028340: mfc1        $t8, $f4
    ctx->r24 = (int32_t)ctx->f4.u32l;
    // 0x80028344: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x80028348: addu        $t5, $t8, $v0
    ctx->r13 = ADD32(ctx->r24, ctx->r2);
    // 0x8002834C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028350: sh          $t5, 0x12A($sp)
    MEM_H(0X12A, ctx->r29) = ctx->r13;
    // 0x80028354: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028358: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002835C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028360: nop

    // 0x80028364: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80028368: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002836C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x80028370: add.s       $f8, $f14, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f14.fl + ctx->f0.fl;
    // 0x80028374: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x80028378: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002837C: sh          $t8, 0x116($sp)
    MEM_H(0X116, ctx->r29) = ctx->r24;
    // 0x80028380: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80028384: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028388: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002838C: nop

    // 0x80028390: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028394: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80028398: mfc1        $a1, $f4
    ctx->r5 = (int32_t)ctx->f4.u32l;
    // 0x8002839C: sub.s       $f10, $f14, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x800283A0: addu        $t6, $a1, $v0
    ctx->r14 = ADD32(ctx->r5, ctx->r2);
    // 0x800283A4: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800283A8: sh          $t6, 0x12C($sp)
    MEM_H(0X12C, ctx->r29) = ctx->r14;
    // 0x800283AC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800283B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800283B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800283B8: addu        $t6, $a0, $v0
    ctx->r14 = ADD32(ctx->r4, ctx->r2);
    // 0x800283BC: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800283C0: sh          $t6, 0x12E($sp)
    MEM_H(0X12E, ctx->r29) = ctx->r14;
    // 0x800283C4: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800283C8: addu        $t7, $a1, $v1
    ctx->r15 = ADD32(ctx->r5, ctx->r3);
    // 0x800283CC: add.s       $f12, $f0, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = ctx->f0.fl + ctx->f0.fl;
    // 0x800283D0: sh          $t7, 0x11A($sp)
    MEM_H(0X11A, ctx->r29) = ctx->r15;
    // 0x800283D4: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800283D8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800283DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800283E0: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x800283E4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800283E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800283EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800283F0: sh          $t4, 0x118($sp)
    MEM_H(0X118, ctx->r29) = ctx->r12;
    // 0x800283F4: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800283F8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800283FC: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80028400: add.s       $f2, $f14, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f2.fl = ctx->f14.fl + ctx->f14.fl;
    // 0x80028404: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x80028408: sub.s       $f10, $f0, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f2.fl;
    // 0x8002840C: sh          $t6, 0x132($sp)
    MEM_H(0X132, ctx->r29) = ctx->r14;
    // 0x80028410: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028414: nop

    // 0x80028418: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002841C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028420: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028424: nop

    // 0x80028428: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8002842C: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028430: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x80028434: sub.s       $f8, $f14, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f12.fl;
    // 0x80028438: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x8002843C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80028440: sh          $t4, 0x11E($sp)
    MEM_H(0X11E, ctx->r29) = ctx->r12;
    // 0x80028444: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80028448: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002844C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028450: nop

    // 0x80028454: cvt.w.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    ctx->f4.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80028458: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002845C: mfc1        $t5, $f4
    ctx->r13 = (int32_t)ctx->f4.u32l;
    // 0x80028460: neg.s       $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = -ctx->f2.fl;
    // 0x80028464: sub.s       $f6, $f10, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x80028468: addu        $t9, $t5, $v0
    ctx->r25 = ADD32(ctx->r13, ctx->r2);
    // 0x8002846C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80028470: sh          $t9, 0x134($sp)
    MEM_H(0X134, ctx->r29) = ctx->r25;
    // 0x80028474: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x80028478: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002847C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028480: nop

    // 0x80028484: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80028488: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8002848C: nop

    // 0x80028490: nop

    // 0x80028494: lwc1        $f14, 0xB4($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0XB4);
    // 0x80028498: lwc1        $f16, 0xAC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XAC);
    // 0x8002849C: add.s       $f4, $f14, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f14.fl + ctx->f12.fl;
    // 0x800284A0: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800284A4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800284A8: addu        $t5, $t8, $v1
    ctx->r13 = ADD32(ctx->r24, ctx->r3);
    // 0x800284AC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800284B0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800284B4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800284B8: sh          $t5, 0x120($sp)
    MEM_H(0X120, ctx->r29) = ctx->r13;
    // 0x800284BC: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800284C0: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x800284C4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800284C8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800284CC: add.s       $f2, $f16, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f2.fl = ctx->f16.fl + ctx->f16.fl;
    // 0x800284D0: addu        $t8, $t7, $v0
    ctx->r24 = ADD32(ctx->r15, ctx->r2);
    // 0x800284D4: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800284D8: sh          $t8, 0x136($sp)
    MEM_H(0X136, ctx->r29) = ctx->r24;
    // 0x800284DC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800284E0: addiu       $s3, $s3, -0x4F60
    ctx->r19 = ADD32(ctx->r19, -0X4F60);
    // 0x800284E4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800284E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800284EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800284F0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800284F4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800284F8: addiu       $a1, $a1, -0x4F5C
    ctx->r5 = ADD32(ctx->r5, -0X4F5C);
    // 0x800284FC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80028500: mfc1        $t6, $f8
    ctx->r14 = (int32_t)ctx->f8.u32l;
    // 0x80028504: sub.s       $f4, $f12, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f12.fl - ctx->f14.fl;
    // 0x80028508: addu        $t7, $t6, $v1
    ctx->r15 = ADD32(ctx->r14, ctx->r3);
    // 0x8002850C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80028510: sh          $t7, 0x122($sp)
    MEM_H(0X122, ctx->r29) = ctx->r15;
    // 0x80028514: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80028518: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002851C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028520: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80028524: cvt.w.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80028528: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002852C: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80028530: add.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl + ctx->f0.fl;
    // 0x80028534: addu        $t6, $t4, $v0
    ctx->r14 = ADD32(ctx->r12, ctx->r2);
    // 0x80028538: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8002853C: sh          $t6, 0x138($sp)
    MEM_H(0X138, ctx->r29) = ctx->r14;
    // 0x80028540: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x80028544: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028548: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002854C: nop

    // 0x80028550: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80028554: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x80028558: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8002855C: addu        $t4, $t9, $v1
    ctx->r12 = ADD32(ctx->r25, ctx->r3);
    // 0x80028560: jal         0x80068408
    // 0x80028564: sh          $t4, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r12;
    mtx_world_origin(rdram, ctx);
        goto after_3;
    // 0x80028564: sh          $t4, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r12;
    after_3:
    // 0x80028568: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002856C: lw          $a0, -0x36E4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X36E4);
    // 0x80028570: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80028574: lw          $t2, 0x74($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X74);
    // 0x80028578: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8002857C: beq         $t2, $v1, L_8002859C
    if (ctx->r10 == ctx->r3) {
        // 0x80028580: addiu       $a1, $zero, 0x1
        ctx->r5 = ADD32(0, 0X1);
            goto L_8002859C;
    }
    // 0x80028580: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80028584: lw          $v0, 0x78($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X78);
    // 0x80028588: nop

    // 0x8002858C: bne         $v0, $v1, L_800285A4
    if (ctx->r2 != ctx->r3) {
        // 0x80028590: nop
    
            goto L_800285A4;
    }
    // 0x80028590: nop

    // 0x80028594: b           L_800285A4
    // 0x80028598: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
        goto L_800285A4;
    // 0x80028598: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
L_8002859C:
    // 0x8002859C: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800285A0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_800285A4:
    // 0x800285A4: beq         $t2, $zero, L_800285C0
    if (ctx->r10 == 0) {
        // 0x800285A8: addiu       $a3, $zero, -0x100
        ctx->r7 = ADD32(0, -0X100);
            goto L_800285C0;
    }
    // 0x800285A8: addiu       $a3, $zero, -0x100
    ctx->r7 = ADD32(0, -0X100);
    // 0x800285AC: lw          $a3, 0x10($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X10);
    // 0x800285B0: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800285B4: and         $t6, $a3, $at
    ctx->r14 = ctx->r7 & ctx->r1;
    // 0x800285B8: lw          $a2, 0x10($t2)
    ctx->r6 = MEM_W(ctx->r10, 0X10);
    // 0x800285BC: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
L_800285C0:
    // 0x800285C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800285C4: jal         0x8007F594
    // 0x800285C8: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    gfx_init_basic_xlu(rdram, ctx);
        goto after_4;
    // 0x800285C8: sw          $t2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r10;
    after_4:
    // 0x800285CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800285D0: lw          $a1, -0x4EF0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4EF0);
    // 0x800285D4: lw          $a0, 0x74($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X74);
    // 0x800285D8: sll         $t7, $a1, 8
    ctx->r15 = S32(ctx->r5 << 8);
    // 0x800285DC: jal         0x8007B46C
    // 0x800285E0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_5;
    // 0x800285E0: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_5:
    // 0x800285E4: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800285E8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800285EC: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800285F0: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800285F4: lh          $a1, 0xA($v0)
    ctx->r5 = MEM_H(ctx->r2, 0XA);
    // 0x800285F8: lw          $t2, 0x7C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X7C);
    // 0x800285FC: andi        $t5, $a1, 0xFF
    ctx->r13 = ctx->r5 & 0XFF;
    // 0x80028600: sll         $t9, $t5, 16
    ctx->r25 = S32(ctx->r13 << 16);
    // 0x80028604: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x80028608: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x8002860C: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x80028610: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80028614: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80028618: lw          $t5, 0xC($v0)
    ctx->r13 = MEM_W(ctx->r2, 0XC);
    // 0x8002861C: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x80028620: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80028624: addu        $t9, $t5, $t1
    ctx->r25 = ADD32(ctx->r13, ctx->r9);
    // 0x80028628: addiu       $t3, $t3, -0x4F58
    ctx->r11 = ADD32(ctx->r11, -0X4F58);
    // 0x8002862C: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x80028630: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80028634: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80028638: addu        $t7, $t4, $t1
    ctx->r15 = ADD32(ctx->r12, ctx->r9);
    // 0x8002863C: andi        $t8, $t7, 0x6
    ctx->r24 = ctx->r15 & 0X6;
    // 0x80028640: ori         $t5, $t8, 0x40
    ctx->r13 = ctx->r24 | 0X40;
    // 0x80028644: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80028648: sw          $t6, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r14;
    // 0x8002864C: andi        $t9, $t5, 0xFF
    ctx->r25 = ctx->r13 & 0XFF;
    // 0x80028650: sll         $t6, $t9, 16
    ctx->r14 = S32(ctx->r25 << 16);
    // 0x80028654: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80028658: or          $t4, $t6, $at
    ctx->r12 = ctx->r14 | ctx->r1;
    // 0x8002865C: ori         $t7, $t4, 0xAA
    ctx->r15 = ctx->r12 | 0XAA;
    // 0x80028660: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80028664: lw          $t8, 0x0($t3)
    ctx->r24 = MEM_W(ctx->r11, 0X0);
    // 0x80028668: lui         $t6, 0x571
    ctx->r14 = S32(0X571 << 16);
    // 0x8002866C: addu        $t5, $t8, $t1
    ctx->r13 = ADD32(ctx->r24, ctx->r9);
    // 0x80028670: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x80028674: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x80028678: ori         $t6, $t6, 0x80
    ctx->r14 = ctx->r14 | 0X80;
    // 0x8002867C: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x80028680: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x80028684: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80028688: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8002868C: lw          $t4, -0x4F54($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X4F54);
    // 0x80028690: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x80028694: addu        $t7, $t4, $t1
    ctx->r15 = ADD32(ctx->r12, ctx->r9);
    // 0x80028698: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8002869C: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800286A0: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800286A4: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800286A8: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800286AC: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800286B0: beq         $t2, $zero, L_800286EC
    if (ctx->r10 == 0) {
        // 0x800286B4: sw          $t5, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r13;
            goto L_800286EC;
    }
    // 0x800286B4: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x800286B8: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800286BC: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x800286C0: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800286C4: sw          $t9, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r25;
    // 0x800286C8: sw          $t4, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r12;
    // 0x800286CC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800286D0: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800286D4: lui         $t8, 0xFB00
    ctx->r24 = S32(0XFB00 << 16);
    // 0x800286D8: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800286DC: sw          $t7, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r15;
    // 0x800286E0: addiu       $t5, $zero, -0x100
    ctx->r13 = ADD32(0, -0X100);
    // 0x800286E4: sw          $t5, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r13;
    // 0x800286E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_800286EC:
    // 0x800286EC: jal         0x8007B3D0
    // 0x800286F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    rendermode_reset(rdram, ctx);
        goto after_6;
    // 0x800286F0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_6:
    // 0x800286F4: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x800286F8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800286FC: lwc1        $f4, 0x10($s2)
    ctx->f4.u32l = MEM_W(ctx->r18, 0X10);
    // 0x80028700: addiu       $a0, $sp, 0xDC
    ctx->r4 = ADD32(ctx->r29, 0XDC);
    // 0x80028704: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80028708: addiu       $v0, $sp, 0xB8
    ctx->r2 = ADD32(ctx->r29, 0XB8);
    // 0x8002870C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80028710: addiu       $a3, $sp, 0xDC
    ctx->r7 = ADD32(ctx->r29, 0XDC);
    // 0x80028714: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80028718: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002871C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028720: addiu       $a2, $sp, 0xCC
    ctx->r6 = ADD32(ctx->r29, 0XCC);
    // 0x80028724: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80028728: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x8002872C: mfc1        $a1, $f8
    ctx->r5 = (int32_t)ctx->f8.u32l;
    // 0x80028730: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80028734: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80028738: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
L_8002873C:
    // 0x8002873C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x80028740: lwc1        $f10, 0xC($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0XC);
    // 0x80028744: sh          $a1, 0x2($s1)
    MEM_H(0X2, ctx->r17) = ctx->r5;
    // 0x80028748: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x8002874C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80028750: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x80028754: nop

    // 0x80028758: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8002875C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80028760: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80028764: nop

    // 0x80028768: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8002876C: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x80028770: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x80028774: sh          $t8, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r24;
    // 0x80028778: lwc1        $f10, 0x14($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8002877C: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80028780: sb          $v1, 0x6($s1)
    MEM_B(0X6, ctx->r17) = ctx->r3;
    // 0x80028784: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80028788: sb          $v1, 0x7($s1)
    MEM_B(0X7, ctx->r17) = ctx->r3;
    // 0x8002878C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80028790: sb          $v1, 0x8($s1)
    MEM_B(0X8, ctx->r17) = ctx->r3;
    // 0x80028794: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80028798: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002879C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800287A0: sltu        $at, $v0, $a2
    ctx->r1 = ctx->r2 < ctx->r6 ? 1 : 0;
    // 0x800287A4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800287A8: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x800287AC: mfc1        $t9, $f8
    ctx->r25 = (int32_t)ctx->f8.u32l;
    // 0x800287B0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800287B4: beq         $at, $zero, L_800287C4
    if (ctx->r1 == 0) {
        // 0x800287B8: sh          $t9, 0x4($s1)
        MEM_H(0X4, ctx->r17) = ctx->r25;
            goto L_800287C4;
    }
    // 0x800287B8: sh          $t9, 0x4($s1)
    MEM_H(0X4, ctx->r17) = ctx->r25;
    // 0x800287BC: b           L_800287C8
    // 0x800287C0: sb          $v1, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r3;
        goto L_800287C8;
    // 0x800287C0: sb          $v1, 0x9($s1)
    MEM_B(0X9, ctx->r17) = ctx->r3;
L_800287C4:
    // 0x800287C4: sb          $zero, 0x9($s1)
    MEM_B(0X9, ctx->r17) = 0;
L_800287C8:
    // 0x800287C8: sltu        $at, $v0, $a3
    ctx->r1 = ctx->r2 < ctx->r7 ? 1 : 0;
    // 0x800287CC: bne         $at, $zero, L_8002873C
    if (ctx->r1 != 0) {
        // 0x800287D0: addiu       $s1, $s1, 0xA
        ctx->r17 = ADD32(ctx->r17, 0XA);
            goto L_8002873C;
    }
    // 0x800287D0: addiu       $s1, $s1, 0xA
    ctx->r17 = ADD32(ctx->r17, 0XA);
    // 0x800287D4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800287D8: addiu       $v0, $v0, -0x36D4
    ctx->r2 = ADD32(ctx->r2, -0X36D4);
    // 0x800287DC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800287E0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    // 0x800287E4: addiu       $a1, $zero, 0x40
    ctx->r5 = ADD32(0, 0X40);
    // 0x800287E8: addiu       $a0, $sp, 0x114
    ctx->r4 = ADD32(ctx->r29, 0X114);
    // 0x800287EC: addiu       $v1, $sp, 0x128
    ctx->r3 = ADD32(ctx->r29, 0X128);
L_800287F0:
    // 0x800287F0: sb          $a1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r5;
    // 0x800287F4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800287F8: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x800287FC: sb          $t6, 0x1($s0)
    MEM_B(0X1, ctx->r16) = ctx->r14;
    // 0x80028800: lbu         $t4, 0x0($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X0);
    // 0x80028804: addiu       $v0, $v0, 0x6
    ctx->r2 = ADD32(ctx->r2, 0X6);
    // 0x80028808: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8002880C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80028810: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x80028814: addiu       $s0, $s0, 0x20
    ctx->r16 = ADD32(ctx->r16, 0X20);
    // 0x80028818: sh          $t5, -0x1C($s0)
    MEM_H(-0X1C, ctx->r16) = ctx->r13;
    // 0x8002881C: lbu         $t9, -0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X6);
    // 0x80028820: nop

    // 0x80028824: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80028828: addu        $t4, $a0, $t6
    ctx->r12 = ADD32(ctx->r4, ctx->r14);
    // 0x8002882C: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x80028830: nop

    // 0x80028834: sh          $t7, -0x1A($s0)
    MEM_H(-0X1A, ctx->r16) = ctx->r15;
    // 0x80028838: lbu         $t8, -0x5($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X5);
    // 0x8002883C: nop

    // 0x80028840: sb          $t8, -0x1E($s0)
    MEM_B(-0X1E, ctx->r16) = ctx->r24;
    // 0x80028844: lbu         $t5, -0x5($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X5);
    // 0x80028848: nop

    // 0x8002884C: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80028850: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80028854: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80028858: nop

    // 0x8002885C: sh          $t4, -0x18($s0)
    MEM_H(-0X18, ctx->r16) = ctx->r12;
    // 0x80028860: lbu         $t7, -0x5($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X5);
    // 0x80028864: nop

    // 0x80028868: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8002886C: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x80028870: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x80028874: nop

    // 0x80028878: sh          $t9, -0x16($s0)
    MEM_H(-0X16, ctx->r16) = ctx->r25;
    // 0x8002887C: lbu         $t6, -0x4($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X4);
    // 0x80028880: nop

    // 0x80028884: sb          $t6, -0x1D($s0)
    MEM_B(-0X1D, ctx->r16) = ctx->r14;
    // 0x80028888: lbu         $t4, -0x4($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X4);
    // 0x8002888C: nop

    // 0x80028890: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x80028894: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80028898: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x8002889C: nop

    // 0x800288A0: sh          $t5, -0x14($s0)
    MEM_H(-0X14, ctx->r16) = ctx->r13;
    // 0x800288A4: lbu         $t9, -0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X4);
    // 0x800288A8: nop

    // 0x800288AC: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x800288B0: addu        $t4, $a0, $t6
    ctx->r12 = ADD32(ctx->r4, ctx->r14);
    // 0x800288B4: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x800288B8: sb          $a1, -0x10($s0)
    MEM_B(-0X10, ctx->r16) = ctx->r5;
    // 0x800288BC: sh          $t7, -0x12($s0)
    MEM_H(-0X12, ctx->r16) = ctx->r15;
    // 0x800288C0: lbu         $t8, -0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X3);
    // 0x800288C4: nop

    // 0x800288C8: sb          $t8, -0xF($s0)
    MEM_B(-0XF, ctx->r16) = ctx->r24;
    // 0x800288CC: lbu         $t5, -0x3($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X3);
    // 0x800288D0: nop

    // 0x800288D4: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x800288D8: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x800288DC: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x800288E0: nop

    // 0x800288E4: sh          $t4, -0xC($s0)
    MEM_H(-0XC, ctx->r16) = ctx->r12;
    // 0x800288E8: lbu         $t7, -0x3($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X3);
    // 0x800288EC: nop

    // 0x800288F0: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x800288F4: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x800288F8: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x800288FC: nop

    // 0x80028900: sh          $t9, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r25;
    // 0x80028904: lbu         $t6, -0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X2);
    // 0x80028908: nop

    // 0x8002890C: sb          $t6, -0xE($s0)
    MEM_B(-0XE, ctx->r16) = ctx->r14;
    // 0x80028910: lbu         $t4, -0x2($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X2);
    // 0x80028914: nop

    // 0x80028918: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x8002891C: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80028920: lh          $t5, 0x0($t8)
    ctx->r13 = MEM_H(ctx->r24, 0X0);
    // 0x80028924: nop

    // 0x80028928: sh          $t5, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r13;
    // 0x8002892C: lbu         $t9, -0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0X2);
    // 0x80028930: nop

    // 0x80028934: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x80028938: addu        $t4, $a0, $t6
    ctx->r12 = ADD32(ctx->r4, ctx->r14);
    // 0x8002893C: lh          $t7, 0x0($t4)
    ctx->r15 = MEM_H(ctx->r12, 0X0);
    // 0x80028940: nop

    // 0x80028944: sh          $t7, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r15;
    // 0x80028948: lbu         $t8, -0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X1);
    // 0x8002894C: nop

    // 0x80028950: sb          $t8, -0xD($s0)
    MEM_B(-0XD, ctx->r16) = ctx->r24;
    // 0x80028954: lbu         $t5, -0x1($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X1);
    // 0x80028958: nop

    // 0x8002895C: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x80028960: addu        $t6, $v1, $t9
    ctx->r14 = ADD32(ctx->r3, ctx->r25);
    // 0x80028964: lh          $t4, 0x0($t6)
    ctx->r12 = MEM_H(ctx->r14, 0X0);
    // 0x80028968: nop

    // 0x8002896C: sh          $t4, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r12;
    // 0x80028970: lbu         $t7, -0x1($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0X1);
    // 0x80028974: nop

    // 0x80028978: sll         $t8, $t7, 1
    ctx->r24 = S32(ctx->r15 << 1);
    // 0x8002897C: addu        $t5, $a0, $t8
    ctx->r13 = ADD32(ctx->r4, ctx->r24);
    // 0x80028980: lh          $t9, 0x0($t5)
    ctx->r25 = MEM_H(ctx->r13, 0X0);
    // 0x80028984: bne         $a2, $a3, L_800287F0
    if (ctx->r6 != ctx->r7) {
        // 0x80028988: sh          $t9, -0x2($s0)
        MEM_H(-0X2, ctx->r16) = ctx->r25;
            goto L_800287F0;
    }
    // 0x80028988: sh          $t9, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r25;
    // 0x8002898C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028990: sw          $s1, -0x4F58($at)
    MEM_W(-0X4F58, ctx->r1) = ctx->r17;
    // 0x80028994: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80028998: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8002899C: sw          $s0, -0x4F54($at)
    MEM_W(-0X4F54, ctx->r1) = ctx->r16;
    // 0x800289A0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800289A4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800289A8: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800289AC: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800289B0: jr          $ra
    // 0x800289B4: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
    return;
    // 0x800289B4: addiu       $sp, $sp, 0x158
    ctx->r29 = ADD32(ctx->r29, 0X158);
;}
RECOMP_FUNC void draw_dialogue_text_unused(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C44C0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C44C4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C44C8: bltz        $a1, L_800C4500
    if (SIGNED(ctx->r5) < 0) {
        // 0x800C44CC: sw          $a1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r5;
            goto L_800C4500;
    }
    // 0x800C44CC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800C44D0: slti        $at, $a1, 0x8
    ctx->r1 = SIGNED(ctx->r5) < 0X8 ? 1 : 0;
    // 0x800C44D4: beq         $at, $zero, L_800C4500
    if (ctx->r1 == 0) {
        // 0x800C44D8: sll         $t7, $a1, 2
        ctx->r15 = S32(ctx->r5 << 2);
            goto L_800C4500;
    }
    // 0x800C44D8: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C44DC: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C44E0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800C44E4: lw          $t8, -0x5818($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5818);
    // 0x800C44E8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C44EC: addu        $t7, $t7, $a1
    ctx->r15 = ADD32(ctx->r15, ctx->r5);
    // 0x800C44F0: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C44F4: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x800C44F8: jal         0x800C45A4
    // 0x800C44FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    render_text_string(rdram, ctx);
        goto after_0;
    // 0x800C44FC: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
L_800C4500:
    // 0x800C4500: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C4504: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800C4508: jr          $ra
    // 0x800C450C: nop

    return;
    // 0x800C450C: nop

;}
RECOMP_FUNC void set_language(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EB94: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8009EB98: addiu       $t6, $zero, 0x0
    ctx->r14 = ADD32(0, 0X0);
    // 0x8009EB9C: addiu       $t7, $zero, 0x0
    ctx->r15 = ADD32(0, 0X0);
    // 0x8009EBA0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009EBA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009EBA8: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
    // 0x8009EBAC: beq         $a0, $at, L_8009EBD4
    if (ctx->r4 == ctx->r1) {
        // 0x8009EBB0: sw          $t6, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r14;
            goto L_8009EBD4;
    }
    // 0x8009EBB0: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8009EBB4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009EBB8: beq         $a0, $at, L_8009EBE8
    if (ctx->r4 == ctx->r1) {
        // 0x8009EBBC: addiu       $t0, $zero, 0x0
        ctx->r8 = ADD32(0, 0X0);
            goto L_8009EBE8;
    }
    // 0x8009EBBC: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x8009EBC0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009EBC4: beq         $a0, $at, L_8009EBF8
    if (ctx->r4 == ctx->r1) {
        // 0x8009EBC8: addiu       $t2, $zero, 0x0
        ctx->r10 = ADD32(0, 0X0);
            goto L_8009EBF8;
    }
    // 0x8009EBC8: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
    // 0x8009EBCC: b           L_8009EC04
    // 0x8009EBD0: nop

        goto L_8009EC04;
    // 0x8009EBD0: nop

L_8009EBD4:
    // 0x8009EBD4: addiu       $t8, $zero, 0x0
    ctx->r24 = ADD32(0, 0X0);
    // 0x8009EBD8: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x8009EBDC: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8009EBE0: b           L_8009EC04
    // 0x8009EBE4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
        goto L_8009EC04;
    // 0x8009EBE4: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
L_8009EBE8:
    // 0x8009EBE8: addiu       $t1, $zero, 0x8
    ctx->r9 = ADD32(0, 0X8);
    // 0x8009EBEC: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009EBF0: b           L_8009EC04
    // 0x8009EBF4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
        goto L_8009EC04;
    // 0x8009EBF4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
L_8009EBF8:
    // 0x8009EBF8: addiu       $t3, $zero, 0xC
    ctx->r11 = ADD32(0, 0XC);
    // 0x8009EBFC: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8009EC00: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
L_8009EC04:
    // 0x8009EC04: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009EC08: addiu       $v0, $v0, 0x6448
    ctx->r2 = ADD32(ctx->r2, 0X6448);
    // 0x8009EC0C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8009EC10: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8009EC14: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8009EC18: and         $t6, $t4, $at
    ctx->r14 = ctx->r12 & ctx->r1;
    // 0x8009EC1C: addiu       $at, $zero, -0xD
    ctx->r1 = ADD32(0, -0XD);
    // 0x8009EC20: lw          $t0, 0x18($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X18);
    // 0x8009EC24: lw          $t1, 0x1C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X1C);
    // 0x8009EC28: and         $t7, $t5, $at
    ctx->r15 = ctx->r13 & ctx->r1;
    // 0x8009EC2C: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8009EC30: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8009EC34: or          $t2, $t6, $t0
    ctx->r10 = ctx->r14 | ctx->r8;
    // 0x8009EC38: or          $t3, $t7, $t1
    ctx->r11 = ctx->r15 | ctx->r9;
    // 0x8009EC3C: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x8009EC40: jal         0x8007F900
    // 0x8009EC44: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    load_menu_text(rdram, ctx);
        goto after_0;
    // 0x8009EC44: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    after_0:
    // 0x8009EC48: jal         0x8006ECE0
    // 0x8009EC4C: nop

    mark_write_eeprom_settings(rdram, ctx);
        goto after_1;
    // 0x8009EC4C: nop

    after_1:
    // 0x8009EC50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009EC54: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8009EC58: jr          $ra
    // 0x8009EC5C: nop

    return;
    // 0x8009EC5C: nop

;}
RECOMP_FUNC void init_particle_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE530: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800AE534: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800AE538: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800AE53C: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800AE540: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800AE544: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800AE548: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800AE54C: jal         0x800AE490
    // 0x800AE550: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    free_particle_assets(rdram, ctx);
        goto after_0;
    // 0x800AE550: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x800AE554: jal         0x80076C58
    // 0x800AE558: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x800AE558: addiu       $a0, $zero, 0x28
    ctx->r4 = ADD32(0, 0X28);
    after_1:
    // 0x800AE55C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800AE560: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AE564: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AE568: addiu       $s2, $s2, 0x2CF0
    ctx->r18 = ADD32(ctx->r18, 0X2CF0);
    // 0x800AE56C: addiu       $a1, $a1, 0x2CE8
    ctx->r5 = ADD32(ctx->r5, 0X2CE8);
    // 0x800AE570: sll         $t6, $a2, 2
    ctx->r14 = S32(ctx->r6 << 2);
    // 0x800AE574: sw          $v0, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r2;
    // 0x800AE578: sw          $a2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r6;
    // 0x800AE57C: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800AE580: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x800AE584: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800AE588: beq         $a2, $t8, L_800AE5B0
    if (ctx->r6 == ctx->r24) {
        // 0x800AE58C: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800AE5B0;
    }
    // 0x800AE58C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AE590: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AE594:
    // 0x800AE594: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800AE598: addu        $t1, $a0, $t0
    ctx->r9 = ADD32(ctx->r4, ctx->r8);
    // 0x800AE59C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x800AE5A0: lw          $t2, 0x4($t1)
    ctx->r10 = MEM_W(ctx->r9, 0X4);
    // 0x800AE5A4: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x800AE5A8: bne         $a2, $t2, L_800AE594
    if (ctx->r6 != ctx->r10) {
        // 0x800AE5AC: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_800AE594;
    }
    // 0x800AE5AC: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
L_800AE5B0:
    // 0x800AE5B0: jal         0x80076C58
    // 0x800AE5B4: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    asset_table_load(rdram, ctx);
        goto after_2;
    // 0x800AE5B4: addiu       $a0, $zero, 0x29
    ctx->r4 = ADD32(0, 0X29);
    after_2:
    // 0x800AE5B8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800AE5BC: addiu       $a1, $a1, 0x2CE8
    ctx->r5 = ADD32(ctx->r5, 0X2CE8);
    // 0x800AE5C0: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x800AE5C4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AE5C8: addiu       $v1, $v1, 0x2CEC
    ctx->r3 = ADD32(ctx->r3, 0X2CEC);
    // 0x800AE5CC: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800AE5D0: blez        $t3, L_800AE610
    if (SIGNED(ctx->r11) <= 0) {
        // 0x800AE5D4: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800AE610;
    }
    // 0x800AE5D4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800AE5D8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800AE5DC:
    // 0x800AE5DC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800AE5E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800AE5E4: addu        $v0, $t4, $s0
    ctx->r2 = ADD32(ctx->r12, ctx->r16);
    // 0x800AE5E8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800AE5EC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AE5F0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x800AE5F4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800AE5F8: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800AE5FC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800AE600: slt         $at, $s1, $t8
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800AE604: bne         $at, $zero, L_800AE5DC
    if (ctx->r1 != 0) {
        // 0x800AE608: nop
    
            goto L_800AE5DC;
    }
    // 0x800AE608: nop

    // 0x800AE60C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AE610:
    // 0x800AE610: jal         0x80076C58
    // 0x800AE614: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    asset_table_load(rdram, ctx);
        goto after_3;
    // 0x800AE614: addiu       $a0, $zero, 0x2A
    ctx->r4 = ADD32(0, 0X2A);
    after_3:
    // 0x800AE618: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x800AE61C: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800AE620: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800AE624: addiu       $s3, $s3, 0x2CFC
    ctx->r19 = ADD32(ctx->r19, 0X2CFC);
    // 0x800AE628: addiu       $s2, $s2, 0x2CF4
    ctx->r18 = ADD32(ctx->r18, 0X2CF4);
    // 0x800AE62C: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x800AE630: sw          $v0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r2;
    // 0x800AE634: sw          $a2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r6;
    // 0x800AE638: addu        $t0, $v0, $t9
    ctx->r8 = ADD32(ctx->r2, ctx->r25);
    // 0x800AE63C: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x800AE640: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
    // 0x800AE644: beq         $a2, $t1, L_800AE66C
    if (ctx->r6 == ctx->r9) {
        // 0x800AE648: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800AE66C;
    }
    // 0x800AE648: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800AE64C: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
L_800AE650:
    // 0x800AE650: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800AE654: addu        $t4, $a0, $t3
    ctx->r12 = ADD32(ctx->r4, ctx->r11);
    // 0x800AE658: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800AE65C: lw          $t5, 0x4($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X4);
    // 0x800AE660: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x800AE664: bne         $a2, $t5, L_800AE650
    if (ctx->r6 != ctx->r13) {
        // 0x800AE668: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_800AE650;
    }
    // 0x800AE668: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
L_800AE66C:
    // 0x800AE66C: jal         0x80076C58
    // 0x800AE670: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x800AE670: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    after_4:
    // 0x800AE674: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AE678: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800AE67C: addiu       $s5, $s5, 0x2CF8
    ctx->r21 = ADD32(ctx->r21, 0X2CF8);
    // 0x800AE680: blez        $t6, L_800AE704
    if (SIGNED(ctx->r14) <= 0) {
        // 0x800AE684: sw          $v0, 0x0($s5)
        MEM_W(0X0, ctx->r21) = ctx->r2;
            goto L_800AE704;
    }
    // 0x800AE684: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x800AE688: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800AE68C: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
L_800AE690:
    // 0x800AE690: lw          $t7, 0x0($s3)
    ctx->r15 = MEM_W(ctx->r19, 0X0);
    // 0x800AE694: lw          $t9, 0x0($s5)
    ctx->r25 = MEM_W(ctx->r21, 0X0);
    // 0x800AE698: addu        $v0, $t7, $s0
    ctx->r2 = ADD32(ctx->r15, ctx->r16);
    // 0x800AE69C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800AE6A0: nop

    // 0x800AE6A4: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x800AE6A8: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x800AE6AC: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x800AE6B0: nop

    // 0x800AE6B4: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x800AE6B8: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x800AE6BC: nop

    // 0x800AE6C0: lw          $v1, 0x9C($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X9C);
    // 0x800AE6C4: nop

    // 0x800AE6C8: beq         $s4, $v1, L_800AE6F0
    if (ctx->r20 == ctx->r3) {
        // 0x800AE6CC: nop
    
            goto L_800AE6F0;
    }
    // 0x800AE6CC: nop

    // 0x800AE6D0: jal         0x8001E29C
    // 0x800AE6D4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    get_misc_asset(rdram, ctx);
        goto after_5;
    // 0x800AE6D4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    after_5:
    // 0x800AE6D8: lw          $t4, 0x0($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X0);
    // 0x800AE6DC: nop

    // 0x800AE6E0: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x800AE6E4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800AE6E8: nop

    // 0x800AE6EC: sw          $v0, 0x9C($t6)
    MEM_W(0X9C, ctx->r14) = ctx->r2;
L_800AE6F0:
    // 0x800AE6F0: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AE6F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800AE6F8: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800AE6FC: bne         $at, $zero, L_800AE690
    if (ctx->r1 != 0) {
        // 0x800AE700: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800AE690;
    }
    // 0x800AE700: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
L_800AE704:
    // 0x800AE704: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800AE708: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800AE70C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800AE710: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800AE714: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800AE718: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800AE71C: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800AE720: jr          $ra
    // 0x800AE724: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x800AE724: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void get_player_character(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009C280: bltz        $a0, L_8009C290
    if (SIGNED(ctx->r4) < 0) {
        // 0x8009C284: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_8009C290;
    }
    // 0x8009C284: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x8009C288: bne         $at, $zero, L_8009C298
    if (ctx->r1 != 0) {
        // 0x8009C28C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8009C298;
    }
    // 0x8009C28C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
L_8009C290:
    // 0x8009C290: jr          $ra
    // 0x8009C294: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8009C294: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009C298:
    // 0x8009C298: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x8009C29C: lb          $t6, 0x63D4($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X63D4);
    // 0x8009C2A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009C2A4: bne         $t6, $zero, L_8009C2B4
    if (ctx->r14 != 0) {
        // 0x8009C2A8: addu        $v0, $v0, $a0
        ctx->r2 = ADD32(ctx->r2, ctx->r4);
            goto L_8009C2B4;
    }
    // 0x8009C2A8: addu        $v0, $v0, $a0
    ctx->r2 = ADD32(ctx->r2, ctx->r4);
    // 0x8009C2AC: jr          $ra
    // 0x8009C2B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8009C2B0: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8009C2B4:
    // 0x8009C2B4: lb          $v0, 0x63E8($v0)
    ctx->r2 = MEM_B(ctx->r2, 0X63E8);
    // 0x8009C2B8: nop

    // 0x8009C2BC: jr          $ra
    // 0x8009C2C0: nop

    return;
    // 0x8009C2C0: nop

;}
RECOMP_FUNC void dialogue_close(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5620: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C5624: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5628: lw          $t6, -0x5818($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5818);
    // 0x800C562C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5630: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C5634: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5638: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C563C: nop

    // 0x800C5640: andi        $t9, $t8, 0x7FFF
    ctx->r25 = ctx->r24 & 0X7FFF;
    // 0x800C5644: jr          $ra
    // 0x800C5648: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C5648: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void hud_render_general(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A8474: addiu       $sp, $sp, -0x160
    ctx->r29 = ADD32(ctx->r29, -0X160);
    // 0x800A8478: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800A847C: sw          $a0, 0x160($sp)
    MEM_W(0X160, ctx->r29) = ctx->r4;
    // 0x800A8480: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x800A8484: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x800A8488: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x800A848C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x800A8490: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x800A8494: sw          $a1, 0x164($sp)
    MEM_W(0X164, ctx->r29) = ctx->r5;
    // 0x800A8498: sw          $a2, 0x168($sp)
    MEM_W(0X168, ctx->r29) = ctx->r6;
    // 0x800A849C: sw          $a3, 0x16C($sp)
    MEM_W(0X16C, ctx->r29) = ctx->r7;
    extern void dkr_hud_general_pass_begin(uint8_t*, recomp_context*); dkr_hud_general_pass_begin(rdram, ctx);
    // 0x800A84A0: jal         0x800A0BD4
    // 0x800A84A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    hud_audio_update(rdram, ctx);
        goto after_0;
    // 0x800A84A4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    after_0:
    // 0x800A84A8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A84AC: addiu       $s0, $s0, 0x6CD8
    ctx->r16 = ADD32(ctx->r16, 0X6CD8);
    // 0x800A84B0: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800A84B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A84B8: sb          $zero, 0x1($t6)
    MEM_B(0X1, ctx->r14) = 0;
    // 0x800A84BC: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A84C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A84C4: sb          $zero, 0x17($t7)
    MEM_B(0X17, ctx->r15) = 0;
    // 0x800A84C8: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A84CC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A84D0: sb          $zero, 0x8($t8)
    MEM_B(0X8, ctx->r24) = 0;
    // 0x800A84D4: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x800A84D8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A84DC: sb          $zero, 0x11($t9)
    MEM_B(0X11, ctx->r25) = 0;
    // 0x800A84E0: lb          $t2, 0x6CD3($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X6CD3);
    // 0x800A84E4: sw          $zero, 0x7180($at)
    MEM_W(0X7180, ctx->r1) = 0;
    // 0x800A84E8: andi        $t3, $t2, 0x2
    ctx->r11 = ctx->r10 & 0X2;
    // 0x800A84EC: beq         $t3, $zero, L_800A8568
    if (ctx->r11 == 0) {
        // 0x800A84F0: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_800A8568;
    }
    // 0x800A84F0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A84F4: lb          $t4, 0x6CD0($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X6CD0);
    // 0x800A84F8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A84FC: mtc1        $t4, $f4
    ctx->f4.u32l = ctx->r12;
    // 0x800A8500: lbu         $t5, 0x718B($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X718B);
    // 0x800A8504: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8508: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800A850C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800A8510: mtc1        $t5, $f10
    ctx->f10.u32l = ctx->r13;
    // 0x800A8514: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800A8518: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A851C: bgez        $t5, L_800A8530
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800A8520: cvt.s.w     $f16, $f10
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
            goto L_800A8530;
    }
    // 0x800A8520: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A8524: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A8528: nop

    // 0x800A852C: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800A8530:
    // 0x800A8530: nop

    // 0x800A8534: div.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800A8538: sub.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f0.fl - ctx->f4.fl;
    // 0x800A853C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A8540: nop

    // 0x800A8544: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A8548: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A854C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8550: nop

    // 0x800A8554: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A8558: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800A855C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A8560: b           L_800A856C
    // 0x800A8564: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
        goto L_800A856C;
    // 0x800A8564: sw          $t7, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r15;
L_800A8568:
    // 0x800A8568: sw          $t8, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r24;
L_800A856C:
    // 0x800A856C: lw          $t9, 0x6CF8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CF8);
    // 0x800A8570: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A8574: blez        $t9, L_800A86D8
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800A8578: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800A86D8;
    }
    // 0x800A8578: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800A857C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8580: addiu       $a1, $a1, 0x6CF4
    ctx->r5 = ADD32(ctx->r5, 0X6CF4);
    // 0x800A8584: ori         $s3, $zero, 0xC000
    ctx->r19 = 0 | 0XC000;
    // 0x800A8588: addiu       $s2, $zero, 0x28
    ctx->r18 = ADD32(0, 0X28);
L_800A858C:
    // 0x800A858C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A8590: nop

    // 0x800A8594: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800A8598: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800A859C: nop

    // 0x800A85A0: beq         $t4, $zero, L_800A86C0
    if (ctx->r12 == 0) {
        // 0x800A85A4: nop
    
            goto L_800A86C0;
    }
    // 0x800A85A4: nop

    // 0x800A85A8: beq         $v1, $s2, L_800A86C0
    if (ctx->r3 == ctx->r18) {
        // 0x800A85AC: nop
    
            goto L_800A86C0;
    }
    // 0x800A85AC: nop

    // 0x800A85B0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A85B4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A85B8: addu        $v0, $t5, $v1
    ctx->r2 = ADD32(ctx->r13, ctx->r3);
    // 0x800A85BC: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800A85C0: nop

    // 0x800A85C4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x800A85C8: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x800A85CC: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A85D0: nop

    // 0x800A85D4: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800A85D8: lbu         $t2, 0x0($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0X0);
    // 0x800A85DC: nop

    // 0x800A85E0: slti        $at, $t2, 0x3D
    ctx->r1 = SIGNED(ctx->r10) < 0X3D ? 1 : 0;
    // 0x800A85E4: bne         $at, $zero, L_800A86C0
    if (ctx->r1 != 0) {
        // 0x800A85E8: nop
    
            goto L_800A86C0;
    }
    // 0x800A85E8: nop

    // 0x800A85EC: lw          $t3, 0x6CF0($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6CF0);
    // 0x800A85F0: sll         $t4, $v1, 1
    ctx->r12 = S32(ctx->r3 << 1);
    // 0x800A85F4: addu        $t5, $t3, $t4
    ctx->r13 = ADD32(ctx->r11, ctx->r12);
    // 0x800A85F8: lh          $v0, 0x0($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X0);
    // 0x800A85FC: nop

    // 0x800A8600: andi        $t6, $v0, 0xC000
    ctx->r14 = ctx->r2 & 0XC000;
    // 0x800A8604: bne         $s3, $t6, L_800A8630
    if (ctx->r19 != ctx->r14) {
        // 0x800A8608: andi        $t9, $v0, 0x8000
        ctx->r25 = ctx->r2 & 0X8000;
            goto L_800A8630;
    }
    // 0x800A8608: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x800A860C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A8610: nop

    // 0x800A8614: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800A8618: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800A861C: jal         0x8007B2BC
    // 0x800A8620: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    tex_free(rdram, ctx);
        goto after_1;
    // 0x800A8620: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_1:
    // 0x800A8624: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8628: b           L_800A86A8
    // 0x800A862C: nop

        goto L_800A86A8;
    // 0x800A862C: nop

L_800A8630:
    // 0x800A8630: beq         $t9, $zero, L_800A865C
    if (ctx->r25 == 0) {
        // 0x800A8634: andi        $t4, $v0, 0x4000
        ctx->r12 = ctx->r2 & 0X4000;
            goto L_800A865C;
    }
    // 0x800A8634: andi        $t4, $v0, 0x4000
    ctx->r12 = ctx->r2 & 0X4000;
    // 0x800A8638: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A863C: nop

    // 0x800A8640: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x800A8644: lw          $a0, 0x0($t3)
    ctx->r4 = MEM_W(ctx->r11, 0X0);
    // 0x800A8648: jal         0x8007CCB0
    // 0x800A864C: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    sprite_free(rdram, ctx);
        goto after_2;
    // 0x800A864C: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_2:
    // 0x800A8650: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8654: b           L_800A86A8
    // 0x800A8658: nop

        goto L_800A86A8;
    // 0x800A8658: nop

L_800A865C:
    // 0x800A865C: beq         $t4, $zero, L_800A8688
    if (ctx->r12 == 0) {
        // 0x800A8660: nop
    
            goto L_800A8688;
    }
    // 0x800A8660: nop

    // 0x800A8664: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800A8668: nop

    // 0x800A866C: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x800A8670: lw          $a0, 0x0($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X0);
    // 0x800A8674: jal         0x8000FFB8
    // 0x800A8678: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    free_object(rdram, ctx);
        goto after_3;
    // 0x800A8678: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_3:
    // 0x800A867C: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A8680: b           L_800A86A8
    // 0x800A8684: nop

        goto L_800A86A8;
    // 0x800A8684: nop

L_800A8688:
    // 0x800A8688: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800A868C: nop

    // 0x800A8690: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800A8694: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800A8698: jal         0x8005FF40
    // 0x800A869C: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    free_3d_model(rdram, ctx);
        goto after_4;
    // 0x800A869C: sw          $v1, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r3;
    after_4:
    // 0x800A86A0: lw          $v1, 0x144($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X144);
    // 0x800A86A4: nop

L_800A86A8:
    // 0x800A86A8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A86AC: lw          $t9, 0x6CF4($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6CF4);
    // 0x800A86B0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A86B4: addu        $t2, $t9, $s1
    ctx->r10 = ADD32(ctx->r25, ctx->r17);
    // 0x800A86B8: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
    // 0x800A86BC: addiu       $a1, $a1, 0x6CF4
    ctx->r5 = ADD32(ctx->r5, 0X6CF4);
L_800A86C0:
    // 0x800A86C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A86C4: lw          $t3, 0x6CF8($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6CF8);
    // 0x800A86C8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A86CC: slt         $at, $v1, $t3
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x800A86D0: bne         $at, $zero, L_800A858C
    if (ctx->r1 != 0) {
        // 0x800A86D4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_800A858C;
    }
    // 0x800A86D4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_800A86D8:
    // 0x800A86D8: jal         0x8006BDB0
    // 0x800A86DC: nop

    level_header(rdram, ctx);
        goto after_5;
    // 0x800A86DC: nop

    after_5:
    // 0x800A86E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A86E4: sw          $v0, 0x6D60($at)
    MEM_W(0X6D60, ctx->r1) = ctx->r2;
    // 0x800A86E8: jal         0x8001BA90
    // 0x800A86EC: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    get_racer_objects_by_port(rdram, ctx);
        goto after_6;
    // 0x800A86EC: addiu       $a0, $sp, 0x140
    ctx->r4 = ADD32(ctx->r29, 0X140);
    after_6:
    // 0x800A86F0: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x800A86F4: sw          $v0, 0x150($sp)
    MEM_W(0X150, ctx->r29) = ctx->r2;
    // 0x800A86F8: lw          $t5, 0x0($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X0);
    // 0x800A86FC: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800A8700: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A8704: addiu       $s4, $s4, 0x6CFC
    ctx->r20 = ADD32(ctx->r20, 0X6CFC);
    // 0x800A8708: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800A870C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800A8710: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800A8714: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A8718: sw          $t7, 0x6D00($at)
    MEM_W(0X6D00, ctx->r1) = ctx->r15;
    // 0x800A871C: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800A8720: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A8724: lw          $t2, 0x6D60($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D60);
    // 0x800A8728: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A872C: sw          $t9, 0x6D04($at)
    MEM_W(0X6D04, ctx->r1) = ctx->r25;
    // 0x800A8730: lb          $v1, 0x4C($t2)
    ctx->r3 = MEM_B(ctx->r10, 0X4C);
    // 0x800A8734: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800A8738: bne         $v1, $at, L_800A8A8C
    if (ctx->r3 != ctx->r1) {
        // 0x800A873C: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800A8A8C;
    }
    // 0x800A873C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A8740: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8744: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x800A8748: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A874C: bne         $v1, $at, L_800A8788
    if (ctx->r3 != ctx->r1) {
        // 0x800A8750: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_800A8788;
    }
    // 0x800A8750: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A8754: lw          $t3, 0x6D0C($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6D0C);
    // 0x800A8758: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800A875C: addu        $t4, $t4, $t3
    ctx->r12 = ADD32(ctx->r12, ctx->r11);
    // 0x800A8760: lb          $t4, 0x27A4($t4)
    ctx->r12 = MEM_B(ctx->r12, 0X27A4);
    // 0x800A8764: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8768: bne         $t4, $zero, L_800A878C
    if (ctx->r12 != 0) {
        // 0x800A876C: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A878C;
    }
    // 0x800A876C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A8770: jal         0x800A14F0
    // 0x800A8774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_draw_eggs(rdram, ctx);
        goto after_7;
    // 0x800A8774: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_7:
    // 0x800A8778: jal         0x8007B3D0
    // 0x800A877C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_8;
    // 0x800A877C: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_8:
    // 0x800A8780: b           L_800A96B4
    // 0x800A8784: nop

        goto L_800A96B4;
    // 0x800A8784: nop

L_800A8788:
    // 0x800A8788: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800A878C:
    // 0x800A878C: bne         $v1, $at, L_800A8A80
    if (ctx->r3 != ctx->r1) {
        // 0x800A8790: nop
    
            goto L_800A8A80;
    }
    // 0x800A8790: nop

    // 0x800A8794: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x800A8798: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A879C: blez        $t5, L_800A88A8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A87A0: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A88A8;
    }
    // 0x800A87A0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A87A4: andi        $t0, $t5, 0x3
    ctx->r8 = ctx->r13 & 0X3;
    // 0x800A87A8: beq         $t0, $zero, L_800A87F8
    if (ctx->r8 == 0) {
        // 0x800A87AC: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_800A87F8;
    }
    // 0x800A87AC: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800A87B0: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800A87B4: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x800A87B8: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A87BC:
    // 0x800A87BC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A87C0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A87C4: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A87C8: nop

    // 0x800A87CC: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A87D0: nop

    // 0x800A87D4: bne         $s3, $t8, L_800A87E0
    if (ctx->r19 != ctx->r24) {
        // 0x800A87D8: nop
    
            goto L_800A87E0;
    }
    // 0x800A87D8: nop

    // 0x800A87DC: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A87E0:
    // 0x800A87E0: bne         $a3, $a1, L_800A87BC
    if (ctx->r7 != ctx->r5) {
        // 0x800A87E4: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A87BC;
    }
    // 0x800A87E4: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A87E8: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800A87EC: nop

    // 0x800A87F0: beq         $a1, $t9, L_800A88A8
    if (ctx->r5 == ctx->r25) {
        // 0x800A87F4: nop
    
            goto L_800A88A8;
    }
    // 0x800A87F4: nop

L_800A87F8:
    // 0x800A87F8: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800A87FC: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x800A8800: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A8804: addu        $a3, $t3, $v0
    ctx->r7 = ADD32(ctx->r11, ctx->r2);
    // 0x800A8808: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x800A880C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A8810:
    // 0x800A8810: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800A8814: nop

    // 0x800A8818: lw          $v1, 0x64($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X64);
    // 0x800A881C: nop

    // 0x800A8820: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800A8824: nop

    // 0x800A8828: bne         $s3, $t6, L_800A8834
    if (ctx->r19 != ctx->r14) {
        // 0x800A882C: nop
    
            goto L_800A8834;
    }
    // 0x800A882C: nop

    // 0x800A8830: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8834:
    // 0x800A8834: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800A8838: nop

    // 0x800A883C: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A8840: nop

    // 0x800A8844: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A8848: nop

    // 0x800A884C: bne         $s3, $t8, L_800A8858
    if (ctx->r19 != ctx->r24) {
        // 0x800A8850: nop
    
            goto L_800A8858;
    }
    // 0x800A8850: nop

    // 0x800A8854: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A8858:
    // 0x800A8858: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800A885C: nop

    // 0x800A8860: lw          $v1, 0x64($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X64);
    // 0x800A8864: nop

    // 0x800A8868: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800A886C: nop

    // 0x800A8870: bne         $s3, $t2, L_800A887C
    if (ctx->r19 != ctx->r10) {
        // 0x800A8874: nop
    
            goto L_800A887C;
    }
    // 0x800A8874: nop

    // 0x800A8878: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A887C:
    // 0x800A887C: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800A8880: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A8884: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x800A8888: nop

    // 0x800A888C: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x800A8890: nop

    // 0x800A8894: bne         $s3, $t4, L_800A88A0
    if (ctx->r19 != ctx->r12) {
        // 0x800A8898: nop
    
            goto L_800A88A0;
    }
    // 0x800A8898: nop

    // 0x800A889C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A88A0:
    // 0x800A88A0: bne         $a0, $a3, L_800A8810
    if (ctx->r4 != ctx->r7) {
        // 0x800A88A4: nop
    
            goto L_800A8810;
    }
    // 0x800A88A4: nop

L_800A88A8:
    // 0x800A88A8: beq         $a2, $zero, L_800A8A80
    if (ctx->r6 == 0) {
        // 0x800A88AC: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_800A8A80;
    }
    // 0x800A88AC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A88B0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A88B4: addiu       $s2, $s2, 0x6CDC
    ctx->r18 = ADD32(ctx->r18, 0X6CDC);
    // 0x800A88B8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A88BC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A88C0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A88C4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A88C8: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A88CC: lwc1        $f16, 0x650($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A88D0: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A88D4: lwc1        $f6, 0x66C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A88D8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A88DC: lwc1        $f18, 0x670($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A88E0: mfc1        $s0, $f8
    ctx->r16 = (int32_t)ctx->f8.u32l;
    // 0x800A88E4: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A88E8: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A88EC: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A88F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A88F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A88F8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A88FC: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A8900: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A8904: mfc1        $s1, $f4
    ctx->r17 = (int32_t)ctx->f4.u32l;
    // 0x800A8908: nop

    // 0x800A890C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A8910: nop

    // 0x800A8914: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A8918: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A891C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8920: nop

    // 0x800A8924: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A8928: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A892C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A8930: nop

    // 0x800A8934: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A8938: nop

    // 0x800A893C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A8940: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8944: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8948: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800A894C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A8950: lui         $at, 0x435D
    ctx->r1 = S32(0X435D << 16);
    // 0x800A8954: swc1        $f16, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f16.u32l;
    // 0x800A8958: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A895C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A8960: lui         $at, 0x4345
    ctx->r1 = S32(0X4345 << 16);
    // 0x800A8964: swc1        $f4, 0x66C($t9)
    MEM_W(0X66C, ctx->r25) = ctx->f4.u32l;
    // 0x800A8968: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A896C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A8970: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800A8974: swc1        $f6, 0x670($t2)
    MEM_W(0X670, ctx->r10) = ctx->f6.u32l;
    // 0x800A8978: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A897C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A8980: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8984: swc1        $f10, 0x650($t3)
    MEM_W(0X650, ctx->r11) = ctx->f10.u32l;
    // 0x800A8988: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x800A898C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x800A8990: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8994: bne         $t4, $zero, L_800A8A18
    if (ctx->r12 != 0) {
        // 0x800A8998: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800A8A18;
    }
    // 0x800A8998: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A899C: lwc1        $f1, -0x7860($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7860);
    // 0x800A89A0: lwc1        $f0, -0x785C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X785C);
    // 0x800A89A4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A89A8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A89AC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A89B0: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A89B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A89B8: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800A89BC: swc1        $f16, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f16.u32l;
    // 0x800A89C0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A89C4: nop

    // 0x800A89C8: lwc1        $f4, 0x66C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A89CC: nop

    // 0x800A89D0: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A89D4: swc1        $f10, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f10.u32l;
    // 0x800A89D8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A89DC: nop

    // 0x800A89E0: lwc1        $f18, 0x650($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A89E4: nop

    // 0x800A89E8: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800A89EC: mul.d       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800A89F0: cvt.s.d     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.d); 
    ctx->f4.fl = CVT_S_D(ctx->f16.d);
    // 0x800A89F4: swc1        $f4, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f4.u32l;
    // 0x800A89F8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A89FC: nop

    // 0x800A8A00: lwc1        $f6, 0x670($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A8A04: nop

    // 0x800A8A08: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x800A8A0C: mul.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x800A8A10: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800A8A14: swc1        $f8, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f8.u32l;
L_800A8A18:
    // 0x800A8A18: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8A1C: sw          $v1, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->r3;
    // 0x800A8A20: jal         0x800A19A4
    // 0x800A8A24: sw          $a3, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r7;
    hud_eggs_portrait(rdram, ctx);
        goto after_9;
    // 0x800A8A24: sw          $a3, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r7;
    after_9:
    // 0x800A8A28: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x800A8A2C: addiu       $t5, $zero, -0x2
    ctx->r13 = ADD32(0, -0X2);
    // 0x800A8A30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A8A34: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A8A38: sw          $t5, 0x2834($at)
    MEM_W(0X2834, ctx->r1) = ctx->r13;
    // 0x800A8A3C: lw          $v1, 0xF4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XF4);
    // 0x800A8A40: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800A8A44: mtc1        $s1, $f6
    ctx->f6.u32l = ctx->r17;
    // 0x800A8A48: lw          $a3, 0xF0($sp)
    ctx->r7 = MEM_W(ctx->r29, 0XF0);
    // 0x800A8A4C: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A8A50: swc1        $f4, 0x64C($t6)
    MEM_W(0X64C, ctx->r14) = ctx->f4.u32l;
    // 0x800A8A54: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A8A58: mtc1        $v1, $f18
    ctx->f18.u32l = ctx->r3;
    // 0x800A8A5C: swc1        $f10, 0x650($t7)
    MEM_W(0X650, ctx->r15) = ctx->f10.u32l;
    // 0x800A8A60: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A8A64: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A8A68: mtc1        $a3, $f16
    ctx->f16.u32l = ctx->r7;
    // 0x800A8A6C: swc1        $f8, 0x66C($t8)
    MEM_W(0X66C, ctx->r24) = ctx->f8.u32l;
    // 0x800A8A70: cvt.s.w     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A8A74: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A8A78: nop

    // 0x800A8A7C: swc1        $f4, 0x670($t9)
    MEM_W(0X670, ctx->r25) = ctx->f4.u32l;
L_800A8A80:
    // 0x800A8A80: b           L_800A96B4
    // 0x800A8A84: nop

        goto L_800A96B4;
    // 0x800A8A84: nop

    // 0x800A8A88: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
L_800A8A8C:
    // 0x800A8A8C: bne         $v1, $at, L_800A9158
    if (ctx->r3 != ctx->r1) {
        // 0x800A8A90: addiu       $at, $zero, 0x41
        ctx->r1 = ADD32(0, 0X41);
            goto L_800A9158;
    }
    // 0x800A8A90: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A8A94: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A8A98: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x800A8A9C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A8AA0: bne         $v1, $at, L_800A8B10
    if (ctx->r3 != ctx->r1) {
        // 0x800A8AA4: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800A8B10;
    }
    // 0x800A8AA4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A8AA8: lw          $t2, 0x6D0C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D0C);
    // 0x800A8AAC: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800A8AB0: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A8AB4: lb          $t3, 0x27A4($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X27A4);
    // 0x800A8AB8: nop

    // 0x800A8ABC: bne         $t3, $zero, L_800A8B14
    if (ctx->r11 != 0) {
        // 0x800A8AC0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A8B14;
    }
    // 0x800A8AC0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A8AC4: jal         0x80068508
    // 0x800A8AC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_10;
    // 0x800A8AC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_10:
    // 0x800A8ACC: jal         0x8007BF1C
    // 0x800A8AD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_11;
    // 0x800A8AD0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A8AD4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8AD8: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A8ADC: jal         0x80067F2C
    // 0x800A8AE0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtx_ortho(rdram, ctx);
        goto after_12;
    // 0x800A8AE0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_12:
    // 0x800A8AE4: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8AE8: jal         0x800A1E48
    // 0x800A8AEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    hud_battle_portraits(rdram, ctx);
        goto after_13;
    // 0x800A8AEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x800A8AF0: jal         0x80068508
    // 0x800A8AF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_14;
    // 0x800A8AF4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x800A8AF8: jal         0x8007B3D0
    // 0x800A8AFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_15;
    // 0x800A8AFC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_15:
    // 0x800A8B00: jal         0x8007BF1C
    // 0x800A8B04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_16;
    // 0x800A8B04: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_16:
    // 0x800A8B08: b           L_800A96B4
    // 0x800A8B0C: nop

        goto L_800A96B4;
    // 0x800A8B0C: nop

L_800A8B10:
    // 0x800A8B10: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_800A8B14:
    // 0x800A8B14: bne         $v1, $at, L_800A914C
    if (ctx->r3 != ctx->r1) {
        // 0x800A8B18: nop
    
            goto L_800A914C;
    }
    // 0x800A8B18: nop

    // 0x800A8B1C: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x800A8B20: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800A8B24: blez        $t4, L_800A8C30
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A8B28: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A8C30;
    }
    // 0x800A8B28: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A8B2C: andi        $t0, $t4, 0x3
    ctx->r8 = ctx->r12 & 0X3;
    // 0x800A8B30: beq         $t0, $zero, L_800A8B80
    if (ctx->r8 == 0) {
        // 0x800A8B34: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_800A8B80;
    }
    // 0x800A8B34: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800A8B38: sll         $t5, $zero, 2
    ctx->r13 = S32(0 << 2);
    // 0x800A8B3C: addu        $a0, $v0, $t5
    ctx->r4 = ADD32(ctx->r2, ctx->r13);
    // 0x800A8B40: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A8B44:
    // 0x800A8B44: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A8B48: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A8B4C: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x800A8B50: nop

    // 0x800A8B54: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A8B58: nop

    // 0x800A8B5C: bne         $s3, $t7, L_800A8B68
    if (ctx->r19 != ctx->r15) {
        // 0x800A8B60: nop
    
            goto L_800A8B68;
    }
    // 0x800A8B60: nop

    // 0x800A8B64: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A8B68:
    // 0x800A8B68: bne         $a2, $a1, L_800A8B44
    if (ctx->r6 != ctx->r5) {
        // 0x800A8B6C: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A8B44;
    }
    // 0x800A8B6C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A8B70: lw          $t8, 0x140($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X140);
    // 0x800A8B74: nop

    // 0x800A8B78: beq         $a1, $t8, L_800A8C30
    if (ctx->r5 == ctx->r24) {
        // 0x800A8B7C: nop
    
            goto L_800A8C30;
    }
    // 0x800A8B7C: nop

L_800A8B80:
    // 0x800A8B80: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800A8B84: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x800A8B88: sll         $t2, $t9, 2
    ctx->r10 = S32(ctx->r25 << 2);
    // 0x800A8B8C: addu        $a2, $t2, $v0
    ctx->r6 = ADD32(ctx->r10, ctx->r2);
    // 0x800A8B90: addu        $a0, $v0, $t3
    ctx->r4 = ADD32(ctx->r2, ctx->r11);
    // 0x800A8B94: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A8B98:
    // 0x800A8B98: lw          $t4, 0x0($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X0);
    // 0x800A8B9C: nop

    // 0x800A8BA0: lw          $v1, 0x64($t4)
    ctx->r3 = MEM_W(ctx->r12, 0X64);
    // 0x800A8BA4: nop

    // 0x800A8BA8: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A8BAC: nop

    // 0x800A8BB0: bne         $s3, $t5, L_800A8BBC
    if (ctx->r19 != ctx->r13) {
        // 0x800A8BB4: nop
    
            goto L_800A8BBC;
    }
    // 0x800A8BB4: nop

    // 0x800A8BB8: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A8BBC:
    // 0x800A8BBC: lw          $t6, 0x4($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4);
    // 0x800A8BC0: nop

    // 0x800A8BC4: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x800A8BC8: nop

    // 0x800A8BCC: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A8BD0: nop

    // 0x800A8BD4: bne         $s3, $t7, L_800A8BE0
    if (ctx->r19 != ctx->r15) {
        // 0x800A8BD8: nop
    
            goto L_800A8BE0;
    }
    // 0x800A8BD8: nop

    // 0x800A8BDC: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A8BE0:
    // 0x800A8BE0: lw          $t8, 0x8($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X8);
    // 0x800A8BE4: nop

    // 0x800A8BE8: lw          $v1, 0x64($t8)
    ctx->r3 = MEM_W(ctx->r24, 0X64);
    // 0x800A8BEC: nop

    // 0x800A8BF0: lh          $t9, 0x0($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X0);
    // 0x800A8BF4: nop

    // 0x800A8BF8: bne         $s3, $t9, L_800A8C04
    if (ctx->r19 != ctx->r25) {
        // 0x800A8BFC: nop
    
            goto L_800A8C04;
    }
    // 0x800A8BFC: nop

    // 0x800A8C00: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A8C04:
    // 0x800A8C04: lw          $t2, 0xC($a0)
    ctx->r10 = MEM_W(ctx->r4, 0XC);
    // 0x800A8C08: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A8C0C: lw          $v1, 0x64($t2)
    ctx->r3 = MEM_W(ctx->r10, 0X64);
    // 0x800A8C10: nop

    // 0x800A8C14: lh          $t3, 0x0($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X0);
    // 0x800A8C18: nop

    // 0x800A8C1C: bne         $s3, $t3, L_800A8C28
    if (ctx->r19 != ctx->r11) {
        // 0x800A8C20: nop
    
            goto L_800A8C28;
    }
    // 0x800A8C20: nop

    // 0x800A8C24: or          $s0, $v1, $zero
    ctx->r16 = ctx->r3 | 0;
L_800A8C28:
    // 0x800A8C28: bne         $a0, $a2, L_800A8B98
    if (ctx->r4 != ctx->r6) {
        // 0x800A8C2C: nop
    
            goto L_800A8B98;
    }
    // 0x800A8C2C: nop

L_800A8C30:
    // 0x800A8C30: beq         $s0, $zero, L_800A914C
    if (ctx->r16 == 0) {
        // 0x800A8C34: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_800A914C;
    }
    // 0x800A8C34: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A8C38: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A8C3C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A8C40: lw          $t4, 0x6CEC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6CEC);
    // 0x800A8C44: addiu       $s2, $s2, 0x6CDC
    ctx->r18 = ADD32(ctx->r18, 0X6CDC);
    // 0x800A8C48: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A8C4C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8C50: sw          $t4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r12;
    // 0x800A8C54: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8C58: lwc1        $f6, 0x64C($t4)
    ctx->f6.u32l = MEM_W(ctx->r12, 0X64C);
    // 0x800A8C5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A8C60: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800A8C64: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A8C68: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x800A8C6C: nop

    // 0x800A8C70: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A8C74: sw          $t6, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r14;
    // 0x800A8C78: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A8C7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8C80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8C84: lwc1        $f18, 0x650($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X650);
    // 0x800A8C88: nop

    // 0x800A8C8C: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8C90: mfc1        $t8, $f8
    ctx->r24 = (int32_t)ctx->f8.u32l;
    // 0x800A8C94: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A8C98: jal         0x8007BF1C
    // 0x800A8C9C: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    sprite_opaque(rdram, ctx);
        goto after_17;
    // 0x800A8C9C: sw          $t8, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r24;
    after_17:
    // 0x800A8CA0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8CA4: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A8CA8: jal         0x80067F2C
    // 0x800A8CAC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtx_ortho(rdram, ctx);
        goto after_18;
    // 0x800A8CAC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_18:
    // 0x800A8CB0: jal         0x80068508
    // 0x800A8CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_19;
    // 0x800A8CB4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_19:
    // 0x800A8CB8: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800A8CBC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A8CC0: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A8CC4: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800A8CC8: swc1        $f16, 0x64C($t9)
    MEM_W(0X64C, ctx->r25) = ctx->f16.u32l;
    // 0x800A8CCC: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x800A8CD0: lui         $t5, 0x8000
    ctx->r13 = S32(0X8000 << 16);
    // 0x800A8CD4: bne         $t2, $zero, L_800A8CF0
    if (ctx->r10 != 0) {
        // 0x800A8CD8: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_800A8CF0;
    }
    // 0x800A8CD8: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800A8CDC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A8CE0: lwc1        $f4, -0x7858($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X7858);
    // 0x800A8CE4: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A8CE8: b           L_800A8D04
    // 0x800A8CEC: swc1        $f4, 0x650($t3)
    MEM_W(0X650, ctx->r11) = ctx->f4.u32l;
        goto L_800A8D04;
    // 0x800A8CEC: swc1        $f4, 0x650($t3)
    MEM_W(0X650, ctx->r11) = ctx->f4.u32l;
L_800A8CF0:
    // 0x800A8CF0: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800A8CF4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A8CF8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A8CFC: nop

    // 0x800A8D00: swc1        $f6, 0x650($t4)
    MEM_W(0X650, ctx->r12) = ctx->f6.u32l;
L_800A8D04:
    // 0x800A8D04: lw          $t5, 0x300($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X300);
    // 0x800A8D08: addiu       $s1, $s1, 0x6CD5
    ctx->r17 = ADD32(ctx->r17, 0X6CD5);
    // 0x800A8D0C: bne         $t5, $zero, L_800A8D90
    if (ctx->r13 != 0) {
        // 0x800A8D10: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800A8D90;
    }
    // 0x800A8D10: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A8D14: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8D18: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x800A8D1C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A8D20: lwc1        $f12, 0x36C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x800A8D24: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A8D28: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A8D2C: sub.s       $f18, $f10, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f12.fl;
    // 0x800A8D30: lwc1        $f10, 0x370($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A8D34: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800A8D38: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A8D3C: nop

    // 0x800A8D40: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A8D44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8D48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8D4C: lui         $at, 0xC2E4
    ctx->r1 = S32(0XC2E4 << 16);
    // 0x800A8D50: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800A8D54: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A8D58: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A8D5C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x800A8D60: sub.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x800A8D64: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A8D68: nop

    // 0x800A8D6C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A8D70: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8D74: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8D78: nop

    // 0x800A8D7C: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A8D80: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800A8D84: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A8D88: b           L_800A8E00
    // 0x800A8D8C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
        goto L_800A8E00;
    // 0x800A8D8C: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_800A8D90:
    // 0x800A8D90: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8D94: lui         $at, 0x4284
    ctx->r1 = S32(0X4284 << 16);
    // 0x800A8D98: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A8D9C: lwc1        $f12, 0x36C($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x800A8DA0: lwc1        $f18, 0x370($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A8DA4: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800A8DA8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A8DAC: nop

    // 0x800A8DB0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A8DB4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8DB8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8DBC: lui         $at, 0xC2C8
    ctx->r1 = S32(0XC2C8 << 16);
    // 0x800A8DC0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A8DC4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A8DC8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A8DCC: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x800A8DD0: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A8DD4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A8DD8: nop

    // 0x800A8DDC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A8DE0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A8DE4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A8DE8: nop

    // 0x800A8DEC: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A8DF0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A8DF4: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800A8DF8: nop

    // 0x800A8DFC: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
L_800A8E00:
    // 0x800A8E00: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A8E04: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A8E08: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x800A8E0C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A8E10: add.s       $f6, $f12, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f12.fl + ctx->f0.fl;
    // 0x800A8E14: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A8E18: swc1        $f6, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f6.u32l;
    // 0x800A8E1C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8E20: cvt.s.w     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    ctx->f2.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A8E24: lwc1        $f18, 0x370($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A8E28: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A8E2C: add.s       $f8, $f18, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f2.fl;
    // 0x800A8E30: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800A8E34: swc1        $f8, 0x370($v0)
    MEM_W(0X370, ctx->r2) = ctx->f8.u32l;
    // 0x800A8E38: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8E3C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A8E40: lwc1        $f16, 0xEC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x800A8E44: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A8E48: add.s       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f0.fl;
    // 0x800A8E4C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A8E50: swc1        $f4, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->f4.u32l;
    // 0x800A8E54: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8E58: nop

    // 0x800A8E5C: lwc1        $f6, 0xF0($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x800A8E60: nop

    // 0x800A8E64: add.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800A8E68: swc1        $f10, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->f10.u32l;
    // 0x800A8E6C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8E70: nop

    // 0x800A8E74: lwc1        $f18, 0x38C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X38C);
    // 0x800A8E78: nop

    // 0x800A8E7C: add.s       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f0.fl;
    // 0x800A8E80: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800A8E84: swc1        $f8, 0x38C($v0)
    MEM_W(0X38C, ctx->r2) = ctx->f8.u32l;
    // 0x800A8E88: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8E8C: cvt.s.w     $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    ctx->f14.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A8E90: lwc1        $f16, 0x390($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X390);
    // 0x800A8E94: nop

    // 0x800A8E98: add.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A8E9C: swc1        $f4, 0x390($v0)
    MEM_W(0X390, ctx->r2) = ctx->f4.u32l;
    // 0x800A8EA0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8EA4: nop

    // 0x800A8EA8: lwc1        $f6, 0x10C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10C);
    // 0x800A8EAC: nop

    // 0x800A8EB0: add.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x800A8EB4: swc1        $f10, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f10.u32l;
    // 0x800A8EB8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8EBC: nop

    // 0x800A8EC0: lwc1        $f8, 0x110($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X110);
    // 0x800A8EC4: nop

    // 0x800A8EC8: sub.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f14.fl;
    // 0x800A8ECC: swc1        $f16, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f16.u32l;
    // 0x800A8ED0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8ED4: nop

    // 0x800A8ED8: lwc1        $f4, 0x12C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X12C);
    // 0x800A8EDC: nop

    // 0x800A8EE0: add.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f0.fl;
    // 0x800A8EE4: swc1        $f6, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f6.u32l;
    // 0x800A8EE8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8EEC: nop

    // 0x800A8EF0: lwc1        $f10, 0x130($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X130);
    // 0x800A8EF4: nop

    // 0x800A8EF8: sub.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f14.fl;
    // 0x800A8EFC: swc1        $f18, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f18.u32l;
    // 0x800A8F00: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F04: nop

    // 0x800A8F08: lwc1        $f8, 0x24C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24C);
    // 0x800A8F0C: nop

    // 0x800A8F10: add.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f0.fl;
    // 0x800A8F14: swc1        $f16, 0x24C($v0)
    MEM_W(0X24C, ctx->r2) = ctx->f16.u32l;
    // 0x800A8F18: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F1C: nop

    // 0x800A8F20: lwc1        $f4, 0x250($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X250);
    // 0x800A8F24: nop

    // 0x800A8F28: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A8F2C: swc1        $f6, 0x250($v0)
    MEM_W(0X250, ctx->r2) = ctx->f6.u32l;
    // 0x800A8F30: lb          $t3, 0x3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X3);
    // 0x800A8F34: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F38: addiu       $t4, $t3, 0x38
    ctx->r12 = ADD32(ctx->r11, 0X38);
    // 0x800A8F3C: sh          $t4, 0x646($t5)
    MEM_H(0X646, ctx->r13) = ctx->r12;
    // 0x800A8F40: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A8F44: nop

    // 0x800A8F48: bne         $t6, $zero, L_800A8F80
    if (ctx->r14 != 0) {
        // 0x800A8F4C: nop
    
            goto L_800A8F80;
    }
    // 0x800A8F4C: nop

    // 0x800A8F50: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F54: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A8F58: lwc1        $f10, 0x64C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A8F5C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A8F60: sub.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800A8F64: swc1        $f8, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f8.u32l;
    // 0x800A8F68: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F6C: nop

    // 0x800A8F70: lwc1        $f16, 0x66C($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A8F74: nop

    // 0x800A8F78: sub.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800A8F7C: swc1        $f6, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f6.u32l;
L_800A8F80:
    // 0x800A8F80: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A8F84: sb          $t7, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r15;
    // 0x800A8F88: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800A8F8C: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800A8F90: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    // 0x800A8F94: jal         0x800AA600
    // 0x800A8F98: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    hud_element_render(rdram, ctx);
        goto after_20;
    // 0x800A8F98: addiu       $a3, $a3, 0x640
    ctx->r7 = ADD32(ctx->r7, 0X640);
    after_20:
    // 0x800A8F9C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8FA0: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x800A8FA4: lb          $t8, 0xFB($v0)
    ctx->r24 = MEM_B(ctx->r2, 0XFB);
    // 0x800A8FA8: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A8FAC: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A8FB0: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A8FB4: bne         $t8, $zero, L_800A8FD0
    if (ctx->r24 != 0) {
        // 0x800A8FB8: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800A8FD0;
    }
    // 0x800A8FB8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800A8FBC: lb          $v1, 0x185($s0)
    ctx->r3 = MEM_B(ctx->r16, 0X185);
    // 0x800A8FC0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A8FC4: bne         $v1, $at, L_800A8FD4
    if (ctx->r3 != ctx->r1) {
        // 0x800A8FC8: lw          $a1, 0x16C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X16C);
            goto L_800A8FD4;
    }
    // 0x800A8FC8: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
    // 0x800A8FCC: sb          $v1, 0xFB($v0)
    MEM_B(0XFB, ctx->r2) = ctx->r3;
L_800A8FD0:
    // 0x800A8FD0: lw          $a1, 0x16C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X16C);
L_800A8FD4:
    // 0x800A8FD4: swc1        $f0, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f0.u32l;
    // 0x800A8FD8: swc1        $f2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f2.u32l;
    // 0x800A8FDC: jal         0x800A4154
    // 0x800A8FE0: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    hud_bananas(rdram, ctx);
        goto after_21;
    // 0x800A8FE0: swc1        $f14, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f14.u32l;
    after_21:
    // 0x800A8FE4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A8FE8: lwc1        $f0, 0x4C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A8FEC: lwc1        $f10, 0x36C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X36C);
    // 0x800A8FF0: lwc1        $f2, 0x48($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800A8FF4: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A8FF8: lwc1        $f14, 0x44($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800A8FFC: swc1        $f18, 0x36C($v0)
    MEM_W(0X36C, ctx->r2) = ctx->f18.u32l;
    // 0x800A9000: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9004: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A9008: lwc1        $f8, 0x370($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X370);
    // 0x800A900C: nop

    // 0x800A9010: sub.s       $f16, $f8, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f2.fl;
    // 0x800A9014: swc1        $f16, 0x370($v0)
    MEM_W(0X370, ctx->r2) = ctx->f16.u32l;
    // 0x800A9018: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A901C: nop

    // 0x800A9020: lwc1        $f4, 0xEC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XEC);
    // 0x800A9024: nop

    // 0x800A9028: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A902C: swc1        $f6, 0xEC($v0)
    MEM_W(0XEC, ctx->r2) = ctx->f6.u32l;
    // 0x800A9030: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9034: nop

    // 0x800A9038: lwc1        $f10, 0xF0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XF0);
    // 0x800A903C: nop

    // 0x800A9040: sub.s       $f18, $f10, $f2
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f2.fl;
    // 0x800A9044: swc1        $f18, 0xF0($v0)
    MEM_W(0XF0, ctx->r2) = ctx->f18.u32l;
    // 0x800A9048: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A904C: nop

    // 0x800A9050: lwc1        $f8, 0x38C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X38C);
    // 0x800A9054: nop

    // 0x800A9058: sub.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A905C: swc1        $f16, 0x38C($v0)
    MEM_W(0X38C, ctx->r2) = ctx->f16.u32l;
    // 0x800A9060: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9064: nop

    // 0x800A9068: lwc1        $f4, 0x390($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X390);
    // 0x800A906C: nop

    // 0x800A9070: sub.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f2.fl;
    // 0x800A9074: swc1        $f6, 0x390($v0)
    MEM_W(0X390, ctx->r2) = ctx->f6.u32l;
    // 0x800A9078: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A907C: nop

    // 0x800A9080: lwc1        $f10, 0x10C($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10C);
    // 0x800A9084: nop

    // 0x800A9088: sub.s       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f10.fl - ctx->f0.fl;
    // 0x800A908C: swc1        $f18, 0x10C($v0)
    MEM_W(0X10C, ctx->r2) = ctx->f18.u32l;
    // 0x800A9090: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9094: nop

    // 0x800A9098: lwc1        $f8, 0x110($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X110);
    // 0x800A909C: nop

    // 0x800A90A0: add.s       $f16, $f8, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f14.fl;
    // 0x800A90A4: swc1        $f16, 0x110($v0)
    MEM_W(0X110, ctx->r2) = ctx->f16.u32l;
    // 0x800A90A8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A90AC: nop

    // 0x800A90B0: lwc1        $f4, 0x12C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X12C);
    // 0x800A90B4: nop

    // 0x800A90B8: sub.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f0.fl;
    // 0x800A90BC: swc1        $f6, 0x12C($v0)
    MEM_W(0X12C, ctx->r2) = ctx->f6.u32l;
    // 0x800A90C0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A90C4: nop

    // 0x800A90C8: lwc1        $f10, 0x130($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X130);
    // 0x800A90CC: nop

    // 0x800A90D0: add.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x800A90D4: swc1        $f18, 0x130($v0)
    MEM_W(0X130, ctx->r2) = ctx->f18.u32l;
    // 0x800A90D8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A90DC: nop

    // 0x800A90E0: lwc1        $f8, 0x24C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X24C);
    // 0x800A90E4: nop

    // 0x800A90E8: sub.s       $f16, $f8, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x800A90EC: swc1        $f16, 0x24C($v0)
    MEM_W(0X24C, ctx->r2) = ctx->f16.u32l;
    // 0x800A90F0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A90F4: nop

    // 0x800A90F8: lwc1        $f4, 0x250($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X250);
    // 0x800A90FC: nop

    // 0x800A9100: add.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f2.fl;
    // 0x800A9104: swc1        $f6, 0x250($v0)
    MEM_W(0X250, ctx->r2) = ctx->f6.u32l;
    // 0x800A9108: lw          $t9, 0xE4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XE4);
    // 0x800A910C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A9110: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A9114: nop

    // 0x800A9118: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A911C: swc1        $f18, 0x64C($t2)
    MEM_W(0X64C, ctx->r10) = ctx->f18.u32l;
    // 0x800A9120: lw          $t3, 0xE0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XE0);
    // 0x800A9124: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A9128: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A912C: nop

    // 0x800A9130: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9134: jal         0x8007BF1C
    // 0x800A9138: swc1        $f16, 0x650($t4)
    MEM_W(0X650, ctx->r12) = ctx->f16.u32l;
    sprite_opaque(rdram, ctx);
        goto after_22;
    // 0x800A9138: swc1        $f16, 0x650($t4)
    MEM_W(0X650, ctx->r12) = ctx->f16.u32l;
    after_22:
    // 0x800A913C: jal         0x8007B3D0
    // 0x800A9140: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_23;
    // 0x800A9140: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_23:
    // 0x800A9144: jal         0x80068508
    // 0x800A9148: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_24;
    // 0x800A9148: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_24:
L_800A914C:
    // 0x800A914C: b           L_800A96B4
    // 0x800A9150: nop

        goto L_800A96B4;
    // 0x800A9150: nop

    // 0x800A9154: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
L_800A9158:
    // 0x800A9158: bne         $v1, $at, L_800A96B4
    if (ctx->r3 != ctx->r1) {
        // 0x800A915C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_800A96B4;
    }
    // 0x800A915C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A9160: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x800A9164: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A9168: bne         $v1, $at, L_800A935C
    if (ctx->r3 != ctx->r1) {
        // 0x800A916C: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_800A935C;
    }
    // 0x800A916C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A9170: lw          $t5, 0x6D0C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D0C);
    // 0x800A9174: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800A9178: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x800A917C: lb          $t6, 0x27A4($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X27A4);
    // 0x800A9180: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A9184: bne         $t6, $zero, L_800A935C
    if (ctx->r14 != 0) {
        // 0x800A9188: addiu       $s2, $s2, 0x6CDC
        ctx->r18 = ADD32(ctx->r18, 0X6CDC);
            goto L_800A935C;
    }
    // 0x800A9188: addiu       $s2, $s2, 0x6CDC
    ctx->r18 = ADD32(ctx->r18, 0X6CDC);
    // 0x800A918C: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A9190: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9194: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A9198: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A919C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A91A0: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A91A4: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A91A8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A91AC: lwc1        $f8, 0x40C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A91B0: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A91B4: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A91B8: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800A91BC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A91C0: addiu       $a0, $sp, 0xCC
    ctx->r4 = ADD32(ctx->r29, 0XCC);
    // 0x800A91C4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A91C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A91CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A91D0: nop

    // 0x800A91D4: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A91D8: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A91DC: mfc1        $s1, $f18
    ctx->r17 = (int32_t)ctx->f18.u32l;
    // 0x800A91E0: nop

    // 0x800A91E4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A91E8: nop

    // 0x800A91EC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A91F0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A91F4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A91F8: nop

    // 0x800A91FC: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A9200: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A9204: mfc1        $s3, $f16
    ctx->r19 = (int32_t)ctx->f16.u32l;
    // 0x800A9208: nop

    // 0x800A920C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A9210: nop

    // 0x800A9214: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A9218: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A921C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9220: nop

    // 0x800A9224: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9228: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800A922C: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A9230: jal         0x8001BA74
    // 0x800A9234: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    get_racer_objects(rdram, ctx);
        goto after_25;
    // 0x800A9234: sw          $t3, 0xBC($sp)
    MEM_W(0XBC, ctx->r29) = ctx->r11;
    after_25:
    // 0x800A9238: lw          $t4, 0xCC($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XCC);
    // 0x800A923C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A9240: blez        $t4, L_800A930C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A9244: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800A930C;
    }
    // 0x800A9244: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_800A9248:
    // 0x800A9248: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800A924C: nop

    // 0x800A9250: lw          $a0, 0x64($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X64);
    // 0x800A9254: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x800A9258: jal         0x800A45F0
    // 0x800A925C: sw          $v1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r3;
    hud_treasure(rdram, ctx);
        goto after_26;
    // 0x800A925C: sw          $v1, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r3;
    after_26:
    // 0x800A9260: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A9264: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A9268: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A926C: lwc1        $f1, -0x7848($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7848);
    // 0x800A9270: lwc1        $f0, -0x7844($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7844);
    // 0x800A9274: lw          $v1, 0xD0($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XD0);
    // 0x800A9278: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x800A927C: bne         $t6, $zero, L_800A92C8
    if (ctx->r14 != 0) {
        // 0x800A9280: lui         $at, 0x425C
        ctx->r1 = S32(0X425C << 16);
            goto L_800A92C8;
    }
    // 0x800A9280: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A9284: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9288: nop

    // 0x800A928C: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9290: nop

    // 0x800A9294: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800A9298: add.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = ctx->f18.d + ctx->f0.d;
    // 0x800A929C: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x800A92A0: swc1        $f16, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f16.u32l;
    // 0x800A92A4: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A92A8: nop

    // 0x800A92AC: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A92B0: nop

    // 0x800A92B4: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A92B8: add.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = ctx->f6.d + ctx->f0.d;
    // 0x800A92BC: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800A92C0: b           L_800A92F8
    // 0x800A92C4: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
        goto L_800A92F8;
    // 0x800A92C4: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
L_800A92C8:
    // 0x800A92C8: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A92CC: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A92D0: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A92D4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A92D8: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800A92DC: swc1        $f4, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f4.u32l;
    // 0x800A92E0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A92E4: nop

    // 0x800A92E8: lwc1        $f6, 0x410($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A92EC: nop

    // 0x800A92F0: add.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800A92F4: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
L_800A92F8:
    // 0x800A92F8: lw          $t7, 0xCC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XCC);
    // 0x800A92FC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A9300: slt         $at, $v1, $t7
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800A9304: bne         $at, $zero, L_800A9248
    if (ctx->r1 != 0) {
        // 0x800A9308: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800A9248;
    }
    // 0x800A9308: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
L_800A930C:
    // 0x800A930C: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x800A9310: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A9314: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9318: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800A931C: mtc1        $s3, $f10
    ctx->f10.u32l = ctx->r19;
    // 0x800A9320: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A9324: swc1        $f16, 0x64C($t8)
    MEM_W(0X64C, ctx->r24) = ctx->f16.u32l;
    // 0x800A9328: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A932C: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9330: swc1        $f6, 0x650($t9)
    MEM_W(0X650, ctx->r25) = ctx->f6.u32l;
    // 0x800A9334: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A9338: nop

    // 0x800A933C: swc1        $f18, 0x40C($t2)
    MEM_W(0X40C, ctx->r10) = ctx->f18.u32l;
    // 0x800A9340: lw          $t3, 0xBC($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XBC);
    // 0x800A9344: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A9348: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A934C: nop

    // 0x800A9350: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9354: b           L_800A96B4
    // 0x800A9358: swc1        $f16, 0x410($t4)
    MEM_W(0X410, ctx->r12) = ctx->f16.u32l;
        goto L_800A96B4;
    // 0x800A9358: swc1        $f16, 0x410($t4)
    MEM_W(0X410, ctx->r12) = ctx->f16.u32l;
L_800A935C:
    // 0x800A935C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A9360: bne         $v1, $at, L_800A96B4
    if (ctx->r3 != ctx->r1) {
        // 0x800A9364: nop
    
            goto L_800A96B4;
    }
    // 0x800A9364: nop

    // 0x800A9368: lw          $t5, 0x140($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X140);
    // 0x800A936C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A9370: blez        $t5, L_800A947C
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800A9374: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800A947C;
    }
    // 0x800A9374: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800A9378: andi        $t0, $t5, 0x3
    ctx->r8 = ctx->r13 & 0X3;
    // 0x800A937C: beq         $t0, $zero, L_800A93CC
    if (ctx->r8 == 0) {
        // 0x800A9380: or          $a3, $t0, $zero
        ctx->r7 = ctx->r8 | 0;
            goto L_800A93CC;
    }
    // 0x800A9380: or          $a3, $t0, $zero
    ctx->r7 = ctx->r8 | 0;
    // 0x800A9384: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800A9388: addu        $a0, $v0, $t6
    ctx->r4 = ADD32(ctx->r2, ctx->r14);
    // 0x800A938C: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A9390:
    // 0x800A9390: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A9394: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800A9398: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A939C: nop

    // 0x800A93A0: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A93A4: nop

    // 0x800A93A8: bne         $s3, $t8, L_800A93B4
    if (ctx->r19 != ctx->r24) {
        // 0x800A93AC: nop
    
            goto L_800A93B4;
    }
    // 0x800A93AC: nop

    // 0x800A93B0: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A93B4:
    // 0x800A93B4: bne         $a3, $a1, L_800A9390
    if (ctx->r7 != ctx->r5) {
        // 0x800A93B8: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_800A9390;
    }
    // 0x800A93B8: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x800A93BC: lw          $t9, 0x140($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X140);
    // 0x800A93C0: nop

    // 0x800A93C4: beq         $a1, $t9, L_800A947C
    if (ctx->r5 == ctx->r25) {
        // 0x800A93C8: nop
    
            goto L_800A947C;
    }
    // 0x800A93C8: nop

L_800A93CC:
    // 0x800A93CC: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800A93D0: sll         $t4, $a1, 2
    ctx->r12 = S32(ctx->r5 << 2);
    // 0x800A93D4: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800A93D8: addu        $a3, $t3, $v0
    ctx->r7 = ADD32(ctx->r11, ctx->r2);
    // 0x800A93DC: addu        $a0, $v0, $t4
    ctx->r4 = ADD32(ctx->r2, ctx->r12);
    // 0x800A93E0: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_800A93E4:
    // 0x800A93E4: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x800A93E8: nop

    // 0x800A93EC: lw          $v1, 0x64($t5)
    ctx->r3 = MEM_W(ctx->r13, 0X64);
    // 0x800A93F0: nop

    // 0x800A93F4: lh          $t6, 0x0($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X0);
    // 0x800A93F8: nop

    // 0x800A93FC: bne         $s3, $t6, L_800A9408
    if (ctx->r19 != ctx->r14) {
        // 0x800A9400: nop
    
            goto L_800A9408;
    }
    // 0x800A9400: nop

    // 0x800A9404: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A9408:
    // 0x800A9408: lw          $t7, 0x4($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4);
    // 0x800A940C: nop

    // 0x800A9410: lw          $v1, 0x64($t7)
    ctx->r3 = MEM_W(ctx->r15, 0X64);
    // 0x800A9414: nop

    // 0x800A9418: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800A941C: nop

    // 0x800A9420: bne         $s3, $t8, L_800A942C
    if (ctx->r19 != ctx->r24) {
        // 0x800A9424: nop
    
            goto L_800A942C;
    }
    // 0x800A9424: nop

    // 0x800A9428: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A942C:
    // 0x800A942C: lw          $t9, 0x8($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X8);
    // 0x800A9430: nop

    // 0x800A9434: lw          $v1, 0x64($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X64);
    // 0x800A9438: nop

    // 0x800A943C: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x800A9440: nop

    // 0x800A9444: bne         $s3, $t2, L_800A9450
    if (ctx->r19 != ctx->r10) {
        // 0x800A9448: nop
    
            goto L_800A9450;
    }
    // 0x800A9448: nop

    // 0x800A944C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A9450:
    // 0x800A9450: lw          $t3, 0xC($a0)
    ctx->r11 = MEM_W(ctx->r4, 0XC);
    // 0x800A9454: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x800A9458: lw          $v1, 0x64($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X64);
    // 0x800A945C: nop

    // 0x800A9460: lh          $t4, 0x0($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X0);
    // 0x800A9464: nop

    // 0x800A9468: bne         $s3, $t4, L_800A9474
    if (ctx->r19 != ctx->r12) {
        // 0x800A946C: nop
    
            goto L_800A9474;
    }
    // 0x800A946C: nop

    // 0x800A9470: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_800A9474:
    // 0x800A9474: bne         $a0, $a3, L_800A93E4
    if (ctx->r4 != ctx->r7) {
        // 0x800A9478: nop
    
            goto L_800A93E4;
    }
    // 0x800A9478: nop

L_800A947C:
    // 0x800A947C: beq         $a2, $zero, L_800A96B4
    if (ctx->r6 == 0) {
        // 0x800A9480: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_800A96B4;
    }
    // 0x800A9480: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A9484: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A9488: addiu       $s2, $s2, 0x6CDC
    ctx->r18 = ADD32(ctx->r18, 0X6CDC);
    // 0x800A948C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9490: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A9494: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9498: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A949C: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A94A0: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A94A4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A94A8: lwc1        $f8, 0x40C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A94AC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A94B0: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A94B4: mfc1        $s0, $f6
    ctx->r16 = (int32_t)ctx->f6.u32l;
    // 0x800A94B8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800A94BC: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x800A94C0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800A94C4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A94C8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A94CC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x800A94D0: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A94D4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800A94D8: mfc1        $s1, $f18
    ctx->r17 = (int32_t)ctx->f18.u32l;
    // 0x800A94DC: nop

    // 0x800A94E0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A94E4: nop

    // 0x800A94E8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A94EC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A94F0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A94F4: nop

    // 0x800A94F8: cvt.w.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A94FC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A9500: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800A9504: nop

    // 0x800A9508: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A950C: nop

    // 0x800A9510: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A9514: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9518: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A951C: lui         $at, 0x4361
    ctx->r1 = S32(0X4361 << 16);
    // 0x800A9520: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9524: lui         $at, 0x4325
    ctx->r1 = S32(0X4325 << 16);
    // 0x800A9528: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A952C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9530: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A9534: lui         $at, 0x4351
    ctx->r1 = S32(0X4351 << 16);
    // 0x800A9538: swc1        $f18, 0x650($t9)
    MEM_W(0X650, ctx->r25) = ctx->f18.u32l;
    // 0x800A953C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A9540: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A9544: lui         $at, 0x4341
    ctx->r1 = S32(0X4341 << 16);
    // 0x800A9548: swc1        $f8, 0x40C($t2)
    MEM_W(0X40C, ctx->r10) = ctx->f8.u32l;
    // 0x800A954C: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A9550: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9554: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9558: swc1        $f16, 0x410($t3)
    MEM_W(0X410, ctx->r11) = ctx->f16.u32l;
    // 0x800A955C: lw          $t4, 0x300($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X300);
    // 0x800A9560: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x800A9564: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A9568: bne         $t4, $zero, L_800A965C
    if (ctx->r12 != 0) {
        // 0x800A956C: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_800A965C;
    }
    // 0x800A956C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A9570: lwc1        $f1, -0x7840($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7840);
    // 0x800A9574: lwc1        $f0, -0x783C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X783C);
    // 0x800A9578: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A957C: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A9580: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A9584: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A9588: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800A958C: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800A9590: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A9594: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A9598: nop

    // 0x800A959C: lwc1        $f18, 0x40C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X40C);
    // 0x800A95A0: nop

    // 0x800A95A4: sub.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800A95A8: swc1        $f16, 0x40C($v0)
    MEM_W(0X40C, ctx->r2) = ctx->f16.u32l;
    // 0x800A95AC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95B0: nop

    // 0x800A95B4: lwc1        $f4, 0x650($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A95B8: nop

    // 0x800A95BC: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x800A95C0: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800A95C4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x800A95C8: swc1        $f18, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f18.u32l;
    // 0x800A95CC: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95D0: nop

    // 0x800A95D4: lwc1        $f8, 0x410($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A95D8: nop

    // 0x800A95DC: cvt.d.s     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f16.d = CVT_D_S(ctx->f8.fl);
    // 0x800A95E0: mul.d       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x800A95E4: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800A95E8: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A95EC: swc1        $f6, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f6.u32l;
    // 0x800A95F0: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A95F4: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A95F8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A95FC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9600: lwc1        $f10, 0x650($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A9604: nop

    // 0x800A9608: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800A960C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800A9610: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A9614: mtc1        $t6, $f8
    ctx->f8.u32l = ctx->r14;
    // 0x800A9618: nop

    // 0x800A961C: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9620: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A9624: swc1        $f16, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f16.u32l;
    // 0x800A9628: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800A962C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A9630: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9634: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9638: lwc1        $f4, 0x410($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X410);
    // 0x800A963C: nop

    // 0x800A9640: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A9644: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800A9648: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A964C: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800A9650: nop

    // 0x800A9654: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9658: swc1        $f18, 0x410($v0)
    MEM_W(0X410, ctx->r2) = ctx->f18.u32l;
L_800A965C:
    // 0x800A965C: sw          $v1, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->r3;
    // 0x800A9660: jal         0x800A45F0
    // 0x800A9664: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    hud_treasure(rdram, ctx);
        goto after_27;
    // 0x800A9664: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    after_27:
    // 0x800A9668: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x800A966C: lw          $v1, 0xA8($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XA8);
    // 0x800A9670: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9674: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9678: mtc1        $s1, $f4
    ctx->f4.u32l = ctx->r17;
    // 0x800A967C: lw          $a1, 0xA4($sp)
    ctx->r5 = MEM_W(ctx->r29, 0XA4);
    // 0x800A9680: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A9684: swc1        $f16, 0x64C($t9)
    MEM_W(0X64C, ctx->r25) = ctx->f16.u32l;
    // 0x800A9688: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A968C: mtc1        $v1, $f10
    ctx->f10.u32l = ctx->r3;
    // 0x800A9690: swc1        $f6, 0x650($t2)
    MEM_W(0X650, ctx->r10) = ctx->f6.u32l;
    // 0x800A9694: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A9698: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800A969C: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800A96A0: swc1        $f18, 0x40C($t3)
    MEM_W(0X40C, ctx->r11) = ctx->f18.u32l;
    // 0x800A96A4: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A96A8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A96AC: nop

    // 0x800A96B0: swc1        $f16, 0x410($t4)
    MEM_W(0X410, ctx->r12) = ctx->f16.u32l;
L_800A96B4:
    // 0x800A96B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A96B8: lw          $v0, 0x7180($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7180);
    // 0x800A96BC: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800A96C0: addiu       $s2, $s2, 0x6CDC
    ctx->r18 = ADD32(ctx->r18, 0X6CDC);
    // 0x800A96C4: beq         $v0, $zero, L_800A9710
    if (ctx->r2 == 0) {
        // 0x800A96C8: addiu       $s3, $zero, -0x1
        ctx->r19 = ADD32(0, -0X1);
            goto L_800A9710;
    }
    // 0x800A96C8: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
    // 0x800A96CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A96D0: addiu       $a1, $a1, 0x6D80
    ctx->r5 = ADD32(ctx->r5, 0X6D80);
    // 0x800A96D4: sll         $t5, $v0, 3
    ctx->r13 = S32(ctx->r2 << 3);
    // 0x800A96D8: addu        $t6, $a1, $t5
    ctx->r14 = ADD32(ctx->r5, ctx->r13);
    // 0x800A96DC: sw          $zero, 0x0($t6)
    MEM_W(0X0, ctx->r14) = 0;
    // 0x800A96E0: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800A96E4: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x800A96E8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x800A96EC: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800A96F0: sw          $t2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r10;
    // 0x800A96F4: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x800A96F8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800A96FC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800A9700: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A9704: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A9708: jal         0x80078AB8
    // 0x800A970C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    texrect_draw(rdram, ctx);
        goto after_28;
    // 0x800A970C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
L_800A9710:
    // 0x800A9710: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800A9714: lw          $t4, 0x160($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X160);
    // 0x800A9718: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A971C: sw          $t3, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r11;
    // 0x800A9720: lw          $t6, 0x164($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X164);
    // 0x800A9724: lw          $t5, 0x6D00($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D00);
    // 0x800A9728: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A972C: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800A9730: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800A9734: lw          $t7, 0x6D04($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D04);
    // 0x800A9738: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A973C: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800A9740: lw          $t9, 0x6D60($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D60);
    // 0x800A9744: nop

    // 0x800A9748: lbu         $t2, 0xBC($t9)
    ctx->r10 = MEM_BU(ctx->r25, 0XBC);
    // 0x800A974C: nop

    // 0x800A9750: andi        $t3, $t2, 0x1
    ctx->r11 = ctx->r10 & 0X1;
    // 0x800A9754: bne         $t3, $zero, L_800AA3D0
    if (ctx->r11 != 0) {
        // 0x800A9758: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AA3D0;
    }
    // 0x800A9758: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A975C: lw          $t4, 0x140($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X140);
    // 0x800A9760: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A9764: blez        $t4, L_800A98E8
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800A9768: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800A98E8;
    }
    // 0x800A9768: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800A976C: andi        $t0, $t4, 0x3
    ctx->r8 = ctx->r12 & 0X3;
    // 0x800A9770: beq         $t0, $zero, L_800A97D8
    if (ctx->r8 == 0) {
        // 0x800A9774: or          $a2, $t0, $zero
        ctx->r6 = ctx->r8 | 0;
            goto L_800A97D8;
    }
    // 0x800A9774: or          $a2, $t0, $zero
    ctx->r6 = ctx->r8 | 0;
    // 0x800A9778: lw          $t5, 0x150($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X150);
    // 0x800A977C: sll         $t6, $zero, 2
    ctx->r14 = S32(0 << 2);
    // 0x800A9780: addu        $s0, $t5, $t6
    ctx->r16 = ADD32(ctx->r13, ctx->r14);
L_800A9784:
    // 0x800A9784: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800A9788: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800A978C: lw          $v0, 0x64($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X64);
    // 0x800A9790: nop

    // 0x800A9794: beq         $v0, $zero, L_800A97C0
    if (ctx->r2 == 0) {
        // 0x800A9798: nop
    
            goto L_800A97C0;
    }
    // 0x800A9798: nop

    // 0x800A979C: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800A97A0: nop

    // 0x800A97A4: beq         $s3, $t8, L_800A97C0
    if (ctx->r19 == ctx->r24) {
        // 0x800A97A8: nop
    
            goto L_800A97C0;
    }
    // 0x800A97A8: nop

    // 0x800A97AC: lb          $t9, 0x1D8($v0)
    ctx->r25 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A97B0: nop

    // 0x800A97B4: bne         $t9, $zero, L_800A97C0
    if (ctx->r25 != 0) {
        // 0x800A97B8: nop
    
            goto L_800A97C0;
    }
    // 0x800A97B8: nop

    // 0x800A97BC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A97C0:
    // 0x800A97C0: bne         $a2, $v1, L_800A9784
    if (ctx->r6 != ctx->r3) {
        // 0x800A97C4: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_800A9784;
    }
    // 0x800A97C4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800A97C8: lw          $t2, 0x140($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X140);
    // 0x800A97CC: nop

    // 0x800A97D0: beq         $v1, $t2, L_800A98E8
    if (ctx->r3 == ctx->r10) {
        // 0x800A97D4: nop
    
            goto L_800A98E8;
    }
    // 0x800A97D4: nop

L_800A97D8:
    // 0x800A97D8: lw          $a2, 0x140($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X140);
    // 0x800A97DC: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800A97E0: sll         $s1, $v1, 2
    ctx->r17 = S32(ctx->r3 << 2);
    // 0x800A97E4: sll         $t4, $a2, 2
    ctx->r12 = S32(ctx->r6 << 2);
    // 0x800A97E8: or          $a2, $t4, $zero
    ctx->r6 = ctx->r12 | 0;
    // 0x800A97EC: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
L_800A97F0:
    // 0x800A97F0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x800A97F4: addiu       $s1, $s1, 0x10
    ctx->r17 = ADD32(ctx->r17, 0X10);
    // 0x800A97F8: lw          $v0, 0x64($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X64);
    // 0x800A97FC: nop

    // 0x800A9800: beq         $v0, $zero, L_800A982C
    if (ctx->r2 == 0) {
        // 0x800A9804: nop
    
            goto L_800A982C;
    }
    // 0x800A9804: nop

    // 0x800A9808: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800A980C: nop

    // 0x800A9810: beq         $s3, $t6, L_800A982C
    if (ctx->r19 == ctx->r14) {
        // 0x800A9814: nop
    
            goto L_800A982C;
    }
    // 0x800A9814: nop

    // 0x800A9818: lb          $t7, 0x1D8($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X1D8);
    // 0x800A981C: nop

    // 0x800A9820: bne         $t7, $zero, L_800A982C
    if (ctx->r15 != 0) {
        // 0x800A9824: nop
    
            goto L_800A982C;
    }
    // 0x800A9824: nop

    // 0x800A9828: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A982C:
    // 0x800A982C: lw          $t8, 0x4($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4);
    // 0x800A9830: nop

    // 0x800A9834: lw          $a1, 0x64($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X64);
    // 0x800A9838: nop

    // 0x800A983C: beq         $a1, $zero, L_800A9868
    if (ctx->r5 == 0) {
        // 0x800A9840: nop
    
            goto L_800A9868;
    }
    // 0x800A9840: nop

    // 0x800A9844: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x800A9848: nop

    // 0x800A984C: beq         $s3, $t9, L_800A9868
    if (ctx->r19 == ctx->r25) {
        // 0x800A9850: nop
    
            goto L_800A9868;
    }
    // 0x800A9850: nop

    // 0x800A9854: lb          $t2, 0x1D8($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1D8);
    // 0x800A9858: nop

    // 0x800A985C: bne         $t2, $zero, L_800A9868
    if (ctx->r10 != 0) {
        // 0x800A9860: nop
    
            goto L_800A9868;
    }
    // 0x800A9860: nop

    // 0x800A9864: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A9868:
    // 0x800A9868: lw          $t3, 0x8($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X8);
    // 0x800A986C: nop

    // 0x800A9870: lw          $a1, 0x64($t3)
    ctx->r5 = MEM_W(ctx->r11, 0X64);
    // 0x800A9874: nop

    // 0x800A9878: beq         $a1, $zero, L_800A98A4
    if (ctx->r5 == 0) {
        // 0x800A987C: nop
    
            goto L_800A98A4;
    }
    // 0x800A987C: nop

    // 0x800A9880: lh          $t4, 0x0($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X0);
    // 0x800A9884: nop

    // 0x800A9888: beq         $s3, $t4, L_800A98A4
    if (ctx->r19 == ctx->r12) {
        // 0x800A988C: nop
    
            goto L_800A98A4;
    }
    // 0x800A988C: nop

    // 0x800A9890: lb          $t5, 0x1D8($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X1D8);
    // 0x800A9894: nop

    // 0x800A9898: bne         $t5, $zero, L_800A98A4
    if (ctx->r13 != 0) {
        // 0x800A989C: nop
    
            goto L_800A98A4;
    }
    // 0x800A989C: nop

    // 0x800A98A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A98A4:
    // 0x800A98A4: lw          $t6, 0xC($s0)
    ctx->r14 = MEM_W(ctx->r16, 0XC);
    // 0x800A98A8: nop

    // 0x800A98AC: lw          $a1, 0x64($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X64);
    // 0x800A98B0: nop

    // 0x800A98B4: beq         $a1, $zero, L_800A98E0
    if (ctx->r5 == 0) {
        // 0x800A98B8: nop
    
            goto L_800A98E0;
    }
    // 0x800A98B8: nop

    // 0x800A98BC: lh          $t7, 0x0($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X0);
    // 0x800A98C0: nop

    // 0x800A98C4: beq         $s3, $t7, L_800A98E0
    if (ctx->r19 == ctx->r15) {
        // 0x800A98C8: nop
    
            goto L_800A98E0;
    }
    // 0x800A98C8: nop

    // 0x800A98CC: lb          $t8, 0x1D8($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1D8);
    // 0x800A98D0: nop

    // 0x800A98D4: bne         $t8, $zero, L_800A98E0
    if (ctx->r24 != 0) {
        // 0x800A98D8: nop
    
            goto L_800A98E0;
    }
    // 0x800A98D8: nop

    // 0x800A98DC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_800A98E0:
    // 0x800A98E0: bne         $s1, $a2, L_800A97F0
    if (ctx->r17 != ctx->r6) {
        // 0x800A98E4: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_800A97F0;
    }
    // 0x800A98E4: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
L_800A98E8:
    // 0x800A98E8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A98EC: lw          $t9, 0x6D0C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D0C);
    // 0x800A98F0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A98F4: bne         $t9, $at, L_800A9910
    if (ctx->r25 != ctx->r1) {
        // 0x800A98F8: nop
    
            goto L_800A9910;
    }
    // 0x800A98F8: nop

    // 0x800A98FC: jal         0x8006EAB0
    // 0x800A9900: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    is_postrace_viewport_active(rdram, ctx);
        goto after_29;
    // 0x800A9900: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    after_29:
    // 0x800A9904: lbu         $a0, 0x113($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X113);
    // 0x800A9908: bne         $v0, $zero, L_800AA3D0
    if (ctx->r2 != 0) {
        // 0x800A990C: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AA3D0;
    }
    // 0x800A990C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800A9910:
    // 0x800A9910: jal         0x80066510
    // 0x800A9914: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_30;
    // 0x800A9914: sb          $a0, 0x113($sp)
    MEM_B(0X113, ctx->r29) = ctx->r4;
    after_30:
    // 0x800A9918: lbu         $a0, 0x113($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X113);
    // 0x800A991C: bne         $v0, $zero, L_800AA3D0
    if (ctx->r2 != 0) {
        // 0x800A9920: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_800AA3D0;
    }
    // 0x800A9920: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800A9924: bne         $a0, $zero, L_800AA3CC
    if (ctx->r4 != 0) {
        // 0x800A9928: lui         $t2, 0x8012
        ctx->r10 = S32(0X8012 << 16);
            goto L_800AA3CC;
    }
    // 0x800A9928: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A992C: lw          $t2, 0x6D0C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D0C);
    // 0x800A9930: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800A9934: addu        $t3, $t3, $t2
    ctx->r11 = ADD32(ctx->r11, ctx->r10);
    // 0x800A9938: lb          $t3, 0x27A4($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X27A4);
    // 0x800A993C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A9940: beq         $t3, $at, L_800A9950
    if (ctx->r11 == ctx->r1) {
        // 0x800A9944: nop
    
            goto L_800A9950;
    }
    // 0x800A9944: nop

    // 0x800A9948: b           L_800AA3D0
    // 0x800A994C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
        goto L_800AA3D0;
    // 0x800A994C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800A9950:
    // 0x800A9950: jal         0x8007B3D0
    // 0x800A9954: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    rendermode_reset(rdram, ctx);
        goto after_31;
    // 0x800A9954: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_31:
    // 0x800A9958: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A995C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A9960: jal         0x80067F2C
    // 0x800A9964: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mtx_ortho(rdram, ctx);
        goto after_32;
    // 0x800A9964: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_32:
    // 0x800A9968: jal         0x8002C7C4
    // 0x800A996C: nop

    get_current_level_model(rdram, ctx);
        goto after_33;
    // 0x800A996C: nop

    after_33:
    // 0x800A9970: beq         $v0, $zero, L_800AA3CC
    if (ctx->r2 == 0) {
        // 0x800A9974: sw          $v0, 0x158($sp)
        MEM_W(0X158, ctx->r29) = ctx->r2;
            goto L_800AA3CC;
    }
    // 0x800A9974: sw          $v0, 0x158($sp)
    MEM_W(0X158, ctx->r29) = ctx->r2;
    // 0x800A9978: jal         0x80069D20
    // 0x800A997C: nop

    cam_get_active_camera(rdram, ctx);
        goto after_34;
    // 0x800A997C: nop

    after_34:
    // 0x800A9980: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800A9984: jal         0x80068508
    // 0x800A9988: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_35;
    // 0x800A9988: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_35:
    // 0x800A998C: lw          $t4, 0x158($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X158);
    // 0x800A9990: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A9994: lw          $v0, 0x6D0C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6D0C);
    // 0x800A9998: lw          $t5, 0x20($t4)
    ctx->r13 = MEM_W(ctx->r12, 0X20);
    // 0x800A999C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A99A0: beq         $v0, $at, L_800A99DC
    if (ctx->r2 == ctx->r1) {
        // 0x800A99A4: sw          $t5, 0x154($sp)
        MEM_W(0X154, ctx->r29) = ctx->r13;
            goto L_800A99DC;
    }
    // 0x800A99A4: sw          $t5, 0x154($sp)
    MEM_W(0X154, ctx->r29) = ctx->r13;
    // 0x800A99A8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A99AC: beq         $v0, $at, L_800A9A14
    if (ctx->r2 == ctx->r1) {
        // 0x800A99B0: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800A9A14;
    }
    // 0x800A99B0: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A99B4: beq         $v0, $at, L_800A9AF0
    if (ctx->r2 == ctx->r1) {
        // 0x800A99B8: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800A9AF0;
    }
    // 0x800A99B8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A99BC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A99C0: addiu       $t6, $zero, 0x87
    ctx->r14 = ADD32(0, 0X87);
    // 0x800A99C4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A99C8: sw          $t6, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->r14;
    // 0x800A99CC: addiu       $s0, $s0, 0x6D5C
    ctx->r16 = ADD32(ctx->r16, 0X6D5C);
    // 0x800A99D0: addiu       $t7, $zero, -0x62
    ctx->r15 = ADD32(0, -0X62);
    // 0x800A99D4: b           L_800A9B38
    // 0x800A99D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
        goto L_800A9B38;
    // 0x800A99D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_800A99DC:
    // 0x800A99DC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A99E0: lw          $t9, 0x6D20($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D20);
    // 0x800A99E4: addiu       $t8, $zero, 0x87
    ctx->r24 = ADD32(0, 0X87);
    // 0x800A99E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A99EC: sw          $t8, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->r24;
    // 0x800A99F0: negu        $t2, $t9
    ctx->r10 = SUB32(0, ctx->r25);
    // 0x800A99F4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A99F8: addiu       $s0, $s0, 0x6D5C
    ctx->r16 = ADD32(ctx->r16, 0X6D5C);
    // 0x800A99FC: bgez        $t2, L_800A9A0C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A9A00: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800A9A0C;
    }
    // 0x800A9A00: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800A9A04: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800A9A08: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800A9A0C:
    // 0x800A9A0C: b           L_800A9B38
    // 0x800A9A10: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
        goto L_800A9B38;
    // 0x800A9A10: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
L_800A9A14:
    // 0x800A9A14: jal         0x8006BD98
    // 0x800A9A18: nop

    level_type(rdram, ctx);
        goto after_36;
    // 0x800A9A18: nop

    after_36:
    // 0x800A9A1C: addiu       $at, $zero, 0x42
    ctx->r1 = ADD32(0, 0X42);
    // 0x800A9A20: beq         $v0, $at, L_800A9A50
    if (ctx->r2 == ctx->r1) {
        // 0x800A9A24: nop
    
            goto L_800A9A50;
    }
    // 0x800A9A24: nop

    // 0x800A9A28: jal         0x8006BD98
    // 0x800A9A2C: nop

    level_type(rdram, ctx);
        goto after_37;
    // 0x800A9A2C: nop

    after_37:
    // 0x800A9A30: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800A9A34: beq         $v0, $at, L_800A9A50
    if (ctx->r2 == ctx->r1) {
        // 0x800A9A38: nop
    
            goto L_800A9A50;
    }
    // 0x800A9A38: nop

    // 0x800A9A3C: jal         0x8006BD98
    // 0x800A9A40: nop

    level_type(rdram, ctx);
        goto after_38;
    // 0x800A9A40: nop

    after_38:
    // 0x800A9A44: addiu       $at, $zero, 0x41
    ctx->r1 = ADD32(0, 0X41);
    // 0x800A9A48: bne         $v0, $at, L_800A9AA0
    if (ctx->r2 != ctx->r1) {
        // 0x800A9A4C: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_800A9AA0;
    }
    // 0x800A9A4C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
L_800A9A50:
    // 0x800A9A50: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A9A54: lw          $t4, 0x6D1C($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D1C);
    // 0x800A9A58: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A9A5C: lw          $t7, 0x6D20($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D20);
    // 0x800A9A60: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800A9A64: negu        $t8, $t7
    ctx->r24 = SUB32(0, ctx->r15);
    // 0x800A9A68: addiu       $s0, $s0, 0x6D5C
    ctx->r16 = ADD32(ctx->r16, 0X6D5C);
    // 0x800A9A6C: bgez        $t4, L_800A9A7C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800A9A70: sra         $t5, $t4, 1
        ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
            goto L_800A9A7C;
    }
    // 0x800A9A70: sra         $t5, $t4, 1
    ctx->r13 = S32(SIGNED(ctx->r12) >> 1);
    // 0x800A9A74: addiu       $at, $t4, 0x1
    ctx->r1 = ADD32(ctx->r12, 0X1);
    // 0x800A9A78: sra         $t5, $at, 1
    ctx->r13 = S32(SIGNED(ctx->r1) >> 1);
L_800A9A7C:
    // 0x800A9A7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9A80: addiu       $t6, $t5, -0x8
    ctx->r14 = ADD32(ctx->r13, -0X8);
    // 0x800A9A84: sw          $t6, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->r14;
    // 0x800A9A88: bgez        $t8, L_800A9A98
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800A9A8C: sra         $t9, $t8, 1
        ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
            goto L_800A9A98;
    }
    // 0x800A9A8C: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800A9A90: addiu       $at, $t8, 0x1
    ctx->r1 = ADD32(ctx->r24, 0X1);
    // 0x800A9A94: sra         $t9, $at, 1
    ctx->r25 = S32(SIGNED(ctx->r1) >> 1);
L_800A9A98:
    // 0x800A9A98: b           L_800A9B38
    // 0x800A9A9C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
        goto L_800A9B38;
    // 0x800A9A9C: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
L_800A9AA0:
    // 0x800A9AA0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A9AA4: lw          $t2, 0x6D1C($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D1C);
    // 0x800A9AA8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A9AAC: lw          $t5, 0x6D20($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D20);
    // 0x800A9AB0: addiu       $t7, $zero, -0x3C
    ctx->r15 = ADD32(0, -0X3C);
    // 0x800A9AB4: addiu       $s0, $s0, 0x6D5C
    ctx->r16 = ADD32(ctx->r16, 0X6D5C);
    // 0x800A9AB8: bgez        $t2, L_800A9AC8
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800A9ABC: sra         $t3, $t2, 1
        ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
            goto L_800A9AC8;
    }
    // 0x800A9ABC: sra         $t3, $t2, 1
    ctx->r11 = S32(SIGNED(ctx->r10) >> 1);
    // 0x800A9AC0: addiu       $at, $t2, 0x1
    ctx->r1 = ADD32(ctx->r10, 0X1);
    // 0x800A9AC4: sra         $t3, $at, 1
    ctx->r11 = S32(SIGNED(ctx->r1) >> 1);
L_800A9AC8:
    // 0x800A9AC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9ACC: addiu       $t4, $t3, 0x48
    ctx->r12 = ADD32(ctx->r11, 0X48);
    // 0x800A9AD0: sw          $t4, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->r12;
    // 0x800A9AD4: bgez        $t5, L_800A9AE4
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800A9AD8: sra         $t6, $t5, 1
        ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
            goto L_800A9AE4;
    }
    // 0x800A9AD8: sra         $t6, $t5, 1
    ctx->r14 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800A9ADC: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x800A9AE0: sra         $t6, $at, 1
    ctx->r14 = S32(SIGNED(ctx->r1) >> 1);
L_800A9AE4:
    // 0x800A9AE4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800A9AE8: b           L_800A9B38
    // 0x800A9AEC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
        goto L_800A9B38;
    // 0x800A9AEC: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
L_800A9AF0:
    // 0x800A9AF0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800A9AF4: lw          $t9, 0x6D1C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X6D1C);
    // 0x800A9AF8: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A9AFC: lw          $t4, 0x6D20($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6D20);
    // 0x800A9B00: addiu       $s0, $s0, 0x6D5C
    ctx->r16 = ADD32(ctx->r16, 0X6D5C);
    // 0x800A9B04: bgez        $t9, L_800A9B14
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800A9B08: sra         $t2, $t9, 1
        ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
            goto L_800A9B14;
    }
    // 0x800A9B08: sra         $t2, $t9, 1
    ctx->r10 = S32(SIGNED(ctx->r25) >> 1);
    // 0x800A9B0C: addiu       $at, $t9, 0x1
    ctx->r1 = ADD32(ctx->r25, 0X1);
    // 0x800A9B10: sra         $t2, $at, 1
    ctx->r10 = S32(SIGNED(ctx->r1) >> 1);
L_800A9B14:
    // 0x800A9B14: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A9B18: addiu       $t3, $t2, -0x8
    ctx->r11 = ADD32(ctx->r10, -0X8);
    // 0x800A9B1C: sw          $t3, 0x6D58($at)
    MEM_W(0X6D58, ctx->r1) = ctx->r11;
    // 0x800A9B20: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x800A9B24: bgez        $t5, L_800A9B34
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800A9B28: sra         $t7, $t5, 1
        ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
            goto L_800A9B34;
    }
    // 0x800A9B28: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x800A9B2C: addiu       $at, $t5, 0x1
    ctx->r1 = ADD32(ctx->r13, 0X1);
    // 0x800A9B30: sra         $t7, $at, 1
    ctx->r15 = S32(SIGNED(ctx->r1) >> 1);
L_800A9B34:
    // 0x800A9B34: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_800A9B38:
    // 0x800A9B38: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A9B3C: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A9B40: nop

    // 0x800A9B44: bne         $t6, $zero, L_800A9B94
    if (ctx->r14 != 0) {
        // 0x800A9B48: nop
    
            goto L_800A9B94;
    }
    // 0x800A9B48: nop

    // 0x800A9B4C: lw          $t8, 0x0($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X0);
    // 0x800A9B50: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A9B54: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800A9B58: lwc1        $f11, -0x7838($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X7838);
    // 0x800A9B5C: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A9B60: lwc1        $f10, -0x7834($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7834);
    // 0x800A9B64: nop

    // 0x800A9B68: mul.d       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = MUL_D(ctx->f6.d, ctx->f10.d);
    // 0x800A9B6C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800A9B70: nop

    // 0x800A9B74: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800A9B78: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9B7C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9B80: nop

    // 0x800A9B84: cvt.w.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_D(ctx->f18.d);
    // 0x800A9B88: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800A9B8C: swc1        $f8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->f8.u32l;
    // 0x800A9B90: nop

L_800A9B94:
    // 0x800A9B94: jal         0x8007BF1C
    // 0x800A9B98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_39;
    // 0x800A9B98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_39:
    // 0x800A9B9C: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x800A9BA0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A9BA4: lw          $t2, 0x6D58($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X6D58);
    // 0x800A9BA8: mtc1        $t6, $f18
    ctx->f18.u32l = ctx->r14;
    // 0x800A9BAC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A9BB0: lw          $t3, 0x6D24($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X6D24);
    // 0x800A9BB4: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A9BB8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A9BBC: lw          $t5, 0x6D28($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D28);
    // 0x800A9BC0: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x800A9BC4: addu        $t7, $t4, $t5
    ctx->r15 = ADD32(ctx->r12, ctx->r13);
    // 0x800A9BC8: mtc1        $t7, $f16
    ctx->f16.u32l = ctx->r15;
    // 0x800A9BCC: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800A9BD0: cvt.s.w     $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    ctx->f0.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A9BD4: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800A9BD8: swc1        $f18, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->f18.u32l;
    // 0x800A9BDC: bne         $t8, $zero, L_800A9BF8
    if (ctx->r24 != 0) {
        // 0x800A9BE0: swc1        $f0, 0x12C($sp)
        MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
            goto L_800A9BF8;
    }
    // 0x800A9BE0: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
    // 0x800A9BE4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800A9BE8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9BEC: nop

    // 0x800A9BF0: sub.s       $f0, $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800A9BF4: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
L_800A9BF8:
    // 0x800A9BF8: lh          $t9, 0x4($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X4);
    // 0x800A9BFC: sh          $zero, 0x122($sp)
    MEM_H(0X122, ctx->r29) = 0;
    // 0x800A9C00: negu        $t2, $t9
    ctx->r10 = SUB32(0, ctx->r25);
    // 0x800A9C04: jal         0x8009C30C
    // 0x800A9C08: sh          $t2, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r10;
    get_filtered_cheats(rdram, ctx);
        goto after_40;
    // 0x800A9C08: sh          $t2, 0x124($sp)
    MEM_H(0X124, ctx->r29) = ctx->r10;
    after_40:
    // 0x800A9C0C: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x800A9C10: beq         $t3, $zero, L_800A9C40
    if (ctx->r11 == 0) {
        // 0x800A9C14: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800A9C40;
    }
    // 0x800A9C14: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A9C18: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A9C1C: lw          $t5, 0x6D1C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D1C);
    // 0x800A9C20: lwc1        $f0, 0x12C($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X12C);
    // 0x800A9C24: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800A9C28: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x800A9C2C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A9C30: sh          $t4, 0x120($sp)
    MEM_H(0X120, ctx->r29) = ctx->r12;
    // 0x800A9C34: sub.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f0.fl - ctx->f8.fl;
    // 0x800A9C38: b           L_800A9C44
    // 0x800A9C3C: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
        goto L_800A9C44;
    // 0x800A9C3C: swc1        $f0, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = ctx->f0.u32l;
L_800A9C40:
    // 0x800A9C40: sh          $zero, 0x120($sp)
    MEM_H(0X120, ctx->r29) = 0;
L_800A9C44:
    // 0x800A9C44: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A9C48: lw          $t7, 0x10C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X10C);
    // 0x800A9C4C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A9C50: slti        $at, $t7, 0xA1
    ctx->r1 = SIGNED(ctx->r15) < 0XA1 ? 1 : 0;
    // 0x800A9C54: sh          $zero, 0x138($sp)
    MEM_H(0X138, ctx->r29) = 0;
    // 0x800A9C58: swc1        $f4, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->f4.u32l;
    // 0x800A9C5C: sw          $t7, 0x108($sp)
    MEM_W(0X108, ctx->r29) = ctx->r15;
    // 0x800A9C60: bne         $at, $zero, L_800A9C70
    if (ctx->r1 != 0) {
        // 0x800A9C64: swc1        $f16, 0x134($sp)
        MEM_W(0X134, ctx->r29) = ctx->f16.u32l;
            goto L_800A9C70;
    }
    // 0x800A9C64: swc1        $f16, 0x134($sp)
    MEM_W(0X134, ctx->r29) = ctx->f16.u32l;
    // 0x800A9C68: addiu       $t6, $zero, 0xA0
    ctx->r14 = ADD32(0, 0XA0);
    // 0x800A9C6C: sw          $t6, 0x10C($sp)
    MEM_W(0X10C, ctx->r29) = ctx->r14;
L_800A9C70:
    // 0x800A9C70: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A9C74: lbu         $t8, 0x6D37($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X6D37);
    // 0x800A9C78: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A9C7C: bne         $t8, $at, L_800A9CB0
    if (ctx->r24 != ctx->r1) {
        // 0x800A9C80: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800A9CB0;
    }
    // 0x800A9C80: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A9C84: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800A9C88: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800A9C8C: addiu       $t9, $t0, 0x8
    ctx->r25 = ADD32(ctx->r8, 0X8);
    // 0x800A9C90: sw          $t9, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r25;
    // 0x800A9C94: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800A9C98: lw          $t3, 0x10C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X10C);
    // 0x800A9C9C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800A9CA0: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800A9CA4: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800A9CA8: b           L_800A9D00
    // 0x800A9CAC: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
        goto L_800A9D00;
    // 0x800A9CAC: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
L_800A9CB0:
    // 0x800A9CB0: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800A9CB4: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A9CB8: addiu       $t7, $t0, 0x8
    ctx->r15 = ADD32(ctx->r8, 0X8);
    // 0x800A9CBC: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x800A9CC0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A9CC4: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800A9CC8: lbu         $t4, 0x6D55($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X6D55);
    // 0x800A9CCC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A9CD0: lbu         $t9, 0x6D54($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X6D54);
    // 0x800A9CD4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A9CD8: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x800A9CDC: lbu         $t8, 0x6D56($t6)
    ctx->r24 = MEM_BU(ctx->r14, 0X6D56);
    // 0x800A9CE0: sll         $t2, $t9, 24
    ctx->r10 = S32(ctx->r25 << 24);
    // 0x800A9CE4: lw          $t4, 0x10C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X10C);
    // 0x800A9CE8: or          $t7, $t2, $t5
    ctx->r15 = ctx->r10 | ctx->r13;
    // 0x800A9CEC: sll         $t9, $t8, 8
    ctx->r25 = S32(ctx->r24 << 8);
    // 0x800A9CF0: or          $t3, $t7, $t9
    ctx->r11 = ctx->r15 | ctx->r25;
    // 0x800A9CF4: andi        $t2, $t4, 0xFF
    ctx->r10 = ctx->r12 & 0XFF;
    // 0x800A9CF8: or          $t5, $t3, $t2
    ctx->r13 = ctx->r11 | ctx->r10;
    // 0x800A9CFC: sw          $t5, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r13;
L_800A9D00:
    // 0x800A9D00: lw          $t6, 0x154($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X154);
    // 0x800A9D04: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9D08: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A9D0C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A9D10: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A9D14: addiu       $a3, $sp, 0x120
    ctx->r7 = ADD32(ctx->r29, 0X120);
    // 0x800A9D18: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    extern void dkr_hud_minimap_begin(uint8_t*, recomp_context*); dkr_hud_minimap_begin(rdram, ctx);
    // 0x800A9D1C: jal         0x80068BF4
    // 0x800A9D20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    render_ortho_triangle_image(rdram, ctx);
        goto after_41;
    // 0x800A9D20: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_41:
    extern void dkr_hud_minimap_end(uint8_t*, recomp_context*); dkr_hud_minimap_end(rdram, ctx);
    // 0x800A9D24: lw          $v0, 0x158($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X158);
    // 0x800A9D28: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800A9D2C: lh          $t8, 0x3E($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X3E);
    // 0x800A9D30: lh          $t7, 0x3C($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X3C);
    // 0x800A9D34: lh          $t4, 0x46($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X46);
    // 0x800A9D38: lh          $t3, 0x44($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X44);
    // 0x800A9D3C: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x800A9D40: subu        $t2, $t4, $t3
    ctx->r10 = SUB32(ctx->r12, ctx->r11);
    // 0x800A9D44: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x800A9D48: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800A9D4C: cvt.s.w     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A9D50: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A9D54: nop

    // 0x800A9D58: div.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = DIV_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800A9D5C: swc1        $f16, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->f16.u32l;
    // 0x800A9D60: lhu         $a0, 0x24($v0)
    ctx->r4 = MEM_HU(ctx->r2, 0X24);
    // 0x800A9D64: nop

    // 0x800A9D68: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800A9D6C: subu        $t5, $t5, $a0
    ctx->r13 = SUB32(ctx->r13, ctx->r4);
    // 0x800A9D70: div         $zero, $t5, $at
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r1)));
    // 0x800A9D74: mflo        $t6
    ctx->r14 = lo;
    // 0x800A9D78: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800A9D7C: jal         0x800707F8
    // 0x800A9D80: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    coss_f(rdram, ctx);
        goto after_42;
    // 0x800A9D80: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_42:
    // 0x800A9D84: lw          $t9, 0x158($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X158);
    // 0x800A9D88: swc1        $f0, 0x118($sp)
    MEM_W(0X118, ctx->r29) = ctx->f0.u32l;
    // 0x800A9D8C: lhu         $a0, 0x24($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X24);
    // 0x800A9D90: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800A9D94: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x800A9D98: subu        $t4, $t4, $a0
    ctx->r12 = SUB32(ctx->r12, ctx->r4);
    // 0x800A9D9C: div         $zero, $t4, $at
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r1)));
    // 0x800A9DA0: mflo        $t3
    ctx->r11 = lo;
    // 0x800A9DA4: sll         $t2, $t3, 16
    ctx->r10 = S32(ctx->r11 << 16);
    // 0x800A9DA8: jal         0x800707C4
    // 0x800A9DAC: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    sins_f(rdram, ctx);
        goto after_43;
    // 0x800A9DAC: sra         $a0, $t2, 16
    ctx->r4 = S32(SIGNED(ctx->r10) >> 16);
    after_43:
    // 0x800A9DB0: jal         0x8000E4D8
    // 0x800A9DB4: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    is_in_time_trial(rdram, ctx);
        goto after_44;
    // 0x800A9DB4: swc1        $f0, 0x114($sp)
    MEM_W(0X114, ctx->r29) = ctx->f0.u32l;
    after_44:
    // 0x800A9DB8: beq         $v0, $zero, L_800A9EC8
    if (ctx->r2 == 0) {
        // 0x800A9DBC: nop
    
            goto L_800A9EC8;
    }
    // 0x800A9DBC: nop

    // 0x800A9DC0: jal         0x8001B288
    // 0x800A9DC4: nop

    timetrial_valid_player_ghost(rdram, ctx);
        goto after_45;
    // 0x800A9DC4: nop

    after_45:
    // 0x800A9DC8: beq         $v0, $zero, L_800A9EC8
    if (ctx->r2 == 0) {
        // 0x800A9DCC: nop
    
            goto L_800A9EC8;
    }
    // 0x800A9DCC: nop

    // 0x800A9DD0: jal         0x8001B2E0
    // 0x800A9DD4: nop

    timetrial_player_ghost(rdram, ctx);
        goto after_46;
    // 0x800A9DD4: nop

    after_46:
    // 0x800A9DD8: beq         $v0, $zero, L_800A9EC8
    if (ctx->r2 == 0) {
        // 0x800A9DDC: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800A9EC8;
    }
    // 0x800A9DDC: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A9DE0: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800A9DE4: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A9DE8: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800A9DEC: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800A9DF0: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800A9DF4: jal         0x800AA3EC
    // 0x800A9DF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_47;
    // 0x800A9DF8: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_47:
    // 0x800A9DFC: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A9E00: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800A9E04: sh          $t6, 0x1E6($t8)
    MEM_H(0X1E6, ctx->r24) = ctx->r14;
    // 0x800A9E08: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800A9E0C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A9E10: sh          $zero, 0x1E4($t7)
    MEM_H(0X1E4, ctx->r15) = 0;
    // 0x800A9E14: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800A9E18: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800A9E1C: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A9E20: swc1        $f6, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f6.u32l;
    // 0x800A9E24: lbu         $t3, 0x39($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X39);
    // 0x800A9E28: lw          $t4, 0x108($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X108);
    // 0x800A9E2C: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800A9E30: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800A9E34: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A9E38: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A9E3C: bgez        $t3, L_800A9E54
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A9E40: cvt.s.w     $f10, $f18
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800A9E54;
    }
    // 0x800A9E40: cvt.s.w     $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    ctx->f10.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800A9E44: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A9E48: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800A9E4C: nop

    // 0x800A9E50: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_800A9E54:
    // 0x800A9E54: mul.s       $f6, $f10, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A9E58: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A9E5C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A9E60: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800A9E64: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800A9E68: mul.d       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f8.d);
    // 0x800A9E6C: addiu       $t5, $t0, 0x8
    ctx->r13 = ADD32(ctx->r8, 0X8);
    // 0x800A9E70: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800A9E74: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800A9E78: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9E7C: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A9E80: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A9E84: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A9E88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9E8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9E90: lui         $at, 0x3C3C
    ctx->r1 = S32(0X3C3C << 16);
    // 0x800A9E94: cvt.w.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.u32l = CVT_W_D(ctx->f4.d);
    // 0x800A9E98: ori         $at, $at, 0x3C00
    ctx->r1 = ctx->r1 | 0X3C00;
    // 0x800A9E9C: mfc1        $v1, $f10
    ctx->r3 = (int32_t)ctx->f10.u32l;
    // 0x800A9EA0: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A9EA4: andi        $t8, $v1, 0xFF
    ctx->r24 = ctx->r3 & 0XFF;
    // 0x800A9EA8: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x800A9EAC: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800A9EB0: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A9EB4: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A9EB8: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A9EBC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A9EC0: jal         0x800AA600
    // 0x800A9EC4: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_48;
    // 0x800A9EC4: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_48:
L_800A9EC8:
    // 0x800A9EC8: jal         0x8001B640
    // 0x800A9ECC: nop

    timetrial_ghost_staff(rdram, ctx);
        goto after_49;
    // 0x800A9ECC: nop

    after_49:
    // 0x800A9ED0: beq         $v0, $zero, L_800A9FE8
    if (ctx->r2 == 0) {
        // 0x800A9ED4: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_800A9FE8;
    }
    // 0x800A9ED4: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800A9ED8: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800A9EDC: lwc1        $f16, 0x11C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800A9EE0: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800A9EE4: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800A9EE8: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A9EEC: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800A9EF0: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800A9EF4: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800A9EF8: swc1        $f18, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f18.u32l;
    // 0x800A9EFC: jal         0x800AA3EC
    // 0x800A9F00: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_50;
    // 0x800A9F00: swc1        $f16, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f16.u32l;
    after_50:
    // 0x800A9F04: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800A9F08: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800A9F0C: sh          $zero, 0x1E4($t4)
    MEM_H(0X1E4, ctx->r12) = 0;
    // 0x800A9F10: lbu         $t3, 0x39($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X39);
    // 0x800A9F14: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800A9F18: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x800A9F1C: addiu       $t1, $t1, 0x27BC
    ctx->r9 = ADD32(ctx->r9, 0X27BC);
    // 0x800A9F20: bgez        $t3, L_800A9F38
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800A9F24: cvt.s.w     $f10, $f4
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800A9F38;
    }
    // 0x800A9F24: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800A9F28: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800A9F2C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A9F30: nop

    // 0x800A9F34: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800A9F38:
    // 0x800A9F38: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800A9F3C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A9F40: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A9F44: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A9F48: cvt.d.s     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f18.d = CVT_D_S(ctx->f6.fl);
    // 0x800A9F4C: mul.d       $f16, $f18, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f16.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x800A9F50: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800A9F54: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800A9F58: addiu       $t5, $t0, 0x8
    ctx->r13 = ADD32(ctx->r8, 0X8);
    // 0x800A9F5C: sw          $t5, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r13;
    // 0x800A9F60: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800A9F64: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800A9F68: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800A9F6C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A9F70: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A9F74: lbu         $t7, 0x1A($t1)
    ctx->r15 = MEM_BU(ctx->r9, 0X1A);
    // 0x800A9F78: cvt.w.d     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.u32l = CVT_W_D(ctx->f16.d);
    // 0x800A9F7C: lbu         $t3, 0x18($t1)
    ctx->r11 = MEM_BU(ctx->r9, 0X18);
    // 0x800A9F80: lbu         $t8, 0x19($t1)
    ctx->r24 = MEM_BU(ctx->r9, 0X19);
    // 0x800A9F84: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800A9F88: sll         $t9, $t7, 8
    ctx->r25 = S32(ctx->r15 << 8);
    // 0x800A9F8C: mfc1        $v1, $f8
    ctx->r3 = (int32_t)ctx->f8.u32l;
    // 0x800A9F90: sll         $t2, $t3, 24
    ctx->r10 = S32(ctx->r11 << 24);
    // 0x800A9F94: or          $t5, $t9, $t2
    ctx->r13 = ctx->r25 | ctx->r10;
    // 0x800A9F98: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800A9F9C: or          $t4, $t5, $t7
    ctx->r12 = ctx->r13 | ctx->r15;
    // 0x800A9FA0: andi        $t3, $v1, 0xFF
    ctx->r11 = ctx->r3 & 0XFF;
    // 0x800A9FA4: or          $t9, $t4, $t3
    ctx->r25 = ctx->r12 | ctx->r11;
    // 0x800A9FA8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A9FAC: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x800A9FB0: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x800A9FB4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800A9FB8: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800A9FBC: swc1        $f10, 0x1E8($t2)
    MEM_W(0X1E8, ctx->r10) = ctx->f10.u32l;
    // 0x800A9FC0: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800A9FC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A9FC8: sh          $t6, 0x1E6($t8)
    MEM_H(0X1E6, ctx->r24) = ctx->r14;
    // 0x800A9FCC: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800A9FD0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A9FD4: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A9FD8: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A9FDC: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800A9FE0: jal         0x800AA600
    // 0x800A9FE4: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_51;
    // 0x800A9FE4: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_51:
L_800A9FE8:
    // 0x800A9FE8: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A9FEC: lw          $t5, 0x6D60($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D60);
    // 0x800A9FF0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800A9FF4: lb          $t7, 0x4C($t5)
    ctx->r15 = MEM_B(ctx->r13, 0X4C);
    // 0x800A9FF8: nop

    // 0x800A9FFC: bne         $t7, $at, L_800AA0A4
    if (ctx->r15 != ctx->r1) {
        // 0x800AA000: lw          $v0, 0x140($sp)
        ctx->r2 = MEM_W(ctx->r29, 0X140);
            goto L_800AA0A4;
    }
    // 0x800AA000: lw          $v0, 0x140($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X140);
    // 0x800AA004: jal         0x80018C6C
    // 0x800AA008: nop

    find_taj_object(rdram, ctx);
        goto after_52;
    // 0x800AA008: nop

    after_52:
    // 0x800AA00C: beq         $v0, $zero, L_800AA0A0
    if (ctx->r2 == 0) {
        // 0x800AA010: nop
    
            goto L_800AA0A0;
    }
    // 0x800AA010: nop

    // 0x800AA014: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800AA018: addiu       $t4, $zero, 0xE
    ctx->r12 = ADD32(0, 0XE);
    // 0x800AA01C: sh          $t4, 0x1E6($t3)
    MEM_H(0X1E6, ctx->r11) = ctx->r12;
    // 0x800AA020: lwc1        $f6, 0x11C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AA024: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800AA028: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800AA02C: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AA030: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AA034: jal         0x800AA3EC
    // 0x800AA038: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_53;
    // 0x800AA038: swc1        $f6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f6.u32l;
    after_53:
    // 0x800AA03C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AA040: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800AA044: sh          $zero, 0x1E4($t9)
    MEM_H(0X1E4, ctx->r25) = 0;
    // 0x800AA048: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA04C: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800AA050: addiu       $t2, $t0, 0x8
    ctx->r10 = ADD32(ctx->r8, 0X8);
    // 0x800AA054: sw          $t2, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r10;
    // 0x800AA058: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800AA05C: lw          $t8, 0x108($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X108);
    // 0x800AA060: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x800AA064: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x800AA068: or          $t7, $t5, $at
    ctx->r15 = ctx->r13 | ctx->r1;
    // 0x800AA06C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA070: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x800AA074: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x800AA078: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA07C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA080: swc1        $f18, 0x1E8($t4)
    MEM_W(0X1E8, ctx->r12) = ctx->f18.u32l;
    // 0x800AA084: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
    // 0x800AA088: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA08C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800AA090: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800AA094: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA098: jal         0x800AA600
    // 0x800AA09C: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_54;
    // 0x800AA09C: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_54:
L_800AA0A0:
    // 0x800AA0A0: lw          $v0, 0x140($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X140);
L_800AA0A4:
    // 0x800AA0A4: lw          $t3, 0x150($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X150);
    // 0x800AA0A8: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800AA0AC: bltz        $v0, L_800AA374
    if (SIGNED(ctx->r2) < 0) {
        // 0x800AA0B0: sll         $s1, $v0, 2
        ctx->r17 = S32(ctx->r2 << 2);
            goto L_800AA374;
    }
    // 0x800AA0B0: sll         $s1, $v0, 2
    ctx->r17 = S32(ctx->r2 << 2);
    // 0x800AA0B4: addu        $s0, $t3, $s1
    ctx->r16 = ADD32(ctx->r11, ctx->r17);
L_800AA0B8:
    // 0x800AA0B8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x800AA0BC: lw          $a2, 0x114($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X114);
    // 0x800AA0C0: lw          $a1, 0x64($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X64);
    // 0x800AA0C4: lw          $a3, 0x118($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X118);
    // 0x800AA0C8: beq         $a1, $zero, L_800AA368
    if (ctx->r5 == 0) {
        // 0x800AA0CC: nop
    
            goto L_800AA368;
    }
    // 0x800AA0CC: nop

    // 0x800AA0D0: lw          $t9, 0x108($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X108);
    // 0x800AA0D4: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800AA0D8: lwc1        $f14, 0x14($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800AA0DC: lwc1        $f4, 0x11C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X11C);
    // 0x800AA0E0: andi        $t2, $t9, 0xFF
    ctx->r10 = ctx->r25 & 0XFF;
    // 0x800AA0E4: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x800AA0E8: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    // 0x800AA0EC: jal         0x800AA3EC
    // 0x800AA0F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    minimap_marker_pos(rdram, ctx);
        goto after_55;
    // 0x800AA0F0: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_55:
    // 0x800AA0F4: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA0F8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA0FC: lh          $t6, 0x0($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X0);
    // 0x800AA100: nop

    // 0x800AA104: beq         $s3, $t6, L_800AA1A4
    if (ctx->r19 == ctx->r14) {
        // 0x800AA108: nop
    
            goto L_800AA1A4;
    }
    // 0x800AA108: nop

    // 0x800AA10C: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800AA110: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA114: lwc1        $f16, 0x1F0($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X1F0);
    // 0x800AA118: addiu       $t8, $zero, 0x1B
    ctx->r24 = ADD32(0, 0X1B);
    // 0x800AA11C: sub.s       $f10, $f16, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800AA120: addiu       $at, $zero, 0x168
    ctx->r1 = ADD32(0, 0X168);
    // 0x800AA124: swc1        $f10, 0x1F0($v0)
    MEM_W(0X1F0, ctx->r2) = ctx->f10.u32l;
    // 0x800AA128: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800AA12C: nop

    // 0x800AA130: sh          $t8, 0x1E6($t5)
    MEM_H(0X1E6, ctx->r13) = ctx->r24;
    // 0x800AA134: lw          $t3, 0x158($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X158);
    // 0x800AA138: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x800AA13C: lhu         $t9, 0x24($t3)
    ctx->r25 = MEM_HU(ctx->r11, 0X24);
    // 0x800AA140: lh          $t4, 0x0($t7)
    ctx->r12 = MEM_H(ctx->r15, 0X0);
    // 0x800AA144: sll         $t2, $t9, 16
    ctx->r10 = S32(ctx->r25 << 16);
    // 0x800AA148: subu        $t2, $t2, $t9
    ctx->r10 = SUB32(ctx->r10, ctx->r25);
    // 0x800AA14C: div         $zero, $t2, $at
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r1)));
    // 0x800AA150: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AA154: mflo        $t6
    ctx->r14 = lo;
    // 0x800AA158: subu        $t5, $t4, $t6
    ctx->r13 = SUB32(ctx->r12, ctx->r14);
    // 0x800AA15C: sh          $t5, 0x1E4($t7)
    MEM_H(0X1E4, ctx->r15) = ctx->r13;
    // 0x800AA160: jal         0x8009C30C
    // 0x800AA164: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    get_filtered_cheats(rdram, ctx);
        goto after_56;
    // 0x800AA164: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_56:
    // 0x800AA168: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA16C: andi        $t3, $v0, 0x4
    ctx->r11 = ctx->r2 & 0X4;
    // 0x800AA170: beq         $t3, $zero, L_800AA190
    if (ctx->r11 == 0) {
        // 0x800AA174: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800AA190;
    }
    // 0x800AA174: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800AA178: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800AA17C: ori         $t2, $zero, 0xFFFF
    ctx->r10 = 0 | 0XFFFF;
    // 0x800AA180: lh          $t9, 0x1E4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X1E4);
    // 0x800AA184: nop

    // 0x800AA188: subu        $t4, $t2, $t9
    ctx->r12 = SUB32(ctx->r10, ctx->r25);
    // 0x800AA18C: sh          $t4, 0x1E4($v0)
    MEM_H(0X1E4, ctx->r2) = ctx->r12;
L_800AA190:
    // 0x800AA190: jal         0x8007BF1C
    // 0x800AA194: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    sprite_opaque(rdram, ctx);
        goto after_57;
    // 0x800AA194: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_57:
    // 0x800AA198: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA19C: b           L_800AA1BC
    // 0x800AA1A0: nop

        goto L_800AA1BC;
    // 0x800AA1A0: nop

L_800AA1A4:
    // 0x800AA1A4: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AA1A8: addiu       $t8, $zero, 0xE
    ctx->r24 = ADD32(0, 0XE);
    // 0x800AA1AC: sh          $zero, 0x1E4($t6)
    MEM_H(0X1E4, ctx->r14) = 0;
    // 0x800AA1B0: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800AA1B4: nop

    // 0x800AA1B8: sh          $t8, 0x1E6($t5)
    MEM_H(0X1E6, ctx->r13) = ctx->r24;
L_800AA1BC:
    // 0x800AA1BC: jal         0x8002341C
    // 0x800AA1C0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    is_taj_challenge(rdram, ctx);
        goto after_58;
    // 0x800AA1C0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_58:
    // 0x800AA1C4: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA1C8: beq         $v0, $zero, L_800AA208
    if (ctx->r2 == 0) {
        // 0x800AA1CC: lui         $t8, 0xFA00
        ctx->r24 = S32(0XFA00 << 16);
            goto L_800AA208;
    }
    // 0x800AA1CC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800AA1D0: lb          $t7, 0x1D6($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X1D6);
    // 0x800AA1D4: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800AA1D8: bne         $t7, $at, L_800AA208
    if (ctx->r15 != ctx->r1) {
        // 0x800AA1DC: lui         $t2, 0xFA00
        ctx->r10 = S32(0XFA00 << 16);
            goto L_800AA208;
    }
    // 0x800AA1DC: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800AA1E0: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA1E4: lui         $at, 0xFF00
    ctx->r1 = S32(0XFF00 << 16);
    // 0x800AA1E8: addiu       $t3, $t0, 0x8
    ctx->r11 = ADD32(ctx->r8, 0X8);
    // 0x800AA1EC: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800AA1F0: sw          $t2, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r10;
    // 0x800AA1F4: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x800AA1F8: ori         $at, $at, 0xFF00
    ctx->r1 = ctx->r1 | 0XFF00;
    // 0x800AA1FC: or          $t4, $t9, $at
    ctx->r12 = ctx->r25 | ctx->r1;
    // 0x800AA200: b           L_800AA25C
    // 0x800AA204: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
        goto L_800AA25C;
    // 0x800AA204: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
L_800AA208:
    // 0x800AA208: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA20C: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800AA210: addiu       $t6, $t0, 0x8
    ctx->r14 = ADD32(ctx->r8, 0X8);
    // 0x800AA214: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x800AA218: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x800AA21C: lb          $t5, 0x3($a1)
    ctx->r13 = MEM_B(ctx->r5, 0X3);
    // 0x800AA220: addiu       $t3, $t3, 0x27BC
    ctx->r11 = ADD32(ctx->r11, 0X27BC);
    // 0x800AA224: sll         $t7, $t5, 2
    ctx->r15 = S32(ctx->r13 << 2);
    // 0x800AA228: subu        $t7, $t7, $t5
    ctx->r15 = SUB32(ctx->r15, ctx->r13);
    // 0x800AA22C: addu        $v0, $t7, $t3
    ctx->r2 = ADD32(ctx->r15, ctx->r11);
    // 0x800AA230: lbu         $t9, 0x2($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X2);
    // 0x800AA234: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800AA238: lbu         $t2, 0x1($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X1);
    // 0x800AA23C: sll         $t4, $t9, 8
    ctx->r12 = S32(ctx->r25 << 8);
    // 0x800AA240: sll         $t5, $t8, 24
    ctx->r13 = S32(ctx->r24 << 24);
    // 0x800AA244: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x800AA248: or          $t7, $t4, $t5
    ctx->r15 = ctx->r12 | ctx->r13;
    // 0x800AA24C: sll         $t9, $t2, 16
    ctx->r25 = S32(ctx->r10 << 16);
    // 0x800AA250: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x800AA254: or          $t4, $t6, $t8
    ctx->r12 = ctx->r14 | ctx->r24;
    // 0x800AA258: sw          $t4, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r12;
L_800AA25C:
    // 0x800AA25C: jal         0x8006BD98
    // 0x800AA260: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    level_type(rdram, ctx);
        goto after_59;
    // 0x800AA260: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_59:
    // 0x800AA264: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA268: andi        $t5, $v0, 0x40
    ctx->r13 = ctx->r2 & 0X40;
    // 0x800AA26C: beq         $t5, $zero, L_800AA284
    if (ctx->r13 == 0) {
        // 0x800AA270: lui         $t2, 0x8000
        ctx->r10 = S32(0X8000 << 16);
            goto L_800AA284;
    }
    // 0x800AA270: lui         $t2, 0x8000
    ctx->r10 = S32(0X8000 << 16);
    // 0x800AA274: lb          $t3, 0x1D8($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X1D8);
    // 0x800AA278: nop

    // 0x800AA27C: bne         $t3, $zero, L_800AA360
    if (ctx->r11 != 0) {
        // 0x800AA280: nop
    
            goto L_800AA360;
    }
    // 0x800AA280: nop

L_800AA284:
    // 0x800AA284: lw          $t2, 0x300($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X300);
    // 0x800AA288: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800AA28C: bne         $t2, $zero, L_800AA2AC
    if (ctx->r10 != 0) {
        // 0x800AA290: nop
    
            goto L_800AA2AC;
    }
    // 0x800AA290: nop

    // 0x800AA294: lw          $v0, 0x0($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X0);
    // 0x800AA298: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800AA29C: lwc1        $f6, 0x1EC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X1EC);
    // 0x800AA2A0: nop

    // 0x800AA2A4: sub.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800AA2A8: swc1        $f4, 0x1EC($v0)
    MEM_W(0X1EC, ctx->r2) = ctx->f4.u32l;
L_800AA2AC:
    // 0x800AA2AC: jal         0x8006BD98
    // 0x800AA2B0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    level_type(rdram, ctx);
        goto after_60;
    // 0x800AA2B0: sw          $a1, 0x148($sp)
    MEM_W(0X148, ctx->r29) = ctx->r5;
    after_60:
    // 0x800AA2B4: lw          $a1, 0x148($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X148);
    // 0x800AA2B8: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800AA2BC: bne         $v0, $at, L_800AA330
    if (ctx->r2 != ctx->r1) {
        // 0x800AA2C0: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_800AA330;
    }
    // 0x800AA2C0: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x800AA2C4: lb          $v0, 0x212($a1)
    ctx->r2 = MEM_B(ctx->r5, 0X212);
    // 0x800AA2C8: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AA2CC: beq         $v0, $zero, L_800AA2F8
    if (ctx->r2 == 0) {
        // 0x800AA2D0: nop
    
            goto L_800AA2F8;
    }
    // 0x800AA2D0: nop

    // 0x800AA2D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800AA2D8: beq         $v0, $at, L_800AA308
    if (ctx->r2 == ctx->r1) {
        // 0x800AA2DC: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800AA308;
    }
    // 0x800AA2DC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800AA2E0: beq         $v0, $at, L_800AA31C
    if (ctx->r2 == ctx->r1) {
        // 0x800AA2E4: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800AA31C;
    }
    // 0x800AA2E4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800AA2E8: beq         $v0, $at, L_800AA31C
    if (ctx->r2 == ctx->r1) {
        // 0x800AA2EC: nop
    
            goto L_800AA31C;
    }
    // 0x800AA2EC: nop

    // 0x800AA2F0: b           L_800AA348
    // 0x800AA2F4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
        goto L_800AA348;
    // 0x800AA2F4: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
L_800AA2F8:
    // 0x800AA2F8: lwc1        $f16, -0x7830($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X7830);
    // 0x800AA2FC: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800AA300: b           L_800AA344
    // 0x800AA304: swc1        $f16, 0x1E8($t7)
    MEM_W(0X1E8, ctx->r15) = ctx->f16.u32l;
        goto L_800AA344;
    // 0x800AA304: swc1        $f16, 0x1E8($t7)
    MEM_W(0X1E8, ctx->r15) = ctx->f16.u32l;
L_800AA308:
    // 0x800AA308: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA30C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800AA310: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x800AA314: b           L_800AA344
    // 0x800AA318: swc1        $f8, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f8.u32l;
        goto L_800AA344;
    // 0x800AA318: swc1        $f8, 0x1E8($t9)
    MEM_W(0X1E8, ctx->r25) = ctx->f8.u32l;
L_800AA31C:
    // 0x800AA31C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800AA320: lwc1        $f10, -0x782C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X782C);
    // 0x800AA324: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800AA328: b           L_800AA344
    // 0x800AA32C: swc1        $f10, 0x1E8($t6)
    MEM_W(0X1E8, ctx->r14) = ctx->f10.u32l;
        goto L_800AA344;
    // 0x800AA32C: swc1        $f10, 0x1E8($t6)
    MEM_W(0X1E8, ctx->r14) = ctx->f10.u32l;
L_800AA330:
    // 0x800AA330: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800AA334: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800AA338: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x800AA33C: nop

    // 0x800AA340: swc1        $f6, 0x1E8($t8)
    MEM_W(0X1E8, ctx->r24) = ctx->f6.u32l;
L_800AA344:
    // 0x800AA344: lw          $a3, 0x0($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X0);
L_800AA348:
    // 0x800AA348: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800AA34C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800AA350: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800AA354: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800AA358: jal         0x800AA600
    // 0x800AA35C: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    hud_element_render(rdram, ctx);
        goto after_61;
    // 0x800AA35C: addiu       $a3, $a3, 0x1E0
    ctx->r7 = ADD32(ctx->r7, 0X1E0);
    after_61:
L_800AA360:
    // 0x800AA360: jal         0x8007BF1C
    // 0x800AA364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_62;
    // 0x800AA364: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_62:
L_800AA368:
    // 0x800AA368: addiu       $s1, $s1, -0x4
    ctx->r17 = ADD32(ctx->r17, -0X4);
    // 0x800AA36C: bgez        $s1, L_800AA0B8
    if (SIGNED(ctx->r17) >= 0) {
        // 0x800AA370: addiu       $s0, $s0, -0x4
        ctx->r16 = ADD32(ctx->r16, -0X4);
            goto L_800AA0B8;
    }
    // 0x800AA370: addiu       $s0, $s0, -0x4
    ctx->r16 = ADD32(ctx->r16, -0X4);
L_800AA374:
    // 0x800AA374: lw          $t0, 0x0($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X0);
    // 0x800AA378: lui         $t5, 0xE700
    ctx->r13 = S32(0XE700 << 16);
    // 0x800AA37C: addiu       $t4, $t0, 0x8
    ctx->r12 = ADD32(ctx->r8, 0X8);
    // 0x800AA380: sw          $t4, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r12;
    // 0x800AA384: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800AA388: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x800AA38C: jal         0x80068508
    // 0x800AA390: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_63;
    // 0x800AA390: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
    after_63:
    // 0x800AA394: jal         0x8007BF1C
    // 0x800AA398: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_64;
    // 0x800AA398: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_64:
    // 0x800AA39C: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x800AA3A0: lw          $t2, 0x160($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X160);
    // 0x800AA3A4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800AA3A8: sw          $t3, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r11;
    // 0x800AA3AC: lw          $t9, 0x164($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X164);
    // 0x800AA3B0: lw          $t7, 0x6D00($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D00);
    // 0x800AA3B4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800AA3B8: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
    // 0x800AA3BC: lw          $t8, 0x168($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X168);
    // 0x800AA3C0: lw          $t6, 0x6D04($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6D04);
    // 0x800AA3C4: nop

    // 0x800AA3C8: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
L_800AA3CC:
    // 0x800AA3CC: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_800AA3D0:
    extern void dkr_hud_general_pass_end(uint8_t*, recomp_context*); dkr_hud_general_pass_end(rdram, ctx);
    // 0x800AA3D0: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800AA3D4: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800AA3D8: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800AA3DC: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800AA3E0: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800AA3E4: jr          $ra
    // 0x800AA3E8: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
    return;
    // 0x800AA3E8: addiu       $sp, $sp, 0x160
    ctx->r29 = ADD32(ctx->r29, 0X160);
;}
RECOMP_FUNC void checkpoint_update_all(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017E98: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x80017E9C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80017EA0: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x80017EA4: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80017EA8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80017EAC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80017EB0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80017EB4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80017EB8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80017EBC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80017EC0: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80017EC4: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80017EC8: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80017ECC: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80017ED0: swc1        $f23, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80017ED4: swc1        $f22, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f22.u32l;
    // 0x80017ED8: swc1        $f21, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80017EDC: swc1        $f20, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f20.u32l;
    // 0x80017EE0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x80017EE4: sw          $zero, -0x5130($at)
    MEM_W(-0X5130, ctx->r1) = 0;
    // 0x80017EE8: blez        $v1, L_80018008
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80017EEC: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80018008;
    }
    // 0x80017EEC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80017EF0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80017EF4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80017EF8: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80017EFC: addiu       $a2, $a2, -0x51A8
    ctx->r6 = ADD32(ctx->r6, -0X51A8);
    // 0x80017F00: addiu       $t1, $t1, -0x5128
    ctx->r9 = ADD32(ctx->r9, -0X5128);
    // 0x80017F04: addiu       $s4, $s4, -0x5134
    ctx->r20 = ADD32(ctx->r20, -0X5134);
    // 0x80017F08: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80017F0C: addiu       $t0, $zero, 0xD
    ctx->r8 = ADD32(0, 0XD);
    // 0x80017F10: addiu       $a1, $zero, 0x3C
    ctx->r5 = ADD32(0, 0X3C);
L_80017F14:
    // 0x80017F14: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80017F18: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80017F1C: addu        $t7, $t6, $v0
    ctx->r15 = ADD32(ctx->r14, ctx->r2);
    // 0x80017F20: lw          $s0, 0x0($t7)
    ctx->r16 = MEM_W(ctx->r15, 0X0);
    // 0x80017F24: nop

    // 0x80017F28: lh          $t8, 0x6($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X6);
    // 0x80017F2C: nop

    // 0x80017F30: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80017F34: bne         $t9, $zero, L_80018000
    if (ctx->r25 != 0) {
        // 0x80017F38: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018000;
    }
    // 0x80017F38: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F3C: lh          $t3, 0x48($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X48);
    // 0x80017F40: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80017F44: bne         $t0, $t3, L_80018000
    if (ctx->r8 != ctx->r11) {
        // 0x80017F48: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018000;
    }
    // 0x80017F48: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F4C: lw          $a3, -0x5130($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5130);
    // 0x80017F50: nop

    // 0x80017F54: slti        $at, $a3, 0x3C
    ctx->r1 = SIGNED(ctx->r7) < 0X3C ? 1 : 0;
    // 0x80017F58: beq         $at, $zero, L_80018000
    if (ctx->r1 == 0) {
        // 0x80017F5C: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018000;
    }
    // 0x80017F5C: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F60: lw          $s7, 0x3C($s0)
    ctx->r23 = MEM_W(ctx->r16, 0X3C);
    // 0x80017F64: lh          $t4, 0x0($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X0);
    // 0x80017F68: lb          $t5, 0x1A($s7)
    ctx->r13 = MEM_B(ctx->r23, 0X1A);
    // 0x80017F6C: nop

    // 0x80017F70: bne         $t4, $t5, L_80018000
    if (ctx->r12 != ctx->r13) {
        // 0x80017F74: slt         $at, $s3, $v1
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_80018000;
    }
    // 0x80017F74: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80017F78: multu       $a3, $a1
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80017F7C: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x80017F80: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80017F84: addiu       $a3, $a3, -0x5130
    ctx->r7 = ADD32(ctx->r7, -0X5130);
    // 0x80017F88: mflo        $t7
    ctx->r15 = lo;
    // 0x80017F8C: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80017F90: sw          $s0, 0x28($t8)
    MEM_W(0X28, ctx->r24) = ctx->r16;
    // 0x80017F94: lbu         $t9, 0x17($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X17);
    // 0x80017F98: lbu         $a0, 0x9($s7)
    ctx->r4 = MEM_BU(ctx->r23, 0X9);
    // 0x80017F9C: beq         $t9, $zero, L_80017FAC
    if (ctx->r25 == 0) {
        // 0x80017FA0: nop
    
            goto L_80017FAC;
    }
    // 0x80017FA0: nop

    // 0x80017FA4: addiu       $a0, $a0, 0xFF
    ctx->r4 = ADD32(ctx->r4, 0XFF);
    // 0x80017FA8: addiu       $t2, $t2, 0x1
    ctx->r10 = ADD32(ctx->r10, 0X1);
L_80017FAC:
    // 0x80017FAC: lw          $t4, 0x0($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X0);
    // 0x80017FB0: lw          $t3, 0x0($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X0);
    // 0x80017FB4: multu       $t4, $a1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80017FB8: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80017FBC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80017FC0: mflo        $t5
    ctx->r13 = lo;
    // 0x80017FC4: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80017FC8: sh          $a0, 0x2C($t6)
    MEM_H(0X2C, ctx->r14) = ctx->r4;
    // 0x80017FCC: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80017FD0: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80017FD4: multu       $t9, $a1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80017FD8: mflo        $t4
    ctx->r12 = lo;
    // 0x80017FDC: addu        $t3, $t8, $t4
    ctx->r11 = ADD32(ctx->r24, ctx->r12);
    // 0x80017FE0: sb          $t7, 0x3A($t3)
    MEM_B(0X3A, ctx->r11) = ctx->r15;
    // 0x80017FE4: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80017FE8: nop

    // 0x80017FEC: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80017FF0: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x80017FF4: lw          $v1, -0x51A4($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X51A4);
    // 0x80017FF8: nop

    // 0x80017FFC: slt         $at, $s3, $v1
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r3) ? 1 : 0;
L_80018000:
    // 0x80018000: bne         $at, $zero, L_80017F14
    if (ctx->r1 != 0) {
        // 0x80018004: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80017F14;
    }
    // 0x80018004: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_80018008:
    // 0x80018008: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001800C: lw          $a3, -0x5130($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5130);
    // 0x80018010: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80018014: lw          $s2, 0x104($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X104);
    // 0x80018018: addiu       $s4, $s4, -0x5134
    ctx->r20 = ADD32(ctx->r20, -0X5134);
    // 0x8001801C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80018020: addiu       $a2, $a3, -0x1
    ctx->r6 = ADD32(ctx->r7, -0X1);
    // 0x80018024: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
L_80018028:
    // 0x80018028: blez        $a2, L_800180B8
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001802C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800180B8;
    }
    // 0x8001802C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80018030: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80018034:
    // 0x80018034: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x80018038: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001803C: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x80018040: lh          $v1, 0x2C($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2C);
    // 0x80018044: lh          $a0, 0x68($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X68);
    // 0x80018048: nop

    // 0x8001804C: bne         $v1, $a0, L_8001805C
    if (ctx->r3 != ctx->r4) {
        // 0x80018050: slt         $at, $a0, $v1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001805C;
    }
    // 0x80018050: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80018054: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80018058: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
L_8001805C:
    // 0x8001805C: beq         $at, $zero, L_800180B0
    if (ctx->r1 == 0) {
        // 0x80018060: slt         $at, $s3, $a2
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_800180B0;
    }
    // 0x80018060: slt         $at, $s3, $a2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x80018064: sh          $a0, 0x2C($v0)
    MEM_H(0X2C, ctx->r2) = ctx->r4;
    // 0x80018068: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8001806C: lw          $s0, 0x28($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X28);
    // 0x80018070: addu        $v0, $t8, $s1
    ctx->r2 = ADD32(ctx->r24, ctx->r17);
    // 0x80018074: lw          $t4, 0x64($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X64);
    // 0x80018078: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x8001807C: sw          $t4, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r12;
    // 0x80018080: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80018084: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80018088: addu        $t3, $t7, $s1
    ctx->r11 = ADD32(ctx->r15, ctx->r17);
    // 0x8001808C: sh          $v1, 0x68($t3)
    MEM_H(0X68, ctx->r11) = ctx->r3;
    // 0x80018090: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80018094: nop

    // 0x80018098: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x8001809C: sw          $s0, 0x64($t6)
    MEM_W(0X64, ctx->r14) = ctx->r16;
    // 0x800180A0: lw          $a3, -0x5130($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5130);
    // 0x800180A4: nop

    // 0x800180A8: addiu       $a2, $a3, -0x1
    ctx->r6 = ADD32(ctx->r7, -0X1);
    // 0x800180AC: slt         $at, $s3, $a2
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r6) ? 1 : 0;
L_800180B0:
    // 0x800180B0: bne         $at, $zero, L_80018034
    if (ctx->r1 != 0) {
        // 0x800180B4: addiu       $s1, $s1, 0x3C
        ctx->r17 = ADD32(ctx->r17, 0X3C);
            goto L_80018034;
    }
    // 0x800180B4: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
L_800180B8:
    // 0x800180B8: beq         $t0, $zero, L_80018028
    if (ctx->r8 == 0) {
        // 0x800180BC: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_80018028;
    }
    // 0x800180BC: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800180C0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800180C4: addiu       $t0, $t0, -0x512C
    ctx->r8 = ADD32(ctx->r8, -0X512C);
    // 0x800180C8: sw          $a3, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r7;
    // 0x800180CC: subu        $t9, $a3, $t2
    ctx->r25 = SUB32(ctx->r7, ctx->r10);
    // 0x800180D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800180D4: beq         $t1, $zero, L_80018100
    if (ctx->r9 == 0) {
        // 0x800180D8: sw          $t9, -0x5130($at)
        MEM_W(-0X5130, ctx->r1) = ctx->r25;
            goto L_80018100;
    }
    // 0x800180D8: sw          $t9, -0x5130($at)
    MEM_W(-0X5130, ctx->r1) = ctx->r25;
    // 0x800180DC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x800180E0: jal         0x800B635C
    // 0x800180E4: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    set_render_printf_position(rdram, ctx);
        goto after_0;
    // 0x800180E4: addiu       $a1, $zero, 0xDC
    ctx->r5 = ADD32(0, 0XDC);
    after_0:
    // 0x800180E8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800180EC: addiu       $a0, $a0, 0x50D4
    ctx->r4 = ADD32(ctx->r4, 0X50D4);
    // 0x800180F0: jal         0x800B5EDC
    // 0x800180F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    render_printf(rdram, ctx);
        goto after_1;
    // 0x800180F4: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800180F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800180FC: addiu       $t0, $t0, -0x512C
    ctx->r8 = ADD32(ctx->r8, -0X512C);
L_80018100:
    // 0x80018100: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80018104: lw          $a3, -0x5130($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5130);
    // 0x80018108: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8001810C: or          $s3, $a3, $zero
    ctx->r19 = ctx->r7 | 0;
    // 0x80018110: slt         $at, $a3, $v0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80018114: beq         $at, $zero, L_800181B0
    if (ctx->r1 == 0) {
        // 0x80018118: sll         $s1, $a3, 4
        ctx->r17 = S32(ctx->r7 << 4);
            goto L_800181B0;
    }
    // 0x80018118: sll         $s1, $a3, 4
    ctx->r17 = S32(ctx->r7 << 4);
    // 0x8001811C: subu        $s1, $s1, $a3
    ctx->r17 = SUB32(ctx->r17, ctx->r7);
    // 0x80018120: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
L_80018124:
    // 0x80018124: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x80018128: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001812C: addu        $t4, $t8, $s1
    ctx->r12 = ADD32(ctx->r24, ctx->r17);
    // 0x80018130: lh          $a1, 0x2C($t4)
    ctx->r5 = MEM_H(ctx->r12, 0X2C);
    // 0x80018134: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80018138: blez        $a3, L_8001819C
    if (SIGNED(ctx->r7) <= 0) {
        // 0x8001813C: addiu       $a1, $a1, -0xFF
        ctx->r5 = ADD32(ctx->r5, -0XFF);
            goto L_8001819C;
    }
    // 0x8001813C: addiu       $a1, $a1, -0xFF
    ctx->r5 = ADD32(ctx->r5, -0XFF);
    // 0x80018140: sll         $v0, $zero, 4
    ctx->r2 = S32(0 << 4);
    // 0x80018144: subu        $v0, $v0, $zero
    ctx->r2 = SUB32(ctx->r2, 0);
    // 0x80018148: sll         $v0, $v0, 2
    ctx->r2 = S32(ctx->r2 << 2);
L_8001814C:
    // 0x8001814C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80018150: nop

    // 0x80018154: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x80018158: lh          $t3, 0x2C($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X2C);
    // 0x8001815C: nop

    // 0x80018160: bne         $a1, $t3, L_80018184
    if (ctx->r5 != ctx->r11) {
        // 0x80018164: nop
    
            goto L_80018184;
    }
    // 0x80018164: nop

    // 0x80018168: sb          $s3, 0x3A($v1)
    MEM_B(0X3A, ctx->r3) = ctx->r19;
    // 0x8001816C: lw          $t5, 0x0($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X0);
    // 0x80018170: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80018174: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80018178: sb          $a0, 0x3A($t6)
    MEM_B(0X3A, ctx->r14) = ctx->r4;
    // 0x8001817C: lw          $a3, -0x5130($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5130);
    // 0x80018180: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
L_80018184:
    // 0x80018184: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80018188: slt         $at, $a0, $a3
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001818C: beq         $at, $zero, L_8001819C
    if (ctx->r1 == 0) {
        // 0x80018190: addiu       $v0, $v0, 0x3C
        ctx->r2 = ADD32(ctx->r2, 0X3C);
            goto L_8001819C;
    }
    // 0x80018190: addiu       $v0, $v0, 0x3C
    ctx->r2 = ADD32(ctx->r2, 0X3C);
    // 0x80018194: beq         $a2, $zero, L_8001814C
    if (ctx->r6 == 0) {
        // 0x80018198: nop
    
            goto L_8001814C;
    }
    // 0x80018198: nop

L_8001819C:
    // 0x8001819C: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x800181A0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800181A4: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800181A8: bne         $at, $zero, L_80018124
    if (ctx->r1 != 0) {
        // 0x800181AC: addiu       $s1, $s1, 0x3C
        ctx->r17 = ADD32(ctx->r17, 0X3C);
            goto L_80018124;
    }
    // 0x800181AC: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
L_800181B0:
    // 0x800181B0: blez        $v0, L_800185A4
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800181B4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800185A4;
    }
    // 0x800181B4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800181B8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800181BC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x800181C0: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800181C4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800181C8:
    // 0x800181C8: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x800181CC: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x800181D0: addu        $s2, $s1, $t9
    ctx->r18 = ADD32(ctx->r17, ctx->r25);
    // 0x800181D4: lw          $s0, 0x28($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X28);
    // 0x800181D8: addiu       $a1, $sp, 0x7C
    ctx->r5 = ADD32(ctx->r29, 0X7C);
    // 0x800181DC: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800181E0: lw          $s7, 0x3C($s0)
    ctx->r23 = MEM_W(ctx->r16, 0X3C);
    // 0x800181E4: sh          $t8, 0x7C($sp)
    MEM_H(0X7C, ctx->r29) = ctx->r24;
    // 0x800181E8: lh          $t4, 0x2($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X2);
    // 0x800181EC: nop

    // 0x800181F0: sh          $t4, 0x7E($sp)
    MEM_H(0X7E, ctx->r29) = ctx->r12;
    // 0x800181F4: lh          $t7, 0x4($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X4);
    // 0x800181F8: swc1        $f22, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f22.u32l;
    // 0x800181FC: swc1        $f20, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f20.u32l;
    // 0x80018200: swc1        $f20, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f20.u32l;
    // 0x80018204: swc1        $f20, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f20.u32l;
    // 0x80018208: jal         0x8006FC30
    // 0x8001820C: sh          $t7, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r15;
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x8001820C: sh          $t7, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r15;
    after_2:
    // 0x80018210: mfc1        $a1, $f20
    ctx->r5 = (int32_t)ctx->f20.u32l;
    // 0x80018214: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x80018218: mfc1        $a3, $f22
    ctx->r7 = (int32_t)ctx->f22.u32l;
    // 0x8001821C: addiu       $t3, $sp, 0xE8
    ctx->r11 = ADD32(ctx->r29, 0XE8);
    // 0x80018220: addiu       $t5, $sp, 0xE4
    ctx->r13 = ADD32(ctx->r29, 0XE4);
    // 0x80018224: addiu       $t6, $sp, 0xE0
    ctx->r14 = ADD32(ctx->r29, 0XE0);
    // 0x80018228: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8001822C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x80018230: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80018234: jal         0x8006F64C
    // 0x80018238: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    mtxf_transform_point(rdram, ctx);
        goto after_3;
    // 0x80018238: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    after_3:
    // 0x8001823C: lwc1        $f4, 0xE8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80018240: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80018244: swc1        $f4, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->f4.u32l;
    // 0x80018248: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x8001824C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80018250: swc1        $f6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->f6.u32l;
    // 0x80018254: lwc1        $f8, 0xE0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80018258: addiu       $t4, $s3, 0x1
    ctx->r12 = ADD32(ctx->r19, 0X1);
    // 0x8001825C: swc1        $f8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->f8.u32l;
    // 0x80018260: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018264: lwc1        $f16, 0xE8($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE8);
    // 0x80018268: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8001826C: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80018270: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x80018274: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018278: mul.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8001827C: lwc1        $f4, 0xE0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x80018280: nop

    // 0x80018284: mul.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x80018288: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x8001828C: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80018290: neg.s       $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = -ctx->f18.fl;
    // 0x80018294: swc1        $f8, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->f8.u32l;
    // 0x80018298: lwc1        $f16, 0xC($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8001829C: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800182A0: swc1        $f16, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->f16.u32l;
    // 0x800182A4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800182A8: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x800182AC: swc1        $f4, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->f4.u32l;
    // 0x800182B0: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800182B4: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800182B8: swc1        $f10, 0x18($s2)
    MEM_W(0X18, ctx->r18) = ctx->f10.u32l;
    // 0x800182BC: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800182C0: nop

    // 0x800182C4: mul.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x800182C8: swc1        $f8, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->f8.u32l;
    // 0x800182CC: lwc1        $f16, 0x8($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800182D0: swc1        $f20, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f20.u32l;
    // 0x800182D4: mul.s       $f10, $f16, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f4.fl);
    // 0x800182D8: swc1        $f20, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f20.u32l;
    // 0x800182DC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800182E0: nop

    // 0x800182E4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800182E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800182EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800182F0: nop

    // 0x800182F4: cvt.w.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    ctx->f6.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800182F8: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x800182FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80018300: sh          $t8, 0x2C($s2)
    MEM_H(0X2C, ctx->r18) = ctx->r24;
    // 0x80018304: lw          $a3, -0x5130($a3)
    ctx->r7 = MEM_W(ctx->r7, -0X5130);
    // 0x80018308: nop

    // 0x8001830C: slt         $at, $s3, $a3
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x80018310: beq         $at, $zero, L_800183FC
    if (ctx->r1 == 0) {
        // 0x80018314: nop
    
            goto L_800183FC;
    }
    // 0x80018314: nop

    // 0x80018318: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
    // 0x8001831C: bne         $t4, $a3, L_80018328
    if (ctx->r12 != ctx->r7) {
        // 0x80018320: or          $a1, $fp, $zero
        ctx->r5 = ctx->r30 | 0;
            goto L_80018328;
    }
    // 0x80018320: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x80018324: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_80018328:
    // 0x80018328: sll         $s6, $a1, 4
    ctx->r22 = S32(ctx->r5 << 4);
    // 0x8001832C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x80018330: subu        $s6, $s6, $a1
    ctx->r22 = SUB32(ctx->r22, ctx->r5);
    // 0x80018334: sll         $s6, $s6, 2
    ctx->r22 = S32(ctx->r22 << 2);
    // 0x80018338: addu        $t3, $t7, $s6
    ctx->r11 = ADD32(ctx->r15, ctx->r22);
    // 0x8001833C: lw          $v0, 0x28($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X28);
    // 0x80018340: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018344: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80018348: lwc1        $f16, 0x10($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8001834C: sub.s       $f0, $f18, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x80018350: lwc1        $f4, 0x10($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80018354: mul.s       $f18, $f0, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80018358: sub.s       $f2, $f16, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x8001835C: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018360: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80018364: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80018368: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x8001836C: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018370: add.s       $f16, $f18, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x80018374: jal         0x800C9AD0
    // 0x80018378: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x80018378: add.s       $f12, $f16, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f16.fl + ctx->f4.fl;
    after_4:
    // 0x8001837C: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    // 0x80018380: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x80018384: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80018388: addu        $t5, $s5, $s6
    ctx->r13 = ADD32(ctx->r21, ctx->r22);
    // 0x8001838C: lb          $v1, 0x3A($t5)
    ctx->r3 = MEM_B(ctx->r13, 0X3A);
    // 0x80018390: nop

    // 0x80018394: beq         $v1, $at, L_800183F0
    if (ctx->r3 == ctx->r1) {
        // 0x80018398: sll         $t6, $v1, 4
        ctx->r14 = S32(ctx->r3 << 4);
            goto L_800183F0;
    }
    // 0x80018398: sll         $t6, $v1, 4
    ctx->r14 = S32(ctx->r3 << 4);
    // 0x8001839C: subu        $t6, $t6, $v1
    ctx->r14 = SUB32(ctx->r14, ctx->r3);
    // 0x800183A0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x800183A4: addu        $t9, $s5, $t6
    ctx->r25 = ADD32(ctx->r21, ctx->r14);
    // 0x800183A8: lw          $v0, 0x28($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X28);
    // 0x800183AC: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800183B0: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800183B4: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800183B8: sub.s       $f0, $f10, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800183BC: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800183C0: mul.s       $f10, $f0, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800183C4: sub.s       $f2, $f18, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800183C8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800183CC: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800183D0: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800183D4: sub.s       $f14, $f16, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800183D8: mul.s       $f8, $f14, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800183DC: add.s       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x800183E0: jal         0x800C9AD0
    // 0x800183E4: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x800183E4: add.s       $f12, $f18, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f8.fl;
    after_5:
    // 0x800183E8: b           L_800184F4
    // 0x800183EC: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
        goto L_800184F4;
    // 0x800183EC: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
L_800183F0:
    // 0x800183F0: lwc1        $f16, 0x20($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800183F4: b           L_800184F4
    // 0x800183F8: swc1        $f16, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f16.u32l;
        goto L_800184F4;
    // 0x800183F8: swc1        $f16, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f16.u32l;
L_800183FC:
    // 0x800183FC: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x80018400: nop

    // 0x80018404: addu        $t8, $s5, $s1
    ctx->r24 = ADD32(ctx->r21, ctx->r17);
    // 0x80018408: lb          $a1, 0x3A($t8)
    ctx->r5 = MEM_B(ctx->r24, 0X3A);
    // 0x8001840C: nop

    // 0x80018410: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80018414: bne         $a1, $a3, L_80018424
    if (ctx->r5 != ctx->r7) {
        // 0x80018418: sll         $s6, $a1, 4
        ctx->r22 = S32(ctx->r5 << 4);
            goto L_80018424;
    }
    // 0x80018418: sll         $s6, $a1, 4
    ctx->r22 = S32(ctx->r5 << 4);
    // 0x8001841C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80018420: sll         $s6, $a1, 4
    ctx->r22 = S32(ctx->r5 << 4);
L_80018424:
    // 0x80018424: subu        $s6, $s6, $a1
    ctx->r22 = SUB32(ctx->r22, ctx->r5);
    // 0x80018428: sll         $s6, $s6, 2
    ctx->r22 = S32(ctx->r22 << 2);
    // 0x8001842C: addu        $t4, $s5, $s6
    ctx->r12 = ADD32(ctx->r21, ctx->r22);
    // 0x80018430: lw          $v0, 0x28($t4)
    ctx->r2 = MEM_W(ctx->r12, 0X28);
    // 0x80018434: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80018438: lwc1        $f10, 0xC($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001843C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80018440: sub.s       $f0, $f4, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x80018444: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80018448: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001844C: sub.s       $f2, $f6, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x80018450: lwc1        $f8, 0x14($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80018454: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80018458: mul.s       $f10, $f2, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001845C: sub.s       $f14, $f8, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x80018460: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80018464: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80018468: jal         0x800C9AD0
    // 0x8001846C: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_6;
    // 0x8001846C: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_6:
    // 0x80018470: swc1        $f0, 0x20($s2)
    MEM_W(0X20, ctx->r18) = ctx->f0.u32l;
    // 0x80018474: lw          $s5, 0x0($s4)
    ctx->r21 = MEM_W(ctx->r20, 0X0);
    // 0x80018478: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001847C: addu        $t7, $s5, $s6
    ctx->r15 = ADD32(ctx->r21, ctx->r22);
    // 0x80018480: lb          $v1, 0x3A($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X3A);
    // 0x80018484: nop

    // 0x80018488: beq         $v1, $at, L_800184E8
    if (ctx->r3 == ctx->r1) {
        // 0x8001848C: sll         $t3, $v1, 4
        ctx->r11 = S32(ctx->r3 << 4);
            goto L_800184E8;
    }
    // 0x8001848C: sll         $t3, $v1, 4
    ctx->r11 = S32(ctx->r3 << 4);
    // 0x80018490: subu        $t3, $t3, $v1
    ctx->r11 = SUB32(ctx->r11, ctx->r3);
    // 0x80018494: sll         $t3, $t3, 2
    ctx->r11 = S32(ctx->r11 << 2);
    // 0x80018498: addu        $t5, $s5, $t3
    ctx->r13 = ADD32(ctx->r21, ctx->r11);
    // 0x8001849C: lw          $v0, 0x28($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X28);
    // 0x800184A0: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800184A4: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800184A8: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800184AC: sub.s       $f0, $f8, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800184B0: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800184B4: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800184B8: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800184BC: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800184C0: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800184C4: mul.s       $f16, $f2, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800184C8: sub.s       $f14, $f6, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f18.fl;
    // 0x800184CC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800184D0: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800184D4: jal         0x800C9AD0
    // 0x800184D8: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x800184D8: add.s       $f12, $f4, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f10.fl;
    after_7:
    // 0x800184DC: swc1        $f0, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f0.u32l;
    // 0x800184E0: b           L_800184F4
    // 0x800184E4: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
        goto L_800184F4;
    // 0x800184E4: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
L_800184E8:
    // 0x800184E8: lwc1        $f6, 0x20($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0X20);
    // 0x800184EC: addiu       $fp, $s3, 0x1
    ctx->r30 = ADD32(ctx->r19, 0X1);
    // 0x800184F0: swc1        $f6, 0x24($s2)
    MEM_W(0X24, ctx->r18) = ctx->f6.u32l;
L_800184F4:
    // 0x800184F4: lb          $t6, 0xB($s7)
    ctx->r14 = MEM_B(ctx->r23, 0XB);
    // 0x800184F8: or          $s3, $fp, $zero
    ctx->r19 = ctx->r30 | 0;
    // 0x800184FC: sb          $t6, 0x2E($s2)
    MEM_B(0X2E, ctx->r18) = ctx->r14;
    // 0x80018500: lb          $t9, 0xF($s7)
    ctx->r25 = MEM_B(ctx->r23, 0XF);
    // 0x80018504: addiu       $s1, $s1, 0x3C
    ctx->r17 = ADD32(ctx->r17, 0X3C);
    // 0x80018508: sb          $t9, 0x32($s2)
    MEM_B(0X32, ctx->r18) = ctx->r25;
    // 0x8001850C: lb          $t8, 0x13($s7)
    ctx->r24 = MEM_B(ctx->r23, 0X13);
    // 0x80018510: nop

    // 0x80018514: sb          $t8, 0x36($s2)
    MEM_B(0X36, ctx->r18) = ctx->r24;
    // 0x80018518: lb          $t4, 0xC($s7)
    ctx->r12 = MEM_B(ctx->r23, 0XC);
    // 0x8001851C: nop

    // 0x80018520: sb          $t4, 0x2F($s2)
    MEM_B(0X2F, ctx->r18) = ctx->r12;
    // 0x80018524: lb          $t7, 0x10($s7)
    ctx->r15 = MEM_B(ctx->r23, 0X10);
    // 0x80018528: nop

    // 0x8001852C: sb          $t7, 0x33($s2)
    MEM_B(0X33, ctx->r18) = ctx->r15;
    // 0x80018530: lb          $t3, 0x14($s7)
    ctx->r11 = MEM_B(ctx->r23, 0X14);
    // 0x80018534: nop

    // 0x80018538: sb          $t3, 0x37($s2)
    MEM_B(0X37, ctx->r18) = ctx->r11;
    // 0x8001853C: lb          $t5, 0xD($s7)
    ctx->r13 = MEM_B(ctx->r23, 0XD);
    // 0x80018540: nop

    // 0x80018544: sb          $t5, 0x30($s2)
    MEM_B(0X30, ctx->r18) = ctx->r13;
    // 0x80018548: lb          $t6, 0x11($s7)
    ctx->r14 = MEM_B(ctx->r23, 0X11);
    // 0x8001854C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80018550: sb          $t6, 0x34($s2)
    MEM_B(0X34, ctx->r18) = ctx->r14;
    // 0x80018554: lb          $t9, 0x15($s7)
    ctx->r25 = MEM_B(ctx->r23, 0X15);
    // 0x80018558: nop

    // 0x8001855C: sb          $t9, 0x38($s2)
    MEM_B(0X38, ctx->r18) = ctx->r25;
    // 0x80018560: lb          $t8, 0xE($s7)
    ctx->r24 = MEM_B(ctx->r23, 0XE);
    // 0x80018564: nop

    // 0x80018568: sb          $t8, 0x31($s2)
    MEM_B(0X31, ctx->r18) = ctx->r24;
    // 0x8001856C: lb          $t4, 0x12($s7)
    ctx->r12 = MEM_B(ctx->r23, 0X12);
    // 0x80018570: nop

    // 0x80018574: sb          $t4, 0x35($s2)
    MEM_B(0X35, ctx->r18) = ctx->r12;
    // 0x80018578: lb          $t7, 0x16($s7)
    ctx->r15 = MEM_B(ctx->r23, 0X16);
    // 0x8001857C: nop

    // 0x80018580: sb          $t7, 0x39($s2)
    MEM_B(0X39, ctx->r18) = ctx->r15;
    // 0x80018584: lbu         $t3, 0x19($s7)
    ctx->r11 = MEM_BU(ctx->r23, 0X19);
    // 0x80018588: nop

    // 0x8001858C: sb          $t3, 0x3B($s2)
    MEM_B(0X3B, ctx->r18) = ctx->r11;
    // 0x80018590: lw          $t5, -0x512C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X512C);
    // 0x80018594: nop

    // 0x80018598: slt         $at, $fp, $t5
    ctx->r1 = SIGNED(ctx->r30) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8001859C: bne         $at, $zero, L_800181C8
    if (ctx->r1 != 0) {
        // 0x800185A0: nop
    
            goto L_800181C8;
    }
    // 0x800185A0: nop

L_800185A4:
    // 0x800185A4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800185A8: lwc1        $f21, 0x28($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800185AC: lwc1        $f20, 0x2C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800185B0: lwc1        $f23, 0x30($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800185B4: lwc1        $f22, 0x34($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800185B8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800185BC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800185C0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800185C4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800185C8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800185CC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800185D0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800185D4: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800185D8: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800185DC: jr          $ra
    // 0x800185E0: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x800185E0: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void trackmenu_track_view(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 5U, dkr_legacy_fields, 0U); }
    // 0x800904E8: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800904EC: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800904F0: jal         0x800C73F0
    // 0x800904F4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    bgload_tick(rdram, ctx);
        goto after_0;
    // 0x800904F4: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x800904F8: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800904FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80090500: blez        $a1, L_80090704
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80090504: andi        $v1, $a1, 0x3
        ctx->r3 = ctx->r5 & 0X3;
            goto L_80090704;
    }
    // 0x80090504: andi        $v1, $a1, 0x3
    ctx->r3 = ctx->r5 & 0X3;
    // 0x80090508: beq         $v1, $zero, L_800905D0
    if (ctx->r3 == 0) {
        // 0x8009050C: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_800905D0;
    }
    // 0x8009050C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x80090510: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090514: lwc1        $f14, 0x69E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X69E8);
    // 0x80090518: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009051C: lwc1        $f16, 0x69EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X69EC);
    // 0x80090520: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80090524: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80090528: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009052C: lwc1        $f1, -0x7B20($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7B20);
    // 0x80090530: lwc1        $f0, -0x7B1C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7B1C);
    // 0x80090534: addiu       $v1, $v1, 0x69DC
    ctx->r3 = ADD32(ctx->r3, 0X69DC);
    // 0x80090538: addiu       $t0, $t0, 0x69E4
    ctx->r8 = ADD32(ctx->r8, 0X69E4);
    // 0x8009053C: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090540: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80090544: sub.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x80090548: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8009054C: cvt.d.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.d = CVT_D_S(ctx->f4.fl);
    // 0x80090550: mul.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80090554: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80090558: cvt.d.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.d = CVT_D_S(ctx->f6.fl);
    // 0x8009055C: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x80090560: beq         $a0, $v0, L_800905B0
    if (ctx->r4 == ctx->r2) {
        // 0x80090564: cvt.d.s     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
            goto L_800905B0;
    }
    // 0x80090564: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
L_80090568:
    // 0x80090568: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x8009056C: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x80090570: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80090574: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x80090578: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8009057C: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x80090580: add.d       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f4.d + ctx->f8.d;
    // 0x80090584: cvt.s.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f8.fl = CVT_S_D(ctx->f8.d);
    // 0x80090588: sub.s       $f4, $f14, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f6.fl;
    // 0x8009058C: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x80090590: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80090594: cvt.d.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f4.d = CVT_D_S(ctx->f4.fl);
    // 0x80090598: mul.d       $f4, $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x8009059C: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800905A0: cvt.d.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f6.d = CVT_D_S(ctx->f6.fl);
    // 0x800905A4: add.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d + ctx->f4.d;
    // 0x800905A8: bne         $a0, $v0, L_80090568
    if (ctx->r4 != ctx->r2) {
        // 0x800905AC: cvt.d.s     $f18, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
            goto L_80090568;
    }
    // 0x800905AC: cvt.d.s     $f18, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f18.d = CVT_D_S(ctx->f8.fl);
L_800905B0:
    // 0x800905B0: mul.d       $f8, $f18, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x800905B4: cvt.d.s     $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f4.d = CVT_D_S(ctx->f12.fl);
    // 0x800905B8: cvt.s.d     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f6.fl = CVT_S_D(ctx->f10.d);
    // 0x800905BC: swc1        $f6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f6.u32l;
    // 0x800905C0: add.d       $f8, $f4, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f4.d + ctx->f8.d;
    // 0x800905C4: cvt.s.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f8.fl = CVT_S_D(ctx->f8.d);
    // 0x800905C8: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x800905CC: beq         $v0, $a1, L_80090704
    if (ctx->r2 == ctx->r5) {
        // 0x800905D0: lui         $at, 0x800F
        ctx->r1 = S32(0X800F << 16);
            goto L_80090704;
    }
L_800905D0:
    // 0x800905D0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800905D4: lwc1        $f1, -0x7B18($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X7B18);
    // 0x800905D8: lwc1        $f0, -0x7B14($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X7B14);
    // 0x800905DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800905E0: lwc1        $f14, 0x69E8($at)
    ctx->f14.u32l = MEM_W(ctx->r1, 0X69E8);
    // 0x800905E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800905E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800905EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800905F0: lwc1        $f16, 0x69EC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X69EC);
    // 0x800905F4: addiu       $t0, $t0, 0x69E4
    ctx->r8 = ADD32(ctx->r8, 0X69E4);
    // 0x800905F8: addiu       $v1, $v1, 0x69DC
    ctx->r3 = ADD32(ctx->r3, 0X69DC);
L_800905FC:
    // 0x800905FC: lwc1        $f18, 0x0($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090600: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80090604: sub.s       $f10, $f14, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x80090608: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8009060C: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80090610: cvt.d.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.d = CVT_D_S(ctx->f10.fl);
    // 0x80090614: mul.d       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80090618: cvt.d.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.d = CVT_D_S(ctx->f18.fl);
    // 0x8009061C: cvt.d.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.d = CVT_D_S(ctx->f8.fl);
    // 0x80090620: cvt.d.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.d = CVT_D_S(ctx->f12.fl);
    // 0x80090624: mul.d       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80090628: add.d       $f10, $f18, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f18.d + ctx->f10.d;
    // 0x8009062C: cvt.s.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f10.fl = CVT_S_D(ctx->f10.d);
    // 0x80090630: add.d       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f12.d + ctx->f8.d;
    // 0x80090634: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x80090638: cvt.s.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f8.fl = CVT_S_D(ctx->f8.d);
    // 0x8009063C: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090640: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
    // 0x80090644: sub.s       $f8, $f14, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x80090648: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8009064C: cvt.d.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.d = CVT_D_S(ctx->f8.fl);
    // 0x80090650: mul.d       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x80090654: sub.s       $f18, $f16, $f12
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x80090658: cvt.d.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.d = CVT_D_S(ctx->f10.fl);
    // 0x8009065C: add.d       $f8, $f10, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f10.d + ctx->f8.d;
    // 0x80090660: cvt.s.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f8.fl = CVT_S_D(ctx->f8.d);
    // 0x80090664: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x80090668: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8009066C: cvt.d.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.d = CVT_D_S(ctx->f18.fl);
    // 0x80090670: mul.d       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x80090674: sub.s       $f10, $f14, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f14.fl - ctx->f8.fl;
    // 0x80090678: cvt.d.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.d = CVT_D_S(ctx->f12.fl);
    // 0x8009067C: add.d       $f18, $f12, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f12.d + ctx->f18.d;
    // 0x80090680: cvt.s.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f18.fl = CVT_S_D(ctx->f18.d);
    // 0x80090684: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x80090688: lwc1        $f18, 0x0($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X0);
    // 0x8009068C: cvt.d.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.d = CVT_D_S(ctx->f10.fl);
    // 0x80090690: mul.d       $f10, $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f10.d, ctx->f0.d);
    // 0x80090694: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80090698: cvt.d.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.d = CVT_D_S(ctx->f8.fl);
    // 0x8009069C: add.d       $f10, $f8, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f10.d = ctx->f8.d + ctx->f10.d;
    // 0x800906A0: cvt.s.d     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f10.fl = CVT_S_D(ctx->f10.d);
    // 0x800906A4: cvt.d.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.d = CVT_D_S(ctx->f12.fl);
    // 0x800906A8: mul.d       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f0.d); 
    ctx->f12.d = MUL_D(ctx->f12.d, ctx->f0.d);
    // 0x800906AC: swc1        $f10, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f10.u32l;
    // 0x800906B0: lwc1        $f10, 0x0($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800906B4: cvt.d.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.d = CVT_D_S(ctx->f18.fl);
    // 0x800906B8: add.d       $f12, $f18, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f12.d); 
    ctx->f12.d = ctx->f18.d + ctx->f12.d;
    // 0x800906BC: cvt.s.d     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.d); 
    ctx->f12.fl = CVT_S_D(ctx->f12.d);
    // 0x800906C0: sub.s       $f18, $f14, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f14.fl - ctx->f10.fl;
    // 0x800906C4: swc1        $f12, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f12.u32l;
    // 0x800906C8: lwc1        $f12, 0x0($t0)
    ctx->f12.u32l = MEM_W(ctx->r8, 0X0);
    // 0x800906CC: cvt.d.s     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f18.d = CVT_D_S(ctx->f18.fl);
    // 0x800906D0: mul.d       $f18, $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x800906D4: sub.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800906D8: cvt.d.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f10.d = CVT_D_S(ctx->f10.fl);
    // 0x800906DC: add.d       $f18, $f10, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f18.d = ctx->f10.d + ctx->f18.d;
    // 0x800906E0: cvt.s.d     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f18.fl = CVT_S_D(ctx->f18.d);
    // 0x800906E4: cvt.d.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.d = CVT_D_S(ctx->f8.fl);
    // 0x800906E8: mul.d       $f8, $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800906EC: cvt.d.s     $f12, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f12.d = CVT_D_S(ctx->f12.fl);
    // 0x800906F0: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x800906F4: add.d       $f8, $f12, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f12.d); NAN_CHECK(ctx->f8.d); 
    ctx->f8.d = ctx->f12.d + ctx->f8.d;
    // 0x800906F8: cvt.s.d     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f8.fl = CVT_S_D(ctx->f8.d);
    // 0x800906FC: bne         $v0, $a1, L_800905FC
    if (ctx->r2 != ctx->r5) {
        // 0x80090700: swc1        $f8, 0x0($t0)
        MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
            goto L_800905FC;
    }
    // 0x80090700: swc1        $f8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f8.u32l;
L_80090704:
    // 0x80090704: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80090708: lw          $t6, 0x63D8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63D8);
    // 0x8009070C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80090710: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80090714: addiu       $at, $zero, 0x20
    ctx->r1 = ADD32(0, 0X20);
    // 0x80090718: addiu       $t0, $t0, 0x69E4
    ctx->r8 = ADD32(ctx->r8, 0X69E4);
    // 0x8009071C: bne         $t6, $at, L_800907F0
    if (ctx->r14 != ctx->r1) {
        // 0x80090720: addiu       $v1, $v1, 0x69DC
        ctx->r3 = ADD32(ctx->r3, 0X69DC);
            goto L_800907F0;
    }
    // 0x80090720: addiu       $v1, $v1, 0x69DC
    ctx->r3 = ADD32(ctx->r3, 0X69DC);
    // 0x80090724: jal         0x800C73E0
    // 0x80090728: nop

    bgload_active(rdram, ctx);
        goto after_1;
    // 0x80090728: nop

    after_1:
    // 0x8009072C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80090730: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80090734: addiu       $t0, $t0, 0x69E4
    ctx->r8 = ADD32(ctx->r8, 0X69E4);
    // 0x80090738: bne         $v0, $zero, L_800907F0
    if (ctx->r2 != 0) {
        // 0x8009073C: addiu       $v1, $v1, 0x69DC
        ctx->r3 = ADD32(ctx->r3, 0X69DC);
            goto L_800907F0;
    }
    // 0x8009073C: addiu       $v1, $v1, 0x69DC
    ctx->r3 = ADD32(ctx->r3, 0X69DC);
    // 0x80090740: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80090744: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80090748: lw          $a0, -0xB3C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XB3C);
    // 0x8009074C: lw          $v0, 0x63D0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D0);
    // 0x80090750: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80090754: bne         $v0, $a0, L_80090778
    if (ctx->r2 != ctx->r4) {
        // 0x80090758: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80090778;
    }
    // 0x80090758: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009075C: lw          $t7, 0x69C8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69C8);
    // 0x80090760: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80090764: lw          $t8, 0x69CC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X69CC);
    // 0x80090768: sw          $t7, 0x69F4($at)
    MEM_W(0X69F4, ctx->r1) = ctx->r15;
    // 0x8009076C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090770: b           L_800907F0
    // 0x80090774: sw          $t8, 0x69F8($at)
    MEM_W(0X69F8, ctx->r1) = ctx->r24;
        goto L_800907F0;
    // 0x80090774: sw          $t8, 0x69F8($at)
    MEM_W(0X69F8, ctx->r1) = ctx->r24;
L_80090778:
    // 0x80090778: beq         $v0, $a0, L_800907F0
    if (ctx->r2 == ctx->r4) {
        // 0x8009077C: addiu       $at, $zero, -0x1
        ctx->r1 = ADD32(0, -0X1);
            goto L_800907F0;
    }
    // 0x8009077C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80090780: beq         $a0, $at, L_800907F0
    if (ctx->r4 == ctx->r1) {
        // 0x80090784: nop
    
            goto L_800907F0;
    }
    // 0x80090784: nop

    // 0x80090788: jal         0x800C7458
    // 0x8009078C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    bgload_start(rdram, ctx);
        goto after_2;
    // 0x8009078C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_2:
    // 0x80090790: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80090794: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80090798: addiu       $t0, $t0, 0x69E4
    ctx->r8 = ADD32(ctx->r8, 0X69E4);
    // 0x8009079C: beq         $v0, $zero, L_800907F0
    if (ctx->r2 == 0) {
        // 0x800907A0: addiu       $v1, $v1, 0x69DC
        ctx->r3 = ADD32(ctx->r3, 0X69DC);
            goto L_800907F0;
    }
    // 0x800907A0: addiu       $v1, $v1, 0x69DC
    ctx->r3 = ADD32(ctx->r3, 0X69DC);
    // 0x800907A4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800907A8: lw          $a0, -0xB3C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0XB3C);
    // 0x800907AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800907B0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800907B4: lw          $t9, 0x69C8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X69C8);
    // 0x800907B8: sw          $a0, 0x63D0($at)
    MEM_W(0X63D0, ctx->r1) = ctx->r4;
    // 0x800907BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800907C0: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800907C4: lw          $t3, 0x69CC($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X69CC);
    // 0x800907C8: sw          $t9, 0x69F4($at)
    MEM_W(0X69F4, ctx->r1) = ctx->r25;
    // 0x800907CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800907D0: jal         0x8006B0AC
    // 0x800907D4: sw          $t3, 0x69F8($at)
    MEM_W(0X69F8, ctx->r1) = ctx->r11;
    leveltable_vehicle_default(rdram, ctx);
        goto after_3;
    // 0x800907D4: sw          $t3, 0x69F8($at)
    MEM_W(0X69F8, ctx->r1) = ctx->r11;
    after_3:
    // 0x800907D8: jal         0x8006DB14
    // 0x800907DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    set_level_default_vehicle(rdram, ctx);
        goto after_4;
    // 0x800907DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x800907E0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800907E4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800907E8: addiu       $t0, $t0, 0x69E4
    ctx->r8 = ADD32(ctx->r8, 0X69E4);
    // 0x800907EC: addiu       $v1, $v1, 0x69DC
    ctx->r3 = ADD32(ctx->r3, 0X69DC);
L_800907F0:
    // 0x800907F0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800907F4: lw          $t4, 0x69F4($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X69F4);
    // 0x800907F8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800907FC: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80090800: addu        $t5, $t5, $t4
    ctx->r13 = ADD32(ctx->r13, ctx->r12);
    // 0x80090804: sll         $t5, $t5, 6
    ctx->r13 = S32(ctx->r13 << 6);
    // 0x80090808: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8009080C: lwc1        $f8, 0x0($v1)
    ctx->f8.u32l = MEM_W(ctx->r3, 0X0);
    // 0x80090810: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090814: lw          $t1, 0x6480($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6480);
    // 0x80090818: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8009081C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80090820: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80090824: lw          $t7, 0x69F8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69F8);
    // 0x80090828: sub.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8009082C: negu        $t8, $t1
    ctx->r24 = SUB32(0, ctx->r9);
    // 0x80090830: multu       $t7, $t8
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80090834: lui         $at, 0x42A0
    ctx->r1 = S32(0X42A0 << 16);
    // 0x80090838: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8009083C: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x80090840: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80090844: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80090848: lw          $v0, 0x6478($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6478);
    // 0x8009084C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80090850: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80090854: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80090858: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009085C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090860: mflo        $t9
    ctx->r25 = lo;
    // 0x80090864: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80090868: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x8009086C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80090870: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x80090874: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80090878: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8009087C: sra         $t3, $t1, 2
    ctx->r11 = S32(SIGNED(ctx->r9) >> 2);
    // 0x80090880: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80090884: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x80090888: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009088C: addiu       $a3, $a1, 0xA0
    ctx->r7 = ADD32(ctx->r5, 0XA0);
    // 0x80090890: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80090894: cvt.s.w     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80090898: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009089C: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800908A0: sub.s       $f4, $f18, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f8.fl;
    // 0x800908A4: sub.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800908A8: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800908AC: nop

    // 0x800908B0: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800908B4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800908B8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800908BC: nop

    // 0x800908C0: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800908C4: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800908C8: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800908CC: addu        $t2, $a2, $v0
    ctx->r10 = ADD32(ctx->r6, ctx->r2);
    // 0x800908D0: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800908D4: sw          $t2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r10;
    // 0x800908D8: jal         0x80066940
    // 0x800908DC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    viewport_menu_set(rdram, ctx);
        goto after_5;
    // 0x800908DC: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    after_5:
    // 0x800908E0: addiu       $t5, $sp, 0x38
    ctx->r13 = ADD32(ctx->r29, 0X38);
    // 0x800908E4: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800908E8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800908EC: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800908F0: addiu       $a2, $sp, 0x40
    ctx->r6 = ADD32(ctx->r29, 0X40);
    // 0x800908F4: jal         0x80066BA8
    // 0x800908F8: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    copy_viewport_background_size_to_coords(rdram, ctx);
        goto after_6;
    // 0x800908F8: addiu       $a3, $sp, 0x3C
    ctx->r7 = ADD32(ctx->r29, 0X3C);
    after_6:
    // 0x800908FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80090900: jal         0x80066818
    // 0x80090904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camEnableUserView(rdram, ctx);
        goto after_7;
    // 0x80090904: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x80090908: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009090C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80090910: jr          $ra
    // 0x80090914: nop

    return;
    // 0x80090914: nop

;}
RECOMP_FUNC void func_800A4C34(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A4C34: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800A4C38: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x800A4C3C: jr          $ra
    // 0x800A4C40: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    return;
    // 0x800A4C40: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
;}
RECOMP_FUNC void obj_init_levelname(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042A1C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80042A20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80042A24: lb          $t6, 0x9($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X9);
    // 0x80042A28: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x80042A2C: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80042A30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80042A34: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80042A38: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80042A3C: swc1        $f10, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f10.u32l;
    // 0x80042A40: lwc1        $f0, 0x78($a0)
    ctx->f0.u32l = MEM_W(ctx->r4, 0X78);
    // 0x80042A44: nop

    // 0x80042A48: mul.s       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80042A4C: swc1        $f16, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f16.u32l;
    // 0x80042A50: lb          $t7, 0x8($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X8);
    // 0x80042A54: sh          $zero, 0x7E($a0)
    MEM_H(0X7E, ctx->r4) = 0;
    // 0x80042A58: sh          $t7, 0x7C($a0)
    MEM_H(0X7C, ctx->r4) = ctx->r15;
    // 0x80042A5C: jal         0x8009C2D0
    // 0x80042A60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    is_in_tracks_mode(rdram, ctx);
        goto after_0;
    // 0x80042A60: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80042A64: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80042A68: beq         $v0, $zero, L_80042A78
    if (ctx->r2 == 0) {
        // 0x80042A6C: nop
    
            goto L_80042A78;
    }
    // 0x80042A6C: nop

    // 0x80042A70: jal         0x8000FFB8
    // 0x80042A74: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80042A74: nop

    after_1:
L_80042A78:
    // 0x80042A78: jal         0x800C56D0
    // 0x80042A7C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_2;
    // 0x80042A7C: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_2:
    // 0x80042A80: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80042A84: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80042A88: jr          $ra
    // 0x80042A8C: nop

    return;
    // 0x80042A8C: nop

;}
RECOMP_FUNC void obj_init_posarrow(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80037624: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80037628: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8003762C: nop

    // 0x80037630: ori         $t7, $t6, 0x4000
    ctx->r15 = ctx->r14 | 0X4000;
    // 0x80037634: jr          $ra
    // 0x80037638: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    return;
    // 0x80037638: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
;}
RECOMP_FUNC void obj_loop_rangetrigger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80042178: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8004217C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80042180: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80042184: lw          $v1, 0x3C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X3C);
    // 0x80042188: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x8004218C: lhu         $t6, 0x8($v1)
    ctx->r14 = MEM_HU(ctx->r3, 0X8);
    // 0x80042190: lwc1        $f12, 0xC($a0)
    ctx->f12.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80042194: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80042198: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x8004219C: bgez        $t6, L_800421B4
    if (SIGNED(ctx->r14) >= 0) {
        // 0x800421A0: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800421B4;
    }
    // 0x800421A0: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800421A4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800421A8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800421AC: nop

    // 0x800421B0: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800421B4:
    // 0x800421B4: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800421B8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800421BC: addiu       $t8, $sp, 0x20
    ctx->r24 = ADD32(ctx->r29, 0X20);
    // 0x800421C0: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x800421C4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800421C8: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    // 0x800421CC: jal         0x80016DE8
    // 0x800421D0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    obj_dist_racer(rdram, ctx);
        goto after_0;
    // 0x800421D0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x800421D4: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x800421D8: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800421DC: blez        $v0, L_800421F0
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800421E0: nop
    
            goto L_800421F0;
    }
    // 0x800421E0: nop

    // 0x800421E4: lhu         $t9, 0xA($v1)
    ctx->r25 = MEM_HU(ctx->r3, 0XA);
    // 0x800421E8: b           L_800421F4
    // 0x800421EC: sw          $t9, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r25;
        goto L_800421F4;
    // 0x800421EC: sw          $t9, 0x74($a0)
    MEM_W(0X74, ctx->r4) = ctx->r25;
L_800421F0:
    // 0x800421F0: sw          $zero, 0x74($a0)
    MEM_W(0X74, ctx->r4) = 0;
L_800421F4:
    // 0x800421F4: lw          $a1, 0x4C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X4C);
    // 0x800421F8: jal         0x800AFC3C
    // 0x800421FC: nop

    obj_spawn_particle(rdram, ctx);
        goto after_1;
    // 0x800421FC: nop

    after_1:
    // 0x80042200: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80042204: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x80042208: jr          $ra
    // 0x8004220C: nop

    return;
    // 0x8004220C: nop

;}
RECOMP_FUNC void func_8001F23C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001F23C: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8001F240: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8001F244: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8001F248: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8001F24C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001F250: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001F254: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001F258: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001F25C: lh          $t6, 0x2($a1)
    ctx->r14 = MEM_H(ctx->r5, 0X2);
    // 0x8001F260: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x8001F264: sh          $t6, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r14;
    // 0x8001F268: lh          $t7, 0x4($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X4);
    // 0x8001F26C: addiu       $s5, $sp, 0x3C
    ctx->r21 = ADD32(ctx->r29, 0X3C);
    // 0x8001F270: sh          $t7, 0x40($sp)
    MEM_H(0X40, ctx->r29) = ctx->r15;
    // 0x8001F274: lh          $t8, 0x6($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X6);
    // 0x8001F278: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x8001F27C: sh          $t8, 0x42($sp)
    MEM_H(0X42, ctx->r29) = ctx->r24;
    // 0x8001F280: lh          $t9, 0xC($a1)
    ctx->r25 = MEM_H(ctx->r5, 0XC);
    // 0x8001F284: nop

    // 0x8001F288: sra         $t0, $t9, 1
    ctx->r8 = S32(SIGNED(ctx->r25) >> 1);
    // 0x8001F28C: andi        $t1, $t0, 0x80
    ctx->r9 = ctx->r8 & 0X80;
    // 0x8001F290: ori         $t2, $t1, 0x8
    ctx->r10 = ctx->r9 | 0X8;
    // 0x8001F294: sb          $t2, 0x3D($sp)
    MEM_B(0X3D, ctx->r29) = ctx->r10;
    // 0x8001F298: lh          $t3, 0xC($a1)
    ctx->r11 = MEM_H(ctx->r5, 0XC);
    // 0x8001F29C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8001F2A0: jal         0x8000EA54
    // 0x8001F2A4: sb          $t3, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r11;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x8001F2A4: sb          $t3, 0x3C($sp)
    MEM_B(0X3C, ctx->r29) = ctx->r11;
    after_0:
    // 0x8001F2A8: sw          $v0, 0x64($s4)
    MEM_W(0X64, ctx->r20) = ctx->r2;
    // 0x8001F2AC: beq         $v0, $zero, L_8001F2E4
    if (ctx->r2 == 0) {
        // 0x8001F2B0: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8001F2E4;
    }
    // 0x8001F2B0: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001F2B4: lh          $t4, 0x48($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X48);
    // 0x8001F2B8: addiu       $at, $zero, 0xC
    ctx->r1 = ADD32(0, 0XC);
    // 0x8001F2BC: bne         $t4, $at, L_8001F2E4
    if (ctx->r12 != ctx->r1) {
        // 0x8001F2C0: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8001F2E4;
    }
    // 0x8001F2C0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001F2C4: lbu         $t5, -0x510C($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X510C);
    // 0x8001F2C8: nop

    // 0x8001F2CC: beq         $t5, $zero, L_8001F2E4
    if (ctx->r13 == 0) {
        // 0x8001F2D0: nop
    
            goto L_8001F2E4;
    }
    // 0x8001F2D0: nop

    // 0x8001F2D4: jal         0x8000FFB8
    // 0x8001F2D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    free_object(rdram, ctx);
        goto after_1;
    // 0x8001F2D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8001F2DC: sw          $zero, 0x64($s4)
    MEM_W(0X64, ctx->r20) = 0;
    // 0x8001F2E0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001F2E4:
    // 0x8001F2E4: beq         $s1, $zero, L_8001F394
    if (ctx->r17 == 0) {
        // 0x8001F2E8: or          $a0, $s4, $zero
        ctx->r4 = ctx->r20 | 0;
            goto L_8001F394;
    }
    // 0x8001F2E8: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F2EC: sw          $zero, 0x3C($s1)
    MEM_W(0X3C, ctx->r17) = 0;
    // 0x8001F2F0: jal         0x8001EFA4
    // 0x8001F2F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_2;
    // 0x8001F2F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_2:
    // 0x8001F2F8: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8001F2FC: addiu       $at, $zero, 0x33
    ctx->r1 = ADD32(0, 0X33);
    // 0x8001F300: lb          $t7, 0x54($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X54);
    // 0x8001F304: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8001F308: bne         $t7, $at, L_8001F394
    if (ctx->r15 != ctx->r1) {
        // 0x8001F30C: addiu       $s3, $s3, -0x52C2
        ctx->r19 = ADD32(ctx->r19, -0X52C2);
            goto L_8001F394;
    }
    // 0x8001F30C: addiu       $s3, $s3, -0x52C2
    ctx->r19 = ADD32(ctx->r19, -0X52C2);
    // 0x8001F310: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x8001F314: lb          $t8, 0x0($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X0);
    // 0x8001F318: jal         0x80066210
    // 0x8001F31C: sb          $t8, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r24;
    cam_get_viewport_layout(rdram, ctx);
        goto after_3;
    // 0x8001F31C: sb          $t8, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r24;
    after_3:
    // 0x8001F320: jal         0x8006C19C
    // 0x8001F324: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    race_is_adventure_2P(rdram, ctx);
        goto after_4;
    // 0x8001F324: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    after_4:
    // 0x8001F328: beq         $v0, $zero, L_8001F334
    if (ctx->r2 == 0) {
        // 0x8001F32C: nop
    
            goto L_8001F334;
    }
    // 0x8001F32C: nop

    // 0x8001F330: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8001F334:
    // 0x8001F334: blez        $s2, L_8001F384
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8001F338: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8001F384;
    }
    // 0x8001F338: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8001F33C: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8001F340:
    // 0x8001F340: jal         0x8000EA54
    // 0x8001F344: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_5;
    // 0x8001F344: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x8001F348: beq         $v0, $zero, L_8001F378
    if (ctx->r2 == 0) {
        // 0x8001F34C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8001F378;
    }
    // 0x8001F34C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8001F350: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8001F354: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    // 0x8001F358: jal         0x8001EFA4
    // 0x8001F35C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    obj_init_animobject(rdram, ctx);
        goto after_6;
    // 0x8001F35C: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_6:
    // 0x8001F360: lw          $v0, 0x64($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X64);
    // 0x8001F364: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001F368: sb          $s0, 0x30($v0)
    MEM_B(0X30, ctx->r2) = ctx->r16;
    // 0x8001F36C: lb          $t9, 0x0($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X0);
    // 0x8001F370: nop

    // 0x8001F374: sb          $t9, 0x44($v0)
    MEM_B(0X44, ctx->r2) = ctx->r25;
L_8001F378:
    // 0x8001F378: slt         $at, $s0, $s2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r18) ? 1 : 0;
    // 0x8001F37C: bne         $at, $zero, L_8001F340
    if (ctx->r1 != 0) {
        // 0x8001F380: or          $a0, $s5, $zero
        ctx->r4 = ctx->r21 | 0;
            goto L_8001F340;
    }
    // 0x8001F380: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
L_8001F384:
    // 0x8001F384: lb          $t0, 0x0($s3)
    ctx->r8 = MEM_B(ctx->r19, 0X0);
    // 0x8001F388: nop

    // 0x8001F38C: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8001F390: sb          $t1, 0x0($s3)
    MEM_B(0X0, ctx->r19) = ctx->r9;
L_8001F394:
    // 0x8001F394: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8001F398: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001F39C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001F3A0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001F3A4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001F3A8: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8001F3AC: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8001F3B0: jr          $ra
    // 0x8001F3B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8001F3B4: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void weather_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ABC5C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800ABC60: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800ABC64: lw          $s0, 0x34($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X34);
    // 0x800ABC68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ABC6C: blez        $s0, L_800ABE58
    if (SIGNED(ctx->r16) <= 0) {
        // 0x800ABC70: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_800ABE58;
    }
    // 0x800ABC70: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800ABC74: addiu       $v0, $v0, 0x7BB8
    ctx->r2 = ADD32(ctx->r2, 0X7BB8);
    // 0x800ABC78: lw          $t6, 0x14($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X14);
    // 0x800ABC7C: nop

    // 0x800ABC80: bne         $a0, $t6, L_800ABCC8
    if (ctx->r4 != ctx->r14) {
        // 0x800ABC84: nop
    
            goto L_800ABCC8;
    }
    // 0x800ABC84: nop

    // 0x800ABC88: lw          $t7, 0x20($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X20);
    // 0x800ABC8C: nop

    // 0x800ABC90: bne         $a1, $t7, L_800ABCC8
    if (ctx->r5 != ctx->r15) {
        // 0x800ABC94: nop
    
            goto L_800ABCC8;
    }
    // 0x800ABC94: nop

    // 0x800ABC98: lw          $t8, 0x2C($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X2C);
    // 0x800ABC9C: nop

    // 0x800ABCA0: bne         $a2, $t8, L_800ABCC8
    if (ctx->r6 != ctx->r24) {
        // 0x800ABCA4: nop
    
            goto L_800ABCC8;
    }
    // 0x800ABCA4: nop

    // 0x800ABCA8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x800ABCAC: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800ABCB0: bne         $a3, $t9, L_800ABCC8
    if (ctx->r7 != ctx->r25) {
        // 0x800ABCB4: nop
    
            goto L_800ABCC8;
    }
    // 0x800ABCB4: nop

    // 0x800ABCB8: lw          $t0, 0x30($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X30);
    // 0x800ABCBC: nop

    // 0x800ABCC0: beq         $v1, $t0, L_800ABE58
    if (ctx->r3 == ctx->r8) {
        // 0x800ABCC4: nop
    
            goto L_800ABE58;
    }
    // 0x800ABCC4: nop

L_800ABCC8:
    // 0x800ABCC8: lw          $t1, 0xC($v0)
    ctx->r9 = MEM_W(ctx->r2, 0XC);
    // 0x800ABCCC: lw          $t4, 0x18($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X18);
    // 0x800ABCD0: subu        $t2, $a0, $t1
    ctx->r10 = SUB32(ctx->r4, ctx->r9);
    // 0x800ABCD4: div         $zero, $t2, $s0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r16)));
    // 0x800ABCD8: subu        $t5, $a1, $t4
    ctx->r13 = SUB32(ctx->r5, ctx->r12);
    // 0x800ABCDC: lw          $t7, 0x24($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X24);
    // 0x800ABCE0: sw          $a0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r4;
    // 0x800ABCE4: subu        $t8, $a2, $t7
    ctx->r24 = SUB32(ctx->r6, ctx->r15);
    // 0x800ABCE8: sw          $a1, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r5;
    // 0x800ABCEC: sw          $a2, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r6;
    // 0x800ABCF0: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800ABCF4: lw          $v1, 0x30($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X30);
    // 0x800ABCF8: bne         $s0, $zero, L_800ABD04
    if (ctx->r16 != 0) {
        // 0x800ABCFC: nop
    
            goto L_800ABD04;
    }
    // 0x800ABCFC: nop

    // 0x800ABD00: break       7
    do_break(2148187392);
L_800ABD04:
    // 0x800ABD04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ABD08: bne         $s0, $at, L_800ABD1C
    if (ctx->r16 != ctx->r1) {
        // 0x800ABD0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800ABD1C;
    }
    // 0x800ABD0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ABD10: bne         $t2, $at, L_800ABD1C
    if (ctx->r10 != ctx->r1) {
        // 0x800ABD14: nop
    
            goto L_800ABD1C;
    }
    // 0x800ABD14: nop

    // 0x800ABD18: break       6
    do_break(2148187416);
L_800ABD1C:
    // 0x800ABD1C: mflo        $t3
    ctx->r11 = lo;
    // 0x800ABD20: sw          $t3, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r11;
    // 0x800ABD24: nop

    // 0x800ABD28: div         $zero, $t5, $s0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r16)));
    // 0x800ABD2C: bne         $s0, $zero, L_800ABD38
    if (ctx->r16 != 0) {
        // 0x800ABD30: nop
    
            goto L_800ABD38;
    }
    // 0x800ABD30: nop

    // 0x800ABD34: break       7
    do_break(2148187444);
L_800ABD38:
    // 0x800ABD38: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ABD3C: bne         $s0, $at, L_800ABD50
    if (ctx->r16 != ctx->r1) {
        // 0x800ABD40: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800ABD50;
    }
    // 0x800ABD40: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ABD44: bne         $t5, $at, L_800ABD50
    if (ctx->r13 != ctx->r1) {
        // 0x800ABD48: nop
    
            goto L_800ABD50;
    }
    // 0x800ABD48: nop

    // 0x800ABD4C: break       6
    do_break(2148187468);
L_800ABD50:
    // 0x800ABD50: mflo        $t6
    ctx->r14 = lo;
    // 0x800ABD54: sw          $t6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r14;
    // 0x800ABD58: nop

    // 0x800ABD5C: div         $zero, $t8, $s0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r16)));
    // 0x800ABD60: bne         $s0, $zero, L_800ABD6C
    if (ctx->r16 != 0) {
        // 0x800ABD64: nop
    
            goto L_800ABD6C;
    }
    // 0x800ABD64: nop

    // 0x800ABD68: break       7
    do_break(2148187496);
L_800ABD6C:
    // 0x800ABD6C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ABD70: bne         $s0, $at, L_800ABD84
    if (ctx->r16 != ctx->r1) {
        // 0x800ABD74: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800ABD84;
    }
    // 0x800ABD74: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ABD78: bne         $t8, $at, L_800ABD84
    if (ctx->r24 != ctx->r1) {
        // 0x800ABD7C: nop
    
            goto L_800ABD84;
    }
    // 0x800ABD7C: nop

    // 0x800ABD80: break       6
    do_break(2148187520);
L_800ABD84:
    // 0x800ABD84: mflo        $t9
    ctx->r25 = lo;
    // 0x800ABD88: sw          $t9, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r25;
    // 0x800ABD8C: lw          $t0, 0x2C5C($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2C5C);
    // 0x800ABD90: nop

    // 0x800ABD94: bne         $t0, $zero, L_800ABE24
    if (ctx->r8 != 0) {
        // 0x800ABD98: nop
    
            goto L_800ABE24;
    }
    // 0x800ABD98: nop

    // 0x800ABD9C: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x800ABDA0: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x800ABDA4: subu        $t2, $a3, $t1
    ctx->r10 = SUB32(ctx->r7, ctx->r9);
    // 0x800ABDA8: div         $zero, $t2, $s0
    lo = S32(S64(S32(ctx->r10)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r10)) % S64(S32(ctx->r16)));
    // 0x800ABDAC: subu        $t5, $v1, $t4
    ctx->r13 = SUB32(ctx->r3, ctx->r12);
    // 0x800ABDB0: bne         $s0, $zero, L_800ABDBC
    if (ctx->r16 != 0) {
        // 0x800ABDB4: nop
    
            goto L_800ABDBC;
    }
    // 0x800ABDB4: nop

    // 0x800ABDB8: break       7
    do_break(2148187576);
L_800ABDBC:
    // 0x800ABDBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ABDC0: bne         $s0, $at, L_800ABDD4
    if (ctx->r16 != ctx->r1) {
        // 0x800ABDC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800ABDD4;
    }
    // 0x800ABDC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ABDC8: bne         $t2, $at, L_800ABDD4
    if (ctx->r10 != ctx->r1) {
        // 0x800ABDCC: nop
    
            goto L_800ABDD4;
    }
    // 0x800ABDCC: nop

    // 0x800ABDD0: break       6
    do_break(2148187600);
L_800ABDD4:
    // 0x800ABDD4: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x800ABDD8: sw          $v1, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r3;
    // 0x800ABDDC: sw          $s0, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = ctx->r16;
    // 0x800ABDE0: mflo        $t3
    ctx->r11 = lo;
    // 0x800ABDE4: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800ABDE8: nop

    // 0x800ABDEC: div         $zero, $t5, $s0
    lo = S32(S64(S32(ctx->r13)) / S64(S32(ctx->r16))); hi = S32(S64(S32(ctx->r13)) % S64(S32(ctx->r16)));
    // 0x800ABDF0: bne         $s0, $zero, L_800ABDFC
    if (ctx->r16 != 0) {
        // 0x800ABDF4: nop
    
            goto L_800ABDFC;
    }
    // 0x800ABDF4: nop

    // 0x800ABDF8: break       7
    do_break(2148187640);
L_800ABDFC:
    // 0x800ABDFC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800ABE00: bne         $s0, $at, L_800ABE14
    if (ctx->r16 != ctx->r1) {
        // 0x800ABE04: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800ABE14;
    }
    // 0x800ABE04: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800ABE08: bne         $t5, $at, L_800ABE14
    if (ctx->r13 != ctx->r1) {
        // 0x800ABE0C: nop
    
            goto L_800ABE14;
    }
    // 0x800ABE0C: nop

    // 0x800ABE10: break       6
    do_break(2148187664);
L_800ABE14:
    // 0x800ABE14: mflo        $t6
    ctx->r14 = lo;
    // 0x800ABE18: sw          $t6, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r14;
    // 0x800ABE1C: b           L_800ABE5C
    // 0x800ABE20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800ABE5C;
    // 0x800ABE20: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800ABE24:
    // 0x800ABE24: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800ABE28: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x800ABE2C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800ABE30: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800ABE34: sw          $a3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r7;
    // 0x800ABE38: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800ABE3C: sw          $v1, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r3;
    // 0x800ABE40: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x800ABE44: addiu       $a0, $a3, 0x1
    ctx->r4 = ADD32(ctx->r7, 0X1);
    // 0x800ABE48: addiu       $a1, $v1, 0x1
    ctx->r5 = ADD32(ctx->r3, 0X1);
    // 0x800ABE4C: mfc1        $a2, $f10
    ctx->r6 = (int32_t)ctx->f10.u32l;
    // 0x800ABE50: jal         0x800AD2C4
    // 0x800ABE54: nop

    rain_set(rdram, ctx);
        goto after_0;
    // 0x800ABE54: nop

    after_0:
L_800ABE58:
    // 0x800ABE58: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800ABE5C:
    // 0x800ABE5C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800ABE60: jr          $ra
    // 0x800ABE64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800ABE64: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void func_80016BC4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80016BC4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80016BC8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80016BCC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80016BD0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80016BD4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80016BD8: lw          $t6, 0x5C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X5C);
    // 0x80016BDC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80016BE0: jal         0x8001709C
    // 0x80016BE4: sb          $zero, 0x104($t6)
    MEM_B(0X104, ctx->r14) = 0;
    obj_collision_transform(rdram, ctx);
        goto after_0;
    // 0x80016BE4: sb          $zero, 0x104($t6)
    MEM_B(0X104, ctx->r14) = 0;
    after_0:
    // 0x80016BE8: jal         0x8001709C
    // 0x80016BEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    obj_collision_transform(rdram, ctx);
        goto after_1;
    // 0x80016BEC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x80016BF0: lw          $t7, 0x40($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X40);
    // 0x80016BF4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80016BF8: lb          $v1, 0x55($t7)
    ctx->r3 = MEM_B(ctx->r15, 0X55);
    // 0x80016BFC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80016C00: blez        $v1, L_80016C54
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80016C04: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80016C54;
    }
    // 0x80016C04: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80016C08:
    // 0x80016C08: lw          $t8, 0x68($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X68);
    // 0x80016C0C: nop

    // 0x80016C10: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80016C14: lw          $v0, 0x0($t9)
    ctx->r2 = MEM_W(ctx->r25, 0X0);
    // 0x80016C18: nop

    // 0x80016C1C: beq         $v0, $zero, L_80016C40
    if (ctx->r2 == 0) {
        // 0x80016C20: nop
    
            goto L_80016C40;
    }
    // 0x80016C20: nop

    // 0x80016C24: lw          $a0, 0x0($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X0);
    // 0x80016C28: jal         0x8006017C
    // 0x80016C2C: nop

    model_init_collision(rdram, ctx);
        goto after_2;
    // 0x80016C2C: nop

    after_2:
    // 0x80016C30: lw          $t0, 0x40($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X40);
    // 0x80016C34: nop

    // 0x80016C38: lb          $v1, 0x55($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X55);
    // 0x80016C3C: nop

L_80016C40:
    // 0x80016C40: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80016C44: slt         $at, $s1, $v1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80016C48: bne         $at, $zero, L_80016C08
    if (ctx->r1 != 0) {
        // 0x80016C4C: addiu       $s0, $s0, 0x4
        ctx->r16 = ADD32(ctx->r16, 0X4);
            goto L_80016C08;
    }
    // 0x80016C4C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80016C50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80016C54:
    // 0x80016C54: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80016C58: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80016C5C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80016C60: jr          $ra
    // 0x80016C64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80016C64: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void alMainBusPull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC3C0: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800CC3C4: lw          $t0, 0x58($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X58);
    // 0x800CC3C8: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800CC3CC: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800CC3D0: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800CC3D4: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800CC3D8: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800CC3DC: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800CC3E0: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800CC3E4: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800CC3E8: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800CC3EC: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800CC3F0: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800CC3F4: lui         $t6, 0x200
    ctx->r14 = S32(0X200 << 16);
    // 0x800CC3F8: sll         $v0, $a2, 1
    ctx->r2 = S32(ctx->r6 << 1);
    // 0x800CC3FC: lui         $t7, 0x200
    ctx->r15 = S32(0X200 << 16);
    // 0x800CC400: ori         $t6, $t6, 0x440
    ctx->r14 = ctx->r14 | 0X440;
    // 0x800CC404: ori         $t7, $t7, 0x580
    ctx->r15 = ctx->r15 | 0X580;
    // 0x800CC408: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x800CC40C: sw          $v0, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r2;
    // 0x800CC410: sw          $t7, 0x8($t0)
    MEM_W(0X8, ctx->r8) = ctx->r15;
    // 0x800CC414: sw          $v0, 0xC($t0)
    MEM_W(0XC, ctx->r8) = ctx->r2;
    // 0x800CC418: lw          $t8, 0x14($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X14);
    // 0x800CC41C: or          $s5, $a2, $zero
    ctx->r21 = ctx->r6 | 0;
    // 0x800CC420: or          $s7, $a1, $zero
    ctx->r23 = ctx->r5 | 0;
    // 0x800CC424: or          $fp, $a3, $zero
    ctx->r30 = ctx->r7 | 0;
    // 0x800CC428: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800CC42C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800CC430: blez        $t8, L_800CC4AC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800CC434: addiu       $s3, $t0, 0x10
        ctx->r19 = ADD32(ctx->r8, 0X10);
            goto L_800CC4AC;
    }
    // 0x800CC434: addiu       $s3, $t0, 0x10
    ctx->r19 = ADD32(ctx->r8, 0X10);
    // 0x800CC438: lui         $s2, 0xC00
    ctx->r18 = S32(0XC00 << 16);
    // 0x800CC43C: ori         $s2, $s2, 0x7FFF
    ctx->r18 = ctx->r18 | 0X7FFF;
    // 0x800CC440: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800CC444: andi        $s6, $v0, 0xFFFF
    ctx->r22 = ctx->r2 & 0XFFFF;
L_800CC448:
    // 0x800CC448: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x800CC44C: sw          $s3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r19;
    // 0x800CC450: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800CC454: lw          $t9, 0x4($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4);
    // 0x800CC458: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800CC45C: or          $a3, $fp, $zero
    ctx->r7 = ctx->r30 | 0;
    // 0x800CC460: jalr        $t9
    // 0x800CC464: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC464: nop

    after_0:
    // 0x800CC468: lui         $t2, 0x6C0
    ctx->r10 = S32(0X6C0 << 16);
    // 0x800CC46C: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x800CC470: lui         $t1, 0x800
    ctx->r9 = S32(0X800 << 16);
    // 0x800CC474: ori         $t2, $t2, 0x440
    ctx->r10 = ctx->r10 | 0X440;
    // 0x800CC478: ori         $t3, $t3, 0x580
    ctx->r11 = ctx->r11 | 0X580;
    // 0x800CC47C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    // 0x800CC480: sw          $s6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r22;
    // 0x800CC484: sw          $t2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r10;
    // 0x800CC488: sw          $s2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r18;
    // 0x800CC48C: sw          $t3, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r11;
    // 0x800CC490: sw          $s2, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r18;
    // 0x800CC494: lw          $t4, 0x14($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X14);
    // 0x800CC498: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800CC49C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x800CC4A0: slt         $at, $s0, $t4
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800CC4A4: bne         $at, $zero, L_800CC448
    if (ctx->r1 != 0) {
        // 0x800CC4A8: addiu       $s3, $v0, 0x18
        ctx->r19 = ADD32(ctx->r2, 0X18);
            goto L_800CC448;
    }
    // 0x800CC4A8: addiu       $s3, $v0, 0x18
    ctx->r19 = ADD32(ctx->r2, 0X18);
L_800CC4AC:
    // 0x800CC4AC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800CC4B0: or          $v0, $s3, $zero
    ctx->r2 = ctx->r19 | 0;
    // 0x800CC4B4: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800CC4B8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800CC4BC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800CC4C0: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800CC4C4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800CC4C8: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800CC4CC: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800CC4D0: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800CC4D4: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800CC4D8: jr          $ra
    // 0x800CC4DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x800CC4DC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void play_random_boss_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CB04: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8005CB08: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8005CB0C: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8005CB10: sw          $a2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r6;
    // 0x8005CB14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005CB18: jal         0x8006F94C
    // 0x8005CB1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x8005CB1C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_0:
    // 0x8005CB20: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x8005CB24: sll         $v1, $v0, 24
    ctx->r3 = S32(ctx->r2 << 24);
    // 0x8005CB28: sra         $t6, $v1, 24
    ctx->r14 = S32(SIGNED(ctx->r3) >> 24);
    // 0x8005CB2C: bne         $a2, $zero, L_8005CB38
    if (ctx->r6 != 0) {
        // 0x8005CB30: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8005CB38;
    }
    // 0x8005CB30: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x8005CB34: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005CB38:
    // 0x8005CB38: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8005CB3C: lw          $t7, -0x2A38($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2A38);
    // 0x8005CB40: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8005CB44: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x8005CB48: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8005CB4C: lhu         $a0, 0x0($t9)
    ctx->r4 = MEM_HU(ctx->r25, 0X0);
    // 0x8005CB50: jal         0x80001D04
    // 0x8005CB54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x8005CB54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x8005CB58: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8005CB5C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8005CB60: jr          $ra
    // 0x8005CB64: nop

    return;
    // 0x8005CB64: nop

;}
RECOMP_FUNC void sprite_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007CCB0: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007CCB4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8007CCB8: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8007CCBC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8007CCC0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8007CCC4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007CCC8: beq         $a0, $zero, L_8007CDA4
    if (ctx->r4 == 0) {
        // 0x8007CCCC: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8007CDA4;
    }
    // 0x8007CCCC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007CCD0: lh          $t6, 0x4($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X4);
    // 0x8007CCD4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007CCD8: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007CCDC: sh          $t7, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r15;
    // 0x8007CCE0: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8007CCE4: nop

    // 0x8007CCE8: bgtz        $t8, L_8007CDA8
    if (SIGNED(ctx->r24) > 0) {
        // 0x8007CCEC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8007CDA8;
    }
    // 0x8007CCEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007CCF0: lw          $v1, 0x6358($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X6358);
    // 0x8007CCF4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007CCF8: blez        $v1, L_8007CDA4
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007CCFC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_8007CDA4;
    }
    // 0x8007CCFC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007CD00: lw          $a0, 0x634C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X634C);
    // 0x8007CD04: nop

    // 0x8007CD08: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_8007CD0C:
    // 0x8007CD0C: sll         $t9, $s3, 3
    ctx->r25 = S32(ctx->r19 << 3);
    // 0x8007CD10: addu        $t0, $a0, $t9
    ctx->r8 = ADD32(ctx->r4, ctx->r25);
    // 0x8007CD14: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8007CD18: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x8007CD1C: bne         $s2, $t1, L_8007CD98
    if (ctx->r18 != ctx->r9) {
        // 0x8007CD20: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8007CD98;
    }
    // 0x8007CD20: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007CD24: lh          $t2, 0x2($s2)
    ctx->r10 = MEM_H(ctx->r18, 0X2);
    // 0x8007CD28: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8007CD2C: blez        $t2, L_8007CD60
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8007CD30: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8007CD60;
    }
    // 0x8007CD30: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007CD34:
    // 0x8007CD34: lw          $t3, 0x8($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X8);
    // 0x8007CD38: nop

    // 0x8007CD3C: addu        $t4, $t3, $s1
    ctx->r12 = ADD32(ctx->r11, ctx->r17);
    // 0x8007CD40: lw          $a0, 0x0($t4)
    ctx->r4 = MEM_W(ctx->r12, 0X0);
    // 0x8007CD44: jal         0x8007B2BC
    // 0x8007CD48: nop

    tex_free(rdram, ctx);
        goto after_0;
    // 0x8007CD48: nop

    after_0:
    // 0x8007CD4C: lh          $t5, 0x2($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X2);
    // 0x8007CD50: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007CD54: slt         $at, $s0, $t5
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007CD58: bne         $at, $zero, L_8007CD34
    if (ctx->r1 != 0) {
        // 0x8007CD5C: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8007CD34;
    }
    // 0x8007CD5C: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8007CD60:
    // 0x8007CD60: jal         0x80071140
    // 0x8007CD64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_1;
    // 0x8007CD64: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_1:
    // 0x8007CD68: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007CD6C: addiu       $v0, $v0, 0x634C
    ctx->r2 = ADD32(ctx->r2, 0X634C);
    // 0x8007CD70: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8007CD74: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8007CD78: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x8007CD7C: sw          $v1, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r3;
    // 0x8007CD80: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8007CD84: nop

    // 0x8007CD88: addu        $t9, $t8, $s3
    ctx->r25 = ADD32(ctx->r24, ctx->r19);
    // 0x8007CD8C: b           L_8007CDA4
    // 0x8007CD90: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
        goto L_8007CDA4;
    // 0x8007CD90: sw          $v1, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r3;
    // 0x8007CD94: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8007CD98:
    // 0x8007CD98: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8007CD9C: bne         $at, $zero, L_8007CD0C
    if (ctx->r1 != 0) {
        // 0x8007CDA0: or          $s3, $v0, $zero
        ctx->r19 = ctx->r2 | 0;
            goto L_8007CD0C;
    }
    // 0x8007CDA0: or          $s3, $v0, $zero
    ctx->r19 = ctx->r2 | 0;
L_8007CDA4:
    // 0x8007CDA4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8007CDA8:
    // 0x8007CDA8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007CDAC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007CDB0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8007CDB4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8007CDB8: jr          $ra
    // 0x8007CDBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8007CDBC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void obj_loop_texscroll(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80040148: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8004014C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80040150: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80040154: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x80040158: lw          $t5, 0x64($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X64);
    // 0x8004015C: jal         0x8002C7C4
    // 0x80040160: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    get_current_level_model(rdram, ctx);
        goto after_0;
    // 0x80040160: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    after_0:
    // 0x80040164: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80040168: lw          $t2, 0x3C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X3C);
    // 0x8004016C: lh          $t0, 0x4($t5)
    ctx->r8 = MEM_H(ctx->r13, 0X4);
    // 0x80040170: lh          $t1, 0x6($t5)
    ctx->r9 = MEM_H(ctx->r13, 0X6);
    // 0x80040174: multu       $t0, $t2
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80040178: lh          $t7, 0x0($t5)
    ctx->r15 = MEM_H(ctx->r13, 0X0);
    // 0x8004017C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80040180: sll         $t8, $t7, 3
    ctx->r24 = S32(ctx->r15 << 3);
    // 0x80040184: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x80040188: lw          $v1, 0x0($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X0);
    // 0x8004018C: lh          $t8, 0x8($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X8);
    // 0x80040190: lbu         $a2, 0x0($v1)
    ctx->r6 = MEM_BU(ctx->r3, 0X0);
    // 0x80040194: lbu         $a3, 0x1($v1)
    ctx->r7 = MEM_BU(ctx->r3, 0X1);
    // 0x80040198: sll         $t7, $a2, 8
    ctx->r15 = S32(ctx->r6 << 8);
    // 0x8004019C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800401A0: lh          $t7, 0xA($t5)
    ctx->r15 = MEM_H(ctx->r13, 0XA);
    // 0x800401A4: mflo        $t0
    ctx->r8 = lo;
    // 0x800401A8: sll         $t6, $a3, 8
    ctx->r14 = S32(ctx->r7 << 8);
    // 0x800401AC: or          $a3, $t6, $zero
    ctx->r7 = ctx->r14 | 0;
    // 0x800401B0: multu       $t1, $t2
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r10)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800401B4: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x800401B8: sh          $t9, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r25;
    // 0x800401BC: lh          $a0, 0x8($t5)
    ctx->r4 = MEM_H(ctx->r13, 0X8);
    // 0x800401C0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800401C4: andi        $t8, $a0, 0x3
    ctx->r24 = ctx->r4 & 0X3;
    // 0x800401C8: sh          $t8, 0x8($t5)
    MEM_H(0X8, ctx->r13) = ctx->r24;
    // 0x800401CC: or          $ra, $zero, $zero
    ctx->r31 = 0 | 0;
    // 0x800401D0: sra         $t0, $a0, 2
    ctx->r8 = S32(SIGNED(ctx->r4) >> 2);
    // 0x800401D4: mflo        $t1
    ctx->r9 = lo;
    // 0x800401D8: addu        $t6, $t7, $t1
    ctx->r14 = ADD32(ctx->r15, ctx->r9);
    // 0x800401DC: sh          $t6, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r14;
    // 0x800401E0: lh          $a1, 0xA($t5)
    ctx->r5 = MEM_H(ctx->r13, 0XA);
    // 0x800401E4: nop

    // 0x800401E8: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x800401EC: sh          $t9, 0xA($t5)
    MEM_H(0XA, ctx->r13) = ctx->r25;
    // 0x800401F0: lh          $t7, 0x1A($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X1A);
    // 0x800401F4: lw          $v1, 0x4($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X4);
    // 0x800401F8: blez        $t7, L_80040398
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800401FC: sra         $t1, $a1, 2
        ctx->r9 = S32(SIGNED(ctx->r5) >> 2);
            goto L_80040398;
    }
    // 0x800401FC: sra         $t1, $a1, 2
    ctx->r9 = S32(SIGNED(ctx->r5) >> 2);
    // 0x80040200: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
L_80040204:
    // 0x80040204: lh          $v0, 0x20($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X20);
    // 0x80040208: lw          $v1, 0xC($t3)
    ctx->r3 = MEM_W(ctx->r11, 0XC);
    // 0x8004020C: blez        $v0, L_80040384
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80040210: or          $t4, $zero, $zero
        ctx->r12 = 0 | 0;
            goto L_80040384;
    }
    // 0x80040210: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x80040214: or          $t2, $v1, $zero
    ctx->r10 = ctx->r3 | 0;
L_80040218:
    // 0x80040218: lh          $t6, 0x0($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X0);
    // 0x8004021C: lbu         $t8, 0x0($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X0);
    // 0x80040220: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x80040224: bne         $t6, $t8, L_8004037C
    if (ctx->r14 != ctx->r24) {
        // 0x80040228: slt         $at, $t4, $v0
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8004037C;
    }
    // 0x80040228: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8004022C: lh          $a1, 0x4($t2)
    ctx->r5 = MEM_H(ctx->r10, 0X4);
    // 0x80040230: lh          $a0, 0x10($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X10);
    // 0x80040234: nop

    // 0x80040238: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8004023C: beq         $at, $zero, L_8004037C
    if (ctx->r1 == 0) {
        // 0x80040240: slt         $at, $t4, $v0
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8004037C;
    }
    // 0x80040240: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
L_80040244:
    // 0x80040244: lw          $t9, 0x4($t3)
    ctx->r25 = MEM_W(ctx->r11, 0X4);
    // 0x80040248: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x8004024C: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x80040250: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80040254: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80040258: andi        $t8, $t6, 0x80
    ctx->r24 = ctx->r14 & 0X80;
    // 0x8004025C: bne         $t8, $zero, L_80040368
    if (ctx->r24 != 0) {
        // 0x80040260: slt         $at, $a1, $a0
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_80040368;
    }
    // 0x80040260: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80040264: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80040268: nop

    // 0x8004026C: slt         $at, $a3, $v1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80040270: beq         $at, $zero, L_80040298
    if (ctx->r1 == 0) {
        // 0x80040274: subu        $t9, $v1, $a3
        ctx->r25 = SUB32(ctx->r3, ctx->r7);
            goto L_80040298;
    }
    // 0x80040274: subu        $t9, $v1, $a3
    ctx->r25 = SUB32(ctx->r3, ctx->r7);
    // 0x80040278: lh          $t7, 0xA($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XA);
    // 0x8004027C: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x80040280: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x80040284: subu        $t6, $t7, $a3
    ctx->r14 = SUB32(ctx->r15, ctx->r7);
    // 0x80040288: subu        $t9, $t8, $a3
    ctx->r25 = SUB32(ctx->r24, ctx->r7);
    // 0x8004028C: lh          $v1, 0x6($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X6);
    // 0x80040290: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x80040294: sh          $t9, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r25;
L_80040298:
    // 0x80040298: bgez        $v1, L_800402BC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8004029C: addu        $t7, $v1, $a3
        ctx->r15 = ADD32(ctx->r3, ctx->r7);
            goto L_800402BC;
    }
    // 0x8004029C: addu        $t7, $v1, $a3
    ctx->r15 = ADD32(ctx->r3, ctx->r7);
    // 0x800402A0: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x800402A4: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x800402A8: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x800402AC: addu        $t8, $t6, $a3
    ctx->r24 = ADD32(ctx->r14, ctx->r7);
    // 0x800402B0: addu        $t7, $t9, $a3
    ctx->r15 = ADD32(ctx->r25, ctx->r7);
    // 0x800402B4: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x800402B8: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
L_800402BC:
    // 0x800402BC: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800402C0: nop

    // 0x800402C4: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800402C8: beq         $at, $zero, L_800402F0
    if (ctx->r1 == 0) {
        // 0x800402CC: subu        $t6, $v1, $a2
        ctx->r14 = SUB32(ctx->r3, ctx->r6);
            goto L_800402F0;
    }
    // 0x800402CC: subu        $t6, $v1, $a2
    ctx->r14 = SUB32(ctx->r3, ctx->r6);
    // 0x800402D0: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x800402D4: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x800402D8: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x800402DC: subu        $t9, $t8, $a2
    ctx->r25 = SUB32(ctx->r24, ctx->r6);
    // 0x800402E0: subu        $t6, $t7, $a2
    ctx->r14 = SUB32(ctx->r15, ctx->r6);
    // 0x800402E4: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x800402E8: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x800402EC: sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
L_800402F0:
    // 0x800402F0: bgez        $v1, L_80040318
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800402F4: addu        $t8, $v1, $a2
        ctx->r24 = ADD32(ctx->r3, ctx->r6);
            goto L_80040318;
    }
    // 0x800402F4: addu        $t8, $v1, $a2
    ctx->r24 = ADD32(ctx->r3, ctx->r6);
    // 0x800402F8: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800402FC: lh          $t6, 0xC($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XC);
    // 0x80040300: sh          $t8, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r24;
    // 0x80040304: addu        $t7, $t9, $a2
    ctx->r15 = ADD32(ctx->r25, ctx->r6);
    // 0x80040308: addu        $t8, $t6, $a2
    ctx->r24 = ADD32(ctx->r14, ctx->r6);
    // 0x8004030C: lh          $v1, 0x4($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X4);
    // 0x80040310: sh          $t7, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r15;
    // 0x80040314: sh          $t8, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r24;
L_80040318:
    // 0x80040318: lh          $t9, 0x6($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X6);
    // 0x8004031C: lh          $t6, 0xA($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XA);
    // 0x80040320: addu        $t7, $t9, $t1
    ctx->r15 = ADD32(ctx->r25, ctx->r9);
    // 0x80040324: lh          $t9, 0xE($v0)
    ctx->r25 = MEM_H(ctx->r2, 0XE);
    // 0x80040328: sh          $t7, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r15;
    // 0x8004032C: addu        $t8, $t6, $t1
    ctx->r24 = ADD32(ctx->r14, ctx->r9);
    // 0x80040330: addu        $t7, $t9, $t1
    ctx->r15 = ADD32(ctx->r25, ctx->r9);
    // 0x80040334: sh          $t8, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r24;
    // 0x80040338: sh          $t7, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r15;
    // 0x8004033C: lh          $t8, 0x8($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X8);
    // 0x80040340: lh          $t7, 0xC($v0)
    ctx->r15 = MEM_H(ctx->r2, 0XC);
    // 0x80040344: addu        $t6, $v1, $t0
    ctx->r14 = ADD32(ctx->r3, ctx->r8);
    // 0x80040348: sh          $t6, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r14;
    // 0x8004034C: addu        $t9, $t8, $t0
    ctx->r25 = ADD32(ctx->r24, ctx->r8);
    // 0x80040350: addu        $t6, $t7, $t0
    ctx->r14 = ADD32(ctx->r15, ctx->r8);
    // 0x80040354: sh          $t9, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r25;
    // 0x80040358: sh          $t6, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r14;
    // 0x8004035C: lh          $a0, 0x10($t2)
    ctx->r4 = MEM_H(ctx->r10, 0X10);
    // 0x80040360: nop

    // 0x80040364: slt         $at, $a1, $a0
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r4) ? 1 : 0;
L_80040368:
    // 0x80040368: bne         $at, $zero, L_80040244
    if (ctx->r1 != 0) {
        // 0x8004036C: nop
    
            goto L_80040244;
    }
    // 0x8004036C: nop

    // 0x80040370: lh          $v0, 0x20($t3)
    ctx->r2 = MEM_H(ctx->r11, 0X20);
    // 0x80040374: nop

    // 0x80040378: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
L_8004037C:
    // 0x8004037C: bne         $at, $zero, L_80040218
    if (ctx->r1 != 0) {
        // 0x80040380: addiu       $t2, $t2, 0xC
        ctx->r10 = ADD32(ctx->r10, 0XC);
            goto L_80040218;
    }
    // 0x80040380: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
L_80040384:
    // 0x80040384: lh          $t8, 0x1A($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X1A);
    // 0x80040388: addiu       $ra, $ra, 0x1
    ctx->r31 = ADD32(ctx->r31, 0X1);
    // 0x8004038C: slt         $at, $ra, $t8
    ctx->r1 = SIGNED(ctx->r31) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80040390: bne         $at, $zero, L_80040204
    if (ctx->r1 != 0) {
        // 0x80040394: addiu       $t3, $t3, 0x44
        ctx->r11 = ADD32(ctx->r11, 0X44);
            goto L_80040204;
    }
    // 0x80040394: addiu       $t3, $t3, 0x44
    ctx->r11 = ADD32(ctx->r11, 0X44);
L_80040398:
    // 0x80040398: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8004039C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800403A0: jr          $ra
    // 0x800403A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800403A4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void light_setup_intensity_change(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032344: blez        $a2, L_80032390
    if (SIGNED(ctx->r6) <= 0) {
        // 0x80032348: nop
    
            goto L_80032390;
    }
    // 0x80032348: nop

    // 0x8003234C: lw          $t7, 0x28($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X28);
    // 0x80032350: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x80032354: subu        $t8, $t6, $t7
    ctx->r24 = SUB32(ctx->r14, ctx->r15);
    // 0x80032358: div         $zero, $t8, $a2
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r6))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r6)));
    // 0x8003235C: sh          $a2, 0x42($a0)
    MEM_H(0X42, ctx->r4) = ctx->r6;
    // 0x80032360: bne         $a2, $zero, L_8003236C
    if (ctx->r6 != 0) {
        // 0x80032364: nop
    
            goto L_8003236C;
    }
    // 0x80032364: nop

    // 0x80032368: break       7
    do_break(2147689320);
L_8003236C:
    // 0x8003236C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80032370: bne         $a2, $at, L_80032384
    if (ctx->r6 != ctx->r1) {
        // 0x80032374: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80032384;
    }
    // 0x80032374: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80032378: bne         $t8, $at, L_80032384
    if (ctx->r24 != ctx->r1) {
        // 0x8003237C: nop
    
            goto L_80032384;
    }
    // 0x8003237C: nop

    // 0x80032380: break       6
    do_break(2147689344);
L_80032384:
    // 0x80032384: mflo        $t9
    ctx->r25 = lo;
    // 0x80032388: sw          $t9, 0x38($a0)
    MEM_W(0X38, ctx->r4) = ctx->r25;
    // 0x8003238C: nop

L_80032390:
    // 0x80032390: jr          $ra
    // 0x80032394: nop

    return;
    // 0x80032394: nop

;}
RECOMP_FUNC void obj_loop_bananacreator(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D3FC: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8003D400: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8003D404: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003D408: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x8003D40C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003D410: beq         $t6, $zero, L_8003D428
    if (ctx->r14 == 0) {
        // 0x8003D414: nop
    
            goto L_8003D428;
    }
    // 0x8003D414: nop

    // 0x8003D418: lw          $t7, 0x78($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X78);
    // 0x8003D41C: nop

    // 0x8003D420: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x8003D424: sw          $t8, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r24;
L_8003D428:
    // 0x8003D428: lw          $t9, 0x78($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X78);
    // 0x8003D42C: nop

    // 0x8003D430: bgtz        $t9, L_8003D528
    if (SIGNED(ctx->r25) > 0) {
        // 0x8003D434: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8003D528;
    }
    // 0x8003D434: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8003D438: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8003D43C: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D440: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8003D444: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D448: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D44C: addiu       $t9, $zero, 0x8
    ctx->r25 = ADD32(0, 0X8);
    // 0x8003D450: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8003D454: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    // 0x8003D458: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8003D45C: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x8003D460: addiu       $t0, $zero, 0x53
    ctx->r8 = ADD32(0, 0X53);
    // 0x8003D464: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x8003D468: sh          $t1, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r9;
    // 0x8003D46C: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x8003D470: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D474: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D478: lwc1        $f8, 0x10($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D47C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8003D480: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8003D484: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x8003D488: mfc1        $t5, $f10
    ctx->r13 = (int32_t)ctx->f10.u32l;
    // 0x8003D48C: nop

    // 0x8003D490: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8003D494: addiu       $t6, $t5, -0x3
    ctx->r14 = ADD32(ctx->r13, -0X3);
    // 0x8003D498: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8003D49C: sh          $t6, 0x3C($sp)
    MEM_H(0X3C, ctx->r29) = ctx->r14;
    // 0x8003D4A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8003D4A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8003D4A8: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x8003D4AC: sb          $t9, 0x39($sp)
    MEM_B(0X39, ctx->r29) = ctx->r25;
    // 0x8003D4B0: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8003D4B4: sb          $t0, 0x38($sp)
    MEM_B(0X38, ctx->r29) = ctx->r8;
    // 0x8003D4B8: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x8003D4BC: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8003D4C0: jal         0x8000EA54
    // 0x8003D4C4: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    spawn_object(rdram, ctx);
        goto after_0;
    // 0x8003D4C4: sh          $t8, 0x3E($sp)
    MEM_H(0X3E, ctx->r29) = ctx->r24;
    after_0:
    // 0x8003D4C8: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8003D4CC: beq         $v0, $zero, L_8003D51C
    if (ctx->r2 == 0) {
        // 0x8003D4D0: sw          $t1, 0x7C($s0)
        MEM_W(0X7C, ctx->r16) = ctx->r9;
            goto L_8003D51C;
    }
    // 0x8003D4D0: sw          $t1, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r9;
    // 0x8003D4D4: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8003D4D8: lw          $v0, 0x64($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X64);
    // 0x8003D4DC: lui         $at, 0x4160
    ctx->r1 = S32(0X4160 << 16);
    // 0x8003D4E0: sw          $s0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r16;
    // 0x8003D4E4: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003D4E8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8003D4EC: lui         $at, 0x3E80
    ctx->r1 = S32(0X3E80 << 16);
    // 0x8003D4F0: lw          $a2, 0x14($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X14);
    // 0x8003D4F4: lwc1        $f12, 0xC($s0)
    ctx->f12.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8003D4F8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003D4FC: addiu       $t2, $zero, 0x22
    ctx->r10 = ADD32(0, 0X22);
    // 0x8003D500: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8003D504: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8003D508: addiu       $a3, $zero, 0x2C
    ctx->r7 = ADD32(0, 0X2C);
    // 0x8003D50C: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003D510: jal         0x8003FC44
    // 0x8003D514: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    obj_spawn_effect(rdram, ctx);
        goto after_1;
    // 0x8003D514: swc1        $f8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f8.u32l;
    after_1:
    // 0x8003D518: sw          $zero, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = 0;
L_8003D51C:
    // 0x8003D51C: addiu       $t3, $zero, 0x4B0
    ctx->r11 = ADD32(0, 0X4B0);
    // 0x8003D520: sw          $t3, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r11;
    // 0x8003D524: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8003D528:
    // 0x8003D528: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003D52C: jr          $ra
    // 0x8003D530: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8003D530: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void tex_cache_asset_id(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C860: bltz        $a0, L_8007C87C
    if (SIGNED(ctx->r4) < 0) {
        // 0x8007C864: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8007C87C;
    }
    // 0x8007C864: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8007C868: lw          $t6, 0x6330($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6330);
    // 0x8007C86C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8007C870: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8007C874: bne         $at, $zero, L_8007C884
    if (ctx->r1 != 0) {
        // 0x8007C878: nop
    
            goto L_8007C884;
    }
    // 0x8007C878: nop

L_8007C87C:
    // 0x8007C87C: jr          $ra
    // 0x8007C880: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    return;
    // 0x8007C880: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007C884:
    // 0x8007C884: lw          $t7, 0x6328($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6328);
    // 0x8007C888: sll         $t9, $a0, 3
    ctx->r25 = S32(ctx->r4 << 3);
    // 0x8007C88C: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8007C890: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8007C894: nop

    // 0x8007C898: jr          $ra
    // 0x8007C89C: nop

    return;
    // 0x8007C89C: nop

;}
RECOMP_FUNC void screenimage_draw(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007F714: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007F718: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8007F71C: sw          $fp, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r30;
    // 0x8007F720: sw          $s7, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r23;
    // 0x8007F724: sw          $s6, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r22;
    // 0x8007F728: sw          $s5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r21;
    // 0x8007F72C: sw          $s4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r20;
    // 0x8007F730: sw          $s3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r19;
    // 0x8007F734: sw          $s2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r18;
    // 0x8007F738: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8007F73C: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8007F740: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F744: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8007F748: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F74C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007F750: addiu       $t8, $t8, -0xBC0
    ctx->r24 = ADD32(ctx->r24, -0XBC0);
    // 0x8007F754: lui         $t7, 0x702
    ctx->r15 = S32(0X702 << 16);
    // 0x8007F758: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007F75C: addu        $t9, $t8, $at
    ctx->r25 = ADD32(ctx->r24, ctx->r1);
    // 0x8007F760: ori         $t7, $t7, 0x10
    ctx->r15 = ctx->r15 | 0X10;
    // 0x8007F764: lui         $s1, 0x708
    ctx->r17 = S32(0X708 << 16);
    // 0x8007F768: lui         $s4, 0x777
    ctx->r20 = S32(0X777 << 16);
    // 0x8007F76C: lui         $s6, 0xF510
    ctx->r22 = S32(0XF510 << 16);
    // 0x8007F770: lui         $s7, 0x8
    ctx->r23 = S32(0X8 << 16);
    // 0x8007F774: lui         $ra, 0x4F
    ctx->r31 = S32(0X4F << 16);
    // 0x8007F778: addiu       $s0, $a1, 0x10
    ctx->r16 = ADD32(ctx->r5, 0X10);
    // 0x8007F77C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8007F780: ori         $ra, $ra, 0xC014
    ctx->r31 = ctx->r31 | 0XC014;
    // 0x8007F784: ori         $s7, $s7, 0x200
    ctx->r23 = ctx->r23 | 0X200;
    // 0x8007F788: ori         $s6, $s6, 0xA000
    ctx->r22 = ctx->r22 | 0XA000;
    // 0x8007F78C: ori         $s4, $s4, 0xF000
    ctx->r20 = ctx->r20 | 0XF000;
    // 0x8007F790: ori         $s1, $s1, 0x200
    ctx->r17 = ctx->r17 | 0X200;
    // 0x8007F794: lui         $s2, 0xE600
    ctx->r18 = S32(0XE600 << 16);
    // 0x8007F798: lui         $s3, 0xF300
    ctx->r19 = S32(0XF300 << 16);
    // 0x8007F79C: lui         $s5, 0xE700
    ctx->r21 = S32(0XE700 << 16);
    // 0x8007F7A0: lui         $fp, 0xF200
    ctx->r30 = S32(0XF200 << 16);
    // 0x8007F7A4: lui         $t5, 0xF510
    ctx->r13 = S32(0XF510 << 16);
    // 0x8007F7A8: lui         $t4, 0x8000
    ctx->r12 = S32(0X8000 << 16);
    // 0x8007F7AC: lui         $t3, 0xFD10
    ctx->r11 = S32(0XFD10 << 16);
    // 0x8007F7B0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007F7B4: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
L_8007F7B8:
    // 0x8007F7B8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F7BC: addu        $t7, $s0, $t4
    ctx->r15 = ADD32(ctx->r16, ctx->r12);
    // 0x8007F7C0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F7C4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007F7C8: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007F7CC: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
    // 0x8007F7D0: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F7D4: addiu       $t2, $a3, 0x6
    ctx->r10 = ADD32(ctx->r7, 0X6);
    // 0x8007F7D8: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007F7DC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007F7E0: sw          $s1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r17;
    // 0x8007F7E4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x8007F7E8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F7EC: lui         $at, 0xE450
    ctx->r1 = S32(0XE450 << 16);
    // 0x8007F7F0: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F7F4: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007F7F8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F7FC: sw          $s2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r18;
    // 0x8007F800: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F804: addiu       $s0, $s0, 0xF00
    ctx->r16 = ADD32(ctx->r16, 0XF00);
    // 0x8007F808: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F80C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007F810: sw          $s4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r20;
    // 0x8007F814: sw          $s3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r19;
    // 0x8007F818: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F81C: nop

    // 0x8007F820: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x8007F824: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007F828: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F82C: sw          $s5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r21;
    // 0x8007F830: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F834: sll         $t7, $t2, 2
    ctx->r15 = S32(ctx->r10 << 2);
    // 0x8007F838: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007F83C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007F840: sw          $s7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r23;
    // 0x8007F844: sw          $s6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r22;
    // 0x8007F848: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F84C: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007F850: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x8007F854: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007F858: sw          $ra, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r31;
    // 0x8007F85C: sw          $fp, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r30;
    // 0x8007F860: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F864: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8007F868: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F86C: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007F870: sll         $t6, $a3, 2
    ctx->r14 = S32(ctx->r7 << 2);
    // 0x8007F874: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007F878: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x8007F87C: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007F880: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F884: lui         $t9, 0xB300
    ctx->r25 = S32(0XB300 << 16);
    // 0x8007F888: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x8007F88C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007F890: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007F894: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007F898: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8007F89C: lui         $t8, 0x1000
    ctx->r24 = S32(0X1000 << 16);
    // 0x8007F8A0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x8007F8A4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007F8A8: ori         $t8, $t8, 0x400
    ctx->r24 = ctx->r24 | 0X400;
    // 0x8007F8AC: lui         $t7, 0xB200
    ctx->r15 = S32(0XB200 << 16);
    // 0x8007F8B0: addiu       $at, $zero, 0xF0
    ctx->r1 = ADD32(0, 0XF0);
    // 0x8007F8B4: or          $a3, $t2, $zero
    ctx->r7 = ctx->r10 | 0;
    // 0x8007F8B8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007F8BC: bne         $t2, $at, L_8007F7B8
    if (ctx->r10 != ctx->r1) {
        // 0x8007F8C0: sw          $t8, 0x4($v0)
        MEM_W(0X4, ctx->r2) = ctx->r24;
            goto L_8007F7B8;
    }
    // 0x8007F8C0: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x8007F8C4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8007F8C8: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8007F8CC: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8007F8D0: lw          $s2, 0x10($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X10);
    // 0x8007F8D4: lw          $s3, 0x14($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X14);
    // 0x8007F8D8: lw          $s4, 0x18($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X18);
    // 0x8007F8DC: lw          $s5, 0x1C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X1C);
    // 0x8007F8E0: lw          $s6, 0x20($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X20);
    // 0x8007F8E4: lw          $s7, 0x24($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X24);
    // 0x8007F8E8: lw          $fp, 0x28($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X28);
    // 0x8007F8EC: jr          $ra
    // 0x8007F8F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8007F8F0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void sndp_stop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000488C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80004890: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80004894: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80004898: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x8000489C: beq         $a0, $zero, L_800048C8
    if (ctx->r4 == 0) {
        // 0x800048A0: sw          $a0, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r4;
            goto L_800048C8;
    }
    // 0x800048A0: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    // 0x800048A4: lbu         $t7, 0x3E($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3E);
    // 0x800048A8: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800048AC: andi        $t8, $t7, 0xFFEF
    ctx->r24 = ctx->r15 & 0XFFEF;
    // 0x800048B0: sb          $t8, 0x3E($a0)
    MEM_B(0X3E, ctx->r4) = ctx->r24;
    // 0x800048B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800048B8: lw          $a0, -0x3944($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X3944);
    // 0x800048BC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800048C0: jal         0x800C91AC
    // 0x800048C4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800048C4: addiu       $a0, $a0, 0x14
    ctx->r4 = ADD32(ctx->r4, 0X14);
    after_0:
L_800048C8:
    // 0x800048C8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800048CC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800048D0: jr          $ra
    // 0x800048D4: nop

    return;
    // 0x800048D4: nop

;}
