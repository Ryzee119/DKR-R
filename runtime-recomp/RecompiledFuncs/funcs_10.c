#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void cam_rotate(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80069CB4: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80069CB8: lw          $t6, 0xCE4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XCE4);
    // 0x80069CBC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80069CC0: sll         $t7, $t6, 4
    ctx->r15 = S32(ctx->r14 << 4);
    // 0x80069CC4: addu        $t7, $t7, $t6
    ctx->r15 = ADD32(ctx->r15, ctx->r14);
    // 0x80069CC8: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80069CCC: addiu       $t8, $t8, 0xAC0
    ctx->r24 = ADD32(ctx->r24, 0XAC0);
    // 0x80069CD0: addu        $v0, $t7, $t8
    ctx->r2 = ADD32(ctx->r15, ctx->r24);
    // 0x80069CD4: lh          $t9, 0x0($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X0);
    // 0x80069CD8: lh          $t1, 0x2($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X2);
    // 0x80069CDC: lh          $t3, 0x4($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X4);
    // 0x80069CE0: addu        $t0, $t9, $a0
    ctx->r8 = ADD32(ctx->r25, ctx->r4);
    // 0x80069CE4: addu        $t2, $t1, $a1
    ctx->r10 = ADD32(ctx->r9, ctx->r5);
    // 0x80069CE8: addu        $t4, $t3, $a2
    ctx->r12 = ADD32(ctx->r11, ctx->r6);
    // 0x80069CEC: sh          $t0, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r8;
    // 0x80069CF0: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x80069CF4: jr          $ra
    // 0x80069CF8: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
    return;
    // 0x80069CF8: sh          $t4, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r12;
;}
RECOMP_FUNC void load_game_text_table(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3048: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C304C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C3050: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x800C3054: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3058: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800C305C: sh          $t6, -0x5874($at)
    MEM_H(-0X5874, ctx->r1) = ctx->r14;
    // 0x800C3060: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x800C3064: jal         0x80070C9C
    // 0x800C3068: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800C3068: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    after_0:
    // 0x800C306C: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C3070: addiu       $v1, $v1, -0x5868
    ctx->r3 = ADD32(ctx->r3, -0X5868);
    // 0x800C3074: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3078: addiu       $t8, $v0, 0x80
    ctx->r24 = ADD32(ctx->r2, 0X80);
    // 0x800C307C: addiu       $a0, $a0, -0x5880
    ctx->r4 = ADD32(ctx->r4, -0X5880);
    // 0x800C3080: addiu       $t0, $t8, 0x3C0
    ctx->r8 = ADD32(ctx->r24, 0X3C0);
    // 0x800C3084: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    // 0x800C3088: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C308C: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800C3090: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3094: jal         0x800C29F0
    // 0x800C3098: sw          $zero, -0x585C($at)
    MEM_W(-0X585C, ctx->r1) = 0;
    init_dialogue_text(rdram, ctx);
        goto after_1;
    // 0x800C3098: sw          $zero, -0x585C($at)
    MEM_W(-0X585C, ctx->r1) = 0;
    after_1:
    // 0x800C309C: jal         0x80076F30
    // 0x800C30A0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    asset_table_size(rdram, ctx);
        goto after_2;
    // 0x800C30A0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_2:
    // 0x800C30A4: sra         $t1, $v0, 2
    ctx->r9 = S32(SIGNED(ctx->r2) >> 2);
    // 0x800C30A8: addiu       $t2, $t1, -0x2
    ctx->r10 = ADD32(ctx->r9, -0X2);
    // 0x800C30AC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C30B0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C30B4: sh          $t2, -0x5870($at)
    MEM_H(-0X5870, ctx->r1) = ctx->r10;
    // 0x800C30B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C30BC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800C30C0: sb          $t3, 0x3670($at)
    MEM_B(0X3670, ctx->r1) = ctx->r11;
    // 0x800C30C4: jr          $ra
    // 0x800C30C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    return;
    // 0x800C30C8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
;}
RECOMP_FUNC void update_envmap_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001D5E0: mul.s       $f4, $f12, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x8001D5E4: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8001D5E8: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x8001D5EC: mtc1        $a2, $f22
    ctx->f22.u32l = ctx->r6;
    // 0x8001D5F0: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8001D5F4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8001D5F8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x8001D5FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001D600: mul.s       $f10, $f22, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x8001D604: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8001D608: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x8001D60C: swc1        $f14, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f14.u32l;
    // 0x8001D610: mov.s       $f20, $f12
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 12);
    ctx->f20.fl = ctx->f12.fl;
    // 0x8001D614: jal         0x800C9AD0
    // 0x8001D618: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x8001D618: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x8001D61C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8001D620: lwc1        $f14, 0x2C($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8001D624: c.eq.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl == ctx->f16.fl;
    // 0x8001D628: lui         $at, 0xC600
    ctx->r1 = S32(0XC600 << 16);
    // 0x8001D62C: bc1t        L_8001D658
    if (c1cs) {
        // 0x8001D630: nop
    
            goto L_8001D658;
    }
    // 0x8001D630: nop

    // 0x8001D634: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8001D638: nop

    // 0x8001D63C: div.s       $f2, $f18, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x8001D640: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x8001D644: nop

    // 0x8001D648: mul.s       $f14, $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x8001D64C: nop

    // 0x8001D650: mul.s       $f22, $f22, $f2
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x8001D654: nop

L_8001D658:
    // 0x8001D658: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001D65C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001D660: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001D664: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D668: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D66C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001D670: cvt.w.s     $f4, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    ctx->f4.u32l = CVT_W_S(ctx->f20.fl);
    // 0x8001D674: addiu       $v0, $v0, -0x5018
    ctx->r2 = ADD32(ctx->r2, -0X5018);
    // 0x8001D678: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001D67C: mfc1        $t7, $f4
    ctx->r15 = (int32_t)ctx->f4.u32l;
    // 0x8001D680: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8001D684: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001D688: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8001D68C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001D690: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D694: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D698: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8001D69C: cvt.w.s     $f6, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    ctx->f6.u32l = CVT_W_S(ctx->f14.fl);
    // 0x8001D6A0: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8001D6A4: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001D6A8: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x8001D6AC: nop

    // 0x8001D6B0: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x8001D6B4: sh          $t9, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r25;
    // 0x8001D6B8: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x8001D6BC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001D6C0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001D6C4: nop

    // 0x8001D6C8: cvt.w.s     $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    ctx->f8.u32l = CVT_W_S(ctx->f22.fl);
    // 0x8001D6CC: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8001D6D0: mfc1        $t1, $f8
    ctx->r9 = (int32_t)ctx->f8.u32l;
    // 0x8001D6D4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x8001D6D8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8001D6DC: jr          $ra
    // 0x8001D6E0: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
    return;
    // 0x8001D6E0: sh          $t1, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r9;
;}
RECOMP_FUNC void func_8002AC00(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002AC00: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8002AC04: lw          $v0, -0x36E8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X36E8);
    // 0x8002AC08: nop

    // 0x8002AC0C: lh          $v1, 0x1A($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X1A);
    // 0x8002AC10: nop

    // 0x8002AC14: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002AC18: beq         $at, $zero, L_8002AC98
    if (ctx->r1 == 0) {
        // 0x8002AC1C: slt         $at, $a1, $v1
        ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8002AC98;
    }
    // 0x8002AC1C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002AC20: beq         $at, $zero, L_8002AC98
    if (ctx->r1 == 0) {
        // 0x8002AC24: sll         $t7, $a0, 4
        ctx->r15 = S32(ctx->r4 << 4);
            goto L_8002AC98;
    }
    // 0x8002AC24: sll         $t7, $a0, 4
    ctx->r15 = S32(ctx->r4 << 4);
    // 0x8002AC28: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8002AC2C: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8002AC30: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8002AC34: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8002AC38: lh          $v1, 0x28($t8)
    ctx->r3 = MEM_H(ctx->r24, 0X28);
    // 0x8002AC3C: beq         $a2, $zero, L_8002AC70
    if (ctx->r6 == 0) {
        // 0x8002AC40: sra         $t0, $a1, 3
        ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
            goto L_8002AC70;
    }
    // 0x8002AC40: sra         $t0, $a1, 3
    ctx->r8 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8002AC44: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x8002AC48: sra         $t1, $a1, 3
    ctx->r9 = S32(SIGNED(ctx->r5) >> 3);
    // 0x8002AC4C: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x8002AC50: addu        $a0, $t0, $t1
    ctx->r4 = ADD32(ctx->r8, ctx->r9);
    // 0x8002AC54: lbu         $t2, 0x0($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X0);
    // 0x8002AC58: andi        $t3, $a1, 0x7
    ctx->r11 = ctx->r5 & 0X7;
    // 0x8002AC5C: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8002AC60: sllv        $t6, $t4, $t3
    ctx->r14 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8002AC64: or          $t7, $t2, $t6
    ctx->r15 = ctx->r10 | ctx->r14;
    // 0x8002AC68: jr          $ra
    // 0x8002AC6C: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
    return;
    // 0x8002AC6C: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_8002AC70:
    // 0x8002AC70: lw          $t8, 0x10($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X10);
    // 0x8002AC74: andi        $t4, $a1, 0x7
    ctx->r12 = ctx->r5 & 0X7;
    // 0x8002AC78: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x8002AC7C: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x8002AC80: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x8002AC84: lbu         $t1, 0x0($a0)
    ctx->r9 = MEM_BU(ctx->r4, 0X0);
    // 0x8002AC88: sllv        $t2, $t3, $t4
    ctx->r10 = S32(ctx->r11 << (ctx->r12 & 31));
    // 0x8002AC8C: nor         $t6, $t2, $zero
    ctx->r14 = ~(ctx->r10 | 0);
    // 0x8002AC90: and         $t7, $t1, $t6
    ctx->r15 = ctx->r9 & ctx->r14;
    // 0x8002AC94: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_8002AC98:
    // 0x8002AC98: jr          $ra
    // 0x8002AC9C: nop

    return;
    // 0x8002AC9C: nop

;}
RECOMP_FUNC void handle_racer_items(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80055EC0: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x80055EC4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80055EC8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80055ECC: sw          $a2, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->r6;
    // 0x80055ED0: sh          $zero, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = 0;
    // 0x80055ED4: lw          $v0, 0x144($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X144);
    // 0x80055ED8: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x80055EDC: beq         $v0, $zero, L_800560AC
    if (ctx->r2 == 0) {
        // 0x80055EE0: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_800560AC;
    }
    // 0x80055EE0: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80055EE4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80055EE8: addiu       $a1, $a1, -0x2AD4
    ctx->r5 = ADD32(ctx->r5, -0X2AD4);
    // 0x80055EEC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x80055EF0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80055EF4: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x80055EF8: bne         $t7, $zero, L_80055F20
    if (ctx->r15 != 0) {
        // 0x80055EFC: nop
    
            goto L_80055F20;
    }
    // 0x80055EFC: nop

    // 0x80055F00: lb          $t8, 0x1D8($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D8);
    // 0x80055F04: nop

    // 0x80055F08: bne         $t8, $zero, L_80055F20
    if (ctx->r24 != 0) {
        // 0x80055F0C: nop
    
            goto L_80055F20;
    }
    // 0x80055F0C: nop

    // 0x80055F10: lb          $t9, 0x187($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X187);
    // 0x80055F14: nop

    // 0x80055F18: beq         $t9, $zero, L_80056924
    if (ctx->r25 == 0) {
        // 0x80055F1C: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056924;
    }
    // 0x80055F1C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80055F20:
    // 0x80055F20: lb          $t4, 0x3A($a3)
    ctx->r12 = MEM_B(ctx->r7, 0X3A);
    // 0x80055F24: lw          $t3, 0x68($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X68);
    // 0x80055F28: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80055F2C: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x80055F30: mtc1        $zero, $f12
    ctx->f12.u32l = 0;
    // 0x80055F34: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x80055F38: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
    // 0x80055F3C: beq         $v0, $zero, L_80055FC8
    if (ctx->r2 == 0) {
        // 0x80055F40: nop
    
            goto L_80055FC8;
    }
    // 0x80055F40: nop

    // 0x80055F44: lw          $t7, 0x40($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X40);
    // 0x80055F48: lw          $a1, 0x0($v0)
    ctx->r5 = MEM_W(ctx->r2, 0X0);
    // 0x80055F4C: lb          $a0, 0x58($t7)
    ctx->r4 = MEM_B(ctx->r15, 0X58);
    // 0x80055F50: nop

    // 0x80055F54: bltz        $a0, L_80055FC8
    if (SIGNED(ctx->r4) < 0) {
        // 0x80055F58: nop
    
            goto L_80055FC8;
    }
    // 0x80055F58: nop

    // 0x80055F5C: lh          $t8, 0x18($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X18);
    // 0x80055F60: nop

    // 0x80055F64: slt         $at, $a0, $t8
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80055F68: beq         $at, $zero, L_80055FC8
    if (ctx->r1 == 0) {
        // 0x80055F6C: nop
    
            goto L_80055FC8;
    }
    // 0x80055F6C: nop

    // 0x80055F70: lw          $a2, 0x44($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X44);
    // 0x80055F74: nop

    // 0x80055F78: beq         $a2, $zero, L_80055FC8
    if (ctx->r6 == 0) {
        // 0x80055F7C: nop
    
            goto L_80055FC8;
    }
    // 0x80055F7C: nop

    // 0x80055F80: lw          $t9, 0x14($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X14);
    // 0x80055F84: sll         $t4, $a0, 1
    ctx->r12 = S32(ctx->r4 << 1);
    // 0x80055F88: addu        $t3, $t9, $t4
    ctx->r11 = ADD32(ctx->r25, ctx->r12);
    // 0x80055F8C: lh          $t5, 0x0($t3)
    ctx->r13 = MEM_H(ctx->r11, 0X0);
    // 0x80055F90: lwc1        $f0, 0x8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80055F94: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x80055F98: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80055F9C: sll         $t6, $t6, 1
    ctx->r14 = S32(ctx->r14 << 1);
    // 0x80055FA0: addu        $v0, $a2, $t6
    ctx->r2 = ADD32(ctx->r6, ctx->r14);
    // 0x80055FA4: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80055FA8: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80055FAC: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80055FB0: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80055FB4: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80055FB8: mul.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x80055FBC: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80055FC0: mul.s       $f12, $f12, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80055FC4: nop

L_80055FC8:
    // 0x80055FC8: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80055FCC: lwc1        $f4, 0x44($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X44);
    // 0x80055FD0: mul.s       $f16, $f10, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x80055FD4: lwc1        $f8, 0xC($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0XC);
    // 0x80055FD8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80055FDC: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x80055FE0: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x80055FE4: add.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x80055FE8: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80055FEC: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80055FF0: add.s       $f10, $f18, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80055FF4: swc1        $f10, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->f10.u32l;
    // 0x80055FF8: lwc1        $f16, 0x3C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80055FFC: lwc1        $f6, 0x48($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X48);
    // 0x80056000: mul.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x80056004: lwc1        $f8, 0x10($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80056008: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x8005600C: add.s       $f18, $f8, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80056010: add.s       $f16, $f18, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f18.fl + ctx->f10.fl;
    // 0x80056014: swc1        $f16, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f16.u32l;
    // 0x80056018: lwc1        $f4, 0x40($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X40);
    // 0x8005601C: lwc1        $f10, 0x4C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X4C);
    // 0x80056020: mul.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80056024: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x80056028: mul.s       $f16, $f10, $f2
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x8005602C: add.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f8.fl + ctx->f6.fl;
    // 0x80056030: add.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f16.fl;
    // 0x80056034: swc1        $f4, 0x14($v1)
    MEM_W(0X14, ctx->r3) = ctx->f4.u32l;
    // 0x80056038: lh          $t9, 0x2E($a3)
    ctx->r25 = MEM_H(ctx->r7, 0X2E);
    // 0x8005603C: nop

    // 0x80056040: sh          $t9, 0x2E($v1)
    MEM_H(0X2E, ctx->r3) = ctx->r25;
    // 0x80056044: lwc1        $f8, 0x1C($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X1C);
    // 0x80056048: lwc1        $f0, 0x684C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X684C);
    // 0x8005604C: lwc1        $f1, 0x6848($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, 0X6848);
    // 0x80056050: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x80056054: mul.d       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x80056058: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005605C: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80056060: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80056064: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x80056068: swc1        $f18, 0x1C($v1)
    MEM_W(0X1C, ctx->r3) = ctx->f18.u32l;
    // 0x8005606C: lwc1        $f16, 0x20($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X20);
    // 0x80056070: nop

    // 0x80056074: cvt.d.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f4.d = CVT_D_S(ctx->f16.fl);
    // 0x80056078: sub.d       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f8.d); 
    ctx->f6.d = ctx->f4.d - ctx->f8.d;
    // 0x8005607C: cvt.s.d     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f10.fl = CVT_S_D(ctx->f6.d);
    // 0x80056080: swc1        $f10, 0x20($v1)
    MEM_W(0X20, ctx->r3) = ctx->f10.u32l;
    // 0x80056084: lwc1        $f18, 0x24($a3)
    ctx->f18.u32l = MEM_W(ctx->r7, 0X24);
    // 0x80056088: nop

    // 0x8005608C: cvt.d.s     $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.d = CVT_D_S(ctx->f18.fl);
    // 0x80056090: mul.d       $f4, $f16, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f16.d, ctx->f0.d);
    // 0x80056094: cvt.s.d     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f8.fl = CVT_S_D(ctx->f4.d);
    // 0x80056098: swc1        $f8, 0x24($v1)
    MEM_W(0X24, ctx->r3) = ctx->f8.u32l;
    // 0x8005609C: sb          $t4, 0xB($v0)
    MEM_B(0XB, ctx->r2) = ctx->r12;
    // 0x800560A0: sw          $zero, 0x144($s0)
    MEM_W(0X144, ctx->r16) = 0;
    // 0x800560A4: b           L_80056920
    // 0x800560A8: sb          $t3, 0x211($s0)
    MEM_B(0X211, ctx->r16) = ctx->r11;
        goto L_80056920;
    // 0x800560A8: sb          $t3, 0x211($s0)
    MEM_B(0X211, ctx->r16) = ctx->r11;
L_800560AC:
    // 0x800560AC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800560B0: addiu       $a1, $a1, -0x2AD4
    ctx->r5 = ADD32(ctx->r5, -0X2AD4);
    // 0x800560B4: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800560B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800560BC: andi        $t6, $t5, 0x2000
    ctx->r14 = ctx->r13 & 0X2000;
    // 0x800560C0: beq         $t6, $zero, L_800560CC
    if (ctx->r14 == 0) {
        // 0x800560C4: addiu       $a0, $zero, 0xC
        ctx->r4 = ADD32(0, 0XC);
            goto L_800560CC;
    }
    // 0x800560C4: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    // 0x800560C8: sb          $zero, 0x211($s0)
    MEM_B(0X211, ctx->r16) = 0;
L_800560CC:
    // 0x800560CC: lb          $t7, 0x211($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X211);
    // 0x800560D0: nop

    // 0x800560D4: beq         $t7, $zero, L_800560F0
    if (ctx->r15 == 0) {
        // 0x800560D8: nop
    
            goto L_800560F0;
    }
    // 0x800560D8: nop

    // 0x800560DC: sw          $zero, -0x2AD0($at)
    MEM_W(-0X2AD0, ctx->r1) = 0;
    // 0x800560E0: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x800560E4: addiu       $at, $zero, -0x2001
    ctx->r1 = ADD32(0, -0X2001);
    // 0x800560E8: and         $t9, $t8, $at
    ctx->r25 = ctx->r24 & ctx->r1;
    // 0x800560EC: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_800560F0:
    // 0x800560F0: lb          $t4, 0x175($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X175);
    // 0x800560F4: nop

    // 0x800560F8: bne         $t4, $zero, L_80056104
    if (ctx->r12 != 0) {
        // 0x800560FC: nop
    
            goto L_80056104;
    }
    // 0x800560FC: nop

    // 0x80056100: sw          $zero, 0x140($s0)
    MEM_W(0X140, ctx->r16) = 0;
L_80056104:
    // 0x80056104: lb          $t3, 0x172($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X172);
    // 0x80056108: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005610C: bne         $t3, $at, L_80056118
    if (ctx->r11 != ctx->r1) {
        // 0x80056110: nop
    
            goto L_80056118;
    }
    // 0x80056110: nop

    // 0x80056114: sb          $zero, 0x173($s0)
    MEM_B(0X173, ctx->r16) = 0;
L_80056118:
    // 0x80056118: lb          $t5, 0x173($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X173);
    // 0x8005611C: nop

    // 0x80056120: bgtz        $t5, L_8005614C
    if (SIGNED(ctx->r13) > 0) {
        // 0x80056124: nop
    
            goto L_8005614C;
    }
    // 0x80056124: nop

    // 0x80056128: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005612C: or          $a0, $a3, $zero
    ctx->r4 = ctx->r7 | 0;
    // 0x80056130: andi        $t7, $t6, 0x2000
    ctx->r15 = ctx->r14 & 0X2000;
    // 0x80056134: beq         $t7, $zero, L_80056924
    if (ctx->r15 == 0) {
        // 0x80056138: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056924;
    }
    // 0x80056138: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8005613C: jal         0x80056930
    // 0x80056140: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    play_char_horn_sound(rdram, ctx);
        goto after_0;
    // 0x80056140: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_0:
    // 0x80056144: b           L_80056924
    // 0x80056148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80056924;
    // 0x80056148: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005614C:
    // 0x8005614C: jal         0x8001E29C
    // 0x80056150: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80056150: sw          $a3, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r7;
    after_1:
    // 0x80056154: lb          $t8, 0x172($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X172);
    // 0x80056158: lb          $t4, 0x174($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X174);
    // 0x8005615C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x80056160: addu        $t9, $t9, $t8
    ctx->r25 = ADD32(ctx->r25, ctx->r24);
    // 0x80056164: sll         $t9, $t9, 1
    ctx->r25 = S32(ctx->r25 << 1);
    // 0x80056168: sll         $t3, $t4, 1
    ctx->r11 = S32(ctx->r12 << 1);
    // 0x8005616C: addu        $t5, $t9, $t3
    ctx->r13 = ADD32(ctx->r25, ctx->r11);
    // 0x80056170: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x80056174: lb          $t0, 0x0($t6)
    ctx->r8 = MEM_B(ctx->r14, 0X0);
    // 0x80056178: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005617C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056180: bne         $t0, $at, L_80056190
    if (ctx->r8 != ctx->r1) {
        // 0x80056184: addiu       $a1, $a1, -0x2AD4
        ctx->r5 = ADD32(ctx->r5, -0X2AD4);
            goto L_80056190;
    }
    // 0x80056184: addiu       $a1, $a1, -0x2AD4
    ctx->r5 = ADD32(ctx->r5, -0X2AD4);
    // 0x80056188: b           L_80056920
    // 0x8005618C: sb          $zero, 0x173($s0)
    MEM_B(0X173, ctx->r16) = 0;
        goto L_80056920;
    // 0x8005618C: sb          $zero, 0x173($s0)
    MEM_B(0X173, ctx->r16) = 0;
L_80056190:
    // 0x80056190: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x80056194: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80056198: andi        $t8, $t7, 0x2000
    ctx->r24 = ctx->r15 & 0X2000;
    // 0x8005619C: beq         $t8, $zero, L_800561C0
    if (ctx->r24 == 0) {
        // 0x800561A0: addiu       $a0, $zero, 0x13E
        ctx->r4 = ADD32(0, 0X13E);
            goto L_800561C0;
    }
    // 0x800561A0: addiu       $a0, $zero, 0x13E
    ctx->r4 = ADD32(0, 0X13E);
    // 0x800561A4: lh          $a1, 0x0($s0)
    ctx->r5 = MEM_H(ctx->r16, 0X0);
    // 0x800561A8: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x800561AC: jal         0x800A74EC
    // 0x800561B0: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    hud_sound_stop(rdram, ctx);
        goto after_2;
    // 0x800561B0: sw          $zero, 0x68($sp)
    MEM_W(0X68, ctx->r29) = 0;
    after_2:
    // 0x800561B4: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800561B8: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x800561BC: nop

L_800561C0:
    // 0x800561C0: lb          $t4, 0x195($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X195);
    // 0x800561C4: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800561C8: beq         $t4, $zero, L_800561E4
    if (ctx->r12 == 0) {
        // 0x800561CC: nop
    
            goto L_800561E4;
    }
    // 0x800561CC: nop

    // 0x800561D0: lb          $t9, 0x175($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X175);
    // 0x800561D4: nop

    // 0x800561D8: bne         $t9, $zero, L_80056924
    if (ctx->r25 != 0) {
        // 0x800561DC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056924;
    }
    // 0x800561DC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800561E0: sb          $zero, 0x195($s0)
    MEM_B(0X195, ctx->r16) = 0;
L_800561E4:
    // 0x800561E4: lw          $t3, -0x2AD8($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AD8);
    // 0x800561E8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800561EC: andi        $t5, $t3, 0x2000
    ctx->r13 = ctx->r11 & 0X2000;
    // 0x800561F0: bne         $t5, $zero, L_8005620C
    if (ctx->r13 != 0) {
        // 0x800561F4: nop
    
            goto L_8005620C;
    }
    // 0x800561F4: nop

    // 0x800561F8: lw          $v1, -0x2AD0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2AD0);
    // 0x800561FC: nop

    // 0x80056200: andi        $t6, $v1, 0x2000
    ctx->r14 = ctx->r3 & 0X2000;
    // 0x80056204: beq         $t6, $zero, L_8005631C
    if (ctx->r14 == 0) {
        // 0x80056208: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_8005631C;
    }
    // 0x80056208: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8005620C:
    // 0x8005620C: beq         $t0, $zero, L_80056248
    if (ctx->r8 == 0) {
        // 0x80056210: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80056248;
    }
    // 0x80056210: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80056214: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80056218: beq         $t0, $at, L_80056284
    if (ctx->r8 == ctx->r1) {
        // 0x8005621C: or          $a1, $s0, $zero
        ctx->r5 = ctx->r16 | 0;
            goto L_80056284;
    }
    // 0x8005621C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x80056220: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80056224: beq         $t0, $at, L_80056284
    if (ctx->r8 == ctx->r1) {
        // 0x80056228: addiu       $at, $zero, 0x7
        ctx->r1 = ADD32(0, 0X7);
            goto L_80056284;
    }
    // 0x80056228: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8005622C: beq         $t0, $at, L_80056284
    if (ctx->r8 == ctx->r1) {
        // 0x80056230: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80056284;
    }
    // 0x80056230: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80056234: lw          $v1, -0x2AD0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2AD0);
    // 0x80056238: nop

    // 0x8005623C: andi        $t7, $v1, 0x2000
    ctx->r15 = ctx->r3 & 0X2000;
    // 0x80056240: b           L_8005631C
    // 0x80056244: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
        goto L_8005631C;
    // 0x80056244: or          $v1, $t7, $zero
    ctx->r3 = ctx->r15 | 0;
L_80056248:
    // 0x80056248: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x8005624C: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x80056250: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80056254: jal         0x8005698C
    // 0x80056258: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_8005698C(rdram, ctx);
        goto after_3;
    // 0x80056258: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_3:
    // 0x8005625C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x80056260: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x80056264: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x80056268: sw          $v0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r2;
    // 0x8005626C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80056270: lw          $v1, -0x2AD0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2AD0);
    // 0x80056274: sw          $v0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r2;
    // 0x80056278: andi        $t8, $v1, 0x2000
    ctx->r24 = ctx->r3 & 0X2000;
    // 0x8005627C: b           L_8005631C
    // 0x80056280: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
        goto L_8005631C;
    // 0x80056280: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_80056284:
    // 0x80056284: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80056288: addiu       $a2, $sp, 0x64
    ctx->r6 = ADD32(ctx->r29, 0X64);
    // 0x8005628C: sw          $a3, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r7;
    // 0x80056290: jal         0x8005698C
    // 0x80056294: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    func_8005698C(rdram, ctx);
        goto after_4;
    // 0x80056294: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    after_4:
    // 0x80056298: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8005629C: lw          $a3, 0x68($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X68);
    // 0x800562A0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800562A4: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800562A8: bne         $t0, $at, L_800562C0
    if (ctx->r8 != ctx->r1) {
        // 0x800562AC: sb          $zero, 0x175($s0)
        MEM_B(0X175, ctx->r16) = 0;
            goto L_800562C0;
    }
    // 0x800562AC: sb          $zero, 0x175($s0)
    MEM_B(0X175, ctx->r16) = 0;
    // 0x800562B0: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800562B4: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800562B8: b           L_800562D0
    // 0x800562BC: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
        goto L_800562D0;
    // 0x800562BC: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
L_800562C0:
    // 0x800562C0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800562C4: lwc1        $f0, 0x6850($at)
    ctx->f0.u32l = MEM_W(ctx->r1, 0X6850);
    // 0x800562C8: nop

    // 0x800562CC: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
L_800562D0:
    // 0x800562D0: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x800562D4: c.lt.s      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.fl < ctx->f0.fl;
    // 0x800562D8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800562DC: bc1f        L_80056304
    if (!c1cs) {
        // 0x800562E0: nop
    
            goto L_80056304;
    }
    // 0x800562E0: nop

    // 0x800562E4: bne         $t0, $at, L_800562FC
    if (ctx->r8 != ctx->r1) {
        // 0x800562E8: nop
    
            goto L_800562FC;
    }
    // 0x800562E8: nop

    // 0x800562EC: beq         $v0, $zero, L_800562FC
    if (ctx->r2 == 0) {
        // 0x800562F0: nop
    
            goto L_800562FC;
    }
    // 0x800562F0: nop

    // 0x800562F4: lw          $a3, 0x64($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X64);
    // 0x800562F8: nop

L_800562FC:
    // 0x800562FC: b           L_8005630C
    // 0x80056300: sw          $v0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r2;
        goto L_8005630C;
    // 0x80056300: sw          $v0, 0x140($s0)
    MEM_W(0X140, ctx->r16) = ctx->r2;
L_80056304:
    // 0x80056304: sw          $zero, 0x140($s0)
    MEM_W(0X140, ctx->r16) = 0;
    // 0x80056308: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8005630C:
    // 0x8005630C: lw          $v1, -0x2AD0($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2AD0);
    // 0x80056310: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x80056314: andi        $t4, $v1, 0x2000
    ctx->r12 = ctx->r3 & 0X2000;
    // 0x80056318: or          $v1, $t4, $zero
    ctx->r3 = ctx->r12 | 0;
L_8005631C:
    // 0x8005631C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80056320: beq         $v1, $zero, L_80056920
    if (ctx->r3 == 0) {
        // 0x80056324: addiu       $v0, $zero, 0x1D
        ctx->r2 = ADD32(0, 0X1D);
            goto L_80056920;
    }
    // 0x80056324: addiu       $v0, $zero, 0x1D
    ctx->r2 = ADD32(0, 0X1D);
    // 0x80056328: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x8005632C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80056330: sltiu       $at, $t0, 0x10
    ctx->r1 = ctx->r8 < 0X10 ? 1 : 0;
    // 0x80056334: sw          $t0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r8;
    // 0x80056338: beq         $at, $zero, L_80056620
    if (ctx->r1 == 0) {
        // 0x8005633C: or          $t9, $t0, $zero
        ctx->r25 = ctx->r8 | 0;
            goto L_80056620;
    }
    // 0x8005633C: or          $t9, $t0, $zero
    ctx->r25 = ctx->r8 | 0;
    // 0x80056340: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80056344: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056348: addu        $at, $at, $t9
    gpr jr_addend_80056354 = ctx->r25;
    ctx->r1 = ADD32(ctx->r1, ctx->r25);
    // 0x8005634C: lw          $t9, 0x6854($at)
    ctx->r25 = ADD32(ctx->r1, 0X6854);
    // 0x80056350: nop

    // 0x80056354: jr          $t9
    // 0x80056358: nop

    switch (jr_addend_80056354 >> 2) {
        case 0: goto L_8005635C; break;
        case 1: goto L_80056370; break;
        case 2: goto L_80056380; break;
        case 3: goto L_8005639C; break;
        case 4: goto L_800563EC; break;
        case 5: goto L_80056508; break;
        case 6: goto L_8005655C; break;
        case 7: goto L_80056508; break;
        case 8: goto L_800563EC; break;
        case 9: goto L_80056620; break;
        case 10: goto L_800563CC; break;
        case 11: goto L_80056380; break;
        case 12: goto L_800565C0; break;
        case 13: goto L_800565E0; break;
        case 14: goto L_80056600; break;
        case 15: goto L_800563EC; break;
        default: switch_error(__func__, 0x80056354, 0x800E6854);
    }
    // 0x80056358: nop

L_8005635C:
    // 0x8005635C: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80056360: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80056364: addiu       $v0, $zero, 0xE5
    ctx->r2 = ADD32(0, 0XE5);
    // 0x80056368: b           L_8005662C
    // 0x8005636C: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
        goto L_8005662C;
    // 0x8005636C: swc1        $f10, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f10.u32l;
L_80056370:
    // 0x80056370: lui         $at, 0xC120
    ctx->r1 = S32(0XC120 << 16);
    // 0x80056374: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80056378: b           L_8005662C
    // 0x8005637C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
        goto L_8005662C;
    // 0x8005637C: swc1        $f18, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f18.u32l;
L_80056380:
    // 0x80056380: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80056384: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80056388: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005638C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80056390: addiu       $v0, $zero, 0xE
    ctx->r2 = ADD32(0, 0XE);
    // 0x80056394: b           L_8005662C
    // 0x80056398: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
        goto L_8005662C;
    // 0x80056398: swc1        $f16, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f16.u32l;
L_8005639C:
    // 0x8005639C: lb          $t3, 0x1D6($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D6);
    // 0x800563A0: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800563A4: beq         $t3, $at, L_800563B4
    if (ctx->r11 == ctx->r1) {
        // 0x800563A8: addiu       $v0, $zero, 0xEB
        ctx->r2 = ADD32(0, 0XEB);
            goto L_800563B4;
    }
    // 0x800563A8: addiu       $v0, $zero, 0xEB
    ctx->r2 = ADD32(0, 0XEB);
    // 0x800563AC: b           L_800563B4
    // 0x800563B0: addiu       $v0, $zero, 0x82
    ctx->r2 = ADD32(0, 0X82);
        goto L_800563B4;
    // 0x800563B0: addiu       $v0, $zero, 0x82
    ctx->r2 = ADD32(0, 0X82);
L_800563B4:
    // 0x800563B4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800563B8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800563BC: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800563C0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800563C4: b           L_8005662C
    // 0x800563C8: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
        goto L_8005662C;
    // 0x800563C8: swc1        $f4, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f4.u32l;
L_800563CC:
    // 0x800563CC: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800563D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800563D4: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x800563D8: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800563DC: addiu       $v0, $zero, 0x2E
    ctx->r2 = ADD32(0, 0X2E);
    // 0x800563E0: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800563E4: b           L_8005662C
    // 0x800563E8: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
        goto L_8005662C;
    // 0x800563E8: swc1        $f8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f8.u32l;
L_800563EC:
    // 0x800563EC: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x800563F0: beq         $t0, $at, L_80056418
    if (ctx->r8 == ctx->r1) {
        // 0x800563F4: addiu       $at, $zero, 0xF
        ctx->r1 = ADD32(0, 0XF);
            goto L_80056418;
    }
    // 0x800563F4: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x800563F8: bne         $t0, $at, L_80056430
    if (ctx->r8 != ctx->r1) {
        // 0x800563FC: nop
    
            goto L_80056430;
    }
    // 0x800563FC: nop

    // 0x80056400: jal         0x8000C8B4
    // 0x80056404: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    normalise_time(rdram, ctx);
        goto after_5;
    // 0x80056404: addiu       $a0, $zero, 0x4B
    ctx->r4 = ADD32(0, 0X4B);
    after_5:
    // 0x80056408: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8005640C: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
    // 0x80056410: b           L_80056440
    // 0x80056414: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
        goto L_80056440;
    // 0x80056414: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
L_80056418:
    // 0x80056418: jal         0x8000C8B4
    // 0x8005641C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    normalise_time(rdram, ctx);
        goto after_6;
    // 0x8005641C: addiu       $a0, $zero, 0x37
    ctx->r4 = ADD32(0, 0X37);
    after_6:
    // 0x80056420: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80056424: sb          $t6, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r14;
    // 0x80056428: b           L_80056440
    // 0x8005642C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
        goto L_80056440;
    // 0x8005642C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
L_80056430:
    // 0x80056430: jal         0x8000C8B4
    // 0x80056434: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    normalise_time(rdram, ctx);
        goto after_7;
    // 0x80056434: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_7:
    // 0x80056438: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x8005643C: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
L_80056440:
    // 0x80056440: lbu         $t7, 0x20C($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X20C);
    // 0x80056444: nop

    // 0x80056448: beq         $t7, $zero, L_80056464
    if (ctx->r15 == 0) {
        // 0x8005644C: lw          $t9, 0x30($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X30);
            goto L_80056464;
    }
    // 0x8005644C: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
    // 0x80056450: lb          $t8, 0x203($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X203);
    // 0x80056454: nop

    // 0x80056458: ori         $t4, $t8, 0x4
    ctx->r12 = ctx->r24 | 0X4;
    // 0x8005645C: sb          $t4, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r12;
    // 0x80056460: lw          $t9, 0x30($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X30);
L_80056464:
    // 0x80056464: addiu       $at, $zero, 0xF
    ctx->r1 = ADD32(0, 0XF);
    // 0x80056468: bne         $t9, $at, L_80056498
    if (ctx->r25 != ctx->r1) {
        // 0x8005646C: lw          $a0, 0x88($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X88);
            goto L_80056498;
    }
    // 0x8005646C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80056470: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80056474: jal         0x80057048
    // 0x80056478: addiu       $a1, $zero, 0x232
    ctx->r5 = ADD32(0, 0X232);
    racer_play_sound(rdram, ctx);
        goto after_8;
    // 0x80056478: addiu       $a1, $zero, 0x232
    ctx->r5 = ADD32(0, 0X232);
    after_8:
    // 0x8005647C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80056480: addiu       $a1, $zero, 0x233
    ctx->r5 = ADD32(0, 0X233);
    // 0x80056484: jal         0x800570A4
    // 0x80056488: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    racer_play_sound_after_delay(rdram, ctx);
        goto after_9;
    // 0x80056488: addiu       $a2, $zero, 0x1E
    ctx->r6 = ADD32(0, 0X1E);
    after_9:
    // 0x8005648C: b           L_800564A4
    // 0x80056490: lb          $t3, 0x173($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X173);
        goto L_800564A4;
    // 0x80056490: lb          $t3, 0x173($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X173);
    // 0x80056494: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
L_80056498:
    // 0x80056498: jal         0x80057048
    // 0x8005649C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    racer_play_sound(rdram, ctx);
        goto after_10;
    // 0x8005649C: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_10:
    // 0x800564A0: lb          $t3, 0x173($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X173);
L_800564A4:
    // 0x800564A4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800564A8: addiu       $t5, $t3, -0x1
    ctx->r13 = ADD32(ctx->r11, -0X1);
    // 0x800564AC: sb          $t5, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r13;
    // 0x800564B0: lw          $t6, 0x30($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X30);
    // 0x800564B4: nop

    // 0x800564B8: bne         $t6, $at, L_800564E4
    if (ctx->r14 != ctx->r1) {
        // 0x800564BC: nop
    
            goto L_800564E4;
    }
    // 0x800564BC: nop

    // 0x800564C0: lb          $t7, 0x1D8($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D8);
    // 0x800564C4: nop

    // 0x800564C8: bne         $t7, $zero, L_80056924
    if (ctx->r15 != 0) {
        // 0x800564CC: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056924;
    }
    // 0x800564CC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800564D0: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800564D4: jal         0x80072348
    // 0x800564D8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    rumble_set(rdram, ctx);
        goto after_11;
    // 0x800564D8: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_11:
    // 0x800564DC: b           L_80056924
    // 0x800564E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80056924;
    // 0x800564E0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800564E4:
    // 0x800564E4: lb          $t8, 0x1D8($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D8);
    // 0x800564E8: nop

    // 0x800564EC: bne         $t8, $zero, L_80056924
    if (ctx->r24 != 0) {
        // 0x800564F0: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056924;
    }
    // 0x800564F0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800564F4: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800564F8: jal         0x80072348
    // 0x800564FC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    rumble_set(rdram, ctx);
        goto after_12;
    // 0x800564FC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    after_12:
    // 0x80056500: b           L_80056924
    // 0x80056504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80056924;
    // 0x80056504: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80056508:
    // 0x80056508: lb          $t4, 0x173($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X173);
    // 0x8005650C: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80056510: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056514: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x80056518: beq         $t3, $at, L_80056920
    if (ctx->r11 == ctx->r1) {
        // 0x8005651C: sb          $t9, 0x173($s0)
        MEM_B(0X173, ctx->r16) = ctx->r25;
            goto L_80056920;
    }
    // 0x8005651C: sb          $t9, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r25;
    // 0x80056520: beq         $t2, $zero, L_80056538
    if (ctx->r10 == 0) {
        // 0x80056524: addiu       $t5, $zero, 0x5A
        ctx->r13 = ADD32(0, 0X5A);
            goto L_80056538;
    }
    // 0x80056524: addiu       $t5, $zero, 0x5A
    ctx->r13 = ADD32(0, 0X5A);
    // 0x80056528: addiu       $t6, $t0, -0x5
    ctx->r14 = ADD32(ctx->r8, -0X5);
    // 0x8005652C: sra         $t7, $t6, 1
    ctx->r15 = S32(SIGNED(ctx->r14) >> 1);
    // 0x80056530: sb          $t5, 0x175($s0)
    MEM_B(0X175, ctx->r16) = ctx->r13;
    // 0x80056534: sb          $t7, 0x184($s0)
    MEM_B(0X184, ctx->r16) = ctx->r15;
L_80056538:
    // 0x80056538: lb          $t8, 0x1D8($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005653C: nop

    // 0x80056540: bne         $t8, $zero, L_80056924
    if (ctx->r24 != 0) {
        // 0x80056544: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056924;
    }
    // 0x80056544: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80056548: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x8005654C: jal         0x80072348
    // 0x80056550: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    rumble_set(rdram, ctx);
        goto after_13;
    // 0x80056550: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_13:
    // 0x80056554: b           L_80056924
    // 0x80056558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80056924;
    // 0x80056558: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8005655C:
    // 0x8005655C: lb          $t4, 0x173($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X173);
    // 0x80056560: lh          $t3, 0x0($s0)
    ctx->r11 = MEM_H(ctx->r16, 0X0);
    // 0x80056564: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80056568: addiu       $t9, $t4, -0x1
    ctx->r25 = ADD32(ctx->r12, -0X1);
    // 0x8005656C: sb          $t9, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r25;
    // 0x80056570: beq         $t3, $at, L_80056920
    if (ctx->r11 == ctx->r1) {
        // 0x80056574: sw          $zero, 0x140($s0)
        MEM_W(0X140, ctx->r16) = 0;
            goto L_80056920;
    }
    // 0x80056574: sw          $zero, 0x140($s0)
    MEM_W(0X140, ctx->r16) = 0;
    // 0x80056578: beq         $a3, $zero, L_8005659C
    if (ctx->r7 == 0) {
        // 0x8005657C: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005659C;
    }
    // 0x8005657C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80056580: addiu       $t6, $zero, 0x78
    ctx->r14 = ADD32(0, 0X78);
    // 0x80056584: sb          $t5, 0x195($a3)
    MEM_B(0X195, ctx->r7) = ctx->r13;
    // 0x80056588: sb          $t6, 0x175($a3)
    MEM_B(0X175, ctx->r7) = ctx->r14;
    // 0x8005658C: lw          $t7, 0x88($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X88);
    // 0x80056590: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x80056594: sb          $t8, 0x184($a3)
    MEM_B(0X184, ctx->r7) = ctx->r24;
    // 0x80056598: sw          $t7, 0x140($a3)
    MEM_W(0X140, ctx->r7) = ctx->r15;
L_8005659C:
    // 0x8005659C: lb          $t4, 0x1D8($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D8);
    // 0x800565A0: nop

    // 0x800565A4: bne         $t4, $zero, L_80056924
    if (ctx->r12 != 0) {
        // 0x800565A8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80056924;
    }
    // 0x800565A8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800565AC: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x800565B0: jal         0x80072348
    // 0x800565B4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    rumble_set(rdram, ctx);
        goto after_14;
    // 0x800565B4: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    after_14:
    // 0x800565B8: b           L_80056924
    // 0x800565BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80056924;
    // 0x800565BC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800565C0:
    // 0x800565C0: lb          $t5, 0x173($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X173);
    // 0x800565C4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800565C8: addiu       $t3, $zero, 0x12C
    ctx->r11 = ADD32(0, 0X12C);
    // 0x800565CC: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x800565D0: sb          $t9, 0x189($s0)
    MEM_B(0X189, ctx->r16) = ctx->r25;
    // 0x800565D4: sh          $t3, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r11;
    // 0x800565D8: b           L_80056920
    // 0x800565DC: sb          $t6, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r14;
        goto L_80056920;
    // 0x800565DC: sb          $t6, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r14;
L_800565E0:
    // 0x800565E0: lb          $t8, 0x173($s0)
    ctx->r24 = MEM_B(ctx->r16, 0X173);
    // 0x800565E4: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x800565E8: addiu       $t9, $zero, 0x258
    ctx->r25 = ADD32(0, 0X258);
    // 0x800565EC: addiu       $t4, $t8, -0x1
    ctx->r12 = ADD32(ctx->r24, -0X1);
    // 0x800565F0: sb          $t7, 0x189($s0)
    MEM_B(0X189, ctx->r16) = ctx->r15;
    // 0x800565F4: sb          $t4, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r12;
    // 0x800565F8: b           L_80056920
    // 0x800565FC: sh          $t9, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r25;
        goto L_80056920;
    // 0x800565FC: sh          $t9, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r25;
L_80056600:
    // 0x80056600: lb          $t6, 0x173($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X173);
    // 0x80056604: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80056608: addiu       $t5, $zero, 0x384
    ctx->r13 = ADD32(0, 0X384);
    // 0x8005660C: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x80056610: sb          $t3, 0x189($s0)
    MEM_B(0X189, ctx->r16) = ctx->r11;
    // 0x80056614: sh          $t5, 0x18E($s0)
    MEM_H(0X18E, ctx->r16) = ctx->r13;
    // 0x80056618: b           L_80056920
    // 0x8005661C: sb          $t7, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r15;
        goto L_80056920;
    // 0x8005661C: sb          $t7, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r15;
L_80056620:
    // 0x80056620: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80056624: nop

    // 0x80056628: swc1        $f6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->f6.u32l;
L_8005662C:
    // 0x8005662C: lw          $a0, 0x88($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X88);
    // 0x80056630: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x80056634: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x80056638: addiu       $a3, $zero, 0x81
    ctx->r7 = ADD32(0, 0X81);
    // 0x8005663C: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x80056640: sw          $t0, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r8;
    // 0x80056644: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x80056648: jal         0x800570B8
    // 0x8005664C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    play_random_character_voice(rdram, ctx);
        goto after_15;
    // 0x8005664C: swc1        $f0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f0.u32l;
    after_15:
    // 0x80056650: lwc1        $f10, 0x38($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80056654: lwc1        $f18, 0x64($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X64);
    // 0x80056658: lw          $v1, 0x88($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X88);
    // 0x8005665C: mul.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80056660: lwc1        $f4, 0xC($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80056664: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x80056668: addiu       $t7, $zero, 0x8
    ctx->r15 = ADD32(0, 0X8);
    // 0x8005666C: add.s       $f8, $f4, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f16.fl;
    // 0x80056670: addiu       $a0, $sp, 0x80
    ctx->r4 = ADD32(ctx->r29, 0X80);
    // 0x80056674: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x80056678: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8005667C: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x80056680: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80056684: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80056688: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8005668C: cvt.w.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    ctx->f6.u32l = CVT_W_S(ctx->f8.fl);
    // 0x80056690: mfc1        $t4, $f6
    ctx->r12 = (int32_t)ctx->f6.u32l;
    // 0x80056694: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x80056698: sh          $t4, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r12;
    // 0x8005669C: lwc1        $f10, 0x3C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x800566A0: lwc1        $f16, 0x10($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X10);
    // 0x800566A4: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800566A8: lwc1        $f10, 0x48($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X48);
    // 0x800566AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800566B0: add.s       $f8, $f16, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f16.fl + ctx->f4.fl;
    // 0x800566B4: mul.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800566B8: add.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800566BC: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800566C0: nop

    // 0x800566C4: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800566C8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800566CC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800566D0: nop

    // 0x800566D4: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800566D8: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800566DC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800566E0: sh          $t3, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r11;
    // 0x800566E4: lwc1        $f10, 0x40($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X40);
    // 0x800566E8: lwc1        $f16, 0x14($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0X14);
    // 0x800566EC: mul.s       $f8, $f10, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800566F0: sb          $t7, 0x81($sp)
    MEM_B(0X81, ctx->r29) = ctx->r15;
    // 0x800566F4: sb          $v0, 0x80($sp)
    MEM_B(0X80, ctx->r29) = ctx->r2;
    // 0x800566F8: add.s       $f4, $f16, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x800566FC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80056700: nop

    // 0x80056704: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80056708: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005670C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80056710: nop

    // 0x80056714: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80056718: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x8005671C: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80056720: jal         0x8000EA54
    // 0x80056724: sh          $t6, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r14;
    spawn_object(rdram, ctx);
        goto after_16;
    // 0x80056724: sh          $t6, 0x86($sp)
    MEM_H(0X86, ctx->r29) = ctx->r14;
    after_16:
    // 0x80056728: lw          $t0, 0x7C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X7C);
    // 0x8005672C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x80056730: lwc1        $f0, 0x58($sp)
    ctx->f0.u32l = MEM_W(ctx->r29, 0X58);
    // 0x80056734: beq         $v0, $zero, L_80056904
    if (ctx->r2 == 0) {
        // 0x80056738: nop
    
            goto L_80056904;
    }
    // 0x80056738: nop

    // 0x8005673C: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x80056740: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x80056744: lwc1        $f18, 0x38($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X38);
    // 0x80056748: lwc1        $f10, 0x1C($t1)
    ctx->f10.u32l = MEM_W(ctx->r9, 0X1C);
    // 0x8005674C: mul.s       $f16, $f18, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80056750: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80056754: sub.s       $f8, $f10, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f16.fl;
    // 0x80056758: swc1        $f8, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f8.u32l;
    // 0x8005675C: lwc1        $f6, 0x3C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X3C);
    // 0x80056760: lwc1        $f4, 0x20($t1)
    ctx->f4.u32l = MEM_W(ctx->r9, 0X20);
    // 0x80056764: mul.s       $f18, $f6, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x80056768: sub.s       $f10, $f4, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x8005676C: swc1        $f10, 0x20($v0)
    MEM_W(0X20, ctx->r2) = ctx->f10.u32l;
    // 0x80056770: lwc1        $f8, 0x40($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X40);
    // 0x80056774: lwc1        $f16, 0x24($t1)
    ctx->f16.u32l = MEM_W(ctx->r9, 0X24);
    // 0x80056778: mul.s       $f6, $f8, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x8005677C: sub.s       $f4, $f16, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f6.fl;
    // 0x80056780: swc1        $f4, 0x24($v0)
    MEM_W(0X24, ctx->r2) = ctx->f4.u32l;
    // 0x80056784: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x80056788: nop

    // 0x8005678C: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x80056790: lh          $t4, 0x2($t1)
    ctx->r12 = MEM_H(ctx->r9, 0X2);
    // 0x80056794: nop

    // 0x80056798: sh          $t4, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r12;
    // 0x8005679C: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x800567A0: nop

    // 0x800567A4: bne         $t9, $at, L_800567DC
    if (ctx->r25 != ctx->r1) {
        // 0x800567A8: nop
    
            goto L_800567DC;
    }
    // 0x800567A8: nop

    // 0x800567AC: lb          $t3, 0x1E5($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1E5);
    // 0x800567B0: nop

    // 0x800567B4: beq         $t3, $zero, L_800567DC
    if (ctx->r11 == 0) {
        // 0x800567B8: nop
    
            goto L_800567DC;
    }
    // 0x800567B8: nop

    // 0x800567BC: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x800567C0: nop

    // 0x800567C4: slti        $at, $v1, -0x3FF
    ctx->r1 = SIGNED(ctx->r3) < -0X3FF ? 1 : 0;
    // 0x800567C8: bne         $at, $zero, L_800567DC
    if (ctx->r1 != 0) {
        // 0x800567CC: slti        $at, $v1, 0x400
        ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
            goto L_800567DC;
    }
    // 0x800567CC: slti        $at, $v1, 0x400
    ctx->r1 = SIGNED(ctx->r3) < 0X400 ? 1 : 0;
    // 0x800567D0: beq         $at, $zero, L_800567DC
    if (ctx->r1 == 0) {
        // 0x800567D4: nop
    
            goto L_800567DC;
    }
    // 0x800567D4: nop

    // 0x800567D8: sh          $zero, 0x2($v0)
    MEM_H(0X2, ctx->r2) = 0;
L_800567DC:
    // 0x800567DC: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x800567E0: andi        $t6, $t0, 0xFF
    ctx->r14 = ctx->r8 & 0XFF;
    // 0x800567E4: sw          $t1, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r9;
    // 0x800567E8: sw          $t2, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r10;
    // 0x800567EC: lb          $t5, 0x192($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X192);
    // 0x800567F0: sltiu       $at, $t6, 0xC
    ctx->r1 = ctx->r14 < 0XC ? 1 : 0;
    // 0x800567F4: sb          $t5, 0x19($v1)
    MEM_B(0X19, ctx->r3) = ctx->r13;
    // 0x800567F8: lwc1        $f18, 0x2C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x800567FC: sb          $t0, 0x18($v1)
    MEM_B(0X18, ctx->r3) = ctx->r8;
    // 0x80056800: sub.s       $f10, $f18, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f18.fl - ctx->f0.fl;
    // 0x80056804: beq         $at, $zero, L_80056884
    if (ctx->r1 == 0) {
        // 0x80056808: swc1        $f10, 0x10($v1)
        MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
            goto L_80056884;
    }
    // 0x80056808: swc1        $f10, 0x10($v1)
    MEM_W(0X10, ctx->r3) = ctx->f10.u32l;
    // 0x8005680C: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80056810: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80056814: addu        $at, $at, $t6
    gpr jr_addend_80056820 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80056818: lw          $t6, 0x6894($at)
    ctx->r14 = ADD32(ctx->r1, 0X6894);
    // 0x8005681C: nop

    // 0x80056820: jr          $t6
    // 0x80056824: nop

    switch (jr_addend_80056820 >> 2) {
        case 0: goto L_80056828; break;
        case 1: goto L_80056834; break;
        case 2: goto L_80056840; break;
        case 3: goto L_8005684C; break;
        case 4: goto L_80056884; break;
        case 5: goto L_80056884; break;
        case 6: goto L_80056884; break;
        case 7: goto L_80056884; break;
        case 8: goto L_80056884; break;
        case 9: goto L_80056884; break;
        case 10: goto L_80056874; break;
        case 11: goto L_80056880; break;
        default: switch_error(__func__, 0x80056820, 0x800E6894);
    }
    // 0x80056824: nop

L_80056828:
    // 0x80056828: addiu       $t7, $zero, 0x134
    ctx->r15 = ADD32(0, 0X134);
    // 0x8005682C: b           L_80056884
    // 0x80056830: sh          $t7, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r15;
        goto L_80056884;
    // 0x80056830: sh          $t7, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r15;
L_80056834:
    // 0x80056834: addiu       $t8, $zero, 0x135
    ctx->r24 = ADD32(0, 0X135);
    // 0x80056838: b           L_80056884
    // 0x8005683C: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
        goto L_80056884;
    // 0x8005683C: sh          $t8, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r24;
L_80056840:
    // 0x80056840: addiu       $t4, $zero, 0xF
    ctx->r12 = ADD32(0, 0XF);
    // 0x80056844: b           L_80056884
    // 0x80056848: sh          $t4, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r12;
        goto L_80056884;
    // 0x80056848: sh          $t4, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r12;
L_8005684C:
    // 0x8005684C: lb          $t9, 0x1D6($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D6);
    // 0x80056850: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80056854: beq         $t9, $at, L_8005686C
    if (ctx->r25 == ctx->r1) {
        // 0x80056858: addiu       $t5, $zero, 0x151
        ctx->r13 = ADD32(0, 0X151);
            goto L_8005686C;
    }
    // 0x80056858: addiu       $t5, $zero, 0x151
    ctx->r13 = ADD32(0, 0X151);
    // 0x8005685C: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80056860: lw          $t3, 0x50($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X50);
    // 0x80056864: nop

    // 0x80056868: swc1        $f8, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->f8.u32l;
L_8005686C:
    // 0x8005686C: b           L_80056884
    // 0x80056870: sh          $t5, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r13;
        goto L_80056884;
    // 0x80056870: sh          $t5, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r13;
L_80056874:
    // 0x80056874: addiu       $t6, $zero, 0xF
    ctx->r14 = ADD32(0, 0XF);
    // 0x80056878: b           L_80056884
    // 0x8005687C: sh          $t6, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r14;
        goto L_80056884;
    // 0x8005687C: sh          $t6, 0x3A($sp)
    MEM_H(0X3A, ctx->r29) = ctx->r14;
L_80056880:
    // 0x80056880: sh          $zero, 0x18($v0)
    MEM_H(0X18, ctx->r2) = 0;
L_80056884:
    // 0x80056884: lhu         $t7, 0x3A($sp)
    ctx->r15 = MEM_HU(ctx->r29, 0X3A);
    // 0x80056888: nop

    // 0x8005688C: beq         $t7, $zero, L_80056904
    if (ctx->r15 == 0) {
        // 0x80056890: nop
    
            goto L_80056904;
    }
    // 0x80056890: nop

    // 0x80056894: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80056898: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8005689C: bne         $t8, $at, L_800568C8
    if (ctx->r24 != ctx->r1) {
        // 0x800568A0: or          $a0, $t7, $zero
        ctx->r4 = ctx->r15 | 0;
            goto L_800568C8;
    }
    // 0x800568A0: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    // 0x800568A4: lw          $a1, 0xC($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC);
    // 0x800568A8: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x800568AC: lw          $a3, 0x14($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X14);
    // 0x800568B0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x800568B4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800568B8: jal         0x80009558
    // 0x800568BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_17;
    // 0x800568BC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_17:
    // 0x800568C0: b           L_80056908
    // 0x800568C4: lb          $v0, 0x173($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X173);
        goto L_80056908;
    // 0x800568C4: lb          $v0, 0x173($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X173);
L_800568C8:
    // 0x800568C8: lw          $a0, 0x218($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X218);
    // 0x800568CC: nop

    // 0x800568D0: beq         $a0, $zero, L_800568E8
    if (ctx->r4 == 0) {
        // 0x800568D4: nop
    
            goto L_800568E8;
    }
    // 0x800568D4: nop

    // 0x800568D8: jal         0x8000488C
    // 0x800568DC: nop

    sndp_stop(rdram, ctx);
        goto after_18;
    // 0x800568DC: nop

    after_18:
    // 0x800568E0: lw          $t1, 0x88($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X88);
    // 0x800568E4: nop

L_800568E8:
    // 0x800568E8: lhu         $a0, 0x3A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X3A);
    // 0x800568EC: lw          $a1, 0xC($t1)
    ctx->r5 = MEM_W(ctx->r9, 0XC);
    // 0x800568F0: lw          $a2, 0x10($t1)
    ctx->r6 = MEM_W(ctx->r9, 0X10);
    // 0x800568F4: lw          $a3, 0x14($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X14);
    // 0x800568F8: addiu       $t9, $s0, 0x218
    ctx->r25 = ADD32(ctx->r16, 0X218);
    // 0x800568FC: jal         0x80001EA8
    // 0x80056900: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    sound_play_spatial(rdram, ctx);
        goto after_19;
    // 0x80056900: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    after_19:
L_80056904:
    // 0x80056904: lb          $v0, 0x173($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X173);
L_80056908:
    // 0x80056908: nop

    // 0x8005690C: blez        $v0, L_8005691C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80056910: addiu       $t3, $v0, -0x1
        ctx->r11 = ADD32(ctx->r2, -0X1);
            goto L_8005691C;
    }
    // 0x80056910: addiu       $t3, $v0, -0x1
    ctx->r11 = ADD32(ctx->r2, -0X1);
    // 0x80056914: b           L_80056920
    // 0x80056918: sb          $t3, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r11;
        goto L_80056920;
    // 0x80056918: sb          $t3, 0x173($s0)
    MEM_B(0X173, ctx->r16) = ctx->r11;
L_8005691C:
    // 0x8005691C: sb          $zero, 0x173($s0)
    MEM_B(0X173, ctx->r16) = 0;
L_80056920:
    // 0x80056920: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80056924:
    // 0x80056924: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80056928: jr          $ra
    // 0x8005692C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    return;
    // 0x8005692C: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
;}
RECOMP_FUNC void func_800738A4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800738A4: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800738A8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800738AC: or          $s4, $a0, $zero
    ctx->r20 = ctx->r4 | 0;
    // 0x800738B0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800738B4: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800738B8: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800738BC: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800738C0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800738C4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800738C8: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x800738CC: jal         0x8006B224
    // 0x800738D0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    level_count(rdram, ctx);
        goto after_0;
    // 0x800738D0: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_0:
    // 0x800738D4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800738D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800738DC: sw          $t6, 0x41EC($at)
    MEM_W(0X41EC, ctx->r1) = ctx->r14;
    // 0x800738E0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800738E4: sw          $zero, 0x41F0($at)
    MEM_W(0X41F0, ctx->r1) = 0;
    // 0x800738E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800738EC: addiu       $t7, $zero, 0x80
    ctx->r15 = ADD32(0, 0X80);
    // 0x800738F0: sw          $t7, 0x41F4($at)
    MEM_W(0X41F4, ctx->r1) = ctx->r15;
    // 0x800738F4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800738F8: jal         0x80072E28
    // 0x800738FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_1;
    // 0x800738FC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_1:
    // 0x80073900: lw          $t8, 0x48($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X48);
    // 0x80073904: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x80073908: blez        $t8, L_80073A18
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8007390C: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_80073A18;
    }
    // 0x8007390C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_80073910:
    // 0x80073910: jal         0x8006B14C
    // 0x80073914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_2;
    // 0x80073914: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x80073918: bne         $v0, $zero, L_80073A08
    if (ctx->r2 != 0) {
        // 0x8007391C: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80073A08;
    }
    // 0x8007391C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80073920: jal         0x8006B0F8
    // 0x80073924: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_3;
    // 0x80073924: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_3:
    // 0x80073928: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x8007392C: sra         $t9, $s3, 16
    ctx->r25 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80073930: andi        $t2, $v0, 0x1
    ctx->r10 = ctx->r2 & 0X1;
    // 0x80073934: beq         $t2, $zero, L_80073970
    if (ctx->r10 == 0) {
        // 0x80073938: or          $s3, $t9, $zero
        ctx->r19 = ctx->r25 | 0;
            goto L_80073970;
    }
    // 0x80073938: or          $s3, $t9, $zero
    ctx->r19 = ctx->r25 | 0;
    // 0x8007393C: lw          $t3, 0x24($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X24);
    // 0x80073940: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073944: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x80073948: lhu         $a1, 0x0($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X0);
    // 0x8007394C: jal         0x80072E28
    // 0x80073950: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_4;
    // 0x80073950: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_4:
    // 0x80073954: lw          $t5, 0x18($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X18);
    // 0x80073958: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007395C: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x80073960: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    // 0x80073964: jal         0x80072E28
    // 0x80073968: nop

    func_80072E28(rdram, ctx);
        goto after_5;
    // 0x80073968: nop

    after_5:
    // 0x8007396C: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_80073970:
    // 0x80073970: andi        $t7, $s3, 0x2
    ctx->r15 = ctx->r19 & 0X2;
    // 0x80073974: beq         $t7, $zero, L_800739B4
    if (ctx->r15 == 0) {
        // 0x80073978: andi        $t2, $s3, 0x4
        ctx->r10 = ctx->r19 & 0X4;
            goto L_800739B4;
    }
    // 0x80073978: andi        $t2, $s3, 0x4
    ctx->r10 = ctx->r19 & 0X4;
    // 0x8007397C: lw          $t8, 0x28($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X28);
    // 0x80073980: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073984: addu        $t9, $t8, $s0
    ctx->r25 = ADD32(ctx->r24, ctx->r16);
    // 0x80073988: lhu         $a1, 0x0($t9)
    ctx->r5 = MEM_HU(ctx->r25, 0X0);
    // 0x8007398C: jal         0x80072E28
    // 0x80073990: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_6;
    // 0x80073990: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_6:
    // 0x80073994: lw          $t0, 0x1C($s4)
    ctx->r8 = MEM_W(ctx->r20, 0X1C);
    // 0x80073998: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8007399C: addu        $t1, $t0, $s0
    ctx->r9 = ADD32(ctx->r8, ctx->r16);
    // 0x800739A0: lhu         $a1, 0x0($t1)
    ctx->r5 = MEM_HU(ctx->r9, 0X0);
    // 0x800739A4: jal         0x80072E28
    // 0x800739A8: nop

    func_80072E28(rdram, ctx);
        goto after_7;
    // 0x800739A8: nop

    after_7:
    // 0x800739AC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800739B0: andi        $t2, $s3, 0x4
    ctx->r10 = ctx->r19 & 0X4;
L_800739B4:
    // 0x800739B4: beq         $t2, $zero, L_800739F4
    if (ctx->r10 == 0) {
        // 0x800739B8: slti        $at, $s2, 0x30
        ctx->r1 = SIGNED(ctx->r18) < 0X30 ? 1 : 0;
            goto L_800739F4;
    }
    // 0x800739B8: slti        $at, $s2, 0x30
    ctx->r1 = SIGNED(ctx->r18) < 0X30 ? 1 : 0;
    // 0x800739BC: lw          $t3, 0x2C($s4)
    ctx->r11 = MEM_W(ctx->r20, 0X2C);
    // 0x800739C0: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x800739C4: addu        $t4, $t3, $s0
    ctx->r12 = ADD32(ctx->r11, ctx->r16);
    // 0x800739C8: lhu         $a1, 0x0($t4)
    ctx->r5 = MEM_HU(ctx->r12, 0X0);
    // 0x800739CC: jal         0x80072E28
    // 0x800739D0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_8;
    // 0x800739D0: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_8:
    // 0x800739D4: lw          $t5, 0x20($s4)
    ctx->r13 = MEM_W(ctx->r20, 0X20);
    // 0x800739D8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x800739DC: addu        $t6, $t5, $s0
    ctx->r14 = ADD32(ctx->r13, ctx->r16);
    // 0x800739E0: lhu         $a1, 0x0($t6)
    ctx->r5 = MEM_HU(ctx->r14, 0X0);
    // 0x800739E4: jal         0x80072E28
    // 0x800739E8: nop

    func_80072E28(rdram, ctx);
        goto after_9;
    // 0x800739E8: nop

    after_9:
    // 0x800739EC: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800739F0: slti        $at, $s2, 0x30
    ctx->r1 = SIGNED(ctx->r18) < 0X30 ? 1 : 0;
L_800739F4:
    // 0x800739F4: bne         $at, $zero, L_80073A08
    if (ctx->r1 != 0) {
        // 0x800739F8: lw          $t7, 0x48($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X48);
            goto L_80073A08;
    }
    // 0x800739F8: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x800739FC: b           L_80073A1C
    // 0x80073A00: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
        goto L_80073A1C;
    // 0x80073A00: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x80073A04: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
L_80073A08:
    // 0x80073A08: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073A0C: slt         $at, $s1, $t7
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80073A10: bne         $at, $zero, L_80073910
    if (ctx->r1 != 0) {
        // 0x80073A14: nop
    
            goto L_80073910;
    }
    // 0x80073A14: nop

L_80073A18:
    // 0x80073A18: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
L_80073A1C:
    // 0x80073A1C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073A20: sw          $t8, 0x41EC($at)
    MEM_W(0X41EC, ctx->r1) = ctx->r24;
    // 0x80073A24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073A28: sw          $zero, 0x41F0($at)
    MEM_W(0X41F0, ctx->r1) = 0;
    // 0x80073A2C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073A30: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80073A34: sw          $t9, 0x41F4($at)
    MEM_W(0X41F4, ctx->r1) = ctx->r25;
    // 0x80073A38: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
    // 0x80073A3C: addiu       $v1, $zero, 0x5
    ctx->r3 = ADD32(0, 0X5);
    // 0x80073A40: addiu       $v0, $t8, 0x2
    ctx->r2 = ADD32(ctx->r24, 0X2);
L_80073A44:
    // 0x80073A44: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80073A48: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073A4C: addu        $v1, $v1, $t0
    ctx->r3 = ADD32(ctx->r3, ctx->r8);
    // 0x80073A50: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x80073A54: slti        $at, $s1, 0xC0
    ctx->r1 = SIGNED(ctx->r17) < 0XC0 ? 1 : 0;
    // 0x80073A58: sra         $t2, $t1, 16
    ctx->r10 = S32(SIGNED(ctx->r9) >> 16);
    // 0x80073A5C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x80073A60: bne         $at, $zero, L_80073A44
    if (ctx->r1 != 0) {
        // 0x80073A64: or          $v1, $t2, $zero
        ctx->r3 = ctx->r10 | 0;
            goto L_80073A44;
    }
    // 0x80073A64: or          $v1, $t2, $zero
    ctx->r3 = ctx->r10 | 0;
    // 0x80073A68: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073A6C: jal         0x80072E28
    // 0x80073A70: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    func_80072E28(rdram, ctx);
        goto after_10;
    // 0x80073A70: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    after_10:
    // 0x80073A74: lw          $s2, 0x54($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X54);
    // 0x80073A78: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073A7C: addiu       $s2, $s2, 0xC0
    ctx->r18 = ADD32(ctx->r18, 0XC0);
    // 0x80073A80: sw          $s2, 0x41EC($at)
    MEM_W(0X41EC, ctx->r1) = ctx->r18;
    // 0x80073A84: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073A88: sw          $zero, 0x41F0($at)
    MEM_W(0X41F0, ctx->r1) = 0;
    // 0x80073A8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073A90: addiu       $t3, $zero, 0x80
    ctx->r11 = ADD32(0, 0X80);
    // 0x80073A94: sw          $t3, 0x41F4($at)
    MEM_W(0X41F4, ctx->r1) = ctx->r11;
    // 0x80073A98: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073A9C: jal         0x80072E28
    // 0x80073AA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80072E28(rdram, ctx);
        goto after_11;
    // 0x80073AA0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80073AA4: lw          $t4, 0x48($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X48);
    // 0x80073AA8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80073AAC: blez        $t4, L_80073B9C
    if (SIGNED(ctx->r12) <= 0) {
        // 0x80073AB0: nop
    
            goto L_80073B9C;
    }
    // 0x80073AB0: nop

L_80073AB4:
    // 0x80073AB4: jal         0x8006B14C
    // 0x80073AB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_type(rdram, ctx);
        goto after_12;
    // 0x80073AB8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_12:
    // 0x80073ABC: bne         $v0, $zero, L_80073B8C
    if (ctx->r2 != 0) {
        // 0x80073AC0: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_80073B8C;
    }
    // 0x80073AC0: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80073AC4: jal         0x8006B0F8
    // 0x80073AC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    leveltable_vehicle_usable(rdram, ctx);
        goto after_13;
    // 0x80073AC8: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_13:
    // 0x80073ACC: sll         $s3, $v0, 16
    ctx->r19 = S32(ctx->r2 << 16);
    // 0x80073AD0: sra         $t5, $s3, 16
    ctx->r13 = S32(SIGNED(ctx->r19) >> 16);
    // 0x80073AD4: andi        $t9, $v0, 0x1
    ctx->r25 = ctx->r2 & 0X1;
    // 0x80073AD8: beq         $t9, $zero, L_80073B10
    if (ctx->r25 == 0) {
        // 0x80073ADC: or          $s3, $t5, $zero
        ctx->r19 = ctx->r13 | 0;
            goto L_80073B10;
    }
    // 0x80073ADC: or          $s3, $t5, $zero
    ctx->r19 = ctx->r13 | 0;
    // 0x80073AE0: lw          $t8, 0x3C($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X3C);
    // 0x80073AE4: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073AE8: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x80073AEC: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    // 0x80073AF0: jal         0x80072E28
    // 0x80073AF4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_14;
    // 0x80073AF4: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_14:
    // 0x80073AF8: lw          $t1, 0x30($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X30);
    // 0x80073AFC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073B00: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073B04: lhu         $a1, 0x0($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X0);
    // 0x80073B08: jal         0x80072E28
    // 0x80073B0C: nop

    func_80072E28(rdram, ctx);
        goto after_15;
    // 0x80073B0C: nop

    after_15:
L_80073B10:
    // 0x80073B10: andi        $t3, $s3, 0x2
    ctx->r11 = ctx->r19 & 0X2;
    // 0x80073B14: beq         $t3, $zero, L_80073B50
    if (ctx->r11 == 0) {
        // 0x80073B18: andi        $t9, $s3, 0x4
        ctx->r25 = ctx->r19 & 0X4;
            goto L_80073B50;
    }
    // 0x80073B18: andi        $t9, $s3, 0x4
    ctx->r25 = ctx->r19 & 0X4;
    // 0x80073B1C: lw          $t4, 0x40($s4)
    ctx->r12 = MEM_W(ctx->r20, 0X40);
    // 0x80073B20: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073B24: addu        $t5, $t4, $s0
    ctx->r13 = ADD32(ctx->r12, ctx->r16);
    // 0x80073B28: lhu         $a1, 0x0($t5)
    ctx->r5 = MEM_HU(ctx->r13, 0X0);
    // 0x80073B2C: jal         0x80072E28
    // 0x80073B30: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_16;
    // 0x80073B30: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_16:
    // 0x80073B34: lw          $t6, 0x34($s4)
    ctx->r14 = MEM_W(ctx->r20, 0X34);
    // 0x80073B38: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073B3C: addu        $t7, $t6, $s0
    ctx->r15 = ADD32(ctx->r14, ctx->r16);
    // 0x80073B40: lhu         $a1, 0x0($t7)
    ctx->r5 = MEM_HU(ctx->r15, 0X0);
    // 0x80073B44: jal         0x80072E28
    // 0x80073B48: nop

    func_80072E28(rdram, ctx);
        goto after_17;
    // 0x80073B48: nop

    after_17:
    // 0x80073B4C: andi        $t9, $s3, 0x4
    ctx->r25 = ctx->r19 & 0X4;
L_80073B50:
    // 0x80073B50: beq         $t9, $zero, L_80073B8C
    if (ctx->r25 == 0) {
        // 0x80073B54: lw          $t3, 0x48($sp)
        ctx->r11 = MEM_W(ctx->r29, 0X48);
            goto L_80073B8C;
    }
    // 0x80073B54: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
    // 0x80073B58: lw          $t8, 0x44($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X44);
    // 0x80073B5C: sll         $s0, $s1, 1
    ctx->r16 = S32(ctx->r17 << 1);
    // 0x80073B60: addu        $t0, $t8, $s0
    ctx->r8 = ADD32(ctx->r24, ctx->r16);
    // 0x80073B64: lhu         $a1, 0x0($t0)
    ctx->r5 = MEM_HU(ctx->r8, 0X0);
    // 0x80073B68: jal         0x80072E28
    // 0x80073B6C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072E28(rdram, ctx);
        goto after_18;
    // 0x80073B6C: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_18:
    // 0x80073B70: lw          $t1, 0x38($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X38);
    // 0x80073B74: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073B78: addu        $t2, $t1, $s0
    ctx->r10 = ADD32(ctx->r9, ctx->r16);
    // 0x80073B7C: lhu         $a1, 0x0($t2)
    ctx->r5 = MEM_HU(ctx->r10, 0X0);
    // 0x80073B80: jal         0x80072E28
    // 0x80073B84: nop

    func_80072E28(rdram, ctx);
        goto after_19;
    // 0x80073B84: nop

    after_19:
    // 0x80073B88: lw          $t3, 0x48($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X48);
L_80073B8C:
    // 0x80073B8C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80073B90: slt         $at, $s1, $t3
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x80073B94: bne         $at, $zero, L_80073AB4
    if (ctx->r1 != 0) {
        // 0x80073B98: nop
    
            goto L_80073AB4;
    }
    // 0x80073B98: nop

L_80073B9C:
    // 0x80073B9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073BA0: sw          $s2, 0x41EC($at)
    MEM_W(0X41EC, ctx->r1) = ctx->r18;
    // 0x80073BA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073BA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80073BAC: lw          $a0, 0x41EC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X41EC);
    // 0x80073BB0: sw          $zero, 0x41F0($at)
    MEM_W(0X41F0, ctx->r1) = 0;
    // 0x80073BB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80073BB8: addiu       $t4, $zero, 0x80
    ctx->r12 = ADD32(0, 0X80);
    // 0x80073BBC: sw          $t4, 0x41F4($at)
    MEM_W(0X41F4, ctx->r1) = ctx->r12;
    // 0x80073BC0: addiu       $a1, $a0, 0x2
    ctx->r5 = ADD32(ctx->r4, 0X2);
    // 0x80073BC4: lbu         $v1, 0x0($a1)
    ctx->r3 = MEM_BU(ctx->r5, 0X0);
    // 0x80073BC8: lbu         $t7, 0x1($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X1);
    // 0x80073BCC: addiu       $t6, $v1, 0x5
    ctx->r14 = ADD32(ctx->r3, 0X5);
    // 0x80073BD0: addu        $v1, $t6, $t7
    ctx->r3 = ADD32(ctx->r14, ctx->r15);
    // 0x80073BD4: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x80073BD8: addiu       $v0, $a0, 0x4
    ctx->r2 = ADD32(ctx->r4, 0X4);
    // 0x80073BDC: addiu       $a0, $zero, 0xC0
    ctx->r4 = ADD32(0, 0XC0);
    // 0x80073BE0: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x80073BE4: addiu       $s1, $zero, 0x4
    ctx->r17 = ADD32(0, 0X4);
L_80073BE8:
    // 0x80073BE8: lbu         $t0, 0x0($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X0);
    // 0x80073BEC: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x80073BF0: lbu         $t6, 0x2($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X2);
    // 0x80073BF4: addu        $t2, $v1, $t0
    ctx->r10 = ADD32(ctx->r3, ctx->r8);
    // 0x80073BF8: lbu         $t8, 0x3($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X3);
    // 0x80073BFC: addu        $t5, $t2, $t3
    ctx->r13 = ADD32(ctx->r10, ctx->r11);
    // 0x80073C00: addu        $t9, $t5, $t6
    ctx->r25 = ADD32(ctx->r13, ctx->r14);
    // 0x80073C04: addu        $v1, $t9, $t8
    ctx->r3 = ADD32(ctx->r25, ctx->r24);
    // 0x80073C08: sll         $t0, $v1, 16
    ctx->r8 = S32(ctx->r3 << 16);
    // 0x80073C0C: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80073C10: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
    // 0x80073C14: or          $v1, $t1, $zero
    ctx->r3 = ctx->r9 | 0;
    // 0x80073C18: bne         $s1, $a0, L_80073BE8
    if (ctx->r17 != ctx->r4) {
        // 0x80073C1C: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_80073BE8;
    }
    // 0x80073C1C: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x80073C20: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x80073C24: jal         0x80072E28
    // 0x80073C28: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    func_80072E28(rdram, ctx);
        goto after_20;
    // 0x80073C28: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_20:
    // 0x80073C2C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80073C30: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80073C34: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80073C38: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80073C3C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80073C40: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80073C44: jr          $ra
    // 0x80073C48: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x80073C48: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void alMainBusNew(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065084: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80065088: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8006508C: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80065090: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80065094: lui         $a2, 0x800D
    ctx->r6 = S32(0X800D << 16);
    // 0x80065098: lui         $a1, 0x800D
    ctx->r5 = S32(0X800D << 16);
    // 0x8006509C: addiu       $a1, $a1, -0x3C40
    ctx->r5 = ADD32(ctx->r5, -0X3C40);
    // 0x800650A0: addiu       $a2, $a2, -0x3C70
    ctx->r6 = ADD32(ctx->r6, -0X3C70);
    // 0x800650A4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800650A8: jal         0x800CA0B0
    // 0x800650AC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    alFilterNew(rdram, ctx);
        goto after_0;
    // 0x800650AC: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_0:
    // 0x800650B0: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800650B4: nop

    // 0x800650B8: sw          $zero, 0x14($a0)
    MEM_W(0X14, ctx->r4) = 0;
    // 0x800650BC: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800650C0: nop

    // 0x800650C4: sw          $t6, 0x18($a0)
    MEM_W(0X18, ctx->r4) = ctx->r14;
    // 0x800650C8: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x800650CC: nop

    // 0x800650D0: sw          $t7, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->r15;
    // 0x800650D4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800650D8: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800650DC: jr          $ra
    // 0x800650E0: nop

    return;
    // 0x800650E0: nop

;}
RECOMP_FUNC void handle_car_velocity_control(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80053664: lwc1        $f4, 0xB4($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XB4);
    // 0x80053668: mtc1        $zero, $f7
    ctx->f_odd[(7 - 1) * 2] = 0;
    // 0x8005366C: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80053670: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x80053674: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x80053678: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005367C: bc1f        L_8005369C
    if (!c1cs) {
        // 0x80053680: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8005369C;
    }
    // 0x80053680: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80053684: lwc1        $f9, 0x6768($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6768);
    // 0x80053688: lwc1        $f8, 0x676C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X676C);
    // 0x8005368C: nop

    // 0x80053690: sub.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d - ctx->f8.d;
    // 0x80053694: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80053698: swc1        $f16, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f16.u32l;
L_8005369C:
    // 0x8005369C: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x800536A0: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800536A4: andi        $t6, $v0, 0x8000
    ctx->r14 = ctx->r2 & 0X8000;
    // 0x800536A8: beq         $t6, $zero, L_800536C8
    if (ctx->r14 == 0) {
        // 0x800536AC: andi        $t7, $v0, 0x4000
        ctx->r15 = ctx->r2 & 0X4000;
            goto L_800536C8;
    }
    // 0x800536AC: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
    // 0x800536B0: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800536B4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800536B8: swc1        $f18, 0xB4($a0)
    MEM_W(0XB4, ctx->r4) = ctx->f18.u32l;
    // 0x800536BC: lw          $v0, -0x2AD8($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AD8);
    // 0x800536C0: nop

    // 0x800536C4: andi        $t7, $v0, 0x4000
    ctx->r15 = ctx->r2 & 0X4000;
L_800536C8:
    // 0x800536C8: beq         $t7, $zero, L_80053710
    if (ctx->r15 == 0) {
        // 0x800536CC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_80053710;
    }
    // 0x800536CC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800536D0: lwc1        $f4, 0xB8($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XB8);
    // 0x800536D4: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x800536D8: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x800536DC: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800536E0: cvt.d.s     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f0.d = CVT_D_S(ctx->f4.fl);
    // 0x800536E4: c.lt.d      $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f0.d < ctx->f6.d;
    // 0x800536E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800536EC: bc1f        L_80053748
    if (!c1cs) {
        // 0x800536F0: nop
    
            goto L_80053748;
    }
    // 0x800536F0: nop

    // 0x800536F4: lwc1        $f9, 0x6770($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6770);
    // 0x800536F8: lwc1        $f8, 0x6774($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6774);
    // 0x800536FC: nop

    // 0x80053700: add.d       $f10, $f0, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f0.d + ctx->f8.d;
    // 0x80053704: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x80053708: jr          $ra
    // 0x8005370C: swc1        $f16, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f16.u32l;
    return;
    // 0x8005370C: swc1        $f16, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f16.u32l;
L_80053710:
    // 0x80053710: lwc1        $f18, 0xB8($a0)
    ctx->f18.u32l = MEM_W(ctx->r4, 0XB8);
    // 0x80053714: lwc1        $f5, 0x6778($at)
    ctx->f_odd[(5 - 1) * 2] = MEM_W(ctx->r1, 0X6778);
    // 0x80053718: lwc1        $f4, 0x677C($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X677C);
    // 0x8005371C: cvt.d.s     $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f0.d = CVT_D_S(ctx->f18.fl);
    // 0x80053720: c.lt.d      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.d < ctx->f0.d;
    // 0x80053724: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80053728: bc1f        L_80053748
    if (!c1cs) {
        // 0x8005372C: nop
    
            goto L_80053748;
    }
    // 0x8005372C: nop

    // 0x80053730: lwc1        $f7, 0x6780($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6780);
    // 0x80053734: lwc1        $f6, 0x6784($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6784);
    // 0x80053738: nop

    // 0x8005373C: sub.d       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f0.d - ctx->f6.d;
    // 0x80053740: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x80053744: swc1        $f10, 0xB8($a0)
    MEM_W(0XB8, ctx->r4) = ctx->f10.u32l;
L_80053748:
    // 0x80053748: jr          $ra
    // 0x8005374C: nop

    return;
    // 0x8005374C: nop

;}
RECOMP_FUNC void debug_text_print(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B5F78: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B5F7C: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x800B5F80: sw          $s3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r19;
    // 0x800B5F84: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800B5F88: sw          $s4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r20;
    // 0x800B5F8C: sw          $s2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r18;
    // 0x800B5F90: sw          $s1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r17;
    // 0x800B5F94: jal         0x80078054
    // 0x800B5F98: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    rdp_init(rdram, ctx);
        goto after_0;
    // 0x800B5F98: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    after_0:
    // 0x800B5F9C: jal         0x8007A520
    // 0x800B5FA0: nop

    fb_size(rdram, ctx);
        goto after_1;
    // 0x800B5FA0: nop

    after_1:
    // 0x800B5FA4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800B5FA8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B5FAC: addiu       $a1, $a1, 0x7CD0
    ctx->r5 = ADD32(ctx->r5, 0X7CD0);
    // 0x800B5FB0: addiu       $a0, $a0, 0x7CD2
    ctx->r4 = ADD32(ctx->r4, 0X7CD2);
    // 0x800B5FB4: srl         $t6, $v0, 16
    ctx->r14 = S32(U32(ctx->r2) >> 16);
    // 0x800B5FB8: sh          $t6, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r14;
    // 0x800B5FBC: sh          $v0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r2;
    // 0x800B5FC0: lw          $v1, 0x0($s3)
    ctx->r3 = MEM_W(ctx->r19, 0X0);
    // 0x800B5FC4: lui         $t9, 0xED00
    ctx->r25 = S32(0XED00 << 16);
    // 0x800B5FC8: addiu       $t8, $v1, 0x8
    ctx->r24 = ADD32(ctx->r3, 0X8);
    // 0x800B5FCC: sw          $t8, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r24;
    // 0x800B5FD0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800B5FD4: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x800B5FD8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800B5FDC: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800B5FE0: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800B5FE4: bgez        $t0, L_800B5FFC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800B5FE8: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800B5FFC;
    }
    // 0x800B5FE8: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B5FEC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B5FF0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B5FF4: nop

    // 0x800B5FF8: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_800B5FFC:
    // 0x800B5FFC: mul.s       $f10, $f6, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800B6000: lhu         $t5, 0x0($a0)
    ctx->r13 = MEM_HU(ctx->r4, 0X0);
    // 0x800B6004: nop

    // 0x800B6008: mtc1        $t5, $f18
    ctx->f18.u32l = ctx->r13;
    // 0x800B600C: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x800B6010: nop

    // 0x800B6014: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x800B6018: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B601C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B6020: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800B6024: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x800B6028: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x800B602C: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x800B6030: andi        $t3, $t2, 0xFFF
    ctx->r11 = ctx->r10 & 0XFFF;
    // 0x800B6034: sll         $t4, $t3, 12
    ctx->r12 = S32(ctx->r11 << 12);
    // 0x800B6038: bgez        $t5, L_800B604C
    if (SIGNED(ctx->r13) >= 0) {
        // 0x800B603C: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800B604C;
    }
    // 0x800B603C: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800B6040: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800B6044: nop

    // 0x800B6048: add.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f8.fl;
L_800B604C:
    // 0x800B604C: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x800B6050: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800B6054: nop

    // 0x800B6058: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800B605C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800B6060: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800B6064: nop

    // 0x800B6068: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800B606C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800B6070: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800B6074: andi        $t8, $t7, 0xFFF
    ctx->r24 = ctx->r15 & 0XFFF;
    // 0x800B6078: or          $t9, $t4, $t8
    ctx->r25 = ctx->r12 | ctx->r24;
    // 0x800B607C: jal         0x800B6E50
    // 0x800B6080: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    debug_text_bounds(rdram, ctx);
        goto after_2;
    // 0x800B6080: sw          $t9, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r25;
    after_2:
    // 0x800B6084: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x800B6088: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B608C: addiu       $t0, $s1, 0x8
    ctx->r8 = ADD32(ctx->r17, 0X8);
    // 0x800B6090: sw          $t0, 0x0($s3)
    MEM_W(0X0, ctx->r19) = ctx->r8;
    // 0x800B6094: addiu       $t2, $t2, 0x2FB8
    ctx->r10 = ADD32(ctx->r10, 0X2FB8);
    // 0x800B6098: lui         $t1, 0x600
    ctx->r9 = S32(0X600 << 16);
    // 0x800B609C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800B60A0: addiu       $s0, $s0, 0x7CD8
    ctx->r16 = ADD32(ctx->r16, 0X7CD8);
    // 0x800B60A4: sw          $t1, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r9;
    // 0x800B60A8: jal         0x800B6EE0
    // 0x800B60AC: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    debug_text_origin(rdram, ctx);
        goto after_3;
    // 0x800B60AC: sw          $t2, 0x4($s1)
    MEM_W(0X4, ctx->r17) = ctx->r10;
    after_3:
    // 0x800B60B0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800B60B4: addiu       $s4, $s4, 0x7CCC
    ctx->r20 = ADD32(ctx->r20, 0X7CCC);
    // 0x800B60B8: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
    // 0x800B60BC: sw          $t3, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r11;
    // 0x800B60C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B60C4: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800B60C8: lhu         $a3, 0x7CAC($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X7CAC);
    // 0x800B60CC: sw          $zero, 0x7CB4($at)
    MEM_W(0X7CB4, ctx->r1) = 0;
    // 0x800B60D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B60D4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B60D8: lhu         $v0, 0x7CAE($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7CAE);
    // 0x800B60DC: sh          $a3, 0x7CB0($at)
    MEM_H(0X7CB0, ctx->r1) = ctx->r7;
    // 0x800B60E0: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800B60E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B60E8: addiu       $s2, $s2, -0x7A28
    ctx->r18 = ADD32(ctx->r18, -0X7A28);
    // 0x800B60EC: sh          $v0, 0x7CB2($at)
    MEM_H(0X7CB2, ctx->r1) = ctx->r2;
    // 0x800B60F0: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x800B60F4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800B60F8: addiu       $t5, $t5, 0x7CD8
    ctx->r13 = ADD32(ctx->r13, 0X7CD8);
    // 0x800B60FC: beq         $t5, $t6, L_800B6140
    if (ctx->r13 == ctx->r14) {
        // 0x800B6100: lui         $s1, 0x8012
        ctx->r17 = S32(0X8012 << 16);
            goto L_800B6140;
    }
    // 0x800B6100: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800B6104: addiu       $s1, $s1, 0x7CB8
    ctx->r17 = ADD32(ctx->r17, 0X7CB8);
L_800B6108:
    // 0x800B6108: sw          $zero, 0x0($s1)
    MEM_W(0X0, ctx->r17) = 0;
    // 0x800B610C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B6110: jal         0x800B653C
    // 0x800B6114: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    debug_text_parse(rdram, ctx);
        goto after_4;
    // 0x800B6114: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_4:
    // 0x800B6118: lw          $t7, 0x0($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X0);
    // 0x800B611C: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800B6120: bne         $s0, $t7, L_800B6108
    if (ctx->r16 != ctx->r15) {
        // 0x800B6124: nop
    
            goto L_800B6108;
    }
    // 0x800B6124: nop

    // 0x800B6128: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800B612C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800B6130: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800B6134: lhu         $v0, 0x7CAE($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X7CAE);
    // 0x800B6138: lhu         $a3, 0x7CAC($a3)
    ctx->r7 = MEM_HU(ctx->r7, 0X7CAC);
    // 0x800B613C: addiu       $s0, $s0, 0x7CD8
    ctx->r16 = ADD32(ctx->r16, 0X7CD8);
L_800B6140:
    // 0x800B6140: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800B6144: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800B6148: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800B614C: lhu         $a2, 0x7CB2($a2)
    ctx->r6 = MEM_HU(ctx->r6, 0X7CB2);
    // 0x800B6150: lhu         $a1, 0x7CB0($a1)
    ctx->r5 = MEM_HU(ctx->r5, 0X7CB0);
    // 0x800B6154: addiu       $t4, $v0, 0xA
    ctx->r12 = ADD32(ctx->r2, 0XA);
    // 0x800B6158: addiu       $s1, $s1, 0x7CB8
    ctx->r17 = ADD32(ctx->r17, 0X7CB8);
    // 0x800B615C: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800B6160: jal         0x800B695C
    // 0x800B6164: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    debug_text_background(rdram, ctx);
        goto after_5;
    // 0x800B6164: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_5:
    // 0x800B6168: jal         0x800B6EE0
    // 0x800B616C: nop

    debug_text_origin(rdram, ctx);
        goto after_6;
    // 0x800B616C: nop

    after_6:
    // 0x800B6170: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x800B6174: sw          $t8, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r24;
    // 0x800B6178: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B617C: sw          $zero, 0x7CB4($at)
    MEM_W(0X7CB4, ctx->r1) = 0;
    // 0x800B6180: lw          $t0, 0x0($s2)
    ctx->r8 = MEM_W(ctx->r18, 0X0);
    // 0x800B6184: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800B6188: addiu       $t9, $t9, 0x7CD8
    ctx->r25 = ADD32(ctx->r25, 0X7CD8);
    // 0x800B618C: beq         $t9, $t0, L_800B61B4
    if (ctx->r25 == ctx->r8) {
        // 0x800B6190: addiu       $s4, $zero, 0x1
        ctx->r20 = ADD32(0, 0X1);
            goto L_800B61B4;
    }
    // 0x800B6190: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
L_800B6194:
    // 0x800B6194: sw          $s4, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r20;
    // 0x800B6198: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x800B619C: jal         0x800B653C
    // 0x800B61A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    debug_text_parse(rdram, ctx);
        goto after_7;
    // 0x800B61A0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    after_7:
    // 0x800B61A4: lw          $t1, 0x0($s2)
    ctx->r9 = MEM_W(ctx->r18, 0X0);
    // 0x800B61A8: addu        $s0, $s0, $v0
    ctx->r16 = ADD32(ctx->r16, ctx->r2);
    // 0x800B61AC: bne         $s0, $t1, L_800B6194
    if (ctx->r16 != ctx->r9) {
        // 0x800B61B0: nop
    
            goto L_800B6194;
    }
    // 0x800B61B0: nop

L_800B61B4:
    // 0x800B61B4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800B61B8: addiu       $t2, $t2, 0x7CD8
    ctx->r10 = ADD32(ctx->r10, 0X7CD8);
    // 0x800B61BC: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x800B61C0: sw          $t2, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r10;
    // 0x800B61C4: lw          $s2, 0x28($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X28);
    // 0x800B61C8: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x800B61CC: lw          $s1, 0x24($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X24);
    // 0x800B61D0: lw          $s3, 0x2C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X2C);
    // 0x800B61D4: lw          $s4, 0x30($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X30);
    // 0x800B61D8: jr          $ra
    // 0x800B61DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B61DC: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void transition_render_circle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2274: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800C2278: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C227C: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800C2280: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800C2284: jal         0x8007B3D0
    // 0x800C2288: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    rendermode_reset(rdram, ctx);
        goto after_0;
    // 0x800C2288: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    after_0:
    // 0x800C228C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800C2290: lw          $v1, 0x31D0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X31D0);
    // 0x800C2294: lw          $t6, 0x18($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X18);
    // 0x800C2298: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x800C229C: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800C22A0: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x800C22A4: addu        $a3, $a3, $t7
    ctx->r7 = ADD32(ctx->r7, ctx->r15);
    // 0x800C22A8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800C22AC: lw          $a3, 0x31C0($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X31C0);
    // 0x800C22B0: addu        $t0, $t0, $t7
    ctx->r8 = ADD32(ctx->r8, ctx->r15);
    // 0x800C22B4: lw          $t0, 0x31C8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X31C8);
    // 0x800C22B8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C22BC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800C22C0: addiu       $t9, $t9, 0x3648
    ctx->r25 = ADD32(ctx->r25, 0X3648);
    // 0x800C22C4: lui         $t8, 0x600
    ctx->r24 = S32(0X600 << 16);
    // 0x800C22C8: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800C22CC: sw          $t9, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r25;
    // 0x800C22D0: lui         $a2, 0x8000
    ctx->r6 = S32(0X8000 << 16);
    // 0x800C22D4: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C22D8: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C22DC: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C22E0: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C22E4: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800C22E8: lui         $t1, 0x400
    ctx->r9 = S32(0X400 << 16);
    // 0x800C22EC: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C22F0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C22F4: addiu       $a3, $a3, 0xB4
    ctx->r7 = ADD32(ctx->r7, 0XB4);
    // 0x800C22F8: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C22FC: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C2300: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C2304: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C2308: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x800C230C: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C2310: lui         $t2, 0x5F0
    ctx->r10 = S32(0X5F0 << 16);
    // 0x800C2314: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C2318: ori         $t2, $t2, 0x100
    ctx->r10 = ctx->r10 | 0X100;
    // 0x800C231C: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C2320: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C2324: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C2328: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800C232C: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800C2330: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800C2334: sw          $a0, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r4;
    // 0x800C2338: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C233C: addiu       $a3, $a3, 0xB4
    ctx->r7 = ADD32(ctx->r7, 0XB4);
    // 0x800C2340: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C2344: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C2348: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800C234C: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800C2350: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C2354: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x800C2358: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C235C: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C2360: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C2364: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800C2368: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800C236C: addiu       $v1, $a1, 0x8
    ctx->r3 = ADD32(ctx->r5, 0X8);
    // 0x800C2370: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C2374: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C2378: addiu       $a3, $a3, 0xB4
    ctx->r7 = ADD32(ctx->r7, 0XB4);
    // 0x800C237C: addu        $a0, $a3, $a2
    ctx->r4 = ADD32(ctx->r7, ctx->r6);
    // 0x800C2380: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C2384: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C2388: andi        $t3, $a0, 0x6
    ctx->r11 = ctx->r4 & 0X6;
    // 0x800C238C: ori         $t4, $t3, 0x88
    ctx->r12 = ctx->r11 | 0X88;
    // 0x800C2390: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C2394: addiu       $v0, $v1, 0x8
    ctx->r2 = ADD32(ctx->r3, 0X8);
    // 0x800C2398: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x800C239C: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C23A0: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800C23A4: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x800C23A8: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800C23AC: addiu       $v1, $v0, 0x8
    ctx->r3 = ADD32(ctx->r2, 0X8);
    // 0x800C23B0: or          $t7, $t6, $t1
    ctx->r15 = ctx->r14 | ctx->r9;
    // 0x800C23B4: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800C23B8: ori         $t8, $t7, 0x14C
    ctx->r24 = ctx->r15 | 0X14C;
    // 0x800C23BC: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800C23C0: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800C23C4: addiu       $a1, $v1, 0x8
    ctx->r5 = ADD32(ctx->r3, 0X8);
    // 0x800C23C8: addiu       $t0, $t0, 0x100
    ctx->r8 = ADD32(ctx->r8, 0X100);
    // 0x800C23CC: addu        $t9, $t0, $a2
    ctx->r25 = ADD32(ctx->r8, ctx->r6);
    // 0x800C23D0: sw          $t9, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->r25;
    // 0x800C23D4: sw          $t2, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r10;
    // 0x800C23D8: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x800C23DC: addiu       $v0, $a1, 0x8
    ctx->r2 = ADD32(ctx->r5, 0X8);
    // 0x800C23E0: jal         0x8007B3D0
    // 0x800C23E4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    rendermode_reset(rdram, ctx);
        goto after_1;
    // 0x800C23E4: sw          $v0, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r2;
    after_1:
    // 0x800C23E8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C23EC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800C23F0: jr          $ra
    // 0x800C23F4: nop

    return;
    // 0x800C23F4: nop

;}
RECOMP_FUNC void play_tt_voice_clip(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80036BCC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80036BD0: addiu       $a3, $a3, -0x2B28
    ctx->r7 = ADD32(ctx->r7, -0X2B28);
    // 0x80036BD4: lw          $a2, 0x0($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X0);
    // 0x80036BD8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80036BDC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80036BE0: beq         $a2, $zero, L_80036C0C
    if (ctx->r6 == 0) {
        // 0x80036BE4: sw          $a0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r4;
            goto L_80036C0C;
    }
    // 0x80036BE4: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80036BE8: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x80036BEC: beq         $t6, $zero, L_80036C0C
    if (ctx->r14 == 0) {
        // 0x80036BF0: nop
    
            goto L_80036C0C;
    }
    // 0x80036BF0: nop

    // 0x80036BF4: jal         0x8000488C
    // 0x80036BF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    sndp_stop(rdram, ctx);
        goto after_0;
    // 0x80036BF8: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    after_0:
    // 0x80036BFC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80036C00: addiu       $a3, $a3, -0x2B28
    ctx->r7 = ADD32(ctx->r7, -0X2B28);
    // 0x80036C04: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x80036C08: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80036C0C:
    // 0x80036C0C: bne         $a2, $zero, L_80036C24
    if (ctx->r6 != 0) {
        // 0x80036C10: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80036C24;
    }
    // 0x80036C10: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80036C14: lhu         $a0, 0x1A($sp)
    ctx->r4 = MEM_HU(ctx->r29, 0X1A);
    // 0x80036C18: jal         0x80001D04
    // 0x80036C1C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    sound_play(rdram, ctx);
        goto after_1;
    // 0x80036C1C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_1:
    // 0x80036C20: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80036C24:
    // 0x80036C24: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80036C28: jr          $ra
    // 0x80036C2C: nop

    return;
    // 0x80036C2C: nop

;}
RECOMP_FUNC void copy_viewport_background_size_to_coords(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066BA8: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066BAC: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066BB0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066BB4: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066BB8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066BBC: addiu       $t7, $t7, -0x2F9C
    ctx->r15 = ADD32(ctx->r15, -0X2F9C);
    // 0x80066BC0: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80066BC4: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066BC8: lw          $t8, 0x20($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X20);
    // 0x80066BCC: nop

    // 0x80066BD0: sw          $t8, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r24;
    // 0x80066BD4: lw          $t9, 0x28($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X28);
    // 0x80066BD8: nop

    // 0x80066BDC: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80066BE0: lw          $t0, 0x24($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X24);
    // 0x80066BE4: nop

    // 0x80066BE8: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80066BEC: lw          $t2, 0x10($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X10);
    // 0x80066BF0: lw          $t1, 0x2C($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X2C);
    // 0x80066BF4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80066BF8: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x80066BFC: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x80066C00: lw          $t5, 0x0($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X0);
    // 0x80066C04: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x80066C08: or          $t4, $t1, $t3
    ctx->r12 = ctx->r9 | ctx->r11;
    // 0x80066C0C: or          $t6, $t4, $t5
    ctx->r14 = ctx->r12 | ctx->r13;
    // 0x80066C10: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x80066C14: bne         $t8, $zero, L_80066C24
    if (ctx->r24 != 0) {
        // 0x80066C18: nop
    
            goto L_80066C24;
    }
    // 0x80066C18: nop

    // 0x80066C1C: jr          $ra
    // 0x80066C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80066C20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80066C24:
    // 0x80066C24: jr          $ra
    // 0x80066C28: nop

    return;
    // 0x80066C28: nop

;}
RECOMP_FUNC void obj_loop_infopoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800388D4: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800388D8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800388DC: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800388E0: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800388E4: lw          $t6, 0x7C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X7C);
    // 0x800388E8: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800388EC: bne         $t6, $zero, L_80038908
    if (ctx->r14 != 0) {
        // 0x800388F0: nop
    
            goto L_80038908;
    }
    // 0x800388F0: nop

    // 0x800388F4: lh          $t7, 0x6($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X6);
    // 0x800388F8: nop

    // 0x800388FC: ori         $t8, $t7, 0x4000
    ctx->r24 = ctx->r15 | 0X4000;
    // 0x80038900: b           L_80038918
    // 0x80038904: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
        goto L_80038918;
    // 0x80038904: sh          $t8, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r24;
L_80038908:
    // 0x80038908: lh          $t9, 0x6($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X6);
    // 0x8003890C: nop

    // 0x80038910: andi        $t0, $t9, 0xBFFF
    ctx->r8 = ctx->r25 & 0XBFFF;
    // 0x80038914: sh          $t0, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r8;
L_80038918:
    // 0x80038918: lw          $v0, 0x4C($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X4C);
    // 0x8003891C: lw          $t2, 0x78($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X78);
    // 0x80038920: lbu         $t1, 0x13($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X13);
    // 0x80038924: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80038928: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x8003892C: slt         $at, $t1, $t4
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x80038930: beq         $at, $zero, L_800389A0
    if (ctx->r1 == 0) {
        // 0x80038934: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389A0;
    }
    // 0x80038934: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038938: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003893C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80038940: lw          $t5, 0x40($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X40);
    // 0x80038944: nop

    // 0x80038948: lb          $t6, 0x54($t5)
    ctx->r14 = MEM_B(ctx->r13, 0X54);
    // 0x8003894C: nop

    // 0x80038950: bne         $t6, $at, L_800389A0
    if (ctx->r14 != ctx->r1) {
        // 0x80038954: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389A0;
    }
    // 0x80038954: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038958: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x8003895C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80038960: lh          $a0, 0x0($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X0);
    // 0x80038964: nop

    // 0x80038968: beq         $a0, $at, L_800389A0
    if (ctx->r4 == ctx->r1) {
        // 0x8003896C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389A0;
    }
    // 0x8003896C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038970: jal         0x8006A554
    // 0x80038974: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    input_pressed(rdram, ctx);
        goto after_0;
    // 0x80038974: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x80038978: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003897C: andi        $t7, $v0, 0x2000
    ctx->r15 = ctx->r2 & 0X2000;
    // 0x80038980: beq         $t7, $zero, L_800389A0
    if (ctx->r15 == 0) {
        // 0x80038984: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800389A0;
    }
    // 0x80038984: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038988: lw          $a0, 0x78($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X78);
    // 0x8003898C: nop

    // 0x80038990: andi        $t8, $a0, 0xFF
    ctx->r24 = ctx->r4 & 0XFF;
    // 0x80038994: jal         0x800C31EC
    // 0x80038998: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    set_current_text(rdram, ctx);
        goto after_1;
    // 0x80038998: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_1:
    // 0x8003899C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800389A0:
    // 0x800389A0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800389A4: jr          $ra
    // 0x800389A8: nop

    return;
    // 0x800389A8: nop

;}
RECOMP_FUNC void tex_asset_size(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007C57C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007C580: addiu       $t6, $zero, 0x4
    ctx->r14 = ADD32(0, 0X4);
    // 0x8007C584: andi        $t7, $a0, 0x8000
    ctx->r15 = ctx->r4 & 0X8000;
    // 0x8007C588: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007C58C: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8007C590: beq         $t7, $zero, L_8007C5AC
    if (ctx->r15 == 0) {
        // 0x8007C594: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007C5AC;
    }
    // 0x8007C594: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007C598: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8007C59C: andi        $t9, $a0, 0x7FFF
    ctx->r25 = ctx->r4 & 0X7FFF;
    // 0x8007C5A0: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8007C5A4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007C5A8: or          $a0, $t9, $zero
    ctx->r4 = ctx->r25 | 0;
L_8007C5AC:
    // 0x8007C5AC: sll         $v1, $v0, 2
    ctx->r3 = S32(ctx->r2 << 2);
    // 0x8007C5B0: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007C5B4: addu        $t0, $t0, $v1
    ctx->r8 = ADD32(ctx->r8, ctx->r3);
    // 0x8007C5B8: lw          $t0, 0x6338($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X6338);
    // 0x8007C5BC: nop

    // 0x8007C5C0: slt         $at, $a0, $t0
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8007C5C4: beq         $at, $zero, L_8007C5D4
    if (ctx->r1 == 0) {
        // 0x8007C5C8: nop
    
            goto L_8007C5D4;
    }
    // 0x8007C5C8: nop

    // 0x8007C5CC: bgez        $a0, L_8007C5DC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8007C5D0: lui         $t1, 0x8012
        ctx->r9 = S32(0X8012 << 16);
            goto L_8007C5DC;
    }
    // 0x8007C5D0: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
L_8007C5D4:
    // 0x8007C5D4: b           L_8007C650
    // 0x8007C5D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8007C650;
    // 0x8007C5D8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8007C5DC:
    // 0x8007C5DC: addu        $t1, $t1, $v1
    ctx->r9 = ADD32(ctx->r9, ctx->r3);
    // 0x8007C5E0: lw          $t1, 0x6320($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6320);
    // 0x8007C5E4: sll         $t2, $a0, 2
    ctx->r10 = S32(ctx->r4 << 2);
    // 0x8007C5E8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007C5EC: lw          $a1, 0x636C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X636C);
    // 0x8007C5F0: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8007C5F4: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8007C5F8: lw          $t3, 0x4($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X4);
    // 0x8007C5FC: lbu         $t4, 0x1D($a1)
    ctx->r12 = MEM_BU(ctx->r5, 0X1D);
    // 0x8007C600: lw          $a0, 0x18($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X18);
    // 0x8007C604: beq         $t4, $zero, L_8007C630
    if (ctx->r12 == 0) {
        // 0x8007C608: subu        $a3, $t3, $a2
        ctx->r7 = SUB32(ctx->r11, ctx->r6);
            goto L_8007C630;
    }
    // 0x8007C608: subu        $a3, $t3, $a2
    ctx->r7 = SUB32(ctx->r11, ctx->r6);
    // 0x8007C60C: jal         0x80076E68
    // 0x8007C610: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    asset_load(rdram, ctx);
        goto after_0;
    // 0x8007C610: addiu       $a3, $zero, 0x28
    ctx->r7 = ADD32(0, 0X28);
    after_0:
    // 0x8007C614: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8007C618: lw          $v1, 0x636C($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X636C);
    // 0x8007C61C: jal         0x800C61AC
    // 0x8007C620: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    byteswap32(rdram, ctx);
        goto after_1;
    // 0x8007C620: addiu       $a0, $v1, 0x20
    ctx->r4 = ADD32(ctx->r3, 0X20);
    after_1:
    // 0x8007C624: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007C628: lw          $a1, 0x636C($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X636C);
    // 0x8007C62C: or          $a3, $v0, $zero
    ctx->r7 = ctx->r2 | 0;
L_8007C630:
    // 0x8007C630: lhu         $v1, 0x12($a1)
    ctx->r3 = MEM_HU(ctx->r5, 0X12);
    // 0x8007C634: nop

    // 0x8007C638: sra         $t5, $v1, 8
    ctx->r13 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8007C63C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x8007C640: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8007C644: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x8007C648: sll         $t7, $t7, 5
    ctx->r15 = S32(ctx->r15 << 5);
    // 0x8007C64C: addu        $v0, $t7, $a3
    ctx->r2 = ADD32(ctx->r15, ctx->r7);
L_8007C650:
    // 0x8007C650: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007C654: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007C658: jr          $ra
    // 0x8007C65C: nop

    return;
    // 0x8007C65C: nop

;}
RECOMP_FUNC void obj_loop_goldenballoon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B4BC: mtc1        $a1, $f4
    ctx->f4.u32l = ctx->r5;
    // 0x8003B4C0: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8003B4C4: lui         $t7, 0x8000
    ctx->r15 = S32(0X8000 << 16);
    // 0x8003B4C8: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8003B4CC: lw          $t7, 0x300($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X300);
    // 0x8003B4D0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x8003B4D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x8003B4D8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8003B4DC: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x8003B4E0: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x8003B4E4: bne         $t7, $zero, L_8003B504
    if (ctx->r15 != 0) {
        // 0x8003B4E8: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_8003B504;
    }
    // 0x8003B4E8: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x8003B4EC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8003B4F0: lwc1        $f9, 0x6160($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6160);
    // 0x8003B4F4: lwc1        $f8, 0x6164($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6164);
    // 0x8003B4F8: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8003B4FC: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8003B500: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
L_8003B504:
    // 0x8003B504: lui         $t8, 0xA000
    ctx->r24 = S32(0XA000 << 16);
    // 0x8003B508: lui         $t9, 0x240B
    ctx->r25 = S32(0X240B << 16);
    // 0x8003B50C: lui         $at, 0x240B
    ctx->r1 = S32(0X240B << 16);
    // 0x8003B510: ori         $at, $at, 0x17D7
    ctx->r1 = ctx->r1 | 0X17D7;
    // 0x8003B514: b           L_8003B520
    // 0x8003B518: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
        goto L_8003B520;
    // 0x8003B518: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003B51C: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
L_8003B520:
    // 0x8003B520: jal         0x8006EA90
    // 0x8003B524: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8003B524: swc1        $f2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f2.u32l;
    after_0:
    // 0x8003B528: lbu         $t3, 0x49($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X49);
    // 0x8003B52C: lw          $v1, 0x3C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X3C);
    // 0x8003B530: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8003B534: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8003B538: lb          $t0, 0x8($v1)
    ctx->r8 = MEM_B(ctx->r3, 0X8);
    // 0x8003B53C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x8003B540: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8003B544: lui         $t1, 0x1
    ctx->r9 = S32(0X1 << 16);
    // 0x8003B548: sllv        $a1, $t1, $t0
    ctx->r5 = S32(ctx->r9 << (ctx->r8 & 31));
    // 0x8003B54C: and         $t7, $t6, $a1
    ctx->r15 = ctx->r14 & ctx->r5;
    // 0x8003B550: beq         $t7, $zero, L_8003B5A0
    if (ctx->r15 == 0) {
        // 0x8003B554: nop
    
            goto L_8003B5A0;
    }
    // 0x8003B554: nop

    // 0x8003B558: lw          $t8, 0x7C($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X7C);
    // 0x8003B55C: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8003B560: blez        $t8, L_8003B590
    if (SIGNED(ctx->r24) <= 0) {
        // 0x8003B564: nop
    
            goto L_8003B590;
    }
    // 0x8003B564: nop

    // 0x8003B568: sw          $t9, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r25;
    // 0x8003B56C: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8003B570: jal         0x800AFC3C
    // 0x8003B574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_1;
    // 0x8003B574: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_1:
    // 0x8003B578: lw          $t1, 0x7C($s1)
    ctx->r9 = MEM_W(ctx->r17, 0X7C);
    // 0x8003B57C: lw          $t0, 0x54($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X54);
    // 0x8003B580: nop

    // 0x8003B584: subu        $t3, $t1, $t0
    ctx->r11 = SUB32(ctx->r9, ctx->r8);
    // 0x8003B588: b           L_8003B7B8
    // 0x8003B58C: sw          $t3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r11;
        goto L_8003B7B8;
    // 0x8003B58C: sw          $t3, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r11;
L_8003B590:
    // 0x8003B590: jal         0x8000FFB8
    // 0x8003B594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_2;
    // 0x8003B594: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_2:
    // 0x8003B598: b           L_8003B7BC
    // 0x8003B59C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_8003B7BC;
    // 0x8003B59C: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003B5A0:
    // 0x8003B5A0: lh          $t2, 0x6($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X6);
    // 0x8003B5A4: lw          $t5, 0x78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X78);
    // 0x8003B5A8: ori         $t4, $t2, 0x4000
    ctx->r12 = ctx->r10 | 0X4000;
    // 0x8003B5AC: bne         $t5, $zero, L_8003B7B8
    if (ctx->r13 != 0) {
        // 0x8003B5B0: sh          $t4, 0x6($s1)
        MEM_H(0X6, ctx->r17) = ctx->r12;
            goto L_8003B7B8;
    }
    // 0x8003B5B0: sh          $t4, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r12;
    // 0x8003B5B4: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8003B5B8: lbu         $a0, 0x39($s1)
    ctx->r4 = MEM_BU(ctx->r17, 0X39);
    // 0x8003B5BC: andi        $t7, $t6, 0xBFFF
    ctx->r15 = ctx->r14 & 0XBFFF;
    // 0x8003B5C0: sh          $t7, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r15;
    // 0x8003B5C4: lw          $v1, 0x54($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X54);
    // 0x8003B5C8: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8003B5CC: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x8003B5D0: subu        $t1, $t9, $t8
    ctx->r9 = SUB32(ctx->r25, ctx->r24);
    // 0x8003B5D4: slt         $at, $a0, $t1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8003B5D8: beq         $at, $zero, L_8003B5EC
    if (ctx->r1 == 0) {
        // 0x8003B5DC: addiu       $t3, $zero, 0xFF
        ctx->r11 = ADD32(0, 0XFF);
            goto L_8003B5EC;
    }
    // 0x8003B5DC: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8003B5E0: addu        $t0, $a0, $t8
    ctx->r8 = ADD32(ctx->r4, ctx->r24);
    // 0x8003B5E4: b           L_8003B5F0
    // 0x8003B5E8: sb          $t0, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r8;
        goto L_8003B5F0;
    // 0x8003B5E8: sb          $t0, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r8;
L_8003B5EC:
    // 0x8003B5EC: sb          $t3, 0x39($s1)
    MEM_B(0X39, ctx->r17) = ctx->r11;
L_8003B5F0:
    // 0x8003B5F0: lw          $a0, 0x4C($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X4C);
    // 0x8003B5F4: nop

    // 0x8003B5F8: lbu         $t2, 0x13($a0)
    ctx->r10 = MEM_BU(ctx->r4, 0X13);
    // 0x8003B5FC: nop

    // 0x8003B600: slti        $at, $t2, 0x2D
    ctx->r1 = SIGNED(ctx->r10) < 0X2D ? 1 : 0;
    // 0x8003B604: beq         $at, $zero, L_8003B6F8
    if (ctx->r1 == 0) {
        // 0x8003B608: nop
    
            goto L_8003B6F8;
    }
    // 0x8003B608: nop

    // 0x8003B60C: bne         $s0, $zero, L_8003B6F8
    if (ctx->r16 != 0) {
        // 0x8003B610: nop
    
            goto L_8003B6F8;
    }
    // 0x8003B610: nop

    // 0x8003B614: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8003B618: nop

    // 0x8003B61C: beq         $v1, $zero, L_8003B6F8
    if (ctx->r3 == 0) {
        // 0x8003B620: nop
    
            goto L_8003B6F8;
    }
    // 0x8003B620: nop

    // 0x8003B624: lw          $t4, 0x40($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X40);
    // 0x8003B628: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    // 0x8003B62C: lb          $t5, 0x54($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X54);
    // 0x8003B630: nop

    // 0x8003B634: bne         $a2, $t5, L_8003B6F8
    if (ctx->r6 != ctx->r13) {
        // 0x8003B638: nop
    
            goto L_8003B6F8;
    }
    // 0x8003B638: nop

    // 0x8003B63C: lw          $a0, 0x64($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X64);
    // 0x8003B640: nop

    // 0x8003B644: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8003B648: nop

    // 0x8003B64C: bne         $t6, $zero, L_8003B6F8
    if (ctx->r14 != 0) {
        // 0x8003B650: nop
    
            goto L_8003B6F8;
    }
    // 0x8003B650: nop

    // 0x8003B654: lbu         $t8, 0x48($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X48);
    // 0x8003B658: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8003B65C: sll         $t9, $t8, 1
    ctx->r25 = S32(ctx->r24 << 1);
    // 0x8003B660: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8003B664: lh          $t1, 0x0($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X0);
    // 0x8003B668: nop

    // 0x8003B66C: addiu       $t0, $t1, 0x1
    ctx->r8 = ADD32(ctx->r9, 0X1);
    // 0x8003B670: sh          $t0, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r8;
    // 0x8003B674: lbu         $t3, 0x48($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X48);
    // 0x8003B678: nop

    // 0x8003B67C: beq         $t3, $zero, L_8003B69C
    if (ctx->r11 == 0) {
        // 0x8003B680: nop
    
            goto L_8003B69C;
    }
    // 0x8003B680: nop

    // 0x8003B684: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8003B688: nop

    // 0x8003B68C: lh          $t2, 0x0($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X0);
    // 0x8003B690: nop

    // 0x8003B694: addiu       $t4, $t2, 0x1
    ctx->r12 = ADD32(ctx->r10, 0X1);
    // 0x8003B698: sh          $t4, 0x0($v1)
    MEM_H(0X0, ctx->r3) = ctx->r12;
L_8003B69C:
    // 0x8003B69C: lbu         $t6, 0x49($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X49);
    // 0x8003B6A0: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8003B6A4: sll         $t8, $t6, 2
    ctx->r24 = S32(ctx->r14 << 2);
    // 0x8003B6A8: addu        $v1, $t5, $t8
    ctx->r3 = ADD32(ctx->r13, ctx->r24);
    // 0x8003B6AC: lw          $t7, 0x0($v1)
    ctx->r15 = MEM_W(ctx->r3, 0X0);
    // 0x8003B6B0: addiu       $a0, $zero, 0x23D
    ctx->r4 = ADD32(0, 0X23D);
    // 0x8003B6B4: or          $t9, $t7, $a1
    ctx->r25 = ctx->r15 | ctx->r5;
    // 0x8003B6B8: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x8003B6BC: lw          $a3, 0x14($s1)
    ctx->r7 = MEM_W(ctx->r17, 0X14);
    // 0x8003B6C0: lw          $a2, 0x10($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X10);
    // 0x8003B6C4: lw          $a1, 0xC($s1)
    ctx->r5 = MEM_W(ctx->r17, 0XC);
    // 0x8003B6C8: jal         0x80001EA8
    // 0x8003B6CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    sound_play_spatial(rdram, ctx);
        goto after_3;
    // 0x8003B6CC: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_3:
    // 0x8003B6D0: lh          $t3, 0x6($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X6);
    // 0x8003B6D4: addiu       $t1, $zero, 0x10
    ctx->r9 = ADD32(0, 0X10);
    // 0x8003B6D8: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x8003B6DC: ori         $t2, $t3, 0x4000
    ctx->r10 = ctx->r11 | 0X4000;
    // 0x8003B6E0: sw          $t1, 0x7C($s1)
    MEM_W(0X7C, ctx->r17) = ctx->r9;
    // 0x8003B6E4: sw          $t0, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r8;
    // 0x8003B6E8: sh          $t2, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r10;
    // 0x8003B6EC: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x8003B6F0: jal         0x800AFC3C
    // 0x8003B6F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_4;
    // 0x8003B6F4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_4:
L_8003B6F8:
    // 0x8003B6F8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8003B6FC: lw          $s0, 0x64($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X64);
    // 0x8003B700: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8003B704: swc1        $f2, 0x14($s0)
    MEM_W(0X14, ctx->r16) = ctx->f2.u32l;
    // 0x8003B708: lbu         $t4, 0x39($s1)
    ctx->r12 = MEM_BU(ctx->r17, 0X39);
    // 0x8003B70C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8003B710: slti        $at, $t4, 0xFF
    ctx->r1 = SIGNED(ctx->r12) < 0XFF ? 1 : 0;
    // 0x8003B714: beq         $at, $zero, L_8003B724
    if (ctx->r1 == 0) {
        // 0x8003B718: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8003B724;
    }
    // 0x8003B718: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B71C: b           L_8003B730
    // 0x8003B720: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_8003B730;
    // 0x8003B720: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_8003B724:
    // 0x8003B724: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8003B728: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8003B72C: nop

L_8003B730:
    // 0x8003B730: lbu         $t6, 0xD($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XD);
    // 0x8003B734: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003B738: bne         $t6, $at, L_8003B7AC
    if (ctx->r14 != ctx->r1) {
        // 0x8003B73C: lw          $a2, 0x2C($sp)
        ctx->r6 = MEM_W(ctx->r29, 0X2C);
            goto L_8003B7AC;
    }
    // 0x8003B73C: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B740: lwc1        $f12, 0xC($s1)
    ctx->f12.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8003B744: lwc1        $f14, 0x10($s1)
    ctx->f14.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8003B748: lw          $a2, 0x14($s1)
    ctx->r6 = MEM_W(ctx->r17, 0X14);
    // 0x8003B74C: jal         0x8001C524
    // 0x8003B750: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    ainode_find_nearest(rdram, ctx);
        goto after_5;
    // 0x8003B750: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8003B754: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003B758: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x8003B75C: beq         $a0, $at, L_8003B7B8
    if (ctx->r4 == ctx->r1) {
        // 0x8003B760: sb          $v0, 0xD($s0)
        MEM_B(0XD, ctx->r16) = ctx->r2;
            goto L_8003B7B8;
    }
    // 0x8003B760: sb          $v0, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r2;
    // 0x8003B764: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8003B768: jal         0x8001CC48
    // 0x8003B76C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_6;
    // 0x8003B76C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_6:
    // 0x8003B770: lbu         $a1, 0xD($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XD);
    // 0x8003B774: sb          $v0, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r2;
    // 0x8003B778: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003B77C: jal         0x8001CC48
    // 0x8003B780: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_7;
    // 0x8003B780: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_7:
    // 0x8003B784: lbu         $a1, 0xE($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0XE);
    // 0x8003B788: sb          $v0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r2;
    // 0x8003B78C: andi        $a0, $v0, 0xFF
    ctx->r4 = ctx->r2 & 0XFF;
    // 0x8003B790: jal         0x8001CC48
    // 0x8003B794: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    ainode_find_next(rdram, ctx);
        goto after_8;
    // 0x8003B794: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_8:
    // 0x8003B798: lbu         $t5, 0xD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XD);
    // 0x8003B79C: sb          $v0, 0x10($s0)
    MEM_B(0X10, ctx->r16) = ctx->r2;
    // 0x8003B7A0: b           L_8003B7B8
    // 0x8003B7A4: sb          $t5, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r13;
        goto L_8003B7B8;
    // 0x8003B7A4: sb          $t5, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r13;
    // 0x8003B7A8: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
L_8003B7AC:
    // 0x8003B7AC: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x8003B7B0: jal         0x8001C6C4
    // 0x8003B7B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    func_8001C6C4(rdram, ctx);
        goto after_9;
    // 0x8003B7B4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_9:
L_8003B7B8:
    // 0x8003B7B8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8003B7BC:
    // 0x8003B7BC: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B7C0: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x8003B7C4: jr          $ra
    // 0x8003B7C8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8003B7C8: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void load_next_ingame_level(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006CAE4: addiu       $t6, $a0, -0x1
    ctx->r14 = ADD32(ctx->r4, -0X1);
    // 0x8006CAE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006CAEC: sw          $t6, 0x3500($at)
    MEM_W(0X3500, ctx->r1) = ctx->r14;
    // 0x8006CAF0: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006CAF4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8006CAF8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006CAFC: bne         $a1, $at, L_8006CB1C
    if (ctx->r5 != ctx->r1) {
        // 0x8006CB00: sw          $a2, 0x20($sp)
        MEM_W(0X20, ctx->r29) = ctx->r6;
            goto L_8006CB1C;
    }
    // 0x8006CB00: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x8006CB04: jal         0x8009C1B0
    // 0x8006CB08: nop

    get_track_id_to_load(rdram, ctx);
        goto after_0;
    // 0x8006CB08: nop

    after_0:
    // 0x8006CB0C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006CB10: addiu       $v1, $v1, 0x34F4
    ctx->r3 = ADD32(ctx->r3, 0X34F4);
    // 0x8006CB14: b           L_8006CB28
    // 0x8006CB18: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
        goto L_8006CB28;
    // 0x8006CB18: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8006CB1C:
    // 0x8006CB1C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006CB20: addiu       $v1, $v1, 0x34F4
    ctx->r3 = ADD32(ctx->r3, 0X34F4);
    // 0x8006CB24: sw          $a1, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r5;
L_8006CB28:
    // 0x8006CB28: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8006CB2C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006CB30: lw          $a2, 0x3504($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X3504);
    // 0x8006CB34: lw          $a1, 0x3500($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X3500);
    // 0x8006CB38: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8006CB3C: lw          $a3, 0x20($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X20);
    // 0x8006CB40: jal         0x8006CB58
    // 0x8006CB44: nop

    load_level_game(rdram, ctx);
        goto after_1;
    // 0x8006CB44: nop

    after_1:
    // 0x8006CB48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006CB4C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006CB50: jr          $ra
    // 0x8006CB54: nop

    return;
    // 0x8006CB54: nop

;}
RECOMP_FUNC void calculate_eeprom_settings_checksum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007480C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80074810: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80074814: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80074818: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8007481C: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80074820: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80074824: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x80074828: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x8007482C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80074830: addiu       $s2, $zero, 0xE
    ctx->r18 = ADD32(0, 0XE);
L_80074834:
    // 0x80074834: lw          $a0, 0x28($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X28);
    // 0x80074838: lw          $a1, 0x2C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X2C);
    // 0x8007483C: sll         $a3, $s0, 2
    ctx->r7 = S32(ctx->r16 << 2);
    // 0x80074840: jal         0x800CEA60
    // 0x80074844: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    __ull_rshift_recomp(rdram, ctx);
        goto after_0;
    // 0x80074844: sra         $a2, $a3, 31
    ctx->r6 = S32(SIGNED(ctx->r7) >> 31);
    after_0:
    // 0x80074848: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8007484C: andi        $t9, $v1, 0xF
    ctx->r25 = ctx->r3 & 0XF;
    // 0x80074850: bne         $s0, $s2, L_80074834
    if (ctx->r16 != ctx->r18) {
        // 0x80074854: addu        $s1, $s1, $t9
        ctx->r17 = ADD32(ctx->r17, ctx->r25);
            goto L_80074834;
    }
    // 0x80074854: addu        $s1, $s1, $t9
    ctx->r17 = ADD32(ctx->r17, ctx->r25);
    // 0x80074858: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8007485C: or          $v0, $s1, $zero
    ctx->r2 = ctx->r17 | 0;
    // 0x80074860: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80074864: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074868: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8007486C: jr          $ra
    // 0x80074870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80074870: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void read_data_from_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076610: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80076614: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80076618: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x8007661C: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x80076620: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80076624: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80076628: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x8007662C: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80076630: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x80076634: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80076638: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8007663C: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80076640: addiu       $t8, $t8, 0x4018
    ctx->r24 = ADD32(ctx->r24, 0X4018);
    // 0x80076644: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80076648: addu        $a0, $t7, $t8
    ctx->r4 = ADD32(ctx->r15, ctx->r24);
    // 0x8007664C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80076650: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80076654: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80076658: jal         0x800CEFDC
    // 0x8007665C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    osPfsReadWriteFile_recomp(rdram, ctx);
        goto after_0;
    // 0x8007665C: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_0:
    // 0x80076660: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80076664: bne         $v0, $zero, L_80076674
    if (ctx->r2 != 0) {
        // 0x80076668: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80076674;
    }
    // 0x80076668: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8007666C: b           L_800766CC
    // 0x80076670: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800766CC;
    // 0x80076670: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80076674:
    // 0x80076674: beq         $v0, $at, L_80076684
    if (ctx->r2 == ctx->r1) {
        // 0x80076678: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80076684;
    }
    // 0x80076678: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x8007667C: bne         $v0, $at, L_80076690
    if (ctx->r2 != ctx->r1) {
        // 0x80076680: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80076690;
    }
    // 0x80076680: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80076684:
    // 0x80076684: b           L_800766CC
    // 0x80076688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800766CC;
    // 0x80076688: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8007668C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_80076690:
    // 0x80076690: bne         $v0, $at, L_800766A4
    if (ctx->r2 != ctx->r1) {
        // 0x80076694: addiu       $at, $zero, 0xA
        ctx->r1 = ADD32(0, 0XA);
            goto L_800766A4;
    }
    // 0x80076694: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x80076698: b           L_800766CC
    // 0x8007669C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800766CC;
    // 0x8007669C: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
    // 0x800766A0: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
L_800766A4:
    // 0x800766A4: bne         $v0, $at, L_800766B8
    if (ctx->r2 != ctx->r1) {
        // 0x800766A8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800766B8;
    }
    // 0x800766A8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800766AC: b           L_800766CC
    // 0x800766B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800766CC;
    // 0x800766B0: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x800766B4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
L_800766B8:
    // 0x800766B8: bne         $v0, $at, L_800766CC
    if (ctx->r2 != ctx->r1) {
        // 0x800766BC: addiu       $v0, $zero, 0x9
        ctx->r2 = ADD32(0, 0X9);
            goto L_800766CC;
    }
    // 0x800766BC: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
    // 0x800766C0: b           L_800766CC
    // 0x800766C4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800766CC;
    // 0x800766C4: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x800766C8: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_800766CC:
    // 0x800766CC: jr          $ra
    // 0x800766D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800766D0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_loop_skycontrol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003CF98: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003CF9C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003CFA0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003CFA4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003CFA8: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x8003CFAC: lw          $t8, 0x7C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X7C);
    // 0x8003CFB0: lbu         $t7, 0x13($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X13);
    // 0x8003CFB4: nop

    // 0x8003CFB8: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8003CFBC: beq         $at, $zero, L_8003CFD4
    if (ctx->r1 == 0) {
        // 0x8003CFC0: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_8003CFD4;
    }
    // 0x8003CFC0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003CFC4: lw          $a0, 0x78($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X78);
    // 0x8003CFC8: jal         0x80028044
    // 0x8003CFCC: nop

    set_skydome_visbility(rdram, ctx);
        goto after_0;
    // 0x8003CFCC: nop

    after_0:
    // 0x8003CFD0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_8003CFD4:
    // 0x8003CFD4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003CFD8: jr          $ra
    // 0x8003CFDC: nop

    return;
    // 0x8003CFDC: nop

;}
RECOMP_FUNC void func_80067D3C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80067D3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80067D40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80067D44: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80067D48: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x80067D4C: lui         $t7, 0xB400
    ctx->r15 = S32(0XB400 << 16);
    // 0x80067D50: addiu       $t6, $v1, 0x8
    ctx->r14 = ADD32(ctx->r3, 0X8);
    // 0x80067D54: sw          $t6, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r14;
    // 0x80067D58: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80067D5C: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x80067D60: lhu         $t8, 0xD6C($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0XD6C);
    // 0x80067D64: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80067D68: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x80067D6C: addiu       $a2, $a2, 0xCE4
    ctx->r6 = ADD32(ctx->r6, 0XCE4);
    // 0x80067D70: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80067D74: lw          $a1, 0x0($a2)
    ctx->r5 = MEM_W(ctx->r6, 0X0);
    // 0x80067D78: lb          $t9, 0xD14($t9)
    ctx->r25 = MEM_B(ctx->r25, 0XD14);
    // 0x80067D7C: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80067D80: beq         $t9, $zero, L_80067D94
    if (ctx->r25 == 0) {
        // 0x80067D84: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_80067D94;
    }
    // 0x80067D84: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80067D88: addiu       $t0, $a1, 0x4
    ctx->r8 = ADD32(ctx->r5, 0X4);
    // 0x80067D8C: sw          $t0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r8;
    // 0x80067D90: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
L_80067D94:
    // 0x80067D94: sll         $t1, $a1, 4
    ctx->r9 = S32(ctx->r5 << 4);
    // 0x80067D98: addu        $t1, $t1, $a1
    ctx->r9 = ADD32(ctx->r9, ctx->r5);
    // 0x80067D9C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80067DA0: addiu       $t2, $t2, 0xAC0
    ctx->r10 = ADD32(ctx->r10, 0XAC0);
    // 0x80067DA4: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80067DA8: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80067DAC: addiu       $a3, $a3, 0xCF0
    ctx->r7 = ADD32(ctx->r7, 0XCF0);
    // 0x80067DB0: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80067DB4: lh          $t5, 0x38($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X38);
    // 0x80067DB8: lh          $t6, 0x2($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X2);
    // 0x80067DBC: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80067DC0: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80067DC4: lh          $t8, 0x4($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X4);
    // 0x80067DC8: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x80067DCC: addu        $t4, $t3, $at
    ctx->r12 = ADD32(ctx->r11, ctx->r1);
    // 0x80067DD0: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80067DD4: neg.s       $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = -ctx->f4.fl;
    // 0x80067DD8: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80067DDC: sh          $t4, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r12;
    // 0x80067DE0: sh          $t7, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r15;
    // 0x80067DE4: swc1        $f6, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f6.u32l;
    // 0x80067DE8: swc1        $f10, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f10.u32l;
    // 0x80067DEC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80067DF0: sh          $t8, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r24;
    // 0x80067DF4: lw          $t9, 0xD18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0XD18);
    // 0x80067DF8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80067DFC: beq         $t9, $zero, L_80067E18
    if (ctx->r25 == 0) {
        // 0x80067E00: addiu       $a0, $a0, 0xF60
        ctx->r4 = ADD32(ctx->r4, 0XF60);
            goto L_80067E18;
    }
    // 0x80067E00: addiu       $a0, $a0, 0xF60
    ctx->r4 = ADD32(ctx->r4, 0XF60);
    // 0x80067E04: lwc1        $f16, 0x10($a3)
    ctx->f16.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80067E08: lwc1        $f18, 0x30($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80067E0C: nop

    // 0x80067E10: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80067E14: swc1        $f4, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f4.u32l;
L_80067E18:
    // 0x80067E18: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80067E1C: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80067E20: neg.s       $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = -ctx->f6.fl;
    // 0x80067E24: jal         0x8006FE74
    // 0x80067E28: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    mtxf_from_inverse_transform(rdram, ctx);
        goto after_0;
    // 0x80067E28: swc1        $f8, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f8.u32l;
    after_0:
    // 0x80067E2C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80067E30: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80067E34: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80067E38: addiu       $a2, $a2, 0xF20
    ctx->r6 = ADD32(ctx->r6, 0XF20);
    // 0x80067E3C: addiu       $a1, $a1, 0xEE0
    ctx->r5 = ADD32(ctx->r5, 0XEE0);
    // 0x80067E40: jal         0x8006F768
    // 0x80067E44: addiu       $a0, $a0, 0xF60
    ctx->r4 = ADD32(ctx->r4, 0XF60);
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x80067E44: addiu       $a0, $a0, 0xF60
    ctx->r4 = ADD32(ctx->r4, 0XF60);
    after_1:
    // 0x80067E48: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80067E4C: lw          $t0, 0xCE4($t0)
    ctx->r8 = MEM_W(ctx->r8, 0XCE4);
    // 0x80067E50: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80067E54: sll         $t1, $t0, 4
    ctx->r9 = S32(ctx->r8 << 4);
    // 0x80067E58: addu        $t1, $t1, $t0
    ctx->r9 = ADD32(ctx->r9, ctx->r8);
    // 0x80067E5C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x80067E60: addiu       $t2, $t2, 0xAC0
    ctx->r10 = ADD32(ctx->r10, 0XAC0);
    // 0x80067E64: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x80067E68: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80067E6C: addiu       $a3, $a3, 0xCF0
    ctx->r7 = ADD32(ctx->r7, 0XCF0);
    // 0x80067E70: lh          $t6, 0x38($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X38);
    // 0x80067E74: lh          $t7, 0x2($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X2);
    // 0x80067E78: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x80067E7C: lh          $t0, 0x4($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X4);
    // 0x80067E80: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80067E84: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80067E88: lwc1        $f16, 0xC($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80067E8C: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x80067E90: addiu       $t4, $zero, -0x8000
    ctx->r12 = ADD32(0, -0X8000);
    // 0x80067E94: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x80067E98: negu        $t9, $t8
    ctx->r25 = SUB32(0, ctx->r24);
    // 0x80067E9C: subu        $t5, $t4, $t3
    ctx->r13 = SUB32(ctx->r12, ctx->r11);
    // 0x80067EA0: negu        $t1, $t0
    ctx->r9 = SUB32(0, ctx->r8);
    // 0x80067EA4: sh          $t5, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r13;
    // 0x80067EA8: sh          $t9, 0x2($a3)
    MEM_H(0X2, ctx->r7) = ctx->r25;
    // 0x80067EAC: sh          $t1, 0x4($a3)
    MEM_H(0X4, ctx->r7) = ctx->r9;
    // 0x80067EB0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80067EB4: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    // 0x80067EB8: swc1        $f16, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f16.u32l;
    // 0x80067EBC: swc1        $f18, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f18.u32l;
    // 0x80067EC0: lw          $t2, 0xD18($t2)
    ctx->r10 = MEM_W(ctx->r10, 0XD18);
    // 0x80067EC4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80067EC8: beq         $t2, $zero, L_80067EE4
    if (ctx->r10 == 0) {
        // 0x80067ECC: addiu       $a0, $a0, 0xFA0
        ctx->r4 = ADD32(ctx->r4, 0XFA0);
            goto L_80067EE4;
    }
    // 0x80067ECC: addiu       $a0, $a0, 0xFA0
    ctx->r4 = ADD32(ctx->r4, 0XFA0);
    // 0x80067ED0: lwc1        $f4, 0x10($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X10);
    // 0x80067ED4: lwc1        $f6, 0x30($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X30);
    // 0x80067ED8: nop

    // 0x80067EDC: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80067EE0: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
L_80067EE4:
    // 0x80067EE4: lwc1        $f10, 0x14($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X14);
    // 0x80067EE8: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x80067EEC: jal         0x8006FC30
    // 0x80067EF0: swc1        $f10, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f10.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_2;
    // 0x80067EF0: swc1        $f10, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f10.u32l;
    after_2:
    // 0x80067EF4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80067EF8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80067EFC: addiu       $a1, $a1, 0x1020
    ctx->r5 = ADD32(ctx->r5, 0X1020);
    // 0x80067F00: jal         0x8006F870
    // 0x80067F04: addiu       $a0, $a0, 0xFA0
    ctx->r4 = ADD32(ctx->r4, 0XFA0);
    mtxf_to_mtx(rdram, ctx);
        goto after_3;
    // 0x80067F04: addiu       $a0, $a0, 0xFA0
    ctx->r4 = ADD32(ctx->r4, 0XFA0);
    after_3:
    // 0x80067F08: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80067F0C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80067F10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80067F14: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80067F18: jr          $ra
    // 0x80067F1C: sw          $t4, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r12;
    return;
    // 0x80067F1C: sw          $t4, 0xCE4($at)
    MEM_W(0XCE4, ctx->r1) = ctx->r12;
;}
RECOMP_FUNC void dialogue_box_clear_unused_flag(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5678: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C567C: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x800C5680: lw          $t6, -0x5818($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5818);
    // 0x800C5684: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x800C5688: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x800C568C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800C5690: lhu         $t8, 0x1E($v0)
    ctx->r24 = MEM_HU(ctx->r2, 0X1E);
    // 0x800C5694: nop

    // 0x800C5698: andi        $t9, $t8, 0xFFFE
    ctx->r25 = ctx->r24 & 0XFFFE;
    // 0x800C569C: jr          $ra
    // 0x800C56A0: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
    return;
    // 0x800C56A0: sh          $t9, 0x1E($v0)
    MEM_H(0X1E, ctx->r2) = ctx->r25;
;}
RECOMP_FUNC void handle_racer_top_speed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80057220: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80057224: lw          $t6, -0x2AC0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2AC0);
    // 0x80057228: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8005722C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80057230: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80057234: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80057238: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8005723C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80057240: beq         $t6, $zero, L_80057250
    if (ctx->r14 == 0) {
        // 0x80057244: sw          $a0, 0x40($sp)
        MEM_W(0X40, ctx->r29) = ctx->r4;
            goto L_80057250;
    }
    // 0x80057244: sw          $a0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r4;
    // 0x80057248: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8005724C: nop

L_80057250:
    // 0x80057250: jal         0x800113AC
    // 0x80057254: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    get_race_start_timer(rdram, ctx);
        goto after_0;
    // 0x80057254: swc1        $f0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f0.u32l;
    after_0:
    // 0x80057258: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005725C: lw          $a0, -0x2AC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2AC0);
    // 0x80057260: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    // 0x80057264: blez        $a0, L_80057430
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80057268: slti        $at, $a0, 0x1E
        ctx->r1 = SIGNED(ctx->r4) < 0X1E ? 1 : 0;
            goto L_80057430;
    }
    // 0x80057268: slti        $at, $a0, 0x1E
    ctx->r1 = SIGNED(ctx->r4) < 0X1E ? 1 : 0;
    // 0x8005726C: beq         $at, $zero, L_80057430
    if (ctx->r1 == 0) {
        // 0x80057270: nop
    
            goto L_80057430;
    }
    // 0x80057270: nop

    // 0x80057274: lbu         $t7, 0x1F4($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1F4);
    // 0x80057278: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8005727C: bne         $t7, $zero, L_80057430
    if (ctx->r15 != 0) {
        // 0x80057280: nop
    
            goto L_80057430;
    }
    // 0x80057280: nop

    // 0x80057284: lw          $t8, -0x2AD4($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2AD4);
    // 0x80057288: addiu       $v1, $a0, -0xE
    ctx->r3 = ADD32(ctx->r4, -0XE);
    // 0x8005728C: andi        $t9, $t8, 0x8000
    ctx->r25 = ctx->r24 & 0X8000;
    // 0x80057290: beq         $t9, $zero, L_80057384
    if (ctx->r25 == 0) {
        // 0x80057294: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_80057384;
    }
    // 0x80057294: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80057298: bgez        $v1, L_800572AC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005729C: addiu       $t2, $zero, 0x18
        ctx->r10 = ADD32(0, 0X18);
            goto L_800572AC;
    }
    // 0x8005729C: addiu       $t2, $zero, 0x18
    ctx->r10 = ADD32(0, 0X18);
    // 0x800572A0: bltz        $v0, L_800572AC
    if (SIGNED(ctx->r2) < 0) {
        // 0x800572A4: nop
    
            goto L_800572AC;
    }
    // 0x800572A4: nop

    // 0x800572A8: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800572AC:
    // 0x800572AC: bgez        $v1, L_800572B8
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800572B0: nop
    
            goto L_800572B8;
    }
    // 0x800572B0: nop

    // 0x800572B4: negu        $v1, $v1
    ctx->r3 = SUB32(0, ctx->r3);
L_800572B8:
    // 0x800572B8: lw          $t0, -0x2AD8($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AD8);
    // 0x800572BC: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x800572C0: andi        $t1, $t0, 0x2000
    ctx->r9 = ctx->r8 & 0X2000;
    // 0x800572C4: beq         $t1, $zero, L_800572DC
    if (ctx->r9 == 0) {
        // 0x800572C8: subu        $a1, $t2, $v1
        ctx->r5 = SUB32(ctx->r10, ctx->r3);
            goto L_800572DC;
    }
    // 0x800572C8: subu        $a1, $t2, $v1
    ctx->r5 = SUB32(ctx->r10, ctx->r3);
    // 0x800572CC: beq         $at, $zero, L_800572DC
    if (ctx->r1 == 0) {
        // 0x800572D0: subu        $a1, $t2, $v1
        ctx->r5 = SUB32(ctx->r10, ctx->r3);
            goto L_800572DC;
    }
    // 0x800572D0: subu        $a1, $t2, $v1
    ctx->r5 = SUB32(ctx->r10, ctx->r3);
    // 0x800572D4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800572D8: subu        $a1, $t2, $v1
    ctx->r5 = SUB32(ctx->r10, ctx->r3);
L_800572DC:
    // 0x800572DC: sra         $a0, $a1, 1
    ctx->r4 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800572E0: jal         0x8000C8B4
    // 0x800572E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_1;
    // 0x800572E4: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_1:
    // 0x800572E8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800572EC: addiu       $at, $zero, 0x18
    ctx->r1 = ADD32(0, 0X18);
    // 0x800572F0: bne         $a1, $at, L_80057310
    if (ctx->r5 != ctx->r1) {
        // 0x800572F4: sb          $v0, 0x1D3($s0)
        MEM_B(0X1D3, ctx->r16) = ctx->r2;
            goto L_80057310;
    }
    // 0x800572F4: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
    // 0x800572F8: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800572FC: jal         0x80057048
    // 0x80057300: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    racer_play_sound(rdram, ctx);
        goto after_2;
    // 0x80057300: addiu       $a1, $zero, 0x22
    ctx->r5 = ADD32(0, 0X22);
    after_2:
    // 0x80057304: jal         0x8000C8B4
    // 0x80057308: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    normalise_time(rdram, ctx);
        goto after_3;
    // 0x80057308: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_3:
    // 0x8005730C: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
L_80057310:
    // 0x80057310: jal         0x8000C8B4
    // 0x80057314: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    normalise_time(rdram, ctx);
        goto after_4;
    // 0x80057314: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_4:
    // 0x80057318: lb          $t3, 0x1D3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D3);
    // 0x8005731C: nop

    // 0x80057320: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80057324: beq         $at, $zero, L_80057334
    if (ctx->r1 == 0) {
        // 0x80057328: nop
    
            goto L_80057334;
    }
    // 0x80057328: nop

    // 0x8005732C: b           L_8005735C
    // 0x80057330: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
        goto L_8005735C;
    // 0x80057330: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
L_80057334:
    // 0x80057334: jal         0x8000C8B4
    // 0x80057338: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    normalise_time(rdram, ctx);
        goto after_5;
    // 0x80057338: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_5:
    // 0x8005733C: lb          $t4, 0x1D3($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D3);
    // 0x80057340: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80057344: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x80057348: beq         $at, $zero, L_80057358
    if (ctx->r1 == 0) {
        // 0x8005734C: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80057358;
    }
    // 0x8005734C: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80057350: b           L_8005735C
    // 0x80057354: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
        goto L_8005735C;
    // 0x80057354: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
L_80057358:
    // 0x80057358: sb          $t6, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r14;
L_8005735C:
    // 0x8005735C: lbu         $t7, 0x1EF($s0)
    ctx->r15 = MEM_BU(ctx->r16, 0X1EF);
    // 0x80057360: addiu       $t9, $zero, 0x7
    ctx->r25 = ADD32(0, 0X7);
    // 0x80057364: ori         $t8, $t7, 0x1
    ctx->r24 = ctx->r15 | 0X1;
    // 0x80057368: sb          $t8, 0x1EF($s0)
    MEM_B(0X1EF, ctx->r16) = ctx->r24;
    // 0x8005736C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80057370: sh          $t9, -0x2AA0($at)
    MEM_H(-0X2AA0, ctx->r1) = ctx->r25;
    // 0x80057374: lb          $t0, 0x1D3($s0)
    ctx->r8 = MEM_B(ctx->r16, 0X1D3);
    // 0x80057378: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005737C: addiu       $v1, $v1, -0x2A7B
    ctx->r3 = ADD32(ctx->r3, -0X2A7B);
    // 0x80057380: sb          $t0, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r8;
L_80057384:
    // 0x80057384: lh          $t1, 0x0($s0)
    ctx->r9 = MEM_H(ctx->r16, 0X0);
    // 0x80057388: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8005738C: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80057390: bne         $t1, $at, L_80057430
    if (ctx->r9 != ctx->r1) {
        // 0x80057394: addiu       $v1, $v1, -0x2A7B
        ctx->r3 = ADD32(ctx->r3, -0X2A7B);
            goto L_80057430;
    }
    // 0x80057394: addiu       $v1, $v1, -0x2A7B
    ctx->r3 = ADD32(ctx->r3, -0X2A7B);
    // 0x80057398: lb          $v0, 0x1CC($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1CC);
    // 0x8005739C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800573A0: beq         $v0, $zero, L_800573C0
    if (ctx->r2 == 0) {
        // 0x800573A4: nop
    
            goto L_800573C0;
    }
    // 0x800573A4: nop

    // 0x800573A8: bne         $v0, $at, L_80057430
    if (ctx->r2 != ctx->r1) {
        // 0x800573AC: nop
    
            goto L_80057430;
    }
    // 0x800573AC: nop

    // 0x800573B0: lb          $t2, 0x0($v1)
    ctx->r10 = MEM_B(ctx->r3, 0X0);
    // 0x800573B4: nop

    // 0x800573B8: beq         $t2, $zero, L_80057430
    if (ctx->r10 == 0) {
        // 0x800573BC: nop
    
            goto L_80057430;
    }
    // 0x800573BC: nop

L_800573C0:
    // 0x800573C0: lb          $v0, 0x0($v1)
    ctx->r2 = MEM_B(ctx->r3, 0X0);
    // 0x800573C4: nop

    // 0x800573C8: beq         $v0, $zero, L_800573D8
    if (ctx->r2 == 0) {
        // 0x800573CC: nop
    
            goto L_800573D8;
    }
    // 0x800573CC: nop

    // 0x800573D0: b           L_800573E4
    // 0x800573D4: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
        goto L_800573E4;
    // 0x800573D4: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
L_800573D8:
    // 0x800573D8: jal         0x8000C8B4
    // 0x800573DC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    normalise_time(rdram, ctx);
        goto after_6;
    // 0x800573DC: addiu       $a0, $zero, 0x5
    ctx->r4 = ADD32(0, 0X5);
    after_6:
    // 0x800573E0: sb          $v0, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r2;
L_800573E4:
    // 0x800573E4: jal         0x8000C8B4
    // 0x800573E8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    normalise_time(rdram, ctx);
        goto after_7;
    // 0x800573E8: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    after_7:
    // 0x800573EC: lb          $t3, 0x1D3($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X1D3);
    // 0x800573F0: nop

    // 0x800573F4: slt         $at, $t3, $v0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800573F8: beq         $at, $zero, L_80057408
    if (ctx->r1 == 0) {
        // 0x800573FC: nop
    
            goto L_80057408;
    }
    // 0x800573FC: nop

    // 0x80057400: b           L_80057430
    // 0x80057404: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
        goto L_80057430;
    // 0x80057404: sb          $zero, 0x203($s0)
    MEM_B(0X203, ctx->r16) = 0;
L_80057408:
    // 0x80057408: jal         0x8000C8B4
    // 0x8005740C: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    normalise_time(rdram, ctx);
        goto after_8;
    // 0x8005740C: addiu       $a0, $zero, 0x23
    ctx->r4 = ADD32(0, 0X23);
    after_8:
    // 0x80057410: lb          $t4, 0x1D3($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1D3);
    // 0x80057414: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80057418: slt         $at, $t4, $v0
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005741C: beq         $at, $zero, L_8005742C
    if (ctx->r1 == 0) {
        // 0x80057420: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_8005742C;
    }
    // 0x80057420: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80057424: b           L_80057430
    // 0x80057428: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
        goto L_80057430;
    // 0x80057428: sb          $t5, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r13;
L_8005742C:
    // 0x8005742C: sb          $t6, 0x203($s0)
    MEM_B(0X203, ctx->r16) = ctx->r14;
L_80057430:
    // 0x80057430: lb          $t7, 0x1D3($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X1D3);
    // 0x80057434: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80057438: lw          $a0, -0x2AC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2AC0);
    // 0x8005743C: beq         $t7, $zero, L_80057488
    if (ctx->r15 == 0) {
        // 0x80057440: slti        $at, $a0, 0x50
        ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
            goto L_80057488;
    }
    // 0x80057440: slti        $at, $a0, 0x50
    ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
    // 0x80057444: bne         $a0, $zero, L_80057488
    if (ctx->r4 != 0) {
        // 0x80057448: slti        $at, $a0, 0x50
        ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
            goto L_80057488;
    }
    // 0x80057448: slti        $at, $a0, 0x50
    ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
    // 0x8005744C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x80057450: nop

    // 0x80057454: beq         $t8, $zero, L_80057488
    if (ctx->r24 == 0) {
        // 0x80057458: slti        $at, $a0, 0x50
        ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
            goto L_80057488;
    }
    // 0x80057458: slti        $at, $a0, 0x50
    ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
    // 0x8005745C: lb          $t9, 0x1D8($s0)
    ctx->r25 = MEM_B(ctx->r16, 0X1D8);
    // 0x80057460: nop

    // 0x80057464: bne         $t9, $zero, L_80057488
    if (ctx->r25 != 0) {
        // 0x80057468: slti        $at, $a0, 0x50
        ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
            goto L_80057488;
    }
    // 0x80057468: slti        $at, $a0, 0x50
    ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
    // 0x8005746C: lh          $a0, 0x0($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X0);
    // 0x80057470: jal         0x80072348
    // 0x80057474: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    rumble_set(rdram, ctx);
        goto after_9;
    // 0x80057474: addiu       $a1, $zero, 0x6
    ctx->r5 = ADD32(0, 0X6);
    after_9:
    // 0x80057478: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8005747C: lw          $a0, -0x2AC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2AC0);
    // 0x80057480: nop

    // 0x80057484: slti        $at, $a0, 0x50
    ctx->r1 = SIGNED(ctx->r4) < 0X50 ? 1 : 0;
L_80057488:
    // 0x80057488: beq         $at, $zero, L_800574B4
    if (ctx->r1 == 0) {
        // 0x8005748C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800574B4;
    }
    // 0x8005748C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80057490: lw          $t0, -0x2AD4($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X2AD4);
    // 0x80057494: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x80057498: andi        $t1, $t0, 0x8000
    ctx->r9 = ctx->r8 & 0X8000;
    // 0x8005749C: beq         $t1, $zero, L_800574B4
    if (ctx->r9 == 0) {
        // 0x800574A0: nop
    
            goto L_800574B4;
    }
    // 0x800574A0: nop

    // 0x800574A4: sb          $t2, 0x1F4($s0)
    MEM_B(0X1F4, ctx->r16) = ctx->r10;
    // 0x800574A8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800574AC: lw          $a0, -0x2AC0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2AC0);
    // 0x800574B0: nop

L_800574B4:
    // 0x800574B4: bne         $a0, $zero, L_800574F0
    if (ctx->r4 != 0) {
        // 0x800574B8: nop
    
            goto L_800574F0;
    }
    // 0x800574B8: nop

    // 0x800574BC: lbu         $v0, 0x1EF($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1EF);
    // 0x800574C0: addiu       $a1, $zero, 0x162
    ctx->r5 = ADD32(0, 0X162);
    // 0x800574C4: andi        $t3, $v0, 0x1
    ctx->r11 = ctx->r2 & 0X1;
    // 0x800574C8: beq         $t3, $zero, L_800574F0
    if (ctx->r11 == 0) {
        // 0x800574CC: andi        $t4, $v0, 0xFFFE
        ctx->r12 = ctx->r2 & 0XFFFE;
            goto L_800574F0;
    }
    // 0x800574CC: andi        $t4, $v0, 0xFFFE
    ctx->r12 = ctx->r2 & 0XFFFE;
    // 0x800574D0: sb          $t4, 0x1EF($s0)
    MEM_B(0X1EF, ctx->r16) = ctx->r12;
    // 0x800574D4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800574D8: addiu       $a2, $zero, 0x8
    ctx->r6 = ADD32(0, 0X8);
    // 0x800574DC: jal         0x800570B8
    // 0x800574E0: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    play_random_character_voice(rdram, ctx);
        goto after_10;
    // 0x800574E0: addiu       $a3, $zero, 0x82
    ctx->r7 = ADD32(0, 0X82);
    after_10:
    // 0x800574E4: lw          $a0, 0x40($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X40);
    // 0x800574E8: jal         0x80057048
    // 0x800574EC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    racer_play_sound(rdram, ctx);
        goto after_11;
    // 0x800574EC: addiu       $a1, $zero, 0x21
    ctx->r5 = ADD32(0, 0X21);
    after_11:
L_800574F0:
    // 0x800574F0: lbu         $v0, 0x1EF($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X1EF);
    // 0x800574F4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800574F8: andi        $t5, $v0, 0x2
    ctx->r13 = ctx->r2 & 0X2;
    // 0x800574FC: beq         $t5, $zero, L_80057508
    if (ctx->r13 == 0) {
        // 0x80057500: andi        $t6, $v0, 0xFFFD
        ctx->r14 = ctx->r2 & 0XFFFD;
            goto L_80057508;
    }
    // 0x80057500: andi        $t6, $v0, 0xFFFD
    ctx->r14 = ctx->r2 & 0XFFFD;
    // 0x80057504: sb          $t6, 0x1EF($s0)
    MEM_B(0X1EF, ctx->r16) = ctx->r14;
L_80057508:
    // 0x80057508: lb          $t7, 0x185($s0)
    ctx->r15 = MEM_B(ctx->r16, 0X185);
    // 0x8005750C: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x80057510: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80057514: bne         $t8, $at, L_80057528
    if (ctx->r24 != ctx->r1) {
        // 0x80057518: cvt.s.w     $f2, $f4
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80057528;
    }
    // 0x80057518: cvt.s.w     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    ctx->f2.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8005751C: lwc1        $f2, 0x124($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X124);
    // 0x80057520: b           L_800575A0
    // 0x80057524: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
        goto L_800575A0;
    // 0x80057524: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_80057528:
    // 0x80057528: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x8005752C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80057530: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80057534: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x80057538: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8005753C: nop

    // 0x80057540: bc1f        L_80057568
    if (!c1cs) {
        // 0x80057544: nop
    
            goto L_80057568;
    }
    // 0x80057544: nop

    // 0x80057548: jal         0x8009C30C
    // 0x8005754C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_12;
    // 0x8005754C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_12:
    // 0x80057550: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80057554: andi        $t9, $v0, 0x4000
    ctx->r25 = ctx->r2 & 0X4000;
    // 0x80057558: bne         $t9, $zero, L_80057568
    if (ctx->r25 != 0) {
        // 0x8005755C: lui         $at, 0x4120
        ctx->r1 = S32(0X4120 << 16);
            goto L_80057568;
    }
    // 0x8005755C: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80057560: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80057564: nop

L_80057568:
    // 0x80057568: jal         0x8009C30C
    // 0x8005756C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    get_filtered_cheats(rdram, ctx);
        goto after_13;
    // 0x8005756C: swc1        $f2, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f2.u32l;
    after_13:
    // 0x80057570: lwc1        $f2, 0x34($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80057574: andi        $t0, $v0, 0x2000
    ctx->r8 = ctx->r2 & 0X2000;
    // 0x80057578: beq         $t0, $zero, L_800575A0
    if (ctx->r8 == 0) {
        // 0x8005757C: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_800575A0;
    }
    // 0x8005757C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80057580: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80057584: nop

    // 0x80057588: c.lt.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl < ctx->f2.fl;
    // 0x8005758C: nop

    // 0x80057590: bc1f        L_800575A0
    if (!c1cs) {
        // 0x80057594: lui         $at, 0x41A0
        ctx->r1 = S32(0X41A0 << 16);
            goto L_800575A0;
    }
    // 0x80057594: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80057598: neg.s       $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = -ctx->f2.fl;
    // 0x8005759C: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
L_800575A0:
    // 0x800575A0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800575A4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800575A8: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x800575AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800575B0: bc1f        L_800575BC
    if (!c1cs) {
        // 0x800575B4: neg.s       $f0, $f12
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
            goto L_800575BC;
    }
    // 0x800575B4: neg.s       $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = -ctx->f12.fl;
    // 0x800575B8: mov.s       $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    ctx->f2.fl = ctx->f12.fl;
L_800575BC:
    // 0x800575BC: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x800575C0: nop

    // 0x800575C4: bc1f        L_800575D0
    if (!c1cs) {
        // 0x800575C8: nop
    
            goto L_800575D0;
    }
    // 0x800575C8: nop

    // 0x800575CC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
L_800575D0:
    // 0x800575D0: lwc1        $f16, 0x68CC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X68CC);
    // 0x800575D4: lwc1        $f12, 0x3C($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800575D8: mul.s       $f18, $f2, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800575DC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800575E0: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    // 0x800575E4: jr          $ra
    // 0x800575E8: add.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f18.fl;
    return;
    // 0x800575E8: add.s       $f0, $f12, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f0.fl = ctx->f12.fl + ctx->f18.fl;
;}
RECOMP_FUNC void menu_logos_screen_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80082AAC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80082AB0: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x80082AB4: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x80082AB8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80082ABC: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80082AC0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80082AC4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80082AC8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082ACC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082AD0: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80082AD4: jal         0x80077B5C
    // 0x80082AD8: swc1        $f4, 0x6450($at)
    MEM_W(0X6450, ctx->r1) = ctx->f4.u32l;
    bgdraw_fillcolour(rdram, ctx);
        goto after_0;
    // 0x80082AD8: swc1        $f4, 0x6450($at)
    MEM_W(0X6450, ctx->r1) = ctx->f4.u32l;
    after_0:
    // 0x80082ADC: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80082AE0: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80082AE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082AE8: bne         $t6, $zero, L_80082B30
    if (ctx->r14 != 0) {
        // 0x80082AEC: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_80082B30;
    }
    // 0x80082AEC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082AF0: addiu       $t7, $zero, 0xE0
    ctx->r15 = ADD32(0, 0XE0);
    // 0x80082AF4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80082AF8: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082AFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80082B00: addiu       $a2, $zero, 0x26
    ctx->r6 = ADD32(0, 0X26);
    // 0x80082B04: jal         0x80066940
    // 0x80082B08: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_1;
    // 0x80082B08: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_1:
    // 0x80082B0C: addiu       $t8, $zero, 0x11C
    ctx->r24 = ADD32(0, 0X11C);
    // 0x80082B10: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x80082B14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082B18: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80082B1C: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x80082B20: jal         0x80066AA8
    // 0x80082B24: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_2;
    // 0x80082B24: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_2:
    // 0x80082B28: b           L_80082B60
    // 0x80082B2C: nop

        goto L_80082B60;
    // 0x80082B2C: nop

L_80082B30:
    // 0x80082B30: addiu       $t9, $zero, 0xC4
    ctx->r25 = ADD32(0, 0XC4);
    // 0x80082B34: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80082B38: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    // 0x80082B3C: jal         0x80066940
    // 0x80082B40: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    viewport_menu_set(rdram, ctx);
        goto after_3;
    // 0x80082B40: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_3:
    // 0x80082B44: addiu       $t0, $zero, 0xF0
    ctx->r8 = ADD32(0, 0XF0);
    // 0x80082B48: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x80082B4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082B50: ori         $a1, $zero, 0x8000
    ctx->r5 = 0 | 0X8000;
    // 0x80082B54: ori         $a2, $zero, 0x8000
    ctx->r6 = 0 | 0X8000;
    // 0x80082B58: jal         0x80066AA8
    // 0x80082B5C: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    set_viewport_properties(rdram, ctx);
        goto after_4;
    // 0x80082B5C: addiu       $a3, $zero, 0x140
    ctx->r7 = ADD32(0, 0X140);
    after_4:
L_80082B60:
    // 0x80082B60: jal         0x80066610
    // 0x80082B64: nop

    copy_viewports_to_stack(rdram, ctx);
        goto after_5;
    // 0x80082B64: nop

    after_5:
    // 0x80082B68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80082B6C: jal         0x80066818
    // 0x80082B70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camEnableUserView(rdram, ctx);
        goto after_6;
    // 0x80082B70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_6:
    // 0x80082B74: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80082B78: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80082B7C: jr          $ra
    // 0x80082B80: nop

    return;
    // 0x80082B80: nop

;}
RECOMP_FUNC void _itoa_recomp(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B4940: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800B4944: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B4948: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B494C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B4950: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B4954: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800B4958: beq         $t6, $zero, L_800B496C
    if (ctx->r14 == 0) {
        // 0x800B495C: sw          $a1, 0x3C($sp)
        MEM_W(0X3C, ctx->r29) = ctx->r5;
            goto L_800B496C;
    }
    // 0x800B495C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    // 0x800B4960: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800B4964: b           L_800B4974
    // 0x800B4968: addiu       $s1, $s1, -0x73D8
    ctx->r17 = ADD32(ctx->r17, -0X73D8);
        goto L_800B4974;
    // 0x800B4968: addiu       $s1, $s1, -0x73D8
    ctx->r17 = ADD32(ctx->r17, -0X73D8);
L_800B496C:
    // 0x800B496C: lui         $s1, 0x800F
    ctx->r17 = S32(0X800F << 16);
    // 0x800B4970: addiu       $s1, $s1, -0x7400
    ctx->r17 = ADD32(ctx->r17, -0X7400);
L_800B4974:
    // 0x800B4974: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800B4978: lw          $t9, 0x3C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X3C);
    // 0x800B497C: or          $s0, $a2, $zero
    ctx->r16 = ctx->r6 | 0;
    // 0x800B4980: bne         $t8, $zero, L_800B4990
    if (ctx->r24 != 0) {
        // 0x800B4984: addiu       $t0, $zero, 0x0
        ctx->r8 = ADD32(0, 0X0);
            goto L_800B4990;
    }
    // 0x800B4984: addiu       $t0, $zero, 0x0
    ctx->r8 = ADD32(0, 0X0);
    // 0x800B4988: beq         $t9, $zero, L_800B49F4
    if (ctx->r25 == 0) {
        // 0x800B498C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B49F4;
    }
    // 0x800B498C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B4990:
    // 0x800B4990: sw          $t0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r8;
    // 0x800B4994: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
L_800B4998:
    // 0x800B4998: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
L_800B499C:
    // 0x800B499C: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B49A0: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800B49A4: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800B49A8: jal         0x800CEA8C
    // 0x800B49AC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    __ull_rem_recomp(rdram, ctx);
        goto after_0;
    // 0x800B49AC: addiu       $s0, $s0, -0x1
    ctx->r16 = ADD32(ctx->r16, -0X1);
    after_0:
    // 0x800B49B0: addu        $t2, $v1, $s1
    ctx->r10 = ADD32(ctx->r3, ctx->r17);
    // 0x800B49B4: lbu         $t3, 0x0($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0X0);
    // 0x800B49B8: nop

    // 0x800B49BC: sb          $t3, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r11;
    // 0x800B49C0: lw          $a3, 0x24($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X24);
    // 0x800B49C4: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x800B49C8: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800B49CC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B49D0: jal         0x800CEAC8
    // 0x800B49D4: nop

    __ull_div_recomp(rdram, ctx);
        goto after_1;
    // 0x800B49D4: nop

    after_1:
    // 0x800B49D8: sw          $v0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r2;
    // 0x800B49DC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B49E0: bne         $v0, $zero, L_800B4998
    if (ctx->r2 != 0) {
        // 0x800B49E4: or          $t5, $v1, $zero
        ctx->r13 = ctx->r3 | 0;
            goto L_800B4998;
    }
    // 0x800B49E4: or          $t5, $v1, $zero
    ctx->r13 = ctx->r3 | 0;
    // 0x800B49E8: bne         $t5, $zero, L_800B499C
    if (ctx->r13 != 0) {
        // 0x800B49EC: lw          $a0, 0x38($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X38);
            goto L_800B499C;
    }
    // 0x800B49EC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x800B49F0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B49F4:
    // 0x800B49F4: or          $v0, $s0, $zero
    ctx->r2 = ctx->r16 | 0;
    // 0x800B49F8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B49FC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B4A00: jr          $ra
    // 0x800B4A04: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800B4A04: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void guPerspective(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CCB50: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800CCB54: mtc1        $a2, $f12
    ctx->f12.u32l = ctx->r6;
    // 0x800CCB58: mtc1        $a3, $f14
    ctx->f14.u32l = ctx->r7;
    // 0x800CCB5C: lwc1        $f4, 0x78($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X78);
    // 0x800CCB60: lwc1        $f6, 0x7C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x800CCB64: lwc1        $f8, 0x80($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X80);
    // 0x800CCB68: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800CCB6C: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    // 0x800CCB70: mfc1        $a2, $f12
    ctx->r6 = (int32_t)ctx->f12.u32l;
    // 0x800CCB74: mfc1        $a3, $f14
    ctx->r7 = (int32_t)ctx->f14.u32l;
    // 0x800CCB78: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800CCB7C: swc1        $f4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f4.u32l;
    // 0x800CCB80: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800CCB84: jal         0x800CC920
    // 0x800CCB88: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    guPerspectiveF(rdram, ctx);
        goto after_0;
    // 0x800CCB88: swc1        $f8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f8.u32l;
    after_0:
    // 0x800CCB8C: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    // 0x800CCB90: jal         0x800D4840
    // 0x800CCB94: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    guMtxF2L(rdram, ctx);
        goto after_1;
    // 0x800CCB94: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    after_1:
    // 0x800CCB98: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800CCB9C: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x800CCBA0: jr          $ra
    // 0x800CCBA4: nop

    return;
    // 0x800CCBA4: nop

;}
RECOMP_FUNC void free_particle_assets(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AE490: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE494: lw          $a0, 0x2CEC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CEC);
    // 0x800AE498: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800AE49C: beq         $a0, $zero, L_800AE4B4
    if (ctx->r4 == 0) {
        // 0x800AE4A0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_800AE4B4;
    }
    // 0x800AE4A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800AE4A4: jal         0x80071140
    // 0x800AE4A8: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800AE4A8: nop

    after_0:
    // 0x800AE4AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE4B0: sw          $zero, 0x2CEC($at)
    MEM_W(0X2CEC, ctx->r1) = 0;
L_800AE4B4:
    // 0x800AE4B4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE4B8: lw          $a0, 0x2CF0($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CF0);
    // 0x800AE4BC: nop

    // 0x800AE4C0: beq         $a0, $zero, L_800AE4D8
    if (ctx->r4 == 0) {
        // 0x800AE4C4: nop
    
            goto L_800AE4D8;
    }
    // 0x800AE4C4: nop

    // 0x800AE4C8: jal         0x80071140
    // 0x800AE4CC: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x800AE4CC: nop

    after_1:
    // 0x800AE4D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE4D4: sw          $zero, 0x2CF0($at)
    MEM_W(0X2CF0, ctx->r1) = 0;
L_800AE4D8:
    // 0x800AE4D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE4DC: lw          $a0, 0x2CF8($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CF8);
    // 0x800AE4E0: nop

    // 0x800AE4E4: beq         $a0, $zero, L_800AE4FC
    if (ctx->r4 == 0) {
        // 0x800AE4E8: nop
    
            goto L_800AE4FC;
    }
    // 0x800AE4E8: nop

    // 0x800AE4EC: jal         0x80071140
    // 0x800AE4F0: nop

    mempool_free(rdram, ctx);
        goto after_2;
    // 0x800AE4F0: nop

    after_2:
    // 0x800AE4F4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE4F8: sw          $zero, 0x2CF8($at)
    MEM_W(0X2CF8, ctx->r1) = 0;
L_800AE4FC:
    // 0x800AE4FC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800AE500: lw          $a0, 0x2CFC($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X2CFC);
    // 0x800AE504: nop

    // 0x800AE508: beq         $a0, $zero, L_800AE524
    if (ctx->r4 == 0) {
        // 0x800AE50C: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800AE524;
    }
    // 0x800AE50C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800AE510: jal         0x80071140
    // 0x800AE514: nop

    mempool_free(rdram, ctx);
        goto after_3;
    // 0x800AE514: nop

    after_3:
    // 0x800AE518: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AE51C: sw          $zero, 0x2CFC($at)
    MEM_W(0X2CFC, ctx->r1) = 0;
    // 0x800AE520: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800AE524:
    // 0x800AE524: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800AE528: jr          $ra
    // 0x800AE52C: nop

    return;
    // 0x800AE52C: nop

;}
RECOMP_FUNC void recomp_entrypoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065D40: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065D44: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065D48: jal         0x800CC5A0
    // 0x80065D4C: nop

    osInitialize_recomp(rdram, ctx);
        goto after_0;
    // 0x80065D4C: nop

    after_0:
    // 0x80065D50: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80065D54: addiu       $t6, $t6, -0x28B0
    ctx->r14 = ADD32(ctx->r14, -0X28B0);
    // 0x80065D58: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065D5C: lui         $a2, 0x8006
    ctx->r6 = S32(0X8006 << 16);
    // 0x80065D60: addiu       $a2, $a2, 0x5D98
    ctx->r6 = ADD32(ctx->r6, 0X5D98);
    // 0x80065D64: addiu       $a0, $a0, -0x8A0
    ctx->r4 = ADD32(ctx->r4, -0X8A0);
    // 0x80065D68: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x80065D6C: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x80065D70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80065D74: jal         0x800C8850
    // 0x80065D78: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    osCreateThread_recomp(rdram, ctx);
        goto after_1;
    // 0x80065D78: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_1:
    // 0x80065D7C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80065D80: jal         0x800C89A0
    // 0x80065D84: addiu       $a0, $a0, -0x8A0
    ctx->r4 = ADD32(ctx->r4, -0X8A0);
    osStartThread_recomp(rdram, ctx);
        goto after_2;
    // 0x80065D84: addiu       $a0, $a0, -0x8A0
    ctx->r4 = ADD32(ctx->r4, -0X8A0);
    after_2:
    // 0x80065D88: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80065D8C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_shade_fast(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800245F0: lw          $a3, 0x54($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X54);
    // 0x800245F4: beq         $a3, $zero, L_8002473C
    if (ctx->r7 == 0) {
        // 0x800245F8: nop
    
            goto L_8002473C;
    }
    // 0x800245F8: nop

    // 0x800245FC: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80024600: mtc1        $a2, $f6
    ctx->f6.u32l = ctx->r6;
    // 0x80024604: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x80024608: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x8002460C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80024610: lh          $t0, 0x28($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X28);
    // 0x80024614: mul.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80024618: lw          $t5, 0x38($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X38);
    // 0x8002461C: lh          $t8, 0x1C($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X1C);
    // 0x80024620: lh          $t7, 0x1E($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X1E);
    // 0x80024624: lh          $t6, 0x20($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X20);
    // 0x80024628: lw          $a3, 0x40($a0)
    ctx->r7 = MEM_W(ctx->r4, 0X40);
    // 0x8002462C: lw          $a1, 0x44($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X44);
    // 0x80024630: mul.s       $f4, $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x80024634: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x80024638: nop

    // 0x8002463C: ori         $v1, $v0, 0x3
    ctx->r3 = ctx->r2 | 0X3;
    // 0x80024640: xori        $v1, $v1, 0x2
    ctx->r3 = ctx->r3 ^ 0X2;
    // 0x80024644: ctc1        $v1, $FpcCsr
    set_cop1_cs(ctx->r3);
    // 0x80024648: sll         $v1, $t0, 2
    ctx->r3 = S32(ctx->r8 << 2);
    // 0x8002464C: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80024650: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x80024654: sll         $v0, $t0, 3
    ctx->r2 = S32(ctx->r8 << 3);
    // 0x80024658: add         $a0, $v0, $v1
    ctx->r4 = ADD32(ctx->r2, ctx->r3);
    // 0x8002465C: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80024660: add         $a0, $a0, $t5
    ctx->r4 = ADD32(ctx->r4, ctx->r13);
    // 0x80024664: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
L_80024668:
    // 0x80024668: lh          $v0, 0x2($t5)
    ctx->r2 = MEM_H(ctx->r13, 0X2);
    // 0x8002466C: lh          $v1, 0xE($t5)
    ctx->r3 = MEM_H(ctx->r13, 0XE);
    // 0x80024670: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x80024674: bne         $t0, $at, L_800246A8
    if (ctx->r8 != ctx->r1) {
        // 0x80024678: sub         $t4, $v1, $v0
        ctx->r12 = SUB32(ctx->r3, ctx->r2);
            goto L_800246A8;
    }
    // 0x80024678: sub         $t4, $v1, $v0
    ctx->r12 = SUB32(ctx->r3, ctx->r2);
    // 0x8002467C: lw          $t1, 0x8($t5)
    ctx->r9 = MEM_W(ctx->r13, 0X8);
    // 0x80024680: sll         $v0, $t4, 3
    ctx->r2 = S32(ctx->r12 << 3);
    // 0x80024684: sll         $v1, $t4, 1
    ctx->r3 = S32(ctx->r12 << 1);
    // 0x80024688: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x8002468C: andi        $t1, $t1, 0x8000
    ctx->r9 = ctx->r9 & 0X8000;
    // 0x80024690: beq         $t1, $zero, L_8002472C
    if (ctx->r9 == 0) {
        // 0x80024694: add         $a1, $a1, $v0
        ctx->r5 = ADD32(ctx->r5, ctx->r2);
            goto L_8002472C;
    }
    // 0x80024694: add         $a1, $a1, $v0
    ctx->r5 = ADD32(ctx->r5, ctx->r2);
    // 0x80024698: sll         $v0, $t4, 2
    ctx->r2 = S32(ctx->r12 << 2);
    // 0x8002469C: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800246A0: b           L_8002472C
    // 0x800246A4: add         $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
        goto L_8002472C;
    // 0x800246A4: add         $a3, $a3, $v0
    ctx->r7 = ADD32(ctx->r7, ctx->r2);
L_800246A8:
    // 0x800246A8: lh          $t0, 0x0($a3)
    ctx->r8 = MEM_H(ctx->r7, 0X0);
    // 0x800246AC: mult        $t0, $t8
    result = S64(S32(ctx->r8)) * S64(S32(ctx->r24)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800246B0: mflo        $t9
    ctx->r25 = lo;
    // 0x800246B4: lh          $t1, 0x2($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X2);
    // 0x800246B8: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x800246BC: mult        $t1, $t7
    result = S64(S32(ctx->r9)) * S64(S32(ctx->r15)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800246C0: mflo        $v0
    ctx->r2 = lo;
    // 0x800246C4: lh          $t2, 0x4($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X4);
    // 0x800246C8: add         $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x800246CC: mult        $t2, $t6
    result = S64(S32(ctx->r10)) * S64(S32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800246D0: mflo        $v0
    ctx->r2 = lo;
    // 0x800246D4: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
    // 0x800246D8: add         $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x800246DC: sra         $t9, $t9, 11
    ctx->r25 = S32(SIGNED(ctx->r25) >> 11);
    // 0x800246E0: bgtz        $t9, L_800246F0
    if (SIGNED(ctx->r25) > 0) {
        // 0x800246E4: nop
    
            goto L_800246F0;
    }
    // 0x800246E4: nop

    // 0x800246E8: b           L_80024710
    // 0x800246EC: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
        goto L_80024710;
    // 0x800246EC: or          $t9, $a2, $zero
    ctx->r25 = ctx->r6 | 0;
L_800246F0:
    // 0x800246F0: mult        $t9, $a2
    result = S64(S32(ctx->r25)) * S64(S32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800246F4: mflo        $t9
    ctx->r25 = lo;
    // 0x800246F8: srl         $t9, $t9, 16
    ctx->r25 = S32(U32(ctx->r25) >> 16);
    // 0x800246FC: add         $t9, $t9, $a2
    ctx->r25 = ADD32(ctx->r25, ctx->r6);
    // 0x80024700: slti        $at, $t9, 0x100
    ctx->r1 = SIGNED(ctx->r25) < 0X100 ? 1 : 0;
    // 0x80024704: bnel        $at, $zero, L_80024714
    if (ctx->r1 != 0) {
        // 0x80024708: sll         $v0, $t9, 8
        ctx->r2 = S32(ctx->r25 << 8);
            goto L_80024714;
    }
    goto skip_0;
    // 0x80024708: sll         $v0, $t9, 8
    ctx->r2 = S32(ctx->r25 << 8);
    skip_0:
    // 0x8002470C: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
L_80024710:
    // 0x80024710: sll         $v0, $t9, 8
    ctx->r2 = S32(ctx->r25 << 8);
L_80024714:
    // 0x80024714: or          $t9, $t9, $v0
    ctx->r25 = ctx->r25 | ctx->r2;
    // 0x80024718: sh          $t9, 0x6($a1)
    MEM_H(0X6, ctx->r5) = ctx->r25;
    // 0x8002471C: ori         $t9, $t9, 0xFF
    ctx->r25 = ctx->r25 | 0XFF;
    // 0x80024720: sh          $t9, 0x8($a1)
    MEM_H(0X8, ctx->r5) = ctx->r25;
    // 0x80024724: bne         $t4, $zero, L_800246A8
    if (ctx->r12 != 0) {
        // 0x80024728: addiu       $a1, $a1, 0xA
        ctx->r5 = ADD32(ctx->r5, 0XA);
            goto L_800246A8;
    }
    // 0x80024728: addiu       $a1, $a1, 0xA
    ctx->r5 = ADD32(ctx->r5, 0XA);
L_8002472C:
    // 0x8002472C: addiu       $t5, $t5, 0xC
    ctx->r13 = ADD32(ctx->r13, 0XC);
    // 0x80024730: slt         $at, $t5, $a0
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x80024734: bnel        $at, $zero, L_80024668
    if (ctx->r1 != 0) {
        // 0x80024738: lbu         $t0, 0x6($t5)
        ctx->r8 = MEM_BU(ctx->r13, 0X6);
            goto L_80024668;
    }
    goto skip_1;
    // 0x80024738: lbu         $t0, 0x6($t5)
    ctx->r8 = MEM_BU(ctx->r13, 0X6);
    skip_1:
L_8002473C:
    // 0x8002473C: jr          $ra
    // 0x80024740: nop

    return;
    // 0x80024740: nop

;}
RECOMP_FUNC void obj_init_scenery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033CC0: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x80033CC4: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x80033CC8: ori         $t7, $t6, 0x2
    ctx->r15 = ctx->r14 | 0X2;
    // 0x80033CCC: sh          $t7, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r15;
    // 0x80033CD0: lbu         $t9, 0x9($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X9);
    // 0x80033CD4: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80033CD8: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80033CDC: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x80033CE0: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80033CE4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033CE8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80033CEC: nop

    // 0x80033CF0: bc1f        L_80033D00
    if (!c1cs) {
        // 0x80033CF4: nop
    
            goto L_80033D00;
    }
    // 0x80033CF4: nop

    // 0x80033CF8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80033CFC: nop

L_80033D00:
    // 0x80033D00: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80033D04: lw          $v0, 0x40($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X40);
    // 0x80033D08: lw          $t0, 0x50($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X50);
    // 0x80033D0C: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80033D10: nop

    // 0x80033D14: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80033D18: swc1        $f10, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f10.u32l;
    // 0x80033D1C: lwc1        $f16, 0x4($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X4);
    // 0x80033D20: nop

    // 0x80033D24: mul.s       $f18, $f16, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80033D28: swc1        $f18, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->f18.u32l;
    // 0x80033D2C: lbu         $t1, 0x8($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X8);
    // 0x80033D30: nop

    // 0x80033D34: sb          $t1, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = ctx->r9;
    // 0x80033D38: lbu         $t3, 0xA($a1)
    ctx->r11 = MEM_BU(ctx->r5, 0XA);
    // 0x80033D3C: nop

    // 0x80033D40: sll         $t4, $t3, 10
    ctx->r12 = S32(ctx->r11 << 10);
    // 0x80033D44: sh          $t4, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r12;
    // 0x80033D48: lbu         $t5, 0xB($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XB);
    // 0x80033D4C: nop

    // 0x80033D50: beq         $t5, $zero, L_80033DA4
    if (ctx->r13 == 0) {
        // 0x80033D54: nop
    
            goto L_80033DA4;
    }
    // 0x80033D54: nop

    // 0x80033D58: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x80033D5C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80033D60: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x80033D64: lw          $t9, 0x4C($a0)
    ctx->r25 = MEM_W(ctx->r4, 0X4C);
    // 0x80033D68: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80033D6C: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x80033D70: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x80033D74: addiu       $t0, $zero, 0x14
    ctx->r8 = ADD32(0, 0X14);
    // 0x80033D78: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x80033D7C: lw          $t2, 0x4C($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X4C);
    // 0x80033D80: addiu       $t3, $zero, -0x5
    ctx->r11 = ADD32(0, -0X5);
    // 0x80033D84: sb          $zero, 0x12($t2)
    MEM_B(0X12, ctx->r10) = 0;
    // 0x80033D88: lw          $t4, 0x4C($a0)
    ctx->r12 = MEM_W(ctx->r4, 0X4C);
    // 0x80033D8C: nop

    // 0x80033D90: sb          $t3, 0x16($t4)
    MEM_B(0X16, ctx->r12) = ctx->r11;
    // 0x80033D94: lw          $t6, 0x4C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X4C);
    // 0x80033D98: lbu         $t5, 0xB($a1)
    ctx->r13 = MEM_BU(ctx->r5, 0XB);
    // 0x80033D9C: nop

    // 0x80033DA0: sb          $t5, 0x17($t6)
    MEM_B(0X17, ctx->r14) = ctx->r13;
L_80033DA4:
    // 0x80033DA4: lw          $t8, 0x40($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X40);
    // 0x80033DA8: lb          $t7, 0x3A($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X3A);
    // 0x80033DAC: lb          $t9, 0x55($t8)
    ctx->r25 = MEM_B(ctx->r24, 0X55);
    // 0x80033DB0: nop

    // 0x80033DB4: slt         $at, $t7, $t9
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80033DB8: bne         $at, $zero, L_80033DC4
    if (ctx->r1 != 0) {
        // 0x80033DBC: nop
    
            goto L_80033DC4;
    }
    // 0x80033DBC: nop

    // 0x80033DC0: sb          $zero, 0x3A($a0)
    MEM_B(0X3A, ctx->r4) = 0;
L_80033DC4:
    // 0x80033DC4: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x80033DC8: jr          $ra
    // 0x80033DCC: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
    return;
    // 0x80033DCC: sw          $zero, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = 0;
;}
RECOMP_FUNC void dialogue_try_close(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CFB0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009CFB4: addiu       $v0, $v0, -0xB20
    ctx->r2 = ADD32(ctx->r2, -0XB20);
    // 0x8009CFB8: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8009CFBC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009CFC0: beq         $t6, $zero, L_8009CFDC
    if (ctx->r14 == 0) {
        // 0x8009CFC4: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8009CFDC;
    }
    // 0x8009CFC4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8009CFC8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8009CFCC: jal         0x800C5620
    // 0x8009CFD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_close(rdram, ctx);
        goto after_0;
    // 0x8009CFD0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_0:
    // 0x8009CFD4: jal         0x8009BE5C
    // 0x8009CFD8: nop

    reset_controller_sticks(rdram, ctx);
        goto after_1;
    // 0x8009CFD8: nop

    after_1:
L_8009CFDC:
    // 0x8009CFDC: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8009CFE0: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8009CFE4: jr          $ra
    // 0x8009CFE8: nop

    return;
    // 0x8009CFE8: nop

;}
RECOMP_FUNC void level_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BD98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006BD9C: lw          $t6, 0x1168($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X1168);
    // 0x8006BDA0: nop

    // 0x8006BDA4: lbu         $v0, 0x4C($t6)
    ctx->r2 = MEM_BU(ctx->r14, 0X4C);
    // 0x8006BDA8: jr          $ra
    // 0x8006BDAC: nop

    return;
    // 0x8006BDAC: nop

;}
RECOMP_FUNC void parse_string_with_number(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C5F60: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C5F64: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800C5F68: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C5F6C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C5F70: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C5F74: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C5F78: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C5F7C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x800C5F80: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800C5F84: beq         $v0, $zero, L_800C5FD8
    if (ctx->r2 == 0) {
        // 0x800C5F88: or          $s3, $a2, $zero
        ctx->r19 = ctx->r6 | 0;
            goto L_800C5FD8;
    }
    // 0x800C5F88: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x800C5F8C: addiu       $s2, $sp, 0x2C
    ctx->r18 = ADD32(ctx->r29, 0X2C);
    // 0x800C5F90: addiu       $s1, $zero, 0x7E
    ctx->r17 = ADD32(0, 0X7E);
L_800C5F94:
    // 0x800C5F94: bne         $s1, $v0, L_800C5FAC
    if (ctx->r17 != ctx->r2) {
        // 0x800C5F98: or          $a0, $s2, $zero
        ctx->r4 = ctx->r18 | 0;
            goto L_800C5FAC;
    }
    // 0x800C5F98: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800C5F9C: jal         0x800C580C
    // 0x800C5FA0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    s32_to_string(rdram, ctx);
        goto after_0;
    // 0x800C5FA0: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_0:
    // 0x800C5FA4: b           L_800C5FC8
    // 0x800C5FA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
        goto L_800C5FC8;
    // 0x800C5FA8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C5FAC:
    // 0x800C5FAC: lw          $t6, 0x2C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5FB0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C5FB4: sb          $v0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r2;
    // 0x800C5FB8: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5FBC: nop

    // 0x800C5FC0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800C5FC4: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
L_800C5FC8:
    // 0x800C5FC8: lbu         $v0, 0x0($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0X0);
    // 0x800C5FCC: nop

    // 0x800C5FD0: bne         $v0, $zero, L_800C5F94
    if (ctx->r2 != 0) {
        // 0x800C5FD4: nop
    
            goto L_800C5F94;
    }
    // 0x800C5FD4: nop

L_800C5FD8:
    // 0x800C5FD8: lw          $t9, 0x2C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X2C);
    // 0x800C5FDC: nop

    // 0x800C5FE0: sb          $zero, 0x0($t9)
    MEM_B(0X0, ctx->r25) = 0;
    // 0x800C5FE4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800C5FE8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C5FEC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C5FF0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C5FF4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C5FF8: jr          $ra
    // 0x800C5FFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800C5FFC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void wavegen_destroy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF3E4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BF3E8: lw          $t6, 0x3190($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3190);
    // 0x800BF3EC: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x800BF3F0: beq         $t6, $zero, L_800BF51C
    if (ctx->r14 == 0) {
        // 0x800BF3F4: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800BF51C;
    }
    // 0x800BF3F4: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800BF3F8: addiu       $t0, $t0, 0x3188
    ctx->r8 = ADD32(ctx->r8, 0X3188);
    // 0x800BF3FC: lw          $a0, 0x0($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X0);
    // 0x800BF400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800BF404: blez        $a0, L_800BF440
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800BF408: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BF440;
    }
    // 0x800BF408: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF40C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800BF410: lw          $t7, 0x3194($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X3194);
    // 0x800BF414: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800BF418: addu        $a2, $t7, $t8
    ctx->r6 = ADD32(ctx->r15, ctx->r24);
L_800BF41C:
    // 0x800BF41C: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800BF420: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800BF424: bne         $a1, $t9, L_800BF430
    if (ctx->r5 != ctx->r25) {
        // 0x800BF428: slt         $at, $v0, $a0
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_800BF430;
    }
    // 0x800BF428: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BF42C: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_800BF430:
    // 0x800BF430: beq         $at, $zero, L_800BF440
    if (ctx->r1 == 0) {
        // 0x800BF434: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_800BF440;
    }
    // 0x800BF434: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x800BF438: beq         $v1, $zero, L_800BF41C
    if (ctx->r3 == 0) {
        // 0x800BF43C: nop
    
            goto L_800BF41C;
    }
    // 0x800BF43C: nop

L_800BF440:
    // 0x800BF440: beq         $v1, $zero, L_800BF51C
    if (ctx->r3 == 0) {
        // 0x800BF444: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800BF51C;
    }
    // 0x800BF444: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800BF448: addiu       $t1, $t1, 0x318C
    ctx->r9 = ADD32(ctx->r9, 0X318C);
    // 0x800BF44C: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800BF450: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x800BF454: blez        $t5, L_800BF4F8
    if (SIGNED(ctx->r13) <= 0) {
        // 0x800BF458: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BF4F8;
    }
    // 0x800BF458: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF45C: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800BF460: addiu       $t2, $t2, 0x3184
    ctx->r10 = ADD32(ctx->r10, 0X3184);
    // 0x800BF464: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x800BF468: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
L_800BF46C:
    // 0x800BF46C: lw          $t7, 0x0($t2)
    ctx->r15 = MEM_W(ctx->r10, 0X0);
    // 0x800BF470: sll         $t6, $v1, 3
    ctx->r14 = S32(ctx->r3 << 3);
    // 0x800BF474: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800BF478: lbu         $t8, 0x0($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X0);
    // 0x800BF47C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800BF480: beq         $t3, $t8, L_800BF4E4
    if (ctx->r11 == ctx->r24) {
        // 0x800BF484: nop
    
            goto L_800BF4E4;
    }
    // 0x800BF484: nop

    // 0x800BF488: lbu         $a3, 0x0($a1)
    ctx->r7 = MEM_BU(ctx->r5, 0X0);
    // 0x800BF48C: addu        $a2, $a1, $zero
    ctx->r6 = ADD32(ctx->r5, 0);
L_800BF490:
    // 0x800BF490: bne         $v0, $a3, L_800BF4C4
    if (ctx->r2 != ctx->r7) {
        // 0x800BF494: slti        $at, $a0, 0x7
        ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
            goto L_800BF4C4;
    }
    // 0x800BF494: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x800BF498: beq         $at, $zero, L_800BF4B8
    if (ctx->r1 == 0) {
        // 0x800BF49C: nop
    
            goto L_800BF4B8;
    }
    // 0x800BF49C: nop

L_800BF4A0:
    // 0x800BF4A0: lbu         $t9, 0x1($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0X1);
    // 0x800BF4A4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BF4A8: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x800BF4AC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BF4B0: bne         $at, $zero, L_800BF4A0
    if (ctx->r1 != 0) {
        // 0x800BF4B4: sb          $t9, -0x1($a2)
        MEM_B(-0X1, ctx->r6) = ctx->r25;
            goto L_800BF4A0;
    }
    // 0x800BF4B4: sb          $t9, -0x1($a2)
    MEM_B(-0X1, ctx->r6) = ctx->r25;
L_800BF4B8:
    // 0x800BF4B8: sb          $t4, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r12;
    // 0x800BF4BC: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BF4C0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800BF4C4:
    // 0x800BF4C4: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x800BF4C8: slti        $at, $a0, 0x8
    ctx->r1 = SIGNED(ctx->r4) < 0X8 ? 1 : 0;
    // 0x800BF4CC: beq         $at, $zero, L_800BF4E4
    if (ctx->r1 == 0) {
        // 0x800BF4D0: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_800BF4E4;
    }
    // 0x800BF4D0: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800BF4D4: lbu         $a3, 0x0($a2)
    ctx->r7 = MEM_BU(ctx->r6, 0X0);
    // 0x800BF4D8: nop

    // 0x800BF4DC: bne         $t3, $a3, L_800BF490
    if (ctx->r11 != ctx->r7) {
        // 0x800BF4E0: nop
    
            goto L_800BF490;
    }
    // 0x800BF4E0: nop

L_800BF4E4:
    // 0x800BF4E4: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800BF4E8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BF4EC: slt         $at, $v1, $t5
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800BF4F0: bne         $at, $zero, L_800BF46C
    if (ctx->r1 != 0) {
        // 0x800BF4F4: nop
    
            goto L_800BF46C;
    }
    // 0x800BF4F4: nop

L_800BF4F8:
    // 0x800BF4F8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BF4FC: lw          $t6, 0x3194($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3194);
    // 0x800BF500: sll         $t7, $v1, 2
    ctx->r15 = S32(ctx->r3 << 2);
    // 0x800BF504: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800BF508: sw          $zero, 0x0($t8)
    MEM_W(0X0, ctx->r24) = 0;
    // 0x800BF50C: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x800BF510: nop

    // 0x800BF514: addiu       $t5, $t9, -0x1
    ctx->r13 = ADD32(ctx->r25, -0X1);
    // 0x800BF518: sw          $t5, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r13;
L_800BF51C:
    // 0x800BF51C: jr          $ra
    // 0x800BF520: nop

    return;
    // 0x800BF520: nop

;}
RECOMP_FUNC void gfxtask_run_xbus2(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800775B0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800775B4: addiu       $v1, $v1, -0x1B28
    ctx->r3 = ADD32(ctx->r3, -0X1B28);
    // 0x800775B8: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800775BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800775C0: sll         $t6, $v0, 3
    ctx->r14 = S32(ctx->r2 << 3);
    // 0x800775C4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800775C8: subu        $t6, $t6, $v0
    ctx->r14 = SUB32(ctx->r14, ctx->r2);
    // 0x800775CC: sll         $t6, $t6, 4
    ctx->r14 = S32(ctx->r14 << 4);
    // 0x800775D0: addiu       $t7, $t7, 0x6020
    ctx->r15 = ADD32(ctx->r15, 0X6020);
    // 0x800775D4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800775D8: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x800775DC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800775E0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x800775E4: sw          $zero, 0x20($sp)
    MEM_W(0X20, ctx->r29) = 0;
    // 0x800775E8: addu        $a3, $t6, $t7
    ctx->r7 = ADD32(ctx->r14, ctx->r15);
    // 0x800775EC: bne         $t8, $at, L_800775F8
    if (ctx->r24 != ctx->r1) {
        // 0x800775F0: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_800775F8;
    }
    // 0x800775F0: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800775F4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800775F8:
    // 0x800775F8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800775FC: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x80077600: addiu       $v0, $v0, -0x7B40
    ctx->r2 = ADD32(ctx->r2, -0X7B40);
    // 0x80077604: subu        $t0, $a1, $a0
    ctx->r8 = SUB32(ctx->r5, ctx->r4);
    // 0x80077608: addiu       $t5, $t5, -0x7A70
    ctx->r13 = ADD32(ctx->r13, -0X7A70);
    // 0x8007760C: sra         $t1, $t0, 3
    ctx->r9 = S32(SIGNED(ctx->r8) >> 3);
    // 0x80077610: subu        $t6, $t5, $v0
    ctx->r14 = SUB32(ctx->r13, ctx->r2);
    // 0x80077614: sll         $t2, $t1, 3
    ctx->r10 = S32(ctx->r9 << 3);
    // 0x80077618: sw          $t2, 0x44($a3)
    MEM_W(0X44, ctx->r7) = ctx->r10;
    // 0x8007761C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x80077620: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x80077624: sw          $t6, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = ctx->r14;
    // 0x80077628: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007762C: sw          $t3, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->r11;
    // 0x80077630: sw          $t4, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->r12;
    // 0x80077634: addiu       $t7, $t7, -0x5690
    ctx->r15 = ADD32(ctx->r15, -0X5690);
    // 0x80077638: lui         $t8, 0x800F
    ctx->r24 = S32(0X800F << 16);
    // 0x8007763C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80077640: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80077644: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80077648: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x8007764C: sw          $t7, 0x20($a3)
    MEM_W(0X20, ctx->r7) = ctx->r15;
    // 0x80077650: addiu       $t8, $t8, -0x5460
    ctx->r24 = ADD32(ctx->r24, -0X5460);
    // 0x80077654: addiu       $t9, $zero, 0x800
    ctx->r25 = ADD32(0, 0X800);
    // 0x80077658: addiu       $t0, $t0, 0x42A0
    ctx->r8 = ADD32(ctx->r8, 0X42A0);
    // 0x8007765C: addiu       $t1, $zero, 0x400
    ctx->r9 = ADD32(0, 0X400);
    // 0x80077660: addiu       $t2, $t2, 0x71B0
    ctx->r10 = ADD32(ctx->r10, 0X71B0);
    // 0x80077664: addiu       $t3, $zero, 0xA00
    ctx->r11 = ADD32(0, 0XA00);
    // 0x80077668: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8007766C: addiu       $t5, $t5, 0x5ED8
    ctx->r13 = ADD32(ctx->r13, 0X5ED8);
    // 0x80077670: addiu       $t6, $t6, -0x1B70
    ctx->r14 = ADD32(ctx->r14, -0X1B70);
    // 0x80077674: sw          $a0, 0x40($a3)
    MEM_W(0X40, ctx->r7) = ctx->r4;
    // 0x80077678: sw          $v0, 0x18($a3)
    MEM_W(0X18, ctx->r7) = ctx->r2;
    // 0x8007767C: sw          $t8, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->r24;
    // 0x80077680: sw          $t9, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = ctx->r25;
    // 0x80077684: sw          $t0, 0x30($a3)
    MEM_W(0X30, ctx->r7) = ctx->r8;
    // 0x80077688: sw          $t1, 0x34($a3)
    MEM_W(0X34, ctx->r7) = ctx->r9;
    // 0x8007768C: sw          $t2, 0x48($a3)
    MEM_W(0X48, ctx->r7) = ctx->r10;
    // 0x80077690: sw          $t3, 0x4C($a3)
    MEM_W(0X4C, ctx->r7) = ctx->r11;
    // 0x80077694: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x80077698: sw          $zero, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = 0;
    // 0x8007769C: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800776A0: sw          $t4, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->r12;
    // 0x800776A4: sw          $t5, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r13;
    // 0x800776A8: sw          $t6, 0x54($a3)
    MEM_W(0X54, ctx->r7) = ctx->r14;
    // 0x800776AC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800776B0: lw          $t7, 0x62D4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X62D4);
    // 0x800776B4: lui         $v0, 0xFF00
    ctx->r2 = S32(0XFF00 << 16);
    // 0x800776B8: ori         $v0, $v0, 0xFF
    ctx->r2 = ctx->r2 | 0XFF;
    // 0x800776BC: addiu       $v1, $zero, 0xFF
    ctx->r3 = ADD32(0, 0XFF);
    // 0x800776C0: sw          $v0, 0x58($a3)
    MEM_W(0X58, ctx->r7) = ctx->r2;
    // 0x800776C4: sw          $v0, 0x5C($a3)
    MEM_W(0X5C, ctx->r7) = ctx->r2;
    // 0x800776C8: sw          $v1, 0x60($a3)
    MEM_W(0X60, ctx->r7) = ctx->r3;
    // 0x800776CC: sw          $v1, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r3;
    // 0x800776D0: sw          $zero, 0x68($a3)
    MEM_W(0X68, ctx->r7) = 0;
    // 0x800776D4: sw          $t7, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->r15;
    // 0x800776D8: lw          $t8, 0x30($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X30);
    // 0x800776DC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800776E0: beq         $t8, $zero, L_800776EC
    if (ctx->r24 == 0) {
        // 0x800776E4: addiu       $t9, $t9, 0x5EA0
        ctx->r25 = ADD32(ctx->r25, 0X5EA0);
            goto L_800776EC;
    }
    // 0x800776E4: addiu       $t9, $t9, 0x5EA0
    ctx->r25 = ADD32(ctx->r25, 0X5EA0);
    // 0x800776E8: sw          $t9, 0x50($a3)
    MEM_W(0X50, ctx->r7) = ctx->r25;
L_800776EC:
    // 0x800776EC: jal         0x800D18A0
    // 0x800776F0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    osWritebackDCacheAll_recomp(rdram, ctx);
        goto after_0;
    // 0x800776F0: sw          $a3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r7;
    after_0:
    // 0x800776F4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800776F8: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x800776FC: lw          $a0, 0x6100($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6100);
    // 0x80077700: jal         0x800C8E30
    // 0x80077704: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osSendMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80077704: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80077708: lw          $t0, 0x30($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X30);
    // 0x8007770C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80077710: beq         $t0, $zero, L_80077724
    if (ctx->r8 == 0) {
        // 0x80077714: addiu       $a0, $a0, 0x5EA0
        ctx->r4 = ADD32(ctx->r4, 0X5EA0);
            goto L_80077724;
    }
    // 0x80077714: addiu       $a0, $a0, 0x5EA0
    ctx->r4 = ADD32(ctx->r4, 0X5EA0);
    // 0x80077718: addiu       $a1, $sp, 0x20
    ctx->r5 = ADD32(ctx->r29, 0X20);
    // 0x8007771C: jal         0x800C8BB0
    // 0x80077720: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_2;
    // 0x80077720: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_2:
L_80077724:
    // 0x80077724: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80077728: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007772C: jr          $ra
    // 0x80077730: nop

    return;
    // 0x80077730: nop

;}
RECOMP_FUNC void track_setup_racers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CC7C: addiu       $sp, $sp, -0x150
    ctx->r29 = ADD32(ctx->r29, -0X150);
    // 0x8000CC80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CC84: sb          $zero, -0x52E0($at)
    MEM_B(-0X52E0, ctx->r1) = 0;
    // 0x8000CC88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CC8C: sw          $zero, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = 0;
    // 0x8000CC90: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CC94: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000CC98: sb          $zero, -0x523C($at)
    MEM_B(-0X523C, ctx->r1) = 0;
    // 0x8000CC9C: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000CCA0: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8000CCA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CCA8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8000CCAC: addiu       $s1, $s1, -0x5100
    ctx->r17 = ADD32(ctx->r17, -0X5100);
    // 0x8000CCB0: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8000CCB4: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8000CCB8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000CCBC: sw          $zero, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = 0;
    // 0x8000CCC0: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8000CCC4: or          $s3, $a2, $zero
    ctx->r19 = ctx->r6 | 0;
    // 0x8000CCC8: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8000CCCC: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8000CCD0: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8000CCD4: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8000CCD8: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000CCDC: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    // 0x8000CCE0: jal         0x800521B8
    // 0x8000CCE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_taj_status(rdram, ctx);
        goto after_0;
    // 0x8000CCE4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8000CCE8: jal         0x8006BDB0
    // 0x8000CCEC: nop

    level_header(rdram, ctx);
        goto after_1;
    // 0x8000CCEC: nop

    after_1:
    // 0x8000CCF0: sw          $v0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r2;
    // 0x8000CCF4: lbu         $v1, 0x4C($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X4C);
    // 0x8000CCF8: addiu       $s6, $zero, 0x6
    ctx->r22 = ADD32(0, 0X6);
    // 0x8000CCFC: beq         $s6, $v1, L_8000E080
    if (ctx->r22 == ctx->r3) {
        // 0x8000CD00: or          $a0, $v1, $zero
        ctx->r4 = ctx->r3 | 0;
            goto L_8000E080;
    }
    // 0x8000CD00: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8000CD04: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000CD08: beq         $v1, $at, L_8000E080
    if (ctx->r3 == ctx->r1) {
        // 0x8000CD0C: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_8000E080;
    }
    // 0x8000CD0C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8000CD10: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000CD14: beq         $v1, $at, L_8000CD20
    if (ctx->r3 == ctx->r1) {
        // 0x8000CD18: andi        $t6, $v1, 0x40
        ctx->r14 = ctx->r3 & 0X40;
            goto L_8000CD20;
    }
    // 0x8000CD18: andi        $t6, $v1, 0x40
    ctx->r14 = ctx->r3 & 0X40;
    // 0x8000CD1C: beq         $t6, $zero, L_8000CD34
    if (ctx->r14 == 0) {
        // 0x8000CD20: lui         $s4, 0x8012
        ctx->r20 = S32(0X8012 << 16);
            goto L_8000CD34;
    }
L_8000CD20:
    // 0x8000CD20: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8000CD24: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CD28: addiu       $s4, $s4, -0x510C
    ctx->r20 = ADD32(ctx->r20, -0X510C);
    // 0x8000CD2C: sb          $zero, -0x510B($at)
    MEM_B(-0X510B, ctx->r1) = 0;
    // 0x8000CD30: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
L_8000CD34:
    // 0x8000CD34: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8000CD38: addiu       $s4, $s4, -0x510C
    ctx->r20 = ADD32(ctx->r20, -0X510C);
    // 0x8000CD3C: sw          $t7, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r15;
    // 0x8000CD40: jal         0x8000E4C8
    // 0x8000CD44: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    is_time_trial_enabled(rdram, ctx);
        goto after_2;
    // 0x8000CD44: sw          $a0, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r4;
    after_2:
    // 0x8000CD48: beq         $v0, $zero, L_8000CD7C
    if (ctx->r2 == 0) {
        // 0x8000CD4C: nop
    
            goto L_8000CD7C;
    }
    // 0x8000CD4C: nop

    // 0x8000CD50: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000CD54: nop

    // 0x8000CD58: bne         $t8, $zero, L_8000CD7C
    if (ctx->r24 != 0) {
        // 0x8000CD5C: nop
    
            goto L_8000CD7C;
    }
    // 0x8000CD5C: nop

    // 0x8000CD60: jal         0x80069D7C
    // 0x8000CD64: nop

    cam_get_cameras(rdram, ctx);
        goto after_3;
    // 0x8000CD64: nop

    after_3:
    // 0x8000CD68: sw          $v0, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r2;
    // 0x8000CD6C: lbu         $t9, 0x3B($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X3B);
    // 0x8000CD70: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000CD74: sw          $t9, 0x130($sp)
    MEM_W(0X130, ctx->r29) = ctx->r25;
    // 0x8000CD78: sb          $t5, 0x3B($v0)
    MEM_B(0X3B, ctx->r2) = ctx->r13;
L_8000CD7C:
    // 0x8000CD7C: jal         0x8006DA0C
    // 0x8000CD80: nop

    get_game_mode(rdram, ctx);
        goto after_4;
    // 0x8000CD80: nop

    after_4:
    // 0x8000CD84: jal         0x8006EA90
    // 0x8000CD88: sw          $v0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r2;
    get_settings(rdram, ctx);
        goto after_5;
    // 0x8000CD88: sw          $v0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r2;
    after_5:
    // 0x8000CD8C: or          $s7, $v0, $zero
    ctx->r23 = ctx->r2 | 0;
    // 0x8000CD90: jal         0x8001E29C
    // 0x8000CD94: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    get_misc_asset(rdram, ctx);
        goto after_6;
    // 0x8000CD94: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_6:
    // 0x8000CD98: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000CD9C: addiu       $t3, $t3, -0x523B
    ctx->r11 = ADD32(ctx->r11, -0X523B);
    // 0x8000CDA0: lb          $t6, 0x0($t3)
    ctx->r14 = MEM_B(ctx->r11, 0X0);
    // 0x8000CDA4: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8000CDA8: addiu       $t4, $t4, -0x517E
    ctx->r12 = ADD32(ctx->r12, -0X517E);
    // 0x8000CDAC: sw          $v0, 0x128($sp)
    MEM_W(0X128, ctx->r29) = ctx->r2;
    // 0x8000CDB0: sh          $t6, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r14;
    // 0x8000CDB4: lbu         $t8, 0x49($s7)
    ctx->r24 = MEM_BU(ctx->r23, 0X49);
    // 0x8000CDB8: lw          $t7, 0x4($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X4);
    // 0x8000CDBC: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000CDC0: addu        $v1, $t7, $t9
    ctx->r3 = ADD32(ctx->r15, ctx->r25);
    // 0x8000CDC4: lw          $a0, 0x0($v1)
    ctx->r4 = MEM_W(ctx->r3, 0X0);
    // 0x8000CDC8: addiu       $v0, $sp, 0xB4
    ctx->r2 = ADD32(ctx->r29, 0XB4);
    // 0x8000CDCC: andi        $t5, $a0, 0x1
    ctx->r13 = ctx->r4 & 0X1;
    // 0x8000CDD0: bne         $t5, $zero, L_8000CDE8
    if (ctx->r13 != 0) {
        // 0x8000CDD4: addiu       $a1, $sp, 0xD4
        ctx->r5 = ADD32(ctx->r29, 0XD4);
            goto L_8000CDE8;
    }
    // 0x8000CDD4: addiu       $a1, $sp, 0xD4
    ctx->r5 = ADD32(ctx->r29, 0XD4);
    // 0x8000CDD8: ori         $t6, $a0, 0x1
    ctx->r14 = ctx->r4 | 0X1;
    // 0x8000CDDC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x8000CDE0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8000CDE4: sb          $t8, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r24;
L_8000CDE8:
    // 0x8000CDE8: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8000CDEC: addiu       $v1, $sp, 0xF4
    ctx->r3 = ADD32(ctx->r29, 0XF4);
    // 0x8000CDF0: beq         $t7, $zero, L_8000CE00
    if (ctx->r15 == 0) {
        // 0x8000CDF4: addiu       $a0, $sp, 0xD4
        ctx->r4 = ADD32(ctx->r29, 0XD4);
            goto L_8000CE00;
    }
    // 0x8000CDF4: addiu       $a0, $sp, 0xD4
    ctx->r4 = ADD32(ctx->r29, 0XD4);
    // 0x8000CDF8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000CDFC: sb          $t9, 0x0($s1)
    MEM_B(0X0, ctx->r17) = ctx->r25;
L_8000CE00:
    // 0x8000CE00: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8000CE04: sltu        $at, $v0, $a1
    ctx->r1 = ctx->r2 < ctx->r5 ? 1 : 0;
    // 0x8000CE08: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000CE0C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000CE10: sw          $zero, -0x4($v1)
    MEM_W(-0X4, ctx->r3) = 0;
    // 0x8000CE14: sw          $zero, -0x4($a0)
    MEM_W(-0X4, ctx->r4) = 0;
    // 0x8000CE18: bne         $at, $zero, L_8000CE00
    if (ctx->r1 != 0) {
        // 0x8000CE1C: sw          $zero, -0x4($v0)
        MEM_W(-0X4, ctx->r2) = 0;
            goto L_8000CE00;
    }
    // 0x8000CE1C: sw          $zero, -0x4($v0)
    MEM_W(-0X4, ctx->r2) = 0;
    // 0x8000CE20: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000CE24: lw          $v0, -0x51A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A4);
    // 0x8000CE28: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000CE2C: blez        $v0, L_8000CF70
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000CE30: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_8000CF70;
    }
    // 0x8000CE30: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000CE34: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8000CE38: lw          $a0, -0x51A8($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X51A8);
    // 0x8000CE3C: sll         $a1, $v0, 2
    ctx->r5 = S32(ctx->r2 << 2);
    // 0x8000CE40: addiu       $t2, $sp, 0x94
    ctx->r10 = ADD32(ctx->r29, 0X94);
    // 0x8000CE44: addiu       $t1, $sp, 0xB4
    ctx->r9 = ADD32(ctx->r29, 0XB4);
    // 0x8000CE48: addiu       $t0, $sp, 0xD4
    ctx->r8 = ADD32(ctx->r29, 0XD4);
    // 0x8000CE4C: addiu       $a3, $sp, 0xF4
    ctx->r7 = ADD32(ctx->r29, 0XF4);
    // 0x8000CE50: addiu       $a2, $zero, 0xB
    ctx->r6 = ADD32(0, 0XB);
L_8000CE54:
    // 0x8000CE54: lw          $s1, 0x0($a0)
    ctx->r17 = MEM_W(ctx->r4, 0X0);
    // 0x8000CE58: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8000CE5C: lh          $t5, 0x6($s1)
    ctx->r13 = MEM_H(ctx->r17, 0X6);
    // 0x8000CE60: nop

    // 0x8000CE64: andi        $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 & 0X8000;
    // 0x8000CE68: bne         $t6, $zero, L_8000CF64
    if (ctx->r14 != 0) {
        // 0x8000CE6C: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CE6C: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CE70: lh          $t8, 0x48($s1)
    ctx->r24 = MEM_H(ctx->r17, 0X48);
    // 0x8000CE74: nop

    // 0x8000CE78: bne         $a2, $t8, L_8000CF64
    if (ctx->r6 != ctx->r24) {
        // 0x8000CE7C: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CE7C: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CE80: lw          $t7, 0x7C($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X7C);
    // 0x8000CE84: nop

    // 0x8000CE88: bne         $s0, $t7, L_8000CF64
    if (ctx->r16 != ctx->r15) {
        // 0x8000CE8C: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CE8C: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CE90: lw          $v0, 0x78($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X78);
    // 0x8000CE94: nop

    // 0x8000CE98: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8000CE9C: beq         $at, $zero, L_8000CF44
    if (ctx->r1 == 0) {
        // 0x8000CEA0: nop
    
            goto L_8000CF44;
    }
    // 0x8000CEA0: nop

    // 0x8000CEA4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000CEA8: lwc1        $f4, 0xC($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8000CEAC: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8000CEB0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000CEB4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000CEB8: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8000CEBC: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8000CEC0: addu        $t8, $a3, $t6
    ctx->r24 = ADD32(ctx->r7, ctx->r14);
    // 0x8000CEC4: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000CEC8: mfc1        $t5, $f6
    ctx->r13 = (int32_t)ctx->f6.u32l;
    // 0x8000CECC: nop

    // 0x8000CED0: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x8000CED4: sw          $t5, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r13;
    // 0x8000CED8: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000CEDC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000CEE0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000CEE4: lwc1        $f8, 0x10($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X10);
    // 0x8000CEE8: lw          $t6, 0x78($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X78);
    // 0x8000CEEC: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8000CEF0: sll         $t5, $t6, 2
    ctx->r13 = S32(ctx->r14 << 2);
    // 0x8000CEF4: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8000CEF8: addu        $t8, $t0, $t5
    ctx->r24 = ADD32(ctx->r8, ctx->r13);
    // 0x8000CEFC: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x8000CF00: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8000CF04: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000CF08: sw          $t9, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r25;
    // 0x8000CF0C: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8000CF10: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000CF14: lw          $t5, 0x78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X78);
    // 0x8000CF18: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8000CF1C: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8000CF20: mfc1        $t6, $f18
    ctx->r14 = (int32_t)ctx->f18.u32l;
    // 0x8000CF24: addu        $t8, $t1, $t9
    ctx->r24 = ADD32(ctx->r9, ctx->r25);
    // 0x8000CF28: sw          $t6, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r14;
    // 0x8000CF2C: lw          $t5, 0x78($s1)
    ctx->r13 = MEM_W(ctx->r17, 0X78);
    // 0x8000CF30: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x8000CF34: lh          $t7, 0x0($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X0);
    // 0x8000CF38: sll         $t9, $t5, 2
    ctx->r25 = S32(ctx->r13 << 2);
    // 0x8000CF3C: addu        $t6, $t2, $t9
    ctx->r14 = ADD32(ctx->r10, ctx->r25);
    // 0x8000CF40: sw          $t7, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r15;
L_8000CF44:
    // 0x8000CF44: lw          $v0, 0x3C($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X3C);
    // 0x8000CF48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CF4C: lb          $v1, 0xB($v0)
    ctx->r3 = MEM_B(ctx->r2, 0XB);
    // 0x8000CF50: nop

    // 0x8000CF54: beq         $v1, $at, L_8000CF64
    if (ctx->r3 == ctx->r1) {
        // 0x8000CF58: slt         $at, $s5, $a1
        ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_8000CF64;
    }
    // 0x8000CF58: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x8000CF5C: or          $fp, $v1, $zero
    ctx->r30 = ctx->r3 | 0;
    // 0x8000CF60: slt         $at, $s5, $a1
    ctx->r1 = SIGNED(ctx->r21) < SIGNED(ctx->r5) ? 1 : 0;
L_8000CF64:
    // 0x8000CF64: bne         $at, $zero, L_8000CE54
    if (ctx->r1 != 0) {
        // 0x8000CF68: addiu       $a0, $a0, 0x4
        ctx->r4 = ADD32(ctx->r4, 0X4);
            goto L_8000CE54;
    }
    // 0x8000CF68: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8000CF6C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000CF70:
    // 0x8000CF70: sb          $fp, 0x0($t3)
    MEM_B(0X0, ctx->r11) = ctx->r30;
    // 0x8000CF74: lb          $t8, 0x0($t3)
    ctx->r24 = MEM_B(ctx->r11, 0X0);
    // 0x8000CF78: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000CF7C: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8000CF80: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CF84: sh          $t8, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r24;
    // 0x8000CF88: addiu       $s0, $s0, -0x38C0
    ctx->r16 = ADD32(ctx->r16, -0X38C0);
    // 0x8000CF8C: addiu       $v0, $s3, 0x1
    ctx->r2 = ADD32(ctx->r19, 0X1);
    // 0x8000CF90: sw          $t5, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = ctx->r13;
    // 0x8000CF94: sw          $v0, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r2;
    // 0x8000CF98: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000CF9C: jal         0x8006C19C
    // 0x8000CFA0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    race_is_adventure_2P(rdram, ctx);
        goto after_7;
    // 0x8000CFA0: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    after_7:
    // 0x8000CFA4: beq         $v0, $zero, L_8000CFC0
    if (ctx->r2 == 0) {
        // 0x8000CFA8: addiu       $t9, $zero, 0x2
        ctx->r25 = ADD32(0, 0X2);
            goto L_8000CFC0;
    }
    // 0x8000CFA8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8000CFAC: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000CFB0: sw          $t9, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r25;
    // 0x8000CFB4: sb          $t7, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r15;
    // 0x8000CFB8: jal         0x800249E0
    // 0x8000CFBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_scene_viewport_num(rdram, ctx);
        goto after_8;
    // 0x8000CFBC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
L_8000CFC0:
    // 0x8000CFC0: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
    // 0x8000CFC4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000CFC8: bne         $t6, $at, L_8000CFD4
    if (ctx->r14 != ctx->r1) {
        // 0x8000CFCC: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8000CFD4;
    }
    // 0x8000CFCC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000CFD0: sb          $zero, 0x0($s4)
    MEM_B(0X0, ctx->r20) = 0;
L_8000CFD4:
    // 0x8000CFD4: lbu         $t8, 0x0($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X0);
    // 0x8000CFD8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CFDC: sb          $t8, -0x510B($at)
    MEM_B(-0X510B, ctx->r1) = ctx->r24;
    // 0x8000CFE0: lbu         $t5, -0x510B($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X510B);
    // 0x8000CFE4: addiu       $t9, $zero, 0x5
    ctx->r25 = ADD32(0, 0X5);
    // 0x8000CFE8: beq         $t5, $zero, L_8000CFF8
    if (ctx->r13 == 0) {
        // 0x8000CFEC: lw          $t7, 0x68($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X68);
            goto L_8000CFF8;
    }
    // 0x8000CFEC: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8000CFF0: sw          $t9, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r25;
    // 0x8000CFF4: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
L_8000CFF8:
    // 0x8000CFF8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x8000CFFC: andi        $t6, $t7, 0x40
    ctx->r14 = ctx->r15 & 0X40;
    // 0x8000D000: beq         $t7, $at, L_8000D01C
    if (ctx->r15 == ctx->r1) {
        // 0x8000D004: sw          $t6, 0x64($sp)
        MEM_W(0X64, ctx->r29) = ctx->r14;
            goto L_8000D01C;
    }
    // 0x8000D004: sw          $t6, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r14;
    // 0x8000D008: lw          $t8, 0x144($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X144);
    // 0x8000D00C: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D010: slti        $at, $t8, 0x3
    ctx->r1 = SIGNED(ctx->r24) < 0X3 ? 1 : 0;
    // 0x8000D014: bne         $at, $zero, L_8000D058
    if (ctx->r1 != 0) {
        // 0x8000D018: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_8000D058;
    }
    // 0x8000D018: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8000D01C:
    // 0x8000D01C: lw          $t5, 0x144($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X144);
    // 0x8000D020: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D024: jal         0x8006C2F0
    // 0x8000D028: sw          $t5, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = ctx->r13;
    level_properties_get(rdram, ctx);
        goto after_9;
    // 0x8000D028: sw          $t5, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = ctx->r13;
    after_9:
    // 0x8000D02C: bne         $v0, $zero, L_8000D070
    if (ctx->r2 != 0) {
        // 0x8000D030: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_8000D070;
    }
    // 0x8000D030: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8000D034: addiu       $v1, $v1, -0x38F8
    ctx->r3 = ADD32(ctx->r3, -0X38F8);
    // 0x8000D038: lh          $v0, 0x0($v1)
    ctx->r2 = MEM_H(ctx->r3, 0X0);
    // 0x8000D03C: lw          $t9, 0x94($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X94);
    // 0x8000D040: beq         $v0, $zero, L_8000D070
    if (ctx->r2 == 0) {
        // 0x8000D044: addu        $t6, $t9, $v0
        ctx->r14 = ADD32(ctx->r25, ctx->r2);
            goto L_8000D070;
    }
    // 0x8000D044: addu        $t6, $t9, $v0
    ctx->r14 = ADD32(ctx->r25, ctx->r2);
    // 0x8000D048: sw          $t6, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r14;
    // 0x8000D04C: b           L_8000D070
    // 0x8000D050: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
        goto L_8000D070;
    // 0x8000D050: sh          $zero, 0x0($v1)
    MEM_H(0X0, ctx->r3) = 0;
    // 0x8000D054: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_8000D058:
    // 0x8000D058: bne         $t7, $at, L_8000D074
    if (ctx->r15 != ctx->r1) {
        // 0x8000D05C: lw          $t8, 0x64($sp)
        ctx->r24 = MEM_W(ctx->r29, 0X64);
            goto L_8000D074;
    }
    // 0x8000D05C: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x8000D060: jal         0x8009C440
    // 0x8000D064: nop

    get_multiplayer_racer_count(rdram, ctx);
        goto after_10;
    // 0x8000D064: nop

    after_10:
    // 0x8000D068: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D06C: sw          $v0, -0x5110($at)
    MEM_W(-0X5110, ctx->r1) = ctx->r2;
L_8000D070:
    // 0x8000D070: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
L_8000D074:
    // 0x8000D074: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000D078: beq         $t8, $zero, L_8000D090
    if (ctx->r24 == 0) {
        // 0x8000D07C: addiu       $a1, $a1, -0x52C4
        ctx->r5 = ADD32(ctx->r5, -0X52C4);
            goto L_8000D090;
    }
    // 0x8000D07C: addiu       $a1, $a1, -0x52C4
    ctx->r5 = ADD32(ctx->r5, -0X52C4);
    // 0x8000D080: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000D084: addiu       $a2, $a2, -0x5110
    ctx->r6 = ADD32(ctx->r6, -0X5110);
    // 0x8000D088: addiu       $t5, $zero, 0x4
    ctx->r13 = ADD32(0, 0X4);
    // 0x8000D08C: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
L_8000D090:
    // 0x8000D090: lw          $t9, 0x68($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X68);
    // 0x8000D094: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8000D098: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D09C: addiu       $a2, $a2, -0x5110
    ctx->r6 = ADD32(ctx->r6, -0X5110);
    // 0x8000D0A0: bne         $t9, $at, L_8000D0BC
    if (ctx->r25 != ctx->r1) {
        // 0x8000D0A4: sb          $zero, 0x0($a1)
        MEM_B(0X0, ctx->r5) = 0;
            goto L_8000D0BC;
    }
    // 0x8000D0A4: sb          $zero, 0x0($a1)
    MEM_B(0X0, ctx->r5) = 0;
    // 0x8000D0A8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000D0AC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8000D0B0: sw          $t6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r14;
    // 0x8000D0B4: sw          $a3, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r7;
    // 0x8000D0B8: sb          $a3, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r7;
L_8000D0BC:
    // 0x8000D0BC: lw          $t7, 0x138($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X138);
    // 0x8000D0C0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D0C4: addiu       $v0, $v0, -0x38E4
    ctx->r2 = ADD32(ctx->r2, -0X38E4);
    // 0x8000D0C8: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x8000D0CC: bne         $t7, $a3, L_8000D0F0
    if (ctx->r15 != ctx->r7) {
        // 0x8000D0D0: sb          $zero, 0x0($v0)
        MEM_B(0X0, ctx->r2) = 0;
            goto L_8000D0F0;
    }
    // 0x8000D0D0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8000D0D4: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000D0D8: addiu       $t5, $zero, 0x2
    ctx->r13 = ADD32(0, 0X2);
    // 0x8000D0DC: bne         $t8, $zero, L_8000D0F0
    if (ctx->r24 != 0) {
        // 0x8000D0E0: nop
    
            goto L_8000D0F0;
    }
    // 0x8000D0E0: nop

    // 0x8000D0E4: sw          $s6, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r22;
    // 0x8000D0E8: sb          $a3, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r7;
    // 0x8000D0EC: sb          $t5, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r13;
L_8000D0F0:
    // 0x8000D0F0: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x8000D0F4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000D0F8: blez        $v1, L_8000D118
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000D0FC: addiu       $v0, $sp, 0x11C
        ctx->r2 = ADD32(ctx->r29, 0X11C);
            goto L_8000D118;
    }
    // 0x8000D0FC: addiu       $v0, $sp, 0x11C
    ctx->r2 = ADD32(ctx->r29, 0X11C);
    // 0x8000D100: addu        $a0, $v1, $v0
    ctx->r4 = ADD32(ctx->r3, ctx->r2);
L_8000D104:
    // 0x8000D104: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000D108: sltu        $at, $v0, $a0
    ctx->r1 = ctx->r2 < ctx->r4 ? 1 : 0;
    // 0x8000D10C: bne         $at, $zero, L_8000D104
    if (ctx->r1 != 0) {
        // 0x8000D110: sb          $zero, -0x1($v0)
        MEM_B(-0X1, ctx->r2) = 0;
            goto L_8000D104;
    }
    // 0x8000D110: sb          $zero, -0x1($v0)
    MEM_B(-0X1, ctx->r2) = 0;
    // 0x8000D114: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000D118:
    // 0x8000D118: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x8000D11C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8000D120: blez        $t6, L_8000D2E0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000D124: or          $v0, $t6, $zero
        ctx->r2 = ctx->r14 | 0;
            goto L_8000D2E0;
    }
    // 0x8000D124: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000D128: andi        $v0, $t6, 0x3
    ctx->r2 = ctx->r14 & 0X3;
    // 0x8000D12C: beq         $v0, $zero, L_8000D1A4
    if (ctx->r2 == 0) {
        // 0x8000D130: or          $t1, $v0, $zero
        ctx->r9 = ctx->r2 | 0;
            goto L_8000D1A4;
    }
    // 0x8000D130: or          $t1, $v0, $zero
    ctx->r9 = ctx->r2 | 0;
    // 0x8000D134: sll         $t7, $s0, 2
    ctx->r15 = S32(ctx->r16 << 2);
    // 0x8000D138: subu        $t7, $t7, $s0
    ctx->r15 = SUB32(ctx->r15, ctx->r16);
    // 0x8000D13C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x8000D140: addu        $a2, $s7, $t7
    ctx->r6 = ADD32(ctx->r23, ctx->r15);
    // 0x8000D144: addiu       $t0, $sp, 0x114
    ctx->r8 = ADD32(ctx->r29, 0X114);
    // 0x8000D148: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
L_8000D14C:
    // 0x8000D14C: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x8000D150: nop

    // 0x8000D154: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D158: beq         $at, $zero, L_8000D178
    if (ctx->r1 == 0) {
        // 0x8000D15C: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D178;
    }
    // 0x8000D15C: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D160: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D164: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D168: bne         $t8, $zero, L_8000D17C
    if (ctx->r24 != 0) {
        // 0x8000D16C: addu        $t9, $t0, $a1
        ctx->r25 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D17C;
    }
    // 0x8000D16C: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D170: b           L_8000D18C
    // 0x8000D174: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D18C;
    // 0x8000D174: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D178:
    // 0x8000D178: addu        $t9, $t0, $a1
    ctx->r25 = ADD32(ctx->r8, ctx->r5);
L_8000D17C:
    // 0x8000D17C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D180: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000D184: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8000D188: sb          $s0, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r16;
L_8000D18C:
    // 0x8000D18C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D190: bne         $t1, $s0, L_8000D14C
    if (ctx->r9 != ctx->r16) {
        // 0x8000D194: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_8000D14C;
    }
    // 0x8000D194: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
    // 0x8000D198: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D19C: nop

    // 0x8000D1A0: beq         $s0, $t7, L_8000D2D8
    if (ctx->r16 == ctx->r15) {
        // 0x8000D1A4: sll         $t8, $s0, 2
        ctx->r24 = S32(ctx->r16 << 2);
            goto L_8000D2D8;
    }
L_8000D1A4:
    // 0x8000D1A4: sll         $t8, $s0, 2
    ctx->r24 = S32(ctx->r16 << 2);
    // 0x8000D1A8: subu        $t8, $t8, $s0
    ctx->r24 = SUB32(ctx->r24, ctx->r16);
    // 0x8000D1AC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8000D1B0: addu        $a2, $s7, $t8
    ctx->r6 = ADD32(ctx->r23, ctx->r24);
    // 0x8000D1B4: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    // 0x8000D1B8: addiu       $t0, $sp, 0x114
    ctx->r8 = ADD32(ctx->r29, 0X114);
L_8000D1BC:
    // 0x8000D1BC: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x8000D1C0: nop

    // 0x8000D1C4: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D1C8: beq         $at, $zero, L_8000D1E8
    if (ctx->r1 == 0) {
        // 0x8000D1CC: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D1E8;
    }
    // 0x8000D1CC: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D1D0: lb          $t5, 0x0($a0)
    ctx->r13 = MEM_B(ctx->r4, 0X0);
    // 0x8000D1D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000D1D8: bne         $t5, $zero, L_8000D1EC
    if (ctx->r13 != 0) {
        // 0x8000D1DC: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D1EC;
    }
    // 0x8000D1DC: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D1E0: b           L_8000D1FC
    // 0x8000D1E4: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
        goto L_8000D1FC;
    // 0x8000D1E4: sb          $t9, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r25;
L_8000D1E8:
    // 0x8000D1E8: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D1EC:
    // 0x8000D1EC: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D1F0: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D1F4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x8000D1F8: sb          $s0, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r16;
L_8000D1FC:
    // 0x8000D1FC: lb          $v0, 0x72($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X72);
    // 0x8000D200: nop

    // 0x8000D204: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D208: beq         $at, $zero, L_8000D228
    if (ctx->r1 == 0) {
        // 0x8000D20C: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D228;
    }
    // 0x8000D20C: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D210: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D214: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D218: bne         $t8, $zero, L_8000D22C
    if (ctx->r24 != 0) {
        // 0x8000D21C: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D22C;
    }
    // 0x8000D21C: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D220: b           L_8000D240
    // 0x8000D224: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D240;
    // 0x8000D224: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D228:
    // 0x8000D228: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D22C:
    // 0x8000D22C: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D230: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D234: addiu       $t9, $s0, 0x1
    ctx->r25 = ADD32(ctx->r16, 0X1);
    // 0x8000D238: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8000D23C: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8000D240:
    // 0x8000D240: lb          $v0, 0x8A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X8A);
    // 0x8000D244: nop

    // 0x8000D248: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D24C: beq         $at, $zero, L_8000D26C
    if (ctx->r1 == 0) {
        // 0x8000D250: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D26C;
    }
    // 0x8000D250: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D254: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D258: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D25C: bne         $t8, $zero, L_8000D270
    if (ctx->r24 != 0) {
        // 0x8000D260: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D270;
    }
    // 0x8000D260: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D264: b           L_8000D284
    // 0x8000D268: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D284;
    // 0x8000D268: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D26C:
    // 0x8000D26C: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D270:
    // 0x8000D270: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D274: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D278: addiu       $t9, $s0, 0x2
    ctx->r25 = ADD32(ctx->r16, 0X2);
    // 0x8000D27C: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8000D280: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8000D284:
    // 0x8000D284: lb          $v0, 0xA2($a2)
    ctx->r2 = MEM_B(ctx->r6, 0XA2);
    // 0x8000D288: nop

    // 0x8000D28C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D290: beq         $at, $zero, L_8000D2B0
    if (ctx->r1 == 0) {
        // 0x8000D294: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D2B0;
    }
    // 0x8000D294: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D298: lb          $t8, 0x0($a0)
    ctx->r24 = MEM_B(ctx->r4, 0X0);
    // 0x8000D29C: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8000D2A0: bne         $t8, $zero, L_8000D2B4
    if (ctx->r24 != 0) {
        // 0x8000D2A4: addu        $t6, $t0, $a1
        ctx->r14 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D2B4;
    }
    // 0x8000D2A4: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D2A8: b           L_8000D2C8
    // 0x8000D2AC: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
        goto L_8000D2C8;
    // 0x8000D2AC: sb          $t5, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r13;
L_8000D2B0:
    // 0x8000D2B0: addu        $t6, $t0, $a1
    ctx->r14 = ADD32(ctx->r8, ctx->r5);
L_8000D2B4:
    // 0x8000D2B4: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D2B8: andi        $t7, $a1, 0xFF
    ctx->r15 = ctx->r5 & 0XFF;
    // 0x8000D2BC: addiu       $t9, $s0, 0x3
    ctx->r25 = ADD32(ctx->r16, 0X3);
    // 0x8000D2C0: sb          $t9, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r25;
    // 0x8000D2C4: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
L_8000D2C8:
    // 0x8000D2C8: lw          $t8, 0x144($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X144);
    // 0x8000D2CC: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8000D2D0: bne         $s0, $t8, L_8000D1BC
    if (ctx->r16 != ctx->r24) {
        // 0x8000D2D4: addiu       $a2, $a2, 0x60
        ctx->r6 = ADD32(ctx->r6, 0X60);
            goto L_8000D1BC;
    }
    // 0x8000D2D4: addiu       $a2, $a2, 0x60
    ctx->r6 = ADD32(ctx->r6, 0X60);
L_8000D2D8:
    // 0x8000D2D8: lw          $v0, 0x144($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X144);
    // 0x8000D2DC: nop

L_8000D2E0:
    // 0x8000D2E0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D2E4: addiu       $a3, $sp, 0x11C
    ctx->r7 = ADD32(ctx->r29, 0X11C);
    // 0x8000D2E8: addiu       $t0, $sp, 0x114
    ctx->r8 = ADD32(ctx->r29, 0X114);
    // 0x8000D2EC: beq         $at, $zero, L_8000D354
    if (ctx->r1 == 0) {
        // 0x8000D2F0: or          $s0, $v0, $zero
        ctx->r16 = ctx->r2 | 0;
            goto L_8000D354;
    }
    // 0x8000D2F0: or          $s0, $v0, $zero
    ctx->r16 = ctx->r2 | 0;
    // 0x8000D2F4: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8000D2F8: subu        $t5, $t5, $v0
    ctx->r13 = SUB32(ctx->r13, ctx->r2);
    // 0x8000D2FC: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8000D300: addu        $a2, $s7, $t5
    ctx->r6 = ADD32(ctx->r23, ctx->r13);
L_8000D304:
    // 0x8000D304: lb          $v0, 0x5A($a2)
    ctx->r2 = MEM_B(ctx->r6, 0X5A);
    // 0x8000D308: nop

    // 0x8000D30C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D310: beq         $at, $zero, L_8000D330
    if (ctx->r1 == 0) {
        // 0x8000D314: addu        $a0, $a3, $v0
        ctx->r4 = ADD32(ctx->r7, ctx->r2);
            goto L_8000D330;
    }
    // 0x8000D314: addu        $a0, $a3, $v0
    ctx->r4 = ADD32(ctx->r7, ctx->r2);
    // 0x8000D318: lb          $t9, 0x0($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X0);
    // 0x8000D31C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8000D320: bne         $t9, $zero, L_8000D334
    if (ctx->r25 != 0) {
        // 0x8000D324: addu        $t7, $t0, $a1
        ctx->r15 = ADD32(ctx->r8, ctx->r5);
            goto L_8000D334;
    }
    // 0x8000D324: addu        $t7, $t0, $a1
    ctx->r15 = ADD32(ctx->r8, ctx->r5);
    // 0x8000D328: b           L_8000D344
    // 0x8000D32C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
        goto L_8000D344;
    // 0x8000D32C: sb          $t6, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r14;
L_8000D330:
    // 0x8000D330: addu        $t7, $t0, $a1
    ctx->r15 = ADD32(ctx->r8, ctx->r5);
L_8000D334:
    // 0x8000D334: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8000D338: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x8000D33C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8000D340: sb          $s0, 0x0($t7)
    MEM_B(0X0, ctx->r15) = ctx->r16;
L_8000D344:
    // 0x8000D344: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D348: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D34C: bne         $at, $zero, L_8000D304
    if (ctx->r1 != 0) {
        // 0x8000D350: addiu       $a2, $a2, 0x18
        ctx->r6 = ADD32(ctx->r6, 0X18);
            goto L_8000D304;
    }
    // 0x8000D350: addiu       $a2, $a2, 0x18
    ctx->r6 = ADD32(ctx->r6, 0X18);
L_8000D354:
    // 0x8000D354: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000D358: blez        $a1, L_8000D3CC
    if (SIGNED(ctx->r5) <= 0) {
        // 0x8000D35C: or          $a0, $a1, $zero
        ctx->r4 = ctx->r5 | 0;
            goto L_8000D3CC;
    }
    // 0x8000D35C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x8000D360: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
L_8000D364:
    // 0x8000D364: blez        $v1, L_8000D3BC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000D368: addu        $v0, $a3, $s2
        ctx->r2 = ADD32(ctx->r7, ctx->r18);
            goto L_8000D3BC;
    }
    // 0x8000D368: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
L_8000D36C:
    // 0x8000D36C: lb          $t5, 0x0($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X0);
    // 0x8000D370: addu        $t6, $t0, $s0
    ctx->r14 = ADD32(ctx->r8, ctx->r16);
    // 0x8000D374: bne         $t5, $zero, L_8000D3A8
    if (ctx->r13 != 0) {
        // 0x8000D378: nop
    
            goto L_8000D3A8;
    }
    // 0x8000D378: nop

    // 0x8000D37C: lb          $t7, 0x0($t6)
    ctx->r15 = MEM_B(ctx->r14, 0X0);
    // 0x8000D380: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000D384: multu       $t7, $s5
    result = U64(U32(ctx->r15)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D388: sb          $t9, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r25;
    // 0x8000D38C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000D390: mflo        $t8
    ctx->r24 = lo;
    // 0x8000D394: addu        $t5, $s7, $t8
    ctx->r13 = ADD32(ctx->r23, ctx->r24);
    // 0x8000D398: sb          $s2, 0x5A($t5)
    MEM_B(0X5A, ctx->r13) = ctx->r18;
    // 0x8000D39C: lw          $v1, -0x5110($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5110);
    // 0x8000D3A0: nop

    // 0x8000D3A4: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
L_8000D3A8:
    // 0x8000D3A8: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000D3AC: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D3B0: bne         $at, $zero, L_8000D36C
    if (ctx->r1 != 0) {
        // 0x8000D3B4: addu        $v0, $a3, $s2
        ctx->r2 = ADD32(ctx->r7, ctx->r18);
            goto L_8000D36C;
    }
    // 0x8000D3B4: addu        $v0, $a3, $s2
    ctx->r2 = ADD32(ctx->r7, ctx->r18);
    // 0x8000D3B8: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000D3BC:
    // 0x8000D3BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D3C0: bne         $s0, $a0, L_8000D364
    if (ctx->r16 != ctx->r4) {
        // 0x8000D3C4: nop
    
            goto L_8000D364;
    }
    // 0x8000D3C4: nop

    // 0x8000D3C8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8000D3CC:
    // 0x8000D3CC: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8000D3D0: addiu       $s5, $zero, 0x18
    ctx->r21 = ADD32(0, 0X18);
    // 0x8000D3D4: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8000D3D8: jal         0x80070C9C
    // 0x8000D3DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    mempool_alloc_safe(rdram, ctx);
        goto after_11;
    // 0x8000D3DC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_11:
    // 0x8000D3E0: sh          $zero, 0xC($v0)
    MEM_H(0XC, ctx->r2) = 0;
    // 0x8000D3E4: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x8000D3E8: sh          $zero, 0x8($v0)
    MEM_H(0X8, ctx->r2) = 0;
    // 0x8000D3EC: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8000D3F0: or          $s6, $v0, $zero
    ctx->r22 = ctx->r2 | 0;
    // 0x8000D3F4: lb          $t6, 0x4D($t9)
    ctx->r14 = MEM_B(ctx->r25, 0X4D);
    // 0x8000D3F8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x8000D3FC: bne         $t6, $zero, L_8000D410
    if (ctx->r14 != 0) {
        // 0x8000D400: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8000D410;
    }
    // 0x8000D400: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000D404: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D408: b           L_8000D41C
    // 0x8000D40C: sb          $zero, -0x51FE($at)
    MEM_B(-0X51FE, ctx->r1) = 0;
        goto L_8000D41C;
    // 0x8000D40C: sb          $zero, -0x51FE($at)
    MEM_B(-0X51FE, ctx->r1) = 0;
L_8000D410:
    // 0x8000D410: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000D414: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D418: sb          $t7, -0x51FE($at)
    MEM_B(-0X51FE, ctx->r1) = ctx->r15;
L_8000D41C:
    // 0x8000D41C: lw          $t8, 0x78($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X78);
    // 0x8000D420: lw          $v1, -0x5110($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5110);
    // 0x8000D424: lb          $t5, 0xB8($t8)
    ctx->r13 = MEM_B(ctx->r24, 0XB8);
    // 0x8000D428: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D42C: sb          $t9, 0x127($sp)
    MEM_B(0X127, ctx->r29) = ctx->r25;
    // 0x8000D430: blez        $v1, L_8000D9AC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8000D434: sb          $t5, -0x52DB($at)
        MEM_B(-0X52DB, ctx->r1) = ctx->r13;
            goto L_8000D9AC;
    }
    // 0x8000D434: sb          $t5, -0x52DB($at)
    MEM_B(-0X52DB, ctx->r1) = ctx->r13;
    // 0x8000D438: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D43C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000D440:
    // 0x8000D440: beq         $v0, $a0, L_8000D4A8
    if (ctx->r2 == ctx->r4) {
        // 0x8000D444: or          $s4, $s0, $zero
        ctx->r20 = ctx->r16 | 0;
            goto L_8000D4A8;
    }
    // 0x8000D444: or          $s4, $s0, $zero
    ctx->r20 = ctx->r16 | 0;
    // 0x8000D448: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8000D44C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000D450: bne         $t6, $zero, L_8000D4A8
    if (ctx->r14 != 0) {
        // 0x8000D454: nop
    
            goto L_8000D4A8;
    }
    // 0x8000D454: nop

    // 0x8000D458: lb          $t7, -0x52C4($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X52C4);
    // 0x8000D45C: nop

    // 0x8000D460: bne         $t7, $zero, L_8000D4A8
    if (ctx->r15 != 0) {
        // 0x8000D464: nop
    
            goto L_8000D4A8;
    }
    // 0x8000D464: nop

    // 0x8000D468: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
L_8000D46C:
    // 0x8000D46C: multu       $s2, $s5
    result = U64(U32(ctx->r18)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D470: mflo        $t8
    ctx->r24 = lo;
    // 0x8000D474: addu        $t5, $s7, $t8
    ctx->r13 = ADD32(ctx->r23, ctx->r24);
    // 0x8000D478: lb          $t9, 0x5A($t5)
    ctx->r25 = MEM_B(ctx->r13, 0X5A);
    // 0x8000D47C: nop

    // 0x8000D480: bne         $s0, $t9, L_8000D490
    if (ctx->r16 != ctx->r25) {
        // 0x8000D484: nop
    
            goto L_8000D490;
    }
    // 0x8000D484: nop

    // 0x8000D488: or          $s4, $s2, $zero
    ctx->r20 = ctx->r18 | 0;
    // 0x8000D48C: or          $s2, $v1, $zero
    ctx->r18 = ctx->r3 | 0;
L_8000D490:
    // 0x8000D490: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000D494: slt         $at, $s2, $v1
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D498: bne         $at, $zero, L_8000D46C
    if (ctx->r1 != 0) {
        // 0x8000D49C: nop
    
            goto L_8000D46C;
    }
    // 0x8000D49C: nop

    // 0x8000D4A0: b           L_8000D4A8
    // 0x8000D4A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
        goto L_8000D4A8;
    // 0x8000D4A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000D4A8:
    // 0x8000D4A8: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x8000D4AC: addiu       $t7, $zero, 0x4
    ctx->r15 = ADD32(0, 0X4);
    // 0x8000D4B0: slt         $at, $s4, $t6
    ctx->r1 = SIGNED(ctx->r20) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000D4B4: beq         $at, $zero, L_8000D4C4
    if (ctx->r1 == 0) {
        // 0x8000D4B8: sll         $a2, $s0, 2
        ctx->r6 = S32(ctx->r16 << 2);
            goto L_8000D4C4;
    }
    // 0x8000D4B8: sll         $a2, $s0, 2
    ctx->r6 = S32(ctx->r16 << 2);
    // 0x8000D4BC: b           L_8000D4C8
    // 0x8000D4C0: sh          $s4, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r20;
        goto L_8000D4C8;
    // 0x8000D4C0: sh          $s4, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r20;
L_8000D4C4:
    // 0x8000D4C4: sh          $t7, 0xE($s6)
    MEM_H(0XE, ctx->r22) = ctx->r15;
L_8000D4C8:
    // 0x8000D4C8: bne         $v0, $a0, L_8000D4E0
    if (ctx->r2 != ctx->r4) {
        // 0x8000D4CC: addiu       $t5, $sp, 0xF4
        ctx->r13 = ADD32(ctx->r29, 0XF4);
            goto L_8000D4E0;
    }
    // 0x8000D4CC: addiu       $t5, $sp, 0xF4
    ctx->r13 = ADD32(ctx->r29, 0XF4);
    // 0x8000D4D0: lh          $t8, 0xE($s6)
    ctx->r24 = MEM_H(ctx->r22, 0XE);
    // 0x8000D4D4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D4D8: beq         $t8, $at, L_8000D994
    if (ctx->r24 == ctx->r1) {
        // 0x8000D4DC: nop
    
            goto L_8000D994;
    }
    // 0x8000D4DC: nop

L_8000D4E0:
    // 0x8000D4E0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D4E4: addu        $s3, $a2, $t5
    ctx->r19 = ADD32(ctx->r6, ctx->r13);
    // 0x8000D4E8: addiu       $t9, $sp, 0xD4
    ctx->r25 = ADD32(ctx->r29, 0XD4);
    // 0x8000D4EC: lb          $v0, -0x52C4($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X52C4);
    // 0x8000D4F0: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x8000D4F4: addiu       $t5, $sp, 0x94
    ctx->r13 = ADD32(ctx->r29, 0X94);
    // 0x8000D4F8: addiu       $t7, $sp, 0xB4
    ctx->r15 = ADD32(ctx->r29, 0XB4);
    // 0x8000D4FC: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x8000D500: addu        $t9, $a2, $t5
    ctx->r25 = ADD32(ctx->r6, ctx->r13);
    // 0x8000D504: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D508: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x8000D50C: sw          $t8, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r24;
    // 0x8000D510: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x8000D514: bne         $v0, $at, L_8000D560
    if (ctx->r2 != ctx->r1) {
        // 0x8000D518: addiu       $s1, $zero, 0x1
        ctx->r17 = ADD32(0, 0X1);
            goto L_8000D560;
    }
    // 0x8000D518: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8000D51C: bne         $s0, $zero, L_8000D544
    if (ctx->r16 != 0) {
        // 0x8000D520: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8000D544;
    }
    // 0x8000D520: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000D524: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000D528: lb          $t6, -0x52DB($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X52DB);
    // 0x8000D52C: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8000D530: sll         $t7, $t6, 1
    ctx->r15 = S32(ctx->r14 << 1);
    // 0x8000D534: addu        $fp, $fp, $t7
    ctx->r30 = ADD32(ctx->r30, ctx->r15);
    // 0x8000D538: lb          $fp, -0x37E0($fp)
    ctx->r30 = MEM_B(ctx->r30, -0X37E0);
    // 0x8000D53C: b           L_8000D5E0
    // 0x8000D540: nop

        goto L_8000D5E0;
    // 0x8000D540: nop

L_8000D544:
    // 0x8000D544: lb          $t8, -0x52DB($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X52DB);
    // 0x8000D548: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8000D54C: sll         $t5, $t8, 1
    ctx->r13 = S32(ctx->r24 << 1);
    // 0x8000D550: addu        $fp, $fp, $t5
    ctx->r30 = ADD32(ctx->r30, ctx->r13);
    // 0x8000D554: lb          $fp, -0x37DF($fp)
    ctx->r30 = MEM_B(ctx->r30, -0X37DF);
    // 0x8000D558: b           L_8000D5E0
    // 0x8000D55C: nop

        goto L_8000D5E0;
    // 0x8000D55C: nop

L_8000D560:
    // 0x8000D560: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D564: bne         $v0, $at, L_8000D580
    if (ctx->r2 != ctx->r1) {
        // 0x8000D568: nop
    
            goto L_8000D580;
    }
    // 0x8000D568: nop

    // 0x8000D56C: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x8000D570: nop

    // 0x8000D574: lb          $fp, 0x4D($t9)
    ctx->r30 = MEM_B(ctx->r25, 0X4D);
    // 0x8000D578: b           L_8000D5E0
    // 0x8000D57C: nop

        goto L_8000D5E0;
    // 0x8000D57C: nop

L_8000D580:
    // 0x8000D580: lh          $t6, 0xE($s6)
    ctx->r14 = MEM_H(ctx->r22, 0XE);
    // 0x8000D584: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D588: beq         $t6, $at, L_8000D5A4
    if (ctx->r14 == ctx->r1) {
        // 0x8000D58C: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000D5A4;
    }
    // 0x8000D58C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000D590: jal         0x8006C19C
    // 0x8000D594: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    race_is_adventure_2P(rdram, ctx);
        goto after_12;
    // 0x8000D594: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_12:
    // 0x8000D598: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D59C: beq         $v0, $zero, L_8000D5B8
    if (ctx->r2 == 0) {
        // 0x8000D5A0: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000D5B8;
    }
    // 0x8000D5A0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_8000D5A4:
    // 0x8000D5A4: jal         0x8009C250
    // 0x8000D5A8: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    get_player_selected_vehicle(rdram, ctx);
        goto after_13;
    // 0x8000D5A8: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_13:
    // 0x8000D5AC: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D5B0: b           L_8000D5E0
    // 0x8000D5B4: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
        goto L_8000D5E0;
    // 0x8000D5B4: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_8000D5B8:
    // 0x8000D5B8: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D5BC: nop

    // 0x8000D5C0: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8000D5C4: bne         $at, $zero, L_8000D5E0
    if (ctx->r1 != 0) {
        // 0x8000D5C8: nop
    
            goto L_8000D5E0;
    }
    // 0x8000D5C8: nop

    // 0x8000D5CC: lh          $a0, 0xE($s6)
    ctx->r4 = MEM_H(ctx->r22, 0XE);
    // 0x8000D5D0: jal         0x8009C250
    // 0x8000D5D4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    get_player_selected_vehicle(rdram, ctx);
        goto after_14;
    // 0x8000D5D4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    after_14:
    // 0x8000D5D8: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D5DC: or          $fp, $v0, $zero
    ctx->r30 = ctx->r2 | 0;
L_8000D5E0:
    // 0x8000D5E0: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000D5E4: lb          $t8, -0x52C4($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X52C4);
    // 0x8000D5E8: lh          $v1, 0xE($s6)
    ctx->r3 = MEM_H(ctx->r22, 0XE);
    // 0x8000D5EC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D5F0: bne         $t8, $at, L_8000D634
    if (ctx->r24 != ctx->r1) {
        // 0x8000D5F4: lui         $t5, 0x800E
        ctx->r13 = S32(0X800E << 16);
            goto L_8000D634;
    }
    // 0x8000D5F4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x8000D5F8: addu        $t5, $t5, $s0
    ctx->r13 = ADD32(ctx->r13, ctx->r16);
    // 0x8000D5FC: lb          $t5, -0x37C0($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X37C0);
    // 0x8000D600: sll         $t6, $fp, 2
    ctx->r14 = S32(ctx->r30 << 2);
    // 0x8000D604: addu        $t6, $t6, $fp
    ctx->r14 = ADD32(ctx->r14, ctx->r30);
    // 0x8000D608: sll         $t9, $t5, 1
    ctx->r25 = S32(ctx->r13 << 1);
    // 0x8000D60C: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x8000D610: addu        $t8, $t9, $t7
    ctx->r24 = ADD32(ctx->r25, ctx->r15);
    // 0x8000D614: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x8000D618: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D61C: addu        $v0, $v0, $t8
    ctx->r2 = ADD32(ctx->r2, ctx->r24);
    // 0x8000D620: subu        $t5, $t5, $s4
    ctx->r13 = SUB32(ctx->r13, ctx->r20);
    // 0x8000D624: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x8000D628: lh          $v0, -0x3858($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X3858);
    // 0x8000D62C: b           L_8000D698
    // 0x8000D630: addu        $a3, $s7, $t5
    ctx->r7 = ADD32(ctx->r23, ctx->r13);
        goto L_8000D698;
    // 0x8000D630: addu        $a3, $s7, $t5
    ctx->r7 = ADD32(ctx->r23, ctx->r13);
L_8000D634:
    // 0x8000D634: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
    // 0x8000D638: beq         $at, $zero, L_8000D67C
    if (ctx->r1 == 0) {
        // 0x8000D63C: sll         $t9, $fp, 1
        ctx->r25 = S32(ctx->r30 << 1);
            goto L_8000D67C;
    }
    // 0x8000D63C: sll         $t9, $fp, 1
    ctx->r25 = S32(ctx->r30 << 1);
    // 0x8000D640: multu       $s4, $s5
    result = U64(U32(ctx->r20)) * U64(U32(ctx->r21)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8000D644: sll         $t8, $fp, 2
    ctx->r24 = S32(ctx->r30 << 2);
    // 0x8000D648: addu        $t8, $t8, $fp
    ctx->r24 = ADD32(ctx->r24, ctx->r30);
    // 0x8000D64C: sll         $t5, $t8, 2
    ctx->r13 = S32(ctx->r24 << 2);
    // 0x8000D650: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D654: mflo        $t6
    ctx->r14 = lo;
    // 0x8000D658: addu        $a3, $s7, $t6
    ctx->r7 = ADD32(ctx->r23, ctx->r14);
    // 0x8000D65C: lb          $t9, 0x59($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X59);
    // 0x8000D660: nop

    // 0x8000D664: sll         $t7, $t9, 1
    ctx->r15 = S32(ctx->r25 << 1);
    // 0x8000D668: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x8000D66C: addu        $v0, $v0, $t6
    ctx->r2 = ADD32(ctx->r2, ctx->r14);
    // 0x8000D670: lh          $v0, -0x3858($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X3858);
    // 0x8000D674: b           L_8000D69C
    // 0x8000D678: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
        goto L_8000D69C;
    // 0x8000D678: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
L_8000D67C:
    // 0x8000D67C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000D680: sll         $t8, $s4, 2
    ctx->r24 = S32(ctx->r20 << 2);
    // 0x8000D684: subu        $t8, $t8, $s4
    ctx->r24 = SUB32(ctx->r24, ctx->r20);
    // 0x8000D688: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8000D68C: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8000D690: lh          $v0, -0x37FE($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X37FE);
    // 0x8000D694: addu        $a3, $s7, $t8
    ctx->r7 = ADD32(ctx->r23, ctx->r24);
L_8000D698:
    // 0x8000D698: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
L_8000D69C:
    // 0x8000D69C: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000D6A0: ori         $t6, $t5, 0x10
    ctx->r14 = ctx->r13 | 0X10;
    // 0x8000D6A4: sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    // 0x8000D6A8: sb          $t6, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r14;
    // 0x8000D6AC: lw          $t9, 0x0($s3)
    ctx->r25 = MEM_W(ctx->r19, 0X0);
    // 0x8000D6B0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D6B4: sh          $t9, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r25;
    // 0x8000D6B8: lw          $t8, 0x4C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X4C);
    // 0x8000D6BC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8000D6C0: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8000D6C4: nop

    // 0x8000D6C8: sh          $t7, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r15;
    // 0x8000D6CC: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8000D6D0: nop

    // 0x8000D6D4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8000D6D8: nop

    // 0x8000D6DC: sh          $t6, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r14;
    // 0x8000D6E0: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8000D6E4: nop

    // 0x8000D6E8: lw          $t8, 0x0($t9)
    ctx->r24 = MEM_W(ctx->r25, 0X0);
    // 0x8000D6EC: bne         $v1, $at, L_8000D710
    if (ctx->r3 != ctx->r1) {
        // 0x8000D6F0: sh          $t8, 0xC($s6)
        MEM_H(0XC, ctx->r22) = ctx->r24;
            goto L_8000D710;
    }
    // 0x8000D6F0: sh          $t8, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r24;
    // 0x8000D6F4: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x8000D6F8: jal         0x800619F4
    // 0x8000D6FC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    model_anim_offset(rdram, ctx);
        goto after_15;
    // 0x8000D6FC: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_15:
    // 0x8000D700: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D704: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8000D708: lh          $v1, 0xE($s6)
    ctx->r3 = MEM_H(ctx->r22, 0XE);
    // 0x8000D70C: nop

L_8000D710:
    // 0x8000D710: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D714: bne         $v1, $at, L_8000D734
    if (ctx->r3 != ctx->r1) {
        // 0x8000D718: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000D734;
    }
    // 0x8000D718: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000D71C: lw          $t7, 0x144($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X144);
    // 0x8000D720: addiu       $s1, $zero, 0x5
    ctx->r17 = ADD32(0, 0X5);
    // 0x8000D724: slti        $at, $t7, 0x2
    ctx->r1 = SIGNED(ctx->r15) < 0X2 ? 1 : 0;
    // 0x8000D728: bne         $at, $zero, L_8000D734
    if (ctx->r1 != 0) {
        // 0x8000D72C: ori         $t5, $s1, 0x8
        ctx->r13 = ctx->r17 | 0X8;
            goto L_8000D734;
    }
    // 0x8000D72C: ori         $t5, $s1, 0x8
    ctx->r13 = ctx->r17 | 0X8;
    // 0x8000D730: or          $s1, $t5, $zero
    ctx->r17 = ctx->r13 | 0;
L_8000D734:
    // 0x8000D734: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8000D738: beq         $v1, $at, L_8000D758
    if (ctx->r3 == ctx->r1) {
        // 0x8000D73C: slti        $at, $fp, 0x5
        ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
            goto L_8000D758;
    }
    // 0x8000D73C: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
    // 0x8000D740: lw          $t6, 0x144($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X144);
    // 0x8000D744: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D748: bne         $t6, $at, L_8000D754
    if (ctx->r14 != ctx->r1) {
        // 0x8000D74C: ori         $t9, $s1, 0x10
        ctx->r25 = ctx->r17 | 0X10;
            goto L_8000D754;
    }
    // 0x8000D74C: ori         $t9, $s1, 0x10
    ctx->r25 = ctx->r17 | 0X10;
    // 0x8000D750: or          $s1, $t9, $zero
    ctx->r17 = ctx->r25 | 0;
L_8000D754:
    // 0x8000D754: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
L_8000D758:
    // 0x8000D758: bne         $at, $zero, L_8000D77C
    if (ctx->r1 != 0) {
        // 0x8000D75C: nop
    
            goto L_8000D77C;
    }
    // 0x8000D75C: nop

    // 0x8000D760: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
    // 0x8000D764: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x8000D768: jal         0x800619F4
    // 0x8000D76C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    model_anim_offset(rdram, ctx);
        goto after_16;
    // 0x8000D76C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_16:
    // 0x8000D770: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D774: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8000D778: nop

L_8000D77C:
    // 0x8000D77C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000D780: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x8000D784: sw          $a2, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r6;
    // 0x8000D788: jal         0x8000EA54
    // 0x8000D78C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    spawn_object(rdram, ctx);
        goto after_17;
    // 0x8000D78C: sw          $a3, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r7;
    after_17:
    // 0x8000D790: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x8000D794: lw          $a2, 0x54($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X54);
    // 0x8000D798: lw          $t7, 0x0($t8)
    ctx->r15 = MEM_W(ctx->r24, 0X0);
    // 0x8000D79C: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x8000D7A0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000D7A4: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x8000D7A8: lw          $t5, -0x511C($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X511C);
    // 0x8000D7AC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000D7B0: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8000D7B4: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000D7B8: lw          $t9, -0x5118($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5118);
    // 0x8000D7BC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000D7C0: addu        $t8, $t9, $a2
    ctx->r24 = ADD32(ctx->r25, ctx->r6);
    // 0x8000D7C4: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8000D7C8: lw          $t7, -0x5114($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5114);
    // 0x8000D7CC: sll         $t5, $s4, 2
    ctx->r13 = S32(ctx->r20 << 2);
    // 0x8000D7D0: addu        $t6, $t7, $t5
    ctx->r14 = ADD32(ctx->r15, ctx->r13);
    // 0x8000D7D4: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8000D7D8: lw          $s3, 0x64($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X64);
    // 0x8000D7DC: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8000D7E0: sb          $fp, 0x1D6($s3)
    MEM_B(0X1D6, ctx->r19) = ctx->r30;
    // 0x8000D7E4: sb          $fp, 0x1D7($s3)
    MEM_B(0X1D7, ctx->r19) = ctx->r30;
    // 0x8000D7E8: lb          $t9, 0x127($sp)
    ctx->r25 = MEM_B(ctx->r29, 0X127);
    // 0x8000D7EC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D7F0: beq         $t9, $at, L_8000D808
    if (ctx->r25 == ctx->r1) {
        // 0x8000D7F4: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8000D808;
    }
    // 0x8000D7F4: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8000D7F8: beq         $t9, $fp, L_8000D808
    if (ctx->r25 == ctx->r30) {
        // 0x8000D7FC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8000D808;
    }
    // 0x8000D7FC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8000D800: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D804: sb          $t8, -0x52E0($at)
    MEM_B(-0X52E0, ctx->r1) = ctx->r24;
L_8000D808:
    // 0x8000D808: sb          $fp, 0x127($sp)
    MEM_B(0X127, ctx->r29) = ctx->r30;
    // 0x8000D80C: lb          $v0, 0x1D6($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X1D6);
    // 0x8000D810: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D814: beq         $v0, $at, L_8000D82C
    if (ctx->r2 == ctx->r1) {
        // 0x8000D818: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_8000D82C;
    }
    // 0x8000D818: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8000D81C: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x8000D820: beq         $v0, $at, L_8000D82C
    if (ctx->r2 == ctx->r1) {
        // 0x8000D824: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8000D82C;
    }
    // 0x8000D824: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D828: bne         $v0, $at, L_8000D834
    if (ctx->r2 != ctx->r1) {
        // 0x8000D82C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000D834;
    }
L_8000D82C:
    // 0x8000D82C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D830: sb          $t7, -0x51FE($at)
    MEM_B(-0X51FE, ctx->r1) = ctx->r15;
L_8000D834:
    // 0x8000D834: sb          $fp, 0x1CB($s3)
    MEM_B(0X1CB, ctx->r19) = ctx->r30;
    // 0x8000D838: lb          $v0, 0x1CB($s3)
    ctx->r2 = MEM_B(ctx->r19, 0X1CB);
    // 0x8000D83C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000D840: bltz        $v0, L_8000D850
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000D844: slti        $at, $v0, 0x3
        ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
            goto L_8000D850;
    }
    // 0x8000D844: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8000D848: bne         $at, $zero, L_8000D854
    if (ctx->r1 != 0) {
        // 0x8000D84C: nop
    
            goto L_8000D854;
    }
    // 0x8000D84C: nop

L_8000D850:
    // 0x8000D850: sb          $zero, 0x1CB($s3)
    MEM_B(0X1CB, ctx->r19) = 0;
L_8000D854:
    // 0x8000D854: sb          $s4, 0x2($s3)
    MEM_B(0X2, ctx->r19) = ctx->r20;
    // 0x8000D858: lb          $t5, 0x59($a3)
    ctx->r13 = MEM_B(ctx->r7, 0X59);
    // 0x8000D85C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000D860: sb          $t5, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r13;
    // 0x8000D864: lb          $t6, -0x52C4($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X52C4);
    // 0x8000D868: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D86C: bne         $t6, $at, L_8000D880
    if (ctx->r14 != ctx->r1) {
        // 0x8000D870: addu        $t9, $t9, $s0
        ctx->r25 = ADD32(ctx->r25, ctx->r16);
            goto L_8000D880;
    }
    // 0x8000D870: addu        $t9, $t9, $s0
    ctx->r25 = ADD32(ctx->r25, ctx->r16);
    // 0x8000D874: lb          $t9, -0x37C0($t9)
    ctx->r25 = MEM_B(ctx->r25, -0X37C0);
    // 0x8000D878: b           L_8000D88C
    // 0x8000D87C: sb          $t9, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r25;
        goto L_8000D88C;
    // 0x8000D87C: sb          $t9, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r25;
L_8000D880:
    // 0x8000D880: lb          $t8, 0x59($a3)
    ctx->r24 = MEM_B(ctx->r7, 0X59);
    // 0x8000D884: nop

    // 0x8000D888: sb          $t8, 0x3($s3)
    MEM_B(0X3, ctx->r19) = ctx->r24;
L_8000D88C:
    // 0x8000D88C: lw          $t7, 0x68($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X68);
    // 0x8000D890: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8000D894: bne         $t7, $at, L_8000D8A4
    if (ctx->r15 != ctx->r1) {
        // 0x8000D898: addiu       $t5, $zero, 0x8
        ctx->r13 = ADD32(0, 0X8);
            goto L_8000D8A4;
    }
    // 0x8000D898: addiu       $t5, $zero, 0x8
    ctx->r13 = ADD32(0, 0X8);
    // 0x8000D89C: b           L_8000D8A8
    // 0x8000D8A0: sb          $t5, 0x185($s3)
    MEM_B(0X185, ctx->r19) = ctx->r13;
        goto L_8000D8A8;
    // 0x8000D8A0: sb          $t5, 0x185($s3)
    MEM_B(0X185, ctx->r19) = ctx->r13;
L_8000D8A4:
    // 0x8000D8A4: sb          $zero, 0x185($s3)
    MEM_B(0X185, ctx->r19) = 0;
L_8000D8A8:
    // 0x8000D8A8: jal         0x8009C30C
    // 0x8000D8AC: nop

    get_filtered_cheats(rdram, ctx);
        goto after_18;
    // 0x8000D8AC: nop

    after_18:
    // 0x8000D8B0: andi        $t6, $v0, 0x80
    ctx->r14 = ctx->r2 & 0X80;
    // 0x8000D8B4: beq         $t6, $zero, L_8000D8E4
    if (ctx->r14 == 0) {
        // 0x8000D8B8: lw          $t5, 0x138($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X138);
            goto L_8000D8E4;
    }
    // 0x8000D8B8: lw          $t5, 0x138($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X138);
    // 0x8000D8BC: lw          $t9, 0x64($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X64);
    // 0x8000D8C0: nop

    // 0x8000D8C4: bne         $t9, $zero, L_8000D8E4
    if (ctx->r25 != 0) {
        // 0x8000D8C8: lw          $t5, 0x138($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X138);
            goto L_8000D8E4;
    }
    // 0x8000D8C8: lw          $t5, 0x138($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X138);
    // 0x8000D8CC: lh          $t8, 0x0($s3)
    ctx->r24 = MEM_H(ctx->r19, 0X0);
    // 0x8000D8D0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000D8D4: beq         $t8, $at, L_8000D8E0
    if (ctx->r24 == ctx->r1) {
        // 0x8000D8D8: addiu       $t7, $zero, 0xA
        ctx->r15 = ADD32(0, 0XA);
            goto L_8000D8E0;
    }
    // 0x8000D8D8: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x8000D8DC: sb          $t7, 0x185($s3)
    MEM_B(0X185, ctx->r19) = ctx->r15;
L_8000D8E0:
    // 0x8000D8E0: lw          $t5, 0x138($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X138);
L_8000D8E4:
    // 0x8000D8E4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000D8E8: bne         $t5, $at, L_8000D8FC
    if (ctx->r13 != ctx->r1) {
        // 0x8000D8EC: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_8000D8FC;
    }
    // 0x8000D8EC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000D8F0: lb          $t6, -0x52C4($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X52C4);
    // 0x8000D8F4: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8000D8F8: bne         $t6, $at, L_8000D920
    if (ctx->r14 != ctx->r1) {
        // 0x8000D8FC: slti        $at, $fp, 0x5
        ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
            goto L_8000D920;
    }
L_8000D8FC:
    // 0x8000D8FC: slti        $at, $fp, 0x5
    ctx->r1 = SIGNED(ctx->r30) < 0X5 ? 1 : 0;
    // 0x8000D900: beq         $at, $zero, L_8000D920
    if (ctx->r1 == 0) {
        // 0x8000D904: nop
    
            goto L_8000D920;
    }
    // 0x8000D904: nop

    // 0x8000D908: lb          $a0, 0x3($s3)
    ctx->r4 = MEM_B(ctx->r19, 0X3);
    // 0x8000D90C: lb          $a1, 0x1D6($s3)
    ctx->r5 = MEM_B(ctx->r19, 0X1D6);
    // 0x8000D910: jal         0x80004B40
    // 0x8000D914: nop

    racer_sound_init(rdram, ctx);
        goto after_19;
    // 0x8000D914: nop

    after_19:
    // 0x8000D918: b           L_8000D924
    // 0x8000D91C: sw          $v0, 0x118($s3)
    MEM_W(0X118, ctx->r19) = ctx->r2;
        goto L_8000D924;
    // 0x8000D91C: sw          $v0, 0x118($s3)
    MEM_W(0X118, ctx->r19) = ctx->r2;
L_8000D920:
    // 0x8000D920: sw          $zero, 0x118($s3)
    MEM_W(0X118, ctx->r19) = 0;
L_8000D924:
    // 0x8000D924: lb          $t9, 0x3($s3)
    ctx->r25 = MEM_B(ctx->r19, 0X3);
    // 0x8000D928: lw          $t8, 0x128($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X128);
    // 0x8000D92C: nop

    // 0x8000D930: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x8000D934: lb          $t5, 0x0($t7)
    ctx->r13 = MEM_B(ctx->r15, 0X0);
    // 0x8000D938: lw          $t9, 0x4C($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X4C);
    // 0x8000D93C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8000D940: sb          $t6, 0x12($t9)
    MEM_B(0X12, ctx->r25) = ctx->r14;
    // 0x8000D944: lb          $t8, 0x1D6($s3)
    ctx->r24 = MEM_B(ctx->r19, 0X1D6);
    // 0x8000D948: nop

    // 0x8000D94C: addiu       $t7, $t8, -0x5
    ctx->r15 = ADD32(ctx->r24, -0X5);
    // 0x8000D950: sltiu       $at, $t7, 0x9
    ctx->r1 = ctx->r15 < 0X9 ? 1 : 0;
    // 0x8000D954: beq         $at, $zero, L_8000D98C
    if (ctx->r1 == 0) {
        // 0x8000D958: sll         $t7, $t7, 2
        ctx->r15 = S32(ctx->r15 << 2);
            goto L_8000D98C;
    }
    // 0x8000D958: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x8000D95C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000D960: addu        $at, $at, $t7
    gpr jr_addend_8000D96C = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x8000D964: lw          $t7, 0x5154($at)
    ctx->r15 = ADD32(ctx->r1, 0X5154);
    // 0x8000D968: nop

    // 0x8000D96C: jr          $t7
    // 0x8000D970: nop

    switch (jr_addend_8000D96C >> 2) {
        case 0: goto L_8000D974; break;
        case 1: goto L_8000D974; break;
        case 2: goto L_8000D974; break;
        case 3: goto L_8000D974; break;
        case 4: goto L_8000D974; break;
        case 5: goto L_8000D98C; break;
        case 6: goto L_8000D974; break;
        case 7: goto L_8000D974; break;
        case 8: goto L_8000D974; break;
        default: switch_error(__func__, 0x8000D96C, 0x800E5154);
    }
    // 0x8000D970: nop

L_8000D974:
    // 0x8000D974: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000D978: jal         0x8005C2F0
    // 0x8000D97C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    racer_special_init(rdram, ctx);
        goto after_20;
    // 0x8000D97C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_20:
    // 0x8000D980: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D984: b           L_8000D994
    // 0x8000D988: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_8000D994;
    // 0x8000D988: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000D98C:
    // 0x8000D98C: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D990: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_8000D994:
    // 0x8000D994: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000D998: lw          $v1, -0x5110($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X5110);
    // 0x8000D99C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000D9A0: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8000D9A4: bne         $at, $zero, L_8000D440
    if (ctx->r1 != 0) {
        // 0x8000D9A8: nop
    
            goto L_8000D440;
    }
    // 0x8000D9A8: nop

L_8000D9AC:
    // 0x8000D9AC: lw          $a0, 0x68($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X68);
    // 0x8000D9B0: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x8000D9B4: beq         $a0, $at, L_8000D9C4
    if (ctx->r4 == ctx->r1) {
        // 0x8000D9B8: or          $s4, $zero, $zero
        ctx->r20 = 0 | 0;
            goto L_8000D9C4;
    }
    // 0x8000D9B8: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8000D9BC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D9C0: sb          $zero, -0x52C4($at)
    MEM_B(-0X52C4, ctx->r1) = 0;
L_8000D9C4:
    // 0x8000D9C4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000D9C8: lb          $t5, -0x52C4($t5)
    ctx->r13 = MEM_B(ctx->r13, -0X52C4);
    // 0x8000D9CC: nop

    // 0x8000D9D0: beq         $t5, $zero, L_8000D9DC
    if (ctx->r13 == 0) {
        // 0x8000D9D4: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000D9DC;
    }
    // 0x8000D9D4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000D9D8: sb          $zero, -0x52E0($at)
    MEM_B(-0X52E0, ctx->r1) = 0;
L_8000D9DC:
    // 0x8000D9DC: jal         0x8006DA0C
    // 0x8000D9E0: nop

    get_game_mode(rdram, ctx);
        goto after_21;
    // 0x8000D9E0: nop

    after_21:
    // 0x8000D9E4: bne         $v0, $zero, L_8000DA9C
    if (ctx->r2 != 0) {
        // 0x8000D9E8: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_8000DA9C;
    }
    // 0x8000D9E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000D9EC: lw          $v0, -0x51A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A4);
    // 0x8000D9F0: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x8000D9F4: blez        $v0, L_8000DA9C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8000D9F8: lui         $s3, 0x8012
        ctx->r19 = S32(0X8012 << 16);
            goto L_8000DA9C;
    }
    // 0x8000D9F8: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000D9FC: addiu       $s3, $s3, -0x51A8
    ctx->r19 = ADD32(ctx->r19, -0X51A8);
L_8000DA00:
    // 0x8000DA00: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x8000DA04: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000DA08: addu        $t9, $t6, $s5
    ctx->r25 = ADD32(ctx->r14, ctx->r21);
    // 0x8000DA0C: lw          $s1, 0x0($t9)
    ctx->r17 = MEM_W(ctx->r25, 0X0);
    // 0x8000DA10: nop

    // 0x8000DA14: lw          $t8, 0x40($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X40);
    // 0x8000DA18: nop

    // 0x8000DA1C: lhu         $s0, 0x30($t8)
    ctx->r16 = MEM_HU(ctx->r24, 0X30);
    // 0x8000DA20: nop

    // 0x8000DA24: andi        $t7, $s0, 0x20
    ctx->r15 = ctx->r16 & 0X20;
    // 0x8000DA28: beq         $t7, $zero, L_8000DA58
    if (ctx->r15 == 0) {
        // 0x8000DA2C: andi        $t6, $s0, 0x40
        ctx->r14 = ctx->r16 & 0X40;
            goto L_8000DA58;
    }
    // 0x8000DA2C: andi        $t6, $s0, 0x40
    ctx->r14 = ctx->r16 & 0X40;
    // 0x8000DA30: lbu         $t5, -0x510B($t5)
    ctx->r13 = MEM_BU(ctx->r13, -0X510B);
    // 0x8000DA34: nop

    // 0x8000DA38: beq         $t5, $zero, L_8000DA58
    if (ctx->r13 == 0) {
        // 0x8000DA3C: nop
    
            goto L_8000DA58;
    }
    // 0x8000DA3C: nop

    // 0x8000DA40: jal         0x8000FFB8
    // 0x8000DA44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_22;
    // 0x8000DA44: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_22:
    // 0x8000DA48: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000DA4C: lw          $v0, -0x51A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A4);
    // 0x8000DA50: b           L_8000DA8C
    // 0x8000DA54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
        goto L_8000DA8C;
    // 0x8000DA54: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8000DA58:
    // 0x8000DA58: beq         $t6, $zero, L_8000DA88
    if (ctx->r14 == 0) {
        // 0x8000DA5C: nop
    
            goto L_8000DA88;
    }
    // 0x8000DA5C: nop

    // 0x8000DA60: lw          $t9, 0x144($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X144);
    // 0x8000DA64: nop

    // 0x8000DA68: slti        $at, $t9, 0x2
    ctx->r1 = SIGNED(ctx->r25) < 0X2 ? 1 : 0;
    // 0x8000DA6C: bne         $at, $zero, L_8000DA88
    if (ctx->r1 != 0) {
        // 0x8000DA70: nop
    
            goto L_8000DA88;
    }
    // 0x8000DA70: nop

    // 0x8000DA74: jal         0x8000FFB8
    // 0x8000DA78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    free_object(rdram, ctx);
        goto after_23;
    // 0x8000DA78: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_23:
    // 0x8000DA7C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8000DA80: lw          $v0, -0x51A4($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X51A4);
    // 0x8000DA84: nop

L_8000DA88:
    // 0x8000DA88: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
L_8000DA8C:
    // 0x8000DA8C: slt         $at, $s2, $v0
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8000DA90: bne         $at, $zero, L_8000DA00
    if (ctx->r1 != 0) {
        // 0x8000DA94: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8000DA00;
    }
    // 0x8000DA94: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
    // 0x8000DA98: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8000DA9C:
    // 0x8000DA9C: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8000DAA0: addiu       $s5, $s5, -0x38E8
    ctx->r21 = ADD32(ctx->r21, -0X38E8);
    // 0x8000DAA4: jal         0x80059B4C
    // 0x8000DAA8: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    timetrial_free_staff_ghost(rdram, ctx);
        goto after_24;
    // 0x8000DAA8: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    after_24:
    // 0x8000DAAC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000DAB0: addiu       $s1, $s1, -0x52C8
    ctx->r17 = ADD32(ctx->r17, -0X52C8);
    // 0x8000DAB4: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x8000DAB8: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8000DABC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000DAC0: lbu         $t7, -0x510B($t7)
    ctx->r15 = MEM_BU(ctx->r15, -0X510B);
    // 0x8000DAC4: nop

    // 0x8000DAC8: beq         $t7, $zero, L_8000DC90
    if (ctx->r15 == 0) {
        // 0x8000DACC: nop
    
            goto L_8000DC90;
    }
    // 0x8000DACC: nop

    // 0x8000DAD0: lw          $t5, 0x144($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X144);
    // 0x8000DAD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000DAD8: bne         $t5, $at, L_8000DC90
    if (ctx->r13 != ctx->r1) {
        // 0x8000DADC: nop
    
            goto L_8000DC90;
    }
    // 0x8000DADC: nop

    // 0x8000DAE0: jal         0x80059944
    // 0x8000DAE4: nop

    timetrial_reset_player_ghost(rdram, ctx);
        goto after_25;
    // 0x8000DAE4: nop

    after_25:
    // 0x8000DAE8: jal         0x8001B668
    // 0x8000DAEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    timetrial_init_player_ghost(rdram, ctx);
        goto after_26;
    // 0x8000DAEC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_26:
    // 0x8000DAF0: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000DAF4: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8000DAF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DAFC: addiu       $s0, $s0, -0x38D8
    ctx->r16 = ADD32(ctx->r16, -0X38D8);
    // 0x8000DB00: sb          $zero, -0x38D0($at)
    MEM_B(-0X38D0, ctx->r1) = 0;
    // 0x8000DB04: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8000DB08: nop

    // 0x8000DB0C: slti        $at, $t6, 0x5
    ctx->r1 = SIGNED(ctx->r14) < 0X5 ? 1 : 0;
    // 0x8000DB10: bne         $at, $zero, L_8000DB1C
    if (ctx->r1 != 0) {
        // 0x8000DB14: nop
    
            goto L_8000DB1C;
    }
    // 0x8000DB14: nop

    // 0x8000DB18: sh          $zero, 0x0($s0)
    MEM_H(0X0, ctx->r16) = 0;
L_8000DB1C:
    // 0x8000DB1C: jal         0x8001B288
    // 0x8000DB20: nop

    timetrial_valid_player_ghost(rdram, ctx);
        goto after_27;
    // 0x8000DB20: nop

    after_27:
    // 0x8000DB24: beq         $v0, $zero, L_8000DBD8
    if (ctx->r2 == 0) {
        // 0x8000DB28: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_8000DBD8;
    }
    // 0x8000DB28: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8000DB2C: lh          $t7, 0x0($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X0);
    // 0x8000DB30: lh          $t9, -0x38D4($t9)
    ctx->r25 = MEM_H(ctx->r25, -0X38D4);
    // 0x8000DB34: sll         $t5, $t7, 2
    ctx->r13 = S32(ctx->r15 << 2);
    // 0x8000DB38: addu        $t5, $t5, $t7
    ctx->r13 = ADD32(ctx->r13, ctx->r15);
    // 0x8000DB3C: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8000DB40: sll         $t8, $t9, 1
    ctx->r24 = S32(ctx->r25 << 1);
    // 0x8000DB44: addu        $t9, $t8, $t6
    ctx->r25 = ADD32(ctx->r24, ctx->r14);
    // 0x8000DB48: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000DB4C: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8000DB50: lh          $v0, -0x3858($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X3858);
    // 0x8000DB54: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000DB58: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x8000DB5C: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000DB60: ori         $t8, $t5, 0x10
    ctx->r24 = ctx->r13 | 0X10;
    // 0x8000DB64: sb          $t8, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r24;
    // 0x8000DB68: sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    // 0x8000DB6C: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x8000DB70: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000DB74: sh          $t6, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r14;
    // 0x8000DB78: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8000DB7C: nop

    // 0x8000DB80: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
    // 0x8000DB84: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8000DB88: nop

    // 0x8000DB8C: sh          $t7, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r15;
    // 0x8000DB90: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8000DB94: jal         0x8000EA54
    // 0x8000DB98: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    spawn_object(rdram, ctx);
        goto after_28;
    // 0x8000DB98: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    after_28:
    // 0x8000DB9C: addiu       $t8, $zero, 0x3A
    ctx->r24 = ADD32(0, 0X3A);
    // 0x8000DBA0: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8000DBA4: sh          $t8, 0x48($v0)
    MEM_H(0X48, ctx->r2) = ctx->r24;
    // 0x8000DBA8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DBAC: lwc1        $f4, 0x5178($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5178);
    // 0x8000DBB0: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    // 0x8000DBB4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8000DBB8: swc1        $f4, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f4.u32l;
    // 0x8000DBBC: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x8000DBC0: addiu       $v1, $v1, -0x52CC
    ctx->r3 = ADD32(ctx->r3, -0X52CC);
    // 0x8000DBC4: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x8000DBC8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8000DBCC: lw          $s3, 0x64($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X64);
    // 0x8000DBD0: addiu       $t5, $zero, 0x60
    ctx->r13 = ADD32(0, 0X60);
    // 0x8000DBD4: sb          $t5, 0x1F7($s3)
    MEM_B(0X1F7, ctx->r19) = ctx->r13;
L_8000DBD8:
    // 0x8000DBD8: jal         0x8006BD88
    // 0x8000DBDC: nop

    level_id(rdram, ctx);
        goto after_29;
    // 0x8000DBDC: nop

    after_29:
    // 0x8000DBE0: jal         0x8001B4FC
    // 0x8000DBE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    timetrial_init_staff_ghost(rdram, ctx);
        goto after_30;
    // 0x8000DBE4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_30:
    // 0x8000DBE8: beq         $v0, $zero, L_8000DC90
    if (ctx->r2 == 0) {
        // 0x8000DBEC: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_8000DC90;
    }
    // 0x8000DBEC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8000DBF0: lh          $t8, -0x517C($t8)
    ctx->r24 = MEM_H(ctx->r24, -0X517C);
    // 0x8000DBF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8000DBF8: sll         $t6, $t8, 2
    ctx->r14 = S32(ctx->r24 << 2);
    // 0x8000DBFC: addu        $t6, $t6, $t8
    ctx->r14 = ADD32(ctx->r14, ctx->r24);
    // 0x8000DC00: sll         $t9, $t6, 2
    ctx->r25 = S32(ctx->r14 << 2);
    // 0x8000DC04: addu        $v0, $v0, $t9
    ctx->r2 = ADD32(ctx->r2, ctx->r25);
    // 0x8000DC08: lh          $v0, -0x3848($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X3848);
    // 0x8000DC0C: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000DC10: andi        $t7, $v0, 0x100
    ctx->r15 = ctx->r2 & 0X100;
    // 0x8000DC14: sra         $t5, $t7, 1
    ctx->r13 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8000DC18: ori         $t8, $t5, 0x10
    ctx->r24 = ctx->r13 | 0X10;
    // 0x8000DC1C: sb          $t8, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r24;
    // 0x8000DC20: sb          $v0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r2;
    // 0x8000DC24: lw          $t6, 0xF4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XF4);
    // 0x8000DC28: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000DC2C: sh          $t6, 0x2($s6)
    MEM_H(0X2, ctx->r22) = ctx->r14;
    // 0x8000DC30: lw          $t9, 0xD4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD4);
    // 0x8000DC34: nop

    // 0x8000DC38: sh          $t9, 0x4($s6)
    MEM_H(0X4, ctx->r22) = ctx->r25;
    // 0x8000DC3C: lw          $t7, 0xB4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB4);
    // 0x8000DC40: nop

    // 0x8000DC44: sh          $t7, 0x6($s6)
    MEM_H(0X6, ctx->r22) = ctx->r15;
    // 0x8000DC48: lw          $t5, 0x94($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X94);
    // 0x8000DC4C: jal         0x8000EA54
    // 0x8000DC50: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    spawn_object(rdram, ctx);
        goto after_31;
    // 0x8000DC50: sh          $t5, 0xC($s6)
    MEM_H(0XC, ctx->r22) = ctx->r13;
    after_31:
    // 0x8000DC54: addiu       $t8, $zero, 0x3A
    ctx->r24 = ADD32(0, 0X3A);
    // 0x8000DC58: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
    // 0x8000DC5C: sh          $t8, 0x48($v0)
    MEM_H(0X48, ctx->r2) = ctx->r24;
    // 0x8000DC60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DC64: lwc1        $f6, 0x517C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X517C);
    // 0x8000DC68: lw          $t6, 0x50($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X50);
    // 0x8000DC6C: addiu       $t5, $zero, 0x60
    ctx->r13 = ADD32(0, 0X60);
    // 0x8000DC70: swc1        $f6, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f6.u32l;
    // 0x8000DC74: lw          $t9, 0x4C($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X4C);
    // 0x8000DC78: nop

    // 0x8000DC7C: sh          $zero, 0x14($t9)
    MEM_H(0X14, ctx->r25) = 0;
    // 0x8000DC80: sw          $v0, 0x0($s5)
    MEM_W(0X0, ctx->r21) = ctx->r2;
    // 0x8000DC84: lw          $s3, 0x64($v0)
    ctx->r19 = MEM_W(ctx->r2, 0X64);
    // 0x8000DC88: nop

    // 0x8000DC8C: sb          $t5, 0x1F7($s3)
    MEM_B(0X1F7, ctx->r19) = ctx->r13;
L_8000DC90:
    // 0x8000DC90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8000DC94: lw          $t6, -0x5110($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X5110);
    // 0x8000DC98: addiu       $t8, $zero, 0x64
    ctx->r24 = ADD32(0, 0X64);
    // 0x8000DC9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DCA0: blez        $t6, L_8000DE44
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8000DCA4: sw          $t8, -0x5250($at)
        MEM_W(-0X5250, ctx->r1) = ctx->r24;
            goto L_8000DE44;
    }
    // 0x8000DCA4: sw          $t8, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = ctx->r24;
    // 0x8000DCA8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8000DCAC:
    // 0x8000DCAC: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000DCB0: lw          $t9, -0x511C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X511C);
    // 0x8000DCB4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000DCB8: addu        $t7, $t9, $s5
    ctx->r15 = ADD32(ctx->r25, ctx->r21);
    // 0x8000DCBC: lw          $s1, 0x0($t7)
    ctx->r17 = MEM_W(ctx->r15, 0X0);
    // 0x8000DCC0: nop

    // 0x8000DCC4: lw          $s3, 0x64($s1)
    ctx->r19 = MEM_W(ctx->r17, 0X64);
    // 0x8000DCC8: nop

    // 0x8000DCCC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_8000DCD0:
    // 0x8000DCD0: jal         0x8004DE38
    // 0x8000DCD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    update_player_racer(rdram, ctx);
        goto after_32;
    // 0x8000DCD4: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_32:
    // 0x8000DCD8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000DCDC: slti        $at, $s0, 0xA
    ctx->r1 = SIGNED(ctx->r16) < 0XA ? 1 : 0;
    // 0x8000DCE0: bne         $at, $zero, L_8000DCD0
    if (ctx->r1 != 0) {
        // 0x8000DCE4: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_8000DCD0;
    }
    // 0x8000DCE4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8000DCE8: lh          $t5, 0x0($s3)
    ctx->r13 = MEM_H(ctx->r19, 0X0);
    // 0x8000DCEC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000DCF0: bne         $t5, $at, L_8000DD68
    if (ctx->r13 != ctx->r1) {
        // 0x8000DCF4: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8000DD68;
    }
    // 0x8000DCF4: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000DCF8: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8000DCFC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8000DD00: lb          $a0, 0x55($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X55);
    // 0x8000DD04: andi        $t8, $s4, 0x1
    ctx->r24 = ctx->r20 & 0X1;
    // 0x8000DD08: blez        $a0, L_8000DDCC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000DD0C: or          $s4, $t8, $zero
        ctx->r20 = ctx->r24 | 0;
            goto L_8000DDCC;
    }
    // 0x8000DD0C: or          $s4, $t8, $zero
    ctx->r20 = ctx->r24 | 0;
    // 0x8000DD10: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_8000DD14:
    // 0x8000DD14: lw          $t9, 0x68($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X68);
    // 0x8000DD18: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000DD1C: addu        $t7, $t9, $v1
    ctx->r15 = ADD32(ctx->r25, ctx->r3);
    // 0x8000DD20: lw          $v0, 0x0($t7)
    ctx->r2 = MEM_W(ctx->r15, 0X0);
    // 0x8000DD24: nop

    // 0x8000DD28: beq         $v0, $zero, L_8000DD58
    if (ctx->r2 == 0) {
        // 0x8000DD2C: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DD58;
    }
    // 0x8000DD2C: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DD30: lb          $t5, 0x20($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X20);
    // 0x8000DD34: sll         $t8, $s4, 1
    ctx->r24 = S32(ctx->r20 << 1);
    // 0x8000DD38: beq         $t5, $zero, L_8000DD58
    if (ctx->r13 == 0) {
        // 0x8000DD3C: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DD58;
    }
    // 0x8000DD3C: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DD40: sb          $t8, 0x20($v0)
    MEM_B(0X20, ctx->r2) = ctx->r24;
    // 0x8000DD44: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8000DD48: nop

    // 0x8000DD4C: lb          $a0, 0x55($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X55);
    // 0x8000DD50: nop

    // 0x8000DD54: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
L_8000DD58:
    // 0x8000DD58: bne         $at, $zero, L_8000DD14
    if (ctx->r1 != 0) {
        // 0x8000DD5C: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000DD14;
    }
    // 0x8000DD5C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x8000DD60: b           L_8000DDCC
    // 0x8000DD64: nop

        goto L_8000DDCC;
    // 0x8000DD64: nop

L_8000DD68:
    // 0x8000DD68: lw          $t9, 0x40($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X40);
    // 0x8000DD6C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000DD70: lb          $a0, 0x55($t9)
    ctx->r4 = MEM_B(ctx->r25, 0X55);
    // 0x8000DD74: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8000DD78: blez        $a0, L_8000DDCC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8000DD7C: nop
    
            goto L_8000DDCC;
    }
    // 0x8000DD7C: nop

L_8000DD80:
    // 0x8000DD80: lw          $t7, 0x68($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X68);
    // 0x8000DD84: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000DD88: addu        $t5, $t7, $v1
    ctx->r13 = ADD32(ctx->r15, ctx->r3);
    // 0x8000DD8C: lw          $v0, 0x0($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X0);
    // 0x8000DD90: nop

    // 0x8000DD94: beq         $v0, $zero, L_8000DDC4
    if (ctx->r2 == 0) {
        // 0x8000DD98: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DDC4;
    }
    // 0x8000DD98: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DD9C: lb          $t8, 0x20($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X20);
    // 0x8000DDA0: nop

    // 0x8000DDA4: beq         $t8, $zero, L_8000DDC4
    if (ctx->r24 == 0) {
        // 0x8000DDA8: slt         $at, $s0, $a0
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
            goto L_8000DDC4;
    }
    // 0x8000DDA8: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000DDAC: sb          $zero, 0x20($v0)
    MEM_B(0X20, ctx->r2) = 0;
    // 0x8000DDB0: lw          $t6, 0x40($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X40);
    // 0x8000DDB4: nop

    // 0x8000DDB8: lb          $a0, 0x55($t6)
    ctx->r4 = MEM_B(ctx->r14, 0X55);
    // 0x8000DDBC: nop

    // 0x8000DDC0: slt         $at, $s0, $a0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r4) ? 1 : 0;
L_8000DDC4:
    // 0x8000DDC4: bne         $at, $zero, L_8000DD80
    if (ctx->r1 != 0) {
        // 0x8000DDC8: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000DD80;
    }
    // 0x8000DDC8: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000DDCC:
    // 0x8000DDCC: jal         0x8009C30C
    // 0x8000DDD0: nop

    get_filtered_cheats(rdram, ctx);
        goto after_33;
    // 0x8000DDD0: nop

    after_33:
    // 0x8000DDD4: andi        $t9, $v0, 0x10
    ctx->r25 = ctx->r2 & 0X10;
    // 0x8000DDD8: beq         $t9, $zero, L_8000DDF4
    if (ctx->r25 == 0) {
        // 0x8000DDDC: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000DDF4;
    }
    // 0x8000DDDC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DDE0: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000DDE4: lwc1        $f10, 0x5180($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X5180);
    // 0x8000DDE8: nop

    // 0x8000DDEC: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x8000DDF0: swc1        $f16, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f16.u32l;
L_8000DDF4:
    // 0x8000DDF4: jal         0x8009C30C
    // 0x8000DDF8: nop

    get_filtered_cheats(rdram, ctx);
        goto after_34;
    // 0x8000DDF8: nop

    after_34:
    // 0x8000DDFC: andi        $t7, $v0, 0x20
    ctx->r15 = ctx->r2 & 0X20;
    // 0x8000DE00: beq         $t7, $zero, L_8000DE1C
    if (ctx->r15 == 0) {
        // 0x8000DE04: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_8000DE1C;
    }
    // 0x8000DE04: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000DE08: lwc1        $f18, 0x8($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X8);
    // 0x8000DE0C: lwc1        $f4, 0x5184($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X5184);
    // 0x8000DE10: nop

    // 0x8000DE14: mul.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f4.fl);
    // 0x8000DE18: swc1        $f6, 0x8($s1)
    MEM_W(0X8, ctx->r17) = ctx->f6.u32l;
L_8000DE1C:
    // 0x8000DE1C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000DE20: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000DE24: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000DE28: swc1        $f0, 0x90($s3)
    MEM_W(0X90, ctx->r19) = ctx->f0.u32l;
    // 0x8000DE2C: swc1        $f0, 0x8C($s3)
    MEM_W(0X8C, ctx->r19) = ctx->f0.u32l;
    // 0x8000DE30: lw          $t5, -0x5110($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X5110);
    // 0x8000DE34: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000DE38: slt         $at, $s2, $t5
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000DE3C: bne         $at, $zero, L_8000DCAC
    if (ctx->r1 != 0) {
        // 0x8000DE40: addiu       $s5, $s5, 0x4
        ctx->r21 = ADD32(ctx->r21, 0X4);
            goto L_8000DCAC;
    }
    // 0x8000DE40: addiu       $s5, $s5, 0x4
    ctx->r21 = ADD32(ctx->r21, 0X4);
L_8000DE44:
    // 0x8000DE44: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000DE48: lw          $t6, 0x64($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X64);
    // 0x8000DE4C: beq         $t8, $zero, L_8000DE7C
    if (ctx->r24 == 0) {
        // 0x8000DE50: addiu       $t5, $zero, 0x50
        ctx->r13 = ADD32(0, 0X50);
            goto L_8000DE7C;
    }
    // 0x8000DE50: addiu       $t5, $zero, 0x50
    ctx->r13 = ADD32(0, 0X50);
    // 0x8000DE54: bne         $t6, $zero, L_8000DE7C
    if (ctx->r14 != 0) {
        // 0x8000DE58: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8000DE7C;
    }
    // 0x8000DE58: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8000DE5C: lbu         $t9, -0x510B($t9)
    ctx->r25 = MEM_BU(ctx->r25, -0X510B);
    // 0x8000DE60: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000DE64: bne         $t9, $zero, L_8000DE7C
    if (ctx->r25 != 0) {
        // 0x8000DE68: nop
    
            goto L_8000DE7C;
    }
    // 0x8000DE68: nop

    // 0x8000DE6C: lb          $t7, -0x52C4($t7)
    ctx->r15 = MEM_B(ctx->r15, -0X52C4);
    // 0x8000DE70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DE74: beq         $t7, $zero, L_8000DE88
    if (ctx->r15 == 0) {
        // 0x8000DE78: nop
    
            goto L_8000DE88;
    }
    // 0x8000DE78: nop

L_8000DE7C:
    // 0x8000DE7C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DE80: b           L_8000DE8C
    // 0x8000DE84: sw          $t5, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = ctx->r13;
        goto L_8000DE8C;
    // 0x8000DE84: sw          $t5, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = ctx->r13;
L_8000DE88:
    // 0x8000DE88: sw          $zero, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = 0;
L_8000DE8C:
    // 0x8000DE8C: lw          $t8, 0x68($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X68);
    // 0x8000DE90: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x8000DE94: bne         $t8, $zero, L_8000DF00
    if (ctx->r24 != 0) {
        // 0x8000DE98: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8000DF00;
    }
    // 0x8000DE98: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8000DE9C: bne         $t6, $at, L_8000DF00
    if (ctx->r14 != ctx->r1) {
        // 0x8000DEA0: nop
    
            goto L_8000DF00;
    }
    // 0x8000DEA0: nop

    // 0x8000DEA4: jal         0x8009EC70
    // 0x8000DEA8: nop

    is_in_adventure_two(rdram, ctx);
        goto after_35;
    // 0x8000DEA8: nop

    after_35:
    // 0x8000DEAC: bne         $v0, $zero, L_8000DF00
    if (ctx->r2 != 0) {
        // 0x8000DEB0: nop
    
            goto L_8000DF00;
    }
    // 0x8000DEB0: nop

    // 0x8000DEB4: jal         0x8006C19C
    // 0x8000DEB8: nop

    race_is_adventure_2P(rdram, ctx);
        goto after_36;
    // 0x8000DEB8: nop

    after_36:
    // 0x8000DEBC: bne         $v0, $zero, L_8000DF00
    if (ctx->r2 != 0) {
        // 0x8000DEC0: or          $s2, $zero, $zero
        ctx->r18 = 0 | 0;
            goto L_8000DF00;
    }
    // 0x8000DEC0: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8000DEC4: addiu       $s3, $zero, 0x3
    ctx->r19 = ADD32(0, 0X3);
    // 0x8000DEC8: addiu       $s1, $zero, 0x8
    ctx->r17 = ADD32(0, 0X8);
    // 0x8000DECC: addiu       $s0, $zero, 0x32
    ctx->r16 = ADD32(0, 0X32);
L_8000DED0:
    // 0x8000DED0: sb          $s0, 0x0($s6)
    MEM_B(0X0, ctx->r22) = ctx->r16;
    // 0x8000DED4: sb          $s1, 0x1($s6)
    MEM_B(0X1, ctx->r22) = ctx->r17;
    // 0x8000DED8: sh          $zero, 0x2($s6)
    MEM_H(0X2, ctx->r22) = 0;
    // 0x8000DEDC: sh          $zero, 0x4($s6)
    MEM_H(0X4, ctx->r22) = 0;
    // 0x8000DEE0: sh          $zero, 0x6($s6)
    MEM_H(0X6, ctx->r22) = 0;
    // 0x8000DEE4: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    // 0x8000DEE8: jal         0x8000EA54
    // 0x8000DEEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_37;
    // 0x8000DEEC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_37:
    // 0x8000DEF0: sw          $s2, 0x78($v0)
    MEM_W(0X78, ctx->r2) = ctx->r18;
    // 0x8000DEF4: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8000DEF8: bne         $s2, $s3, L_8000DED0
    if (ctx->r18 != ctx->r19) {
        // 0x8000DEFC: sw          $zero, 0x3C($v0)
        MEM_W(0X3C, ctx->r2) = 0;
            goto L_8000DED0;
    }
    // 0x8000DEFC: sw          $zero, 0x3C($v0)
    MEM_W(0X3C, ctx->r2) = 0;
L_8000DF00:
    // 0x8000DF00: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DF04: sh          $zero, -0x52B2($at)
    MEM_H(-0X52B2, ctx->r1) = 0;
    // 0x8000DF08: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000DF0C: sw          $zero, -0x524C($at)
    MEM_W(-0X524C, ctx->r1) = 0;
    // 0x8000DF10: jal         0x8009D330
    // 0x8000DF14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_38;
    // 0x8000DF14: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_38:
    // 0x8000DF18: lbu         $t9, 0x48($s7)
    ctx->r25 = MEM_BU(ctx->r23, 0X48);
    // 0x8000DF1C: nop

    // 0x8000DF20: bne         $t9, $zero, L_8000E018
    if (ctx->r25 != 0) {
        // 0x8000DF24: lw          $t6, 0x130($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X130);
            goto L_8000E018;
    }
    // 0x8000DF24: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x8000DF28: jal         0x8009C2D0
    // 0x8000DF2C: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_39;
    // 0x8000DF2C: nop

    after_39:
    // 0x8000DF30: bne         $v0, $zero, L_8000E014
    if (ctx->r2 != 0) {
        // 0x8000DF34: addiu       $a0, $zero, 0x10
        ctx->r4 = ADD32(0, 0X10);
            goto L_8000E014;
    }
    // 0x8000DF34: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    // 0x8000DF38: jal         0x8001E29C
    // 0x8000DF3C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    get_misc_asset(rdram, ctx);
        goto after_40;
    // 0x8000DF3C: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    after_40:
    // 0x8000DF40: lhu         $v1, 0x14($s7)
    ctx->r3 = MEM_HU(ctx->r23, 0X14);
    // 0x8000DF44: nop

    // 0x8000DF48: andi        $t7, $v1, 0x1
    ctx->r15 = ctx->r3 & 0X1;
    // 0x8000DF4C: bne         $t7, $zero, L_8000DF78
    if (ctx->r15 != 0) {
        // 0x8000DF50: andi        $t9, $v1, 0x2
        ctx->r25 = ctx->r3 & 0X2;
            goto L_8000DF78;
    }
    // 0x8000DF50: andi        $t9, $v1, 0x2
    ctx->r25 = ctx->r3 & 0X2;
    // 0x8000DF54: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x8000DF58: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8000DF5C: lh          $t8, 0x0($t5)
    ctx->r24 = MEM_H(ctx->r13, 0X0);
    // 0x8000DF60: nop

    // 0x8000DF64: slt         $at, $t8, $t6
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000DF68: bne         $at, $zero, L_8000DF78
    if (ctx->r1 != 0) {
        // 0x8000DF6C: nop
    
            goto L_8000DF78;
    }
    // 0x8000DF6C: nop

    // 0x8000DF70: b           L_8000DFCC
    // 0x8000DF74: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
        goto L_8000DFCC;
    // 0x8000DF74: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_8000DF78:
    // 0x8000DF78: bne         $t9, $zero, L_8000DFA4
    if (ctx->r25 != 0) {
        // 0x8000DF7C: andi        $t6, $v1, 0x4
        ctx->r14 = ctx->r3 & 0X4;
            goto L_8000DFA4;
    }
    // 0x8000DF7C: andi        $t6, $v1, 0x4
    ctx->r14 = ctx->r3 & 0X4;
    // 0x8000DF80: lw          $t7, 0x0($s7)
    ctx->r15 = MEM_W(ctx->r23, 0X0);
    // 0x8000DF84: lb          $t8, 0x1($v0)
    ctx->r24 = MEM_B(ctx->r2, 0X1);
    // 0x8000DF88: lh          $t5, 0x0($t7)
    ctx->r13 = MEM_H(ctx->r15, 0X0);
    // 0x8000DF8C: nop

    // 0x8000DF90: slt         $at, $t5, $t8
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8000DF94: bne         $at, $zero, L_8000DFA4
    if (ctx->r1 != 0) {
        // 0x8000DF98: nop
    
            goto L_8000DFA4;
    }
    // 0x8000DF98: nop

    // 0x8000DF9C: b           L_8000DFCC
    // 0x8000DFA0: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
        goto L_8000DFCC;
    // 0x8000DFA0: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
L_8000DFA4:
    // 0x8000DFA4: bne         $t6, $zero, L_8000DFCC
    if (ctx->r14 != 0) {
        // 0x8000DFA8: nop
    
            goto L_8000DFCC;
    }
    // 0x8000DFA8: nop

    // 0x8000DFAC: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x8000DFB0: lb          $t5, 0x2($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X2);
    // 0x8000DFB4: lh          $t7, 0x0($t9)
    ctx->r15 = MEM_H(ctx->r25, 0X0);
    // 0x8000DFB8: nop

    // 0x8000DFBC: slt         $at, $t7, $t5
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8000DFC0: bne         $at, $zero, L_8000DFCC
    if (ctx->r1 != 0) {
        // 0x8000DFC4: nop
    
            goto L_8000DFCC;
    }
    // 0x8000DFC4: nop

    // 0x8000DFC8: addiu       $s2, $zero, 0x3
    ctx->r18 = ADD32(0, 0X3);
L_8000DFCC:
    // 0x8000DFCC: beq         $s2, $zero, L_8000E018
    if (ctx->r18 == 0) {
        // 0x8000DFD0: lw          $t6, 0x130($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X130);
            goto L_8000E018;
    }
    // 0x8000DFD0: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
    // 0x8000DFD4: jal         0x80039320
    // 0x8000DFD8: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    set_taj_voice_line(rdram, ctx);
        goto after_41;
    // 0x8000DFD8: addiu       $a0, $zero, 0x250
    ctx->r4 = ADD32(0, 0X250);
    after_41:
    // 0x8000DFDC: lhu         $t8, 0x14($s7)
    ctx->r24 = MEM_HU(ctx->r23, 0X14);
    // 0x8000DFE0: addiu       $t6, $s2, 0x1F
    ctx->r14 = ADD32(ctx->r18, 0X1F);
    // 0x8000DFE4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000DFE8: sllv        $t7, $t9, $t6
    ctx->r15 = S32(ctx->r25 << (ctx->r14 & 31));
    // 0x8000DFEC: or          $t5, $t8, $t7
    ctx->r13 = ctx->r24 | ctx->r15;
    // 0x8000DFF0: sh          $t5, 0x14($s7)
    MEM_H(0X14, ctx->r23) = ctx->r13;
    // 0x8000DFF4: jal         0x800521B8
    // 0x8000DFF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    set_taj_status(rdram, ctx);
        goto after_42;
    // 0x8000DFF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_42:
    // 0x8000DFFC: jal         0x8009D330
    // 0x8000E000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    set_next_taj_challenge_menu(rdram, ctx);
        goto after_43;
    // 0x8000E000: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_43:
    // 0x8000E004: jal         0x8009C1A0
    // 0x8000E008: nop

    get_save_file_index(rdram, ctx);
        goto after_44;
    // 0x8000E008: nop

    after_44:
    // 0x8000E00C: jal         0x8006EC48
    // 0x8000E010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    safe_mark_write_save_file(rdram, ctx);
        goto after_45;
    // 0x8000E010: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_45:
L_8000E014:
    // 0x8000E014: lw          $t6, 0x130($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X130);
L_8000E018:
    // 0x8000E018: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8000E01C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E020: bltz        $t6, L_8000E038
    if (SIGNED(ctx->r14) < 0) {
        // 0x8000E024: sb          $t9, -0x52DC($at)
        MEM_B(-0X52DC, ctx->r1) = ctx->r25;
            goto L_8000E038;
    }
    // 0x8000E024: sb          $t9, -0x52DC($at)
    MEM_B(-0X52DC, ctx->r1) = ctx->r25;
    // 0x8000E028: lw          $t8, 0x130($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X130);
    // 0x8000E02C: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x8000E030: nop

    // 0x8000E034: sb          $t8, 0x3B($t7)
    MEM_B(0X3B, ctx->r15) = ctx->r24;
L_8000E038:
    // 0x8000E038: jal         0x8000E148
    // 0x8000E03C: nop

    racetype_demo(rdram, ctx);
        goto after_46;
    // 0x8000E03C: nop

    after_46:
    // 0x8000E040: beq         $v0, $zero, L_8000E068
    if (ctx->r2 == 0) {
        // 0x8000E044: nop
    
            goto L_8000E068;
    }
    // 0x8000E044: nop

    // 0x8000E048: jal         0x80072298
    // 0x8000E04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    rumble_init(rdram, ctx);
        goto after_47;
    // 0x8000E04C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_47:
    // 0x8000E050: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000E054: sw          $zero, -0x5250($at)
    MEM_W(-0X5250, ctx->r1) = 0;
    // 0x8000E058: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8000E05C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8000E060: jal         0x8006BD10
    // 0x8000E064: nop

    level_music_start(rdram, ctx);
        goto after_48;
    // 0x8000E064: nop

    after_48:
L_8000E068:
    // 0x8000E068: jal         0x800710B0
    // 0x8000E06C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_49;
    // 0x8000E06C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_49:
    // 0x8000E070: jal         0x80071140
    // 0x8000E074: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    mempool_free(rdram, ctx);
        goto after_50;
    // 0x8000E074: or          $a0, $s6, $zero
    ctx->r4 = ctx->r22 | 0;
    after_50:
    // 0x8000E078: jal         0x800710B0
    // 0x8000E07C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_51;
    // 0x8000E07C: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_51:
L_8000E080:
    // 0x8000E080: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8000E084: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000E088: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000E08C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000E090: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8000E094: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8000E098: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8000E09C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8000E0A0: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8000E0A4: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8000E0A8: jr          $ra
    // 0x8000E0AC: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
    return;
    // 0x8000E0AC: addiu       $sp, $sp, 0x150
    ctx->r29 = ADD32(ctx->r29, 0X150);
;}
RECOMP_FUNC void set_vehicle_id_for_menu(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DB20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DB24: jr          $ra
    // 0x8006DB28: sw          $a0, 0x351C($at)
    MEM_W(0X351C, ctx->r1) = ctx->r4;
    return;
    // 0x8006DB28: sw          $a0, 0x351C($at)
    MEM_W(0X351C, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void obj_init_weapon(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E5C8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8003E5CC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8003E5D0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x8003E5D4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8003E5D8: lw          $t7, 0x4C($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E5DC: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x8003E5E0: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x8003E5E4: lw          $t8, 0x4C($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E5E8: addiu       $t9, $zero, 0x18
    ctx->r25 = ADD32(0, 0X18);
    // 0x8003E5EC: sb          $zero, 0x11($t8)
    MEM_B(0X11, ctx->r24) = 0;
    // 0x8003E5F0: lw          $t0, 0x4C($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E5F4: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8003E5F8: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003E5FC: lw          $t1, 0x4C($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X4C);
    // 0x8003E600: addiu       $a0, $zero, 0x1E0
    ctx->r4 = ADD32(0, 0X1E0);
    // 0x8003E604: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003E608: jal         0x8000C8B4
    // 0x8003E60C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    normalise_time(rdram, ctx);
        goto after_0;
    // 0x8003E60C: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003E610: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x8003E614: nop

    // 0x8003E618: sw          $v0, 0x78($a1)
    MEM_W(0X78, ctx->r5) = ctx->r2;
    // 0x8003E61C: sw          $zero, 0x7C($a1)
    MEM_W(0X7C, ctx->r5) = 0;
    // 0x8003E620: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8003E624: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8003E628: jr          $ra
    // 0x8003E62C: nop

    return;
    // 0x8003E62C: nop

;}
RECOMP_FUNC void obj_init_wballoonpop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003E5B0: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003E5B4: jr          $ra
    // 0x8003E5B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003E5B8: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void func_80027568(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80027568: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x8002756C: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x80027570: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80027574: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x80027578: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x8002757C: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x80027580: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80027584: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x80027588: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x8002758C: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80027590: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80027594: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80027598: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8002759C: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800275A0: jal         0x8001BA74
    // 0x800275A4: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800275A4: addiu       $a0, $sp, 0xC4
    ctx->r4 = ADD32(ctx->r29, 0XC4);
    after_0:
    // 0x800275A8: lw          $t6, 0xC4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XC4);
    // 0x800275AC: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800275B0: bne         $t6, $zero, L_800275C0
    if (ctx->r14 != 0) {
        // 0x800275B4: nop
    
            goto L_800275C0;
    }
    // 0x800275B4: nop

    // 0x800275B8: b           L_800278AC
    // 0x800275BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800278AC;
    // 0x800275BC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800275C0:
    // 0x800275C0: jal         0x80066510
    // 0x800275C4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    check_if_showing_cutscene_camera(rdram, ctx);
        goto after_1;
    // 0x800275C4: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_1:
    // 0x800275C8: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x800275CC: bne         $v0, $zero, L_800275F8
    if (ctx->r2 != 0) {
        // 0x800275D0: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800275F8;
    }
    // 0x800275D0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800275D4: lw          $t7, -0x4F50($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X4F50);
    // 0x800275D8: nop

    // 0x800275DC: lh          $v0, 0x36($t7)
    ctx->r2 = MEM_H(ctx->r15, 0X36);
    // 0x800275E0: nop

    // 0x800275E4: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x800275E8: beq         $at, $zero, L_800275F8
    if (ctx->r1 == 0) {
        // 0x800275EC: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800275F8;
    }
    // 0x800275EC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800275F0: bne         $v0, $at, L_80027600
    if (ctx->r2 != ctx->r1) {
        // 0x800275F4: nop
    
            goto L_80027600;
    }
    // 0x800275F4: nop

L_800275F8:
    // 0x800275F8: b           L_800278AC
    // 0x800275FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800278AC;
    // 0x800275FC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80027600:
    // 0x80027600: jal         0x80066220
    // 0x80027604: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    get_current_viewport(rdram, ctx);
        goto after_2;
    // 0x80027604: sw          $a2, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r6;
    after_2:
    // 0x80027608: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x8002760C: lw          $a2, 0x80($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X80);
    // 0x80027610: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x80027614: blez        $t8, L_8002765C
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80027618: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_8002765C;
    }
    // 0x80027618: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x8002761C: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_80027620:
    // 0x80027620: addu        $t6, $a2, $t9
    ctx->r14 = ADD32(ctx->r6, ctx->r25);
    // 0x80027624: lw          $a1, 0x0($t6)
    ctx->r5 = MEM_W(ctx->r14, 0X0);
    // 0x80027628: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x8002762C: lw          $a0, 0x64($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X64);
    // 0x80027630: nop

    // 0x80027634: lh          $t7, 0x0($a0)
    ctx->r15 = MEM_H(ctx->r4, 0X0);
    // 0x80027638: nop

    // 0x8002763C: bne         $v0, $t7, L_80027650
    if (ctx->r2 != ctx->r15) {
        // 0x80027640: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_80027650;
    }
    // 0x80027640: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80027644: lw          $v1, 0xC4($sp)
    ctx->r3 = MEM_W(ctx->r29, 0XC4);
    // 0x80027648: or          $t3, $a1, $zero
    ctx->r11 = ctx->r5 | 0;
    // 0x8002764C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80027650:
    // 0x80027650: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80027654: bne         $at, $zero, L_80027620
    if (ctx->r1 != 0) {
        // 0x80027658: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_80027620;
    }
    // 0x80027658: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
L_8002765C:
    // 0x8002765C: bne         $t3, $zero, L_8002766C
    if (ctx->r11 != 0) {
        // 0x80027660: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_8002766C;
    }
    // 0x80027660: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80027664: b           L_800278AC
    // 0x80027668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800278AC;
    // 0x80027668: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8002766C:
    // 0x8002766C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80027670: lw          $a2, -0x4F50($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X4F50);
    // 0x80027674: addiu       $a1, $t3, 0xC
    ctx->r5 = ADD32(ctx->r11, 0XC);
    // 0x80027678: addiu       $a3, $zero, -0x1
    ctx->r7 = ADD32(0, -0X1);
    // 0x8002767C: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x80027680: jal         0x80031130
    // 0x80027684: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    generate_collision_candidates(rdram, ctx);
        goto after_3;
    // 0x80027684: addiu       $a2, $a2, 0xC
    ctx->r6 = ADD32(ctx->r6, 0XC);
    after_3:
    // 0x80027688: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002768C: lw          $v1, -0x2C88($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X2C88);
    // 0x80027690: lw          $t3, 0x7C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X7C);
    // 0x80027694: blez        $v1, L_800278A8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80027698: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800278A8;
    }
    // 0x80027698: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8002769C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800276A0: lw          $t9, -0x2C90($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2C90);
    // 0x800276A4: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x800276A8: sll         $t4, $zero, 2
    ctx->r12 = S32(0 << 2);
    // 0x800276AC: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x800276B0: mtc1        $at, $f26
    ctx->f26.u32l = ctx->r1;
    // 0x800276B4: lw          $ra, 0xE4($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE4);
    // 0x800276B8: sw          $t6, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r14;
    // 0x800276BC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x800276C0: addu        $t5, $t9, $t4
    ctx->r13 = ADD32(ctx->r25, ctx->r12);
L_800276C4:
    // 0x800276C4: lw          $a0, 0x0($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X0);
    // 0x800276C8: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800276CC: blez        $a0, L_800276DC
    if (SIGNED(ctx->r4) <= 0) {
        // 0x800276D0: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_800276DC;
    }
    // 0x800276D0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800276D4: b           L_80027888
    // 0x800276D8: or          $ra, $a0, $at
    ctx->r31 = ctx->r4 | ctx->r1;
        goto L_80027888;
    // 0x800276D8: or          $ra, $a0, $at
    ctx->r31 = ctx->r4 | ctx->r1;
L_800276DC:
    // 0x800276DC: lhu         $t7, 0x0($a0)
    ctx->r15 = MEM_HU(ctx->r4, 0X0);
    // 0x800276E0: lw          $t0, 0x18($ra)
    ctx->r8 = MEM_W(ctx->r31, 0X18);
    // 0x800276E4: lw          $a1, -0x4F50($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X4F50);
    // 0x800276E8: sll         $t8, $t7, 4
    ctx->r24 = S32(ctx->r15 << 4);
    // 0x800276EC: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x800276F0: lwc1        $f2, 0x0($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800276F4: lwc1        $f28, 0xC($a1)
    ctx->f28.u32l = MEM_W(ctx->r5, 0XC);
    // 0x800276F8: lwc1        $f20, 0x4($v1)
    ctx->f20.u32l = MEM_W(ctx->r3, 0X4);
    // 0x800276FC: mul.s       $f4, $f28, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f2.fl);
    // 0x80027700: lwc1        $f30, 0x10($a1)
    ctx->f30.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80027704: lwc1        $f22, 0x8($v1)
    ctx->f22.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80027708: lwc1        $f0, 0x14($a1)
    ctx->f0.u32l = MEM_W(ctx->r5, 0X14);
    // 0x8002770C: mul.s       $f6, $f20, $f30
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f30.fl);
    // 0x80027710: lwc1        $f24, 0xC($v1)
    ctx->f24.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80027714: lui         $at, 0x402C
    ctx->r1 = S32(0X402C << 16);
    // 0x80027718: or          $t2, $a0, $zero
    ctx->r10 = ctx->r4 | 0;
    // 0x8002771C: mul.s       $f10, $f22, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x80027720: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x80027724: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80027728: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8002772C: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80027730: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80027734: add.s       $f6, $f4, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f24.fl;
    // 0x80027738: swc1        $f0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f0.u32l;
    // 0x8002773C: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80027740: sub.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = ctx->f8.d - ctx->f10.d;
    // 0x80027744: lwc1        $f8, 0x5E94($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X5E94);
    // 0x80027748: cvt.s.d     $f12, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f12.fl = CVT_S_D(ctx->f4.d);
    // 0x8002774C: lwc1        $f9, 0x5E90($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X5E90);
    // 0x80027750: cvt.d.s     $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f6.d = CVT_D_S(ctx->f12.fl);
    // 0x80027754: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80027758: nop

    // 0x8002775C: bc1f        L_8002788C
    if (!c1cs) {
        // 0x80027760: lw          $t9, 0x4C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X4C);
            goto L_8002788C;
    }
    // 0x80027760: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
    // 0x80027764: lwc1        $f14, 0xC($t3)
    ctx->f14.u32l = MEM_W(ctx->r11, 0XC);
    // 0x80027768: lwc1        $f16, 0x10($t3)
    ctx->f16.u32l = MEM_W(ctx->r11, 0X10);
    // 0x8002776C: mul.s       $f10, $f14, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f2.fl);
    // 0x80027770: lwc1        $f18, 0x14($t3)
    ctx->f18.u32l = MEM_W(ctx->r11, 0X14);
    // 0x80027774: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80027778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8002777C: mul.s       $f4, $f20, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f16.fl);
    // 0x80027780: nop

    // 0x80027784: mul.s       $f8, $f22, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x80027788: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x8002778C: lwc1        $f7, 0x5E98($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X5E98);
    // 0x80027790: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80027794: lwc1        $f6, 0x5E9C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X5E9C);
    // 0x80027798: add.s       $f0, $f10, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f0.fl = ctx->f10.fl + ctx->f24.fl;
    // 0x8002779C: lwc1        $f8, 0x5C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x800277A0: cvt.d.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.d = CVT_D_S(ctx->f0.fl);
    // 0x800277A4: c.le.d      $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f6.d <= ctx->f4.d;
    // 0x800277A8: nop

    // 0x800277AC: bc1f        L_80027888
    if (!c1cs) {
        // 0x800277B0: nop
    
            goto L_80027888;
    }
    // 0x800277B0: nop

    // 0x800277B4: c.eq.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl == ctx->f12.fl;
    // 0x800277B8: sub.s       $f20, $f28, $f14
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f20.fl = ctx->f28.fl - ctx->f14.fl;
    // 0x800277BC: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x800277C0: sub.s       $f22, $f30, $f16
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f22.fl = ctx->f30.fl - ctx->f16.fl;
    // 0x800277C4: bc1t        L_800277D8
    if (c1cs) {
        // 0x800277C8: sub.s       $f24, $f8, $f18
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f18.fl;
            goto L_800277D8;
    }
    // 0x800277C8: sub.s       $f24, $f8, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f24.fl = ctx->f8.fl - ctx->f18.fl;
    // 0x800277CC: sub.s       $f10, $f0, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f12.fl;
    // 0x800277D0: b           L_800277E0
    // 0x800277D4: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
        goto L_800277E0;
    // 0x800277D4: div.s       $f2, $f0, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
L_800277D8:
    // 0x800277D8: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800277DC: nop

L_800277E0:
    // 0x800277E0: mul.s       $f4, $f20, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x800277E4: sll         $a1, $v0, 1
    ctx->r5 = S32(ctx->r2 << 1);
    // 0x800277E8: addu        $a2, $t2, $a1
    ctx->r6 = ADD32(ctx->r10, ctx->r5);
    // 0x800277EC: mul.s       $f6, $f22, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f2.fl);
    // 0x800277F0: add.s       $f20, $f14, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f20.fl = ctx->f14.fl + ctx->f4.fl;
    // 0x800277F4: mul.s       $f8, $f24, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f24.fl, ctx->f2.fl);
    // 0x800277F8: add.s       $f22, $f16, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f22.fl = ctx->f16.fl + ctx->f6.fl;
    // 0x800277FC: add.s       $f24, $f18, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f24.fl = ctx->f18.fl + ctx->f8.fl;
L_80027800:
    // 0x80027800: lhu         $v0, 0x2($a2)
    ctx->r2 = MEM_HU(ctx->r6, 0X2);
    // 0x80027804: addiu       $a1, $a1, 0x2
    ctx->r5 = ADD32(ctx->r5, 0X2);
    // 0x80027808: andi        $t9, $v0, 0x8000
    ctx->r25 = ctx->r2 & 0X8000;
    // 0x8002780C: beq         $t9, $zero, L_80027820
    if (ctx->r25 == 0) {
        // 0x80027810: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80027820;
    }
    // 0x80027810: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80027814: andi        $t6, $v0, 0x7FFF
    ctx->r14 = ctx->r2 & 0X7FFF;
    // 0x80027818: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8002781C: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
L_80027820:
    // 0x80027820: sll         $t8, $v0, 4
    ctx->r24 = S32(ctx->r2 << 4);
    // 0x80027824: addu        $v1, $t0, $t8
    ctx->r3 = ADD32(ctx->r8, ctx->r24);
    // 0x80027828: lwc1        $f0, 0x0($v1)
    ctx->f0.u32l = MEM_W(ctx->r3, 0X0);
    // 0x8002782C: lwc1        $f2, 0x4($v1)
    ctx->f2.u32l = MEM_W(ctx->r3, 0X4);
    // 0x80027830: mul.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f20.fl);
    // 0x80027834: lwc1        $f12, 0x8($v1)
    ctx->f12.u32l = MEM_W(ctx->r3, 0X8);
    // 0x80027838: lwc1        $f14, 0xC($v1)
    ctx->f14.u32l = MEM_W(ctx->r3, 0XC);
    // 0x8002783C: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x80027840: mul.s       $f4, $f2, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f22.fl);
    // 0x80027844: nop

    // 0x80027848: mul.s       $f8, $f12, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f24.fl);
    // 0x8002784C: add.s       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x80027850: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80027854: add.s       $f18, $f10, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = ctx->f10.fl + ctx->f14.fl;
    // 0x80027858: beq         $a0, $zero, L_80027864
    if (ctx->r4 == 0) {
        // 0x8002785C: mov.s       $f16, $f18
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
            goto L_80027864;
    }
    // 0x8002785C: mov.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    ctx->f16.fl = ctx->f18.fl;
    // 0x80027860: neg.s       $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = -ctx->f18.fl;
L_80027864:
    // 0x80027864: c.lt.s      $f26, $f16
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f26.fl < ctx->f16.fl;
    // 0x80027868: nop

    // 0x8002786C: bc1f        L_80027878
    if (!c1cs) {
        // 0x80027870: nop
    
            goto L_80027878;
    }
    // 0x80027870: nop

    // 0x80027874: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_80027878:
    // 0x80027878: beq         $at, $zero, L_80027888
    if (ctx->r1 == 0) {
        // 0x8002787C: addiu       $a2, $a2, 0x2
        ctx->r6 = ADD32(ctx->r6, 0X2);
            goto L_80027888;
    }
    // 0x8002787C: addiu       $a2, $a2, 0x2
    ctx->r6 = ADD32(ctx->r6, 0X2);
    // 0x80027880: beq         $a3, $t1, L_80027800
    if (ctx->r7 == ctx->r9) {
        // 0x80027884: nop
    
            goto L_80027800;
    }
    // 0x80027884: nop

L_80027888:
    // 0x80027888: lw          $t9, 0x4C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X4C);
L_8002788C:
    // 0x8002788C: addiu       $t4, $t4, 0x4
    ctx->r12 = ADD32(ctx->r12, 0X4);
    // 0x80027890: slt         $at, $t4, $t9
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x80027894: beq         $at, $zero, L_800278A8
    if (ctx->r1 == 0) {
        // 0x80027898: addiu       $t5, $t5, 0x4
        ctx->r13 = ADD32(ctx->r13, 0X4);
            goto L_800278A8;
    }
    // 0x80027898: addiu       $t5, $t5, 0x4
    ctx->r13 = ADD32(ctx->r13, 0X4);
    // 0x8002789C: beq         $a3, $zero, L_800276C4
    if (ctx->r7 == 0) {
        // 0x800278A0: nop
    
            goto L_800276C4;
    }
    // 0x800278A0: nop

    // 0x800278A4: sw          $ra, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r31;
L_800278A8:
    // 0x800278A8: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_800278AC:
    // 0x800278AC: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x800278B0: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800278B4: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800278B8: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800278BC: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800278C0: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800278C4: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800278C8: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800278CC: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800278D0: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800278D4: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800278D8: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800278DC: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800278E0: jr          $ra
    // 0x800278E4: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    return;
    // 0x800278E4: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
;}
RECOMP_FUNC void gzip_inflate_block(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C68C0: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C68C4: lw          $t3, -0x552C($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X552C);
    // 0x800C68C8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C68CC: sw          $zero, -0x5528($at)
    MEM_W(-0X5528, ctx->r1) = 0;
    // 0x800C68D0: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C68D4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800C68D8: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800C68DC: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C68E0: sltu        $at, $t3, $t0
    ctx->r1 = ctx->r11 < ctx->r8 ? 1 : 0;
    // 0x800C68E4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800C68E8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800C68EC: lw          $t4, 0x3768($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3768);
    // 0x800C68F0: beq         $at, $zero, L_800C6914
    if (ctx->r1 == 0) {
        // 0x800C68F4: lw          $t2, -0x5530($t2)
        ctx->r10 = MEM_W(ctx->r10, -0X5530);
            goto L_800C6914;
    }
    // 0x800C68F4: lw          $t2, -0x5530($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5530);
L_800C68F8:
    // 0x800C68F8: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x800C68FC: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C6900: sllv        $v0, $v0, $t3
    ctx->r2 = S32(ctx->r2 << (ctx->r11 & 31));
    // 0x800C6904: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800C6908: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C690C: bne         $at, $zero, L_800C68F8
    if (ctx->r1 != 0) {
        // 0x800C6910: or          $t2, $t2, $v0
        ctx->r10 = ctx->r10 | ctx->r2;
            goto L_800C68F8;
    }
    // 0x800C6910: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
L_800C6914:
    // 0x800C6914: andi        $s0, $t2, 0x1
    ctx->r16 = ctx->r10 & 0X1;
    // 0x800C6918: srlv        $t2, $t2, $t0
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r8 & 31));
    // 0x800C691C: sub         $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x800C6920: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C6924: sltu        $at, $t3, $t0
    ctx->r1 = ctx->r11 < ctx->r8 ? 1 : 0;
    // 0x800C6928: beq         $at, $zero, L_800C694C
    if (ctx->r1 == 0) {
        // 0x800C692C: nop
    
            goto L_800C694C;
    }
    // 0x800C692C: nop

L_800C6930:
    // 0x800C6930: lbu         $v0, 0x0($t4)
    ctx->r2 = MEM_BU(ctx->r12, 0X0);
    // 0x800C6934: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x800C6938: sllv        $v0, $v0, $t3
    ctx->r2 = S32(ctx->r2 << (ctx->r11 & 31));
    // 0x800C693C: addiu       $t3, $t3, 0x8
    ctx->r11 = ADD32(ctx->r11, 0X8);
    // 0x800C6940: slt         $at, $t3, $t0
    ctx->r1 = SIGNED(ctx->r11) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6944: bne         $at, $zero, L_800C6930
    if (ctx->r1 != 0) {
        // 0x800C6948: or          $t2, $t2, $v0
        ctx->r10 = ctx->r10 | ctx->r2;
            goto L_800C6930;
    }
    // 0x800C6948: or          $t2, $t2, $v0
    ctx->r10 = ctx->r10 | ctx->r2;
L_800C694C:
    // 0x800C694C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6950: andi        $t1, $t2, 0x3
    ctx->r9 = ctx->r10 & 0X3;
    // 0x800C6954: sw          $t4, 0x3768($at)
    MEM_W(0X3768, ctx->r1) = ctx->r12;
    // 0x800C6958: srlv        $t2, $t2, $t0
    ctx->r10 = S32(U32(ctx->r10) >> (ctx->r8 & 31));
    // 0x800C695C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6960: sw          $t2, -0x5530($at)
    MEM_W(-0X5530, ctx->r1) = ctx->r10;
    // 0x800C6964: sub         $t3, $t3, $t0
    ctx->r11 = SUB32(ctx->r11, ctx->r8);
    // 0x800C6968: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C696C: sw          $t3, -0x552C($at)
    MEM_W(-0X552C, ctx->r1) = ctx->r11;
    // 0x800C6970: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800C6974: beq         $t1, $at, L_800C69A4
    if (ctx->r9 == ctx->r1) {
        // 0x800C6978: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_800C69A4;
    }
    // 0x800C6978: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C697C: beq         $t1, $at, L_800C6994
    if (ctx->r9 == ctx->r1) {
        // 0x800C6980: nop
    
            goto L_800C6994;
    }
    // 0x800C6980: nop

    // 0x800C6984: jal         0x800C6F34
    // 0x800C6988: nop

    gzip_inflate_stored(rdram, ctx);
        goto after_0;
    // 0x800C6988: nop

    after_0:
    // 0x800C698C: j           L_800C69AC
    // 0x800C6990: nop

        goto L_800C69AC;
    // 0x800C6990: nop

L_800C6994:
    // 0x800C6994: jal         0x800C6DDC
    // 0x800C6998: nop

    gzip_inflate_fixed(rdram, ctx);
        goto after_1;
    // 0x800C6998: nop

    after_1:
    // 0x800C699C: j           L_800C69AC
    // 0x800C69A0: nop

        goto L_800C69AC;
    // 0x800C69A0: nop

L_800C69A4:
    // 0x800C69A4: jal         0x800C69C4
    // 0x800C69A8: nop

    gzip_inflate_dynamic(rdram, ctx);
        goto after_2;
    // 0x800C69A8: nop

    after_2:
L_800C69AC:
    // 0x800C69AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C69B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x800C69B4: sub         $v0, $v0, $s0
    ctx->r2 = SUB32(ctx->r2, ctx->r16);
    // 0x800C69B8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C69BC: jr          $ra
    // 0x800C69C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800C69C0: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void mtx_world_origin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80068408: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006840C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80068410: lw          $t6, 0xD1C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XD1C);
    // 0x80068414: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80068418: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006841C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80068420: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068424: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x80068428: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x8006842C: addu        $a0, $a0, $t7
    ctx->r4 = ADD32(ctx->r4, ctx->r15);
    // 0x80068430: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80068434: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x80068438: mfc1        $a1, $f0
    ctx->r5 = (int32_t)ctx->f0.u32l;
    // 0x8006843C: mfc1        $a2, $f0
    ctx->r6 = (int32_t)ctx->f0.u32l;
    // 0x80068440: mfc1        $a3, $f0
    ctx->r7 = (int32_t)ctx->f0.u32l;
    // 0x80068444: jal         0x800705F8
    // 0x80068448: nop

    mtxf_from_translation(rdram, ctx);
        goto after_0;
    // 0x80068448: nop

    after_0:
    // 0x8006844C: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80068450: lw          $t8, 0xD1C($t8)
    ctx->r24 = MEM_W(ctx->r24, 0XD1C);
    // 0x80068454: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80068458: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8006845C: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80068460: lw          $a0, 0xD70($a0)
    ctx->r4 = MEM_W(ctx->r4, 0XD70);
    // 0x80068464: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80068468: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006846C: addiu       $a2, $a2, 0x1060
    ctx->r6 = ADD32(ctx->r6, 0X1060);
    // 0x80068470: jal         0x8006F768
    // 0x80068474: addiu       $a1, $a1, 0xF20
    ctx->r5 = ADD32(ctx->r5, 0XF20);
    mtxf_mul(rdram, ctx);
        goto after_1;
    // 0x80068474: addiu       $a1, $a1, 0xF20
    ctx->r5 = ADD32(ctx->r5, 0XF20);
    after_1:
    // 0x80068478: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006847C: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x80068480: jal         0x8006F870
    // 0x80068484: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    mtxf_to_mtx(rdram, ctx);
        goto after_2;
    // 0x80068484: addiu       $a0, $a0, 0x1060
    ctx->r4 = ADD32(ctx->r4, 0X1060);
    after_2:
    // 0x80068488: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8006848C: lw          $t1, 0xD1C($t1)
    ctx->r9 = MEM_W(ctx->r9, 0XD1C);
    // 0x80068490: lw          $t0, 0x0($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X0);
    // 0x80068494: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80068498: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8006849C: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x800684A0: addu        $at, $at, $t2
    ctx->r1 = ADD32(ctx->r1, ctx->r10);
    // 0x800684A4: sw          $t0, 0xD88($at)
    MEM_W(0XD88, ctx->r1) = ctx->r8;
    // 0x800684A8: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x800684AC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800684B0: addiu       $t3, $v1, 0x8
    ctx->r11 = ADD32(ctx->r3, 0X8);
    // 0x800684B4: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800684B8: lw          $t4, 0xD08($t4)
    ctx->r12 = MEM_W(ctx->r12, 0XD08);
    // 0x800684BC: lui         $at, 0x100
    ctx->r1 = S32(0X100 << 16);
    // 0x800684C0: sll         $t5, $t4, 6
    ctx->r13 = S32(ctx->r12 << 6);
    // 0x800684C4: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800684C8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800684CC: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800684D0: ori         $t9, $t8, 0x40
    ctx->r25 = ctx->r24 | 0X40;
    // 0x800684D4: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    extern void dkr_presentation_world_origin_matrix(uint8_t*, recomp_context*); dkr_presentation_world_origin_matrix(rdram, ctx);
    // 0x800684D8: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x800684DC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800684E0: addu        $t0, $t1, $at
    ctx->r8 = ADD32(ctx->r9, ctx->r1);
    // 0x800684E4: sw          $t0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r8;
    // 0x800684E8: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x800684EC: nop

    // 0x800684F0: addiu       $t3, $t2, 0x40
    ctx->r11 = ADD32(ctx->r10, 0X40);
    // 0x800684F4: sw          $t3, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r11;
    // 0x800684F8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800684FC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80068500: jr          $ra
    // 0x80068504: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80068504: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_door_number(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80011264: lh          $t6, 0x50($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X50);
    // 0x80011268: nop

    // 0x8001126C: blez        $t6, L_8001135C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80011270: nop
    
            goto L_8001135C;
    }
    // 0x80011270: nop

    // 0x80011274: lw          $v0, 0x64($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X64);
    // 0x80011278: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x8001127C: lbu         $v1, 0x10($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X10);
    // 0x80011280: lw          $t0, 0x38($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X38);
    // 0x80011284: div         $zero, $v1, $t2
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r10))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r10)));
    // 0x80011288: bne         $t2, $zero, L_80011294
    if (ctx->r10 != 0) {
        // 0x8001128C: nop
    
            goto L_80011294;
    }
    // 0x8001128C: nop

    // 0x80011290: break       7
    do_break(2147553936);
L_80011294:
    // 0x80011294: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80011298: bne         $t2, $at, L_800112AC
    if (ctx->r10 != ctx->r1) {
        // 0x8001129C: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800112AC;
    }
    // 0x8001129C: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800112A0: bne         $v1, $at, L_800112AC
    if (ctx->r3 != ctx->r1) {
        // 0x800112A4: nop
    
            goto L_800112AC;
    }
    // 0x800112A4: nop

    // 0x800112A8: break       6
    do_break(2147553960);
L_800112AC:
    // 0x800112AC: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x800112B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800112B4: lui         $t2, 0x1
    ctx->r10 = S32(0X1 << 16);
    // 0x800112B8: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x800112BC: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
    // 0x800112C0: mflo        $a2
    ctx->r6 = lo;
    // 0x800112C4: addiu       $a2, $a2, -0x1
    ctx->r6 = ADD32(ctx->r6, -0X1);
    // 0x800112C8: mfhi        $v1
    ctx->r3 = hi;
    // 0x800112CC: sll         $t7, $a2, 2
    ctx->r15 = S32(ctx->r6 << 2);
    // 0x800112D0: sll         $t8, $v1, 2
    ctx->r24 = S32(ctx->r3 << 2);
    // 0x800112D4: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x800112D8: blez        $t1, L_8001135C
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800112DC: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_8001135C;
    }
    // 0x800112DC: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800112E0:
    // 0x800112E0: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x800112E4: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800112E8: and         $t4, $t9, $t2
    ctx->r12 = ctx->r25 & ctx->r10;
    // 0x800112EC: beq         $t4, $zero, L_80011354
    if (ctx->r12 == 0) {
        // 0x800112F0: slt         $at, $a3, $t1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80011354;
    }
    // 0x800112F0: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x800112F4: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800112F8: nop

    // 0x800112FC: beq         $t3, $a1, L_80011354
    if (ctx->r11 == ctx->r5) {
        // 0x80011300: slt         $at, $a3, $t1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80011354;
    }
    // 0x80011300: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011304: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80011308: sll         $t6, $a1, 3
    ctx->r14 = S32(ctx->r5 << 3);
    // 0x8001130C: addu        $t7, $t5, $t6
    ctx->r15 = ADD32(ctx->r13, ctx->r14);
    // 0x80011310: lw          $t0, 0x0($t7)
    ctx->r8 = MEM_W(ctx->r15, 0X0);
    // 0x80011314: nop

    // 0x80011318: lhu         $t8, 0x12($t0)
    ctx->r24 = MEM_HU(ctx->r8, 0X12);
    // 0x8001131C: nop

    // 0x80011320: slti        $at, $t8, 0x901
    ctx->r1 = SIGNED(ctx->r24) < 0X901 ? 1 : 0;
    // 0x80011324: bne         $at, $zero, L_8001133C
    if (ctx->r1 != 0) {
        // 0x80011328: nop
    
            goto L_8001133C;
    }
    // 0x80011328: nop

    // 0x8001132C: sb          $v1, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r3;
    // 0x80011330: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x80011334: b           L_80011354
    // 0x80011338: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
        goto L_80011354;
    // 0x80011338: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
L_8001133C:
    // 0x8001133C: bltz        $a2, L_80011354
    if (SIGNED(ctx->r6) < 0) {
        // 0x80011340: slt         $at, $a3, $t1
        ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_80011354;
    }
    // 0x80011340: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80011344: sb          $a2, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r6;
    // 0x80011348: lh          $t1, 0x28($a0)
    ctx->r9 = MEM_H(ctx->r4, 0X28);
    // 0x8001134C: nop

    // 0x80011350: slt         $at, $a3, $t1
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r9) ? 1 : 0;
L_80011354:
    // 0x80011354: bne         $at, $zero, L_800112E0
    if (ctx->r1 != 0) {
        // 0x80011358: addiu       $v0, $v0, 0xC
        ctx->r2 = ADD32(ctx->r2, 0XC);
            goto L_800112E0;
    }
    // 0x80011358: addiu       $v0, $v0, 0xC
    ctx->r2 = ADD32(ctx->r2, 0XC);
L_8001135C:
    // 0x8001135C: jr          $ra
    // 0x80011360: nop

    return;
    // 0x80011360: nop

;}
RECOMP_FUNC void bad_int_sqrt(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800707AC: mtc1        $a0, $f0
    ctx->f0.u32l = ctx->r4;
    // 0x800707B0: nop

    // 0x800707B4: sqrt.s      $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = sqrtf(ctx->f0.fl);
    // 0x800707B8: mfc1        $v0, $f0
    ctx->r2 = (int32_t)ctx->f0.u32l;
    // 0x800707BC: jr          $ra
    // 0x800707C0: nop

    return;
    // 0x800707C0: nop

;}
RECOMP_FUNC void obj_init_timetrialghost(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80035E20: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x80035E24: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x80035E28: sw          $zero, 0x78($a0)
    MEM_W(0X78, ctx->r4) = 0;
    // 0x80035E2C: jr          $ra
    // 0x80035E30: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
    return;
    // 0x80035E30: sw          $t6, 0x7C($a0)
    MEM_W(0X7C, ctx->r4) = ctx->r14;
;}
RECOMP_FUNC void hud_draw_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AAFD0: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800AAFD4: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x800AAFD8: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x800AAFDC: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x800AAFE0: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x800AAFE4: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x800AAFE8: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x800AAFEC: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x800AAFF0: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800AAFF4: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800AAFF8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800AAFFC: lh          $a1, 0x28($a0)
    ctx->r5 = MEM_H(ctx->r4, 0X28);
    // 0x800AB000: or          $s3, $a0, $zero
    ctx->r19 = ctx->r4 | 0;
    // 0x800AB004: blez        $a1, L_800AB164
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AB008: or          $s7, $zero, $zero
        ctx->r23 = 0 | 0;
            goto L_800AB164;
    }
    // 0x800AB008: or          $s7, $zero, $zero
    ctx->r23 = 0 | 0;
    // 0x800AB00C: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x800AB010: addiu       $s2, $s2, 0x6CFC
    ctx->r18 = ADD32(ctx->r18, 0X6CFC);
    // 0x800AB014: or          $fp, $zero, $zero
    ctx->r30 = 0 | 0;
L_800AB018:
    // 0x800AB018: lw          $t6, 0x38($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X38);
    // 0x800AB01C: addiu       $s6, $zero, 0x1
    ctx->r22 = ADD32(0, 0X1);
    // 0x800AB020: addu        $v0, $t6, $fp
    ctx->r2 = ADD32(ctx->r14, ctx->r30);
    // 0x800AB024: lw          $a3, 0x8($v0)
    ctx->r7 = MEM_W(ctx->r2, 0X8);
    // 0x800AB028: addiu       $at, $zero, 0xFF
    ctx->r1 = ADD32(0, 0XFF);
    // 0x800AB02C: andi        $t7, $a3, 0x100
    ctx->r15 = ctx->r7 & 0X100;
    // 0x800AB030: bne         $t7, $zero, L_800AB154
    if (ctx->r15 != 0) {
        // 0x800AB034: nop
    
            goto L_800AB154;
    }
    // 0x800AB034: nop

    // 0x800AB038: lh          $v1, 0x2($v0)
    ctx->r3 = MEM_H(ctx->r2, 0X2);
    // 0x800AB03C: lh          $a0, 0x4($v0)
    ctx->r4 = MEM_H(ctx->r2, 0X4);
    // 0x800AB040: sll         $t3, $v1, 2
    ctx->r11 = S32(ctx->r3 << 2);
    // 0x800AB044: lh          $t8, 0xE($v0)
    ctx->r24 = MEM_H(ctx->r2, 0XE);
    // 0x800AB048: lh          $t9, 0x10($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X10);
    // 0x800AB04C: lw          $t2, 0x4($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X4);
    // 0x800AB050: lw          $t4, 0x8($s3)
    ctx->r12 = MEM_W(ctx->r19, 0X8);
    // 0x800AB054: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x800AB058: addu        $t3, $t3, $v1
    ctx->r11 = ADD32(ctx->r11, ctx->r3);
    // 0x800AB05C: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800AB060: sll         $t5, $a0, 4
    ctx->r13 = S32(ctx->r4 << 4);
    // 0x800AB064: subu        $s0, $t8, $v1
    ctx->r16 = SUB32(ctx->r24, ctx->r3);
    // 0x800AB068: subu        $s4, $t9, $a0
    ctx->r20 = SUB32(ctx->r25, ctx->r4);
    // 0x800AB06C: addu        $s5, $t2, $t3
    ctx->r21 = ADD32(ctx->r10, ctx->r11);
    // 0x800AB070: bne         $a1, $at, L_800AB080
    if (ctx->r5 != ctx->r1) {
        // 0x800AB074: addu        $t0, $t4, $t5
        ctx->r8 = ADD32(ctx->r12, ctx->r13);
            goto L_800AB080;
    }
    // 0x800AB074: addu        $t0, $t4, $t5
    ctx->r8 = ADD32(ctx->r12, ctx->r13);
    // 0x800AB078: b           L_800AB094
    // 0x800AB07C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
        goto L_800AB094;
    // 0x800AB07C: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_800AB080:
    // 0x800AB080: lw          $t6, 0x0($s3)
    ctx->r14 = MEM_W(ctx->r19, 0X0);
    // 0x800AB084: sll         $t7, $a1, 3
    ctx->r15 = S32(ctx->r5 << 3);
    // 0x800AB088: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800AB08C: lw          $s1, 0x0($t8)
    ctx->r17 = MEM_W(ctx->r24, 0X0);
    // 0x800AB090: nop

L_800AB094:
    // 0x800AB094: addiu       $at, $zero, -0x3
    ctx->r1 = ADD32(0, -0X3);
    // 0x800AB098: and         $a2, $a3, $at
    ctx->r6 = ctx->r7 & ctx->r1;
    // 0x800AB09C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    // 0x800AB0A0: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800AB0A4: jal         0x8007B4C8
    // 0x800AB0A8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x800AB0A8: sw          $t0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r8;
    after_0:
    // 0x800AB0AC: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800AB0B0: lui         $t1, 0x8000
    ctx->r9 = S32(0X8000 << 16);
    // 0x800AB0B4: addu        $a0, $s5, $t1
    ctx->r4 = ADD32(ctx->r21, ctx->r9);
    // 0x800AB0B8: addiu       $t2, $s0, -0x1
    ctx->r10 = ADD32(ctx->r16, -0X1);
    // 0x800AB0BC: addiu       $t9, $v1, 0x8
    ctx->r25 = ADD32(ctx->r3, 0X8);
    // 0x800AB0C0: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x800AB0C4: sll         $t3, $t2, 3
    ctx->r11 = S32(ctx->r10 << 3);
    // 0x800AB0C8: andi        $t4, $a0, 0x6
    ctx->r12 = ctx->r4 & 0X6;
    // 0x800AB0CC: or          $t5, $t3, $t4
    ctx->r13 = ctx->r11 | ctx->r12;
    // 0x800AB0D0: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x800AB0D4: addu        $t2, $t9, $s0
    ctx->r10 = ADD32(ctx->r25, ctx->r16);
    // 0x800AB0D8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800AB0DC: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x800AB0E0: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800AB0E4: addiu       $t4, $t3, 0x8
    ctx->r12 = ADD32(ctx->r11, 0X8);
    // 0x800AB0E8: lui         $at, 0x400
    ctx->r1 = S32(0X400 << 16);
    // 0x800AB0EC: lw          $t0, 0x44($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X44);
    // 0x800AB0F0: or          $t8, $t7, $at
    ctx->r24 = ctx->r15 | ctx->r1;
    // 0x800AB0F4: andi        $t5, $t4, 0xFFFF
    ctx->r13 = ctx->r12 & 0XFFFF;
    // 0x800AB0F8: or          $t6, $t8, $t5
    ctx->r14 = ctx->r24 | ctx->r13;
    // 0x800AB0FC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800AB100: bne         $s1, $zero, L_800AB10C
    if (ctx->r17 != 0) {
        // 0x800AB104: sw          $a0, 0x4($v1)
        MEM_W(0X4, ctx->r3) = ctx->r4;
            goto L_800AB10C;
    }
    // 0x800AB104: sw          $a0, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r4;
    // 0x800AB108: or          $s6, $zero, $zero
    ctx->r22 = 0 | 0;
L_800AB10C:
    // 0x800AB10C: addiu       $t9, $s4, -0x1
    ctx->r25 = ADD32(ctx->r20, -0X1);
    // 0x800AB110: lw          $v1, 0x0($s2)
    ctx->r3 = MEM_W(ctx->r18, 0X0);
    // 0x800AB114: sll         $t2, $t9, 4
    ctx->r10 = S32(ctx->r25 << 4);
    // 0x800AB118: or          $t3, $t2, $s6
    ctx->r11 = ctx->r10 | ctx->r22;
    // 0x800AB11C: andi        $t4, $t3, 0xFF
    ctx->r12 = ctx->r11 & 0XFF;
    // 0x800AB120: addiu       $t7, $v1, 0x8
    ctx->r15 = ADD32(ctx->r3, 0X8);
    // 0x800AB124: sw          $t7, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r15;
    // 0x800AB128: sll         $t8, $t4, 16
    ctx->r24 = S32(ctx->r12 << 16);
    // 0x800AB12C: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800AB130: sll         $t6, $s4, 4
    ctx->r14 = S32(ctx->r20 << 4);
    // 0x800AB134: andi        $t7, $t6, 0xFFFF
    ctx->r15 = ctx->r14 & 0XFFFF;
    // 0x800AB138: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x800AB13C: or          $t9, $t5, $t7
    ctx->r25 = ctx->r13 | ctx->r15;
    // 0x800AB140: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800AB144: sw          $t2, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r10;
    // 0x800AB148: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800AB14C: lh          $a1, 0x28($s3)
    ctx->r5 = MEM_H(ctx->r19, 0X28);
    // 0x800AB150: nop

L_800AB154:
    // 0x800AB154: addiu       $s7, $s7, 0x1
    ctx->r23 = ADD32(ctx->r23, 0X1);
    // 0x800AB158: slt         $at, $s7, $a1
    ctx->r1 = SIGNED(ctx->r23) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800AB15C: bne         $at, $zero, L_800AB018
    if (ctx->r1 != 0) {
        // 0x800AB160: addiu       $fp, $fp, 0xC
        ctx->r30 = ADD32(ctx->r30, 0XC);
            goto L_800AB018;
    }
    // 0x800AB160: addiu       $fp, $fp, 0xC
    ctx->r30 = ADD32(ctx->r30, 0XC);
L_800AB164:
    // 0x800AB164: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x800AB168: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800AB16C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800AB170: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800AB174: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x800AB178: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x800AB17C: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x800AB180: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x800AB184: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x800AB188: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x800AB18C: jr          $ra
    // 0x800AB190: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x800AB190: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void write_game_data_to_controller_pak(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80073F5C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80073F60: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80073F64: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x80073F68: jal         0x80073C4C
    // 0x80073F6C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    get_game_data_file_size(rdram, ctx);
        goto after_0;
    // 0x80073F6C: sw          $a1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r5;
    after_0:
    // 0x80073F70: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x80073F74: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80073F78: jal         0x80070C9C
    // 0x80073F7C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x80073F7C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x80073F80: lui         $t6, 0x4741
    ctx->r14 = S32(0X4741 << 16);
    // 0x80073F84: sw          $v0, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r2;
    // 0x80073F88: ori         $t6, $t6, 0x4D44
    ctx->r14 = ctx->r14 | 0X4D44;
    // 0x80073F8C: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
    // 0x80073F90: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x80073F94: jal         0x800732E8
    // 0x80073F98: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    func_800732E8(rdram, ctx);
        goto after_2;
    // 0x80073F98: addiu       $a1, $v0, 0x4
    ctx->r5 = ADD32(ctx->r2, 0X4);
    after_2:
    // 0x80073F9C: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80073FA0: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
    // 0x80073FA4: jal         0x80073C5C
    // 0x80073FA8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    get_file_extension(rdram, ctx);
        goto after_3;
    // 0x80073FA8: addiu       $a2, $sp, 0x30
    ctx->r6 = ADD32(ctx->r29, 0X30);
    after_3:
    // 0x80073FAC: bne         $v0, $zero, L_80073FE0
    if (ctx->r2 != 0) {
        // 0x80073FB0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_80073FE0;
    }
    // 0x80073FB0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x80073FB4: lw          $t7, 0x2C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X2C);
    // 0x80073FB8: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x80073FBC: lw          $a0, 0x38($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X38);
    // 0x80073FC0: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80073FC4: addiu       $a2, $a2, 0x7680
    ctx->r6 = ADD32(ctx->r6, 0X7680);
    // 0x80073FC8: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80073FCC: addiu       $a3, $sp, 0x30
    ctx->r7 = ADD32(ctx->r29, 0X30);
    // 0x80073FD0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80073FD4: jal         0x800766D4
    // 0x80073FD8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    write_controller_pak_file(rdram, ctx);
        goto after_4;
    // 0x80073FD8: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_4:
    // 0x80073FDC: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_80073FE0:
    // 0x80073FE0: lw          $a0, 0x2C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X2C);
    // 0x80073FE4: jal         0x80071140
    // 0x80073FE8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    mempool_free(rdram, ctx);
        goto after_5;
    // 0x80073FE8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_5:
    // 0x80073FEC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80073FF0: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80073FF4: beq         $v1, $zero, L_80074010
    if (ctx->r3 == 0) {
        // 0x80073FF8: or          $v0, $v1, $zero
        ctx->r2 = ctx->r3 | 0;
            goto L_80074010;
    }
    // 0x80073FF8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    // 0x80073FFC: lw          $t9, 0x38($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X38);
    // 0x80074000: nop

    // 0x80074004: sll         $t0, $t9, 30
    ctx->r8 = S32(ctx->r25 << 30);
    // 0x80074008: or          $v1, $v1, $t0
    ctx->r3 = ctx->r3 | ctx->r8;
    // 0x8007400C: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80074010:
    // 0x80074010: jr          $ra
    // 0x80074014: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80074014: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void light_remove(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80032BAC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80032BB0: addiu       $t0, $t0, -0x36A4
    ctx->r8 = ADD32(ctx->r8, -0X36A4);
    // 0x80032BB4: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80032BB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80032BBC: blez        $a1, L_80032BF8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80032BC0: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_80032BF8;
    }
    // 0x80032BC0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80032BC4: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80032BC8: lw          $t6, -0x36B0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36B0);
    // 0x80032BCC: sll         $t7, $zero, 2
    ctx->r15 = S32(0 << 2);
    // 0x80032BD0: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
L_80032BD4:
    // 0x80032BD4: lw          $a3, 0x0($a2)
    ctx->r7 = MEM_W(ctx->r6, 0X0);
    // 0x80032BD8: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80032BDC: bne         $a0, $a3, L_80032BE8
    if (ctx->r4 != ctx->r7) {
        // 0x80032BE0: slt         $at, $v1, $a1
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
            goto L_80032BE8;
    }
    // 0x80032BE0: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80032BE4: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
L_80032BE8:
    // 0x80032BE8: beq         $at, $zero, L_80032BF8
    if (ctx->r1 == 0) {
        // 0x80032BEC: addiu       $a2, $a2, 0x4
        ctx->r6 = ADD32(ctx->r6, 0X4);
            goto L_80032BF8;
    }
    // 0x80032BEC: addiu       $a2, $a2, 0x4
    ctx->r6 = ADD32(ctx->r6, 0X4);
    // 0x80032BF0: beq         $v0, $zero, L_80032BD4
    if (ctx->r2 == 0) {
        // 0x80032BF4: nop
    
            goto L_80032BD4;
    }
    // 0x80032BF4: nop

L_80032BF8:
    // 0x80032BF8: beq         $v0, $zero, L_80032C64
    if (ctx->r2 == 0) {
        // 0x80032BFC: addiu       $t8, $a1, -0x1
        ctx->r24 = ADD32(ctx->r5, -0X1);
            goto L_80032C64;
    }
    // 0x80032BFC: addiu       $t8, $a1, -0x1
    ctx->r24 = ADD32(ctx->r5, -0X1);
    // 0x80032C00: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x80032C04: slt         $at, $v1, $t8
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80032C08: sw          $t8, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r24;
    // 0x80032C0C: beq         $at, $zero, L_80032C4C
    if (ctx->r1 == 0) {
        // 0x80032C10: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_80032C4C;
    }
    // 0x80032C10: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x80032C14: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80032C18: addiu       $a3, $a3, -0x36B0
    ctx->r7 = ADD32(ctx->r7, -0X36B0);
    // 0x80032C1C: sll         $a0, $v1, 2
    ctx->r4 = S32(ctx->r3 << 2);
L_80032C20:
    // 0x80032C20: lw          $t9, 0x0($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X0);
    // 0x80032C24: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80032C28: addu        $a2, $t9, $a0
    ctx->r6 = ADD32(ctx->r25, ctx->r4);
    // 0x80032C2C: lw          $t1, 0x4($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X4);
    // 0x80032C30: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x80032C34: sw          $t1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r9;
    // 0x80032C38: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80032C3C: nop

    // 0x80032C40: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80032C44: bne         $at, $zero, L_80032C20
    if (ctx->r1 != 0) {
        // 0x80032C48: nop
    
            goto L_80032C20;
    }
    // 0x80032C48: nop

L_80032C4C:
    // 0x80032C4C: lui         $a3, 0x800E
    ctx->r7 = S32(0X800E << 16);
    // 0x80032C50: addiu       $a3, $a3, -0x36B0
    ctx->r7 = ADD32(ctx->r7, -0X36B0);
    // 0x80032C54: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x80032C58: sll         $t3, $a1, 2
    ctx->r11 = S32(ctx->r5 << 2);
    // 0x80032C5C: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x80032C60: sw          $v0, 0x0($t4)
    MEM_W(0X0, ctx->r12) = ctx->r2;
L_80032C64:
    // 0x80032C64: jr          $ra
    // 0x80032C68: nop

    return;
    // 0x80032C68: nop

;}
RECOMP_FUNC void ghostmenu_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80099E8C: addiu       $sp, $sp, -0xF0
    ctx->r29 = ADD32(ctx->r29, -0XF0);
    // 0x80099E90: sw          $s7, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r23;
    // 0x80099E94: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x80099E98: addiu       $s7, $s7, 0x63A0
    ctx->r23 = ADD32(ctx->r23, 0X63A0);
    // 0x80099E9C: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x80099EA0: sw          $a0, 0xF0($sp)
    MEM_W(0XF0, ctx->r29) = ctx->r4;
    // 0x80099EA4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80099EA8: sw          $fp, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r30;
    // 0x80099EAC: sw          $s6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r22;
    // 0x80099EB0: sw          $s5, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r21;
    // 0x80099EB4: sw          $s4, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r20;
    // 0x80099EB8: sw          $s3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r19;
    // 0x80099EBC: sw          $s2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r18;
    // 0x80099EC0: sw          $s1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r17;
    // 0x80099EC4: sw          $s0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r16;
    // 0x80099EC8: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x80099ECC: jal         0x80067F2C
    // 0x80099ED0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    mtx_ortho(rdram, ctx);
        goto after_0;
    // 0x80099ED0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_0:
    // 0x80099ED4: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x80099ED8: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x80099EDC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80099EE0: bne         $t6, $zero, L_80099EF4
    if (ctx->r14 != 0) {
        // 0x80099EE4: addiu       $a0, $zero, 0x2
        ctx->r4 = ADD32(0, 0X2);
            goto L_80099EF4;
    }
    // 0x80099EE4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80099EE8: addiu       $t7, $zero, 0xC
    ctx->r15 = ADD32(0, 0XC);
    // 0x80099EEC: b           L_80099EF8
    // 0x80099EF0: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
        goto L_80099EF8;
    // 0x80099EF0: sw          $t7, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = ctx->r15;
L_80099EF4:
    // 0x80099EF4: sw          $zero, 0xD0($sp)
    MEM_W(0XD0, ctx->r29) = 0;
L_80099EF8:
    // 0x80099EF8: lw          $t8, 0x63D8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X63D8);
    // 0x80099EFC: jal         0x800C42EC
    // 0x80099F00: sw          $t8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r24;
    set_text_font(rdram, ctx);
        goto after_1;
    // 0x80099F00: sw          $t8, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r24;
    after_1:
    // 0x80099F04: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80099F08: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80099F0C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80099F10: jal         0x800C43CC
    // 0x80099F14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_background_colour(rdram, ctx);
        goto after_2;
    // 0x80099F14: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_2:
    // 0x80099F18: addiu       $t9, $zero, 0x80
    ctx->r25 = ADD32(0, 0X80);
    // 0x80099F1C: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80099F20: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80099F24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80099F28: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80099F2C: jal         0x800C4384
    // 0x80099F30: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_3;
    // 0x80099F30: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_3:
    // 0x80099F34: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80099F38: lw          $t1, -0xB60($t1)
    ctx->r9 = MEM_W(ctx->r9, -0XB60);
    // 0x80099F3C: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x80099F40: lw          $a3, 0x148($t1)
    ctx->r7 = MEM_W(ctx->r9, 0X148);
    // 0x80099F44: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x80099F48: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80099F4C: addiu       $a1, $zero, 0xA1
    ctx->r5 = ADD32(0, 0XA1);
    // 0x80099F50: jal         0x800C4440
    // 0x80099F54: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    draw_text(rdram, ctx);
        goto after_4;
    // 0x80099F54: addiu       $a2, $zero, 0x23
    ctx->r6 = ADD32(0, 0X23);
    after_4:
    // 0x80099F58: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x80099F5C: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x80099F60: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80099F64: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80099F68: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80099F6C: jal         0x800C4384
    // 0x80099F70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_5;
    // 0x80099F70: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x80099F74: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80099F78: lw          $t4, -0xB60($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB60);
    // 0x80099F7C: addiu       $t5, $zero, 0xC
    ctx->r13 = ADD32(0, 0XC);
    // 0x80099F80: lw          $a3, 0x148($t4)
    ctx->r7 = MEM_W(ctx->r12, 0X148);
    // 0x80099F84: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x80099F88: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80099F8C: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80099F90: jal         0x800C4440
    // 0x80099F94: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    draw_text(rdram, ctx);
        goto after_6;
    // 0x80099F94: addiu       $a2, $zero, 0x20
    ctx->r6 = ADD32(0, 0X20);
    after_6:
    // 0x80099F98: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80099F9C: lw          $t6, 0x64D4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X64D4);
    // 0x80099FA0: addiu       $s2, $zero, 0x38
    ctx->r18 = ADD32(0, 0X38);
    // 0x80099FA4: bgtz        $t6, L_80099FF8
    if (SIGNED(ctx->r14) > 0) {
        // 0x80099FA8: addiu       $t1, $zero, 0x3
        ctx->r9 = ADD32(0, 0X3);
            goto L_80099FF8;
    }
    // 0x80099FA8: addiu       $t1, $zero, 0x3
    ctx->r9 = ADD32(0, 0X3);
    // 0x80099FAC: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80099FB0: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x80099FB4: addiu       $a0, $zero, 0xFF
    ctx->r4 = ADD32(0, 0XFF);
    // 0x80099FB8: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x80099FBC: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x80099FC0: jal         0x800C4384
    // 0x80099FC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_text_colour(rdram, ctx);
        goto after_7;
    // 0x80099FC4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_7:
    // 0x80099FC8: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80099FCC: lw          $t8, -0xB60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB60);
    // 0x80099FD0: lw          $a2, 0xD0($sp)
    ctx->r6 = MEM_W(ctx->r29, 0XD0);
    // 0x80099FD4: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x80099FD8: lw          $a3, 0x14C($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X14C);
    // 0x80099FDC: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x80099FE0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x80099FE4: addiu       $a1, $zero, 0xA0
    ctx->r5 = ADD32(0, 0XA0);
    // 0x80099FE8: jal         0x800C4440
    // 0x80099FEC: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    draw_text(rdram, ctx);
        goto after_8;
    // 0x80099FEC: addiu       $a2, $a2, 0x78
    ctx->r6 = ADD32(ctx->r6, 0X78);
    after_8:
    // 0x80099FF0: b           L_8009A7A8
    // 0x80099FF4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
        goto L_8009A7A8;
    // 0x80099FF4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_80099FF8:
    // 0x80099FF8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80099FFC: lw          $v0, 0x63BC($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63BC);
    // 0x8009A000: sw          $t1, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r9;
    // 0x8009A004: sll         $t2, $v0, 3
    ctx->r10 = S32(ctx->r2 << 3);
    // 0x8009A008: slti        $at, $t2, 0x100
    ctx->r1 = SIGNED(ctx->r10) < 0X100 ? 1 : 0;
    // 0x8009A00C: bne         $at, $zero, L_8009A01C
    if (ctx->r1 != 0) {
        // 0x8009A010: or          $v0, $t2, $zero
        ctx->r2 = ctx->r10 | 0;
            goto L_8009A01C;
    }
    // 0x8009A010: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    // 0x8009A014: addiu       $t3, $zero, 0x1FF
    ctx->r11 = ADD32(0, 0X1FF);
    // 0x8009A018: subu        $v0, $t3, $t2
    ctx->r2 = SUB32(ctx->r11, ctx->r10);
L_8009A01C:
    // 0x8009A01C: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8009A020: or          $t4, $v0, $at
    ctx->r12 = ctx->r2 | ctx->r1;
    // 0x8009A024: sw          $t4, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r12;
    // 0x8009A028: jal         0x800C42EC
    // 0x8009A02C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_text_font(rdram, ctx);
        goto after_9;
    // 0x8009A02C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
    // 0x8009A030: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8009A034: lw          $v0, 0xE4($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XE4);
    // 0x8009A038: lw          $t5, 0x64D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X64D4);
    // 0x8009A03C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8009A040: slt         $at, $v0, $t5
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x8009A044: beq         $at, $zero, L_8009A4F4
    if (ctx->r1 == 0) {
        // 0x8009A048: addiu       $t6, $t6, 0x6508
        ctx->r14 = ADD32(ctx->r14, 0X6508);
            goto L_8009A4F4;
    }
    // 0x8009A048: addiu       $t6, $t6, 0x6508
    ctx->r14 = ADD32(ctx->r14, 0X6508);
    // 0x8009A04C: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x8009A050: mtc1        $t5, $f4
    ctx->f4.u32l = ctx->r13;
    // 0x8009A054: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8009A058: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009A05C: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8009A060: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009A064: addiu       $t3, $t3, 0x6520
    ctx->r11 = ADD32(ctx->r11, 0X6520);
    // 0x8009A068: addiu       $t9, $t9, 0x6518
    ctx->r25 = ADD32(ctx->r25, 0X6518);
    // 0x8009A06C: addiu       $t7, $t7, 0x6510
    ctx->r15 = ADD32(ctx->r15, 0X6510);
    // 0x8009A070: sll         $t2, $v0, 1
    ctx->r10 = S32(ctx->r2 << 1);
    // 0x8009A074: addu        $t4, $t2, $t3
    ctx->r12 = ADD32(ctx->r10, ctx->r11);
    // 0x8009A078: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x8009A07C: addu        $t1, $v0, $t9
    ctx->r9 = ADD32(ctx->r2, ctx->r25);
    // 0x8009A080: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x8009A084: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8009A088: addiu       $s1, $s1, 0x1754
    ctx->r17 = ADD32(ctx->r17, 0X1754);
    // 0x8009A08C: addiu       $s5, $s5, 0x1E20
    ctx->r21 = ADD32(ctx->r21, 0X1E20);
    // 0x8009A090: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x8009A094: sw          $t8, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r24;
    // 0x8009A098: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x8009A09C: swc1        $f6, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f6.u32l;
    // 0x8009A0A0: addu        $fp, $v0, $t6
    ctx->r30 = ADD32(ctx->r2, ctx->r14);
    // 0x8009A0A4: addiu       $s6, $zero, 0x4
    ctx->r22 = ADD32(0, 0X4);
    // 0x8009A0A8: addiu       $s4, $zero, 0x3F
    ctx->r20 = ADD32(0, 0X3F);
    // 0x8009A0AC: addiu       $s3, $sp, 0x88
    ctx->r19 = ADD32(ctx->r29, 0X88);
L_8009A0B0:
    // 0x8009A0B0: lbu         $a0, 0x0($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0X0);
    // 0x8009A0B4: jal         0x8006B190
    // 0x8009A0B8: nop

    leveltable_world(rdram, ctx);
        goto after_10;
    // 0x8009A0B8: nop

    after_10:
    // 0x8009A0BC: addiu       $v1, $v0, -0x1
    ctx->r3 = ADD32(ctx->r2, -0X1);
    // 0x8009A0C0: bltz        $v1, L_8009A0D4
    if (SIGNED(ctx->r3) < 0) {
        // 0x8009A0C4: or          $t0, $v1, $zero
        ctx->r8 = ctx->r3 | 0;
            goto L_8009A0D4;
    }
    // 0x8009A0C4: or          $t0, $v1, $zero
    ctx->r8 = ctx->r3 | 0;
    // 0x8009A0C8: slti        $at, $v1, 0x5
    ctx->r1 = SIGNED(ctx->r3) < 0X5 ? 1 : 0;
    // 0x8009A0CC: bne         $at, $zero, L_8009A0D8
    if (ctx->r1 != 0) {
        // 0x8009A0D0: nop
    
            goto L_8009A0D8;
    }
    // 0x8009A0D0: nop

L_8009A0D4:
    // 0x8009A0D4: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8009A0D8:
    // 0x8009A0D8: lbu         $a0, 0x0($fp)
    ctx->r4 = MEM_BU(ctx->r30, 0X0);
    // 0x8009A0DC: jal         0x8006BDDC
    // 0x8009A0E0: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    level_name(rdram, ctx);
        goto after_11;
    // 0x8009A0E0: sw          $t0, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r8;
    after_11:
    // 0x8009A0E4: lbu         $t6, 0x0($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X0);
    // 0x8009A0E8: lw          $t0, 0xEC($sp)
    ctx->r8 = MEM_W(ctx->r29, 0XEC);
    // 0x8009A0EC: beq         $t6, $zero, L_8009A13C
    if (ctx->r14 == 0) {
        // 0x8009A0F0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_8009A13C;
    }
    // 0x8009A0F0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009A0F4: lbu         $a1, 0x0($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X0);
    // 0x8009A0F8: addu        $a0, $s3, $zero
    ctx->r4 = ADD32(ctx->r19, 0);
    // 0x8009A0FC: addu        $a2, $v0, $zero
    ctx->r6 = ADD32(ctx->r2, 0);
    // 0x8009A100: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
L_8009A104:
    // 0x8009A104: slti        $at, $v1, 0x61
    ctx->r1 = SIGNED(ctx->r3) < 0X61 ? 1 : 0;
    // 0x8009A108: bne         $at, $zero, L_8009A120
    if (ctx->r1 != 0) {
        // 0x8009A10C: sb          $a1, 0x0($a0)
        MEM_B(0X0, ctx->r4) = ctx->r5;
            goto L_8009A120;
    }
    // 0x8009A10C: sb          $a1, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r5;
    // 0x8009A110: slti        $at, $v1, 0x7B
    ctx->r1 = SIGNED(ctx->r3) < 0X7B ? 1 : 0;
    // 0x8009A114: beq         $at, $zero, L_8009A120
    if (ctx->r1 == 0) {
        // 0x8009A118: xori        $t7, $v1, 0x20
        ctx->r15 = ctx->r3 ^ 0X20;
            goto L_8009A120;
    }
    // 0x8009A118: xori        $t7, $v1, 0x20
    ctx->r15 = ctx->r3 ^ 0X20;
    // 0x8009A11C: sb          $t7, 0x0($a0)
    MEM_B(0X0, ctx->r4) = ctx->r15;
L_8009A120:
    // 0x8009A120: lbu         $a1, 0x1($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X1);
    // 0x8009A124: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009A128: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8009A12C: beq         $a1, $zero, L_8009A13C
    if (ctx->r5 == 0) {
        // 0x8009A130: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8009A13C;
    }
    // 0x8009A130: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x8009A134: bne         $s0, $s4, L_8009A104
    if (ctx->r16 != ctx->r20) {
        // 0x8009A138: andi        $v1, $a1, 0xFF
        ctx->r3 = ctx->r5 & 0XFF;
            goto L_8009A104;
    }
    // 0x8009A138: andi        $v1, $a1, 0xFF
    ctx->r3 = ctx->r5 & 0XFF;
L_8009A13C:
    // 0x8009A13C: mtc1        $s2, $f8
    ctx->f8.u32l = ctx->r18;
    // 0x8009A140: addu        $t8, $s3, $s0
    ctx->r24 = ADD32(ctx->r19, ctx->r16);
    // 0x8009A144: sb          $zero, 0x0($t8)
    MEM_B(0X0, ctx->r24) = 0;
    // 0x8009A148: lui         $at, 0x3F40
    ctx->r1 = S32(0X3F40 << 16);
    // 0x8009A14C: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8009A150: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8009A154: lui         $at, 0x3F50
    ctx->r1 = S32(0X3F50 << 16);
    // 0x8009A158: sll         $t9, $t0, 2
    ctx->r25 = S32(ctx->r8 << 2);
    // 0x8009A15C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A160: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8009A164: addu        $a1, $a1, $t9
    ctx->r5 = ADD32(ctx->r5, ctx->r25);
    // 0x8009A168: lw          $a1, 0x16F4($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X16F4);
    // 0x8009A16C: mfc1        $a3, $f8
    ctx->r7 = (int32_t)ctx->f8.u32l;
    // 0x8009A170: lw          $a2, 0x68($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X68);
    // 0x8009A174: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8009A178: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    // 0x8009A17C: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8009A180: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009A184: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A188: swc1        $f10, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f10.u32l;
    // 0x8009A18C: jal         0x80078D00
    // 0x8009A190: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_12;
    // 0x8009A190: swc1        $f16, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f16.u32l;
    after_12:
    // 0x8009A194: addiu       $t2, $zero, 0x34
    ctx->r10 = ADD32(0, 0X34);
    // 0x8009A198: addiu       $t3, $zero, 0x20
    ctx->r11 = ADD32(0, 0X20);
    // 0x8009A19C: addiu       $t4, $zero, 0x50
    ctx->r12 = ADD32(0, 0X50);
    // 0x8009A1A0: addiu       $t5, $zero, 0xB0
    ctx->r13 = ADD32(0, 0XB0);
    // 0x8009A1A4: addiu       $t6, $zero, 0x80
    ctx->r14 = ADD32(0, 0X80);
    // 0x8009A1A8: sw          $t6, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r14;
    // 0x8009A1AC: sw          $t5, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r13;
    // 0x8009A1B0: sw          $t4, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r12;
    // 0x8009A1B4: sw          $t3, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r11;
    // 0x8009A1B8: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009A1BC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A1C0: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8009A1C4: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8009A1C8: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x8009A1CC: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x8009A1D0: jal         0x80080E90
    // 0x8009A1D4: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    func_80080E90(rdram, ctx);
        goto after_13;
    // 0x8009A1D4: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    after_13:
    // 0x8009A1D8: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009A1DC: lw          $t8, 0x6498($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X6498);
    // 0x8009A1E0: lw          $t7, 0xE4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XE4);
    // 0x8009A1E4: lw          $v0, 0xD8($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XD8);
    // 0x8009A1E8: bne         $t7, $t8, L_8009A220
    if (ctx->r15 != ctx->r24) {
        // 0x8009A1EC: or          $a0, $s7, $zero
        ctx->r4 = ctx->r23 | 0;
            goto L_8009A220;
    }
    // 0x8009A1EC: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A1F0: addiu       $t9, $zero, 0x34
    ctx->r25 = ADD32(0, 0X34);
    // 0x8009A1F4: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A1F8: addiu       $a1, $zero, 0x28
    ctx->r5 = ADD32(0, 0X28);
    // 0x8009A1FC: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8009A200: addiu       $a3, $zero, 0xF0
    ctx->r7 = ADD32(0, 0XF0);
    // 0x8009A204: sw          $s6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r22;
    // 0x8009A208: sw          $s6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r22;
    // 0x8009A20C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x8009A210: sw          $v0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r2;
    // 0x8009A214: sw          $v0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r2;
    // 0x8009A218: jal         0x80080E90
    // 0x8009A21C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    func_80080E90(rdram, ctx);
        goto after_14;
    // 0x8009A21C: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
    after_14:
L_8009A220:
    // 0x8009A220: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009A224: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009A228: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8009A22C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009A230: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A234: jal         0x800C4384
    // 0x8009A238: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_15;
    // 0x8009A238: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_15:
    // 0x8009A23C: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
L_8009A240:
    // 0x8009A240: addu        $v0, $s5, $t2
    ctx->r2 = ADD32(ctx->r21, ctx->r10);
    // 0x8009A244: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x8009A248: lb          $t5, 0x1($v0)
    ctx->r13 = MEM_B(ctx->r2, 0X1);
    // 0x8009A24C: lh          $t4, 0x0($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X0);
    // 0x8009A250: lh          $t7, 0x2($s1)
    ctx->r15 = MEM_H(ctx->r17, 0X2);
    // 0x8009A254: addiu       $t8, $zero, 0xC
    ctx->r24 = ADD32(0, 0XC);
    // 0x8009A258: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8009A25C: addu        $a1, $t3, $t4
    ctx->r5 = ADD32(ctx->r11, ctx->r12);
    // 0x8009A260: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x8009A264: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8009A268: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A26C: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8009A270: jal         0x800C4440
    // 0x8009A274: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    draw_text(rdram, ctx);
        goto after_16;
    // 0x8009A274: addu        $a2, $t6, $t7
    ctx->r6 = ADD32(ctx->r14, ctx->r15);
    after_16:
    // 0x8009A278: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009A27C: bne         $s0, $s6, L_8009A240
    if (ctx->r16 != ctx->r22) {
        // 0x8009A280: sll         $t2, $s0, 1
        ctx->r10 = S32(ctx->r16 << 1);
            goto L_8009A240;
    }
    // 0x8009A280: sll         $t2, $s0, 1
    ctx->r10 = S32(ctx->r16 << 1);
    // 0x8009A284: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009A288: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009A28C: addiu       $a0, $zero, 0xC8
    ctx->r4 = ADD32(0, 0XC8);
    // 0x8009A290: addiu       $a1, $zero, 0xE4
    ctx->r5 = ADD32(0, 0XE4);
    // 0x8009A294: addiu       $a2, $zero, 0x50
    ctx->r6 = ADD32(0, 0X50);
    // 0x8009A298: jal         0x800C4384
    // 0x8009A29C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    set_text_colour(rdram, ctx);
        goto after_17;
    // 0x8009A29C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    after_17:
    // 0x8009A2A0: lh          $a1, 0x0($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X0);
    // 0x8009A2A4: lh          $t1, 0x2($s1)
    ctx->r9 = MEM_H(ctx->r17, 0X2);
    // 0x8009A2A8: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8009A2AC: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009A2B0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A2B4: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    // 0x8009A2B8: addiu       $a1, $a1, 0x28
    ctx->r5 = ADD32(ctx->r5, 0X28);
    // 0x8009A2BC: jal         0x800C4440
    // 0x8009A2C0: addu        $a2, $t1, $s2
    ctx->r6 = ADD32(ctx->r9, ctx->r18);
    draw_text(rdram, ctx);
        goto after_18;
    // 0x8009A2C0: addu        $a2, $t1, $s2
    ctx->r6 = ADD32(ctx->r9, ctx->r18);
    after_18:
    // 0x8009A2C4: lw          $t3, 0x74($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X74);
    // 0x8009A2C8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A2CC: lbu         $t4, 0x0($t3)
    ctx->r12 = MEM_BU(ctx->r11, 0X0);
    // 0x8009A2D0: lh          $a2, 0x4($s1)
    ctx->r6 = MEM_H(ctx->r17, 0X4);
    // 0x8009A2D4: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x8009A2D8: lh          $t6, 0x6($s1)
    ctx->r14 = MEM_H(ctx->r17, 0X6);
    // 0x8009A2DC: addu        $a1, $a1, $t5
    ctx->r5 = ADD32(ctx->r5, ctx->r13);
    // 0x8009A2E0: lw          $a1, 0xAF0($a1)
    ctx->r5 = MEM_W(ctx->r5, 0XAF0);
    // 0x8009A2E4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009A2E8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009A2EC: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009A2F0: addiu       $t1, $zero, 0xFF
    ctx->r9 = ADD32(0, 0XFF);
    // 0x8009A2F4: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009A2F8: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8009A2FC: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009A300: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009A304: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A308: addiu       $a2, $a2, 0x28
    ctx->r6 = ADD32(ctx->r6, 0X28);
    // 0x8009A30C: jal         0x80078AB8
    // 0x8009A310: addu        $a3, $t6, $s2
    ctx->r7 = ADD32(ctx->r14, ctx->r18);
    texrect_draw(rdram, ctx);
        goto after_19;
    // 0x8009A310: addu        $a3, $t6, $s2
    ctx->r7 = ADD32(ctx->r14, ctx->r18);
    after_19:
    // 0x8009A314: lw          $t2, 0x70($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X70);
    // 0x8009A318: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009A31C: lbu         $v0, 0x0($t2)
    ctx->r2 = MEM_BU(ctx->r10, 0X0);
    // 0x8009A320: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A324: beq         $v0, $at, L_8009A344
    if (ctx->r2 == ctx->r1) {
        // 0x8009A328: addiu       $t7, $zero, -0x1
        ctx->r15 = ADD32(0, -0X1);
            goto L_8009A344;
    }
    // 0x8009A328: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x8009A32C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009A330: beq         $v0, $at, L_8009A350
    if (ctx->r2 == ctx->r1) {
        // 0x8009A334: lui         $a1, 0x800E
        ctx->r5 = S32(0X800E << 16);
            goto L_8009A350;
    }
    // 0x8009A334: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A338: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A33C: b           L_8009A354
    // 0x8009A340: addiu       $a1, $a1, 0x45C
    ctx->r5 = ADD32(ctx->r5, 0X45C);
        goto L_8009A354;
    // 0x8009A340: addiu       $a1, $a1, 0x45C
    ctx->r5 = ADD32(ctx->r5, 0X45C);
L_8009A344:
    // 0x8009A344: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8009A348: b           L_8009A354
    // 0x8009A34C: addiu       $a1, $a1, 0x474
    ctx->r5 = ADD32(ctx->r5, 0X474);
        goto L_8009A354;
    // 0x8009A34C: addiu       $a1, $a1, 0x474
    ctx->r5 = ADD32(ctx->r5, 0X474);
L_8009A350:
    // 0x8009A350: addiu       $a1, $a1, 0x48C
    ctx->r5 = ADD32(ctx->r5, 0X48C);
L_8009A354:
    // 0x8009A354: lh          $t3, 0x8($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X8);
    // 0x8009A358: lh          $t5, 0xA($s1)
    ctx->r13 = MEM_H(ctx->r17, 0XA);
    // 0x8009A35C: addiu       $t4, $t3, 0x28
    ctx->r12 = ADD32(ctx->r11, 0X28);
    // 0x8009A360: addu        $t6, $t5, $s2
    ctx->r14 = ADD32(ctx->r13, ctx->r18);
    // 0x8009A364: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8009A368: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x8009A36C: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8009A370: lui         $at, 0x3F20
    ctx->r1 = S32(0X3F20 << 16);
    // 0x8009A374: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8009A378: cvt.s.w     $f18, $f18
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    ctx->f18.fl = CVT_S_W(ctx->f18.u32l);
    // 0x8009A37C: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x8009A380: sw          $t7, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r15;
    // 0x8009A384: mfc1        $a2, $f18
    ctx->r6 = (int32_t)ctx->f18.u32l;
    // 0x8009A388: sw          $zero, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = 0;
    // 0x8009A38C: swc1        $f0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f0.u32l;
    // 0x8009A390: jal         0x80078D00
    // 0x8009A394: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    texrect_draw_scaled(rdram, ctx);
        goto after_20;
    // 0x8009A394: swc1        $f0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f0.u32l;
    after_20:
    // 0x8009A398: jal         0x8007B3D0
    // 0x8009A39C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    rendermode_reset(rdram, ctx);
        goto after_21;
    // 0x8009A39C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_21:
    // 0x8009A3A0: lh          $t8, 0xC($s1)
    ctx->r24 = MEM_H(ctx->r17, 0XC);
    // 0x8009A3A4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009A3A8: addiu       $t9, $t8, -0x78
    ctx->r25 = ADD32(ctx->r24, -0X78);
    // 0x8009A3AC: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x8009A3B0: addiu       $v0, $v0, -0x8A4
    ctx->r2 = ADD32(ctx->r2, -0X8A4);
    // 0x8009A3B4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8009A3B8: lw          $t1, 0x0($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X0);
    // 0x8009A3BC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009A3C0: swc1        $f8, 0xEC($t1)
    MEM_W(0XEC, ctx->r9) = ctx->f8.u32l;
    // 0x8009A3C4: lh          $t2, 0xE($s1)
    ctx->r10 = MEM_H(ctx->r17, 0XE);
    // 0x8009A3C8: lw          $t5, 0xD0($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A3CC: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x8009A3D0: subu        $t4, $t3, $s2
    ctx->r12 = SUB32(ctx->r11, ctx->r18);
    // 0x8009A3D4: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x8009A3D8: addiu       $t7, $t6, 0x78
    ctx->r15 = ADD32(ctx->r14, 0X78);
    // 0x8009A3DC: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x8009A3E0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x8009A3E4: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x8009A3E8: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A3EC: swc1        $f16, 0xF0($t8)
    MEM_W(0XF0, ctx->r24) = ctx->f16.u32l;
    // 0x8009A3F0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8009A3F4: lwc1        $f18, -0x7A90($at)
    ctx->f18.u32l = MEM_W(ctx->r1, -0X7A90);
    // 0x8009A3F8: jal         0x8009CA60
    // 0x8009A3FC: swc1        $f18, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f18.u32l;
    menu_element_render(rdram, ctx);
        goto after_22;
    // 0x8009A3FC: swc1        $f18, 0xE8($t9)
    MEM_W(0XE8, ctx->r25) = ctx->f18.u32l;
    after_22:
    // 0x8009A400: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8009A404: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A408: sw          $t1, -0x89C($at)
    MEM_W(-0X89C, ctx->r1) = ctx->r9;
    // 0x8009A40C: lh          $t3, 0x12($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X12);
    // 0x8009A410: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A414: lw          $t6, 0xD0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A418: negu        $t4, $t3
    ctx->r12 = SUB32(0, ctx->r11);
    // 0x8009A41C: lhu         $a0, 0x0($t2)
    ctx->r4 = MEM_HU(ctx->r10, 0X0);
    // 0x8009A420: lh          $a1, 0x10($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X10);
    // 0x8009A424: subu        $t5, $t4, $s2
    ctx->r13 = SUB32(ctx->r12, ctx->r18);
    // 0x8009A428: addu        $a2, $t5, $t6
    ctx->r6 = ADD32(ctx->r13, ctx->r14);
    // 0x8009A42C: addiu       $a2, $a2, 0x77
    ctx->r6 = ADD32(ctx->r6, 0X77);
    // 0x8009A430: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8009A434: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009A438: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009A43C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009A440: jal         0x80081800
    // 0x8009A444: addiu       $a1, $a1, -0x77
    ctx->r5 = ADD32(ctx->r5, -0X77);
    menu_timestamp_render(rdram, ctx);
        goto after_23;
    // 0x8009A444: addiu       $a1, $a1, -0x77
    ctx->r5 = ADD32(ctx->r5, -0X77);
    after_23:
    // 0x8009A448: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009A44C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009A450: sw          $t7, -0x89C($at)
    MEM_W(-0X89C, ctx->r1) = ctx->r15;
    // 0x8009A454: lh          $t9, 0x12($s1)
    ctx->r25 = MEM_H(ctx->r17, 0X12);
    // 0x8009A458: lw          $t8, 0x6C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A45C: lw          $t3, 0xD0($sp)
    ctx->r11 = MEM_W(ctx->r29, 0XD0);
    // 0x8009A460: negu        $t1, $t9
    ctx->r9 = SUB32(0, ctx->r25);
    // 0x8009A464: lhu         $a0, 0x0($t8)
    ctx->r4 = MEM_HU(ctx->r24, 0X0);
    // 0x8009A468: lh          $a1, 0x10($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X10);
    // 0x8009A46C: subu        $t2, $t1, $s2
    ctx->r10 = SUB32(ctx->r9, ctx->r18);
    // 0x8009A470: addiu       $t4, $zero, 0xC0
    ctx->r12 = ADD32(0, 0XC0);
    // 0x8009A474: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009A478: addu        $a2, $t2, $t3
    ctx->r6 = ADD32(ctx->r10, ctx->r11);
    // 0x8009A47C: addiu       $a2, $a2, 0x79
    ctx->r6 = ADD32(ctx->r6, 0X79);
    // 0x8009A480: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009A484: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009A488: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    // 0x8009A48C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009A490: jal         0x80081800
    // 0x8009A494: addiu       $a1, $a1, -0x79
    ctx->r5 = ADD32(ctx->r5, -0X79);
    menu_timestamp_render(rdram, ctx);
        goto after_24;
    // 0x8009A494: addiu       $a1, $a1, -0x79
    ctx->r5 = ADD32(ctx->r5, -0X79);
    after_24:
    // 0x8009A498: lw          $t8, 0x74($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X74);
    // 0x8009A49C: lw          $t6, 0xE4($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XE4);
    // 0x8009A4A0: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x8009A4A4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009A4A8: lw          $t1, 0x70($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X70);
    // 0x8009A4AC: lw          $t3, 0x6C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X6C);
    // 0x8009A4B0: lw          $t5, 0xE8($sp)
    ctx->r13 = MEM_W(ctx->r29, 0XE8);
    // 0x8009A4B4: lw          $t8, 0x64D4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X64D4);
    // 0x8009A4B8: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8009A4BC: addiu       $t2, $t1, 0x1
    ctx->r10 = ADD32(ctx->r9, 0X1);
    // 0x8009A4C0: addiu       $t4, $t3, 0x2
    ctx->r12 = ADD32(ctx->r11, 0X2);
    // 0x8009A4C4: addiu       $t6, $t5, -0x1
    ctx->r14 = ADD32(ctx->r13, -0X1);
    // 0x8009A4C8: slt         $at, $t7, $t8
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x8009A4CC: sw          $t4, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r12;
    // 0x8009A4D0: sw          $t2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r10;
    // 0x8009A4D4: sw          $t7, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->r15;
    // 0x8009A4D8: sw          $t9, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r25;
    // 0x8009A4DC: addiu       $fp, $fp, 0x1
    ctx->r30 = ADD32(ctx->r30, 0X1);
    // 0x8009A4E0: sw          $t6, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r14;
    // 0x8009A4E4: beq         $at, $zero, L_8009A4F4
    if (ctx->r1 == 0) {
        // 0x8009A4E8: addiu       $s2, $s2, 0x36
        ctx->r18 = ADD32(ctx->r18, 0X36);
            goto L_8009A4F4;
    }
    // 0x8009A4E8: addiu       $s2, $s2, 0x36
    ctx->r18 = ADD32(ctx->r18, 0X36);
    // 0x8009A4EC: bgtz        $t6, L_8009A0B0
    if (SIGNED(ctx->r14) > 0) {
        // 0x8009A4F0: nop
    
            goto L_8009A0B0;
    }
    // 0x8009A4F0: nop

L_8009A4F4:
    // 0x8009A4F4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009A4F8: lw          $t9, 0xD8($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XD8);
    // 0x8009A4FC: addiu       $s0, $s0, 0x63E0
    ctx->r16 = ADD32(ctx->r16, 0X63E0);
    // 0x8009A500: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8009A504: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x8009A508: blez        $t2, L_8009A698
    if (SIGNED(ctx->r10) <= 0) {
        // 0x8009A50C: sw          $t1, 0xD8($sp)
        MEM_W(0XD8, ctx->r29) = ctx->r9;
            goto L_8009A698;
    }
    // 0x8009A50C: sw          $t1, 0xD8($sp)
    MEM_W(0XD8, ctx->r29) = ctx->r9;
    // 0x8009A510: jal         0x800C56D0
    // 0x8009A514: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    clear_dialogue_box_open_flag(rdram, ctx);
        goto after_25;
    // 0x8009A514: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_25:
    // 0x8009A518: jal         0x800C5494
    // 0x8009A51C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    dialogue_clear(rdram, ctx);
        goto after_26;
    // 0x8009A51C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    after_26:
    // 0x8009A520: addiu       $t3, $zero, 0x8A
    ctx->r11 = ADD32(0, 0X8A);
    // 0x8009A524: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x8009A528: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A52C: addiu       $a1, $zero, 0x68
    ctx->r5 = ADD32(0, 0X68);
    // 0x8009A530: addiu       $a2, $zero, 0x66
    ctx->r6 = ADD32(0, 0X66);
    // 0x8009A534: jal         0x800C4EDC
    // 0x8009A538: addiu       $a3, $zero, 0xD8
    ctx->r7 = ADD32(0, 0XD8);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_27;
    // 0x8009A538: addiu       $a3, $zero, 0xD8
    ctx->r7 = ADD32(0, 0XD8);
    after_27:
    // 0x8009A53C: addiu       $t4, $zero, 0xC0
    ctx->r12 = ADD32(0, 0XC0);
    // 0x8009A540: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x8009A544: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A548: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009A54C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A550: jal         0x800C4FBC
    // 0x8009A554: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_28;
    // 0x8009A554: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_28:
    // 0x8009A558: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A55C: jal         0x800C4F7C
    // 0x8009A560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    set_dialogue_font(rdram, ctx);
        goto after_29;
    // 0x8009A560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_29:
    // 0x8009A564: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A568: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009A56C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A570: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009A574: jal         0x800C5050
    // 0x8009A578: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_background_colour(rdram, ctx);
        goto after_30;
    // 0x8009A578: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_30:
    // 0x8009A57C: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8009A580: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8009A584: bne         $t5, $at, L_8009A5B8
    if (ctx->r13 != ctx->r1) {
        // 0x8009A588: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8009A5B8;
    }
    // 0x8009A588: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A58C: lw          $t7, 0xD8($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XD8);
    // 0x8009A590: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009A594: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009A598: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A59C: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009A5A0: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009A5A4: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009A5A8: jal         0x800C5000
    // 0x8009A5AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    set_current_text_colour(rdram, ctx);
        goto after_31;
    // 0x8009A5AC: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    after_31:
    // 0x8009A5B0: b           L_8009A5D4
    // 0x8009A5B4: nop

        goto L_8009A5D4;
    // 0x8009A5B4: nop

L_8009A5B8:
    // 0x8009A5B8: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8009A5BC: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8009A5C0: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009A5C4: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009A5C8: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009A5CC: jal         0x800C5000
    // 0x8009A5D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_32;
    // 0x8009A5D0: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_32:
L_8009A5D4:
    // 0x8009A5D4: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x8009A5D8: lw          $t9, -0xB60($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB60);
    // 0x8009A5DC: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
    // 0x8009A5E0: lw          $a3, 0x150($t9)
    ctx->r7 = MEM_W(ctx->r25, 0X150);
    // 0x8009A5E4: addiu       $t2, $zero, 0xC
    ctx->r10 = ADD32(0, 0XC);
    // 0x8009A5E8: sw          $t2, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r10;
    // 0x8009A5EC: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x8009A5F0: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A5F4: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009A5F8: jal         0x800C5168
    // 0x8009A5FC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    render_dialogue_text(rdram, ctx);
        goto after_33;
    // 0x8009A5FC: addiu       $a2, $zero, 0xC
    ctx->r6 = ADD32(0, 0XC);
    after_33:
    // 0x8009A600: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8009A604: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009A608: bne         $t3, $at, L_8009A63C
    if (ctx->r11 != ctx->r1) {
        // 0x8009A60C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_8009A63C;
    }
    // 0x8009A60C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A610: lw          $t4, 0xD8($sp)
    ctx->r12 = MEM_W(ctx->r29, 0XD8);
    // 0x8009A614: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009A618: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    // 0x8009A61C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A620: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009A624: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009A628: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009A62C: jal         0x800C5000
    // 0x8009A630: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    set_current_text_colour(rdram, ctx);
        goto after_34;
    // 0x8009A630: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    after_34:
    // 0x8009A634: b           L_8009A658
    // 0x8009A638: nop

        goto L_8009A658;
    // 0x8009A638: nop

L_8009A63C:
    // 0x8009A63C: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009A640: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8009A644: addiu       $a1, $zero, 0xFF
    ctx->r5 = ADD32(0, 0XFF);
    // 0x8009A648: addiu       $a2, $zero, 0xFF
    ctx->r6 = ADD32(0, 0XFF);
    // 0x8009A64C: addiu       $a3, $zero, 0xFF
    ctx->r7 = ADD32(0, 0XFF);
    // 0x8009A650: jal         0x800C5000
    // 0x8009A654: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    set_current_text_colour(rdram, ctx);
        goto after_35;
    // 0x8009A654: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    after_35:
L_8009A658:
    // 0x8009A658: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009A65C: lw          $t8, -0xB60($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB60);
    // 0x8009A660: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8009A664: lw          $a3, 0x154($t8)
    ctx->r7 = MEM_W(ctx->r24, 0X154);
    // 0x8009A668: addiu       $t9, $zero, 0xC
    ctx->r25 = ADD32(0, 0XC);
    // 0x8009A66C: sw          $t9, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r25;
    // 0x8009A670: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    // 0x8009A674: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x8009A678: addiu       $a1, $zero, -0x8000
    ctx->r5 = ADD32(0, -0X8000);
    // 0x8009A67C: jal         0x800C5168
    // 0x8009A680: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    render_dialogue_text(rdram, ctx);
        goto after_36;
    // 0x8009A680: addiu       $a2, $zero, 0x1C
    ctx->r6 = ADD32(0, 0X1C);
    after_36:
    // 0x8009A684: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A688: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009A68C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A690: jal         0x800C5B58
    // 0x8009A694: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    render_dialogue_box(rdram, ctx);
        goto after_37;
    // 0x8009A694: addiu       $a3, $zero, 0x7
    ctx->r7 = ADD32(0, 0X7);
    after_37:
L_8009A698:
    // 0x8009A698: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8009A69C: lw          $t1, 0x63BC($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X63BC);
    // 0x8009A6A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009A6A4: andi        $t2, $t1, 0x10
    ctx->r10 = ctx->r9 & 0X10;
    // 0x8009A6A8: beq         $t2, $zero, L_8009A7A4
    if (ctx->r10 == 0) {
        // 0x8009A6AC: lui         $t3, 0x8012
        ctx->r11 = S32(0X8012 << 16);
            goto L_8009A7A4;
    }
    // 0x8009A6AC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009A6B0: lw          $v0, 0x63D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D8);
    // 0x8009A6B4: lw          $t3, 0x64D4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X64D4);
    // 0x8009A6B8: addiu       $t4, $v0, 0x3
    ctx->r12 = ADD32(ctx->r2, 0X3);
    // 0x8009A6BC: slt         $at, $t4, $t3
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r11) ? 1 : 0;
    // 0x8009A6C0: beq         $at, $zero, L_8009A734
    if (ctx->r1 == 0) {
        // 0x8009A6C4: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_8009A734;
    }
    // 0x8009A6C4: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009A6C8: addiu       $s0, $s0, 0x43C
    ctx->r16 = ADD32(ctx->r16, 0X43C);
    // 0x8009A6CC: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x8009A6D0: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8009A6D4: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009A6D8: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A6DC: addiu       $a2, $zero, 0xA1
    ctx->r6 = ADD32(0, 0XA1);
    // 0x8009A6E0: addiu       $a3, $s2, 0x3
    ctx->r7 = ADD32(ctx->r18, 0X3);
    // 0x8009A6E4: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009A6E8: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009A6EC: jal         0x80078AB8
    // 0x8009A6F0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    texrect_draw(rdram, ctx);
        goto after_38;
    // 0x8009A6F0: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_38:
    // 0x8009A6F4: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x8009A6F8: addiu       $t8, $zero, 0xFF
    ctx->r24 = ADD32(0, 0XFF);
    // 0x8009A6FC: addiu       $t6, $zero, 0xFF
    ctx->r14 = ADD32(0, 0XFF);
    // 0x8009A700: addiu       $t9, $zero, 0xFF
    ctx->r25 = ADD32(0, 0XFF);
    // 0x8009A704: sw          $t9, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r25;
    // 0x8009A708: sw          $t6, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r14;
    // 0x8009A70C: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    // 0x8009A710: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8009A714: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A718: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009A71C: addiu       $a2, $zero, 0x9F
    ctx->r6 = ADD32(0, 0X9F);
    // 0x8009A720: jal         0x80078AB8
    // 0x8009A724: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
    texrect_draw(rdram, ctx);
        goto after_39;
    // 0x8009A724: addiu       $a3, $s2, 0x1
    ctx->r7 = ADD32(ctx->r18, 0X1);
    after_39:
    // 0x8009A728: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009A72C: lw          $v0, 0x63D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D8);
    // 0x8009A730: nop

L_8009A734:
    // 0x8009A734: blez        $v0, L_8009A79C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009A738: lui         $s0, 0x800E
        ctx->r16 = S32(0X800E << 16);
            goto L_8009A79C;
    }
    // 0x8009A738: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8009A73C: addiu       $s0, $s0, 0x41C
    ctx->r16 = ADD32(ctx->r16, 0X41C);
    // 0x8009A740: addiu       $t1, $zero, 0x80
    ctx->r9 = ADD32(0, 0X80);
    // 0x8009A744: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x8009A748: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009A74C: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A750: addiu       $a2, $zero, 0xA1
    ctx->r6 = ADD32(0, 0XA1);
    // 0x8009A754: addiu       $a3, $zero, 0x36
    ctx->r7 = ADD32(0, 0X36);
    // 0x8009A758: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x8009A75C: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x8009A760: jal         0x80078AB8
    // 0x8009A764: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    texrect_draw(rdram, ctx);
        goto after_40;
    // 0x8009A764: sw          $zero, 0x18($sp)
    MEM_W(0X18, ctx->r29) = 0;
    after_40:
    // 0x8009A768: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x8009A76C: addiu       $t3, $zero, 0xFF
    ctx->r11 = ADD32(0, 0XFF);
    // 0x8009A770: addiu       $t4, $zero, 0xFF
    ctx->r12 = ADD32(0, 0XFF);
    // 0x8009A774: addiu       $t5, $zero, 0xFF
    ctx->r13 = ADD32(0, 0XFF);
    // 0x8009A778: sw          $t5, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r13;
    // 0x8009A77C: sw          $t4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r12;
    // 0x8009A780: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8009A784: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x8009A788: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    // 0x8009A78C: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8009A790: addiu       $a2, $zero, 0x9F
    ctx->r6 = ADD32(0, 0X9F);
    // 0x8009A794: jal         0x80078AB8
    // 0x8009A798: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    texrect_draw(rdram, ctx);
        goto after_41;
    // 0x8009A798: addiu       $a3, $zero, 0x34
    ctx->r7 = ADD32(0, 0X34);
    after_41:
L_8009A79C:
    // 0x8009A79C: jal         0x8007B3D0
    // 0x8009A7A0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    rendermode_reset(rdram, ctx);
        goto after_42;
    // 0x8009A7A0: or          $a0, $s7, $zero
    ctx->r4 = ctx->r23 | 0;
    after_42:
L_8009A7A4:
    // 0x8009A7A4: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
L_8009A7A8:
    // 0x8009A7A8: lw          $s0, 0x38($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X38);
    // 0x8009A7AC: lw          $s1, 0x3C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X3C);
    // 0x8009A7B0: lw          $s2, 0x40($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X40);
    // 0x8009A7B4: lw          $s3, 0x44($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X44);
    // 0x8009A7B8: lw          $s4, 0x48($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X48);
    // 0x8009A7BC: lw          $s5, 0x4C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X4C);
    // 0x8009A7C0: lw          $s6, 0x50($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X50);
    // 0x8009A7C4: lw          $s7, 0x54($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X54);
    // 0x8009A7C8: lw          $fp, 0x58($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X58);
    // 0x8009A7CC: jr          $ra
    // 0x8009A7D0: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
    return;
    // 0x8009A7D0: addiu       $sp, $sp, 0xF0
    ctx->r29 = ADD32(ctx->r29, 0XF0);
;}
RECOMP_FUNC void alCSPSetVol(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_scale_sequence_player_volume(uint8_t*, recomp_context*); dkr_scale_sequence_player_volume(rdram, ctx);
    // 0x800C7850: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800C7854: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800C7858: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    // 0x800C785C: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x800C7860: addiu       $t7, $zero, 0xA
    ctx->r15 = ADD32(0, 0XA);
    // 0x800C7864: sh          $t7, 0x18($sp)
    MEM_H(0X18, ctx->r29) = ctx->r15;
    // 0x800C7868: sh          $t6, 0x1C($sp)
    MEM_H(0X1C, ctx->r29) = ctx->r14;
    // 0x800C786C: addiu       $a1, $sp, 0x18
    ctx->r5 = ADD32(ctx->r29, 0X18);
    // 0x800C7870: addiu       $a0, $a0, 0x48
    ctx->r4 = ADD32(ctx->r4, 0X48);
    // 0x800C7874: jal         0x800C91AC
    // 0x800C7878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    alEvtqPostEvent(rdram, ctx);
        goto after_0;
    // 0x800C7878: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x800C787C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800C7880: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x800C7884: jr          $ra
    // 0x800C7888: nop

    return;
    // 0x800C7888: nop

;}
RECOMP_FUNC void dialogue_challenge_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C3564: addiu       $sp, $sp, -0x88
    ctx->r29 = ADD32(ctx->r29, -0X88);
    // 0x800C3568: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C356C: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x800C3570: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x800C3574: addiu       $t8, $zero, 0xB4
    ctx->r24 = ADD32(0, 0XB4);
    // 0x800C3578: addiu       $t9, $zero, 0x7D
    ctx->r25 = ADD32(0, 0X7D);
    // 0x800C357C: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800C3580: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x800C3584: addiu       $t2, $zero, 0xA
    ctx->r10 = ADD32(0, 0XA);
    // 0x800C3588: addiu       $t3, $zero, 0xF
    ctx->r11 = ADD32(0, 0XF);
    // 0x800C358C: addiu       $t4, $zero, 0x7D
    ctx->r12 = ADD32(0, 0X7D);
    // 0x800C3590: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800C3594: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800C3598: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C359C: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C35A0: sw          $zero, 0x40($sp)
    MEM_W(0X40, ctx->r29) = 0;
    // 0x800C35A4: sw          $t9, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r25;
    // 0x800C35A8: sw          $t8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r24;
    // 0x800C35AC: sw          $t7, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r15;
    // 0x800C35B0: sw          $t6, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r14;
    // 0x800C35B4: sw          $t0, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r8;
    // 0x800C35B8: sw          $zero, 0x54($sp)
    MEM_W(0X54, ctx->r29) = 0;
    // 0x800C35BC: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
    // 0x800C35C0: sw          $zero, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = 0;
    // 0x800C35C4: sw          $zero, 0x60($sp)
    MEM_W(0X60, ctx->r29) = 0;
    // 0x800C35C8: sw          $t3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r11;
    // 0x800C35CC: sw          $t2, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r10;
    // 0x800C35D0: sw          $t1, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->r9;
    // 0x800C35D4: sw          $t4, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r12;
    // 0x800C35D8: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C35DC: addiu       $a1, $zero, 0xA
    ctx->r5 = ADD32(0, 0XA);
    // 0x800C35E0: addiu       $a2, $zero, 0xF
    ctx->r6 = ADD32(0, 0XF);
    // 0x800C35E4: jal         0x800C4EDC
    // 0x800C35E8: addiu       $a3, $zero, 0xB4
    ctx->r7 = ADD32(0, 0XB4);
    set_current_dialogue_box_coords(rdram, ctx);
        goto after_0;
    // 0x800C35E8: addiu       $a3, $zero, 0xB4
    ctx->r7 = ADD32(0, 0XB4);
    after_0:
    // 0x800C35EC: lw          $a1, 0x40($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X40);
    // 0x800C35F0: jal         0x800C4F7C
    // 0x800C35F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_dialogue_font(rdram, ctx);
        goto after_1;
    // 0x800C35F4: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800C35F8: addiu       $t5, $zero, 0x80
    ctx->r13 = ADD32(0, 0X80);
    // 0x800C35FC: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x800C3600: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3604: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800C3608: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    // 0x800C360C: jal         0x800C4FBC
    // 0x800C3610: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_2;
    // 0x800C3610: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x800C3614: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x800C3618: lw          $a1, 0x54($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X54);
    // 0x800C361C: lw          $a2, 0x58($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X58);
    // 0x800C3620: lw          $a3, 0x5C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X5C);
    // 0x800C3624: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x800C3628: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x800C362C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3630: jal         0x800C5000
    // 0x800C3634: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    set_current_text_colour(rdram, ctx);
        goto after_3;
    // 0x800C3634: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_3:
    // 0x800C3638: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C363C: lh          $a0, -0x5872($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X5872);
    // 0x800C3640: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800C3644: beq         $a0, $zero, L_800C36D4
    if (ctx->r4 == 0) {
        // 0x800C3648: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800C36D4;
    }
    // 0x800C3648: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C364C: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800C3650: lw          $v0, -0x5860($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5860);
    // 0x800C3654: addiu       $s2, $zero, 0x2
    ctx->r18 = ADD32(0, 0X2);
    // 0x800C3658: lbu         $t8, 0x0($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X0);
    // 0x800C365C: addu        $s0, $v0, $zero
    ctx->r16 = ADD32(ctx->r2, 0);
    // 0x800C3660: beq         $s2, $t8, L_800C36D4
    if (ctx->r18 == ctx->r24) {
        // 0x800C3664: andi        $v1, $t8, 0xFF
        ctx->r3 = ctx->r24 & 0XFF;
            goto L_800C36D4;
    }
    // 0x800C3664: andi        $v1, $t8, 0xFF
    ctx->r3 = ctx->r24 & 0XFF;
    // 0x800C3668: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x800C366C: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C3670:
    // 0x800C3670: bne         $at, $zero, L_800C36AC
    if (ctx->r1 != 0) {
        // 0x800C3674: slti        $at, $v1, 0xD
        ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
            goto L_800C36AC;
    }
    // 0x800C3674: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x800C3678: beq         $at, $zero, L_800C36AC
    if (ctx->r1 == 0) {
        // 0x800C367C: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_800C36AC;
    }
    // 0x800C367C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800C3680: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C3684: jal         0x800C38B4
    // 0x800C3688: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    func_800C38B4(rdram, ctx);
        goto after_4;
    // 0x800C3688: sw          $a2, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r6;
    after_4:
    // 0x800C368C: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800C3690: lw          $t9, -0x5860($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5860);
    // 0x800C3694: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C3698: addu        $s0, $t9, $v0
    ctx->r16 = ADD32(ctx->r25, ctx->r2);
    // 0x800C369C: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C36A0: lh          $a0, -0x5872($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X5872);
    // 0x800C36A4: lw          $a2, 0x7C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X7C);
    // 0x800C36A8: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C36AC:
    // 0x800C36AC: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C36B0: bne         $v1, $at, L_800C36BC
    if (ctx->r3 != ctx->r1) {
        // 0x800C36B4: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_800C36BC;
    }
    // 0x800C36B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C36B8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800C36BC:
    // 0x800C36BC: beq         $a2, $a0, L_800C36D4
    if (ctx->r6 == ctx->r4) {
        // 0x800C36C0: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C36D4;
    }
    // 0x800C36C0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C36C4: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C36C8: nop

    // 0x800C36CC: bne         $s2, $v1, L_800C3670
    if (ctx->r18 != ctx->r3) {
        // 0x800C36D0: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800C3670;
    }
    // 0x800C36D0: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C36D4:
    // 0x800C36D4: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C36D8: lw          $t0, -0x5860($t0)
    ctx->r8 = MEM_W(ctx->r8, -0X5860);
    // 0x800C36DC: addiu       $s3, $sp, 0x40
    ctx->r19 = ADD32(ctx->r29, 0X40);
    // 0x800C36E0: addu        $t1, $t0, $s1
    ctx->r9 = ADD32(ctx->r8, ctx->r17);
    // 0x800C36E4: lbu         $v1, 0x0($t1)
    ctx->r3 = MEM_BU(ctx->r9, 0X0);
    // 0x800C36E8: nop

    // 0x800C36EC: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800C36F0: bne         $at, $zero, L_800C370C
    if (ctx->r1 != 0) {
        // 0x800C36F4: slti        $at, $v1, 0xD
        ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
            goto L_800C370C;
    }
    // 0x800C36F4: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x800C36F8: beq         $at, $zero, L_800C370C
    if (ctx->r1 == 0) {
        // 0x800C36FC: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C370C;
    }
    // 0x800C36FC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C3700: jal         0x800C38B4
    // 0x800C3704: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C38B4(rdram, ctx);
        goto after_5;
    // 0x800C3704: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_5:
    // 0x800C3708: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C370C:
    // 0x800C370C: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
L_800C3710:
    // 0x800C3710: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C3714: lw          $t2, -0x5860($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5860);
    // 0x800C3718: lw          $t3, 0x64($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X64);
    // 0x800C371C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800C3720: bne         $t3, $zero, L_800C3734
    if (ctx->r11 != 0) {
        // 0x800C3724: addu        $s0, $t2, $s1
        ctx->r16 = ADD32(ctx->r10, ctx->r17);
            goto L_800C3734;
    }
    // 0x800C3724: addu        $s0, $t2, $s1
    ctx->r16 = ADD32(ctx->r10, ctx->r17);
    // 0x800C3728: lw          $a1, 0x68($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X68);
    // 0x800C372C: b           L_800C374C
    // 0x800C3730: nop

        goto L_800C374C;
    // 0x800C3730: nop

L_800C3734:
    // 0x800C3734: lw          $t4, 0x4C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X4C);
    // 0x800C3738: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800C373C: nop

    // 0x800C3740: subu        $a1, $t4, $t5
    ctx->r5 = SUB32(ctx->r12, ctx->r13);
    // 0x800C3744: sra         $t6, $a1, 1
    ctx->r14 = S32(SIGNED(ctx->r5) >> 1);
    // 0x800C3748: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
L_800C374C:
    // 0x800C374C: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800C3750: lh          $t7, 0x3674($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X3674);
    // 0x800C3754: lw          $t8, 0x64($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X64);
    // 0x800C3758: lw          $a2, 0x6C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X6C);
    // 0x800C375C: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x800C3760: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x800C3764: jal         0x800C5168
    // 0x800C3768: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    render_dialogue_text(rdram, ctx);
        goto after_6;
    // 0x800C3768: sw          $t8, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r24;
    after_6:
    // 0x800C376C: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800C3770: lw          $t0, 0x70($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X70);
    // 0x800C3774: lui         $t2, 0x8013
    ctx->r10 = S32(0X8013 << 16);
    // 0x800C3778: lw          $t2, -0x5860($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X5860);
    // 0x800C377C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x800C3780: sw          $t1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r9;
    // 0x800C3784: addu        $s0, $t2, $s1
    ctx->r16 = ADD32(ctx->r10, ctx->r17);
    // 0x800C3788: lbu         $v1, 0x0($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X0);
    // 0x800C378C: nop

    // 0x800C3790: blez        $v1, L_800C37A8
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800C3794: nop
    
            goto L_800C37A8;
    }
    // 0x800C3794: nop

L_800C3798:
    // 0x800C3798: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x800C379C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C37A0: bgtz        $v1, L_800C3798
    if (SIGNED(ctx->r3) > 0) {
        // 0x800C37A4: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C3798;
    }
    // 0x800C37A4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C37A8:
    // 0x800C37A8: bne         $v1, $zero, L_800C37C4
    if (ctx->r3 != 0) {
        // 0x800C37AC: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800C37C4;
    }
    // 0x800C37AC: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C37B0:
    // 0x800C37B0: lbu         $v1, 0x1($s0)
    ctx->r3 = MEM_BU(ctx->r16, 0X1);
    // 0x800C37B4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x800C37B8: beq         $v1, $zero, L_800C37B0
    if (ctx->r3 == 0) {
        // 0x800C37BC: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C37B0;
    }
    // 0x800C37BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800C37C0: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C37C4:
    // 0x800C37C4: beq         $at, $zero, L_800C37D4
    if (ctx->r1 == 0) {
        // 0x800C37C8: slti        $at, $v1, 0x3
        ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
            goto L_800C37D4;
    }
    // 0x800C37C8: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800C37CC: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x800C37D0: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
L_800C37D4:
    // 0x800C37D4: bne         $at, $zero, L_800C37F0
    if (ctx->r1 != 0) {
        // 0x800C37D8: slti        $at, $v1, 0xD
        ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
            goto L_800C37F0;
    }
    // 0x800C37D8: slti        $at, $v1, 0xD
    ctx->r1 = SIGNED(ctx->r3) < 0XD ? 1 : 0;
    // 0x800C37DC: beq         $at, $zero, L_800C37F0
    if (ctx->r1 == 0) {
        // 0x800C37E0: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_800C37F0;
    }
    // 0x800C37E0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x800C37E4: jal         0x800C38B4
    // 0x800C37E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    func_800C38B4(rdram, ctx);
        goto after_7;
    // 0x800C37E8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x800C37EC: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
L_800C37F0:
    // 0x800C37F0: bne         $s2, $zero, L_800C3710
    if (ctx->r18 != 0) {
        // 0x800C37F4: nop
    
            goto L_800C3710;
    }
    // 0x800C37F4: nop

    // 0x800C37F8: jal         0x8006A554
    // 0x800C37FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    input_pressed(rdram, ctx);
        goto after_8;
    // 0x800C37FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_8:
    // 0x800C3800: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C3804: lb          $t3, -0x5879($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X5879);
    // 0x800C3808: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800C380C: bne         $t3, $zero, L_800C3818
    if (ctx->r11 != 0) {
        // 0x800C3810: lui         $s0, 0x8013
        ctx->r16 = S32(0X8013 << 16);
            goto L_800C3818;
    }
    // 0x800C3810: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C3814: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800C3818:
    // 0x800C3818: addiu       $s0, $s0, -0x5876
    ctx->r16 = ADD32(ctx->r16, -0X5876);
    // 0x800C381C: lbu         $t4, 0x0($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X0);
    // 0x800C3820: andi        $t5, $v1, 0x8000
    ctx->r13 = ctx->r3 & 0X8000;
    // 0x800C3824: bne         $t4, $zero, L_800C3894
    if (ctx->r12 != 0) {
        // 0x800C3828: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800C3894;
    }
    // 0x800C3828: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C382C: bne         $t5, $zero, L_800C3840
    if (ctx->r13 != 0) {
        // 0x800C3830: lui         $t6, 0x8013
        ctx->r14 = S32(0X8013 << 16);
            goto L_800C3840;
    }
    // 0x800C3830: lui         $t6, 0x8013
    ctx->r14 = S32(0X8013 << 16);
    // 0x800C3834: lb          $t6, -0x587C($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X587C);
    // 0x800C3838: nop

    // 0x800C383C: beq         $t6, $zero, L_800C3890
    if (ctx->r14 == 0) {
        // 0x800C3840: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800C3890;
    }
L_800C3840:
    // 0x800C3840: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800C3844: lw          $t7, -0x5860($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5860);
    // 0x800C3848: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800C384C: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x800C3850: lbu         $t9, 0x0($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X0);
    // 0x800C3854: lui         $t0, 0x8013
    ctx->r8 = S32(0X8013 << 16);
    // 0x800C3858: bne         $t9, $at, L_800C3874
    if (ctx->r25 != ctx->r1) {
        // 0x800C385C: addiu       $a0, $zero, 0x3
        ctx->r4 = ADD32(0, 0X3);
            goto L_800C3874;
    }
    // 0x800C385C: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    // 0x800C3860: lh          $t0, -0x5872($t0)
    ctx->r8 = MEM_H(ctx->r8, -0X5872);
    // 0x800C3864: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3868: addiu       $t1, $t0, 0x1
    ctx->r9 = ADD32(ctx->r8, 0X1);
    // 0x800C386C: b           L_800C3880
    // 0x800C3870: sh          $t1, -0x5872($at)
    MEM_H(-0X5872, ctx->r1) = ctx->r9;
        goto L_800C3880;
    // 0x800C3870: sh          $t1, -0x5872($at)
    MEM_H(-0X5872, ctx->r1) = ctx->r9;
L_800C3874:
    // 0x800C3874: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3878: jal         0x8009CF68
    // 0x800C387C: sb          $zero, -0x5877($at)
    MEM_B(-0X5877, ctx->r1) = 0;
    dialogue_npc_finish(rdram, ctx);
        goto after_9;
    // 0x800C387C: sb          $zero, -0x5877($at)
    MEM_B(-0X5877, ctx->r1) = 0;
    after_9:
L_800C3880:
    // 0x800C3880: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C3884: sb          $zero, -0x587C($at)
    MEM_B(-0X587C, ctx->r1) = 0;
    // 0x800C3888: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C388C: sb          $zero, -0x587A($at)
    MEM_B(-0X587A, ctx->r1) = 0;
L_800C3890:
    // 0x800C3890: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800C3894:
    // 0x800C3894: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x800C3898: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C389C: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C38A0: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800C38A4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800C38A8: addiu       $sp, $sp, 0x88
    ctx->r29 = ADD32(ctx->r29, 0X88);
    // 0x800C38AC: jr          $ra
    // 0x800C38B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    return;
    // 0x800C38B0: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
;}
