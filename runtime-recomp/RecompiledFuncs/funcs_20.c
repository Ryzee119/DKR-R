#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void drm_checksum_balloon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005A3D0: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8005A3D4: lw          $a1, -0x34B0($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X34B0);
    // 0x8005A3D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005A3DC: blez        $a1, L_8005A404
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005A3E0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8005A404;
    }
    // 0x8005A3E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005A3E4: lui         $v1, 0x8004
    ctx->r3 = S32(0X8004 << 16);
    // 0x8005A3E8: addiu       $v1, $v1, -0x4B44
    ctx->r3 = ADD32(ctx->r3, -0X4B44);
L_8005A3EC:
    // 0x8005A3EC: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x8005A3F0: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x8005A3F4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8005A3F8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005A3FC: bne         $at, $zero, L_8005A3EC
    if (ctx->r1 != 0) {
        // 0x8005A400: addu        $v0, $v0, $t7
        ctx->r2 = ADD32(ctx->r2, ctx->r15);
            goto L_8005A3EC;
    }
    // 0x8005A400: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
L_8005A404:
    // 0x8005A404: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8005A408: lw          $t8, -0x3230($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X3230);
    // 0x8005A40C: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x8005A410: beq         $v0, $t8, L_8005A41C
    if (ctx->r2 == ctx->r24) {
        // 0x8005A414: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8005A41C;
    }
    // 0x8005A414: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005A418: sh          $t9, -0x34AC($at)
    MEM_H(-0X34AC, ctx->r1) = ctx->r25;
L_8005A41C:
    // 0x8005A41C: jr          $ra
    // 0x8005A420: nop

    return;
    // 0x8005A420: nop

;}
RECOMP_FUNC void menu_magic_codes_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800895DC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800895E0: sh          $zero, 0x6C40($at)
    MEM_H(0X6C40, ctx->r1) = 0;
    // 0x800895E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800895E8: sh          $zero, 0x6C42($at)
    MEM_H(0X6C42, ctx->r1) = 0;
    // 0x800895EC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800895F0: sh          $zero, 0x6C46($at)
    MEM_H(0X6C46, ctx->r1) = 0;
    // 0x800895F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800895F8: sh          $zero, 0x6C44($at)
    MEM_H(0X6C44, ctx->r1) = 0;
    // 0x800895FC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089600: sw          $zero, 0x6470($at)
    MEM_W(0X6470, ctx->r1) = 0;
    // 0x80089604: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089608: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8008960C: sh          $t6, 0x6C4C($at)
    MEM_H(0X6C4C, ctx->r1) = ctx->r14;
    // 0x80089610: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80089614: sb          $zero, 0x6C58($at)
    MEM_B(0X6C58, ctx->r1) = 0;
    // 0x80089618: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008961C: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x80089620: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089624: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x80089628: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008962C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80089630: sw          $zero, 0x63D8($at)
    MEM_W(0X63D8, ctx->r1) = 0;
    // 0x80089634: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80089638: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008963C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80089640: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x80089644: jal         0x800C01D8
    // 0x80089648: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_0;
    // 0x80089648: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_0:
    // 0x8008964C: addiu       $t7, $zero, 0x84
    ctx->r15 = ADD32(0, 0X84);
    // 0x80089650: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80089654: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80089658: addiu       $a1, $zero, 0x32
    ctx->r5 = ADD32(0, 0X32);
    // 0x8008965C: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    // 0x80089660: jal         0x800C4EDC
    // 0x80089664: addiu       $a3, $zero, 0x10E
    ctx->r7 = ADD32(0, 0X10E);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_1;
    // 0x80089664: addiu       $a3, $zero, 0x10E
    ctx->r7 = ADD32(0, 0X10E);
    after_1:
    // 0x80089668: addiu       $t8, $zero, 0x80
    ctx->r24 = ADD32(0, 0X80);
    // 0x8008966C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80089670: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80089674: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80089678: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008967C: jal         0x800C4FBC
    // 0x80089680: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x80089680: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80089684: jal         0x800C5494
    // 0x80089688: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x80089688: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_3:
    // 0x8008968C: jal         0x800C4170
    // 0x80089690: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_4;
    // 0x80089690: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80089694: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80089698: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8008969C: jr          $ra
    // 0x800896A0: nop

    return;
    // 0x800896A0: nop

;}
RECOMP_FUNC void func_8002DE30(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002DE30: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x8002DE34: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8002DE38: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8002DE3C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8002DE40: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8002DE44: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8002DE48: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8002DE4C: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8002DE50: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8002DE54: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8002DE58: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8002DE5C: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8002DE60: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8002DE64: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8002DE68: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x8002DE6C: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002DE70: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8002DE74: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DE78: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DE7C: lwc1        $f4, 0x10($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8002DE80: lw          $a1, 0x40($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X40);
    // 0x8002DE84: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002DE88: lh          $t7, 0x44($a1)
    ctx->r15 = MEM_H(ctx->r5, 0X44);
    // 0x8002DE8C: mfc1        $v0, $f6
    ctx->r2 = (int32_t)ctx->f6.u32l;
    // 0x8002DE90: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002DE94: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8002DE98: sw          $t8, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r24;
    // 0x8002DE9C: lh          $t9, 0x42($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X42);
    // 0x8002DEA0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8002DEA4: addu        $t4, $v0, $t9
    ctx->r12 = ADD32(ctx->r2, ctx->r25);
    // 0x8002DEA8: sw          $t4, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r12;
    // 0x8002DEAC: lh          $v1, 0x2E($a0)
    ctx->r3 = MEM_H(ctx->r4, 0X2E);
    // 0x8002DEB0: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8002DEB4: beq         $v1, $at, L_8002E1F4
    if (ctx->r3 == ctx->r1) {
        // 0x8002DEB8: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_8002E1F4;
    }
    // 0x8002DEB8: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x8002DEBC: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x8002DEC0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8002DEC4: lwc1        $f0, 0xC($s6)
    ctx->f0.u32l = MEM_W(ctx->r22, 0XC);
    // 0x8002DEC8: lwc1        $f2, 0x14($s6)
    ctx->f2.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8002DECC: sub.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x8002DED0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8002DED4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002DED8: addiu       $s0, $s0, -0x36E8
    ctx->r16 = ADD32(ctx->r16, -0X36E8);
    // 0x8002DEDC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002DEE0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DEE4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DEE8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8002DEEC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002DEF0: lw          $t6, 0x8($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X8);
    // 0x8002DEF4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002DEF8: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x8002DEFC: sub.s       $f16, $f2, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x8002DF00: subu        $t7, $t7, $v1
    ctx->r15 = SUB32(ctx->r15, ctx->r3);
    // 0x8002DF04: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002DF08: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x8002DF0C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002DF10: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DF14: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DF18: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002DF1C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002DF20: addu        $a0, $t6, $t7
    ctx->r4 = ADD32(ctx->r14, ctx->r15);
    // 0x8002DF24: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002DF28: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8002DF2C: add.s       $f4, $f0, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f0.fl + ctx->f12.fl;
    // 0x8002DF30: sw          $v1, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->r3;
    // 0x8002DF34: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x8002DF38: nop

    // 0x8002DF3C: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x8002DF40: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DF44: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DF48: nop

    // 0x8002DF4C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002DF50: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x8002DF54: mfc1        $a3, $f6
    ctx->r7 = (int32_t)ctx->f6.u32l;
    // 0x8002DF58: add.s       $f8, $f2, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f2.fl + ctx->f12.fl;
    // 0x8002DF5C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x8002DF60: nop

    // 0x8002DF64: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x8002DF68: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002DF6C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002DF70: nop

    // 0x8002DF74: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8002DF78: mfc1        $t6, $f10
    ctx->r14 = (int32_t)ctx->f10.u32l;
    // 0x8002DF7C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x8002DF80: jal         0x800314DC
    // 0x8002DF84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    compute_grid_overlap_mask(rdram, ctx);
        goto after_0;
    // 0x8002DF84: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_0:
    // 0x8002DF88: lw          $v1, 0x8C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X8C);
    // 0x8002DF8C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8002DF90: sll         $t9, $v1, 4
    ctx->r25 = S32(ctx->r3 << 4);
    // 0x8002DF94: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002DF98: addu        $t9, $t9, $v1
    ctx->r25 = ADD32(ctx->r25, ctx->r3);
    // 0x8002DF9C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x8002DFA0: sw          $zero, 0x78($sp)
    MEM_W(0X78, ctx->r29) = 0;
    // 0x8002DFA4: addu        $s5, $t8, $t9
    ctx->r21 = ADD32(ctx->r24, ctx->r25);
    // 0x8002DFA8: lh          $t4, 0x20($s5)
    ctx->r12 = MEM_H(ctx->r21, 0X20);
    // 0x8002DFAC: or          $t3, $v0, $zero
    ctx->r11 = ctx->r2 | 0;
    // 0x8002DFB0: blez        $t4, L_8002E1F4
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8002DFB4: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_8002E1F4;
    }
    // 0x8002DFB4: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8002DFB8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8002DFBC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x8002DFC0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002DFC4: lwc1        $f21, 0x5F40($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X5F40);
    // 0x8002DFC8: lwc1        $f20, 0x5F44($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X5F44);
    // 0x8002DFCC: lw          $v0, 0xC($s5)
    ctx->r2 = MEM_W(ctx->r21, 0XC);
    // 0x8002DFD0: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
    // 0x8002DFD4: addiu       $s1, $zero, 0xA
    ctx->r17 = ADD32(0, 0XA);
L_8002DFD8:
    // 0x8002DFD8: lw          $v1, 0x8($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X8);
    // 0x8002DFDC: nop

    // 0x8002DFE0: andi        $t6, $v1, 0x6900
    ctx->r14 = ctx->r3 & 0X6900;
    // 0x8002DFE4: bne         $t6, $zero, L_8002E1C8
    if (ctx->r14 != 0) {
        // 0x8002DFE8: srl         $fp, $v1, 19
        ctx->r30 = S32(U32(ctx->r3) >> 19);
            goto L_8002E1C8;
    }
    // 0x8002DFE8: srl         $fp, $v1, 19
    ctx->r30 = S32(U32(ctx->r3) >> 19);
    // 0x8002DFEC: lh          $t8, 0x2($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X2);
    // 0x8002DFF0: lh          $s3, 0x4($v0)
    ctx->r19 = MEM_H(ctx->r2, 0X4);
    // 0x8002DFF4: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x8002DFF8: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8002DFFC: lw          $t4, 0x0($s5)
    ctx->r12 = MEM_W(ctx->r21, 0X0);
    // 0x8002E000: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8002E004: andi        $t7, $fp, 0x7
    ctx->r15 = ctx->r30 & 0X7;
    // 0x8002E008: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x8002E00C: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002E010: or          $fp, $t7, $zero
    ctx->r30 = ctx->r15 | 0;
    // 0x8002E014: beq         $at, $zero, L_8002E1C8
    if (ctx->r1 == 0) {
        // 0x8002E018: addu        $s0, $t9, $t4
        ctx->r16 = ADD32(ctx->r25, ctx->r12);
            goto L_8002E1C8;
    }
    // 0x8002E018: addu        $s0, $t9, $t4
    ctx->r16 = ADD32(ctx->r25, ctx->r12);
    // 0x8002E01C: bne         $s7, $zero, L_8002E1C8
    if (ctx->r23 != 0) {
        // 0x8002E020: sll         $s4, $s3, 1
        ctx->r20 = S32(ctx->r19 << 1);
            goto L_8002E1C8;
    }
    // 0x8002E020: sll         $s4, $s3, 1
    ctx->r20 = S32(ctx->r19 << 1);
L_8002E024:
    // 0x8002E024: lw          $t6, 0x10($s5)
    ctx->r14 = MEM_W(ctx->r21, 0X10);
    // 0x8002E028: nop

    // 0x8002E02C: addu        $t7, $t6, $s4
    ctx->r15 = ADD32(ctx->r14, ctx->r20);
    // 0x8002E030: lh          $t8, 0x0($t7)
    ctx->r24 = MEM_H(ctx->r15, 0X0);
    // 0x8002E034: nop

    // 0x8002E038: and         $v0, $t8, $t3
    ctx->r2 = ctx->r24 & ctx->r11;
    // 0x8002E03C: andi        $t9, $v0, 0xFF
    ctx->r25 = ctx->r2 & 0XFF;
    // 0x8002E040: beq         $t9, $zero, L_8002E1A0
    if (ctx->r25 == 0) {
        // 0x8002E044: andi        $t4, $v0, 0xFF00
        ctx->r12 = ctx->r2 & 0XFF00;
            goto L_8002E1A0;
    }
    // 0x8002E044: andi        $t4, $v0, 0xFF00
    ctx->r12 = ctx->r2 & 0XFF00;
    // 0x8002E048: beq         $t4, $zero, L_8002E1A0
    if (ctx->r12 == 0) {
        // 0x8002E04C: nop
    
            goto L_8002E1A0;
    }
    // 0x8002E04C: nop

    // 0x8002E050: lw          $t5, 0x4($s5)
    ctx->r13 = MEM_W(ctx->r21, 0X4);
    // 0x8002E054: sll         $t6, $s3, 4
    ctx->r14 = S32(ctx->r19 << 4);
    // 0x8002E058: addu        $t0, $t5, $t6
    ctx->r8 = ADD32(ctx->r13, ctx->r14);
    // 0x8002E05C: lbu         $t7, 0x1($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X1);
    // 0x8002E060: lw          $t6, 0x90($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X90);
    // 0x8002E064: multu       $t7, $s1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E068: lw          $t7, 0x94($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X94);
    // 0x8002E06C: addiu       $a0, $t0, 0x1
    ctx->r4 = ADD32(ctx->r8, 0X1);
    // 0x8002E070: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8002E074: mflo        $t1
    ctx->r9 = lo;
    // 0x8002E078: addu        $t8, $s0, $t1
    ctx->r24 = ADD32(ctx->r16, ctx->r9);
    // 0x8002E07C: lh          $a1, 0x2($t8)
    ctx->r5 = MEM_H(ctx->r24, 0X2);
    // 0x8002E080: nop

    // 0x8002E084: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_8002E088:
    // 0x8002E088: lbu         $t9, 0x1($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X1);
    // 0x8002E08C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8002E090: multu       $t9, $s1
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E094: mflo        $t4
    ctx->r12 = lo;
    // 0x8002E098: addu        $t5, $s0, $t4
    ctx->r13 = ADD32(ctx->r16, ctx->r12);
    // 0x8002E09C: lh          $v0, 0x2($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X2);
    // 0x8002E0A0: nop

    // 0x8002E0A4: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002E0A8: beq         $at, $zero, L_8002E0BC
    if (ctx->r1 == 0) {
        // 0x8002E0AC: slt         $at, $a2, $v0
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002E0BC;
    }
    // 0x8002E0AC: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002E0B0: b           L_8002E0C8
    // 0x8002E0B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
        goto L_8002E0C8;
    // 0x8002E0B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8002E0B8: slt         $at, $a2, $v0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r2) ? 1 : 0;
L_8002E0BC:
    // 0x8002E0BC: beq         $at, $zero, L_8002E0C8
    if (ctx->r1 == 0) {
        // 0x8002E0C0: nop
    
            goto L_8002E0C8;
    }
    // 0x8002E0C0: nop

    // 0x8002E0C4: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_8002E0C8:
    // 0x8002E0C8: bne         $v1, $s2, L_8002E088
    if (ctx->r3 != ctx->r18) {
        // 0x8002E0CC: addiu       $a0, $a0, 0x1
        ctx->r4 = ADD32(ctx->r4, 0X1);
            goto L_8002E088;
    }
    // 0x8002E0CC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8002E0D0: slt         $at, $a2, $t6
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002E0D4: bne         $at, $zero, L_8002E1A0
    if (ctx->r1 != 0) {
        // 0x8002E0D8: slt         $at, $t7, $a1
        ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8002E1A0;
    }
    // 0x8002E0D8: slt         $at, $t7, $a1
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8002E0DC: bne         $at, $zero, L_8002E1A0
    if (ctx->r1 != 0) {
        // 0x8002E0E0: nop
    
            goto L_8002E1A0;
    }
    // 0x8002E0E0: nop

    // 0x8002E0E4: lbu         $t4, 0x2($t0)
    ctx->r12 = MEM_BU(ctx->r8, 0X2);
    // 0x8002E0E8: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8002E0EC: multu       $t4, $s1
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E0F0: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8002E0F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E0F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E0FC: lwc1        $f16, 0xC($s6)
    ctx->f16.u32l = MEM_W(ctx->r22, 0XC);
    // 0x8002E100: lbu         $t6, 0x3($t0)
    ctx->r14 = MEM_BU(ctx->r8, 0X3);
    // 0x8002E104: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8002E108: lwc1        $f4, 0x14($s6)
    ctx->f4.u32l = MEM_W(ctx->r22, 0X14);
    // 0x8002E10C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8002E110: mfc1        $a0, $f18
    ctx->r4 = (int32_t)ctx->f18.u32l;
    // 0x8002E114: sw          $t3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r11;
    // 0x8002E118: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8002E11C: mflo        $t5
    ctx->r13 = lo;
    // 0x8002E120: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8002E124: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8002E128: multu       $t6, $s1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r17)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002E12C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8002E130: addu        $a3, $t5, $s0
    ctx->r7 = ADD32(ctx->r13, ctx->r16);
    // 0x8002E134: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8002E138: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    // 0x8002E13C: mfc1        $a1, $f6
    ctx->r5 = (int32_t)ctx->f6.u32l;
    // 0x8002E140: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8002E144: addu        $a2, $t1, $s0
    ctx->r6 = ADD32(ctx->r9, ctx->r16);
    // 0x8002E148: mflo        $t7
    ctx->r15 = lo;
    // 0x8002E14C: addu        $t8, $t7, $s0
    ctx->r24 = ADD32(ctx->r15, ctx->r16);
    // 0x8002E150: jal         0x800704F0
    // 0x8002E154: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    tri2d_xz_contains_point(rdram, ctx);
        goto after_1;
    // 0x8002E154: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_1:
    // 0x8002E158: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8002E15C: lw          $t3, 0x88($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X88);
    // 0x8002E160: beq         $v0, $zero, L_8002E1A0
    if (ctx->r2 == 0) {
        // 0x8002E164: sll         $t9, $fp, 2
        ctx->r25 = S32(ctx->r30 << 2);
            goto L_8002E1A0;
    }
    // 0x8002E164: sll         $t9, $fp, 2
    ctx->r25 = S32(ctx->r30 << 2);
    // 0x8002E168: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002E16C: addu        $at, $at, $t9
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8002E170: lwc1        $f10, -0x377C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X377C);
    // 0x8002E174: lw          $v0, 0x54($s6)
    ctx->r2 = MEM_W(ctx->r22, 0X54);
    // 0x8002E178: sub.s       $f16, $f22, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f22.fl - ctx->f10.fl;
    // 0x8002E17C: lwc1        $f0, 0x0($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X0);
    // 0x8002E180: addiu       $s7, $zero, 0x1
    ctx->r23 = ADD32(0, 0X1);
    // 0x8002E184: sub.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x8002E188: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x8002E18C: mul.d       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f20.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f20.d);
    // 0x8002E190: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8002E194: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8002E198: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x8002E19C: swc1        $f16, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f16.u32l;
L_8002E1A0:
    // 0x8002E1A0: lw          $t4, 0xC($s5)
    ctx->r12 = MEM_W(ctx->r21, 0XC);
    // 0x8002E1A4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002E1A8: addu        $v0, $t4, $t2
    ctx->r2 = ADD32(ctx->r12, ctx->r10);
    // 0x8002E1AC: lh          $t5, 0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X10);
    // 0x8002E1B0: addiu       $s4, $s4, 0x2
    ctx->r20 = ADD32(ctx->r20, 0X2);
    // 0x8002E1B4: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8002E1B8: beq         $at, $zero, L_8002E1CC
    if (ctx->r1 == 0) {
        // 0x8002E1BC: lw          $t6, 0x78($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X78);
            goto L_8002E1CC;
    }
    // 0x8002E1BC: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x8002E1C0: beq         $s7, $zero, L_8002E024
    if (ctx->r23 == 0) {
        // 0x8002E1C4: nop
    
            goto L_8002E024;
    }
    // 0x8002E1C4: nop

L_8002E1C8:
    // 0x8002E1C8: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
L_8002E1CC:
    // 0x8002E1CC: addiu       $t2, $t2, 0xC
    ctx->r10 = ADD32(ctx->r10, 0XC);
    // 0x8002E1D0: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8002E1D4: sw          $t7, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r15;
    // 0x8002E1D8: lh          $t8, 0x20($s5)
    ctx->r24 = MEM_H(ctx->r21, 0X20);
    // 0x8002E1DC: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
    // 0x8002E1E0: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8002E1E4: beq         $at, $zero, L_8002E1F8
    if (ctx->r1 == 0) {
        // 0x8002E1E8: lw          $ra, 0x54($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X54);
            goto L_8002E1F8;
    }
    // 0x8002E1E8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x8002E1EC: beq         $s7, $zero, L_8002DFD8
    if (ctx->r23 == 0) {
        // 0x8002E1F0: nop
    
            goto L_8002DFD8;
    }
    // 0x8002E1F0: nop

L_8002E1F4:
    // 0x8002E1F4: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
L_8002E1F8:
    // 0x8002E1F8: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8002E1FC: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8002E200: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8002E204: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8002E208: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x8002E20C: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x8002E210: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x8002E214: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x8002E218: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x8002E21C: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x8002E220: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x8002E224: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x8002E228: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x8002E22C: jr          $ra
    // 0x8002E230: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8002E230: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void set_current_dialogue_background_colour(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C4FBC: blez        $a0, L_800C4FF8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800C4FC0: slti        $at, $a0, 0x8
        ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
            goto L_800C4FF8;
    }
    // 0x800C4FC0: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800C4FC4: beq         $at, $zero, L_800C4FF8
    if (ctx->r1 == 0) {
        // 0x800C4FC8: sll         $t6, $a0, 2
        ctx->r14 = S32(ctx->r4 << 2);
            goto L_800C4FF8;
    }
    // 0x800C4FC8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x800C4FCC: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C4FD0: lw          $t7, -0x5818($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5818);
    // 0x800C4FD4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x800C4FD8: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x800C4FDC: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C4FE0: sb          $a1, 0x10($v0)
    MEM_B(0X10, ctx->r2) = ctx->r5;
    // 0x800C4FE4: sb          $a2, 0x11($v0)
    MEM_B(0X11, ctx->r2) = ctx->r6;
    // 0x800C4FE8: sb          $a3, 0x12($v0)
    MEM_B(0X12, ctx->r2) = ctx->r7;
    // 0x800C4FEC: lw          $t8, 0x10($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X10);
    // 0x800C4FF0: nop

    // 0x800C4FF4: sb          $t8, 0x13($v0)
    MEM_B(0X13, ctx->r2) = ctx->r24;
L_800C4FF8:
    // 0x800C4FF8: jr          $ra
    // 0x800C4FFC: nop

    return;
    // 0x800C4FFC: nop

;}
RECOMP_FUNC void func_8000B38C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000B38C: addiu       $sp, $sp, -0xA0
    ctx->r29 = ADD32(ctx->r29, -0XA0);
    // 0x8000B390: lwc1        $f4, 0xB0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XB0);
    // 0x8000B394: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8000B398: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8000B39C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8000B3A0: mtc1        $a3, $f20
    ctx->f20.u32l = ctx->r7;
    // 0x8000B3A4: addiu       $s5, $sp, 0x64
    ctx->r21 = ADD32(ctx->r29, 0X64);
    // 0x8000B3A8: or          $s6, $a0, $zero
    ctx->r22 = ctx->r4 | 0;
    // 0x8000B3AC: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8000B3B0: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8000B3B4: sw          $a1, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r5;
    // 0x8000B3B8: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x8000B3BC: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000B3C0: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8000B3C4: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8000B3C8: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8000B3CC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8000B3D0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8000B3D4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8000B3D8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8000B3DC: swc1        $f6, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f6.u32l;
    // 0x8000B3E0: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000B3E4: jal         0x80070490
    // 0x8000B3E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    vec3f_rotate_py(rdram, ctx);
        goto after_0;
    // 0x8000B3E8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x8000B3EC: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000B3F0: lwc1        $f10, 0xC($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000B3F4: or          $s0, $s6, $zero
    ctx->r16 = ctx->r22 | 0;
    // 0x8000B3F8: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000B3FC: addiu       $s4, $zero, -0x1
    ctx->r20 = ADD32(0, -0X1);
    // 0x8000B400: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000B404: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8000B408: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000B40C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B410: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B414: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x8000B418: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000B41C: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8000B420: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8000B424: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000B428: sh          $t7, 0x0($s6)
    MEM_H(0X0, ctx->r22) = ctx->r15;
    // 0x8000B42C: lwc1        $f6, 0x10($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8000B430: lwc1        $f4, 0x68($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000B434: addiu       $s2, $s2, -0x3898
    ctx->r18 = ADD32(ctx->r18, -0X3898);
    // 0x8000B438: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000B43C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000B440: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000B444: nop

    // 0x8000B448: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000B44C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B450: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B454: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000B458: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000B45C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B460: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000B464: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000B468: sh          $t9, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r25;
    // 0x8000B46C: lwc1        $f18, 0x14($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8000B470: lwc1        $f16, 0x6C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000B474: sh          $s4, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r20;
    // 0x8000B478: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000B47C: sh          $s4, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r20;
    // 0x8000B480: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B484: nop

    // 0x8000B488: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000B48C: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000B490: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000B494: sh          $t7, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r15;
    // 0x8000B498: nop

L_8000B49C:
    // 0x8000B49C: lwc1        $f8, 0x0($s2)
    ctx->f8.u32l = MEM_W(ctx->r18, 0X0);
    // 0x8000B4A0: addiu       $s2, $s2, 0x8
    ctx->r18 = ADD32(ctx->r18, 0X8);
    // 0x8000B4A4: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x8000B4A8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8000B4AC: or          $a1, $s5, $zero
    ctx->r5 = ctx->r21 | 0;
    // 0x8000B4B0: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
    // 0x8000B4B4: lwc1        $f16, -0x4($s2)
    ctx->f16.u32l = MEM_W(ctx->r18, -0X4);
    // 0x8000B4B8: swc1        $f22, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f22.u32l;
    // 0x8000B4BC: mul.s       $f18, $f16, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x8000B4C0: jal         0x80070320
    // 0x8000B4C4: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x8000B4C4: swc1        $f18, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x8000B4C8: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8000B4CC: lwc1        $f6, 0xC($s3)
    ctx->f6.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8000B4D0: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8000B4D4: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000B4D8: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x8000B4DC: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8000B4E0: nop

    // 0x8000B4E4: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000B4E8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B4EC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B4F0: nop

    // 0x8000B4F4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000B4F8: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000B4FC: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000B500: sh          $t9, -0xA($s0)
    MEM_H(-0XA, ctx->r16) = ctx->r25;
    // 0x8000B504: lwc1        $f18, 0x10($s3)
    ctx->f18.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8000B508: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x8000B50C: nop

    // 0x8000B510: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x8000B514: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8000B518: nop

    // 0x8000B51C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8000B520: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B524: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B528: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8000B52C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000B530: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000B534: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8000B538: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8000B53C: sh          $t7, -0x8($s0)
    MEM_H(-0X8, ctx->r16) = ctx->r15;
    // 0x8000B540: lwc1        $f10, 0x14($s3)
    ctx->f10.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8000B544: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x8000B548: sh          $s4, -0x4($s0)
    MEM_H(-0X4, ctx->r16) = ctx->r20;
    // 0x8000B54C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x8000B550: sh          $s4, -0x2($s0)
    MEM_H(-0X2, ctx->r16) = ctx->r20;
    // 0x8000B554: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000B558: slti        $at, $s1, 0x8
    ctx->r1 = SIGNED(ctx->r17) < 0X8 ? 1 : 0;
    // 0x8000B55C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000B560: mfc1        $t9, $f18
    ctx->r25 = (int32_t)ctx->f18.u32l;
    // 0x8000B564: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8000B568: bne         $at, $zero, L_8000B49C
    if (ctx->r1 != 0) {
        // 0x8000B56C: sh          $t9, -0x6($s0)
        MEM_H(-0X6, ctx->r16) = ctx->r25;
            goto L_8000B49C;
    }
    // 0x8000B56C: sh          $t9, -0x6($s0)
    MEM_H(-0X6, ctx->r16) = ctx->r25;
    // 0x8000B570: lw          $v0, 0xB8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XB8);
    // 0x8000B574: lh          $s1, 0xB6($sp)
    ctx->r17 = MEM_H(ctx->r29, 0XB6);
    // 0x8000B578: lbu         $s6, 0x1($v0)
    ctx->r22 = MEM_BU(ctx->r2, 0X1);
    // 0x8000B57C: lbu         $s2, 0x0($v0)
    ctx->r18 = MEM_BU(ctx->r2, 0X0);
    // 0x8000B580: addiu       $s6, $s6, -0x1
    ctx->r22 = ADD32(ctx->r22, -0X1);
    // 0x8000B584: sll         $t7, $s6, 4
    ctx->r15 = S32(ctx->r22 << 4);
    // 0x8000B588: addiu       $s2, $s2, -0x1
    ctx->r18 = ADD32(ctx->r18, -0X1);
    // 0x8000B58C: sll         $t6, $s2, 4
    ctx->r14 = S32(ctx->r18 << 4);
    // 0x8000B590: or          $s2, $t6, $zero
    ctx->r18 = ctx->r14 | 0;
    // 0x8000B594: or          $s6, $t7, $zero
    ctx->r22 = ctx->r15 | 0;
    // 0x8000B598: sll         $s3, $t7, 16
    ctx->r19 = S32(ctx->r15 << 16);
    // 0x8000B59C: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x8000B5A0: addiu       $s5, $sp, 0xA0
    ctx->r21 = ADD32(ctx->r29, 0XA0);
    // 0x8000B5A4: lui         $s4, 0xFFFF
    ctx->r20 = S32(0XFFFF << 16);
L_8000B5A8:
    // 0x8000B5A8: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8000B5AC: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000B5B0: jal         0x80070830
    // 0x8000B5B4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    sins_s16(rdram, ctx);
        goto after_2;
    // 0x8000B5B4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_2:
    // 0x8000B5B8: multu       $v0, $s2
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r18)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000B5BC: sll         $a0, $s1, 16
    ctx->r4 = S32(ctx->r17 << 16);
    // 0x8000B5C0: sra         $t8, $a0, 16
    ctx->r24 = S32(SIGNED(ctx->r4) >> 16);
    // 0x8000B5C4: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x8000B5C8: mflo        $t9
    ctx->r25 = lo;
    // 0x8000B5CC: sra         $t6, $t9, 16
    ctx->r14 = S32(SIGNED(ctx->r25) >> 16);
    // 0x8000B5D0: addu        $t7, $t6, $s2
    ctx->r15 = ADD32(ctx->r14, ctx->r18);
    // 0x8000B5D4: jal         0x8007082C
    // 0x8000B5D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    coss_s16(rdram, ctx);
        goto after_3;
    // 0x8000B5D8: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
    after_3:
    // 0x8000B5DC: multu       $s6, $v0
    result = U64(U32(ctx->r22)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000B5E0: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8000B5E4: addiu       $s1, $s1, 0x2000
    ctx->r17 = ADD32(ctx->r17, 0X2000);
    // 0x8000B5E8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000B5EC: sltu        $at, $s0, $s5
    ctx->r1 = ctx->r16 < ctx->r21 ? 1 : 0;
    // 0x8000B5F0: mflo        $t6
    ctx->r14 = lo;
    // 0x8000B5F4: addu        $t7, $s3, $t6
    ctx->r15 = ADD32(ctx->r19, ctx->r14);
    // 0x8000B5F8: and         $t8, $t7, $s4
    ctx->r24 = ctx->r15 & ctx->r20;
    // 0x8000B5FC: sll         $t7, $s1, 16
    ctx->r15 = S32(ctx->r17 << 16);
    // 0x8000B600: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000B604: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8000B608: sw          $t6, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r14;
    // 0x8000B60C: bne         $at, $zero, L_8000B5A8
    if (ctx->r1 != 0) {
        // 0x8000B610: or          $s1, $t9, $zero
        ctx->r17 = ctx->r25 | 0;
            goto L_8000B5A8;
    }
    // 0x8000B610: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
    // 0x8000B614: sll         $t6, $s2, 16
    ctx->r14 = S32(ctx->r18 << 16);
    // 0x8000B618: andi        $t7, $s6, 0xFFFF
    ctx->r15 = ctx->r22 & 0XFFFF;
    // 0x8000B61C: lw          $v0, 0xA4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XA4);
    // 0x8000B620: sh          $t9, 0xB6($sp)
    MEM_H(0XB6, ctx->r29) = ctx->r25;
    // 0x8000B624: or          $t4, $t6, $t7
    ctx->r12 = ctx->r14 | ctx->r15;
    // 0x8000B628: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000B62C: addiu       $s0, $sp, 0x80
    ctx->r16 = ADD32(ctx->r29, 0X80);
    // 0x8000B630: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8000B634: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
L_8000B638:
    // 0x8000B638: addiu       $a1, $s1, 0x1
    ctx->r5 = ADD32(ctx->r17, 0X1);
    // 0x8000B63C: andi        $a2, $a1, 0x7
    ctx->r6 = ctx->r5 & 0X7;
    // 0x8000B640: addiu       $t8, $a2, 0x1
    ctx->r24 = ADD32(ctx->r6, 0X1);
    // 0x8000B644: sll         $t9, $a1, 8
    ctx->r25 = S32(ctx->r5 << 8);
    // 0x8000B648: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x8000B64C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8000B650: sw          $t4, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r12;
    // 0x8000B654: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8000B658: sll         $t9, $a2, 2
    ctx->r25 = S32(ctx->r6 << 2);
    // 0x8000B65C: addu        $t8, $a0, $t9
    ctx->r24 = ADD32(ctx->r4, ctx->r25);
    // 0x8000B660: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x8000B664: lw          $t6, 0x0($t8)
    ctx->r14 = MEM_W(ctx->r24, 0X0);
    // 0x8000B668: addiu       $a3, $s1, 0x2
    ctx->r7 = ADD32(ctx->r17, 0X2);
    // 0x8000B66C: andi        $t0, $a3, 0x7
    ctx->r8 = ctx->r7 & 0X7;
    // 0x8000B670: addiu       $t9, $t0, 0x1
    ctx->r25 = ADD32(ctx->r8, 0X1);
    // 0x8000B674: sll         $t7, $a3, 8
    ctx->r15 = S32(ctx->r7 << 8);
    // 0x8000B678: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8000B67C: sw          $t8, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r24;
    // 0x8000B680: sw          $t4, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r12;
    // 0x8000B684: sw          $t6, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r14;
    // 0x8000B688: lw          $t6, 0x4($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4);
    // 0x8000B68C: sll         $t7, $t0, 2
    ctx->r15 = S32(ctx->r8 << 2);
    // 0x8000B690: addu        $t9, $a0, $t7
    ctx->r25 = ADD32(ctx->r4, ctx->r15);
    // 0x8000B694: sw          $t6, 0x18($v0)
    MEM_W(0X18, ctx->r2) = ctx->r14;
    // 0x8000B698: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8000B69C: addiu       $t1, $s1, 0x3
    ctx->r9 = ADD32(ctx->r17, 0X3);
    // 0x8000B6A0: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x8000B6A4: addiu       $t7, $t2, 0x1
    ctx->r15 = ADD32(ctx->r10, 0X1);
    // 0x8000B6A8: sll         $t6, $t1, 8
    ctx->r14 = S32(ctx->r9 << 8);
    // 0x8000B6AC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x8000B6B0: sw          $t9, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->r25;
    // 0x8000B6B4: sw          $t4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->r12;
    // 0x8000B6B8: sw          $t8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->r24;
    // 0x8000B6BC: lw          $t8, 0x8($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X8);
    // 0x8000B6C0: sll         $t6, $t2, 2
    ctx->r14 = S32(ctx->r10 << 2);
    // 0x8000B6C4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8000B6C8: sw          $t8, 0x28($v0)
    MEM_W(0X28, ctx->r2) = ctx->r24;
    // 0x8000B6CC: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8000B6D0: addiu       $v1, $s1, 0x4
    ctx->r3 = ADD32(ctx->r17, 0X4);
    // 0x8000B6D4: andi        $t3, $v1, 0x7
    ctx->r11 = ctx->r3 & 0X7;
    // 0x8000B6D8: addiu       $t6, $t3, 0x1
    ctx->r14 = ADD32(ctx->r11, 0X1);
    // 0x8000B6DC: sll         $t8, $v1, 8
    ctx->r24 = S32(ctx->r3 << 8);
    // 0x8000B6E0: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8000B6E4: sw          $t7, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r15;
    // 0x8000B6E8: sw          $t4, 0x34($v0)
    MEM_W(0X34, ctx->r2) = ctx->r12;
    // 0x8000B6EC: sw          $t9, 0x2C($v0)
    MEM_W(0X2C, ctx->r2) = ctx->r25;
    // 0x8000B6F0: lw          $t9, 0xC($s0)
    ctx->r25 = MEM_W(ctx->r16, 0XC);
    // 0x8000B6F4: sll         $t8, $t3, 2
    ctx->r24 = S32(ctx->r11 << 2);
    // 0x8000B6F8: addu        $t6, $a0, $t8
    ctx->r14 = ADD32(ctx->r4, ctx->r24);
    // 0x8000B6FC: sw          $t9, 0x38($v0)
    MEM_W(0X38, ctx->r2) = ctx->r25;
    // 0x8000B700: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8000B704: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8000B708: addiu       $v0, $v0, 0x40
    ctx->r2 = ADD32(ctx->r2, 0X40);
    // 0x8000B70C: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x8000B710: bne         $v1, $t5, L_8000B638
    if (ctx->r3 != ctx->r13) {
        // 0x8000B714: sw          $t7, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->r15;
            goto L_8000B638;
    }
    // 0x8000B714: sw          $t7, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->r15;
    // 0x8000B718: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8000B71C: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8000B720: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000B724: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8000B728: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000B72C: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8000B730: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8000B734: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8000B738: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8000B73C: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8000B740: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8000B744: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8000B748: jr          $ra
    // 0x8000B74C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
    return;
    // 0x8000B74C: addiu       $sp, $sp, 0xA0
    ctx->r29 = ADD32(ctx->r29, 0XA0);
;}
RECOMP_FUNC void _freePVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006571C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065720: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065724: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80065728: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006572C: jal         0x800C8760
    // 0x80065730: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x80065730: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80065734: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80065738: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x8006573C: jal         0x800C8790
    // 0x80065740: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    alLink(rdram, ctx);
        goto after_1;
    // 0x80065740: addiu       $a1, $a1, 0x14
    ctx->r5 = ADD32(ctx->r5, 0X14);
    after_1:
    // 0x80065744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80065748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006574C: jr          $ra
    // 0x80065750: nop

    return;
    // 0x80065750: nop

;}
RECOMP_FUNC void sndp_set_active_sound_limit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000318C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80003190: lw          $v0, -0x3944($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X3944);
    // 0x80003194: nop

    // 0x80003198: lw          $v1, 0x44($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X44);
    // 0x8000319C: nop

    // 0x800031A0: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800031A4: bne         $at, $zero, L_800031B4
    if (ctx->r1 != 0) {
        // 0x800031A8: nop
    
            goto L_800031B4;
    }
    // 0x800031A8: nop

    // 0x800031AC: jr          $ra
    // 0x800031B0: sw          $a0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r4;
    return;
    // 0x800031B0: sw          $a0, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r4;
L_800031B4:
    // 0x800031B4: sw          $v1, 0x48($v0)
    MEM_W(0X48, ctx->r2) = ctx->r3;
    // 0x800031B8: jr          $ra
    // 0x800031BC: nop

    return;
    // 0x800031BC: nop

;}
RECOMP_FUNC void get_checkpoint_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BA64: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BA68: lw          $v0, -0x5130($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5130);
    // 0x8001BA6C: jr          $ra
    // 0x8001BA70: nop

    return;
    // 0x8001BA70: nop

;}
RECOMP_FUNC void homing_rocket_get_next_direction(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001955C: addiu       $sp, $sp, -0xC0
    ctx->r29 = ADD32(ctx->r29, -0XC0);
    // 0x80019560: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80019564: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80019568: lw          $s6, -0x5130($s6)
    ctx->r22 = MEM_W(ctx->r22, -0X5130);
    // 0x8001956C: sw          $a2, 0xC8($sp)
    MEM_W(0XC8, ctx->r29) = ctx->r6;
    // 0x80019570: andi        $t6, $a2, 0xFF
    ctx->r14 = ctx->r6 & 0XFF;
    // 0x80019574: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x80019578: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8001957C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x80019580: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80019584: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80019588: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8001958C: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x80019590: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80019594: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80019598: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x8001959C: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800195A0: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800195A4: bne         $s6, $zero, L_800195B4
    if (ctx->r22 != 0) {
        // 0x800195A8: sw          $a0, 0xC0($sp)
        MEM_W(0XC0, ctx->r29) = ctx->r4;
            goto L_800195B4;
    }
    // 0x800195A8: sw          $a0, 0xC0($sp)
    MEM_W(0XC0, ctx->r29) = ctx->r4;
    // 0x800195AC: b           L_800197D0
    // 0x800195B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800197D0;
    // 0x800195B0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800195B4:
    // 0x800195B4: addiu       $v0, $a1, -0x2
    ctx->r2 = ADD32(ctx->r5, -0X2);
    // 0x800195B8: bgez        $v0, L_800195C4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800195BC: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_800195C4;
    }
    // 0x800195BC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800195C0: addu        $s1, $v0, $s6
    ctx->r17 = ADD32(ctx->r2, ctx->r22);
L_800195C4:
    // 0x800195C4: mtc1        $a3, $f18
    ctx->f18.u32l = ctx->r7;
    // 0x800195C8: lw          $t7, 0xD0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD0);
    // 0x800195CC: cvt.s.w     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    ctx->f20.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800195D0: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800195D4: or          $s4, $a2, $zero
    ctx->r20 = ctx->r6 | 0;
    // 0x800195D8: cvt.s.w     $f22, $f18
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    ctx->f22.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800195DC: addiu       $s2, $sp, 0xA4
    ctx->r18 = ADD32(ctx->r29, 0XA4);
    // 0x800195E0: addiu       $s3, $sp, 0x94
    ctx->r19 = ADD32(ctx->r29, 0X94);
    // 0x800195E4: addiu       $s0, $sp, 0x84
    ctx->r16 = ADD32(ctx->r29, 0X84);
    // 0x800195E8: addiu       $s5, $sp, 0x94
    ctx->r21 = ADD32(ctx->r29, 0X94);
L_800195EC:
    // 0x800195EC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800195F0: jal         0x8001BA1C
    // 0x800195F4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_0;
    // 0x800195F4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_0:
    // 0x800195F8: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x800195FC: lwc1        $f10, 0x8($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X8);
    // 0x80019600: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80019604: mul.s       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80019608: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001960C: addiu       $s2, $s2, 0x4
    ctx->r18 = ADD32(ctx->r18, 0X4);
    // 0x80019610: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x80019614: mul.s       $f4, $f18, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f18.fl, ctx->f20.fl);
    // 0x80019618: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8001961C: swc1        $f8, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->f8.u32l;
    // 0x80019620: lwc1        $f18, 0x1C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x80019624: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80019628: mul.s       $f6, $f18, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f22.fl);
    // 0x8001962C: add.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f6.fl;
    // 0x80019630: swc1        $f4, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->f4.u32l;
    // 0x80019634: lwc1        $f18, 0x0($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80019638: lwc1        $f8, 0x1C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8001963C: neg.s       $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = -ctx->f18.fl;
    // 0x80019640: mul.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x80019644: lwc1        $f18, 0x18($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X18);
    // 0x80019648: mul.s       $f4, $f6, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x8001964C: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80019650: bne         $s1, $s6, L_8001965C
    if (ctx->r17 != ctx->r22) {
        // 0x80019654: swc1        $f8, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->f8.u32l;
            goto L_8001965C;
    }
    // 0x80019654: swc1        $f8, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->f8.u32l;
    // 0x80019658: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001965C:
    // 0x8001965C: bne         $s0, $s5, L_800195EC
    if (ctx->r16 != ctx->r21) {
        // 0x80019660: addiu       $s3, $s3, 0x4
        ctx->r19 = ADD32(ctx->r19, 0X4);
            goto L_800195EC;
    }
    // 0x80019660: addiu       $s3, $s3, 0x4
    ctx->r19 = ADD32(ctx->r19, 0X4);
    // 0x80019664: lwc1        $f10, 0xD4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XD4);
    // 0x80019668: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x8001966C: mtc1        $at, $f3
    ctx->f_odd[(3 - 1) * 2] = ctx->r1;
    // 0x80019670: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80019674: cvt.d.s     $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f6.d = CVT_D_S(ctx->f10.fl);
    // 0x80019678: sub.d       $f18, $f2, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f2.d - ctx->f6.d;
    // 0x8001967C: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80019680: cvt.s.d     $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f20.fl = CVT_S_D(ctx->f18.d);
    // 0x80019684: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80019688: c.lt.s      $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f20.fl < ctx->f12.fl;
    // 0x8001968C: addiu       $a0, $sp, 0xA4
    ctx->r4 = ADD32(ctx->r29, 0XA4);
    // 0x80019690: bc1f        L_8001969C
    if (!c1cs) {
        // 0x80019694: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8001969C;
    }
    // 0x80019694: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80019698: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
L_8001969C:
    // 0x8001969C: cvt.d.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); 
    ctx->f4.d = CVT_D_S(ctx->f20.fl);
    // 0x800196A0: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x800196A4: nop

    // 0x800196A8: bc1f        L_800196B8
    if (!c1cs) {
        // 0x800196AC: nop
    
            goto L_800196B8;
    }
    // 0x800196AC: nop

    // 0x800196B0: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800196B4: nop

L_800196B8:
    // 0x800196B8: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800196BC: jal         0x8002263C
    // 0x800196C0: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    cubic_spline_interpolation(rdram, ctx);
        goto after_1;
    // 0x800196C0: addiu       $a3, $sp, 0x70
    ctx->r7 = ADD32(ctx->r29, 0X70);
    after_1:
    // 0x800196C4: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800196C8: swc1        $f0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f0.u32l;
    // 0x800196CC: addiu       $a0, $sp, 0x94
    ctx->r4 = ADD32(ctx->r29, 0X94);
    // 0x800196D0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800196D4: jal         0x8002263C
    // 0x800196D8: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    cubic_spline_interpolation(rdram, ctx);
        goto after_2;
    // 0x800196D8: addiu       $a3, $sp, 0x6C
    ctx->r7 = ADD32(ctx->r29, 0X6C);
    after_2:
    // 0x800196DC: mfc1        $a2, $f20
    ctx->r6 = (int32_t)ctx->f20.u32l;
    // 0x800196E0: mov.s       $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    ctx->f22.fl = ctx->f0.fl;
    // 0x800196E4: addiu       $a0, $sp, 0x84
    ctx->r4 = ADD32(ctx->r29, 0X84);
    // 0x800196E8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800196EC: jal         0x8002263C
    // 0x800196F0: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    cubic_spline_interpolation(rdram, ctx);
        goto after_3;
    // 0x800196F0: addiu       $a3, $sp, 0x68
    ctx->r7 = ADD32(ctx->r29, 0X68);
    after_3:
    // 0x800196F4: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800196F8: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800196FC: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80019700: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80019704: swc1        $f0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f0.u32l;
    // 0x80019708: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001970C: nop

    // 0x80019710: mul.s       $f18, $f16, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x80019714: add.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80019718: jal         0x800C9AD0
    // 0x8001971C: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_4;
    // 0x8001971C: add.s       $f12, $f6, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f18.fl;
    after_4:
    // 0x80019720: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80019724: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80019728: c.eq.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl == ctx->f4.fl;
    // 0x8001972C: nop

    // 0x80019730: bc1t        L_80019778
    if (c1cs) {
        // 0x80019734: nop
    
            goto L_80019778;
    }
    // 0x80019734: nop

    // 0x80019738: lwc1        $f9, 0x5630($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5630);
    // 0x8001973C: lwc1        $f8, 0x5634($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5634);
    // 0x80019740: cvt.d.s     $f10, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f10.d = CVT_D_S(ctx->f0.fl);
    // 0x80019744: nop

    // 0x80019748: div.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x8001974C: lwc1        $f2, 0x70($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80019750: lwc1        $f14, 0x6C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80019754: lwc1        $f16, 0x68($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80019758: cvt.s.d     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f20.fl = CVT_S_D(ctx->f6.d);
    // 0x8001975C: mul.s       $f2, $f2, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f20.fl);
    // 0x80019760: nop

    // 0x80019764: mul.s       $f14, $f14, $f20
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80019768: swc1        $f2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f2.u32l;
    // 0x8001976C: mul.s       $f16, $f16, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f16.fl, ctx->f20.fl);
    // 0x80019770: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x80019774: swc1        $f16, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f16.u32l;
L_80019778:
    // 0x80019778: lwc1        $f18, 0x80($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X80);
    // 0x8001977C: lwc1        $f4, 0x70($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80019780: lw          $t8, 0xC0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC0);
    // 0x80019784: add.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x80019788: lwc1        $f10, 0xC($t8)
    ctx->f10.u32l = MEM_W(ctx->r24, 0XC);
    // 0x8001978C: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x80019790: sub.s       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80019794: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80019798: swc1        $f6, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->f6.u32l;
    // 0x8001979C: lwc1        $f18, 0x6C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800197A0: lwc1        $f8, 0x10($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X10);
    // 0x800197A4: add.s       $f4, $f22, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f22.fl + ctx->f18.fl;
    // 0x800197A8: lw          $t0, 0xDC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XDC);
    // 0x800197AC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800197B0: swc1        $f10, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f10.u32l;
    // 0x800197B4: lwc1        $f18, 0x68($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800197B8: lwc1        $f6, 0x78($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800197BC: lwc1        $f8, 0x14($t8)
    ctx->f8.u32l = MEM_W(ctx->r24, 0X14);
    // 0x800197C0: add.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800197C4: lw          $t1, 0xE0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XE0);
    // 0x800197C8: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800197CC: swc1        $f10, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->f10.u32l;
L_800197D0:
    // 0x800197D0: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800197D4: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800197D8: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800197DC: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800197E0: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800197E4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x800197E8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x800197EC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x800197F0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x800197F4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x800197F8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x800197FC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80019800: jr          $ra
    // 0x80019804: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
    return;
    // 0x80019804: addiu       $sp, $sp, 0xC0
    ctx->r29 = ADD32(ctx->r29, 0XC0);
;}
RECOMP_FUNC void get_npc_pos_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003ACAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8003ACB0: lwc1        $f0, -0x2B30($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X2B30);
    // 0x8003ACB4: jr          $ra
    // 0x8003ACB8: nop

    return;
    // 0x8003ACB8: nop

;}
RECOMP_FUNC void obj_init_flycoin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003D2AC: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003D2B0: jr          $ra
    // 0x8003D2B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003D2B4: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void load_level_for_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 8U, dkr_legacy_fields, 0U); }
    // 0x8006E2E8: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006E2EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006E2F0: lb          $t6, 0x3514($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X3514);
    // 0x8006E2F4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006E2F8: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006E2FC: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006E300: bne         $t6, $zero, L_8006E36C
    if (ctx->r14 != 0) {
        // 0x8006E304: sw          $a2, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r6;
            goto L_8006E36C;
    }
    // 0x8006E304: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006E308: jal         0x8006DBE4
    // 0x8006E30C: nop

    unload_level_menu(rdram, ctx);
        goto after_0;
    // 0x8006E30C: nop

    after_0:
    // 0x8006E310: jal         0x800C73E0
    // 0x8006E314: nop

    bgload_active(rdram, ctx);
        goto after_1;
    // 0x8006E314: nop

    after_1:
    // 0x8006E318: bne         $v0, $zero, L_8006E36C
    if (ctx->r2 != 0) {
        // 0x8006E31C: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8006E36C;
    }
    // 0x8006E31C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006E320: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006E324: lw          $t7, 0x34E8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X34E8);
    // 0x8006E328: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8006E32C: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8006E330: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x8006E334: lw          $t9, 0x11F0($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X11F0);
    // 0x8006E338: addiu       $v1, $v1, 0x11F8
    ctx->r3 = ADD32(ctx->r3, 0X11F8);
    // 0x8006E33C: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8006E340: addiu       $t0, $t9, 0x8
    ctx->r8 = ADD32(ctx->r25, 0X8);
    // 0x8006E344: sw          $t0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r8;
    // 0x8006E348: lui         $t1, 0xE900
    ctx->r9 = S32(0XE900 << 16);
    // 0x8006E34C: sw          $t1, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r9;
    // 0x8006E350: sw          $zero, 0x4($t9)
    MEM_W(0X4, ctx->r25) = 0;
    // 0x8006E354: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8006E358: lui         $t3, 0xB800
    ctx->r11 = S32(0XB800 << 16);
    // 0x8006E35C: addiu       $t2, $v0, 0x8
    ctx->r10 = ADD32(ctx->r2, 0X8);
    // 0x8006E360: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8006E364: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8006E368: sw          $t3, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r11;
L_8006E36C:
    // 0x8006E36C: lw          $t4, 0x20($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X20);
    // 0x8006E370: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006E374: beq         $t4, $at, L_8006E3A4
    if (ctx->r12 == ctx->r1) {
        // 0x8006E378: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_8006E3A4;
    }
    // 0x8006E378: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006E37C: lw          $t5, 0x28($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X28);
    // 0x8006E380: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006E384: or          $a0, $t4, $zero
    ctx->r4 = ctx->r12 | 0;
    // 0x8006E388: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006E38C: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8006E390: jal         0x8006DB3C
    // 0x8006E394: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    load_level_menu(rdram, ctx);
        goto after_2;
    // 0x8006E394: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    after_2:
    // 0x8006E398: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E39C: b           L_8006E3AC
    // 0x8006E3A0: sb          $zero, 0x3514($at)
    MEM_B(0X3514, ctx->r1) = 0;
        goto L_8006E3AC;
    // 0x8006E3A0: sb          $zero, 0x3514($at)
    MEM_B(0X3514, ctx->r1) = 0;
L_8006E3A4:
    // 0x8006E3A4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006E3A8: sb          $t6, 0x3514($at)
    MEM_B(0X3514, ctx->r1) = ctx->r14;
L_8006E3AC:
    // 0x8006E3AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E3B0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006E3B4: jr          $ra
    // 0x8006E3B8: nop

    return;
    // 0x8006E3B8: nop

;}
RECOMP_FUNC void waves_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_presentation_wave_begin(uint8_t*, recomp_context*); dkr_presentation_wave_begin(rdram, ctx);
    // 0x800BA8E4: addiu       $sp, $sp, -0x120
    ctx->r29 = ADD32(ctx->r29, -0X120);
    // 0x800BA8E8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800BA8EC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800BA8F0: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x800BA8F4: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x800BA8F8: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x800BA8FC: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x800BA900: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x800BA904: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x800BA908: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x800BA90C: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x800BA910: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x800BA914: swc1        $f25, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BA918: swc1        $f24, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f24.u32l;
    // 0x800BA91C: swc1        $f23, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BA920: swc1        $f22, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f22.u32l;
    // 0x800BA924: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BA928: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x800BA92C: sw          $a0, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r4;
    // 0x800BA930: bne         $a2, $at, L_800BA94C
    if (ctx->r6 != ctx->r1) {
        // 0x800BA934: sw          $a1, 0x124($sp)
        MEM_W(0X124, ctx->r29) = ctx->r5;
            goto L_800BA94C;
    }
    // 0x800BA934: sw          $a1, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r5;
    // 0x800BA938: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BA93C: lw          $t6, -0x5F88($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5F88);
    // 0x800BA940: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800BA944: beq         $t6, $at, L_800BA954
    if (ctx->r14 == ctx->r1) {
        // 0x800BA948: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_800BA954;
    }
    // 0x800BA948: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
L_800BA94C:
    // 0x800BA94C: b           L_800BA958
    // 0x800BA950: sw          $zero, 0x128($sp)
    MEM_W(0X128, ctx->r29) = 0;
        goto L_800BA958;
    // 0x800BA950: sw          $zero, 0x128($sp)
    MEM_W(0X128, ctx->r29) = 0;
L_800BA954:
    // 0x800BA954: sw          $t7, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r15;
L_800BA958:
    // 0x800BA958: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800BA95C: lw          $t8, 0x30DC($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X30DC);
    // 0x800BA960: lui         $s1, 0x8013
    ctx->r17 = S32(0X8013 << 16);
    // 0x800BA964: blez        $t8, L_800BB2A4
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800BA968: addiu       $s1, $s1, -0x6040
        ctx->r17 = ADD32(ctx->r17, -0X6040);
            goto L_800BB2A4;
    }
    // 0x800BA968: addiu       $s1, $s1, -0x6040
    ctx->r17 = ADD32(ctx->r17, -0X6040);
    // 0x800BA96C: lw          $t9, 0x120($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X120);
    // 0x800BA970: lw          $t7, 0x124($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X124);
    // 0x800BA974: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800BA978: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BA97C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BA980: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x800BA984: sw          $zero, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = 0;
    // 0x800BA988: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BA98C: jal         0x8007B3D0
    // 0x800BA990: sw          $t8, -0x603C($at)
    MEM_W(-0X603C, ctx->r1) = ctx->r24;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800BA990: sw          $t8, -0x603C($at)
    MEM_W(-0X603C, ctx->r1) = ctx->r24;
    after_0:
    // 0x800BA994: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BA998: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BA99C: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BA9A0: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BA9A4: lui         $t6, 0xB700
    ctx->r14 = S32(0XB700 << 16);
    // 0x800BA9A8: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800BA9AC: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
    // 0x800BA9B0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BA9B4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BA9B8: lw          $t8, 0x4C($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X4C);
    // 0x800BA9BC: lui         $t9, 0x1
    ctx->r25 = S32(0X1 << 16);
    // 0x800BA9C0: beq         $t8, $zero, L_800BAB80
    if (ctx->r24 == 0) {
        // 0x800BA9C4: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800BAB80;
    }
    // 0x800BA9C4: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BA9C8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BA9CC: lui         $t6, 0xB600
    ctx->r14 = S32(0XB600 << 16);
    // 0x800BA9D0: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BA9D4: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BA9D8: lui         $t7, 0x1
    ctx->r15 = S32(0X1 << 16);
    // 0x800BA9DC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BA9E0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BA9E4: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BA9E8: lw          $a1, -0x5F64($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5F64);
    // 0x800BA9EC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800BA9F0: lw          $a0, 0x30D0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X30D0);
    // 0x800BA9F4: sll         $t8, $a1, 8
    ctx->r24 = S32(ctx->r5 << 8);
    // 0x800BA9F8: jal         0x8007B46C
    // 0x800BA9FC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_1;
    // 0x800BA9FC: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_1:
    // 0x800BAA00: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BAA04: lw          $t9, -0x5F84($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5F84);
    // 0x800BAA08: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BAA0C: lbu         $a1, 0x7($t9)
    ctx->r5 = MEM_BU(ctx->r25, 0X7);
    // 0x800BAA10: lw          $a0, -0x5F80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5F80);
    // 0x800BAA14: sll         $t6, $a1, 14
    ctx->r14 = S32(ctx->r5 << 14);
    // 0x800BAA18: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x800BAA1C: jal         0x8007B46C
    // 0x800BAA20: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_2;
    // 0x800BAA20: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_2:
    // 0x800BAA24: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x800BAA28: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800BAA2C: jal         0x800BA4B8
    // 0x800BAA30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    wave_load_material(rdram, ctx);
        goto after_3;
    // 0x800BAA30: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_3:
    // 0x800BAA34: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800BAA38: jal         0x800BA4B8
    // 0x800BAA3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    wave_load_material(rdram, ctx);
        goto after_4;
    // 0x800BAA3C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x800BAA40: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAA44: lui         $t8, 0xFC22
    ctx->r24 = S32(0XFC22 << 16);
    // 0x800BAA48: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BAA4C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BAA50: lui         $t9, 0x1010
    ctx->r25 = S32(0X1010 << 16);
    // 0x800BAA54: ori         $t9, $t9, 0x923F
    ctx->r25 = ctx->r25 | 0X923F;
    // 0x800BAA58: ori         $t8, $t8, 0x66AC
    ctx->r24 = ctx->r24 | 0X66AC;
    // 0x800BAA5C: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800BAA60: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BAA64: lbu         $t6, 0x2($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0X2);
    // 0x800BAA68: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAA6C: andi        $t7, $t6, 0xF
    ctx->r15 = ctx->r14 & 0XF;
    // 0x800BAA70: bne         $t7, $zero, L_800BAAB4
    if (ctx->r15 != 0) {
        // 0x800BAA74: addiu       $ra, $ra, -0x6038
        ctx->r31 = ADD32(ctx->r31, -0X6038);
            goto L_800BAAB4;
    }
    // 0x800BAA74: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
    // 0x800BAA78: jal         0x80066210
    // 0x800BAA7C: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_5;
    // 0x800BAA7C: nop

    after_5:
    // 0x800BAA80: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAA84: bgtz        $v0, L_800BAAB4
    if (SIGNED(ctx->r2) > 0) {
        // 0x800BAA88: addiu       $ra, $ra, -0x6038
        ctx->r31 = ADD32(ctx->r31, -0X6038);
            goto L_800BAAB4;
    }
    // 0x800BAA88: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
    // 0x800BAA8C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAA90: lui         $t9, 0xEF18
    ctx->r25 = S32(0XEF18 << 16);
    // 0x800BAA94: lui         $t6, 0x10
    ctx->r14 = S32(0X10 << 16);
    // 0x800BAA98: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BAA9C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BAAA0: ori         $t6, $t6, 0x45D8
    ctx->r14 = ctx->r14 | 0X45D8;
    // 0x800BAAA4: ori         $t9, $t9, 0x2C0F
    ctx->r25 = ctx->r25 | 0X2C0F;
    // 0x800BAAA8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BAAAC: b           L_800BAAD8
    // 0x800BAAB0: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
        goto L_800BAAD8;
    // 0x800BAAB0: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
L_800BAAB4:
    // 0x800BAAB4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAAB8: lui         $t8, 0xEF18
    ctx->r24 = S32(0XEF18 << 16);
    // 0x800BAABC: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BAAC0: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BAAC4: lui         $t9, 0x11
    ctx->r25 = S32(0X11 << 16);
    // 0x800BAAC8: ori         $t9, $t9, 0x2078
    ctx->r25 = ctx->r25 | 0X2078;
    // 0x800BAACC: ori         $t8, $t8, 0x2C0F
    ctx->r24 = ctx->r24 | 0X2C0F;
    // 0x800BAAD0: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800BAAD4: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
L_800BAAD8:
    // 0x800BAAD8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAADC: addiu       $v1, $zero, -0x100
    ctx->r3 = ADD32(0, -0X100);
    // 0x800BAAE0: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800BAAE4: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BAAE8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BAAEC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800BAAF0: addiu       $t1, $t1, 0x3180
    ctx->r9 = ADD32(ctx->r9, 0X3180);
    // 0x800BAAF4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BAAF8: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x800BAAFC: lw          $t8, 0x0($t1)
    ctx->r24 = MEM_W(ctx->r9, 0X0);
    // 0x800BAB00: nop

    // 0x800BAB04: beq         $t8, $zero, L_800BAB60
    if (ctx->r24 == 0) {
        // 0x800BAB08: nop
    
            goto L_800BAB60;
    }
    // 0x800BAB08: nop

    // 0x800BAB0C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAB10: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800BAB14: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BAB18: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BAB1C: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BAB20: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800BAB24: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x800BAB28: lbu         $t8, 0x10($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X10);
    // 0x800BAB2C: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x800BAB30: sll         $t9, $t8, 24
    ctx->r25 = S32(ctx->r24 << 24);
    // 0x800BAB34: sll         $t8, $t7, 16
    ctx->r24 = S32(ctx->r15 << 16);
    // 0x800BAB38: or          $t6, $t9, $t8
    ctx->r14 = ctx->r25 | ctx->r24;
    // 0x800BAB3C: lbu         $t9, 0x12($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X12);
    // 0x800BAB40: nop

    // 0x800BAB44: sll         $t8, $t9, 8
    ctx->r24 = S32(ctx->r25 << 8);
    // 0x800BAB48: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x800BAB4C: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x800BAB50: nop

    // 0x800BAB54: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x800BAB58: b           L_800BACE0
    // 0x800BAB5C: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
        goto L_800BACE0;
    // 0x800BAB5C: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
L_800BAB60:
    // 0x800BAB60: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAB64: lui         $t7, 0xFB00
    ctx->r15 = S32(0XFB00 << 16);
    // 0x800BAB68: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BAB6C: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BAB70: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
    // 0x800BAB74: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BAB78: b           L_800BACE0
    // 0x800BAB7C: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
        goto L_800BACE0;
    // 0x800BAB7C: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
L_800BAB80:
    // 0x800BAB80: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAB84: lui         $t8, 0xB700
    ctx->r24 = S32(0XB700 << 16);
    // 0x800BAB88: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800BAB8C: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BAB90: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BAB94: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
    // 0x800BAB98: lw          $t7, -0x5F84($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5F84);
    // 0x800BAB9C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BABA0: lbu         $a1, 0x7($t7)
    ctx->r5 = MEM_BU(ctx->r15, 0X7);
    // 0x800BABA4: lw          $a0, -0x5F80($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X5F80);
    // 0x800BABA8: sll         $t6, $a1, 14
    ctx->r14 = S32(ctx->r5 << 14);
    // 0x800BABAC: jal         0x8007B46C
    // 0x800BABB0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    set_animated_texture_header(rdram, ctx);
        goto after_6;
    // 0x800BABB0: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    after_6:
    // 0x800BABB4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BABB8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x800BABBC: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BABC0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BABC4: lh          $a0, 0xA($v0)
    ctx->r4 = MEM_H(ctx->r2, 0XA);
    // 0x800BABC8: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
    // 0x800BABCC: andi        $t9, $a0, 0xFF
    ctx->r25 = ctx->r4 & 0XFF;
    // 0x800BABD0: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800BABD4: sll         $t8, $a0, 3
    ctx->r24 = S32(ctx->r4 << 3);
    // 0x800BABD8: andi        $t9, $t8, 0xFFFF
    ctx->r25 = ctx->r24 & 0XFFFF;
    // 0x800BABDC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x800BABE0: or          $t7, $t6, $t9
    ctx->r15 = ctx->r14 | ctx->r25;
    // 0x800BABE4: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BABE8: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x800BABEC: lui         $t7, 0xFC56
    ctx->r15 = S32(0XFC56 << 16);
    // 0x800BABF0: addu        $t6, $t8, $s2
    ctx->r14 = ADD32(ctx->r24, ctx->r18);
    // 0x800BABF4: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800BABF8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BABFC: lui         $t8, 0x1FFC
    ctx->r24 = S32(0X1FFC << 16);
    // 0x800BAC00: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BAC04: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BAC08: ori         $t8, $t8, 0xF7F8
    ctx->r24 = ctx->r24 | 0XF7F8;
    // 0x800BAC0C: ori         $t7, $t7, 0x7E04
    ctx->r15 = ctx->r15 | 0X7E04;
    // 0x800BAC10: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BAC14: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800BAC18: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAC1C: lui         $t7, 0xC811
    ctx->r15 = S32(0XC811 << 16);
    // 0x800BAC20: addiu       $t6, $a3, 0x8
    ctx->r14 = ADD32(ctx->r7, 0X8);
    // 0x800BAC24: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x800BAC28: lui         $t9, 0xEF18
    ctx->r25 = S32(0XEF18 << 16);
    // 0x800BAC2C: ori         $t9, $t9, 0x2C0F
    ctx->r25 = ctx->r25 | 0X2C0F;
    // 0x800BAC30: ori         $t7, $t7, 0x2078
    ctx->r15 = ctx->r15 | 0X2078;
    // 0x800BAC34: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BAC38: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BAC3C: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAC40: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BAC44: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BAC48: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BAC4C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800BAC50: lui         $t6, 0xFA00
    ctx->r14 = S32(0XFA00 << 16);
    // 0x800BAC54: addiu       $t1, $t1, 0x3180
    ctx->r9 = ADD32(ctx->r9, 0X3180);
    // 0x800BAC58: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BAC5C: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BAC60: lw          $t7, 0x0($t1)
    ctx->r15 = MEM_W(ctx->r9, 0X0);
    // 0x800BAC64: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAC68: beq         $t7, $zero, L_800BACC4
    if (ctx->r15 == 0) {
        // 0x800BAC6C: addiu       $ra, $ra, -0x6038
        ctx->r31 = ADD32(ctx->r31, -0X6038);
            goto L_800BACC4;
    }
    // 0x800BAC6C: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
    // 0x800BAC70: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAC74: lui         $t6, 0xFB00
    ctx->r14 = S32(0XFB00 << 16);
    // 0x800BAC78: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BAC7C: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BAC80: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BAC84: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800BAC88: nop

    // 0x800BAC8C: lbu         $t7, 0x10($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X10);
    // 0x800BAC90: lbu         $t9, 0x11($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X11);
    // 0x800BAC94: sll         $t8, $t7, 24
    ctx->r24 = S32(ctx->r15 << 24);
    // 0x800BAC98: sll         $t7, $t9, 16
    ctx->r15 = S32(ctx->r25 << 16);
    // 0x800BAC9C: or          $t6, $t8, $t7
    ctx->r14 = ctx->r24 | ctx->r15;
    // 0x800BACA0: lbu         $t8, 0x12($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X12);
    // 0x800BACA4: nop

    // 0x800BACA8: sll         $t7, $t8, 8
    ctx->r15 = S32(ctx->r24 << 8);
    // 0x800BACAC: or          $t9, $t6, $t7
    ctx->r25 = ctx->r14 | ctx->r15;
    // 0x800BACB0: lbu         $t6, 0x13($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X13);
    // 0x800BACB4: nop

    // 0x800BACB8: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x800BACBC: b           L_800BACE0
    // 0x800BACC0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
        goto L_800BACE0;
    // 0x800BACC0: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
L_800BACC4:
    // 0x800BACC4: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BACC8: addiu       $v1, $zero, -0x100
    ctx->r3 = ADD32(0, -0X100);
    // 0x800BACCC: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BACD0: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BACD4: lui         $t9, 0xFB00
    ctx->r25 = S32(0XFB00 << 16);
    // 0x800BACD8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BACDC: sw          $v1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r3;
L_800BACE0:
    // 0x800BACE0: lw          $t6, 0x28($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X28);
    // 0x800BACE4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BACE8: beq         $t6, $zero, L_800BAD08
    if (ctx->r14 == 0) {
        // 0x800BACEC: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_800BAD08;
    }
    // 0x800BACEC: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BACF0: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BACF4: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BACF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BACFC: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800BAD00: b           L_800BAD18
    // 0x800BAD04: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
        goto L_800BAD18;
    // 0x800BAD04: swc1        $f20, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f20.u32l;
L_800BAD08:
    // 0x800BAD08: mtc1        $at, $f24
    ctx->f24.u32l = ctx->r1;
    // 0x800BAD0C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BAD10: mtc1        $at, $f20
    ctx->f20.u32l = ctx->r1;
    // 0x800BAD14: swc1        $f24, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f24.u32l;
L_800BAD18:
    // 0x800BAD18: lw          $t7, 0x30DC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X30DC);
    // 0x800BAD1C: sh          $zero, 0xE8($sp)
    MEM_H(0XE8, ctx->r29) = 0;
    // 0x800BAD20: sh          $zero, 0xE6($sp)
    MEM_H(0XE6, ctx->r29) = 0;
    // 0x800BAD24: blez        $t7, L_800BB240
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800BAD28: sh          $zero, 0xE4($sp)
        MEM_H(0XE4, ctx->r29) = 0;
            goto L_800BB240;
    }
    // 0x800BAD28: sh          $zero, 0xE4($sp)
    MEM_H(0XE4, ctx->r29) = 0;
    // 0x800BAD2C: lw          $t8, 0xDC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XDC);
    // 0x800BAD30: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800BAD34: addiu       $t6, $t6, -0x5E18
    ctx->r14 = ADD32(ctx->r14, -0X5E18);
    // 0x800BAD38: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x800BAD3C: addu        $s0, $t9, $t6
    ctx->r16 = ADD32(ctx->r25, ctx->r14);
    // 0x800BAD40: lui         $s7, 0x800E
    ctx->r23 = S32(0X800E << 16);
    // 0x800BAD44: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800BAD48: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800BAD4C: mtc1        $zero, $f22
    ctx->f22.u32l = 0;
    // 0x800BAD50: addiu       $s3, $s3, -0x5FE8
    ctx->r19 = ADD32(ctx->r19, -0X5FE8);
    // 0x800BAD54: addiu       $s5, $s5, 0x3070
    ctx->r21 = ADD32(ctx->r21, 0X3070);
    // 0x800BAD58: addiu       $s7, $s7, 0x3080
    ctx->r23 = ADD32(ctx->r23, 0X3080);
    // 0x800BAD5C: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
    // 0x800BAD60: addiu       $s6, $zero, 0xA
    ctx->r22 = ADD32(0, 0XA);
    // 0x800BAD64: lui         $s4, 0x400
    ctx->r20 = S32(0X400 << 16);
L_800BAD68:
    // 0x800BAD68: lw          $t7, 0x4C($ra)
    ctx->r15 = MEM_W(ctx->r31, 0X4C);
    // 0x800BAD6C: lw          $s0, 0x74($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X74);
    // 0x800BAD70: beq         $t7, $zero, L_800BAD94
    if (ctx->r15 == 0) {
        // 0x800BAD74: nop
    
            goto L_800BAD94;
    }
    // 0x800BAD74: nop

    // 0x800BAD78: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800BAD7C: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x800BAD80: jal         0x800B92F4
    // 0x800BAD84: nop

    func_800B92F4(rdram, ctx);
        goto after_7;
    // 0x800BAD84: nop

    after_7:
    // 0x800BAD88: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAD8C: b           L_800BADAC
    // 0x800BAD90: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
        goto L_800BADAC;
    // 0x800BAD90: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
L_800BAD94:
    // 0x800BAD94: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800BAD98: lw          $a1, 0x128($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X128);
    // 0x800BAD9C: jal         0x800B97A8
    // 0x800BADA0: nop

    func_800B97A8(rdram, ctx);
        goto after_8;
    // 0x800BADA0: nop

    after_8:
    // 0x800BADA4: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BADA8: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
L_800BADAC:
    // 0x800BADAC: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x800BADB0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BADB4: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x800BADB8: lw          $t6, 0x30D8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30D8);
    // 0x800BADBC: subu        $t9, $t9, $t8
    ctx->r25 = SUB32(ctx->r25, ctx->r24);
    // 0x800BADC0: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x800BADC4: addu        $v0, $t9, $t6
    ctx->r2 = ADD32(ctx->r25, ctx->r14);
    // 0x800BADC8: lh          $t7, 0x4($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X4);
    // 0x800BADCC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BADD0: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x800BADD4: lw          $t6, 0x30D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30D4);
    // 0x800BADD8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BADDC: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BADE0: addiu       $a1, $a1, -0x603C
    ctx->r5 = ADD32(ctx->r5, -0X603C);
    // 0x800BADE4: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
    // 0x800BADE8: lh          $t8, 0x6($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X6);
    // 0x800BADEC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BADF0: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800BADF4: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    // 0x800BADF8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BADFC: swc1        $f10, 0xF4($sp)
    MEM_W(0XF4, ctx->r29) = ctx->f10.u32l;
    // 0x800BAE00: lh          $t9, 0x8($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X8);
    // 0x800BAE04: nop

    // 0x800BAE08: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800BAE0C: nop

    // 0x800BAE10: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800BAE14: swc1        $f18, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f18.u32l;
    // 0x800BAE18: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800BAE1C: nop

    // 0x800BAE20: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BAE24: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x800BAE28: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800BAE2C: lw          $t6, 0x28($ra)
    ctx->r14 = MEM_W(ctx->r31, 0X28);
    extern void dkr_presentation_wave_block(uint8_t*, recomp_context*); dkr_presentation_wave_block(rdram, ctx);
    // 0x800BAE30: sw          $t7, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r15;
    // 0x800BAE34: beq         $t6, $zero, L_800BB0C8
    if (ctx->r14 == 0) {
        // 0x800BAE38: nop
    
            goto L_800BB0C8;
    }
    // 0x800BAE38: nop

    // 0x800BAE3C: sw          $zero, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = 0;
    // 0x800BAE40: sw          $v0, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->r2;
    // 0x800BAE44: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
L_800BAE48:
    // 0x800BAE48: lw          $v0, 0xE0($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE0);
    // 0x800BAE4C: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x800BAE50: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x800BAE54: nop

    // 0x800BAE58: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BAE5C: nop

    // 0x800BAE60: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BAE64: swc1        $f6, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f6.u32l;
L_800BAE68:
    // 0x800BAE68: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800BAE6C: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800BAE70: addiu       $a1, $a1, -0x603C
    ctx->r5 = ADD32(ctx->r5, -0X603C);
    // 0x800BAE74: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800BAE78: addiu       $a2, $sp, 0xE4
    ctx->r6 = ADD32(ctx->r29, 0XE4);
    extern void dkr_presentation_wave_selection(uint8_t*, recomp_context*); dkr_presentation_wave_selection(rdram, ctx);
    // 0x800BAE7C: jal         0x80069484
    // 0x800BAE80: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_9;
    // 0x800BAE80: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_9:
    // 0x800BAE84: lw          $a1, 0x104($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X104);
    // 0x800BAE88: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BAE8C: andi        $t9, $a1, 0xFF
    ctx->r25 = ctx->r5 & 0XFF;
    // 0x800BAE90: beq         $t9, $zero, L_800BAFC0
    if (ctx->r25 == 0) {
        // 0x800BAE94: addiu       $ra, $ra, -0x6038
        ctx->r31 = ADD32(ctx->r31, -0X6038);
            goto L_800BAFC0;
    }
    // 0x800BAE94: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
    // 0x800BAE98: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BAE9C: addiu       $t7, $t9, -0x1
    ctx->r15 = ADD32(ctx->r25, -0X1);
    // 0x800BAEA0: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x800BAEA4: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BAEA8: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800BAEAC: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800BAEB0: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800BAEB4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800BAEB8: sll         $t8, $t3, 3
    ctx->r24 = S32(ctx->r11 << 3);
    // 0x800BAEBC: sll         $t7, $t4, 1
    ctx->r15 = S32(ctx->r12 << 1);
    // 0x800BAEC0: addiu       $t4, $t7, 0x8
    ctx->r12 = ADD32(ctx->r15, 0X8);
    // 0x800BAEC4: or          $t3, $t8, $zero
    ctx->r11 = ctx->r24 | 0;
    // 0x800BAEC8: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x800BAECC: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x800BAED0: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x800BAED4: mflo        $t6
    ctx->r14 = lo;
    // 0x800BAED8: ori         $t7, $t9, 0x1
    ctx->r15 = ctx->r25 | 0X1;
    // 0x800BAEDC: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800BAEE0: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BAEE4: andi        $t6, $t4, 0xFFFF
    ctx->r14 = ctx->r12 & 0XFFFF;
    // 0x800BAEE8: or          $t4, $t6, $zero
    ctx->r12 = ctx->r14 | 0;
    // 0x800BAEEC: andi        $t6, $t7, 0xFF
    ctx->r14 = ctx->r15 & 0XFF;
    // 0x800BAEF0: sll         $t8, $t6, 16
    ctx->r24 = S32(ctx->r14 << 16);
    // 0x800BAEF4: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x800BAEF8: andi        $t6, $t7, 0xFFFF
    ctx->r14 = ctx->r15 & 0XFFFF;
    // 0x800BAEFC: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x800BAF00: or          $t5, $t9, $t6
    ctx->r13 = ctx->r25 | ctx->r14;
    // 0x800BAF04: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800BAF08: mflo        $t0
    ctx->r8 = lo;
    // 0x800BAF0C: blez        $a2, L_800BB058
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BAF10: nop
    
            goto L_800BB058;
    }
    // 0x800BAF10: nop

L_800BAF14:
    // 0x800BAF14: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BAF18: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800BAF1C: lw          $t7, 0x128($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X128);
    // 0x800BAF20: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAF24: addu        $a0, $t8, $t7
    ctx->r4 = ADD32(ctx->r24, ctx->r15);
    // 0x800BAF28: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x800BAF2C: addu        $t6, $s5, $t9
    ctx->r14 = ADD32(ctx->r21, ctx->r25);
    // 0x800BAF30: lw          $t8, 0x0($t6)
    ctx->r24 = MEM_W(ctx->r14, 0X0);
    // 0x800BAF34: addu        $t9, $s7, $t9
    ctx->r25 = ADD32(ctx->r23, ctx->r25);
    // 0x800BAF38: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x800BAF3C: mflo        $t7
    ctx->r15 = lo;
    // 0x800BAF40: addu        $t1, $t8, $t7
    ctx->r9 = ADD32(ctx->r24, ctx->r15);
    // 0x800BAF44: sll         $t8, $a2, 1
    ctx->r24 = S32(ctx->r6 << 1);
    // 0x800BAF48: multu       $s0, $t8
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BAF4C: addu        $a1, $t1, $s2
    ctx->r5 = ADD32(ctx->r9, ctx->r18);
    // 0x800BAF50: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BAF54: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BAF58: sw          $a1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r5;
    // 0x800BAF5C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BAF60: mflo        $t7
    ctx->r15 = lo;
    // 0x800BAF64: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x800BAF68: andi        $t7, $a1, 0x6
    ctx->r15 = ctx->r5 & 0X6;
    // 0x800BAF6C: addu        $t2, $t6, $t9
    ctx->r10 = ADD32(ctx->r14, ctx->r25);
    // 0x800BAF70: or          $t6, $t3, $t7
    ctx->r14 = ctx->r11 | ctx->r15;
    // 0x800BAF74: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800BAF78: sll         $t8, $t9, 16
    ctx->r24 = S32(ctx->r25 << 16);
    // 0x800BAF7C: or          $t7, $t8, $s4
    ctx->r15 = ctx->r24 | ctx->r20;
    // 0x800BAF80: or          $t6, $t7, $t4
    ctx->r14 = ctx->r15 | ctx->r12;
    // 0x800BAF84: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
    // 0x800BAF88: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAF8C: addu        $t8, $t2, $s2
    ctx->r24 = ADD32(ctx->r10, ctx->r18);
    // 0x800BAF90: addiu       $t9, $a3, 0x8
    ctx->r25 = ADD32(ctx->r7, 0X8);
    // 0x800BAF94: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x800BAF98: sw          $t8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r24;
    // 0x800BAF9C: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800BAFA0: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BAFA4: nop

    // 0x800BAFA8: slt         $at, $s0, $a2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BAFAC: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800BAFB0: bne         $at, $zero, L_800BAF14
    if (ctx->r1 != 0) {
        // 0x800BAFB4: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BAF14;
    }
    // 0x800BAFB4: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x800BAFB8: b           L_800BB058
    // 0x800BAFBC: nop

        goto L_800BB058;
    // 0x800BAFBC: nop

L_800BAFC0:
    // 0x800BAFC0: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800BAFC4: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x800BAFC8: multu       $t6, $a1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BAFCC: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BAFD0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BAFD4: addiu       $a0, $a0, -0x5FD8
    ctx->r4 = ADD32(ctx->r4, -0X5FD8);
    // 0x800BAFD8: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BAFDC: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BAFE0: mflo        $t9
    ctx->r25 = lo;
    // 0x800BAFE4: addu        $t8, $a0, $t9
    ctx->r24 = ADD32(ctx->r4, ctx->r25);
    // 0x800BAFE8: addu        $t7, $t8, $s2
    ctx->r15 = ADD32(ctx->r24, ctx->r18);
    // 0x800BAFEC: andi        $t6, $t7, 0x6
    ctx->r14 = ctx->r15 & 0X6;
    // 0x800BAFF0: ori         $t9, $t6, 0x18
    ctx->r25 = ctx->r14 | 0X18;
    // 0x800BAFF4: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x800BAFF8: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800BAFFC: or          $t6, $t7, $s4
    ctx->r14 = ctx->r15 | ctx->r20;
    // 0x800BB000: ori         $t9, $t6, 0x50
    ctx->r25 = ctx->r14 | 0X50;
    // 0x800BB004: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB008: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x800BB00C: nop

    // 0x800BB010: multu       $t8, $a1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB014: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB018: addu        $t6, $a0, $t7
    ctx->r14 = ADD32(ctx->r4, ctx->r15);
    // 0x800BB01C: addu        $t9, $t6, $s2
    ctx->r25 = ADD32(ctx->r14, ctx->r18);
    // 0x800BB020: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
    // 0x800BB024: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB028: lui         $t7, 0x511
    ctx->r15 = S32(0X511 << 16);
    // 0x800BB02C: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB030: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB034: ori         $t7, $t7, 0x20
    ctx->r15 = ctx->r15 | 0X20;
    // 0x800BB038: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB03C: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x800BB040: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BB044: sll         $t8, $t9, 5
    ctx->r24 = S32(ctx->r25 << 5);
    // 0x800BB048: addu        $t7, $t8, $s2
    ctx->r15 = ADD32(ctx->r24, ctx->r18);
    // 0x800BB04C: addiu       $t6, $t6, 0x3090
    ctx->r14 = ADD32(ctx->r14, 0X3090);
    // 0x800BB050: addu        $t9, $t7, $t6
    ctx->r25 = ADD32(ctx->r15, ctx->r14);
    // 0x800BB054: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
L_800BB058:
    // 0x800BB058: jal         0x80069A40
    // 0x800BB05C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_pop(rdram, ctx);
        goto after_10;
    // 0x800BB05C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_10:
    // 0x800BB060: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB064: lwc1        $f10, -0x5F60($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5F60);
    // 0x800BB068: lw          $t8, 0x104($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X104);
    // 0x800BB06C: mul.s       $f16, $f10, $f20
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f20.fl);
    // 0x800BB070: lwc1        $f8, 0xF0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XF0);
    // 0x800BB074: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x800BB078: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800BB07C: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800BB080: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB084: sra         $t7, $t8, 8
    ctx->r15 = S32(SIGNED(ctx->r24) >> 8);
    // 0x800BB088: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
    // 0x800BB08C: sw          $t7, 0x104($sp)
    MEM_W(0X104, ctx->r29) = ctx->r15;
    // 0x800BB090: bne         $fp, $v1, L_800BAE68
    if (ctx->r30 != ctx->r3) {
        // 0x800BB094: swc1        $f18, 0xF0($sp)
        MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
            goto L_800BAE68;
    }
    // 0x800BB094: swc1        $f18, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->f18.u32l;
    // 0x800BB098: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BB09C: lwc1        $f6, -0x5F5C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5F5C);
    // 0x800BB0A0: lw          $v0, 0x11C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X11C);
    // 0x800BB0A4: mul.s       $f10, $f6, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BB0A8: lwc1        $f4, 0xF8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XF8);
    // 0x800BB0AC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BB0B0: sw          $v0, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r2;
    // 0x800BB0B4: add.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x800BB0B8: bne         $v0, $v1, L_800BAE48
    if (ctx->r2 != ctx->r3) {
        // 0x800BB0BC: swc1        $f8, 0xF8($sp)
        MEM_W(0XF8, ctx->r29) = ctx->f8.u32l;
            goto L_800BAE48;
    }
    // 0x800BB0BC: swc1        $f8, 0xF8($sp)
    MEM_W(0XF8, ctx->r29) = ctx->f8.u32l;
    // 0x800BB0C0: b           L_800BB21C
    // 0x800BB0C4: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
        goto L_800BB21C;
    // 0x800BB0C4: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
L_800BB0C8:
    // 0x800BB0C8: sw          $s0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r16;
    // 0x800BB0CC: mfc1        $a3, $f24
    ctx->r7 = (int32_t)ctx->f24.u32l;
    // 0x800BB0D0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    extern void dkr_presentation_wave_selection(uint8_t*, recomp_context*); dkr_presentation_wave_selection(rdram, ctx);
    // 0x800BB0D4: jal         0x80069484
    // 0x800BB0D8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_11;
    // 0x800BB0D8: swc1        $f22, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f22.u32l;
    after_11:
    // 0x800BB0DC: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB0E0: lw          $t6, 0x104($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X104);
    // 0x800BB0E4: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
    // 0x800BB0E8: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BB0EC: andi        $t9, $t6, 0xFF
    ctx->r25 = ctx->r14 & 0XFF;
    // 0x800BB0F0: addiu       $t8, $t9, -0x1
    ctx->r24 = ADD32(ctx->r25, -0X1);
    // 0x800BB0F4: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x800BB0F8: multu       $t8, $v1
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB0FC: sll         $v0, $v1, 1
    ctx->r2 = S32(ctx->r3 << 1);
    // 0x800BB100: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
    // 0x800BB104: addu        $t4, $t9, $v0
    ctx->r12 = ADD32(ctx->r25, ctx->r2);
    // 0x800BB108: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800BB10C: sll         $t6, $t3, 3
    ctx->r14 = S32(ctx->r11 << 3);
    // 0x800BB110: sll         $t8, $t4, 1
    ctx->r24 = S32(ctx->r12 << 1);
    // 0x800BB114: addiu       $t4, $t8, 0x8
    ctx->r12 = ADD32(ctx->r24, 0X8);
    // 0x800BB118: or          $t3, $t6, $zero
    ctx->r11 = ctx->r14 | 0;
    // 0x800BB11C: sll         $a0, $a2, 1
    ctx->r4 = S32(ctx->r6 << 1);
    // 0x800BB120: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x800BB124: sll         $t9, $t6, 4
    ctx->r25 = S32(ctx->r14 << 4);
    // 0x800BB128: mflo        $t7
    ctx->r15 = lo;
    // 0x800BB12C: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x800BB130: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800BB134: multu       $t7, $v1
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB138: andi        $t7, $t4, 0xFFFF
    ctx->r15 = ctx->r12 & 0XFFFF;
    // 0x800BB13C: or          $t4, $t7, $zero
    ctx->r12 = ctx->r15 | 0;
    // 0x800BB140: andi        $t7, $t8, 0xFF
    ctx->r15 = ctx->r24 & 0XFF;
    // 0x800BB144: sll         $t6, $t7, 16
    ctx->r14 = S32(ctx->r15 << 16);
    // 0x800BB148: sll         $t8, $a0, 4
    ctx->r24 = S32(ctx->r4 << 4);
    // 0x800BB14C: andi        $t7, $t8, 0xFFFF
    ctx->r15 = ctx->r24 & 0XFFFF;
    // 0x800BB150: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x800BB154: mflo        $t0
    ctx->r8 = lo;
    // 0x800BB158: blez        $a2, L_800BB208
    if (SIGNED(ctx->r6) <= 0) {
        // 0x800BB15C: nop
    
            goto L_800BB208;
    }
    // 0x800BB15C: nop

    // 0x800BB160: lw          $fp, 0x128($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X128);
    // 0x800BB164: or          $t5, $t9, $t7
    ctx->r13 = ctx->r25 | ctx->r15;
L_800BB168:
    // 0x800BB168: multu       $t0, $s6
    result = U64(U32(ctx->r8)) * U64(U32(ctx->r22)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB16C: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800BB170: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB174: addu        $a0, $t6, $fp
    ctx->r4 = ADD32(ctx->r14, ctx->r30);
    // 0x800BB178: sll         $t8, $a0, 2
    ctx->r24 = S32(ctx->r4 << 2);
    // 0x800BB17C: addu        $t9, $s5, $t8
    ctx->r25 = ADD32(ctx->r21, ctx->r24);
    // 0x800BB180: lw          $t7, 0x0($t9)
    ctx->r15 = MEM_W(ctx->r25, 0X0);
    // 0x800BB184: addu        $t8, $s7, $t8
    ctx->r24 = ADD32(ctx->r23, ctx->r24);
    // 0x800BB188: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800BB18C: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB190: addu        $t1, $t7, $t6
    ctx->r9 = ADD32(ctx->r15, ctx->r14);
    // 0x800BB194: sll         $t7, $a2, 1
    ctx->r15 = S32(ctx->r6 << 1);
    // 0x800BB198: multu       $s0, $t7
    result = U64(U32(ctx->r16)) * U64(U32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BB19C: addu        $a1, $t1, $s2
    ctx->r5 = ADD32(ctx->r9, ctx->r18);
    // 0x800BB1A0: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BB1A4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BB1A8: sw          $a1, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r5;
    // 0x800BB1AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800BB1B0: mflo        $t6
    ctx->r14 = lo;
    // 0x800BB1B4: sll         $t8, $t6, 4
    ctx->r24 = S32(ctx->r14 << 4);
    // 0x800BB1B8: andi        $t6, $a1, 0x6
    ctx->r14 = ctx->r5 & 0X6;
    // 0x800BB1BC: addu        $t2, $t9, $t8
    ctx->r10 = ADD32(ctx->r25, ctx->r24);
    // 0x800BB1C0: or          $t9, $t3, $t6
    ctx->r25 = ctx->r11 | ctx->r14;
    // 0x800BB1C4: andi        $t8, $t9, 0xFF
    ctx->r24 = ctx->r25 & 0XFF;
    // 0x800BB1C8: sll         $t7, $t8, 16
    ctx->r15 = S32(ctx->r24 << 16);
    // 0x800BB1CC: or          $t6, $t7, $s4
    ctx->r14 = ctx->r15 | ctx->r20;
    // 0x800BB1D0: or          $t9, $t6, $t4
    ctx->r25 = ctx->r14 | ctx->r12;
    // 0x800BB1D4: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB1D8: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB1DC: addu        $t7, $t2, $s2
    ctx->r15 = ADD32(ctx->r10, ctx->r18);
    // 0x800BB1E0: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB1E4: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB1E8: sw          $t7, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r15;
    // 0x800BB1EC: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
    // 0x800BB1F0: lw          $a2, 0x0($ra)
    ctx->r6 = MEM_W(ctx->r31, 0X0);
    // 0x800BB1F4: nop

    // 0x800BB1F8: slt         $at, $s0, $a2
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x800BB1FC: addu        $t0, $t0, $a2
    ctx->r8 = ADD32(ctx->r8, ctx->r6);
    // 0x800BB200: bne         $at, $zero, L_800BB168
    if (ctx->r1 != 0) {
        // 0x800BB204: addiu       $t0, $t0, 0x1
        ctx->r8 = ADD32(ctx->r8, 0X1);
            goto L_800BB168;
    }
    // 0x800BB204: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
L_800BB208:
    // 0x800BB208: jal         0x80069A40
    // 0x800BB20C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_pop(rdram, ctx);
        goto after_12;
    // 0x800BB20C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x800BB210: lui         $ra, 0x8013
    ctx->r31 = S32(0X8013 << 16);
    // 0x800BB214: addiu       $ra, $ra, -0x6038
    ctx->r31 = ADD32(ctx->r31, -0X6038);
    // 0x800BB218: lw          $t6, 0xDC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XDC);
L_800BB21C:
    // 0x800BB21C: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x800BB220: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x800BB224: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BB228: lw          $t6, 0x30DC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X30DC);
    // 0x800BB22C: addiu       $t7, $t8, 0x2
    ctx->r15 = ADD32(ctx->r24, 0X2);
    // 0x800BB230: slt         $at, $t9, $t6
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BB234: sw          $t7, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r15;
    // 0x800BB238: bne         $at, $zero, L_800BAD68
    if (ctx->r1 != 0) {
        // 0x800BB23C: sw          $t9, 0xDC($sp)
        MEM_W(0XDC, ctx->r29) = ctx->r25;
            goto L_800BAD68;
    }
    // 0x800BB23C: sw          $t9, 0xDC($sp)
    MEM_W(0XDC, ctx->r29) = ctx->r25;
L_800BB240:
    // 0x800BB240: lw          $t8, 0x4C($ra)
    ctx->r24 = MEM_W(ctx->r31, 0X4C);
    // 0x800BB244: lui         $t9, 0xB700
    ctx->r25 = S32(0XB700 << 16);
    // 0x800BB248: beq         $t8, $zero, L_800BB284
    if (ctx->r24 == 0) {
        // 0x800BB24C: nop
    
            goto L_800BB284;
    }
    // 0x800BB24C: nop

    // 0x800BB250: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB254: lui         $t6, 0x1
    ctx->r14 = S32(0X1 << 16);
    // 0x800BB258: addiu       $t7, $a3, 0x8
    ctx->r15 = ADD32(ctx->r7, 0X8);
    // 0x800BB25C: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x800BB260: sw          $t6, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r14;
    // 0x800BB264: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x800BB268: lw          $a3, 0x0($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X0);
    // 0x800BB26C: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800BB270: addiu       $t8, $a3, 0x8
    ctx->r24 = ADD32(ctx->r7, 0X8);
    // 0x800BB274: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x800BB278: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800BB27C: sw          $t7, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r15;
    // 0x800BB280: sw          $t9, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->r25;
L_800BB284:
    // 0x800BB284: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x800BB288: lw          $t8, 0x120($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X120);
    // 0x800BB28C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BB290: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x800BB294: lw          $t9, 0x124($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X124);
    // 0x800BB298: lw          $t7, -0x603C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X603C);
    // 0x800BB29C: nop

    // 0x800BB2A0: sw          $t7, 0x0($t9)
    MEM_W(0X0, ctx->r25) = ctx->r15;
L_800BB2A4:
    extern void dkr_presentation_wave_end(uint8_t*, recomp_context*); dkr_presentation_wave_end(rdram, ctx);
    // 0x800BB2A4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800BB2A8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800BB2AC: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BB2B0: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BB2B4: lwc1        $f23, 0x28($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BB2B8: lwc1        $f22, 0x2C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BB2BC: lwc1        $f25, 0x30($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BB2C0: lwc1        $f24, 0x34($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BB2C4: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x800BB2C8: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x800BB2CC: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x800BB2D0: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x800BB2D4: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x800BB2D8: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x800BB2DC: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x800BB2E0: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x800BB2E4: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x800BB2E8: sw          $zero, 0x30DC($at)
    MEM_W(0X30DC, ctx->r1) = 0;
    // 0x800BB2EC: jr          $ra
    // 0x800BB2F0: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
    return;
    // 0x800BB2F0: addiu       $sp, $sp, 0x120
    ctx->r29 = ADD32(ctx->r29, 0X120);
;}
RECOMP_FUNC void race_finish_timer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE44: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001AE48: lh          $v0, -0x52B2($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X52B2);
    // 0x8001AE4C: jr          $ra
    // 0x8001AE50: nop

    return;
    // 0x8001AE50: nop

;}
RECOMP_FUNC void particle_deallocate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B2040: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800B2044: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B2048: lh          $v0, 0x2C($a0)
    ctx->r2 = MEM_H(ctx->r4, 0X2C);
    // 0x800B204C: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800B2050: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800B2054: bne         $at, $zero, L_800B206C
    if (ctx->r1 != 0) {
        // 0x800B2058: addiu       $at, $zero, 0x80
        ctx->r1 = ADD32(0, 0X80);
            goto L_800B206C;
    }
    // 0x800B2058: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x800B205C: beq         $v0, $at, L_800B2090
    if (ctx->r2 == ctx->r1) {
        // 0x800B2060: nop
    
            goto L_800B2090;
    }
    // 0x800B2060: nop

    // 0x800B2064: b           L_800B2254
    // 0x800B2068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_800B2254;
    // 0x800B2068: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B206C:
    // 0x800B206C: sltiu       $at, $v0, 0x5
    ctx->r1 = ctx->r2 < 0X5 ? 1 : 0;
    // 0x800B2070: beq         $at, $zero, L_800B2250
    if (ctx->r1 == 0) {
        // 0x800B2074: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_800B2250;
    }
    // 0x800B2074: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x800B2078: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B207C: addu        $at, $at, $t6
    gpr jr_addend_800B2088 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x800B2080: lw          $t6, -0x7424($at)
    ctx->r14 = ADD32(ctx->r1, -0X7424);
    // 0x800B2084: nop

    // 0x800B2088: jr          $t6
    // 0x800B208C: nop

    switch (jr_addend_800B2088 >> 2) {
        case 0: goto L_800B2250; break;
        case 1: goto L_800B20E0; break;
        case 2: goto L_800B2138; break;
        case 3: goto L_800B2190; break;
        case 4: goto L_800B21E8; break;
        default: switch_error(__func__, 0x800B2088, 0x800E8BDC);
    }
    // 0x800B208C: nop

L_800B2090:
    // 0x800B2090: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2094: lw          $v0, 0x2CB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2CB8);
    // 0x800B2098: nop

    // 0x800B209C: blez        $v0, L_800B2254
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B20A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2254;
    }
    // 0x800B20A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B20A4: lw          $a0, 0x44($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X44);
    // 0x800B20A8: nop

    // 0x800B20AC: beq         $a0, $zero, L_800B20D0
    if (ctx->r4 == 0) {
        // 0x800B20B0: addiu       $t7, $v0, -0x1
        ctx->r15 = ADD32(ctx->r2, -0X1);
            goto L_800B20D0;
    }
    // 0x800B20B0: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
    // 0x800B20B4: jal         0x8007CCB0
    // 0x800B20B8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    sprite_free(rdram, ctx);
        goto after_0;
    // 0x800B20B8: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x800B20BC: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B20C0: lw          $v0, 0x2CB8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2CB8);
    // 0x800B20C4: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B20C8: nop

    // 0x800B20CC: addiu       $t7, $v0, -0x1
    ctx->r15 = ADD32(ctx->r2, -0X1);
L_800B20D0:
    // 0x800B20D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B20D4: sw          $t7, 0x2CB8($at)
    MEM_W(0X2CB8, ctx->r1) = ctx->r15;
    // 0x800B20D8: b           L_800B2250
    // 0x800B20DC: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B2250;
    // 0x800B20DC: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B20E0:
    // 0x800B20E0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B20E4: lw          $v0, 0x2CA0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2CA0);
    // 0x800B20E8: nop

    // 0x800B20EC: blez        $v0, L_800B2254
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B20F0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2254;
    }
    // 0x800B20F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B20F4: lw          $t8, 0x44($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X44);
    // 0x800B20F8: nop

    // 0x800B20FC: lw          $a0, 0x0($t8)
    ctx->r4 = MEM_W(ctx->r24, 0X0);
    // 0x800B2100: nop

    // 0x800B2104: beq         $a0, $zero, L_800B2128
    if (ctx->r4 == 0) {
        // 0x800B2108: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_800B2128;
    }
    // 0x800B2108: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x800B210C: jal         0x8007B2BC
    // 0x800B2110: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_1;
    // 0x800B2110: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_1:
    // 0x800B2114: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2118: lw          $v0, 0x2CA0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2CA0);
    // 0x800B211C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2120: nop

    // 0x800B2124: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
L_800B2128:
    // 0x800B2128: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B212C: sw          $t9, 0x2CA0($at)
    MEM_W(0X2CA0, ctx->r1) = ctx->r25;
    // 0x800B2130: b           L_800B2250
    // 0x800B2134: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B2250;
    // 0x800B2134: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B2138:
    // 0x800B2138: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B213C: lw          $v0, 0x2CAC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2CAC);
    // 0x800B2140: nop

    // 0x800B2144: blez        $v0, L_800B2254
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B2148: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2254;
    }
    // 0x800B2148: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B214C: lw          $t0, 0x44($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X44);
    // 0x800B2150: nop

    // 0x800B2154: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800B2158: nop

    // 0x800B215C: beq         $a0, $zero, L_800B2180
    if (ctx->r4 == 0) {
        // 0x800B2160: addiu       $t1, $v0, -0x1
        ctx->r9 = ADD32(ctx->r2, -0X1);
            goto L_800B2180;
    }
    // 0x800B2160: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x800B2164: jal         0x8007B2BC
    // 0x800B2168: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_2;
    // 0x800B2168: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_2:
    // 0x800B216C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2170: lw          $v0, 0x2CAC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2CAC);
    // 0x800B2174: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2178: nop

    // 0x800B217C: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
L_800B2180:
    // 0x800B2180: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B2184: sw          $t1, 0x2CAC($at)
    MEM_W(0X2CAC, ctx->r1) = ctx->r9;
    // 0x800B2188: b           L_800B2250
    // 0x800B218C: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B2250;
    // 0x800B218C: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B2190:
    // 0x800B2190: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2194: lw          $v0, 0x2CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2CC4);
    // 0x800B2198: nop

    // 0x800B219C: blez        $v0, L_800B2254
    if (SIGNED(ctx->r2) <= 0) {
        // 0x800B21A0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2254;
    }
    // 0x800B21A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B21A4: lw          $t2, 0x44($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X44);
    // 0x800B21A8: nop

    // 0x800B21AC: lw          $a0, 0x0($t2)
    ctx->r4 = MEM_W(ctx->r10, 0X0);
    // 0x800B21B0: nop

    // 0x800B21B4: beq         $a0, $zero, L_800B21D8
    if (ctx->r4 == 0) {
        // 0x800B21B8: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_800B21D8;
    }
    // 0x800B21B8: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x800B21BC: jal         0x8007B2BC
    // 0x800B21C0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_3;
    // 0x800B21C0: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_3:
    // 0x800B21C4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B21C8: lw          $v0, 0x2CC4($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X2CC4);
    // 0x800B21CC: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B21D0: nop

    // 0x800B21D4: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
L_800B21D8:
    // 0x800B21D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800B21DC: sw          $t3, 0x2CC4($at)
    MEM_W(0X2CC4, ctx->r1) = ctx->r11;
    // 0x800B21E0: b           L_800B2250
    // 0x800B21E4: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
        goto L_800B2250;
    // 0x800B21E4: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B21E8:
    // 0x800B21E8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800B21EC: lw          $t4, 0x2CD0($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X2CD0);
    // 0x800B21F0: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x800B21F4: blez        $t4, L_800B2254
    if (SIGNED(ctx->r12) <= 0) {
        // 0x800B21F8: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800B2254;
    }
    // 0x800B21F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B21FC: jal         0x800B263C
    // 0x800B2200: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    delete_point_particle_from_sequence(rdram, ctx);
        goto after_4;
    // 0x800B2200: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_4:
    // 0x800B2204: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2208: nop

    // 0x800B220C: lw          $t5, 0x44($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X44);
    // 0x800B2210: nop

    // 0x800B2214: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800B2218: nop

    // 0x800B221C: beq         $a0, $zero, L_800B2234
    if (ctx->r4 == 0) {
        // 0x800B2220: nop
    
            goto L_800B2234;
    }
    // 0x800B2220: nop

    // 0x800B2224: jal         0x8007B2BC
    // 0x800B2228: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    tex_free(rdram, ctx);
        goto after_5;
    // 0x800B2228: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_5:
    // 0x800B222C: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x800B2230: nop

L_800B2234:
    // 0x800B2234: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800B2238: addiu       $v0, $v0, 0x2CD0
    ctx->r2 = ADD32(ctx->r2, 0X2CD0);
    // 0x800B223C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x800B2240: nop

    // 0x800B2244: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x800B2248: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800B224C: sh          $zero, 0x2C($a1)
    MEM_H(0X2C, ctx->r5) = 0;
L_800B2250:
    // 0x800B2250: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800B2254:
    // 0x800B2254: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800B2258: jr          $ra
    // 0x800B225C: nop

    return;
    // 0x800B225C: nop

;}
RECOMP_FUNC void object_model_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    int32_t dkr_model_count_before = MEM_W(0, (int32_t)0x8011d62cU); int32_t dkr_model_free_before = MEM_W(0, (int32_t)0x8011d634U);
    // 0x8005F99C: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8005F9A0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8005F9A4: lw          $t6, -0x29D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X29D0);
    // 0x8005F9A8: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8005F9AC: slt         $at, $a0, $t6
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8005F9B0: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x8005F9B4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8005F9B8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8005F9BC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8005F9C0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8005F9C4: bne         $at, $zero, L_8005F9D0
    if (ctx->r1 != 0) {
        // 0x8005F9C8: sw          $a1, 0x5C($sp)
        MEM_W(0X5C, ctx->r29) = ctx->r5;
            goto L_8005F9D0;
    }
    // 0x8005F9C8: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    // 0x8005F9CC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8005F9D0:
    // 0x8005F9D0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8005F9D4: addiu       $a2, $a2, -0x29D4
    ctx->r6 = ADD32(ctx->r6, -0X29D4);
    // 0x8005F9D8: lw          $a0, 0x0($a2)
    ctx->r4 = MEM_W(ctx->r6, 0X0);
    // 0x8005F9DC: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005F9E0: blez        $a0, L_8005FA40
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8005F9E4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8005FA40;
    }
    // 0x8005F9E4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005F9E8: lw          $v1, -0x29DC($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X29DC);
    // 0x8005F9EC: nop

    // 0x8005F9F0: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
L_8005F9F4:
    // 0x8005F9F4: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x8005F9F8: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8005F9FC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005FA00: bne         $s3, $t9, L_8005FA38
    if (ctx->r19 != ctx->r25) {
        // 0x8005FA04: slt         $at, $s1, $a0
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8005FA38;
    }
    // 0x8005FA04: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005FA08: lw          $s2, 0x4($v0)
    ctx->r18 = MEM_W(ctx->r2, 0X4);
    // 0x8005FA0C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005FA10: jal         0x8005FCD0
    // 0x8005FA14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    model_instance_init(rdram, ctx);
        goto after_0;
    // 0x8005FA14: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_0:
    // 0x8005FA18: beq         $v0, $zero, L_8005FA30
    if (ctx->r2 == 0) {
        // 0x8005FA1C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005FA30;
    }
    // 0x8005FA1C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005FA20: lh          $t0, 0x30($s2)
    ctx->r8 = MEM_H(ctx->r18, 0X30);
    // 0x8005FA24: nop

    // 0x8005FA28: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x8005FA2C: sh          $t1, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r9;
L_8005FA30:
    // 0x8005FA30: b           L_8005FCB4
    // 0x8005FA34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
        goto L_8005FCB4;
    // 0x8005FA34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8005FA38:
    // 0x8005FA38: bne         $at, $zero, L_8005F9F4
    if (ctx->r1 != 0) {
        // 0x8005FA3C: sll         $t8, $s1, 3
        ctx->r24 = S32(ctx->r17 << 3);
            goto L_8005F9F4;
    }
    // 0x8005FA3C: sll         $t8, $s1, 3
    ctx->r24 = S32(ctx->r17 << 3);
L_8005FA40:
    // 0x8005FA40: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005FA44: addiu       $v1, $v1, -0x29CC
    ctx->r3 = ADD32(ctx->r3, -0X29CC);
    // 0x8005FA48: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8005FA4C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005FA50: blez        $v0, L_8005FA74
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8005FA54: addiu       $t2, $v0, -0x1
        ctx->r10 = ADD32(ctx->r2, -0X1);
            goto L_8005FA74;
    }
    // 0x8005FA54: addiu       $t2, $v0, -0x1
    ctx->r10 = ADD32(ctx->r2, -0X1);
    // 0x8005FA58: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x8005FA5C: lw          $t3, -0x29D8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X29D8);
    // 0x8005FA60: sll         $t5, $t2, 2
    ctx->r13 = S32(ctx->r10 << 2);
    // 0x8005FA64: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8005FA68: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8005FA6C: b           L_8005FA80
    // 0x8005FA70: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
        goto L_8005FA80;
    // 0x8005FA70: sw          $t7, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r15;
L_8005FA74:
    // 0x8005FA74: addiu       $t8, $a0, 0x1
    ctx->r24 = ADD32(ctx->r4, 0X1);
    // 0x8005FA78: sw          $a0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r4;
    // 0x8005FA7C: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
L_8005FA80:
    // 0x8005FA80: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8005FA84: lw          $t9, -0x29E0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X29E0);
    // 0x8005FA88: sll         $t0, $s3, 2
    ctx->r8 = S32(ctx->r19 << 2);
    // 0x8005FA8C: addu        $v0, $t9, $t0
    ctx->r2 = ADD32(ctx->r25, ctx->r8);
    // 0x8005FA90: lw          $s0, 0x0($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X0);
    // 0x8005FA94: lw          $t1, 0x4($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X4);
    // 0x8005FA98: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8005FA9C: subu        $t2, $t1, $s0
    ctx->r10 = SUB32(ctx->r9, ctx->r16);
    // 0x8005FAA0: sw          $t2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r10;
    // 0x8005FAA4: jal         0x800C61DC
    // 0x8005FAA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    gzip_size_uncompressed(rdram, ctx);
        goto after_1;
    // 0x8005FAA8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_1:
    // 0x8005FAAC: addiu       $a0, $v0, 0x80
    ctx->r4 = ADD32(ctx->r2, 0X80);
    // 0x8005FAB0: lui         $a1, 0xFF00
    ctx->r5 = S32(0XFF00 << 16);
    // 0x8005FAB4: sw          $a0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r4;
    // 0x8005FAB8: jal         0x80070D10
    // 0x8005FABC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    mempool_alloc(rdram, ctx);
        goto after_2;
    // 0x8005FABC: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    after_2:
    // 0x8005FAC0: bne         $v0, $zero, L_8005FAD0
    if (ctx->r2 != 0) {
        // 0x8005FAC4: or          $s2, $v0, $zero
        ctx->r18 = ctx->r2 | 0;
            goto L_8005FAD0;
    }
    // 0x8005FAC4: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8005FAC8: b           L_8005FCB4
    // 0x8005FACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8005FCB4;
    // 0x8005FACC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FAD0:
    // 0x8005FAD0: lw          $t4, 0x34($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X34);
    // 0x8005FAD4: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x8005FAD8: addu        $t3, $s2, $t4
    ctx->r11 = ADD32(ctx->r18, ctx->r12);
    // 0x8005FADC: subu        $a1, $t3, $a3
    ctx->r5 = SUB32(ctx->r11, ctx->r7);
    // 0x8005FAE0: sw          $a1, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r5;
    // 0x8005FAE4: addiu       $a0, $zero, 0x1D
    ctx->r4 = ADD32(0, 0X1D);
    // 0x8005FAE8: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8005FAEC: jal         0x80076E68
    // 0x8005FAF0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    asset_load(rdram, ctx);
        goto after_3;
    // 0x8005FAF0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    after_3:
    // 0x8005FAF4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8005FAF8: jal         0x800C6218
    // 0x8005FAFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    gzip_inflate(rdram, ctx);
        goto after_4;
    // 0x8005FAFC: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_4:
    // 0x8005FB00: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x8005FB04: lw          $t7, 0x4($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X4);
    // 0x8005FB08: lw          $t9, 0x8($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X8);
    // 0x8005FB0C: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8005FB10: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8005FB14: lw          $t1, 0x38($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X38);
    // 0x8005FB18: lw          $t4, 0x14($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X14);
    // 0x8005FB1C: lw          $t5, 0x1C($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X1C);
    // 0x8005FB20: lw          $t7, 0x4C($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X4C);
    // 0x8005FB24: lh          $a0, 0x22($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X22);
    // 0x8005FB28: sw          $t6, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r14;
    // 0x8005FB2C: sw          $t8, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r24;
    // 0x8005FB30: addu        $t0, $t9, $s2
    ctx->r8 = ADD32(ctx->r25, ctx->r18);
    // 0x8005FB34: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005FB38: addu        $t2, $t1, $s2
    ctx->r10 = ADD32(ctx->r9, ctx->r18);
    // 0x8005FB3C: addu        $t3, $t4, $s2
    ctx->r11 = ADD32(ctx->r12, ctx->r18);
    // 0x8005FB40: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8005FB44: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x8005FB48: sw          $t0, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r8;
    // 0x8005FB4C: sw          $t2, 0x38($s2)
    MEM_W(0X38, ctx->r18) = ctx->r10;
    // 0x8005FB50: sw          $t3, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r11;
    // 0x8005FB54: sw          $t6, 0x1C($s2)
    MEM_W(0X1C, ctx->r18) = ctx->r14;
    // 0x8005FB58: sw          $t8, 0x4C($s2)
    MEM_W(0X4C, ctx->r18) = ctx->r24;
    // 0x8005FB5C: sh          $t9, 0x30($s2)
    MEM_H(0X30, ctx->r18) = ctx->r25;
    // 0x8005FB60: sw          $zero, 0xC($s2)
    MEM_W(0XC, ctx->r18) = 0;
    // 0x8005FB64: sw          $zero, 0x10($s2)
    MEM_W(0X10, ctx->r18) = 0;
    // 0x8005FB68: sh          $zero, 0x32($s2)
    MEM_H(0X32, ctx->r18) = 0;
    // 0x8005FB6C: sh          $zero, 0x52($s2)
    MEM_H(0X52, ctx->r18) = 0;
    // 0x8005FB70: sw          $zero, 0x40($s2)
    MEM_W(0X40, ctx->r18) = 0;
    // 0x8005FB74: sh          $zero, 0x48($s2)
    MEM_H(0X48, ctx->r18) = 0;
    // 0x8005FB78: sw          $zero, 0x44($s2)
    MEM_W(0X44, ctx->r18) = 0;
    // 0x8005FB7C: blez        $a0, L_8005FBEC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8005FB80: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8005FBEC;
    }
    // 0x8005FB80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005FB84: lw          $s0, 0x0($s2)
    ctx->r16 = MEM_W(ctx->r18, 0X0);
    // 0x8005FB88: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8005FB8C:
    // 0x8005FB8C: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8005FB90: sb          $a1, 0x3F($sp)
    MEM_B(0X3F, ctx->r29) = ctx->r5;
    // 0x8005FB94: ori         $t0, $a0, 0x8000
    ctx->r8 = ctx->r4 | 0X8000;
    // 0x8005FB98: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
    // 0x8005FB9C: jal         0x8007AE74
    // 0x8005FBA0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    load_texture(rdram, ctx);
        goto after_5;
    // 0x8005FBA0: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x8005FBA4: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8005FBA8: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x8005FBAC: lb          $a1, 0x3F($sp)
    ctx->r5 = MEM_B(ctx->r29, 0X3F);
    // 0x8005FBB0: addu        $t2, $t1, $v1
    ctx->r10 = ADD32(ctx->r9, ctx->r3);
    // 0x8005FBB4: sw          $v0, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r2;
    // 0x8005FBB8: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8005FBBC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005FBC0: addu        $s0, $t4, $v1
    ctx->r16 = ADD32(ctx->r12, ctx->r3);
    // 0x8005FBC4: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8005FBC8: nop

    // 0x8005FBCC: bne         $t3, $zero, L_8005FBD8
    if (ctx->r11 != 0) {
        // 0x8005FBD0: nop
    
            goto L_8005FBD8;
    }
    // 0x8005FBD0: nop

    // 0x8005FBD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
L_8005FBD8:
    // 0x8005FBD8: lh          $a0, 0x22($s2)
    ctx->r4 = MEM_H(ctx->r18, 0X22);
    // 0x8005FBDC: addiu       $v1, $v1, 0x8
    ctx->r3 = ADD32(ctx->r3, 0X8);
    // 0x8005FBE0: slt         $at, $s1, $a0
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005FBE4: bne         $at, $zero, L_8005FB8C
    if (ctx->r1 != 0) {
        // 0x8005FBE8: addiu       $s0, $s0, 0x8
        ctx->r16 = ADD32(ctx->r16, 0X8);
            goto L_8005FB8C;
    }
    // 0x8005FBE8: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
L_8005FBEC:
    // 0x8005FBEC: bne         $a1, $zero, L_8005FCA8
    if (ctx->r5 != 0) {
        // 0x8005FBF0: nop
    
            goto L_8005FCA8;
    }
    // 0x8005FBF0: nop

    // 0x8005FBF4: lh          $a1, 0x28($s2)
    ctx->r5 = MEM_H(ctx->r18, 0X28);
    // 0x8005FBF8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8005FBFC: blez        $a1, L_8005FC2C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8005FC00: nop
    
            goto L_8005FC2C;
    }
    // 0x8005FC00: nop

    // 0x8005FC04: lw          $v0, 0x38($s2)
    ctx->r2 = MEM_W(ctx->r18, 0X38);
    // 0x8005FC08: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
L_8005FC0C:
    // 0x8005FC0C: lbu         $v1, 0x0($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X0);
    // 0x8005FC10: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8005FC14: beq         $a2, $v1, L_8005FC20
    if (ctx->r6 == ctx->r3) {
        // 0x8005FC18: slt         $at, $v1, $a0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8005FC20;
    }
    // 0x8005FC18: slt         $at, $v1, $a0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8005FC1C: beq         $at, $zero, L_8005FCA8
    if (ctx->r1 == 0) {
        // 0x8005FC20: slt         $at, $s1, $a1
        ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8005FCA8;
    }
L_8005FC20:
    // 0x8005FC20: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8005FC24: bne         $at, $zero, L_8005FC0C
    if (ctx->r1 != 0) {
        // 0x8005FC28: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_8005FC0C;
    }
    // 0x8005FC28: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8005FC2C:
    // 0x8005FC2C: jal         0x80060EA8
    // 0x8005FC30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    model_init_normals(rdram, ctx);
        goto after_6;
    // 0x8005FC30: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_6:
    // 0x8005FC34: bne         $v0, $zero, L_8005FCA8
    if (ctx->r2 != 0) {
        // 0x8005FC38: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_8005FCA8;
    }
    // 0x8005FC38: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x8005FC3C: jal         0x80061A00
    // 0x8005FC40: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    model_anim_init(rdram, ctx);
        goto after_7;
    // 0x8005FC40: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x8005FC44: bne         $v0, $zero, L_8005FCA8
    if (ctx->r2 != 0) {
        // 0x8005FC48: nop
    
            goto L_8005FCA8;
    }
    // 0x8005FC48: nop

    // 0x8005FC4C: lw          $a1, 0x5C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X5C);
    // 0x8005FC50: jal         0x8005FCD0
    // 0x8005FC54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    model_instance_init(rdram, ctx);
        goto after_8;
    // 0x8005FC54: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_8:
    // 0x8005FC58: beq         $v0, $zero, L_8005FCA8
    if (ctx->r2 == 0) {
        // 0x8005FC5C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8005FCA8;
    }
    // 0x8005FC5C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8005FC60: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005FC64: lw          $t5, 0x50($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X50);
    // 0x8005FC68: addiu       $a0, $a0, -0x29DC
    ctx->r4 = ADD32(ctx->r4, -0X29DC);
    // 0x8005FC6C: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x8005FC70: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8005FC74: addu        $t8, $t7, $t6
    ctx->r24 = ADD32(ctx->r15, ctx->r14);
    // 0x8005FC78: sw          $s3, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r19;
    // 0x8005FC7C: lw          $t9, 0x0($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X0);
    // 0x8005FC80: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8005FC84: addu        $t0, $t9, $t6
    ctx->r8 = ADD32(ctx->r25, ctx->r14);
    // 0x8005FC88: sw          $s2, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r18;
    // 0x8005FC8C: lw          $t1, -0x29D4($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X29D4);
    // 0x8005FC90: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x8005FC94: slti        $at, $t1, 0x46
    ctx->r1 = SIGNED(ctx->r9) < 0X46 ? 1 : 0;
    // 0x8005FC98: beq         $at, $zero, L_8005FCA8
    if (ctx->r1 == 0) {
        // 0x8005FC9C: nop
    
            goto L_8005FCA8;
    }
    // 0x8005FC9C: nop

    // 0x8005FCA0: b           L_8005FCB4
    // 0x8005FCA4: sb          $zero, 0x20($v1)
    MEM_B(0X20, ctx->r3) = 0;
        goto L_8005FCB4;
    // 0x8005FCA4: sb          $zero, 0x20($v1)
    MEM_B(0X20, ctx->r3) = 0;
L_8005FCA8:
    // 0x8005FCA8: jal         0x80060058
    // 0x8005FCAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    free_model_data(rdram, ctx);
        goto after_9;
    // 0x8005FCAC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_9:
    // 0x8005FCB0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8005FCB4:
    if (ctx->r2 == 0) { MEM_W(0, (int32_t)0x8011d62cU) = dkr_model_count_before; MEM_W(0, (int32_t)0x8011d634U) = dkr_model_free_before; }
    // 0x8005FCB4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005FCB8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8005FCBC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8005FCC0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8005FCC4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8005FCC8: jr          $ra
    // 0x8005FCCC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8005FCCC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void turn_head_towards_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80052388: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8005238C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80052390: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80052394: lwc1        $f6, 0xC($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0XC);
    // 0x80052398: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x8005239C: lwc1        $f10, 0x14($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800523A0: sub.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800523A4: lwc1        $f8, 0x14($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800523A8: mul.s       $f16, $f12, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800523AC: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800523B0: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800523B4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800523B8: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800523BC: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800523C0: c.lt.s      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.fl < ctx->f6.fl;
    // 0x800523C4: nop

    // 0x800523C8: bc1f        L_80052500
    if (!c1cs) {
        // 0x800523CC: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80052500;
    }
    // 0x800523CC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800523D0: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x800523D4: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800523D8: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800523DC: swc1        $f12, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f12.u32l;
    // 0x800523E0: jal         0x80070750
    // 0x800523E4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    arctan2_f(rdram, ctx);
        goto after_0;
    // 0x800523E4: swc1        $f14, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f14.u32l;
    after_0:
    // 0x800523E8: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x800523EC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800523F0: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800523F4: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x800523F8: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800523FC: subu        $v1, $v0, $t7
    ctx->r3 = SUB32(ctx->r2, ctx->r15);
    // 0x80052400: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x80052404: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x80052408: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x8005240C: lwc1        $f12, 0x20($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X20);
    // 0x80052410: lwc1        $f14, 0x1C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80052414: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80052418: bne         $at, $zero, L_80052428
    if (ctx->r1 != 0) {
        // 0x8005241C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80052428;
    }
    // 0x8005241C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x80052420: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80052424: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80052428:
    // 0x80052428: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005242C: beq         $at, $zero, L_80052438
    if (ctx->r1 == 0) {
        // 0x80052430: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_80052438;
    }
    // 0x80052430: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x80052434: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80052438:
    // 0x80052438: slti        $at, $v1, 0x3001
    ctx->r1 = SIGNED(ctx->r3) < 0X3001 ? 1 : 0;
    // 0x8005243C: bne         $at, $zero, L_8005244C
    if (ctx->r1 != 0) {
        // 0x80052440: slti        $at, $v1, -0x3000
        ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
            goto L_8005244C;
    }
    // 0x80052440: slti        $at, $v1, -0x3000
    ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
    // 0x80052444: addiu       $v1, $zero, 0x3000
    ctx->r3 = ADD32(0, 0X3000);
    // 0x80052448: slti        $at, $v1, -0x3000
    ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
L_8005244C:
    // 0x8005244C: beq         $at, $zero, L_80052458
    if (ctx->r1 == 0) {
        // 0x80052450: nop
    
            goto L_80052458;
    }
    // 0x80052450: nop

    // 0x80052454: addiu       $v1, $zero, -0x3000
    ctx->r3 = ADD32(0, -0X3000);
L_80052458:
    // 0x80052458: lb          $t8, 0x1E7($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X1E7);
    // 0x8005245C: sh          $v1, 0x16C($a1)
    MEM_H(0X16C, ctx->r5) = ctx->r3;
    // 0x80052460: andi        $t9, $t8, 0x3F
    ctx->r25 = ctx->r24 & 0X3F;
    // 0x80052464: slti        $at, $t9, 0x1F
    ctx->r1 = SIGNED(ctx->r25) < 0X1F ? 1 : 0;
    // 0x80052468: beq         $at, $zero, L_80052474
    if (ctx->r1 == 0) {
        // 0x8005246C: nop
    
            goto L_80052474;
    }
    // 0x8005246C: nop

    // 0x80052470: sh          $zero, 0x16C($a1)
    MEM_H(0X16C, ctx->r5) = 0;
L_80052474:
    // 0x80052474: lw          $a1, 0x64($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X64);
    // 0x80052478: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8005247C: jal         0x80070750
    // 0x80052480: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    arctan2_f(rdram, ctx);
        goto after_1;
    // 0x80052480: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_1:
    // 0x80052484: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80052488: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005248C: lh          $t0, 0x0($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X0);
    // 0x80052490: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x80052494: andi        $t1, $t0, 0xFFFF
    ctx->r9 = ctx->r8 & 0XFFFF;
    // 0x80052498: subu        $v1, $v0, $t1
    ctx->r3 = SUB32(ctx->r2, ctx->r9);
    // 0x8005249C: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x800524A0: bne         $at, $zero, L_800524B0
    if (ctx->r1 != 0) {
        // 0x800524A4: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_800524B0;
    }
    // 0x800524A4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x800524A8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x800524AC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800524B0:
    // 0x800524B0: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x800524B4: beq         $at, $zero, L_800524C0
    if (ctx->r1 == 0) {
        // 0x800524B8: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800524C0;
    }
    // 0x800524B8: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800524BC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800524C0:
    // 0x800524C0: slti        $at, $v1, 0x3001
    ctx->r1 = SIGNED(ctx->r3) < 0X3001 ? 1 : 0;
    // 0x800524C4: bne         $at, $zero, L_800524D4
    if (ctx->r1 != 0) {
        // 0x800524C8: slti        $at, $v1, -0x3000
        ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
            goto L_800524D4;
    }
    // 0x800524C8: slti        $at, $v1, -0x3000
    ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
    // 0x800524CC: addiu       $v1, $zero, 0x3000
    ctx->r3 = ADD32(0, 0X3000);
    // 0x800524D0: slti        $at, $v1, -0x3000
    ctx->r1 = SIGNED(ctx->r3) < -0X3000 ? 1 : 0;
L_800524D4:
    // 0x800524D4: beq         $at, $zero, L_800524E0
    if (ctx->r1 == 0) {
        // 0x800524D8: nop
    
            goto L_800524E0;
    }
    // 0x800524D8: nop

    // 0x800524DC: addiu       $v1, $zero, -0x3000
    ctx->r3 = ADD32(0, -0X3000);
L_800524E0:
    // 0x800524E0: lb          $t2, 0x1E7($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X1E7);
    // 0x800524E4: sh          $v1, 0x16C($a1)
    MEM_H(0X16C, ctx->r5) = ctx->r3;
    // 0x800524E8: andi        $t3, $t2, 0x1F
    ctx->r11 = ctx->r10 & 0X1F;
    // 0x800524EC: slti        $at, $t3, 0xA
    ctx->r1 = SIGNED(ctx->r11) < 0XA ? 1 : 0;
    // 0x800524F0: beq         $at, $zero, L_800524FC
    if (ctx->r1 == 0) {
        // 0x800524F4: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_800524FC;
    }
    // 0x800524F4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800524F8: sh          $zero, 0x16C($a1)
    MEM_H(0X16C, ctx->r5) = 0;
L_800524FC:
    // 0x800524FC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80052500:
    // 0x80052500: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80052504: jr          $ra
    // 0x80052508: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80052508: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void regenerate_point_particles_mesh(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B3E64: addiu       $sp, $sp, -0x90
    ctx->r29 = ADD32(ctx->r29, -0X90);
    // 0x800B3E68: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x800B3E6C: sw          $fp, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r30;
    // 0x800B3E70: sw          $s7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r23;
    // 0x800B3E74: sw          $s6, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r22;
    // 0x800B3E78: sw          $s5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r21;
    // 0x800B3E7C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B3E80: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B3E84: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B3E88: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B3E8C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x800B3E90: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800B3E94: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x800B3E98: lw          $s6, 0x70($a0)
    ctx->r22 = MEM_W(ctx->r4, 0X70);
    // 0x800B3E9C: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800B3EA0: beq         $s6, $zero, L_800B4450
    if (ctx->r22 == 0) {
        // 0x800B3EA4: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_800B4450;
    }
    // 0x800B3EA4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800B3EA8: lw          $t6, 0xC($s6)
    ctx->r14 = MEM_W(ctx->r22, 0XC);
    // 0x800B3EAC: nop

    // 0x800B3EB0: beq         $t6, $zero, L_800B4454
    if (ctx->r14 == 0) {
        // 0x800B3EB4: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800B4454;
    }
    // 0x800B3EB4: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B3EB8: lbu         $v0, 0x6($s6)
    ctx->r2 = MEM_BU(ctx->r22, 0X6);
    // 0x800B3EBC: addiu       $fp, $sp, 0x7C
    ctx->r30 = ADD32(ctx->r29, 0X7C);
    // 0x800B3EC0: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800B3EC4: bltz        $v0, L_800B4450
    if (SIGNED(ctx->r2) < 0) {
        // 0x800B3EC8: sll         $s2, $v0, 2
        ctx->r18 = S32(ctx->r2 << 2);
            goto L_800B4450;
    }
    // 0x800B3EC8: sll         $s2, $v0, 2
    ctx->r18 = S32(ctx->r2 << 2);
    // 0x800B3ECC: mtc1        $zero, $f20
    ctx->f20.u32l = 0;
    // 0x800B3ED0: addiu       $s7, $sp, 0x70
    ctx->r23 = ADD32(ctx->r29, 0X70);
    // 0x800B3ED4: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
L_800B3ED8:
    // 0x800B3ED8: lw          $t7, 0xC($s6)
    ctx->r15 = MEM_W(ctx->r22, 0XC);
    // 0x800B3EDC: or          $a1, $s7, $zero
    ctx->r5 = ctx->r23 | 0;
    // 0x800B3EE0: addu        $t8, $t7, $s2
    ctx->r24 = ADD32(ctx->r15, ctx->r18);
    // 0x800B3EE4: lw          $s0, 0x0($t8)
    ctx->r16 = MEM_W(ctx->r24, 0X0);
    // 0x800B3EE8: nop

    // 0x800B3EEC: lh          $t9, 0x3A($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X3A);
    // 0x800B3EF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3EF4: beq         $t9, $zero, L_800B4454
    if (ctx->r25 == 0) {
        // 0x800B3EF8: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_800B4454;
    }
    // 0x800B3EF8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800B3EFC: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B3F00: lw          $s1, 0x44($s0)
    ctx->r17 = MEM_W(ctx->r16, 0X44);
    // 0x800B3F04: swc1        $f20, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->f20.u32l;
    // 0x800B3F08: swc1        $f20, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->f20.u32l;
    // 0x800B3F0C: jal         0x80070320
    // 0x800B3F10: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_0;
    // 0x800B3F10: swc1        $f4, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800B3F14: swc1        $f20, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f20.u32l;
    // 0x800B3F18: lwc1        $f6, 0x8($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X8);
    // 0x800B3F1C: swc1        $f20, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->f20.u32l;
    // 0x800B3F20: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800B3F24: or          $a1, $fp, $zero
    ctx->r5 = ctx->r30 | 0;
    // 0x800B3F28: jal         0x80070320
    // 0x800B3F2C: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    vec3f_rotate(rdram, ctx);
        goto after_1;
    // 0x800B3F2C: swc1        $f6, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->f6.u32l;
    after_1:
    // 0x800B3F30: lbu         $t1, 0x75($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X75);
    // 0x800B3F34: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B3F38: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x800B3F3C: multu       $t2, $s4
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B3F40: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B3F44: lw          $t0, 0x8($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X8);
    // 0x800B3F48: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B3F4C: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800B3F50: nop

    // 0x800B3F54: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800B3F58: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3F5C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3F60: nop

    // 0x800B3F64: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B3F68: mflo        $t3
    ctx->r11 = lo;
    // 0x800B3F6C: mfc1        $t5, $f18
    ctx->r13 = (int32_t)ctx->f18.u32l;
    // 0x800B3F70: addu        $v1, $t0, $t3
    ctx->r3 = ADD32(ctx->r8, ctx->r11);
    // 0x800B3F74: sh          $t5, 0x28($v1)
    MEM_H(0X28, ctx->r3) = ctx->r13;
    // 0x800B3F78: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800B3F7C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B3F80: lwc1        $f4, 0x74($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B3F84: addiu       $v1, $v1, 0x46
    ctx->r3 = ADD32(ctx->r3, 0X46);
    // 0x800B3F88: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B3F8C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B3F90: nop

    // 0x800B3F94: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B3F98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3F9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3FA0: nop

    // 0x800B3FA4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B3FA8: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800B3FAC: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B3FB0: sh          $t7, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = ctx->r15;
    // 0x800B3FB4: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B3FB8: lwc1        $f16, 0x78($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B3FBC: nop

    // 0x800B3FC0: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B3FC4: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B3FC8: nop

    // 0x800B3FCC: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B3FD0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B3FD4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B3FD8: nop

    // 0x800B3FDC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B3FE0: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800B3FE4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B3FE8: sh          $t9, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r25;
    // 0x800B3FEC: lbu         $t1, 0x6C($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B3FF0: nop

    // 0x800B3FF4: sb          $t1, -0x18($v1)
    MEM_B(-0X18, ctx->r3) = ctx->r9;
    // 0x800B3FF8: lbu         $t2, 0x6D($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B3FFC: nop

    // 0x800B4000: sb          $t2, -0x17($v1)
    MEM_B(-0X17, ctx->r3) = ctx->r10;
    // 0x800B4004: lbu         $t0, 0x6E($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B4008: nop

    // 0x800B400C: sb          $t0, -0x16($v1)
    MEM_B(-0X16, ctx->r3) = ctx->r8;
    // 0x800B4010: lh          $t3, 0x5C($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X5C);
    // 0x800B4014: nop

    // 0x800B4018: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x800B401C: sb          $t4, -0x15($v1)
    MEM_B(-0X15, ctx->r3) = ctx->r12;
    // 0x800B4020: lwc1        $f8, 0x7C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B4024: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B4028: nop

    // 0x800B402C: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800B4030: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800B4034: nop

    // 0x800B4038: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800B403C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4040: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4044: nop

    // 0x800B4048: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B404C: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x800B4050: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800B4054: sh          $t6, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r14;
    // 0x800B4058: lwc1        $f4, 0x80($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B405C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B4060: nop

    // 0x800B4064: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800B4068: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B406C: nop

    // 0x800B4070: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B4074: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4078: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B407C: nop

    // 0x800B4080: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B4084: mfc1        $t8, $f10
    ctx->r24 = (int32_t)ctx->f10.u32l;
    // 0x800B4088: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B408C: sh          $t8, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r24;
    // 0x800B4090: lwc1        $f16, 0x84($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B4094: lwc1        $f18, 0x14($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B4098: nop

    // 0x800B409C: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800B40A0: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B40A4: nop

    // 0x800B40A8: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B40AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B40B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B40B4: nop

    // 0x800B40B8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B40BC: mfc1        $t1, $f6
    ctx->r9 = (int32_t)ctx->f6.u32l;
    // 0x800B40C0: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B40C4: sh          $t1, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r9;
    // 0x800B40C8: lbu         $t2, 0x6C($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B40CC: nop

    // 0x800B40D0: sb          $t2, -0xE($v1)
    MEM_B(-0XE, ctx->r3) = ctx->r10;
    // 0x800B40D4: lbu         $t0, 0x6D($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B40D8: nop

    // 0x800B40DC: sb          $t0, -0xD($v1)
    MEM_B(-0XD, ctx->r3) = ctx->r8;
    // 0x800B40E0: lbu         $t3, 0x6E($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B40E4: nop

    // 0x800B40E8: sb          $t3, -0xC($v1)
    MEM_B(-0XC, ctx->r3) = ctx->r11;
    // 0x800B40EC: lh          $t4, 0x5C($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X5C);
    // 0x800B40F0: nop

    // 0x800B40F4: sra         $t5, $t4, 8
    ctx->r13 = S32(SIGNED(ctx->r12) >> 8);
    // 0x800B40F8: sb          $t5, -0xB($v1)
    MEM_B(-0XB, ctx->r3) = ctx->r13;
    // 0x800B40FC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B4100: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800B4104: nop

    // 0x800B4108: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B410C: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B4110: nop

    // 0x800B4114: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B4118: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B411C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4120: nop

    // 0x800B4124: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B4128: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x800B412C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B4130: sh          $t7, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r15;
    // 0x800B4134: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B4138: lwc1        $f6, 0x74($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X74);
    // 0x800B413C: nop

    // 0x800B4140: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B4144: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800B4148: nop

    // 0x800B414C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800B4150: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4154: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4158: nop

    // 0x800B415C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B4160: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800B4164: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800B4168: sh          $t9, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r25;
    // 0x800B416C: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B4170: lwc1        $f18, 0x78($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800B4174: nop

    // 0x800B4178: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B417C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B4180: nop

    // 0x800B4184: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B4188: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B418C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4190: nop

    // 0x800B4194: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B4198: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x800B419C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B41A0: sh          $t2, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r10;
    // 0x800B41A4: lbu         $t0, 0x6C($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B41A8: nop

    // 0x800B41AC: sb          $t0, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r8;
    // 0x800B41B0: lbu         $t3, 0x6D($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B41B4: nop

    // 0x800B41B8: sb          $t3, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r11;
    // 0x800B41BC: lbu         $t4, 0x6E($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B41C0: nop

    // 0x800B41C4: sb          $t4, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r12;
    // 0x800B41C8: lh          $t5, 0x5C($s0)
    ctx->r13 = MEM_H(ctx->r16, 0X5C);
    // 0x800B41CC: nop

    // 0x800B41D0: sra         $t6, $t5, 8
    ctx->r14 = S32(SIGNED(ctx->r13) >> 8);
    // 0x800B41D4: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800B41D8: lwc1        $f10, 0x7C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800B41DC: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800B41E0: nop

    // 0x800B41E4: sub.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800B41E8: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800B41EC: nop

    // 0x800B41F0: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800B41F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B41F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B41FC: nop

    // 0x800B4200: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800B4204: mfc1        $t8, $f18
    ctx->r24 = (int32_t)ctx->f18.u32l;
    // 0x800B4208: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800B420C: sh          $t8, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r24;
    // 0x800B4210: lwc1        $f6, 0x80($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800B4214: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800B4218: nop

    // 0x800B421C: sub.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800B4220: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800B4224: nop

    // 0x800B4228: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800B422C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4230: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B4234: nop

    // 0x800B4238: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800B423C: mfc1        $t1, $f10
    ctx->r9 = (int32_t)ctx->f10.u32l;
    // 0x800B4240: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800B4244: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x800B4248: lwc1        $f18, 0x84($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X84);
    // 0x800B424C: lwc1        $f16, 0x14($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800B4250: nop

    // 0x800B4254: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800B4258: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800B425C: nop

    // 0x800B4260: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800B4264: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B4268: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B426C: nop

    // 0x800B4270: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800B4274: mfc1        $t0, $f6
    ctx->r8 = (int32_t)ctx->f6.u32l;
    // 0x800B4278: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800B427C: sh          $t0, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r8;
    // 0x800B4280: lbu         $t3, 0x6C($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0X6C);
    // 0x800B4284: nop

    // 0x800B4288: sb          $t3, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r11;
    // 0x800B428C: lbu         $t4, 0x6D($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X6D);
    // 0x800B4290: nop

    // 0x800B4294: sb          $t4, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r12;
    // 0x800B4298: lbu         $t5, 0x6E($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X6E);
    // 0x800B429C: nop

    // 0x800B42A0: sb          $t5, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r13;
    // 0x800B42A4: lh          $t6, 0x5C($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X5C);
    // 0x800B42A8: nop

    // 0x800B42AC: sra         $t7, $t6, 8
    ctx->r15 = S32(SIGNED(ctx->r14) >> 8);
    // 0x800B42B0: sb          $t7, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r15;
    // 0x800B42B4: lbu         $t9, 0x75($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0X75);
    // 0x800B42B8: lw          $t8, 0x8($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X8);
    // 0x800B42BC: sll         $t1, $t9, 3
    ctx->r9 = S32(ctx->r25 << 3);
    // 0x800B42C0: multu       $t1, $s4
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B42C4: mflo        $t2
    ctx->r10 = lo;
    // 0x800B42C8: addu        $a0, $t8, $t2
    ctx->r4 = ADD32(ctx->r24, ctx->r10);
    // 0x800B42CC: beq         $s3, $zero, L_800B42F4
    if (ctx->r19 == 0) {
        // 0x800B42D0: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_800B42F4;
    }
    // 0x800B42D0: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x800B42D4: lbu         $t3, 0x75($s5)
    ctx->r11 = MEM_BU(ctx->r21, 0X75);
    // 0x800B42D8: lw          $t0, 0x8($s3)
    ctx->r8 = MEM_W(ctx->r19, 0X8);
    // 0x800B42DC: sll         $t4, $t3, 3
    ctx->r12 = S32(ctx->r11 << 3);
    // 0x800B42E0: multu       $t4, $s4
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r20)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B42E4: mflo        $t5
    ctx->r13 = lo;
    // 0x800B42E8: addu        $v0, $t0, $t5
    ctx->r2 = ADD32(ctx->r8, ctx->r13);
    // 0x800B42EC: b           L_800B42F8
    // 0x800B42F0: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
        goto L_800B42F8;
    // 0x800B42F0: addiu       $v0, $v0, 0x28
    ctx->r2 = ADD32(ctx->r2, 0X28);
L_800B42F4:
    // 0x800B42F4: addiu       $v0, $a0, 0x28
    ctx->r2 = ADD32(ctx->r4, 0X28);
L_800B42F8:
    // 0x800B42F8: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x800B42FC: addiu       $s2, $s2, -0x4
    ctx->r18 = ADD32(ctx->r18, -0X4);
    // 0x800B4300: sh          $t6, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r14;
    // 0x800B4304: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x800B4308: addiu       $v1, $v1, 0x1E
    ctx->r3 = ADD32(ctx->r3, 0X1E);
    // 0x800B430C: sh          $t7, -0x1C($v1)
    MEM_H(-0X1C, ctx->r3) = ctx->r15;
    // 0x800B4310: lh          $t9, 0x4($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X4);
    // 0x800B4314: addiu       $v0, $v0, 0x1E
    ctx->r2 = ADD32(ctx->r2, 0X1E);
    // 0x800B4318: sh          $t9, -0x1A($v1)
    MEM_H(-0X1A, ctx->r3) = ctx->r25;
    // 0x800B431C: lbu         $t1, -0x18($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0X18);
    // 0x800B4320: or          $s5, $s0, $zero
    ctx->r21 = ctx->r16 | 0;
    // 0x800B4324: sb          $t1, -0x18($v1)
    MEM_B(-0X18, ctx->r3) = ctx->r9;
    // 0x800B4328: lbu         $t8, -0x17($v0)
    ctx->r24 = MEM_BU(ctx->r2, -0X17);
    // 0x800B432C: or          $s3, $s1, $zero
    ctx->r19 = ctx->r17 | 0;
    // 0x800B4330: sb          $t8, -0x17($v1)
    MEM_B(-0X17, ctx->r3) = ctx->r24;
    // 0x800B4334: lbu         $t2, -0x16($v0)
    ctx->r10 = MEM_BU(ctx->r2, -0X16);
    // 0x800B4338: nop

    // 0x800B433C: sb          $t2, -0x16($v1)
    MEM_B(-0X16, ctx->r3) = ctx->r10;
    // 0x800B4340: lbu         $t3, -0x15($v0)
    ctx->r11 = MEM_BU(ctx->r2, -0X15);
    // 0x800B4344: nop

    // 0x800B4348: sb          $t3, -0x15($v1)
    MEM_B(-0X15, ctx->r3) = ctx->r11;
    // 0x800B434C: lh          $t4, -0x14($v0)
    ctx->r12 = MEM_H(ctx->r2, -0X14);
    // 0x800B4350: nop

    // 0x800B4354: sh          $t4, -0x14($v1)
    MEM_H(-0X14, ctx->r3) = ctx->r12;
    // 0x800B4358: lh          $t0, -0x12($v0)
    ctx->r8 = MEM_H(ctx->r2, -0X12);
    // 0x800B435C: nop

    // 0x800B4360: sh          $t0, -0x12($v1)
    MEM_H(-0X12, ctx->r3) = ctx->r8;
    // 0x800B4364: lh          $t5, -0x10($v0)
    ctx->r13 = MEM_H(ctx->r2, -0X10);
    // 0x800B4368: nop

    // 0x800B436C: sh          $t5, -0x10($v1)
    MEM_H(-0X10, ctx->r3) = ctx->r13;
    // 0x800B4370: lbu         $t6, -0xE($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0XE);
    // 0x800B4374: nop

    // 0x800B4378: sb          $t6, -0xE($v1)
    MEM_B(-0XE, ctx->r3) = ctx->r14;
    // 0x800B437C: lbu         $t7, -0xD($v0)
    ctx->r15 = MEM_BU(ctx->r2, -0XD);
    // 0x800B4380: nop

    // 0x800B4384: sb          $t7, -0xD($v1)
    MEM_B(-0XD, ctx->r3) = ctx->r15;
    // 0x800B4388: lbu         $t9, -0xC($v0)
    ctx->r25 = MEM_BU(ctx->r2, -0XC);
    // 0x800B438C: nop

    // 0x800B4390: sb          $t9, -0xC($v1)
    MEM_B(-0XC, ctx->r3) = ctx->r25;
    // 0x800B4394: lbu         $t1, -0xB($v0)
    ctx->r9 = MEM_BU(ctx->r2, -0XB);
    // 0x800B4398: nop

    // 0x800B439C: sb          $t1, -0xB($v1)
    MEM_B(-0XB, ctx->r3) = ctx->r9;
    // 0x800B43A0: lh          $t8, -0xA($v0)
    ctx->r24 = MEM_H(ctx->r2, -0XA);
    // 0x800B43A4: nop

    // 0x800B43A8: sh          $t8, -0xA($v1)
    MEM_H(-0XA, ctx->r3) = ctx->r24;
    // 0x800B43AC: lh          $t2, -0x8($v0)
    ctx->r10 = MEM_H(ctx->r2, -0X8);
    // 0x800B43B0: nop

    // 0x800B43B4: sh          $t2, -0x8($v1)
    MEM_H(-0X8, ctx->r3) = ctx->r10;
    // 0x800B43B8: lh          $t3, -0x6($v0)
    ctx->r11 = MEM_H(ctx->r2, -0X6);
    // 0x800B43BC: nop

    // 0x800B43C0: sh          $t3, -0x6($v1)
    MEM_H(-0X6, ctx->r3) = ctx->r11;
    // 0x800B43C4: lbu         $t4, -0x4($v0)
    ctx->r12 = MEM_BU(ctx->r2, -0X4);
    // 0x800B43C8: nop

    // 0x800B43CC: sb          $t4, -0x4($v1)
    MEM_B(-0X4, ctx->r3) = ctx->r12;
    // 0x800B43D0: lbu         $t0, -0x3($v0)
    ctx->r8 = MEM_BU(ctx->r2, -0X3);
    // 0x800B43D4: nop

    // 0x800B43D8: sb          $t0, -0x3($v1)
    MEM_B(-0X3, ctx->r3) = ctx->r8;
    // 0x800B43DC: lbu         $t5, -0x2($v0)
    ctx->r13 = MEM_BU(ctx->r2, -0X2);
    // 0x800B43E0: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800B43E4: sb          $t5, -0x2($v1)
    MEM_B(-0X2, ctx->r3) = ctx->r13;
    // 0x800B43E8: lbu         $t6, -0x1($v0)
    ctx->r14 = MEM_BU(ctx->r2, -0X1);
    // 0x800B43EC: nop

    // 0x800B43F0: sb          $t6, -0x1($v1)
    MEM_B(-0X1, ctx->r3) = ctx->r14;
    // 0x800B43F4: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800B43F8: nop

    // 0x800B43FC: sh          $t7, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r15;
    // 0x800B4400: lh          $t9, 0x2($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X2);
    // 0x800B4404: nop

    // 0x800B4408: sh          $t9, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r25;
    // 0x800B440C: lh          $t1, 0x4($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X4);
    // 0x800B4410: nop

    // 0x800B4414: sh          $t1, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r9;
    // 0x800B4418: lbu         $t8, 0x6($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X6);
    // 0x800B441C: nop

    // 0x800B4420: sb          $t8, 0x6($v1)
    MEM_B(0X6, ctx->r3) = ctx->r24;
    // 0x800B4424: lbu         $t2, 0x7($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X7);
    // 0x800B4428: nop

    // 0x800B442C: sb          $t2, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r10;
    // 0x800B4430: lbu         $t3, 0x8($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X8);
    // 0x800B4434: nop

    // 0x800B4438: sb          $t3, 0x8($v1)
    MEM_B(0X8, ctx->r3) = ctx->r11;
    // 0x800B443C: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
    // 0x800B4440: nop

    // 0x800B4444: sb          $t4, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r12;
    // 0x800B4448: bgez        $s2, L_800B3ED8
    if (SIGNED(ctx->r18) >= 0) {
        // 0x800B444C: sb          $t0, 0x77($s0)
        MEM_B(0X77, ctx->r16) = ctx->r8;
            goto L_800B3ED8;
    }
    // 0x800B444C: sb          $t0, 0x77($s0)
    MEM_B(0X77, ctx->r16) = ctx->r8;
L_800B4450:
    // 0x800B4450: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_800B4454:
    // 0x800B4454: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800B4458: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800B445C: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B4460: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B4464: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B4468: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B446C: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B4470: lw          $s5, 0x34($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X34);
    // 0x800B4474: lw          $s6, 0x38($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X38);
    // 0x800B4478: lw          $s7, 0x3C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X3C);
    // 0x800B447C: lw          $fp, 0x40($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X40);
    // 0x800B4480: jr          $ra
    // 0x800B4484: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
    return;
    // 0x800B4484: addiu       $sp, $sp, 0x90
    ctx->r29 = ADD32(ctx->r29, 0X90);
;}
RECOMP_FUNC void obj_init_fogchanger(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF18: lbu         $t6, 0x8($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X8);
    // 0x8003CF1C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8003CF20: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8003CF24: bgez        $t6, L_8003CF38
    if (SIGNED(ctx->r14) >= 0) {
        // 0x8003CF28: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_8003CF38;
    }
    // 0x8003CF28: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003CF2C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003CF30: nop

    // 0x8003CF34: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_8003CF38:
    // 0x8003CF38: lui         $at, 0x4100
    ctx->r1 = S32(0X4100 << 16);
    // 0x8003CF3C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8003CF40: nop

    // 0x8003CF44: mul.s       $f0, $f6, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x8003CF48: nop

    // 0x8003CF4C: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003CF50: jr          $ra
    // 0x8003CF54: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
    return;
    // 0x8003CF54: swc1        $f0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->f0.u32l;
;}
RECOMP_FUNC void cutscene_id_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E450: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001E454: jr          $ra
    // 0x8001E458: sh          $a0, -0x5186($at)
    MEM_H(-0X5186, ctx->r1) = ctx->r4;
    return;
    // 0x8001E458: sh          $a0, -0x5186($at)
    MEM_H(-0X5186, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_init_groundzipper(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035AE8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80035AEC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80035AF0: lbu         $t7, 0x9($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X9);
    // 0x80035AF4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80035AF8: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80035AFC: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80035B00: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80035B04: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80035B08: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80035B0C: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80035B10: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80035B14: bc1f        L_80035B24
    if (!c1cs) {
        // 0x80035B18: nop
    
            goto L_80035B24;
    }
    // 0x80035B18: nop

    // 0x80035B1C: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80035B20: nop

L_80035B24:
    // 0x80035B24: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80035B28: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80035B2C: lw          $t8, 0x50($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X50);
    // 0x80035B30: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80035B34: nop

    // 0x80035B38: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80035B3C: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80035B40: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80035B44: nop

    // 0x80035B48: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80035B4C: swc1        $f18, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f18.u32l;
    // 0x80035B50: lbu         $t0, 0xA($a1)
    ctx->r8 = MEM_BU(ctx->r5, 0XA);
    // 0x80035B54: lw          $t3, 0x40($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X40);
    // 0x80035B58: sll         $t1, $t0, 10
    ctx->r9 = S32(ctx->r8 << 10);
    // 0x80035B5C: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x80035B60: lb          $t2, 0x3A($a0)
    ctx->r10 = MEM_B(ctx->r4, 0X3A);
    // 0x80035B64: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x80035B68: nop

    // 0x80035B6C: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80035B70: bne         $at, $zero, L_80035B80
    if (ctx->r1 != 0) {
        // 0x80035B74: lui         $at, 0x41E0
        ctx->r1 = S32(0X41E0 << 16);
            goto L_80035B80;
    }
    // 0x80035B74: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
    // 0x80035B78: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
    // 0x80035B7C: lui         $at, 0x41E0
    ctx->r1 = S32(0X41E0 << 16);
L_80035B80:
    // 0x80035B80: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80035B84: nop

    // 0x80035B88: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80035B8C: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80035B90: nop

    // 0x80035B94: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80035B98: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80035B9C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80035BA0: nop

    // 0x80035BA4: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80035BA8: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x80035BAC: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80035BB0: addiu       $v0, $v0, 0xF
    ctx->r2 = ADD32(ctx->r2, 0XF);
    // 0x80035BB4: bgez        $v0, L_80035BC0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80035BB8: sw          $v0, 0x78($a0)
        MEM_W(0X78, ctx->r4) = ctx->r2;
            goto L_80035BC0;
    }
    // 0x80035BB8: sw          $v0, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r2;
    // 0x80035BBC: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
L_80035BC0:
    // 0x80035BC0: lw          $t6, 0x78($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X78);
    // 0x80035BC4: nop

    // 0x80035BC8: slti        $at, $t6, 0x100
    ctx->r1 = SIGNED(ctx->r14) < 0X100 ? 1 : 0;
    // 0x80035BCC: bne         $at, $zero, L_80035BD8
    if (ctx->r1 != 0) {
        // 0x80035BD0: nop
    
            goto L_80035BD8;
    }
    // 0x80035BD0: nop

    // 0x80035BD4: sw          $t7, 0x78($a0)
    MEM_W(0X78, ctx->r4) = ctx->r15;
L_80035BD8:
    // 0x80035BD8: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80035BDC: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80035BE0: sh          $t8, 0x14($t9)
    MEM_H(0X14, ctx->r25) = ctx->r24;
    // 0x80035BE4: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x80035BE8: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
    // 0x80035BEC: sb          $zero, 0x11($t0)
    MEM_B(0X11, ctx->r8) = 0;
    // 0x80035BF0: lw          $t3, 0x4C($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X4C);
    // 0x80035BF4: addiu       $t4, $zero, -0x64
    ctx->r12 = ADD32(0, -0X64);
    // 0x80035BF8: sb          $t1, 0x10($t3)
    MEM_B(0X10, ctx->r11) = ctx->r9;
    // 0x80035BFC: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C00: addiu       $t6, $zero, 0x64
    ctx->r14 = ADD32(0, 0X64);
    // 0x80035C04: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    // 0x80035C08: lw          $t5, 0x4C($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C0C: nop

    // 0x80035C10: sb          $t4, 0x16($t5)
    MEM_B(0X16, ctx->r13) = ctx->r12;
    // 0x80035C14: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80035C18: nop

    // 0x80035C1C: sb          $t6, 0x17($t7)
    MEM_B(0X17, ctx->r15) = ctx->r14;
    // 0x80035C20: jal         0x8009C30C
    // 0x80035C24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    get_filtered_cheats(rdram, ctx);
        goto after_0;
    // 0x80035C24: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    after_0:
    // 0x80035C28: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x80035C2C: sll         $t8, $v0, 10
    ctx->r24 = S32(ctx->r2 << 10);
    // 0x80035C30: bgez        $t8, L_80035C44
    if (SIGNED(ctx->r24) >= 0) {
        // 0x80035C34: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80035C44;
    }
    // 0x80035C34: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80035C38: jal         0x8000FFB8
    // 0x80035C3C: nop

    free_object(rdram, ctx);
        goto after_1;
    // 0x80035C3C: nop

    after_1:
    // 0x80035C40: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80035C44:
    // 0x80035C44: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80035C48: jr          $ra
    // 0x80035C4C: nop

    return;
    // 0x80035C4C: nop

;}
RECOMP_FUNC void stack_pointer(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B7D10: jr          $ra
    // 0x800B7D14: or          $v0, $sp, $zero
    ctx->r2 = ctx->r29 | 0;
    return;
    // 0x800B7D14: or          $v0, $sp, $zero
    ctx->r2 = ctx->r29 | 0;
;}
RECOMP_FUNC void waves_init_header(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B8134: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800B8138: lw          $v0, -0x5F88($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5F88);
    // 0x800B813C: addiu       $v1, $zero, 0x2
    ctx->r3 = ADD32(0, 0X2);
    // 0x800B8140: beq         $v1, $v0, L_800B815C
    if (ctx->r3 == ctx->r2) {
        // 0x800B8144: lui         $a1, 0x8013
        ctx->r5 = S32(0X8013 << 16);
            goto L_800B815C;
    }
    // 0x800B8144: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B8148: lbu         $t6, 0x56($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X56);
    // 0x800B814C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B8150: addiu       $a1, $a1, -0x6038
    ctx->r5 = ADD32(ctx->r5, -0X6038);
    // 0x800B8154: b           L_800B8168
    // 0x800B8158: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
        goto L_800B8168;
    // 0x800B8158: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
L_800B815C:
    // 0x800B815C: addiu       $a1, $a1, -0x6038
    ctx->r5 = ADD32(ctx->r5, -0X6038);
    // 0x800B8160: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x800B8164: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_800B8168:
    // 0x800B8168: lbu         $t8, 0x57($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X57);
    // 0x800B816C: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800B8170: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x800B8174: lbu         $t9, 0x58($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X58);
    // 0x800B8178: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B817C: sw          $t9, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->r25;
    // 0x800B8180: lh          $t0, 0x5A($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X5A);
    // 0x800B8184: addiu       $at, $zero, -0x2
    ctx->r1 = ADD32(0, -0X2);
    // 0x800B8188: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B818C: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800B8190: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8194: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B8198: swc1        $f8, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f8.u32l;
    // 0x800B819C: lbu         $t1, 0x59($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X59);
    // 0x800B81A0: nop

    // 0x800B81A4: sll         $t2, $t1, 8
    ctx->r10 = S32(ctx->r9 << 8);
    // 0x800B81A8: sw          $t2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->r10;
    // 0x800B81AC: lbu         $t3, 0x5C($a0)
    ctx->r11 = MEM_BU(ctx->r4, 0X5C);
    // 0x800B81B0: nop

    // 0x800B81B4: sw          $t3, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->r11;
    // 0x800B81B8: lh          $t4, 0x5E($a0)
    ctx->r12 = MEM_H(ctx->r4, 0X5E);
    // 0x800B81BC: nop

    // 0x800B81C0: mtc1        $t4, $f10
    ctx->f10.u32l = ctx->r12;
    // 0x800B81C4: nop

    // 0x800B81C8: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B81CC: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B81D0: swc1        $f18, 0x18($a1)
    MEM_W(0X18, ctx->r5) = ctx->f18.u32l;
    // 0x800B81D4: lbu         $t5, 0x5D($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X5D);
    // 0x800B81D8: nop

    // 0x800B81DC: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800B81E0: sw          $t6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->r14;
    // 0x800B81E4: lh          $t7, 0x60($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X60);
    // 0x800B81E8: nop

    // 0x800B81EC: and         $t8, $t7, $at
    ctx->r24 = ctx->r15 & ctx->r1;
    // 0x800B81F0: beq         $v1, $v0, L_800B8204
    if (ctx->r3 == ctx->r2) {
        // 0x800B81F4: sw          $t8, 0x20($a1)
        MEM_W(0X20, ctx->r5) = ctx->r24;
            goto L_800B8204;
    }
    // 0x800B81F4: sw          $t8, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->r24;
    // 0x800B81F8: lh          $t9, 0x6E($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X6E);
    // 0x800B81FC: b           L_800B8208
    // 0x800B8200: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
        goto L_800B8208;
    // 0x800B8200: sw          $t9, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r25;
L_800B8204:
    // 0x800B8204: sw          $t0, 0x24($a1)
    MEM_W(0X24, ctx->r5) = ctx->r8;
L_800B8208:
    // 0x800B8208: lbu         $t1, 0x71($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X71);
    // 0x800B820C: nop

    // 0x800B8210: sw          $t1, 0x28($a1)
    MEM_W(0X28, ctx->r5) = ctx->r9;
    // 0x800B8214: lh          $t2, 0x68($a0)
    ctx->r10 = MEM_H(ctx->r4, 0X68);
    // 0x800B8218: nop

    // 0x800B821C: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x800B8220: sw          $t3, 0x2C($a1)
    MEM_W(0X2C, ctx->r5) = ctx->r11;
    // 0x800B8224: lbu         $t4, 0x6A($a0)
    ctx->r12 = MEM_BU(ctx->r4, 0X6A);
    // 0x800B8228: nop

    // 0x800B822C: sw          $t4, 0x30($a1)
    MEM_W(0X30, ctx->r5) = ctx->r12;
    // 0x800B8230: lbu         $t5, 0x6B($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X6B);
    // 0x800B8234: nop

    // 0x800B8238: sw          $t5, 0x34($a1)
    MEM_W(0X34, ctx->r5) = ctx->r13;
    // 0x800B823C: lb          $t6, 0x6C($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X6C);
    // 0x800B8240: nop

    // 0x800B8244: sw          $t6, 0x38($a1)
    MEM_W(0X38, ctx->r5) = ctx->r14;
    // 0x800B8248: lb          $t7, 0x6D($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X6D);
    // 0x800B824C: nop

    // 0x800B8250: sw          $t7, 0x3C($a1)
    MEM_W(0X3C, ctx->r5) = ctx->r15;
    // 0x800B8254: lh          $t8, 0x62($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X62);
    // 0x800B8258: nop

    // 0x800B825C: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800B8260: nop

    // 0x800B8264: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B8268: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B826C: swc1        $f8, 0x40($a1)
    MEM_W(0X40, ctx->r5) = ctx->f8.u32l;
    // 0x800B8270: lh          $t9, 0x64($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X64);
    // 0x800B8274: nop

    // 0x800B8278: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800B827C: nop

    // 0x800B8280: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B8284: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x800B8288: swc1        $f18, 0x44($a1)
    MEM_W(0X44, ctx->r5) = ctx->f18.u32l;
    // 0x800B828C: lh          $t0, 0x66($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X66);
    // 0x800B8290: nop

    // 0x800B8294: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B8298: nop

    // 0x800B829C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B82A0: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B82A4: swc1        $f8, 0x48($a1)
    MEM_W(0X48, ctx->r5) = ctx->f8.u32l;
    // 0x800B82A8: lbu         $t1, 0x70($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X70);
    // 0x800B82AC: jr          $ra
    // 0x800B82B0: sw          $t1, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = ctx->r9;
    return;
    // 0x800B82B0: sw          $t1, 0x4C($a1)
    MEM_W(0X4C, ctx->r5) = ctx->r9;
;}
RECOMP_FUNC void menu_timestamp_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80081800: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x80081804: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081808: lbu         $t7, 0x73($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X73);
    // 0x8008180C: sb          $a3, -0xB5C($at)
    MEM_B(-0XB5C, ctx->r1) = ctx->r7;
    // 0x80081810: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081814: lbu         $t8, 0x77($sp)
    ctx->r24 = MEM_BU(ctx->r29, 0X77);
    // 0x80081818: lbu         $t9, 0x7B($sp)
    ctx->r25 = MEM_BU(ctx->r29, 0X7B);
    // 0x8008181C: sb          $t7, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r15;
    // 0x80081820: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80081824: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081828: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8008182C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x80081830: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x80081834: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x80081838: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008183C: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80081840: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80081844: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80081848: sw          $a3, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r7;
    // 0x8008184C: bne         $t9, $zero, L_800818A4
    if (ctx->r25 != 0) {
        // 0x80081850: sb          $t8, -0xB54($at)
        MEM_B(-0XB54, ctx->r1) = ctx->r24;
            goto L_800818A4;
    }
    // 0x80081850: sb          $t8, -0xB54($at)
    MEM_B(-0XB54, ctx->r1) = ctx->r24;
    // 0x80081854: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x80081858: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x8008185C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081860: addiu       $s2, $s2, -0x8A4
    ctx->r18 = ADD32(ctx->r18, -0X8A4);
    // 0x80081864: addiu       $t1, $a2, -0x2
    ctx->r9 = ADD32(ctx->r6, -0X2);
    // 0x80081868: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x8008186C: mtc1        $t1, $f8
    ctx->f8.u32l = ctx->r9;
    // 0x80081870: swc1        $f6, 0x10($t0)
    MEM_W(0X10, ctx->r8) = ctx->f6.u32l;
    // 0x80081874: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081878: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x8008187C: addiu       $t3, $zero, 0xB
    ctx->r11 = ADD32(0, 0XB);
    // 0x80081880: addiu       $t4, $zero, 0xA
    ctx->r12 = ADD32(0, 0XA);
    // 0x80081884: swc1        $f10, 0x30($t2)
    MEM_W(0X30, ctx->r10) = ctx->f10.u32l;
    // 0x80081888: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008188C: addiu       $s5, $zero, 0x1
    ctx->r21 = ADD32(0, 0X1);
    // 0x80081890: addiu       $s0, $a1, -0x27
    ctx->r16 = ADD32(ctx->r5, -0X27);
    // 0x80081894: addiu       $s6, $zero, 0xC
    ctx->r22 = ADD32(0, 0XC);
    // 0x80081898: sw          $t3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r11;
    // 0x8008189C: b           L_800818F0
    // 0x800818A0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
        goto L_800818F0;
    // 0x800818A0: sw          $t4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r12;
L_800818A4:
    // 0x800818A4: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800818A8: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x800818AC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800818B0: addiu       $s2, $s2, -0x8A4
    ctx->r18 = ADD32(ctx->r18, -0X8A4);
    // 0x800818B4: addiu       $t6, $a2, -0x1
    ctx->r14 = ADD32(ctx->r6, -0X1);
    // 0x800818B8: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x800818BC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x800818C0: swc1        $f18, 0x50($t5)
    MEM_W(0X50, ctx->r13) = ctx->f18.u32l;
    // 0x800818C4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800818C8: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800818CC: addiu       $t8, $zero, 0x9
    ctx->r24 = ADD32(0, 0X9);
    // 0x800818D0: swc1        $f6, 0x70($t7)
    MEM_W(0X70, ctx->r15) = ctx->f6.u32l;
    // 0x800818D4: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x800818D8: addiu       $s3, $zero, 0x2
    ctx->r19 = ADD32(0, 0X2);
    // 0x800818DC: addiu       $s5, $zero, 0x3
    ctx->r21 = ADD32(0, 0X3);
    // 0x800818E0: addiu       $s0, $s0, -0x1C
    ctx->r16 = ADD32(ctx->r16, -0X1C);
    // 0x800818E4: addiu       $s6, $zero, 0x9
    ctx->r22 = ADD32(0, 0X9);
    // 0x800818E8: sw          $t8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r24;
    // 0x800818EC: sw          $t9, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r25;
L_800818F0:
    // 0x800818F0: addiu       $a1, $sp, 0x5C
    ctx->r5 = ADD32(ctx->r29, 0X5C);
    // 0x800818F4: addiu       $a2, $sp, 0x58
    ctx->r6 = ADD32(ctx->r29, 0X58);
    // 0x800818F8: jal         0x80059790
    // 0x800818FC: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    get_timestamp_from_frames(rdram, ctx);
        goto after_0;
    // 0x800818FC: addiu       $a3, $sp, 0x54
    ctx->r7 = ADD32(ctx->r29, 0X54);
    after_0:
    // 0x80081900: jal         0x80068508
    // 0x80081904: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x80081904: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x80081908: jal         0x8007BF1C
    // 0x8008190C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_2;
    // 0x8008190C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x80081910: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x80081914: addiu       $s4, $zero, 0xA
    ctx->r20 = ADD32(0, 0XA);
    // 0x80081918: div         $zero, $t0, $s4
    lo = S32(S64(S32(ctx->r8)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r8)) % S64(S32(ctx->r20)));
    // 0x8008191C: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80081920: sll         $s1, $s3, 5
    ctx->r17 = S32(ctx->r19 << 5);
    // 0x80081924: addu        $t3, $t2, $s1
    ctx->r11 = ADD32(ctx->r10, ctx->r17);
    // 0x80081928: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x8008192C: bne         $s4, $zero, L_80081938
    if (ctx->r20 != 0) {
        // 0x80081930: nop
    
            goto L_80081938;
    }
    // 0x80081930: nop

    // 0x80081934: break       7
    do_break(2148014388);
L_80081938:
    // 0x80081938: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008193C: bne         $s4, $at, L_80081950
    if (ctx->r20 != ctx->r1) {
        // 0x80081940: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081950;
    }
    // 0x80081940: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081944: bne         $t0, $at, L_80081950
    if (ctx->r8 != ctx->r1) {
        // 0x80081948: nop
    
            goto L_80081950;
    }
    // 0x80081948: nop

    // 0x8008194C: break       6
    do_break(2148014412);
L_80081950:
    // 0x80081950: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081954: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081958: mflo        $t1
    ctx->r9 = lo;
    // 0x8008195C: sh          $t1, 0x18($t3)
    MEM_H(0X18, ctx->r11) = ctx->r9;
    // 0x80081960: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80081964: nop

    // 0x80081968: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x8008196C: jal         0x8009CA60
    // 0x80081970: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_3;
    // 0x80081970: swc1        $f10, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f10.u32l;
    after_3:
    // 0x80081974: lw          $t6, 0x5C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X5C);
    // 0x80081978: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8008197C: div         $zero, $t6, $s4
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r20)));
    // 0x80081980: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80081984: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x80081988: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x8008198C: bne         $s4, $zero, L_80081998
    if (ctx->r20 != 0) {
        // 0x80081990: nop
    
            goto L_80081998;
    }
    // 0x80081990: nop

    // 0x80081994: break       7
    do_break(2148014484);
L_80081998:
    // 0x80081998: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008199C: bne         $s4, $at, L_800819B0
    if (ctx->r20 != ctx->r1) {
        // 0x800819A0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800819B0;
    }
    // 0x800819A0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800819A4: bne         $t6, $at, L_800819B0
    if (ctx->r14 != ctx->r1) {
        // 0x800819A8: nop
    
            goto L_800819B0;
    }
    // 0x800819A8: nop

    // 0x800819AC: break       6
    do_break(2148014508);
L_800819B0:
    // 0x800819B0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800819B4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800819B8: mfhi        $t7
    ctx->r15 = hi;
    // 0x800819BC: sh          $t7, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r15;
    // 0x800819C0: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800819C4: nop

    // 0x800819C8: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x800819CC: jal         0x8009CA60
    // 0x800819D0: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_4;
    // 0x800819D0: swc1        $f18, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f18.u32l;
    after_4:
    // 0x800819D4: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x800819D8: lw          $t3, 0x0($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X0);
    // 0x800819DC: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x800819E0: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x800819E4: sll         $v0, $s5, 5
    ctx->r2 = S32(ctx->r21 << 5);
    // 0x800819E8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800819EC: addu        $t4, $t3, $v0
    ctx->r12 = ADD32(ctx->r11, ctx->r2);
    // 0x800819F0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x800819F4: swc1        $f6, 0xC($t4)
    MEM_W(0XC, ctx->r12) = ctx->f6.u32l;
    // 0x800819F8: jal         0x8009CA60
    // 0x800819FC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    menu_element_render(rdram, ctx);
        goto after_5;
    // 0x800819FC: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    after_5:
    // 0x80081A00: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x80081A04: lw          $t5, 0x40($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X40);
    // 0x80081A08: div         $zero, $t6, $s4
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r20)));
    // 0x80081A0C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80081A10: addu        $s0, $s0, $t5
    ctx->r16 = ADD32(ctx->r16, ctx->r13);
    // 0x80081A14: addu        $t9, $t7, $s1
    ctx->r25 = ADD32(ctx->r15, ctx->r17);
    // 0x80081A18: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80081A1C: bne         $s4, $zero, L_80081A28
    if (ctx->r20 != 0) {
        // 0x80081A20: nop
    
            goto L_80081A28;
    }
    // 0x80081A20: nop

    // 0x80081A24: break       7
    do_break(2148014628);
L_80081A28:
    // 0x80081A28: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081A2C: bne         $s4, $at, L_80081A40
    if (ctx->r20 != ctx->r1) {
        // 0x80081A30: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081A40;
    }
    // 0x80081A30: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081A34: bne         $t6, $at, L_80081A40
    if (ctx->r14 != ctx->r1) {
        // 0x80081A38: nop
    
            goto L_80081A40;
    }
    // 0x80081A38: nop

    // 0x80081A3C: break       6
    do_break(2148014652);
L_80081A40:
    // 0x80081A40: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081A44: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081A48: mflo        $t8
    ctx->r24 = lo;
    // 0x80081A4C: sh          $t8, 0x18($t9)
    MEM_H(0X18, ctx->r25) = ctx->r24;
    // 0x80081A50: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x80081A54: nop

    // 0x80081A58: addu        $t2, $t0, $s1
    ctx->r10 = ADD32(ctx->r8, ctx->r17);
    // 0x80081A5C: jal         0x8009CA60
    // 0x80081A60: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_6;
    // 0x80081A60: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    after_6:
    // 0x80081A64: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x80081A68: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80081A6C: div         $zero, $t1, $s4
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r20)));
    // 0x80081A70: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80081A74: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80081A78: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80081A7C: bne         $s4, $zero, L_80081A88
    if (ctx->r20 != 0) {
        // 0x80081A80: nop
    
            goto L_80081A88;
    }
    // 0x80081A80: nop

    // 0x80081A84: break       7
    do_break(2148014724);
L_80081A88:
    // 0x80081A88: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081A8C: bne         $s4, $at, L_80081AA0
    if (ctx->r20 != ctx->r1) {
        // 0x80081A90: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081AA0;
    }
    // 0x80081A90: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081A94: bne         $t1, $at, L_80081AA0
    if (ctx->r9 != ctx->r1) {
        // 0x80081A98: nop
    
            goto L_80081AA0;
    }
    // 0x80081A98: nop

    // 0x80081A9C: break       6
    do_break(2148014748);
L_80081AA0:
    // 0x80081AA0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80081AA4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081AA8: mfhi        $t3
    ctx->r11 = hi;
    // 0x80081AAC: sh          $t3, 0x18($t5)
    MEM_H(0X18, ctx->r13) = ctx->r11;
    // 0x80081AB0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x80081AB4: nop

    // 0x80081AB8: addu        $t7, $t6, $s1
    ctx->r15 = ADD32(ctx->r14, ctx->r17);
    // 0x80081ABC: jal         0x8009CA60
    // 0x80081AC0: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_7;
    // 0x80081AC0: swc1        $f18, 0xC($t7)
    MEM_W(0XC, ctx->r15) = ctx->f18.u32l;
    after_7:
    // 0x80081AC4: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80081AC8: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80081ACC: addu        $s0, $s0, $t8
    ctx->r16 = ADD32(ctx->r16, ctx->r24);
    // 0x80081AD0: mtc1        $s0, $f4
    ctx->f4.u32l = ctx->r16;
    // 0x80081AD4: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80081AD8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80081ADC: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80081AE0: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    // 0x80081AE4: jal         0x8009CA60
    // 0x80081AE8: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    menu_element_render(rdram, ctx);
        goto after_8;
    // 0x80081AE8: swc1        $f6, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f6.u32l;
    after_8:
    // 0x80081AEC: lw          $t4, 0x54($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X54);
    // 0x80081AF0: lw          $t1, 0x40($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X40);
    // 0x80081AF4: div         $zero, $t4, $s4
    lo = S32(S64(S32(ctx->r12)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r12)) % S64(S32(ctx->r20)));
    // 0x80081AF8: lw          $t5, 0x0($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X0);
    // 0x80081AFC: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
    // 0x80081B00: addu        $t6, $t5, $s1
    ctx->r14 = ADD32(ctx->r13, ctx->r17);
    // 0x80081B04: mtc1        $s0, $f8
    ctx->f8.u32l = ctx->r16;
    // 0x80081B08: bne         $s4, $zero, L_80081B14
    if (ctx->r20 != 0) {
        // 0x80081B0C: nop
    
            goto L_80081B14;
    }
    // 0x80081B0C: nop

    // 0x80081B10: break       7
    do_break(2148014864);
L_80081B14:
    // 0x80081B14: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081B18: bne         $s4, $at, L_80081B2C
    if (ctx->r20 != ctx->r1) {
        // 0x80081B1C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081B2C;
    }
    // 0x80081B1C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081B20: bne         $t4, $at, L_80081B2C
    if (ctx->r12 != ctx->r1) {
        // 0x80081B24: nop
    
            goto L_80081B2C;
    }
    // 0x80081B24: nop

    // 0x80081B28: break       6
    do_break(2148014888);
L_80081B2C:
    // 0x80081B2C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80081B30: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081B34: mflo        $t3
    ctx->r11 = lo;
    // 0x80081B38: sh          $t3, 0x18($t6)
    MEM_H(0X18, ctx->r14) = ctx->r11;
    // 0x80081B3C: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x80081B40: nop

    // 0x80081B44: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x80081B48: jal         0x8009CA60
    // 0x80081B4C: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    menu_element_render(rdram, ctx);
        goto after_9;
    // 0x80081B4C: swc1        $f10, 0xC($t8)
    MEM_W(0XC, ctx->r24) = ctx->f10.u32l;
    after_9:
    // 0x80081B50: lw          $t9, 0x54($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X54);
    // 0x80081B54: lw          $t2, 0x0($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X0);
    // 0x80081B58: div         $zero, $t9, $s4
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r20))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r20)));
    // 0x80081B5C: addu        $s0, $s0, $s6
    ctx->r16 = ADD32(ctx->r16, ctx->r22);
    // 0x80081B60: addu        $t1, $t2, $s1
    ctx->r9 = ADD32(ctx->r10, ctx->r17);
    // 0x80081B64: mtc1        $s0, $f16
    ctx->f16.u32l = ctx->r16;
    // 0x80081B68: bne         $s4, $zero, L_80081B74
    if (ctx->r20 != 0) {
        // 0x80081B6C: nop
    
            goto L_80081B74;
    }
    // 0x80081B6C: nop

    // 0x80081B70: break       7
    do_break(2148014960);
L_80081B74:
    // 0x80081B74: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80081B78: bne         $s4, $at, L_80081B8C
    if (ctx->r20 != ctx->r1) {
        // 0x80081B7C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_80081B8C;
    }
    // 0x80081B7C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80081B80: bne         $t9, $at, L_80081B8C
    if (ctx->r25 != ctx->r1) {
        // 0x80081B84: nop
    
            goto L_80081B8C;
    }
    // 0x80081B84: nop

    // 0x80081B88: break       6
    do_break(2148014984);
L_80081B8C:
    // 0x80081B8C: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x80081B90: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80081B94: mfhi        $t0
    ctx->r8 = hi;
    // 0x80081B98: sh          $t0, 0x18($t1)
    MEM_H(0X18, ctx->r9) = ctx->r8;
    // 0x80081B9C: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x80081BA0: nop

    // 0x80081BA4: addu        $t5, $t4, $s1
    ctx->r13 = ADD32(ctx->r12, ctx->r17);
    // 0x80081BA8: jal         0x8009CA60
    // 0x80081BAC: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_10;
    // 0x80081BAC: swc1        $f18, 0xC($t5)
    MEM_W(0XC, ctx->r13) = ctx->f18.u32l;
    after_10:
    // 0x80081BB0: jal         0x80068508
    // 0x80081BB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_11;
    // 0x80081BB4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x80081BB8: jal         0x8007BF1C
    // 0x80081BBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_12;
    // 0x80081BBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_12:
    // 0x80081BC0: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x80081BC4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081BC8: sb          $v0, -0xB5C($at)
    MEM_B(-0XB5C, ctx->r1) = ctx->r2;
    // 0x80081BCC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081BD0: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80081BD4: sb          $v0, -0xB58($at)
    MEM_B(-0XB58, ctx->r1) = ctx->r2;
    // 0x80081BD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80081BDC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80081BE0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80081BE4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80081BE8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80081BEC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80081BF0: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x80081BF4: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x80081BF8: sb          $v0, -0xB54($at)
    MEM_B(-0XB54, ctx->r1) = ctx->r2;
    // 0x80081BFC: jr          $ra
    // 0x80081C00: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x80081C00: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void race_finish_time_trial(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001AE64: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8001AE68: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8001AE6C: jal         0x8006BDB0
    // 0x8001AE70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    level_header(rdram, ctx);
        goto after_0;
    // 0x8001AE70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8001AE74: jal         0x8006EA90
    // 0x8001AE78: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_1;
    // 0x8001AE78: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_1:
    // 0x8001AE7C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8001AE80: sb          $zero, 0x114($v0)
    MEM_B(0X114, ctx->r2) = 0;
    // 0x8001AE84: sb          $zero, 0x116($v0)
    MEM_B(0X116, ctx->r2) = 0;
    // 0x8001AE88: sb          $zero, 0x115($v0)
    MEM_B(0X115, ctx->r2) = 0;
    // 0x8001AE8C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001AE90: lw          $t6, -0x5118($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5118);
    // 0x8001AE94: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8001AE98: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001AE9C: lw          $t9, -0x5110($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5110);
    // 0x8001AEA0: lw          $t8, 0x64($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X64);
    // 0x8001AEA4: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x8001AEA8: ori         $s0, $zero, 0x8CA1
    ctx->r16 = 0 | 0X8CA1;
    // 0x8001AEAC: ori         $t1, $zero, 0x8CA1
    ctx->r9 = 0 | 0X8CA1;
    // 0x8001AEB0: or          $t5, $zero, $zero
    ctx->r13 = 0 | 0;
    // 0x8001AEB4: blez        $t9, L_8001B020
    if (SIGNED(ctx->r25) <= 0) {
        // 0x8001AEB8: sw          $t8, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r24;
            goto L_8001B020;
    }
    // 0x8001AEB8: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
    // 0x8001AEBC: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8001AEC0:
    // 0x8001AEC0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001AEC4: lw          $t6, -0x5118($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5118);
    // 0x8001AEC8: nop

    // 0x8001AECC: addu        $t7, $t6, $t4
    ctx->r15 = ADD32(ctx->r14, ctx->r12);
    // 0x8001AED0: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8001AED4: nop

    // 0x8001AED8: lw          $a3, 0x64($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X64);
    // 0x8001AEDC: nop

    // 0x8001AEE0: lb          $t9, 0x2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X2);
    // 0x8001AEE4: nop

    // 0x8001AEE8: bltz        $t9, L_8001B008
    if (SIGNED(ctx->r25) < 0) {
        // 0x8001AEEC: nop
    
            goto L_8001B008;
    }
    // 0x8001AEEC: nop

    // 0x8001AEF0: sw          $a3, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r7;
    // 0x8001AEF4: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x8001AEF8: sw          $t1, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r9;
    // 0x8001AEFC: sw          $t2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r10;
    // 0x8001AF00: sw          $t4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r12;
    // 0x8001AF04: jal         0x8009C3C8
    // 0x8001AF08: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    get_number_of_active_players(rdram, ctx);
        goto after_2;
    // 0x8001AF08: sw          $t5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r13;
    after_2:
    // 0x8001AF0C: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x8001AF10: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001AF14: lb          $v1, 0x2($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X2);
    // 0x8001AF18: lw          $t1, 0x50($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X50);
    // 0x8001AF1C: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x8001AF20: lw          $t4, 0x24($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X24);
    // 0x8001AF24: lw          $t5, 0x4C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X4C);
    // 0x8001AF28: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001AF2C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001AF30: beq         $at, $zero, L_8001B008
    if (ctx->r1 == 0) {
        // 0x8001AF34: addiu       $ra, $zero, 0x18
        ctx->r31 = ADD32(0, 0X18);
            goto L_8001B008;
    }
    // 0x8001AF34: addiu       $ra, $zero, 0x18
    ctx->r31 = ADD32(0, 0X18);
    // 0x8001AF38: multu       $v1, $ra
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AF3C: mflo        $t6
    ctx->r14 = lo;
    // 0x8001AF40: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8001AF44: sb          $zero, 0x58($t7)
    MEM_B(0X58, ctx->r15) = 0;
    // 0x8001AF48: lb          $v0, 0x1D7($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X1D7);
    // 0x8001AF4C: nop

    // 0x8001AF50: bltz        $v0, L_8001B008
    if (SIGNED(ctx->r2) < 0) {
        // 0x8001AF54: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_8001B008;
    }
    // 0x8001AF54: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001AF58: beq         $at, $zero, L_8001B008
    if (ctx->r1 == 0) {
        // 0x8001AF5C: nop
    
            goto L_8001B008;
    }
    // 0x8001AF5C: nop

    // 0x8001AF60: lb          $t8, 0x4B($t2)
    ctx->r24 = MEM_B(ctx->r10, 0X4B);
    // 0x8001AF64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8001AF68: blez        $t8, L_8001AFDC
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8001AF6C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8001AFDC;
    }
    // 0x8001AF6C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8001AF70: sll         $t9, $a0, 2
    ctx->r25 = S32(ctx->r4 << 2);
    // 0x8001AF74: addu        $v0, $a3, $t9
    ctx->r2 = ADD32(ctx->r7, ctx->r25);
    // 0x8001AF78: sll         $a1, $a0, 1
    ctx->r5 = S32(ctx->r4 << 1);
L_8001AF7C:
    // 0x8001AF7C: lb          $t7, 0x2($a3)
    ctx->r15 = MEM_B(ctx->r7, 0X2);
    // 0x8001AF80: lw          $t6, 0x128($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X128);
    // 0x8001AF84: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8001AF88: subu        $t8, $t8, $t7
    ctx->r24 = SUB32(ctx->r24, ctx->r15);
    // 0x8001AF8C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8001AF90: addu        $t9, $t0, $t8
    ctx->r25 = ADD32(ctx->r8, ctx->r24);
    // 0x8001AF94: addu        $t7, $t9, $a1
    ctx->r15 = ADD32(ctx->r25, ctx->r5);
    // 0x8001AF98: sh          $t6, 0x66($t7)
    MEM_H(0X66, ctx->r15) = ctx->r14;
    // 0x8001AF9C: lw          $v1, 0x128($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X128);
    // 0x8001AFA0: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x8001AFA4: slt         $at, $v1, $t1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001AFA8: beq         $at, $zero, L_8001AFC0
    if (ctx->r1 == 0) {
        // 0x8001AFAC: addu        $a2, $a2, $v1
        ctx->r6 = ADD32(ctx->r6, ctx->r3);
            goto L_8001AFC0;
    }
    // 0x8001AFAC: addu        $a2, $a2, $v1
    ctx->r6 = ADD32(ctx->r6, ctx->r3);
    // 0x8001AFB0: sb          $a0, 0x116($t0)
    MEM_B(0X116, ctx->r8) = ctx->r4;
    // 0x8001AFB4: lb          $t8, 0x2($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X2);
    // 0x8001AFB8: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x8001AFBC: sb          $t8, 0x115($t0)
    MEM_B(0X115, ctx->r8) = ctx->r24;
L_8001AFC0:
    // 0x8001AFC0: lb          $t9, 0x4B($t2)
    ctx->r25 = MEM_B(ctx->r10, 0X4B);
    // 0x8001AFC4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8001AFC8: slt         $at, $a0, $t9
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001AFCC: beq         $at, $zero, L_8001AFDC
    if (ctx->r1 == 0) {
        // 0x8001AFD0: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8001AFDC;
    }
    // 0x8001AFD0: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001AFD4: bne         $a0, $t3, L_8001AF7C
    if (ctx->r4 != ctx->r11) {
        // 0x8001AFD8: nop
    
            goto L_8001AF7C;
    }
    // 0x8001AFD8: nop

L_8001AFDC:
    // 0x8001AFDC: lb          $t6, 0x2($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X2);
    // 0x8001AFE0: slt         $at, $a2, $s0
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8001AFE4: multu       $t6, $ra
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001AFE8: mflo        $t7
    ctx->r15 = lo;
    // 0x8001AFEC: addu        $t8, $t0, $t7
    ctx->r24 = ADD32(ctx->r8, ctx->r15);
    // 0x8001AFF0: beq         $at, $zero, L_8001B008
    if (ctx->r1 == 0) {
        // 0x8001AFF4: sh          $a2, 0x64($t8)
        MEM_H(0X64, ctx->r24) = ctx->r6;
            goto L_8001B008;
    }
    // 0x8001AFF4: sh          $a2, 0x64($t8)
    MEM_H(0X64, ctx->r24) = ctx->r6;
    // 0x8001AFF8: lb          $t9, 0x2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X2);
    // 0x8001AFFC: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x8001B000: sb          $t9, 0x114($t0)
    MEM_B(0X114, ctx->r8) = ctx->r25;
    // 0x8001B004: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
L_8001B008:
    // 0x8001B008: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B00C: lw          $t6, -0x5110($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5110);
    // 0x8001B010: addiu       $t5, $t5, 0x1
    ctx->r13 = ADD32(ctx->r13, 0X1);
    // 0x8001B014: slt         $at, $t5, $t6
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8001B018: bne         $at, $zero, L_8001AEC0
    if (ctx->r1 != 0) {
        // 0x8001B01C: addiu       $t4, $t4, 0x4
        ctx->r12 = ADD32(ctx->r12, 0X4);
            goto L_8001AEC0;
    }
    // 0x8001B01C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
L_8001B020:
    // 0x8001B020: sb          $zero, 0x117($t0)
    MEM_B(0X117, ctx->r8) = 0;
    // 0x8001B024: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8001B028: lbu         $t7, -0x510B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X510B);
    // 0x8001B02C: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001B030: beq         $t7, $zero, L_8001B278
    if (ctx->r15 == 0) {
        // 0x8001B034: addiu       $ra, $zero, 0x18
        ctx->r31 = ADD32(0, 0X18);
            goto L_8001B278;
    }
    // 0x8001B034: addiu       $ra, $zero, 0x18
    ctx->r31 = ADD32(0, 0X18);
    // 0x8001B038: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001B03C: lh          $v0, -0x517E($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X517E);
    // 0x8001B040: nop

    // 0x8001B044: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8001B048: beq         $at, $zero, L_8001B058
    if (ctx->r1 == 0) {
        // 0x8001B04C: nop
    
            goto L_8001B058;
    }
    // 0x8001B04C: nop

    // 0x8001B050: bgez        $v0, L_8001B05C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8001B054: nop
    
            goto L_8001B05C;
    }
    // 0x8001B054: nop

L_8001B058:
    // 0x8001B058: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001B05C:
    // 0x8001B05C: lb          $t9, 0x115($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X115);
    // 0x8001B060: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8001B064: bne         $t9, $zero, L_8001B0C8
    if (ctx->r25 != 0) {
        // 0x8001B068: sb          $t8, 0x117($t0)
        MEM_B(0X117, ctx->r8) = ctx->r24;
            goto L_8001B0C8;
    }
    // 0x8001B068: sb          $t8, 0x117($t0)
    MEM_B(0X117, ctx->r8) = ctx->r24;
    // 0x8001B06C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001B070: lbu         $t9, 0x49($t0)
    ctx->r25 = MEM_BU(ctx->r8, 0X49);
    // 0x8001B074: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8001B078: lw          $t8, 0x24($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X24);
    // 0x8001B07C: sll         $t6, $t9, 1
    ctx->r14 = S32(ctx->r25 << 1);
    // 0x8001B080: addu        $a0, $t8, $t6
    ctx->r4 = ADD32(ctx->r24, ctx->r14);
    // 0x8001B084: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8001B088: nop

    // 0x8001B08C: beq         $v1, $zero, L_8001B09C
    if (ctx->r3 == 0) {
        // 0x8001B090: slt         $at, $t1, $v1
        ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001B09C;
    }
    // 0x8001B090: slt         $at, $t1, $v1
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001B094: beq         $at, $zero, L_8001B0C8
    if (ctx->r1 == 0) {
        // 0x8001B098: nop
    
            goto L_8001B0C8;
    }
    // 0x8001B098: nop

L_8001B09C:
    // 0x8001B09C: sh          $t1, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r9;
    // 0x8001B0A0: lb          $t7, 0x115($t0)
    ctx->r15 = MEM_B(ctx->r8, 0X115);
    // 0x8001B0A4: lb          $t6, 0x116($t0)
    ctx->r14 = MEM_B(ctx->r8, 0X116);
    // 0x8001B0A8: multu       $t7, $ra
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B0AC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B0B0: mflo        $t9
    ctx->r25 = lo;
    // 0x8001B0B4: addu        $v1, $t0, $t9
    ctx->r3 = ADD32(ctx->r8, ctx->r25);
    // 0x8001B0B8: lb          $t8, 0x58($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X58);
    // 0x8001B0BC: sllv        $t9, $t7, $t6
    ctx->r25 = S32(ctx->r15 << (ctx->r14 & 31));
    // 0x8001B0C0: or          $t7, $t8, $t9
    ctx->r15 = ctx->r24 | ctx->r25;
    // 0x8001B0C4: sb          $t7, 0x58($v1)
    MEM_B(0X58, ctx->r3) = ctx->r15;
L_8001B0C8:
    // 0x8001B0C8: lb          $a1, 0x114($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X114);
    // 0x8001B0CC: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8001B0D0: bne         $a1, $zero, L_8001B134
    if (ctx->r5 != 0) {
        // 0x8001B0D4: nop
    
            goto L_8001B134;
    }
    // 0x8001B0D4: nop

    // 0x8001B0D8: lbu         $t7, 0x49($t0)
    ctx->r15 = MEM_BU(ctx->r8, 0X49);
    // 0x8001B0DC: addu        $t8, $t0, $t6
    ctx->r24 = ADD32(ctx->r8, ctx->r14);
    // 0x8001B0E0: lw          $t9, 0x3C($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X3C);
    // 0x8001B0E4: sll         $t6, $t7, 1
    ctx->r14 = S32(ctx->r15 << 1);
    // 0x8001B0E8: addu        $a0, $t9, $t6
    ctx->r4 = ADD32(ctx->r25, ctx->r14);
    // 0x8001B0EC: lhu         $v1, 0x0($a0)
    ctx->r3 = MEM_HU(ctx->r4, 0X0);
    // 0x8001B0F0: nop

    // 0x8001B0F4: beq         $v1, $zero, L_8001B104
    if (ctx->r3 == 0) {
        // 0x8001B0F8: slt         $at, $s0, $v1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001B104;
    }
    // 0x8001B0F8: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001B0FC: beq         $at, $zero, L_8001B134
    if (ctx->r1 == 0) {
        // 0x8001B100: nop
    
            goto L_8001B134;
    }
    // 0x8001B100: nop

L_8001B104:
    // 0x8001B104: sh          $s0, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r16;
    // 0x8001B108: lb          $t8, 0x114($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X114);
    // 0x8001B10C: nop

    // 0x8001B110: multu       $t8, $ra
    result = U64(U32(ctx->r24)) * U64(U32(ctx->r31)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8001B114: mflo        $t7
    ctx->r15 = lo;
    // 0x8001B118: addu        $v1, $t0, $t7
    ctx->r3 = ADD32(ctx->r8, ctx->r15);
    // 0x8001B11C: lb          $t9, 0x58($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X58);
    // 0x8001B120: nop

    // 0x8001B124: ori         $t6, $t9, 0x80
    ctx->r14 = ctx->r25 | 0X80;
    // 0x8001B128: sb          $t6, 0x58($v1)
    MEM_B(0X58, ctx->r3) = ctx->r14;
    // 0x8001B12C: lb          $a1, 0x114($t0)
    ctx->r5 = MEM_B(ctx->r8, 0X114);
    // 0x8001B130: nop

L_8001B134:
    // 0x8001B134: bne         $a1, $zero, L_8001B278
    if (ctx->r5 != 0) {
        // 0x8001B138: slti        $at, $s0, 0x2A30
        ctx->r1 = SIGNED(ctx->r16) < 0X2A30 ? 1 : 0;
            goto L_8001B278;
    }
    // 0x8001B138: slti        $at, $s0, 0x2A30
    ctx->r1 = SIGNED(ctx->r16) < 0X2A30 ? 1 : 0;
    // 0x8001B13C: beq         $at, $zero, L_8001B1D0
    if (ctx->r1 == 0) {
        // 0x8001B140: nop
    
            goto L_8001B1D0;
    }
    // 0x8001B140: nop

    // 0x8001B144: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8001B148: lh          $t8, -0x38D8($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X38D8);
    // 0x8001B14C: nop

    // 0x8001B150: bne         $v0, $t8, L_8001B190
    if (ctx->r2 != ctx->r24) {
        // 0x8001B154: nop
    
            goto L_8001B190;
    }
    // 0x8001B154: nop

    // 0x8001B158: jal         0x800599A8
    // 0x8001B15C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    timetrial_map_id(rdram, ctx);
        goto after_3;
    // 0x8001B15C: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    after_3:
    // 0x8001B160: jal         0x8006BD88
    // 0x8001B164: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    level_id(rdram, ctx);
        goto after_4;
    // 0x8001B164: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_4:
    // 0x8001B168: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8001B16C: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8001B170: bne         $v0, $t7, L_8001B190
    if (ctx->r2 != ctx->r15) {
        // 0x8001B174: addiu       $t3, $zero, 0x5
        ctx->r11 = ADD32(0, 0X5);
            goto L_8001B190;
    }
    // 0x8001B174: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001B178: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8001B17C: lh          $t9, -0x38DC($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X38DC);
    // 0x8001B180: nop

    // 0x8001B184: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001B188: beq         $at, $zero, L_8001B1D0
    if (ctx->r1 == 0) {
        // 0x8001B18C: nop
    
            goto L_8001B1D0;
    }
    // 0x8001B18C: nop

L_8001B190:
    // 0x8001B190: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B194: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001B198: lh          $t6, -0x517E($t6)
    ctx->r14 = MEM_H(ctx->r14, -0X517E);
    // 0x8001B19C: sh          $s0, -0x38DC($at)
    MEM_H(-0X38DC, ctx->r1) = ctx->r16;
    // 0x8001B1A0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1A4: sh          $t6, -0x38D8($at)
    MEM_H(-0X38D8, ctx->r1) = ctx->r14;
    // 0x8001B1A8: lb          $t8, 0x59($t0)
    ctx->r24 = MEM_B(ctx->r8, 0X59);
    // 0x8001B1AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1B0: jal         0x8006BD88
    // 0x8001B1B4: sh          $t8, -0x38D4($at)
    MEM_H(-0X38D4, ctx->r1) = ctx->r24;
    level_id(rdram, ctx);
        goto after_5;
    // 0x8001B1B4: sh          $t8, -0x38D4($at)
    MEM_H(-0X38D4, ctx->r1) = ctx->r24;
    after_5:
    // 0x8001B1B8: jal         0x80059984
    // 0x8001B1BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    timetrial_swap_player_ghost(rdram, ctx);
        goto after_6;
    // 0x8001B1BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8001B1C0: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8001B1C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001B1C8: addiu       $t3, $zero, 0x5
    ctx->r11 = ADD32(0, 0X5);
    // 0x8001B1CC: sb          $t7, -0x38D0($at)
    MEM_B(-0X38D0, ctx->r1) = ctx->r15;
L_8001B1D0:
    // 0x8001B1D0: lui         $t9, 0x8000
    ctx->r25 = S32(0X8000 << 16);
    // 0x8001B1D4: lw          $t9, 0x300($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X300);
    // 0x8001B1D8: sll         $t6, $s0, 2
    ctx->r14 = S32(ctx->r16 << 2);
    // 0x8001B1DC: bne         $t9, $zero, L_8001B220
    if (ctx->r25 != 0) {
        // 0x8001B1E0: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8001B220;
    }
    // 0x8001B1E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001B1E4: subu        $t6, $t6, $s0
    ctx->r14 = SUB32(ctx->r14, ctx->r16);
    // 0x8001B1E8: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x8001B1EC: div         $zero, $t6, $t3
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r11))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r11)));
    // 0x8001B1F0: bne         $t3, $zero, L_8001B1FC
    if (ctx->r11 != 0) {
        // 0x8001B1F4: nop
    
            goto L_8001B1FC;
    }
    // 0x8001B1F4: nop

    // 0x8001B1F8: break       7
    do_break(2147594744);
L_8001B1FC:
    // 0x8001B1FC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8001B200: bne         $t3, $at, L_8001B214
    if (ctx->r11 != ctx->r1) {
        // 0x8001B204: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8001B214;
    }
    // 0x8001B204: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8001B208: bne         $t6, $at, L_8001B214
    if (ctx->r14 != ctx->r1) {
        // 0x8001B20C: nop
    
            goto L_8001B214;
    }
    // 0x8001B20C: nop

    // 0x8001B210: break       6
    do_break(2147594768);
L_8001B214:
    // 0x8001B214: mflo        $s0
    ctx->r16 = lo;
    // 0x8001B218: nop

    // 0x8001B21C: nop

L_8001B220:
    // 0x8001B220: lh          $t8, -0x5180($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X5180);
    // 0x8001B224: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001B228: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001B22C: beq         $at, $zero, L_8001B270
    if (ctx->r1 == 0) {
        // 0x8001B230: lui         $t7, 0x800E
        ctx->r15 = S32(0X800E << 16);
            goto L_8001B270;
    }
    // 0x8001B230: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8001B234: lbu         $t7, -0x38CC($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X38CC);
    // 0x8001B238: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8001B23C: beq         $t7, $zero, L_8001B260
    if (ctx->r15 == 0) {
        // 0x8001B240: nop
    
            goto L_8001B260;
    }
    // 0x8001B240: nop

    // 0x8001B244: jal         0x8006BD88
    // 0x8001B248: nop

    level_id(rdram, ctx);
        goto after_7;
    // 0x8001B248: nop

    after_7:
    // 0x8001B24C: lw          $a1, 0x34($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X34);
    // 0x8001B250: jal         0x8001B3C4
    // 0x8001B254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    tt_ghost_beaten(rdram, ctx);
        goto after_8;
    // 0x8001B254: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_8:
    // 0x8001B258: b           L_8001B27C
    // 0x8001B25C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001B27C;
    // 0x8001B25C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B260:
    // 0x8001B260: jal         0x800A6DB4
    // 0x8001B264: nop

    hud_time_trial_message(rdram, ctx);
        goto after_9;
    // 0x8001B264: nop

    after_9:
    // 0x8001B268: b           L_8001B27C
    // 0x8001B26C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_8001B27C;
    // 0x8001B26C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B270:
    // 0x8001B270: jal         0x800A6DB4
    // 0x8001B274: nop

    hud_time_trial_message(rdram, ctx);
        goto after_10;
    // 0x8001B274: nop

    after_10:
L_8001B278:
    // 0x8001B278: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8001B27C:
    // 0x8001B27C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001B280: jr          $ra
    // 0x8001B284: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8001B284: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void func_800179D0(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800179D0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800179D4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800179D8: addiu       $a1, $a1, -0x500C
    ctx->r5 = ADD32(ctx->r5, -0X500C);
L_800179DC:
    // 0x800179DC: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800179E0: sll         $t6, $v0, 6
    ctx->r14 = S32(ctx->r2 << 6);
    // 0x800179E4: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x800179E8: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800179EC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800179F0: beq         $a0, $zero, L_80017A00
    if (ctx->r4 == 0) {
        // 0x800179F4: sll         $t9, $v0, 16
        ctx->r25 = S32(ctx->r2 << 16);
            goto L_80017A00;
    }
    // 0x800179F4: sll         $t9, $v0, 16
    ctx->r25 = S32(ctx->r2 << 16);
    // 0x800179F8: addiu       $t8, $a0, -0x1
    ctx->r24 = ADD32(ctx->r4, -0X1);
    // 0x800179FC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_80017A00:
    // 0x80017A00: sra         $v0, $t9, 16
    ctx->r2 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80017A04: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x80017A08: bne         $at, $zero, L_800179DC
    if (ctx->r1 != 0) {
        // 0x80017A0C: nop
    
            goto L_800179DC;
    }
    // 0x80017A0C: nop

    // 0x80017A10: jr          $ra
    // 0x80017A14: nop

    return;
    // 0x80017A14: nop

;}
RECOMP_FUNC void alCSPSetBank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C7A60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7A64: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7A68: addiu       $t6, $zero, 0xE
    ctx->r14 = ADD32(0, 0XE);
    // 0x800C7A6C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C7A70: sh          $t6, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r14;
    // 0x800C7A74: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7A78: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C7A7C: jal         0x800C91AC
    // 0x800C7A80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7A80: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C7A84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7A88: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7A8C: jr          $ra
    // 0x800C7A90: nop

    return;
    // 0x800C7A90: nop

;}
RECOMP_FUNC void input_clamp_stick_mag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006A624: sll         $t6, $a0, 24
    ctx->r14 = S32(ctx->r4 << 24);
    // 0x8006A628: sra         $t7, $t6, 24
    ctx->r15 = S32(SIGNED(ctx->r14) >> 24);
    // 0x8006A62C: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8006A630: slti        $at, $t7, 0x8
    ctx->r1 = SIGNED(ctx->r15) < 0X8 ? 1 : 0;
    // 0x8006A634: beq         $at, $zero, L_8006A650
    if (ctx->r1 == 0) {
        // 0x8006A638: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_8006A650;
    }
    // 0x8006A638: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x8006A63C: slti        $at, $t7, -0x7
    ctx->r1 = SIGNED(ctx->r15) < -0X7 ? 1 : 0;
    // 0x8006A640: bne         $at, $zero, L_8006A650
    if (ctx->r1 != 0) {
        // 0x8006A644: nop
    
            goto L_8006A650;
    }
    // 0x8006A644: nop

    // 0x8006A648: jr          $ra
    // 0x8006A64C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006A64C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006A650:
    // 0x8006A650: blez        $a0, L_8006A678
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8006A654: nop
    
            goto L_8006A678;
    }
    // 0x8006A654: nop

    // 0x8006A658: addiu       $a0, $a0, -0x8
    ctx->r4 = ADD32(ctx->r4, -0X8);
    // 0x8006A65C: sll         $t8, $a0, 24
    ctx->r24 = S32(ctx->r4 << 24);
    // 0x8006A660: sra         $a0, $t8, 24
    ctx->r4 = S32(SIGNED(ctx->r24) >> 24);
    // 0x8006A664: slti        $at, $a0, 0x47
    ctx->r1 = SIGNED(ctx->r4) < 0X47 ? 1 : 0;
    // 0x8006A668: bne         $at, $zero, L_8006A698
    if (ctx->r1 != 0) {
        // 0x8006A66C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8006A698;
    }
    // 0x8006A66C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006A670: b           L_8006A694
    // 0x8006A674: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
        goto L_8006A694;
    // 0x8006A674: addiu       $a0, $zero, 0x46
    ctx->r4 = ADD32(0, 0X46);
L_8006A678:
    // 0x8006A678: addiu       $a0, $a0, 0x8
    ctx->r4 = ADD32(ctx->r4, 0X8);
    // 0x8006A67C: sll         $t0, $a0, 24
    ctx->r8 = S32(ctx->r4 << 24);
    // 0x8006A680: sra         $a0, $t0, 24
    ctx->r4 = S32(SIGNED(ctx->r8) >> 24);
    // 0x8006A684: slti        $at, $a0, -0x46
    ctx->r1 = SIGNED(ctx->r4) < -0X46 ? 1 : 0;
    // 0x8006A688: beq         $at, $zero, L_8006A698
    if (ctx->r1 == 0) {
        // 0x8006A68C: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_8006A698;
    }
    // 0x8006A68C: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x8006A690: addiu       $a0, $zero, -0x46
    ctx->r4 = ADD32(0, -0X46);
L_8006A694:
    // 0x8006A694: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
L_8006A698:
    // 0x8006A698: jr          $ra
    // 0x8006A69C: nop

    return;
    // 0x8006A69C: nop

;}
RECOMP_FUNC void ainode_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001BF20: addiu       $sp, $sp, -0x190
    ctx->r29 = ADD32(ctx->r29, -0X190);
    // 0x8001BF24: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001BF28: addiu       $v0, $v0, -0x50F0
    ctx->r2 = ADD32(ctx->r2, -0X50F0);
    // 0x8001BF2C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8001BF30: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001BF34: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001BF38: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001BF3C: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001BF40: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001BF44: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001BF48: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001BF4C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001BF50: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001BF54: beq         $t6, $zero, L_8001C3E8
    if (ctx->r14 == 0) {
        // 0x8001BF58: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8001C3E8;
    }
    // 0x8001BF58: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001BF5C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001BF60: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x8001BF64: addiu       $t2, $t2, -0x50FC
    ctx->r10 = ADD32(ctx->r10, -0X50FC);
    // 0x8001BF68: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_8001BF6C:
    // 0x8001BF6C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x8001BF70: nop

    // 0x8001BF74: addu        $t8, $t7, $fp
    ctx->r24 = ADD32(ctx->r15, ctx->r30);
    // 0x8001BF78: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8001BF7C: slti        $at, $fp, 0x200
    ctx->r1 = SIGNED(ctx->r30) < 0X200 ? 1 : 0;
    // 0x8001BF80: bne         $at, $zero, L_8001BF6C
    if (ctx->r1 != 0) {
        // 0x8001BF84: sw          $zero, 0x0($t8)
        MEM_W(0X0, ctx->r24) = 0;
            goto L_8001BF6C;
    }
    // 0x8001BF84: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x8001BF88: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001BF8C: lw          $a0, -0x51A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X51A4);
    // 0x8001BF90: sh          $zero, 0x186($sp)
    MEM_H(0X186, ctx->r29) = 0;
    // 0x8001BF94: blez        $a0, L_8001C04C
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001BF98: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001C04C;
    }
    // 0x8001BF98: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001BF9C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001BFA0: addiu       $a1, $a1, -0x51A8
    ctx->r5 = ADD32(ctx->r5, -0X51A8);
    // 0x8001BFA4: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8001BFA8: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x8001BFAC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
L_8001BFB0:
    // 0x8001BFB0: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x8001BFB4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001BFB8: addu        $t3, $t9, $fp
    ctx->r11 = ADD32(ctx->r25, ctx->r30);
    // 0x8001BFBC: lw          $s3, 0x0($t3)
    ctx->r19 = MEM_W(ctx->r11, 0X0);
    // 0x8001BFC0: nop

    // 0x8001BFC4: lh          $t4, 0x6($s3)
    ctx->r12 = MEM_H(ctx->r19, 0X6);
    // 0x8001BFC8: nop

    // 0x8001BFCC: andi        $t5, $t4, 0x8000
    ctx->r13 = ctx->r12 & 0X8000;
    // 0x8001BFD0: bne         $t5, $zero, L_8001C044
    if (ctx->r13 != 0) {
        // 0x8001BFD4: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8001C044;
    }
    // 0x8001BFD4: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001BFD8: lh          $t6, 0x48($s3)
    ctx->r14 = MEM_H(ctx->r19, 0X48);
    // 0x8001BFDC: nop

    // 0x8001BFE0: bne         $a2, $t6, L_8001C044
    if (ctx->r6 != ctx->r14) {
        // 0x8001BFE4: slt         $at, $a3, $a0
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8001C044;
    }
    // 0x8001BFE4: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001BFE8: lw          $v0, 0x3C($s3)
    ctx->r2 = MEM_W(ctx->r19, 0X3C);
    // 0x8001BFEC: nop

    // 0x8001BFF0: lbu         $v1, 0x9($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X9);
    // 0x8001BFF4: nop

    // 0x8001BFF8: andi        $t7, $v1, 0x80
    ctx->r15 = ctx->r3 & 0X80;
    // 0x8001BFFC: bne         $t7, $zero, L_8001C040
    if (ctx->r15 != 0) {
        // 0x8001C000: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8001C040;
    }
    // 0x8001C000: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8001C004: lw          $t8, 0x0($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X0);
    // 0x8001C008: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001C00C: addu        $t3, $t8, $t9
    ctx->r11 = ADD32(ctx->r24, ctx->r25);
    // 0x8001C010: sw          $s3, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r19;
    // 0x8001C014: lh          $t5, 0x186($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X186);
    // 0x8001C018: lbu         $t4, 0x9($v0)
    ctx->r12 = MEM_BU(ctx->r2, 0X9);
    // 0x8001C01C: addu        $t6, $sp, $t5
    ctx->r14 = ADD32(ctx->r29, ctx->r13);
    // 0x8001C020: sb          $t4, 0xE4($t6)
    MEM_B(0XE4, ctx->r14) = ctx->r12;
    // 0x8001C024: lb          $t7, 0xE($v0)
    ctx->r15 = MEM_B(ctx->r2, 0XE);
    // 0x8001C028: addu        $t9, $s7, $t5
    ctx->r25 = ADD32(ctx->r23, ctx->r13);
    // 0x8001C02C: andi        $t8, $t7, 0x3
    ctx->r24 = ctx->r15 & 0X3;
    // 0x8001C030: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    // 0x8001C034: addiu       $t3, $t5, 0x1
    ctx->r11 = ADD32(ctx->r13, 0X1);
    // 0x8001C038: lw          $a0, -0x51A4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X51A4);
    // 0x8001C03C: sh          $t3, 0x186($sp)
    MEM_H(0X186, ctx->r29) = ctx->r11;
L_8001C040:
    // 0x8001C040: slt         $at, $a3, $a0
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r4) ? 1 : 0;
L_8001C044:
    // 0x8001C044: bne         $at, $zero, L_8001BFB0
    if (ctx->r1 != 0) {
        // 0x8001C048: addiu       $fp, $fp, 0x4
        ctx->r30 = ADD32(ctx->r30, 0X4);
            goto L_8001BFB0;
    }
    // 0x8001C048: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
L_8001C04C:
    // 0x8001C04C: lh          $t4, 0x186($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X186);
    // 0x8001C050: addiu       $s7, $sp, 0x64
    ctx->r23 = ADD32(ctx->r29, 0X64);
    // 0x8001C054: beq         $t4, $zero, L_8001C3E8
    if (ctx->r12 == 0) {
        // 0x8001C058: or          $fp, $zero, $zero
        ctx->r30 = 0 | 0;
            goto L_8001C3E8;
    }
    // 0x8001C058: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
    // 0x8001C05C: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8001C060: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
L_8001C064:
    // 0x8001C064: lw          $t6, 0x0($t2)
    ctx->r14 = MEM_W(ctx->r10, 0X0);
    // 0x8001C068: nop

    // 0x8001C06C: addu        $t7, $t6, $fp
    ctx->r15 = ADD32(ctx->r14, ctx->r30);
    // 0x8001C070: lw          $s3, 0x0($t7)
    ctx->r19 = MEM_W(ctx->r15, 0X0);
    // 0x8001C074: nop

    // 0x8001C078: beq         $s3, $zero, L_8001C140
    if (ctx->r19 == 0) {
        // 0x8001C07C: nop
    
            goto L_8001C140;
    }
    // 0x8001C07C: nop

    // 0x8001C080: lw          $s4, 0x64($s3)
    ctx->r20 = MEM_W(ctx->r19, 0X64);
    // 0x8001C084: lw          $s0, 0x3C($s3)
    ctx->r16 = MEM_W(ctx->r19, 0X3C);
    // 0x8001C088: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8001C08C:
    // 0x8001C08C: lbu         $v1, 0xA($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0XA);
    // 0x8001C090: nop

    // 0x8001C094: andi        $t8, $v1, 0x80
    ctx->r24 = ctx->r3 & 0X80;
    // 0x8001C098: bne         $t8, $zero, L_8001C134
    if (ctx->r24 != 0) {
        // 0x8001C09C: sll         $t5, $v1, 2
        ctx->r13 = S32(ctx->r3 << 2);
            goto L_8001C134;
    }
    // 0x8001C09C: sll         $t5, $v1, 2
    ctx->r13 = S32(ctx->r3 << 2);
    // 0x8001C0A0: lw          $t9, 0x0($t2)
    ctx->r25 = MEM_W(ctx->r10, 0X0);
    // 0x8001C0A4: sll         $t4, $s1, 2
    ctx->r12 = S32(ctx->r17 << 2);
    // 0x8001C0A8: addu        $t3, $t9, $t5
    ctx->r11 = ADD32(ctx->r25, ctx->r13);
    // 0x8001C0AC: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8001C0B0: addu        $t6, $s4, $t4
    ctx->r14 = ADD32(ctx->r20, ctx->r12);
    // 0x8001C0B4: bne         $v0, $zero, L_8001C0C4
    if (ctx->r2 != 0) {
        // 0x8001C0B8: sw          $v0, 0x0($t6)
        MEM_W(0X0, ctx->r14) = ctx->r2;
            goto L_8001C0C4;
    }
    // 0x8001C0B8: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8001C0BC: b           L_8001C134
    // 0x8001C0C0: sb          $s5, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r21;
        goto L_8001C134;
    // 0x8001C0C0: sb          $s5, 0xA($s0)
    MEM_B(0XA, ctx->r16) = ctx->r21;
L_8001C0C4:
    // 0x8001C0C4: lwc1        $f4, 0xC($s3)
    ctx->f4.u32l = MEM_W(ctx->r19, 0XC);
    // 0x8001C0C8: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8001C0CC: lwc1        $f8, 0x10($s3)
    ctx->f8.u32l = MEM_W(ctx->r19, 0X10);
    // 0x8001C0D0: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8001C0D4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8001C0D8: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8001C0DC: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8001C0E0: lwc1        $f16, 0x14($s3)
    ctx->f16.u32l = MEM_W(ctx->r19, 0X14);
    // 0x8001C0E4: lwc1        $f18, 0x14($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8001C0E8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8001C0EC: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8001C0F0: sll         $t7, $s1, 1
    ctx->r15 = S32(ctx->r17 << 1);
    // 0x8001C0F4: addu        $s2, $s4, $t7
    ctx->r18 = ADD32(ctx->r20, ctx->r15);
    // 0x8001C0F8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001C0FC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001C100: jal         0x800C9AD0
    // 0x8001C104: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001C104: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8001C108: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001C10C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x8001C110: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001C114: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001C118: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001C11C: addiu       $t2, $t2, -0x50FC
    ctx->r10 = ADD32(ctx->r10, -0X50FC);
    // 0x8001C120: cvt.w.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8001C124: mfc1        $t9, $f16
    ctx->r25 = (int32_t)ctx->f16.u32l;
    // 0x8001C128: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001C12C: sh          $t9, 0x10($s2)
    MEM_H(0X10, ctx->r18) = ctx->r25;
    // 0x8001C130: nop

L_8001C134:
    // 0x8001C134: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8001C138: bne         $s1, $s6, L_8001C08C
    if (ctx->r17 != ctx->r22) {
        // 0x8001C13C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_8001C08C;
    }
    // 0x8001C13C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_8001C140:
    // 0x8001C140: addiu       $fp, $fp, 0x4
    ctx->r30 = ADD32(ctx->r30, 0X4);
    // 0x8001C144: addiu       $at, $zero, 0x200
    ctx->r1 = ADD32(0, 0X200);
    // 0x8001C148: bne         $fp, $at, L_8001C064
    if (ctx->r30 != ctx->r1) {
        // 0x8001C14C: nop
    
            goto L_8001C064;
    }
    // 0x8001C14C: nop

    // 0x8001C150: lh          $t1, 0x186($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X186);
    // 0x8001C154: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001C158: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
L_8001C15C:
    // 0x8001C15C: blez        $t1, L_8001C2AC
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C160: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8001C2AC;
    }
    // 0x8001C160: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8001C164: lh          $v0, 0x186($sp)
    ctx->r2 = MEM_H(ctx->r29, 0X186);
    // 0x8001C168: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8001C16C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001C170: andi        $t5, $v0, 0x1
    ctx->r13 = ctx->r2 & 0X1;
    // 0x8001C174: beq         $t5, $zero, L_8001C1DC
    if (ctx->r13 == 0) {
        // 0x8001C178: addiu       $t7, $sp, 0xE4
        ctx->r15 = ADD32(ctx->r29, 0XE4);
            goto L_8001C1DC;
    }
    // 0x8001C178: addiu       $t7, $sp, 0xE4
    ctx->r15 = ADD32(ctx->r29, 0XE4);
    // 0x8001C17C: lb          $t3, 0xE5($sp)
    ctx->r11 = MEM_B(ctx->r29, 0XE5);
    // 0x8001C180: lb          $t8, 0xE4($sp)
    ctx->r24 = MEM_B(ctx->r29, 0XE4);
    // 0x8001C184: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001C188: addu        $t6, $t0, $t4
    ctx->r14 = ADD32(ctx->r8, ctx->r12);
    // 0x8001C18C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8001C190: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x8001C194: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8001C198: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001C19C: lwc1        $f2, 0x10($t4)
    ctx->f2.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8001C1A0: lwc1        $f0, 0x10($t7)
    ctx->f0.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8001C1A4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8001C1A8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8001C1AC: nop

    // 0x8001C1B0: bc1f        L_8001C1D4
    if (!c1cs) {
        // 0x8001C1B4: nop
    
            goto L_8001C1D4;
    }
    // 0x8001C1B4: nop

    // 0x8001C1B8: lb          $v0, 0x64($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X64);
    // 0x8001C1BC: lb          $t6, 0x65($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X65);
    // 0x8001C1C0: sb          $t3, 0xE4($sp)
    MEM_B(0XE4, ctx->r29) = ctx->r11;
    // 0x8001C1C4: sb          $t8, 0xE5($sp)
    MEM_B(0XE5, ctx->r29) = ctx->r24;
    // 0x8001C1C8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C1CC: sb          $v0, 0x65($sp)
    MEM_B(0X65, ctx->r29) = ctx->r2;
    // 0x8001C1D0: sb          $t6, 0x64($sp)
    MEM_B(0X64, ctx->r29) = ctx->r14;
L_8001C1D4:
    // 0x8001C1D4: beq         $a3, $t1, L_8001C2A8
    if (ctx->r7 == ctx->r9) {
        // 0x8001C1D8: addiu       $t7, $sp, 0xE4
        ctx->r15 = ADD32(ctx->r29, 0XE4);
            goto L_8001C2A8;
    }
    // 0x8001C1D8: addiu       $t7, $sp, 0xE4
    ctx->r15 = ADD32(ctx->r29, 0XE4);
L_8001C1DC:
    // 0x8001C1DC: addu        $a0, $a3, $t7
    ctx->r4 = ADD32(ctx->r7, ctx->r15);
L_8001C1E0:
    // 0x8001C1E0: lb          $a1, 0x1($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X1);
    // 0x8001C1E4: lb          $a2, 0x0($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X0);
    // 0x8001C1E8: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x8001C1EC: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8001C1F0: addu        $t3, $t0, $t8
    ctx->r11 = ADD32(ctx->r8, ctx->r24);
    // 0x8001C1F4: addu        $t5, $t0, $t9
    ctx->r13 = ADD32(ctx->r8, ctx->r25);
    // 0x8001C1F8: lw          $t4, 0x0($t5)
    ctx->r12 = MEM_W(ctx->r13, 0X0);
    // 0x8001C1FC: lw          $t6, 0x0($t3)
    ctx->r14 = MEM_W(ctx->r11, 0X0);
    // 0x8001C200: lwc1        $f0, 0x10($t4)
    ctx->f0.u32l = MEM_W(ctx->r12, 0X10);
    // 0x8001C204: lwc1        $f18, 0x10($t6)
    ctx->f18.u32l = MEM_W(ctx->r14, 0X10);
    // 0x8001C208: addu        $v1, $s7, $a3
    ctx->r3 = ADD32(ctx->r23, ctx->r7);
    // 0x8001C20C: c.lt.s      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.fl < ctx->f18.fl;
    // 0x8001C210: nop

    // 0x8001C214: bc1f        L_8001C250
    if (!c1cs) {
        // 0x8001C218: nop
    
            goto L_8001C250;
    }
    // 0x8001C218: nop

    // 0x8001C21C: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8001C220: sb          $a2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r6;
    // 0x8001C224: lb          $a1, 0x1($a0)
    ctx->r5 = MEM_B(ctx->r4, 0X1);
    // 0x8001C228: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x8001C22C: lb          $t9, 0x1($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X1);
    // 0x8001C230: sll         $t5, $a1, 2
    ctx->r13 = S32(ctx->r5 << 2);
    // 0x8001C234: addu        $t4, $t0, $t5
    ctx->r12 = ADD32(ctx->r8, ctx->r13);
    // 0x8001C238: sb          $v0, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r2;
    // 0x8001C23C: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x8001C240: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8001C244: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C248: lwc1        $f0, 0x10($t8)
    ctx->f0.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8001C24C: nop

L_8001C250:
    // 0x8001C250: lb          $a2, 0x2($a0)
    ctx->r6 = MEM_B(ctx->r4, 0X2);
    // 0x8001C254: addu        $v1, $s7, $a3
    ctx->r3 = ADD32(ctx->r23, ctx->r7);
    // 0x8001C258: sll         $t3, $a2, 2
    ctx->r11 = S32(ctx->r6 << 2);
    // 0x8001C25C: addu        $t6, $t0, $t3
    ctx->r14 = ADD32(ctx->r8, ctx->r11);
    // 0x8001C260: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x8001C264: nop

    // 0x8001C268: lwc1        $f4, 0x10($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X10);
    // 0x8001C26C: nop

    // 0x8001C270: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x8001C274: nop

    // 0x8001C278: bc1f        L_8001C29C
    if (!c1cs) {
        // 0x8001C27C: nop
    
            goto L_8001C29C;
    }
    // 0x8001C27C: nop

    // 0x8001C280: lb          $v0, 0x1($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X1);
    // 0x8001C284: lb          $t5, 0x2($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X2);
    // 0x8001C288: sb          $a2, 0x1($a0)
    MEM_B(0X1, ctx->r4) = ctx->r6;
    // 0x8001C28C: sb          $a1, 0x2($a0)
    MEM_B(0X2, ctx->r4) = ctx->r5;
    // 0x8001C290: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001C294: sb          $v0, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r2;
    // 0x8001C298: sb          $t5, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r13;
L_8001C29C:
    // 0x8001C29C: addiu       $a3, $a3, 0x2
    ctx->r7 = ADD32(ctx->r7, 0X2);
    // 0x8001C2A0: bne         $a3, $t1, L_8001C1E0
    if (ctx->r7 != ctx->r9) {
        // 0x8001C2A4: addiu       $a0, $a0, 0x2
        ctx->r4 = ADD32(ctx->r4, 0X2);
            goto L_8001C1E0;
    }
    // 0x8001C2A4: addiu       $a0, $a0, 0x2
    ctx->r4 = ADD32(ctx->r4, 0X2);
L_8001C2A8:
    // 0x8001C2A8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_8001C2AC:
    // 0x8001C2AC: beq         $s1, $zero, L_8001C15C
    if (ctx->r17 == 0) {
        // 0x8001C2B0: nop
    
            goto L_8001C15C;
    }
    // 0x8001C2B0: nop

    // 0x8001C2B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C2B8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001C2BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001C2C0: lwc1        $f0, 0x5638($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X5638);
    // 0x8001C2C4: addiu       $v1, $v1, -0x50D4
    ctx->r3 = ADD32(ctx->r3, -0X50D4);
    // 0x8001C2C8: addiu       $v0, $v0, -0x50E8
    ctx->r2 = ADD32(ctx->r2, -0X50E8);
L_8001C2CC:
    // 0x8001C2CC: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8001C2D0: sltu        $at, $v0, $v1
    ctx->r1 = ctx->r2 < ctx->r3 ? 1 : 0;
    // 0x8001C2D4: bne         $at, $zero, L_8001C2CC
    if (ctx->r1 != 0) {
        // 0x8001C2D8: swc1        $f0, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
            goto L_8001C2CC;
    }
    // 0x8001C2D8: swc1        $f0, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = ctx->f0.u32l;
    // 0x8001C2DC: lb          $v0, 0x64($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X64);
    // 0x8001C2E0: blez        $t1, L_8001C3C4
    if (SIGNED(ctx->r9) <= 0) {
        // 0x8001C2E4: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8001C3C4;
    }
    // 0x8001C2E4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8001C2E8: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8001C2EC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001C2F0: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x8001C2F4: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001C2F8: addiu       $a2, $a2, -0x50E8
    ctx->r6 = ADD32(ctx->r6, -0X50E8);
    // 0x8001C2FC: addiu       $t4, $sp, 0x64
    ctx->r12 = ADD32(ctx->r29, 0X64);
L_8001C300:
    // 0x8001C300: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C304: beq         $at, $zero, L_8001C344
    if (ctx->r1 == 0) {
        // 0x8001C308: addu        $v1, $a3, $t4
        ctx->r3 = ADD32(ctx->r7, ctx->r12);
            goto L_8001C344;
    }
    // 0x8001C308: addu        $v1, $a3, $t4
    ctx->r3 = ADD32(ctx->r7, ctx->r12);
    // 0x8001C30C: lb          $t8, 0x0($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X0);
    // 0x8001C310: nop

    // 0x8001C314: slt         $at, $v0, $t8
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8001C318: bne         $at, $zero, L_8001C344
    if (ctx->r1 != 0) {
        // 0x8001C31C: nop
    
            goto L_8001C344;
    }
    // 0x8001C31C: nop

L_8001C320:
    // 0x8001C320: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x8001C324: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C328: beq         $at, $zero, L_8001C344
    if (ctx->r1 == 0) {
        // 0x8001C32C: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_8001C344;
    }
    // 0x8001C32C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8001C330: lb          $t3, 0x0($v1)
    ctx->r11 = MEM_B(ctx->r3, 0X0);
    // 0x8001C334: nop

    // 0x8001C338: slt         $at, $v0, $t3
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8001C33C: beq         $at, $zero, L_8001C320
    if (ctx->r1 == 0) {
        // 0x8001C340: nop
    
            goto L_8001C320;
    }
    // 0x8001C340: nop

L_8001C344:
    // 0x8001C344: lb          $a1, 0x0($v1)
    ctx->r5 = MEM_B(ctx->r3, 0X0);
    // 0x8001C348: addiu       $t7, $sp, 0xE4
    ctx->r15 = ADD32(ctx->r29, 0XE4);
    // 0x8001C34C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8001C350: beq         $at, $zero, L_8001C3B0
    if (ctx->r1 == 0) {
        // 0x8001C354: addu        $a0, $a3, $t7
        ctx->r4 = ADD32(ctx->r7, ctx->r15);
            goto L_8001C3B0;
    }
    // 0x8001C354: addu        $a0, $a3, $t7
    ctx->r4 = ADD32(ctx->r7, ctx->r15);
    // 0x8001C358: sll         $v0, $a1, 24
    ctx->r2 = S32(ctx->r5 << 24);
    // 0x8001C35C: lw          $t0, 0x0($t2)
    ctx->r8 = MEM_W(ctx->r10, 0X0);
    // 0x8001C360: lb          $t9, -0x1($a0)
    ctx->r25 = MEM_B(ctx->r4, -0X1);
    // 0x8001C364: lb          $t3, 0x0($a0)
    ctx->r11 = MEM_B(ctx->r4, 0X0);
    // 0x8001C368: sra         $t6, $v0, 24
    ctx->r14 = S32(SIGNED(ctx->r2) >> 24);
    // 0x8001C36C: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8001C370: sll         $t5, $t9, 2
    ctx->r13 = S32(ctx->r25 << 2);
    // 0x8001C374: sll         $t6, $t3, 2
    ctx->r14 = S32(ctx->r11 << 2);
    // 0x8001C378: addu        $t7, $t0, $t6
    ctx->r15 = ADD32(ctx->r8, ctx->r14);
    // 0x8001C37C: addu        $t4, $t0, $t5
    ctx->r12 = ADD32(ctx->r8, ctx->r13);
    // 0x8001C380: lw          $t8, 0x0($t4)
    ctx->r24 = MEM_W(ctx->r12, 0X0);
    // 0x8001C384: lw          $t9, 0x0($t7)
    ctx->r25 = MEM_W(ctx->r15, 0X0);
    // 0x8001C388: lwc1        $f6, 0x10($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X10);
    // 0x8001C38C: lwc1        $f8, 0x10($t9)
    ctx->f8.u32l = MEM_W(ctx->r25, 0X10);
    // 0x8001C390: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8001C394: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8001C398: addu        $t4, $a2, $t5
    ctx->r12 = ADD32(ctx->r6, ctx->r13);
    // 0x8001C39C: cvt.d.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f16.d = CVT_D_S(ctx->f10.fl);
    // 0x8001C3A0: mul.d       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x8001C3A4: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8001C3A8: b           L_8001C3B8
    // 0x8001C3AC: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
        goto L_8001C3B8;
    // 0x8001C3AC: swc1        $f4, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->f4.u32l;
L_8001C3B0:
    // 0x8001C3B0: lh          $a3, 0x186($sp)
    ctx->r7 = MEM_H(ctx->r29, 0X186);
    // 0x8001C3B4: nop

L_8001C3B8:
    // 0x8001C3B8: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001C3BC: bne         $at, $zero, L_8001C300
    if (ctx->r1 != 0) {
        // 0x8001C3C0: addiu       $t4, $sp, 0x64
        ctx->r12 = ADD32(ctx->r29, 0X64);
            goto L_8001C300;
    }
    // 0x8001C3C0: addiu       $t4, $sp, 0x64
    ctx->r12 = ADD32(ctx->r29, 0X64);
L_8001C3C4:
    // 0x8001C3C4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8001C3C8: lwc1        $f6, 0x563C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X563C);
    // 0x8001C3CC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001C3D0: addiu       $a2, $a2, -0x50E8
    ctx->r6 = ADD32(ctx->r6, -0X50E8);
    // 0x8001C3D4: swc1        $f6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->f6.u32l;
    // 0x8001C3D8: lwc1        $f8, 0x0($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001C3DC: nop

    // 0x8001C3E0: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x8001C3E4: swc1        $f10, 0x10($a2)
    MEM_W(0X10, ctx->r6) = ctx->f10.u32l;
L_8001C3E8:
    // 0x8001C3E8: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001C3EC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001C3F0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001C3F4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001C3F8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001C3FC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001C400: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001C404: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001C408: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001C40C: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001C410: jr          $ra
    // 0x8001C414: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
    return;
    // 0x8001C414: addiu       $sp, $sp, 0x190
    ctx->r29 = ADD32(ctx->r29, 0X190);
;}
RECOMP_FUNC void alAuxBusParam(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_audio_bus_guard(uint8_t*, recomp_context*); if (dkr_audio_bus_guard(rdram, ctx)) { return; }
    // 0x800659D4: lw          $v1, 0x1C($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X1C);
    // 0x800659D8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800659DC: beq         $a1, $at, L_800659F8
    if (ctx->r5 == ctx->r1) {
        // 0x800659E0: or          $v0, $a0, $zero
        ctx->r2 = ctx->r4 | 0;
            goto L_800659F8;
    }
    // 0x800659E0: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    // 0x800659E4: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800659E8: beq         $a1, $at, L_80065A20
    if (ctx->r5 == ctx->r1) {
        // 0x800659EC: nop
    
            goto L_80065A20;
    }
    // 0x800659EC: nop

    // 0x800659F0: jr          $ra
    // 0x800659F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800659F4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800659F8:
    // 0x800659F8: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x800659FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80065A00: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80065A04: addu        $t8, $v1, $t7
    ctx->r24 = ADD32(ctx->r3, ctx->r15);
    // 0x80065A08: sw          $a2, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r6;
    // 0x80065A0C: lw          $t9, 0x14($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X14);
    // 0x80065A10: nop

    // 0x80065A14: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80065A18: jr          $ra
    // 0x80065A1C: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
    return;
    // 0x80065A1C: sw          $t0, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r8;
L_80065A20:
    // 0x80065A20: lw          $t1, 0x14($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X14);
    // 0x80065A24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80065A28: blez        $t1, L_80065A78
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80065A2C: or          $a3, $v1, $zero
        ctx->r7 = ctx->r3 | 0;
            goto L_80065A78;
    }
    // 0x80065A2C: or          $a3, $v1, $zero
    ctx->r7 = ctx->r3 | 0;
L_80065A30:
    // 0x80065A30: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80065A34: nop

    // 0x80065A38: bne         $a2, $t2, L_80065A64
    if (ctx->r6 != ctx->r10) {
        // 0x80065A3C: nop
    
            goto L_80065A64;
    }
    // 0x80065A3C: nop

    // 0x80065A40: lw          $t3, 0x14($a0)
    ctx->r11 = MEM_W(ctx->r4, 0X14);
    // 0x80065A44: nop

    // 0x80065A48: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x80065A4C: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80065A50: sw          $t4, 0x14($a0)
    MEM_W(0X14, ctx->r4) = ctx->r12;
    // 0x80065A54: addu        $t7, $v1, $t6
    ctx->r15 = ADD32(ctx->r3, ctx->r14);
    // 0x80065A58: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x80065A5C: nop

    // 0x80065A60: sw          $t8, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r24;
L_80065A64:
    // 0x80065A64: lw          $t9, 0x14($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X14);
    // 0x80065A68: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x80065A6C: slt         $at, $a1, $t9
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80065A70: bne         $at, $zero, L_80065A30
    if (ctx->r1 != 0) {
        // 0x80065A74: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_80065A30;
    }
    // 0x80065A74: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
L_80065A78:
    // 0x80065A78: jr          $ra
    // 0x80065A7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80065A7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void reset_delayed_text(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C314C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C3150: jr          $ra
    // 0x800C3154: sw          $zero, 0x3678($at)
    MEM_W(0X3678, ctx->r1) = 0;
    return;
    // 0x800C3154: sw          $zero, 0x3678($at)
    MEM_W(0X3678, ctx->r1) = 0;
;}
RECOMP_FUNC void drm_validate_imem(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F4EC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F4F0: jr          $ra
    // 0x8006F4F4: nop

    return;
    // 0x8006F4F4: nop

    // 0x8006F4F8: beq         $t7, $at, L_8006F508
    if (ctx->r15 == ctx->r1) {
        // 0x8006F4FC: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_8006F508;
    }
    // 0x8006F4FC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006F500: jr          $ra
    // 0x8006F504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8006F504: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8006F508:
    // 0x8006F508: jr          $ra
    // 0x8006F50C: nop

    return;
    // 0x8006F50C: nop

;}
RECOMP_FUNC void amCreateAudioMgr(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002660: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80002664: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002668: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8000266C: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x80002670: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x80002674: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x80002678: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x8000267C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80002680: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x80002684: sw          $a2, 0x5F90($at)
    MEM_W(0X5F90, ctx->r1) = ctx->r6;
    // 0x80002688: lw          $t6, 0x14($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X14);
    // 0x8000268C: lui         $at, 0x8011
    ctx->r1 = S32(0X8011 << 16);
    // 0x80002690: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x80002694: addiu       $t7, $t7, 0x3008
    ctx->r15 = ADD32(ctx->r15, 0X3008);
    // 0x80002698: sw          $t6, 0x5F94($at)
    MEM_W(0X5F94, ctx->r1) = ctx->r14;
    // 0x8000269C: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800026A0: sw          $t7, 0x10($a0)
    MEM_W(0X10, ctx->r4) = ctx->r15;
    // 0x800026A4: jal         0x800C8600
    // 0x800026A8: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    osAiSetFrequency_recomp(rdram, ctx);
        goto after_0;
    // 0x800026A8: addiu       $a0, $zero, 0x5622
    ctx->r4 = ADD32(0, 0X5622);
    after_0:
    // 0x800026AC: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800026B0: sw          $v0, 0x18($s3)
    MEM_W(0X18, ctx->r19) = ctx->r2;
    // 0x800026B4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800026B8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800026BC: lw          $t8, 0x6170($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6170);
    // 0x800026C0: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x800026C4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800026C8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x800026CC: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800026D0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800026D4: addiu       $a0, $a0, -0x69D4
    ctx->r4 = ADD32(ctx->r4, -0X69D4);
    // 0x800026D8: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800026DC: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800026E0: addiu       $s4, $s4, -0x69D0
    ctx->r20 = ADD32(ctx->r20, -0X69D0);
    // 0x800026E4: div.s       $f0, $f10, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = DIV_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800026E8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800026EC: nop

    // 0x800026F0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800026F4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800026F8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800026FC: nop

    // 0x80002700: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80002704: mfc1        $v1, $f4
    ctx->r3 = (int32_t)ctx->f4.u32l;
    // 0x80002708: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000270C: mtc1        $v1, $f6
    ctx->f6.u32l = ctx->r3;
    // 0x80002710: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
    // 0x80002714: bgez        $v1, L_8000272C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80002718: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000272C;
    }
    // 0x80002718: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000271C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80002720: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80002724: nop

    // 0x80002728: add.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f16.fl;
L_8000272C:
    // 0x8000272C: c.lt.s      $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f8.fl < ctx->f0.fl;
    // 0x80002730: nop

    // 0x80002734: bc1f        L_80002744
    if (!c1cs) {
        // 0x80002738: addiu       $t2, $v1, 0x1
        ctx->r10 = ADD32(ctx->r3, 0X1);
            goto L_80002744;
    }
    // 0x80002738: addiu       $t2, $v1, 0x1
    ctx->r10 = ADD32(ctx->r3, 0X1);
    // 0x8000273C: sw          $t2, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r10;
    // 0x80002740: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
L_80002744:
    // 0x80002744: andi        $t3, $v1, 0xF
    ctx->r11 = ctx->r3 & 0XF;
    // 0x80002748: beq         $t3, $zero, L_8000275C
    if (ctx->r11 == 0) {
        // 0x8000274C: addiu       $at, $zero, -0x10
        ctx->r1 = ADD32(0, -0X10);
            goto L_8000275C;
    }
    // 0x8000274C: addiu       $at, $zero, -0x10
    ctx->r1 = ADD32(0, -0X10);
    // 0x80002750: and         $t4, $v1, $at
    ctx->r12 = ctx->r3 & ctx->r1;
    // 0x80002754: addiu       $v1, $t4, 0x10
    ctx->r3 = ADD32(ctx->r12, 0X10);
    // 0x80002758: sw          $v1, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r3;
L_8000275C:
    // 0x8000275C: addiu       $t6, $v1, -0x10
    ctx->r14 = ADD32(ctx->r3, -0X10);
    // 0x80002760: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80002764: sw          $t6, -0x69D8($at)
    MEM_W(-0X69D8, ctx->r1) = ctx->r14;
    // 0x80002768: addiu       $t7, $v1, 0x70
    ctx->r15 = ADD32(ctx->r3, 0X70);
    // 0x8000276C: sw          $t7, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r15;
    // 0x80002770: lbu         $t8, 0x1C($s3)
    ctx->r24 = MEM_BU(ctx->r19, 0X1C);
    // 0x80002774: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80002778: bne         $t8, $at, L_800027E8
    if (ctx->r24 != ctx->r1) {
        // 0x8000277C: nop
    
            goto L_800027E8;
    }
    // 0x8000277C: nop

    // 0x80002780: jal         0x80076C58
    // 0x80002784: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    asset_table_load(rdram, ctx);
        goto after_1;
    // 0x80002784: addiu       $a0, $zero, 0x26
    ctx->r4 = ADD32(0, 0X26);
    after_1:
    // 0x80002788: lw          $t9, 0x24($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X24);
    // 0x8000278C: lw          $t1, 0x20($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X20);
    // 0x80002790: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x80002794: subu        $s0, $t9, $t1
    ctx->r16 = SUB32(ctx->r25, ctx->r9);
    // 0x80002798: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x8000279C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800027A0: jal         0x80070C9C
    // 0x800027A4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x800027A4: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    after_2:
    // 0x800027A8: lw          $a2, 0x20($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X20);
    // 0x800027AC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x800027B0: addiu       $a0, $zero, 0x27
    ctx->r4 = ADD32(0, 0X27);
    // 0x800027B4: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800027B8: jal         0x80076E68
    // 0x800027BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_3;
    // 0x800027BC: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    after_3:
    // 0x800027C0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800027C4: sw          $s1, 0x20($s3)
    MEM_W(0X20, ctx->r19) = ctx->r17;
    // 0x800027C8: sw          $zero, 0x24($s3)
    MEM_W(0X24, ctx->r19) = 0;
    // 0x800027CC: addiu       $a0, $a0, 0x61D0
    ctx->r4 = ADD32(ctx->r4, 0X61D0);
    // 0x800027D0: jal         0x800C87EC
    // 0x800027D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alInit(rdram, ctx);
        goto after_4;
    // 0x800027D4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_4:
    // 0x800027D8: jal         0x80071140
    // 0x800027DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x800027DC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_5:
    // 0x800027E0: b           L_800027F8
    // 0x800027E4: nop

        goto L_800027F8;
    // 0x800027E4: nop

L_800027E8:
    // 0x800027E8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800027EC: addiu       $a0, $a0, 0x61D0
    ctx->r4 = ADD32(ctx->r4, 0X61D0);
    // 0x800027F0: jal         0x800C87EC
    // 0x800027F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    alInit(rdram, ctx);
        goto after_6;
    // 0x800027F4: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_6:
L_800027F8:
    // 0x800027F8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800027FC: addiu       $v0, $v0, -0x6DC0
    ctx->r2 = ADD32(ctx->r2, -0X6DC0);
    // 0x80002800: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80002804: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80002808: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8000280C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x80002810: addiu       $s0, $s0, -0x6DAC
    ctx->r16 = ADD32(ctx->r16, -0X6DAC);
    // 0x80002814: addiu       $s2, $s2, -0x6DC0
    ctx->r18 = ADD32(ctx->r18, -0X6DC0);
    // 0x80002818: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8000281C:
    // 0x8000281C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80002820: jal         0x800C8790
    // 0x80002824: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_7;
    // 0x80002824: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_7:
    // 0x80002828: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8000282C: addiu       $t2, $zero, 0x400
    ctx->r10 = ADD32(0, 0X400);
    // 0x80002830: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80002834: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80002838: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000283C: jal         0x800C77F0
    // 0x80002840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_8;
    // 0x80002840: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_8:
    // 0x80002844: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80002848: slti        $at, $s1, 0x31
    ctx->r1 = SIGNED(ctx->r17) < 0X31 ? 1 : 0;
    // 0x8000284C: addiu       $s2, $s2, 0x14
    ctx->r18 = ADD32(ctx->r18, 0X14);
    // 0x80002850: addiu       $s0, $s0, 0x14
    ctx->r16 = ADD32(ctx->r16, 0X14);
    // 0x80002854: bne         $at, $zero, L_8000281C
    if (ctx->r1 != 0) {
        // 0x80002858: sw          $v0, -0x4($s2)
        MEM_W(-0X4, ctx->r18) = ctx->r2;
            goto L_8000281C;
    }
    // 0x80002858: sw          $v0, -0x4($s2)
    MEM_W(-0X4, ctx->r18) = ctx->r2;
    // 0x8000285C: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80002860: addiu       $t3, $zero, 0x400
    ctx->r11 = ADD32(0, 0X400);
    // 0x80002864: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80002868: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000286C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002870: jal         0x800C77F0
    // 0x80002874: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_9;
    // 0x80002874: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_9:
    // 0x80002878: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000287C: addiu       $a0, $a0, -0x69C8
    ctx->r4 = ADD32(ctx->r4, -0X69C8);
    // 0x80002880: addiu       $t4, $zero, 0x400
    ctx->r12 = ADD32(0, 0X400);
    // 0x80002884: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80002888: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x8000288C: lh          $a2, 0x0($a0)
    ctx->r6 = MEM_H(ctx->r4, 0X0);
    // 0x80002890: addiu       $t0, $t0, -0x3974
    ctx->r8 = ADD32(ctx->r8, -0X3974);
    // 0x80002894: lui         $t5, 0x8002
    ctx->r13 = S32(0X8002 << 16);
    // 0x80002898: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x8000289C: addiu       $t5, $t5, -0x67F8
    ctx->r13 = ADD32(ctx->r13, -0X67F8);
    // 0x800028A0: sb          $zero, 0x0($t0)
    MEM_B(0X0, ctx->r8) = 0;
    // 0x800028A4: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800028A8: lw          $a1, -0x396C($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X396C);
    // 0x800028AC: subu        $v1, $t5, $a2
    ctx->r3 = SUB32(ctx->r13, ctx->r6);
    // 0x800028B0: addu        $a3, $a2, $v1
    ctx->r7 = ADD32(ctx->r6, ctx->r3);
    // 0x800028B4: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800028B8: blez        $a1, L_800028E8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800028BC: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800028E8;
    }
    // 0x800028BC: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800028C0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800028C4:
    // 0x800028C4: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x800028C8: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x800028CC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800028D0: slt         $at, $s1, $a1
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800028D4: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800028D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800028DC: sh          $t8, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r24;
    // 0x800028E0: bne         $at, $zero, L_800028C4
    if (ctx->r1 != 0) {
        // 0x800028E4: addu        $v1, $v1, $t6
        ctx->r3 = ADD32(ctx->r3, ctx->r14);
            goto L_800028C4;
    }
    // 0x800028E4: addu        $v1, $v1, $t6
    ctx->r3 = ADD32(ctx->r3, ctx->r14);
L_800028E8:
    // 0x800028E8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800028EC: lw          $t9, -0x3970($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X3970);
    // 0x800028F0: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x800028F4: beq         $v1, $t9, L_80002904
    if (ctx->r3 == ctx->r25) {
        // 0x800028F8: addiu       $s0, $s0, 0x5F98
        ctx->r16 = ADD32(ctx->r16, 0X5F98);
            goto L_80002904;
    }
    // 0x800028F8: addiu       $s0, $s0, 0x5F98
    ctx->r16 = ADD32(ctx->r16, 0X5F98);
    // 0x800028FC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80002900: sb          $t1, 0x0($t0)
    MEM_B(0X0, ctx->r8) = ctx->r9;
L_80002904:
    // 0x80002904: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x80002908: addiu       $s1, $s1, 0x5FA0
    ctx->r17 = ADD32(ctx->r17, 0X5FA0);
L_8000290C:
    // 0x8000290C: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x80002910: ori         $t2, $zero, 0xA000
    ctx->r10 = 0 | 0XA000;
    // 0x80002914: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80002918: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000291C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002920: jal         0x800C77F0
    // 0x80002924: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_10;
    // 0x80002924: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_10:
    // 0x80002928: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000292C: sltu        $at, $s0, $s1
    ctx->r1 = ctx->r16 < ctx->r17 ? 1 : 0;
    // 0x80002930: bne         $at, $zero, L_8000290C
    if (ctx->r1 != 0) {
        // 0x80002934: sw          $v0, -0x4($s0)
        MEM_W(-0X4, ctx->r16) = ctx->r2;
            goto L_8000290C;
    }
    // 0x80002934: sw          $v0, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = ctx->r2;
    // 0x80002938: lw          $v0, 0x0($s4)
    ctx->r2 = MEM_W(ctx->r20, 0X0);
    // 0x8000293C: lui         $t4, 0x803F
    ctx->r12 = S32(0X803F << 16);
    // 0x80002940: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x80002944: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x80002948: sll         $a0, $t3, 2
    ctx->r4 = S32(ctx->r11 << 2);
    // 0x8000294C: ori         $t4, $t4, 0xFE00
    ctx->r12 = ctx->r12 | 0XFE00;
    // 0x80002950: lui         $a2, 0xFF
    ctx->r6 = S32(0XFF << 16);
    // 0x80002954: ori         $a2, $a2, 0xFFFF
    ctx->r6 = ctx->r6 | 0XFFFF;
    // 0x80002958: subu        $a1, $t4, $a0
    ctx->r5 = SUB32(ctx->r12, ctx->r4);
    // 0x8000295C: jal         0x80070EF8
    // 0x80002960: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    mempool_alloc_fixed(rdram, ctx);
        goto after_11;
    // 0x80002960: or          $v0, $a0, $zero
    ctx->r2 = ctx->r4 | 0;
    after_11:
    // 0x80002964: lui         $s0, 0x8011
    ctx->r16 = S32(0X8011 << 16);
    // 0x80002968: lui         $s1, 0x8011
    ctx->r17 = S32(0X8011 << 16);
    // 0x8000296C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80002970: addiu       $s1, $s1, 0x5FA4
    ctx->r17 = ADD32(ctx->r17, 0X5FA4);
    // 0x80002974: addiu       $s0, $s0, 0x5F98
    ctx->r16 = ADD32(ctx->r16, 0X5F98);
L_80002978:
    // 0x80002978: lw          $a2, 0x14($s3)
    ctx->r6 = MEM_W(ctx->r19, 0X14);
    // 0x8000297C: addiu       $t5, $zero, 0x78
    ctx->r13 = ADD32(0, 0X78);
    // 0x80002980: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80002984: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x80002988: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000298C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002990: jal         0x800C77F0
    // 0x80002994: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_12;
    // 0x80002994: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_12:
    // 0x80002998: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8000299C: sw          $v0, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->r2;
    // 0x800029A0: sw          $v1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r3;
    // 0x800029A4: lw          $t6, 0x0($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X0);
    // 0x800029A8: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800029AC: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800029B0: bne         $s0, $s1, L_80002978
    if (ctx->r16 != ctx->r17) {
        // 0x800029B4: addu        $v1, $v1, $t7
        ctx->r3 = ADD32(ctx->r3, ctx->r15);
            goto L_80002978;
    }
    // 0x800029B4: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800029B8: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800029BC: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800029C0: addiu       $a1, $a1, 0x61B0
    ctx->r5 = ADD32(ctx->r5, 0X61B0);
    // 0x800029C4: addiu       $a0, $a0, 0x6198
    ctx->r4 = ADD32(ctx->r4, 0X6198);
    // 0x800029C8: jal         0x800C8820
    // 0x800029CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_13;
    // 0x800029CC: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_13:
    // 0x800029D0: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x800029D4: lui         $a1, 0x8011
    ctx->r5 = S32(0X8011 << 16);
    // 0x800029D8: addiu       $a1, $a1, 0x6178
    ctx->r5 = ADD32(ctx->r5, 0X6178);
    // 0x800029DC: addiu       $a0, $a0, 0x6160
    ctx->r4 = ADD32(ctx->r4, 0X6160);
    // 0x800029E0: jal         0x800C8820
    // 0x800029E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_14;
    // 0x800029E4: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    after_14:
    // 0x800029E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800029EC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800029F0: addiu       $a1, $a1, -0x64F8
    ctx->r5 = ADD32(ctx->r5, -0X64F8);
    // 0x800029F4: addiu       $a0, $a0, -0x6510
    ctx->r4 = ADD32(ctx->r4, -0X6510);
    // 0x800029F8: jal         0x800C8820
    // 0x800029FC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_15;
    // 0x800029FC: addiu       $a2, $zero, 0x32
    ctx->r6 = ADD32(0, 0X32);
    after_15:
    // 0x80002A00: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80002A04: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80002A08: addiu       $t8, $t8, -0x6DD0
    ctx->r24 = ADD32(ctx->r24, -0X6DD0);
    // 0x80002A0C: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80002A10: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x80002A14: addiu       $a2, $a2, 0x2A98
    ctx->r6 = ADD32(ctx->r6, 0X2A98);
    // 0x80002A18: addiu       $a0, $a0, 0x5FB0
    ctx->r4 = ADD32(ctx->r4, 0X5FB0);
    // 0x80002A1C: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80002A20: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x80002A24: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80002A28: jal         0x800C8850
    // 0x80002A2C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    osCreateThread_recomp(rdram, ctx);
        goto after_16;
    // 0x80002A2C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    after_16:
    // 0x80002A30: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x80002A34: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80002A38: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x80002A3C: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x80002A40: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x80002A44: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x80002A48: jr          $ra
    // 0x80002A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80002A4C: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void check_for_rumble_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80075CE0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80075CE4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80075CE8: jal         0x800758DC
    // 0x80075CEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80075CEC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    after_0:
    // 0x80075CF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80075CF4: jal         0x80075AEC
    // 0x80075CF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80075CF8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    after_1:
    // 0x80075CFC: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80075D00: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x80075D04: bne         $v1, $at, L_80075D28
    if (ctx->r3 != ctx->r1) {
        // 0x80075D08: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80075D28;
    }
    // 0x80075D08: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80075D0C: lw          $t7, 0x20($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X20);
    // 0x80075D10: addiu       $v0, $v0, 0x41E5
    ctx->r2 = ADD32(ctx->r2, 0X41E5);
    // 0x80075D14: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x80075D18: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80075D1C: sllv        $t9, $t8, $t7
    ctx->r25 = S32(ctx->r24 << (ctx->r15 & 31));
    // 0x80075D20: or          $t0, $t6, $t9
    ctx->r8 = ctx->r14 | ctx->r25;
    // 0x80075D24: sb          $t0, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r8;
L_80075D28:
    // 0x80075D28: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80075D2C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80075D30: jr          $ra
    // 0x80075D34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80075D34: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mode_init_taj_race(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80022948: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8002294C: addiu       $v0, $v0, -0x5109
    ctx->r2 = ADD32(ctx->r2, -0X5109);
    // 0x80022950: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x80022954: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x80022958: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8002295C: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
    // 0x80022960: lb          $t8, 0x0($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X0);
    // 0x80022964: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80022968: bne         $t8, $zero, L_80022CEC
    if (ctx->r24 != 0) {
        // 0x8002296C: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_80022CEC;
    }
    // 0x8002296C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80022970: jal         0x8006BDB0
    // 0x80022974: nop

    level_header(rdram, ctx);
        goto after_0;
    // 0x80022974: nop

    after_0:
    // 0x80022978: sw          $v0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r2;
    // 0x8002297C: lbu         $t9, 0x52($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X52);
    // 0x80022980: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022984: sb          $t9, -0x5108($at)
    MEM_B(-0X5108, ctx->r1) = ctx->r25;
    // 0x80022988: lhu         $t1, 0x54($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0X54);
    // 0x8002298C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022990: addiu       $t2, $zero, 0x1D
    ctx->r10 = ADD32(0, 0X1D);
    // 0x80022994: ori         $t3, $zero, 0xFFFF
    ctx->r11 = 0 | 0XFFFF;
    // 0x80022998: sw          $t1, -0x5104($at)
    MEM_W(-0X5104, ctx->r1) = ctx->r9;
    // 0x8002299C: sb          $t2, 0x52($v0)
    MEM_B(0X52, ctx->r2) = ctx->r10;
    // 0x800229A0: sh          $t3, 0x54($v0)
    MEM_H(0X54, ctx->r2) = ctx->r11;
    // 0x800229A4: jal         0x8001BAC8
    // 0x800229A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_1;
    // 0x800229A8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x800229AC: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x800229B0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800229B4: lb          $t4, 0x1D6($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D6);
    // 0x800229B8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800229BC: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x800229C0: sb          $t5, -0x510A($at)
    MEM_B(-0X510A, ctx->r1) = ctx->r13;
    // 0x800229C4: jal         0x800230D0
    // 0x800229C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    func_800230D0(rdram, ctx);
        goto after_2;
    // 0x800229C8: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_2:
    // 0x800229CC: lh          $t6, 0x1A0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X1A0);
    // 0x800229D0: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x800229D4: subu        $t8, $t7, $t6
    ctx->r24 = SUB32(ctx->r15, ctx->r14);
    // 0x800229D8: sh          $t8, 0x196($s0)
    MEM_H(0X196, ctx->r16) = ctx->r24;
    // 0x800229DC: sb          $zero, 0x1FC($s0)
    MEM_B(0X1FC, ctx->r16) = 0;
    // 0x800229E0: sb          $zero, 0x1F4($s0)
    MEM_B(0X1F4, ctx->r16) = 0;
    // 0x800229E4: sh          $zero, 0x190($s0)
    MEM_H(0X190, ctx->r16) = 0;
    // 0x800229E8: sb          $zero, 0x192($s0)
    MEM_B(0X192, ctx->r16) = 0;
    // 0x800229EC: sb          $zero, 0x193($s0)
    MEM_B(0X193, ctx->r16) = 0;
    // 0x800229F0: sb          $zero, 0x194($s0)
    MEM_B(0X194, ctx->r16) = 0;
    // 0x800229F4: sw          $zero, 0x128($s0)
    MEM_W(0X128, ctx->r16) = 0;
    // 0x800229F8: sw          $zero, 0x12C($s0)
    MEM_W(0X12C, ctx->r16) = 0;
    // 0x800229FC: sw          $zero, 0x130($s0)
    MEM_W(0X130, ctx->r16) = 0;
    // 0x80022A00: sh          $zero, 0x1BA($s0)
    MEM_H(0X1BA, ctx->r16) = 0;
    // 0x80022A04: jal         0x8006EA90
    // 0x80022A08: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_3;
    // 0x80022A08: sw          $v0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r2;
    after_3:
    // 0x80022A0C: addiu       $t9, $zero, 0x50
    ctx->r25 = ADD32(0, 0X50);
    // 0x80022A10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022A14: sw          $t9, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = ctx->r25;
    // 0x80022A18: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022A1C: lw          $v1, 0x68($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X68);
    // 0x80022A20: sw          $zero, -0x524C($at)
    MEM_W(-0X524C, ctx->r1) = 0;
    // 0x80022A24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022A28: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x80022A2C: sw          $v0, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r2;
    // 0x80022A30: sw          $t1, -0x5240($at)
    MEM_W(-0X5240, ctx->r1) = ctx->r9;
    // 0x80022A34: addiu       $t2, $zero, 0x3
    ctx->r10 = ADD32(0, 0X3);
    // 0x80022A38: sb          $t2, 0x4B($v1)
    MEM_B(0X4B, ctx->r3) = ctx->r10;
    // 0x80022A3C: jal         0x8009F034
    // 0x80022A40: sb          $zero, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = 0;
    hud_init_element(rdram, ctx);
        goto after_4;
    // 0x80022A40: sb          $zero, 0x4C($v1)
    MEM_B(0X4C, ctx->r3) = 0;
    after_4:
    // 0x80022A44: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80022A48: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80022A4C: or          $v1, $s0, $zero
    ctx->r3 = ctx->r16 | 0;
L_80022A50:
    // 0x80022A50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80022A54: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80022A58: sw          $zero, 0x128($v1)
    MEM_W(0X128, ctx->r3) = 0;
    // 0x80022A5C: bne         $at, $zero, L_80022A50
    if (ctx->r1 != 0) {
        // 0x80022A60: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80022A50;
    }
    // 0x80022A60: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x80022A64: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x80022A68: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80022A6C: lwc1        $f6, 0x8($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X8);
    // 0x80022A70: lwc1        $f4, 0x10($t0)
    ctx->f4.u32l = MEM_W(ctx->r8, 0X10);
    // 0x80022A74: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80022A78: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x80022A7C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80022A80: nop

    // 0x80022A84: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80022A88: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022A8C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022A90: nop

    // 0x80022A94: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80022A98: mfc1        $t4, $f16
    ctx->r12 = (int32_t)ctx->f16.u32l;
    // 0x80022A9C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80022AA0: sh          $t4, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r12;
    // 0x80022AA4: lwc1        $f6, 0x0($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X0);
    // 0x80022AA8: lwc1        $f18, 0x18($t0)
    ctx->f18.u32l = MEM_W(ctx->r8, 0X18);
    // 0x80022AAC: mul.s       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80022AB0: sll         $t6, $t4, 16
    ctx->r14 = S32(ctx->r12 << 16);
    // 0x80022AB4: sra         $t8, $t6, 16
    ctx->r24 = S32(SIGNED(ctx->r14) >> 16);
    // 0x80022AB8: mtc1        $t8, $f16
    ctx->f16.u32l = ctx->r24;
    // 0x80022ABC: sub.s       $f8, $f18, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f4.fl;
    // 0x80022AC0: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80022AC4: nop

    // 0x80022AC8: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80022ACC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022AD0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022AD4: nop

    // 0x80022AD8: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80022ADC: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x80022AE0: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80022AE4: sll         $t9, $t7, 16
    ctx->r25 = S32(ctx->r15 << 16);
    // 0x80022AE8: sra         $t1, $t9, 16
    ctx->r9 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80022AEC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80022AF0: sh          $t7, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r15;
    // 0x80022AF4: cvt.s.w     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80022AF8: lwc1        $f14, 0x14($t0)
    ctx->f14.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80022AFC: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x80022B00: mfc1        $a2, $f6
    ctx->r6 = (int32_t)ctx->f6.u32l;
    // 0x80022B04: jal         0x80029F18
    // 0x80022B08: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x80022B08: cvt.s.w     $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    ctx->f12.fl = CVT_S_W(ctx->f16.u32l);
    after_5:
    // 0x80022B0C: lh          $t2, 0x5A($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5A);
    // 0x80022B10: lh          $t3, 0x5E($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X5E);
    // 0x80022B14: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x80022B18: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80022B1C: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80022B20: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80022B24: addiu       $a3, $sp, 0x2C
    ctx->r7 = ADD32(ctx->r29, 0X2C);
    // 0x80022B28: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80022B2C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x80022B30: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80022B34: jal         0x8002BAB0
    // 0x80022B38: nop

    collision_get_y(rdram, ctx);
        goto after_6;
    // 0x80022B38: nop

    after_6:
    // 0x80022B3C: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80022B40: beq         $v0, $zero, L_80022B74
    if (ctx->r2 == 0) {
        // 0x80022B44: addiu       $t7, $zero, 0x10
        ctx->r15 = ADD32(0, 0X10);
            goto L_80022B74;
    }
    // 0x80022B44: addiu       $t7, $zero, 0x10
    ctx->r15 = ADD32(0, 0X10);
    // 0x80022B48: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80022B4C: lwc1        $f8, 0x2C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80022B50: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80022B54: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022B58: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022B5C: nop

    // 0x80022B60: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80022B64: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x80022B68: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80022B6C: b           L_80022BA0
    // 0x80022B70: sh          $t4, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r12;
        goto L_80022BA0;
    // 0x80022B70: sh          $t4, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r12;
L_80022B74:
    // 0x80022B74: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x80022B78: lwc1        $f16, 0x14($t0)
    ctx->f16.u32l = MEM_W(ctx->r8, 0X14);
    // 0x80022B7C: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80022B80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80022B84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80022B88: nop

    // 0x80022B8C: cvt.w.s     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80022B90: mfc1        $t8, $f6
    ctx->r24 = (int32_t)ctx->f6.u32l;
    // 0x80022B94: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x80022B98: sh          $t8, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r24;
    // 0x80022B9C: nop

L_80022BA0:
    // 0x80022BA0: sb          $t7, 0x59($sp)
    MEM_B(0X59, ctx->r29) = ctx->r15;
    // 0x80022BA4: lh          $t9, 0x1A0($s0)
    ctx->r25 = MEM_H(ctx->r16, 0X1A0);
    // 0x80022BA8: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
    // 0x80022BAC: addiu       $t2, $zero, 0xDA
    ctx->r10 = ADD32(0, 0XDA);
    // 0x80022BB0: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x80022BB4: sh          $zero, 0x60($sp)
    MEM_H(0X60, ctx->r29) = 0;
    // 0x80022BB8: sh          $t1, 0x66($sp)
    MEM_H(0X66, ctx->r29) = ctx->r9;
    // 0x80022BBC: sb          $t2, 0x58($sp)
    MEM_B(0X58, ctx->r29) = ctx->r10;
    // 0x80022BC0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80022BC4: jal         0x800619F4
    // 0x80022BC8: sh          $t9, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r25;
    model_anim_offset(rdram, ctx);
        goto after_7;
    // 0x80022BC8: sh          $t9, 0x64($sp)
    MEM_H(0X64, ctx->r29) = ctx->r25;
    after_7:
    // 0x80022BCC: addiu       $a0, $sp, 0x58
    ctx->r4 = ADD32(ctx->r29, 0X58);
    // 0x80022BD0: jal         0x8000EA54
    // 0x80022BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_8;
    // 0x80022BD4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_8:
    // 0x80022BD8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80022BDC: lw          $t3, -0x511C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X511C);
    // 0x80022BE0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80022BE4: sw          $v0, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r2;
    // 0x80022BE8: lw          $t5, -0x5118($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5118);
    // 0x80022BEC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80022BF0: sw          $v0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r2;
    // 0x80022BF4: lw          $t4, -0x5114($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X5114);
    // 0x80022BF8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80022BFC: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80022C00: sw          $v0, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r2;
    // 0x80022C04: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80022C08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80022C0C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80022C10: sw          $t6, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = ctx->r14;
    // 0x80022C14: lw          $s0, 0x64($v0)
    ctx->r16 = MEM_W(ctx->r2, 0X64);
    // 0x80022C18: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x80022C1C: sb          $t8, 0x1D6($s0)
    MEM_B(0X1D6, ctx->r16) = ctx->r24;
    // 0x80022C20: lb          $t7, 0x1D6($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D6);
    // 0x80022C24: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80022C28: sb          $t9, 0x2($s0)
    MEM_B(0X2, ctx->r16) = ctx->r25;
    // 0x80022C2C: sb          $t7, 0x1D7($s0)
    MEM_B(0X1D7, ctx->r16) = ctx->r15;
    // 0x80022C30: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x80022C34: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80022C38: lb          $t2, 0x59($t1)
    ctx->r10 = MEM_B(ctx->r9, 0X59);
    // 0x80022C3C: swc1        $f0, 0x90($s0)
    MEM_W(0X90, ctx->r16) = ctx->f0.u32l;
    // 0x80022C40: swc1        $f0, 0x8C($s0)
    MEM_W(0X8C, ctx->r16) = ctx->f0.u32l;
    // 0x80022C44: sb          $t3, 0x1F7($s0)
    MEM_B(0X1F7, ctx->r16) = ctx->r11;
    // 0x80022C48: sw          $zero, 0x118($s0)
    MEM_W(0X118, ctx->r16) = 0;
    // 0x80022C4C: sb          $t2, 0x3($s0)
    MEM_B(0X3, ctx->r16) = ctx->r10;
    // 0x80022C50: lw          $t4, 0x4C($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4C);
    // 0x80022C54: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x80022C58: sb          $t5, 0x12($t4)
    MEM_B(0X12, ctx->r12) = ctx->r13;
    // 0x80022C5C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80022C60: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80022C64: lw          $a1, -0x51A4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X51A4);
    // 0x80022C68: lw          $a0, -0x51A0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X51A0);
    // 0x80022C6C: addiu       $a3, $zero, 0x3E
    ctx->r7 = ADD32(0, 0X3E);
    // 0x80022C70: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022C74: beq         $at, $zero, L_80022CD8
    if (ctx->r1 == 0) {
        // 0x80022C78: sll         $v1, $a0, 2
        ctx->r3 = S32(ctx->r4 << 2);
            goto L_80022CD8;
    }
    // 0x80022C78: sll         $v1, $a0, 2
    ctx->r3 = S32(ctx->r4 << 2);
    // 0x80022C7C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80022C80: addiu       $a2, $a2, -0x51A8
    ctx->r6 = ADD32(ctx->r6, -0X51A8);
L_80022C84:
    // 0x80022C84: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x80022C88: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80022C8C: addu        $t8, $t6, $v1
    ctx->r24 = ADD32(ctx->r14, ctx->r3);
    // 0x80022C90: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x80022C94: nop

    // 0x80022C98: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x80022C9C: nop

    // 0x80022CA0: andi        $t9, $t7, 0x8000
    ctx->r25 = ctx->r15 & 0X8000;
    // 0x80022CA4: bne         $t9, $zero, L_80022CD0
    if (ctx->r25 != 0) {
        // 0x80022CA8: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80022CD0;
    }
    // 0x80022CA8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022CAC: lh          $t1, 0x48($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X48);
    // 0x80022CB0: nop

    // 0x80022CB4: bne         $a3, $t1, L_80022CD0
    if (ctx->r7 != ctx->r9) {
        // 0x80022CB8: slt         $at, $a0, $a1
        ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80022CD0;
    }
    // 0x80022CB8: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80022CBC: sw          $v0, 0x154($s0)
    MEM_W(0X154, ctx->r16) = ctx->r2;
    // 0x80022CC0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80022CC4: lw          $a1, -0x51A4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X51A4);
    // 0x80022CC8: nop

    // 0x80022CCC: slt         $at, $a0, $a1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r5) ? 1 : 0;
L_80022CD0:
    // 0x80022CD0: bne         $at, $zero, L_80022C84
    if (ctx->r1 != 0) {
        // 0x80022CD4: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_80022C84;
    }
    // 0x80022CD4: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_80022CD8:
    // 0x80022CD8: jal         0x8006F388
    // 0x80022CDC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    set_pause_lockout_timer(rdram, ctx);
        goto after_9;
    // 0x80022CDC: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_9:
    // 0x80022CE0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80022CE4: jal         0x800C01D8
    // 0x80022CE8: addiu       $a0, $a0, -0x3910
    ctx->r4 = ADD32(ctx->r4, -0X3910);
    transition_begin(rdram, ctx);
        goto after_10;
    // 0x80022CE8: addiu       $a0, $a0, -0x3910
    ctx->r4 = ADD32(ctx->r4, -0X3910);
    after_10:
L_80022CEC:
    // 0x80022CEC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80022CF0: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80022CF4: jr          $ra
    // 0x80022CF8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x80022CF8: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void race_finish_adventure(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_netplay_adventure_finish_barrier(uint8_t*, recomp_context*); dkr_netplay_adventure_finish_barrier(rdram, ctx);
    // 0x8001A8D4: addiu       $t6, $zero, 0x12C
    ctx->r14 = ADD32(0, 0X12C);
    // 0x8001A8D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A8DC: sh          $t6, -0x52B2($at)
    MEM_H(-0X52B2, ctx->r1) = ctx->r14;
    // 0x8001A8E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A8E4: sb          $zero, -0x52B0($at)
    MEM_B(-0X52B0, ctx->r1) = 0;
    // 0x8001A8E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001A8EC: jr          $ra
    // 0x8001A8F0: sb          $a0, -0x52AE($at)
    MEM_B(-0X52AE, ctx->r1) = ctx->r4;
    return;
    // 0x8001A8F0: sb          $a0, -0x52AE($at)
    MEM_B(-0X52AE, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void material_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007D0F4: addiu       $sp, $sp, -0x280
    ctx->r29 = ADD32(ctx->r29, -0X280);
    // 0x8007D0F8: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007D0FC: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8007D100: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8007D104: sw          $a1, 0x284($sp)
    MEM_W(0X284, ctx->r29) = ctx->r5;
    // 0x8007D108: lbu         $v1, 0x2($a0)
    ctx->r3 = MEM_BU(ctx->r4, 0X2);
    // 0x8007D10C: sw          $a1, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r5;
    // 0x8007D110: sra         $t7, $v1, 4
    ctx->r15 = S32(SIGNED(ctx->r3) >> 4);
    // 0x8007D114: andi        $t8, $t7, 0xF
    ctx->r24 = ctx->r15 & 0XF;
    // 0x8007D118: sw          $t8, 0x278($sp)
    MEM_W(0X278, ctx->r29) = ctx->r24;
    // 0x8007D11C: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8007D120: lbu         $s0, 0x1($a0)
    ctx->r16 = MEM_BU(ctx->r4, 0X1);
    // 0x8007D124: lbu         $t5, 0x0($a0)
    ctx->r13 = MEM_BU(ctx->r4, 0X0);
    // 0x8007D128: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8007D12C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007D130: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8007D134: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8007D138: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x8007D13C: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8007D140: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8007D144: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8007D148: andi        $t4, $v1, 0xF
    ctx->r12 = ctx->r3 & 0XF;
L_8007D14C:
    // 0x8007D14C: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8007D150: beq         $at, $zero, L_8007D160
    if (ctx->r1 == 0) {
        // 0x8007D154: sll         $t7, $v0, 1
        ctx->r15 = S32(ctx->r2 << 1);
            goto L_8007D160;
    }
    // 0x8007D154: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x8007D158: b           L_8007D16C
    // 0x8007D15C: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
        goto L_8007D16C;
    // 0x8007D15C: addiu       $t2, $a2, 0x1
    ctx->r10 = ADD32(ctx->r6, 0X1);
L_8007D160:
    // 0x8007D160: bne         $v0, $t5, L_8007D170
    if (ctx->r2 != ctx->r13) {
        // 0x8007D164: slt         $at, $v0, $s0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
            goto L_8007D170;
    }
    // 0x8007D164: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
    // 0x8007D168: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8007D16C:
    // 0x8007D16C: slt         $at, $v0, $s0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r16) ? 1 : 0;
L_8007D170:
    // 0x8007D170: beq         $at, $zero, L_8007D180
    if (ctx->r1 == 0) {
        // 0x8007D174: addiu       $v1, $a2, 0x1
        ctx->r3 = ADD32(ctx->r6, 0X1);
            goto L_8007D180;
    }
    // 0x8007D174: addiu       $v1, $a2, 0x1
    ctx->r3 = ADD32(ctx->r6, 0X1);
    // 0x8007D178: b           L_8007D18C
    // 0x8007D17C: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
        goto L_8007D18C;
    // 0x8007D17C: or          $t3, $v1, $zero
    ctx->r11 = ctx->r3 | 0;
L_8007D180:
    // 0x8007D180: bne         $v0, $s0, L_8007D190
    if (ctx->r2 != ctx->r16) {
        // 0x8007D184: or          $a2, $v1, $zero
        ctx->r6 = ctx->r3 | 0;
            goto L_8007D190;
    }
    // 0x8007D184: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
    // 0x8007D188: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
L_8007D18C:
    // 0x8007D18C: or          $a2, $v1, $zero
    ctx->r6 = ctx->r3 | 0;
L_8007D190:
    // 0x8007D190: bne         $v1, $a0, L_8007D14C
    if (ctx->r3 != ctx->r4) {
        // 0x8007D194: or          $v0, $t7, $zero
        ctx->r2 = ctx->r15 | 0;
            goto L_8007D14C;
    }
    // 0x8007D194: or          $v0, $t7, $zero
    ctx->r2 = ctx->r15 | 0;
    // 0x8007D198: bne         $t0, $zero, L_8007D1B4
    if (ctx->r8 != 0) {
        // 0x8007D19C: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8007D1B4;
    }
    // 0x8007D19C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8007D1A0: lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X6);
    // 0x8007D1A4: nop

    // 0x8007D1A8: andi        $t8, $v0, 0x40
    ctx->r24 = ctx->r2 & 0X40;
    // 0x8007D1AC: beq         $t8, $zero, L_8007D1C4
    if (ctx->r24 == 0) {
        // 0x8007D1B0: nop
    
            goto L_8007D1C4;
    }
    // 0x8007D1B0: nop

L_8007D1B4:
    // 0x8007D1B4: sw          $t9, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = ctx->r25;
    // 0x8007D1B8: lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X6);
    // 0x8007D1BC: b           L_8007D1C8
    // 0x8007D1C0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
        goto L_8007D1C8;
    // 0x8007D1C0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8007D1C4:
    // 0x8007D1C4: sw          $zero, 0x26C($sp)
    MEM_W(0X26C, ctx->r29) = 0;
L_8007D1C8:
    // 0x8007D1C8: bne         $t1, $zero, L_8007D1D8
    if (ctx->r9 != 0) {
        // 0x8007D1CC: andi        $t8, $v0, 0x400
        ctx->r24 = ctx->r2 & 0X400;
            goto L_8007D1D8;
    }
    // 0x8007D1CC: andi        $t8, $v0, 0x400
    ctx->r24 = ctx->r2 & 0X400;
    // 0x8007D1D0: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x8007D1D4: beq         $t6, $zero, L_8007D1E8
    if (ctx->r14 == 0) {
        // 0x8007D1D8: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_8007D1E8;
    }
L_8007D1D8:
    // 0x8007D1D8: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8007D1DC: sw          $t7, 0x268($sp)
    MEM_W(0X268, ctx->r29) = ctx->r15;
    // 0x8007D1E0: b           L_8007D1EC
    // 0x8007D1E4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
        goto L_8007D1EC;
    // 0x8007D1E4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
L_8007D1E8:
    // 0x8007D1E8: sw          $zero, 0x268($sp)
    MEM_W(0X268, ctx->r29) = 0;
L_8007D1EC:
    // 0x8007D1EC: bne         $t8, $zero, L_8007E24C
    if (ctx->r24 != 0) {
        // 0x8007D1F0: nop
    
            goto L_8007E24C;
    }
    // 0x8007D1F0: nop

    // 0x8007D1F4: sw          $t2, 0x264($sp)
    MEM_W(0X264, ctx->r29) = ctx->r10;
    // 0x8007D1F8: sw          $t3, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r11;
    // 0x8007D1FC: bne         $t4, $zero, L_8007D3EC
    if (ctx->r12 != 0) {
        // 0x8007D200: sw          $t4, 0x27C($sp)
        MEM_W(0X27C, ctx->r29) = ctx->r12;
            goto L_8007D3EC;
    }
    // 0x8007D200: sw          $t4, 0x27C($sp)
    MEM_W(0X27C, ctx->r29) = ctx->r12;
    // 0x8007D204: lw          $t2, 0x284($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X284);
    // 0x8007D208: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D20C: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007D210: addu        $t6, $s1, $at
    ctx->r14 = ADD32(ctx->r17, ctx->r1);
    // 0x8007D214: lui         $t9, 0xFD18
    ctx->r25 = S32(0XFD18 << 16);
    // 0x8007D218: addiu       $a3, $t2, 0x8
    ctx->r7 = ADD32(ctx->r10, 0X8);
    // 0x8007D21C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007D220: lui         $t7, 0xF518
    ctx->r15 = S32(0XF518 << 16);
    // 0x8007D224: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007D228: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8007D22C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D230: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8007D234: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007D238: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007D23C: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007D240: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8007D244: sll         $v0, $t8, 18
    ctx->r2 = S32(ctx->r24 << 18);
    // 0x8007D248: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007D24C: andi        $t8, $a1, 0x3
    ctx->r24 = ctx->r5 & 0X3;
    // 0x8007D250: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8007D254: sll         $v1, $t6, 14
    ctx->r3 = S32(ctx->r14 << 14);
    // 0x8007D258: sll         $a1, $t8, 8
    ctx->r5 = S32(ctx->r24 << 8);
    // 0x8007D25C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D260: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8007D264: andi        $t6, $a2, 0xF
    ctx->r14 = ctx->r6 & 0XF;
    // 0x8007D268: sll         $a2, $t6, 4
    ctx->r6 = S32(ctx->r14 << 4);
    // 0x8007D26C: or          $t9, $t8, $v1
    ctx->r25 = ctx->r24 | ctx->r3;
    // 0x8007D270: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x8007D274: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007D278: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D27C: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007D280: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8007D284: mflo        $t0
    ctx->r8 = lo;
    // 0x8007D288: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007D28C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D290: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8007D294: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007D298: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8007D29C: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007D2A0: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007D2A4: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007D2A8: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8007D2AC: beq         $at, $zero, L_8007D2BC
    if (ctx->r1 == 0) {
        // 0x8007D2B0: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007D2BC;
    }
    // 0x8007D2B0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D2B4: b           L_8007D2C0
    // 0x8007D2B8: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007D2C0;
    // 0x8007D2B8: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007D2BC:
    // 0x8007D2BC: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007D2C0:
    // 0x8007D2C0: sll         $t0, $t5, 2
    ctx->r8 = S32(ctx->r13 << 2);
    // 0x8007D2C4: bgez        $t0, L_8007D2D4
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8007D2C8: sra         $t6, $t0, 3
        ctx->r14 = S32(SIGNED(ctx->r8) >> 3);
            goto L_8007D2D4;
    }
    // 0x8007D2C8: sra         $t6, $t0, 3
    ctx->r14 = S32(SIGNED(ctx->r8) >> 3);
    // 0x8007D2CC: addiu       $at, $t0, 0x7
    ctx->r1 = ADD32(ctx->r8, 0X7);
    // 0x8007D2D0: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8007D2D4:
    // 0x8007D2D4: bgtz        $t6, L_8007D2E4
    if (SIGNED(ctx->r14) > 0) {
        // 0x8007D2D8: or          $t0, $t6, $zero
        ctx->r8 = ctx->r14 | 0;
            goto L_8007D2E4;
    }
    // 0x8007D2D8: or          $t0, $t6, $zero
    ctx->r8 = ctx->r14 | 0;
    // 0x8007D2DC: b           L_8007D2E8
    // 0x8007D2E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007D2E8;
    // 0x8007D2E0: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007D2E4:
    // 0x8007D2E4: or          $t2, $t0, $zero
    ctx->r10 = ctx->r8 | 0;
L_8007D2E8:
    // 0x8007D2E8: bgtz        $t0, L_8007D2F8
    if (SIGNED(ctx->r8) > 0) {
        // 0x8007D2EC: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8007D2F8;
    }
    // 0x8007D2EC: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8007D2F0: b           L_8007D2FC
    // 0x8007D2F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007D2FC;
    // 0x8007D2F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007D2F8:
    // 0x8007D2F8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007D2FC:
    // 0x8007D2FC: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x8007D300: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007D304: bne         $a0, $zero, L_8007D310
    if (ctx->r4 != 0) {
        // 0x8007D308: nop
    
            goto L_8007D310;
    }
    // 0x8007D308: nop

    // 0x8007D30C: break       7
    do_break(2147996428);
L_8007D310:
    // 0x8007D310: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007D314: bne         $a0, $at, L_8007D328
    if (ctx->r4 != ctx->r1) {
        // 0x8007D318: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007D328;
    }
    // 0x8007D318: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D31C: bne         $t7, $at, L_8007D328
    if (ctx->r15 != ctx->r1) {
        // 0x8007D320: nop
    
            goto L_8007D328;
    }
    // 0x8007D320: nop

    // 0x8007D324: break       6
    do_break(2147996452);
L_8007D328:
    // 0x8007D328: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D32C: andi        $t7, $ra, 0xFFF
    ctx->r15 = ctx->r31 & 0XFFF;
    // 0x8007D330: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D334: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007D338: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D33C: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007D340: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D344: mflo        $t8
    ctx->r24 = lo;
    // 0x8007D348: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8007D34C: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007D350: sll         $t8, $t7, 12
    ctx->r24 = S32(ctx->r15 << 12);
    // 0x8007D354: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007D358: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8007D35C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8007D360: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x8007D364: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007D368: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8007D36C: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007D370: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8007D374: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x8007D378: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007D37C: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x8007D380: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8007D384: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007D388: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007D38C: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007D390: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007D394: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007D398: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007D39C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007D3A0: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007D3A4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007D3A8: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007D3AC: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007D3B0: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007D3B4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007D3B8: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007D3BC: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007D3C0: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007D3C4: lw          $t7, 0x278($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X278);
    // 0x8007D3C8: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007D3CC: beq         $t7, $zero, L_8007D3DC
    if (ctx->r15 == 0) {
        // 0x8007D3D0: nop
    
            goto L_8007D3DC;
    }
    // 0x8007D3D0: nop

    // 0x8007D3D4: bne         $t7, $at, L_8007D3F0
    if (ctx->r15 != ctx->r1) {
        // 0x8007D3D8: lw          $t9, 0x27C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X27C);
            goto L_8007D3F0;
    }
    // 0x8007D3D8: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007D3DC:
    // 0x8007D3DC: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007D3E0: nop

    // 0x8007D3E4: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007D3E8: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007D3EC:
    // 0x8007D3EC: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007D3F0:
    // 0x8007D3F0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007D3F4: bne         $t9, $at, L_8007D5F8
    if (ctx->r25 != ctx->r1) {
        // 0x8007D3F8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007D5F8;
    }
    // 0x8007D3F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007D3FC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D400: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007D404: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007D408: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007D40C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D410: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8007D414: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007D418: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007D41C: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8007D420: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007D424: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007D428: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007D42C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007D430: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007D434: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007D438: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007D43C: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007D440: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007D444: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007D448: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007D44C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D450: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007D454: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x8007D458: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007D45C: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x8007D460: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x8007D464: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007D468: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D46C: or          $t6, $t8, $t6
    ctx->r14 = ctx->r24 | ctx->r14;
    // 0x8007D470: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D474: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007D478: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007D47C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007D480: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x8007D484: addiu       $t8, $t4, 0x7
    ctx->r24 = ADD32(ctx->r12, 0X7);
    // 0x8007D488: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007D48C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D490: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007D494: sra         $t6, $t8, 3
    ctx->r14 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007D498: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007D49C: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007D4A0: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8007D4A4: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007D4A8: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8007D4AC: or          $t8, $v0, $v1
    ctx->r24 = ctx->r2 | ctx->r3;
    // 0x8007D4B0: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007D4B4: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007D4B8: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007D4BC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D4C0: or          $t9, $t6, $a2
    ctx->r25 = ctx->r14 | ctx->r6;
    // 0x8007D4C4: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007D4C8: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007D4CC: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007D4D0: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8007D4D4: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8007D4D8: mflo        $t0
    ctx->r8 = lo;
    // 0x8007D4DC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007D4E0: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007D4E4: or          $t7, $t9, $t6
    ctx->r15 = ctx->r25 | ctx->r14;
    // 0x8007D4E8: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007D4EC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007D4F0: sw          $t3, 0x21C($sp)
    MEM_W(0X21C, ctx->r29) = ctx->r11;
    // 0x8007D4F4: beq         $at, $zero, L_8007D504
    if (ctx->r1 == 0) {
        // 0x8007D4F8: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007D504;
    }
    // 0x8007D4F8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D4FC: b           L_8007D508
    // 0x8007D500: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007D508;
    // 0x8007D500: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007D504:
    // 0x8007D504: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007D508:
    // 0x8007D508: bgez        $t4, L_8007D518
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007D50C: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007D518;
    }
    // 0x8007D50C: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007D510: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007D514: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007D518:
    // 0x8007D518: bgtz        $t3, L_8007D528
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007D51C: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007D528;
    }
    // 0x8007D51C: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007D520: b           L_8007D528
    // 0x8007D524: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007D528;
    // 0x8007D524: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007D528:
    // 0x8007D528: bgtz        $t3, L_8007D538
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007D52C: addiu       $t8, $t2, 0x7FF
        ctx->r24 = ADD32(ctx->r10, 0X7FF);
            goto L_8007D538;
    }
    // 0x8007D52C: addiu       $t8, $t2, 0x7FF
    ctx->r24 = ADD32(ctx->r10, 0X7FF);
    // 0x8007D530: b           L_8007D53C
    // 0x8007D534: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007D53C;
    // 0x8007D534: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007D538:
    // 0x8007D538: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_8007D53C:
    // 0x8007D53C: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x8007D540: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007D544: bne         $a0, $zero, L_8007D550
    if (ctx->r4 != 0) {
        // 0x8007D548: nop
    
            goto L_8007D550;
    }
    // 0x8007D548: nop

    // 0x8007D54C: break       7
    do_break(2147997004);
L_8007D550:
    // 0x8007D550: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007D554: bne         $a0, $at, L_8007D568
    if (ctx->r4 != ctx->r1) {
        // 0x8007D558: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007D568;
    }
    // 0x8007D558: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D55C: bne         $t8, $at, L_8007D568
    if (ctx->r24 != ctx->r1) {
        // 0x8007D560: nop
    
            goto L_8007D568;
    }
    // 0x8007D560: nop

    // 0x8007D564: break       6
    do_break(2147997028);
L_8007D568:
    // 0x8007D568: andi        $t8, $ra, 0xFFF
    ctx->r24 = ctx->r31 & 0XFFF;
    // 0x8007D56C: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D570: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D574: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007D578: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D57C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007D580: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D584: mflo        $t9
    ctx->r25 = lo;
    // 0x8007D588: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007D58C: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007D590: lw          $t8, 0x21C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X21C);
    // 0x8007D594: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007D598: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8007D59C: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8007D5A0: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007D5A4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007D5A8: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007D5AC: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007D5B0: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8007D5B4: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007D5B8: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007D5BC: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D5C0: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007D5C4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007D5C8: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007D5CC: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007D5D0: lw          $v0, 0x278($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X278);
    // 0x8007D5D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007D5D8: beq         $v0, $zero, L_8007D5E8
    if (ctx->r2 == 0) {
        // 0x8007D5DC: sw          $t9, 0x4($a1)
        MEM_W(0X4, ctx->r5) = ctx->r25;
            goto L_8007D5E8;
    }
    // 0x8007D5DC: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8007D5E0: bne         $v0, $at, L_8007D5FC
    if (ctx->r2 != ctx->r1) {
        // 0x8007D5E4: lw          $t7, 0x27C($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X27C);
            goto L_8007D5FC;
    }
    // 0x8007D5E4: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
L_8007D5E8:
    // 0x8007D5E8: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8007D5EC: nop

    // 0x8007D5F0: ori         $t8, $t6, 0x4
    ctx->r24 = ctx->r14 | 0X4;
    // 0x8007D5F4: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
L_8007D5F8:
    // 0x8007D5F8: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
L_8007D5FC:
    // 0x8007D5FC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007D600: bne         $t7, $at, L_8007D8A4
    if (ctx->r15 != ctx->r1) {
        // 0x8007D604: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007D8A4;
    }
    // 0x8007D604: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007D608: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007D60C: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007D610: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007D614: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D618: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007D61C: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007D620: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007D624: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007D628: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007D62C: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007D630: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007D634: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D638: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007D63C: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007D640: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D644: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007D648: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007D64C: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007D650: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007D654: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x8007D658: sw          $t9, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r25;
    // 0x8007D65C: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007D660: or          $t9, $t7, $a2
    ctx->r25 = ctx->r15 | ctx->r6;
    // 0x8007D664: or          $t6, $v0, $v1
    ctx->r14 = ctx->r2 | ctx->r3;
    // 0x8007D668: or          $t8, $t6, $a1
    ctx->r24 = ctx->r14 | ctx->r5;
    // 0x8007D66C: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x8007D670: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007D674: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007D678: or          $t7, $t8, $a2
    ctx->r15 = ctx->r24 | ctx->r6;
    // 0x8007D67C: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8007D680: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007D684: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007D688: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x8007D68C: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8007D690: andi        $t8, $t6, 0xFFF
    ctx->r24 = ctx->r14 & 0XFFF;
    // 0x8007D694: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x8007D698: mflo        $t2
    ctx->r10 = lo;
    // 0x8007D69C: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8007D6A0: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007D6A4: sw          $t5, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r13;
    // 0x8007D6A8: jal         0x8007EF64
    // 0x8007D6AC: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    tex_palette_id(rdram, ctx);
        goto after_0;
    // 0x8007D6AC: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    after_0:
    // 0x8007D6B0: lw          $a3, 0x248($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X248);
    // 0x8007D6B4: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007D6B8: lw          $t5, 0x274($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X274);
    // 0x8007D6BC: lui         $t6, 0xFD50
    ctx->r14 = S32(0XFD50 << 16);
    // 0x8007D6C0: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007D6C4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007D6C8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x8007D6CC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D6D0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007D6D4: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8007D6D8: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007D6DC: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007D6E0: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8007D6E4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D6E8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007D6EC: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x8007D6F0: sra         $t8, $t0, 2
    ctx->r24 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007D6F4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007D6F8: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007D6FC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D700: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007D704: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007D708: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007D70C: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007D710: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007D714: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007D718: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8007D71C: beq         $at, $zero, L_8007D72C
    if (ctx->r1 == 0) {
        // 0x8007D720: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007D72C;
    }
    // 0x8007D720: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D724: b           L_8007D730
    // 0x8007D728: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007D730;
    // 0x8007D728: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007D72C:
    // 0x8007D72C: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007D730:
    // 0x8007D730: bgez        $t5, L_8007D740
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007D734: sra         $t1, $t5, 4
        ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
            goto L_8007D740;
    }
    // 0x8007D734: sra         $t1, $t5, 4
    ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8007D738: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x8007D73C: sra         $t1, $at, 4
    ctx->r9 = S32(SIGNED(ctx->r1) >> 4);
L_8007D740:
    // 0x8007D740: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8007D744: div         $zero, $t8, $t1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r9)));
    // 0x8007D748: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007D74C: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007D750: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D754: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007D758: bne         $t1, $zero, L_8007D764
    if (ctx->r9 != 0) {
        // 0x8007D75C: nop
    
            goto L_8007D764;
    }
    // 0x8007D75C: nop

    // 0x8007D760: break       7
    do_break(2147997536);
L_8007D764:
    // 0x8007D764: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007D768: bne         $t1, $at, L_8007D77C
    if (ctx->r9 != ctx->r1) {
        // 0x8007D76C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007D77C;
    }
    // 0x8007D76C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D770: bne         $t8, $at, L_8007D77C
    if (ctx->r24 != ctx->r1) {
        // 0x8007D774: nop
    
            goto L_8007D77C;
    }
    // 0x8007D774: nop

    // 0x8007D778: break       6
    do_break(2147997560);
L_8007D77C:
    // 0x8007D77C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007D780: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D784: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8007D788: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007D78C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D790: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007D794: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D798: mflo        $t9
    ctx->r25 = lo;
    // 0x8007D79C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007D7A0: or          $t8, $t7, $t6
    ctx->r24 = ctx->r15 | ctx->r14;
    // 0x8007D7A4: sw          $t8, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r24;
    // 0x8007D7A8: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007D7AC: addiu       $t6, $t7, 0x7
    ctx->r14 = ADD32(ctx->r15, 0X7);
    // 0x8007D7B0: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007D7B4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007D7B8: sra         $t8, $t6, 3
    ctx->r24 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8007D7BC: andi        $t9, $t8, 0x1FF
    ctx->r25 = ctx->r24 & 0X1FF;
    // 0x8007D7C0: sll         $t7, $t9, 9
    ctx->r15 = S32(ctx->r25 << 9);
    // 0x8007D7C4: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8007D7C8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007D7CC: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007D7D0: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007D7D4: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007D7D8: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007D7DC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007D7E0: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007D7E4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007D7E8: sw          $t7, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r15;
    // 0x8007D7EC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D7F0: lui         $t6, 0xFD10
    ctx->r14 = S32(0XFD10 << 16);
    // 0x8007D7F4: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007D7F8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007D7FC: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8007D800: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D804: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007D808: lui         $t8, 0xE800
    ctx->r24 = S32(0XE800 << 16);
    // 0x8007D80C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007D810: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007D814: lui         $t9, 0xF500
    ctx->r25 = S32(0XF500 << 16);
    // 0x8007D818: ori         $t9, $t9, 0x100
    ctx->r25 = ctx->r25 | 0X100;
    // 0x8007D81C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D820: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8007D824: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007D828: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007D82C: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007D830: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D834: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007D838: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8007D83C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007D840: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8007D844: lw          $a0, 0x278($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X278);
    // 0x8007D848: lui         $t9, 0x703
    ctx->r25 = S32(0X703 << 16);
    // 0x8007D84C: ori         $t9, $t9, 0xC000
    ctx->r25 = ctx->r25 | 0XC000;
    // 0x8007D850: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D854: lui         $t8, 0xF000
    ctx->r24 = S32(0XF000 << 16);
    // 0x8007D858: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007D85C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007D860: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x8007D864: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007D868: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007D86C: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007D870: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8007D874: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D878: ori         $t8, $t6, 0x20
    ctx->r24 = ctx->r14 | 0X20;
    // 0x8007D87C: beq         $a0, $zero, L_8007D890
    if (ctx->r4 == 0) {
        // 0x8007D880: sh          $t8, 0x6($s1)
        MEM_H(0X6, ctx->r17) = ctx->r24;
            goto L_8007D890;
    }
    // 0x8007D880: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
    // 0x8007D884: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007D888: bne         $a0, $at, L_8007D8A4
    if (ctx->r4 != ctx->r1) {
        // 0x8007D88C: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007D8A4;
    }
    // 0x8007D88C: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007D890:
    // 0x8007D890: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007D894: nop

    // 0x8007D898: ori         $t7, $t9, 0x4
    ctx->r15 = ctx->r25 | 0X4;
    // 0x8007D89C: sh          $t7, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r15;
    // 0x8007D8A0: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007D8A4:
    // 0x8007D8A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007D8A8: bne         $t6, $at, L_8007DA9C
    if (ctx->r14 != ctx->r1) {
        // 0x8007D8AC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007DA9C;
    }
    // 0x8007D8AC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007D8B0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007D8B4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007D8B8: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007D8BC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007D8C0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D8C4: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8007D8C8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007D8CC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007D8D0: lui         $t7, 0xF570
    ctx->r15 = S32(0XF570 << 16);
    // 0x8007D8D4: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8007D8D8: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007D8DC: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007D8E0: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007D8E4: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007D8E8: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007D8EC: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007D8F0: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x8007D8F4: sll         $v1, $t9, 14
    ctx->r3 = S32(ctx->r25 << 14);
    // 0x8007D8F8: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007D8FC: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007D900: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007D904: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007D908: sll         $t7, $t9, 4
    ctx->r15 = S32(ctx->r25 << 4);
    // 0x8007D90C: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007D910: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007D914: or          $t9, $t8, $a1
    ctx->r25 = ctx->r24 | ctx->r5;
    // 0x8007D918: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8007D91C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007D920: or          $t7, $t9, $t7
    ctx->r15 = ctx->r25 | ctx->r15;
    // 0x8007D924: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D928: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007D92C: sw          $t7, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r15;
    // 0x8007D930: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007D934: sll         $t4, $t5, 1
    ctx->r12 = S32(ctx->r13 << 1);
    // 0x8007D938: addiu       $t9, $t4, 0x7
    ctx->r25 = ADD32(ctx->r12, 0X7);
    // 0x8007D93C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007D940: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D944: or          $ra, $a3, $zero
    ctx->r31 = ctx->r7 | 0;
    // 0x8007D948: sra         $t7, $t9, 3
    ctx->r15 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007D94C: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007D950: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007D954: sw          $t8, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r24;
    // 0x8007D958: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8007D95C: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8007D960: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007D964: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007D968: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8007D96C: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007D970: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007D974: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007D978: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8007D97C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007D980: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007D984: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8007D988: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007D98C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007D990: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007D994: andi        $t7, $t9, 0xFFF
    ctx->r15 = ctx->r25 & 0XFFF;
    // 0x8007D998: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x8007D99C: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007D9A0: sw          $ra, 0x1CC($sp)
    MEM_W(0X1CC, ctx->r29) = ctx->r31;
    // 0x8007D9A4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007D9A8: bgez        $t4, L_8007D9B8
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007D9AC: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007D9B8;
    }
    // 0x8007D9AC: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007D9B0: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007D9B4: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007D9B8:
    // 0x8007D9B8: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007D9BC: beq         $at, $zero, L_8007D9CC
    if (ctx->r1 == 0) {
        // 0x8007D9C0: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007D9CC;
    }
    // 0x8007D9C0: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007D9C4: b           L_8007D9D0
    // 0x8007D9C8: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007D9D0;
    // 0x8007D9C8: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007D9CC:
    // 0x8007D9CC: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007D9D0:
    // 0x8007D9D0: bgtz        $t3, L_8007D9E0
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007D9D4: or          $a0, $t3, $zero
        ctx->r4 = ctx->r11 | 0;
            goto L_8007D9E0;
    }
    // 0x8007D9D4: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
    // 0x8007D9D8: b           L_8007D9E0
    // 0x8007D9DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007D9E0;
    // 0x8007D9DC: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007D9E0:
    // 0x8007D9E0: bgtz        $t3, L_8007D9F0
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007D9E4: addiu       $t9, $t2, 0x7FF
        ctx->r25 = ADD32(ctx->r10, 0X7FF);
            goto L_8007D9F0;
    }
    // 0x8007D9E4: addiu       $t9, $t2, 0x7FF
    ctx->r25 = ADD32(ctx->r10, 0X7FF);
    // 0x8007D9E8: b           L_8007D9F0
    // 0x8007D9EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007D9F0;
    // 0x8007D9EC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007D9F0:
    // 0x8007D9F0: div         $zero, $t9, $a0
    lo = S32(S64(S32(ctx->r25)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r25)) % S64(S32(ctx->r4)));
    // 0x8007D9F4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007D9F8: bne         $a0, $zero, L_8007DA04
    if (ctx->r4 != 0) {
        // 0x8007D9FC: nop
    
            goto L_8007DA04;
    }
    // 0x8007D9FC: nop

    // 0x8007DA00: break       7
    do_break(2147998208);
L_8007DA04:
    // 0x8007DA04: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007DA08: bne         $a0, $at, L_8007DA1C
    if (ctx->r4 != ctx->r1) {
        // 0x8007DA0C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007DA1C;
    }
    // 0x8007DA0C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DA10: bne         $t9, $at, L_8007DA1C
    if (ctx->r25 != ctx->r1) {
        // 0x8007DA14: nop
    
            goto L_8007DA1C;
    }
    // 0x8007DA14: nop

    // 0x8007DA18: break       6
    do_break(2147998232);
L_8007DA1C:
    // 0x8007DA1C: andi        $t9, $ra, 0xFFF
    ctx->r25 = ctx->r31 & 0XFFF;
    // 0x8007DA20: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DA24: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DA28: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DA2C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DA30: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DA34: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DA38: mflo        $t6
    ctx->r14 = lo;
    // 0x8007DA3C: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007DA40: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007DA44: lw          $t9, 0x1CC($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X1CC);
    // 0x8007DA48: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007DA4C: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007DA50: sw          $t7, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r15;
    // 0x8007DA54: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007DA58: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007DA5C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007DA60: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007DA64: lui         $at, 0xF570
    ctx->r1 = S32(0XF570 << 16);
    // 0x8007DA68: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007DA6C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007DA70: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DA74: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007DA78: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007DA7C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007DA80: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007DA84: nop

    // 0x8007DA88: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007DA8C: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007DA90: nop

    // 0x8007DA94: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8007DA98: sh          $t9, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r25;
L_8007DA9C:
    // 0x8007DA9C: lw          $t8, 0x27C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X27C);
    // 0x8007DAA0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007DAA4: bne         $t8, $at, L_8007DC98
    if (ctx->r24 != ctx->r1) {
        // 0x8007DAA8: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007DC98;
    }
    // 0x8007DAA8: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DAAC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DAB0: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007DAB4: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007DAB8: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007DABC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DAC0: lui         $t6, 0xFD70
    ctx->r14 = S32(0XFD70 << 16);
    // 0x8007DAC4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007DAC8: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007DACC: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8007DAD0: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x8007DAD4: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007DAD8: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007DADC: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007DAE0: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8007DAE4: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007DAE8: sll         $v0, $t8, 18
    ctx->r2 = S32(ctx->r24 << 18);
    // 0x8007DAEC: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007DAF0: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007DAF4: andi        $t8, $a1, 0x3
    ctx->r24 = ctx->r5 & 0X3;
    // 0x8007DAF8: sll         $a1, $t8, 8
    ctx->r5 = S32(ctx->r24 << 8);
    // 0x8007DAFC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DB00: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007DB04: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8007DB08: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8007DB0C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DB10: or          $t6, $t8, $v1
    ctx->r14 = ctx->r24 | ctx->r3;
    // 0x8007DB14: or          $t7, $t6, $a1
    ctx->r15 = ctx->r14 | ctx->r5;
    // 0x8007DB18: or          $a2, $t9, $zero
    ctx->r6 = ctx->r25 | 0;
    // 0x8007DB1C: or          $t9, $t7, $t9
    ctx->r25 = ctx->r15 | ctx->r25;
    // 0x8007DB20: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB24: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007DB28: sw          $t9, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r25;
    // 0x8007DB2C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB30: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8007DB34: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007DB38: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007DB3C: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007DB40: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007DB44: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8007DB48: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8007DB4C: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8007DB50: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8007DB54: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007DB58: or          $t8, $t9, $a2
    ctx->r24 = ctx->r25 | ctx->r6;
    // 0x8007DB5C: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007DB60: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007DB64: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8007DB68: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007DB6C: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8007DB70: mflo        $t2
    ctx->r10 = lo;
    // 0x8007DB74: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8007DB78: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007DB7C: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007DB80: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007DB84: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007DB88: or          $t6, $t8, $t9
    ctx->r14 = ctx->r24 | ctx->r25;
    // 0x8007DB8C: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8007DB90: sw          $t3, 0x1B0($sp)
    MEM_W(0X1B0, ctx->r29) = ctx->r11;
    // 0x8007DB94: beq         $at, $zero, L_8007DBA4
    if (ctx->r1 == 0) {
        // 0x8007DB98: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007DBA4;
    }
    // 0x8007DB98: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DB9C: b           L_8007DBA8
    // 0x8007DBA0: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007DBA8;
    // 0x8007DBA0: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007DBA4:
    // 0x8007DBA4: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007DBA8:
    // 0x8007DBA8: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x8007DBAC: bgez        $t4, L_8007DBBC
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007DBB0: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007DBBC;
    }
    // 0x8007DBB0: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007DBB4: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007DBB8: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007DBBC:
    // 0x8007DBBC: bgtz        $t3, L_8007DBCC
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007DBC0: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007DBCC;
    }
    // 0x8007DBC0: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007DBC4: b           L_8007DBCC
    // 0x8007DBC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007DBCC;
    // 0x8007DBC8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007DBCC:
    // 0x8007DBCC: bgtz        $t3, L_8007DBDC
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007DBD0: addiu       $t8, $t2, 0x7FF
        ctx->r24 = ADD32(ctx->r10, 0X7FF);
            goto L_8007DBDC;
    }
    // 0x8007DBD0: addiu       $t8, $t2, 0x7FF
    ctx->r24 = ADD32(ctx->r10, 0X7FF);
    // 0x8007DBD4: b           L_8007DBE0
    // 0x8007DBD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007DBE0;
    // 0x8007DBD8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007DBDC:
    // 0x8007DBDC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_8007DBE0:
    // 0x8007DBE0: div         $zero, $t8, $a0
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r4)));
    // 0x8007DBE4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007DBE8: bne         $a0, $zero, L_8007DBF4
    if (ctx->r4 != 0) {
        // 0x8007DBEC: nop
    
            goto L_8007DBF4;
    }
    // 0x8007DBEC: nop

    // 0x8007DBF0: break       7
    do_break(2147998704);
L_8007DBF4:
    // 0x8007DBF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007DBF8: bne         $a0, $at, L_8007DC0C
    if (ctx->r4 != ctx->r1) {
        // 0x8007DBFC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007DC0C;
    }
    // 0x8007DBFC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DC00: bne         $t8, $at, L_8007DC0C
    if (ctx->r24 != ctx->r1) {
        // 0x8007DC04: nop
    
            goto L_8007DC0C;
    }
    // 0x8007DC04: nop

    // 0x8007DC08: break       6
    do_break(2147998728);
L_8007DC0C:
    // 0x8007DC0C: andi        $t8, $ra, 0xFFF
    ctx->r24 = ctx->r31 & 0XFFF;
    // 0x8007DC10: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DC14: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC18: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DC1C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC20: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DC24: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DC28: mflo        $t9
    ctx->r25 = lo;
    // 0x8007DC2C: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007DC30: sll         $t9, $t8, 12
    ctx->r25 = S32(ctx->r24 << 12);
    // 0x8007DC34: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007DC38: lw          $t8, 0x1B0($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1B0);
    // 0x8007DC3C: or          $t6, $t7, $t9
    ctx->r14 = ctx->r15 | ctx->r25;
    // 0x8007DC40: sw          $t6, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r14;
    // 0x8007DC44: addiu       $t9, $t4, 0x7
    ctx->r25 = ADD32(ctx->r12, 0X7);
    // 0x8007DC48: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007DC4C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007DC50: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007DC54: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x8007DC58: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8007DC5C: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8007DC60: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007DC64: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007DC68: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007DC6C: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DC70: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007DC74: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007DC78: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007DC7C: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007DC80: nop

    // 0x8007DC84: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007DC88: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007DC8C: nop

    // 0x8007DC90: ori         $t6, $t9, 0x4
    ctx->r14 = ctx->r25 | 0X4;
    // 0x8007DC94: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007DC98:
    // 0x8007DC98: lw          $t8, 0x27C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X27C);
    // 0x8007DC9C: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007DCA0: bne         $t8, $at, L_8007DE74
    if (ctx->r24 != ctx->r1) {
        // 0x8007DCA4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007DE74;
    }
    // 0x8007DCA4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DCA8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DCAC: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007DCB0: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007DCB4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007DCB8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DCBC: lui         $t7, 0xFD70
    ctx->r15 = S32(0XFD70 << 16);
    // 0x8007DCC0: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007DCC4: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007DCC8: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8007DCCC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007DCD0: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007DCD4: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007DCD8: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007DCDC: andi        $t8, $v0, 0x3
    ctx->r24 = ctx->r2 & 0X3;
    // 0x8007DCE0: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007DCE4: sll         $v0, $t8, 18
    ctx->r2 = S32(ctx->r24 << 18);
    // 0x8007DCE8: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x8007DCEC: sll         $v1, $t9, 14
    ctx->r3 = S32(ctx->r25 << 14);
    // 0x8007DCF0: andi        $t8, $a1, 0x3
    ctx->r24 = ctx->r5 & 0X3;
    // 0x8007DCF4: sll         $a1, $t8, 8
    ctx->r5 = S32(ctx->r24 << 8);
    // 0x8007DCF8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DCFC: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007DD00: sll         $t6, $t9, 4
    ctx->r14 = S32(ctx->r25 << 4);
    // 0x8007DD04: or          $t8, $v0, $at
    ctx->r24 = ctx->r2 | ctx->r1;
    // 0x8007DD08: or          $t7, $t8, $v1
    ctx->r15 = ctx->r24 | ctx->r3;
    // 0x8007DD0C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DD10: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8007DD14: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007DD18: or          $t6, $t9, $t6
    ctx->r14 = ctx->r25 | ctx->r14;
    // 0x8007DD1C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DD20: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007DD24: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8007DD28: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DD2C: lui         $t8, 0xE600
    ctx->r24 = S32(0XE600 << 16);
    // 0x8007DD30: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007DD34: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8007DD38: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8007DD3C: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007DD40: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007DD44: sw          $t7, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r15;
    // 0x8007DD48: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x8007DD4C: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007DD50: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007DD54: or          $t8, $t6, $a2
    ctx->r24 = ctx->r14 | ctx->r6;
    // 0x8007DD58: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007DD5C: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007DD60: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007DD64: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007DD68: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007DD6C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007DD70: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007DD74: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007DD78: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007DD7C: sra         $t9, $t0, 2
    ctx->r25 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007DD80: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007DD84: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007DD88: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8007DD8C: sra         $t9, $ra, 3
    ctx->r25 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007DD90: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007DD94: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DD98: bgez        $t5, L_8007DDA8
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007DD9C: sra         $t1, $t5, 4
        ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
            goto L_8007DDA8;
    }
    // 0x8007DD9C: sra         $t1, $t5, 4
    ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8007DDA0: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x8007DDA4: sra         $t1, $at, 4
    ctx->r9 = S32(SIGNED(ctx->r1) >> 4);
L_8007DDA8:
    // 0x8007DDA8: addiu       $t8, $t1, 0x7FF
    ctx->r24 = ADD32(ctx->r9, 0X7FF);
    // 0x8007DDAC: div         $zero, $t8, $t1
    lo = S32(S64(S32(ctx->r24)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r24)) % S64(S32(ctx->r9)));
    // 0x8007DDB0: bne         $t1, $zero, L_8007DDBC
    if (ctx->r9 != 0) {
        // 0x8007DDB4: nop
    
            goto L_8007DDBC;
    }
    // 0x8007DDB4: nop

    // 0x8007DDB8: break       7
    do_break(2147999160);
L_8007DDBC:
    // 0x8007DDBC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007DDC0: bne         $t1, $at, L_8007DDD4
    if (ctx->r9 != ctx->r1) {
        // 0x8007DDC4: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007DDD4;
    }
    // 0x8007DDC4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DDC8: bne         $t8, $at, L_8007DDD4
    if (ctx->r24 != ctx->r1) {
        // 0x8007DDCC: nop
    
            goto L_8007DDD4;
    }
    // 0x8007DDCC: nop

    // 0x8007DDD0: break       6
    do_break(2147999184);
L_8007DDD4:
    // 0x8007DDD4: andi        $t8, $t9, 0x1FF
    ctx->r24 = ctx->r25 & 0X1FF;
    // 0x8007DDD8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007DDDC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DDE0: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007DDE4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007DDE8: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x8007DDEC: mflo        $t6
    ctx->r14 = lo;
    // 0x8007DDF0: andi        $t7, $t6, 0xFFF
    ctx->r15 = ctx->r14 & 0XFFF;
    // 0x8007DDF4: sll         $t6, $t8, 9
    ctx->r14 = S32(ctx->r24 << 9);
    // 0x8007DDF8: or          $ra, $t6, $zero
    ctx->r31 = ctx->r14 | 0;
    // 0x8007DDFC: beq         $at, $zero, L_8007DE0C
    if (ctx->r1 == 0) {
        // 0x8007DE00: sw          $t7, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r15;
            goto L_8007DE0C;
    }
    // 0x8007DE00: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007DE04: b           L_8007DE0C
    // 0x8007DE08: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007DE0C;
    // 0x8007DE08: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007DE0C:
    // 0x8007DE0C: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007DE10: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007DE14: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8007DE18: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DE1C: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007DE20: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007DE24: sw          $t7, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r15;
    // 0x8007DE28: lui         $at, 0xF560
    ctx->r1 = S32(0XF560 << 16);
    // 0x8007DE2C: lui         $t9, 0xE700
    ctx->r25 = S32(0XE700 << 16);
    // 0x8007DE30: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x8007DE34: or          $t8, $ra, $at
    ctx->r24 = ctx->r31 | ctx->r1;
    // 0x8007DE38: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007DE3C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007DE40: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007DE44: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DE48: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007DE4C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007DE50: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007DE54: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007DE58: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007DE5C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DE60: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8007DE64: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007DE68: nop

    // 0x8007DE6C: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007DE70: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007DE74:
    // 0x8007DE74: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8007DE78: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007DE7C: bne         $t7, $at, L_8007E068
    if (ctx->r15 != ctx->r1) {
        // 0x8007DE80: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E068;
    }
    // 0x8007DE80: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007DE84: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DE88: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007DE8C: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007DE90: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007DE94: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DE98: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x8007DE9C: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007DEA0: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007DEA4: lui         $t6, 0xF590
    ctx->r14 = S32(0XF590 << 16);
    // 0x8007DEA8: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007DEAC: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007DEB0: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007DEB4: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007DEB8: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8007DEBC: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007DEC0: sll         $v0, $t7, 18
    ctx->r2 = S32(ctx->r15 << 18);
    // 0x8007DEC4: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007DEC8: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007DECC: andi        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 & 0X3;
    // 0x8007DED0: sll         $a1, $t7, 8
    ctx->r5 = S32(ctx->r15 << 8);
    // 0x8007DED4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007DED8: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007DEDC: sll         $t6, $t8, 4
    ctx->r14 = S32(ctx->r24 << 4);
    // 0x8007DEE0: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x8007DEE4: or          $t9, $t7, $v1
    ctx->r25 = ctx->r15 | ctx->r3;
    // 0x8007DEE8: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007DEEC: or          $a2, $t6, $zero
    ctx->r6 = ctx->r14 | 0;
    // 0x8007DEF0: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007DEF4: or          $t6, $t8, $t6
    ctx->r14 = ctx->r24 | ctx->r14;
    // 0x8007DEF8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DEFC: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007DF00: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007DF04: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DF08: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007DF0C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8007DF10: or          $ra, $a3, $zero
    ctx->r31 = ctx->r7 | 0;
    // 0x8007DF14: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007DF18: or          $t8, $v0, $v1
    ctx->r24 = ctx->r2 | ctx->r3;
    // 0x8007DF1C: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007DF20: sw          $t9, 0x0($ra)
    MEM_W(0X0, ctx->r31) = ctx->r25;
    // 0x8007DF24: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007DF28: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007DF2C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007DF30: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007DF34: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007DF38: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007DF3C: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007DF40: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007DF44: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007DF48: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007DF4C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8007DF50: mflo        $t0
    ctx->r8 = lo;
    // 0x8007DF54: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8007DF58: or          $t4, $t5, $zero
    ctx->r12 = ctx->r13 | 0;
    // 0x8007DF5C: addiu       $t7, $t4, 0x7
    ctx->r15 = ADD32(ctx->r12, 0X7);
    // 0x8007DF60: sra         $t8, $t0, 1
    ctx->r24 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007DF64: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007DF68: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8007DF6C: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007DF70: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007DF74: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x8007DF78: sw          $t8, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r24;
    // 0x8007DF7C: sw          $ra, 0x178($sp)
    MEM_W(0X178, ctx->r29) = ctx->r31;
    // 0x8007DF80: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007DF84: bgez        $t4, L_8007DF94
    if (SIGNED(ctx->r12) >= 0) {
        // 0x8007DF88: sra         $t3, $t4, 3
        ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
            goto L_8007DF94;
    }
    // 0x8007DF88: sra         $t3, $t4, 3
    ctx->r11 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007DF8C: addiu       $at, $t4, 0x7
    ctx->r1 = ADD32(ctx->r12, 0X7);
    // 0x8007DF90: sra         $t3, $at, 3
    ctx->r11 = S32(SIGNED(ctx->r1) >> 3);
L_8007DF94:
    // 0x8007DF94: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007DF98: beq         $at, $zero, L_8007DFA8
    if (ctx->r1 == 0) {
        // 0x8007DF9C: or          $t4, $t8, $zero
        ctx->r12 = ctx->r24 | 0;
            goto L_8007DFA8;
    }
    // 0x8007DF9C: or          $t4, $t8, $zero
    ctx->r12 = ctx->r24 | 0;
    // 0x8007DFA0: b           L_8007DFAC
    // 0x8007DFA4: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
        goto L_8007DFAC;
    // 0x8007DFA4: or          $ra, $t0, $zero
    ctx->r31 = ctx->r8 | 0;
L_8007DFA8:
    // 0x8007DFA8: addiu       $ra, $zero, 0x7FF
    ctx->r31 = ADD32(0, 0X7FF);
L_8007DFAC:
    // 0x8007DFAC: bgtz        $t3, L_8007DFBC
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007DFB0: or          $t2, $t3, $zero
        ctx->r10 = ctx->r11 | 0;
            goto L_8007DFBC;
    }
    // 0x8007DFB0: or          $t2, $t3, $zero
    ctx->r10 = ctx->r11 | 0;
    // 0x8007DFB4: b           L_8007DFBC
    // 0x8007DFB8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
        goto L_8007DFBC;
    // 0x8007DFB8: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
L_8007DFBC:
    // 0x8007DFBC: bgtz        $t3, L_8007DFCC
    if (SIGNED(ctx->r11) > 0) {
        // 0x8007DFC0: addiu       $t7, $t2, 0x7FF
        ctx->r15 = ADD32(ctx->r10, 0X7FF);
            goto L_8007DFCC;
    }
    // 0x8007DFC0: addiu       $t7, $t2, 0x7FF
    ctx->r15 = ADD32(ctx->r10, 0X7FF);
    // 0x8007DFC4: b           L_8007DFD0
    // 0x8007DFC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
        goto L_8007DFD0;
    // 0x8007DFC8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
L_8007DFCC:
    // 0x8007DFCC: or          $a0, $t3, $zero
    ctx->r4 = ctx->r11 | 0;
L_8007DFD0:
    // 0x8007DFD0: div         $zero, $t7, $a0
    lo = S32(S64(S32(ctx->r15)) / S64(S32(ctx->r4))); hi = S32(S64(S32(ctx->r15)) % S64(S32(ctx->r4)));
    // 0x8007DFD4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007DFD8: bne         $a0, $zero, L_8007DFE4
    if (ctx->r4 != 0) {
        // 0x8007DFDC: nop
    
            goto L_8007DFE4;
    }
    // 0x8007DFDC: nop

    // 0x8007DFE0: break       7
    do_break(2147999712);
L_8007DFE4:
    // 0x8007DFE4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007DFE8: bne         $a0, $at, L_8007DFFC
    if (ctx->r4 != ctx->r1) {
        // 0x8007DFEC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007DFFC;
    }
    // 0x8007DFEC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007DFF0: bne         $t7, $at, L_8007DFFC
    if (ctx->r15 != ctx->r1) {
        // 0x8007DFF4: nop
    
            goto L_8007DFFC;
    }
    // 0x8007DFF4: nop

    // 0x8007DFF8: break       6
    do_break(2147999736);
L_8007DFFC:
    // 0x8007DFFC: andi        $t7, $ra, 0xFFF
    ctx->r15 = ctx->r31 & 0XFFF;
    // 0x8007E000: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E004: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E008: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E00C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E010: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E014: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E018: mflo        $t6
    ctx->r14 = lo;
    // 0x8007E01C: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8007E020: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007E024: lw          $t7, 0x178($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X178);
    // 0x8007E028: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007E02C: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007E030: sw          $t9, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r25;
    // 0x8007E034: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007E038: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8007E03C: or          $t6, $t4, $at
    ctx->r14 = ctx->r12 | ctx->r1;
    // 0x8007E040: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007E044: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E048: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007E04C: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E050: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007E054: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007E058: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007E05C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007E060: nop

    // 0x8007E064: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
L_8007E068:
    // 0x8007E068: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E06C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007E070: bne         $t6, $at, L_8007E234
    if (ctx->r14 != ctx->r1) {
        // 0x8007E074: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E234;
    }
    // 0x8007E074: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E078: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E07C: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E080: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E084: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007E088: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E08C: lui         $t9, 0xFD90
    ctx->r25 = S32(0XFD90 << 16);
    // 0x8007E090: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007E094: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E098: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x8007E09C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8007E0A0: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E0A4: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E0A8: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E0AC: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007E0B0: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E0B4: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007E0B8: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007E0BC: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007E0C0: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007E0C4: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007E0C8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E0CC: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007E0D0: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x8007E0D4: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007E0D8: or          $t9, $t6, $v1
    ctx->r25 = ctx->r14 | ctx->r3;
    // 0x8007E0DC: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E0E0: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007E0E4: or          $a2, $t8, $zero
    ctx->r6 = ctx->r24 | 0;
    // 0x8007E0E8: or          $t8, $t7, $t8
    ctx->r24 = ctx->r15 | ctx->r24;
    // 0x8007E0EC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E0F0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E0F4: sw          $t8, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r24;
    // 0x8007E0F8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E0FC: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007E100: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8007E104: or          $t4, $a3, $zero
    ctx->r12 = ctx->r7 | 0;
    // 0x8007E108: sw          $zero, 0x4($t3)
    MEM_W(0X4, ctx->r11) = 0;
    // 0x8007E10C: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007E110: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007E114: sw          $t9, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r25;
    // 0x8007E118: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x8007E11C: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007E120: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E124: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007E128: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007E12C: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007E130: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007E134: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E138: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8007E13C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E140: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x8007E144: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007E148: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007E14C: sra         $t7, $t0, 2
    ctx->r15 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007E150: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007E154: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007E158: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007E15C: sra         $t7, $ra, 3
    ctx->r15 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007E160: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007E164: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E168: bgez        $t5, L_8007E178
    if (SIGNED(ctx->r13) >= 0) {
        // 0x8007E16C: sra         $t1, $t5, 4
        ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
            goto L_8007E178;
    }
    // 0x8007E16C: sra         $t1, $t5, 4
    ctx->r9 = S32(SIGNED(ctx->r13) >> 4);
    // 0x8007E170: addiu       $at, $t5, 0xF
    ctx->r1 = ADD32(ctx->r13, 0XF);
    // 0x8007E174: sra         $t1, $at, 4
    ctx->r9 = S32(SIGNED(ctx->r1) >> 4);
L_8007E178:
    // 0x8007E178: addiu       $t6, $t1, 0x7FF
    ctx->r14 = ADD32(ctx->r9, 0X7FF);
    // 0x8007E17C: div         $zero, $t6, $t1
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r9)));
    // 0x8007E180: bne         $t1, $zero, L_8007E18C
    if (ctx->r9 != 0) {
        // 0x8007E184: nop
    
            goto L_8007E18C;
    }
    // 0x8007E184: nop

    // 0x8007E188: break       7
    do_break(2148000136);
L_8007E18C:
    // 0x8007E18C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8007E190: bne         $t1, $at, L_8007E1A4
    if (ctx->r9 != ctx->r1) {
        // 0x8007E194: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_8007E1A4;
    }
    // 0x8007E194: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E198: bne         $t6, $at, L_8007E1A4
    if (ctx->r14 != ctx->r1) {
        // 0x8007E19C: nop
    
            goto L_8007E1A4;
    }
    // 0x8007E19C: nop

    // 0x8007E1A0: break       6
    do_break(2148000160);
L_8007E1A4:
    // 0x8007E1A4: andi        $t6, $t7, 0x1FF
    ctx->r14 = ctx->r15 & 0X1FF;
    // 0x8007E1A8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E1AC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E1B0: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E1B4: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E1B8: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
    // 0x8007E1BC: mflo        $t8
    ctx->r24 = lo;
    // 0x8007E1C0: andi        $t9, $t8, 0xFFF
    ctx->r25 = ctx->r24 & 0XFFF;
    // 0x8007E1C4: sll         $t8, $t6, 9
    ctx->r24 = S32(ctx->r14 << 9);
    // 0x8007E1C8: or          $ra, $t8, $zero
    ctx->r31 = ctx->r24 | 0;
    // 0x8007E1CC: beq         $at, $zero, L_8007E1DC
    if (ctx->r1 == 0) {
        // 0x8007E1D0: sw          $t9, 0x30($sp)
        MEM_W(0X30, ctx->r29) = ctx->r25;
            goto L_8007E1DC;
    }
    // 0x8007E1D0: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8007E1D4: b           L_8007E1DC
    // 0x8007E1D8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E1DC;
    // 0x8007E1D8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E1DC:
    // 0x8007E1DC: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007E1E0: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x8007E1E4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8007E1E8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E1EC: or          $t6, $t7, $at
    ctx->r14 = ctx->r15 | ctx->r1;
    // 0x8007E1F0: or          $t9, $t6, $t8
    ctx->r25 = ctx->r14 | ctx->r24;
    // 0x8007E1F4: sw          $t9, 0x4($t4)
    MEM_W(0X4, ctx->r12) = ctx->r25;
    // 0x8007E1F8: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8007E1FC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007E200: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007E204: or          $t6, $ra, $at
    ctx->r14 = ctx->r31 | ctx->r1;
    // 0x8007E208: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E20C: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8007E210: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E214: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E218: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E21C: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007E220: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8007E224: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007E228: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007E22C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E230: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
L_8007E234:
    // 0x8007E234: lw          $t6, 0xC($s1)
    ctx->r14 = MEM_W(ctx->r17, 0XC);
    // 0x8007E238: nop

    // 0x8007E23C: subu        $t8, $a3, $t6
    ctx->r24 = SUB32(ctx->r7, ctx->r14);
    // 0x8007E240: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007E244: b           L_8007EF50
    // 0x8007E248: sh          $t9, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r25;
        goto L_8007EF50;
    // 0x8007E248: sh          $t9, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r25;
L_8007E24C:
    // 0x8007E24C: sw          $t2, 0x264($sp)
    MEM_W(0X264, ctx->r29) = ctx->r10;
    // 0x8007E250: sw          $t3, 0x260($sp)
    MEM_W(0X260, ctx->r29) = ctx->r11;
    // 0x8007E254: bne         $t4, $zero, L_8007E3D0
    if (ctx->r12 != 0) {
        // 0x8007E258: sw          $t4, 0x27C($sp)
        MEM_W(0X27C, ctx->r29) = ctx->r12;
            goto L_8007E3D0;
    }
    // 0x8007E258: sw          $t4, 0x27C($sp)
    MEM_W(0X27C, ctx->r29) = ctx->r12;
    // 0x8007E25C: lw          $t2, 0x284($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X284);
    // 0x8007E260: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E264: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E268: addu        $t6, $s1, $at
    ctx->r14 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E26C: lui         $t7, 0xFD18
    ctx->r15 = S32(0XFD18 << 16);
    // 0x8007E270: addiu       $a3, $t2, 0x8
    ctx->r7 = ADD32(ctx->r10, 0X8);
    // 0x8007E274: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007E278: lui         $t8, 0xF518
    ctx->r24 = S32(0XF518 << 16);
    // 0x8007E27C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8007E280: sw          $t6, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r14;
    // 0x8007E284: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E288: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x8007E28C: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E290: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E294: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E298: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007E29C: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007E2A0: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E2A4: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007E2A8: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8007E2AC: sll         $v1, $t6, 14
    ctx->r3 = S32(ctx->r14 << 14);
    // 0x8007E2B0: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007E2B4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E2B8: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007E2BC: andi        $t6, $a2, 0xF
    ctx->r14 = ctx->r6 & 0XF;
    // 0x8007E2C0: sll         $a2, $t6, 4
    ctx->r6 = S32(ctx->r14 << 4);
    // 0x8007E2C4: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x8007E2C8: or          $t6, $t7, $a1
    ctx->r14 = ctx->r15 | ctx->r5;
    // 0x8007E2CC: or          $t8, $t6, $a2
    ctx->r24 = ctx->r14 | ctx->r6;
    // 0x8007E2D0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E2D4: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E2D8: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8007E2DC: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E2E0: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007E2E4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E2E8: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007E2EC: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8007E2F0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E2F4: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E2F8: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007E2FC: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007E300: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8007E304: beq         $at, $zero, L_8007E314
    if (ctx->r1 == 0) {
        // 0x8007E308: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007E314;
    }
    // 0x8007E308: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E30C: b           L_8007E318
    // 0x8007E310: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E318;
    // 0x8007E310: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E314:
    // 0x8007E314: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007E318:
    // 0x8007E318: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x8007E31C: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007E320: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E324: or          $t9, $t8, $at
    ctx->r25 = ctx->r24 | ctx->r1;
    // 0x8007E328: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007E32C: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8007E330: addiu       $t8, $t6, 0x7
    ctx->r24 = ADD32(ctx->r14, 0X7);
    // 0x8007E334: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007E338: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007E33C: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
    // 0x8007E340: sra         $t9, $t8, 3
    ctx->r25 = S32(SIGNED(ctx->r24) >> 3);
    // 0x8007E344: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8007E348: sll         $t6, $t7, 9
    ctx->r14 = S32(ctx->r15 << 9);
    // 0x8007E34C: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007E350: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E354: lui         $at, 0xF518
    ctx->r1 = S32(0XF518 << 16);
    // 0x8007E358: or          $t8, $t6, $at
    ctx->r24 = ctx->r14 | ctx->r1;
    // 0x8007E35C: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E360: or          $t7, $t9, $a1
    ctx->r15 = ctx->r25 | ctx->r5;
    // 0x8007E364: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007E368: sw          $zero, 0x4($t0)
    MEM_W(0X4, ctx->r8) = 0;
    // 0x8007E36C: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007E370: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E374: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007E378: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007E37C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E380: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E384: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007E388: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007E38C: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8007E390: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007E394: sll         $t7, $t9, 2
    ctx->r15 = S32(ctx->r25 << 2);
    // 0x8007E398: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007E39C: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007E3A0: or          $t9, $t8, $t6
    ctx->r25 = ctx->r24 | ctx->r14;
    // 0x8007E3A4: sw          $t9, 0x4($t2)
    MEM_W(0X4, ctx->r10) = ctx->r25;
    // 0x8007E3A8: lw          $t7, 0x278($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X278);
    // 0x8007E3AC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E3B0: beq         $t7, $zero, L_8007E3C0
    if (ctx->r15 == 0) {
        // 0x8007E3B4: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8007E3C0;
    }
    // 0x8007E3B4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E3B8: bne         $t7, $at, L_8007E3D4
    if (ctx->r15 != ctx->r1) {
        // 0x8007E3BC: lw          $t9, 0x27C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X27C);
            goto L_8007E3D4;
    }
    // 0x8007E3BC: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007E3C0:
    // 0x8007E3C0: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007E3C4: nop

    // 0x8007E3C8: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007E3CC: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007E3D0:
    // 0x8007E3D0: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
L_8007E3D4:
    // 0x8007E3D4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007E3D8: bne         $t9, $at, L_8007E56C
    if (ctx->r25 != ctx->r1) {
        // 0x8007E3DC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E56C;
    }
    // 0x8007E3DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E3E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E3E4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E3E8: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E3EC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E3F0: lui         $t7, 0xFD10
    ctx->r15 = S32(0XFD10 << 16);
    // 0x8007E3F4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x8007E3F8: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E3FC: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007E400: lui         $t6, 0xF510
    ctx->r14 = S32(0XF510 << 16);
    // 0x8007E404: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007E408: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E40C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E410: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E414: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007E418: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007E41C: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E420: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007E424: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007E428: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007E42C: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007E430: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E434: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007E438: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007E43C: sll         $a2, $t8, 4
    ctx->r6 = S32(ctx->r24 << 4);
    // 0x8007E440: or          $t7, $t9, $v1
    ctx->r15 = ctx->r25 | ctx->r3;
    // 0x8007E444: or          $t8, $t7, $a1
    ctx->r24 = ctx->r15 | ctx->r5;
    // 0x8007E448: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007E44C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E450: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E454: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E458: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007E45C: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007E460: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007E464: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E468: sll         $t8, $t5, 1
    ctx->r24 = S32(ctx->r13 << 1);
    // 0x8007E46C: addiu       $t6, $t8, 0x7
    ctx->r14 = ADD32(ctx->r24, 0X7);
    // 0x8007E470: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E474: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007E478: lui         $t7, 0xF300
    ctx->r15 = S32(0XF300 << 16);
    // 0x8007E47C: sw          $t7, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r15;
    // 0x8007E480: sra         $t9, $t6, 3
    ctx->r25 = S32(SIGNED(ctx->r14) >> 3);
    // 0x8007E484: andi        $t7, $t9, 0x1FF
    ctx->r15 = ctx->r25 & 0X1FF;
    // 0x8007E488: sll         $t8, $t7, 9
    ctx->r24 = S32(ctx->r15 << 9);
    // 0x8007E48C: or          $t6, $v0, $v1
    ctx->r14 = ctx->r2 | ctx->r3;
    // 0x8007E490: or          $t9, $t6, $a1
    ctx->r25 = ctx->r14 | ctx->r5;
    // 0x8007E494: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x8007E498: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007E49C: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8007E4A0: or          $t7, $t9, $a2
    ctx->r15 = ctx->r25 | ctx->r6;
    // 0x8007E4A4: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8007E4A8: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007E4AC: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007E4B0: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8007E4B4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8007E4B8: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E4BC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007E4C0: andi        $t9, $t6, 0xFFF
    ctx->r25 = ctx->r14 & 0XFFF;
    // 0x8007E4C4: or          $t8, $t7, $t9
    ctx->r24 = ctx->r15 | ctx->r25;
    // 0x8007E4C8: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E4CC: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007E4D0: beq         $at, $zero, L_8007E4E0
    if (ctx->r1 == 0) {
        // 0x8007E4D4: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007E4E0;
    }
    // 0x8007E4D4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E4D8: b           L_8007E4E4
    // 0x8007E4DC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E4E4;
    // 0x8007E4DC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E4E0:
    // 0x8007E4E0: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007E4E4:
    // 0x8007E4E4: andi        $t6, $a0, 0xFFF
    ctx->r14 = ctx->r4 & 0XFFF;
    // 0x8007E4E8: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007E4EC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E4F0: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007E4F4: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007E4F8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E4FC: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007E500: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007E504: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E508: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x8007E50C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E510: lui         $at, 0xF510
    ctx->r1 = S32(0XF510 << 16);
    // 0x8007E514: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E518: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x8007E51C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007E520: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E524: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E528: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E52C: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007E530: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007E534: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007E538: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007E53C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E540: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007E544: lw          $t7, 0x278($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X278);
    // 0x8007E548: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E54C: beq         $t7, $zero, L_8007E55C
    if (ctx->r15 == 0) {
        // 0x8007E550: nop
    
            goto L_8007E55C;
    }
    // 0x8007E550: nop

    // 0x8007E554: bne         $t7, $at, L_8007E570
    if (ctx->r15 != ctx->r1) {
        // 0x8007E558: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007E570;
    }
    // 0x8007E558: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007E55C:
    // 0x8007E55C: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007E560: nop

    // 0x8007E564: ori         $t8, $t9, 0x4
    ctx->r24 = ctx->r25 | 0X4;
    // 0x8007E568: sh          $t8, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r24;
L_8007E56C:
    // 0x8007E56C: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007E570:
    // 0x8007E570: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8007E574: bne         $t6, $at, L_8007E7D4
    if (ctx->r14 != ctx->r1) {
        // 0x8007E578: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007E7D4;
    }
    // 0x8007E578: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E57C: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E580: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E584: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E588: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E58C: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007E590: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007E594: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E598: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E59C: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E5A0: andi        $t6, $v1, 0xF
    ctx->r14 = ctx->r3 & 0XF;
    // 0x8007E5A4: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007E5A8: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E5AC: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007E5B0: sll         $v1, $t6, 14
    ctx->r3 = S32(ctx->r14 << 14);
    // 0x8007E5B4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E5B8: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007E5BC: andi        $t6, $a2, 0xF
    ctx->r14 = ctx->r6 & 0XF;
    // 0x8007E5C0: sll         $a2, $t6, 4
    ctx->r6 = S32(ctx->r14 << 4);
    // 0x8007E5C4: or          $t8, $t9, $v1
    ctx->r24 = ctx->r25 | ctx->r3;
    // 0x8007E5C8: lh          $a0, 0x8($s1)
    ctx->r4 = MEM_H(ctx->r17, 0X8);
    // 0x8007E5CC: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x8007E5D0: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007E5D4: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007E5D8: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007E5DC: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007E5E0: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
    // 0x8007E5E4: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007E5E8: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007E5EC: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007E5F0: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007E5F4: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007E5F8: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007E5FC: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007E600: sll         $t6, $t8, 12
    ctx->r14 = S32(ctx->r24 << 12);
    // 0x8007E604: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007E608: or          $t7, $t6, $t8
    ctx->r15 = ctx->r14 | ctx->r24;
    // 0x8007E60C: mflo        $t2
    ctx->r10 = lo;
    // 0x8007E610: sw          $t2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r10;
    // 0x8007E614: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007E618: sw          $t5, 0x274($sp)
    MEM_W(0X274, ctx->r29) = ctx->r13;
    // 0x8007E61C: jal         0x8007EF64
    // 0x8007E620: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    tex_palette_id(rdram, ctx);
        goto after_1;
    // 0x8007E620: sw          $a3, 0x248($sp)
    MEM_W(0X248, ctx->r29) = ctx->r7;
    after_1:
    // 0x8007E624: lw          $a3, 0x248($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X248);
    // 0x8007E628: lw          $t2, 0x30($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X30);
    // 0x8007E62C: lw          $t5, 0x274($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X274);
    // 0x8007E630: lui         $t9, 0xFD50
    ctx->r25 = S32(0XFD50 << 16);
    // 0x8007E634: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E638: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007E63C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x8007E640: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E644: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E648: lui         $t8, 0xF550
    ctx->r24 = S32(0XF550 << 16);
    // 0x8007E64C: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007E650: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007E654: lw          $t7, 0x34($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X34);
    // 0x8007E658: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E65C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E660: addiu       $t0, $t2, 0x3
    ctx->r8 = ADD32(ctx->r10, 0X3);
    // 0x8007E664: sra         $t8, $t0, 2
    ctx->r24 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007E668: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007E66C: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007E670: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E674: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007E678: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007E67C: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E680: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E684: sw          $zero, 0x4($a1)
    MEM_W(0X4, ctx->r5) = 0;
    // 0x8007E688: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8007E68C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007E690: beq         $at, $zero, L_8007E6A0
    if (ctx->r1 == 0) {
        // 0x8007E694: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007E6A0;
    }
    // 0x8007E694: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E698: b           L_8007E6A4
    // 0x8007E69C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E6A4;
    // 0x8007E69C: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E6A0:
    // 0x8007E6A0: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007E6A4:
    // 0x8007E6A4: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007E6A8: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8007E6AC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E6B0: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007E6B4: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007E6B8: sra         $t7, $t5, 1
    ctx->r15 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007E6BC: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x8007E6C0: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E6C4: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007E6C8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007E6CC: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007E6D0: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x8007E6D4: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8007E6D8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E6DC: lui         $at, 0xF540
    ctx->r1 = S32(0XF540 << 16);
    // 0x8007E6E0: or          $t9, $t7, $at
    ctx->r25 = ctx->r15 | ctx->r1;
    // 0x8007E6E4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E6E8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8007E6EC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007E6F0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E6F4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E6F8: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007E6FC: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007E700: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
    // 0x8007E704: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8007E708: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8007E70C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E710: sw          $t7, 0x4($a2)
    MEM_W(0X4, ctx->r6) = ctx->r15;
    // 0x8007E714: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E718: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E71C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E720: lui         $t9, 0xFD10
    ctx->r25 = S32(0XFD10 << 16);
    // 0x8007E724: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007E728: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E72C: sw          $v0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r2;
    // 0x8007E730: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E734: lui         $t6, 0xE800
    ctx->r14 = S32(0XE800 << 16);
    // 0x8007E738: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007E73C: sw          $zero, 0x4($a0)
    MEM_W(0X4, ctx->r4) = 0;
    // 0x8007E740: lui         $t8, 0xF500
    ctx->r24 = S32(0XF500 << 16);
    // 0x8007E744: ori         $t8, $t8, 0x100
    ctx->r24 = ctx->r24 | 0X100;
    // 0x8007E748: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E74C: lui         $t7, 0x700
    ctx->r15 = S32(0X700 << 16);
    // 0x8007E750: sw          $t7, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r15;
    // 0x8007E754: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
    // 0x8007E758: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007E75C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E760: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007E764: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007E768: sw          $t9, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r25;
    // 0x8007E76C: sw          $zero, 0x4($a2)
    MEM_W(0X4, ctx->r6) = 0;
    // 0x8007E770: lui         $t8, 0x703
    ctx->r24 = S32(0X703 << 16);
    // 0x8007E774: ori         $t8, $t8, 0xC000
    ctx->r24 = ctx->r24 | 0XC000;
    // 0x8007E778: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E77C: lui         $t6, 0xF000
    ctx->r14 = S32(0XF000 << 16);
    // 0x8007E780: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007E784: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E788: sw          $t8, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r24;
    // 0x8007E78C: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007E790: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007E794: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E798: lh          $t9, 0x6($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X6);
    // 0x8007E79C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E7A0: ori         $t6, $t9, 0x20
    ctx->r14 = ctx->r25 | 0X20;
    // 0x8007E7A4: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
    // 0x8007E7A8: lw          $t8, 0x278($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X278);
    // 0x8007E7AC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007E7B0: beq         $t8, $zero, L_8007E7C0
    if (ctx->r24 == 0) {
        // 0x8007E7B4: nop
    
            goto L_8007E7C0;
    }
    // 0x8007E7B4: nop

    // 0x8007E7B8: bne         $t8, $at, L_8007E7D4
    if (ctx->r24 != ctx->r1) {
        // 0x8007E7BC: lw          $t6, 0x27C($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X27C);
            goto L_8007E7D4;
    }
    // 0x8007E7BC: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007E7C0:
    // 0x8007E7C0: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007E7C4: nop

    // 0x8007E7C8: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8007E7CC: sh          $t9, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r25;
    // 0x8007E7D0: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
L_8007E7D4:
    // 0x8007E7D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8007E7D8: bne         $t6, $at, L_8007E954
    if (ctx->r14 != ctx->r1) {
        // 0x8007E7DC: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007E954;
    }
    // 0x8007E7DC: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E7E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E7E4: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E7E8: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E7EC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E7F0: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8007E7F4: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007E7F8: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E7FC: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007E800: lui         $t9, 0xF570
    ctx->r25 = S32(0XF570 << 16);
    // 0x8007E804: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8007E808: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E80C: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E810: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E814: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007E818: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007E81C: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E820: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007E824: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007E828: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007E82C: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007E830: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E834: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007E838: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007E83C: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007E840: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007E844: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007E848: or          $t9, $t7, $a2
    ctx->r25 = ctx->r15 | ctx->r6;
    // 0x8007E84C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E850: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E854: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007E858: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8007E85C: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007E860: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007E864: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E868: sll         $t7, $t5, 1
    ctx->r15 = S32(ctx->r13 << 1);
    // 0x8007E86C: addiu       $t9, $t7, 0x7
    ctx->r25 = ADD32(ctx->r15, 0X7);
    // 0x8007E870: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E874: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007E878: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007E87C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007E880: sra         $t6, $t9, 3
    ctx->r14 = S32(SIGNED(ctx->r25) >> 3);
    // 0x8007E884: andi        $t8, $t6, 0x1FF
    ctx->r24 = ctx->r14 & 0X1FF;
    // 0x8007E888: sll         $t7, $t8, 9
    ctx->r15 = S32(ctx->r24 << 9);
    // 0x8007E88C: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007E890: or          $t6, $t9, $a1
    ctx->r14 = ctx->r25 | ctx->r5;
    // 0x8007E894: sw          $t7, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r15;
    // 0x8007E898: addiu       $t7, $t5, -0x1
    ctx->r15 = ADD32(ctx->r13, -0X1);
    // 0x8007E89C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007E8A0: or          $t8, $t6, $a2
    ctx->r24 = ctx->r14 | ctx->r6;
    // 0x8007E8A4: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007E8A8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x8007E8AC: addiu       $t7, $s0, -0x1
    ctx->r15 = ADD32(ctx->r16, -0X1);
    // 0x8007E8B0: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8007E8B4: sll         $t8, $t6, 12
    ctx->r24 = S32(ctx->r14 << 12);
    // 0x8007E8B8: mflo        $t0
    ctx->r8 = lo;
    // 0x8007E8BC: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8007E8C0: andi        $t6, $t9, 0xFFF
    ctx->r14 = ctx->r25 & 0XFFF;
    // 0x8007E8C4: or          $t7, $t8, $t6
    ctx->r15 = ctx->r24 | ctx->r14;
    // 0x8007E8C8: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007E8CC: sw          $t7, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r15;
    // 0x8007E8D0: beq         $at, $zero, L_8007E8E0
    if (ctx->r1 == 0) {
        // 0x8007E8D4: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007E8E0;
    }
    // 0x8007E8D4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E8D8: b           L_8007E8E4
    // 0x8007E8DC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007E8E4;
    // 0x8007E8DC: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007E8E0:
    // 0x8007E8E0: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007E8E4:
    // 0x8007E8E4: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007E8E8: sll         $t8, $t9, 12
    ctx->r24 = S32(ctx->r25 << 12);
    // 0x8007E8EC: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E8F0: or          $t6, $t8, $at
    ctx->r14 = ctx->r24 | ctx->r1;
    // 0x8007E8F4: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8007E8F8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007E8FC: lui         $t7, 0xE700
    ctx->r15 = S32(0XE700 << 16);
    // 0x8007E900: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8007E904: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007E908: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x8007E90C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E910: lui         $at, 0xF570
    ctx->r1 = S32(0XF570 << 16);
    // 0x8007E914: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007E918: or          $t8, $t9, $at
    ctx->r24 = ctx->r25 | ctx->r1;
    // 0x8007E91C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8007E920: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007E924: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E928: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007E92C: lui         $t7, 0xF200
    ctx->r15 = S32(0XF200 << 16);
    // 0x8007E930: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007E934: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
    // 0x8007E938: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8007E93C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E940: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x8007E944: lh          $t8, 0x6($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X6);
    // 0x8007E948: nop

    // 0x8007E94C: ori         $t6, $t8, 0x4
    ctx->r14 = ctx->r24 | 0X4;
    // 0x8007E950: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007E954:
    // 0x8007E954: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8007E958: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8007E95C: bne         $t7, $at, L_8007EAD4
    if (ctx->r15 != ctx->r1) {
        // 0x8007E960: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007EAD4;
    }
    // 0x8007E960: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007E964: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007E968: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007E96C: addu        $t8, $s1, $at
    ctx->r24 = ADD32(ctx->r17, ctx->r1);
    // 0x8007E970: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E974: lui         $t9, 0xFD70
    ctx->r25 = S32(0XFD70 << 16);
    // 0x8007E978: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8007E97C: or          $t0, $a3, $zero
    ctx->r8 = ctx->r7 | 0;
    // 0x8007E980: sw          $t8, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r24;
    // 0x8007E984: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8007E988: sw          $t6, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r14;
    // 0x8007E98C: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007E990: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007E994: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007E998: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8007E99C: sll         $v0, $t7, 18
    ctx->r2 = S32(ctx->r15 << 18);
    // 0x8007E9A0: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007E9A4: andi        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 & 0X3;
    // 0x8007E9A8: andi        $t8, $v1, 0xF
    ctx->r24 = ctx->r3 & 0XF;
    // 0x8007E9AC: sll         $v1, $t8, 14
    ctx->r3 = S32(ctx->r24 << 14);
    // 0x8007E9B0: sll         $a1, $t7, 8
    ctx->r5 = S32(ctx->r15 << 8);
    // 0x8007E9B4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007E9B8: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x8007E9BC: andi        $t8, $a2, 0xF
    ctx->r24 = ctx->r6 & 0XF;
    // 0x8007E9C0: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007E9C4: sll         $a2, $t8, 4
    ctx->r6 = S32(ctx->r24 << 4);
    // 0x8007E9C8: or          $t9, $t7, $v1
    ctx->r25 = ctx->r15 | ctx->r3;
    // 0x8007E9CC: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007E9D0: or          $t6, $t8, $a2
    ctx->r14 = ctx->r24 | ctx->r6;
    // 0x8007E9D4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E9D8: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007E9DC: sw          $t6, 0x4($t0)
    MEM_W(0X4, ctx->r8) = ctx->r14;
    // 0x8007E9E0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007E9E4: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007E9E8: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8007E9EC: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007E9F0: sw          $zero, 0x4($t1)
    MEM_W(0X4, ctx->r9) = 0;
    // 0x8007E9F4: or          $t8, $v0, $v1
    ctx->r24 = ctx->r2 | ctx->r3;
    // 0x8007E9F8: lui         $t9, 0xF300
    ctx->r25 = S32(0XF300 << 16);
    // 0x8007E9FC: sw          $t9, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r25;
    // 0x8007EA00: or          $t6, $t8, $a1
    ctx->r14 = ctx->r24 | ctx->r5;
    // 0x8007EA04: addiu       $t9, $t5, -0x1
    ctx->r25 = ADD32(ctx->r13, -0X1);
    // 0x8007EA08: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007EA0C: or          $t7, $t6, $a2
    ctx->r15 = ctx->r14 | ctx->r6;
    // 0x8007EA10: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007EA14: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007EA18: addiu       $t9, $s0, -0x1
    ctx->r25 = ADD32(ctx->r16, -0X1);
    // 0x8007EA1C: sll         $t8, $t9, 2
    ctx->r24 = S32(ctx->r25 << 2);
    // 0x8007EA20: sll         $t7, $t6, 12
    ctx->r15 = S32(ctx->r14 << 12);
    // 0x8007EA24: mflo        $t2
    ctx->r10 = lo;
    // 0x8007EA28: addiu       $t0, $t2, 0x1
    ctx->r8 = ADD32(ctx->r10, 0X1);
    // 0x8007EA2C: andi        $t6, $t8, 0xFFF
    ctx->r14 = ctx->r24 & 0XFFF;
    // 0x8007EA30: sra         $t8, $t0, 1
    ctx->r24 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007EA34: addiu       $t0, $t8, -0x1
    ctx->r8 = ADD32(ctx->r24, -0X1);
    // 0x8007EA38: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007EA3C: or          $t9, $t7, $t6
    ctx->r25 = ctx->r15 | ctx->r14;
    // 0x8007EA40: sw          $t9, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r25;
    // 0x8007EA44: beq         $at, $zero, L_8007EA54
    if (ctx->r1 == 0) {
        // 0x8007EA48: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007EA54;
    }
    // 0x8007EA48: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EA4C: b           L_8007EA58
    // 0x8007EA50: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007EA58;
    // 0x8007EA50: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007EA54:
    // 0x8007EA54: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007EA58:
    // 0x8007EA58: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007EA5C: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007EA60: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EA64: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8007EA68: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007EA6C: addiu       $t7, $t5, 0x7
    ctx->r15 = ADD32(ctx->r13, 0X7);
    // 0x8007EA70: sra         $t6, $t7, 3
    ctx->r14 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8007EA74: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007EA78: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007EA7C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007EA80: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007EA84: sll         $t8, $t9, 9
    ctx->r24 = S32(ctx->r25 << 9);
    // 0x8007EA88: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EA8C: lui         $at, 0xF568
    ctx->r1 = S32(0XF568 << 16);
    // 0x8007EA90: or          $t7, $t8, $at
    ctx->r15 = ctx->r24 | ctx->r1;
    // 0x8007EA94: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EA98: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007EA9C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007EAA0: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EAA4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EAA8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EAAC: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007EAB0: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007EAB4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007EAB8: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007EABC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EAC0: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007EAC4: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007EAC8: nop

    // 0x8007EACC: ori         $t6, $t7, 0x4
    ctx->r14 = ctx->r15 | 0X4;
    // 0x8007EAD0: sh          $t6, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r14;
L_8007EAD4:
    // 0x8007EAD4: lw          $t9, 0x27C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X27C);
    // 0x8007EAD8: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x8007EADC: bne         $t9, $at, L_8007EC58
    if (ctx->r25 != ctx->r1) {
        // 0x8007EAE0: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007EC58;
    }
    // 0x8007EAE0: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EAE4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EAE8: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007EAEC: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007EAF0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EAF4: lui         $t8, 0xFD70
    ctx->r24 = S32(0XFD70 << 16);
    // 0x8007EAF8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007EAFC: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EB00: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007EB04: lui         $t6, 0xF570
    ctx->r14 = S32(0XF570 << 16);
    // 0x8007EB08: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x8007EB0C: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007EB10: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007EB14: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007EB18: andi        $t9, $v0, 0x3
    ctx->r25 = ctx->r2 & 0X3;
    // 0x8007EB1C: sll         $v0, $t9, 18
    ctx->r2 = S32(ctx->r25 << 18);
    // 0x8007EB20: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007EB24: andi        $t9, $a1, 0x3
    ctx->r25 = ctx->r5 & 0X3;
    // 0x8007EB28: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007EB2C: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007EB30: sll         $a1, $t9, 8
    ctx->r5 = S32(ctx->r25 << 8);
    // 0x8007EB34: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EB38: or          $t9, $v0, $at
    ctx->r25 = ctx->r2 | ctx->r1;
    // 0x8007EB3C: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007EB40: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007EB44: or          $t8, $t9, $v1
    ctx->r24 = ctx->r25 | ctx->r3;
    // 0x8007EB48: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007EB4C: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007EB50: or          $t6, $t7, $a2
    ctx->r14 = ctx->r15 | ctx->r6;
    // 0x8007EB54: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB58: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007EB5C: sw          $t6, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r14;
    // 0x8007EB60: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EB64: lui         $t9, 0xE600
    ctx->r25 = S32(0XE600 << 16);
    // 0x8007EB68: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x8007EB6C: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007EB70: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007EB74: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007EB78: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007EB7C: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007EB80: or          $t6, $t7, $a1
    ctx->r14 = ctx->r15 | ctx->r5;
    // 0x8007EB84: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007EB88: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007EB8C: or          $t9, $t6, $a2
    ctx->r25 = ctx->r14 | ctx->r6;
    // 0x8007EB90: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007EB94: sw          $t9, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r25;
    // 0x8007EB98: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007EB9C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007EBA0: sll         $t9, $t6, 12
    ctx->r25 = S32(ctx->r14 << 12);
    // 0x8007EBA4: andi        $t6, $t7, 0xFFF
    ctx->r14 = ctx->r15 & 0XFFF;
    // 0x8007EBA8: mflo        $t0
    ctx->r8 = lo;
    // 0x8007EBAC: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007EBB0: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007EBB4: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007EBB8: sra         $t7, $t0, 2
    ctx->r15 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007EBBC: or          $t8, $t9, $t6
    ctx->r24 = ctx->r25 | ctx->r14;
    // 0x8007EBC0: sra         $t9, $ra, 3
    ctx->r25 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007EBC4: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007EBC8: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007EBCC: andi        $t6, $t9, 0x1FF
    ctx->r14 = ctx->r25 & 0X1FF;
    // 0x8007EBD0: sll         $ra, $t6, 9
    ctx->r31 = S32(ctx->r14 << 9);
    // 0x8007EBD4: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007EBD8: beq         $at, $zero, L_8007EBE8
    if (ctx->r1 == 0) {
        // 0x8007EBDC: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007EBE8;
    }
    // 0x8007EBDC: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EBE0: b           L_8007EBEC
    // 0x8007EBE4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007EBEC;
    // 0x8007EBE4: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007EBE8:
    // 0x8007EBE8: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007EBEC:
    // 0x8007EBEC: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007EBF0: sll         $t9, $t7, 12
    ctx->r25 = S32(ctx->r15 << 12);
    // 0x8007EBF4: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EBF8: or          $t6, $t9, $at
    ctx->r14 = ctx->r25 | ctx->r1;
    // 0x8007EBFC: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007EC00: sw          $t6, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r14;
    // 0x8007EC04: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EC08: lui         $at, 0xF560
    ctx->r1 = S32(0XF560 << 16);
    // 0x8007EC0C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007EC10: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007EC14: or          $t7, $ra, $at
    ctx->r15 = ctx->r31 | ctx->r1;
    // 0x8007EC18: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EC1C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007EC20: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007EC24: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EC28: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EC2C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EC30: lui         $t6, 0xF200
    ctx->r14 = S32(0XF200 << 16);
    // 0x8007EC34: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    // 0x8007EC38: sw          $t6, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r14;
    // 0x8007EC3C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007EC40: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EC44: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
    // 0x8007EC48: lh          $t7, 0x6($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X6);
    // 0x8007EC4C: nop

    // 0x8007EC50: ori         $t9, $t7, 0x4
    ctx->r25 = ctx->r15 | 0X4;
    // 0x8007EC54: sh          $t9, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r25;
L_8007EC58:
    // 0x8007EC58: lw          $t6, 0x27C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X27C);
    // 0x8007EC5C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8007EC60: bne         $t6, $at, L_8007EDC8
    if (ctx->r14 != ctx->r1) {
        // 0x8007EC64: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007EDC8;
    }
    // 0x8007EC64: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EC68: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EC6C: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007EC70: addu        $t7, $s1, $at
    ctx->r15 = ADD32(ctx->r17, ctx->r1);
    // 0x8007EC74: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EC78: lui         $t8, 0xFD90
    ctx->r24 = S32(0XFD90 << 16);
    // 0x8007EC7C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x8007EC80: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EC84: sw          $t7, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r15;
    // 0x8007EC88: lui         $t9, 0xF590
    ctx->r25 = S32(0XF590 << 16);
    // 0x8007EC8C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8007EC90: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007EC94: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007EC98: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007EC9C: andi        $t6, $v0, 0x3
    ctx->r14 = ctx->r2 & 0X3;
    // 0x8007ECA0: sll         $v0, $t6, 18
    ctx->r2 = S32(ctx->r14 << 18);
    // 0x8007ECA4: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007ECA8: andi        $t6, $a1, 0x3
    ctx->r14 = ctx->r5 & 0X3;
    // 0x8007ECAC: andi        $t7, $v1, 0xF
    ctx->r15 = ctx->r3 & 0XF;
    // 0x8007ECB0: sll         $v1, $t7, 14
    ctx->r3 = S32(ctx->r15 << 14);
    // 0x8007ECB4: sll         $a1, $t6, 8
    ctx->r5 = S32(ctx->r14 << 8);
    // 0x8007ECB8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007ECBC: or          $t6, $v0, $at
    ctx->r14 = ctx->r2 | ctx->r1;
    // 0x8007ECC0: andi        $t7, $a2, 0xF
    ctx->r15 = ctx->r6 & 0XF;
    // 0x8007ECC4: sll         $a2, $t7, 4
    ctx->r6 = S32(ctx->r15 << 4);
    // 0x8007ECC8: or          $t8, $t6, $v1
    ctx->r24 = ctx->r14 | ctx->r3;
    // 0x8007ECCC: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007ECD0: or          $t7, $t8, $a1
    ctx->r15 = ctx->r24 | ctx->r5;
    // 0x8007ECD4: or          $t9, $t7, $a2
    ctx->r25 = ctx->r15 | ctx->r6;
    // 0x8007ECD8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ECDC: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007ECE0: sw          $t9, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r25;
    // 0x8007ECE4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ECE8: lui         $t6, 0xE600
    ctx->r14 = S32(0XE600 << 16);
    // 0x8007ECEC: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8007ECF0: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007ECF4: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007ECF8: or          $t7, $v0, $v1
    ctx->r15 = ctx->r2 | ctx->r3;
    // 0x8007ECFC: lui         $t8, 0xF300
    ctx->r24 = S32(0XF300 << 16);
    // 0x8007ED00: sw          $t8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r24;
    // 0x8007ED04: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8007ED08: addiu       $t8, $t5, -0x1
    ctx->r24 = ADD32(ctx->r13, -0X1);
    // 0x8007ED0C: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007ED10: or          $t6, $t9, $a2
    ctx->r14 = ctx->r25 | ctx->r6;
    // 0x8007ED14: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007ED18: sw          $t6, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r14;
    // 0x8007ED1C: addiu       $t8, $s0, -0x1
    ctx->r24 = ADD32(ctx->r16, -0X1);
    // 0x8007ED20: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8007ED24: sll         $t6, $t9, 12
    ctx->r14 = S32(ctx->r25 << 12);
    // 0x8007ED28: andi        $t9, $t7, 0xFFF
    ctx->r25 = ctx->r15 & 0XFFF;
    // 0x8007ED2C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007ED30: addiu       $t0, $t0, 0x1
    ctx->r8 = ADD32(ctx->r8, 0X1);
    // 0x8007ED34: sra         $t7, $t0, 1
    ctx->r15 = S32(SIGNED(ctx->r8) >> 1);
    // 0x8007ED38: or          $t8, $t6, $t9
    ctx->r24 = ctx->r14 | ctx->r25;
    // 0x8007ED3C: addiu       $t4, $t5, 0x7
    ctx->r12 = ADD32(ctx->r13, 0X7);
    // 0x8007ED40: sra         $t6, $t4, 3
    ctx->r14 = S32(SIGNED(ctx->r12) >> 3);
    // 0x8007ED44: addiu       $t0, $t7, -0x1
    ctx->r8 = ADD32(ctx->r15, -0X1);
    // 0x8007ED48: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007ED4C: andi        $t9, $t6, 0x1FF
    ctx->r25 = ctx->r14 & 0X1FF;
    // 0x8007ED50: sll         $t4, $t9, 9
    ctx->r12 = S32(ctx->r25 << 9);
    // 0x8007ED54: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x8007ED58: beq         $at, $zero, L_8007ED68
    if (ctx->r1 == 0) {
        // 0x8007ED5C: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007ED68;
    }
    // 0x8007ED5C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ED60: b           L_8007ED6C
    // 0x8007ED64: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007ED6C;
    // 0x8007ED64: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007ED68:
    // 0x8007ED68: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007ED6C:
    // 0x8007ED6C: andi        $t7, $a0, 0xFFF
    ctx->r15 = ctx->r4 & 0XFFF;
    // 0x8007ED70: sll         $t6, $t7, 12
    ctx->r14 = S32(ctx->r15 << 12);
    // 0x8007ED74: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007ED78: or          $t9, $t6, $at
    ctx->r25 = ctx->r14 | ctx->r1;
    // 0x8007ED7C: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007ED80: sw          $t9, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r25;
    // 0x8007ED84: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007ED88: lui         $at, 0xF588
    ctx->r1 = S32(0XF588 << 16);
    // 0x8007ED8C: lui         $t8, 0xE700
    ctx->r24 = S32(0XE700 << 16);
    // 0x8007ED90: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x8007ED94: or          $t7, $t4, $at
    ctx->r15 = ctx->r12 | ctx->r1;
    // 0x8007ED98: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007ED9C: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007EDA0: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007EDA4: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EDA8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EDAC: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EDB0: lui         $t9, 0xF200
    ctx->r25 = S32(0XF200 << 16);
    // 0x8007EDB4: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x8007EDB8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007EDBC: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8007EDC0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EDC4: sw          $t8, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r24;
L_8007EDC8:
    // 0x8007EDC8: lw          $t7, 0x27C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X27C);
    // 0x8007EDCC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8007EDD0: bne         $t7, $at, L_8007EF3C
    if (ctx->r15 != ctx->r1) {
        // 0x8007EDD4: or          $a0, $a3, $zero
        ctx->r4 = ctx->r7 | 0;
            goto L_8007EF3C;
    }
    // 0x8007EDD4: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x8007EDD8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8007EDDC: ori         $at, $at, 0x20
    ctx->r1 = ctx->r1 | 0X20;
    // 0x8007EDE0: addu        $t9, $s1, $at
    ctx->r25 = ADD32(ctx->r17, ctx->r1);
    // 0x8007EDE4: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EDE8: lui         $t6, 0xFD90
    ctx->r14 = S32(0XFD90 << 16);
    // 0x8007EDEC: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x8007EDF0: or          $t1, $a3, $zero
    ctx->r9 = ctx->r7 | 0;
    // 0x8007EDF4: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x8007EDF8: lui         $t8, 0xF590
    ctx->r24 = S32(0XF590 << 16);
    // 0x8007EDFC: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x8007EE00: lw          $v0, 0x268($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X268);
    // 0x8007EE04: lw          $a1, 0x26C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X26C);
    // 0x8007EE08: lw          $v1, 0x260($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X260);
    // 0x8007EE0C: andi        $t7, $v0, 0x3
    ctx->r15 = ctx->r2 & 0X3;
    // 0x8007EE10: sll         $v0, $t7, 18
    ctx->r2 = S32(ctx->r15 << 18);
    // 0x8007EE14: lw          $a2, 0x264($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X264);
    // 0x8007EE18: andi        $t7, $a1, 0x3
    ctx->r15 = ctx->r5 & 0X3;
    // 0x8007EE1C: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x8007EE20: sll         $v1, $t9, 14
    ctx->r3 = S32(ctx->r25 << 14);
    // 0x8007EE24: sll         $a1, $t7, 8
    ctx->r5 = S32(ctx->r15 << 8);
    // 0x8007EE28: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EE2C: or          $t7, $v0, $at
    ctx->r15 = ctx->r2 | ctx->r1;
    // 0x8007EE30: andi        $t9, $a2, 0xF
    ctx->r25 = ctx->r6 & 0XF;
    // 0x8007EE34: sll         $a2, $t9, 4
    ctx->r6 = S32(ctx->r25 << 4);
    // 0x8007EE38: or          $t6, $t7, $v1
    ctx->r14 = ctx->r15 | ctx->r3;
    // 0x8007EE3C: multu       $t5, $s0
    result = U64(U32(ctx->r13)) * U64(U32(ctx->r16)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8007EE40: or          $t9, $t6, $a1
    ctx->r25 = ctx->r14 | ctx->r5;
    // 0x8007EE44: or          $t8, $t9, $a2
    ctx->r24 = ctx->r25 | ctx->r6;
    // 0x8007EE48: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EE4C: or          $t2, $a3, $zero
    ctx->r10 = ctx->r7 | 0;
    // 0x8007EE50: sw          $t8, 0x4($t1)
    MEM_W(0X4, ctx->r9) = ctx->r24;
    // 0x8007EE54: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EE58: lui         $t7, 0xE600
    ctx->r15 = S32(0XE600 << 16);
    // 0x8007EE5C: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
    // 0x8007EE60: or          $t3, $a3, $zero
    ctx->r11 = ctx->r7 | 0;
    // 0x8007EE64: sw          $zero, 0x4($t2)
    MEM_W(0X4, ctx->r10) = 0;
    // 0x8007EE68: or          $t9, $v0, $v1
    ctx->r25 = ctx->r2 | ctx->r3;
    // 0x8007EE6C: lui         $t6, 0xF300
    ctx->r14 = S32(0XF300 << 16);
    // 0x8007EE70: sw          $t6, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r14;
    // 0x8007EE74: or          $t8, $t9, $a1
    ctx->r24 = ctx->r25 | ctx->r5;
    // 0x8007EE78: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8007EE7C: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8007EE80: or          $t7, $t8, $a2
    ctx->r15 = ctx->r24 | ctx->r6;
    // 0x8007EE84: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007EE88: sw          $t7, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r15;
    // 0x8007EE8C: addiu       $t6, $s0, -0x1
    ctx->r14 = ADD32(ctx->r16, -0X1);
    // 0x8007EE90: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8007EE94: sll         $t7, $t8, 12
    ctx->r15 = S32(ctx->r24 << 12);
    // 0x8007EE98: andi        $t8, $t9, 0xFFF
    ctx->r24 = ctx->r25 & 0XFFF;
    // 0x8007EE9C: mflo        $t0
    ctx->r8 = lo;
    // 0x8007EEA0: addiu       $t0, $t0, 0x3
    ctx->r8 = ADD32(ctx->r8, 0X3);
    // 0x8007EEA4: sra         $ra, $t5, 1
    ctx->r31 = S32(SIGNED(ctx->r13) >> 1);
    // 0x8007EEA8: addiu       $ra, $ra, 0x7
    ctx->r31 = ADD32(ctx->r31, 0X7);
    // 0x8007EEAC: sra         $t9, $t0, 2
    ctx->r25 = S32(SIGNED(ctx->r8) >> 2);
    // 0x8007EEB0: or          $t6, $t7, $t8
    ctx->r14 = ctx->r15 | ctx->r24;
    // 0x8007EEB4: sra         $t7, $ra, 3
    ctx->r15 = S32(SIGNED(ctx->r31) >> 3);
    // 0x8007EEB8: addiu       $t0, $t9, -0x1
    ctx->r8 = ADD32(ctx->r25, -0X1);
    // 0x8007EEBC: slti        $at, $t0, 0x7FF
    ctx->r1 = SIGNED(ctx->r8) < 0X7FF ? 1 : 0;
    // 0x8007EEC0: andi        $t8, $t7, 0x1FF
    ctx->r24 = ctx->r15 & 0X1FF;
    // 0x8007EEC4: sll         $ra, $t8, 9
    ctx->r31 = S32(ctx->r24 << 9);
    // 0x8007EEC8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8007EECC: beq         $at, $zero, L_8007EEDC
    if (ctx->r1 == 0) {
        // 0x8007EED0: addiu       $a3, $a3, 0x8
        ctx->r7 = ADD32(ctx->r7, 0X8);
            goto L_8007EEDC;
    }
    // 0x8007EED0: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EED4: b           L_8007EEE0
    // 0x8007EED8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
        goto L_8007EEE0;
    // 0x8007EED8: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_8007EEDC:
    // 0x8007EEDC: addiu       $a0, $zero, 0x7FF
    ctx->r4 = ADD32(0, 0X7FF);
L_8007EEE0:
    // 0x8007EEE0: andi        $t9, $a0, 0xFFF
    ctx->r25 = ctx->r4 & 0XFFF;
    // 0x8007EEE4: sll         $t7, $t9, 12
    ctx->r15 = S32(ctx->r25 << 12);
    // 0x8007EEE8: lui         $at, 0x700
    ctx->r1 = S32(0X700 << 16);
    // 0x8007EEEC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x8007EEF0: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    // 0x8007EEF4: sw          $t8, 0x4($t3)
    MEM_W(0X4, ctx->r11) = ctx->r24;
    // 0x8007EEF8: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EEFC: lui         $at, 0xF580
    ctx->r1 = S32(0XF580 << 16);
    // 0x8007EF00: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x8007EF04: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8007EF08: or          $t9, $ra, $at
    ctx->r25 = ctx->r31 | ctx->r1;
    // 0x8007EF0C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
    // 0x8007EF10: sw          $zero, 0x4($v0)
    MEM_W(0X4, ctx->r2) = 0;
    // 0x8007EF14: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8007EF18: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x8007EF1C: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EF20: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8007EF24: lui         $t8, 0xF200
    ctx->r24 = S32(0XF200 << 16);
    // 0x8007EF28: sw          $t7, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r15;
    // 0x8007EF2C: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x8007EF30: lw          $t6, 0x28($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X28);
    // 0x8007EF34: addiu       $a3, $a3, 0x8
    ctx->r7 = ADD32(ctx->r7, 0X8);
    // 0x8007EF38: sw          $t6, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r14;
L_8007EF3C:
    // 0x8007EF3C: lw          $t9, 0xC($s1)
    ctx->r25 = MEM_W(ctx->r17, 0XC);
    // 0x8007EF40: nop

    // 0x8007EF44: subu        $t7, $a3, $t9
    ctx->r15 = SUB32(ctx->r7, ctx->r25);
    // 0x8007EF48: sra         $t8, $t7, 3
    ctx->r24 = S32(SIGNED(ctx->r15) >> 3);
    // 0x8007EF4C: sh          $t8, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r24;
L_8007EF50:
    // 0x8007EF50: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007EF54: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8007EF58: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8007EF5C: jr          $ra
    // 0x8007EF60: addiu       $sp, $sp, 0x280
    ctx->r29 = ADD32(ctx->r29, 0X280);
    return;
    // 0x8007EF60: addiu       $sp, $sp, 0x280
    ctx->r29 = ADD32(ctx->r29, 0X280);
;}
RECOMP_FUNC void read_time_data_from_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80074018: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8007401C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074020: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074024: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074028: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8007402C: jal         0x800758DC
    // 0x80074030: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    get_si_device_status(rdram, ctx);
        goto after_0;
    // 0x80074030: sw          $a2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r6;
    after_0:
    // 0x80074034: beq         $v0, $zero, L_80074058
    if (ctx->r2 == 0) {
        // 0x80074038: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80074058;
    }
    // 0x80074038: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007403C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074040: jal         0x80075AEC
    // 0x80074044: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    start_reading_controller_data(rdram, ctx);
        goto after_1;
    // 0x80074044: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_1:
    // 0x80074048: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8007404C: sll         $t6, $s0, 30
    ctx->r14 = S32(ctx->r16 << 30);
    // 0x80074050: b           L_80074138
    // 0x80074054: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
        goto L_80074138;
    // 0x80074054: or          $v0, $t6, $v1
    ctx->r2 = ctx->r14 | ctx->r3;
L_80074058:
    // 0x80074058: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8007405C: lw          $a2, 0x34($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X34);
    // 0x80074060: addiu       $a1, $a1, 0x7690
    ctx->r5 = ADD32(ctx->r5, 0X7690);
    // 0x80074064: jal         0x800764E8
    // 0x80074068: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    get_file_number(rdram, ctx);
        goto after_2;
    // 0x80074068: addiu       $a3, $sp, 0x24
    ctx->r7 = ADD32(ctx->r29, 0X24);
    after_2:
    // 0x8007406C: bne         $v0, $zero, L_80074114
    if (ctx->r2 != 0) {
        // 0x80074070: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80074114;
    }
    // 0x80074070: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80074074: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80074078: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007407C: jal         0x80076924
    // 0x80074080: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    get_file_size(rdram, ctx);
        goto after_3;
    // 0x80074080: addiu       $a2, $sp, 0x20
    ctx->r6 = ADD32(ctx->r29, 0X20);
    after_3:
    // 0x80074084: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x80074088: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8007408C: bne         $a0, $zero, L_80074098
    if (ctx->r4 != 0) {
        // 0x80074090: nop
    
            goto L_80074098;
    }
    // 0x80074090: nop

    // 0x80074094: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
L_80074098:
    // 0x80074098: bne         $v1, $zero, L_80074114
    if (ctx->r3 != 0) {
        // 0x8007409C: nop
    
            goto L_80074114;
    }
    // 0x8007409C: nop

    // 0x800740A0: jal         0x80070C9C
    // 0x800740A4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_4;
    // 0x800740A4: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_4:
    // 0x800740A8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800740AC: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x800740B0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x800740B4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800740B8: jal         0x80076610
    // 0x800740BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    read_data_from_controller_pak(rdram, ctx);
        goto after_5;
    // 0x800740BC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    after_5:
    // 0x800740C0: bne         $v0, $zero, L_80074100
    if (ctx->r2 != 0) {
        // 0x800740C4: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80074100;
    }
    // 0x800740C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800740C8: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800740CC: lui         $at, 0x5449
    ctx->r1 = S32(0X5449 << 16);
    // 0x800740D0: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800740D4: ori         $at, $at, 0x4D44
    ctx->r1 = ctx->r1 | 0X4D44;
    // 0x800740D8: bne         $t7, $at, L_80074100
    if (ctx->r15 != ctx->r1) {
        // 0x800740DC: addiu       $v1, $zero, 0x9
        ctx->r3 = ADD32(0, 0X9);
            goto L_80074100;
    }
    // 0x800740DC: addiu       $v1, $zero, 0x9
    ctx->r3 = ADD32(0, 0X9);
    // 0x800740E0: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800740E4: addiu       $a1, $a3, 0x4
    ctx->r5 = ADD32(ctx->r7, 0X4);
    // 0x800740E8: addiu       $a2, $zero, 0x3
    ctx->r6 = ADD32(0, 0X3);
    // 0x800740EC: jal         0x80073588
    // 0x800740F0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80073588(rdram, ctx);
        goto after_6;
    // 0x800740F0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_6:
    // 0x800740F4: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x800740F8: b           L_80074104
    // 0x800740FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
        goto L_80074104;
    // 0x800740FC: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80074100:
    // 0x80074100: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
L_80074104:
    // 0x80074104: jal         0x80071140
    // 0x80074108: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_7;
    // 0x80074108: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_7:
    // 0x8007410C: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074110: nop

L_80074114:
    // 0x80074114: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80074118: jal         0x80075AEC
    // 0x8007411C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    start_reading_controller_data(rdram, ctx);
        goto after_8;
    // 0x8007411C: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_8:
    // 0x80074120: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80074124: sll         $t8, $s0, 30
    ctx->r24 = S32(ctx->r16 << 30);
    // 0x80074128: beq         $v1, $zero, L_80074138
    if (ctx->r3 == 0) {
        // 0x8007412C: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074138;
    }
    // 0x8007412C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80074130: or          $v1, $v1, $t8
    ctx->r3 = ctx->r3 | ctx->r24;
    // 0x80074134: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074138:
    // 0x80074138: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8007413C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074140: jr          $ra
    // 0x80074144: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x80074144: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void music_current_sequence(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001918: lui         $v1, 0x8011
    ctx->r3 = S32(0X8011 << 16);
    // 0x8000191C: lbu         $v1, 0x5D04($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X5D04);
    // 0x80001920: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80001924: beq         $v1, $zero, L_8000194C
    if (ctx->r3 == 0) {
        // 0x80001928: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8000194C;
    }
    // 0x80001928: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000192C: lw          $t6, -0x39D0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X39D0);
    // 0x80001930: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80001934: lw          $t7, 0x2C($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X2C);
    // 0x80001938: nop

    // 0x8000193C: bne         $t7, $at, L_8000194C
    if (ctx->r15 != ctx->r1) {
        // 0x80001940: nop
    
            goto L_8000194C;
    }
    // 0x80001940: nop

    // 0x80001944: jr          $ra
    // 0x80001948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80001948: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000194C:
    // 0x8000194C: jr          $ra
    // 0x80001950: nop

    return;
    // 0x80001950: nop

;}
RECOMP_FUNC void rain_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800ADBC8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800ADBCC: lw          $t6, 0x2C60($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2C60);
    // 0x800ADBD0: lui         $at, 0x4490
    ctx->r1 = S32(0X4490 << 16);
    // 0x800ADBD4: sra         $t7, $t6, 6
    ctx->r15 = S32(SIGNED(ctx->r14) >> 6);
    // 0x800ADBD8: mtc1        $t7, $f6
    ctx->f6.u32l = ctx->r15;
    // 0x800ADBDC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800ADBE0: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800ADBE4: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800ADBE8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800ADBEC: sub.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f8.fl;
    // 0x800ADBF0: lw          $t8, 0x7C1C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X7C1C);
    // 0x800ADBF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800ADBF8: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800ADBFC: swc1        $f10, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f10.u32l;
    // 0x800ADC00: lh          $a0, 0x0($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X0);
    // 0x800ADC04: jal         0x800707C4
    // 0x800ADC08: nop

    sins_f(rdram, ctx);
        goto after_0;
    // 0x800ADC08: nop

    after_0:
    // 0x800ADC0C: lwc1        $f6, 0x28($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800ADC10: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800ADC14: mul.s       $f12, $f0, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800ADC18: lw          $t9, 0x7C1C($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X7C1C);
    // 0x800ADC1C: nop

    // 0x800ADC20: lh          $a0, 0x0($t9)
    ctx->r4 = MEM_H(ctx->r25, 0X0);
    // 0x800ADC24: jal         0x800707F8
    // 0x800ADC28: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800ADC28: swc1        $f12, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f12.u32l;
    after_1:
    // 0x800ADC2C: lwc1        $f4, 0x28($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X28);
    // 0x800ADC30: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800ADC34: mul.s       $f2, $f0, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x800ADC38: lwc1        $f12, 0x24($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800ADC3C: lw          $v0, 0x7C1C($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X7C1C);
    // 0x800ADC40: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800ADC44: sub.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x800ADC48: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x800ADC4C: addiu       $v1, $v1, 0x2C94
    ctx->r3 = ADD32(ctx->r3, 0X2C94);
    // 0x800ADC50: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x800ADC54: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800ADC58: neg.s       $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = -ctx->f2.fl;
    // 0x800ADC5C: add.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800ADC60: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800ADC64: sub.s       $f8, $f4, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = ctx->f4.fl - ctx->f12.fl;
    // 0x800ADC68: beq         $a0, $zero, L_800ADC8C
    if (ctx->r4 == 0) {
        // 0x800ADC6C: add.s       $f18, $f6, $f8
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
            goto L_800ADC8C;
    }
    // 0x800ADC6C: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800ADC70: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800ADC74: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800ADC78: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800ADC7C: jal         0x800096D8
    // 0x800ADC80: nop

    audspat_point_set_position(rdram, ctx);
        goto after_2;
    // 0x800ADC80: nop

    after_2:
    // 0x800ADC84: b           L_800ADCB0
    // 0x800ADC88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_800ADCB0;
    // 0x800ADC88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800ADC8C:
    // 0x800ADC8C: mfc1        $a1, $f14
    ctx->r5 = (int32_t)ctx->f14.u32l;
    // 0x800ADC90: mfc1        $a2, $f16
    ctx->r6 = (int32_t)ctx->f16.u32l;
    // 0x800ADC94: mfc1        $a3, $f18
    ctx->r7 = (int32_t)ctx->f18.u32l;
    // 0x800ADC98: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800ADC9C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x800ADCA0: addiu       $a0, $zero, 0x23E
    ctx->r4 = ADD32(0, 0X23E);
    // 0x800ADCA4: jal         0x80009558
    // 0x800ADCA8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x800ADCA8: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    after_3:
    // 0x800ADCAC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800ADCB0:
    // 0x800ADCB0: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    // 0x800ADCB4: jr          $ra
    // 0x800ADCB8: nop

    return;
    // 0x800ADCB8: nop

;}
RECOMP_FUNC void racer_boss_finish(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005CB68: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8005CB6C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8005CB70: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8005CB74: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8005CB78: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8005CB7C: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8005CB80: jal         0x8006EA90
    // 0x8005CB84: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8005CB84: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    after_0:
    // 0x8005CB88: lbu         $t8, 0x48($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X48);
    // 0x8005CB8C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8005CB90: sllv        $t1, $t9, $t8
    ctx->r9 = S32(ctx->r25 << (ctx->r24 & 31));
    // 0x8005CB94: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005CB98: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8005CB9C: jal         0x8001E29C
    // 0x8005CBA0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8005CBA0: addiu       $a0, $zero, 0x44
    ctx->r4 = ADD32(0, 0X44);
    after_1:
    // 0x8005CBA4: lb          $t4, 0x5($v0)
    ctx->r12 = MEM_B(ctx->r2, 0X5);
    // 0x8005CBA8: addiu       $a0, $zero, 0x43
    ctx->r4 = ADD32(0, 0X43);
    // 0x8005CBAC: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
    // 0x8005CBB0: lb          $t5, 0x6($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X6);
    // 0x8005CBB4: nop

    // 0x8005CBB8: sw          $t5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r13;
    // 0x8005CBBC: lb          $t6, 0x7($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X7);
    // 0x8005CBC0: jal         0x8001E29C
    // 0x8005CBC4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    get_misc_asset(rdram, ctx);
        goto after_2;
    // 0x8005CBC4: sw          $t6, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r14;
    after_2:
    // 0x8005CBC8: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005CBCC: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x8005CBD0: lbu         $a0, 0x49($t2)
    ctx->r4 = MEM_BU(ctx->r10, 0X49);
    // 0x8005CBD4: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005CBD8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x8005CBDC: beq         $a0, $t7, L_8005CBF8
    if (ctx->r4 == ctx->r15) {
        // 0x8005CBE0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8005CBF8;
    }
    // 0x8005CBE0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8005CBE4: or          $v1, $a1, $zero
    ctx->r3 = ctx->r5 | 0;
L_8005CBE8:
    // 0x8005CBE8: lb          $t9, 0x2($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X2);
    // 0x8005CBEC: addiu       $s0, $s0, 0x2
    ctx->r16 = ADD32(ctx->r16, 0X2);
    // 0x8005CBF0: bne         $a0, $t9, L_8005CBE8
    if (ctx->r4 != ctx->r25) {
        // 0x8005CBF4: addiu       $v1, $v1, 0x2
        ctx->r3 = ADD32(ctx->r3, 0X2);
            goto L_8005CBE8;
    }
    // 0x8005CBF4: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
L_8005CBF8:
    // 0x8005CBF8: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x8005CBFC: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
    // 0x8005CC00: lh          $t5, 0x1AC($t4)
    ctx->r13 = MEM_H(ctx->r12, 0X1AC);
    // 0x8005CC04: addu        $t8, $s0, $v0
    ctx->r24 = ADD32(ctx->r16, ctx->r2);
    // 0x8005CC08: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8005CC0C: lb          $s0, 0x1($t8)
    ctx->r16 = MEM_B(ctx->r24, 0X1);
    // 0x8005CC10: bne         $t6, $v1, L_8005D028
    if (ctx->r14 != ctx->r3) {
        // 0x8005CC14: sw          $t5, 0x34($sp)
        MEM_W(0X34, ctx->r29) = ctx->r13;
            goto L_8005D028;
    }
    // 0x8005CC14: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
    // 0x8005CC18: bne         $t5, $v1, L_8005CC40
    if (ctx->r13 != ctx->r3) {
        // 0x8005CC1C: addiu       $a0, $zero, 0x3E
        ctx->r4 = ADD32(0, 0X3E);
            goto L_8005CC40;
    }
    // 0x8005CC1C: addiu       $a0, $zero, 0x3E
    ctx->r4 = ADD32(0, 0X3E);
    // 0x8005CC20: addiu       $a0, $zero, 0x3D
    ctx->r4 = ADD32(0, 0X3D);
    // 0x8005CC24: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005CC28: jal         0x80000B34
    // 0x8005CC2C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    music_play(rdram, ctx);
        goto after_3;
    // 0x8005CC2C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_3:
    // 0x8005CC30: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005CC34: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005CC38: b           L_8005CC5C
    // 0x8005CC3C: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
        goto L_8005CC5C;
    // 0x8005CC3C: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
L_8005CC40:
    // 0x8005CC40: sw          $t1, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r9;
    // 0x8005CC44: jal         0x80000B34
    // 0x8005CC48: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    music_play(rdram, ctx);
        goto after_4;
    // 0x8005CC48: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_4:
    // 0x8005CC4C: lw          $t1, 0x38($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X38);
    // 0x8005CC50: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005CC54: nop

    // 0x8005CC58: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
L_8005CC5C:
    // 0x8005CC5C: lw          $t0, 0x34($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X34);
    // 0x8005CC60: beq         $v1, $zero, L_8005CC6C
    if (ctx->r3 == 0) {
        // 0x8005CC64: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8005CC6C;
    }
    // 0x8005CC64: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8005CC68: bne         $v1, $at, L_8005CDF8
    if (ctx->r3 != ctx->r1) {
        // 0x8005CC6C: addiu       $t3, $zero, 0x1
        ctx->r11 = ADD32(0, 0X1);
            goto L_8005CDF8;
    }
L_8005CC6C:
    // 0x8005CC6C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8005CC70: bne         $t0, $t3, L_8005CCAC
    if (ctx->r8 != ctx->r11) {
        // 0x8005CC74: nop
    
            goto L_8005CCAC;
    }
    // 0x8005CC74: nop

    // 0x8005CC78: lhu         $t7, 0xC($t2)
    ctx->r15 = MEM_HU(ctx->r10, 0XC);
    // 0x8005CC7C: lbu         $t4, 0x49($t2)
    ctx->r12 = MEM_BU(ctx->r10, 0X49);
    // 0x8005CC80: lw          $t8, 0x4($t2)
    ctx->r24 = MEM_W(ctx->r10, 0X4);
    // 0x8005CC84: or          $t9, $t7, $t1
    ctx->r25 = ctx->r15 | ctx->r9;
    // 0x8005CC88: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x8005CC8C: sh          $t9, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r25;
    // 0x8005CC90: addu        $v0, $t8, $t6
    ctx->r2 = ADD32(ctx->r24, ctx->r14);
    // 0x8005CC94: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x8005CC98: nop

    // 0x8005CC9C: ori         $t7, $t5, 0x2
    ctx->r15 = ctx->r13 | 0X2;
    // 0x8005CCA0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005CCA4: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
    // 0x8005CCA8: nop

L_8005CCAC:
    // 0x8005CCAC: bne         $v1, $zero, L_8005CD2C
    if (ctx->r3 != 0) {
        // 0x8005CCB0: nop
    
            goto L_8005CD2C;
    }
    // 0x8005CCB0: nop

    // 0x8005CCB4: bne         $t0, $t3, L_8005CD00
    if (ctx->r8 != ctx->r11) {
        // 0x8005CCB8: addiu       $a0, $zero, -0xA
        ctx->r4 = ADD32(0, -0XA);
            goto L_8005CD00;
    }
    // 0x8005CCB8: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x8005CCBC: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x8005CCC0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CCC4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CCC8: jal         0x8006C1AC
    // 0x8005CCCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_5;
    // 0x8005CCCC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8005CCD0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x8005CCD4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CCD8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CCDC: jal         0x8006C1AC
    // 0x8005CCE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_6;
    // 0x8005CCE0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_6:
    // 0x8005CCE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CCE8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CCEC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CCF0: jal         0x8006C1AC
    // 0x8005CCF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    level_properties_push(rdram, ctx);
        goto after_7;
    // 0x8005CCF4: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_7:
    // 0x8005CCF8: b           L_8005CDC0
    // 0x8005CCFC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_8005CDC0;
    // 0x8005CCFC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CD00:
    // 0x8005CD00: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CD04: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CD08: jal         0x8006C1AC
    // 0x8005CD0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_8;
    // 0x8005CD0C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_8:
    // 0x8005CD10: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CD14: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CD18: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CD1C: jal         0x8006C1AC
    // 0x8005CD20: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    level_properties_push(rdram, ctx);
        goto after_9;
    // 0x8005CD20: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_9:
    // 0x8005CD24: b           L_8005CDC0
    // 0x8005CD28: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_8005CDC0;
    // 0x8005CD28: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CD2C:
    // 0x8005CD2C: bne         $t0, $t3, L_8005CD98
    if (ctx->r8 != ctx->r11) {
        // 0x8005CD30: addiu       $a0, $zero, -0xA
        ctx->r4 = ADD32(0, -0XA);
            goto L_8005CD98;
    }
    // 0x8005CD30: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x8005CD34: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8005CD38: jal         0x8009EA78
    // 0x8005CD3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    set_eeprom_settings_value(rdram, ctx);
        goto after_10;
    // 0x8005CD3C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_10:
    // 0x8005CD40: addiu       $a0, $zero, -0x2
    ctx->r4 = ADD32(0, -0X2);
    // 0x8005CD44: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CD48: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CD4C: jal         0x8006C1AC
    // 0x8005CD50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_11;
    // 0x8005CD50: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_11:
    // 0x8005CD54: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8005CD58: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CD5C: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CD60: jal         0x8006C1AC
    // 0x8005CD64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_12;
    // 0x8005CD64: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_12:
    // 0x8005CD68: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x8005CD6C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CD70: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CD74: jal         0x8006C1AC
    // 0x8005CD78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_13;
    // 0x8005CD78: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_13:
    // 0x8005CD7C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CD80: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CD84: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CD88: jal         0x8006C1AC
    // 0x8005CD8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    level_properties_push(rdram, ctx);
        goto after_14;
    // 0x8005CD8C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_14:
    // 0x8005CD90: b           L_8005CDC0
    // 0x8005CD94: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
        goto L_8005CDC0;
    // 0x8005CD94: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CD98:
    // 0x8005CD98: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CD9C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CDA0: jal         0x8006C1AC
    // 0x8005CDA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_15;
    // 0x8005CDA4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_15:
    // 0x8005CDA8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CDAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CDB0: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CDB4: jal         0x8006C1AC
    // 0x8005CDB8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    level_properties_push(rdram, ctx);
        goto after_16;
    // 0x8005CDB8: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    after_16:
    // 0x8005CDBC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
L_8005CDC0:
    // 0x8005CDC0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CDC4: bne         $t9, $at, L_8005CDDC
    if (ctx->r25 != ctx->r1) {
        // 0x8005CDC8: nop
    
            goto L_8005CDDC;
    }
    // 0x8005CDC8: nop

    // 0x8005CDCC: jal         0x8006F140
    // 0x8005CDD0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    level_transition_begin(rdram, ctx);
        goto after_17;
    // 0x8005CDD0: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_17:
    // 0x8005CDD4: b           L_8005CDE8
    // 0x8005CDD8: lb          $v0, 0x43($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X43);
        goto L_8005CDE8;
    // 0x8005CDD8: lb          $v0, 0x43($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X43);
L_8005CDDC:
    // 0x8005CDDC: jal         0x8006F140
    // 0x8005CDE0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_transition_begin(rdram, ctx);
        goto after_18;
    // 0x8005CDE0: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_18:
    // 0x8005CDE4: lb          $v0, 0x43($sp)
    ctx->r2 = MEM_B(ctx->r29, 0X43);
L_8005CDE8:
    // 0x8005CDE8: lw          $t6, 0x4C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X4C);
    // 0x8005CDEC: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x8005CDF0: b           L_8005D038
    // 0x8005CDF4: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
        goto L_8005D038;
    // 0x8005CDF4: sb          $t8, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r24;
L_8005CDF8:
    // 0x8005CDF8: lbu         $t7, 0x49($t2)
    ctx->r15 = MEM_BU(ctx->r10, 0X49);
    // 0x8005CDFC: lw          $t5, 0x4($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X4);
    // 0x8005CE00: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8005CE04: addu        $v0, $t5, $t9
    ctx->r2 = ADD32(ctx->r13, ctx->r25);
    // 0x8005CE08: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005CE0C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005CE10: andi        $t4, $v1, 0x2
    ctx->r12 = ctx->r3 & 0X2;
    // 0x8005CE14: beq         $t4, $zero, L_8005CE7C
    if (ctx->r12 == 0) {
        // 0x8005CE18: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8005CE7C;
    }
    // 0x8005CE18: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CE1C: lw          $t8, 0x34($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X34);
    // 0x8005CE20: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005CE24: bne         $t8, $at, L_8005CE44
    if (ctx->r24 != ctx->r1) {
        // 0x8005CE28: nop
    
            goto L_8005CE44;
    }
    // 0x8005CE28: nop

    // 0x8005CE2C: jal         0x8006F140
    // 0x8005CE30: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    level_transition_begin(rdram, ctx);
        goto after_19;
    // 0x8005CE30: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_19:
    // 0x8005CE34: jal         0x8000E128
    // 0x8005CE38: nop

    instShowBearBar(rdram, ctx);
        goto after_20;
    // 0x8005CE38: nop

    after_20:
    // 0x8005CE3C: b           L_8005CE68
    // 0x8005CE40: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
        goto L_8005CE68;
    // 0x8005CE40: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005CE44:
    // 0x8005CE44: jal         0x8006F140
    // 0x8005CE48: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_transition_begin(rdram, ctx);
        goto after_21;
    // 0x8005CE48: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_21:
    // 0x8005CE4C: jal         0x8009EC80
    // 0x8005CE50: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_22;
    // 0x8005CE50: nop

    after_22:
    // 0x8005CE54: beq         $v0, $zero, L_8005CE68
    if (ctx->r2 == 0) {
        // 0x8005CE58: lb          $t6, 0x43($sp)
        ctx->r14 = MEM_B(ctx->r29, 0X43);
            goto L_8005CE68;
    }
    // 0x8005CE58: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
    // 0x8005CE5C: jal         0x8006F398
    // 0x8005CE60: nop

    swap_lead_player(rdram, ctx);
        goto after_23;
    // 0x8005CE60: nop

    after_23:
    // 0x8005CE64: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005CE68:
    // 0x8005CE68: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x8005CE6C: addiu       $t9, $t6, 0x1
    ctx->r25 = ADD32(ctx->r14, 0X1);
    // 0x8005CE70: sb          $t9, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r25;
    // 0x8005CE74: b           L_8005D038
    // 0x8005CE78: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
        goto L_8005D038;
    // 0x8005CE78: sb          $t9, 0x0($t4)
    MEM_B(0X0, ctx->r12) = ctx->r25;
L_8005CE7C:
    // 0x8005CE7C: bne         $t8, $at, L_8005CFE0
    if (ctx->r24 != ctx->r1) {
        // 0x8005CE80: addiu       $a0, $zero, -0xA
        ctx->r4 = ADD32(0, -0XA);
            goto L_8005CFE0;
    }
    // 0x8005CE80: addiu       $a0, $zero, -0xA
    ctx->r4 = ADD32(0, -0XA);
    // 0x8005CE84: ori         $t6, $v1, 0x2
    ctx->r14 = ctx->r3 | 0X2;
    // 0x8005CE88: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x8005CE8C: lhu         $t0, 0xC($t2)
    ctx->r8 = MEM_HU(ctx->r10, 0XC);
    // 0x8005CE90: sll         $t9, $t1, 6
    ctx->r25 = S32(ctx->r9 << 6);
    // 0x8005CE94: and         $t7, $t0, $t1
    ctx->r15 = ctx->r8 & ctx->r9;
    // 0x8005CE98: bne         $t7, $zero, L_8005CED8
    if (ctx->r15 != 0) {
        // 0x8005CE9C: and         $t4, $t0, $t9
        ctx->r12 = ctx->r8 & ctx->r25;
            goto L_8005CED8;
    }
    // 0x8005CE9C: and         $t4, $t0, $t9
    ctx->r12 = ctx->r8 & ctx->r25;
    // 0x8005CEA0: or          $t5, $t0, $t1
    ctx->r13 = ctx->r8 | ctx->r9;
    // 0x8005CEA4: sh          $t5, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r13;
    // 0x8005CEA8: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005CEAC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CEB0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CEB4: jal         0x8006C1AC
    // 0x8005CEB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_24;
    // 0x8005CEB8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_24:
    // 0x8005CEBC: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CEC0: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005CEC4: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CEC8: jal         0x8006C1AC
    // 0x8005CECC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    level_properties_push(rdram, ctx);
        goto after_25;
    // 0x8005CECC: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_25:
    // 0x8005CED0: b           L_8005CFC8
    // 0x8005CED4: nop

        goto L_8005CFC8;
    // 0x8005CED4: nop

L_8005CED8:
    // 0x8005CED8: bne         $t4, $zero, L_8005CFA4
    if (ctx->r12 != 0) {
        // 0x8005CEDC: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8005CFA4;
    }
    // 0x8005CEDC: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005CEE0: lbu         $v1, 0x48($t2)
    ctx->r3 = MEM_BU(ctx->r10, 0X48);
    // 0x8005CEE4: or          $t8, $t0, $t9
    ctx->r24 = ctx->r8 | ctx->r25;
    // 0x8005CEE8: sh          $t8, 0xC($t2)
    MEM_H(0XC, ctx->r10) = ctx->r24;
    // 0x8005CEEC: blez        $v1, L_8005CF20
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8005CEF0: or          $t1, $zero, $zero
        ctx->r9 = 0 | 0;
            goto L_8005CF20;
    }
    // 0x8005CEF0: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x8005CEF4: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8005CEF8: beq         $at, $zero, L_8005CF20
    if (ctx->r1 == 0) {
        // 0x8005CEFC: nop
    
            goto L_8005CF20;
    }
    // 0x8005CEFC: nop

    // 0x8005CF00: lbu         $t1, 0x17($t2)
    ctx->r9 = MEM_BU(ctx->r10, 0X17);
    // 0x8005CF04: nop

    // 0x8005CF08: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8005CF0C: slti        $at, $t1, 0x5
    ctx->r1 = SIGNED(ctx->r9) < 0X5 ? 1 : 0;
    // 0x8005CF10: bne         $at, $zero, L_8005CF1C
    if (ctx->r1 != 0) {
        // 0x8005CF14: nop
    
            goto L_8005CF1C;
    }
    // 0x8005CF14: nop

    // 0x8005CF18: addiu       $t1, $zero, 0x4
    ctx->r9 = ADD32(0, 0X4);
L_8005CF1C:
    // 0x8005CF1C: sb          $t1, 0x17($t2)
    MEM_B(0X17, ctx->r10) = ctx->r9;
L_8005CF20:
    // 0x8005CF20: beq         $t1, $zero, L_8005CF78
    if (ctx->r9 == 0) {
        // 0x8005CF24: addiu       $a0, $zero, -0x1
        ctx->r4 = ADD32(0, -0X1);
            goto L_8005CF78;
    }
    // 0x8005CF24: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005CF28: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8005CF2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF30: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CF34: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8005CF38: jal         0x8006C1AC
    // 0x8005CF3C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    level_properties_push(rdram, ctx);
        goto after_26;
    // 0x8005CF3C: sw          $t2, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r10;
    after_26:
    // 0x8005CF40: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x8005CF44: addiu       $a0, $zero, 0x2B
    ctx->r4 = ADD32(0, 0X2B);
    // 0x8005CF48: lbu         $a3, 0x17($t2)
    ctx->r7 = MEM_BU(ctx->r10, 0X17);
    // 0x8005CF4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF50: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF54: jal         0x8006C1AC
    // 0x8005CF58: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    level_properties_push(rdram, ctx);
        goto after_27;
    // 0x8005CF58: addiu       $a3, $a3, -0x1
    ctx->r7 = ADD32(ctx->r7, -0X1);
    after_27:
    // 0x8005CF5C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CF60: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    // 0x8005CF64: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF68: jal         0x8006C1AC
    // 0x8005CF6C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    level_properties_push(rdram, ctx);
        goto after_28;
    // 0x8005CF6C: addiu       $a3, $zero, 0x6
    ctx->r7 = ADD32(0, 0X6);
    after_28:
    // 0x8005CF70: b           L_8005CFC8
    // 0x8005CF74: nop

        goto L_8005CFC8;
    // 0x8005CF74: nop

L_8005CF78:
    // 0x8005CF78: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CF7C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CF80: jal         0x8006C1AC
    // 0x8005CF84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_29;
    // 0x8005CF84: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_29:
    // 0x8005CF88: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CF8C: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005CF90: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CF94: jal         0x8006C1AC
    // 0x8005CF98: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    level_properties_push(rdram, ctx);
        goto after_30;
    // 0x8005CF98: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_30:
    // 0x8005CF9C: b           L_8005CFC8
    // 0x8005CFA0: nop

        goto L_8005CFC8;
    // 0x8005CFA0: nop

L_8005CFA4:
    // 0x8005CFA4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CFA8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CFAC: jal         0x8006C1AC
    // 0x8005CFB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_31;
    // 0x8005CFB0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_31:
    // 0x8005CFB4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CFB8: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
    // 0x8005CFBC: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CFC0: jal         0x8006C1AC
    // 0x8005CFC4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    level_properties_push(rdram, ctx);
        goto after_32;
    // 0x8005CFC4: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    after_32:
L_8005CFC8:
    // 0x8005CFC8: jal         0x8006F140
    // 0x8005CFCC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    level_transition_begin(rdram, ctx);
        goto after_33;
    // 0x8005CFCC: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    after_33:
    // 0x8005CFD0: jal         0x8000E128
    // 0x8005CFD4: nop

    instShowBearBar(rdram, ctx);
        goto after_34;
    // 0x8005CFD4: nop

    after_34:
    // 0x8005CFD8: b           L_8005D010
    // 0x8005CFDC: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
        goto L_8005D010;
    // 0x8005CFDC: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005CFE0:
    // 0x8005CFE0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8005CFE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8005CFE8: jal         0x8006C1AC
    // 0x8005CFEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    level_properties_push(rdram, ctx);
        goto after_35;
    // 0x8005CFEC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_35:
    // 0x8005CFF0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005CFF4: addiu       $a1, $zero, 0x5
    ctx->r5 = ADD32(0, 0X5);
    // 0x8005CFF8: addiu       $a2, $zero, -0x1
    ctx->r6 = ADD32(0, -0X1);
    // 0x8005CFFC: jal         0x8006C1AC
    // 0x8005D000: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    level_properties_push(rdram, ctx);
        goto after_36;
    // 0x8005D000: addiu       $a3, $zero, 0x5
    ctx->r7 = ADD32(0, 0X5);
    after_36:
    // 0x8005D004: jal         0x8006F140
    // 0x8005D008: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    level_transition_begin(rdram, ctx);
        goto after_37;
    // 0x8005D008: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_37:
    // 0x8005D00C: lb          $t6, 0x43($sp)
    ctx->r14 = MEM_B(ctx->r29, 0X43);
L_8005D010:
    // 0x8005D010: nop

    // 0x8005D014: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005D018: jal         0x8009C1A0
    // 0x8005D01C: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    get_save_file_index(rdram, ctx);
        goto after_38;
    // 0x8005D01C: sb          $t7, 0x43($sp)
    MEM_B(0X43, ctx->r29) = ctx->r15;
    after_38:
    // 0x8005D020: jal         0x8006EC48
    // 0x8005D024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_39;
    // 0x8005D024: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_39:
L_8005D028:
    // 0x8005D028: lb          $t5, 0x43($sp)
    ctx->r13 = MEM_B(ctx->r29, 0X43);
    // 0x8005D02C: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x8005D030: nop

    // 0x8005D034: sb          $t5, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r13;
L_8005D038:
    // 0x8005D038: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8005D03C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8005D040: jr          $ra
    // 0x8005D044: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x8005D044: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void sound_seqplayer_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80002224: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80002228: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x8000222C: addiu       $a2, $a2, 0x5CE8
    ctx->r6 = ADD32(ctx->r6, 0X5CE8);
    // 0x80002230: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80002234: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x80002238: sw          $a1, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r5;
    // 0x8000223C: sw          $a0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r4;
    // 0x80002240: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x80002244: sb          $a0, 0x34($sp)
    MEM_B(0X34, ctx->r29) = ctx->r4;
    // 0x80002248: addiu       $t8, $zero, 0x10
    ctx->r24 = ADD32(0, 0X10);
    // 0x8000224C: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80002250: sb          $t8, 0x2C($sp)
    MEM_B(0X2C, ctx->r29) = ctx->r24;
    // 0x80002254: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80002258: sw          $zero, 0x38($sp)
    MEM_W(0X38, ctx->r29) = 0;
    // 0x8000225C: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    // 0x80002260: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x80002264: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80002268: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000226C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80002270: jal         0x800C77F0
    // 0x80002274: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    alHeapDBAlloc(rdram, ctx);
        goto after_0;
    // 0x80002274: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    after_0:
    // 0x80002278: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x8000227C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80002280: jal         0x80062290
    // 0x80002284: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    alCSPNew(rdram, ctx);
        goto after_1;
    // 0x80002284: addiu       $a1, $sp, 0x24
    ctx->r5 = ADD32(ctx->r29, 0X24);
    after_1:
    // 0x80002288: lui         $t0, 0x8011
    ctx->r8 = S32(0X8011 << 16);
    // 0x8000228C: lw          $t0, 0x5D10($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X5D10);
    // 0x80002290: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80002294: lw          $a1, 0x4($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X4);
    // 0x80002298: jal         0x800C7A60
    // 0x8000229C: nop

    alCSPSetBank(rdram, ctx);
        goto after_2;
    // 0x8000229C: nop

    after_2:
    // 0x800022A0: lw          $v0, 0x44($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X44);
    // 0x800022A4: addiu       $t1, $zero, 0x7F
    ctx->r9 = ADD32(0, 0X7F);
    // 0x800022A8: sb          $t1, 0x36($v0)
    MEM_B(0X36, ctx->r2) = ctx->r9;
    // 0x800022AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800022B0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x800022B4: jr          $ra
    // 0x800022B8: nop

    return;
    // 0x800022B8: nop

;}
RECOMP_FUNC void audspat_point_stop_by_index(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A2E8: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000A2EC: addiu       $a3, $a3, -0x3920
    ctx->r7 = ADD32(ctx->r7, -0X3920);
    // 0x8000A2F0: lhu         $t6, 0x0($a3)
    ctx->r14 = MEM_HU(ctx->r7, 0X0);
    // 0x8000A2F4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8000A2F8: beq         $t6, $zero, L_8000A404
    if (ctx->r14 == 0) {
        // 0x8000A2FC: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8000A404;
    }
    // 0x8000A2FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8000A300: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000A304: lw          $t7, -0x63BC($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X63BC);
    // 0x8000A308: sll         $a1, $a0, 2
    ctx->r5 = S32(ctx->r4 << 2);
    // 0x8000A30C: addu        $v1, $t7, $a1
    ctx->r3 = ADD32(ctx->r15, ctx->r5);
    // 0x8000A310: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A314: nop

    // 0x8000A318: lw          $a0, 0x18($v0)
    ctx->r4 = MEM_W(ctx->r2, 0X18);
    // 0x8000A31C: nop

    // 0x8000A320: beq         $a0, $zero, L_8000A34C
    if (ctx->r4 == 0) {
        // 0x8000A324: nop
    
            goto L_8000A34C;
    }
    // 0x8000A324: nop

    // 0x8000A328: jal         0x8000488C
    // 0x8000A32C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x8000A32C: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000A330: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000A334: lw          $t8, -0x63BC($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X63BC);
    // 0x8000A338: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A33C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000A340: addu        $v1, $t8, $a1
    ctx->r3 = ADD32(ctx->r24, ctx->r5);
    // 0x8000A344: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x8000A348: addiu       $a3, $a3, -0x3920
    ctx->r7 = ADD32(ctx->r7, -0X3920);
L_8000A34C:
    // 0x8000A34C: lw          $a2, 0x1C($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X1C);
    // 0x8000A350: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000A354: beq         $a2, $zero, L_8000A3A4
    if (ctx->r6 == 0) {
        // 0x8000A358: nop
    
            goto L_8000A3A4;
    }
    // 0x8000A358: nop

    // 0x8000A35C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8000A360: lw          $t9, -0x63BC($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X63BC);
    // 0x8000A364: nop

    // 0x8000A368: addu        $t0, $t9, $a1
    ctx->r8 = ADD32(ctx->r25, ctx->r5);
    // 0x8000A36C: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000A370: nop

    // 0x8000A374: lhu         $a0, 0xC($t1)
    ctx->r4 = MEM_HU(ctx->r9, 0XC);
    // 0x8000A378: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8000A37C: ori         $t2, $a0, 0x5000
    ctx->r10 = ctx->r4 | 0X5000;
    // 0x8000A380: sll         $t3, $t2, 16
    ctx->r11 = S32(ctx->r10 << 16);
    // 0x8000A384: jal         0x800245B4
    // 0x8000A388: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    func_800245B4(rdram, ctx);
        goto after_1;
    // 0x8000A388: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_1:
    // 0x8000A38C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000A390: lw          $t5, -0x63BC($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X63BC);
    // 0x8000A394: lw          $a1, 0x1C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X1C);
    // 0x8000A398: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x8000A39C: addiu       $a3, $a3, -0x3920
    ctx->r7 = ADD32(ctx->r7, -0X3920);
    // 0x8000A3A0: addu        $v1, $t5, $a1
    ctx->r3 = ADD32(ctx->r13, ctx->r5);
L_8000A3A4:
    // 0x8000A3A4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000A3A8: addiu       $a0, $a0, -0x63B4
    ctx->r4 = ADD32(ctx->r4, -0X63B4);
    // 0x8000A3AC: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8000A3B0: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000A3B4: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8000A3B8: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    // 0x8000A3BC: lw          $t9, -0x63B0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X63B0);
    // 0x8000A3C0: andi        $t0, $t7, 0xFF
    ctx->r8 = ctx->r15 & 0XFF;
    // 0x8000A3C4: lw          $t8, 0x0($v1)
    ctx->r24 = MEM_W(ctx->r3, 0X0);
    // 0x8000A3C8: sll         $t1, $t0, 2
    ctx->r9 = S32(ctx->r8 << 2);
    // 0x8000A3CC: addu        $t2, $t9, $t1
    ctx->r10 = ADD32(ctx->r25, ctx->r9);
    // 0x8000A3D0: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x8000A3D4: lhu         $t3, 0x0($a3)
    ctx->r11 = MEM_HU(ctx->r7, 0X0);
    // 0x8000A3D8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000A3DC: lw          $v0, -0x63BC($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X63BC);
    // 0x8000A3E0: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8000A3E4: addu        $t5, $v0, $t4
    ctx->r13 = ADD32(ctx->r2, ctx->r12);
    // 0x8000A3E8: lw          $t6, -0x4($t5)
    ctx->r14 = MEM_W(ctx->r13, -0X4);
    // 0x8000A3EC: addu        $t7, $v0, $a1
    ctx->r15 = ADD32(ctx->r2, ctx->r5);
    // 0x8000A3F0: sw          $t6, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r14;
    // 0x8000A3F4: lhu         $t0, 0x0($a3)
    ctx->r8 = MEM_HU(ctx->r7, 0X0);
    // 0x8000A3F8: nop

    // 0x8000A3FC: addiu       $t9, $t0, -0x1
    ctx->r25 = ADD32(ctx->r8, -0X1);
    // 0x8000A400: sh          $t9, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r25;
L_8000A404:
    // 0x8000A404: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000A408: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8000A40C: jr          $ra
    // 0x8000A410: nop

    return;
    // 0x8000A410: nop

;}
RECOMP_FUNC void alFxReverbSet(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006492C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80064930: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x80064934: jr          $ra
    // 0x80064938: sb          $a0, -0x3150($at)
    MEM_B(-0X3150, ctx->r1) = ctx->r4;
    return;
    // 0x80064938: sb          $a0, -0x3150($at)
    MEM_B(-0X3150, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void menu_camera_centre(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009BD5C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8009BD60: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009BD64: jal         0x8006652C
    // 0x8009BD68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    cam_set_layout(rdram, ctx);
        goto after_0;
    // 0x8009BD68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8009BD6C: jal         0x800665E8
    // 0x8009BD70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_active_camera(rdram, ctx);
        goto after_1;
    // 0x8009BD70: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8009BD74: jal         0x80069D20
    // 0x8009BD78: nop

    cam_get_active_camera(rdram, ctx);
        goto after_2;
    // 0x8009BD78: nop

    after_2:
    // 0x8009BD7C: lh          $t6, 0x0($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X0);
    // 0x8009BD80: lui         $at, 0xC200
    ctx->r1 = S32(0XC200 << 16);
    // 0x8009BD84: sh          $t6, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r14;
    // 0x8009BD88: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x8009BD8C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009BD90: sh          $t7, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r15;
    // 0x8009BD94: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x8009BD98: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x8009BD9C: sh          $t8, 0x26($sp)
    MEM_H(0X26, ctx->r29) = ctx->r24;
    // 0x8009BDA0: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8009BDA4: addiu       $t9, $zero, -0x8000
    ctx->r25 = ADD32(0, -0X8000);
    // 0x8009BDA8: swc1        $f4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f4.u32l;
    // 0x8009BDAC: lwc1        $f6, 0x10($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8009BDB0: lui         $a2, 0xBF80
    ctx->r6 = S32(0XBF80 << 16);
    // 0x8009BDB4: swc1        $f6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f6.u32l;
    // 0x8009BDB8: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8009BDBC: mov.s       $f14, $f12
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 12);
    ctx->f14.fl = ctx->f12.fl;
    // 0x8009BDC0: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    // 0x8009BDC4: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x8009BDC8: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
    // 0x8009BDCC: sh          $t9, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r25;
    // 0x8009BDD0: swc1        $f0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f0.u32l;
    // 0x8009BDD4: swc1        $f0, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f0.u32l;
    // 0x8009BDD8: swc1        $f0, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f0.u32l;
    // 0x8009BDDC: jal         0x8001D5E0
    // 0x8009BDE0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    update_envmap_position(rdram, ctx);
        goto after_3;
    // 0x8009BDE0: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    after_3:
    // 0x8009BDE4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8009BDE8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009BDEC: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x8009BDF0: jal         0x80066CDC
    // 0x8009BDF4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    viewport_main(rdram, ctx);
        goto after_4;
    // 0x8009BDF4: addiu       $a0, $a0, 0x63A0
    ctx->r4 = ADD32(ctx->r4, 0X63A0);
    after_4:
    // 0x8009BDF8: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8009BDFC: lh          $t0, 0x2A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X2A);
    // 0x8009BE00: nop

    // 0x8009BE04: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x8009BE08: lh          $t1, 0x28($sp)
    ctx->r9 = MEM_H(ctx->r29, 0X28);
    // 0x8009BE0C: nop

    // 0x8009BE10: sh          $t1, 0x2($v1)
    MEM_H(0X2, ctx->r3) = ctx->r9;
    // 0x8009BE14: lh          $t2, 0x26($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X26);
    // 0x8009BE18: nop

    // 0x8009BE1C: sh          $t2, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r10;
    // 0x8009BE20: lwc1        $f10, 0x20($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X20);
    // 0x8009BE24: nop

    // 0x8009BE28: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x8009BE2C: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8009BE30: nop

    // 0x8009BE34: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x8009BE38: lwc1        $f18, 0x18($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X18);
    // 0x8009BE3C: nop

    // 0x8009BE40: swc1        $f18, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f18.u32l;
    // 0x8009BE44: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009BE48: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x8009BE4C: jr          $ra
    // 0x8009BE50: nop

    return;
    // 0x8009BE50: nop

;}
RECOMP_FUNC void cheatmenu_checksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008AD44: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8008AD48: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8008AD4C: lw          $t6, 0x1E18($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1E18);
    // 0x8008AD50: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8008AD54: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008AD58: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008AD5C: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008AD60: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008AD64: bne         $t6, $zero, L_8008AE54
    if (ctx->r14 != 0) {
        // 0x8008AD68: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8008AE54;
    }
    // 0x8008AD68: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008AD6C: lui         $s0, 0xAD
    ctx->r16 = S32(0XAD << 16);
    // 0x8008AD70: addiu       $s0, $s0, -0x69D0
    ctx->r16 = ADD32(ctx->r16, -0X69D0);
    // 0x8008AD74: addiu       $s0, $s0, -0x1000
    ctx->r16 = ADD32(ctx->r16, -0X1000);
    // 0x8008AD78: addiu       $s3, $zero, 0x1000
    ctx->r19 = ADD32(0, 0X1000);
    // 0x8008AD7C: or          $s2, $s0, $zero
    ctx->r18 = ctx->r16 | 0;
    // 0x8008AD80: addiu       $a0, $zero, 0x5000
    ctx->r4 = ADD32(0, 0X5000);
    // 0x8008AD84: jal         0x80070C9C
    // 0x8008AD88: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x8008AD88: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    after_0:
    // 0x8008AD8C: beq         $s0, $zero, L_8008AE40
    if (ctx->r16 == 0) {
        // 0x8008AD90: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8008AE40;
    }
    // 0x8008AD90: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
L_8008AD94:
    // 0x8008AD94: slti        $at, $s2, 0x5001
    ctx->r1 = SIGNED(ctx->r18) < 0X5001 ? 1 : 0;
    // 0x8008AD98: or          $s1, $s2, $zero
    ctx->r17 = ctx->r18 | 0;
    // 0x8008AD9C: bne         $at, $zero, L_8008ADA8
    if (ctx->r1 != 0) {
        // 0x8008ADA0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8008ADA8;
    }
    // 0x8008ADA0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8008ADA4: addiu       $s1, $zero, 0x5000
    ctx->r17 = ADD32(0, 0X5000);
L_8008ADA8:
    // 0x8008ADA8: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x8008ADAC: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    // 0x8008ADB0: jal         0x80076F78
    // 0x8008ADB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    dmacopy(rdram, ctx);
        goto after_1;
    // 0x8008ADB4: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    after_1:
    // 0x8008ADB8: blez        $s1, L_8008AE38
    if (SIGNED(ctx->r17) <= 0) {
        // 0x8008ADBC: subu        $s2, $s2, $s1
        ctx->r18 = SUB32(ctx->r18, ctx->r17);
            goto L_8008AE38;
    }
    // 0x8008ADBC: subu        $s2, $s2, $s1
    ctx->r18 = SUB32(ctx->r18, ctx->r17);
    // 0x8008ADC0: andi        $a0, $s1, 0x3
    ctx->r4 = ctx->r17 & 0X3;
    // 0x8008ADC4: beq         $a0, $zero, L_8008ADF8
    if (ctx->r4 == 0) {
        // 0x8008ADC8: or          $v1, $a0, $zero
        ctx->r3 = ctx->r4 | 0;
            goto L_8008ADF8;
    }
    // 0x8008ADC8: or          $v1, $a0, $zero
    ctx->r3 = ctx->r4 | 0;
    // 0x8008ADCC: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008ADD0: lw          $a1, 0x1E14($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1E14);
    // 0x8008ADD4: addu        $v0, $s4, $s0
    ctx->r2 = ADD32(ctx->r20, ctx->r16);
L_8008ADD8:
    // 0x8008ADD8: lbu         $t7, 0x0($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X0);
    // 0x8008ADDC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8008ADE0: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8008ADE4: bne         $v1, $s0, L_8008ADD8
    if (ctx->r3 != ctx->r16) {
        // 0x8008ADE8: addu        $a1, $a1, $t7
        ctx->r5 = ADD32(ctx->r5, ctx->r15);
            goto L_8008ADD8;
    }
    // 0x8008ADE8: addu        $a1, $a1, $t7
    ctx->r5 = ADD32(ctx->r5, ctx->r15);
    // 0x8008ADEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008ADF0: beq         $s0, $s1, L_8008AE38
    if (ctx->r16 == ctx->r17) {
        // 0x8008ADF4: sw          $a1, 0x1E14($at)
        MEM_W(0X1E14, ctx->r1) = ctx->r5;
            goto L_8008AE38;
    }
    // 0x8008ADF4: sw          $a1, 0x1E14($at)
    MEM_W(0X1E14, ctx->r1) = ctx->r5;
L_8008ADF8:
    // 0x8008ADF8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008ADFC: lw          $a1, 0x1E14($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1E14);
    // 0x8008AE00: addu        $v0, $s4, $s0
    ctx->r2 = ADD32(ctx->r20, ctx->r16);
L_8008AE04:
    // 0x8008AE04: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x8008AE08: lbu         $t9, 0x1($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X1);
    // 0x8008AE0C: lbu         $t0, 0x2($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X2);
    // 0x8008AE10: addu        $a1, $a1, $t8
    ctx->r5 = ADD32(ctx->r5, ctx->r24);
    // 0x8008AE14: lbu         $t1, 0x3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X3);
    // 0x8008AE18: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8008AE1C: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008AE20: addu        $a1, $a1, $t0
    ctx->r5 = ADD32(ctx->r5, ctx->r8);
    // 0x8008AE24: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8008AE28: bne         $s0, $s1, L_8008AE04
    if (ctx->r16 != ctx->r17) {
        // 0x8008AE2C: addu        $a1, $a1, $t1
        ctx->r5 = ADD32(ctx->r5, ctx->r9);
            goto L_8008AE04;
    }
    // 0x8008AE2C: addu        $a1, $a1, $t1
    ctx->r5 = ADD32(ctx->r5, ctx->r9);
    // 0x8008AE30: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AE34: sw          $a1, 0x1E14($at)
    MEM_W(0X1E14, ctx->r1) = ctx->r5;
L_8008AE38:
    // 0x8008AE38: bne         $s2, $zero, L_8008AD94
    if (ctx->r18 != 0) {
        // 0x8008AE3C: addu        $s3, $s3, $s1
        ctx->r19 = ADD32(ctx->r19, ctx->r17);
            goto L_8008AD94;
    }
    // 0x8008AE3C: addu        $s3, $s3, $s1
    ctx->r19 = ADD32(ctx->r19, ctx->r17);
L_8008AE40:
    // 0x8008AE40: jal         0x80071140
    // 0x8008AE44: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    mempool_free(rdram, ctx);
        goto after_2;
    // 0x8008AE44: or          $a0, $s4, $zero
    ctx->r4 = ctx->r20 | 0;
    after_2:
    // 0x8008AE48: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8008AE4C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008AE50: sw          $t2, 0x1E18($at)
    MEM_W(0X1E18, ctx->r1) = ctx->r10;
L_8008AE54:
    // 0x8008AE54: lui         $s0, 0xAD
    ctx->r16 = S32(0XAD << 16);
    // 0x8008AE58: addiu       $s0, $s0, -0x69D0
    ctx->r16 = ADD32(ctx->r16, -0X69D0);
    // 0x8008AE5C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8008AE60: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8008AE64: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008AE68: jal         0x800B62B4
    // 0x8008AE6C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    set_render_printf_background_colour(rdram, ctx);
        goto after_3;
    // 0x8008AE6C: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
    after_3:
    // 0x8008AE70: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    // 0x8008AE74: jal         0x800B635C
    // 0x8008AE78: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    set_render_printf_position(rdram, ctx);
        goto after_4;
    // 0x8008AE78: addiu       $a1, $zero, 0x88
    ctx->r5 = ADD32(0, 0X88);
    after_4:
    // 0x8008AE7C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8008AE80: lw          $a1, 0x1E14($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X1E14);
    // 0x8008AE84: lui         $a0, 0x800F
    ctx->r4 = S32(0X800F << 16);
    // 0x8008AE88: addiu       $a0, $a0, -0x7DE8
    ctx->r4 = ADD32(ctx->r4, -0X7DE8);
    // 0x8008AE8C: jal         0x800B5EDC
    // 0x8008AE90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    render_printf(rdram, ctx);
        goto after_5;
    // 0x8008AE90: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_5:
    // 0x8008AE94: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8008AE98: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008AE9C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008AEA0: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008AEA4: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008AEA8: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008AEAC: jr          $ra
    // 0x8008AEB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8008AEB0: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void lensflare_on(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC860: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800AC864: lw          $t6, 0x2A80($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X2A80);
    // 0x800AC868: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC86C: beq         $t6, $zero, L_800AC878
    if (ctx->r14 == 0) {
        // 0x800AC870: nop
    
            goto L_800AC878;
    }
    // 0x800AC870: nop

    // 0x800AC874: sw          $zero, 0x2A84($at)
    MEM_W(0X2A84, ctx->r1) = 0;
L_800AC878:
    // 0x800AC878: jr          $ra
    // 0x800AC87C: nop

    return;
    // 0x800AC87C: nop

;}
RECOMP_FUNC void render_misc_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011960: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80011964: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80011968: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8001196C: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80011970: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80011974: sw          $a3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r7;
    // 0x80011978: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8001197C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80011980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80011984: lw          $a3, 0x48($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X48);
    // 0x80011988: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001198C: addiu       $a0, $a0, -0x5174
    ctx->r4 = ADD32(ctx->r4, -0X5174);
    // 0x80011990: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    // 0x80011994: addiu       $a1, $a1, -0x5170
    ctx->r5 = ADD32(ctx->r5, -0X5170);
    // 0x80011998: jal         0x80069484
    // 0x8001199C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    mtx_cam_push(rdram, ctx);
        goto after_0;
    // 0x8001199C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x800119A0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800119A4: addiu       $a0, $a0, -0x5174
    ctx->r4 = ADD32(ctx->r4, -0X5174);
    // 0x800119A8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800119AC: lui         $t7, 0xFA00
    ctx->r15 = S32(0XFA00 << 16);
    // 0x800119B0: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x800119B4: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x800119B8: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800119BC: sw          $t8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r24;
    // 0x800119C0: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800119C4: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800119C8: lui         $t2, 0xFB00
    ctx->r10 = S32(0XFB00 << 16);
    // 0x800119CC: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800119D0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800119D4: addiu       $t3, $zero, -0x100
    ctx->r11 = ADD32(0, -0X100);
    // 0x800119D8: sw          $t3, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r11;
    // 0x800119DC: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800119E0: lw          $t4, 0x3C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X3C);
    // 0x800119E4: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800119E8: beq         $t4, $zero, L_800119F8
    if (ctx->r12 == 0) {
        // 0x800119EC: lw          $a1, 0x3C($sp)
        ctx->r5 = MEM_W(ctx->r29, 0X3C);
            goto L_800119F8;
    }
    // 0x800119EC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800119F0: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x800119F4: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
L_800119F8:
    // 0x800119F8: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x800119FC: lw          $a3, 0x44($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X44);
    // 0x80011A00: jal         0x8007B4E8
    // 0x80011A04: nop

    material_set(rdram, ctx);
        goto after_1;
    // 0x80011A04: nop

    after_1:
    // 0x80011A08: lw          $t1, 0x30($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X30);
    // 0x80011A0C: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80011A10: lui         $t0, 0x8000
    ctx->r8 = S32(0X8000 << 16);
    // 0x80011A14: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80011A18: addiu       $t8, $t1, -0x1
    ctx->r24 = ADD32(ctx->r9, -0X1);
    // 0x80011A1C: addu        $a1, $t7, $t0
    ctx->r5 = ADD32(ctx->r15, ctx->r8);
    // 0x80011A20: addiu       $a0, $a0, -0x5174
    ctx->r4 = ADD32(ctx->r4, -0X5174);
    // 0x80011A24: andi        $t2, $a1, 0x6
    ctx->r10 = ctx->r5 & 0X6;
    // 0x80011A28: sll         $t9, $t8, 3
    ctx->r25 = S32(ctx->r24 << 3);
    // 0x80011A2C: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80011A30: or          $t3, $t9, $t2
    ctx->r11 = ctx->r25 | ctx->r10;
    // 0x80011A34: sll         $t7, $t1, 3
    ctx->r15 = S32(ctx->r9 << 3);
    // 0x80011A38: addu        $t8, $t7, $t1
    ctx->r24 = ADD32(ctx->r15, ctx->r9);
    // 0x80011A3C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x80011A40: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x80011A44: addiu       $t6, $v0, 0x8
    ctx->r14 = ADD32(ctx->r2, 0X8);
    // 0x80011A48: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80011A4C: sll         $t5, $t4, 16
    ctx->r13 = S32(ctx->r12 << 16);
    // 0x80011A50: addiu       $t2, $t9, 0x8
    ctx->r10 = ADD32(ctx->r25, 0X8);
    // 0x80011A54: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x80011A58: lw          $a3, 0x38($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X38);
    // 0x80011A5C: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x80011A60: andi        $t3, $t2, 0xFFFF
    ctx->r11 = ctx->r10 & 0XFFFF;
    // 0x80011A64: or          $t4, $t6, $t3
    ctx->r12 = ctx->r14 | ctx->r11;
    // 0x80011A68: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x80011A6C: sw          $a1, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r5;
    // 0x80011A70: lw          $t9, 0x24($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X24);
    // 0x80011A74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x80011A78: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x80011A7C: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x80011A80: or          $t2, $t8, $t9
    ctx->r10 = ctx->r24 | ctx->r25;
    // 0x80011A84: addiu       $t5, $v0, 0x8
    ctx->r13 = ADD32(ctx->r2, 0X8);
    // 0x80011A88: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x80011A8C: andi        $t6, $t2, 0xFF
    ctx->r14 = ctx->r10 & 0XFF;
    // 0x80011A90: sll         $t3, $t6, 16
    ctx->r11 = S32(ctx->r14 << 16);
    // 0x80011A94: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x80011A98: sll         $t5, $a3, 4
    ctx->r13 = S32(ctx->r7 << 4);
    // 0x80011A9C: andi        $t7, $t5, 0xFFFF
    ctx->r15 = ctx->r13 & 0XFFFF;
    // 0x80011AA0: or          $t4, $t3, $at
    ctx->r12 = ctx->r11 | ctx->r1;
    // 0x80011AA4: or          $t8, $t4, $t7
    ctx->r24 = ctx->r12 | ctx->r15;
    // 0x80011AA8: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x80011AAC: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x80011AB0: nop

    // 0x80011AB4: addu        $t2, $t9, $t0
    ctx->r10 = ADD32(ctx->r25, ctx->r8);
    // 0x80011AB8: jal         0x80069A40
    // 0x80011ABC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    mtx_pop(rdram, ctx);
        goto after_2;
    // 0x80011ABC: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    after_2:
    // 0x80011AC0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80011AC4: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80011AC8: jr          $ra
    // 0x80011ACC: nop

    return;
    // 0x80011ACC: nop

;}
RECOMP_FUNC void is_in_adventure_two(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009EC70: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009EC74: lw          $v0, -0xB6C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB6C);
    // 0x8009EC78: jr          $ra
    // 0x8009EC7C: nop

    return;
    // 0x8009EC7C: nop

;}
RECOMP_FUNC void fb_swap(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007AB9C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007ABA0: addiu       $a1, $a1, 0x62C8
    ctx->r5 = ADD32(ctx->r5, 0X62C8);
    // 0x8007ABA4: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8007ABA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007ABAC: addiu       $a0, $a0, 0x62C0
    ctx->r4 = ADD32(ctx->r4, 0X62C0);
    // 0x8007ABB0: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8007ABB4: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x8007ABB8: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8007ABBC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ABC0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8007ABC4: lw          $v1, -0x1890($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X1890);
    // 0x8007ABC8: sw          $t8, 0x62D8($at)
    MEM_W(0X62D8, ctx->r1) = ctx->r24;
    // 0x8007ABCC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ABD0: xori        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 ^ 0X1;
    // 0x8007ABD4: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x8007ABD8: sw          $v1, 0x62E0($at)
    MEM_W(0X62E0, ctx->r1) = ctx->r3;
    // 0x8007ABDC: addu        $t2, $a0, $t1
    ctx->r10 = ADD32(ctx->r4, ctx->r9);
    // 0x8007ABE0: lw          $t3, 0x0($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X0);
    // 0x8007ABE4: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8007ABE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ABEC: sw          $t3, 0x62D4($at)
    MEM_W(0X62D4, ctx->r1) = ctx->r11;
    // 0x8007ABF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007ABF4: jr          $ra
    // 0x8007ABF8: sw          $v1, 0x62DC($at)
    MEM_W(0X62DC, ctx->r1) = ctx->r3;
    return;
    // 0x8007ABF8: sw          $v1, 0x62DC($at)
    MEM_W(0X62DC, ctx->r1) = ctx->r3;
;}
