#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void __osIdCheckSum(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800D534C: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800D5350: sh          $zero, 0x6($sp)
    MEM_H(0X6, ctx->r29) = 0;
    // 0x800D5354: sh          $zero, 0x0($a2)
    MEM_H(0X0, ctx->r6) = 0;
    // 0x800D5358: lhu         $t6, 0x0($a2)
    ctx->r14 = MEM_HU(ctx->r6, 0X0);
    // 0x800D535C: sh          $t6, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r14;
    // 0x800D5360: sw          $zero, 0x0($sp)
    MEM_W(0X0, ctx->r29) = 0;
L_800D5364:
    // 0x800D5364: lw          $t7, 0x0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X0);
    // 0x800D5368: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800D536C: lhu         $t9, 0x0($t8)
    ctx->r25 = MEM_HU(ctx->r24, 0X0);
    // 0x800D5370: sh          $t9, 0x6($sp)
    MEM_H(0X6, ctx->r29) = ctx->r25;
    // 0x800D5374: lhu         $t0, 0x0($a1)
    ctx->r8 = MEM_HU(ctx->r5, 0X0);
    // 0x800D5378: addu        $t1, $t0, $t9
    ctx->r9 = ADD32(ctx->r8, ctx->r25);
    // 0x800D537C: sh          $t1, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r9;
    // 0x800D5380: lhu         $t3, 0x6($sp)
    ctx->r11 = MEM_HU(ctx->r29, 0X6);
    // 0x800D5384: lhu         $t2, 0x0($a2)
    ctx->r10 = MEM_HU(ctx->r6, 0X0);
    // 0x800D5388: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x800D538C: addu        $t5, $t2, $t4
    ctx->r13 = ADD32(ctx->r10, ctx->r12);
    // 0x800D5390: sh          $t5, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r13;
    // 0x800D5394: lw          $t6, 0x0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X0);
    // 0x800D5398: addiu       $t7, $t6, 0x2
    ctx->r15 = ADD32(ctx->r14, 0X2);
    // 0x800D539C: sltiu       $at, $t7, 0x1C
    ctx->r1 = ctx->r15 < 0X1C ? 1 : 0;
    // 0x800D53A0: bne         $at, $zero, L_800D5364
    if (ctx->r1 != 0) {
        // 0x800D53A4: sw          $t7, 0x0($sp)
        MEM_W(0X0, ctx->r29) = ctx->r15;
            goto L_800D5364;
    }
    // 0x800D53A4: sw          $t7, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r15;
    // 0x800D53A8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800D53AC: jr          $ra
    // 0x800D53B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    return;
    // 0x800D53B0: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
;}
RECOMP_FUNC void get_race_countdown(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001139C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800113A0: lw          $v0, -0x5250($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X5250);
    // 0x800113A4: jr          $ra
    // 0x800113A8: nop

    return;
    // 0x800113A8: nop

;}
RECOMP_FUNC void lensflare_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AC850: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800AC854: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800AC858: jr          $ra
    // 0x800AC85C: sw          $t6, 0x2A84($at)
    MEM_W(0X2A84, ctx->r1) = ctx->r14;
    return;
    // 0x800AC85C: sw          $t6, 0x2A84($at)
    MEM_W(0X2A84, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void obj_wave_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BE654: addiu       $sp, $sp, -0xE8
    ctx->r29 = ADD32(ctx->r29, -0XE8);
    // 0x800BE658: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BE65C: lw          $t6, 0x3040($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3040);
    // 0x800BE660: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800BE664: mtc1        $a2, $f24
    ctx->f24.u32l = ctx->r6;
    // 0x800BE668: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x800BE66C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BE670: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BE674: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BE678: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800BE67C: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BE680: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800BE684: sw          $a0, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r4;
    // 0x800BE688: sw          $a1, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->r5;
    // 0x800BE68C: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x800BE690: beq         $t6, $zero, L_800BEE8C
    if (ctx->r14 == 0) {
        // 0x800BE694: or          $t2, $zero, $zero
        ctx->r10 = 0 | 0;
            goto L_800BEE8C;
    }
    // 0x800BE694: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x800BE698: bltz        $a0, L_800BEE8C
    if (SIGNED(ctx->r4) < 0) {
        // 0x800BE69C: lui         $t7, 0x8013
        ctx->r15 = S32(0X8013 << 16);
            goto L_800BEE8C;
    }
    // 0x800BE69C: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BE6A0: lw          $t7, -0x5F20($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X5F20);
    // 0x800BE6A4: lui         $a1, 0xFF
    ctx->r5 = S32(0XFF << 16);
    // 0x800BE6A8: slt         $at, $a0, $t7
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BE6AC: beq         $at, $zero, L_800BEE8C
    if (ctx->r1 == 0) {
        // 0x800BE6B0: lui         $a0, 0x8013
        ctx->r4 = S32(0X8013 << 16);
            goto L_800BEE8C;
    }
    // 0x800BE6B0: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BE6B4: lw          $a0, -0x6018($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6018);
    // 0x800BE6B8: ori         $a1, $a1, 0xFFFF
    ctx->r5 = ctx->r5 | 0XFFFF;
    // 0x800BE6BC: sra         $t8, $a0, 1
    ctx->r24 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800BE6C0: addiu       $a0, $t8, 0xE
    ctx->r4 = ADD32(ctx->r24, 0XE);
    // 0x800BE6C4: sw          $a2, 0xE8($sp)
    MEM_W(0XE8, ctx->r29) = ctx->r6;
    // 0x800BE6C8: jal         0x80070C9C
    // 0x800BE6CC: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    mempool_alloc_safe(rdram, ctx);
        goto after_0;
    // 0x800BE6CC: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    after_0:
    // 0x800BE6D0: lw          $ra, 0xE8($sp)
    ctx->r31 = MEM_W(ctx->r29, 0XE8);
    // 0x800BE6D4: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800BE6D8: addiu       $t5, $t5, 0x30D8
    ctx->r13 = ADD32(ctx->r13, 0X30D8);
    // 0x800BE6DC: sll         $t1, $ra, 3
    ctx->r9 = S32(ctx->r31 << 3);
    // 0x800BE6E0: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x800BE6E4: subu        $t1, $t1, $ra
    ctx->r9 = SUB32(ctx->r9, ctx->r31);
    // 0x800BE6E8: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x800BE6EC: addu        $t6, $t9, $t1
    ctx->r14 = ADD32(ctx->r25, ctx->r9);
    // 0x800BE6F0: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x800BE6F4: lh          $t0, 0xA6($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA6);
    // 0x800BE6F8: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800BE6FC: sb          $zero, 0x2($v0)
    MEM_B(0X2, ctx->r2) = 0;
    // 0x800BE700: sb          $t8, 0x3($v0)
    MEM_B(0X3, ctx->r2) = ctx->r24;
    // 0x800BE704: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800BE708: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BE70C: sh          $t7, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r15;
    // 0x800BE710: lw          $t9, -0x6018($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X6018);
    // 0x800BE714: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BE718: sh          $t9, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r25;
    // 0x800BE71C: lw          $t6, 0x317C($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X317C);
    // 0x800BE720: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE724: multu       $ra, $t6
    result = U64(U32(ctx->r31)) * U64(U32(ctx->r14)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE728: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BE72C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE730: lwc1        $f20, -0x5F44($at)
    ctx->f20.u32l = MEM_W(ctx->r1, -0X5F44);
    // 0x800BE734: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE738: lwc1        $f22, -0x5F48($at)
    ctx->f22.u32l = MEM_W(ctx->r1, -0X5F48);
    // 0x800BE73C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE740: lwc1        $f4, -0x5FF4($at)
    ctx->f4.u32l = MEM_W(ctx->r1, -0X5FF4);
    // 0x800BE744: lui         $at, 0x42FE
    ctx->r1 = S32(0X42FE << 16);
    // 0x800BE748: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BE74C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BE750: lw          $t8, -0x6010($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6010);
    // 0x800BE754: sub.s       $f6, $f12, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f12.fl - ctx->f4.fl;
    // 0x800BE758: mflo        $t7
    ctx->r15 = lo;
    // 0x800BE75C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800BE760: sw          $t7, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r15;
    // 0x800BE764: beq         $t8, $zero, L_800BE794
    if (ctx->r24 == 0) {
        // 0x800BE768: div.s       $f2, $f6, $f8
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_800BE794;
    }
    // 0x800BE768: div.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800BE76C: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BE770: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x800BE774: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800BE778: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x800BE77C: lw          $t4, -0x6038($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6038);
    // 0x800BE780: nop

    // 0x800BE784: sll         $t9, $t4, 1
    ctx->r25 = S32(ctx->r12 << 1);
    // 0x800BE788: mul.s       $f22, $f22, $f0
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f22.fl = MUL_S(ctx->f22.fl, ctx->f0.fl);
    // 0x800BE78C: b           L_800BE7A4
    // 0x800BE790: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
        goto L_800BE7A4;
    // 0x800BE790: addiu       $t4, $t9, 0x1
    ctx->r12 = ADD32(ctx->r25, 0X1);
L_800BE794:
    // 0x800BE794: lui         $t4, 0x8013
    ctx->r12 = S32(0X8013 << 16);
    // 0x800BE798: lw          $t4, -0x6038($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X6038);
    // 0x800BE79C: nop

    // 0x800BE7A0: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
L_800BE7A4:
    // 0x800BE7A4: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x800BE7A8: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800BE7AC: addu        $a3, $t6, $t1
    ctx->r7 = ADD32(ctx->r14, ctx->r9);
    // 0x800BE7B0: lh          $t7, 0x4($a3)
    ctx->r15 = MEM_H(ctx->r7, 0X4);
    // 0x800BE7B4: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800BE7B8: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x800BE7BC: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE7C0: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE7C4: sub.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800BE7C8: c.lt.s      $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f16.fl < ctx->f14.fl;
    // 0x800BE7CC: nop

    // 0x800BE7D0: bc1f        L_800BE7E0
    if (!c1cs) {
        // 0x800BE7D4: nop
    
            goto L_800BE7E0;
    }
    // 0x800BE7D4: nop

    // 0x800BE7D8: b           L_800BE810
    // 0x800BE7DC: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
        goto L_800BE810;
    // 0x800BE7DC: mov.s       $f16, $f14
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 14);
    ctx->f16.fl = ctx->f14.fl;
L_800BE7E0:
    // 0x800BE7E0: lwc1        $f0, -0x5F60($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5F60);
    // 0x800BE7E4: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE7E8: c.le.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl <= ctx->f16.fl;
    // 0x800BE7EC: swc1        $f16, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f16.u32l;
    // 0x800BE7F0: bc1f        L_800BE810
    if (!c1cs) {
        // 0x800BE7F4: nop
    
            goto L_800BE810;
    }
    // 0x800BE7F4: nop

    // 0x800BE7F8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BE7FC: nop

    // 0x800BE800: sub.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f0.fl - ctx->f6.fl;
    // 0x800BE804: swc1        $f8, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f8.u32l;
    // 0x800BE808: lwc1        $f16, 0xEC($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800BE80C: nop

L_800BE810:
    // 0x800BE810: lh          $t8, 0x8($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X8);
    // 0x800BE814: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BE818: mtc1        $t8, $f10
    ctx->f10.u32l = ctx->r24;
    // 0x800BE81C: div.s       $f8, $f16, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = DIV_S(ctx->f16.fl, ctx->f22.fl);
    // 0x800BE820: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800BE824: sub.s       $f24, $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f4.fl;
    // 0x800BE828: c.lt.s      $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f24.fl < ctx->f14.fl;
    // 0x800BE82C: nop

    // 0x800BE830: bc1f        L_800BE840
    if (!c1cs) {
        // 0x800BE834: nop
    
            goto L_800BE840;
    }
    // 0x800BE834: nop

    // 0x800BE838: b           L_800BE864
    // 0x800BE83C: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
        goto L_800BE864;
    // 0x800BE83C: mov.s       $f24, $f14
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 14);
    ctx->f24.fl = ctx->f14.fl;
L_800BE840:
    // 0x800BE840: lwc1        $f0, -0x5F5C($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5F5C);
    // 0x800BE844: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800BE848: c.le.s      $f0, $f24
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f0.fl <= ctx->f24.fl;
    // 0x800BE84C: nop

    // 0x800BE850: bc1f        L_800BE864
    if (!c1cs) {
        // 0x800BE854: nop
    
            goto L_800BE864;
    }
    // 0x800BE854: nop

    // 0x800BE858: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BE85C: nop

    // 0x800BE860: sub.s       $f24, $f0, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f0.fl - ctx->f6.fl;
L_800BE864:
    // 0x800BE864: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BE868: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800BE86C: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BE870: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE874: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE878: nop

    // 0x800BE87C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BE880: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BE884: mfc1        $a1, $f10
    ctx->r5 = (int32_t)ctx->f10.u32l;
    // 0x800BE888: div.s       $f4, $f24, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = DIV_S(ctx->f24.fl, ctx->f20.fl);
    // 0x800BE88C: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800BE890: sw          $a1, 0xC4($sp)
    MEM_W(0XC4, ctx->r29) = ctx->r5;
    // 0x800BE894: sh          $ra, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r31;
    // 0x800BE898: sh          $a1, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r5;
    // 0x800BE89C: addiu       $ra, $sp, 0x50
    ctx->r31 = ADD32(ctx->r29, 0X50);
    // 0x800BE8A0: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x800BE8A4: nop

    // 0x800BE8A8: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x800BE8AC: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BE8B0: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BE8B4: nop

    // 0x800BE8B8: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800BE8BC: mfc1        $t3, $f6
    ctx->r11 = (int32_t)ctx->f6.u32l;
    // 0x800BE8C0: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x800BE8C4: mtc1        $t3, $f6
    ctx->f6.u32l = ctx->r11;
    // 0x800BE8C8: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BE8CC: sh          $t3, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r11;
    // 0x800BE8D0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x800BE8D4: mul.s       $f4, $f10, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800BE8D8: addu        $a3, $t7, $t1
    ctx->r7 = ADD32(ctx->r15, ctx->r9);
    // 0x800BE8DC: lh          $t8, 0x12($a3)
    ctx->r24 = MEM_H(ctx->r7, 0X12);
    // 0x800BE8E0: lw          $t9, 0xC4($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XC4);
    // 0x800BE8E4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800BE8E8: lw          $v1, -0x6034($v1)
    ctx->r3 = MEM_W(ctx->r3, -0X6034);
    // 0x800BE8EC: addu        $a0, $t8, $t9
    ctx->r4 = ADD32(ctx->r24, ctx->r25);
    // 0x800BE8F0: mul.s       $f10, $f8, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BE8F4: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BE8F8: addiu       $t5, $sp, 0x80
    ctx->r13 = ADD32(ctx->r29, 0X80);
    // 0x800BE8FC: sub.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800BE900: bne         $at, $zero, L_800BE918
    if (ctx->r1 != 0) {
        // 0x800BE904: sub.s       $f24, $f24, $f10
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f10.fl;
            goto L_800BE918;
    }
    // 0x800BE904: sub.s       $f24, $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f24.fl = ctx->f24.fl - ctx->f10.fl;
L_800BE908:
    // 0x800BE908: subu        $a0, $a0, $v1
    ctx->r4 = SUB32(ctx->r4, ctx->r3);
    // 0x800BE90C: slt         $at, $a0, $v1
    ctx->r1 = SIGNED(ctx->r4) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BE910: beq         $at, $zero, L_800BE908
    if (ctx->r1 == 0) {
        // 0x800BE914: nop
    
            goto L_800BE908;
    }
    // 0x800BE914: nop

L_800BE918:
    // 0x800BE918: lh          $t6, 0x10($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X10);
    // 0x800BE91C: addiu       $a2, $a0, 0x1
    ctx->r6 = ADD32(ctx->r4, 0X1);
    // 0x800BE920: addu        $v0, $t6, $t3
    ctx->r2 = ADD32(ctx->r14, ctx->r11);
    // 0x800BE924: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BE928: bne         $at, $zero, L_800BE940
    if (ctx->r1 != 0) {
        // 0x800BE92C: nop
    
            goto L_800BE940;
    }
    // 0x800BE92C: nop

L_800BE930:
    // 0x800BE930: subu        $v0, $v0, $v1
    ctx->r2 = SUB32(ctx->r2, ctx->r3);
    // 0x800BE934: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BE938: beq         $at, $zero, L_800BE930
    if (ctx->r1 == 0) {
        // 0x800BE93C: nop
    
            goto L_800BE930;
    }
    // 0x800BE93C: nop

L_800BE940:
    // 0x800BE940: c.eq.s      $f24, $f20
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f24.fl == ctx->f20.fl;
    // 0x800BE944: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x800BE948: bc1t        L_800BE974
    if (c1cs) {
        // 0x800BE94C: slt         $at, $a2, $v1
        ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_800BE974;
    }
    // 0x800BE94C: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BE950: sub.s       $f4, $f20, $f24
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f4.fl = ctx->f20.fl - ctx->f24.fl;
    // 0x800BE954: nop

    // 0x800BE958: div.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800BE95C: mul.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f22.fl);
    // 0x800BE960: c.lt.s      $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f16.fl < ctx->f8.fl;
    // 0x800BE964: nop

    // 0x800BE968: bc1f        L_800BE974
    if (!c1cs) {
        // 0x800BE96C: nop
    
            goto L_800BE974;
    }
    // 0x800BE96C: nop

    // 0x800BE970: addiu       $t1, $zero, 0x1
    ctx->r9 = ADD32(0, 0X1);
L_800BE974:
    // 0x800BE974: beq         $t1, $zero, L_800BEA0C
    if (ctx->r9 == 0) {
        // 0x800BE978: addiu       $a1, $v0, 0x1
        ctx->r5 = ADD32(ctx->r2, 0X1);
            goto L_800BEA0C;
    }
    // 0x800BE978: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x800BE97C: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE980: addiu       $a1, $v0, 0x1
    ctx->r5 = ADD32(ctx->r2, 0X1);
    // 0x800BE984: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BE988: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800BE98C: mflo        $a2
    ctx->r6 = lo;
    // 0x800BE990: addu        $a3, $a2, $a0
    ctx->r7 = ADD32(ctx->r6, ctx->r4);
    // 0x800BE994: bne         $at, $zero, L_800BE9A4
    if (ctx->r1 != 0) {
        // 0x800BE998: sw          $a3, 0x80($sp)
        MEM_W(0X80, ctx->r29) = ctx->r7;
            goto L_800BE9A4;
    }
    // 0x800BE998: sw          $a3, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r7;
    // 0x800BE99C: b           L_800BE9B4
    // 0x800BE9A0: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
        goto L_800BE9B4;
    // 0x800BE9A0: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
L_800BE9A4:
    // 0x800BE9A4: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE9A8: mflo        $t7
    ctx->r15 = lo;
    // 0x800BE9AC: addu        $t8, $t7, $a0
    ctx->r24 = ADD32(ctx->r15, ctx->r4);
    // 0x800BE9B0: sw          $t8, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r24;
L_800BE9B4:
    // 0x800BE9B4: slt         $at, $t9, $v1
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BE9B8: bne         $at, $zero, L_800BE9C8
    if (ctx->r1 != 0) {
        // 0x800BE9BC: addiu       $v0, $a3, 0x1
        ctx->r2 = ADD32(ctx->r7, 0X1);
            goto L_800BE9C8;
    }
    // 0x800BE9BC: addiu       $v0, $a3, 0x1
    ctx->r2 = ADD32(ctx->r7, 0X1);
    // 0x800BE9C0: b           L_800BE9CC
    // 0x800BE9C4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
        goto L_800BE9CC;
    // 0x800BE9C4: sw          $a2, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r6;
L_800BE9C8:
    // 0x800BE9C8: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
L_800BE9CC:
    // 0x800BE9CC: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE9D0: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x800BE9D4: lw          $t6, 0xB0($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XB0);
    // 0x800BE9D8: lw          $t7, 0xC4($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XC4);
    // 0x800BE9DC: swc1        $f14, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f14.u32l;
    // 0x800BE9E0: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800BE9E4: mflo        $t8
    ctx->r24 = lo;
    // 0x800BE9E8: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x800BE9EC: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x800BE9F0: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BE9F4: sw          $v1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r3;
    // 0x800BE9F8: sw          $t8, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r24;
    // 0x800BE9FC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEA00: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEA04: b           L_800BEAD0
    // 0x800BEA08: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
        goto L_800BEAD0;
    // 0x800BEA08: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
L_800BEA0C:
    // 0x800BEA0C: bne         $at, $zero, L_800BEA28
    if (ctx->r1 != 0) {
        // 0x800BEA10: nop
    
            goto L_800BEA28;
    }
    // 0x800BEA10: nop

    // 0x800BEA14: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEA18: mflo        $t9
    ctx->r25 = lo;
    // 0x800BEA1C: sw          $t9, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r25;
    // 0x800BEA20: b           L_800BEA40
    // 0x800BEA24: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
        goto L_800BEA40;
    // 0x800BEA24: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_800BEA28:
    // 0x800BEA28: multu       $v0, $v1
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEA2C: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEA30: addu        $t7, $a0, $t6
    ctx->r15 = ADD32(ctx->r4, ctx->r14);
    // 0x800BEA34: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BEA38: sw          $t8, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r24;
    // 0x800BEA3C: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
L_800BEA40:
    // 0x800BEA40: bne         $at, $zero, L_800BEA50
    if (ctx->r1 != 0) {
        // 0x800BEA44: or          $v0, $a2, $zero
        ctx->r2 = ctx->r6 | 0;
            goto L_800BEA50;
    }
    // 0x800BEA44: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
    // 0x800BEA48: b           L_800BEA60
    // 0x800BEA4C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
        goto L_800BEA60;
    // 0x800BEA4C: sw          $a0, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r4;
L_800BEA50:
    // 0x800BEA50: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEA54: mflo        $t9
    ctx->r25 = lo;
    // 0x800BEA58: addu        $t6, $t9, $a0
    ctx->r14 = ADD32(ctx->r25, ctx->r4);
    // 0x800BEA5C: sw          $t6, 0x84($sp)
    MEM_W(0X84, ctx->r29) = ctx->r14;
L_800BEA60:
    // 0x800BEA60: slt         $at, $a2, $v1
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEA64: bne         $at, $zero, L_800BEA74
    if (ctx->r1 != 0) {
        // 0x800BEA68: nop
    
            goto L_800BEA74;
    }
    // 0x800BEA68: nop

    // 0x800BEA6C: b           L_800BEA74
    // 0x800BEA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800BEA74;
    // 0x800BEA70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800BEA74:
    // 0x800BEA74: slt         $at, $a1, $v1
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800BEA78: beq         $at, $zero, L_800BEA90
    if (ctx->r1 == 0) {
        // 0x800BEA7C: sw          $v0, 0x88($sp)
        MEM_W(0X88, ctx->r29) = ctx->r2;
            goto L_800BEA90;
    }
    // 0x800BEA7C: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
    // 0x800BEA80: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEA84: mflo        $t7
    ctx->r15 = lo;
    // 0x800BEA88: addu        $v0, $v0, $t7
    ctx->r2 = ADD32(ctx->r2, ctx->r15);
    // 0x800BEA8C: sw          $v0, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->r2;
L_800BEA90:
    // 0x800BEA90: multu       $t3, $t4
    result = U64(U32(ctx->r11)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEA94: lw          $t8, 0xC4($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XC4);
    // 0x800BEA98: lw          $t9, 0xB0($sp)
    ctx->r25 = MEM_W(ctx->r29, 0XB0);
    // 0x800BEA9C: swc1        $f22, 0xE4($sp)
    MEM_W(0XE4, ctx->r29) = ctx->f22.u32l;
    // 0x800BEAA0: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x800BEAA4: addiu       $t9, $t3, 0x1
    ctx->r25 = ADD32(ctx->r11, 0X1);
    // 0x800BEAA8: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEAAC: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEAB0: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800BEAB4: multu       $t9, $t4
    result = U64(U32(ctx->r25)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BEAB8: sw          $t8, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r24;
    // 0x800BEABC: mflo        $t6
    ctx->r14 = lo;
    // 0x800BEAC0: addu        $v1, $v0, $t6
    ctx->r3 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEAC4: addiu       $t7, $v1, 0x1
    ctx->r15 = ADD32(ctx->r3, 0X1);
    // 0x800BEAC8: sw          $v1, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r3;
    // 0x800BEACC: sw          $t7, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r15;
L_800BEAD0:
    // 0x800BEAD0: lui         $t3, 0x800E
    ctx->r11 = S32(0X800E << 16);
    // 0x800BEAD4: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BEAD8: sw          $t1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r9;
    // 0x800BEADC: lw          $t4, 0x3178($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3178);
    // 0x800BEAE0: lw          $t3, 0x3044($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X3044);
    // 0x800BEAE4: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x800BEAE8: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BEAEC: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
L_800BEAF0:
    // 0x800BEAF0: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x800BEAF4: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800BEAF8: sll         $t9, $a3, 3
    ctx->r25 = S32(ctx->r7 << 3);
    // 0x800BEAFC: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BEB00: addu        $a0, $t3, $t8
    ctx->r4 = ADD32(ctx->r11, ctx->r24);
    // 0x800BEB04: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x800BEB08: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x800BEB0C: addu        $a1, $ra, $v0
    ctx->r5 = ADD32(ctx->r31, ctx->r2);
    // 0x800BEB10: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800BEB14: lh          $t6, 0x2($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X2);
    // 0x800BEB18: swc1        $f12, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f12.u32l;
    // 0x800BEB1C: addu        $t7, $sp, $v0
    ctx->r15 = ADD32(ctx->r29, ctx->r2);
    // 0x800BEB20: sw          $t6, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r14;
    // 0x800BEB24: lw          $t7, 0x5C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5C);
    // 0x800BEB28: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BEB2C: addu        $t8, $t7, $t4
    ctx->r24 = ADD32(ctx->r15, ctx->r12);
    // 0x800BEB30: lbu         $a2, 0x0($t8)
    ctx->r6 = MEM_BU(ctx->r24, 0X0);
    // 0x800BEB34: sll         $t9, $a3, 16
    ctx->r25 = S32(ctx->r7 << 16);
    // 0x800BEB38: slti        $at, $a2, 0x7F
    ctx->r1 = SIGNED(ctx->r6) < 0X7F ? 1 : 0;
    // 0x800BEB3C: beq         $at, $zero, L_800BEB68
    if (ctx->r1 == 0) {
        // 0x800BEB40: sra         $a3, $t9, 16
        ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
            goto L_800BEB68;
    }
    // 0x800BEB40: sra         $a3, $t9, 16
    ctx->r7 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800BEB44: mtc1        $a2, $f4
    ctx->f4.u32l = ctx->r6;
    // 0x800BEB48: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BEB4C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BEB50: lwc1        $f10, -0x5FF4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X5FF4);
    // 0x800BEB54: mul.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BEB58: lwc1        $f6, 0x0($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X0);
    // 0x800BEB5C: add.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f8.fl;
    // 0x800BEB60: mul.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800BEB64: swc1        $f10, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->f10.u32l;
L_800BEB68:
    // 0x800BEB68: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800BEB6C: bne         $at, $zero, L_800BEAF0
    if (ctx->r1 != 0) {
        // 0x800BEB70: sll         $v0, $a3, 2
        ctx->r2 = S32(ctx->r7 << 2);
            goto L_800BEAF0;
    }
    // 0x800BEB70: sll         $v0, $a3, 2
    ctx->r2 = S32(ctx->r7 << 2);
    // 0x800BEB74: lui         $t7, 0x8013
    ctx->r15 = S32(0X8013 << 16);
    // 0x800BEB78: lw          $t7, -0x6010($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X6010);
    // 0x800BEB7C: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800BEB80: beq         $t7, $zero, L_800BEBD0
    if (ctx->r15 == 0) {
        // 0x800BEB84: lui         $t8, 0x8013
        ctx->r24 = S32(0X8013 << 16);
            goto L_800BEBD0;
    }
    // 0x800BEB84: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BEB88: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800BEB8C: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800BEB90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BEB94: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800BEB98: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800BEB9C: lwc1        $f8, 0x54($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800BEBA0: nop

    // 0x800BEBA4: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800BEBA8: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800BEBAC: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800BEBB0: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800BEBB4: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800BEBB8: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x800BEBBC: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800BEBC0: mul.d       $f4, $f6, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x800BEBC4: swc1        $f10, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f10.u32l;
    // 0x800BEBC8: cvt.s.d     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f10.fl = CVT_S_D(ctx->f4.d);
    // 0x800BEBCC: swc1        $f10, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->f10.u32l;
L_800BEBD0:
    // 0x800BEBD0: lw          $t8, -0x6018($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X6018);
    // 0x800BEBD4: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800BEBD8: sra         $t9, $t8, 1
    ctx->r25 = S32(SIGNED(ctx->r24) >> 1);
    // 0x800BEBDC: blez        $t9, L_800BEE90
    if (SIGNED(ctx->r25) <= 0) {
        // 0x800BEBE0: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_800BEE90;
    }
    // 0x800BEBE0: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BEBE4: mul.s       $f18, $f20, $f22
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f22.fl);
    // 0x800BEBE8: swc1        $f16, 0xEC($sp)
    MEM_W(0XEC, ctx->r29) = ctx->f16.u32l;
    // 0x800BEBEC: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800BEBF0: swc1        $f8, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f8.u32l;
    // 0x800BEBF4: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
L_800BEBF8:
    // 0x800BEBF8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800BEBFC: lw          $v0, 0x3040($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3040);
    // 0x800BEC00: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x800BEC04: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BEC08: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800BEC0C: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BEC10: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BEC14: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEC18: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BEC1C: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x800BEC20: lw          $t7, 0x74($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X74);
    // 0x800BEC24: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800BEC28: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BEC2C: addu        $t6, $v0, $t9
    ctx->r14 = ADD32(ctx->r2, ctx->r25);
    // 0x800BEC30: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800BEC34: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x800BEC38: lwc1        $f6, 0x0($t6)
    ctx->f6.u32l = MEM_W(ctx->r14, 0X0);
    // 0x800BEC3C: addu        $t9, $v0, $t8
    ctx->r25 = ADD32(ctx->r2, ctx->r24);
    // 0x800BEC40: mul.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BEC44: lwc1        $f4, 0x0($t9)
    ctx->f4.u32l = MEM_W(ctx->r25, 0X0);
    // 0x800BEC48: lw          $t6, 0x78($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X78);
    // 0x800BEC4C: lw          $t9, 0x7C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X7C);
    // 0x800BEC50: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800BEC54: lwc1        $f10, 0x54($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X54);
    // 0x800BEC58: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BEC5C: addu        $t8, $v0, $t7
    ctx->r24 = ADD32(ctx->r2, ctx->r15);
    // 0x800BEC60: sll         $t6, $t9, 2
    ctx->r14 = S32(ctx->r25 << 2);
    // 0x800BEC64: mul.s       $f12, $f10, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = MUL_S(ctx->f10.fl, ctx->f8.fl);
    // 0x800BEC68: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x800BEC6C: lwc1        $f4, 0x0($t7)
    ctx->f4.u32l = MEM_W(ctx->r15, 0X0);
    // 0x800BEC70: lwc1        $f6, 0x0($t8)
    ctx->f6.u32l = MEM_W(ctx->r24, 0X0);
    // 0x800BEC74: lwc1        $f8, 0x58($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X58);
    // 0x800BEC78: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BEC7C: lw          $t8, 0xAC($sp)
    ctx->r24 = MEM_W(ctx->r29, 0XAC);
    // 0x800BEC80: mul.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = MUL_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800BEC84: beq         $t8, $zero, L_800BECA4
    if (ctx->r24 == 0) {
        // 0x800BEC88: nop
    
            goto L_800BECA4;
    }
    // 0x800BEC88: nop

    // 0x800BEC8C: sub.s       $f6, $f16, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800BEC90: mul.s       $f2, $f6, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f6.fl, ctx->f20.fl);
    // 0x800BEC94: sub.s       $f4, $f16, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f12.fl;
    // 0x800BEC98: mul.s       $f14, $f4, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f4.fl, ctx->f22.fl);
    // 0x800BEC9C: b           L_800BECB8
    // 0x800BECA0: nop

        goto L_800BECB8;
    // 0x800BECA0: nop

L_800BECA4:
    // 0x800BECA4: sub.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f12.fl - ctx->f0.fl;
    // 0x800BECA8: mul.s       $f2, $f8, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = MUL_S(ctx->f8.fl, ctx->f20.fl);
    // 0x800BECAC: sub.s       $f10, $f16, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f16.fl - ctx->f0.fl;
    // 0x800BECB0: mul.s       $f14, $f10, $f22
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f14.fl = MUL_S(ctx->f10.fl, ctx->f22.fl);
    // 0x800BECB4: nop

L_800BECB8:
    // 0x800BECB8: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800BECBC: lwc1        $f4, 0x40($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800BECC0: sh          $a3, 0xA2($sp)
    MEM_H(0XA2, ctx->r29) = ctx->r7;
    // 0x800BECC4: sh          $t0, 0xA6($sp)
    MEM_H(0XA6, ctx->r29) = ctx->r8;
    // 0x800BECC8: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800BECCC: add.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800BECD0: sw          $t2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r10;
    // 0x800BECD4: swc1        $f2, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->f2.u32l;
    // 0x800BECD8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800BECDC: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    // 0x800BECE0: swc1        $f16, 0xE0($sp)
    MEM_W(0XE0, ctx->r29) = ctx->f16.u32l;
    // 0x800BECE4: jal         0x800C9AD0
    // 0x800BECE8: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x800BECE8: swc1        $f18, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f18.u32l;
    after_1:
    // 0x800BECEC: lwc1        $f2, 0x9C($sp)
    ctx->f2.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x800BECF0: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x800BECF4: div.s       $f2, $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f2.fl = DIV_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800BECF8: lwc1        $f18, 0x44($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X44);
    // 0x800BECFC: lwc1        $f6, 0xEC($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XEC);
    // 0x800BED00: lwc1        $f16, 0xE0($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0XE0);
    // 0x800BED04: lui         $at, 0x4180
    ctx->r1 = S32(0X4180 << 16);
    // 0x800BED08: lh          $t0, 0xA6($sp)
    ctx->r8 = MEM_H(ctx->r29, 0XA6);
    // 0x800BED0C: lh          $a3, 0xA2($sp)
    ctx->r7 = MEM_H(ctx->r29, 0XA2);
    // 0x800BED10: lw          $t2, 0x4C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X4C);
    // 0x800BED14: addiu       $t1, $sp, 0x68
    ctx->r9 = ADD32(ctx->r29, 0X68);
    // 0x800BED18: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BED1C: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800BED20: negu        $t6, $t0
    ctx->r14 = SUB32(0, ctx->r8);
    // 0x800BED24: div.s       $f14, $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f14.fl = DIV_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800BED28: mul.s       $f4, $f2, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x800BED2C: lwc1        $f6, 0xE4($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0XE4);
    // 0x800BED30: div.s       $f12, $f18, $f0
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f0.fl);
    // 0x800BED34: mul.s       $f8, $f14, $f24
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f8.fl = MUL_S(ctx->f14.fl, ctx->f24.fl);
    // 0x800BED38: add.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BED3C: mul.s       $f4, $f6, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x800BED40: nop

    // 0x800BED44: mul.s       $f8, $f16, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f12.fl);
    // 0x800BED48: add.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f8.fl;
    // 0x800BED4C: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800BED50: sub.s       $f4, $f10, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800BED54: mul.s       $f10, $f4, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x800BED58: nop

    // 0x800BED5C: div.s       $f6, $f10, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f10.fl, ctx->f12.fl);
    // 0x800BED60: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x800BED64: nop

    // 0x800BED68: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x800BED6C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BED70: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BED74: nop

    // 0x800BED78: cvt.w.s     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BED7C: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x800BED80: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x800BED84: negu        $v0, $v0
    ctx->r2 = SUB32(0, ctx->r2);
    // 0x800BED88: slt         $at, $v0, $t0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800BED8C: beq         $at, $zero, L_800BEDA0
    if (ctx->r1 == 0) {
        // 0x800BED90: or          $a2, $v0, $zero
        ctx->r6 = ctx->r2 | 0;
            goto L_800BEDA0;
    }
    // 0x800BED90: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x800BED94: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800BED98: beq         $at, $zero, L_800BEE10
    if (ctx->r1 == 0) {
        // 0x800BED9C: nop
    
            goto L_800BEE10;
    }
    // 0x800BED9C: nop

L_800BEDA0:
    // 0x800BEDA0: addu        $t0, $t0, $t0
    ctx->r8 = ADD32(ctx->r8, ctx->r8);
    // 0x800BEDA4: sll         $t7, $t0, 16
    ctx->r15 = S32(ctx->r8 << 16);
    // 0x800BEDA8: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800BEDAC: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800BEDB0: sll         $t9, $v1, 16
    ctx->r25 = S32(ctx->r3 << 16);
    // 0x800BEDB4: slt         $at, $a2, $t8
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x800BEDB8: or          $t0, $t8, $zero
    ctx->r8 = ctx->r24 | 0;
    // 0x800BEDBC: beq         $at, $zero, L_800BEDA0
    if (ctx->r1 == 0) {
        // 0x800BEDC0: sra         $v1, $t9, 16
        ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
            goto L_800BEDA0;
    }
    // 0x800BEDC0: sra         $v1, $t9, 16
    ctx->r3 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800BEDC4: negu        $t7, $t8
    ctx->r15 = SUB32(0, ctx->r24);
    // 0x800BEDC8: slt         $at, $a2, $t7
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x800BEDCC: bne         $at, $zero, L_800BEDA0
    if (ctx->r1 != 0) {
        // 0x800BEDD0: nop
    
            goto L_800BEDA0;
    }
    // 0x800BEDD0: nop

    // 0x800BEDD4: blez        $a3, L_800BEE00
    if (SIGNED(ctx->r7) <= 0) {
        // 0x800BEDD8: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_800BEE00;
    }
    // 0x800BEDD8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
L_800BEDDC:
    // 0x800BEDDC: addu        $v0, $t2, $a1
    ctx->r2 = ADD32(ctx->r10, ctx->r5);
    // 0x800BEDE0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BEDE4: lb          $t8, 0xE($v0)
    ctx->r24 = MEM_B(ctx->r2, 0XE);
    // 0x800BEDE8: sll         $t6, $a1, 16
    ctx->r14 = S32(ctx->r5 << 16);
    // 0x800BEDEC: sra         $a1, $t6, 16
    ctx->r5 = S32(SIGNED(ctx->r14) >> 16);
    // 0x800BEDF0: slt         $at, $a1, $a3
    ctx->r1 = SIGNED(ctx->r5) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x800BEDF4: srav        $t9, $t8, $v1
    ctx->r25 = S32(SIGNED(ctx->r24) >> (ctx->r3 & 31));
    // 0x800BEDF8: bne         $at, $zero, L_800BEDDC
    if (ctx->r1 != 0) {
        // 0x800BEDFC: sb          $t9, 0xE($v0)
        MEM_B(0XE, ctx->r2) = ctx->r25;
            goto L_800BEDDC;
    }
    // 0x800BEDFC: sb          $t9, 0xE($v0)
    MEM_B(0XE, ctx->r2) = ctx->r25;
L_800BEE00:
    // 0x800BEE00: lbu         $t8, 0x2($t2)
    ctx->r24 = MEM_BU(ctx->r10, 0X2);
    // 0x800BEE04: nop

    // 0x800BEE08: addu        $t9, $t8, $v1
    ctx->r25 = ADD32(ctx->r24, ctx->r3);
    // 0x800BEE0C: sb          $t9, 0x2($t2)
    MEM_B(0X2, ctx->r10) = ctx->r25;
L_800BEE10:
    // 0x800BEE10: lbu         $t6, 0x2($t2)
    ctx->r14 = MEM_BU(ctx->r10, 0X2);
    // 0x800BEE14: addu        $t8, $t2, $a3
    ctx->r24 = ADD32(ctx->r10, ctx->r7);
    // 0x800BEE18: srav        $t7, $a2, $t6
    ctx->r15 = S32(SIGNED(ctx->r6) >> (ctx->r14 & 31));
    // 0x800BEE1C: sb          $t7, 0xE($t8)
    MEM_B(0XE, ctx->r24) = ctx->r15;
    // 0x800BEE20: lw          $a0, -0x6018($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X6018);
    // 0x800BEE24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x800BEE28: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
L_800BEE2C:
    // 0x800BEE2C: addu        $v1, $t1, $t9
    ctx->r3 = ADD32(ctx->r9, ctx->r25);
    // 0x800BEE30: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800BEE34: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x800BEE38: addiu       $v0, $t6, 0x2
    ctx->r2 = ADD32(ctx->r14, 0X2);
    // 0x800BEE3C: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BEE40: bne         $at, $zero, L_800BEE5C
    if (ctx->r1 != 0) {
        // 0x800BEE44: sw          $v0, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r2;
            goto L_800BEE5C;
    }
    // 0x800BEE44: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_800BEE48:
    // 0x800BEE48: subu        $t8, $v0, $a0
    ctx->r24 = SUB32(ctx->r2, ctx->r4);
    // 0x800BEE4C: slt         $at, $t8, $a0
    ctx->r1 = SIGNED(ctx->r24) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x800BEE50: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800BEE54: beq         $at, $zero, L_800BEE48
    if (ctx->r1 == 0) {
        // 0x800BEE58: or          $v0, $t8, $zero
        ctx->r2 = ctx->r24 | 0;
            goto L_800BEE48;
    }
    // 0x800BEE58: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_800BEE5C:
    // 0x800BEE5C: sll         $t9, $a1, 16
    ctx->r25 = S32(ctx->r5 << 16);
    // 0x800BEE60: sra         $a1, $t9, 16
    ctx->r5 = S32(SIGNED(ctx->r25) >> 16);
    // 0x800BEE64: slti        $at, $a1, 0x6
    ctx->r1 = SIGNED(ctx->r5) < 0X6 ? 1 : 0;
    // 0x800BEE68: bne         $at, $zero, L_800BEE2C
    if (ctx->r1 != 0) {
        // 0x800BEE6C: sll         $t9, $a1, 2
        ctx->r25 = S32(ctx->r5 << 2);
            goto L_800BEE2C;
    }
    // 0x800BEE6C: sll         $t9, $a1, 2
    ctx->r25 = S32(ctx->r5 << 2);
    // 0x800BEE70: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800BEE74: sll         $t7, $a3, 16
    ctx->r15 = S32(ctx->r7 << 16);
    // 0x800BEE78: sra         $a3, $t7, 16
    ctx->r7 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800BEE7C: sra         $t9, $a0, 1
    ctx->r25 = S32(SIGNED(ctx->r4) >> 1);
    // 0x800BEE80: slt         $at, $a3, $t9
    ctx->r1 = SIGNED(ctx->r7) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800BEE84: bne         $at, $zero, L_800BEBF8
    if (ctx->r1 != 0) {
        // 0x800BEE88: lw          $t6, 0x68($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X68);
            goto L_800BEBF8;
    }
    // 0x800BEE88: lw          $t6, 0x68($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X68);
L_800BEE8C:
    // 0x800BEE8C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_800BEE90:
    // 0x800BEE90: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800BEE94: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BEE98: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BEE9C: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BEEA0: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BEEA4: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BEEA8: addiu       $sp, $sp, 0xE8
    ctx->r29 = ADD32(ctx->r29, 0XE8);
    // 0x800BEEAC: jr          $ra
    // 0x800BEEB0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
    return;
    // 0x800BEEB0: or          $v0, $t2, $zero
    ctx->r2 = ctx->r10 | 0;
;}
RECOMP_FUNC void __lookupVoice(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000A84C: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    // 0x8000A850: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x8000A854: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8000A858: andi        $t7, $a2, 0xFF
    ctx->r15 = ctx->r6 & 0XFF;
    // 0x8000A85C: or          $a2, $t7, $zero
    ctx->r6 = ctx->r15 | 0;
    // 0x8000A860: beq         $v1, $zero, L_8000A8C4
    if (ctx->r3 == 0) {
        // 0x8000A864: andi        $t6, $a1, 0xFF
        ctx->r14 = ctx->r5 & 0XFF;
            goto L_8000A8C4;
    }
    // 0x8000A864: andi        $t6, $a1, 0xFF
    ctx->r14 = ctx->r5 & 0XFF;
    // 0x8000A868: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    // 0x8000A86C: addiu       $a3, $zero, 0x4
    ctx->r7 = ADD32(0, 0X4);
    // 0x8000A870: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_8000A874:
    // 0x8000A874: lbu         $t8, 0x32($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X32);
    // 0x8000A878: nop

    // 0x8000A87C: bne         $v0, $t8, L_8000A8B4
    if (ctx->r2 != ctx->r24) {
        // 0x8000A880: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A880: nop

    // 0x8000A884: lbu         $t9, 0x31($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X31);
    // 0x8000A888: nop

    // 0x8000A88C: bne         $a2, $t9, L_8000A8B4
    if (ctx->r6 != ctx->r25) {
        // 0x8000A890: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A890: nop

    // 0x8000A894: lbu         $a0, 0x35($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X35);
    // 0x8000A898: nop

    // 0x8000A89C: beq         $a1, $a0, L_8000A8B4
    if (ctx->r5 == ctx->r4) {
        // 0x8000A8A0: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A8A0: nop

    // 0x8000A8A4: beq         $a3, $a0, L_8000A8B4
    if (ctx->r7 == ctx->r4) {
        // 0x8000A8A8: nop
    
            goto L_8000A8B4;
    }
    // 0x8000A8A8: nop

    // 0x8000A8AC: jr          $ra
    // 0x8000A8B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000A8B0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8000A8B4:
    // 0x8000A8B4: lw          $v1, 0x0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X0);
    // 0x8000A8B8: nop

    // 0x8000A8BC: bne         $v1, $zero, L_8000A874
    if (ctx->r3 != 0) {
        // 0x8000A8C0: nop
    
            goto L_8000A874;
    }
    // 0x8000A8C0: nop

L_8000A8C4:
    // 0x8000A8C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000A8C8: jr          $ra
    // 0x8000A8CC: nop

    return;
    // 0x8000A8CC: nop

;}
RECOMP_FUNC void audspat_distance_to_segment(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800092A8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800092AC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800092B0: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800092B4: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800092B8: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800092BC: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800092C0: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800092C4: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800092C8: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x800092CC: swc1        $f14, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->f14.u32l;
    // 0x800092D0: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x800092D4: lwc1        $f4, 0xC($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0XC);
    // 0x800092D8: lwc1        $f20, 0x0($a3)
    ctx->f20.u32l = MEM_W(ctx->r7, 0X0);
    // 0x800092DC: lwc1        $f22, 0x4($a3)
    ctx->f22.u32l = MEM_W(ctx->r7, 0X4);
    // 0x800092E0: lwc1        $f24, 0x8($a3)
    ctx->f24.u32l = MEM_W(ctx->r7, 0X8);
    // 0x800092E4: swc1        $f4, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f4.u32l;
    // 0x800092E8: lwc1        $f6, 0x10($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X10);
    // 0x800092EC: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800092F0: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800092F4: lwc1        $f8, 0x14($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X14);
    // 0x800092F8: lwc1        $f6, 0x48($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800092FC: sub.s       $f2, $f10, $f20
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f20.fl;
    // 0x80009300: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80009304: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80009308: sub.s       $f8, $f6, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f22.fl;
    // 0x8000930C: mtc1        $zero, $f1
    ctx->f_odd[(1 - 1) * 2] = 0;
    // 0x80009310: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80009314: sub.s       $f6, $f10, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f10.fl - ctx->f24.fl;
    // 0x80009318: swc1        $f2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f2.u32l;
    // 0x8000931C: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80009320: c.eq.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d == ctx->f10.d;
    // 0x80009324: swc1        $f8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f8.u32l;
    // 0x80009328: mov.s       $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = ctx->f8.fl;
    // 0x8000932C: swc1        $f6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f6.u32l;
    // 0x80009330: bc1f        L_8000936C
    if (!c1cs) {
        // 0x80009334: mov.s       $f18, $f6
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
            goto L_8000936C;
    }
    // 0x80009334: mov.s       $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = ctx->f6.fl;
    // 0x80009338: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x8000933C: c.eq.d      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.d == ctx->f4.d;
    // 0x80009340: nop

    // 0x80009344: bc1f        L_8000936C
    if (!c1cs) {
        // 0x80009348: nop
    
            goto L_8000936C;
    }
    // 0x80009348: nop

    // 0x8000934C: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x80009350: c.eq.d      $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f0.d == ctx->f10.d;
    // 0x80009354: nop

    // 0x80009358: bc1f        L_8000936C
    if (!c1cs) {
        // 0x8000935C: nop
    
            goto L_8000936C;
    }
    // 0x8000935C: nop

    // 0x80009360: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80009364: b           L_800093BC
    // 0x80009368: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
        goto L_800093BC;
    // 0x80009368: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_8000936C:
    // 0x8000936C: lwc1        $f8, 0x68($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80009370: lwc1        $f10, 0x6C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80009374: sub.s       $f4, $f8, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f20.fl;
    // 0x80009378: mul.s       $f6, $f4, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f2.fl);
    // 0x8000937C: sub.s       $f8, $f10, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f8.fl = ctx->f10.fl - ctx->f22.fl;
    // 0x80009380: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x80009384: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80009388: add.s       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x8000938C: sub.s       $f6, $f8, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = ctx->f8.fl - ctx->f24.fl;
    // 0x80009390: mul.s       $f4, $f6, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f6.fl, ctx->f18.fl);
    // 0x80009394: nop

    // 0x80009398: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8000939C: add.s       $f8, $f10, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800093A0: mul.s       $f10, $f16, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f16.fl, ctx->f16.fl);
    // 0x800093A4: add.s       $f4, $f6, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f10.fl;
    // 0x800093A8: mul.s       $f6, $f18, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x800093AC: add.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800093B0: nop

    // 0x800093B4: div.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = DIV_S(ctx->f8.fl, ctx->f10.fl);
    // 0x800093B8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
L_800093BC:
    // 0x800093BC: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800093C0: c.lt.s      $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f0.fl < ctx->f4.fl;
    // 0x800093C4: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800093C8: bc1f        L_8000941C
    if (!c1cs) {
        // 0x800093CC: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_8000941C;
    }
    // 0x800093CC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800093D0: swc1        $f20, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f20.u32l;
    // 0x800093D4: swc1        $f22, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f22.u32l;
    // 0x800093D8: lw          $t6, 0x80($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X80);
    // 0x800093DC: nop

    // 0x800093E0: swc1        $f24, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->f24.u32l;
    // 0x800093E4: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800093E8: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800093EC: sub.s       $f0, $f20, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f20.fl - ctx->f6.fl;
    // 0x800093F0: lwc1        $f10, 0x70($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800093F4: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800093F8: sub.s       $f2, $f22, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f22.fl - ctx->f8.fl;
    // 0x800093FC: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009400: sub.s       $f14, $f24, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x80009404: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80009408: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8000940C: jal         0x800C9AD0
    // 0x80009410: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80009410: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_0:
    // 0x80009414: b           L_8000951C
    // 0x80009418: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8000951C;
    // 0x80009418: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8000941C:
    // 0x8000941C: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80009420: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x80009424: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x80009428: lwc1        $f8, 0x38($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X38);
    // 0x8000942C: bc1f        L_800094A0
    if (!c1cs) {
        // 0x80009430: nop
    
            goto L_800094A0;
    }
    // 0x80009430: nop

    // 0x80009434: lwc1        $f6, 0x4C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80009438: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x8000943C: swc1        $f6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f6.u32l;
    // 0x80009440: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80009444: nop

    // 0x80009448: swc1        $f8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f8.u32l;
    // 0x8000944C: lw          $t7, 0x80($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X80);
    // 0x80009450: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80009454: nop

    // 0x80009458: swc1        $f10, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->f10.u32l;
    // 0x8000945C: lwc1        $f6, 0x68($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80009460: lwc1        $f4, 0x4C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x80009464: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x80009468: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8000946C: lwc1        $f4, 0x6C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x80009470: lwc1        $f6, 0x70($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X70);
    // 0x80009474: sub.s       $f2, $f8, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f4.fl;
    // 0x80009478: mul.s       $f8, $f0, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8000947C: sub.s       $f14, $f10, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x80009480: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009484: nop

    // 0x80009488: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8000948C: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80009490: jal         0x800C9AD0
    // 0x80009494: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80009494: add.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f6.fl;
    after_1:
    // 0x80009498: b           L_8000951C
    // 0x8000949C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
        goto L_8000951C;
    // 0x8000949C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_800094A0:
    // 0x800094A0: mul.s       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x800094A4: lw          $v0, 0x78($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X78);
    // 0x800094A8: lw          $v1, 0x7C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X7C);
    // 0x800094AC: add.s       $f10, $f4, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f20.fl;
    // 0x800094B0: swc1        $f10, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f10.u32l;
    // 0x800094B4: lwc1        $f6, 0x34($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800094B8: nop

    // 0x800094BC: mul.s       $f8, $f0, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f6.fl);
    // 0x800094C0: add.s       $f4, $f8, $f22
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f22.fl;
    // 0x800094C4: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x800094C8: lwc1        $f10, 0x30($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800094CC: lw          $t8, 0x80($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X80);
    // 0x800094D0: mul.s       $f6, $f0, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800094D4: add.s       $f16, $f6, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f24.fl;
    // 0x800094D8: swc1        $f16, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->f16.u32l;
    // 0x800094DC: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x800094E0: lwc1        $f8, 0x70($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X70);
    // 0x800094E4: lwc1        $f4, 0x0($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X0);
    // 0x800094E8: sub.s       $f18, $f16, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800094EC: lwc1        $f8, 0x6C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X6C);
    // 0x800094F0: sub.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f4.fl - ctx->f10.fl;
    // 0x800094F4: lwc1        $f6, 0x0($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800094F8: mul.s       $f4, $f2, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800094FC: sub.s       $f14, $f6, $f8
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f14.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80009500: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80009504: nop

    // 0x80009508: mul.s       $f8, $f18, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f18.fl, ctx->f18.fl);
    // 0x8000950C: add.s       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f10.fl;
    // 0x80009510: jal         0x800C9AD0
    // 0x80009514: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80009514: add.s       $f12, $f8, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f6.fl;
    after_2:
    // 0x80009518: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
L_8000951C:
    // 0x8000951C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80009520: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80009524: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80009528: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8000952C: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x80009530: cvt.w.s     $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    ctx->f4.u32l = CVT_W_S(ctx->f0.fl);
    // 0x80009534: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x80009538: mfc1        $v0, $f4
    ctx->r2 = (int32_t)ctx->f4.u32l;
    // 0x8000953C: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80009540: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80009544: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80009548: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000954C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80009550: jr          $ra
    // 0x80009554: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    return;
    // 0x80009554: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
;}
RECOMP_FUNC void calc_env_mapping_for_object(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001DD54: addiu       $sp, $sp, -0x118
    ctx->r29 = ADD32(ctx->r29, -0X118);
    // 0x8001DD58: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8001DD5C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8001DD60: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8001DD64: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8001DD68: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8001DD6C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8001DD70: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8001DD74: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8001DD78: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8001DD7C: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8001DD80: sw          $a1, 0x11C($sp)
    MEM_W(0X11C, ctx->r29) = ctx->r5;
    // 0x8001DD84: sw          $a2, 0x120($sp)
    MEM_W(0X120, ctx->r29) = ctx->r6;
    // 0x8001DD88: sw          $a3, 0x124($sp)
    MEM_W(0X124, ctx->r29) = ctx->r7;
    // 0x8001DD8C: lw          $t1, 0x8($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X8);
    // 0x8001DD90: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x8001DD94: sw          $t1, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r9;
    // 0x8001DD98: lw          $t2, 0x40($a0)
    ctx->r10 = MEM_W(ctx->r4, 0X40);
    // 0x8001DD9C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8001DDA0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8001DDA4: addiu       $s1, $sp, 0x98
    ctx->r17 = ADD32(ctx->r29, 0X98);
    // 0x8001DDA8: or          $fp, $a0, $zero
    ctx->r30 = ctx->r4 | 0;
    // 0x8001DDAC: or          $t6, $a1, $zero
    ctx->r14 = ctx->r5 | 0;
    // 0x8001DDB0: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8001DDB4: sh          $t6, 0x84($sp)
    MEM_H(0X84, ctx->r29) = ctx->r14;
    // 0x8001DDB8: sh          $a2, 0x82($sp)
    MEM_H(0X82, ctx->r29) = ctx->r6;
    // 0x8001DDBC: sh          $a3, 0x80($sp)
    MEM_H(0X80, ctx->r29) = ctx->r7;
    // 0x8001DDC0: addiu       $a1, $sp, 0x80
    ctx->r5 = ADD32(ctx->r29, 0X80);
    // 0x8001DDC4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DDC8: swc1        $f0, 0x8C($sp)
    MEM_W(0X8C, ctx->r29) = ctx->f0.u32l;
    // 0x8001DDCC: swc1        $f0, 0x90($sp)
    MEM_W(0X90, ctx->r29) = ctx->f0.u32l;
    // 0x8001DDD0: swc1        $f0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f0.u32l;
    // 0x8001DDD4: sw          $t2, 0x74($sp)
    MEM_W(0X74, ctx->r29) = ctx->r10;
    // 0x8001DDD8: jal         0x8006FC30
    // 0x8001DDDC: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_0;
    // 0x8001DDDC: swc1        $f4, 0x88($sp)
    MEM_W(0X88, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x8001DDE0: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DDE4: jal         0x8006F5E0
    // 0x8001DDE8: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    mtxf_to_mtxs(rdram, ctx);
        goto after_1;
    // 0x8001DDE8: addiu       $a1, $sp, 0xD8
    ctx->r5 = ADD32(ctx->r29, 0XD8);
    after_1:
    // 0x8001DDEC: sh          $zero, 0x62($sp)
    MEM_H(0X62, ctx->r29) = 0;
    // 0x8001DDF0: lh          $v0, 0x28($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X28);
    // 0x8001DDF4: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8001DDF8: blez        $v0, L_8001E10C
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001DDFC: addiu       $s3, $s3, -0x5098
        ctx->r19 = ADD32(ctx->r19, -0X5098);
            goto L_8001E10C;
    }
    // 0x8001DDFC: addiu       $s3, $s3, -0x5098
    ctx->r19 = ADD32(ctx->r19, -0X5098);
    // 0x8001DE00: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8001DE04: lw          $a2, 0x38($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X38);
    // 0x8001DE08: addiu       $s1, $s1, -0x5018
    ctx->r17 = ADD32(ctx->r17, -0X5018);
L_8001DE0C:
    // 0x8001DE0C: lh          $s7, 0x62($sp)
    ctx->r23 = MEM_H(ctx->r29, 0X62);
    // 0x8001DE10: lui         $at, 0x2
    ctx->r1 = S32(0X2 << 16);
    // 0x8001DE14: sll         $t3, $s7, 2
    ctx->r11 = S32(ctx->r23 << 2);
    // 0x8001DE18: subu        $t3, $t3, $s7
    ctx->r11 = SUB32(ctx->r11, ctx->r23);
    // 0x8001DE1C: sll         $s7, $t3, 2
    ctx->r23 = S32(ctx->r11 << 2);
    // 0x8001DE20: addu        $a1, $a2, $s7
    ctx->r5 = ADD32(ctx->r6, ctx->r23);
    // 0x8001DE24: lw          $v1, 0x8($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X8);
    // 0x8001DE28: nop

    // 0x8001DE2C: andi        $t4, $v1, 0x8000
    ctx->r12 = ctx->r3 & 0X8000;
    // 0x8001DE30: beq         $t4, $zero, L_8001E0C0
    if (ctx->r12 == 0) {
        // 0x8001DE34: and         $t5, $v1, $at
        ctx->r13 = ctx->r3 & ctx->r1;
            goto L_8001E0C0;
    }
    // 0x8001DE34: and         $t5, $v1, $at
    ctx->r13 = ctx->r3 & ctx->r1;
    // 0x8001DE38: ori         $t6, $t5, 0x8000
    ctx->r14 = ctx->r13 | 0X8000;
    // 0x8001DE3C: xori        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 ^ 0X8000;
    // 0x8001DE40: sw          $t7, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r15;
    // 0x8001DE44: lbu         $t9, 0x0($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X0);
    // 0x8001DE48: lw          $t8, 0x0($fp)
    ctx->r24 = MEM_W(ctx->r30, 0X0);
    // 0x8001DE4C: sll         $t0, $t9, 3
    ctx->r8 = S32(ctx->r25 << 3);
    // 0x8001DE50: addu        $t1, $t8, $t0
    ctx->r9 = ADD32(ctx->r24, ctx->r8);
    // 0x8001DE54: lw          $a0, 0x0($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X0);
    // 0x8001DE58: addiu       $a3, $zero, 0x20
    ctx->r7 = ADD32(0, 0X20);
    // 0x8001DE5C: lbu         $v0, 0x0($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X0);
    // 0x8001DE60: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
    // 0x8001DE64: beq         $v0, $a3, L_8001DEB8
    if (ctx->r2 == ctx->r7) {
        // 0x8001DE68: addiu       $t9, $zero, 0x6
        ctx->r25 = ADD32(0, 0X6);
            goto L_8001DEB8;
    }
    // 0x8001DE68: addiu       $t9, $zero, 0x6
    ctx->r25 = ADD32(0, 0X6);
    // 0x8001DE6C: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001DE70: beq         $v0, $at, L_8001DEA8
    if (ctx->r2 == ctx->r1) {
        // 0x8001DE74: addiu       $t6, $zero, 0x5
        ctx->r14 = ADD32(0, 0X5);
            goto L_8001DEA8;
    }
    // 0x8001DE74: addiu       $t6, $zero, 0x5
    ctx->r14 = ADD32(0, 0X5);
    // 0x8001DE78: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001DE7C: beq         $v0, $at, L_8001DE98
    if (ctx->r2 == ctx->r1) {
        // 0x8001DE80: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8001DE98;
    }
    // 0x8001DE80: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8001DE84: addiu       $t2, $zero, 0x7
    ctx->r10 = ADD32(0, 0X7);
    // 0x8001DE88: addiu       $t3, $zero, 0x1FF
    ctx->r11 = ADD32(0, 0X1FF);
    // 0x8001DE8C: sh          $t3, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r11;
    // 0x8001DE90: b           L_8001DEC4
    // 0x8001DE94: sh          $t2, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r10;
        goto L_8001DEC4;
    // 0x8001DE94: sh          $t2, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r10;
L_8001DE98:
    // 0x8001DE98: addiu       $t5, $zero, 0xFFF
    ctx->r13 = ADD32(0, 0XFFF);
    // 0x8001DE9C: sh          $t5, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r13;
    // 0x8001DEA0: b           L_8001DEC4
    // 0x8001DEA4: sh          $t4, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r12;
        goto L_8001DEC4;
    // 0x8001DEA4: sh          $t4, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r12;
L_8001DEA8:
    // 0x8001DEA8: addiu       $t7, $zero, 0x7FF
    ctx->r15 = ADD32(0, 0X7FF);
    // 0x8001DEAC: sh          $t7, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r15;
    // 0x8001DEB0: b           L_8001DEC4
    // 0x8001DEB4: sh          $t6, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r14;
        goto L_8001DEC4;
    // 0x8001DEB4: sh          $t6, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r14;
L_8001DEB8:
    // 0x8001DEB8: addiu       $t8, $zero, 0x3FF
    ctx->r24 = ADD32(0, 0X3FF);
    // 0x8001DEBC: sh          $t8, 0x68($sp)
    MEM_H(0X68, ctx->r29) = ctx->r24;
    // 0x8001DEC0: sh          $t9, 0x6A($sp)
    MEM_H(0X6A, ctx->r29) = ctx->r25;
L_8001DEC4:
    // 0x8001DEC4: lbu         $v0, 0x1($a0)
    ctx->r2 = MEM_BU(ctx->r4, 0X1);
    // 0x8001DEC8: addiu       $s5, $zero, 0x6
    ctx->r21 = ADD32(0, 0X6);
    // 0x8001DECC: beq         $v0, $a3, L_8001DF08
    if (ctx->r2 == ctx->r7) {
        // 0x8001DED0: addiu       $s6, $zero, 0x3FF
        ctx->r22 = ADD32(0, 0X3FF);
            goto L_8001DF08;
    }
    // 0x8001DED0: addiu       $s6, $zero, 0x3FF
    ctx->r22 = ADD32(0, 0X3FF);
    // 0x8001DED4: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x8001DED8: beq         $v0, $at, L_8001DF00
    if (ctx->r2 == ctx->r1) {
        // 0x8001DEDC: addiu       $s5, $zero, 0x5
        ctx->r21 = ADD32(0, 0X5);
            goto L_8001DF00;
    }
    // 0x8001DEDC: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x8001DEE0: addiu       $at, $zero, 0x80
    ctx->r1 = ADD32(0, 0X80);
    // 0x8001DEE4: beq         $v0, $at, L_8001DEF8
    if (ctx->r2 == ctx->r1) {
        // 0x8001DEE8: addiu       $s5, $zero, 0x4
        ctx->r21 = ADD32(0, 0X4);
            goto L_8001DEF8;
    }
    // 0x8001DEE8: addiu       $s5, $zero, 0x4
    ctx->r21 = ADD32(0, 0X4);
    // 0x8001DEEC: addiu       $s5, $zero, 0x7
    ctx->r21 = ADD32(0, 0X7);
    // 0x8001DEF0: b           L_8001DF08
    // 0x8001DEF4: addiu       $s6, $zero, 0x1FF
    ctx->r22 = ADD32(0, 0X1FF);
        goto L_8001DF08;
    // 0x8001DEF4: addiu       $s6, $zero, 0x1FF
    ctx->r22 = ADD32(0, 0X1FF);
L_8001DEF8:
    // 0x8001DEF8: b           L_8001DF08
    // 0x8001DEFC: addiu       $s6, $zero, 0xFFF
    ctx->r22 = ADD32(0, 0XFFF);
        goto L_8001DF08;
    // 0x8001DEFC: addiu       $s6, $zero, 0xFFF
    ctx->r22 = ADD32(0, 0XFFF);
L_8001DF00:
    // 0x8001DF00: b           L_8001DF08
    // 0x8001DF04: addiu       $s6, $zero, 0x7FF
    ctx->r22 = ADD32(0, 0X7FF);
        goto L_8001DF08;
    // 0x8001DF04: addiu       $s6, $zero, 0x7FF
    ctx->r22 = ADD32(0, 0X7FF);
L_8001DF08:
    // 0x8001DF08: lh          $s0, 0x2($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X2);
    // 0x8001DF0C: lh          $t0, 0xE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XE);
    // 0x8001DF10: nop

    // 0x8001DF14: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001DF18: beq         $at, $zero, L_8001E01C
    if (ctx->r1 == 0) {
        // 0x8001DF1C: sll         $t2, $s4, 2
        ctx->r10 = S32(ctx->r20 << 2);
            goto L_8001E01C;
    }
L_8001DF1C:
    // 0x8001DF1C: sll         $t2, $s4, 2
    ctx->r10 = S32(ctx->r20 << 2);
    // 0x8001DF20: lw          $t1, 0x74($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X74);
    // 0x8001DF24: subu        $t2, $t2, $s4
    ctx->r10 = SUB32(ctx->r10, ctx->r20);
    // 0x8001DF28: sll         $t2, $t2, 1
    ctx->r10 = S32(ctx->r10 << 1);
    // 0x8001DF2C: addu        $v0, $t1, $t2
    ctx->r2 = ADD32(ctx->r9, ctx->r10);
    // 0x8001DF30: lh          $t3, 0x0($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X0);
    // 0x8001DF34: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8001DF38: sh          $t3, 0x6($s1)
    MEM_H(0X6, ctx->r17) = ctx->r11;
    // 0x8001DF3C: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x8001DF40: sll         $t6, $s4, 16
    ctx->r14 = S32(ctx->r20 << 16);
    // 0x8001DF44: sh          $t4, 0x8($s1)
    MEM_H(0X8, ctx->r17) = ctx->r12;
    // 0x8001DF48: lh          $t5, 0x4($v0)
    ctx->r13 = MEM_H(ctx->r2, 0X4);
    // 0x8001DF4C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001DF50: sra         $s4, $t6, 16
    ctx->r20 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001DF54: addiu       $a1, $a1, -0x5012
    ctx->r5 = ADD32(ctx->r5, -0X5012);
    // 0x8001DF58: addiu       $a0, $sp, 0xD8
    ctx->r4 = ADD32(ctx->r29, 0XD8);
    // 0x8001DF5C: jal         0x8006FB60
    // 0x8001DF60: sh          $t5, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r13;
    mtxs_transform_dir(rdram, ctx);
        goto after_2;
    // 0x8001DF60: sh          $t5, 0xA($s1)
    MEM_H(0XA, ctx->r17) = ctx->r13;
    after_2:
    // 0x8001DF64: lw          $t9, 0x70($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X70);
    // 0x8001DF68: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8001DF6C: bne         $t9, $zero, L_8001DF7C
    if (ctx->r25 != 0) {
        // 0x8001DF70: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001DF7C;
    }
    // 0x8001DF70: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001DF74: jal         0x8006F9B8
    // 0x8001DF78: addiu       $a1, $a1, -0x5012
    ctx->r5 = ADD32(ctx->r5, -0X5012);
    vec3s_reflect(rdram, ctx);
        goto after_3;
    // 0x8001DF78: addiu       $a1, $a1, -0x5012
    ctx->r5 = ADD32(ctx->r5, -0X5012);
    after_3:
L_8001DF7C:
    // 0x8001DF7C: lh          $v0, 0x6($s1)
    ctx->r2 = MEM_H(ctx->r17, 0X6);
    // 0x8001DF80: lh          $v1, 0x8($s1)
    ctx->r3 = MEM_H(ctx->r17, 0X8);
    // 0x8001DF84: blez        $v0, L_8001DF98
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8001DF88: ori         $a3, $zero, 0x8000
        ctx->r7 = 0 | 0X8000;
            goto L_8001DF98;
    }
    // 0x8001DF88: ori         $a3, $zero, 0x8000
    ctx->r7 = 0 | 0X8000;
    // 0x8001DF8C: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8001DF90: sll         $t8, $v0, 16
    ctx->r24 = S32(ctx->r2 << 16);
    // 0x8001DF94: sra         $v0, $t8, 16
    ctx->r2 = S32(SIGNED(ctx->r24) >> 16);
L_8001DF98:
    // 0x8001DF98: blez        $v1, L_8001DFAC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001DF9C: sll         $t3, $v0, 2
        ctx->r11 = S32(ctx->r2 << 2);
            goto L_8001DFAC;
    }
    // 0x8001DF9C: sll         $t3, $v0, 2
    ctx->r11 = S32(ctx->r2 << 2);
    // 0x8001DFA0: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
    // 0x8001DFA4: sll         $t1, $v1, 16
    ctx->r9 = S32(ctx->r3 << 16);
    // 0x8001DFA8: sra         $v1, $t1, 16
    ctx->r3 = S32(SIGNED(ctx->r9) >> 16);
L_8001DFAC:
    // 0x8001DFAC: addu        $v0, $t3, $a3
    ctx->r2 = ADD32(ctx->r11, ctx->r7);
    // 0x8001DFB0: sll         $t6, $v1, 2
    ctx->r14 = S32(ctx->r3 << 2);
    // 0x8001DFB4: lh          $t0, 0x6A($sp)
    ctx->r8 = MEM_H(ctx->r29, 0X6A);
    // 0x8001DFB8: sll         $t4, $v0, 16
    ctx->r12 = S32(ctx->r2 << 16);
    // 0x8001DFBC: addu        $v1, $t6, $a3
    ctx->r3 = ADD32(ctx->r14, ctx->r7);
    // 0x8001DFC0: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x8001DFC4: sll         $t7, $v1, 16
    ctx->r15 = S32(ctx->r3 << 16);
    // 0x8001DFC8: lh          $t2, 0x68($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X68);
    // 0x8001DFCC: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001DFD0: sll         $t8, $s2, 2
    ctx->r24 = S32(ctx->r18 << 2);
    // 0x8001DFD4: srav        $t1, $t5, $t0
    ctx->r9 = S32(SIGNED(ctx->r13) >> (ctx->r8 & 31));
    // 0x8001DFD8: addu        $a0, $s3, $t8
    ctx->r4 = ADD32(ctx->r19, ctx->r24);
    // 0x8001DFDC: srav        $t4, $t9, $s5
    ctx->r12 = S32(SIGNED(ctx->r25) >> (ctx->r21 & 31));
    // 0x8001DFE0: and         $t5, $t4, $s6
    ctx->r13 = ctx->r12 & ctx->r22;
    // 0x8001DFE4: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x8001DFE8: sh          $t3, 0x0($a0)
    MEM_H(0X0, ctx->r4) = ctx->r11;
    // 0x8001DFEC: sh          $t5, 0x2($a0)
    MEM_H(0X2, ctx->r4) = ctx->r13;
    // 0x8001DFF0: lw          $a2, 0x38($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X38);
    // 0x8001DFF4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001DFF8: addu        $a1, $a2, $s7
    ctx->r5 = ADD32(ctx->r6, ctx->r23);
    // 0x8001DFFC: lh          $t0, 0xE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XE);
    // 0x8001E000: sll         $t6, $s0, 16
    ctx->r14 = S32(ctx->r16 << 16);
    // 0x8001E004: sra         $s0, $t6, 16
    ctx->r16 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001E008: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x8001E00C: sll         $t9, $s2, 16
    ctx->r25 = S32(ctx->r18 << 16);
    // 0x8001E010: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8001E014: bne         $at, $zero, L_8001DF1C
    if (ctx->r1 != 0) {
        // 0x8001E018: sra         $s2, $t9, 16
        ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
            goto L_8001DF1C;
    }
    // 0x8001E018: sra         $s2, $t9, 16
    ctx->r18 = S32(SIGNED(ctx->r25) >> 16);
L_8001E01C:
    // 0x8001E01C: lh          $s0, 0x4($a1)
    ctx->r16 = MEM_H(ctx->r5, 0X4);
    // 0x8001E020: lh          $t1, 0x10($a1)
    ctx->r9 = MEM_H(ctx->r5, 0X10);
    // 0x8001E024: lw          $a3, 0x78($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X78);
    // 0x8001E028: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8001E02C: beq         $at, $zero, L_8001E0B4
    if (ctx->r1 == 0) {
        // 0x8001E030: sll         $t2, $s0, 4
        ctx->r10 = S32(ctx->r16 << 4);
            goto L_8001E0B4;
    }
    // 0x8001E030: sll         $t2, $s0, 4
    ctx->r10 = S32(ctx->r16 << 4);
L_8001E034:
    // 0x8001E034: addu        $v0, $a3, $t2
    ctx->r2 = ADD32(ctx->r7, ctx->r10);
    // 0x8001E038: lbu         $t3, 0x1($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X1);
    // 0x8001E03C: lbu         $t7, 0x2($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X2);
    // 0x8001E040: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x8001E044: addu        $v1, $s3, $t4
    ctx->r3 = ADD32(ctx->r19, ctx->r12);
    // 0x8001E048: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x8001E04C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8001E050: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x8001E054: lh          $t6, 0x2($v1)
    ctx->r14 = MEM_H(ctx->r3, 0X2);
    // 0x8001E058: addu        $a0, $s3, $t9
    ctx->r4 = ADD32(ctx->r19, ctx->r25);
    // 0x8001E05C: sh          $t6, 0x6($v0)
    MEM_H(0X6, ctx->r2) = ctx->r14;
    // 0x8001E060: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x8001E064: lbu         $t1, 0x3($v0)
    ctx->r9 = MEM_BU(ctx->r2, 0X3);
    // 0x8001E068: sh          $t8, 0x8($v0)
    MEM_H(0X8, ctx->r2) = ctx->r24;
    // 0x8001E06C: lh          $t0, 0x2($a0)
    ctx->r8 = MEM_H(ctx->r4, 0X2);
    // 0x8001E070: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x8001E074: addu        $a1, $s3, $t2
    ctx->r5 = ADD32(ctx->r19, ctx->r10);
    // 0x8001E078: sh          $t0, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r8;
    // 0x8001E07C: lh          $t3, 0x0($a1)
    ctx->r11 = MEM_H(ctx->r5, 0X0);
    // 0x8001E080: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8001E084: sh          $t3, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r11;
    // 0x8001E088: lh          $t4, 0x2($a1)
    ctx->r12 = MEM_H(ctx->r5, 0X2);
    // 0x8001E08C: sll         $t5, $s0, 16
    ctx->r13 = S32(ctx->r16 << 16);
    // 0x8001E090: sh          $t4, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r12;
    // 0x8001E094: lw          $a2, 0x38($fp)
    ctx->r6 = MEM_W(ctx->r30, 0X38);
    // 0x8001E098: sra         $s0, $t5, 16
    ctx->r16 = S32(SIGNED(ctx->r13) >> 16);
    // 0x8001E09C: addu        $t7, $a2, $s7
    ctx->r15 = ADD32(ctx->r6, ctx->r23);
    // 0x8001E0A0: lh          $t9, 0x10($t7)
    ctx->r25 = MEM_H(ctx->r15, 0X10);
    // 0x8001E0A4: nop

    // 0x8001E0A8: slt         $at, $s0, $t9
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x8001E0AC: bne         $at, $zero, L_8001E034
    if (ctx->r1 != 0) {
        // 0x8001E0B0: sll         $t2, $s0, 4
        ctx->r10 = S32(ctx->r16 << 4);
            goto L_8001E034;
    }
    // 0x8001E0B0: sll         $t2, $s0, 4
    ctx->r10 = S32(ctx->r16 << 4);
L_8001E0B4:
    // 0x8001E0B4: lh          $v0, 0x28($fp)
    ctx->r2 = MEM_H(ctx->r30, 0X28);
    // 0x8001E0B8: b           L_8001E0F0
    // 0x8001E0BC: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
        goto L_8001E0F0;
    // 0x8001E0BC: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
L_8001E0C0:
    // 0x8001E0C0: lbu         $t8, 0x6($a1)
    ctx->r24 = MEM_BU(ctx->r5, 0X6);
    // 0x8001E0C4: nop

    // 0x8001E0C8: slti        $at, $t8, 0xFF
    ctx->r1 = SIGNED(ctx->r24) < 0XFF ? 1 : 0;
    // 0x8001E0CC: beq         $at, $zero, L_8001E0F0
    if (ctx->r1 == 0) {
        // 0x8001E0D0: lh          $t5, 0x62($sp)
        ctx->r13 = MEM_H(ctx->r29, 0X62);
            goto L_8001E0F0;
    }
    // 0x8001E0D0: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
    // 0x8001E0D4: lh          $t0, 0xE($a1)
    ctx->r8 = MEM_H(ctx->r5, 0XE);
    // 0x8001E0D8: lh          $t2, 0x2($a1)
    ctx->r10 = MEM_H(ctx->r5, 0X2);
    // 0x8001E0DC: addu        $t1, $s4, $t0
    ctx->r9 = ADD32(ctx->r20, ctx->r8);
    // 0x8001E0E0: subu        $s4, $t1, $t2
    ctx->r20 = SUB32(ctx->r9, ctx->r10);
    // 0x8001E0E4: sll         $t3, $s4, 16
    ctx->r11 = S32(ctx->r20 << 16);
    // 0x8001E0E8: sra         $s4, $t3, 16
    ctx->r20 = S32(SIGNED(ctx->r11) >> 16);
    // 0x8001E0EC: lh          $t5, 0x62($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X62);
L_8001E0F0:
    // 0x8001E0F0: nop

    // 0x8001E0F4: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x8001E0F8: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8001E0FC: sra         $t9, $t7, 16
    ctx->r25 = S32(SIGNED(ctx->r15) >> 16);
    // 0x8001E100: slt         $at, $t9, $v0
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001E104: bne         $at, $zero, L_8001DE0C
    if (ctx->r1 != 0) {
        // 0x8001E108: sh          $t6, 0x62($sp)
        MEM_H(0X62, ctx->r29) = ctx->r14;
            goto L_8001DE0C;
    }
    // 0x8001E108: sh          $t6, 0x62($sp)
    MEM_H(0X62, ctx->r29) = ctx->r14;
L_8001E10C:
    // 0x8001E10C: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8001E110: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8001E114: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8001E118: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8001E11C: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8001E120: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8001E124: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8001E128: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8001E12C: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8001E130: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8001E134: jr          $ra
    // 0x8001E138: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
    return;
    // 0x8001E138: addiu       $sp, $sp, 0x118
    ctx->r29 = ADD32(ctx->r29, 0X118);
;}
RECOMP_FUNC void is_drumstick_unlocked(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009ECD0: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009ECD4: lw          $v0, -0x268($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X268);
    // 0x8009ECD8: nop

    // 0x8009ECDC: andi        $t6, $v0, 0x2
    ctx->r14 = ctx->r2 & 0X2;
    // 0x8009ECE0: jr          $ra
    // 0x8009ECE4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8009ECE4: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void obj_init_log(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004049C: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800404A0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800404A4: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x800404A8: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x800404AC: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x800404B0: lw          $a1, 0xC($a3)
    ctx->r5 = MEM_W(ctx->r7, 0XC);
    // 0x800404B4: lw          $a2, 0x14($a3)
    ctx->r6 = MEM_W(ctx->r7, 0X14);
    // 0x800404B8: lh          $a0, 0x2E($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X2E);
    // 0x800404BC: jal         0x800BE654
    // 0x800404C0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    obj_wave_init(rdram, ctx);
        goto after_0;
    // 0x800404C0: sw          $a3, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r7;
    after_0:
    // 0x800404C4: lw          $a3, 0x18($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X18);
    // 0x800404C8: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x800404CC: lw          $t7, 0x4C($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X4C);
    // 0x800404D0: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800404D4: sw          $v0, 0x64($a3)
    MEM_W(0X64, ctx->r7) = ctx->r2;
    // 0x800404D8: sh          $t6, 0x14($t7)
    MEM_H(0X14, ctx->r15) = ctx->r14;
    // 0x800404DC: lw          $t9, 0x4C($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X4C);
    // 0x800404E0: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x800404E4: sb          $t8, 0x11($t9)
    MEM_B(0X11, ctx->r25) = ctx->r24;
    // 0x800404E8: lw          $t1, 0x4C($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X4C);
    // 0x800404EC: addiu       $t0, $zero, 0x1E
    ctx->r8 = ADD32(0, 0X1E);
    // 0x800404F0: sb          $t0, 0x10($t1)
    MEM_B(0X10, ctx->r9) = ctx->r8;
    // 0x800404F4: lbu         $t3, 0x9($v1)
    ctx->r11 = MEM_BU(ctx->r3, 0X9);
    // 0x800404F8: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800404FC: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80040500: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80040504: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80040508: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8004050C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80040510: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80040514: nop

    // 0x80040518: bc1f        L_80040528
    if (!c1cs) {
        // 0x8004051C: nop
    
            goto L_80040528;
    }
    // 0x8004051C: nop

    // 0x80040520: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80040524: nop

L_80040528:
    // 0x80040528: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x8004052C: lw          $t4, 0x40($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X40);
    // 0x80040530: nop

    // 0x80040534: lwc1        $f8, 0xC($t4)
    ctx->f8.u32l = MEM_W(ctx->r12, 0XC);
    // 0x80040538: nop

    // 0x8004053C: mul.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f8.fl, ctx->f0.fl);
    // 0x80040540: swc1        $f10, 0x8($a3)
    MEM_W(0X8, ctx->r7) = ctx->f10.u32l;
    // 0x80040544: lbu         $t5, 0x8($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X8);
    // 0x80040548: nop

    // 0x8004054C: sb          $t5, 0x3A($a3)
    MEM_B(0X3A, ctx->r7) = ctx->r13;
    // 0x80040550: lbu         $t7, 0xA($v1)
    ctx->r15 = MEM_BU(ctx->r3, 0XA);
    // 0x80040554: nop

    // 0x80040558: sll         $t8, $t7, 10
    ctx->r24 = S32(ctx->r15 << 10);
    // 0x8004055C: sh          $t8, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r24;
    // 0x80040560: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80040564: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80040568: jr          $ra
    // 0x8004056C: nop

    return;
    // 0x8004056C: nop

;}
RECOMP_FUNC void music_get_fx_mix_all_channels(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80001440: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001444: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80001448: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x8000144C: addiu       $s3, $s3, -0x39D0
    ctx->r19 = ADD32(ctx->r19, -0X39D0);
    // 0x80001450: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80001454: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80001458: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000145C: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80001460: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80001464: lbu         $t6, 0x34($s1)
    ctx->r14 = MEM_BU(ctx->r17, 0X34);
    // 0x80001468: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000146C: blez        $t6, L_800014A0
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80001470: or          $s2, $a0, $zero
        ctx->r18 = ctx->r4 | 0;
            goto L_800014A0;
    }
    // 0x80001470: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80001474: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_80001478:
    // 0x80001478: jal         0x800C79C0
    // 0x8000147C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    alSeqpGetChlFXMix(rdram, ctx);
        goto after_0;
    // 0x8000147C: andi        $a1, $s0, 0xFF
    ctx->r5 = ctx->r16 & 0XFF;
    after_0:
    // 0x80001480: sb          $v0, 0x0($s2)
    MEM_B(0X0, ctx->r18) = ctx->r2;
    // 0x80001484: lw          $s1, 0x0($s3)
    ctx->r17 = MEM_W(ctx->r19, 0X0);
    // 0x80001488: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000148C: lbu         $t7, 0x34($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X34);
    // 0x80001490: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80001494: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x80001498: bne         $at, $zero, L_80001478
    if (ctx->r1 != 0) {
        // 0x8000149C: or          $a0, $s1, $zero
        ctx->r4 = ctx->r17 | 0;
            goto L_80001478;
    }
    // 0x8000149C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
L_800014A0:
    // 0x800014A0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800014A4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800014A8: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800014AC: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800014B0: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800014B4: jr          $ra
    // 0x800014B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800014B8: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void track_spawn_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C8F8: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x8000C8FC: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000C900: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8000C904: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8000C908: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8000C90C: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x8000C910: jal         0x8006EA90
    // 0x8000C914: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8000C914: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8000C918: lbu         $t8, 0x49($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X49);
    // 0x8000C91C: lw          $t7, 0x4($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X4);
    // 0x8000C920: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x8000C924: addu        $t0, $t7, $t9
    ctx->r8 = ADD32(ctx->r15, ctx->r25);
    // 0x8000C928: lw          $v1, 0x0($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X0);
    // 0x8000C92C: lhu         $s0, 0xC($v0)
    ctx->r16 = MEM_HU(ctx->r2, 0XC);
    // 0x8000C930: andi        $t1, $v1, 0x4
    ctx->r9 = ctx->r3 & 0X4;
    // 0x8000C934: sltiu       $v1, $t1, 0x1
    ctx->r3 = ctx->r9 < 0X1 ? 1 : 0;
    // 0x8000C938: beq         $v1, $zero, L_8000C958
    if (ctx->r3 == 0) {
        // 0x8000C93C: ori         $t6, $s0, 0x820
        ctx->r14 = ctx->r16 | 0X820;
            goto L_8000C958;
    }
    // 0x8000C93C: ori         $t6, $s0, 0x820
    ctx->r14 = ctx->r16 | 0X820;
    // 0x8000C940: lbu         $t3, 0x48($v0)
    ctx->r11 = MEM_BU(ctx->r2, 0X48);
    // 0x8000C944: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x8000C948: sllv        $t5, $t4, $t3
    ctx->r13 = S32(ctx->r12 << (ctx->r11 & 31));
    // 0x8000C94C: and         $v1, $t5, $t6
    ctx->r3 = ctx->r13 & ctx->r14;
    // 0x8000C950: sltu        $t6, $zero, $v1
    ctx->r14 = 0 < ctx->r3 ? 1 : 0;
    // 0x8000C954: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
L_8000C958:
    // 0x8000C958: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000C95C: addiu       $s0, $s0, -0x51FD
    ctx->r16 = ADD32(ctx->r16, -0X51FD);
    // 0x8000C960: sb          $v1, 0x0($s0)
    MEM_B(0X0, ctx->r16) = ctx->r3;
    // 0x8000C964: lbu         $t7, 0x49($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X49);
    // 0x8000C968: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8000C96C: sll         $t9, $t7, 2
    ctx->r25 = S32(ctx->r15 << 2);
    // 0x8000C970: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x8000C974: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000C978: nop

    // 0x8000C97C: andi        $t2, $t1, 0x2
    ctx->r10 = ctx->r9 & 0X2;
    // 0x8000C980: bne         $t2, $zero, L_8000C98C
    if (ctx->r10 != 0) {
        // 0x8000C984: nop
    
            goto L_8000C98C;
    }
    // 0x8000C984: nop

    // 0x8000C988: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8000C98C:
    // 0x8000C98C: jal         0x8009C2D0
    // 0x8000C990: nop

    is_in_tracks_mode(rdram, ctx);
        goto after_1;
    // 0x8000C990: nop

    after_1:
    // 0x8000C994: beq         $v0, $zero, L_8000C9A0
    if (ctx->r2 == 0) {
        // 0x8000C998: nop
    
            goto L_8000C9A0;
    }
    // 0x8000C998: nop

    // 0x8000C99C: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8000C9A0:
    // 0x8000C9A0: jal         0x8006BD98
    // 0x8000C9A4: nop

    level_type(rdram, ctx);
        goto after_2;
    // 0x8000C9A4: nop

    after_2:
    // 0x8000C9A8: beq         $v0, $zero, L_8000C9B4
    if (ctx->r2 == 0) {
        // 0x8000C9AC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8000C9B4;
    }
    // 0x8000C9AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C9B0: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
L_8000C9B4:
    // 0x8000C9B4: sb          $zero, -0x52C2($at)
    MEM_B(-0X52C2, ctx->r1) = 0;
    // 0x8000C9B8: addiu       $a0, $zero, 0x3000
    ctx->r4 = ADD32(0, 0X3000);
    // 0x8000C9BC: jal         0x80070C9C
    // 0x8000C9C0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8000C9C0: ori         $a1, $zero, 0xFFFF
    ctx->r5 = 0 | 0XFFFF;
    after_3:
    // 0x8000C9C4: lw          $v1, 0x5C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X5C);
    // 0x8000C9C8: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8000C9CC: sll         $t4, $v1, 2
    ctx->r12 = S32(ctx->r3 << 2);
    // 0x8000C9D0: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8000C9D4: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8000C9D8: addiu       $t3, $t3, -0x5150
    ctx->r11 = ADD32(ctx->r11, -0X5150);
    // 0x8000C9DC: addiu       $t5, $t5, -0x5168
    ctx->r13 = ADD32(ctx->r13, -0X5168);
    // 0x8000C9E0: addiu       $t7, $t7, -0x5160
    ctx->r15 = ADD32(ctx->r15, -0X5160);
    // 0x8000C9E4: lw          $t8, 0x58($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X58);
    // 0x8000C9E8: addu        $a1, $t4, $t3
    ctx->r5 = ADD32(ctx->r12, ctx->r11);
    // 0x8000C9EC: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x8000C9F0: addiu       $t6, $v0, 0x10
    ctx->r14 = ADD32(ctx->r2, 0X10);
    // 0x8000C9F4: addu        $s2, $t4, $t7
    ctx->r18 = ADD32(ctx->r12, ctx->r15);
    // 0x8000C9F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C9FC: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x8000CA00: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8000CA04: sw          $zero, 0x0($s2)
    MEM_W(0X0, ctx->r18) = 0;
    // 0x8000CA08: addu        $at, $at, $t4
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x8000CA0C: sw          $v0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r2;
    // 0x8000CA10: sw          $a1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r5;
    // 0x8000CA14: addiu       $a0, $zero, 0x14
    ctx->r4 = ADD32(0, 0X14);
    // 0x8000CA18: jal         0x80076C58
    // 0x8000CA1C: sw          $t8, -0x5158($at)
    MEM_W(-0X5158, ctx->r1) = ctx->r24;
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8000CA1C: sw          $t8, -0x5158($at)
    MEM_W(-0X5158, ctx->r1) = ctx->r24;
    after_4:
    // 0x8000CA20: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8000CA24: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8000CA28: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
    // 0x8000CA2C: beq         $a1, $t9, L_8000CA48
    if (ctx->r5 == ctx->r25) {
        // 0x8000CA30: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_8000CA48;
    }
    // 0x8000CA30: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8000CA34: or          $v1, $a2, $zero
    ctx->r3 = ctx->r6 | 0;
L_8000CA38:
    // 0x8000CA38: lw          $t0, 0x4($v1)
    ctx->r8 = MEM_W(ctx->r3, 0X4);
    // 0x8000CA3C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8000CA40: bne         $a1, $t0, L_8000CA38
    if (ctx->r5 != ctx->r8) {
        // 0x8000CA44: addiu       $v1, $v1, 0x4
        ctx->r3 = ADD32(ctx->r3, 0X4);
            goto L_8000CA38;
    }
    // 0x8000CA44: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
L_8000CA48:
    // 0x8000CA48: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x8000CA4C: addiu       $a0, $a0, -0x1
    ctx->r4 = ADD32(ctx->r4, -0X1);
    // 0x8000CA50: slt         $at, $t1, $a0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8000CA54: bne         $at, $zero, L_8000CA60
    if (ctx->r1 != 0) {
        // 0x8000CA58: addiu       $a0, $zero, 0x15
        ctx->r4 = ADD32(0, 0X15);
            goto L_8000CA60;
    }
    // 0x8000CA58: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8000CA5C: sw          $zero, 0x58($sp)
    MEM_W(0X58, ctx->r29) = 0;
L_8000CA60:
    // 0x8000CA60: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8000CA64: nop

    // 0x8000CA68: sll         $t4, $t2, 2
    ctx->r12 = S32(ctx->r10 << 2);
    // 0x8000CA6C: addu        $v1, $v0, $t4
    ctx->r3 = ADD32(ctx->r2, ctx->r12);
    // 0x8000CA70: lw          $s0, 0x0($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X0);
    // 0x8000CA74: lw          $t3, 0x4($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X4);
    // 0x8000CA78: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8000CA7C: subu        $a3, $t3, $s0
    ctx->r7 = SUB32(ctx->r11, ctx->r16);
    // 0x8000CA80: beq         $a3, $zero, L_8000CBAC
    if (ctx->r7 == 0) {
        // 0x8000CA84: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_8000CBAC;
    }
    // 0x8000CA84: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000CA88: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x8000CA8C: jal         0x800C61DC
    // 0x8000CA90: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    gzip_size_uncompressed(rdram, ctx);
        goto after_5;
    // 0x8000CA90: sw          $a3, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r7;
    after_5:
    // 0x8000CA94: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x8000CA98: lw          $a3, 0x54($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X54);
    // 0x8000CA9C: addu        $t6, $t5, $v0
    ctx->r14 = ADD32(ctx->r13, ctx->r2);
    // 0x8000CAA0: subu        $a1, $t6, $a3
    ctx->r5 = SUB32(ctx->r14, ctx->r7);
    // 0x8000CAA4: addiu       $a1, $a1, 0x20
    ctx->r5 = ADD32(ctx->r5, 0X20);
    // 0x8000CAA8: sw          $a1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r5;
    // 0x8000CAAC: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x8000CAB0: jal         0x80076E68
    // 0x8000CAB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    asset_load(rdram, ctx);
        goto after_6;
    // 0x8000CAB4: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_6:
    // 0x8000CAB8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x8000CABC: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x8000CAC0: jal         0x800C6218
    // 0x8000CAC4: nop

    gzip_inflate(rdram, ctx);
        goto after_7;
    // 0x8000CAC4: nop

    after_7:
    // 0x8000CAC8: lw          $a0, 0x3C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X3C);
    // 0x8000CACC: jal         0x80071140
    // 0x8000CAD0: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8000CAD0: nop

    after_8:
    // 0x8000CAD4: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000CAD8: lw          $t0, 0x48($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X48);
    // 0x8000CADC: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000CAE0: lw          $t2, 0x5C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X5C);
    // 0x8000CAE4: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8000CAE8: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
    // 0x8000CAEC: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x8000CAF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CAF4: sw          $t1, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r9;
    // 0x8000CAF8: sw          $t2, -0x5140($at)
    MEM_W(-0X5140, ctx->r1) = ctx->r10;
    // 0x8000CAFC: lw          $t4, 0x0($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X0);
    // 0x8000CB00: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000CB04: blez        $t4, L_8000CB58
    if (SIGNED(ctx->r12) <= 0) {
        // 0x8000CB08: nop
    
            goto L_8000CB58;
    }
    // 0x8000CB08: nop

L_8000CB0C:
    // 0x8000CB0C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8000CB10: jal         0x8000EA54
    // 0x8000CB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    spawn_object(rdram, ctx);
        goto after_9;
    // 0x8000CB14: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_9:
    // 0x8000CB18: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x8000CB1C: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8000CB20: lbu         $a0, 0x1($v1)
    ctx->r4 = MEM_BU(ctx->r3, 0X1);
    // 0x8000CB24: nop

    // 0x8000CB28: andi        $t3, $a0, 0x3F
    ctx->r11 = ctx->r4 & 0X3F;
    // 0x8000CB2C: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x8000CB30: addu        $t5, $t3, $v1
    ctx->r13 = ADD32(ctx->r11, ctx->r3);
    // 0x8000CB34: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8000CB38: bne         $at, $zero, L_8000CB0C
    if (ctx->r1 != 0) {
        // 0x8000CB3C: sw          $t5, 0x0($s1)
        MEM_W(0X0, ctx->r17) = ctx->r13;
            goto L_8000CB0C;
    }
    // 0x8000CB3C: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x8000CB40: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8000CB44: nop

    // 0x8000CB48: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000CB4C: nop

    // 0x8000CB50: addiu       $t9, $t8, 0x10
    ctx->r25 = ADD32(ctx->r24, 0X10);
    // 0x8000CB54: sw          $t9, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r25;
L_8000CB58:
    // 0x8000CB58: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CB5C: sw          $zero, -0x5190($at)
    MEM_W(-0X5190, ctx->r1) = 0;
    // 0x8000CB60: addiu       $s0, $zero, 0x1
    ctx->r16 = ADD32(0, 0X1);
    // 0x8000CB64: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8000CB68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000CB6C: addiu       $s1, $s1, -0x5254
    ctx->r17 = ADD32(ctx->r17, -0X5254);
    // 0x8000CB70: sw          $s0, -0x5240($at)
    MEM_W(-0X5240, ctx->r1) = ctx->r16;
    // 0x8000CB74: lw          $t0, 0x0($s1)
    ctx->r8 = MEM_W(ctx->r17, 0X0);
    // 0x8000CB78: nop

    // 0x8000CB7C: bne         $t0, $zero, L_8000CBA4
    if (ctx->r8 != 0) {
        // 0x8000CB80: nop
    
            goto L_8000CBA4;
    }
    // 0x8000CB80: nop

    // 0x8000CB84: jal         0x8001004C
    // 0x8000CB88: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_10;
    // 0x8000CB88: nop

    after_10:
    // 0x8000CB8C: jal         0x80017E98
    // 0x8000CB90: nop

    checkpoint_update_all(rdram, ctx);
        goto after_11;
    // 0x8000CB90: nop

    after_11:
    // 0x8000CB94: jal         0x8001BC54
    // 0x8000CB98: nop

    spectate_update(rdram, ctx);
        goto after_12;
    // 0x8000CB98: nop

    after_12:
    // 0x8000CB9C: jal         0x8001E93C
    // 0x8000CBA0: nop

    func_8001E93C(rdram, ctx);
        goto after_13;
    // 0x8000CBA0: nop

    after_13:
L_8000CBA4:
    // 0x8000CBA4: sw          $s0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r16;
    // 0x8000CBA8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_8000CBAC:
    // 0x8000CBAC: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8000CBB0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8000CBB4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8000CBB8: jr          $ra
    // 0x8000CBBC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x8000CBBC: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void generate_track(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002C0C4: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x8002C0C8: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8002C0CC: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8002C0D0: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8002C0D4: lui         $a0, 0xFF
    ctx->r4 = S32(0XFF << 16);
    // 0x8002C0D8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x8002C0DC: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x8002C0E0: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8002C0E4: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8002C0E8: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8002C0EC: jal         0x8007B374
    // 0x8002C0F0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    set_texture_colour_tag(rdram, ctx);
        goto after_0;
    // 0x8002C0F0: ori         $a0, $a0, 0xFF
    ctx->r4 = ctx->r4 | 0XFF;
    after_0:
    // 0x8002C0F4: lui         $s5, 0x8
    ctx->r21 = S32(0X8 << 16);
    // 0x8002C0F8: ori         $s5, $s5, 0x2A00
    ctx->r21 = ctx->r21 | 0X2A00;
    extern void dkr_custom_tracks_track_heap(uint8_t*, recomp_context*); dkr_custom_tracks_track_heap(rdram, ctx);
    // 0x8002C0FC: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8002C100: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8002C104: jal         0x80070C9C
    // 0x8002C108: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    mempool_alloc_safe(rdram, ctx);
        goto after_1;
    // 0x8002C108: or          $a0, $s5, $zero
    ctx->r4 = ctx->r21 | 0;
    after_1:
    // 0x8002C10C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8002C110: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8002C114: addiu       $s1, $s1, -0x36E8
    ctx->r17 = ADD32(ctx->r17, -0X36E8);
    // 0x8002C118: addiu       $v1, $v1, -0x2CF4
    ctx->r3 = ADD32(ctx->r3, -0X2CF4);
    // 0x8002C11C: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8002C120: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x8002C124: sw          $v0, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r2;
    // 0x8002C128: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8002C12C: jal         0x80070C9C
    // 0x8002C130: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x8002C130: addiu       $a0, $zero, 0x7D0
    ctx->r4 = ADD32(0, 0X7D0);
    after_2:
    // 0x8002C134: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002C138: lui         $a1, 0xFFFF
    ctx->r5 = S32(0XFFFF << 16);
    // 0x8002C13C: sw          $v0, -0x2C90($at)
    MEM_W(-0X2C90, ctx->r1) = ctx->r2;
    // 0x8002C140: ori         $a1, $a1, 0xFF
    ctx->r5 = ctx->r5 | 0XFF;
    // 0x8002C144: jal         0x80070C9C
    // 0x8002C148: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x8002C148: addiu       $a0, $zero, 0x1F4
    ctx->r4 = ADD32(0, 0X1F4);
    after_3:
    // 0x8002C14C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002C150: sw          $v0, -0x2C8C($at)
    MEM_W(-0X2C8C, ctx->r1) = ctx->r2;
    // 0x8002C154: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002C158: sw          $zero, -0x2C88($at)
    MEM_W(-0X2C88, ctx->r1) = 0;
    // 0x8002C15C: jal         0x80076C58
    // 0x8002C160: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    asset_table_load(rdram, ctx);
        goto after_4;
    // 0x8002C160: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_4:
    // 0x8002C164: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002C168: addiu       $s4, $s4, -0x2CF0
    ctx->r20 = ADD32(ctx->r20, -0X2CF0);
    // 0x8002C16C: sw          $v0, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r2;
    // 0x8002C170: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x8002C174: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8002C178: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8002C17C: beq         $v1, $t7, L_8002C194
    if (ctx->r3 == ctx->r15) {
        // 0x8002C180: or          $t0, $v0, $zero
        ctx->r8 = ctx->r2 | 0;
            goto L_8002C194;
    }
    // 0x8002C180: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
L_8002C184:
    // 0x8002C184: lw          $t8, 0x4($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X4);
    // 0x8002C188: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8002C18C: bne         $v1, $t8, L_8002C184
    if (ctx->r3 != ctx->r24) {
        // 0x8002C190: addiu       $v0, $v0, 0x4
        ctx->r2 = ADD32(ctx->r2, 0X4);
            goto L_8002C184;
    }
    // 0x8002C190: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
L_8002C194:
    // 0x8002C194: addiu       $t4, $t4, -0x1
    ctx->r12 = ADD32(ctx->r12, -0X1);
    // 0x8002C198: slt         $at, $s2, $t4
    ctx->r1 = SIGNED(ctx->r18) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8002C19C: bne         $at, $zero, L_8002C1A8
    if (ctx->r1 != 0) {
        // 0x8002C1A0: addiu       $a0, $zero, 0x1B
        ctx->r4 = ADD32(0, 0X1B);
            goto L_8002C1A8;
    }
    // 0x8002C1A0: addiu       $a0, $zero, 0x1B
    ctx->r4 = ADD32(0, 0X1B);
    // 0x8002C1A4: or          $s2, $zero, $zero
    ctx->r18 = 0 | 0;
L_8002C1A8:
    // 0x8002C1A8: sll         $t9, $s2, 2
    ctx->r25 = S32(ctx->r18 << 2);
    // 0x8002C1AC: addu        $v0, $t0, $t9
    ctx->r2 = ADD32(ctx->r8, ctx->r25);
    // 0x8002C1B0: lw          $a2, 0x0($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X0);
    // 0x8002C1B4: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8002C1B8: lw          $s0, 0x0($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X0);
    // 0x8002C1BC: subu        $s3, $t5, $a2
    ctx->r19 = SUB32(ctx->r13, ctx->r6);
    // 0x8002C1C0: addu        $t6, $s0, $s5
    ctx->r14 = ADD32(ctx->r16, ctx->r21);
    // 0x8002C1C4: subu        $s0, $t6, $s3
    ctx->r16 = SUB32(ctx->r14, ctx->r19);
    // 0x8002C1C8: bgez        $s0, L_8002C1DC
    if (SIGNED(ctx->r16) >= 0) {
        // 0x8002C1CC: andi        $t7, $s0, 0xF
        ctx->r15 = ctx->r16 & 0XF;
            goto L_8002C1DC;
    }
    // 0x8002C1CC: andi        $t7, $s0, 0xF
    ctx->r15 = ctx->r16 & 0XF;
    // 0x8002C1D0: beq         $t7, $zero, L_8002C1DC
    if (ctx->r15 == 0) {
        // 0x8002C1D4: nop
    
            goto L_8002C1DC;
    }
    // 0x8002C1D4: nop

    // 0x8002C1D8: addiu       $t7, $t7, -0x10
    ctx->r15 = ADD32(ctx->r15, -0X10);
L_8002C1DC:
    // 0x8002C1DC: subu        $s0, $s0, $t7
    ctx->r16 = SUB32(ctx->r16, ctx->r15);
    // 0x8002C1E0: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8002C1E4: jal         0x80076E68
    // 0x8002C1E8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    asset_load(rdram, ctx);
        goto after_5;
    // 0x8002C1E8: or          $a3, $s3, $zero
    ctx->r7 = ctx->r19 | 0;
    after_5:
    // 0x8002C1EC: lw          $a1, 0x0($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X0);
    // 0x8002C1F0: jal         0x800C6218
    // 0x8002C1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    gzip_inflate(rdram, ctx);
        goto after_6;
    // 0x8002C1F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_6:
    // 0x8002C1F8: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x8002C1FC: jal         0x80071140
    // 0x8002C200: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8002C200: nop

    after_7:
    // 0x8002C204: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C208: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8002C20C: lw          $t8, 0x0($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X0);
    // 0x8002C210: or          $a2, $s2, $zero
    ctx->r6 = ctx->r18 | 0;
    // 0x8002C214: addu        $t9, $t8, $s2
    ctx->r25 = ADD32(ctx->r24, ctx->r18);
    // 0x8002C218: sw          $t9, 0x0($s2)
    MEM_W(0X0, ctx->r18) = ctx->r25;
    // 0x8002C21C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C220: nop

    // 0x8002C224: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x8002C228: nop

    // 0x8002C22C: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8002C230: sw          $t6, 0x4($s2)
    MEM_W(0X4, ctx->r18) = ctx->r14;
    // 0x8002C234: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C238: nop

    // 0x8002C23C: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x8002C240: nop

    // 0x8002C244: addu        $t8, $t7, $a2
    ctx->r24 = ADD32(ctx->r15, ctx->r6);
    // 0x8002C248: sw          $t8, 0x8($s2)
    MEM_W(0X8, ctx->r18) = ctx->r24;
    // 0x8002C24C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C250: nop

    // 0x8002C254: lw          $t9, 0xC($s2)
    ctx->r25 = MEM_W(ctx->r18, 0XC);
    // 0x8002C258: nop

    // 0x8002C25C: addu        $t5, $t9, $a2
    ctx->r13 = ADD32(ctx->r25, ctx->r6);
    // 0x8002C260: sw          $t5, 0xC($s2)
    MEM_W(0XC, ctx->r18) = ctx->r13;
    // 0x8002C264: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C268: nop

    // 0x8002C26C: lw          $t6, 0x10($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X10);
    // 0x8002C270: nop

    // 0x8002C274: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8002C278: sw          $t7, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r15;
    // 0x8002C27C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C280: nop

    // 0x8002C284: lw          $t8, 0x14($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X14);
    // 0x8002C288: nop

    // 0x8002C28C: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8002C290: sw          $t9, 0x14($s2)
    MEM_W(0X14, ctx->r18) = ctx->r25;
    // 0x8002C294: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C298: nop

    // 0x8002C29C: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C2A0: nop

    // 0x8002C2A4: blez        $v1, L_8002C354
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002C2A8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8002C354;
    }
    // 0x8002C2A8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
L_8002C2AC:
    // 0x8002C2AC: lw          $t5, 0x4($s2)
    ctx->r13 = MEM_W(ctx->r18, 0X4);
    // 0x8002C2B0: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C2B4: addu        $v0, $t5, $s3
    ctx->r2 = ADD32(ctx->r13, ctx->r19);
    // 0x8002C2B8: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8002C2BC: nop

    // 0x8002C2C0: addu        $t7, $t6, $a2
    ctx->r15 = ADD32(ctx->r14, ctx->r6);
    // 0x8002C2C4: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8002C2C8: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002C2CC: nop

    // 0x8002C2D0: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002C2D4: nop

    // 0x8002C2D8: addu        $v0, $t9, $s3
    ctx->r2 = ADD32(ctx->r25, ctx->r19);
    // 0x8002C2DC: lw          $t5, 0x4($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X4);
    // 0x8002C2E0: nop

    // 0x8002C2E4: addu        $t6, $t5, $a2
    ctx->r14 = ADD32(ctx->r13, ctx->r6);
    // 0x8002C2E8: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x8002C2EC: lw          $t7, 0x0($s1)
    ctx->r15 = MEM_W(ctx->r17, 0X0);
    // 0x8002C2F0: nop

    // 0x8002C2F4: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8002C2F8: nop

    // 0x8002C2FC: addu        $v0, $t8, $s3
    ctx->r2 = ADD32(ctx->r24, ctx->r19);
    // 0x8002C300: lw          $t9, 0xC($v0)
    ctx->r25 = MEM_W(ctx->r2, 0XC);
    // 0x8002C304: nop

    // 0x8002C308: addu        $t5, $t9, $a2
    ctx->r13 = ADD32(ctx->r25, ctx->r6);
    // 0x8002C30C: sw          $t5, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r13;
    // 0x8002C310: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C314: nop

    // 0x8002C318: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C31C: nop

    // 0x8002C320: addu        $v0, $t7, $s3
    ctx->r2 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C324: lw          $t8, 0x14($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X14);
    // 0x8002C328: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
    // 0x8002C32C: addu        $t9, $t8, $a2
    ctx->r25 = ADD32(ctx->r24, ctx->r6);
    // 0x8002C330: sw          $t9, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->r25;
    // 0x8002C334: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C338: nop

    // 0x8002C33C: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C340: nop

    // 0x8002C344: slt         $at, $s0, $v1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002C348: bne         $at, $zero, L_8002C2AC
    if (ctx->r1 != 0) {
        // 0x8002C34C: nop
    
            goto L_8002C2AC;
    }
    // 0x8002C34C: nop

    // 0x8002C350: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002C354:
    // 0x8002C354: lh          $t5, 0x18($s2)
    ctx->r13 = MEM_H(ctx->r18, 0X18);
    // 0x8002C358: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002C35C: blez        $t5, L_8002C3C0
    if (SIGNED(ctx->r13) <= 0) {
        // 0x8002C360: nop
    
            goto L_8002C3C0;
    }
    // 0x8002C360: nop

L_8002C364:
    // 0x8002C364: lw          $t6, 0x0($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X0);
    // 0x8002C368: nop

    // 0x8002C36C: addu        $t7, $t6, $s3
    ctx->r15 = ADD32(ctx->r14, ctx->r19);
    // 0x8002C370: lw          $a0, 0x0($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X0);
    // 0x8002C374: nop

    // 0x8002C378: ori         $t8, $a0, 0x8000
    ctx->r24 = ctx->r4 | 0X8000;
    // 0x8002C37C: jal         0x8007AE74
    // 0x8002C380: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    load_texture(rdram, ctx);
        goto after_8;
    // 0x8002C380: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    after_8:
    // 0x8002C384: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002C388: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C38C: lw          $t5, 0x0($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X0);
    // 0x8002C390: nop

    // 0x8002C394: addu        $t6, $t5, $s3
    ctx->r14 = ADD32(ctx->r13, ctx->r19);
    // 0x8002C398: sw          $v0, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r2;
    // 0x8002C39C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C3A0: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x8002C3A4: lh          $t7, 0x18($s2)
    ctx->r15 = MEM_H(ctx->r18, 0X18);
    // 0x8002C3A8: nop

    // 0x8002C3AC: slt         $at, $s0, $t7
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002C3B0: bne         $at, $zero, L_8002C364
    if (ctx->r1 != 0) {
        // 0x8002C3B4: nop
    
            goto L_8002C364;
    }
    // 0x8002C3B4: nop

    // 0x8002C3B8: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C3BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_8002C3C0:
    // 0x8002C3C0: lw          $t8, 0x48($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X48);
    // 0x8002C3C4: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x8002C3C8: blez        $v1, L_8002C4EC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002C3CC: addu        $s4, $s2, $t8
        ctx->r20 = ADD32(ctx->r18, ctx->r24);
            goto L_8002C4EC;
    }
    // 0x8002C3CC: addu        $s4, $s2, $t8
    ctx->r20 = ADD32(ctx->r18, ctx->r24);
    // 0x8002C3D0: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002C3D4: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
L_8002C3D8:
    // 0x8002C3D8: lw          $t9, 0x4($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X4);
    // 0x8002C3DC: nop

    // 0x8002C3E0: addu        $t5, $t9, $s3
    ctx->r13 = ADD32(ctx->r25, ctx->r19);
    // 0x8002C3E4: sw          $s4, 0x10($t5)
    MEM_W(0X10, ctx->r13) = ctx->r20;
    // 0x8002C3E8: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C3EC: nop

    // 0x8002C3F0: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C3F4: nop

    // 0x8002C3F8: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C3FC: lh          $t9, 0x1E($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X1E);
    // 0x8002C400: nop

    // 0x8002C404: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8002C408: jal         0x80071850
    // 0x8002C40C: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    align16(rdram, ctx);
        goto after_9;
    // 0x8002C40C: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    after_9:
    // 0x8002C410: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C414: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002C418: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C41C: nop

    // 0x8002C420: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C424: sw          $v0, 0x18($t8)
    MEM_W(0X18, ctx->r24) = ctx->r2;
    // 0x8002C428: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002C42C: nop

    // 0x8002C430: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8002C434: jal         0x8002CC30
    // 0x8002C438: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    track_init_collision(rdram, ctx);
        goto after_10;
    // 0x8002C438: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    after_10:
    // 0x8002C43C: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C440: addu        $s4, $v0, $s4
    ctx->r20 = ADD32(ctx->r2, ctx->r20);
    // 0x8002C444: lw          $t6, 0x4($s2)
    ctx->r14 = MEM_W(ctx->r18, 0X4);
    // 0x8002C448: lw          $t7, 0x8($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X8);
    // 0x8002C44C: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    // 0x8002C450: addu        $a0, $t6, $s3
    ctx->r4 = ADD32(ctx->r14, ctx->r19);
    // 0x8002C454: jal         0x8002C954
    // 0x8002C458: addu        $a1, $t7, $s5
    ctx->r5 = ADD32(ctx->r15, ctx->r21);
    func_8002C954(rdram, ctx);
        goto after_11;
    // 0x8002C458: addu        $a1, $t7, $s5
    ctx->r5 = ADD32(ctx->r15, ctx->r21);
    after_11:
    // 0x8002C45C: lw          $t8, 0x0($s1)
    ctx->r24 = MEM_W(ctx->r17, 0X0);
    // 0x8002C460: nop

    // 0x8002C464: lw          $t9, 0x4($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X4);
    // 0x8002C468: nop

    // 0x8002C46C: addu        $t5, $t9, $s3
    ctx->r13 = ADD32(ctx->r25, ctx->r19);
    // 0x8002C470: sh          $zero, 0x30($t5)
    MEM_H(0X30, ctx->r13) = 0;
    // 0x8002C474: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C478: nop

    // 0x8002C47C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C480: nop

    // 0x8002C484: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C488: sw          $s4, 0x34($t8)
    MEM_W(0X34, ctx->r24) = ctx->r20;
    // 0x8002C48C: lw          $t9, 0x0($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X0);
    // 0x8002C490: nop

    // 0x8002C494: lw          $t5, 0x4($t9)
    ctx->r13 = MEM_W(ctx->r25, 0X4);
    // 0x8002C498: jal         0x8002C71C
    // 0x8002C49C: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    func_8002C71C(rdram, ctx);
        goto after_12;
    // 0x8002C49C: addu        $a0, $t5, $s3
    ctx->r4 = ADD32(ctx->r13, ctx->r19);
    after_12:
    // 0x8002C4A0: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4A4: nop

    // 0x8002C4A8: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C4AC: nop

    // 0x8002C4B0: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8002C4B4: lh          $t9, 0x32($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X32);
    // 0x8002C4B8: nop

    // 0x8002C4BC: sll         $t5, $t9, 1
    ctx->r13 = S32(ctx->r25 << 1);
    // 0x8002C4C0: jal         0x80071850
    // 0x8002C4C4: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    align16(rdram, ctx);
        goto after_13;
    // 0x8002C4C4: addu        $a0, $t5, $s4
    ctx->r4 = ADD32(ctx->r13, ctx->r20);
    after_13:
    // 0x8002C4C8: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C4CC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C4D0: lh          $t6, 0x1A($s2)
    ctx->r14 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C4D4: addiu       $s3, $s3, 0x44
    ctx->r19 = ADD32(ctx->r19, 0X44);
    // 0x8002C4D8: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002C4DC: addiu       $s5, $s5, 0xC
    ctx->r21 = ADD32(ctx->r21, 0XC);
    // 0x8002C4E0: bne         $at, $zero, L_8002C3D8
    if (ctx->r1 != 0) {
        // 0x8002C4E4: or          $s4, $v0, $zero
        ctx->r20 = ctx->r2 | 0;
            goto L_8002C3D8;
    }
    // 0x8002C4E4: or          $s4, $v0, $zero
    ctx->r20 = ctx->r2 | 0;
    // 0x8002C4E8: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
L_8002C4EC:
    // 0x8002C4EC: lui         $at, 0x8
    ctx->r1 = S32(0X8 << 16);
    // 0x8002C4F0: subu        $s3, $s4, $v0
    ctx->r19 = SUB32(ctx->r20, ctx->r2);
    // 0x8002C4F4: ori         $at, $at, 0x2A01
    ctx->r1 = ctx->r1 | 0X2A01;
    // 0x8002C4F8: slt         $at, $s3, $at
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8002C4FC: bne         $at, $zero, L_8002C510
    if (ctx->r1 != 0) {
        // 0x8002C500: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_8002C510;
    }
    // 0x8002C500: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8002C504: addiu       $a0, $a0, 0x5E38
    ctx->r4 = ADD32(ctx->r4, 0X5E38);
    // 0x8002C508: jal         0x800C9D54
    // 0x8002C50C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    rmonPrintf_recomp(rdram, ctx);
        goto after_14;
    // 0x8002C50C: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_14:
L_8002C510:
    // 0x8002C510: jal         0x800710B0
    // 0x8002C514: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_15;
    // 0x8002C514: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_15:
    // 0x8002C518: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002C51C: lw          $a0, -0x2CF4($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2CF4);
    // 0x8002C520: jal         0x80071140
    // 0x8002C524: nop

    mempool_free(rdram, ctx);
        goto after_16;
    // 0x8002C524: nop

    after_16:
    // 0x8002C528: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8002C52C: lw          $a1, -0x2CF4($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X2CF4);
    // 0x8002C530: lui         $a2, 0xFFFF
    ctx->r6 = S32(0XFFFF << 16);
    // 0x8002C534: ori         $a2, $a2, 0xFF
    ctx->r6 = ctx->r6 | 0XFF;
    // 0x8002C538: jal         0x80070EF8
    // 0x8002C53C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    mempool_alloc_fixed(rdram, ctx);
        goto after_17;
    // 0x8002C53C: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_17:
    // 0x8002C540: jal         0x800710B0
    // 0x8002C544: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_18;
    // 0x8002C544: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_18:
    // 0x8002C548: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002C54C: jal         0x800A83B4
    // 0x8002C550: nop

    minimap_init(rdram, ctx);
        goto after_19;
    // 0x8002C550: nop

    after_19:
    // 0x8002C554: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C558: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8002C55C: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C560: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8002C564: blez        $v1, L_8002C6EC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8002C568: lui         $t3, 0x800
        ctx->r11 = S32(0X800 << 16);
            goto L_8002C6EC;
    }
    // 0x8002C568: lui         $t3, 0x800
    ctx->r11 = S32(0X800 << 16);
    // 0x8002C56C: lw          $a2, 0x4($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X4);
    // 0x8002C570: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8002C574: addiu       $a3, $zero, 0x80
    ctx->r7 = ADD32(0, 0X80);
L_8002C578:
    // 0x8002C578: lh          $v0, 0x20($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X20);
    // 0x8002C57C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8002C580: blez        $v0, L_8002C6DC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8002C584: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8002C6DC;
    }
    // 0x8002C584: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8002C588: lw          $a0, 0xC($a2)
    ctx->r4 = MEM_W(ctx->r6, 0XC);
    // 0x8002C58C: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
L_8002C590:
    // 0x8002C590: lh          $s0, 0x2($a0)
    ctx->r16 = MEM_H(ctx->r4, 0X2);
    // 0x8002C594: lh          $t1, 0xE($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XE);
    // 0x8002C598: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002C59C: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C5A0: beq         $at, $zero, L_8002C6C8
    if (ctx->r1 == 0) {
        // 0x8002C5A4: slt         $at, $s3, $v0
        ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8002C6C8;
    }
    // 0x8002C5A4: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8002C5A8: sll         $v0, $s0, 2
    ctx->r2 = S32(ctx->r16 << 2);
    // 0x8002C5AC: addu        $v0, $v0, $s0
    ctx->r2 = ADD32(ctx->r2, ctx->r16);
    // 0x8002C5B0: sll         $v0, $v0, 1
    ctx->r2 = S32(ctx->r2 << 1);
L_8002C5B4:
    // 0x8002C5B4: lw          $t7, 0x0($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X0);
    // 0x8002C5B8: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8002C5BC: addu        $v1, $t7, $v0
    ctx->r3 = ADD32(ctx->r15, ctx->r2);
    // 0x8002C5C0: lbu         $t8, 0x6($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X6);
    // 0x8002C5C4: nop

    // 0x8002C5C8: bne         $t2, $t8, L_8002C6B4
    if (ctx->r10 != ctx->r24) {
        // 0x8002C5CC: slt         $at, $s0, $t1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8002C6B4;
    }
    // 0x8002C5CC: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C5D0: lbu         $t9, 0x7($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X7);
    // 0x8002C5D4: nop

    // 0x8002C5D8: bne         $t2, $t9, L_8002C6B4
    if (ctx->r10 != ctx->r25) {
        // 0x8002C5DC: slt         $at, $s0, $t1
        ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
            goto L_8002C6B4;
    }
    // 0x8002C5DC: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x8002C5E0: lbu         $t5, 0x8($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X8);
    // 0x8002C5E4: nop

    // 0x8002C5E8: sb          $t5, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r13;
    // 0x8002C5EC: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C5F0: nop

    // 0x8002C5F4: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C5F8: nop

    // 0x8002C5FC: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C600: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C604: nop

    // 0x8002C608: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C60C: sb          $a3, 0x6($t5)
    MEM_B(0X6, ctx->r13) = ctx->r7;
    // 0x8002C610: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C614: nop

    // 0x8002C618: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C61C: nop

    // 0x8002C620: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C624: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C628: nop

    // 0x8002C62C: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C630: sb          $a3, 0x7($t5)
    MEM_B(0X7, ctx->r13) = ctx->r7;
    // 0x8002C634: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C638: nop

    // 0x8002C63C: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C640: nop

    // 0x8002C644: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C648: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8002C64C: nop

    // 0x8002C650: addu        $t5, $t9, $v0
    ctx->r13 = ADD32(ctx->r25, ctx->r2);
    // 0x8002C654: sb          $a3, 0x8($t5)
    MEM_B(0X8, ctx->r13) = ctx->r7;
    // 0x8002C658: lw          $t6, 0x0($s1)
    ctx->r14 = MEM_W(ctx->r17, 0X0);
    // 0x8002C65C: nop

    // 0x8002C660: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8002C664: nop

    // 0x8002C668: addu        $t8, $t7, $a1
    ctx->r24 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C66C: lw          $t9, 0xC($t8)
    ctx->r25 = MEM_W(ctx->r24, 0XC);
    // 0x8002C670: nop

    // 0x8002C674: addu        $a0, $t9, $t0
    ctx->r4 = ADD32(ctx->r25, ctx->r8);
    // 0x8002C678: lw          $t5, 0x8($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X8);
    // 0x8002C67C: nop

    // 0x8002C680: or          $t6, $t5, $t3
    ctx->r14 = ctx->r13 | ctx->r11;
    // 0x8002C684: sw          $t6, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r14;
    // 0x8002C688: lw          $s2, 0x0($s1)
    ctx->r18 = MEM_W(ctx->r17, 0X0);
    // 0x8002C68C: nop

    // 0x8002C690: lw          $t7, 0x4($s2)
    ctx->r15 = MEM_W(ctx->r18, 0X4);
    // 0x8002C694: nop

    // 0x8002C698: addu        $a2, $t7, $a1
    ctx->r6 = ADD32(ctx->r15, ctx->r5);
    // 0x8002C69C: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x8002C6A0: nop

    // 0x8002C6A4: addu        $a0, $t8, $t0
    ctx->r4 = ADD32(ctx->r24, ctx->r8);
    // 0x8002C6A8: lh          $t1, 0xE($a0)
    ctx->r9 = MEM_H(ctx->r4, 0XE);
    // 0x8002C6AC: nop

    // 0x8002C6B0: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
L_8002C6B4:
    // 0x8002C6B4: bne         $at, $zero, L_8002C5B4
    if (ctx->r1 != 0) {
        // 0x8002C6B8: addiu       $v0, $v0, 0xA
        ctx->r2 = ADD32(ctx->r2, 0XA);
            goto L_8002C5B4;
    }
    // 0x8002C6B8: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x8002C6BC: lh          $v0, 0x20($a2)
    ctx->r2 = MEM_H(ctx->r6, 0X20);
    // 0x8002C6C0: nop

    // 0x8002C6C4: slt         $at, $s3, $v0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r2) ? 1 : 0;
L_8002C6C8:
    // 0x8002C6C8: addiu       $t0, $t0, 0xC
    ctx->r8 = ADD32(ctx->r8, 0XC);
    // 0x8002C6CC: bne         $at, $zero, L_8002C590
    if (ctx->r1 != 0) {
        // 0x8002C6D0: addiu       $a0, $a0, 0xC
        ctx->r4 = ADD32(ctx->r4, 0XC);
            goto L_8002C590;
    }
    // 0x8002C6D0: addiu       $a0, $a0, 0xC
    ctx->r4 = ADD32(ctx->r4, 0XC);
    // 0x8002C6D4: lh          $v1, 0x1A($s2)
    ctx->r3 = MEM_H(ctx->r18, 0X1A);
    // 0x8002C6D8: nop

L_8002C6DC:
    // 0x8002C6DC: slt         $at, $t4, $v1
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8002C6E0: addiu       $a1, $a1, 0x44
    ctx->r5 = ADD32(ctx->r5, 0X44);
    // 0x8002C6E4: bne         $at, $zero, L_8002C578
    if (ctx->r1 != 0) {
        // 0x8002C6E8: addiu       $a2, $a2, 0x44
        ctx->r6 = ADD32(ctx->r6, 0X44);
            goto L_8002C578;
    }
    // 0x8002C6E8: addiu       $a2, $a2, 0x44
    ctx->r6 = ADD32(ctx->r6, 0X44);
L_8002C6EC:
    // 0x8002C6EC: lui         $a0, 0xFF00
    ctx->r4 = S32(0XFF00 << 16);
    // 0x8002C6F0: jal         0x8007B374
    // 0x8002C6F4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    set_texture_colour_tag(rdram, ctx);
        goto after_20;
    // 0x8002C6F4: ori         $a0, $a0, 0xFFFF
    ctx->r4 = ctx->r4 | 0XFFFF;
    after_20:
    // 0x8002C6F8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8002C6FC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8002C700: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8002C704: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8002C708: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8002C70C: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x8002C710: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x8002C714: jr          $ra
    // 0x8002C718: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    return;
    // 0x8002C718: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
;}
RECOMP_FUNC void waves_block_hq(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B9228: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800B922C: lw          $a1, -0x5F20($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X5F20);
    // 0x800B9230: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x800B9234: blez        $a1, L_800B9284
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800B9238: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800B9284;
    }
    // 0x800B9238: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800B923C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800B9240: lw          $a2, 0x30D8($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X30D8);
    // 0x800B9244: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x800B9248: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800B924C: nop

    // 0x800B9250: beq         $a0, $t6, L_800B9284
    if (ctx->r4 == ctx->r14) {
        // 0x800B9254: nop
    
            goto L_800B9284;
    }
    // 0x800B9254: nop

L_800B9258:
    // 0x800B9258: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x800B925C: slt         $at, $v0, $a1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x800B9260: beq         $at, $zero, L_800B9284
    if (ctx->r1 == 0) {
        // 0x800B9264: nop
    
            goto L_800B9284;
    }
    // 0x800B9264: nop

    // 0x800B9268: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B926C: mflo        $t7
    ctx->r15 = lo;
    // 0x800B9270: addu        $t8, $a2, $t7
    ctx->r24 = ADD32(ctx->r6, ctx->r15);
    // 0x800B9274: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x800B9278: nop

    // 0x800B927C: bne         $a0, $t9, L_800B9258
    if (ctx->r4 != ctx->r25) {
        // 0x800B9280: nop
    
            goto L_800B9258;
    }
    // 0x800B9280: nop

L_800B9284:
    // 0x800B9284: addiu       $a3, $zero, 0x1C
    ctx->r7 = ADD32(0, 0X1C);
    // 0x800B9288: multu       $v0, $a3
    result = U64(U32(ctx->r2)) * U64(U32(ctx->r7)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800B928C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800B9290: lw          $t0, 0x30D8($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X30D8);
    // 0x800B9294: lui         $t5, 0x800E
    ctx->r13 = S32(0X800E << 16);
    // 0x800B9298: lw          $t5, 0x30D4($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X30D4);
    // 0x800B929C: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800B92A0: addiu       $a1, $a1, 0x30DC
    ctx->r5 = ADD32(ctx->r5, 0X30DC);
    // 0x800B92A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800B92A8: mflo        $t1
    ctx->r9 = lo;
    // 0x800B92AC: addu        $t2, $t0, $t1
    ctx->r10 = ADD32(ctx->r8, ctx->r9);
    // 0x800B92B0: lw          $t3, 0xC($t2)
    ctx->r11 = MEM_W(ctx->r10, 0XC);
    // 0x800B92B4: nop

    // 0x800B92B8: sll         $t4, $t3, 2
    ctx->r12 = S32(ctx->r11 << 2);
    // 0x800B92BC: addu        $t6, $t5, $t4
    ctx->r14 = ADD32(ctx->r13, ctx->r12);
    // 0x800B92C0: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x800B92C4: nop

    // 0x800B92C8: beq         $t7, $zero, L_800B92EC
    if (ctx->r15 == 0) {
        // 0x800B92CC: nop
    
            goto L_800B92EC;
    }
    // 0x800B92CC: nop

    // 0x800B92D0: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x800B92D4: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800B92D8: sll         $t8, $a0, 1
    ctx->r24 = S32(ctx->r4 << 1);
    // 0x800B92DC: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800B92E0: sh          $v0, -0x5E18($at)
    MEM_H(-0X5E18, ctx->r1) = ctx->r2;
    // 0x800B92E4: addiu       $t9, $a0, 0x1
    ctx->r25 = ADD32(ctx->r4, 0X1);
    // 0x800B92E8: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
L_800B92EC:
    // 0x800B92EC: jr          $ra
    // 0x800B92F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800B92F0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void load_level_game(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern void dkr_netplay_gameplay_level_begin(uint8_t*, recomp_context*); dkr_netplay_gameplay_level_begin(rdram, ctx); extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 14U, dkr_legacy_fields, 0U); }
    // 0x8006CB58: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006CB5C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006CB60: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006CB64: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006CB68: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006CB6C: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x8006CB70: jal         0x8006ECFC
    // 0x8006CB74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    alloc_displaylist_heap(rdram, ctx);
        goto after_0;
    // 0x8006CB74: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x8006CB78: jal         0x800710B0
    // 0x8006CB7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    mempool_free_timer(rdram, ctx);
        goto after_1;
    // 0x8006CB7C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_1:
    // 0x8006CB80: jal         0x80065EA0
    // 0x8006CB84: nop

    cam_init(rdram, ctx);
        goto after_2;
    // 0x8006CB84: nop

    after_2:
    // 0x8006CB88: jal         0x800C3048
    // 0x8006CB8C: nop

    load_game_text_table(rdram, ctx);
        goto after_3;
    // 0x8006CB8C: nop

    after_3:
    // 0x8006CB90: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006CB94: lw          $t6, 0x3508($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3508);
    // 0x8006CB98: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006CB9C: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8006CBA0: lw          $a2, 0x28($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X28);
    // 0x8006CBA4: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x8006CBA8: jal         0x8006B250
    // 0x8006CBAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    level_load(rdram, ctx);
        goto after_4;
    // 0x8006CBAC: sw          $t6, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r14;
    after_4:
    // 0x8006CBB0: jal         0x80066210
    // 0x8006CBB4: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_5;
    // 0x8006CBB4: nop

    after_5:
    // 0x8006CBB8: jal         0x8009ECF0
    // 0x8006CBBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    hud_init(rdram, ctx);
        goto after_6;
    // 0x8006CBBC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x8006CBC0: addiu       $t7, $zero, 0x32
    ctx->r15 = ADD32(0, 0X32);
    // 0x8006CBC4: sw          $t7, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r15;
    // 0x8006CBC8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    // 0x8006CBCC: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    // 0x8006CBD0: addiu       $a2, $zero, 0x96
    ctx->r6 = ADD32(0, 0X96);
    // 0x8006CBD4: addiu       $a3, $zero, 0x64
    ctx->r7 = ADD32(0, 0X64);
    // 0x8006CBD8: jal         0x800AE728
    // 0x8006CBDC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    init_particle_buffers(rdram, ctx);
        goto after_7;
    // 0x8006CBDC: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    after_7:
    // 0x8006CBE0: jal         0x8001BF20
    // 0x8006CBE4: nop

    ainode_update(rdram, ctx);
        goto after_8;
    // 0x8006CBE4: nop

    after_8:
    // 0x8006CBE8: addiu       $a0, $zero, 0x0
    ctx->r4 = ADD32(0, 0X0);
    // 0x8006CBEC: jal         0x800CD260
    // 0x8006CBF0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    osSetTime_recomp(rdram, ctx);
        goto after_9;
    // 0x8006CBF0: addiu       $a1, $zero, 0x0
    ctx->r5 = ADD32(0, 0X0);
    after_9:
    // 0x8006CBF4: jal         0x800710B0
    // 0x8006CBF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    mempool_free_timer(rdram, ctx);
        goto after_10;
    // 0x8006CBF8: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_10:
    // 0x8006CBFC: jal         0x80072298
    // 0x8006CC00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_init(rdram, ctx);
        goto after_11;
    // 0x8006CC00: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_11:
    extern void dkr_netplay_gameplay_level_ready(uint8_t*, recomp_context*); dkr_netplay_gameplay_level_ready(rdram, ctx);
    // 0x8006CC04: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006CC08: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x8006CC0C: jr          $ra
    // 0x8006CC10: nop

    return;
    // 0x8006CC10: nop

;}
RECOMP_FUNC void update_camera_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8004D590: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x8004D594: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8004D598: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8004D59C: lw          $v0, -0x2AC0($v0)
    ctx->r2 = MEM_W(ctx->r2, -0X2AC0);
    // 0x8004D5A0: addiu       $sp, $sp, -0xA8
    ctx->r29 = ADD32(ctx->r29, -0XA8);
    // 0x8004D5A4: slti        $at, $v0, 0x3D
    ctx->r1 = SIGNED(ctx->r2) < 0X3D ? 1 : 0;
    // 0x8004D5A8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8004D5AC: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8004D5B0: swc1        $f12, 0xA8($sp)
    MEM_W(0XA8, ctx->r29) = ctx->f12.u32l;
    // 0x8004D5B4: sw          $a1, 0xAC($sp)
    MEM_W(0XAC, ctx->r29) = ctx->r5;
    // 0x8004D5B8: bne         $at, $zero, L_8004D5E0
    if (ctx->r1 != 0) {
        // 0x8004D5BC: mov.s       $f14, $f0
        CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
            goto L_8004D5E0;
    }
    // 0x8004D5BC: mov.s       $f14, $f0
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    ctx->f14.fl = ctx->f0.fl;
    // 0x8004D5C0: addiu       $t6, $v0, -0x3C
    ctx->r14 = ADD32(ctx->r2, -0X3C);
    // 0x8004D5C4: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x8004D5C8: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x8004D5CC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8004D5D0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8004D5D4: nop

    // 0x8004D5D8: mul.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f8.fl);
    // 0x8004D5DC: add.s       $f14, $f0, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f0.fl + ctx->f10.fl;
L_8004D5E0:
    // 0x8004D5E0: lh          $t7, 0x1A0($a2)
    ctx->r15 = MEM_H(ctx->r6, 0X1A0);
    // 0x8004D5E4: ori         $t8, $zero, 0x8000
    ctx->r24 = 0 | 0X8000;
    // 0x8004D5E8: subu        $t9, $t8, $t7
    ctx->r25 = SUB32(ctx->r24, ctx->r15);
    // 0x8004D5EC: sh          $t9, 0x196($a2)
    MEM_H(0X196, ctx->r6) = ctx->r25;
    // 0x8004D5F0: swc1        $f14, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->f14.u32l;
    // 0x8004D5F4: jal         0x80066210
    // 0x8004D5F8: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8004D5F8: sw          $a2, 0xB0($sp)
    MEM_W(0XB0, ctx->r29) = ctx->r6;
    after_0:
    // 0x8004D5FC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8004D600: lwc1        $f14, 0x94($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X94);
    // 0x8004D604: bne         $v0, $a0, L_8004D618
    if (ctx->r2 != ctx->r4) {
        // 0x8004D608: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8004D618;
    }
    // 0x8004D608: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8004D60C: lui         $at, 0x4320
    ctx->r1 = S32(0X4320 << 16);
    // 0x8004D610: mtc1        $at, $f14
    ctx->f14.u32l = ctx->r1;
    // 0x8004D614: nop

L_8004D618:
    // 0x8004D618: addiu       $s0, $s0, -0x2AF8
    ctx->r16 = ADD32(ctx->r16, -0X2AF8);
    // 0x8004D61C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D620: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8004D624: lbu         $v1, 0x3B($v0)
    ctx->r3 = MEM_BU(ctx->r2, 0X3B);
    // 0x8004D628: nop

    // 0x8004D62C: bne         $a0, $v1, L_8004D640
    if (ctx->r4 != ctx->r3) {
        // 0x8004D630: lui         $at, 0x420C
        ctx->r1 = S32(0X420C << 16);
            goto L_8004D640;
    }
    // 0x8004D630: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8004D634: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x8004D638: nop

    // 0x8004D63C: add.s       $f14, $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f14.fl = ctx->f14.fl + ctx->f16.fl;
L_8004D640:
    // 0x8004D640: bne         $a0, $v1, L_8004D654
    if (ctx->r4 != ctx->r3) {
        // 0x8004D644: lui         $at, 0x420C
        ctx->r1 = S32(0X420C << 16);
            goto L_8004D654;
    }
    // 0x8004D644: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x8004D648: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x8004D64C: nop

    // 0x8004D650: sub.s       $f14, $f14, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f14.fl - ctx->f18.fl;
L_8004D654:
    // 0x8004D654: lwc1        $f0, 0x1C($v0)
    ctx->f0.u32l = MEM_W(ctx->r2, 0X1C);
    // 0x8004D658: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x8004D65C: sub.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f0.fl;
    // 0x8004D660: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8004D664: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8004D668: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8004D66C: cvt.d.s     $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f16.d = CVT_D_S(ctx->f0.fl);
    // 0x8004D670: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8004D674: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x8004D678: addiu       $a1, $a1, -0x2AF0
    ctx->r5 = ADD32(ctx->r5, -0X2AF0);
    // 0x8004D67C: add.d       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f16.d + ctx->f10.d;
    // 0x8004D680: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D684: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8004D688: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x8004D68C: swc1        $f4, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f4.u32l;
    // 0x8004D690: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D694: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8004D698: lh          $t1, 0x0($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X0);
    // 0x8004D69C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x8004D6A0: subu        $t3, $t2, $t1
    ctx->r11 = SUB32(ctx->r10, ctx->r9);
    // 0x8004D6A4: sh          $t3, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r11;
    // 0x8004D6A8: lh          $t4, 0x2($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X2);
    // 0x8004D6AC: sh          $zero, 0x4($a1)
    MEM_H(0X4, ctx->r5) = 0;
    // 0x8004D6B0: negu        $t5, $t4
    ctx->r13 = SUB32(0, ctx->r12);
    // 0x8004D6B4: sh          $t5, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r13;
    // 0x8004D6B8: swc1        $f2, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f2.u32l;
    // 0x8004D6BC: swc1        $f2, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f2.u32l;
    // 0x8004D6C0: swc1        $f2, 0x14($a1)
    MEM_W(0X14, ctx->r5) = ctx->f2.u32l;
    // 0x8004D6C4: jal         0x8006FC30
    // 0x8004D6C8: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    mtxf_from_transform(rdram, ctx);
        goto after_1;
    // 0x8004D6C8: swc1        $f6, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f6.u32l;
    after_1:
    // 0x8004D6CC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8004D6D0: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D6D4: lw          $a3, 0x1C($t6)
    ctx->r7 = MEM_W(ctx->r14, 0X1C);
    // 0x8004D6D8: addiu       $t8, $sp, 0x90
    ctx->r24 = ADD32(ctx->r29, 0X90);
    // 0x8004D6DC: addiu       $t7, $sp, 0x8C
    ctx->r15 = ADD32(ctx->r29, 0X8C);
    // 0x8004D6E0: addiu       $t9, $sp, 0x88
    ctx->r25 = ADD32(ctx->r29, 0X88);
    // 0x8004D6E4: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8004D6E8: mfc1        $a2, $f2
    ctx->r6 = (int32_t)ctx->f2.u32l;
    // 0x8004D6EC: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    // 0x8004D6F0: sw          $t7, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r15;
    // 0x8004D6F4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8004D6F8: jal         0x8006F64C
    // 0x8004D6FC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    mtxf_transform_point(rdram, ctx);
        goto after_2;
    // 0x8004D6FC: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_2:
    // 0x8004D700: lw          $v0, 0xAC($sp)
    ctx->r2 = MEM_W(ctx->r29, 0XAC);
    // 0x8004D704: lwc1        $f16, 0x90($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8004D708: lwc1        $f8, 0xC($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004D70C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8004D710: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8004D714: addiu       $a0, $zero, 0x800
    ctx->r4 = ADD32(0, 0X800);
    // 0x8004D718: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x8004D71C: lwc1        $f4, 0x8C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8004D720: lwc1        $f18, 0x10($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004D724: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8004D728: add.s       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = ctx->f18.fl + ctx->f4.fl;
    // 0x8004D72C: swc1        $f6, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f6.u32l;
    // 0x8004D730: lwc1        $f16, 0x88($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004D734: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004D738: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8004D73C: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x8004D740: jal         0x800707C4
    // 0x8004D744: swc1        $f10, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f10.u32l;
    sins_f(rdram, ctx);
        goto after_3;
    // 0x8004D744: swc1        $f10, 0x14($t3)
    MEM_W(0X14, ctx->r11) = ctx->f10.u32l;
    after_3:
    // 0x8004D748: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8004D74C: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x8004D750: lwc1        $f18, 0x1C($t4)
    ctx->f18.u32l = MEM_W(ctx->r12, 0X1C);
    // 0x8004D754: addiu       $t5, $sp, 0x90
    ctx->r13 = ADD32(ctx->r29, 0X90);
    // 0x8004D758: mul.s       $f4, $f0, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x8004D75C: addiu       $t6, $sp, 0x8C
    ctx->r14 = ADD32(ctx->r29, 0X8C);
    // 0x8004D760: addiu       $t8, $sp, 0x88
    ctx->r24 = ADD32(ctx->r29, 0X88);
    // 0x8004D764: mfc1        $a1, $f2
    ctx->r5 = (int32_t)ctx->f2.u32l;
    // 0x8004D768: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x8004D76C: mfc1        $a3, $f2
    ctx->r7 = (int32_t)ctx->f2.u32l;
    // 0x8004D770: sw          $t8, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r24;
    // 0x8004D774: sw          $t6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r14;
    // 0x8004D778: sw          $t5, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r13;
    // 0x8004D77C: jal         0x8006F64C
    // 0x8004D780: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    mtxf_transform_point(rdram, ctx);
        goto after_4;
    // 0x8004D780: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    after_4:
    // 0x8004D784: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D788: lwc1        $f8, 0x90($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X90);
    // 0x8004D78C: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004D790: ori         $t0, $zero, 0x8001
    ctx->r8 = 0 | 0X8001;
    // 0x8004D794: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004D798: swc1        $f16, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f16.u32l;
    // 0x8004D79C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D7A0: lwc1        $f18, 0x8C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X8C);
    // 0x8004D7A4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004D7A8: nop

    // 0x8004D7AC: add.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f10.fl + ctx->f18.fl;
    // 0x8004D7B0: swc1        $f4, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f4.u32l;
    // 0x8004D7B4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D7B8: lwc1        $f8, 0x88($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X88);
    // 0x8004D7BC: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004D7C0: nop

    // 0x8004D7C4: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x8004D7C8: swc1        $f16, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f16.u32l;
    // 0x8004D7CC: lw          $t7, 0xAC($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XAC);
    // 0x8004D7D0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D7D4: lh          $a0, 0x4($t7)
    ctx->r4 = MEM_H(ctx->r15, 0X4);
    // 0x8004D7D8: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x8004D7DC: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004D7E0: andi        $t9, $a0, 0xFFFF
    ctx->r25 = ctx->r4 & 0XFFFF;
    // 0x8004D7E4: andi        $t2, $a2, 0xFFFF
    ctx->r10 = ctx->r6 & 0XFFFF;
    // 0x8004D7E8: subu        $v1, $t9, $t2
    ctx->r3 = SUB32(ctx->r25, ctx->r10);
    // 0x8004D7EC: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004D7F0: bne         $at, $zero, L_8004D800
    if (ctx->r1 != 0) {
        // 0x8004D7F4: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004D800;
    }
    // 0x8004D7F4: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004D7F8: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004D7FC: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004D800:
    // 0x8004D800: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004D804: beq         $at, $zero, L_8004D810
    if (ctx->r1 == 0) {
        // 0x8004D808: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004D810;
    }
    // 0x8004D808: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004D80C: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004D810:
    // 0x8004D810: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x8004D814: lwc1        $f10, 0xA8($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA8);
    // 0x8004D818: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x8004D81C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8004D820: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8004D824: nop

    // 0x8004D828: cvt.w.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8004D82C: mfc1        $a1, $f18
    ctx->r5 = (int32_t)ctx->f18.u32l;
    // 0x8004D830: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8004D834: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D838: mflo        $t3
    ctx->r11 = lo;
    // 0x8004D83C: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x8004D840: addu        $t5, $a2, $t4
    ctx->r13 = ADD32(ctx->r6, ctx->r12);
    // 0x8004D844: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x8004D848: lw          $t6, 0xAC($sp)
    ctx->r14 = MEM_W(ctx->r29, 0XAC);
    // 0x8004D84C: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D850: lh          $a0, 0x2($t6)
    ctx->r4 = MEM_H(ctx->r14, 0X2);
    // 0x8004D854: lh          $a3, 0x2($v0)
    ctx->r7 = MEM_H(ctx->r2, 0X2);
    // 0x8004D858: negu        $a0, $a0
    ctx->r4 = SUB32(0, ctx->r4);
    // 0x8004D85C: andi        $t8, $a3, 0xFFFF
    ctx->r24 = ctx->r7 & 0XFFFF;
    // 0x8004D860: subu        $v1, $a0, $t8
    ctx->r3 = SUB32(ctx->r4, ctx->r24);
    // 0x8004D864: slt         $at, $v1, $t0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8004D868: bne         $at, $zero, L_8004D878
    if (ctx->r1 != 0) {
        // 0x8004D86C: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8004D878;
    }
    // 0x8004D86C: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8004D870: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8004D874: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004D878:
    // 0x8004D878: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8004D87C: beq         $at, $zero, L_8004D888
    if (ctx->r1 == 0) {
        // 0x8004D880: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8004D888;
    }
    // 0x8004D880: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8004D884: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8004D888:
    // 0x8004D888: multu       $v1, $a1
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r5)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8004D88C: mflo        $t7
    ctx->r15 = lo;
    // 0x8004D890: sra         $t9, $t7, 4
    ctx->r25 = S32(SIGNED(ctx->r15) >> 4);
    // 0x8004D894: addu        $t2, $a3, $t9
    ctx->r10 = ADD32(ctx->r7, ctx->r25);
    // 0x8004D898: sh          $t2, 0x2($v0)
    MEM_H(0X2, ctx->r2) = ctx->r10;
    // 0x8004D89C: lw          $t1, 0xB0($sp)
    ctx->r9 = MEM_W(ctx->r29, 0XB0);
    // 0x8004D8A0: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8004D8A4: lh          $t3, 0x196($t1)
    ctx->r11 = MEM_H(ctx->r9, 0X196);
    // 0x8004D8A8: nop

    // 0x8004D8AC: sh          $t3, 0x0($t4)
    MEM_H(0X0, ctx->r12) = ctx->r11;
    // 0x8004D8B0: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D8B4: nop

    // 0x8004D8B8: lwc1        $f12, 0xC($v0)
    ctx->f12.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004D8BC: lwc1        $f14, 0x10($v0)
    ctx->f14.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004D8C0: lw          $a2, 0x14($v0)
    ctx->r6 = MEM_W(ctx->r2, 0X14);
    // 0x8004D8C4: jal         0x80029F18
    // 0x8004D8C8: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_5;
    // 0x8004D8C8: nop

    after_5:
    // 0x8004D8CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8004D8D0: beq         $v0, $at, L_8004D8E4
    if (ctx->r2 == ctx->r1) {
        // 0x8004D8D4: nop
    
            goto L_8004D8E4;
    }
    // 0x8004D8D4: nop

    // 0x8004D8D8: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8004D8DC: nop

    // 0x8004D8E0: sh          $v0, 0x34($t5)
    MEM_H(0X34, ctx->r13) = ctx->r2;
L_8004D8E4:
    // 0x8004D8E4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8004D8E8: lw          $t7, 0xB0($sp)
    ctx->r15 = MEM_W(ctx->r29, 0XB0);
    // 0x8004D8EC: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x8004D8F0: nop

    // 0x8004D8F4: sh          $t8, 0x196($t7)
    MEM_H(0X196, ctx->r15) = ctx->r24;
    // 0x8004D8F8: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D8FC: nop

    // 0x8004D900: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8004D904: lwc1        $f6, 0x24($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X24);
    // 0x8004D908: nop

    // 0x8004D90C: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004D910: swc1        $f8, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f8.u32l;
    // 0x8004D914: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D918: nop

    // 0x8004D91C: lwc1        $f16, 0x10($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8004D920: lwc1        $f10, 0x28($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X28);
    // 0x8004D924: nop

    // 0x8004D928: add.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl + ctx->f10.fl;
    // 0x8004D92C: swc1        $f18, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f18.u32l;
    // 0x8004D930: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8004D934: nop

    // 0x8004D938: lwc1        $f4, 0x14($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8004D93C: lwc1        $f6, 0x2C($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X2C);
    // 0x8004D940: nop

    // 0x8004D944: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8004D948: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
    // 0x8004D94C: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8004D950: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8004D954: jr          $ra
    // 0x8004D958: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
    return;
    // 0x8004D958: addiu       $sp, $sp, 0xA8
    ctx->r29 = ADD32(ctx->r29, 0XA8);
;}
RECOMP_FUNC void func_8006D968(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006D968: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8006D96C: lw          $t6, 0x34EC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X34EC);
    // 0x8006D970: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8006D974: beq         $t6, $at, L_8006DA04
    if (ctx->r14 == ctx->r1) {
        // 0x8006D978: lui         $a2, 0x8012
        ctx->r6 = S32(0X8012 << 16);
            goto L_8006DA04;
    }
    // 0x8006D978: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8006D97C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8006D980: lw          $t7, 0x34F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X34F4);
    // 0x8006D984: addiu       $a2, $a2, 0x1250
    ctx->r6 = ADD32(ctx->r6, 0X1250);
    // 0x8006D988: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006D98C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006D990: addiu       $v0, $v0, 0x1252
    ctx->r2 = ADD32(ctx->r2, 0X1252);
    // 0x8006D994: addiu       $v1, $v1, 0x1250
    ctx->r3 = ADD32(ctx->r3, 0X1250);
    // 0x8006D998: or          $a1, $a0, $zero
    ctx->r5 = ctx->r4 | 0;
    // 0x8006D99C: sb          $t7, 0x0($a2)
    MEM_B(0X0, ctx->r6) = ctx->r15;
L_8006D9A0:
    // 0x8006D9A0: lb          $t8, 0x8($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X8);
    // 0x8006D9A4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8006D9A8: sb          $t8, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r24;
    // 0x8006D9AC: lb          $t9, 0xA($a1)
    ctx->r25 = MEM_B(ctx->r5, 0XA);
    // 0x8006D9B0: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8006D9B4: sb          $t9, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r25;
    // 0x8006D9B8: lb          $t0, 0xB($a1)
    ctx->r8 = MEM_B(ctx->r5, 0XB);
    // 0x8006D9BC: nop

    // 0x8006D9C0: sb          $t0, 0x5($v1)
    MEM_B(0X5, ctx->r3) = ctx->r8;
    // 0x8006D9C4: lb          $t1, 0xD($a1)
    ctx->r9 = MEM_B(ctx->r5, 0XD);
    // 0x8006D9C8: nop

    // 0x8006D9CC: sb          $t1, 0x7($v1)
    MEM_B(0X7, ctx->r3) = ctx->r9;
    // 0x8006D9D0: lb          $t2, 0x11($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X11);
    // 0x8006D9D4: nop

    // 0x8006D9D8: sb          $t2, 0x9($v1)
    MEM_B(0X9, ctx->r3) = ctx->r10;
    // 0x8006D9DC: lb          $t3, 0x13($a1)
    ctx->r11 = MEM_B(ctx->r5, 0X13);
    // 0x8006D9E0: bne         $v1, $v0, L_8006D9A0
    if (ctx->r3 != ctx->r2) {
        // 0x8006D9E4: sb          $t3, 0xB($v1)
        MEM_B(0XB, ctx->r3) = ctx->r11;
            goto L_8006D9A0;
    }
    // 0x8006D9E4: sb          $t3, 0xB($v1)
    MEM_B(0XB, ctx->r3) = ctx->r11;
    // 0x8006D9E8: lb          $t4, 0x16($a0)
    ctx->r12 = MEM_B(ctx->r4, 0X16);
    // 0x8006D9EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006D9F0: sb          $t4, 0xE($a2)
    MEM_B(0XE, ctx->r6) = ctx->r12;
    // 0x8006D9F4: lb          $t5, 0x17($a0)
    ctx->r13 = MEM_B(ctx->r4, 0X17);
    // 0x8006D9F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006D9FC: sb          $t5, 0xF($a2)
    MEM_B(0XF, ctx->r6) = ctx->r13;
    // 0x8006DA00: sw          $t6, 0x34FC($at)
    MEM_W(0X34FC, ctx->r1) = ctx->r14;
L_8006DA04:
    // 0x8006DA04: jr          $ra
    // 0x8006DA08: nop

    return;
    // 0x8006DA08: nop

;}
RECOMP_FUNC void audspat_point_set_position(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800096D8: mtc1        $a1, $f12
    ctx->f12.u32l = ctx->r5;
    // 0x800096DC: mtc1        $a2, $f14
    ctx->f14.u32l = ctx->r6;
    // 0x800096E0: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x800096E4: swc1        $f12, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->f12.u32l;
    // 0x800096E8: swc1        $f14, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->f14.u32l;
    // 0x800096EC: lwc1        $f4, 0xC($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XC);
    // 0x800096F0: jr          $ra
    // 0x800096F4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
    return;
    // 0x800096F4: swc1        $f4, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->f4.u32l;
;}
RECOMP_FUNC void hud_balloons(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A718C: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800A7190: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A7194: jal         0x8006EA90
    // 0x800A7198: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x800A7198: sw          $a0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r4;
    after_0:
    // 0x800A719C: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A71A0: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A71A4: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A71A8: bne         $t6, $zero, L_800A71B8
    if (ctx->r14 != 0) {
        // 0x800A71AC: addiu       $t7, $zero, 0x286
        ctx->r15 = ADD32(0, 0X286);
            goto L_800A71B8;
    }
    // 0x800A71AC: addiu       $t7, $zero, 0x286
    ctx->r15 = ADD32(0, 0X286);
    // 0x800A71B0: b           L_800A71C0
    // 0x800A71B4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
        goto L_800A71C0;
    // 0x800A71B4: sw          $t7, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r15;
L_800A71B8:
    // 0x800A71B8: addiu       $t8, $zero, 0x348
    ctx->r24 = ADD32(0, 0X348);
    // 0x800A71BC: sw          $t8, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r24;
L_800A71C0:
    // 0x800A71C0: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x800A71C4: nop

    // 0x800A71C8: andi        $t2, $t9, 0x4
    ctx->r10 = ctx->r25 & 0X4;
    // 0x800A71CC: beq         $t2, $zero, L_800A71E0
    if (ctx->r10 == 0) {
        // 0x800A71D0: lui         $t4, 0x8012
        ctx->r12 = S32(0X8012 << 16);
            goto L_800A71E0;
    }
    // 0x800A71D0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x800A71D4: lw          $t4, 0x6CDC($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6CDC);
    // 0x800A71D8: addiu       $t3, $zero, 0x45
    ctx->r11 = ADD32(0, 0X45);
    // 0x800A71DC: sh          $t3, 0x266($t4)
    MEM_H(0X266, ctx->r12) = ctx->r11;
L_800A71E0:
    // 0x800A71E0: jal         0x8001E440
    // 0x800A71E4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    cutscene_id(rdram, ctx);
        goto after_1;
    // 0x800A71E4: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_1:
    // 0x800A71E8: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A71EC: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A71F0: bne         $v0, $at, L_800A7228
    if (ctx->r2 != ctx->r1) {
        // 0x800A71F4: nop
    
            goto L_800A7228;
    }
    // 0x800A71F4: nop

    // 0x800A71F8: jal         0x8001AE54
    // 0x800A71FC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    get_balloon_cutscene_timer(rdram, ctx);
        goto after_2;
    // 0x800A71FC: sw          $a0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r4;
    after_2:
    // 0x800A7200: lw          $t5, 0x20($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X20);
    // 0x800A7204: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
    // 0x800A7208: sltu        $at, $v0, $t5
    ctx->r1 = ctx->r2 < ctx->r13 ? 1 : 0;
    // 0x800A720C: beq         $at, $zero, L_800A7228
    if (ctx->r1 == 0) {
        // 0x800A7210: nop
    
            goto L_800A7228;
    }
    // 0x800A7210: nop

    // 0x800A7214: lw          $t6, 0x0($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X0);
    // 0x800A7218: nop

    // 0x800A721C: lh          $v1, 0x0($t6)
    ctx->r3 = MEM_H(ctx->r14, 0X0);
    // 0x800A7220: b           L_800A7298
    // 0x800A7224: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
        goto L_800A7298;
    // 0x800A7224: addiu       $v1, $v1, -0x1
    ctx->r3 = ADD32(ctx->r3, -0X1);
L_800A7228:
    // 0x800A7228: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800A722C: nop

    // 0x800A7230: lh          $v1, 0x0($t7)
    ctx->r3 = MEM_H(ctx->r15, 0X0);
    // 0x800A7234: jal         0x8001E440
    // 0x800A7238: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    cutscene_id(rdram, ctx);
        goto after_3;
    // 0x800A7238: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_3:
    // 0x800A723C: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800A7240: addiu       $at, $zero, 0xA
    ctx->r1 = ADD32(0, 0XA);
    // 0x800A7244: bne         $v0, $at, L_800A7298
    if (ctx->r2 != ctx->r1) {
        // 0x800A7248: nop
    
            goto L_800A7298;
    }
    // 0x800A7248: nop

    // 0x800A724C: jal         0x8001AE54
    // 0x800A7250: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    get_balloon_cutscene_timer(rdram, ctx);
        goto after_4;
    // 0x800A7250: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_4:
    // 0x800A7254: lw          $t8, 0x20($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X20);
    // 0x800A7258: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800A725C: addiu       $t9, $t8, 0x8
    ctx->r25 = ADD32(ctx->r24, 0X8);
    // 0x800A7260: sltu        $at, $v0, $t9
    ctx->r1 = ctx->r2 < ctx->r25 ? 1 : 0;
    // 0x800A7264: beq         $at, $zero, L_800A7298
    if (ctx->r1 == 0) {
        // 0x800A7268: nop
    
            goto L_800A7298;
    }
    // 0x800A7268: nop

    // 0x800A726C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7270: addiu       $a1, $a1, 0x6D44
    ctx->r5 = ADD32(ctx->r5, 0X6D44);
    // 0x800A7274: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x800A7278: nop

    // 0x800A727C: bne         $t2, $zero, L_800A7298
    if (ctx->r10 != 0) {
        // 0x800A7280: nop
    
            goto L_800A7298;
    }
    // 0x800A7280: nop

    // 0x800A7284: addiu       $a0, $zero, 0xFE
    ctx->r4 = ADD32(0, 0XFE);
    // 0x800A7288: jal         0x80001D04
    // 0x800A728C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x800A728C: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_5:
    // 0x800A7290: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x800A7294: nop

L_800A7298:
    // 0x800A7298: bgez        $v1, L_800A72A4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800A729C: addiu       $t1, $zero, 0xA
        ctx->r9 = ADD32(0, 0XA);
            goto L_800A72A4;
    }
    // 0x800A729C: addiu       $t1, $zero, 0xA
    ctx->r9 = ADD32(0, 0XA);
    // 0x800A72A0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_800A72A4:
    // 0x800A72A4: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x800A72A8: bne         $t1, $zero, L_800A72B4
    if (ctx->r9 != 0) {
        // 0x800A72AC: nop
    
            goto L_800A72B4;
    }
    // 0x800A72AC: nop

    // 0x800A72B0: break       7
    do_break(2148168368);
L_800A72B4:
    // 0x800A72B4: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A72B8: bne         $t1, $at, L_800A72CC
    if (ctx->r9 != ctx->r1) {
        // 0x800A72BC: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A72CC;
    }
    // 0x800A72BC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A72C0: bne         $v1, $at, L_800A72CC
    if (ctx->r3 != ctx->r1) {
        // 0x800A72C4: nop
    
            goto L_800A72CC;
    }
    // 0x800A72C4: nop

    // 0x800A72C8: break       6
    do_break(2148168392);
L_800A72CC:
    // 0x800A72CC: mflo        $v0
    ctx->r2 = lo;
    // 0x800A72D0: beq         $v0, $zero, L_800A7348
    if (ctx->r2 == 0) {
        // 0x800A72D4: nop
    
            goto L_800A7348;
    }
    // 0x800A72D4: nop

    // 0x800A72D8: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x800A72DC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A72E0: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A72E4: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800A72E8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A72EC: sh          $v0, 0x2B8($t3)
    MEM_H(0X2B8, ctx->r11) = ctx->r2;
    // 0x800A72F0: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A72F4: bne         $t1, $zero, L_800A7300
    if (ctx->r9 != 0) {
        // 0x800A72F8: nop
    
            goto L_800A7300;
    }
    // 0x800A72F8: nop

    // 0x800A72FC: break       7
    do_break(2148168444);
L_800A7300:
    // 0x800A7300: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7304: bne         $t1, $at, L_800A7318
    if (ctx->r9 != ctx->r1) {
        // 0x800A7308: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A7318;
    }
    // 0x800A7308: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A730C: bne         $v1, $at, L_800A7318
    if (ctx->r3 != ctx->r1) {
        // 0x800A7310: nop
    
            goto L_800A7318;
    }
    // 0x800A7310: nop

    // 0x800A7314: break       6
    do_break(2148168468);
L_800A7318:
    // 0x800A7318: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A731C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7320: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A7324: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A7328: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A732C: mfhi        $t4
    ctx->r12 = hi;
    // 0x800A7330: sh          $t4, 0x2D8($t5)
    MEM_H(0X2D8, ctx->r13) = ctx->r12;
    // 0x800A7334: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A7338: jal         0x800AA600
    // 0x800A733C: addiu       $a3, $a3, 0x2C0
    ctx->r7 = ADD32(ctx->r7, 0X2C0);
    hud_element_render(rdram, ctx);
        goto after_6;
    // 0x800A733C: addiu       $a3, $a3, 0x2C0
    ctx->r7 = ADD32(ctx->r7, 0X2C0);
    after_6:
    // 0x800A7340: b           L_800A7384
    // 0x800A7344: nop

        goto L_800A7384;
    // 0x800A7344: nop

L_800A7348:
    // 0x800A7348: div         $zero, $v1, $t1
    lo = S32(S64(S32(ctx->r3)) / S64(S32(ctx->r9))); hi = S32(S64(S32(ctx->r3)) % S64(S32(ctx->r9)));
    // 0x800A734C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A7350: lw          $t7, 0x6CDC($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6CDC);
    // 0x800A7354: bne         $t1, $zero, L_800A7360
    if (ctx->r9 != 0) {
        // 0x800A7358: nop
    
            goto L_800A7360;
    }
    // 0x800A7358: nop

    // 0x800A735C: break       7
    do_break(2148168540);
L_800A7360:
    // 0x800A7360: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800A7364: bne         $t1, $at, L_800A7378
    if (ctx->r9 != ctx->r1) {
        // 0x800A7368: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800A7378;
    }
    // 0x800A7368: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800A736C: bne         $v1, $at, L_800A7378
    if (ctx->r3 != ctx->r1) {
        // 0x800A7370: nop
    
            goto L_800A7378;
    }
    // 0x800A7370: nop

    // 0x800A7374: break       6
    do_break(2148168564);
L_800A7378:
    // 0x800A7378: mfhi        $t6
    ctx->r14 = hi;
    // 0x800A737C: sh          $t6, 0x2B8($t7)
    MEM_H(0X2B8, ctx->r15) = ctx->r14;
    // 0x800A7380: nop

L_800A7384:
    // 0x800A7384: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A7388: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A738C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7390: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7394: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A7398: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A739C: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A73A0: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A73A4: jal         0x800AA600
    // 0x800A73A8: addiu       $a3, $a3, 0x2A0
    ctx->r7 = ADD32(ctx->r7, 0X2A0);
    hud_element_render(rdram, ctx);
        goto after_7;
    // 0x800A73A8: addiu       $a3, $a3, 0x2A0
    ctx->r7 = ADD32(ctx->r7, 0X2A0);
    after_7:
    // 0x800A73AC: jal         0x80066098
    // 0x800A73B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_8;
    // 0x800A73B0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_8:
    // 0x800A73B4: lui         $t8, 0x8000
    ctx->r24 = S32(0X8000 << 16);
    // 0x800A73B8: lw          $t8, 0x300($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X300);
    // 0x800A73BC: nop

    // 0x800A73C0: bne         $t8, $zero, L_800A73D0
    if (ctx->r24 != 0) {
        // 0x800A73C4: nop
    
            goto L_800A73D0;
    }
    // 0x800A73C4: nop

    // 0x800A73C8: jal         0x8007BF1C
    // 0x800A73CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_9;
    // 0x800A73CC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_9:
L_800A73D0:
    // 0x800A73D0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A73D4: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A73D8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A73DC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A73E0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A73E4: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A73E8: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A73EC: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A73F0: jal         0x800AA600
    // 0x800A73F4: addiu       $a3, $a3, 0x260
    ctx->r7 = ADD32(ctx->r7, 0X260);
    hud_element_render(rdram, ctx);
        goto after_10;
    // 0x800A73F4: addiu       $a3, $a3, 0x260
    ctx->r7 = ADD32(ctx->r7, 0X260);
    after_10:
    // 0x800A73F8: jal         0x8007BF1C
    // 0x800A73FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_11;
    // 0x800A73FC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_11:
    // 0x800A7400: jal         0x80066098
    // 0x800A7404: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    enable_pal_viewport_height_adjust(rdram, ctx);
        goto after_12;
    // 0x800A7404: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_12:
    // 0x800A7408: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A740C: lw          $a3, 0x6CDC($a3)
    ctx->r7 = MEM_W(ctx->r7, 0X6CDC);
    // 0x800A7410: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A7414: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A7418: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A741C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A7420: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A7424: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A7428: jal         0x800AA600
    // 0x800A742C: addiu       $a3, $a3, 0x280
    ctx->r7 = ADD32(ctx->r7, 0X280);
    hud_element_render(rdram, ctx);
        goto after_13;
    // 0x800A742C: addiu       $a3, $a3, 0x280
    ctx->r7 = ADD32(ctx->r7, 0X280);
    after_13:
    // 0x800A7430: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800A7434: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800A7438: jr          $ra
    // 0x800A743C: nop

    return;
    // 0x800A743C: nop

;}
RECOMP_FUNC void void_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800257D0: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800257D4: lw          $t6, -0x36DC($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X36DC);
    // 0x800257D8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800257DC: beq         $t6, $zero, L_8002580C
    if (ctx->r14 == 0) {
        // 0x800257E0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8002580C;
    }
    // 0x800257E0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800257E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800257E8: lw          $a0, -0x2B8C($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2B8C);
    // 0x800257EC: jal         0x80071140
    // 0x800257F0: nop

    mempool_free(rdram, ctx);
        goto after_0;
    // 0x800257F0: nop

    after_0:
    // 0x800257F4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800257F8: lw          $a0, -0x36DC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X36DC);
    // 0x800257FC: jal         0x80071140
    // 0x80025800: nop

    mempool_free(rdram, ctx);
        goto after_1;
    // 0x80025800: nop

    after_1:
    // 0x80025804: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80025808: sw          $zero, -0x36DC($at)
    MEM_W(-0X36DC, ctx->r1) = 0;
L_8002580C:
    // 0x8002580C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80025810: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80025814: jr          $ra
    // 0x80025818: nop

    return;
    // 0x80025818: nop

;}
RECOMP_FUNC void coss_f(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800707F8: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x800707FC: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070800: jal         0x8007082C
    // 0x80070804: nop

    coss_s16(rdram, ctx);
        goto after_0;
    // 0x80070804: nop

    after_0:
    // 0x80070808: mtc1        $v0, $f0
    ctx->f0.u32l = ctx->r2;
    // 0x8007080C: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x80070810: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80070814: cvt.s.w     $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    ctx->f0.fl = CVT_S_W(ctx->f0.u32l);
    // 0x80070818: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x8007081C: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x80070820: mul.s       $f0, $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f2.fl);
    // 0x80070824: jr          $ra
    // 0x80070828: nop

    return;
    // 0x80070828: nop

;}
RECOMP_FUNC void obj_init_door(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003B7CC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8003B7D0: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8003B7D4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8003B7D8: lb          $a3, 0xC($a1)
    ctx->r7 = MEM_B(ctx->r5, 0XC);
    // 0x8003B7DC: lw          $v1, 0x64($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X64);
    // 0x8003B7E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B7E4: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8003B7E8: bne         $a3, $at, L_8003B80C
    if (ctx->r7 != ctx->r1) {
        // 0x8003B7EC: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_8003B80C;
    }
    // 0x8003B7EC: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x8003B7F0: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8003B7F4: jal         0x8000CC20
    // 0x8003B7F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    func_8000CC20(rdram, ctx);
        goto after_0;
    // 0x8003B7F8: sw          $a1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r5;
    after_0:
    // 0x8003B7FC: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B800: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003B804: b           L_8003B82C
    // 0x8003B808: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
        goto L_8003B82C;
    // 0x8003B808: sb          $v0, 0xC($a2)
    MEM_B(0XC, ctx->r6) = ctx->r2;
L_8003B80C:
    // 0x8003B80C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8003B810: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    // 0x8003B814: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8003B818: jal         0x8000CBF0
    // 0x8003B81C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    func_8000CBF0(rdram, ctx);
        goto after_1;
    // 0x8003B81C: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_1:
    // 0x8003B820: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003B824: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B828: nop

L_8003B82C:
    // 0x8003B82C: lb          $t6, 0xC($a2)
    ctx->r14 = MEM_B(ctx->r6, 0XC);
    // 0x8003B830: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8003B834: sb          $t6, 0xE($v1)
    MEM_B(0XE, ctx->r3) = ctx->r14;
    // 0x8003B838: lbu         $t7, 0xE($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0XE);
    // 0x8003B83C: lb          $t1, 0xE($v1)
    ctx->r9 = MEM_B(ctx->r3, 0XE);
    // 0x8003B840: sb          $t7, 0xF($v1)
    MEM_B(0XF, ctx->r3) = ctx->r15;
    // 0x8003B844: lbu         $t8, 0xD($a2)
    ctx->r24 = MEM_BU(ctx->r6, 0XD);
    // 0x8003B848: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8003B84C: sb          $t8, 0x11($v1)
    MEM_B(0X11, ctx->r3) = ctx->r24;
    // 0x8003B850: lbu         $t9, 0xD($a2)
    ctx->r25 = MEM_BU(ctx->r6, 0XD);
    // 0x8003B854: addiu       $a0, $a0, 0x5FB4
    ctx->r4 = ADD32(ctx->r4, 0X5FB4);
    // 0x8003B858: sb          $t9, 0x10($v1)
    MEM_B(0X10, ctx->r3) = ctx->r25;
    // 0x8003B85C: lbu         $t0, 0xB($a2)
    ctx->r8 = MEM_BU(ctx->r6, 0XB);
    // 0x8003B860: bne         $t1, $at, L_8003B880
    if (ctx->r9 != ctx->r1) {
        // 0x8003B864: sb          $t0, 0x12($v1)
        MEM_B(0X12, ctx->r3) = ctx->r8;
            goto L_8003B880;
    }
    // 0x8003B864: sb          $t0, 0x12($v1)
    MEM_B(0X12, ctx->r3) = ctx->r8;
    // 0x8003B868: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x8003B86C: jal         0x800C9D54
    // 0x8003B870: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    rmonPrintf_recomp(rdram, ctx);
        goto after_2;
    // 0x8003B870: sw          $a2, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r6;
    after_2:
    // 0x8003B874: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8003B878: lw          $a2, 0x2C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X2C);
    // 0x8003B87C: nop

L_8003B880:
    // 0x8003B880: lbu         $t2, 0xA($a2)
    ctx->r10 = MEM_BU(ctx->r6, 0XA);
    // 0x8003B884: lwc1        $f4, 0x10($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X10);
    // 0x8003B888: sb          $t2, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = ctx->r10;
    // 0x8003B88C: lbu         $t4, 0x8($a2)
    ctx->r12 = MEM_BU(ctx->r6, 0X8);
    // 0x8003B890: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x8003B894: sll         $t5, $t4, 10
    ctx->r13 = S32(ctx->r12 << 10);
    // 0x8003B898: sh          $t5, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r13;
    // 0x8003B89C: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8003B8A0: swc1        $f4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f4.u32l;
    // 0x8003B8A4: lh          $t6, 0x0($s0)
    ctx->r14 = MEM_H(ctx->r16, 0X0);
    // 0x8003B8A8: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8003B8AC: sw          $t6, 0x78($s0)
    MEM_W(0X78, ctx->r16) = ctx->r14;
    // 0x8003B8B0: lbu         $t7, 0x9($a2)
    ctx->r15 = MEM_BU(ctx->r6, 0X9);
    // 0x8003B8B4: lui         $at, 0x4280
    ctx->r1 = S32(0X4280 << 16);
    // 0x8003B8B8: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8003B8BC: sll         $t9, $t8, 10
    ctx->r25 = S32(ctx->r24 << 10);
    // 0x8003B8C0: sw          $t9, 0x7C($s0)
    MEM_W(0X7C, ctx->r16) = ctx->r25;
    // 0x8003B8C4: lbu         $t1, 0x12($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0X12);
    // 0x8003B8C8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8003B8CC: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x8003B8D0: nop

    // 0x8003B8D4: cvt.s.w     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    ctx->f0.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8003B8D8: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x8003B8DC: nop

    // 0x8003B8E0: bc1f        L_8003B8F0
    if (!c1cs) {
        // 0x8003B8E4: nop
    
            goto L_8003B8F0;
    }
    // 0x8003B8E4: nop

    // 0x8003B8E8: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x8003B8EC: nop

L_8003B8F0:
    // 0x8003B8F0: div.s       $f0, $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f8.fl);
    // 0x8003B8F4: lw          $t2, 0x40($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X40);
    // 0x8003B8F8: addiu       $t5, $zero, 0x21
    ctx->r13 = ADD32(0, 0X21);
    // 0x8003B8FC: lwc1        $f10, 0xC($t2)
    ctx->f10.u32l = MEM_W(ctx->r10, 0XC);
    // 0x8003B900: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8003B904: addiu       $t9, $zero, 0x14
    ctx->r25 = ADD32(0, 0X14);
    // 0x8003B908: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x8003B90C: swc1        $f16, 0x8($s0)
    MEM_W(0X8, ctx->r16) = ctx->f16.u32l;
    // 0x8003B910: lbu         $t3, 0xF($a2)
    ctx->r11 = MEM_BU(ctx->r6, 0XF);
    // 0x8003B914: nop

    // 0x8003B918: sb          $t3, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r11;
    // 0x8003B91C: lb          $t4, 0x11($a2)
    ctx->r12 = MEM_B(ctx->r6, 0X11);
    // 0x8003B920: nop

    // 0x8003B924: sb          $t4, 0x14($v1)
    MEM_B(0X14, ctx->r3) = ctx->r12;
    // 0x8003B928: lw          $t6, 0x4C($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B92C: nop

    // 0x8003B930: sh          $t5, 0x14($t6)
    MEM_H(0X14, ctx->r14) = ctx->r13;
    // 0x8003B934: lw          $t8, 0x4C($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B938: nop

    // 0x8003B93C: sb          $t7, 0x11($t8)
    MEM_B(0X11, ctx->r24) = ctx->r15;
    // 0x8003B940: lw          $t0, 0x4C($s0)
    ctx->r8 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B944: nop

    // 0x8003B948: sb          $t9, 0x10($t0)
    MEM_B(0X10, ctx->r8) = ctx->r25;
    // 0x8003B94C: lw          $t1, 0x4C($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X4C);
    // 0x8003B950: nop

    // 0x8003B954: sb          $zero, 0x12($t1)
    MEM_B(0X12, ctx->r9) = 0;
    // 0x8003B958: lw          $t3, 0x40($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X40);
    // 0x8003B95C: lb          $t2, 0x3A($s0)
    ctx->r10 = MEM_B(ctx->r16, 0X3A);
    // 0x8003B960: lb          $t4, 0x55($t3)
    ctx->r12 = MEM_B(ctx->r11, 0X55);
    // 0x8003B964: nop

    // 0x8003B968: slt         $at, $t2, $t4
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8003B96C: bne         $at, $zero, L_8003B97C
    if (ctx->r1 != 0) {
        // 0x8003B970: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8003B97C;
    }
    // 0x8003B970: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8003B974: sb          $zero, 0x3A($s0)
    MEM_B(0X3A, ctx->r16) = 0;
    // 0x8003B978: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8003B97C:
    // 0x8003B97C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8003B980: jr          $ra
    // 0x8003B984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8003B984: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sound_volume_reset(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000890: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80000894: lbu         $t7, 0x5F79($t7)
    ctx->r15 = MEM_BU(ctx->r15, 0X5F79);
    // 0x80000898: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8000089C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800008A0: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800008A4: bne         $t7, $zero, L_80000958
    if (ctx->r15 != 0) {
        // 0x800008A8: andi        $t6, $a0, 0xFF
        ctx->r14 = ctx->r4 & 0XFF;
            goto L_80000958;
    }
    // 0x800008A8: andi        $t6, $a0, 0xFF
    ctx->r14 = ctx->r4 & 0XFF;
    // 0x800008AC: lui         $v0, 0x8011
    ctx->r2 = S32(0X8011 << 16);
    // 0x800008B0: addiu       $v0, $v0, 0x5F78
    ctx->r2 = ADD32(ctx->r2, 0X5F78);
    // 0x800008B4: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x800008B8: bne         $t8, $zero, L_80000958
    if (ctx->r24 != 0) {
        // 0x800008BC: sb          $t6, 0x0($v0)
        MEM_B(0X0, ctx->r2) = ctx->r14;
            goto L_80000958;
    }
    // 0x800008BC: sb          $t6, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r14;
    // 0x800008C0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800008C4: addiu       $t9, $zero, 0x100
    ctx->r25 = ADD32(0, 0X100);
    // 0x800008C8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800008CC: lbu         $a0, -0x39C8($a0)
    ctx->r4 = MEM_BU(ctx->r4, -0X39C8);
    // 0x800008D0: jal         0x80001990
    // 0x800008D4: sw          $t9, -0x3994($at)
    MEM_W(-0X3994, ctx->r1) = ctx->r25;
    music_volume_set(rdram, ctx);
        goto after_0;
    // 0x800008D4: sw          $t9, -0x3994($at)
    MEM_W(-0X3994, ctx->r1) = ctx->r25;
    after_0:
    // 0x800008D8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800008DC: lw          $a1, -0x3994($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3994);
    // 0x800008E0: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800008E4: sll         $t0, $a1, 7
    ctx->r8 = S32(ctx->r5 << 7);
    // 0x800008E8: addiu       $a1, $t0, -0x1
    ctx->r5 = ADD32(ctx->r8, -0X1);
    // 0x800008EC: andi        $t1, $a1, 0xFFFF
    ctx->r9 = ctx->r5 & 0XFFFF;
    // 0x800008F0: jal         0x80004A60
    // 0x800008F4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_1;
    // 0x800008F4: or          $a1, $t1, $zero
    ctx->r5 = ctx->r9 | 0;
    after_1:
    // 0x800008F8: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x800008FC: lw          $a1, -0x3994($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3994);
    // 0x80000900: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80000904: sll         $t2, $a1, 7
    ctx->r10 = S32(ctx->r5 << 7);
    // 0x80000908: addiu       $a1, $t2, -0x1
    ctx->r5 = ADD32(ctx->r10, -0X1);
    // 0x8000090C: andi        $t3, $a1, 0xFFFF
    ctx->r11 = ctx->r5 & 0XFFFF;
    // 0x80000910: jal         0x80004A60
    // 0x80000914: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_2;
    // 0x80000914: or          $a1, $t3, $zero
    ctx->r5 = ctx->r11 | 0;
    after_2:
    // 0x80000918: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000091C: lw          $a1, -0x3994($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3994);
    // 0x80000920: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x80000924: sll         $t4, $a1, 7
    ctx->r12 = S32(ctx->r5 << 7);
    // 0x80000928: addiu       $a1, $t4, -0x1
    ctx->r5 = ADD32(ctx->r12, -0X1);
    // 0x8000092C: andi        $t5, $a1, 0xFFFF
    ctx->r13 = ctx->r5 & 0XFFFF;
    // 0x80000930: jal         0x80004A60
    // 0x80000934: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_3;
    // 0x80000934: or          $a1, $t5, $zero
    ctx->r5 = ctx->r13 | 0;
    after_3:
    // 0x80000938: lui         $a1, 0x800E
    ctx->r5 = S32(0X800E << 16);
    // 0x8000093C: lw          $a1, -0x3994($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X3994);
    // 0x80000940: addiu       $a0, $zero, 0x4
    ctx->r4 = ADD32(0, 0X4);
    // 0x80000944: sll         $t6, $a1, 7
    ctx->r14 = S32(ctx->r5 << 7);
    // 0x80000948: addiu       $a1, $t6, -0x1
    ctx->r5 = ADD32(ctx->r14, -0X1);
    // 0x8000094C: andi        $t7, $a1, 0xFFFF
    ctx->r15 = ctx->r5 & 0XFFFF;
    // 0x80000950: jal         0x80004A60
    // 0x80000954: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    sndp_set_group_volume(rdram, ctx);
        goto after_4;
    // 0x80000954: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    after_4:
L_80000958:
    // 0x80000958: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000095C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80000960: jr          $ra
    // 0x80000964: nop

    return;
    // 0x80000964: nop

;}
RECOMP_FUNC void menu_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800815A4: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x800815A8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800815AC: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x800815B0: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x800815B4: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x800815B8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800815BC: lw          $t7, 0x0($a0)
    ctx->r15 = MEM_W(ctx->r4, 0X0);
    // 0x800815C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800815C4: sw          $t7, 0x63A0($at)
    MEM_W(0X63A0, ctx->r1) = ctx->r15;
    // 0x800815C8: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800815CC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800815D0: sw          $t9, 0x63A8($at)
    MEM_W(0X63A8, ctx->r1) = ctx->r25;
    // 0x800815D4: lw          $t1, 0x0($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X0);
    // 0x800815D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800815DC: sw          $t1, 0x63AC($at)
    MEM_W(0X63AC, ctx->r1) = ctx->r9;
    // 0x800815E0: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800815E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800815E8: jal         0x8009BF20
    // 0x800815EC: sw          $t3, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r11;
    update_controller_sticks(rdram, ctx);
        goto after_0;
    // 0x800815EC: sw          $t3, 0x63B0($at)
    MEM_W(0X63B0, ctx->r1) = ctx->r11;
    after_0:
    // 0x800815F0: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800815F4: lw          $t4, -0xB90($t4)
    ctx->r12 = MEM_W(ctx->r12, -0XB90);
    // 0x800815F8: nop

    // 0x800815FC: sltiu       $at, $t4, 0x1D
    ctx->r1 = ctx->r12 < 0X1D ? 1 : 0;
    // 0x80081600: beq         $at, $zero, L_800817AC
    if (ctx->r1 == 0) {
        // 0x80081604: sll         $t4, $t4, 2
        ctx->r12 = S32(ctx->r12 << 2);
            goto L_800817AC;
    }
    // 0x80081604: sll         $t4, $t4, 2
    ctx->r12 = S32(ctx->r12 << 2);
    // 0x80081608: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8008160C: addu        $at, $at, $t4
    gpr jr_addend_80081618 = ctx->r12;
    ctx->r1 = ADD32(ctx->r1, ctx->r12);
    // 0x80081610: lw          $t4, -0x7D08($at)
    ctx->r12 = ADD32(ctx->r1, -0X7D08);
    // 0x80081614: nop

    // 0x80081618: jr          $t4
    // 0x8008161C: nop

    switch (jr_addend_80081618 >> 2) {
        case 0: goto L_80081634; break;
        case 1: goto L_80081620; break;
        case 2: goto L_800817AC; break;
        case 3: goto L_800816AC; break;
        case 4: goto L_800817AC; break;
        case 5: goto L_800816FC; break;
        case 6: goto L_800816C0; break;
        case 7: goto L_800817AC; break;
        case 8: goto L_800817AC; break;
        case 9: goto L_800817AC; break;
        case 10: goto L_80081684; break;
        case 11: goto L_80081698; break;
        case 12: goto L_80081648; break;
        case 13: goto L_8008165C; break;
        case 14: goto L_80081670; break;
        case 15: goto L_800816E8; break;
        case 16: goto L_800817AC; break;
        case 17: goto L_80081710; break;
        case 18: goto L_800817AC; break;
        case 19: goto L_800816D4; break;
        case 20: goto L_80081724; break;
        case 21: goto L_80081738; break;
        case 22: goto L_800817AC; break;
        case 23: goto L_8008174C; break;
        case 24: goto L_80081760; break;
        case 25: goto L_80081774; break;
        case 26: goto L_80081788; break;
        case 27: goto L_800817AC; break;
        case 28: goto L_8008179C; break;
        default: switch_error(__func__, 0x80081618, 0x800E82F8);
    }
    // 0x8008161C: nop

L_80081620:
    // 0x80081620: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081624: jal         0x80082B84
    // 0x80081628: nop

    menu_logo_screen_loop(rdram, ctx);
        goto after_1;
    // 0x80081628: nop

    after_1:
    // 0x8008162C: b           L_800817AC
    // 0x80081630: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081630: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081634:
    // 0x80081634: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081638: jal         0x800839E4
    // 0x8008163C: nop

    menu_title_screen_loop(rdram, ctx);
        goto after_2;
    // 0x8008163C: nop

    after_2:
    // 0x80081640: b           L_800817AC
    // 0x80081644: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081644: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081648:
    // 0x80081648: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008164C: jal         0x8008435C
    // 0x80081650: nop

    menu_options_loop(rdram, ctx);
        goto after_3;
    // 0x80081650: nop

    after_3:
    // 0x80081654: b           L_800817AC
    // 0x80081658: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081658: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_8008165C:
    // 0x8008165C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081660: jal         0x80084C74
    // 0x80081664: nop

    menu_audio_options_loop(rdram, ctx);
        goto after_4;
    // 0x80081664: nop

    after_4:
    // 0x80081668: b           L_800817AC
    // 0x8008166C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x8008166C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081670:
    // 0x80081670: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081674: jal         0x80087B60
    // 0x80081678: nop

    menu_save_options_loop(rdram, ctx);
        goto after_5;
    // 0x80081678: nop

    after_5:
    // 0x8008167C: b           L_800817AC
    // 0x80081680: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081680: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081684:
    // 0x80081684: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081688: jal         0x80089CD8
    // 0x8008168C: nop

    menu_magic_codes_loop(rdram, ctx);
        goto after_6;
    // 0x8008168C: nop

    after_6:
    // 0x80081690: b           L_800817AC
    // 0x80081694: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081694: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081698:
    // 0x80081698: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008169C: jal         0x8008A928
    // 0x800816A0: nop

    menu_magic_codes_list_loop(rdram, ctx);
        goto after_7;
    // 0x800816A0: nop

    after_7:
    // 0x800816A4: b           L_800817AC
    // 0x800816A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x800816A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_800816AC:
    // 0x800816AC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800816B0: jal         0x8008BD24
    // 0x800816B4: nop

    menu_character_select_loop(rdram, ctx);
        goto after_8;
    // 0x800816B4: nop

    after_8:
    // 0x800816B8: b           L_800817AC
    // 0x800816BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x800816BC: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_800816C0:
    // 0x800816C0: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800816C4: jal         0x8008DE70
    // 0x800816C8: nop

    menu_file_select_loop(rdram, ctx);
        goto after_9;
    // 0x800816C8: nop

    after_9:
    // 0x800816CC: b           L_800817AC
    // 0x800816D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x800816D0: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_800816D4:
    // 0x800816D4: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800816D8: jal         0x8008C7BC
    // 0x800816DC: nop

    menu_game_select_loop(rdram, ctx);
        goto after_10;
    // 0x800816DC: nop

    after_10:
    // 0x800816E0: b           L_800817AC
    // 0x800816E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x800816E4: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_800816E8:
    // 0x800816E8: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800816EC: jal         0x8008F234
    // 0x800816F0: nop

    menu_track_select_loop(rdram, ctx);
        goto after_11;
    // 0x800816F0: nop

    after_11:
    // 0x800816F4: b           L_800817AC
    // 0x800816F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x800816F8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_800816FC:
    // 0x800816FC: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081700: jal         0x80093600
    // 0x80081704: nop

    menu_adventure_track_loop(rdram, ctx);
        goto after_12;
    // 0x80081704: nop

    after_12:
    // 0x80081708: b           L_800817AC
    // 0x8008170C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x8008170C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081710:
    // 0x80081710: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081714: jal         0x800972A8
    // 0x80081718: nop

    menu_results_loop(rdram, ctx);
        goto after_13;
    // 0x80081718: nop

    after_13:
    // 0x8008171C: b           L_800817AC
    // 0x80081720: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081720: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081724:
    // 0x80081724: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081728: jal         0x8009859C
    // 0x8008172C: nop

    menu_trophy_race_round_loop(rdram, ctx);
        goto after_14;
    // 0x8008172C: nop

    after_14:
    // 0x80081730: b           L_800817AC
    // 0x80081734: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081734: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081738:
    // 0x80081738: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008173C: jal         0x80098FD4
    // 0x80081740: nop

    menu_trophy_race_rankings_loop(rdram, ctx);
        goto after_15;
    // 0x80081740: nop

    after_15:
    // 0x80081744: b           L_800817AC
    // 0x80081748: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081748: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_8008174C:
    // 0x8008174C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081750: jal         0x8009ACFC
    // 0x80081754: nop

    menu_cinematic_loop(rdram, ctx);
        goto after_16;
    // 0x80081754: nop

    after_16:
    // 0x80081758: b           L_800817AC
    // 0x8008175C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x8008175C: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081760:
    // 0x80081760: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081764: jal         0x8009A7D4
    // 0x80081768: nop

    menu_ghost_data_loop(rdram, ctx);
        goto after_17;
    // 0x80081768: nop

    after_17:
    // 0x8008176C: b           L_800817AC
    // 0x80081770: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081770: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081774:
    // 0x80081774: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x80081778: jal         0x8009B32C
    // 0x8008177C: nop

    menu_credits_loop(rdram, ctx);
        goto after_18;
    // 0x8008177C: nop

    after_18:
    // 0x80081780: b           L_800817AC
    // 0x80081784: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081784: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_80081788:
    // 0x80081788: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x8008178C: jal         0x8008860C
    // 0x80081790: nop

    menu_boot_loop(rdram, ctx);
        goto after_19;
    // 0x80081790: nop

    after_19:
    // 0x80081794: b           L_800817AC
    // 0x80081798: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
        goto L_800817AC;
    // 0x80081798: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_8008179C:
    // 0x8008179C: lw          $a0, 0x30($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X30);
    // 0x800817A0: jal         0x8008C3FC
    // 0x800817A4: nop

    menu_caution_loop(rdram, ctx);
        goto after_20;
    // 0x800817A4: nop

    after_20:
    // 0x800817A8: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
L_800817AC:
    // 0x800817AC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800817B0: lw          $t5, 0x63A0($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X63A0);
    // 0x800817B4: lw          $t6, 0x20($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X20);
    // 0x800817B8: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800817BC: sw          $t5, 0x0($t6)
    MEM_W(0X0, ctx->r14) = ctx->r13;
    // 0x800817C0: lw          $t8, 0x24($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X24);
    // 0x800817C4: lw          $t7, 0x63A8($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X63A8);
    // 0x800817C8: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x800817CC: sw          $t7, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r15;
    // 0x800817D0: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800817D4: lw          $t9, 0x63AC($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X63AC);
    // 0x800817D8: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x800817DC: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800817E0: lw          $t2, 0x2C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X2C);
    // 0x800817E4: lw          $t1, 0x63B0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X63B0);
    // 0x800817E8: nop

    // 0x800817EC: sw          $t1, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r9;
    // 0x800817F0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800817F4: lw          $v0, 0x1C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X1C);
    // 0x800817F8: jr          $ra
    // 0x800817FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x800817FC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void obj_enable_emitter(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AF52C: lw          $t6, 0x6C($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X6C);
    // 0x800AF530: sll         $t7, $a1, 5
    ctx->r15 = S32(ctx->r5 << 5);
    // 0x800AF534: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x800AF538: lh          $a2, 0x4($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X4);
    // 0x800AF53C: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800AF540: andi        $t8, $a2, 0x4000
    ctx->r24 = ctx->r6 & 0X4000;
    // 0x800AF544: beq         $t8, $zero, L_800AF570
    if (ctx->r24 == 0) {
        // 0x800AF548: sh          $zero, 0xA($v0)
        MEM_H(0XA, ctx->r2) = 0;
            goto L_800AF570;
    }
    // 0x800AF548: sh          $zero, 0xA($v0)
    MEM_H(0XA, ctx->r2) = 0;
    // 0x800AF54C: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x800AF550: nop

    // 0x800AF554: swc1        $f4, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f4.u32l;
    // 0x800AF558: lwc1        $f6, 0x10($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X10);
    // 0x800AF55C: nop

    // 0x800AF560: swc1        $f6, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->f6.u32l;
    // 0x800AF564: lwc1        $f8, 0x14($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X14);
    // 0x800AF568: b           L_800AF6B0
    // 0x800AF56C: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
        goto L_800AF6B0;
    // 0x800AF56C: swc1        $f8, 0x14($v0)
    MEM_W(0X14, ctx->r2) = ctx->f8.u32l;
L_800AF570:
    // 0x800AF570: andi        $t9, $a2, 0x400
    ctx->r25 = ctx->r6 & 0X400;
    // 0x800AF574: beq         $t9, $zero, L_800AF638
    if (ctx->r25 == 0) {
        // 0x800AF578: lui         $t0, 0x800E
        ctx->r8 = S32(0X800E << 16);
            goto L_800AF638;
    }
    // 0x800AF578: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800AF57C: lh          $t1, 0x8($v0)
    ctx->r9 = MEM_H(ctx->r2, 0X8);
    // 0x800AF580: lw          $t0, 0x2CF0($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X2CF0);
    // 0x800AF584: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x800AF588: addu        $t3, $t0, $t2
    ctx->r11 = ADD32(ctx->r8, ctx->r10);
    // 0x800AF58C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x800AF590: lbu         $a1, 0x6($v0)
    ctx->r5 = MEM_BU(ctx->r2, 0X6);
    // 0x800AF594: lbu         $t5, 0x17($t4)
    ctx->r13 = MEM_BU(ctx->r12, 0X17);
    // 0x800AF598: nop

    // 0x800AF59C: sll         $t6, $t5, 8
    ctx->r14 = S32(ctx->r13 << 8);
    // 0x800AF5A0: blez        $a1, L_800AF5E0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AF5A4: sh          $t6, 0xA($v0)
        MEM_H(0XA, ctx->r2) = ctx->r14;
            goto L_800AF5E0;
    }
    // 0x800AF5A4: sh          $t6, 0xA($v0)
    MEM_H(0XA, ctx->r2) = ctx->r14;
    // 0x800AF5A8: blez        $a1, L_800AF5E0
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800AF5AC: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800AF5E0;
    }
    // 0x800AF5AC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800AF5B0: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
L_800AF5B4:
    // 0x800AF5B4: lw          $t7, 0xC($v0)
    ctx->r15 = MEM_W(ctx->r2, 0XC);
    // 0x800AF5B8: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x800AF5BC: addu        $t8, $t7, $a3
    ctx->r24 = ADD32(ctx->r15, ctx->r7);
    // 0x800AF5C0: lw          $a1, 0x0($t8)
    ctx->r5 = MEM_W(ctx->r24, 0X0);
    // 0x800AF5C4: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800AF5C8: sh          $zero, 0x3A($a1)
    MEM_H(0X3A, ctx->r5) = 0;
    // 0x800AF5CC: lbu         $t9, 0x6($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X6);
    // 0x800AF5D0: nop

    // 0x800AF5D4: slt         $at, $a2, $t9
    ctx->r1 = SIGNED(ctx->r6) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800AF5D8: bne         $at, $zero, L_800AF5B4
    if (ctx->r1 != 0) {
        // 0x800AF5DC: nop
    
            goto L_800AF5B4;
    }
    // 0x800AF5DC: nop

L_800AF5E0:
    // 0x800AF5E0: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AF5E4: nop

    // 0x800AF5E8: andi        $t1, $a1, 0x1
    ctx->r9 = ctx->r5 & 0X1;
    // 0x800AF5EC: beq         $t1, $zero, L_800AF618
    if (ctx->r9 == 0) {
        // 0x800AF5F0: andi        $t3, $a1, 0x4
        ctx->r11 = ctx->r5 & 0X4;
            goto L_800AF618;
    }
    // 0x800AF5F0: andi        $t3, $a1, 0x4
    ctx->r11 = ctx->r5 & 0X4;
    // 0x800AF5F4: lh          $t0, 0x14($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X14);
    // 0x800AF5F8: nop

    // 0x800AF5FC: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x800AF600: lh          $t2, 0x16($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X16);
    // 0x800AF604: nop

    // 0x800AF608: sh          $t2, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r10;
    // 0x800AF60C: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AF610: nop

    // 0x800AF614: andi        $t3, $a1, 0x4
    ctx->r11 = ctx->r5 & 0X4;
L_800AF618:
    // 0x800AF618: beq         $t3, $zero, L_800AF6B0
    if (ctx->r11 == 0) {
        // 0x800AF61C: nop
    
            goto L_800AF6B0;
    }
    // 0x800AF61C: nop

    // 0x800AF620: lh          $t4, 0x22($v1)
    ctx->r12 = MEM_H(ctx->r3, 0X22);
    // 0x800AF624: nop

    // 0x800AF628: sh          $t4, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r12;
    // 0x800AF62C: lh          $t5, 0x24($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X24);
    // 0x800AF630: b           L_800AF6B0
    // 0x800AF634: sh          $t5, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r13;
        goto L_800AF6B0;
    // 0x800AF634: sh          $t5, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r13;
L_800AF638:
    // 0x800AF638: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AF63C: nop

    // 0x800AF640: andi        $t6, $a1, 0x1
    ctx->r14 = ctx->r5 & 0X1;
    // 0x800AF644: beq         $t6, $zero, L_800AF680
    if (ctx->r14 == 0) {
        // 0x800AF648: andi        $t1, $a1, 0x4
        ctx->r9 = ctx->r5 & 0X4;
            goto L_800AF680;
    }
    // 0x800AF648: andi        $t1, $a1, 0x4
    ctx->r9 = ctx->r5 & 0X4;
    // 0x800AF64C: sb          $zero, 0x6($v0)
    MEM_B(0X6, ctx->r2) = 0;
    // 0x800AF650: lh          $t7, 0x14($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X14);
    // 0x800AF654: nop

    // 0x800AF658: sh          $t7, 0xC($v0)
    MEM_H(0XC, ctx->r2) = ctx->r15;
    // 0x800AF65C: lh          $t8, 0x16($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X16);
    // 0x800AF660: nop

    // 0x800AF664: sh          $t8, 0xE($v0)
    MEM_H(0XE, ctx->r2) = ctx->r24;
    // 0x800AF668: lh          $t9, 0x18($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X18);
    // 0x800AF66C: nop

    // 0x800AF670: sh          $t9, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r25;
    // 0x800AF674: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800AF678: nop

    // 0x800AF67C: andi        $t1, $a1, 0x4
    ctx->r9 = ctx->r5 & 0X4;
L_800AF680:
    // 0x800AF680: beq         $t1, $zero, L_800AF6B0
    if (ctx->r9 == 0) {
        // 0x800AF684: nop
    
            goto L_800AF6B0;
    }
    // 0x800AF684: nop

    // 0x800AF688: sb          $zero, 0x7($v0)
    MEM_B(0X7, ctx->r2) = 0;
    // 0x800AF68C: lh          $t0, 0x22($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X22);
    // 0x800AF690: nop

    // 0x800AF694: sh          $t0, 0x12($v0)
    MEM_H(0X12, ctx->r2) = ctx->r8;
    // 0x800AF698: lh          $t2, 0x24($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X24);
    // 0x800AF69C: nop

    // 0x800AF6A0: sh          $t2, 0x14($v0)
    MEM_H(0X14, ctx->r2) = ctx->r10;
    // 0x800AF6A4: lh          $t3, 0x26($v1)
    ctx->r11 = MEM_H(ctx->r3, 0X26);
    // 0x800AF6A8: nop

    // 0x800AF6AC: sh          $t3, 0x16($v0)
    MEM_H(0X16, ctx->r2) = ctx->r11;
L_800AF6B0:
    // 0x800AF6B0: lh          $t4, 0x4($v0)
    ctx->r12 = MEM_H(ctx->r2, 0X4);
    // 0x800AF6B4: nop

    // 0x800AF6B8: andi        $t5, $t4, 0xFDFF
    ctx->r13 = ctx->r12 & 0XFDFF;
    // 0x800AF6BC: sh          $t5, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r13;
    // 0x800AF6C0: lh          $t6, 0x4($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X4);
    // 0x800AF6C4: nop

    // 0x800AF6C8: ori         $t7, $t6, 0xA000
    ctx->r15 = ctx->r14 | 0XA000;
    // 0x800AF6CC: sh          $t7, 0x4($v0)
    MEM_H(0X4, ctx->r2) = ctx->r15;
    // 0x800AF6D0: lh          $t8, 0x1A($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X1A);
    // 0x800AF6D4: nop

    // 0x800AF6D8: addiu       $t9, $t8, 0x1
    ctx->r25 = ADD32(ctx->r24, 0X1);
    // 0x800AF6DC: jr          $ra
    // 0x800AF6E0: sh          $t9, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r25;
    return;
    // 0x800AF6E0: sh          $t9, 0x1A($a0)
    MEM_H(0X1A, ctx->r4) = ctx->r25;
;}
RECOMP_FUNC void rumble_update(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80072718: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8007271C: sw          $fp, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r30;
    // 0x80072720: lui         $fp, 0x8012
    ctx->r30 = S32(0X8012 << 16);
    // 0x80072724: addiu       $fp, $fp, 0x41E6
    ctx->r30 = ADD32(ctx->r30, 0X41E6);
    // 0x80072728: lbu         $t6, 0x0($fp)
    ctx->r14 = MEM_BU(ctx->r30, 0X0);
    // 0x8007272C: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80072730: sw          $s7, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r23;
    // 0x80072734: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x80072738: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8007273C: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x80072740: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x80072744: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x80072748: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8007274C: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x80072750: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80072754: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80072758: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8007275C: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80072760: bne         $t6, $zero, L_80072778
    if (ctx->r14 != 0) {
        // 0x80072764: sw          $a0, 0x78($sp)
        MEM_W(0X78, ctx->r29) = ctx->r4;
            goto L_80072778;
    }
    // 0x80072764: sw          $a0, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r4;
    // 0x80072768: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x8007276C: lw          $t7, -0x1B74($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X1B74);
    // 0x80072770: nop

    // 0x80072774: beq         $t7, $zero, L_80072C14
    if (ctx->r15 == 0) {
        // 0x80072778: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80072C14;
    }
L_80072778:
    // 0x80072778: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007277C: addiu       $v0, $v0, 0x41E8
    ctx->r2 = ADD32(ctx->r2, 0X41E8);
    // 0x80072780: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80072784: lw          $t9, 0x78($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X78);
    // 0x80072788: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007278C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80072790: slti        $at, $t0, 0x79
    ctx->r1 = SIGNED(ctx->r8) < 0X79 ? 1 : 0;
    // 0x80072794: bne         $at, $zero, L_80072884
    if (ctx->r1 != 0) {
        // 0x80072798: sw          $t0, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r8;
            goto L_80072884;
    }
    // 0x80072798: sw          $t0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r8;
    // 0x8007279C: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800727A0: lw          $a0, 0x4010($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4010);
    // 0x800727A4: jal         0x800CD290
    // 0x800727A8: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_0;
    // 0x800727A8: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    after_0:
    // 0x800727AC: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x800727B0: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800727B4: addiu       $s4, $s4, 0x41E7
    ctx->r20 = ADD32(ctx->r20, 0X41E7);
    // 0x800727B8: addiu       $s6, $s6, 0x4018
    ctx->r22 = ADD32(ctx->r22, 0X4018);
    // 0x800727BC: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800727C0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x800727C4: addiu       $s7, $zero, 0x68
    ctx->r23 = ADD32(0, 0X68);
L_800727C8:
    // 0x800727C8: lbu         $t2, 0x6D($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6D);
    // 0x800727CC: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x800727D0: and         $t3, $t2, $v1
    ctx->r11 = ctx->r10 & ctx->r3;
    // 0x800727D4: beq         $t3, $zero, L_80072864
    if (ctx->r11 == 0) {
        // 0x800727D8: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80072864;
    }
    // 0x800727D8: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800727DC: lbu         $t4, 0x0($fp)
    ctx->r12 = MEM_BU(ctx->r30, 0X0);
    // 0x800727E0: lbu         $t6, 0x41E5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X41E5);
    // 0x800727E4: nor         $t5, $t4, $zero
    ctx->r13 = ~(ctx->r12 | 0);
    // 0x800727E8: and         $t7, $t5, $t6
    ctx->r15 = ctx->r13 & ctx->r14;
    // 0x800727EC: and         $t8, $t7, $v1
    ctx->r24 = ctx->r15 & ctx->r3;
    // 0x800727F0: bne         $t8, $zero, L_80072864
    if (ctx->r24 != 0) {
        // 0x800727F4: nop
    
            goto L_80072864;
    }
    // 0x800727F4: nop

    // 0x800727F8: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800727FC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072800: lw          $a0, 0x4010($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4010);
    // 0x80072804: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80072808: mflo        $t9
    ctx->r25 = lo;
    // 0x8007280C: addu        $a1, $s6, $t9
    ctx->r5 = ADD32(ctx->r22, ctx->r25);
    // 0x80072810: jal         0x800720DC
    // 0x80072814: nop

    osMotorInit_recomp(rdram, ctx);
        goto after_1;
    // 0x80072814: nop

    after_1:
    // 0x80072818: beq         $v0, $zero, L_80072854
    if (ctx->r2 == 0) {
        // 0x8007281C: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_80072854;
    }
    // 0x8007281C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80072820: lbu         $t0, 0x0($fp)
    ctx->r8 = MEM_BU(ctx->r30, 0X0);
    // 0x80072824: lbu         $t2, 0x0($s4)
    ctx->r10 = MEM_BU(ctx->r20, 0X0);
    // 0x80072828: nor         $v0, $s1, $zero
    ctx->r2 = ~(ctx->r17 | 0);
    // 0x8007282C: and         $t1, $t0, $v0
    ctx->r9 = ctx->r8 & ctx->r2;
    // 0x80072830: and         $t3, $t2, $v0
    ctx->r11 = ctx->r10 & ctx->r2;
    // 0x80072834: sb          $t1, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r9;
    // 0x80072838: sb          $t3, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r11;
    // 0x8007283C: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80072840: lbu         $t4, 0x41E5($t4)
    ctx->r12 = MEM_BU(ctx->r12, 0X41E5);
    // 0x80072844: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072848: and         $t5, $t4, $v0
    ctx->r13 = ctx->r12 & ctx->r2;
    // 0x8007284C: b           L_80072864
    // 0x80072850: sb          $t5, 0x41E5($at)
    MEM_B(0X41E5, ctx->r1) = ctx->r13;
        goto L_80072864;
    // 0x80072850: sb          $t5, 0x41E5($at)
    MEM_B(0X41E5, ctx->r1) = ctx->r13;
L_80072854:
    // 0x80072854: lbu         $t6, 0x41E5($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X41E5);
    // 0x80072858: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007285C: or          $t7, $t6, $s1
    ctx->r15 = ctx->r14 | ctx->r17;
    // 0x80072860: sb          $t7, 0x41E5($at)
    MEM_B(0X41E5, ctx->r1) = ctx->r15;
L_80072864:
    // 0x80072864: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x80072868: andi        $t8, $s3, 0xFF
    ctx->r24 = ctx->r19 & 0XFF;
    // 0x8007286C: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x80072870: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x80072874: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80072878: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x8007287C: bne         $at, $zero, L_800727C8
    if (ctx->r1 != 0) {
        // 0x80072880: or          $s3, $t8, $zero
        ctx->r19 = ctx->r24 | 0;
            goto L_800727C8;
    }
    // 0x80072880: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
L_80072884:
    // 0x80072884: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80072888: lbu         $t0, 0x41E5($t0)
    ctx->r8 = MEM_BU(ctx->r8, 0X41E5);
    // 0x8007288C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072890: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x80072894: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x80072898: lw          $a0, -0x1B74($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1B74);
    // 0x8007289C: addiu       $s6, $s6, 0x4018
    ctx->r22 = ADD32(ctx->r22, 0X4018);
    // 0x800728A0: addiu       $s4, $s4, 0x41E7
    ctx->r20 = ADD32(ctx->r20, 0X41E7);
    // 0x800728A4: bne         $t0, $zero, L_800728B4
    if (ctx->r8 != 0) {
        // 0x800728A8: addiu       $s7, $zero, 0x68
        ctx->r23 = ADD32(0, 0X68);
            goto L_800728B4;
    }
    // 0x800728A8: addiu       $s7, $zero, 0x68
    ctx->r23 = ADD32(0, 0X68);
    // 0x800728AC: beq         $a0, $zero, L_80072C18
    if (ctx->r4 == 0) {
        // 0x800728B0: lw          $ra, 0x4C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X4C);
            goto L_80072C18;
    }
    // 0x800728B0: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_800728B4:
    // 0x800728B4: beq         $a0, $zero, L_800728D8
    if (ctx->r4 == 0) {
        // 0x800728B8: or          $s5, $zero, $zero
        ctx->r21 = 0 | 0;
            goto L_800728D8;
    }
    // 0x800728B8: or          $s5, $zero, $zero
    ctx->r21 = 0 | 0;
    // 0x800728BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800728C0: lw          $a0, 0x4010($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4010);
    // 0x800728C4: jal         0x800CD290
    // 0x800728C8: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    osPfsIsPlug_recomp(rdram, ctx);
        goto after_2;
    // 0x800728C8: addiu       $a1, $sp, 0x6D
    ctx->r5 = ADD32(ctx->r29, 0X6D);
    after_2:
    // 0x800728CC: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800728D0: lw          $a0, -0x1B74($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1B74);
    // 0x800728D4: nop

L_800728D8:
    // 0x800728D8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800728DC: lwc1        $f23, 0x77E8($at)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r1, 0X77E8);
    // 0x800728E0: lwc1        $f22, 0x77EC($at)
    ctx->f22.u32l = MEM_W(ctx->r1, 0X77EC);
    // 0x800728E4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800728E8: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x800728EC: lwc1        $f21, 0x77F0($at)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r1, 0X77F0);
    // 0x800728F0: lwc1        $f20, 0x77F4($at)
    ctx->f20.u32l = MEM_W(ctx->r1, 0X77F4);
    // 0x800728F4: addiu       $s0, $s0, 0x41B8
    ctx->r16 = ADD32(ctx->r16, 0X41B8);
    // 0x800728F8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800728FC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_80072900:
    // 0x80072900: beq         $a0, $zero, L_80072980
    if (ctx->r4 == 0) {
        // 0x80072904: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_80072980;
    }
    // 0x80072904: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80072908: addiu       $t1, $zero, -0x1
    ctx->r9 = ADD32(0, -0X1);
    // 0x8007290C: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    // 0x80072910: lh          $v0, 0x4($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X4);
    // 0x80072914: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x80072918: sh          $v0, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r2;
    // 0x8007291C: sh          $v0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r2;
    // 0x80072920: lbu         $t2, 0x6D($sp)
    ctx->r10 = MEM_BU(ctx->r29, 0X6D);
    // 0x80072924: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072928: and         $t3, $t2, $v1
    ctx->r11 = ctx->r10 & ctx->r3;
    // 0x8007292C: bne         $t3, $zero, L_80072940
    if (ctx->r11 != 0) {
        // 0x80072930: nop
    
            goto L_80072940;
    }
    // 0x80072930: nop

    // 0x80072934: lw          $a0, -0x1B74($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1B74);
    // 0x80072938: b           L_80072BD8
    // 0x8007293C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072BD8;
    // 0x8007293C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072940:
    // 0x80072940: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072944: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80072948: lw          $a0, 0x4010($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X4010);
    // 0x8007294C: or          $a2, $s3, $zero
    ctx->r6 = ctx->r19 | 0;
    // 0x80072950: mflo        $t4
    ctx->r12 = lo;
    // 0x80072954: addu        $s2, $s6, $t4
    ctx->r18 = ADD32(ctx->r22, ctx->r12);
    // 0x80072958: jal         0x800720DC
    // 0x8007295C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_3;
    // 0x8007295C: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_3:
    // 0x80072960: bne         $v0, $zero, L_80072970
    if (ctx->r2 != 0) {
        // 0x80072964: nop
    
            goto L_80072970;
    }
    // 0x80072964: nop

    // 0x80072968: jal         0x80071D30
    // 0x8007296C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    osMotorStop_recomp(rdram, ctx);
        goto after_4;
    // 0x8007296C: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_4:
L_80072970:
    // 0x80072970: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072974: lw          $a0, -0x1B74($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1B74);
    // 0x80072978: b           L_80072BD8
    // 0x8007297C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072BD8;
    // 0x8007297C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072980:
    // 0x80072980: lbu         $v0, 0x0($fp)
    ctx->r2 = MEM_BU(ctx->r30, 0X0);
    // 0x80072984: lbu         $t5, 0x41E5($t5)
    ctx->r13 = MEM_BU(ctx->r13, 0X41E5);
    // 0x80072988: or          $s1, $v1, $zero
    ctx->r17 = ctx->r3 | 0;
    // 0x8007298C: and         $t6, $v0, $t5
    ctx->r14 = ctx->r2 & ctx->r13;
    // 0x80072990: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x80072994: beq         $t7, $zero, L_80072BD4
    if (ctx->r15 == 0) {
        // 0x80072998: nop
    
            goto L_80072BD4;
    }
    // 0x80072998: nop

    // 0x8007299C: lh          $v1, 0x4($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X4);
    // 0x800729A0: lw          $t2, 0x78($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X78);
    // 0x800729A4: bgtz        $v1, L_800729E8
    if (SIGNED(ctx->r3) > 0) {
        // 0x800729A8: subu        $t3, $v1, $t2
        ctx->r11 = SUB32(ctx->r3, ctx->r10);
            goto L_800729E8;
    }
    // 0x800729A8: subu        $t3, $v1, $t2
    ctx->r11 = SUB32(ctx->r3, ctx->r10);
    // 0x800729AC: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800729B0: nor         $t8, $s1, $zero
    ctx->r24 = ~(ctx->r17 | 0);
    // 0x800729B4: and         $t9, $v0, $t8
    ctx->r25 = ctx->r2 & ctx->r24;
    // 0x800729B8: sb          $t9, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r25;
    // 0x800729BC: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x800729C0: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x800729C4: sh          $zero, 0x8($s0)
    MEM_H(0X8, ctx->r16) = 0;
    // 0x800729C8: mflo        $t1
    ctx->r9 = lo;
    // 0x800729CC: addu        $a0, $s6, $t1
    ctx->r4 = ADD32(ctx->r22, ctx->r9);
    // 0x800729D0: jal         0x80071D30
    // 0x800729D4: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_5;
    // 0x800729D4: nop

    after_5:
    // 0x800729D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800729DC: lw          $a0, -0x1B74($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1B74);
    // 0x800729E0: b           L_80072BD8
    // 0x800729E4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072BD8;
    // 0x800729E4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_800729E8:
    // 0x800729E8: sh          $t3, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r11;
    // 0x800729EC: lw          $t5, 0x78($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X78);
    // 0x800729F0: lh          $t4, 0x8($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X8);
    // 0x800729F4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800729F8: addu        $t6, $t4, $t5
    ctx->r14 = ADD32(ctx->r12, ctx->r13);
    // 0x800729FC: sh          $t6, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r14;
    // 0x80072A00: lh          $v0, 0x8($s0)
    ctx->r2 = MEM_H(ctx->r16, 0X8);
    // 0x80072A04: nop

    // 0x80072A08: bgez        $v0, L_80072A1C
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80072A0C: slti        $at, $v0, 0x259
        ctx->r1 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
            goto L_80072A1C;
    }
    // 0x80072A0C: slti        $at, $v0, 0x259
    ctx->r1 = SIGNED(ctx->r2) < 0X259 ? 1 : 0;
    // 0x80072A10: lw          $a0, -0x1B74($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1B74);
    // 0x80072A14: b           L_80072BD8
    // 0x80072A18: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072BD8;
    // 0x80072A18: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072A1C:
    // 0x80072A1C: bne         $at, $zero, L_80072A68
    if (ctx->r1 != 0) {
        // 0x80072A20: nop
    
            goto L_80072A68;
    }
    // 0x80072A20: nop

    // 0x80072A24: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072A28: lbu         $t7, 0x0($fp)
    ctx->r15 = MEM_BU(ctx->r30, 0X0);
    // 0x80072A2C: nor         $t8, $s1, $zero
    ctx->r24 = ~(ctx->r17 | 0);
    // 0x80072A30: and         $t9, $t7, $t8
    ctx->r25 = ctx->r15 & ctx->r24;
    // 0x80072A34: sb          $t9, 0x0($fp)
    MEM_B(0X0, ctx->r30) = ctx->r25;
    // 0x80072A38: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x80072A3C: addiu       $t1, $zero, -0x12C
    ctx->r9 = ADD32(0, -0X12C);
    // 0x80072A40: sh          $t0, 0x0($s0)
    MEM_H(0X0, ctx->r16) = ctx->r8;
    // 0x80072A44: sh          $t1, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r9;
    // 0x80072A48: mflo        $t2
    ctx->r10 = lo;
    // 0x80072A4C: addu        $a0, $s6, $t2
    ctx->r4 = ADD32(ctx->r22, ctx->r10);
    // 0x80072A50: jal         0x80071D30
    // 0x80072A54: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_6;
    // 0x80072A54: nop

    after_6:
    // 0x80072A58: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072A5C: lw          $a0, -0x1B74($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1B74);
    // 0x80072A60: b           L_80072BD8
    // 0x80072A64: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
        goto L_80072BD8;
    // 0x80072A64: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072A68:
    // 0x80072A68: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80072A6C: nop

    // 0x80072A70: mtc1        $a0, $f4
    ctx->f4.u32l = ctx->r4;
    // 0x80072A74: nop

    // 0x80072A78: cvt.d.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.d = CVT_D_W(ctx->f4.u32l);
    // 0x80072A7C: c.lt.d      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.d < ctx->f0.d;
    // 0x80072A80: nop

    // 0x80072A84: bc1f        L_80072AC8
    if (!c1cs) {
        // 0x80072A88: nop
    
            goto L_80072AC8;
    }
    // 0x80072A88: nop

    // 0x80072A8C: lbu         $t3, 0x0($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X0);
    // 0x80072A90: nop

    // 0x80072A94: and         $t4, $t3, $s1
    ctx->r12 = ctx->r11 & ctx->r17;
    // 0x80072A98: bne         $t4, $zero, L_80072BC8
    if (ctx->r12 != 0) {
        // 0x80072A9C: nop
    
            goto L_80072BC8;
    }
    // 0x80072A9C: nop

    // 0x80072AA0: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072AA4: mflo        $t5
    ctx->r13 = lo;
    // 0x80072AA8: addu        $a0, $s6, $t5
    ctx->r4 = ADD32(ctx->r22, ctx->r13);
    // 0x80072AAC: jal         0x80071E58
    // 0x80072AB0: nop

    osMotorStart_recomp(rdram, ctx);
        goto after_7;
    // 0x80072AB0: nop

    after_7:
    // 0x80072AB4: lbu         $t6, 0x0($s4)
    ctx->r14 = MEM_BU(ctx->r20, 0X0);
    // 0x80072AB8: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072ABC: or          $t7, $t6, $s1
    ctx->r15 = ctx->r14 | ctx->r17;
    // 0x80072AC0: b           L_80072BC8
    // 0x80072AC4: sb          $t7, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r15;
        goto L_80072BC8;
    // 0x80072AC4: sb          $t7, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r15;
L_80072AC8:
    // 0x80072AC8: c.lt.d      $f0, $f22
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f0.d < ctx->f22.d;
    // 0x80072ACC: nop

    // 0x80072AD0: bc1f        L_80072B18
    if (!c1cs) {
        // 0x80072AD4: nop
    
            goto L_80072B18;
    }
    // 0x80072AD4: nop

    // 0x80072AD8: lbu         $t8, 0x0($s4)
    ctx->r24 = MEM_BU(ctx->r20, 0X0);
    // 0x80072ADC: nop

    // 0x80072AE0: and         $t9, $t8, $s1
    ctx->r25 = ctx->r24 & ctx->r17;
    // 0x80072AE4: beq         $t9, $zero, L_80072BC8
    if (ctx->r25 == 0) {
        // 0x80072AE8: nop
    
            goto L_80072BC8;
    }
    // 0x80072AE8: nop

    // 0x80072AEC: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072AF0: mflo        $t0
    ctx->r8 = lo;
    // 0x80072AF4: addu        $a0, $s6, $t0
    ctx->r4 = ADD32(ctx->r22, ctx->r8);
    // 0x80072AF8: jal         0x80071D30
    // 0x80072AFC: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_8;
    // 0x80072AFC: nop

    after_8:
    // 0x80072B00: lbu         $t1, 0x0($s4)
    ctx->r9 = MEM_BU(ctx->r20, 0X0);
    // 0x80072B04: nor         $t2, $s1, $zero
    ctx->r10 = ~(ctx->r17 | 0);
    // 0x80072B08: and         $t3, $t1, $t2
    ctx->r11 = ctx->r9 & ctx->r10;
    // 0x80072B0C: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072B10: b           L_80072BC8
    // 0x80072B14: sb          $t3, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r11;
        goto L_80072BC8;
    // 0x80072B14: sb          $t3, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r11;
L_80072B18:
    // 0x80072B18: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80072B1C: nop

    // 0x80072B20: slti        $at, $v1, 0x100
    ctx->r1 = SIGNED(ctx->r3) < 0X100 ? 1 : 0;
    // 0x80072B24: bne         $at, $zero, L_80072B78
    if (ctx->r1 != 0) {
        // 0x80072B28: nop
    
            goto L_80072B78;
    }
    // 0x80072B28: nop

    // 0x80072B2C: lbu         $t4, 0x0($s4)
    ctx->r12 = MEM_BU(ctx->r20, 0X0);
    // 0x80072B30: nop

    // 0x80072B34: and         $t5, $t4, $s1
    ctx->r13 = ctx->r12 & ctx->r17;
    // 0x80072B38: bne         $t5, $zero, L_80072B70
    if (ctx->r13 != 0) {
        // 0x80072B3C: addiu       $t9, $v1, -0x100
        ctx->r25 = ADD32(ctx->r3, -0X100);
            goto L_80072B70;
    }
    // 0x80072B3C: addiu       $t9, $v1, -0x100
    ctx->r25 = ADD32(ctx->r3, -0X100);
    // 0x80072B40: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072B44: mflo        $t6
    ctx->r14 = lo;
    // 0x80072B48: addu        $a0, $s6, $t6
    ctx->r4 = ADD32(ctx->r22, ctx->r14);
    // 0x80072B4C: jal         0x80071E58
    // 0x80072B50: nop

    osMotorStart_recomp(rdram, ctx);
        goto after_9;
    // 0x80072B50: nop

    after_9:
    // 0x80072B54: lbu         $t7, 0x0($s4)
    ctx->r15 = MEM_BU(ctx->r20, 0X0);
    // 0x80072B58: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072B5C: or          $t8, $t7, $s1
    ctx->r24 = ctx->r15 | ctx->r17;
    // 0x80072B60: sb          $t8, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r24;
    // 0x80072B64: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80072B68: nop

    // 0x80072B6C: addiu       $t9, $v1, -0x100
    ctx->r25 = ADD32(ctx->r3, -0X100);
L_80072B70:
    // 0x80072B70: b           L_80072BC8
    // 0x80072B74: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
        goto L_80072BC8;
    // 0x80072B74: sh          $t9, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r25;
L_80072B78:
    // 0x80072B78: lbu         $t0, 0x0($s4)
    ctx->r8 = MEM_BU(ctx->r20, 0X0);
    // 0x80072B7C: nop

    // 0x80072B80: and         $t1, $t0, $s1
    ctx->r9 = ctx->r8 & ctx->r17;
    // 0x80072B84: beq         $t1, $zero, L_80072BC0
    if (ctx->r9 == 0) {
        // 0x80072B88: addu        $t6, $v1, $a0
        ctx->r14 = ADD32(ctx->r3, ctx->r4);
            goto L_80072BC0;
    }
    // 0x80072B88: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
    // 0x80072B8C: multu       $s3, $s7
    result = U64(U32(ctx->r19)) * U64(U32(ctx->r23)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80072B90: mflo        $t2
    ctx->r10 = lo;
    // 0x80072B94: addu        $a0, $s6, $t2
    ctx->r4 = ADD32(ctx->r22, ctx->r10);
    // 0x80072B98: jal         0x80071D30
    // 0x80072B9C: nop

    osMotorStop_recomp(rdram, ctx);
        goto after_10;
    // 0x80072B9C: nop

    after_10:
    // 0x80072BA0: lbu         $t3, 0x0($s4)
    ctx->r11 = MEM_BU(ctx->r20, 0X0);
    // 0x80072BA4: nor         $t4, $s1, $zero
    ctx->r12 = ~(ctx->r17 | 0);
    // 0x80072BA8: and         $t5, $t3, $t4
    ctx->r13 = ctx->r11 & ctx->r12;
    // 0x80072BAC: sb          $t5, 0x0($s4)
    MEM_B(0X0, ctx->r20) = ctx->r13;
    // 0x80072BB0: lh          $v1, 0x6($s0)
    ctx->r3 = MEM_H(ctx->r16, 0X6);
    // 0x80072BB4: lh          $a0, 0x2($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X2);
    // 0x80072BB8: or          $s5, $s5, $v0
    ctx->r21 = ctx->r21 | ctx->r2;
    // 0x80072BBC: addu        $t6, $v1, $a0
    ctx->r14 = ADD32(ctx->r3, ctx->r4);
L_80072BC0:
    // 0x80072BC0: addiu       $t7, $t6, 0x4
    ctx->r15 = ADD32(ctx->r14, 0X4);
    // 0x80072BC4: sh          $t7, 0x6($s0)
    MEM_H(0X6, ctx->r16) = ctx->r15;
L_80072BC8:
    // 0x80072BC8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80072BCC: lw          $a0, -0x1B74($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X1B74);
    // 0x80072BD0: nop

L_80072BD4:
    // 0x80072BD4: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_80072BD8:
    // 0x80072BD8: andi        $t8, $s3, 0xFF
    ctx->r24 = ctx->r19 & 0XFF;
    // 0x80072BDC: sll         $v1, $s1, 1
    ctx->r3 = S32(ctx->r17 << 1);
    // 0x80072BE0: andi        $t9, $v1, 0xFF
    ctx->r25 = ctx->r3 & 0XFF;
    // 0x80072BE4: slti        $at, $t8, 0x4
    ctx->r1 = SIGNED(ctx->r24) < 0X4 ? 1 : 0;
    // 0x80072BE8: or          $v1, $t9, $zero
    ctx->r3 = ctx->r25 | 0;
    // 0x80072BEC: or          $s3, $t8, $zero
    ctx->r19 = ctx->r24 | 0;
    // 0x80072BF0: bne         $at, $zero, L_80072900
    if (ctx->r1 != 0) {
        // 0x80072BF4: addiu       $s0, $s0, 0xA
        ctx->r16 = ADD32(ctx->r16, 0XA);
            goto L_80072900;
    }
    // 0x80072BF4: addiu       $s0, $s0, 0xA
    ctx->r16 = ADD32(ctx->r16, 0XA);
    // 0x80072BF8: beq         $s5, $zero, L_80072C04
    if (ctx->r21 == 0) {
        // 0x80072BFC: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_80072C04;
    }
    // 0x80072BFC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80072C00: sb          $zero, 0x41E5($at)
    MEM_B(0X41E5, ctx->r1) = 0;
L_80072C04:
    // 0x80072C04: beq         $a0, $zero, L_80072C14
    if (ctx->r4 == 0) {
        // 0x80072C08: addiu       $t0, $a0, -0x1
        ctx->r8 = ADD32(ctx->r4, -0X1);
            goto L_80072C14;
    }
    // 0x80072C08: addiu       $t0, $a0, -0x1
    ctx->r8 = ADD32(ctx->r4, -0X1);
    // 0x80072C0C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80072C10: sw          $t0, -0x1B74($at)
    MEM_W(-0X1B74, ctx->r1) = ctx->r8;
L_80072C14:
    // 0x80072C14: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
L_80072C18:
    // 0x80072C18: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80072C1C: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80072C20: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80072C24: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80072C28: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x80072C2C: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x80072C30: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x80072C34: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x80072C38: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x80072C3C: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x80072C40: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x80072C44: lw          $s7, 0x44($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X44);
    // 0x80072C48: lw          $fp, 0x48($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X48);
    // 0x80072C4C: jr          $ra
    // 0x80072C50: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x80072C50: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void menu_magic_codes_list_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008A4E8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A4EC: sw          $zero, 0x63BC($at)
    MEM_W(0X63BC, ctx->r1) = 0;
    // 0x8008A4F0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8008A4F4: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x8008A4F8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A4FC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008A500: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
    // 0x8008A504: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008A508: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A50C: sh          $zero, 0x6C46($at)
    MEM_H(0X6C46, ctx->r1) = 0;
    // 0x8008A510: jal         0x800C4170
    // 0x8008A514: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_0;
    // 0x8008A514: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008A518: jal         0x8009C6D4
    // 0x8008A51C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    menu_asset_load(rdram, ctx);
        goto after_1;
    // 0x8008A51C: addiu       $a0, $zero, 0x3F
    ctx->r4 = ADD32(0, 0X3F);
    after_1:
    // 0x8008A520: jal         0x8008E4B0
    // 0x8008A524: nop

    menu_init_arrow_textures(rdram, ctx);
        goto after_2;
    // 0x8008A524: nop

    after_2:
    // 0x8008A528: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008A52C: jal         0x800C01D8
    // 0x8008A530: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8008A530: addiu       $a0, $a0, -0x884
    ctx->r4 = ADD32(ctx->r4, -0X884);
    after_3:
    // 0x8008A534: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x8008A538: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x8008A53C: addiu       $t8, $zero, 0xA
    ctx->r24 = ADD32(0, 0XA);
    // 0x8008A540: bne         $t6, $zero, L_8008A558
    if (ctx->r14 != 0) {
        // 0x8008A544: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8008A558;
    }
    // 0x8008A544: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A548: addiu       $t7, $zero, 0xB
    ctx->r15 = ADD32(0, 0XB);
    // 0x8008A54C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008A550: b           L_8008A55C
    // 0x8008A554: sw          $t7, 0x6C70($at)
    MEM_W(0X6C70, ctx->r1) = ctx->r15;
        goto L_8008A55C;
    // 0x8008A554: sw          $t7, 0x6C70($at)
    MEM_W(0X6C70, ctx->r1) = ctx->r15;
L_8008A558:
    // 0x8008A558: sw          $t8, 0x6C70($at)
    MEM_W(0X6C70, ctx->r1) = ctx->r24;
L_8008A55C:
    // 0x8008A55C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008A560: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008A564: jr          $ra
    // 0x8008A568: nop

    return;
    // 0x8008A568: nop

;}
RECOMP_FUNC void set_taj_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800521B8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800521BC: jr          $ra
    // 0x800521C0: sb          $a0, -0x2A7E($at)
    MEM_B(-0X2A7E, ctx->r1) = ctx->r4;
    return;
    // 0x800521C0: sb          $a0, -0x2A7E($at)
    MEM_B(-0X2A7E, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void music_change_off(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80000B18: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80000B1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80000B20: jr          $ra
    // 0x80000B24: sw          $t6, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = ctx->r14;
    return;
    // 0x80000B24: sw          $t6, -0x39B8($at)
    MEM_W(-0X39B8, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void menu_controller_pak_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800890AC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800890B0: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x800890B4: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800890B8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800890BC: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
    // 0x800890C0: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x800890C4: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800890C8: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x800890CC: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x800890D0: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x800890D4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800890D8: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800890DC: sw          $zero, 0x30($sp)
    MEM_W(0X30, ctx->r29) = 0;
    // 0x800890E0: sw          $zero, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = 0;
    // 0x800890E4: beq         $at, $zero, L_80089108
    if (ctx->r1 == 0) {
        // 0x800890E8: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_80089108;
    }
    // 0x800890E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x800890EC: jal         0x80088938
    // 0x800890F0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    pakmenu_render(rdram, ctx);
        goto after_0;
    // 0x800890F0: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    after_0:
    // 0x800890F4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800890F8: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x800890FC: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80089100: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x80089104: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_80089108:
    // 0x80089108: bne         $v0, $zero, L_80089568
    if (ctx->r2 != 0) {
        // 0x8008910C: addu        $t4, $v0, $a0
        ctx->r12 = ADD32(ctx->r2, ctx->r4);
            goto L_80089568;
    }
    // 0x8008910C: addu        $t4, $v0, $a0
    ctx->r12 = ADD32(ctx->r2, ctx->r4);
    // 0x80089110: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80089114: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80089118: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8008911C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x80089120: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x80089124: addiu       $a1, $a1, 0x6464
    ctx->r5 = ADD32(ctx->r5, 0X6464);
    // 0x80089128: addiu       $v1, $v1, 0x645C
    ctx->r3 = ADD32(ctx->r3, 0X645C);
    // 0x8008912C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
L_80089130:
    // 0x80089130: sw          $v1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r3;
    // 0x80089134: sw          $a0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r4;
    // 0x80089138: sw          $a1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r5;
    // 0x8008913C: sw          $a2, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r6;
    // 0x80089140: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    // 0x80089144: jal         0x8006A554
    // 0x80089148: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x80089148: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x8008914C: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80089150: lw          $a1, 0x18($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X18);
    // 0x80089154: lw          $a0, 0x44($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X44);
    // 0x80089158: lw          $a2, 0x40($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X40);
    // 0x8008915C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80089160: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x80089164: lb          $t9, 0x0($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X0);
    // 0x80089168: lb          $t4, 0x0($a1)
    ctx->r12 = MEM_B(ctx->r5, 0X0);
    // 0x8008916C: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80089170: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80089174: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x80089178: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8008917C: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
    // 0x80089180: addu        $a3, $a3, $t9
    ctx->r7 = ADD32(ctx->r7, ctx->r25);
    // 0x80089184: bne         $a0, $at, L_80089130
    if (ctx->r4 != ctx->r1) {
        // 0x80089188: addu        $t0, $t0, $t4
        ctx->r8 = ADD32(ctx->r8, ctx->r12);
            goto L_80089130;
    }
    // 0x80089188: addu        $t0, $t0, $t4
    ctx->r8 = ADD32(ctx->r8, ctx->r12);
    // 0x8008918C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80089190: lw          $v0, 0x6BC8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6BC8);
    // 0x80089194: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80089198: beq         $v0, $zero, L_80089234
    if (ctx->r2 == 0) {
        // 0x8008919C: addiu       $t2, $t2, 0x63E0
        ctx->r10 = ADD32(ctx->r10, 0X63E0);
            goto L_80089234;
    }
    // 0x8008919C: addiu       $t2, $t2, 0x63E0
    ctx->r10 = ADD32(ctx->r10, 0X63E0);
    // 0x800891A0: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800891A4: beq         $v0, $at, L_80089510
    if (ctx->r2 == ctx->r1) {
        // 0x800891A8: andi        $t5, $a2, 0x9000
        ctx->r13 = ctx->r6 & 0X9000;
            goto L_80089510;
    }
    // 0x800891A8: andi        $t5, $a2, 0x9000
    ctx->r13 = ctx->r6 & 0X9000;
    // 0x800891AC: beq         $t5, $zero, L_80089510
    if (ctx->r13 == 0) {
        // 0x800891B0: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80089510;
    }
    // 0x800891B0: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800891B4: jal         0x80001D04
    // 0x800891B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x800891B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x800891BC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800891C0: addiu       $a0, $a0, 0x6A68
    ctx->r4 = ADD32(ctx->r4, 0X6A68);
    // 0x800891C4: jal         0x80087F14
    // 0x800891C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    func_80087F14(rdram, ctx);
        goto after_3;
    // 0x800891C8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_3:
    // 0x800891CC: bne         $v0, $zero, L_800891DC
    if (ctx->r2 != 0) {
        // 0x800891D0: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_800891DC;
    }
    // 0x800891D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800891D4: b           L_800891F0
    // 0x800891D8: sw          $zero, 0x6BC8($at)
    MEM_W(0X6BC8, ctx->r1) = 0;
        goto L_800891F0;
    // 0x800891D8: sw          $zero, 0x6BC8($at)
    MEM_W(0X6BC8, ctx->r1) = 0;
L_800891DC:
    // 0x800891DC: jal         0x8008832C
    // 0x800891E0: nop

    check_for_controller_pak_errors(rdram, ctx);
        goto after_4;
    // 0x800891E0: nop

    after_4:
    // 0x800891E4: bne         $v0, $zero, L_800891F0
    if (ctx->r2 != 0) {
        // 0x800891E8: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800891F0;
    }
    // 0x800891E8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800891EC: sw          $zero, -0x26C($at)
    MEM_W(-0X26C, ctx->r1) = 0;
L_800891F0:
    // 0x800891F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800891F4: lw          $t6, 0x6BC8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X6BC8);
    // 0x800891F8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800891FC: bne         $t6, $zero, L_80089510
    if (ctx->r14 != 0) {
        // 0x80089200: nop
    
            goto L_80089510;
    }
    // 0x80089200: nop

    // 0x80089204: lw          $t7, -0x26C($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X26C);
    // 0x80089208: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8008920C: bne         $t7, $zero, L_80089510
    if (ctx->r15 != 0) {
        // 0x80089210: addiu       $t9, $zero, 0x1
        ctx->r25 = ADD32(0, 0X1);
            goto L_80089510;
    }
    // 0x80089210: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089214: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089218: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8008921C: sw          $t8, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r24;
    // 0x80089220: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
    // 0x80089224: jal         0x800C01D8
    // 0x80089228: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_5;
    // 0x80089228: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_5:
    // 0x8008922C: b           L_80089514
    // 0x80089230: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
        goto L_80089514;
    // 0x80089230: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80089234:
    // 0x80089234: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80089238: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008923C: beq         $v0, $zero, L_80089384
    if (ctx->r2 == 0) {
        // 0x80089240: andi        $t8, $a2, 0x4000
        ctx->r24 = ctx->r6 & 0X4000;
            goto L_80089384;
    }
    // 0x80089240: andi        $t8, $a2, 0x4000
    ctx->r24 = ctx->r6 & 0X4000;
    // 0x80089244: addiu       $a0, $a0, 0x6C10
    ctx->r4 = ADD32(ctx->r4, 0X6C10);
    // 0x80089248: lw          $v1, 0x0($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X0);
    // 0x8008924C: andi        $t5, $a2, 0x4000
    ctx->r13 = ctx->r6 & 0X4000;
    // 0x80089250: beq         $v1, $zero, L_80089304
    if (ctx->r3 == 0) {
        // 0x80089254: addiu       $t4, $v1, -0x1
        ctx->r12 = ADD32(ctx->r3, -0X1);
            goto L_80089304;
    }
    // 0x80089254: addiu       $t4, $v1, -0x1
    ctx->r12 = ADD32(ctx->r3, -0X1);
    // 0x80089258: bne         $t4, $zero, L_80089510
    if (ctx->r12 != 0) {
        // 0x8008925C: sw          $t4, 0x0($a0)
        MEM_W(0X0, ctx->r4) = ctx->r12;
            goto L_80089510;
    }
    // 0x8008925C: sw          $t4, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r12;
    // 0x80089260: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80089264: addiu       $t1, $t1, -0xBA0
    ctx->r9 = ADD32(ctx->r9, -0XBA0);
    // 0x80089268: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008926C: lw          $a0, 0x6A68($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6A68);
    // 0x80089270: lw          $a1, 0x0($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X0);
    // 0x80089274: jal         0x800762C8
    // 0x80089278: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    delete_file(rdram, ctx);
        goto after_6;
    // 0x80089278: sw          $a3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r7;
    after_6:
    // 0x8008927C: lw          $a3, 0x3C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X3C);
    // 0x80089280: beq         $v0, $zero, L_800892B4
    if (ctx->r2 == 0) {
        // 0x80089284: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_800892B4;
    }
    // 0x80089284: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80089288: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8008928C: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089290: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80089294: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80089298: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x8008929C: sw          $t7, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r15;
    // 0x800892A0: jal         0x800C01D8
    // 0x800892A4: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_7;
    // 0x800892A4: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_7:
    // 0x800892A8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800892AC: b           L_800892FC
    // 0x800892B0: addiu       $t2, $t2, 0x63E0
    ctx->r10 = ADD32(ctx->r10, 0X63E0);
        goto L_800892FC;
    // 0x800892B0: addiu       $t2, $t2, 0x63E0
    ctx->r10 = ADD32(ctx->r10, 0X63E0);
L_800892B4:
    // 0x800892B4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800892B8: sw          $t8, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r24;
    // 0x800892BC: addiu       $a0, $a0, 0x6A68
    ctx->r4 = ADD32(ctx->r4, 0X6A68);
    // 0x800892C0: jal         0x80087F14
    // 0x800892C4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    func_80087F14(rdram, ctx);
        goto after_8;
    // 0x800892C4: or          $a1, $a3, $zero
    ctx->r5 = ctx->r7 | 0;
    after_8:
    // 0x800892C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800892CC: beq         $v0, $zero, L_800892FC
    if (ctx->r2 == 0) {
        // 0x800892D0: addiu       $t2, $t2, 0x63E0
        ctx->r10 = ADD32(ctx->r10, 0X63E0);
            goto L_800892FC;
    }
    // 0x800892D0: addiu       $t2, $t2, 0x63E0
    ctx->r10 = ADD32(ctx->r10, 0X63E0);
    // 0x800892D4: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x800892D8: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800892DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800892E0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800892E4: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x800892E8: sw          $t4, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r12;
    // 0x800892EC: jal         0x800C01D8
    // 0x800892F0: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_9;
    // 0x800892F0: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_9:
    // 0x800892F4: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800892F8: addiu       $t2, $t2, 0x63E0
    ctx->r10 = ADD32(ctx->r10, 0X63E0);
L_800892FC:
    // 0x800892FC: b           L_80089510
    // 0x80089300: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_80089510;
    // 0x80089300: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80089304:
    // 0x80089304: beq         $t5, $zero, L_8008931C
    if (ctx->r13 == 0) {
        // 0x80089308: andi        $t7, $a2, 0x9000
        ctx->r15 = ctx->r6 & 0X9000;
            goto L_8008931C;
    }
    // 0x80089308: andi        $t7, $a2, 0x9000
    ctx->r15 = ctx->r6 & 0X9000;
    // 0x8008930C: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80089310: sw          $t6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r14;
    // 0x80089314: b           L_80089510
    // 0x80089318: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_80089510;
    // 0x80089318: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_8008931C:
    // 0x8008931C: beq         $t7, $zero, L_80089344
    if (ctx->r15 == 0) {
        // 0x80089320: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80089344;
    }
    // 0x80089320: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80089324: bne         $v0, $at, L_80089334
    if (ctx->r2 != ctx->r1) {
        // 0x80089328: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_80089334;
    }
    // 0x80089328: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8008932C: b           L_80089510
    // 0x80089330: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
        goto L_80089510;
    // 0x80089330: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
L_80089334:
    // 0x80089334: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80089338: sw          $t9, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r25;
    // 0x8008933C: b           L_80089510
    // 0x80089340: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
        goto L_80089510;
    // 0x80089340: sw          $zero, 0x0($t2)
    MEM_W(0X0, ctx->r10) = 0;
L_80089344:
    // 0x80089344: blez        $t0, L_80089364
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80089348: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80089364;
    }
    // 0x80089348: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8008934C: bne         $at, $zero, L_80089364
    if (ctx->r1 != 0) {
        // 0x80089350: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_80089364;
    }
    // 0x80089350: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80089354: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x80089358: sw          $t4, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r12;
    // 0x8008935C: b           L_80089510
    // 0x80089360: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
        goto L_80089510;
    // 0x80089360: sw          $t5, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r13;
L_80089364:
    // 0x80089364: bgez        $t0, L_80089510
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80089368: slti        $at, $v0, 0x2
        ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
            goto L_80089510;
    }
    // 0x80089368: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x8008936C: beq         $at, $zero, L_80089510
    if (ctx->r1 == 0) {
        // 0x80089370: addiu       $t6, $zero, 0x2
        ctx->r14 = ADD32(0, 0X2);
            goto L_80089510;
    }
    // 0x80089370: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x80089374: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089378: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x8008937C: b           L_80089510
    // 0x80089380: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_80089510;
    // 0x80089380: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80089384:
    // 0x80089384: bne         $t8, $zero, L_800893A4
    if (ctx->r24 != 0) {
        // 0x80089388: lui         $t1, 0x800E
        ctx->r9 = S32(0X800E << 16);
            goto L_800893A4;
    }
    // 0x80089388: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8008938C: addiu       $t1, $t1, -0xBA0
    ctx->r9 = ADD32(ctx->r9, -0XBA0);
    // 0x80089390: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x80089394: addiu       $t3, $zero, 0x10
    ctx->r11 = ADD32(0, 0X10);
    // 0x80089398: bne         $t3, $v1, L_800893CC
    if (ctx->r11 != ctx->r3) {
        // 0x8008939C: andi        $t9, $a2, 0x9000
        ctx->r25 = ctx->r6 & 0X9000;
            goto L_800893CC;
    }
    // 0x8008939C: andi        $t9, $a2, 0x9000
    ctx->r25 = ctx->r6 & 0X9000;
    // 0x800893A0: beq         $t9, $zero, L_800893CC
    if (ctx->r25 == 0) {
        // 0x800893A4: addiu       $t4, $zero, 0x1
        ctx->r12 = ADD32(0, 0X1);
            goto L_800893CC;
    }
L_800893A4:
    // 0x800893A4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800893A8: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x800893AC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800893B0: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800893B4: sw          $t4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r12;
    // 0x800893B8: sw          $t5, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r13;
    // 0x800893BC: jal         0x800C01D8
    // 0x800893C0: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_10;
    // 0x800893C0: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_10:
    // 0x800893C4: b           L_80089514
    // 0x800893C8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
        goto L_80089514;
    // 0x800893C8: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_800893CC:
    // 0x800893CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800893D0: beq         $v1, $at, L_800893E8
    if (ctx->r3 == ctx->r1) {
        // 0x800893D4: nop
    
            goto L_800893E8;
    }
    // 0x800893D4: nop

    // 0x800893D8: beq         $v1, $t3, L_800893FC
    if (ctx->r3 == ctx->r11) {
        // 0x800893DC: nop
    
            goto L_800893FC;
    }
    // 0x800893DC: nop

    // 0x800893E0: b           L_80089414
    // 0x800893E4: andi        $v0, $a2, 0x9000
    ctx->r2 = ctx->r6 & 0X9000;
        goto L_80089414;
    // 0x800893E4: andi        $v0, $a2, 0x9000
    ctx->r2 = ctx->r6 & 0X9000;
L_800893E8:
    // 0x800893E8: bgez        $t0, L_80089510
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800893EC: addiu       $t6, $zero, 0x1
        ctx->r14 = ADD32(0, 0X1);
            goto L_80089510;
    }
    // 0x800893EC: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x800893F0: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x800893F4: b           L_80089510
    // 0x800893F8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
        goto L_80089510;
    // 0x800893F8: sw          $t6, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r14;
L_800893FC:
    // 0x800893FC: blez        $t0, L_80089510
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80089400: addiu       $t7, $zero, 0xF
        ctx->r15 = ADD32(0, 0XF);
            goto L_80089510;
    }
    // 0x80089400: addiu       $t7, $zero, 0xF
    ctx->r15 = ADD32(0, 0XF);
    // 0x80089404: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80089408: sw          $t7, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r15;
    // 0x8008940C: b           L_80089510
    // 0x80089410: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
        goto L_80089510;
    // 0x80089410: sw          $t8, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r24;
L_80089414:
    // 0x80089414: beq         $v0, $zero, L_80089464
    if (ctx->r2 == 0) {
        // 0x80089418: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80089464;
    }
    // 0x80089418: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008941C: addu        $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x80089420: lbu         $v0, 0x6B60($v0)
    ctx->r2 = MEM_BU(ctx->r2, 0X6B60);
    // 0x80089424: nop

    // 0x80089428: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x8008942C: bne         $at, $zero, L_80089458
    if (ctx->r1 != 0) {
        // 0x80089430: slti        $at, $v0, 0x7
        ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
            goto L_80089458;
    }
    // 0x80089430: slti        $at, $v0, 0x7
    ctx->r1 = SIGNED(ctx->r2) < 0X7 ? 1 : 0;
    // 0x80089434: beq         $at, $zero, L_80089458
    if (ctx->r1 == 0) {
        // 0x80089438: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80089458;
    }
    // 0x80089438: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8008943C: addiu       $a0, $a0, 0x6C10
    ctx->r4 = ADD32(ctx->r4, 0X6C10);
    // 0x80089440: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80089444: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80089448: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x8008944C: sw          $t9, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r25;
    // 0x80089450: b           L_800894A8
    // 0x80089454: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
        goto L_800894A8;
    // 0x80089454: sw          $t4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r12;
L_80089458:
    // 0x80089458: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8008945C: b           L_800894A8
    // 0x80089460: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
        goto L_800894A8;
    // 0x80089460: sw          $t5, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r13;
L_80089464:
    // 0x80089464: blez        $t0, L_80089490
    if (SIGNED(ctx->r8) <= 0) {
        // 0x80089468: addiu       $t6, $v1, -0x1
        ctx->r14 = ADD32(ctx->r3, -0X1);
            goto L_80089490;
    }
    // 0x80089468: addiu       $t6, $v1, -0x1
    ctx->r14 = ADD32(ctx->r3, -0X1);
    // 0x8008946C: sw          $t6, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r14;
    // 0x80089470: bgez        $t6, L_80089484
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80089474: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_80089484;
    }
    // 0x80089474: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x80089478: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8008947C: b           L_800894A8
    // 0x80089480: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
        goto L_800894A8;
    // 0x80089480: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
L_80089484:
    // 0x80089484: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x80089488: b           L_800894A8
    // 0x8008948C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
        goto L_800894A8;
    // 0x8008948C: sw          $t7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r15;
L_80089490:
    // 0x80089490: bgez        $t0, L_800894A8
    if (SIGNED(ctx->r8) >= 0) {
        // 0x80089494: addiu       $t8, $v1, 0x1
        ctx->r24 = ADD32(ctx->r3, 0X1);
            goto L_800894A8;
    }
    // 0x80089494: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80089498: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x8008949C: sw          $t8, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r24;
    // 0x800894A0: sw          $t9, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r25;
    // 0x800894A4: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800894A8:
    // 0x800894A8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800894AC: addiu       $a1, $a1, 0x63D8
    ctx->r5 = ADD32(ctx->r5, 0X63D8);
    // 0x800894B0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800894B4: lw          $a0, 0x6BB4($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6BB4);
    // 0x800894B8: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800894BC: subu        $t5, $v1, $a0
    ctx->r13 = SUB32(ctx->r3, ctx->r4);
    // 0x800894C0: addu        $t4, $v0, $a0
    ctx->r12 = ADD32(ctx->r2, ctx->r4);
    // 0x800894C4: slt         $at, $v1, $t4
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800894C8: bne         $at, $zero, L_800894DC
    if (ctx->r1 != 0) {
        // 0x800894CC: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_800894DC;
    }
    // 0x800894CC: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800894D0: addiu       $v0, $t5, 0x1
    ctx->r2 = ADD32(ctx->r13, 0X1);
    // 0x800894D4: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800894D8: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_800894DC:
    // 0x800894DC: beq         $at, $zero, L_800894EC
    if (ctx->r1 == 0) {
        // 0x800894E0: nop
    
            goto L_800894EC;
    }
    // 0x800894E0: nop

    // 0x800894E4: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x800894E8: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_800894EC:
    // 0x800894EC: subu        $v1, $t3, $a0
    ctx->r3 = SUB32(ctx->r11, ctx->r4);
    // 0x800894F0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800894F4: beq         $at, $zero, L_80089504
    if (ctx->r1 == 0) {
        // 0x800894F8: nop
    
            goto L_80089504;
    }
    // 0x800894F8: nop

    // 0x800894FC: sw          $v1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r3;
    // 0x80089500: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80089504:
    // 0x80089504: bgez        $v0, L_80089514
    if (SIGNED(ctx->r2) >= 0) {
        // 0x80089508: lw          $t7, 0x30($sp)
        ctx->r15 = MEM_W(ctx->r29, 0X30);
            goto L_80089514;
    }
    // 0x80089508: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
    // 0x8008950C: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80089510:
    // 0x80089510: lw          $t7, 0x30($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X30);
L_80089514:
    // 0x80089514: lw          $t8, 0x2C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X2C);
    // 0x80089518: beq         $t7, $zero, L_80089530
    if (ctx->r15 == 0) {
        // 0x8008951C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_80089530;
    }
    // 0x8008951C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x80089520: jal         0x80001D04
    // 0x80089524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x80089524: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
    // 0x80089528: b           L_80089598
    // 0x8008952C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80089598;
    // 0x8008952C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80089530:
    // 0x80089530: beq         $t8, $zero, L_80089548
    if (ctx->r24 == 0) {
        // 0x80089534: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_80089548;
    }
    // 0x80089534: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80089538: jal         0x80001D04
    // 0x8008953C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_12;
    // 0x8008953C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x80089540: b           L_80089598
    // 0x80089544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80089598;
    // 0x80089544: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80089548:
    // 0x80089548: lw          $t9, 0x34($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X34);
    // 0x8008954C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80089550: beq         $t9, $zero, L_80089598
    if (ctx->r25 == 0) {
        // 0x80089554: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80089598;
    }
    // 0x80089554: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80089558: jal         0x80001D04
    // 0x8008955C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x8008955C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
    // 0x80089560: b           L_80089598
    // 0x80089564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80089598;
    // 0x80089564: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80089568:
    // 0x80089568: slti        $at, $t4, 0x24
    ctx->r1 = SIGNED(ctx->r12) < 0X24 ? 1 : 0;
    // 0x8008956C: bne         $at, $zero, L_80089594
    if (ctx->r1 != 0) {
        // 0x80089570: sw          $t4, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r12;
            goto L_80089594;
    }
    // 0x80089570: sw          $t4, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r12;
    // 0x80089574: jal         0x800895A4
    // 0x80089578: nop

    pakmenu_free(rdram, ctx);
        goto after_14;
    // 0x80089578: nop

    after_14:
    // 0x8008957C: jal         0x800813D0
    // 0x80089580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    menu_init(rdram, ctx);
        goto after_15;
    // 0x80089580: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_15:
    // 0x80089584: addiu       $a0, $zero, 0x15
    ctx->r4 = ADD32(0, 0X15);
    // 0x80089588: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8008958C: jal         0x8006E2E8
    // 0x80089590: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    load_level_for_menu(rdram, ctx);
        goto after_16;
    // 0x80089590: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_16:
L_80089594:
    // 0x80089594: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80089598:
    // 0x80089598: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8008959C: jr          $ra
    // 0x800895A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x800895A0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void update_camera_car(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800581E8: addiu       $sp, $sp, -0x68
    ctx->r29 = ADD32(ctx->r29, -0X68);
    // 0x800581EC: lui         $at, 0x42F0
    ctx->r1 = S32(0X42F0 << 16);
    // 0x800581F0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800581F4: lui         $at, 0x4248
    ctx->r1 = S32(0X4248 << 16);
    // 0x800581F8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800581FC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80058200: addiu       $t6, $zero, 0x400
    ctx->r14 = ADD32(0, 0X400);
    // 0x80058204: swc1        $f12, 0x68($sp)
    MEM_W(0X68, ctx->r29) = ctx->f12.u32l;
    // 0x80058208: sw          $a1, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r5;
    // 0x8005820C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80058210: sw          $a2, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r6;
    // 0x80058214: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x80058218: jal         0x80066210
    // 0x8005821C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    cam_get_viewport_layout(rdram, ctx);
        goto after_0;
    // 0x8005821C: swc1        $f4, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f4.u32l;
    after_0:
    // 0x80058220: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80058224: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058228: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8005822C: bne         $v0, $a0, L_80058244
    if (ctx->r2 != ctx->r4) {
        // 0x80058230: lui         $at, 0x4340
        ctx->r1 = S32(0X4340 << 16);
            goto L_80058244;
    }
    // 0x80058230: lui         $at, 0x4340
    ctx->r1 = S32(0X4340 << 16);
    // 0x80058234: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80058238: addiu       $t7, $zero, 0x200
    ctx->r15 = ADD32(0, 0X200);
    // 0x8005823C: b           L_80058264
    // 0x80058240: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
        goto L_80058264;
    // 0x80058240: sw          $t7, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r15;
L_80058244:
    // 0x80058244: slti        $at, $v0, 0x3
    ctx->r1 = SIGNED(ctx->r2) < 0X3 ? 1 : 0;
    // 0x80058248: bne         $at, $zero, L_80058264
    if (ctx->r1 != 0) {
        // 0x8005824C: lui         $at, 0x42C8
        ctx->r1 = S32(0X42C8 << 16);
            goto L_80058264;
    }
    // 0x8005824C: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80058250: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80058254: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x80058258: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8005825C: nop

    // 0x80058260: swc1        $f6, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f6.u32l;
L_80058264:
    // 0x80058264: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80058268: jal         0x80023568
    // 0x8005826C: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005826C: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    after_1:
    // 0x80058270: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x80058274: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058278: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x8005827C: beq         $v0, $a0, L_80058288
    if (ctx->r2 == ctx->r4) {
        // 0x80058280: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_80058288;
    }
    // 0x80058280: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80058284: bne         $v0, $at, L_800582D0
    if (ctx->r2 != ctx->r1) {
        // 0x80058288: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800582D0;
    }
L_80058288:
    // 0x80058288: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005828C: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x80058290: lui         $at, 0x4310
    ctx->r1 = S32(0X4310 << 16);
    // 0x80058294: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x80058298: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x8005829C: lui         $at, 0x42DC
    ctx->r1 = S32(0X42DC << 16);
    // 0x800582A0: lbu         $t9, 0x3B($t8)
    ctx->r25 = MEM_BU(ctx->r24, 0X3B);
    // 0x800582A4: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800582A8: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800582AC: bne         $t9, $at, L_800582C4
    if (ctx->r25 != ctx->r1) {
        // 0x800582B0: mov.s       $f16, $f0
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
            goto L_800582C4;
    }
    // 0x800582B0: mov.s       $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    ctx->f16.fl = ctx->f0.fl;
    // 0x800582B4: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x800582B8: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800582BC: nop

    // 0x800582C0: add.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f0.fl + ctx->f8.fl;
L_800582C4:
    // 0x800582C4: addiu       $t1, $zero, 0xD00
    ctx->r9 = ADD32(0, 0XD00);
    // 0x800582C8: sw          $t1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r9;
    // 0x800582CC: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
L_800582D0:
    // 0x800582D0: lh          $t2, 0x1A0($a3)
    ctx->r10 = MEM_H(ctx->r7, 0X1A0);
    // 0x800582D4: lh          $v0, 0x19E($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X19E);
    // 0x800582D8: negu        $t3, $t2
    ctx->r11 = SUB32(0, ctx->r10);
    // 0x800582DC: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x800582E0: subu        $t4, $t3, $v0
    ctx->r12 = SUB32(ctx->r11, ctx->r2);
    // 0x800582E4: addu        $t5, $t4, $at
    ctx->r13 = ADD32(ctx->r12, ctx->r1);
    // 0x800582E8: sra         $v1, $v0, 3
    ctx->r3 = S32(SIGNED(ctx->r2) >> 3);
    // 0x800582EC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800582F0: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800582F4: slti        $at, $v1, 0x401
    ctx->r1 = SIGNED(ctx->r3) < 0X401 ? 1 : 0;
    // 0x800582F8: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x800582FC: bne         $at, $zero, L_80058308
    if (ctx->r1 != 0) {
        // 0x80058300: sh          $t5, 0x196($a3)
        MEM_H(0X196, ctx->r7) = ctx->r13;
            goto L_80058308;
    }
    // 0x80058300: sh          $t5, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r13;
    // 0x80058304: addiu       $v1, $zero, 0x400
    ctx->r3 = ADD32(0, 0X400);
L_80058308:
    // 0x80058308: slti        $at, $v1, -0x400
    ctx->r1 = SIGNED(ctx->r3) < -0X400 ? 1 : 0;
    // 0x8005830C: beq         $at, $zero, L_80058318
    if (ctx->r1 == 0) {
        // 0x80058310: nop
    
            goto L_80058318;
    }
    // 0x80058310: nop

    // 0x80058314: addiu       $v1, $zero, -0x400
    ctx->r3 = ADD32(0, -0X400);
L_80058318:
    // 0x80058318: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005831C: lwc1        $f10, 0x68($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X68);
    // 0x80058320: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x80058324: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80058328: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005832C: nop

    // 0x80058330: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80058334: mfc1        $a2, $f4
    ctx->r6 = (int32_t)ctx->f4.u32l;
    // 0x80058338: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005833C: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80058340: mflo        $v1
    ctx->r3 = lo;
    // 0x80058344: blez        $v1, L_80058358
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80058348: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_80058358;
    }
    // 0x80058348: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8005834C: beq         $at, $zero, L_80058358
    if (ctx->r1 == 0) {
        // 0x80058350: subu        $t7, $v0, $v1
        ctx->r15 = SUB32(ctx->r2, ctx->r3);
            goto L_80058358;
    }
    // 0x80058350: subu        $t7, $v0, $v1
    ctx->r15 = SUB32(ctx->r2, ctx->r3);
    // 0x80058354: sh          $t7, 0x19E($a3)
    MEM_H(0X19E, ctx->r7) = ctx->r15;
L_80058358:
    // 0x80058358: bgez        $v1, L_80058378
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8005835C: nop
    
            goto L_80058378;
    }
    // 0x8005835C: nop

    // 0x80058360: lh          $v0, 0x19E($a3)
    ctx->r2 = MEM_H(ctx->r7, 0X19E);
    // 0x80058364: nop

    // 0x80058368: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8005836C: beq         $at, $zero, L_80058378
    if (ctx->r1 == 0) {
        // 0x80058370: subu        $t8, $v0, $v1
        ctx->r24 = SUB32(ctx->r2, ctx->r3);
            goto L_80058378;
    }
    // 0x80058370: subu        $t8, $v0, $v1
    ctx->r24 = SUB32(ctx->r2, ctx->r3);
    // 0x80058374: sh          $t8, 0x19E($a3)
    MEM_H(0X19E, ctx->r7) = ctx->r24;
L_80058378:
    // 0x80058378: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8005837C: lwc1        $f14, 0xB8($a3)
    ctx->f14.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x80058380: lbu         $v0, 0x3B($a1)
    ctx->r2 = MEM_BU(ctx->r5, 0X3B);
    // 0x80058384: lwc1        $f2, 0x8($a3)
    ctx->f2.u32l = MEM_W(ctx->r7, 0X8);
    // 0x80058388: beq         $v0, $a0, L_800583A8
    if (ctx->r2 == ctx->r4) {
        // 0x8005838C: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_800583A8;
    }
    // 0x8005838C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80058390: beq         $v0, $at, L_800583B8
    if (ctx->r2 == ctx->r1) {
        // 0x80058394: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_800583B8;
    }
    // 0x80058394: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80058398: beq         $v0, $at, L_800583D8
    if (ctx->r2 == ctx->r1) {
        // 0x8005839C: lui         $at, 0x4254
        ctx->r1 = S32(0X4254 << 16);
            goto L_800583D8;
    }
    // 0x8005839C: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
    // 0x800583A0: b           L_8005840C
    // 0x800583A4: lb          $t9, 0x1E2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1E2);
        goto L_8005840C;
    // 0x800583A4: lb          $t9, 0x1E2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1E2);
L_800583A8:
    // 0x800583A8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800583AC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800583B0: b           L_80058408
    // 0x800583B4: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
        goto L_80058408;
    // 0x800583B4: add.s       $f16, $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f6.fl;
L_800583B8:
    // 0x800583B8: lui         $at, 0x420C
    ctx->r1 = S32(0X420C << 16);
    // 0x800583BC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800583C0: lui         $at, 0x4120
    ctx->r1 = S32(0X4120 << 16);
    // 0x800583C4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800583C8: sub.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f8.fl;
    // 0x800583CC: b           L_80058408
    // 0x800583D0: sub.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f10.fl;
        goto L_80058408;
    // 0x800583D0: sub.s       $f18, $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f10.fl;
    // 0x800583D4: lui         $at, 0x4254
    ctx->r1 = S32(0X4254 << 16);
L_800583D8:
    // 0x800583D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800583DC: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x800583E0: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800583E4: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x800583E8: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x800583EC: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800583F0: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800583F4: sub.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f4.fl;
    // 0x800583F8: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x800583FC: mul.d       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f4.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x80058400: sub.s       $f18, $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80058404: cvt.s.d     $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f2.fl = CVT_S_D(ctx->f4.d);
L_80058408:
    // 0x80058408: lb          $t9, 0x1E2($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1E2);
L_8005840C:
    // 0x8005840C: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80058410: slti        $at, $t9, 0x3
    ctx->r1 = SIGNED(ctx->r25) < 0X3 ? 1 : 0;
    // 0x80058414: beq         $at, $zero, L_80058430
    if (ctx->r1 == 0) {
        // 0x80058418: lw          $t2, 0x6C($sp)
        ctx->r10 = MEM_W(ctx->r29, 0X6C);
            goto L_80058430;
    }
    // 0x80058418: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
    // 0x8005841C: lb          $t1, 0x1E5($a3)
    ctx->r9 = MEM_B(ctx->r7, 0X1E5);
    // 0x80058420: nop

    // 0x80058424: beq         $t1, $zero, L_800584B8
    if (ctx->r9 == 0) {
        // 0x80058428: nop
    
            goto L_800584B8;
    }
    // 0x80058428: nop

    // 0x8005842C: lw          $t2, 0x6C($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X6C);
L_80058430:
    // 0x80058430: lw          $t4, 0x1C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X1C);
    // 0x80058434: lh          $v0, 0x2($t2)
    ctx->r2 = MEM_H(ctx->r10, 0X2);
    // 0x80058438: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005843C: blez        $v0, L_80058460
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80058440: nop
    
            goto L_80058460;
    }
    // 0x80058440: nop

    // 0x80058444: addiu       $v0, $v0, -0x71C
    ctx->r2 = ADD32(ctx->r2, -0X71C);
    // 0x80058448: bgez        $v0, L_80058458
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005844C: sra         $t3, $v0, 1
        ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
            goto L_80058458;
    }
    // 0x8005844C: sra         $t3, $v0, 1
    ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
    // 0x80058450: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80058454: sra         $t3, $v0, 1
    ctx->r11 = S32(SIGNED(ctx->r2) >> 1);
L_80058458:
    // 0x80058458: b           L_80058470
    // 0x8005845C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
        goto L_80058470;
    // 0x8005845C: or          $v0, $t3, $zero
    ctx->r2 = ctx->r11 | 0;
L_80058460:
    // 0x80058460: addiu       $v0, $v0, 0x71C
    ctx->r2 = ADD32(ctx->r2, 0X71C);
    // 0x80058464: blez        $v0, L_80058470
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80058468: nop
    
            goto L_80058470;
    }
    // 0x80058468: nop

    // 0x8005846C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80058470:
    // 0x80058470: lh          $a0, 0x2($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X2);
    // 0x80058474: subu        $v0, $t4, $v0
    ctx->r2 = SUB32(ctx->r12, ctx->r2);
    // 0x80058478: andi        $t5, $a0, 0xFFFF
    ctx->r13 = ctx->r4 & 0XFFFF;
    // 0x8005847C: subu        $v1, $v0, $t5
    ctx->r3 = SUB32(ctx->r2, ctx->r13);
    // 0x80058480: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x80058484: bne         $at, $zero, L_80058494
    if (ctx->r1 != 0) {
        // 0x80058488: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_80058494;
    }
    // 0x80058488: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005848C: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x80058490: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_80058494:
    // 0x80058494: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x80058498: beq         $at, $zero, L_800584A4
    if (ctx->r1 == 0) {
        // 0x8005849C: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_800584A4;
    }
    // 0x8005849C: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x800584A0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_800584A4:
    // 0x800584A4: multu       $v1, $a2
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r6)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800584A8: mflo        $t6
    ctx->r14 = lo;
    // 0x800584AC: sra         $t7, $t6, 4
    ctx->r15 = S32(SIGNED(ctx->r14) >> 4);
    // 0x800584B0: addu        $t8, $a0, $t7
    ctx->r24 = ADD32(ctx->r4, ctx->r15);
    // 0x800584B4: sh          $t8, 0x2($a1)
    MEM_H(0X2, ctx->r5) = ctx->r24;
L_800584B8:
    // 0x800584B8: lwc1        $f0, 0x2C($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X2C);
    // 0x800584BC: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800584C0: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x800584C4: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x800584C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800584CC: bc1f        L_80058528
    if (!c1cs) {
        // 0x800584D0: nop
    
            goto L_80058528;
    }
    // 0x800584D0: nop

    // 0x800584D4: mul.s       $f10, $f0, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f14.fl);
    // 0x800584D8: lb          $t9, 0x1E6($a3)
    ctx->r25 = MEM_B(ctx->r7, 0X1E6);
    // 0x800584DC: lui         $at, 0x40C0
    ctx->r1 = S32(0X40C0 << 16);
    // 0x800584E0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800584E4: beq         $t9, $zero, L_800584F8
    if (ctx->r25 == 0) {
        // 0x800584E8: neg.s       $f4, $f10
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
            goto L_800584F8;
    }
    // 0x800584E8: neg.s       $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = -ctx->f10.fl;
    // 0x800584EC: lui         $at, 0x4040
    ctx->r1 = S32(0X4040 << 16);
    // 0x800584F0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800584F4: nop

L_800584F8:
    // 0x800584F8: mul.s       $f12, $f4, $f12
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x800584FC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80058500: lwc1        $f7, 0x6910($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6910);
    // 0x80058504: lwc1        $f6, 0x6914($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6914);
    // 0x80058508: cvt.d.s     $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); 
    ctx->f8.d = CVT_D_S(ctx->f12.fl);
    // 0x8005850C: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x80058510: lui         $at, 0x4282
    ctx->r1 = S32(0X4282 << 16);
    // 0x80058514: bc1f        L_80058524
    if (!c1cs) {
        // 0x80058518: nop
    
            goto L_80058524;
    }
    // 0x80058518: nop

    // 0x8005851C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x80058520: nop

L_80058524:
    // 0x80058524: sub.s       $f16, $f16, $f12
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f16.fl = ctx->f16.fl - ctx->f12.fl;
L_80058528:
    // 0x80058528: lb          $t1, 0x1E6($a3)
    ctx->r9 = MEM_B(ctx->r7, 0X1E6);
    // 0x8005852C: nop

    // 0x80058530: bne         $t1, $zero, L_8005854C
    if (ctx->r9 != 0) {
        // 0x80058534: lui         $at, 0x4270
        ctx->r1 = S32(0X4270 << 16);
            goto L_8005854C;
    }
    // 0x80058534: lui         $at, 0x4270
    ctx->r1 = S32(0X4270 << 16);
    // 0x80058538: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8005853C: nop

    // 0x80058540: mul.s       $f4, $f2, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = MUL_S(ctx->f2.fl, ctx->f10.fl);
    // 0x80058544: b           L_80058560
    // 0x80058548: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
        goto L_80058560;
    // 0x80058548: add.s       $f16, $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f4.fl;
L_8005854C:
    // 0x8005854C: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80058550: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80058554: nop

    // 0x80058558: mul.s       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f6.fl);
    // 0x8005855C: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_80058560:
    // 0x80058560: lw          $t2, -0x2AC0($t2)
    ctx->r10 = MEM_W(ctx->r10, -0X2AC0);
    // 0x80058564: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    // 0x80058568: bne         $t2, $zero, L_800585BC
    if (ctx->r10 != 0) {
        // 0x8005856C: addiu       $a0, $zero, 0x24
        ctx->r4 = ADD32(0, 0X24);
            goto L_800585BC;
    }
    // 0x8005856C: addiu       $a0, $zero, 0x24
    ctx->r4 = ADD32(0, 0X24);
    // 0x80058570: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80058574: swc1        $f16, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->f16.u32l;
    // 0x80058578: jal         0x8000C8B4
    // 0x8005857C: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    normalise_time(rdram, ctx);
        goto after_2;
    // 0x8005857C: swc1        $f18, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f18.u32l;
    after_2:
    // 0x80058580: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058584: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80058588: lb          $v1, 0x1D3($a3)
    ctx->r3 = MEM_B(ctx->r7, 0X1D3);
    // 0x8005858C: lwc1        $f16, 0x54($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X54);
    // 0x80058590: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80058594: beq         $at, $zero, L_800585AC
    if (ctx->r1 == 0) {
        // 0x80058598: addiu       $t0, $t0, -0x2AF8
        ctx->r8 = ADD32(ctx->r8, -0X2AF8);
            goto L_800585AC;
    }
    // 0x80058598: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x8005859C: lui         $at, 0xC1F0
    ctx->r1 = S32(0XC1F0 << 16);
    // 0x800585A0: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800585A4: b           L_800585BC
    // 0x800585A8: nop

        goto L_800585BC;
    // 0x800585A8: nop

L_800585AC:
    // 0x800585AC: blez        $v1, L_800585BC
    if (SIGNED(ctx->r3) <= 0) {
        // 0x800585B0: lui         $at, 0x4334
        ctx->r1 = S32(0X4334 << 16);
            goto L_800585BC;
    }
    // 0x800585B0: lui         $at, 0x4334
    ctx->r1 = S32(0X4334 << 16);
    // 0x800585B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800585B8: nop

L_800585BC:
    // 0x800585BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800585C0: lw          $t3, -0x2AC0($t3)
    ctx->r11 = MEM_W(ctx->r11, -0X2AC0);
    // 0x800585C4: lwc1        $f18, 0x50($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X50);
    // 0x800585C8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800585CC: slti        $at, $t3, 0x51
    ctx->r1 = SIGNED(ctx->r11) < 0X51 ? 1 : 0;
    // 0x800585D0: bne         $at, $zero, L_800585F0
    if (ctx->r1 != 0) {
        // 0x800585D4: nop
    
            goto L_800585F0;
    }
    // 0x800585D4: nop

    // 0x800585D8: swc1        $f16, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f16.u32l;
    // 0x800585DC: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x800585E0: nop

    // 0x800585E4: swc1        $f18, 0x20($t4)
    MEM_W(0X20, ctx->r12) = ctx->f18.u32l;
    // 0x800585E8: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x800585EC: nop

L_800585F0:
    // 0x800585F0: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800585F4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800585F8: sub.s       $f4, $f16, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f2.fl;
    // 0x800585FC: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x80058600: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x80058604: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x80058608: mul.d       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f0.d); 
    ctx->f8.d = MUL_D(ctx->f6.d, ctx->f0.d);
    // 0x8005860C: cvt.d.s     $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f10.d = CVT_D_S(ctx->f2.fl);
    // 0x80058610: add.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d + ctx->f8.d;
    // 0x80058614: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80058618: swc1        $f6, 0x1C($a1)
    MEM_W(0X1C, ctx->r5) = ctx->f6.u32l;
    // 0x8005861C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058620: nop

    // 0x80058624: lwc1        $f14, 0x20($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X20);
    // 0x80058628: nop

    // 0x8005862C: sub.s       $f8, $f18, $f14
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x80058630: cvt.d.s     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.d = CVT_D_S(ctx->f8.fl);
    // 0x80058634: mul.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f0.d);
    // 0x80058638: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x8005863C: add.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f10.d + ctx->f6.d;
    // 0x80058640: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x80058644: swc1        $f4, 0x20($a1)
    MEM_W(0X20, ctx->r5) = ctx->f4.u32l;
    // 0x80058648: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x8005864C: lw          $t7, 0x1C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X1C);
    // 0x80058650: lh          $t6, 0x2($t5)
    ctx->r14 = MEM_H(ctx->r13, 0X2);
    // 0x80058654: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x80058658: subu        $a0, $t6, $t7
    ctx->r4 = SUB32(ctx->r14, ctx->r15);
    // 0x8005865C: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x80058660: jal         0x800707C4
    // 0x80058664: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    sins_f(rdram, ctx);
        goto after_3;
    // 0x80058664: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_3:
    // 0x80058668: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8005866C: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x80058670: lw          $t1, 0x0($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X0);
    // 0x80058674: lw          $t3, 0x1C($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X1C);
    // 0x80058678: lh          $t2, 0x2($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X2);
    // 0x8005867C: swc1        $f0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f0.u32l;
    // 0x80058680: subu        $a0, $t2, $t3
    ctx->r4 = SUB32(ctx->r10, ctx->r11);
    // 0x80058684: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x80058688: jal         0x800707F8
    // 0x8005868C: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_4;
    // 0x8005868C: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_4:
    // 0x80058690: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80058694: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x80058698: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8005869C: lwc1        $f16, 0x38($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800586A0: lwc1        $f2, 0x1C($a1)
    ctx->f2.u32l = MEM_W(ctx->r5, 0X1C);
    // 0x800586A4: lwc1        $f14, 0x20($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X20);
    // 0x800586A8: mul.s       $f10, $f2, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f0.fl);
    // 0x800586AC: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800586B0: ori         $t7, $zero, 0x8000
    ctx->r15 = 0 | 0X8000;
    // 0x800586B4: mul.s       $f6, $f14, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f16.fl);
    // 0x800586B8: nop

    // 0x800586BC: mul.s       $f8, $f2, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f16.fl);
    // 0x800586C0: sub.s       $f12, $f10, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f6.fl;
    // 0x800586C4: mul.s       $f4, $f14, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f0.fl);
    // 0x800586C8: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x800586CC: swc1        $f10, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f10.u32l;
    // 0x800586D0: lh          $t6, 0x196($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X196);
    // 0x800586D4: swc1        $f12, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f12.u32l;
    // 0x800586D8: subu        $a0, $t7, $t6
    ctx->r4 = SUB32(ctx->r15, ctx->r14);
    // 0x800586DC: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x800586E0: jal         0x800707C4
    // 0x800586E4: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    sins_f(rdram, ctx);
        goto after_5;
    // 0x800586E4: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_5:
    // 0x800586E8: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x800586EC: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800586F0: mul.s       $f6, $f0, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800586F4: ori         $t2, $zero, 0x8000
    ctx->r10 = 0 | 0X8000;
    // 0x800586F8: swc1        $f6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->f6.u32l;
    // 0x800586FC: lh          $t1, 0x196($a3)
    ctx->r9 = MEM_H(ctx->r7, 0X196);
    // 0x80058700: nop

    // 0x80058704: subu        $a0, $t2, $t1
    ctx->r4 = SUB32(ctx->r10, ctx->r9);
    // 0x80058708: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x8005870C: jal         0x800707F8
    // 0x80058710: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80058710: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_6:
    // 0x80058714: lwc1        $f12, 0x40($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X40);
    // 0x80058718: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8005871C: mul.s       $f8, $f0, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x80058720: lw          $t5, -0x2AD8($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X2AD8);
    // 0x80058724: mtc1        $zero, $f14
    ctx->f14.u32l = 0;
    // 0x80058728: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x8005872C: andi        $t7, $t5, 0x8000
    ctx->r15 = ctx->r13 & 0X8000;
    // 0x80058730: swc1        $f8, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f8.u32l;
    // 0x80058734: beq         $t7, $zero, L_800587C4
    if (ctx->r15 == 0) {
        // 0x80058738: mov.s       $f2, $f14
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
            goto L_800587C4;
    }
    // 0x80058738: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
    // 0x8005873C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80058740: lwc1        $f4, 0x30($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X30);
    // 0x80058744: lwc1        $f7, 0x6918($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6918);
    // 0x80058748: lwc1        $f6, 0x691C($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X691C);
    // 0x8005874C: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80058750: mul.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80058754: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80058758: cvt.s.d     $f2, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f2.fl = CVT_S_D(ctx->f8.d);
    // 0x8005875C: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x80058760: nop

    // 0x80058764: bc1f        L_8005879C
    if (!c1cs) {
        // 0x80058768: nop
    
            goto L_8005879C;
    }
    // 0x80058768: nop

    // 0x8005876C: lui         $at, 0x3FF8
    ctx->r1 = S32(0X3FF8 << 16);
    // 0x80058770: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80058774: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80058778: cvt.d.s     $f4, $f2
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f4.d = CVT_D_S(ctx->f2.fl);
    // 0x8005877C: sub.d       $f6, $f4, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = ctx->f4.d - ctx->f10.d;
    // 0x80058780: cvt.s.d     $f2, $f6
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f2.fl = CVT_S_D(ctx->f6.d);
    // 0x80058784: c.lt.s      $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    c1cs = ctx->f2.fl < ctx->f14.fl;
    // 0x80058788: nop

    // 0x8005878C: bc1f        L_800587C4
    if (!c1cs) {
        // 0x80058790: nop
    
            goto L_800587C4;
    }
    // 0x80058790: nop

    // 0x80058794: b           L_800587C4
    // 0x80058798: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
        goto L_800587C4;
    // 0x80058798: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_8005879C:
    // 0x8005879C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800587A0: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800587A4: cvt.d.s     $f8, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f8.d = CVT_D_S(ctx->f2.fl);
    // 0x800587A8: add.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f8.d + ctx->f4.d;
    // 0x800587AC: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x800587B0: c.lt.s      $f14, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f14.fl < ctx->f2.fl;
    // 0x800587B4: nop

    // 0x800587B8: bc1f        L_800587C4
    if (!c1cs) {
        // 0x800587BC: nop
    
            goto L_800587C4;
    }
    // 0x800587BC: nop

    // 0x800587C0: mov.s       $f2, $f14
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 14);
    ctx->f2.fl = ctx->f14.fl;
L_800587C4:
    // 0x800587C4: lb          $v0, 0x1E6($a3)
    ctx->r2 = MEM_B(ctx->r7, 0X1E6);
    // 0x800587C8: nop

    // 0x800587CC: beq         $v0, $zero, L_800587F0
    if (ctx->r2 == 0) {
        // 0x800587D0: nop
    
            goto L_800587F0;
    }
    // 0x800587D0: nop

    // 0x800587D4: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x800587D8: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x800587DC: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800587E0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800587E4: neg.s       $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = -ctx->f8.fl;
    // 0x800587E8: mul.s       $f2, $f4, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x800587EC: nop

L_800587F0:
    // 0x800587F0: lwc1        $f0, 0xC8($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x800587F4: lui         $at, 0x3FC0
    ctx->r1 = S32(0X3FC0 << 16);
    // 0x800587F8: sub.s       $f6, $f2, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = ctx->f2.fl - ctx->f0.fl;
    // 0x800587FC: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80058800: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80058804: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80058808: mul.d       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f4.d);
    // 0x8005880C: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x80058810: lb          $t6, 0x1DB($a3)
    ctx->r14 = MEM_B(ctx->r7, 0X1DB);
    // 0x80058814: add.d       $f8, $f6, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f6.d + ctx->f10.d;
    // 0x80058818: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8005881C: beq         $t6, $zero, L_8005884C
    if (ctx->r14 == 0) {
        // 0x80058820: swc1        $f4, 0xC8($a3)
        MEM_W(0XC8, ctx->r7) = ctx->f4.u32l;
            goto L_8005884C;
    }
    // 0x80058820: swc1        $f4, 0xC8($a3)
    MEM_W(0XC8, ctx->r7) = ctx->f4.u32l;
    // 0x80058824: lwc1        $f6, 0x94($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80058828: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8005882C: mtc1        $at, $f11
    ctx->f_odd[(11 - 1) * 2] = ctx->r1;
    // 0x80058830: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80058834: cvt.d.s     $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f0.d = CVT_D_S(ctx->f6.fl);
    // 0x80058838: mul.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = MUL_D(ctx->f0.d, ctx->f10.d);
    // 0x8005883C: sub.d       $f4, $f0, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f0.d - ctx->f8.d;
    // 0x80058840: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x80058844: b           L_80058880
    // 0x80058848: swc1        $f6, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f6.u32l;
        goto L_80058880;
    // 0x80058848: swc1        $f6, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f6.u32l;
L_8005884C:
    // 0x8005884C: lui         $at, 0x4024
    ctx->r1 = S32(0X4024 << 16);
    // 0x80058850: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80058854: lwc1        $f10, 0x94($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80058858: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005885C: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80058860: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x80058864: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80058868: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005886C: sub.d       $f4, $f8, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = ctx->f8.d - ctx->f0.d;
    // 0x80058870: mul.d       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = MUL_D(ctx->f4.d, ctx->f6.d);
    // 0x80058874: add.d       $f8, $f0, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f10.d); 
    ctx->f8.d = ctx->f0.d + ctx->f10.d;
    // 0x80058878: cvt.s.d     $f4, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f4.fl = CVT_S_D(ctx->f8.d);
    // 0x8005887C: swc1        $f4, 0x94($a3)
    MEM_W(0X94, ctx->r7) = ctx->f4.u32l;
L_80058880:
    // 0x80058880: lwc1        $f0, 0x94($a3)
    ctx->f0.u32l = MEM_W(ctx->r7, 0X94);
    // 0x80058884: lwc1        $f10, 0x38($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X38);
    // 0x80058888: lw          $v0, 0x6C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X6C);
    // 0x8005888C: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80058890: lwc1        $f6, 0xC($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0XC);
    // 0x80058894: nop

    // 0x80058898: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x8005889C: swc1        $f4, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f4.u32l;
    // 0x800588A0: lwc1        $f6, 0x3C($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X3C);
    // 0x800588A4: lwc1        $f10, 0x10($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X10);
    // 0x800588A8: mul.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f0.fl);
    // 0x800588AC: sub.s       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x800588B0: swc1        $f4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f4.u32l;
    // 0x800588B4: lwc1        $f10, 0x40($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0X40);
    // 0x800588B8: lwc1        $f6, 0x14($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X14);
    // 0x800588BC: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800588C0: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x800588C4: swc1        $f4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f4.u32l;
    // 0x800588C8: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x800588CC: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800588D0: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x800588D4: sll         $t8, $a0, 16
    ctx->r24 = S32(ctx->r4 << 16);
    // 0x800588D8: jal         0x800707C4
    // 0x800588DC: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    sins_f(rdram, ctx);
        goto after_7;
    // 0x800588DC: sra         $a0, $t8, 16
    ctx->r4 = S32(SIGNED(ctx->r24) >> 16);
    after_7:
    // 0x800588E0: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800588E4: lwc1        $f6, 0x30($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800588E8: lwc1        $f10, 0xC8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x800588EC: lwc1        $f8, 0x48($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X48);
    // 0x800588F0: mul.s       $f12, $f0, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f10.fl);
    // 0x800588F4: add.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x800588F8: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800588FC: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x80058900: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80058904: add.s       $f10, $f4, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80058908: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8005890C: swc1        $f10, 0xC($t2)
    MEM_W(0XC, ctx->r10) = ctx->f10.u32l;
    // 0x80058910: lwc1        $f8, 0x50($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X50);
    // 0x80058914: lwc1        $f6, 0x2C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80058918: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x8005891C: add.s       $f18, $f6, $f8
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f18.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80058920: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80058924: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80058928: sub.s       $f4, $f14, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f14.fl - ctx->f18.fl;
    // 0x8005892C: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80058930: cvt.d.s     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f10.d = CVT_D_S(ctx->f4.fl);
    // 0x80058934: mul.d       $f8, $f10, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x80058938: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005893C: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x80058940: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80058944: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80058948: cvt.s.d     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f16.fl = CVT_S_D(ctx->f8.d);
    // 0x8005894C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80058950: cvt.d.s     $f2, $f16
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f2.d = CVT_D_S(ctx->f16.fl);
    // 0x80058954: c.lt.d      $f2, $f4
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f2.d < ctx->f4.d;
    // 0x80058958: nop

    // 0x8005895C: bc1f        L_80058990
    if (!c1cs) {
        // 0x80058960: nop
    
            goto L_80058990;
    }
    // 0x80058960: nop

    // 0x80058964: mtc1        $at, $f7
    ctx->f_odd[(7 - 1) * 2] = ctx->r1;
    // 0x80058968: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x8005896C: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x80058970: add.d       $f8, $f2, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f6.d); 
    ctx->f8.d = ctx->f2.d + ctx->f6.d;
    // 0x80058974: sub.d       $f4, $f10, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = ctx->f10.d - ctx->f8.d;
    // 0x80058978: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x8005897C: swc1        $f6, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f6.u32l;
    // 0x80058980: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058984: nop

    // 0x80058988: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x8005898C: nop

L_80058990:
    // 0x80058990: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x80058994: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x80058998: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005899C: cvt.d.s     $f10, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f10.d = CVT_D_S(ctx->f14.fl);
    // 0x800589A0: mul.d       $f4, $f2, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f2.d); NAN_CHECK(ctx->f8.d); 
    ctx->f4.d = MUL_D(ctx->f2.d, ctx->f8.d);
    // 0x800589A4: sub.d       $f6, $f10, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = ctx->f10.d - ctx->f4.d;
    // 0x800589A8: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800589AC: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800589B0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x800589B4: swc1        $f8, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f8.u32l;
    // 0x800589B8: bc1t        L_800589D0
    if (c1cs) {
        // 0x800589BC: nop
    
            goto L_800589D0;
    }
    // 0x800589BC: nop

    // 0x800589C0: lw          $t1, -0x2AC0($t1)
    ctx->r9 = MEM_W(ctx->r9, -0X2AC0);
    // 0x800589C4: nop

    // 0x800589C8: beq         $t1, $zero, L_800589DC
    if (ctx->r9 == 0) {
        // 0x800589CC: nop
    
            goto L_800589DC;
    }
    // 0x800589CC: nop

L_800589D0:
    // 0x800589D0: lw          $t3, 0x0($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X0);
    // 0x800589D4: nop

    // 0x800589D8: swc1        $f18, 0x10($t3)
    MEM_W(0X10, ctx->r11) = ctx->f18.u32l;
L_800589DC:
    // 0x800589DC: lh          $a0, 0x196($a3)
    ctx->r4 = MEM_H(ctx->r7, 0X196);
    // 0x800589E0: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    // 0x800589E4: addiu       $a0, $a0, 0x4000
    ctx->r4 = ADD32(ctx->r4, 0X4000);
    // 0x800589E8: sll         $t4, $a0, 16
    ctx->r12 = S32(ctx->r4 << 16);
    // 0x800589EC: jal         0x800707F8
    // 0x800589F0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    coss_f(rdram, ctx);
        goto after_8;
    // 0x800589F0: sra         $a0, $t4, 16
    ctx->r4 = S32(SIGNED(ctx->r12) >> 16);
    after_8:
    // 0x800589F4: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x800589F8: neg.s       $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = -ctx->f0.fl;
    // 0x800589FC: lwc1        $f6, 0xC8($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x80058A00: lwc1        $f8, 0x28($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X28);
    // 0x80058A04: mul.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = MUL_S(ctx->f4.fl, ctx->f6.fl);
    // 0x80058A08: lwc1        $f10, 0x44($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80058A0C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80058A10: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x80058A14: add.s       $f4, $f8, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x80058A18: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80058A1C: add.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = ctx->f4.fl + ctx->f12.fl;
    // 0x80058A20: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80058A24: swc1        $f6, 0x14($t7)
    MEM_W(0X14, ctx->r15) = ctx->f6.u32l;
    // 0x80058A28: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80058A2C: lh          $t6, 0x196($a3)
    ctx->r14 = MEM_H(ctx->r7, 0X196);
    // 0x80058A30: addiu       $t7, $zero, 0x2000
    ctx->r15 = ADD32(0, 0X2000);
    // 0x80058A34: sh          $t6, 0x0($t8)
    MEM_H(0X0, ctx->r24) = ctx->r14;
    // 0x80058A38: lw          $t9, 0x6C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X6C);
    // 0x80058A3C: lb          $t2, 0x1E6($a3)
    ctx->r10 = MEM_B(ctx->r7, 0X1E6);
    // 0x80058A40: lh          $v0, 0x4($t9)
    ctx->r2 = MEM_H(ctx->r25, 0X4);
    // 0x80058A44: beq         $t2, $zero, L_80058A6C
    if (ctx->r10 == 0) {
        // 0x80058A48: addiu       $t6, $zero, -0x2000
        ctx->r14 = ADD32(0, -0X2000);
            goto L_80058A6C;
    }
    // 0x80058A48: addiu       $t6, $zero, -0x2000
    ctx->r14 = ADD32(0, -0X2000);
    // 0x80058A4C: lwc1        $f10, 0xB8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XB8);
    // 0x80058A50: mtc1        $zero, $f9
    ctx->f_odd[(9 - 1) * 2] = 0;
    // 0x80058A54: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80058A58: cvt.d.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f4.d = CVT_D_S(ctx->f10.fl);
    // 0x80058A5C: c.lt.d      $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f8.d < ctx->f4.d;
    // 0x80058A60: nop

    // 0x80058A64: bc1t        L_80058A7C
    if (c1cs) {
        // 0x80058A68: nop
    
            goto L_80058A7C;
    }
    // 0x80058A68: nop

L_80058A6C:
    // 0x80058A6C: lh          $t1, -0x2A7A($t1)
    ctx->r9 = MEM_H(ctx->r9, -0X2A7A);
    // 0x80058A70: nop

    // 0x80058A74: beq         $t1, $zero, L_80058A80
    if (ctx->r9 == 0) {
        // 0x80058A78: nop
    
            goto L_80058A80;
    }
    // 0x80058A78: nop

L_80058A7C:
    // 0x80058A7C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80058A80:
    // 0x80058A80: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058A84: nop

    // 0x80058A88: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80058A8C: nop

    // 0x80058A90: addu        $t3, $a0, $v0
    ctx->r11 = ADD32(ctx->r4, ctx->r2);
    // 0x80058A94: sra         $t4, $t3, 4
    ctx->r12 = S32(SIGNED(ctx->r11) >> 4);
    // 0x80058A98: subu        $t5, $a0, $t4
    ctx->r13 = SUB32(ctx->r4, ctx->r12);
    // 0x80058A9C: sh          $t5, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r13;
    // 0x80058AA0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058AA4: nop

    // 0x80058AA8: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80058AAC: nop

    // 0x80058AB0: slti        $at, $a0, 0x2001
    ctx->r1 = SIGNED(ctx->r4) < 0X2001 ? 1 : 0;
    // 0x80058AB4: bne         $at, $zero, L_80058AD4
    if (ctx->r1 != 0) {
        // 0x80058AB8: slti        $at, $a0, -0x2000
        ctx->r1 = SIGNED(ctx->r4) < -0X2000 ? 1 : 0;
            goto L_80058AD4;
    }
    // 0x80058AB8: slti        $at, $a0, -0x2000
    ctx->r1 = SIGNED(ctx->r4) < -0X2000 ? 1 : 0;
    // 0x80058ABC: sh          $t7, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r15;
    // 0x80058AC0: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058AC4: nop

    // 0x80058AC8: lh          $a0, 0x4($a1)
    ctx->r4 = MEM_H(ctx->r5, 0X4);
    // 0x80058ACC: nop

    // 0x80058AD0: slti        $at, $a0, -0x2000
    ctx->r1 = SIGNED(ctx->r4) < -0X2000 ? 1 : 0;
L_80058AD4:
    // 0x80058AD4: beq         $at, $zero, L_80058AF0
    if (ctx->r1 == 0) {
        // 0x80058AD8: nop
    
            goto L_80058AF0;
    }
    // 0x80058AD8: nop

    // 0x80058ADC: sh          $t6, 0x4($a1)
    MEM_H(0X4, ctx->r5) = ctx->r14;
    // 0x80058AE0: lw          $t8, 0x0($t0)
    ctx->r24 = MEM_W(ctx->r8, 0X0);
    // 0x80058AE4: nop

    // 0x80058AE8: lh          $a0, 0x4($t8)
    ctx->r4 = MEM_H(ctx->r24, 0X4);
    // 0x80058AEC: nop

L_80058AF0:
    // 0x80058AF0: jal         0x800707C4
    // 0x80058AF4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    sins_f(rdram, ctx);
        goto after_9;
    // 0x80058AF4: sw          $a3, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r7;
    after_9:
    // 0x80058AF8: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058AFC: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80058B00: lwc1        $f10, 0xC8($a3)
    ctx->f10.u32l = MEM_W(ctx->r7, 0XC8);
    // 0x80058B04: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x80058B08: mul.s       $f8, $f10, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x80058B0C: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058B10: nop

    // 0x80058B14: lwc1        $f6, 0x10($a1)
    ctx->f6.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80058B18: nop

    // 0x80058B1C: sub.s       $f4, $f6, $f8
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f4.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80058B20: swc1        $f4, 0x10($a1)
    MEM_W(0X10, ctx->r5) = ctx->f4.u32l;
    // 0x80058B24: lw          $a1, 0x0($t0)
    ctx->r5 = MEM_W(ctx->r8, 0X0);
    // 0x80058B28: nop

    // 0x80058B2C: lwc1        $f12, 0xC($a1)
    ctx->f12.u32l = MEM_W(ctx->r5, 0XC);
    // 0x80058B30: lwc1        $f14, 0x10($a1)
    ctx->f14.u32l = MEM_W(ctx->r5, 0X10);
    // 0x80058B34: lw          $a2, 0x14($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X14);
    // 0x80058B38: jal         0x80029F18
    // 0x80058B3C: nop

    get_level_segment_index_from_position(rdram, ctx);
        goto after_10;
    // 0x80058B3C: nop

    after_10:
    // 0x80058B40: lw          $a3, 0x70($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X70);
    // 0x80058B44: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x80058B48: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x80058B4C: beq         $v0, $at, L_80058B60
    if (ctx->r2 == ctx->r1) {
        // 0x80058B50: addiu       $t0, $t0, -0x2AF8
        ctx->r8 = ADD32(ctx->r8, -0X2AF8);
            goto L_80058B60;
    }
    // 0x80058B50: addiu       $t0, $t0, -0x2AF8
    ctx->r8 = ADD32(ctx->r8, -0X2AF8);
    // 0x80058B54: lw          $t9, 0x0($t0)
    ctx->r25 = MEM_W(ctx->r8, 0X0);
    // 0x80058B58: nop

    // 0x80058B5C: sh          $v0, 0x34($t9)
    MEM_H(0X34, ctx->r25) = ctx->r2;
L_80058B60:
    // 0x80058B60: lw          $t2, 0x0($t0)
    ctx->r10 = MEM_W(ctx->r8, 0X0);
    // 0x80058B64: nop

    // 0x80058B68: lh          $t1, 0x0($t2)
    ctx->r9 = MEM_H(ctx->r10, 0X0);
    // 0x80058B6C: nop

    // 0x80058B70: sh          $t1, 0x196($a3)
    MEM_H(0X196, ctx->r7) = ctx->r9;
    // 0x80058B74: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80058B78: addiu       $sp, $sp, 0x68
    ctx->r29 = ADD32(ctx->r29, 0X68);
    // 0x80058B7C: jr          $ra
    // 0x80058B80: nop

    return;
    // 0x80058B80: nop

;}
RECOMP_FUNC void sound_play(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { extern int dkr_legacy_character_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*); static const uint32_t dkr_character_menu_fields[] = { 0x801263d4U, 0x801263dcU, 0x801263e8U, 0x801263f0U, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df480U, 0x800df4bcU, 0x800df47cU, 0x801263a0U, 0x801263ccU, 0x800e3690U, 0x800e36c8U, 0x80126808U, 0x801263c0U, 0x8011ae5cU, 0x8011aec8U }; if (dkr_legacy_character_menu(rdram, ctx, 8U, dkr_character_menu_fields)) return; } { extern int dkr_legacy_character_play_sound(uint8_t*, recomp_context*, unsigned); if (dkr_legacy_character_play_sound(rdram, ctx, 2U)) return; }
    // 0x80001D04: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80001D08: lw          $t7, 0x5D20($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5D20);
    // 0x80001D0C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80001D10: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001D14: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x80001D18: slt         $at, $t7, $t6
    ctx->r1 = SIGNED(ctx->r15) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x80001D1C: or          $a0, $t6, $zero
    ctx->r4 = ctx->r14 | 0;
    // 0x80001D20: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001D24: beq         $at, $zero, L_80001D3C
    if (ctx->r1 == 0) {
        // 0x80001D28: or          $a3, $a1, $zero
        ctx->r7 = ctx->r5 | 0;
            goto L_80001D3C;
    }
    // 0x80001D28: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x80001D2C: beq         $a1, $zero, L_80001E9C
    if (ctx->r5 == 0) {
        // 0x80001D30: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001E9C;
    }
    // 0x80001D30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001D34: b           L_80001E98
    // 0x80001D38: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
        goto L_80001E98;
    // 0x80001D38: sw          $zero, 0x0($a1)
    MEM_W(0X0, ctx->r5) = 0;
L_80001D3C:
    // 0x80001D3C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80001D40: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001D44: lw          $t8, 0x5D18($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5D18);
    // 0x80001D48: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x80001D4C: sll         $t0, $t0, 1
    ctx->r8 = S32(ctx->r8 << 1);
    // 0x80001D50: addu        $v0, $t8, $t0
    ctx->r2 = ADD32(ctx->r24, ctx->r8);
    // 0x80001D54: lhu         $v1, 0x0($v0)
    ctx->r3 = MEM_HU(ctx->r2, 0X0);
    // 0x80001D58: nop

    // 0x80001D5C: bne         $v1, $zero, L_80001D74
    if (ctx->r3 != 0) {
        // 0x80001D60: nop
    
            goto L_80001D74;
    }
    // 0x80001D60: nop

    // 0x80001D64: beq         $a3, $zero, L_80001E9C
    if (ctx->r7 == 0) {
        // 0x80001D68: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001E9C;
    }
    // 0x80001D68: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001D6C: b           L_80001E98
    // 0x80001D70: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
        goto L_80001E98;
    // 0x80001D70: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
L_80001D74:
    // 0x80001D74: lbu         $t9, 0x4($v0)
    ctx->r25 = MEM_BU(ctx->r2, 0X4);
    // 0x80001D78: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80001D7C: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x80001D80: bgez        $t9, L_80001D94
    if (SIGNED(ctx->r25) >= 0) {
        // 0x80001D84: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80001D94;
    }
    // 0x80001D84: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80001D88: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80001D8C: nop

    // 0x80001D90: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80001D94:
    // 0x80001D94: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x80001D98: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80001D9C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001DA0: div.s       $f16, $f6, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x80001DA4: sra         $t7, $a1, 16
    ctx->r15 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001DA8: lui         $t1, 0x8011
    ctx->r9 = S32(0X8011 << 16);
    // 0x80001DAC: or          $a1, $t7, $zero
    ctx->r5 = ctx->r15 | 0;
    // 0x80001DB0: lui         $t6, 0x8011
    ctx->r14 = S32(0X8011 << 16);
    // 0x80001DB4: beq         $a3, $zero, L_80001E34
    if (ctx->r7 == 0) {
        // 0x80001DB8: swc1        $f16, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
            goto L_80001E34;
    }
    // 0x80001DB8: swc1        $f16, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f16.u32l;
    // 0x80001DBC: lw          $t1, 0x5D14($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X5D14);
    // 0x80001DC0: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001DC4: lbu         $a2, 0x8($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X8);
    // 0x80001DC8: lw          $a0, 0x4($t1)
    ctx->r4 = MEM_W(ctx->r9, 0X4);
    // 0x80001DCC: sra         $t2, $a1, 16
    ctx->r10 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001DD0: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x80001DD4: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80001DD8: jal         0x80004668
    // 0x80001DDC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    sndp_play_with_priority(rdram, ctx);
        goto after_0;
    // 0x80001DDC: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    after_0:
    // 0x80001DE0: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80001DE4: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80001DE8: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80001DEC: lui         $t3, 0x8011
    ctx->r11 = S32(0X8011 << 16);
    // 0x80001DF0: beq         $a0, $zero, L_80001E9C
    if (ctx->r4 == 0) {
        // 0x80001DF4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001E9C;
    }
    // 0x80001DF4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001DF8: lw          $t3, 0x5D18($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X5D18);
    // 0x80001DFC: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80001E00: addu        $t4, $t3, $t0
    ctx->r12 = ADD32(ctx->r11, ctx->r8);
    // 0x80001E04: lbu         $a2, 0x2($t4)
    ctx->r6 = MEM_BU(ctx->r12, 0X2);
    // 0x80001E08: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x80001E0C: sll         $t5, $a2, 8
    ctx->r13 = S32(ctx->r6 << 8);
    // 0x80001E10: jal         0x800049F8
    // 0x80001E14: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    sndp_set_param(rdram, ctx);
        goto after_1;
    // 0x80001E14: or          $a2, $t5, $zero
    ctx->r6 = ctx->r13 | 0;
    after_1:
    // 0x80001E18: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x80001E1C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80001E20: lw          $a0, 0x0($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X0);
    // 0x80001E24: jal         0x800049F8
    // 0x80001E28: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_2;
    // 0x80001E28: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_2:
    // 0x80001E2C: b           L_80001E9C
    // 0x80001E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80001E9C;
    // 0x80001E30: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001E34:
    // 0x80001E34: lw          $t6, 0x5D14($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X5D14);
    // 0x80001E38: lbu         $a2, 0x8($v0)
    ctx->r6 = MEM_BU(ctx->r2, 0X8);
    // 0x80001E3C: lui         $a3, 0x8011
    ctx->r7 = S32(0X8011 << 16);
    // 0x80001E40: lw          $a0, 0x4($t6)
    ctx->r4 = MEM_W(ctx->r14, 0X4);
    // 0x80001E44: sw          $t0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r8;
    // 0x80001E48: jal         0x80004668
    // 0x80001E4C: addiu       $a3, $a3, 0x5F80
    ctx->r7 = ADD32(ctx->r7, 0X5F80);
    sndp_play_with_priority(rdram, ctx);
        goto after_3;
    // 0x80001E4C: addiu       $a3, $a3, 0x5F80
    ctx->r7 = ADD32(ctx->r7, 0X5F80);
    after_3:
    // 0x80001E50: lui         $t8, 0x8011
    ctx->r24 = S32(0X8011 << 16);
    // 0x80001E54: lw          $t8, 0x5F80($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X5F80);
    // 0x80001E58: lw          $t0, 0x1C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X1C);
    // 0x80001E5C: beq         $t8, $zero, L_80001E98
    if (ctx->r24 == 0) {
        // 0x80001E60: lui         $t9, 0x8011
        ctx->r25 = S32(0X8011 << 16);
            goto L_80001E98;
    }
    // 0x80001E60: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80001E64: lw          $t9, 0x5D18($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5D18);
    // 0x80001E68: or          $a0, $t8, $zero
    ctx->r4 = ctx->r24 | 0;
    // 0x80001E6C: addu        $t1, $t9, $t0
    ctx->r9 = ADD32(ctx->r25, ctx->r8);
    // 0x80001E70: lbu         $a2, 0x2($t1)
    ctx->r6 = MEM_BU(ctx->r9, 0X2);
    // 0x80001E74: addiu       $a1, $zero, 0x8
    ctx->r5 = ADD32(0, 0X8);
    // 0x80001E78: sll         $t2, $a2, 8
    ctx->r10 = S32(ctx->r6 << 8);
    // 0x80001E7C: jal         0x800049F8
    // 0x80001E80: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    sndp_set_param(rdram, ctx);
        goto after_4;
    // 0x80001E80: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_4:
    // 0x80001E84: lui         $a0, 0x8011
    ctx->r4 = S32(0X8011 << 16);
    // 0x80001E88: lw          $a0, 0x5F80($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X5F80);
    // 0x80001E8C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80001E90: jal         0x800049F8
    // 0x80001E94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    sndp_set_param(rdram, ctx);
        goto after_5;
    // 0x80001E94: addiu       $a1, $zero, 0x10
    ctx->r5 = ADD32(0, 0X10);
    after_5:
L_80001E98:
    // 0x80001E98: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001E9C:
    // 0x80001E9C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x80001EA0: jr          $ra
    // 0x80001EA4: nop

    return;
    // 0x80001EA4: nop

;}
RECOMP_FUNC void get_memory_colour_tag_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071A24: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80071A28: lw          $v0, 0x3588($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X3588);
    // 0x80071A2C: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80071A30: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80071A34: addiu       $a2, $zero, 0x640
    ctx->r6 = ADD32(0, 0X640);
L_80071A38:
    // 0x80071A38: lh          $t6, 0x8($v0)
    ctx->r14 = MEM_H(ctx->r2, 0X8);
    // 0x80071A3C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x80071A40: beq         $t6, $zero, L_80071A5C
    if (ctx->r14 == 0) {
        // 0x80071A44: nop
    
            goto L_80071A5C;
    }
    // 0x80071A44: nop

    // 0x80071A48: lw          $t7, 0x10($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X10);
    // 0x80071A4C: nop

    // 0x80071A50: bne         $a0, $t7, L_80071A5C
    if (ctx->r4 != ctx->r15) {
        // 0x80071A54: nop
    
            goto L_80071A5C;
    }
    // 0x80071A54: nop

    // 0x80071A58: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071A5C:
    // 0x80071A5C: lh          $t8, 0x1C($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X1C);
    // 0x80071A60: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071A64: beq         $t8, $zero, L_80071A80
    if (ctx->r24 == 0) {
        // 0x80071A68: nop
    
            goto L_80071A80;
    }
    // 0x80071A68: nop

    // 0x80071A6C: lw          $t9, 0x10($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X10);
    // 0x80071A70: nop

    // 0x80071A74: bne         $a0, $t9, L_80071A80
    if (ctx->r4 != ctx->r25) {
        // 0x80071A78: nop
    
            goto L_80071A80;
    }
    // 0x80071A78: nop

    // 0x80071A7C: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071A80:
    // 0x80071A80: lh          $t0, 0x1C($v0)
    ctx->r8 = MEM_H(ctx->r2, 0X1C);
    // 0x80071A84: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071A88: beq         $t0, $zero, L_80071AA4
    if (ctx->r8 == 0) {
        // 0x80071A8C: nop
    
            goto L_80071AA4;
    }
    // 0x80071A8C: nop

    // 0x80071A90: lw          $t1, 0x10($v0)
    ctx->r9 = MEM_W(ctx->r2, 0X10);
    // 0x80071A94: nop

    // 0x80071A98: bne         $a0, $t1, L_80071AA4
    if (ctx->r4 != ctx->r9) {
        // 0x80071A9C: nop
    
            goto L_80071AA4;
    }
    // 0x80071A9C: nop

    // 0x80071AA0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071AA4:
    // 0x80071AA4: lh          $t2, 0x1C($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X1C);
    // 0x80071AA8: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071AAC: beq         $t2, $zero, L_80071AC8
    if (ctx->r10 == 0) {
        // 0x80071AB0: nop
    
            goto L_80071AC8;
    }
    // 0x80071AB0: nop

    // 0x80071AB4: lw          $t3, 0x10($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X10);
    // 0x80071AB8: nop

    // 0x80071ABC: bne         $a0, $t3, L_80071AC8
    if (ctx->r4 != ctx->r11) {
        // 0x80071AC0: nop
    
            goto L_80071AC8;
    }
    // 0x80071AC0: nop

    // 0x80071AC4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
L_80071AC8:
    // 0x80071AC8: bne         $a1, $a2, L_80071A38
    if (ctx->r5 != ctx->r6) {
        // 0x80071ACC: addiu       $v0, $v0, 0x14
        ctx->r2 = ADD32(ctx->r2, 0X14);
            goto L_80071A38;
    }
    // 0x80071ACC: addiu       $v0, $v0, 0x14
    ctx->r2 = ADD32(ctx->r2, 0X14);
    // 0x80071AD0: jr          $ra
    // 0x80071AD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x80071AD4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void mtxf_billboard(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80070130: addiu       $sp, $sp, -0x8
    ctx->r29 = ADD32(ctx->r29, -0X8);
    // 0x80070134: or          $t9, $a3, $zero
    ctx->r25 = ctx->r7 | 0;
    // 0x80070138: lui         $at, 0x3780
    ctx->r1 = S32(0X3780 << 16);
    // 0x8007013C: sd          $ra, 0x0($sp)
    SD(ctx->r31, 0X0, ctx->r29);
    // 0x80070140: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80070144: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80070148: jal         0x80070830
    // 0x8007014C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    sins_s16(rdram, ctx);
        goto after_0;
    // 0x8007014C: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    after_0:
    // 0x80070150: mtc1        $v0, $f8
    ctx->f8.u32l = ctx->r2;
    // 0x80070154: or          $a0, $a1, $zero
    ctx->r4 = ctx->r5 | 0;
    // 0x80070158: cvt.s.w     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.fl = CVT_S_W(ctx->f8.u32l);
    // 0x8007015C: mul.s       $f8, $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f18.fl);
    // 0x80070160: jal         0x8007082C
    // 0x80070164: nop

    coss_s16(rdram, ctx);
        goto after_1;
    // 0x80070164: nop

    after_1:
    // 0x80070168: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x8007016C: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x80070170: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80070174: cvt.s.w     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80070178: swc1        $f16, 0x28($a3)
    MEM_W(0X28, ctx->r7) = ctx->f16.u32l;
    // 0x8007017C: sw          $zero, 0x8($a3)
    MEM_W(0X8, ctx->r7) = 0;
    // 0x80070180: sw          $zero, 0xC($a3)
    MEM_W(0XC, ctx->r7) = 0;
    // 0x80070184: sw          $zero, 0x18($a3)
    MEM_W(0X18, ctx->r7) = 0;
    // 0x80070188: sw          $zero, 0x1C($a3)
    MEM_W(0X1C, ctx->r7) = 0;
    // 0x8007018C: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80070190: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80070194: sw          $zero, 0x20($a3)
    MEM_W(0X20, ctx->r7) = 0;
    // 0x80070198: sw          $zero, 0x24($a3)
    MEM_W(0X24, ctx->r7) = 0;
    // 0x8007019C: sw          $zero, 0x2C($a3)
    MEM_W(0X2C, ctx->r7) = 0;
    // 0x800701A0: sw          $zero, 0x30($a3)
    MEM_W(0X30, ctx->r7) = 0;
    // 0x800701A4: sw          $zero, 0x34($a3)
    MEM_W(0X34, ctx->r7) = 0;
    // 0x800701A8: mul.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800701AC: sw          $zero, 0x38($a3)
    MEM_W(0X38, ctx->r7) = 0;
    // 0x800701B0: mul.s       $f8, $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800701B4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800701B8: swc1        $f10, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->f10.u32l;
    // 0x800701BC: mul.s       $f10, $f10, $f18
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800701C0: swc1        $f16, 0x3C($a3)
    MEM_W(0X3C, ctx->r7) = ctx->f16.u32l;
    // 0x800701C4: swc1        $f8, 0x4($a3)
    MEM_W(0X4, ctx->r7) = ctx->f8.u32l;
    // 0x800701C8: neg.s       $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f8.fl = -ctx->f8.fl;
    // 0x800701CC: swc1        $f8, 0x10($a3)
    MEM_W(0X10, ctx->r7) = ctx->f8.u32l;
    // 0x800701D0: swc1        $f10, 0x14($a3)
    MEM_W(0X14, ctx->r7) = ctx->f10.u32l;
    // 0x800701D4: ld          $ra, 0x0($sp)
    ctx->r31 = LD(ctx->r29, 0X0);
    // 0x800701D8: addiu       $sp, $sp, 0x8
    ctx->r29 = ADD32(ctx->r29, 0X8);
    // 0x800701DC: jr          $ra
    // 0x800701E0: nop

    return;
    // 0x800701E0: nop

;}
RECOMP_FUNC void debug_text_origin(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B6EE0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800B6EE4: lw          $t6, 0x7CBC($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X7CBC);
    // 0x800B6EE8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6EEC: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800B6EF0: lw          $t7, 0x7CC4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X7CC4);
    // 0x800B6EF4: sh          $t6, 0x7CAC($at)
    MEM_H(0X7CAC, ctx->r1) = ctx->r14;
    // 0x800B6EF8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800B6EFC: jr          $ra
    // 0x800B6F00: sh          $t7, 0x7CAE($at)
    MEM_H(0X7CAE, ctx->r1) = ctx->r15;
    return;
    // 0x800B6F00: sh          $t7, 0x7CAE($at)
    MEM_H(0X7CAE, ctx->r1) = ctx->r15;
;}
RECOMP_FUNC void level_header_count(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006BDC0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006BDC4: lw          $v0, 0x1170($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X1170);
    // 0x8006BDC8: nop

    // 0x8006BDCC: addiu       $v0, $v0, -0x1
    ctx->r2 = ADD32(ctx->r2, -0X1);
    // 0x8006BDD0: andi        $t6, $v0, 0xFF
    ctx->r14 = ctx->r2 & 0XFF;
    // 0x8006BDD4: jr          $ra
    // 0x8006BDD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
    return;
    // 0x8006BDD8: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
;}
RECOMP_FUNC void obj_loop_effectbox(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80034B74: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80034B78: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80034B7C: sw          $s0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r16;
    // 0x80034B80: swc1        $f31, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80034B84: swc1        $f30, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->f30.u32l;
    // 0x80034B88: swc1        $f29, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80034B8C: swc1        $f28, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f28.u32l;
    // 0x80034B90: swc1        $f27, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80034B94: swc1        $f26, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f26.u32l;
    // 0x80034B98: swc1        $f25, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80034B9C: swc1        $f24, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f24.u32l;
    // 0x80034BA0: swc1        $f23, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80034BA4: swc1        $f22, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f22.u32l;
    // 0x80034BA8: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80034BAC: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80034BB0: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80034BB4: lw          $s0, 0x3C($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X3C);
    // 0x80034BB8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80034BBC: sw          $a2, 0x98($sp)
    MEM_W(0X98, ctx->r29) = ctx->r6;
    // 0x80034BC0: jal         0x8001BA74
    // 0x80034BC4: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x80034BC4: addiu       $a0, $sp, 0x8C
    ctx->r4 = ADD32(ctx->r29, 0X8C);
    after_0:
    // 0x80034BC8: sw          $v0, 0x94($sp)
    MEM_W(0X94, ctx->r29) = ctx->r2;
    // 0x80034BCC: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    // 0x80034BD0: nop

    // 0x80034BD4: sll         $t6, $a0, 8
    ctx->r14 = S32(ctx->r4 << 8);
    // 0x80034BD8: negu        $a0, $t6
    ctx->r4 = SUB32(0, ctx->r14);
    // 0x80034BDC: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x80034BE0: jal         0x800707F8
    // 0x80034BE4: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x80034BE4: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    after_1:
    // 0x80034BE8: lbu         $a0, 0xB($s0)
    ctx->r4 = MEM_BU(ctx->r16, 0XB);
    // 0x80034BEC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x80034BF0: sll         $t9, $a0, 8
    ctx->r25 = S32(ctx->r4 << 8);
    // 0x80034BF4: negu        $a0, $t9
    ctx->r4 = SUB32(0, ctx->r25);
    // 0x80034BF8: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80034BFC: jal         0x800707C4
    // 0x80034C00: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    sins_f(rdram, ctx);
        goto after_2;
    // 0x80034C00: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_2:
    // 0x80034C04: lbu         $t2, 0x8($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X8);
    // 0x80034C08: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
    // 0x80034C0C: multu       $t2, $v0
    result = U64(U32(ctx->r10)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034C10: lbu         $t4, 0x9($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0X9);
    // 0x80034C14: lbu         $t6, 0xA($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XA);
    // 0x80034C18: lw          $t8, 0x8C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X8C);
    // 0x80034C1C: lw          $a2, 0x98($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X98);
    // 0x80034C20: lw          $a1, 0x94($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X94);
    // 0x80034C24: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80034C28: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80034C2C: addiu       $a3, $zero, 0x1
    ctx->r7 = ADD32(0, 0X1);
    // 0x80034C30: mflo        $t3
    ctx->r11 = lo;
    // 0x80034C34: mtc1        $t3, $f4
    ctx->f4.u32l = ctx->r11;
    // 0x80034C38: nop

    // 0x80034C3C: multu       $t4, $v0
    result = U64(U32(ctx->r12)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034C40: cvt.s.w     $f22, $f4
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    ctx->f22.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80034C44: mflo        $t5
    ctx->r13 = lo;
    // 0x80034C48: mtc1        $t5, $f6
    ctx->f6.u32l = ctx->r13;
    // 0x80034C4C: nop

    // 0x80034C50: multu       $t6, $v0
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r2)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80034C54: cvt.s.w     $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    ctx->f18.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80034C58: mflo        $t7
    ctx->r15 = lo;
    // 0x80034C5C: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x80034C60: blez        $t8, L_80034E30
    if (SIGNED(ctx->r24) <= 0) {
        // 0x80034C64: cvt.s.w     $f24, $f8
        CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
            goto L_80034E30;
    }
    // 0x80034C64: cvt.s.w     $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    ctx->f24.fl = CVT_S_W(ctx->f8.u32l);
    // 0x80034C68: mtc1        $at, $f30
    ctx->f30.u32l = ctx->r1;
    // 0x80034C6C: lui         $at, 0x3FF0
    ctx->r1 = S32(0X3FF0 << 16);
    // 0x80034C70: mtc1        $at, $f27
    ctx->f_odd[(27 - 1) * 2] = ctx->r1;
    // 0x80034C74: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x80034C78: neg.s       $f28, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = -ctx->f18.fl;
L_80034C7C:
    // 0x80034C7C: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x80034C80: lwc1        $f4, 0xC($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80034C84: lwc1        $f8, 0x10($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X10);
    // 0x80034C88: lwc1        $f10, 0xC($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0XC);
    // 0x80034C8C: lwc1        $f6, 0x10($v1)
    ctx->f6.u32l = MEM_W(ctx->r3, 0X10);
    // 0x80034C90: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80034C94: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80034C98: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80034C9C: lwc1        $f10, 0x14($v1)
    ctx->f10.u32l = MEM_W(ctx->r3, 0X14);
    // 0x80034CA0: c.lt.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl < ctx->f2.fl;
    // 0x80034CA4: sub.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80034CA8: bc1f        L_80034E24
    if (!c1cs) {
        // 0x80034CAC: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E24;
    }
    // 0x80034CAC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034CB0: c.lt.s      $f2, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f2.fl < ctx->f18.fl;
    // 0x80034CB4: nop

    // 0x80034CB8: bc1f        L_80034E24
    if (!c1cs) {
        // 0x80034CBC: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E24;
    }
    // 0x80034CBC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034CC0: mul.s       $f6, $f14, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f20.fl);
    // 0x80034CC4: neg.s       $f10, $f22
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); 
    ctx->f10.fl = -ctx->f22.fl;
    // 0x80034CC8: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x80034CCC: add.s       $f16, $f6, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80034CD0: c.lt.s      $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f10.fl < ctx->f16.fl;
    // 0x80034CD4: nop

    // 0x80034CD8: bc1f        L_80034E24
    if (!c1cs) {
        // 0x80034CDC: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E24;
    }
    // 0x80034CDC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034CE0: c.lt.s      $f16, $f22
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f16.fl < ctx->f22.fl;
    // 0x80034CE4: nop

    // 0x80034CE8: bc1f        L_80034E24
    if (!c1cs) {
        // 0x80034CEC: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E24;
    }
    // 0x80034CEC: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034CF0: neg.s       $f4, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = -ctx->f14.fl;
    // 0x80034CF4: mul.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80034CF8: neg.s       $f10, $f24
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); 
    ctx->f10.fl = -ctx->f24.fl;
    // 0x80034CFC: mul.s       $f8, $f12, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f20.fl);
    // 0x80034D00: add.s       $f12, $f6, $f8
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f12.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80034D04: c.lt.s      $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f10.fl < ctx->f12.fl;
    // 0x80034D08: nop

    // 0x80034D0C: bc1f        L_80034E24
    if (!c1cs) {
        // 0x80034D10: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E24;
    }
    // 0x80034D10: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D14: c.lt.s      $f12, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f12.fl < ctx->f24.fl;
    // 0x80034D18: nop

    // 0x80034D1C: bc1f        L_80034E20
    if (!c1cs) {
        // 0x80034D20: nop
    
            goto L_80034E20;
    }
    // 0x80034D20: nop

    // 0x80034D24: div.s       $f12, $f18, $f30
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f12.fl = DIV_S(ctx->f18.fl, ctx->f30.fl);
    // 0x80034D28: lw          $v0, 0x64($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X64);
    // 0x80034D2C: lbu         $t9, 0xC($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XC);
    // 0x80034D30: nop

    // 0x80034D34: sb          $t9, 0x1FE($v0)
    MEM_B(0X1FE, ctx->r2) = ctx->r25;
    // 0x80034D38: lbu         $t0, 0xD($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XD);
    // 0x80034D3C: andi        $t1, $t9, 0xFF
    ctx->r9 = ctx->r25 & 0XFF;
    // 0x80034D40: sb          $t0, 0x1FF($v0)
    MEM_B(0X1FF, ctx->r2) = ctx->r8;
    // 0x80034D44: c.lt.s      $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f12.fl < ctx->f2.fl;
    // 0x80034D48: nop

    // 0x80034D4C: bc1f        L_80034E24
    if (!c1cs) {
        // 0x80034D50: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E24;
    }
    // 0x80034D50: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D54: bne         $a3, $t1, L_80034E24
    if (ctx->r7 != ctx->r9) {
        // 0x80034D58: lw          $t5, 0x8C($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X8C);
            goto L_80034E24;
    }
    // 0x80034D58: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
    // 0x80034D5C: sub.s       $f4, $f2, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f2.fl - ctx->f12.fl;
    // 0x80034D60: andi        $t2, $t0, 0xFF
    ctx->r10 = ctx->r8 & 0XFF;
    // 0x80034D64: div.s       $f6, $f4, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f12.fl);
    // 0x80034D68: mtc1        $t2, $f4
    ctx->f4.u32l = ctx->r10;
    // 0x80034D6C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x80034D70: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x80034D74: sub.d       $f10, $f26, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f26.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f26.d - ctx->f8.d;
    // 0x80034D78: cvt.s.d     $f2, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f2.fl = CVT_S_D(ctx->f10.d);
    // 0x80034D7C: bgez        $t2, L_80034D90
    if (SIGNED(ctx->r10) >= 0) {
        // 0x80034D80: cvt.s.w     $f6, $f4
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
            goto L_80034D90;
    }
    // 0x80034D80: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80034D84: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80034D88: nop

    // 0x80034D8C: add.s       $f6, $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f8.fl;
L_80034D90:
    // 0x80034D90: mul.s       $f10, $f6, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = MUL_S(ctx->f6.fl, ctx->f2.fl);
    // 0x80034D94: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80034D98: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x80034D9C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80034DA0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80034DA4: nop

    // 0x80034DA8: cvt.w.s     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80034DAC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80034DB0: nop

    // 0x80034DB4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80034DB8: beq         $t4, $zero, L_80034E04
    if (ctx->r12 == 0) {
        // 0x80034DBC: nop
    
            goto L_80034E04;
    }
    // 0x80034DBC: nop

    // 0x80034DC0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x80034DC4: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x80034DC8: sub.s       $f4, $f10, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f4.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80034DCC: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x80034DD0: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x80034DD4: nop

    // 0x80034DD8: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80034DDC: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x80034DE0: nop

    // 0x80034DE4: andi        $t4, $t4, 0x78
    ctx->r12 = ctx->r12 & 0X78;
    // 0x80034DE8: bne         $t4, $zero, L_80034DFC
    if (ctx->r12 != 0) {
        // 0x80034DEC: nop
    
            goto L_80034DFC;
    }
    // 0x80034DEC: nop

    // 0x80034DF0: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80034DF4: b           L_80034E14
    // 0x80034DF8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
        goto L_80034E14;
    // 0x80034DF8: or          $t4, $t4, $at
    ctx->r12 = ctx->r12 | ctx->r1;
L_80034DFC:
    // 0x80034DFC: b           L_80034E14
    // 0x80034E00: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
        goto L_80034E14;
    // 0x80034E00: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
L_80034E04:
    // 0x80034E04: mfc1        $t4, $f4
    ctx->r12 = (int32_t)ctx->f4.u32l;
    // 0x80034E08: nop

    // 0x80034E0C: bltz        $t4, L_80034DFC
    if (SIGNED(ctx->r12) < 0) {
        // 0x80034E10: nop
    
            goto L_80034DFC;
    }
    // 0x80034E10: nop

L_80034E14:
    // 0x80034E14: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80034E18: sb          $t4, 0x1FF($v0)
    MEM_B(0X1FF, ctx->r2) = ctx->r12;
    // 0x80034E1C: nop

L_80034E20:
    // 0x80034E20: lw          $t5, 0x8C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X8C);
L_80034E24:
    // 0x80034E24: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x80034E28: bne         $a0, $t5, L_80034C7C
    if (ctx->r4 != ctx->r13) {
        // 0x80034E2C: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_80034C7C;
    }
    // 0x80034E2C: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_80034E30:
    // 0x80034E30: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x80034E34: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80034E38: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80034E3C: lwc1        $f23, 0x20($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x80034E40: lwc1        $f22, 0x24($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X24);
    // 0x80034E44: lwc1        $f25, 0x28($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x80034E48: lwc1        $f24, 0x2C($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x80034E4C: lwc1        $f27, 0x30($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x80034E50: lwc1        $f26, 0x34($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X34);
    // 0x80034E54: lwc1        $f29, 0x38($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x80034E58: lwc1        $f28, 0x3C($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x80034E5C: lwc1        $f31, 0x40($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X40);
    // 0x80034E60: lwc1        $f30, 0x44($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X44);
    // 0x80034E64: lw          $s0, 0x48($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X48);
    // 0x80034E68: jr          $ra
    // 0x80034E6C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x80034E6C: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void mempool_print_slots(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80071C74: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80071C78: lw          $v1, 0x35C0($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X35C0);
    // 0x80071C7C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80071C80: bltz        $v1, L_80071CE0
    if (SIGNED(ctx->r3) < 0) {
        // 0x80071C84: addiu       $a0, $t6, 0x3580
        ctx->r4 = ADD32(ctx->r14, 0X3580);
            goto L_80071CE0;
    }
    // 0x80071C84: addiu       $a0, $t6, 0x3580
    ctx->r4 = ADD32(ctx->r14, 0X3580);
    // 0x80071C88: sll         $t7, $v1, 4
    ctx->r15 = S32(ctx->r3 << 4);
    // 0x80071C8C: addu        $t0, $t7, $a0
    ctx->r8 = ADD32(ctx->r15, ctx->r4);
    // 0x80071C90: addiu       $t4, $zero, 0x14
    ctx->r12 = ADD32(0, 0X14);
    // 0x80071C94: addiu       $t3, $zero, -0x1
    ctx->r11 = ADD32(0, -0X1);
L_80071C98:
    // 0x80071C98: lw          $v1, 0x8($a0)
    ctx->r3 = MEM_W(ctx->r4, 0X8);
    // 0x80071C9C: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x80071CA0: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_80071CA4:
    // 0x80071CA4: lh          $a1, 0x8($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X8);
    // 0x80071CA8: lh          $a3, 0xC($v0)
    ctx->r7 = MEM_H(ctx->r2, 0XC);
    // 0x80071CAC: beq         $a1, $zero, L_80071CB4
    if (ctx->r5 == 0) {
        // 0x80071CB0: or          $a2, $a3, $zero
        ctx->r6 = ctx->r7 | 0;
            goto L_80071CB4;
    }
    // 0x80071CB0: or          $a2, $a3, $zero
    ctx->r6 = ctx->r7 | 0;
L_80071CB4:
    // 0x80071CB4: beq         $a2, $t3, L_80071CCC
    if (ctx->r6 == ctx->r11) {
        // 0x80071CB8: nop
    
            goto L_80071CCC;
    }
    // 0x80071CB8: nop

    // 0x80071CBC: multu       $a3, $t4
    result = U64(U32(ctx->r7)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80071CC0: mflo        $t8
    ctx->r24 = lo;
    // 0x80071CC4: addu        $v0, $v1, $t8
    ctx->r2 = ADD32(ctx->r3, ctx->r24);
    // 0x80071CC8: nop

L_80071CCC:
    // 0x80071CCC: bne         $a2, $t3, L_80071CA4
    if (ctx->r6 != ctx->r11) {
        // 0x80071CD0: nop
    
            goto L_80071CA4;
    }
    // 0x80071CD0: nop

    // 0x80071CD4: sltu        $at, $t0, $a0
    ctx->r1 = ctx->r8 < ctx->r4 ? 1 : 0;
    // 0x80071CD8: beq         $at, $zero, L_80071C98
    if (ctx->r1 == 0) {
        // 0x80071CDC: nop
    
            goto L_80071C98;
    }
    // 0x80071CDC: nop

L_80071CE0:
    // 0x80071CE0: jr          $ra
    // 0x80071CE4: nop

    return;
    // 0x80071CE4: nop

;}
RECOMP_FUNC void func_8001E89C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E89C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E8A0: addiu       $v0, $v0, -0x51FF
    ctx->r2 = ADD32(ctx->r2, -0X51FF);
    // 0x8001E8A4: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001E8A8: nop

    // 0x8001E8AC: beq         $t6, $zero, L_8001E8BC
    if (ctx->r14 == 0) {
        // 0x8001E8B0: nop
    
            goto L_8001E8BC;
    }
    // 0x8001E8B0: nop

    // 0x8001E8B4: jr          $ra
    // 0x8001E8B8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    return;
    // 0x8001E8B8: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8001E8BC:
    // 0x8001E8BC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E8C0: lb          $v1, -0x5200($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X5200);
    // 0x8001E8C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E8C8: blez        $v1, L_8001E934
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E8CC: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8001E934;
    }
    // 0x8001E8CC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001E8D0: addiu       $a1, $a1, -0x5228
    ctx->r5 = ADD32(ctx->r5, -0X5228);
L_8001E8D4:
    // 0x8001E8D4: lw          $a0, 0x0($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X0);
    // 0x8001E8D8: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E8DC: lw          $a2, 0x64($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X64);
    // 0x8001E8E0: nop

    // 0x8001E8E4: lw          $a3, 0xC($a2)
    ctx->r7 = MEM_W(ctx->r6, 0XC);
    // 0x8001E8E8: nop

    // 0x8001E8EC: beq         $a3, $zero, L_8001E92C
    if (ctx->r7 == 0) {
        // 0x8001E8F0: slt         $at, $v0, $v1
        ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
            goto L_8001E92C;
    }
    // 0x8001E8F0: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E8F4: lwc1        $f4, 0x0($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X0);
    // 0x8001E8F8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001E8FC: swc1        $f4, 0xC($a3)
    MEM_W(0XC, ctx->r7) = ctx->f4.u32l;
    // 0x8001E900: lw          $t7, 0xC($a2)
    ctx->r15 = MEM_W(ctx->r6, 0XC);
    // 0x8001E904: lwc1        $f6, 0x4($a2)
    ctx->f6.u32l = MEM_W(ctx->r6, 0X4);
    // 0x8001E908: nop

    // 0x8001E90C: swc1        $f6, 0x10($t7)
    MEM_W(0X10, ctx->r15) = ctx->f6.u32l;
    // 0x8001E910: lw          $t8, 0xC($a2)
    ctx->r24 = MEM_W(ctx->r6, 0XC);
    // 0x8001E914: lwc1        $f8, 0x8($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X8);
    // 0x8001E918: nop

    // 0x8001E91C: swc1        $f8, 0x14($t8)
    MEM_W(0X14, ctx->r24) = ctx->f8.u32l;
    // 0x8001E920: lb          $v1, -0x5200($v1)
    ctx->r3 = MEM_B(ctx->r3, -0X5200);
    // 0x8001E924: nop

    // 0x8001E928: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
L_8001E92C:
    // 0x8001E92C: bne         $at, $zero, L_8001E8D4
    if (ctx->r1 != 0) {
        // 0x8001E930: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001E8D4;
    }
    // 0x8001E930: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001E934:
    // 0x8001E934: jr          $ra
    // 0x8001E938: nop

    return;
    // 0x8001E938: nop

;}
RECOMP_FUNC void obj_door_override(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800235C0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800235C4: lb          $v0, -0x522B($v0)
    ctx->r2 = MEM_B(ctx->r2, -0X522B);
    // 0x800235C8: jr          $ra
    // 0x800235CC: nop

    return;
    // 0x800235CC: nop

;}
RECOMP_FUNC void obj_init_exit(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80038E3C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80038E40: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80038E44: lbu         $t7, 0x10($a1)
    ctx->r15 = MEM_BU(ctx->r5, 0X10);
    // 0x80038E48: lui         $at, 0x40A0
    ctx->r1 = S32(0X40A0 << 16);
    // 0x80038E4C: mtc1        $t7, $f4
    ctx->f4.u32l = ctx->r15;
    // 0x80038E50: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x80038E54: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80038E58: lui         $at, 0x4300
    ctx->r1 = S32(0X4300 << 16);
    // 0x80038E5C: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80038E60: c.lt.s      $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f0.fl < ctx->f2.fl;
    // 0x80038E64: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x80038E68: bc1f        L_80038E78
    if (!c1cs) {
        // 0x80038E6C: nop
    
            goto L_80038E78;
    }
    // 0x80038E6C: nop

    // 0x80038E70: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
    // 0x80038E74: nop

L_80038E78:
    // 0x80038E78: div.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = DIV_S(ctx->f0.fl, ctx->f6.fl);
    // 0x80038E7C: lw          $v0, 0x64($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X64);
    // 0x80038E80: swc1        $f0, 0x8($a2)
    MEM_W(0X8, ctx->r6) = ctx->f0.u32l;
    // 0x80038E84: lbu         $t9, 0x11($a1)
    ctx->r25 = MEM_BU(ctx->r5, 0X11);
    // 0x80038E88: nop

    // 0x80038E8C: sll         $t0, $t9, 10
    ctx->r8 = S32(ctx->r25 << 10);
    // 0x80038E90: sh          $t0, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r8;
    // 0x80038E94: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80038E98: sw          $a2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r6;
    // 0x80038E9C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80038EA0: jal         0x800707C4
    // 0x80038EA4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    sins_f(rdram, ctx);
        goto after_0;
    // 0x80038EA4: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_0:
    // 0x80038EA8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80038EAC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80038EB0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x80038EB4: swc1        $f0, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->f0.u32l;
    // 0x80038EB8: swc1        $f8, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->f8.u32l;
    // 0x80038EBC: lh          $a0, 0x0($a2)
    ctx->r4 = MEM_H(ctx->r6, 0X0);
    // 0x80038EC0: jal         0x800707F8
    // 0x80038EC4: nop

    coss_f(rdram, ctx);
        goto after_1;
    // 0x80038EC4: nop

    after_1:
    // 0x80038EC8: lw          $v0, 0x18($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X18);
    // 0x80038ECC: lw          $a2, 0x20($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X20);
    // 0x80038ED0: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x80038ED4: swc1        $f0, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->f0.u32l;
    // 0x80038ED8: lwc1        $f10, 0x0($v0)
    ctx->f10.u32l = MEM_W(ctx->r2, 0X0);
    // 0x80038EDC: lwc1        $f16, 0xC($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0XC);
    // 0x80038EE0: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x80038EE4: mul.s       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x80038EE8: addiu       $t3, $zero, 0x2
    ctx->r11 = ADD32(0, 0X2);
    // 0x80038EEC: mul.s       $f6, $f0, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80038EF0: add.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl + ctx->f6.fl;
    // 0x80038EF4: neg.s       $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = -ctx->f8.fl;
    // 0x80038EF8: swc1        $f10, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->f10.u32l;
    // 0x80038EFC: lbu         $t1, 0x10($a1)
    ctx->r9 = MEM_BU(ctx->r5, 0X10);
    // 0x80038F00: nop

    // 0x80038F04: sw          $t1, 0x10($v0)
    MEM_W(0X10, ctx->r2) = ctx->r9;
    // 0x80038F08: lb          $t2, 0x18($a1)
    ctx->r10 = MEM_B(ctx->r5, 0X18);
    // 0x80038F0C: nop

    // 0x80038F10: sb          $t2, 0x14($v0)
    MEM_B(0X14, ctx->r2) = ctx->r10;
    // 0x80038F14: lw          $t4, 0x4C($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F18: nop

    // 0x80038F1C: sh          $t3, 0x14($t4)
    MEM_H(0X14, ctx->r12) = ctx->r11;
    // 0x80038F20: lw          $t5, 0x4C($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F24: nop

    // 0x80038F28: sb          $zero, 0x11($t5)
    MEM_B(0X11, ctx->r13) = 0;
    // 0x80038F2C: lw          $t7, 0x4C($a2)
    ctx->r15 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F30: lbu         $t6, 0x10($a1)
    ctx->r14 = MEM_BU(ctx->r5, 0X10);
    // 0x80038F34: nop

    // 0x80038F38: sb          $t6, 0x10($t7)
    MEM_B(0X10, ctx->r15) = ctx->r14;
    // 0x80038F3C: lw          $t8, 0x4C($a2)
    ctx->r24 = MEM_W(ctx->r6, 0X4C);
    // 0x80038F40: nop

    // 0x80038F44: sb          $zero, 0x12($t8)
    MEM_B(0X12, ctx->r24) = 0;
    // 0x80038F48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80038F4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80038F50: jr          $ra
    // 0x80038F54: nop

    return;
    // 0x80038F54: nop

;}
RECOMP_FUNC void waves_get_y(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BEFC4: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800BEFC8: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BEFCC: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x800BEFD0: lw          $t6, 0x3188($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3188);
    // 0x800BEFD4: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x800BEFD8: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x800BEFDC: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x800BEFE0: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x800BEFE4: or          $s0, $a1, $zero
    ctx->r16 = ctx->r5 | 0;
    // 0x800BEFE8: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x800BEFEC: sw          $ra, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r31;
    // 0x800BEFF0: sw          $s5, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r21;
    // 0x800BEFF4: sw          $s4, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r20;
    // 0x800BEFF8: sw          $s3, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r19;
    // 0x800BEFFC: sw          $s2, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r18;
    // 0x800BF000: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x800BF004: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x800BF008: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x800BF00C: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x800BF010: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x800BF014: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x800BF018: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x800BF01C: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x800BF020: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x800BF024: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x800BF028: bgtz        $t6, L_800BF038
    if (SIGNED(ctx->r14) > 0) {
        // 0x800BF02C: mov.s       $f28, $f2
        CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
            goto L_800BF038;
    }
    // 0x800BF02C: mov.s       $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    ctx->f28.fl = ctx->f2.fl;
    // 0x800BF030: b           L_800BF390
    // 0x800BF034: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
        goto L_800BF390;
    // 0x800BF034: mov.s       $f0, $f2
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 2);
    ctx->f0.fl = ctx->f2.fl;
L_800BF038:
    // 0x800BF038: lui         $v0, 0x8013
    ctx->r2 = S32(0X8013 << 16);
    // 0x800BF03C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF040: addiu       $v0, $v0, -0x6038
    ctx->r2 = ADD32(ctx->r2, -0X6038);
    // 0x800BF044: lwc1        $f0, -0x5F48($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X5F48);
    // 0x800BF048: lw          $t7, 0x28($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X28);
    // 0x800BF04C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800BF050: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x800BF054: lwc1        $f2, -0x5F44($at)
    ctx->f2.u32l = MEM_W(ctx->r1, -0X5F44);
    // 0x800BF058: beq         $t7, $zero, L_800BF07C
    if (ctx->r15 == 0) {
        // 0x800BF05C: lui         $t9, 0x800E
        ctx->r25 = S32(0X800E << 16);
            goto L_800BF07C;
    }
    // 0x800BF05C: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800BF060: lui         $at, 0x3F00
    ctx->r1 = S32(0X3F00 << 16);
    // 0x800BF064: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800BF068: sll         $t8, $v1, 1
    ctx->r24 = S32(ctx->r3 << 1);
    // 0x800BF06C: mul.s       $f0, $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f12.fl);
    // 0x800BF070: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800BF074: mul.s       $f2, $f2, $f12
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800BF078: nop

L_800BF07C:
    // 0x800BF07C: sll         $t0, $a0, 3
    ctx->r8 = S32(ctx->r4 << 3);
    // 0x800BF080: lw          $t9, 0x30D8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X30D8);
    // 0x800BF084: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x800BF088: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x800BF08C: addu        $a2, $t9, $t0
    ctx->r6 = ADD32(ctx->r25, ctx->r8);
    // 0x800BF090: lbu         $t1, 0xA($a2)
    ctx->r9 = MEM_BU(ctx->r6, 0XA);
    // 0x800BF094: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x800BF098: multu       $t1, $v1
    result = U64(U32(ctx->r9)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BF09C: lw          $t4, 0x3184($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X3184);
    // 0x800BF0A0: addiu       $s5, $zero, 0xFF
    ctx->r21 = ADD32(0, 0XFF);
    // 0x800BF0A4: mflo        $t2
    ctx->r10 = lo;
    // 0x800BF0A8: addu        $a1, $t2, $s0
    ctx->r5 = ADD32(ctx->r10, ctx->r16);
    // 0x800BF0AC: sll         $t3, $a1, 3
    ctx->r11 = S32(ctx->r5 << 3);
    // 0x800BF0B0: addu        $a3, $t3, $t4
    ctx->r7 = ADD32(ctx->r11, ctx->r12);
    // 0x800BF0B4: lbu         $t5, 0x0($a3)
    ctx->r13 = MEM_BU(ctx->r7, 0X0);
    // 0x800BF0B8: nop

    // 0x800BF0BC: beq         $s5, $t5, L_800BF38C
    if (ctx->r21 == ctx->r13) {
        // 0x800BF0C0: nop
    
            goto L_800BF38C;
    }
    // 0x800BF0C0: nop

    // 0x800BF0C4: lbu         $t6, 0xB($a2)
    ctx->r14 = MEM_BU(ctx->r6, 0XB);
    // 0x800BF0C8: mtc1        $a1, $f8
    ctx->f8.u32l = ctx->r5;
    // 0x800BF0CC: multu       $t6, $v1
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800BF0D0: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800BF0D4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BF0D8: lw          $t8, -0x5F30($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X5F30);
    // 0x800BF0DC: lui         $t9, 0x8013
    ctx->r25 = S32(0X8013 << 16);
    // 0x800BF0E0: mtc1        $t8, $f4
    ctx->f4.u32l = ctx->r24;
    // 0x800BF0E4: mul.s       $f16, $f10, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BF0E8: lw          $t9, -0x5F2C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X5F2C);
    // 0x800BF0EC: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800BF0F0: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x800BF0F4: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BF0F8: mtc1        $zero, $f26
    ctx->f26.u32l = 0;
    // 0x800BF0FC: mflo        $t7
    ctx->r15 = lo;
    // 0x800BF100: addu        $a0, $t7, $s1
    ctx->r4 = ADD32(ctx->r15, ctx->r17);
    // 0x800BF104: mtc1        $a0, $f8
    ctx->f8.u32l = ctx->r4;
    // 0x800BF108: add.s       $f30, $f6, $f16
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f30.fl = ctx->f6.fl + ctx->f16.fl;
    // 0x800BF10C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x800BF110: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BF114: addiu       $s4, $s4, 0x3190
    ctx->r20 = ADD32(ctx->r20, 0X3190);
    // 0x800BF118: or          $s2, $a3, $zero
    ctx->r18 = ctx->r7 | 0;
    // 0x800BF11C: mul.s       $f6, $f10, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f10.fl, ctx->f2.fl);
    // 0x800BF120: andi        $v0, $t5, 0xFF
    ctx->r2 = ctx->r13 & 0XFF;
    // 0x800BF124: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BF128: add.s       $f24, $f4, $f6
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f24.fl = ctx->f4.fl + ctx->f6.fl;
L_800BF12C:
    // 0x800BF12C: lw          $t1, 0x0($s4)
    ctx->r9 = MEM_W(ctx->r20, 0X0);
    // 0x800BF130: sll         $t0, $v0, 6
    ctx->r8 = S32(ctx->r2 << 6);
    // 0x800BF134: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    // 0x800BF138: lwc1        $f16, 0x0($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X0);
    // 0x800BF13C: nop

    // 0x800BF140: c.le.s      $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    c1cs = ctx->f16.fl <= ctx->f24.fl;
    // 0x800BF144: nop

    // 0x800BF148: bc1f        L_800BF36C
    if (!c1cs) {
        // 0x800BF14C: nop
    
            goto L_800BF36C;
    }
    // 0x800BF14C: nop

    // 0x800BF150: lwc1        $f18, 0x4($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X4);
    // 0x800BF154: nop

    // 0x800BF158: c.le.s      $f24, $f18
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f24.fl <= ctx->f18.fl;
    // 0x800BF15C: nop

    // 0x800BF160: bc1f        L_800BF36C
    if (!c1cs) {
        // 0x800BF164: nop
    
            goto L_800BF36C;
    }
    // 0x800BF164: nop

    // 0x800BF168: lwc1        $f8, 0x8($s1)
    ctx->f8.u32l = MEM_W(ctx->r17, 0X8);
    // 0x800BF16C: lwc1        $f10, 0xC($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0XC);
    // 0x800BF170: sub.s       $f20, $f30, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 30);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f30.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = ctx->f30.fl - ctx->f8.fl;
    // 0x800BF174: lwc1        $f16, 0x14($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X14);
    // 0x800BF178: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x800BF17C: sub.s       $f22, $f24, $f10
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f22.fl = ctx->f24.fl - ctx->f10.fl;
    // 0x800BF180: mul.s       $f6, $f22, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f22.fl);
    // 0x800BF184: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x800BF188: c.lt.s      $f12, $f16
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f12.fl < ctx->f16.fl;
    // 0x800BF18C: nop

    // 0x800BF190: bc1f        L_800BF36C
    if (!c1cs) {
        // 0x800BF194: nop
    
            goto L_800BF36C;
    }
    // 0x800BF194: nop

    // 0x800BF198: jal         0x800C9AD0
    // 0x800BF19C: nop

    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x800BF19C: nop

    after_0:
    // 0x800BF1A0: lbu         $t2, 0x30($s1)
    ctx->r10 = MEM_BU(ctx->r17, 0X30);
    // 0x800BF1A4: lhu         $s0, 0x1A($s1)
    ctx->r16 = MEM_HU(ctx->r17, 0X1A);
    // 0x800BF1A8: beq         $t2, $zero, L_800BF230
    if (ctx->r10 == 0) {
        // 0x800BF1AC: mov.s       $f2, $f0
        CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
            goto L_800BF230;
    }
    // 0x800BF1AC: mov.s       $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    ctx->f2.fl = ctx->f0.fl;
    // 0x800BF1B0: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800BF1B4: nop

    // 0x800BF1B8: bc1f        L_800BF1F8
    if (!c1cs) {
        // 0x800BF1BC: nop
    
            goto L_800BF1F8;
    }
    // 0x800BF1BC: nop

    // 0x800BF1C0: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF1C4: nop

    // 0x800BF1C8: mul.s       $f8, $f20, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f20.fl, ctx->f18.fl);
    // 0x800BF1CC: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x800BF1D0: nop

    // 0x800BF1D4: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x800BF1D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF1DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF1E0: nop

    // 0x800BF1E4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BF1E8: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x800BF1EC: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x800BF1F0: b           L_800BF2F8
    // 0x800BF1F4: subu        $s0, $s0, $t4
    ctx->r16 = SUB32(ctx->r16, ctx->r12);
        goto L_800BF2F8;
    // 0x800BF1F4: subu        $s0, $s0, $t4
    ctx->r16 = SUB32(ctx->r16, ctx->r12);
L_800BF1F8:
    // 0x800BF1F8: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF1FC: nop

    // 0x800BF200: mul.s       $f6, $f20, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f20.fl, ctx->f4.fl);
    // 0x800BF204: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800BF208: nop

    // 0x800BF20C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800BF210: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF214: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF218: nop

    // 0x800BF21C: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BF220: mfc1        $t6, $f16
    ctx->r14 = (int32_t)ctx->f16.u32l;
    // 0x800BF224: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800BF228: b           L_800BF2F8
    // 0x800BF22C: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
        goto L_800BF2F8;
    // 0x800BF22C: addu        $s0, $s0, $t6
    ctx->r16 = ADD32(ctx->r16, ctx->r14);
L_800BF230:
    // 0x800BF230: lbu         $t7, 0x31($s1)
    ctx->r15 = MEM_BU(ctx->r17, 0X31);
    // 0x800BF234: nop

    // 0x800BF238: beq         $t7, $zero, L_800BF2C0
    if (ctx->r15 == 0) {
        // 0x800BF23C: nop
    
            goto L_800BF2C0;
    }
    // 0x800BF23C: nop

    // 0x800BF240: c.lt.s      $f20, $f26
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 26);
    c1cs = ctx->f20.fl < ctx->f26.fl;
    // 0x800BF244: nop

    // 0x800BF248: bc1f        L_800BF288
    if (!c1cs) {
        // 0x800BF24C: nop
    
            goto L_800BF288;
    }
    // 0x800BF24C: nop

    // 0x800BF250: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF254: nop

    // 0x800BF258: mul.s       $f8, $f22, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f22.fl, ctx->f18.fl);
    // 0x800BF25C: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800BF260: nop

    // 0x800BF264: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800BF268: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF26C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF270: nop

    // 0x800BF274: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BF278: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x800BF27C: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800BF280: b           L_800BF2F8
    // 0x800BF284: subu        $s0, $s0, $t9
    ctx->r16 = SUB32(ctx->r16, ctx->r25);
        goto L_800BF2F8;
    // 0x800BF284: subu        $s0, $s0, $t9
    ctx->r16 = SUB32(ctx->r16, ctx->r25);
L_800BF288:
    // 0x800BF288: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF28C: nop

    // 0x800BF290: mul.s       $f6, $f22, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f22.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f22.fl, ctx->f4.fl);
    // 0x800BF294: cfc1        $t0, $FpcCsr
    ctx->r8 = get_cop1_cs();
    // 0x800BF298: nop

    // 0x800BF29C: ori         $at, $t0, 0x3
    ctx->r1 = ctx->r8 | 0X3;
    // 0x800BF2A0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF2A4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF2A8: nop

    // 0x800BF2AC: cvt.w.s     $f16, $f6
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    ctx->f16.u32l = CVT_W_S(ctx->f6.fl);
    // 0x800BF2B0: mfc1        $t1, $f16
    ctx->r9 = (int32_t)ctx->f16.u32l;
    // 0x800BF2B4: ctc1        $t0, $FpcCsr
    set_cop1_cs(ctx->r8);
    // 0x800BF2B8: b           L_800BF2F8
    // 0x800BF2BC: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
        goto L_800BF2F8;
    // 0x800BF2BC: addu        $s0, $s0, $t1
    ctx->r16 = ADD32(ctx->r16, ctx->r9);
L_800BF2C0:
    // 0x800BF2C0: lwc1        $f18, 0x20($s1)
    ctx->f18.u32l = MEM_W(ctx->r17, 0X20);
    // 0x800BF2C4: nop

    // 0x800BF2C8: mul.s       $f8, $f0, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = MUL_S(ctx->f0.fl, ctx->f18.fl);
    // 0x800BF2CC: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x800BF2D0: nop

    // 0x800BF2D4: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x800BF2D8: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF2DC: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF2E0: nop

    // 0x800BF2E4: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800BF2E8: mfc1        $t3, $f10
    ctx->r11 = (int32_t)ctx->f10.u32l;
    // 0x800BF2EC: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x800BF2F0: addu        $s0, $s0, $t3
    ctx->r16 = ADD32(ctx->r16, ctx->r11);
    // 0x800BF2F4: nop

L_800BF2F8:
    // 0x800BF2F8: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x800BF2FC: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800BF300: lwc1        $f16, 0x10($s1)
    ctx->f16.u32l = MEM_W(ctx->r17, 0X10);
    // 0x800BF304: mul.s       $f6, $f2, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f4.fl);
    // 0x800BF308: nop

    // 0x800BF30C: div.s       $f18, $f6, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f16.fl);
    // 0x800BF310: cfc1        $t4, $FpcCsr
    ctx->r12 = get_cop1_cs();
    // 0x800BF314: nop

    // 0x800BF318: ori         $at, $t4, 0x3
    ctx->r1 = ctx->r12 | 0X3;
    // 0x800BF31C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800BF320: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800BF324: nop

    // 0x800BF328: cvt.w.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    ctx->f8.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800BF32C: mfc1        $a0, $f8
    ctx->r4 = (int32_t)ctx->f8.u32l;
    // 0x800BF330: ctc1        $t4, $FpcCsr
    set_cop1_cs(ctx->r12);
    // 0x800BF334: sll         $t5, $a0, 16
    ctx->r13 = S32(ctx->r4 << 16);
    // 0x800BF338: jal         0x800707F8
    // 0x800BF33C: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    coss_f(rdram, ctx);
        goto after_1;
    // 0x800BF33C: sra         $a0, $t5, 16
    ctx->r4 = S32(SIGNED(ctx->r13) >> 16);
    after_1:
    // 0x800BF340: sll         $a0, $s0, 16
    ctx->r4 = S32(ctx->r16 << 16);
    // 0x800BF344: sra         $t7, $a0, 16
    ctx->r15 = S32(SIGNED(ctx->r4) >> 16);
    // 0x800BF348: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x800BF34C: jal         0x800707C4
    // 0x800BF350: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    sins_f(rdram, ctx);
        goto after_2;
    // 0x800BF350: or          $a0, $t7, $zero
    ctx->r4 = ctx->r15 | 0;
    after_2:
    // 0x800BF354: lwc1        $f10, 0x24($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X24);
    // 0x800BF358: nop

    // 0x800BF35C: mul.s       $f4, $f10, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f0.fl);
    // 0x800BF360: nop

    // 0x800BF364: mul.s       $f6, $f4, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f20.fl);
    // 0x800BF368: add.s       $f28, $f28, $f6
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f28.fl = ctx->f28.fl + ctx->f6.fl;
L_800BF36C:
    // 0x800BF36C: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x800BF370: slti        $at, $s3, 0x8
    ctx->r1 = SIGNED(ctx->r19) < 0X8 ? 1 : 0;
    // 0x800BF374: beq         $at, $zero, L_800BF38C
    if (ctx->r1 == 0) {
        // 0x800BF378: addiu       $s2, $s2, 0x1
        ctx->r18 = ADD32(ctx->r18, 0X1);
            goto L_800BF38C;
    }
    // 0x800BF378: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x800BF37C: lbu         $v0, 0x0($s2)
    ctx->r2 = MEM_BU(ctx->r18, 0X0);
    // 0x800BF380: nop

    // 0x800BF384: bne         $s5, $v0, L_800BF12C
    if (ctx->r21 != ctx->r2) {
        // 0x800BF388: nop
    
            goto L_800BF12C;
    }
    // 0x800BF388: nop

L_800BF38C:
    // 0x800BF38C: mov.s       $f0, $f28
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 28);
    ctx->f0.fl = ctx->f28.fl;
L_800BF390:
    // 0x800BF390: lw          $ra, 0x5C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X5C);
    // 0x800BF394: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x800BF398: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x800BF39C: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x800BF3A0: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800BF3A4: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x800BF3A8: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x800BF3AC: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x800BF3B0: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x800BF3B4: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x800BF3B8: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800BF3BC: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x800BF3C0: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x800BF3C4: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x800BF3C8: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x800BF3CC: lw          $s2, 0x4C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X4C);
    // 0x800BF3D0: lw          $s3, 0x50($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X50);
    // 0x800BF3D4: lw          $s4, 0x54($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X54);
    // 0x800BF3D8: lw          $s5, 0x58($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X58);
    // 0x800BF3DC: jr          $ra
    // 0x800BF3E0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x800BF3E0: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void debug_text_width(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B63F4: addiu       $sp, $sp, -0x138
    ctx->r29 = ADD32(ctx->r29, -0X138);
    // 0x800B63F8: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800B63FC: sw          $a0, 0x138($sp)
    MEM_W(0X138, ctx->r29) = ctx->r4;
    // 0x800B6400: sw          $a1, 0x13C($sp)
    MEM_W(0X13C, ctx->r29) = ctx->r5;
    // 0x800B6404: sw          $a2, 0x140($sp)
    MEM_W(0X140, ctx->r29) = ctx->r6;
    // 0x800B6408: sw          $a3, 0x144($sp)
    MEM_W(0X144, ctx->r29) = ctx->r7;
    // 0x800B640C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800B6410: jal         0x800B4A08
    // 0x800B6414: sw          $zero, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = 0;
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_0;
    // 0x800B6414: sw          $zero, 0x12C($sp)
    MEM_W(0X12C, ctx->r29) = 0;
    after_0:
    // 0x800B6418: lw          $a1, 0x138($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X138);
    // 0x800B641C: addiu       $a0, $sp, 0x2C
    ctx->r4 = ADD32(ctx->r29, 0X2C);
    // 0x800B6420: jal         0x800B4A40
    // 0x800B6424: addiu       $a2, $sp, 0x13C
    ctx->r6 = ADD32(ctx->r29, 0X13C);
    vsprintf_recomp(rdram, ctx);
        goto after_1;
    // 0x800B6424: addiu       $a2, $sp, 0x13C
    ctx->r6 = ADD32(ctx->r29, 0X13C);
    after_1:
    // 0x800B6428: jal         0x800B4A08
    // 0x800B642C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprintfSetSpacingCodes(rdram, ctx);
        goto after_2;
    // 0x800B642C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_2:
    // 0x800B6430: lbu         $t7, 0x2C($sp)
    ctx->r15 = MEM_BU(ctx->r29, 0X2C);
    // 0x800B6434: lw          $a3, 0x12C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X12C);
    // 0x800B6438: addiu       $t6, $sp, 0x2C
    ctx->r14 = ADD32(ctx->r29, 0X2C);
    // 0x800B643C: beq         $t7, $zero, L_800B652C
    if (ctx->r15 == 0) {
        // 0x800B6440: or          $v1, $t6, $zero
        ctx->r3 = ctx->r14 | 0;
            goto L_800B652C;
    }
    // 0x800B6440: or          $v1, $t6, $zero
    ctx->r3 = ctx->r14 | 0;
    // 0x800B6444: lbu         $a1, 0x0($t6)
    ctx->r5 = MEM_BU(ctx->r14, 0X0);
    // 0x800B6448: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800B644C: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800B6450: addiu       $a2, $a2, 0x7CCC
    ctx->r6 = ADD32(ctx->r6, 0X7CCC);
    // 0x800B6454: addiu       $t2, $t2, 0x2EF4
    ctx->r10 = ADD32(ctx->r10, 0X2EF4);
    // 0x800B6458: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800B645C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800B6460: addiu       $t1, $zero, 0x20
    ctx->r9 = ADD32(0, 0X20);
    // 0x800B6464: addiu       $t0, $zero, 0xA
    ctx->r8 = ADD32(0, 0XA);
    // 0x800B6468: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800B646C:
    // 0x800B646C: beq         $v0, $t0, L_800B651C
    if (ctx->r2 == ctx->r8) {
        // 0x800B6470: nop
    
            goto L_800B651C;
    }
    // 0x800B6470: nop

    // 0x800B6474: bne         $v0, $t1, L_800B6484
    if (ctx->r2 != ctx->r9) {
        // 0x800B6478: slti        $at, $v0, 0x40
        ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
            goto L_800B6484;
    }
    // 0x800B6478: slti        $at, $v0, 0x40
    ctx->r1 = SIGNED(ctx->r2) < 0X40 ? 1 : 0;
    // 0x800B647C: b           L_800B651C
    // 0x800B6480: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
        goto L_800B651C;
    // 0x800B6480: addiu       $a3, $a3, 0x6
    ctx->r7 = ADD32(ctx->r7, 0X6);
L_800B6484:
    // 0x800B6484: beq         $at, $zero, L_800B64AC
    if (ctx->r1 == 0) {
        // 0x800B6488: slti        $at, $v0, 0x60
        ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
            goto L_800B64AC;
    }
    // 0x800B6488: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
    // 0x800B648C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x800B6490: lbu         $t8, 0x0($v1)
    ctx->r24 = MEM_BU(ctx->r3, 0X0);
    // 0x800B6494: nop

    // 0x800B6498: addiu       $t9, $t8, -0x21
    ctx->r25 = ADD32(ctx->r24, -0X21);
    // 0x800B649C: sb          $t9, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r25;
    // 0x800B64A0: b           L_800B64F4
    // 0x800B64A4: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
        goto L_800B64F4;
    // 0x800B64A4: andi        $a1, $t9, 0xFF
    ctx->r5 = ctx->r25 & 0XFF;
    // 0x800B64A8: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
L_800B64AC:
    // 0x800B64AC: beq         $at, $zero, L_800B64D4
    if (ctx->r1 == 0) {
        // 0x800B64B0: slti        $at, $v0, 0x80
        ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
            goto L_800B64D4;
    }
    // 0x800B64B0: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
    // 0x800B64B4: sw          $t3, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r11;
    // 0x800B64B8: lbu         $t5, 0x0($v1)
    ctx->r13 = MEM_BU(ctx->r3, 0X0);
    // 0x800B64BC: nop

    // 0x800B64C0: addiu       $t7, $t5, -0x40
    ctx->r15 = ADD32(ctx->r13, -0X40);
    // 0x800B64C4: sb          $t7, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r15;
    // 0x800B64C8: b           L_800B64F4
    // 0x800B64CC: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
        goto L_800B64F4;
    // 0x800B64CC: andi        $a1, $t7, 0xFF
    ctx->r5 = ctx->r15 & 0XFF;
    // 0x800B64D0: slti        $at, $v0, 0x80
    ctx->r1 = SIGNED(ctx->r2) < 0X80 ? 1 : 0;
L_800B64D4:
    // 0x800B64D4: beq         $at, $zero, L_800B64F4
    if (ctx->r1 == 0) {
        // 0x800B64D8: nop
    
            goto L_800B64F4;
    }
    // 0x800B64D8: nop

    // 0x800B64DC: sw          $t4, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r12;
    // 0x800B64E0: lbu         $t6, 0x0($v1)
    ctx->r14 = MEM_BU(ctx->r3, 0X0);
    // 0x800B64E4: nop

    // 0x800B64E8: addiu       $t8, $t6, -0x60
    ctx->r24 = ADD32(ctx->r14, -0X60);
    // 0x800B64EC: sb          $t8, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r24;
    // 0x800B64F0: andi        $a1, $t8, 0xFF
    ctx->r5 = ctx->r24 & 0XFF;
L_800B64F4:
    // 0x800B64F4: lw          $t9, 0x0($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X0);
    // 0x800B64F8: sll         $t6, $a1, 1
    ctx->r14 = S32(ctx->r5 << 1);
    // 0x800B64FC: sll         $t5, $t9, 6
    ctx->r13 = S32(ctx->r25 << 6);
    // 0x800B6500: addu        $t7, $t2, $t5
    ctx->r15 = ADD32(ctx->r10, ctx->r13);
    // 0x800B6504: addu        $v0, $t7, $t6
    ctx->r2 = ADD32(ctx->r15, ctx->r14);
    // 0x800B6508: lbu         $t8, 0x1($v0)
    ctx->r24 = MEM_BU(ctx->r2, 0X1);
    // 0x800B650C: lbu         $a0, 0x0($v0)
    ctx->r4 = MEM_BU(ctx->r2, 0X0);
    // 0x800B6510: addu        $t9, $a3, $t8
    ctx->r25 = ADD32(ctx->r7, ctx->r24);
    // 0x800B6514: subu        $a3, $t9, $a0
    ctx->r7 = SUB32(ctx->r25, ctx->r4);
    // 0x800B6518: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
L_800B651C:
    // 0x800B651C: lbu         $a1, 0x1($v1)
    ctx->r5 = MEM_BU(ctx->r3, 0X1);
    // 0x800B6520: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800B6524: bne         $a1, $zero, L_800B646C
    if (ctx->r5 != 0) {
        // 0x800B6528: or          $v0, $a1, $zero
        ctx->r2 = ctx->r5 | 0;
            goto L_800B646C;
    }
    // 0x800B6528: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800B652C:
    // 0x800B652C: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800B6530: addiu       $sp, $sp, 0x138
    ctx->r29 = ADD32(ctx->r29, 0X138);
    // 0x800B6534: jr          $ra
    // 0x800B6538: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
    return;
    // 0x800B6538: or          $v0, $a3, $zero
    ctx->r2 = ctx->r7 | 0;
;}
RECOMP_FUNC void transition_init_blank(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C2640: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800C2644: lui         $a0, 0x8013
    ctx->r4 = S32(0X8013 << 16);
    // 0x800C2648: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C264C: lui         $a1, 0x8013
    ctx->r5 = S32(0X8013 << 16);
    // 0x800C2650: addiu       $a1, $a1, -0x58C0
    ctx->r5 = ADD32(ctx->r5, -0X58C0);
    // 0x800C2654: addiu       $v1, $v1, -0x58C8
    ctx->r3 = ADD32(ctx->r3, -0X58C8);
    // 0x800C2658: addiu       $a0, $a0, -0x58C4
    ctx->r4 = ADD32(ctx->r4, -0X58C4);
    // 0x800C265C: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x800C2660: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x800C2664: lw          $t0, 0x0($a1)
    ctx->r8 = MEM_W(ctx->r5, 0X0);
    // 0x800C2668: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x800C266C: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2670: sll         $t1, $t0, 16
    ctx->r9 = S32(ctx->r8 << 16);
    // 0x800C2674: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x800C2678: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800C267C: sw          $t1, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r9;
    // 0x800C2680: addiu       $t2, $zero, 0xFF
    ctx->r10 = ADD32(0, 0XFF);
    // 0x800C2684: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2688: sb          $t2, -0x58C9($at)
    MEM_B(-0X58C9, ctx->r1) = ctx->r10;
    // 0x800C268C: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C2690: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C2694: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C2698: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x800C269C: swc1        $f4, -0x58B0($at)
    MEM_W(-0X58B0, ctx->r1) = ctx->f4.u32l;
    // 0x800C26A0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C26A4: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C26A8: lbu         $t3, -0x58CC($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X58CC);
    // 0x800C26AC: swc1        $f6, -0x58AC($at)
    MEM_W(-0X58AC, ctx->r1) = ctx->f6.u32l;
    // 0x800C26B0: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x800C26B4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x800C26B8: lhu         $v0, 0x31B0($v0)
    ctx->r2 = MEM_HU(ctx->r2, 0X31B0);
    // 0x800C26BC: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800C26C0: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800C26C4: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800C26C8: lui         $t8, 0x8013
    ctx->r24 = S32(0X8013 << 16);
    // 0x800C26CC: bne         $v0, $zero, L_800C26D8
    if (ctx->r2 != 0) {
        // 0x800C26D0: nop
    
            goto L_800C26D8;
    }
    // 0x800C26D0: nop

    // 0x800C26D4: break       7
    do_break(2148280020);
L_800C26D8:
    // 0x800C26D8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C26DC: bne         $v0, $at, L_800C26F0
    if (ctx->r2 != ctx->r1) {
        // 0x800C26E0: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C26F0;
    }
    // 0x800C26E0: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C26E4: bne         $t6, $at, L_800C26F0
    if (ctx->r14 != ctx->r1) {
        // 0x800C26E8: nop
    
            goto L_800C26F0;
    }
    // 0x800C26E8: nop

    // 0x800C26EC: break       6
    do_break(2148280044);
L_800C26F0:
    // 0x800C26F0: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C26F4: lbu         $t8, -0x58CB($t8)
    ctx->r24 = MEM_BU(ctx->r24, -0X58CB);
    // 0x800C26F8: lui         $t3, 0x8013
    ctx->r11 = S32(0X8013 << 16);
    // 0x800C26FC: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800C2700: lbu         $t3, -0x58CA($t3)
    ctx->r11 = MEM_BU(ctx->r11, -0X58CA);
    // 0x800C2704: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x800C2708: sll         $t4, $t3, 16
    ctx->r12 = S32(ctx->r11 << 16);
    // 0x800C270C: mflo        $t7
    ctx->r15 = lo;
    // 0x800C2710: sw          $t7, -0x58BC($at)
    MEM_W(-0X58BC, ctx->r1) = ctx->r15;
    // 0x800C2714: lw          $t0, 0x0($a0)
    ctx->r8 = MEM_W(ctx->r4, 0X0);
    // 0x800C2718: nop

    // 0x800C271C: subu        $t1, $t9, $t0
    ctx->r9 = SUB32(ctx->r25, ctx->r8);
    // 0x800C2720: div         $zero, $t1, $v0
    lo = S32(S64(S32(ctx->r9)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r9)) % S64(S32(ctx->r2)));
    // 0x800C2724: bne         $v0, $zero, L_800C2730
    if (ctx->r2 != 0) {
        // 0x800C2728: nop
    
            goto L_800C2730;
    }
    // 0x800C2728: nop

    // 0x800C272C: break       7
    do_break(2148280108);
L_800C2730:
    // 0x800C2730: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C2734: bne         $v0, $at, L_800C2748
    if (ctx->r2 != ctx->r1) {
        // 0x800C2738: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C2748;
    }
    // 0x800C2738: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C273C: bne         $t1, $at, L_800C2748
    if (ctx->r9 != ctx->r1) {
        // 0x800C2740: nop
    
            goto L_800C2748;
    }
    // 0x800C2740: nop

    // 0x800C2744: break       6
    do_break(2148280132);
L_800C2748:
    // 0x800C2748: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C274C: mflo        $t2
    ctx->r10 = lo;
    // 0x800C2750: sw          $t2, -0x58B8($at)
    MEM_W(-0X58B8, ctx->r1) = ctx->r10;
    // 0x800C2754: lw          $t5, 0x0($a1)
    ctx->r13 = MEM_W(ctx->r5, 0X0);
    // 0x800C2758: nop

    // 0x800C275C: subu        $t6, $t4, $t5
    ctx->r14 = SUB32(ctx->r12, ctx->r13);
    // 0x800C2760: div         $zero, $t6, $v0
    lo = S32(S64(S32(ctx->r14)) / S64(S32(ctx->r2))); hi = S32(S64(S32(ctx->r14)) % S64(S32(ctx->r2)));
    // 0x800C2764: bne         $v0, $zero, L_800C2770
    if (ctx->r2 != 0) {
        // 0x800C2768: nop
    
            goto L_800C2770;
    }
    // 0x800C2768: nop

    // 0x800C276C: break       7
    do_break(2148280172);
L_800C2770:
    // 0x800C2770: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800C2774: bne         $v0, $at, L_800C2788
    if (ctx->r2 != ctx->r1) {
        // 0x800C2778: lui         $at, 0x8000
        ctx->r1 = S32(0X8000 << 16);
            goto L_800C2788;
    }
    // 0x800C2778: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x800C277C: bne         $t6, $at, L_800C2788
    if (ctx->r14 != ctx->r1) {
        // 0x800C2780: nop
    
            goto L_800C2788;
    }
    // 0x800C2780: nop

    // 0x800C2784: break       6
    do_break(2148280196);
L_800C2788:
    // 0x800C2788: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C278C: mflo        $t7
    ctx->r15 = lo;
    // 0x800C2790: sw          $t7, -0x58B4($at)
    MEM_W(-0X58B4, ctx->r1) = ctx->r15;
    // 0x800C2794: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C2798: jr          $ra
    // 0x800C279C: sw          $t8, 0x31AC($at)
    MEM_W(0X31AC, ctx->r1) = ctx->r24;
    return;
    // 0x800C279C: sw          $t8, 0x31AC($at)
    MEM_W(0X31AC, ctx->r1) = ctx->r24;
;}
RECOMP_FUNC void trackmenu_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 2U, dkr_legacy_fields, 0U); }
    // 0x80090918: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8009091C: lw          $v1, -0xB84($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB84);
    // 0x80090920: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x80090924: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80090928: sw          $a0, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r4;
    // 0x8009092C: blez        $v1, L_80090B4C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80090930: sw          $v1, 0x24($sp)
        MEM_W(0X24, ctx->r29) = ctx->r3;
            goto L_80090B4C;
    }
    // 0x80090930: sw          $v1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r3;
    // 0x80090934: lui         $at, 0x4080
    ctx->r1 = S32(0X4080 << 16);
    // 0x80090938: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x8009093C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090940: lwc1        $f4, 0x69E8($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69E8);
    // 0x80090944: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090948: lwc1        $f6, 0x69DC($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X69DC);
    // 0x8009094C: lui         $at, 0xC080
    ctx->r1 = S32(0XC080 << 16);
    // 0x80090950: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x80090954: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80090958: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x8009095C: nop

    // 0x80090960: bc1t        L_800909B0
    if (c1cs) {
        // 0x80090964: nop
    
            goto L_800909B0;
    }
    // 0x80090964: nop

    // 0x80090968: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8009096C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090970: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x80090974: nop

    // 0x80090978: bc1t        L_800909B0
    if (c1cs) {
        // 0x8009097C: nop
    
            goto L_800909B0;
    }
    // 0x8009097C: nop

    // 0x80090980: lwc1        $f8, 0x69EC($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X69EC);
    // 0x80090984: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090988: lwc1        $f10, 0x69E4($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X69E4);
    // 0x8009098C: nop

    // 0x80090990: sub.s       $f0, $f8, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f0.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80090994: c.lt.s      $f2, $f0
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f2.fl < ctx->f0.fl;
    // 0x80090998: nop

    // 0x8009099C: bc1t        L_800909B0
    if (c1cs) {
        // 0x800909A0: nop
    
            goto L_800909B0;
    }
    // 0x800909A0: nop

    // 0x800909A4: c.lt.s      $f0, $f12
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 12);
    c1cs = ctx->f0.fl < ctx->f12.fl;
    // 0x800909A8: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x800909AC: bc1f        L_800909C0
    if (!c1cs) {
        // 0x800909B0: lui         $at, 0x800E
        ctx->r1 = S32(0X800E << 16);
            goto L_800909C0;
    }
L_800909B0:
    // 0x800909B0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800909B4: sw          $t6, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r14;
    // 0x800909B8: b           L_800909E8
    // 0x800909BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
        goto L_800909E8;
    // 0x800909BC: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800909C0:
    // 0x800909C0: lw          $t7, 0x1E1C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X1E1C);
    // 0x800909C4: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800909C8: beq         $t7, $zero, L_800909EC
    if (ctx->r15 == 0) {
        // 0x800909CC: addiu       $t1, $v1, -0x1
        ctx->r9 = ADD32(ctx->r3, -0X1);
            goto L_800909EC;
    }
    // 0x800909CC: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
    // 0x800909D0: jal         0x80001D04
    // 0x800909D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_0;
    // 0x800909D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_0:
    // 0x800909D8: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800909DC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800909E0: lw          $v1, -0xB84($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB84);
    // 0x800909E4: sw          $zero, 0x1E1C($at)
    MEM_W(0X1E1C, ctx->r1) = 0;
L_800909E8:
    // 0x800909E8: addiu       $t1, $v1, -0x1
    ctx->r9 = ADD32(ctx->r3, -0X1);
L_800909EC:
    // 0x800909EC: slti        $at, $t1, 0x15
    ctx->r1 = SIGNED(ctx->r9) < 0X15 ? 1 : 0;
    // 0x800909F0: bne         $at, $zero, L_800909FC
    if (ctx->r1 != 0) {
        // 0x800909F4: addiu       $t2, $zero, 0xA0
        ctx->r10 = ADD32(0, 0XA0);
            goto L_800909FC;
    }
    // 0x800909F4: addiu       $t2, $zero, 0xA0
    ctx->r10 = ADD32(0, 0XA0);
    // 0x800909F8: addiu       $t1, $zero, 0x14
    ctx->r9 = ADD32(0, 0X14);
L_800909FC:
    // 0x800909FC: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x80090A00: lw          $t4, 0x6478($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6478);
    // 0x80090A04: slti        $at, $t1, 0x14
    ctx->r1 = SIGNED(ctx->r9) < 0X14 ? 1 : 0;
    // 0x80090A08: beq         $at, $zero, L_80090A9C
    if (ctx->r1 == 0) {
        // 0x80090A0C: or          $t0, $t4, $zero
        ctx->r8 = ctx->r12 | 0;
            goto L_80090A9C;
    }
    // 0x80090A0C: or          $t0, $t4, $zero
    ctx->r8 = ctx->r12 | 0;
    // 0x80090A10: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090A14: lwc1        $f16, 0x69E8($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X69E8);
    // 0x80090A18: addiu       $t8, $zero, 0xA0
    ctx->r24 = ADD32(0, 0XA0);
    // 0x80090A1C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x80090A20: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090A24: lwc1        $f18, 0x69DC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X69DC);
    // 0x80090A28: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80090A2C: sub.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x80090A30: add.s       $f10, $f8, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f4.fl;
    // 0x80090A34: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80090A38: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80090A3C: nop

    // 0x80090A40: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80090A44: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80090A48: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090A4C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090A50: cvt.w.s     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = CVT_W_S(ctx->f10.fl);
    // 0x80090A54: lwc1        $f18, 0x69EC($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X69EC);
    // 0x80090A58: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80090A5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090A60: lwc1        $f6, 0x69E4($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X69E4);
    // 0x80090A64: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090A68: mfc1        $t2, $f16
    ctx->r10 = (int32_t)ctx->f16.u32l;
    // 0x80090A6C: sub.s       $f8, $f18, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f18.fl - ctx->f6.fl;
    // 0x80090A70: sub.s       $f16, $f10, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f8.fl;
    // 0x80090A74: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x80090A78: nop

    // 0x80090A7C: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x80090A80: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80090A84: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090A88: nop

    // 0x80090A8C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x80090A90: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x80090A94: mfc1        $t0, $f18
    ctx->r8 = (int32_t)ctx->f18.u32l;
    // 0x80090A98: nop

L_80090A9C:
    // 0x80090A9C: addiu       $t6, $t1, 0x14
    ctx->r14 = ADD32(ctx->r9, 0X14);
    // 0x80090AA0: multu       $t6, $t4
    result = U64(U32(ctx->r14)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80090AA4: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x80090AA8: sll         $v1, $t1, 2
    ctx->r3 = S32(ctx->r9 << 2);
    // 0x80090AAC: subu        $a1, $t2, $v1
    ctx->r5 = SUB32(ctx->r10, ctx->r3);
    // 0x80090AB0: addu        $a3, $v1, $t2
    ctx->r7 = ADD32(ctx->r3, ctx->r10);
    // 0x80090AB4: addiu       $a3, $a3, 0x50
    ctx->r7 = ADD32(ctx->r7, 0X50);
    // 0x80090AB8: addiu       $a1, $a1, -0x50
    ctx->r5 = ADD32(ctx->r5, -0X50);
    // 0x80090ABC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80090AC0: sw          $t1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r9;
    // 0x80090AC4: mflo        $v0
    ctx->r2 = lo;
    // 0x80090AC8: nop

    // 0x80090ACC: nop

    // 0x80090AD0: div         $zero, $v0, $at
    lo = S32(S64(S32(ctx->r2)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r2)) % S64(S32(ctx->r1)));
    // 0x80090AD4: mflo        $t7
    ctx->r15 = lo;
    // 0x80090AD8: addu        $t3, $t7, $t0
    ctx->r11 = ADD32(ctx->r15, ctx->r8);
    // 0x80090ADC: subu        $a2, $t0, $t7
    ctx->r6 = SUB32(ctx->r8, ctx->r15);
    // 0x80090AE0: jal         0x80066940
    // 0x80090AE4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    viewport_menu_set(rdram, ctx);
        goto after_1;
    // 0x80090AE4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    after_1:
    extern void dkr_track_select_fullscreen_preview(uint8_t*, recomp_context*); dkr_track_select_fullscreen_preview(rdram, ctx);
    // 0x80090AE8: lw          $t1, 0x3C($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X3C);
    // 0x80090AEC: lui         $at, 0x41A0
    ctx->r1 = S32(0X41A0 << 16);
    // 0x80090AF0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x80090AF4: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80090AF8: cvt.s.w     $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    ctx->f4.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80090AFC: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80090B00: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x80090B04: div.s       $f8, $f4, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f10.fl);
    // 0x80090B08: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80090B0C: addiu       $v1, $v1, -0xAF0
    ctx->r3 = ADD32(ctx->r3, -0XAF0);
    // 0x80090B10: lwc1        $f18, 0x88($v1)
    ctx->f18.u32l = MEM_W(ctx->r3, 0X88);
    // 0x80090B14: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80090B18: addiu       $v0, $v0, -0x8A4
    ctx->r2 = ADD32(ctx->r2, -0X8A4);
    // 0x80090B1C: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80090B20: add.s       $f0, $f16, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f0.fl = ctx->f16.fl + ctx->f8.fl;
    // 0x80090B24: mul.s       $f6, $f18, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f0.fl);
    // 0x80090B28: swc1        $f6, 0x88($t8)
    MEM_W(0X88, ctx->r24) = ctx->f6.u32l;
    // 0x80090B2C: lwc1        $f4, 0xC8($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0XC8);
    // 0x80090B30: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80090B34: mul.s       $f10, $f4, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = MUL_S(ctx->f4.fl, ctx->f0.fl);
    // 0x80090B38: swc1        $f10, 0xC8($t9)
    MEM_W(0XC8, ctx->r25) = ctx->f10.u32l;
    // 0x80090B3C: lwc1        $f16, 0xA8($v1)
    ctx->f16.u32l = MEM_W(ctx->r3, 0XA8);
    // 0x80090B40: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x80090B44: mul.s       $f8, $f16, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f16.fl, ctx->f0.fl);
    // 0x80090B48: swc1        $f8, 0xA8($t5)
    MEM_W(0XA8, ctx->r13) = ctx->f8.u32l;
L_80090B4C:
    // 0x80090B4C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80090B50: jal         0x80066818
    // 0x80090B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camEnableUserView(rdram, ctx);
        goto after_2;
    // 0x80090B54: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x80090B58: jal         0x800C73E0
    // 0x80090B5C: nop

    bgload_active(rdram, ctx);
        goto after_3;
    // 0x80090B5C: nop

    after_3:
    // 0x80090B60: bne         $v0, $zero, L_80090CA8
    if (ctx->r2 != 0) {
        // 0x80090B64: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_80090CA8;
    }
    // 0x80090B64: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80090B68: lw          $v1, -0xB84($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB84);
    // 0x80090B6C: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80090B70: bgez        $v1, L_80090B94
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80090B74: addiu       $t2, $t2, 0x69C8
        ctx->r10 = ADD32(ctx->r10, 0X69C8);
            goto L_80090B94;
    }
    // 0x80090B74: addiu       $t2, $t2, 0x69C8
    ctx->r10 = ADD32(ctx->r10, 0X69C8);
    // 0x80090B78: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80090B7C: lw          $t7, 0x48($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X48);
    // 0x80090B80: addiu       $v0, $v0, -0x8A0
    ctx->r2 = ADD32(ctx->r2, -0X8A0);
    // 0x80090B84: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80090B88: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x80090B8C: subu        $t9, $t6, $t8
    ctx->r25 = SUB32(ctx->r14, ctx->r24);
    // 0x80090B90: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
L_80090B94:
    // 0x80090B94: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80090B98: lw          $t7, 0x69F4($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X69F4);
    // 0x80090B9C: lw          $t5, 0x0($t2)
    ctx->r13 = MEM_W(ctx->r10, 0X0);
    // 0x80090BA0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80090BA4: bne         $t5, $t7, L_80090BE4
    if (ctx->r13 != ctx->r15) {
        // 0x80090BA8: addiu       $a3, $a3, 0x69CC
        ctx->r7 = ADD32(ctx->r7, 0X69CC);
            goto L_80090BE4;
    }
    // 0x80090BA8: addiu       $a3, $a3, 0x69CC
    ctx->r7 = ADD32(ctx->r7, 0X69CC);
    // 0x80090BAC: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80090BB0: lw          $t8, 0x69F8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X69F8);
    // 0x80090BB4: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x80090BB8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80090BBC: bne         $t6, $t8, L_80090BE4
    if (ctx->r14 != ctx->r24) {
        // 0x80090BC0: addiu       $v0, $v0, 0x63D8
        ctx->r2 = ADD32(ctx->r2, 0X63D8);
            goto L_80090BE4;
    }
    // 0x80090BC0: addiu       $v0, $v0, 0x63D8
    ctx->r2 = ADD32(ctx->r2, 0X63D8);
    // 0x80090BC4: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x80090BC8: lw          $t5, 0x48($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X48);
    // 0x80090BCC: nop

    // 0x80090BD0: subu        $t7, $t9, $t5
    ctx->r15 = SUB32(ctx->r25, ctx->r13);
    // 0x80090BD4: bgez        $t7, L_80090C0C
    if (SIGNED(ctx->r15) >= 0) {
        // 0x80090BD8: sw          $t7, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r15;
            goto L_80090C0C;
    }
    // 0x80090BD8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x80090BDC: b           L_80090C0C
    // 0x80090BE0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
        goto L_80090C0C;
    // 0x80090BE0: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_80090BE4:
    // 0x80090BE4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80090BE8: addiu       $v0, $v0, 0x63D8
    ctx->r2 = ADD32(ctx->r2, 0X63D8);
    // 0x80090BEC: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x80090BF0: lw          $t9, 0x48($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X48);
    // 0x80090BF4: addiu       $t6, $zero, 0x20
    ctx->r14 = ADD32(0, 0X20);
    // 0x80090BF8: addu        $t5, $t8, $t9
    ctx->r13 = ADD32(ctx->r24, ctx->r25);
    // 0x80090BFC: slti        $at, $t5, 0x21
    ctx->r1 = SIGNED(ctx->r13) < 0X21 ? 1 : 0;
    // 0x80090C00: bne         $at, $zero, L_80090C0C
    if (ctx->r1 != 0) {
        // 0x80090C04: sw          $t5, 0x0($v0)
        MEM_W(0X0, ctx->r2) = ctx->r13;
            goto L_80090C0C;
    }
    // 0x80090C04: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x80090C08: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_80090C0C:
    // 0x80090C0C: slti        $at, $v1, -0x16
    ctx->r1 = SIGNED(ctx->r3) < -0X16 ? 1 : 0;
    // 0x80090C10: beq         $at, $zero, L_80090C34
    if (ctx->r1 == 0) {
        // 0x80090C14: slti        $at, $v1, 0x1F
        ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
            goto L_80090C34;
    }
    // 0x80090C14: slti        $at, $v1, 0x1F
    ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
    // 0x80090C18: jal         0x80078AAC
    // 0x80090C1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    bgdraw_set_func(rdram, ctx);
        goto after_4;
    // 0x80090C1C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_4:
    // 0x80090C20: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80090C24: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80090C28: lw          $v1, -0xB84($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB84);
    // 0x80090C2C: sw          $zero, 0x97C($at)
    MEM_W(0X97C, ctx->r1) = 0;
    // 0x80090C30: slti        $at, $v1, 0x1F
    ctx->r1 = SIGNED(ctx->r3) < 0X1F ? 1 : 0;
L_80090C34:
    // 0x80090C34: bne         $at, $zero, L_80090C84
    if (ctx->r1 != 0) {
        // 0x80090C38: slti        $at, $v1, -0x1E
        ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
            goto L_80090C84;
    }
    // 0x80090C38: slti        $at, $v1, -0x1E
    ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
    // 0x80090C3C: jal         0x8009EC60
    // 0x80090C40: nop

    is_adventure_two_unlocked(rdram, ctx);
        goto after_5;
    // 0x80090C40: nop

    after_5:
    // 0x80090C44: beq         $v0, $zero, L_80090C68
    if (ctx->r2 == 0) {
        // 0x80090C48: lui         $t8, 0x8012
        ctx->r24 = S32(0X8012 << 16);
            goto L_80090C68;
    }
    // 0x80090C48: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80090C4C: lw          $t8, 0x69C8($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X69C8);
    // 0x80090C50: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80090C54: beq         $t8, $at, L_80090C68
    if (ctx->r24 == ctx->r1) {
        // 0x80090C58: addiu       $t9, $zero, -0x1
        ctx->r25 = ADD32(0, -0X1);
            goto L_80090C68;
    }
    // 0x80090C58: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x80090C5C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090C60: b           L_80090C70
    // 0x80090C64: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
        goto L_80090C70;
    // 0x80090C64: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
L_80090C68:
    // 0x80090C68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090C6C: sw          $zero, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = 0;
L_80090C70:
    // 0x80090C70: jal         0x8008F00C
    // 0x80090C74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    trackmenu_assets(rdram, ctx);
        goto after_6;
    // 0x80090C74: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x80090C78: b           L_80090CAC
    // 0x80090C7C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
        goto L_80090CAC;
    // 0x80090C7C: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80090C80: slti        $at, $v1, -0x1E
    ctx->r1 = SIGNED(ctx->r3) < -0X1E ? 1 : 0;
L_80090C84:
    // 0x80090C84: beq         $at, $zero, L_80090CAC
    if (ctx->r1 == 0) {
        // 0x80090C88: lw          $t5, 0x24($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X24);
            goto L_80090CAC;
    }
    // 0x80090C88: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
    // 0x80090C8C: jal         0x800C0180
    // 0x80090C90: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_7;
    // 0x80090C90: nop

    after_7:
    // 0x80090C94: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80090C98: jal         0x80066894
    // 0x80090C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    camDisableUserView(rdram, ctx);
        goto after_8;
    // 0x80090C9C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x80090CA0: jal         0x8008F00C
    // 0x80090CA4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    trackmenu_assets(rdram, ctx);
        goto after_9;
    // 0x80090CA4: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    after_9:
L_80090CA8:
    // 0x80090CA8: lw          $t5, 0x24($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X24);
L_80090CAC:
    // 0x80090CAC: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80090CB0: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x80090CB4: addiu       $t2, $t2, 0x69C8
    ctx->r10 = ADD32(ctx->r10, 0X69C8);
    // 0x80090CB8: bne         $t5, $zero, L_80090EC8
    if (ctx->r13 != 0) {
        // 0x80090CBC: addiu       $a3, $a3, 0x69CC
        ctx->r7 = ADD32(ctx->r7, 0X69CC);
            goto L_80090EC8;
    }
    // 0x80090CBC: addiu       $a3, $a3, 0x69CC
    ctx->r7 = ADD32(ctx->r7, 0X69CC);
    // 0x80090CC0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80090CC4: lh          $t7, 0x6918($t7)
    ctx->r15 = MEM_H(ctx->r15, 0X6918);
    // 0x80090CC8: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x80090CCC: bne         $v1, $t7, L_80090CDC
    if (ctx->r3 != ctx->r15) {
        // 0x80090CD0: lui         $v0, 0x8012
        ctx->r2 = S32(0X8012 << 16);
            goto L_80090CDC;
    }
    // 0x80090CD0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80090CD4: b           L_80090CE0
    // 0x80090CD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
        goto L_80090CE0;
    // 0x80090CD8: addiu       $a1, $zero, 0x3
    ctx->r5 = ADD32(0, 0X3);
L_80090CDC:
    // 0x80090CDC: addiu       $a1, $zero, 0x4
    ctx->r5 = ADD32(0, 0X4);
L_80090CE0:
    // 0x80090CE0: lw          $v0, 0x67E8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X67E8);
    // 0x80090CE4: nop

    // 0x80090CE8: andi        $t6, $v0, 0x9000
    ctx->r14 = ctx->r2 & 0X9000;
    // 0x80090CEC: beq         $t6, $zero, L_80090D38
    if (ctx->r14 == 0) {
        // 0x80090CF0: andi        $t5, $v0, 0x4000
        ctx->r13 = ctx->r2 & 0X4000;
            goto L_80090D38;
    }
    // 0x80090CF0: andi        $t5, $v0, 0x4000
    ctx->r13 = ctx->r2 & 0X4000;
    // 0x80090CF4: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80090CF8: lw          $v0, -0xB3C($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB3C);
    // 0x80090CFC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80090D00: beq         $v1, $v0, L_80090D28
    if (ctx->r3 == ctx->r2) {
        // 0x80090D04: addiu       $a0, $zero, 0x6A
        ctx->r4 = ADD32(0, 0X6A);
            goto L_80090D28;
    }
    // 0x80090D04: addiu       $a0, $zero, 0x6A
    ctx->r4 = ADD32(0, 0X6A);
    // 0x80090D08: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80090D0C: sw          $t8, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r24;
    // 0x80090D10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80090D14: sw          $v0, -0xB2C($at)
    MEM_W(-0XB2C, ctx->r1) = ctx->r2;
    // 0x80090D18: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80090D1C: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80090D20: b           L_80090EC8
    // 0x80090D24: sw          $t9, 0x1E1C($at)
    MEM_W(0X1E1C, ctx->r1) = ctx->r25;
        goto L_80090EC8;
    // 0x80090D24: sw          $t9, 0x1E1C($at)
    MEM_W(0X1E1C, ctx->r1) = ctx->r25;
L_80090D28:
    // 0x80090D28: jal         0x80001D04
    // 0x80090D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x80090D2C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x80090D30: b           L_80090ECC
    // 0x80090D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
        goto L_80090ECC;
    // 0x80090D34: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80090D38:
    // 0x80090D38: beq         $t5, $zero, L_80090D6C
    if (ctx->r13 == 0) {
        // 0x80090D3C: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80090D6C;
    }
    // 0x80090D3C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80090D40: jal         0x800C0180
    // 0x80090D44: nop

    disable_new_screen_transitions(rdram, ctx);
        goto after_11;
    // 0x80090D44: nop

    after_11:
    // 0x80090D48: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80090D4C: jal         0x800C01D8
    // 0x80090D50: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_12;
    // 0x80090D50: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_12:
    // 0x80090D54: jal         0x800C0170
    // 0x80090D58: nop

    enable_new_screen_transitions(rdram, ctx);
        goto after_13;
    // 0x80090D58: nop

    after_13:
    // 0x80090D5C: addiu       $t7, $zero, -0x1
    ctx->r15 = ADD32(0, -0X1);
    // 0x80090D60: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80090D64: b           L_80090EC8
    // 0x80090D68: sw          $t7, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r15;
        goto L_80090EC8;
    // 0x80090D68: sw          $t7, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r15;
L_80090D6C:
    // 0x80090D6C: lw          $v0, 0x0($t2)
    ctx->r2 = MEM_W(ctx->r10, 0X0);
    // 0x80090D70: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80090D74: lh          $a0, 0x6820($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6820);
    // 0x80090D78: or          $t0, $v0, $zero
    ctx->r8 = ctx->r2 | 0;
    // 0x80090D7C: bgez        $a0, L_80090D94
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80090D80: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_80090D94;
    }
    // 0x80090D80: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x80090D84: blez        $v0, L_80090D94
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80090D88: addiu       $t6, $v0, -0x1
        ctx->r14 = ADD32(ctx->r2, -0X1);
            goto L_80090D94;
    }
    // 0x80090D88: addiu       $t6, $v0, -0x1
    ctx->r14 = ADD32(ctx->r2, -0X1);
    // 0x80090D8C: sw          $t6, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r14;
    // 0x80090D90: or          $v0, $t6, $zero
    ctx->r2 = ctx->r14 | 0;
L_80090D94:
    // 0x80090D94: blez        $a0, L_80090DB0
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80090D98: addiu       $a2, $zero, 0x4
        ctx->r6 = ADD32(0, 0X4);
            goto L_80090DB0;
    }
    // 0x80090D98: addiu       $a2, $zero, 0x4
    ctx->r6 = ADD32(0, 0X4);
    // 0x80090D9C: slti        $at, $v0, 0x5
    ctx->r1 = SIGNED(ctx->r2) < 0X5 ? 1 : 0;
    // 0x80090DA0: beq         $at, $zero, L_80090DB0
    if (ctx->r1 == 0) {
        // 0x80090DA4: addiu       $t8, $v0, 0x1
        ctx->r24 = ADD32(ctx->r2, 0X1);
            goto L_80090DB0;
    }
    // 0x80090DA4: addiu       $t8, $v0, 0x1
    ctx->r24 = ADD32(ctx->r2, 0X1);
    // 0x80090DA8: sw          $t8, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r24;
    // 0x80090DAC: or          $v0, $t8, $zero
    ctx->r2 = ctx->r24 | 0;
L_80090DB0:
    // 0x80090DB0: bne         $a2, $v1, L_80090DC8
    if (ctx->r6 != ctx->r3) {
        // 0x80090DB4: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80090DC8;
    }
    // 0x80090DB4: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80090DB8: bne         $v0, $at, L_80090DC8
    if (ctx->r2 != ctx->r1) {
        // 0x80090DBC: nop
    
            goto L_80090DC8;
    }
    // 0x80090DBC: nop

    // 0x80090DC0: sw          $a2, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r6;
    // 0x80090DC4: or          $v0, $a2, $zero
    ctx->r2 = ctx->r6 | 0;
L_80090DC8:
    // 0x80090DC8: bne         $a0, $zero, L_80090E24
    if (ctx->r4 != 0) {
        // 0x80090DCC: lui         $a0, 0x8012
        ctx->r4 = S32(0X8012 << 16);
            goto L_80090E24;
    }
    // 0x80090DCC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80090DD0: lh          $a0, 0x6838($a0)
    ctx->r4 = MEM_H(ctx->r4, 0X6838);
    // 0x80090DD4: slt         $at, $v1, $a1
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r5) ? 1 : 0;
    // 0x80090DD8: bgez        $a0, L_80090DEC
    if (SIGNED(ctx->r4) >= 0) {
        // 0x80090DDC: nop
    
            goto L_80090DEC;
    }
    // 0x80090DDC: nop

    // 0x80090DE0: beq         $at, $zero, L_80090DEC
    if (ctx->r1 == 0) {
        // 0x80090DE4: addiu       $t9, $v1, 0x1
        ctx->r25 = ADD32(ctx->r3, 0X1);
            goto L_80090DEC;
    }
    // 0x80090DE4: addiu       $t9, $v1, 0x1
    ctx->r25 = ADD32(ctx->r3, 0X1);
    // 0x80090DE8: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
L_80090DEC:
    // 0x80090DEC: blez        $a0, L_80090E08
    if (SIGNED(ctx->r4) <= 0) {
        // 0x80090DF0: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_80090E08;
    }
    // 0x80090DF0: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80090DF4: lw          $v1, 0x0($a3)
    ctx->r3 = MEM_W(ctx->r7, 0X0);
    // 0x80090DF8: nop

    // 0x80090DFC: blez        $v1, L_80090E08
    if (SIGNED(ctx->r3) <= 0) {
        // 0x80090E00: addiu       $t5, $v1, -0x1
        ctx->r13 = ADD32(ctx->r3, -0X1);
            goto L_80090E08;
    }
    // 0x80090E00: addiu       $t5, $v1, -0x1
    ctx->r13 = ADD32(ctx->r3, -0X1);
    // 0x80090E04: sw          $t5, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r13;
L_80090E08:
    // 0x80090E08: bne         $v0, $at, L_80090E24
    if (ctx->r2 != ctx->r1) {
        // 0x80090E0C: nop
    
            goto L_80090E24;
    }
    // 0x80090E0C: nop

    // 0x80090E10: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x80090E14: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x80090E18: bne         $a2, $t7, L_80090E24
    if (ctx->r6 != ctx->r15) {
        // 0x80090E1C: nop
    
            goto L_80090E24;
    }
    // 0x80090E1C: nop

    // 0x80090E20: sw          $t6, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r14;
L_80090E24:
    // 0x80090E24: bne         $t0, $v0, L_80090E3C
    if (ctx->r8 != ctx->r2) {
        // 0x80090E28: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80090E3C;
    }
    // 0x80090E28: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x80090E2C: lw          $t8, 0x0($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X0);
    // 0x80090E30: nop

    // 0x80090E34: beq         $t1, $t8, L_80090ECC
    if (ctx->r9 == ctx->r24) {
        // 0x80090E38: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_80090ECC;
    }
    // 0x80090E38: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80090E3C:
    // 0x80090E3C: jal         0x80001D04
    // 0x80090E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_14;
    // 0x80090E40: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_14:
    // 0x80090E44: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80090E48: lw          $v1, 0x69CC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X69CC);
    // 0x80090E4C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80090E50: lw          $v0, 0x69C8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X69C8);
    // 0x80090E54: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x80090E58: subu        $t9, $t9, $v1
    ctx->r25 = SUB32(ctx->r25, ctx->r3);
    // 0x80090E5C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80090E60: sll         $t5, $v0, 1
    ctx->r13 = S32(ctx->r2 << 1);
    // 0x80090E64: addu        $t7, $t9, $t5
    ctx->r15 = ADD32(ctx->r25, ctx->r13);
    // 0x80090E68: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x80090E6C: lw          $t5, 0x6480($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6480);
    // 0x80090E70: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x80090E74: multu       $v1, $t5
    result = U64(U32(ctx->r3)) * U64(U32(ctx->r13)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x80090E78: addu        $t6, $t6, $t7
    ctx->r14 = ADD32(ctx->r14, ctx->r15);
    // 0x80090E7C: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x80090E80: lh          $t6, 0x68E8($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X68E8);
    // 0x80090E84: addu        $t9, $t9, $v0
    ctx->r25 = ADD32(ctx->r25, ctx->r2);
    // 0x80090E88: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80090E8C: sll         $t9, $t9, 6
    ctx->r25 = S32(ctx->r25 << 6);
    // 0x80090E90: mtc1        $t9, $f18
    ctx->f18.u32l = ctx->r25;
    // 0x80090E94: sw          $t6, -0xB3C($at)
    MEM_W(-0XB3C, ctx->r1) = ctx->r14;
    // 0x80090E98: cvt.s.w     $f6, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    ctx->f6.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80090E9C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80090EA0: addiu       $t8, $v1, 0x1
    ctx->r24 = ADD32(ctx->r3, 0X1);
    // 0x80090EA4: mflo        $t7
    ctx->r15 = lo;
    // 0x80090EA8: negu        $t6, $t7
    ctx->r14 = SUB32(0, ctx->r15);
    // 0x80090EAC: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80090EB0: sw          $t8, -0xB38($at)
    MEM_W(-0XB38, ctx->r1) = ctx->r24;
    // 0x80090EB4: cvt.s.w     $f10, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    ctx->f10.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80090EB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090EBC: swc1        $f6, 0x69E8($at)
    MEM_W(0X69E8, ctx->r1) = ctx->f6.u32l;
    // 0x80090EC0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090EC4: swc1        $f10, 0x69EC($at)
    MEM_W(0X69EC, ctx->r1) = ctx->f10.u32l;
L_80090EC8:
    // 0x80090EC8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_80090ECC:
    // 0x80090ECC: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 3U, dkr_legacy_fields, 0U); }
    // 0x80090ED0: jr          $ra
    // 0x80090ED4: nop

    return;
    // 0x80090ED4: nop

;}
RECOMP_FUNC void obj_loop_wavepower(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BFFDC: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800BFFE0: lw          $t6, 0x3198($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X3198);
    // 0x800BFFE4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800BFFE8: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800BFFEC: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800BFFF0: beq         $a0, $t6, L_800C0160
    if (ctx->r4 == ctx->r14) {
        // 0x800BFFF4: sw          $ra, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r31;
            goto L_800C0160;
    }
    // 0x800BFFF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800BFFF8: jal         0x8001BA74
    // 0x800BFFFC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800BFFFC: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x800C0000: lw          $a1, 0x50($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X50);
    // 0x800C0004: nop

    // 0x800C0008: blez        $a1, L_800C0164
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C000C: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0164;
    }
    // 0x800C000C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0010: blez        $a1, L_800C005C
    if (SIGNED(ctx->r5) <= 0) {
        // 0x800C0014: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800C005C;
    }
    // 0x800C0014: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800C0018: sll         $t7, $a1, 2
    ctx->r15 = S32(ctx->r5 << 2);
    // 0x800C001C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800C0020: addu        $v1, $v0, $t8
    ctx->r3 = ADD32(ctx->r2, ctx->r24);
    // 0x800C0024: addu        $a3, $t7, $v0
    ctx->r7 = ADD32(ctx->r15, ctx->r2);
L_800C0028:
    // 0x800C0028: lw          $a1, 0x0($v1)
    ctx->r5 = MEM_W(ctx->r3, 0X0);
    // 0x800C002C: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800C0030: lw          $a0, 0x64($a1)
    ctx->r4 = MEM_W(ctx->r5, 0X64);
    // 0x800C0034: sltu        $at, $v1, $a3
    ctx->r1 = ctx->r3 < ctx->r7 ? 1 : 0;
    // 0x800C0038: lh          $t9, 0x0($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X0);
    // 0x800C003C: nop

    // 0x800C0040: bne         $t9, $zero, L_800C004C
    if (ctx->r25 != 0) {
        // 0x800C0044: nop
    
            goto L_800C004C;
    }
    // 0x800C0044: nop

    // 0x800C0048: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
L_800C004C:
    // 0x800C004C: beq         $at, $zero, L_800C005C
    if (ctx->r1 == 0) {
        // 0x800C0050: nop
    
            goto L_800C005C;
    }
    // 0x800C0050: nop

    // 0x800C0054: beq         $a2, $zero, L_800C0028
    if (ctx->r6 == 0) {
        // 0x800C0058: nop
    
            goto L_800C0028;
    }
    // 0x800C0058: nop

L_800C005C:
    // 0x800C005C: beq         $a2, $zero, L_800C0164
    if (ctx->r6 == 0) {
        // 0x800C0060: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0164;
    }
    // 0x800C0060: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C0064: lw          $v0, 0x3C($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X3C);
    // 0x800C0068: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C006C: lhu         $t0, 0x8($v0)
    ctx->r8 = MEM_HU(ctx->r2, 0X8);
    // 0x800C0070: lui         $v1, 0x8013
    ctx->r3 = S32(0X8013 << 16);
    // 0x800C0074: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800C0078: bgez        $t0, L_800C008C
    if (SIGNED(ctx->r8) >= 0) {
        // 0x800C007C: cvt.s.w     $f0, $f4
        CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800C008C;
    }
    // 0x800C007C: cvt.s.w     $f0, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    ctx->f0.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800C0080: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C0084: nop

    // 0x800C0088: add.s       $f0, $f0, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f0.fl + ctx->f6.fl;
L_800C008C:
    // 0x800C008C: lwc1        $f8, 0xC($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0XC);
    // 0x800C0090: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x800C0094: mul.s       $f0, $f0, $f0
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f0.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x800C0098: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x800C009C: lwc1        $f16, 0x10($a2)
    ctx->f16.u32l = MEM_W(ctx->r6, 0X10);
    // 0x800C00A0: lwc1        $f18, 0x10($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X10);
    // 0x800C00A4: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x800C00A8: sub.s       $f12, $f16, $f18
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f12.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x800C00AC: lwc1        $f4, 0x14($a2)
    ctx->f4.u32l = MEM_W(ctx->r6, 0X14);
    // 0x800C00B0: lwc1        $f6, 0x14($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X14);
    // 0x800C00B4: mul.s       $f10, $f12, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f12.fl, ctx->f12.fl);
    // 0x800C00B8: sub.s       $f14, $f4, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f14.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C00BC: mul.s       $f18, $f14, $f14
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f18.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x800C00C0: add.s       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f8.fl + ctx->f10.fl;
    // 0x800C00C4: add.s       $f4, $f16, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = ctx->f16.fl + ctx->f18.fl;
    // 0x800C00C8: c.lt.s      $f4, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f4.fl < ctx->f0.fl;
    // 0x800C00CC: nop

    // 0x800C00D0: bc1f        L_800C0164
    if (!c1cs) {
        // 0x800C00D4: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800C0164;
    }
    // 0x800C00D4: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800C00D8: lhu         $t1, 0xA($v0)
    ctx->r9 = MEM_HU(ctx->r2, 0XA);
    // 0x800C00DC: addiu       $v1, $v1, -0x58E0
    ctx->r3 = ADD32(ctx->r3, -0X58E0);
    // 0x800C00E0: mtc1        $t1, $f6
    ctx->f6.u32l = ctx->r9;
    // 0x800C00E4: bgez        $t1, L_800C00FC
    if (SIGNED(ctx->r9) >= 0) {
        // 0x800C00E8: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_800C00FC;
    }
    // 0x800C00E8: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800C00EC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C00F0: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C00F4: nop

    // 0x800C00F8: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_800C00FC:
    // 0x800C00FC: lui         $at, 0x3B80
    ctx->r1 = S32(0X3B80 << 16);
    // 0x800C0100: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C0104: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0108: mul.s       $f18, $f8, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x800C010C: swc1        $f18, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->f18.u32l;
    // 0x800C0110: lhu         $t2, 0xC($v0)
    ctx->r10 = MEM_HU(ctx->r2, 0XC);
    // 0x800C0114: lwc1        $f6, -0x5FF8($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X5FF8);
    // 0x800C0118: lwc1        $f4, 0x0($v1)
    ctx->f4.u32l = MEM_W(ctx->r3, 0X0);
    // 0x800C011C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800C0120: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x800C0124: bgez        $t2, L_800C013C
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800C0128: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C013C;
    }
    // 0x800C0128: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C012C: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C0130: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800C0134: nop

    // 0x800C0138: add.s       $f16, $f16, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f18.fl;
L_800C013C:
    // 0x800C013C: nop

    // 0x800C0140: div.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = DIV_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800C0144: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0148: swc1        $f4, -0x58DC($at)
    MEM_W(-0X58DC, ctx->r1) = ctx->f4.u32l;
    // 0x800C014C: lhu         $t3, 0xC($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XC);
    // 0x800C0150: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0154: sw          $t3, -0x58D8($at)
    MEM_W(-0X58D8, ctx->r1) = ctx->r11;
    // 0x800C0158: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C015C: sw          $s0, 0x3198($at)
    MEM_W(0X3198, ctx->r1) = ctx->r16;
L_800C0160:
    // 0x800C0160: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800C0164:
    // 0x800C0164: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800C0168: jr          $ra
    // 0x800C016C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    return;
    // 0x800C016C: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
;}
RECOMP_FUNC void obj_loop_scenery(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033DD0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80033DD4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80033DD8: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80033DDC: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x80033DE0: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80033DE4: beq         $v0, $zero, L_80033F38
    if (ctx->r2 == 0) {
        // 0x80033DE8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_80033F38;
    }
    // 0x80033DE8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80033DEC: lh          $t6, 0x7C($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X7C);
    // 0x80033DF0: addiu       $v1, $a0, 0x78
    ctx->r3 = ADD32(ctx->r4, 0X78);
    // 0x80033DF4: blez        $t6, L_80033E14
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80033DF8: nop
    
            goto L_80033E14;
    }
    // 0x80033DF8: nop

    // 0x80033DFC: lh          $t7, 0x4($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X4);
    // 0x80033E00: nop

    // 0x80033E04: subu        $t8, $t7, $a1
    ctx->r24 = SUB32(ctx->r15, ctx->r5);
    // 0x80033E08: sh          $t8, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r24;
    // 0x80033E0C: lw          $v0, 0x4C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X4C);
    // 0x80033E10: nop

L_80033E14:
    // 0x80033E14: lh          $t9, 0x14($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X14);
    // 0x80033E18: addiu       $v1, $s0, 0x78
    ctx->r3 = ADD32(ctx->r16, 0X78);
    // 0x80033E1C: andi        $t0, $t9, 0x40
    ctx->r8 = ctx->r25 & 0X40;
    // 0x80033E20: beq         $t0, $zero, L_80033EEC
    if (ctx->r8 == 0) {
        // 0x80033E24: nop
    
            goto L_80033EEC;
    }
    // 0x80033E24: nop

    // 0x80033E28: lh          $t1, 0x4($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X4);
    // 0x80033E2C: addiu       $a0, $zero, 0x13C
    ctx->r4 = ADD32(0, 0X13C);
    // 0x80033E30: bgtz        $t1, L_80033EEC
    if (SIGNED(ctx->r9) > 0) {
        // 0x80033E34: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_80033EEC;
    }
    // 0x80033E34: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80033E38: lw          $a1, 0xC($s0)
    ctx->r5 = MEM_W(ctx->r16, 0XC);
    // 0x80033E3C: lw          $a2, 0x10($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X10);
    // 0x80033E40: lw          $a3, 0x14($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X14);
    // 0x80033E44: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80033E48: sw          $zero, 0x14($sp)
    MEM_W(0X14, ctx->r29) = 0;
    // 0x80033E4C: jal         0x80009558
    // 0x80033E50: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_0;
    // 0x80033E50: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_0:
    // 0x80033E54: lw          $t3, 0x4C($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X4C);
    // 0x80033E58: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033E5C: lw          $t4, 0x0($t3)
    ctx->r12 = MEM_W(ctx->r11, 0X0);
    // 0x80033E60: addiu       $t5, $zero, 0x71C
    ctx->r13 = ADD32(0, 0X71C);
    // 0x80033E64: addiu       $t6, $zero, 0xA
    ctx->r14 = ADD32(0, 0XA);
    // 0x80033E68: sh          $t5, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r13;
    // 0x80033E6C: sh          $t6, 0x4($v1)
    MEM_H(0X4, ctx->r3) = ctx->r14;
    // 0x80033E70: jal         0x8009C3C8
    // 0x80033E74: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    get_number_of_active_players(rdram, ctx);
        goto after_1;
    // 0x80033E74: sw          $t4, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r12;
    after_1:
    // 0x80033E78: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033E7C: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x80033E80: beq         $at, $zero, L_80033F00
    if (ctx->r1 == 0) {
        // 0x80033E84: nop
    
            goto L_80033F00;
    }
    // 0x80033E84: nop

    // 0x80033E88: lw          $t7, 0x40($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X40);
    // 0x80033E8C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80033E90: lb          $v0, 0x57($t7)
    ctx->r2 = MEM_B(ctx->r15, 0X57);
    // 0x80033E94: nop

    // 0x80033E98: blez        $v0, L_80033F00
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80033E9C: nop
    
            goto L_80033F00;
    }
    // 0x80033E9C: nop

    // 0x80033EA0: bne         $v0, $at, L_80033EB0
    if (ctx->r2 != ctx->r1) {
        // 0x80033EA4: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_80033EB0;
    }
    // 0x80033EA4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x80033EA8: b           L_80033EC4
    // 0x80033EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
        goto L_80033EC4;
    // 0x80033EAC: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
L_80033EB0:
    // 0x80033EB0: addiu       $a1, $v0, -0x1
    ctx->r5 = ADD32(ctx->r2, -0X1);
    // 0x80033EB4: jal         0x8006F94C
    // 0x80033EB8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    rand_range(rdram, ctx);
        goto after_2;
    // 0x80033EB8: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    after_2:
    // 0x80033EBC: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033EC0: or          $a2, $v0, $zero
    ctx->r6 = ctx->r2 | 0;
L_80033EC4:
    // 0x80033EC4: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x80033EC8: sllv        $t9, $t8, $a2
    ctx->r25 = S32(ctx->r24 << (ctx->r6 & 31));
    // 0x80033ECC: sw          $t9, 0x74($s0)
    MEM_W(0X74, ctx->r16) = ctx->r25;
    // 0x80033ED0: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x80033ED4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80033ED8: jal         0x800AFC3C
    // 0x80033EDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    obj_spawn_particle(rdram, ctx);
        goto after_3;
    // 0x80033EDC: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_3:
    // 0x80033EE0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x80033EE4: b           L_80033F04
    // 0x80033EE8: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
        goto L_80033F04;
    // 0x80033EE8: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
L_80033EEC:
    // 0x80033EEC: lh          $t0, 0x4($v1)
    ctx->r8 = MEM_H(ctx->r3, 0X4);
    // 0x80033EF0: nop

    // 0x80033EF4: bgtz        $t0, L_80033F00
    if (SIGNED(ctx->r8) > 0) {
        // 0x80033EF8: nop
    
            goto L_80033F00;
    }
    // 0x80033EF8: nop

    // 0x80033EFC: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80033F00:
    // 0x80033F00: lh          $t1, 0x6($v1)
    ctx->r9 = MEM_H(ctx->r3, 0X6);
L_80033F04:
    // 0x80033F04: nop

    // 0x80033F08: sh          $t1, 0x4($s0)
    MEM_H(0X4, ctx->r16) = ctx->r9;
    // 0x80033F0C: lh          $t2, 0x6($v1)
    ctx->r10 = MEM_H(ctx->r3, 0X6);
    // 0x80033F10: nop

    // 0x80033F14: negu        $at, $t2
    ctx->r1 = SUB32(0, ctx->r10);
    // 0x80033F18: sll         $t3, $at, 2
    ctx->r11 = S32(ctx->r1 << 2);
    // 0x80033F1C: subu        $t3, $t3, $at
    ctx->r11 = SUB32(ctx->r11, ctx->r1);
    // 0x80033F20: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80033F24: addu        $t3, $t3, $at
    ctx->r11 = ADD32(ctx->r11, ctx->r1);
    // 0x80033F28: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80033F2C: sra         $t4, $t3, 8
    ctx->r12 = S32(SIGNED(ctx->r11) >> 8);
    // 0x80033F30: sh          $t4, 0x6($v1)
    MEM_H(0X6, ctx->r3) = ctx->r12;
    // 0x80033F34: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033F38:
    // 0x80033F38: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80033F3C: jr          $ra
    // 0x80033F40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80033F40: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void fb_memcpy(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007ABFC: blez        $a2, L_8007AC60
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8007AC00: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8007AC60;
    }
    // 0x8007AC00: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007AC04: andi        $a3, $a2, 0x3
    ctx->r7 = ctx->r6 & 0X3;
    // 0x8007AC08: beq         $a3, $zero, L_8007AC30
    if (ctx->r7 == 0) {
        // 0x8007AC0C: or          $v1, $a3, $zero
        ctx->r3 = ctx->r7 | 0;
            goto L_8007AC30;
    }
    // 0x8007AC0C: or          $v1, $a3, $zero
    ctx->r3 = ctx->r7 | 0;
L_8007AC10:
    // 0x8007AC10: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x8007AC14: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007AC18: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8007AC1C: addiu       $a0, $a0, 0x1
    ctx->r4 = ADD32(ctx->r4, 0X1);
    // 0x8007AC20: bne         $v1, $v0, L_8007AC10
    if (ctx->r3 != ctx->r2) {
        // 0x8007AC24: sb          $t6, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r14;
            goto L_8007AC10;
    }
    // 0x8007AC24: sb          $t6, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r14;
    // 0x8007AC28: beq         $v0, $a2, L_8007AC60
    if (ctx->r2 == ctx->r6) {
        // 0x8007AC2C: nop
    
            goto L_8007AC60;
    }
    // 0x8007AC2C: nop

L_8007AC30:
    // 0x8007AC30: lbu         $t7, 0x0($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X0);
    // 0x8007AC34: addiu       $v0, $v0, 0x4
    ctx->r2 = ADD32(ctx->r2, 0X4);
    // 0x8007AC38: sb          $t7, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r15;
    // 0x8007AC3C: lbu         $t8, 0x1($a0)
    ctx->r24 = MEM_BU(ctx->r4, 0X1);
    // 0x8007AC40: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x8007AC44: sb          $t8, -0x3($a1)
    MEM_B(-0X3, ctx->r5) = ctx->r24;
    // 0x8007AC48: lbu         $t9, 0x2($a0)
    ctx->r25 = MEM_BU(ctx->r4, 0X2);
    // 0x8007AC4C: addiu       $a0, $a0, 0x4
    ctx->r4 = ADD32(ctx->r4, 0X4);
    // 0x8007AC50: sb          $t9, -0x2($a1)
    MEM_B(-0X2, ctx->r5) = ctx->r25;
    // 0x8007AC54: lbu         $t0, -0x1($a0)
    ctx->r8 = MEM_BU(ctx->r4, -0X1);
    // 0x8007AC58: bne         $v0, $a2, L_8007AC30
    if (ctx->r2 != ctx->r6) {
        // 0x8007AC5C: sb          $t0, -0x1($a1)
        MEM_B(-0X1, ctx->r5) = ctx->r8;
            goto L_8007AC30;
    }
    // 0x8007AC5C: sb          $t0, -0x1($a1)
    MEM_B(-0X1, ctx->r5) = ctx->r8;
L_8007AC60:
    // 0x8007AC60: jr          $ra
    // 0x8007AC64: nop

    return;
    // 0x8007AC64: nop

;}
RECOMP_FUNC void thread30_bgload(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C74A0: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x800C74A4: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800C74A8: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800C74AC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x800C74B0: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800C74B4: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x800C74B8: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800C74BC: lui         $s0, 0x8013
    ctx->r16 = S32(0X8013 << 16);
    // 0x800C74C0: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800C74C4: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800C74C8: lui         $s5, 0x800E
    ctx->r21 = S32(0X800E << 16);
    // 0x800C74CC: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800C74D0: sw          $a0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r4;
    // 0x800C74D4: sw          $zero, 0x34($sp)
    MEM_W(0X34, ctx->r29) = 0;
    // 0x800C74D8: addiu       $s5, $s5, 0x3770
    ctx->r21 = ADD32(ctx->r21, 0X3770);
    // 0x800C74DC: addiu       $s4, $s4, 0x3778
    ctx->r20 = ADD32(ctx->r20, 0X3778);
    // 0x800C74E0: addiu       $s3, $s3, 0x3774
    ctx->r19 = ADD32(ctx->r19, 0X3774);
    // 0x800C74E4: addiu       $s0, $s0, -0x5360
    ctx->r16 = ADD32(ctx->r16, -0X5360);
    // 0x800C74E8: addiu       $s1, $sp, 0x34
    ctx->r17 = ADD32(ctx->r29, 0X34);
    // 0x800C74EC: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
L_800C74F0:
    // 0x800C74F0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800C74F4:
    // 0x800C74F4: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800C74F8: jal         0x800C8BB0
    // 0x800C74FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x800C74FC: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_0:
    // 0x800C7500: lw          $t6, 0x34($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X34);
    // 0x800C7504: nop

    // 0x800C7508: bne         $t6, $s2, L_800C74F4
    if (ctx->r14 != ctx->r18) {
        // 0x800C750C: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_800C74F4;
    }
    // 0x800C750C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800C7510: lw          $a0, 0x0($s3)
    ctx->r4 = MEM_W(ctx->r19, 0X0);
    // 0x800C7514: lw          $a2, 0x0($s4)
    ctx->r6 = MEM_W(ctx->r20, 0X0);
    // 0x800C7518: jal         0x8006E2E8
    // 0x800C751C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    load_level_for_menu(rdram, ctx);
        goto after_1;
    // 0x800C751C: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_1:
    // 0x800C7520: b           L_800C74F0
    // 0x800C7524: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
        goto L_800C74F0;
    // 0x800C7524: sw          $zero, 0x0($s5)
    MEM_W(0X0, ctx->r21) = 0;
    // 0x800C7528: nop

    // 0x800C752C: nop

    // 0x800C7530: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800C7534: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800C7538: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800C753C: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800C7540: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800C7544: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x800C7548: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x800C754C: jr          $ra
    // 0x800C7550: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x800C7550: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void menu_save_options_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80087B60: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80087B64: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x80087B68: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x80087B6C: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x80087B70: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x80087B74: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x80087B78: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x80087B7C: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80087B80: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80087B84: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80087B88: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80087B8C: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x80087B90: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x80087B94: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x80087B98: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80087B9C: beq         $v0, $zero, L_80087BC4
    if (ctx->r2 == 0) {
        // 0x80087BA0: sw          $s1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r17;
            goto L_80087BC4;
    }
    // 0x80087BA0: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x80087BA4: blez        $v0, L_80087BBC
    if (SIGNED(ctx->r2) <= 0) {
        // 0x80087BA8: subu        $t0, $v0, $s0
        ctx->r8 = SUB32(ctx->r2, ctx->r16);
            goto L_80087BBC;
    }
    // 0x80087BA8: subu        $t0, $v0, $s0
    ctx->r8 = SUB32(ctx->r2, ctx->r16);
    // 0x80087BAC: addu        $t9, $v0, $a0
    ctx->r25 = ADD32(ctx->r2, ctx->r4);
    // 0x80087BB0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087BB4: b           L_80087BC4
    // 0x80087BB8: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
        goto L_80087BC4;
    // 0x80087BB8: sw          $t9, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r25;
L_80087BBC:
    // 0x80087BBC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087BC0: sw          $t0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r8;
L_80087BC4:
    // 0x80087BC4: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80087BC8: lw          $t1, 0x63E0($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X63E0);
    // 0x80087BCC: nop

    // 0x80087BD0: andi        $t2, $t1, 0x7
    ctx->r10 = ctx->r9 & 0X7;
    // 0x80087BD4: slti        $at, $t2, 0x2
    ctx->r1 = SIGNED(ctx->r10) < 0X2 ? 1 : 0;
    // 0x80087BD8: bne         $at, $zero, L_80087BE8
    if (ctx->r1 != 0) {
        // 0x80087BDC: nop
    
            goto L_80087BE8;
    }
    // 0x80087BDC: nop

    // 0x80087BE0: jal         0x80086A48
    // 0x80087BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    savemenu_move(rdram, ctx);
        goto after_0;
    // 0x80087BE4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
L_80087BE8:
    // 0x80087BE8: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80087BEC: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80087BF0: nop

    // 0x80087BF4: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x80087BF8: bne         $at, $zero, L_80087C1C
    if (ctx->r1 != 0) {
        // 0x80087BFC: slti        $at, $v0, 0x14
        ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
            goto L_80087C1C;
    }
    // 0x80087BFC: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x80087C00: beq         $at, $zero, L_80087C1C
    if (ctx->r1 == 0) {
        // 0x80087C04: nop
    
            goto L_80087C1C;
    }
    // 0x80087C04: nop

    // 0x80087C08: jal         0x80085B9C
    // 0x80087C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    savemenu_render(rdram, ctx);
        goto after_1;
    // 0x80087C0C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_1:
    // 0x80087C10: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x80087C14: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x80087C18: nop

L_80087C1C:
    // 0x80087C1C: beq         $v0, $zero, L_80087C6C
    if (ctx->r2 == 0) {
        // 0x80087C20: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_80087C6C;
    }
    // 0x80087C20: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80087C24: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x80087C28: bne         $at, $zero, L_80087C4C
    if (ctx->r1 != 0) {
        // 0x80087C2C: slti        $at, $v0, -0x1E
        ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
            goto L_80087C4C;
    }
    // 0x80087C2C: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
    // 0x80087C30: jal         0x80087EB8
    // 0x80087C34: nop

    savemenu_free(rdram, ctx);
        goto after_2;
    // 0x80087C34: nop

    after_2:
    // 0x80087C38: jal         0x800813D0
    // 0x80087C3C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    menu_init(rdram, ctx);
        goto after_3;
    // 0x80087C3C: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_3:
    // 0x80087C40: b           L_80087E98
    // 0x80087C44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80087E98;
    // 0x80087C44: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x80087C48: slti        $at, $v0, -0x1E
    ctx->r1 = SIGNED(ctx->r2) < -0X1E ? 1 : 0;
L_80087C4C:
    // 0x80087C4C: beq         $at, $zero, L_80087C64
    if (ctx->r1 == 0) {
        // 0x80087C50: nop
    
            goto L_80087C64;
    }
    // 0x80087C50: nop

    // 0x80087C54: jal         0x80087EB8
    // 0x80087C58: nop

    savemenu_free(rdram, ctx);
        goto after_4;
    // 0x80087C58: nop

    after_4:
    // 0x80087C5C: jal         0x800813D0
    // 0x80087C60: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    menu_init(rdram, ctx);
        goto after_5;
    // 0x80087C60: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_5:
L_80087C64:
    // 0x80087C64: b           L_80087E98
    // 0x80087C68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80087E98;
    // 0x80087C68: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80087C6C:
    // 0x80087C6C: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x80087C70: lw          $t3, 0x63C4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X63C4);
    // 0x80087C74: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x80087C78: bne         $t3, $zero, L_80087CCC
    if (ctx->r11 != 0) {
        // 0x80087C7C: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_80087CCC;
    }
    // 0x80087C7C: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x80087C80: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x80087C84: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x80087C88: addiu       $s2, $s2, 0x6464
    ctx->r18 = ADD32(ctx->r18, 0X6464);
    // 0x80087C8C: addiu       $s1, $s1, 0x645C
    ctx->r17 = ADD32(ctx->r17, 0X645C);
    // 0x80087C90: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80087C94:
    // 0x80087C94: lb          $t4, 0x0($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X0);
    // 0x80087C98: lb          $t5, 0x0($s2)
    ctx->r13 = MEM_B(ctx->r18, 0X0);
    // 0x80087C9C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80087CA0: sw          $a2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r6;
    // 0x80087CA4: addu        $s4, $s4, $t4
    ctx->r20 = ADD32(ctx->r20, ctx->r12);
    // 0x80087CA8: jal         0x8006A554
    // 0x80087CAC: addu        $s3, $s3, $t5
    ctx->r19 = ADD32(ctx->r19, ctx->r13);
    input_pressed(rdram, ctx);
        goto after_6;
    // 0x80087CAC: addu        $s3, $s3, $t5
    ctx->r19 = ADD32(ctx->r19, ctx->r13);
    after_6:
    // 0x80087CB0: lw          $a2, 0x30($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X30);
    // 0x80087CB4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80087CB8: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x80087CBC: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80087CC0: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80087CC4: bne         $s0, $at, L_80087C94
    if (ctx->r16 != ctx->r1) {
        // 0x80087CC8: or          $a2, $a2, $v0
        ctx->r6 = ctx->r6 | ctx->r2;
            goto L_80087C94;
    }
    // 0x80087CC8: or          $a2, $a2, $v0
    ctx->r6 = ctx->r6 | ctx->r2;
L_80087CCC:
    // 0x80087CCC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80087CD0: lw          $v0, 0x63E0($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63E0);
    // 0x80087CD4: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80087CD8: andi        $t6, $v0, 0x8
    ctx->r14 = ctx->r2 & 0X8;
    // 0x80087CDC: beq         $t6, $zero, L_80087CF8
    if (ctx->r14 == 0) {
        // 0x80087CE0: sltiu       $at, $v0, 0x8
        ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
            goto L_80087CF8;
    }
    // 0x80087CE0: sltiu       $at, $v0, 0x8
    ctx->r1 = ctx->r2 < 0X8 ? 1 : 0;
    // 0x80087CE4: jal         0x80087734
    // 0x80087CE8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    savemenu_input_message(rdram, ctx);
        goto after_7;
    // 0x80087CE8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    after_7:
    // 0x80087CEC: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087CF0: b           L_80087E8C
    // 0x80087CF4: sw          $v0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r2;
        goto L_80087E8C;
    // 0x80087CF4: sw          $v0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r2;
L_80087CF8:
    // 0x80087CF8: beq         $at, $zero, L_80087E70
    if (ctx->r1 == 0) {
        // 0x80087CFC: sll         $t7, $v0, 2
        ctx->r15 = S32(ctx->r2 << 2);
            goto L_80087E70;
    }
    // 0x80087CFC: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x80087D00: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x80087D04: addu        $at, $at, $t7
    gpr jr_addend_80087D10 = ctx->r15;
    ctx->r1 = ADD32(ctx->r1, ctx->r15);
    // 0x80087D08: lw          $t7, -0x7B50($at)
    ctx->r15 = ADD32(ctx->r1, -0X7B50);
    // 0x80087D0C: nop

    // 0x80087D10: jr          $t7
    // 0x80087D14: nop

    switch (jr_addend_80087D10 >> 2) {
        case 0: goto L_80087D18; break;
        case 1: goto L_80087D28; break;
        case 2: goto L_80087D54; break;
        case 3: goto L_80087D94; break;
        case 4: goto L_80087DAC; break;
        case 5: goto L_80087DEC; break;
        case 6: goto L_80087E04; break;
        case 7: goto L_80087E1C; break;
        default: switch_error(__func__, 0x80087D10, 0x800E84B0);
    }
    // 0x80087D14: nop

L_80087D18:
    // 0x80087D18: addiu       $t8, $zero, -0x1
    ctx->r24 = ADD32(0, -0X1);
    // 0x80087D1C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087D20: b           L_80087E70
    // 0x80087D24: sw          $t8, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r24;
        goto L_80087E70;
    // 0x80087D24: sw          $t8, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r24;
L_80087D28:
    // 0x80087D28: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80087D2C: addiu       $s0, $s0, 0x63D8
    ctx->r16 = ADD32(ctx->r16, 0X63D8);
    // 0x80087D30: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x80087D34: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x80087D38: addiu       $t0, $t9, 0x1
    ctx->r8 = ADD32(ctx->r25, 0X1);
    // 0x80087D3C: slti        $at, $t0, 0xB
    ctx->r1 = SIGNED(ctx->r8) < 0XB ? 1 : 0;
    // 0x80087D40: bne         $at, $zero, L_80087E70
    if (ctx->r1 != 0) {
        // 0x80087D44: sw          $t0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r8;
            goto L_80087E70;
    }
    // 0x80087D44: sw          $t0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r8;
    // 0x80087D48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D4C: b           L_80087E70
    // 0x80087D50: sw          $t2, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r10;
        goto L_80087E70;
    // 0x80087D50: sw          $t2, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r10;
L_80087D54:
    // 0x80087D54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D58: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x80087D5C: sw          $zero, 0x6BD4($at)
    MEM_W(0X6BD4, ctx->r1) = 0;
    // 0x80087D60: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D64: jal         0x800862C4
    // 0x80087D68: swc1        $f4, 0x6BDC($at)
    MEM_W(0X6BDC, ctx->r1) = ctx->f4.u32l;
    savemenu_load_sources(rdram, ctx);
        goto after_8;
    // 0x80087D68: swc1        $f4, 0x6BDC($at)
    MEM_W(0X6BDC, ctx->r1) = ctx->f4.u32l;
    after_8:
    // 0x80087D6C: beq         $v0, $zero, L_80087D84
    if (ctx->r2 == 0) {
        // 0x80087D70: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80087D84;
    }
    // 0x80087D70: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80087D74: jal         0x800871D8
    // 0x80087D78: nop

    savemenu_render_error(rdram, ctx);
        goto after_9;
    // 0x80087D78: nop

    after_9:
    // 0x80087D7C: b           L_80087E70
    // 0x80087D80: nop

        goto L_80087E70;
    // 0x80087D80: nop

L_80087D84:
    // 0x80087D84: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x80087D88: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087D8C: b           L_80087E70
    // 0x80087D90: sw          $t3, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r11;
        goto L_80087E70;
    // 0x80087D90: sw          $t3, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r11;
L_80087D94:
    // 0x80087D94: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80087D98: jal         0x800874D0
    // 0x80087D9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    savemenu_input_source(rdram, ctx);
        goto after_10;
    // 0x80087D9C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_10:
    // 0x80087DA0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087DA4: b           L_80087E70
    // 0x80087DA8: sw          $v0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r2;
        goto L_80087E70;
    // 0x80087DA8: sw          $v0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r2;
L_80087DAC:
    // 0x80087DAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DB0: mtc1        $zero, $f6
    ctx->f6.u32l = 0;
    // 0x80087DB4: sw          $zero, 0x6BE4($at)
    MEM_W(0X6BE4, ctx->r1) = 0;
    // 0x80087DB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DBC: jal         0x800867D4
    // 0x80087DC0: swc1        $f6, 0x6BEC($at)
    MEM_W(0X6BEC, ctx->r1) = ctx->f6.u32l;
    savemenu_load_destinations(rdram, ctx);
        goto after_11;
    // 0x80087DC0: swc1        $f6, 0x6BEC($at)
    MEM_W(0X6BEC, ctx->r1) = ctx->f6.u32l;
    after_11:
    // 0x80087DC4: beq         $v0, $zero, L_80087DDC
    if (ctx->r2 == 0) {
        // 0x80087DC8: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80087DDC;
    }
    // 0x80087DC8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80087DCC: jal         0x800871D8
    // 0x80087DD0: nop

    savemenu_render_error(rdram, ctx);
        goto after_12;
    // 0x80087DD0: nop

    after_12:
    // 0x80087DD4: b           L_80087E70
    // 0x80087DD8: nop

        goto L_80087E70;
    // 0x80087DD8: nop

L_80087DDC:
    // 0x80087DDC: addiu       $t4, $zero, 0x5
    ctx->r12 = ADD32(0, 0X5);
    // 0x80087DE0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087DE4: b           L_80087E70
    // 0x80087DE8: sw          $t4, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r12;
        goto L_80087E70;
    // 0x80087DE8: sw          $t4, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r12;
L_80087DEC:
    // 0x80087DEC: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80087DF0: jal         0x800875E4
    // 0x80087DF4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    savemenu_input_dest(rdram, ctx);
        goto after_13;
    // 0x80087DF4: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_13:
    // 0x80087DF8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087DFC: b           L_80087E70
    // 0x80087E00: sw          $v0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r2;
        goto L_80087E70;
    // 0x80087E00: sw          $v0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r2;
L_80087E04:
    // 0x80087E04: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x80087E08: jal         0x800876CC
    // 0x80087E0C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    savemenu_input_confirm(rdram, ctx);
        goto after_14;
    // 0x80087E0C: or          $a1, $s4, $zero
    ctx->r5 = ctx->r20 | 0;
    after_14:
    // 0x80087E10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80087E14: b           L_80087E70
    // 0x80087E18: sw          $v0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r2;
        goto L_80087E70;
    // 0x80087E18: sw          $v0, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r2;
L_80087E1C:
    // 0x80087E1C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80087E20: addiu       $s0, $s0, 0x63D8
    ctx->r16 = ADD32(ctx->r16, 0X63D8);
    // 0x80087E24: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x80087E28: nop

    // 0x80087E2C: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x80087E30: slti        $at, $t6, 0x4
    ctx->r1 = SIGNED(ctx->r14) < 0X4 ? 1 : 0;
    // 0x80087E34: bne         $at, $zero, L_80087E70
    if (ctx->r1 != 0) {
        // 0x80087E38: sw          $t6, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r14;
            goto L_80087E70;
    }
    // 0x80087E38: sw          $t6, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r14;
    // 0x80087E3C: jal         0x80086AFC
    // 0x80087E40: nop

    savemenu_write(rdram, ctx);
        goto after_15;
    // 0x80087E40: nop

    after_15:
    // 0x80087E44: beq         $v0, $zero, L_80087E5C
    if (ctx->r2 == 0) {
        // 0x80087E48: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_80087E5C;
    }
    // 0x80087E48: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80087E4C: jal         0x800871D8
    // 0x80087E50: nop

    savemenu_render_error(rdram, ctx);
        goto after_16;
    // 0x80087E50: nop

    after_16:
    // 0x80087E54: b           L_80087E70
    // 0x80087E58: nop

        goto L_80087E70;
    // 0x80087E58: nop

L_80087E5C:
    // 0x80087E5C: addiu       $t8, $zero, 0x6
    ctx->r24 = ADD32(0, 0X6);
    // 0x80087E60: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    // 0x80087E64: addiu       $t9, $zero, 0x1
    ctx->r25 = ADD32(0, 0X1);
    // 0x80087E68: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087E6C: sw          $t9, 0x63E0($at)
    MEM_W(0X63E0, ctx->r1) = ctx->r25;
L_80087E70:
    // 0x80087E70: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80087E74: lw          $t0, -0xB84($t0)
    ctx->r8 = MEM_W(ctx->r8, -0XB84);
    // 0x80087E78: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80087E7C: beq         $t0, $zero, L_80087E8C
    if (ctx->r8 == 0) {
        // 0x80087E80: nop
    
            goto L_80087E8C;
    }
    // 0x80087E80: nop

    // 0x80087E84: jal         0x800C01D8
    // 0x80087E88: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_17;
    // 0x80087E88: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_17:
L_80087E8C:
    // 0x80087E8C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80087E90: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
    // 0x80087E94: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80087E98:
    // 0x80087E98: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80087E9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80087EA0: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80087EA4: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80087EA8: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x80087EAC: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x80087EB0: jr          $ra
    // 0x80087EB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x80087EB4: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void set_racer_position_and_angle(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E13C: addiu       $sp, $sp, -0x10
    ctx->r29 = ADD32(ctx->r29, -0X10);
    // 0x8001E140: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001E144: addiu       $t3, $t3, -0x51A4
    ctx->r11 = ADD32(ctx->r11, -0X51A4);
    // 0x8001E148: sw          $s0, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r16;
    // 0x8001E14C: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8001E150: sll         $s0, $a0, 16
    ctx->r16 = S32(ctx->r4 << 16);
    // 0x8001E154: sra         $t6, $s0, 16
    ctx->r14 = S32(SIGNED(ctx->r16) >> 16);
    // 0x8001E158: sw          $s1, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r17;
    // 0x8001E15C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x8001E160: or          $s0, $t6, $zero
    ctx->r16 = ctx->r14 | 0;
    // 0x8001E164: sw          $a0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r4;
    // 0x8001E168: blez        $v1, L_8001E28C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8001E16C: or          $v0, $zero, $zero
        ctx->r2 = 0 | 0;
            goto L_8001E28C;
    }
    // 0x8001E16C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8001E170: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001E174: lw          $t2, 0x28($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X28);
    // 0x8001E178: lw          $t1, 0x24($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X24);
    // 0x8001E17C: lw          $t0, 0x20($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X20);
    // 0x8001E180: addiu       $t4, $t4, -0x51A8
    ctx->r12 = ADD32(ctx->r12, -0X51A8);
    // 0x8001E184: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8001E188:
    // 0x8001E188: lw          $t7, 0x0($t4)
    ctx->r15 = MEM_W(ctx->r12, 0X0);
    // 0x8001E18C: sll         $t8, $v0, 2
    ctx->r24 = S32(ctx->r2 << 2);
    // 0x8001E190: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x8001E194: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8001E198: nop

    // 0x8001E19C: lh          $t6, 0x6($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X6);
    // 0x8001E1A0: nop

    // 0x8001E1A4: andi        $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 & 0X8000;
    // 0x8001E1A8: bne         $t7, $zero, L_8001E27C
    if (ctx->r15 != 0) {
        // 0x8001E1AC: nop
    
            goto L_8001E27C;
    }
    // 0x8001E1AC: nop

    // 0x8001E1B0: lh          $t8, 0x48($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X48);
    // 0x8001E1B4: nop

    // 0x8001E1B8: bne         $t5, $t8, L_8001E27C
    if (ctx->r13 != ctx->r24) {
        // 0x8001E1BC: nop
    
            goto L_8001E27C;
    }
    // 0x8001E1BC: nop

    // 0x8001E1C0: lw          $a1, 0x64($a0)
    ctx->r5 = MEM_W(ctx->r4, 0X64);
    // 0x8001E1C4: nop

    // 0x8001E1C8: lh          $t9, 0x0($a1)
    ctx->r25 = MEM_H(ctx->r5, 0X0);
    // 0x8001E1CC: nop

    // 0x8001E1D0: bne         $s0, $t9, L_8001E280
    if (ctx->r16 != ctx->r25) {
        // 0x8001E1D4: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8001E280;
    }
    // 0x8001E1D4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001E1D8: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8001E1DC: lwc1        $f4, 0xC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8001E1E0: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001E1E4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001E1E8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001E1EC: nop

    // 0x8001E1F0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8001E1F4: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001E1F8: mfc1        $t7, $f6
    ctx->r15 = (int32_t)ctx->f6.u32l;
    // 0x8001E1FC: nop

    // 0x8001E200: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x8001E204: sh          $t7, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r15;
    // 0x8001E208: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x8001E20C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001E210: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001E214: lwc1        $f8, 0x10($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X10);
    // 0x8001E218: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8001E21C: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8001E220: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8001E224: mfc1        $t9, $f10
    ctx->r25 = (int32_t)ctx->f10.u32l;
    // 0x8001E228: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x8001E22C: sh          $t9, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r25;
    // 0x8001E230: lwc1        $f16, 0x14($a0)
    ctx->f16.u32l = MEM_W(ctx->r4, 0X14);
    // 0x8001E234: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8001E238: nop

    // 0x8001E23C: cvt.w.s     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.u32l = CVT_W_S(ctx->f16.fl);
    // 0x8001E240: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8001E244: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8001E248: sh          $t7, 0x0($a3)
    MEM_H(0X0, ctx->r7) = ctx->r15;
    // 0x8001E24C: lh          $t8, 0x4($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X4);
    // 0x8001E250: nop

    // 0x8001E254: sh          $t8, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r24;
    // 0x8001E258: lh          $t9, 0x2($a0)
    ctx->r25 = MEM_H(ctx->r4, 0X2);
    // 0x8001E25C: nop

    // 0x8001E260: sh          $t9, 0x0($t1)
    MEM_H(0X0, ctx->r9) = ctx->r25;
    // 0x8001E264: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x8001E268: nop

    // 0x8001E26C: sh          $t6, 0x0($t2)
    MEM_H(0X0, ctx->r10) = ctx->r14;
    // 0x8001E270: lw          $v1, 0x0($t3)
    ctx->r3 = MEM_W(ctx->r11, 0X0);
    // 0x8001E274: nop

    // 0x8001E278: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8001E27C:
    // 0x8001E27C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8001E280:
    // 0x8001E280: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001E284: bne         $at, $zero, L_8001E188
    if (ctx->r1 != 0) {
        // 0x8001E288: nop
    
            goto L_8001E188;
    }
    // 0x8001E288: nop

L_8001E28C:
    // 0x8001E28C: lw          $s0, 0x8($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X8);
    // 0x8001E290: lw          $s1, 0xC($sp)
    ctx->r17 = MEM_W(ctx->r29, 0XC);
    // 0x8001E294: jr          $ra
    // 0x8001E298: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
    return;
    // 0x8001E298: addiu       $sp, $sp, 0x10
    ctx->r29 = ADD32(ctx->r29, 0X10);
;}
