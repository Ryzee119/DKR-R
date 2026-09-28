#include "recomp.h"
#include "funcs.h"

RECOMP_FUNC void is_reset_pressed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006EAC0: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006EAC4: lw          $v1, 0x3560($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3560);
    // 0x8006EAC8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8006EACC: bne         $v1, $zero, L_8006EB04
    if (ctx->r3 != 0) {
        // 0x8006EAD0: sw          $ra, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r31;
            goto L_8006EB04;
    }
    // 0x8006EAD0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8006EAD4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8006EAD8: addiu       $a0, $a0, 0x3548
    ctx->r4 = ADD32(ctx->r4, 0X3548);
    // 0x8006EADC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8006EAE0: jal         0x800C8BB0
    // 0x8006EAE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_0;
    // 0x8006EAE4: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_0:
    // 0x8006EAE8: addiu       $t6, $v0, 0x1
    ctx->r14 = ADD32(ctx->r2, 0X1);
    // 0x8006EAEC: sltu        $t6, $zero, $t6
    ctx->r14 = 0 < ctx->r14 ? 1 : 0;
    // 0x8006EAF0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006EAF4: sw          $t6, 0x3560($at)
    MEM_W(0X3560, ctx->r1) = ctx->r14;
    // 0x8006EAF8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006EAFC: lw          $v1, 0x3560($v1)
    ctx->r3 = MEM_W(ctx->r3, 0X3560);
    // 0x8006EB00: nop

L_8006EB04:
    // 0x8006EB04: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8006EB08: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006EB0C: jr          $ra
    // 0x8006EB10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8006EB10: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void update_bluey(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8005D0D0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x8005D0D4: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x8005D0D8: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x8005D0DC: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x8005D0E0: sw          $s0, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r16;
    // 0x8005D0E4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8005D0E8: or          $s0, $a3, $zero
    ctx->r16 = ctx->r7 | 0;
    // 0x8005D0EC: or          $s1, $a2, $zero
    ctx->r17 = ctx->r6 | 0;
    // 0x8005D0F0: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8005D0F4: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x8005D0F8: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x8005D0FC: jal         0x8005CA78
    // 0x8005D100: addiu       $a0, $a0, -0x3200
    ctx->r4 = ADD32(ctx->r4, -0X3200);
    set_boss_voice_clip_offset(rdram, ctx);
        goto after_0;
    // 0x8005D100: addiu       $a0, $a0, -0x3200
    ctx->r4 = ADD32(ctx->r4, -0X3200);
    after_0:
    // 0x8005D104: lw          $v0, 0x74($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X74);
    // 0x8005D108: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8005D10C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x8005D110: addiu       $v1, $zero, -0x11
    ctx->r3 = ADD32(0, -0X11);
    // 0x8005D114: and         $t7, $t6, $v1
    ctx->r15 = ctx->r14 & ctx->r3;
    // 0x8005D118: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x8005D11C: lw          $t8, 0x0($a1)
    ctx->r24 = MEM_W(ctx->r5, 0X0);
    // 0x8005D120: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D124: and         $t9, $t8, $v1
    ctx->r25 = ctx->r24 & ctx->r3;
    // 0x8005D128: sw          $t9, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r25;
    // 0x8005D12C: lb          $t2, 0x3B($s1)
    ctx->r10 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D130: nop

    // 0x8005D134: sh          $t2, 0x5E($sp)
    MEM_H(0X5E, ctx->r29) = ctx->r10;
    // 0x8005D138: lh          $t3, 0x18($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X18);
    // 0x8005D13C: nop

    // 0x8005D140: sh          $t3, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r11;
    // 0x8005D144: lh          $t4, 0x16A($s0)
    ctx->r12 = MEM_H(ctx->r16, 0X16A);
    // 0x8005D148: nop

    // 0x8005D14C: sh          $t4, 0x5A($sp)
    MEM_H(0X5A, ctx->r29) = ctx->r12;
    // 0x8005D150: lb          $t5, 0x1D8($s0)
    ctx->r13 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D154: nop

    // 0x8005D158: bne         $t5, $at, L_8005D18C
    if (ctx->r13 != ctx->r1) {
        // 0x8005D15C: lw          $t1, 0x78($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X78);
            goto L_8005D18C;
    }
    // 0x8005D15C: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D160: jal         0x80023568
    // 0x8005D164: nop

    func_80023568(rdram, ctx);
        goto after_1;
    // 0x8005D164: nop

    after_1:
    // 0x8005D168: beq         $v0, $zero, L_8005D18C
    if (ctx->r2 == 0) {
        // 0x8005D16C: lw          $t1, 0x78($sp)
        ctx->r9 = MEM_W(ctx->r29, 0X78);
            goto L_8005D18C;
    }
    // 0x8005D16C: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D170: jal         0x80021400
    // 0x8005D174: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    func_80021400(rdram, ctx);
        goto after_2;
    // 0x8005D174: addiu       $a0, $zero, 0x82
    ctx->r4 = ADD32(0, 0X82);
    after_2:
    // 0x8005D178: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D17C: nop

    // 0x8005D180: addiu       $t7, $t6, 0x1
    ctx->r15 = ADD32(ctx->r14, 0X1);
    // 0x8005D184: sb          $t7, 0x1D8($s0)
    MEM_B(0X1D8, ctx->r16) = ctx->r15;
    // 0x8005D188: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
L_8005D18C:
    // 0x8005D18C: addiu       $a0, $zero, 0x64
    ctx->r4 = ADD32(0, 0X64);
    // 0x8005D190: lw          $v1, 0x0($t1)
    ctx->r3 = MEM_W(ctx->r9, 0X0);
    // 0x8005D194: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8005D198: bne         $v1, $a0, L_8005D1A4
    if (ctx->r3 != ctx->r4) {
        // 0x8005D19C: lui         $at, 0x8012
        ctx->r1 = S32(0X8012 << 16);
            goto L_8005D1A4;
    }
    // 0x8005D19C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D1A0: sb          $zero, -0x2A30($at)
    MEM_B(-0X2A30, ctx->r1) = 0;
L_8005D1A4:
    // 0x8005D1A4: lh          $t8, 0x0($s0)
    ctx->r24 = MEM_H(ctx->r16, 0X0);
    // 0x8005D1A8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005D1AC: bne         $t0, $t8, L_8005D22C
    if (ctx->r8 != ctx->r24) {
        // 0x8005D1B0: nop
    
            goto L_8005D22C;
    }
    // 0x8005D1B0: nop

    // 0x8005D1B4: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8005D1B8: nop

    // 0x8005D1BC: beq         $a0, $v0, L_8005D22C
    if (ctx->r4 == ctx->r2) {
        // 0x8005D1C0: addiu       $t9, $v0, -0xF
        ctx->r25 = ADD32(ctx->r2, -0XF);
            goto L_8005D22C;
    }
    // 0x8005D1C0: addiu       $t9, $v0, -0xF
    ctx->r25 = ADD32(ctx->r2, -0XF);
    // 0x8005D1C4: bgez        $t9, L_8005D224
    if (SIGNED(ctx->r25) >= 0) {
        // 0x8005D1C8: sw          $t9, 0x0($t1)
        MEM_W(0X0, ctx->r9) = ctx->r25;
            goto L_8005D224;
    }
    // 0x8005D1C8: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
    // 0x8005D1CC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8005D1D0: lb          $t3, -0x2A2F($t3)
    ctx->r11 = MEM_B(ctx->r11, -0X2A2F);
    // 0x8005D1D4: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8005D1D8: bne         $t3, $zero, L_8005D204
    if (ctx->r11 != 0) {
        // 0x8005D1DC: addiu       $t5, $zero, 0x1
        ctx->r13 = ADD32(0, 0X1);
            goto L_8005D204;
    }
    // 0x8005D1DC: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
    // 0x8005D1E0: jal         0x8005CB04
    // 0x8005D1E4: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    play_random_boss_sound(rdram, ctx);
        goto after_3;
    // 0x8005D1E4: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_3:
    // 0x8005D1E8: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8005D1EC: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D1F0: addiu       $t4, $zero, 0x3
    ctx->r12 = ADD32(0, 0X3);
    // 0x8005D1F4: sb          $t4, 0x1D3($s0)
    MEM_B(0X1D3, ctx->r16) = ctx->r12;
    // 0x8005D1F8: lw          $a1, 0x70($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X70);
    // 0x8005D1FC: nop

    // 0x8005D200: addiu       $t5, $zero, 0x1
    ctx->r13 = ADD32(0, 0X1);
L_8005D204:
    // 0x8005D204: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D208: sb          $t5, -0x2A2F($at)
    MEM_B(-0X2A2F, ctx->r1) = ctx->r13;
    // 0x8005D20C: sw          $zero, 0x0($t1)
    MEM_W(0X0, ctx->r9) = 0;
    // 0x8005D210: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x8005D214: nop

    // 0x8005D218: ori         $t7, $t6, 0x8000
    ctx->r15 = ctx->r14 | 0X8000;
    // 0x8005D21C: b           L_8005D22C
    // 0x8005D220: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
        goto L_8005D22C;
    // 0x8005D220: sw          $t7, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r15;
L_8005D224:
    // 0x8005D224: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8005D228: sb          $zero, -0x2A2F($at)
    MEM_B(-0X2A2F, ctx->r1) = 0;
L_8005D22C:
    // 0x8005D22C: lw          $a0, 0x60($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X60);
    // 0x8005D230: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x8005D234: or          $a2, $s1, $zero
    ctx->r6 = ctx->r17 | 0;
    // 0x8005D238: or          $a3, $s0, $zero
    ctx->r7 = ctx->r16 | 0;
    // 0x8005D23C: jal         0x8004F7F4
    // 0x8005D240: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    func_8004F7F4(rdram, ctx);
        goto after_4;
    // 0x8005D240: sw          $v1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r3;
    after_4:
    // 0x8005D244: lw          $v1, 0x48($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X48);
    // 0x8005D248: lw          $t1, 0x78($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X78);
    // 0x8005D24C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005D250: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8005D254: swc1        $f16, 0x30($s0)
    MEM_W(0X30, ctx->r16) = ctx->f16.u32l;
    // 0x8005D258: lh          $t8, 0x5A($sp)
    ctx->r24 = MEM_H(ctx->r29, 0X5A);
    // 0x8005D25C: nop

    // 0x8005D260: sh          $t8, 0x16A($s0)
    MEM_H(0X16A, ctx->r16) = ctx->r24;
    // 0x8005D264: lh          $t9, 0x5E($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X5E);
    // 0x8005D268: nop

    // 0x8005D26C: sb          $t9, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r25;
    // 0x8005D270: lh          $t2, 0x5C($sp)
    ctx->r10 = MEM_H(ctx->r29, 0X5C);
    // 0x8005D274: nop

    // 0x8005D278: sh          $t2, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r10;
    // 0x8005D27C: lb          $t3, 0x187($s0)
    ctx->r11 = MEM_B(ctx->r16, 0X187);
    // 0x8005D280: nop

    // 0x8005D284: beq         $t3, $zero, L_8005D314
    if (ctx->r11 == 0) {
        // 0x8005D288: nop
    
            goto L_8005D314;
    }
    // 0x8005D288: nop

    // 0x8005D28C: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D290: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005D294: beq         $v1, $at, L_8005D314
    if (ctx->r3 == ctx->r1) {
        // 0x8005D298: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005D314;
    }
    // 0x8005D298: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005D29C: sb          $v1, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r3;
    // 0x8005D2A0: sb          $t4, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r12;
    // 0x8005D2A4: swc1        $f16, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f16.u32l;
    // 0x8005D2A8: jal         0x8005CB04
    // 0x8005D2AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    play_random_boss_sound(rdram, ctx);
        goto after_5;
    // 0x8005D2AC: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_5:
    // 0x8005D2B0: addiu       $a0, $zero, 0x11
    ctx->r4 = ADD32(0, 0X11);
    // 0x8005D2B4: jal         0x80001D04
    // 0x8005D2B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8005D2B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8005D2BC: lui         $at, 0x4140
    ctx->r1 = S32(0X4140 << 16);
    // 0x8005D2C0: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8005D2C4: jal         0x80069F28
    // 0x8005D2C8: nop

    set_camera_shake(rdram, ctx);
        goto after_7;
    // 0x8005D2C8: nop

    after_7:
    // 0x8005D2CC: sb          $zero, 0x187($s0)
    MEM_B(0X187, ctx->r16) = 0;
    // 0x8005D2D0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D2D4: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D2D8: lwc1        $f9, 0x6A30($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A30);
    // 0x8005D2DC: lwc1        $f8, 0x6A34($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A34);
    // 0x8005D2E0: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D2E4: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x8005D2E8: lui         $at, 0x401E
    ctx->r1 = S32(0X401E << 16);
    // 0x8005D2EC: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x8005D2F0: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x8005D2F4: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D2F8: swc1        $f18, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f18.u32l;
    // 0x8005D2FC: lwc1        $f4, 0x20($s1)
    ctx->f4.u32l = MEM_W(ctx->r17, 0X20);
    // 0x8005D300: nop

    // 0x8005D304: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D308: add.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = ctx->f6.d + ctx->f8.d;
    // 0x8005D30C: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D310: swc1        $f18, 0x20($s1)
    MEM_W(0X20, ctx->r17) = ctx->f18.u32l;
L_8005D314:
    // 0x8005D314: lw          $t5, 0x148($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X148);
    // 0x8005D318: nop

    // 0x8005D31C: beq         $t5, $zero, L_8005D358
    if (ctx->r13 == 0) {
        // 0x8005D320: nop
    
            goto L_8005D358;
    }
    // 0x8005D320: nop

    // 0x8005D324: lwc1        $f0, 0x1C($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0X1C);
    // 0x8005D328: lwc1        $f2, 0x24($s1)
    ctx->f2.u32l = MEM_W(ctx->r17, 0X24);
    // 0x8005D32C: mul.s       $f20, $f0, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8005D330: nop

    // 0x8005D334: mul.s       $f14, $f2, $f2
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f14.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8005D338: nop

    // 0x8005D33C: mul.s       $f4, $f20, $f20
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f4.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005D340: nop

    // 0x8005D344: mul.s       $f6, $f14, $f14
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f6.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005D348: jal         0x800C9AD0
    // 0x8005D34C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_8;
    // 0x8005D34C: add.s       $f12, $f4, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f12.fl = ctx->f4.fl + ctx->f6.fl;
    after_8:
    // 0x8005D350: neg.s       $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = -ctx->f0.fl;
    // 0x8005D354: swc1        $f8, 0x2C($s0)
    MEM_W(0X2C, ctx->r16) = ctx->f8.u32l;
L_8005D358:
    // 0x8005D358: lb          $a0, 0x192($s0)
    ctx->r4 = MEM_B(ctx->r16, 0X192);
    // 0x8005D35C: lbu         $a1, 0x1C8($s0)
    ctx->r5 = MEM_BU(ctx->r16, 0X1C8);
    // 0x8005D360: jal         0x8001BA1C
    // 0x8005D364: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    find_next_checkpoint_node(rdram, ctx);
        goto after_9;
    // 0x8005D364: sw          $zero, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = 0;
    after_9:
    // 0x8005D368: lb          $t6, 0x1CA($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1CA);
    // 0x8005D36C: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x8005D370: addu        $t7, $v0, $t6
    ctx->r15 = ADD32(ctx->r2, ctx->r14);
    // 0x8005D374: lb          $t8, 0x36($t7)
    ctx->r24 = MEM_B(ctx->r15, 0X36);
    // 0x8005D378: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x8005D37C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D380: bne         $t8, $at, L_8005D38C
    if (ctx->r24 != ctx->r1) {
        // 0x8005D384: addiu       $t0, $zero, -0x1
        ctx->r8 = ADD32(0, -0X1);
            goto L_8005D38C;
    }
    // 0x8005D384: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
    // 0x8005D388: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_8005D38C:
    // 0x8005D38C: lb          $t9, 0x3B($s1)
    ctx->r25 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D390: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005D394: beq         $t9, $at, L_8005D524
    if (ctx->r25 == ctx->r1) {
        // 0x8005D398: nop
    
            goto L_8005D524;
    }
    // 0x8005D398: nop

    // 0x8005D39C: lwc1        $f10, 0x2C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D3A0: lui         $at, 0xC000
    ctx->r1 = S32(0XC000 << 16);
    // 0x8005D3A4: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005D3A8: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005D3AC: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8005D3B0: c.lt.d      $f0, $f18
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f0.d < ctx->f18.d;
    // 0x8005D3B4: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D3B8: bc1f        L_8005D494
    if (!c1cs) {
        // 0x8005D3BC: nop
    
            goto L_8005D494;
    }
    // 0x8005D3BC: nop

    // 0x8005D3C0: beq         $v1, $zero, L_8005D454
    if (ctx->r3 == 0) {
        // 0x8005D3C4: addiu       $t3, $zero, 0x3
        ctx->r11 = ADD32(0, 0X3);
            goto L_8005D454;
    }
    // 0x8005D3C4: addiu       $t3, $zero, 0x3
    ctx->r11 = ADD32(0, 0X3);
    // 0x8005D3C8: lbu         $t2, 0x1CD($s0)
    ctx->r10 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005D3CC: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005D3D0: beq         $t2, $at, L_8005D3E4
    if (ctx->r10 == ctx->r1) {
        // 0x8005D3D4: lui         $at, 0x4220
        ctx->r1 = S32(0X4220 << 16);
            goto L_8005D3E4;
    }
    // 0x8005D3D4: lui         $at, 0x4220
    ctx->r1 = S32(0X4220 << 16);
    // 0x8005D3D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8005D3DC: nop

    // 0x8005D3E0: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005D3E4:
    // 0x8005D3E4: sb          $t3, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r11;
    // 0x8005D3E8: lb          $v0, 0x1E1($s0)
    ctx->r2 = MEM_B(ctx->r16, 0X1E1);
    // 0x8005D3EC: addiu       $t5, $zero, 0x28
    ctx->r13 = ADD32(0, 0X28);
    // 0x8005D3F0: sll         $t4, $v0, 1
    ctx->r12 = S32(ctx->r2 << 1);
    // 0x8005D3F4: subu        $v0, $t5, $t4
    ctx->r2 = SUB32(ctx->r13, ctx->r12);
    // 0x8005D3F8: bgez        $v0, L_8005D408
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8005D3FC: slti        $at, $v0, 0x4A
        ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
            goto L_8005D408;
    }
    // 0x8005D3FC: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
    // 0x8005D400: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8005D404: slti        $at, $v0, 0x4A
    ctx->r1 = SIGNED(ctx->r2) < 0X4A ? 1 : 0;
L_8005D408:
    // 0x8005D408: bne         $at, $zero, L_8005D414
    if (ctx->r1 != 0) {
        // 0x8005D40C: nop
    
            goto L_8005D414;
    }
    // 0x8005D40C: nop

    // 0x8005D410: addiu       $v0, $zero, 0x49
    ctx->r2 = ADD32(0, 0X49);
L_8005D414:
    // 0x8005D414: mtc1        $v0, $f6
    ctx->f6.u32l = ctx->r2;
    // 0x8005D418: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D41C: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8005D420: lui         $at, 0x3FD0
    ctx->r1 = S32(0X3FD0 << 16);
    // 0x8005D424: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x8005D428: sub.s       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f0.fl;
    // 0x8005D42C: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x8005D430: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x8005D434: mul.d       $f6, $f18, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = MUL_D(ctx->f18.d, ctx->f4.d);
    // 0x8005D438: cvt.d.s     $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f8.d = CVT_D_S(ctx->f0.fl);
    // 0x8005D43C: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x8005D440: sb          $t6, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r14;
    // 0x8005D444: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8005D448: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D44C: b           L_8005D540
    // 0x8005D450: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005D540;
    // 0x8005D450: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005D454:
    // 0x8005D454: sb          $zero, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = 0;
    // 0x8005D458: sb          $zero, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = 0;
    // 0x8005D45C: lwc1        $f8, 0x64($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D460: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D464: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x8005D468: mul.s       $f6, $f4, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f4.fl, ctx->f8.fl);
    // 0x8005D46C: mtc1        $at, $f19
    ctx->f_odd[(19 - 1) * 2] = ctx->r1;
    // 0x8005D470: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x8005D474: lwc1        $f8, 0xC($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D478: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8005D47C: mul.d       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f18.d); 
    ctx->f4.d = MUL_D(ctx->f10.d, ctx->f18.d);
    // 0x8005D480: cvt.d.s     $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f6.d = CVT_D_S(ctx->f8.fl);
    // 0x8005D484: sub.d       $f10, $f6, $f4
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f4.d); 
    ctx->f10.d = ctx->f6.d - ctx->f4.d;
    // 0x8005D488: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D48C: b           L_8005D540
    // 0x8005D490: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005D540;
    // 0x8005D490: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005D494:
    // 0x8005D494: lwc1        $f9, 0x6A38($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A38);
    // 0x8005D498: lwc1        $f8, 0x6A3C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A3C);
    // 0x8005D49C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D4A0: c.lt.d      $f0, $f8
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f0.d < ctx->f8.d;
    // 0x8005D4A4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8005D4A8: bc1t        L_8005D4CC
    if (c1cs) {
        // 0x8005D4AC: addiu       $t8, $zero, 0x1
        ctx->r24 = ADD32(0, 0X1);
            goto L_8005D4CC;
    }
    // 0x8005D4AC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005D4B0: lwc1        $f7, 0x6A40($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, 0X6A40);
    // 0x8005D4B4: lwc1        $f6, 0x6A44($at)
    ctx->f6.u32l = MEM_W(ctx->r1, 0X6A44);
    // 0x8005D4B8: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x8005D4BC: c.lt.d      $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f6.d < ctx->f0.d;
    // 0x8005D4C0: addiu       $t2, $zero, 0x2
    ctx->r10 = ADD32(0, 0X2);
    // 0x8005D4C4: bc1f        L_8005D4FC
    if (!c1cs) {
        // 0x8005D4C8: nop
    
            goto L_8005D4FC;
    }
    // 0x8005D4C8: nop

L_8005D4CC:
    // 0x8005D4CC: sb          $t7, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r15;
    // 0x8005D4D0: sb          $t8, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r24;
    // 0x8005D4D4: lwc1        $f10, 0x64($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D4D8: lwc1        $f4, 0x2C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X2C);
    // 0x8005D4DC: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8005D4E0: mul.s       $f18, $f4, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f4.fl, ctx->f10.fl);
    // 0x8005D4E4: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x8005D4E8: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D4EC: mul.s       $f6, $f18, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f6.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x8005D4F0: sub.s       $f10, $f4, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f10.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005D4F4: b           L_8005D540
    // 0x8005D4F8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
        goto L_8005D540;
    // 0x8005D4F8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
L_8005D4FC:
    // 0x8005D4FC: sb          $t9, 0x1CD($s0)
    MEM_B(0X1CD, ctx->r16) = ctx->r25;
    // 0x8005D500: sb          $t2, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r10;
    // 0x8005D504: lwc1        $f18, 0xC($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D508: lwc1        $f4, 0x64($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D50C: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x8005D510: cvt.d.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f6.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D514: add.d       $f10, $f8, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f6.d); 
    ctx->f10.d = ctx->f8.d + ctx->f6.d;
    // 0x8005D518: cvt.s.d     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f18.fl = CVT_S_D(ctx->f10.d);
    // 0x8005D51C: b           L_8005D540
    // 0x8005D520: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
        goto L_8005D540;
    // 0x8005D520: swc1        $f18, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f18.u32l;
L_8005D524:
    // 0x8005D524: lwc1        $f4, 0xC($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D528: lwc1        $f6, 0x64($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X64);
    // 0x8005D52C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x8005D530: cvt.d.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f10.d = CVT_D_S(ctx->f6.fl);
    // 0x8005D534: add.d       $f18, $f8, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f18.d = ctx->f8.d + ctx->f10.d;
    // 0x8005D538: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x8005D53C: swc1        $f4, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f4.u32l;
L_8005D540:
    // 0x8005D540: lw          $t3, 0x68($s1)
    ctx->r11 = MEM_W(ctx->r17, 0X68);
    // 0x8005D544: lb          $t5, 0x3B($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D548: lw          $v0, 0x0($t3)
    ctx->r2 = MEM_W(ctx->r11, 0X0);
    // 0x8005D54C: sll         $t6, $t5, 3
    ctx->r14 = S32(ctx->r13 << 3);
    // 0x8005D550: lw          $v1, 0x0($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X0);
    // 0x8005D554: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D558: lw          $t4, 0x44($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X44);
    // 0x8005D55C: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005D560: addu        $t7, $t4, $t6
    ctx->r15 = ADD32(ctx->r12, ctx->r14);
    // 0x8005D564: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8005D568: nop

    // 0x8005D56C: sll         $t9, $t8, 4
    ctx->r25 = S32(ctx->r24 << 4);
    // 0x8005D570: addiu       $t2, $t9, -0x11
    ctx->r10 = ADD32(ctx->r25, -0X11);
    // 0x8005D574: mtc1        $t2, $f6
    ctx->f6.u32l = ctx->r10;
    // 0x8005D578: bc1f        L_8005D5A4
    if (!c1cs) {
        // 0x8005D57C: cvt.s.w     $f20, $f6
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8005D5A4;
    }
    // 0x8005D57C: cvt.s.w     $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    ctx->f20.fl = CVT_S_W(ctx->f6.u32l);
L_8005D580:
    // 0x8005D580: add.s       $f8, $f0, $f20
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f8.fl = ctx->f0.fl + ctx->f20.fl;
    // 0x8005D584: swc1        $f8, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f8.u32l;
    // 0x8005D588: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005D58C: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D590: nop

    // 0x8005D594: c.lt.s      $f0, $f16
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f0.fl < ctx->f16.fl;
    // 0x8005D598: nop

    // 0x8005D59C: bc1t        L_8005D580
    if (c1cs) {
        // 0x8005D5A0: nop
    
            goto L_8005D580;
    }
    // 0x8005D5A0: nop

L_8005D5A4:
    // 0x8005D5A4: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005D5A8: nop

    // 0x8005D5AC: bc1f        L_8005D5D8
    if (!c1cs) {
        // 0x8005D5B0: nop
    
            goto L_8005D5D8;
    }
    // 0x8005D5B0: nop

L_8005D5B4:
    // 0x8005D5B4: sub.s       $f10, $f0, $f20
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f10.fl = ctx->f0.fl - ctx->f20.fl;
    // 0x8005D5B8: swc1        $f10, 0xC($s0)
    MEM_W(0XC, ctx->r16) = ctx->f10.u32l;
    // 0x8005D5BC: sh          $t0, 0x10($v0)
    MEM_H(0X10, ctx->r2) = ctx->r8;
    // 0x8005D5C0: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D5C4: nop

    // 0x8005D5C8: c.lt.s      $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f20.fl < ctx->f0.fl;
    // 0x8005D5CC: nop

    // 0x8005D5D0: bc1t        L_8005D5B4
    if (c1cs) {
        // 0x8005D5D4: nop
    
            goto L_8005D5B4;
    }
    // 0x8005D5D4: nop

L_8005D5D8:
    // 0x8005D5D8: lh          $t3, 0x10($v0)
    ctx->r11 = MEM_H(ctx->r2, 0X10);
    // 0x8005D5DC: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D5E0: bne         $t0, $t3, L_8005D608
    if (ctx->r8 != ctx->r11) {
        // 0x8005D5E4: addiu       $at, $zero, 0x4
        ctx->r1 = ADD32(0, 0X4);
            goto L_8005D608;
    }
    // 0x8005D5E4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8005D5E8: bne         $v1, $at, L_8005D608
    if (ctx->r3 != ctx->r1) {
        // 0x8005D5EC: nop
    
            goto L_8005D608;
    }
    // 0x8005D5EC: nop

    // 0x8005D5F0: lbu         $t5, 0x1CD($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0X1CD);
    // 0x8005D5F4: nop

    // 0x8005D5F8: sb          $t5, 0x3B($s1)
    MEM_B(0X3B, ctx->r17) = ctx->r13;
    // 0x8005D5FC: lwc1        $f0, 0xC($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0XC);
    // 0x8005D600: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D604: nop

L_8005D608:
    // 0x8005D608: cfc1        $t6, $FpcCsr
    ctx->r14 = get_cop1_cs();
    // 0x8005D60C: lh          $t4, 0x18($s1)
    ctx->r12 = MEM_H(ctx->r17, 0X18);
    // 0x8005D610: ori         $at, $t6, 0x3
    ctx->r1 = ctx->r14 | 0X3;
    // 0x8005D614: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8005D618: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8005D61C: sh          $t4, 0x5C($sp)
    MEM_H(0X5C, ctx->r29) = ctx->r12;
    // 0x8005D620: cvt.w.s     $f18, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    ctx->f18.u32l = CVT_W_S(ctx->f0.fl);
    // 0x8005D624: sw          $zero, 0x74($s1)
    MEM_W(0X74, ctx->r17) = 0;
    // 0x8005D628: mfc1        $t7, $f18
    ctx->r15 = (int32_t)ctx->f18.u32l;
    // 0x8005D62C: ctc1        $t6, $FpcCsr
    set_cop1_cs(ctx->r14);
    // 0x8005D630: bne         $v1, $zero, L_8005D664
    if (ctx->r3 != 0) {
        // 0x8005D634: sh          $t7, 0x18($s1)
        MEM_H(0X18, ctx->r17) = ctx->r15;
            goto L_8005D664;
    }
    // 0x8005D634: sh          $t7, 0x18($s1)
    MEM_H(0X18, ctx->r17) = ctx->r15;
    // 0x8005D638: lh          $a2, 0x5C($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X5C);
    // 0x8005D63C: addiu       $t8, $zero, 0xAD
    ctx->r24 = ADD32(0, 0XAD);
    // 0x8005D640: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x8005D644: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005D648: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    // 0x8005D64C: jal         0x800113CC
    // 0x8005D650: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    play_footstep_sounds(rdram, ctx);
        goto after_10;
    // 0x8005D650: addiu       $a3, $zero, 0xAC
    ctx->r7 = ADD32(0, 0XAC);
    after_10:
    // 0x8005D654: lw          $t9, 0x74($s1)
    ctx->r25 = MEM_W(ctx->r17, 0X74);
    // 0x8005D658: nop

    // 0x8005D65C: ori         $t2, $t9, 0x3
    ctx->r10 = ctx->r25 | 0X3;
    // 0x8005D660: sw          $t2, 0x74($s1)
    MEM_W(0X74, ctx->r17) = ctx->r10;
L_8005D664:
    // 0x8005D664: lw          $a1, 0x60($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X60);
    // 0x8005D668: jal         0x800AFC3C
    // 0x8005D66C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    obj_spawn_particle(rdram, ctx);
        goto after_11;
    // 0x8005D66C: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_11:
    // 0x8005D670: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8005D674: or          $a1, $s0, $zero
    ctx->r5 = ctx->r16 | 0;
    // 0x8005D678: jal         0x8005D048
    // 0x8005D67C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    fade_when_near_camera(rdram, ctx);
        goto after_12;
    // 0x8005D67C: addiu       $a2, $zero, 0x28
    ctx->r6 = ADD32(0, 0X28);
    after_12:
    // 0x8005D680: jal         0x8001BAC8
    // 0x8005D684: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    get_racer_object(rdram, ctx);
        goto after_13;
    // 0x8005D684: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x8005D688: sw          $v0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r2;
    // 0x8005D68C: lwc1        $f6, 0xC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XC);
    // 0x8005D690: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8005D694: lwc1        $f10, 0x14($s1)
    ctx->f10.u32l = MEM_W(ctx->r17, 0X14);
    // 0x8005D698: sub.s       $f20, $f4, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8005D69C: lwc1        $f8, 0x14($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8005D6A0: mul.s       $f18, $f20, $f20
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f20.fl); 
    ctx->f18.fl = MUL_S(ctx->f20.fl, ctx->f20.fl);
    // 0x8005D6A4: sub.s       $f14, $f8, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8005D6A8: swc1        $f14, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->f14.u32l;
    // 0x8005D6AC: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8005D6B0: jal         0x800C9AD0
    // 0x8005D6B4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_14;
    // 0x8005D6B4: add.s       $f12, $f18, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f18.fl + ctx->f4.fl;
    after_14:
    // 0x8005D6B8: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8005D6BC: lwc1        $f9, 0x6A48($at)
    ctx->f_odd[(9 - 1) * 2] = MEM_W(ctx->r1, 0X6A48);
    // 0x8005D6C0: lwc1        $f8, 0x6A4C($at)
    ctx->f8.u32l = MEM_W(ctx->r1, 0X6A4C);
    // 0x8005D6C4: cvt.d.s     $f6, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); 
    ctx->f6.d = CVT_D_S(ctx->f0.fl);
    // 0x8005D6C8: c.lt.d      $f6, $f8
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f6.d < ctx->f8.d;
    // 0x8005D6CC: lwc1        $f14, 0x50($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X50);
    // 0x8005D6D0: bc1f        L_8005D740
    if (!c1cs) {
        // 0x8005D6D4: nop
    
            goto L_8005D740;
    }
    // 0x8005D6D4: nop

    // 0x8005D6D8: jal         0x80070750
    // 0x8005D6DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    arctan2_f(rdram, ctx);
        goto after_15;
    // 0x8005D6DC: mov.s       $f12, $f20
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 20);
    ctx->f12.fl = ctx->f20.fl;
    after_15:
    // 0x8005D6E0: lh          $t3, 0x0($s1)
    ctx->r11 = MEM_H(ctx->r17, 0X0);
    // 0x8005D6E4: ori         $at, $zero, 0x8000
    ctx->r1 = 0 | 0X8000;
    // 0x8005D6E8: andi        $t5, $t3, 0xFFFF
    ctx->r13 = ctx->r11 & 0XFFFF;
    // 0x8005D6EC: subu        $v1, $v0, $t5
    ctx->r3 = SUB32(ctx->r2, ctx->r13);
    // 0x8005D6F0: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
    // 0x8005D6F4: ori         $at, $zero, 0x8001
    ctx->r1 = 0 | 0X8001;
    // 0x8005D6F8: slt         $at, $v1, $at
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r1) ? 1 : 0;
    // 0x8005D6FC: bne         $at, $zero, L_8005D70C
    if (ctx->r1 != 0) {
        // 0x8005D700: lui         $at, 0xFFFF
        ctx->r1 = S32(0XFFFF << 16);
            goto L_8005D70C;
    }
    // 0x8005D700: lui         $at, 0xFFFF
    ctx->r1 = S32(0XFFFF << 16);
    // 0x8005D704: ori         $at, $at, 0x1
    ctx->r1 = ctx->r1 | 0X1;
    // 0x8005D708: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005D70C:
    // 0x8005D70C: slti        $at, $v1, -0x8000
    ctx->r1 = SIGNED(ctx->r3) < -0X8000 ? 1 : 0;
    // 0x8005D710: beq         $at, $zero, L_8005D71C
    if (ctx->r1 == 0) {
        // 0x8005D714: ori         $at, $zero, 0xFFFF
        ctx->r1 = 0 | 0XFFFF;
            goto L_8005D71C;
    }
    // 0x8005D714: ori         $at, $zero, 0xFFFF
    ctx->r1 = 0 | 0XFFFF;
    // 0x8005D718: addu        $v1, $v1, $at
    ctx->r3 = ADD32(ctx->r3, ctx->r1);
L_8005D71C:
    // 0x8005D71C: slti        $at, $v1, 0xC01
    ctx->r1 = SIGNED(ctx->r3) < 0XC01 ? 1 : 0;
    // 0x8005D720: bne         $at, $zero, L_8005D730
    if (ctx->r1 != 0) {
        // 0x8005D724: slti        $at, $v1, -0xC00
        ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
            goto L_8005D730;
    }
    // 0x8005D724: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
    // 0x8005D728: addiu       $v1, $zero, 0xC00
    ctx->r3 = ADD32(0, 0XC00);
    // 0x8005D72C: slti        $at, $v1, -0xC00
    ctx->r1 = SIGNED(ctx->r3) < -0XC00 ? 1 : 0;
L_8005D730:
    // 0x8005D730: beq         $at, $zero, L_8005D73C
    if (ctx->r1 == 0) {
        // 0x8005D734: nop
    
            goto L_8005D73C;
    }
    // 0x8005D734: nop

    // 0x8005D738: addiu       $v1, $zero, -0xC00
    ctx->r3 = ADD32(0, -0XC00);
L_8005D73C:
    // 0x8005D73C: sh          $v1, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r3;
L_8005D740:
    // 0x8005D740: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D744: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D748: bne         $v1, $at, L_8005D780
    if (ctx->r3 != ctx->r1) {
        // 0x8005D74C: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8005D780;
    }
    // 0x8005D74C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8005D750: lb          $t4, 0x1E7($s0)
    ctx->r12 = MEM_B(ctx->r16, 0X1E7);
    // 0x8005D754: nop

    // 0x8005D758: andi        $t6, $t4, 0x1F
    ctx->r14 = ctx->r12 & 0X1F;
    // 0x8005D75C: slti        $at, $t6, 0xA
    ctx->r1 = SIGNED(ctx->r14) < 0XA ? 1 : 0;
    // 0x8005D760: beq         $at, $zero, L_8005D784
    if (ctx->r1 == 0) {
        // 0x8005D764: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8005D784;
    }
    // 0x8005D764: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8005D768: lh          $t7, 0x16C($s0)
    ctx->r15 = MEM_H(ctx->r16, 0X16C);
    // 0x8005D76C: nop

    // 0x8005D770: sra         $t8, $t7, 1
    ctx->r24 = S32(SIGNED(ctx->r15) >> 1);
    // 0x8005D774: sh          $t8, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = ctx->r24;
    // 0x8005D778: lb          $v1, 0x3B($s1)
    ctx->r3 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D77C: nop

L_8005D780:
    // 0x8005D780: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
L_8005D784:
    // 0x8005D784: bne         $v1, $at, L_8005D790
    if (ctx->r3 != ctx->r1) {
        // 0x8005D788: addiu       $a1, $a1, -0x2A30
        ctx->r5 = ADD32(ctx->r5, -0X2A30);
            goto L_8005D790;
    }
    // 0x8005D788: addiu       $a1, $a1, -0x2A30
    ctx->r5 = ADD32(ctx->r5, -0X2A30);
    // 0x8005D78C: sh          $zero, 0x16C($s0)
    MEM_H(0X16C, ctx->r16) = 0;
L_8005D790:
    // 0x8005D790: lw          $v1, 0x34($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X34);
    // 0x8005D794: nop

    // 0x8005D798: lw          $v0, 0x4C($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X4C);
    // 0x8005D79C: lw          $s0, 0x64($v1)
    ctx->r16 = MEM_W(ctx->r3, 0X64);
    // 0x8005D7A0: lw          $t9, 0x0($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X0);
    // 0x8005D7A4: nop

    // 0x8005D7A8: bne         $s1, $t9, L_8005D7D8
    if (ctx->r17 != ctx->r25) {
        // 0x8005D7AC: nop
    
            goto L_8005D7D8;
    }
    // 0x8005D7AC: nop

    // 0x8005D7B0: lh          $t2, 0x14($v0)
    ctx->r10 = MEM_H(ctx->r2, 0X14);
    // 0x8005D7B4: nop

    // 0x8005D7B8: andi        $t3, $t2, 0x8
    ctx->r11 = ctx->r10 & 0X8;
    // 0x8005D7BC: beq         $t3, $zero, L_8005D7D8
    if (ctx->r11 == 0) {
        // 0x8005D7C0: nop
    
            goto L_8005D7D8;
    }
    // 0x8005D7C0: nop

    // 0x8005D7C4: lb          $t5, 0x3B($s1)
    ctx->r13 = MEM_B(ctx->r17, 0X3B);
    // 0x8005D7C8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8005D7CC: bne         $t5, $at, L_8005D7D8
    if (ctx->r13 != ctx->r1) {
        // 0x8005D7D0: addiu       $t4, $zero, 0x4
        ctx->r12 = ADD32(0, 0X4);
            goto L_8005D7D8;
    }
    // 0x8005D7D0: addiu       $t4, $zero, 0x4
    ctx->r12 = ADD32(0, 0X4);
    // 0x8005D7D4: sb          $t4, 0x187($s0)
    MEM_B(0X187, ctx->r16) = ctx->r12;
L_8005D7D8:
    // 0x8005D7D8: lb          $t6, 0x1D8($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X1D8);
    // 0x8005D7DC: nop

    // 0x8005D7E0: beq         $t6, $zero, L_8005D804
    if (ctx->r14 == 0) {
        // 0x8005D7E4: lw          $ra, 0x2C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X2C);
            goto L_8005D804;
    }
    // 0x8005D7E4: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x8005D7E8: lb          $t7, 0x0($a1)
    ctx->r15 = MEM_B(ctx->r5, 0X0);
    // 0x8005D7EC: addiu       $t8, $zero, 0x1
    ctx->r24 = ADD32(0, 0X1);
    // 0x8005D7F0: bne         $t7, $zero, L_8005D800
    if (ctx->r15 != 0) {
        // 0x8005D7F4: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_8005D800;
    }
    // 0x8005D7F4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8005D7F8: jal         0x8005CB68
    // 0x8005D7FC: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    racer_boss_finish(rdram, ctx);
        goto after_16;
    // 0x8005D7FC: sb          $t8, 0x0($a1)
    MEM_B(0X0, ctx->r5) = ctx->r24;
    after_16:
L_8005D800:
    // 0x8005D800: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
L_8005D804:
    // 0x8005D804: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8005D808: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8005D80C: lw          $s0, 0x24($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X24);
    // 0x8005D810: lw          $s1, 0x28($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X28);
    // 0x8005D814: jr          $ra
    // 0x8005D818: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    return;
    // 0x8005D818: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
;}
RECOMP_FUNC void alFxParamHdl(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80063FAC: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80063FB0: addiu       $v1, $a1, -0x2
    ctx->r3 = ADD32(ctx->r5, -0X2);
    // 0x80063FB4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80063FB8: andi        $t6, $v1, 0x7
    ctx->r14 = ctx->r3 & 0X7;
    // 0x80063FBC: lw          $t0, 0x0($a2)
    ctx->r8 = MEM_W(ctx->r6, 0X0);
    // 0x80063FC0: sltiu       $at, $t6, 0x8
    ctx->r1 = ctx->r14 < 0X8 ? 1 : 0;
    // 0x80063FC4: beq         $at, $zero, L_80064214
    if (ctx->r1 == 0) {
        // 0x80063FC8: or          $a3, $a0, $zero
        ctx->r7 = ctx->r4 | 0;
            goto L_80064214;
    }
    // 0x80063FC8: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
    // 0x80063FCC: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x80063FD0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80063FD4: addu        $at, $at, $t6
    gpr jr_addend_80063FE0 = ctx->r14;
    ctx->r1 = ADD32(ctx->r1, ctx->r14);
    // 0x80063FD8: lw          $t6, 0x6E70($at)
    ctx->r14 = ADD32(ctx->r1, 0X6E70);
    // 0x80063FDC: nop

    // 0x80063FE0: jr          $t6
    // 0x80063FE4: nop

    switch (jr_addend_80063FE0 >> 2) {
        case 0: goto L_80063FE8; break;
        case 1: goto L_8006401C; break;
        case 2: goto L_8006407C; break;
        case 3: goto L_80064050; break;
        case 4: goto L_800640A8; break;
        case 5: goto L_800640D4; break;
        case 6: goto L_80064144; break;
        case 7: goto L_800641C4; break;
        default: switch_error(__func__, 0x80063FE0, 0x800E6E70);
    }
    // 0x80063FE4: nop

L_80063FE8:
    // 0x80063FE8: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80063FEC: and         $t7, $t0, $at
    ctx->r15 = ctx->r8 & ctx->r1;
    // 0x80063FF0: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80063FF4: bgez        $v1, L_80064004
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80063FF8: sra         $t9, $v1, 3
        ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064004;
    }
    // 0x80063FF8: sra         $t9, $v1, 3
    ctx->r25 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80063FFC: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064000: sra         $t9, $at, 3
    ctx->r25 = S32(SIGNED(ctx->r1) >> 3);
L_80064004:
    // 0x80064004: sll         $t1, $t9, 2
    ctx->r9 = S32(ctx->r25 << 2);
    // 0x80064008: addu        $t1, $t1, $t9
    ctx->r9 = ADD32(ctx->r9, ctx->r25);
    // 0x8006400C: sll         $t1, $t1, 3
    ctx->r9 = S32(ctx->r9 << 3);
    // 0x80064010: addu        $t2, $t8, $t1
    ctx->r10 = ADD32(ctx->r24, ctx->r9);
    // 0x80064014: b           L_80064214
    // 0x80064018: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
        goto L_80064214;
    // 0x80064018: sw          $t7, 0x0($t2)
    MEM_W(0X0, ctx->r10) = ctx->r15;
L_8006401C:
    // 0x8006401C: addiu       $at, $zero, -0x8
    ctx->r1 = ADD32(0, -0X8);
    // 0x80064020: and         $t3, $t0, $at
    ctx->r11 = ctx->r8 & ctx->r1;
    // 0x80064024: lw          $t4, 0x20($a3)
    ctx->r12 = MEM_W(ctx->r7, 0X20);
    // 0x80064028: bgez        $v1, L_80064038
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006402C: sra         $t5, $v1, 3
        ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064038;
    }
    // 0x8006402C: sra         $t5, $v1, 3
    ctx->r13 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80064030: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064034: sra         $t5, $at, 3
    ctx->r13 = S32(SIGNED(ctx->r1) >> 3);
L_80064038:
    // 0x80064038: sll         $t6, $t5, 2
    ctx->r14 = S32(ctx->r13 << 2);
    // 0x8006403C: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x80064040: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80064044: addu        $t9, $t4, $t6
    ctx->r25 = ADD32(ctx->r12, ctx->r14);
    // 0x80064048: b           L_80064214
    // 0x8006404C: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
        goto L_80064214;
    // 0x8006404C: sw          $t3, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r11;
L_80064050:
    // 0x80064050: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80064054: bgez        $v1, L_80064064
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064058: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064064;
    }
    // 0x80064058: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x8006405C: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064060: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_80064064:
    // 0x80064064: sll         $t7, $t1, 2
    ctx->r15 = S32(ctx->r9 << 2);
    // 0x80064068: addu        $t7, $t7, $t1
    ctx->r15 = ADD32(ctx->r15, ctx->r9);
    // 0x8006406C: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80064070: addu        $t2, $t8, $t7
    ctx->r10 = ADD32(ctx->r24, ctx->r15);
    // 0x80064074: b           L_80064214
    // 0x80064078: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
        goto L_80064214;
    // 0x80064078: sh          $t0, 0x8($t2)
    MEM_H(0X8, ctx->r10) = ctx->r8;
L_8006407C:
    // 0x8006407C: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x80064080: bgez        $v1, L_80064090
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064084: sra         $t4, $v1, 3
        ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064090;
    }
    // 0x80064084: sra         $t4, $v1, 3
    ctx->r12 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80064088: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x8006408C: sra         $t4, $at, 3
    ctx->r12 = S32(SIGNED(ctx->r1) >> 3);
L_80064090:
    // 0x80064090: sll         $t6, $t4, 2
    ctx->r14 = S32(ctx->r12 << 2);
    // 0x80064094: addu        $t6, $t6, $t4
    ctx->r14 = ADD32(ctx->r14, ctx->r12);
    // 0x80064098: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x8006409C: addu        $t3, $t5, $t6
    ctx->r11 = ADD32(ctx->r13, ctx->r14);
    // 0x800640A0: b           L_80064214
    // 0x800640A4: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
        goto L_80064214;
    // 0x800640A4: sh          $t0, 0xA($t3)
    MEM_H(0XA, ctx->r11) = ctx->r8;
L_800640A8:
    // 0x800640A8: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x800640AC: bgez        $v1, L_800640BC
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800640B0: sra         $t1, $v1, 3
        ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800640BC;
    }
    // 0x800640B0: sra         $t1, $v1, 3
    ctx->r9 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800640B4: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800640B8: sra         $t1, $at, 3
    ctx->r9 = S32(SIGNED(ctx->r1) >> 3);
L_800640BC:
    // 0x800640BC: sll         $t8, $t1, 2
    ctx->r24 = S32(ctx->r9 << 2);
    // 0x800640C0: addu        $t8, $t8, $t1
    ctx->r24 = ADD32(ctx->r24, ctx->r9);
    // 0x800640C4: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x800640C8: addu        $t7, $t9, $t8
    ctx->r15 = ADD32(ctx->r25, ctx->r24);
    // 0x800640CC: b           L_80064214
    // 0x800640D0: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
        goto L_80064214;
    // 0x800640D0: sh          $t0, 0xC($t7)
    MEM_H(0XC, ctx->r15) = ctx->r8;
L_800640D4:
    // 0x800640D4: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x800640D8: lui         $at, 0x447A
    ctx->r1 = S32(0X447A << 16);
    // 0x800640DC: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800640E0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800640E4: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800640E8: div.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x800640EC: lw          $t2, 0x3780($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X3780);
    // 0x800640F0: lw          $t5, 0x20($a3)
    ctx->r13 = MEM_W(ctx->r7, 0X20);
    // 0x800640F4: lw          $t4, 0x44($t2)
    ctx->r12 = MEM_W(ctx->r10, 0X44);
    // 0x800640F8: nop

    // 0x800640FC: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x80064100: nop

    // 0x80064104: cvt.d.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.d = CVT_D_W(ctx->f18.u32l);
    // 0x80064108: cvt.d.s     $f0, $f10
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f0.d = CVT_D_S(ctx->f10.fl);
    // 0x8006410C: add.d       $f16, $f0, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.d); NAN_CHECK(ctx->f0.d); 
    ctx->f16.d = ctx->f0.d + ctx->f0.d;
    // 0x80064110: nop

    // 0x80064114: div.d       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f4.d); 
    ctx->f6.d = DIV_D(ctx->f16.d, ctx->f4.d);
    // 0x80064118: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x8006411C: bgez        $v1, L_8006412C
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80064120: sra         $t6, $v1, 3
        ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
            goto L_8006412C;
    }
    // 0x80064120: sra         $t6, $v1, 3
    ctx->r14 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80064124: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064128: sra         $t6, $at, 3
    ctx->r14 = S32(SIGNED(ctx->r1) >> 3);
L_8006412C:
    // 0x8006412C: sll         $t3, $t6, 2
    ctx->r11 = S32(ctx->r14 << 2);
    // 0x80064130: addu        $t3, $t3, $t6
    ctx->r11 = ADD32(ctx->r11, ctx->r14);
    // 0x80064134: sll         $t3, $t3, 3
    ctx->r11 = S32(ctx->r11 << 3);
    // 0x80064138: addu        $t1, $t5, $t3
    ctx->r9 = ADD32(ctx->r13, ctx->r11);
    // 0x8006413C: b           L_80064214
    // 0x80064140: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
        goto L_80064214;
    // 0x80064140: swc1        $f8, 0x10($t1)
    MEM_W(0X10, ctx->r9) = ctx->f8.u32l;
L_80064144:
    // 0x80064144: lw          $t9, 0x20($a3)
    ctx->r25 = MEM_W(ctx->r7, 0X20);
    // 0x80064148: bgez        $v1, L_80064158
    if (SIGNED(ctx->r3) >= 0) {
        // 0x8006414C: sra         $t8, $v1, 3
        ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
            goto L_80064158;
    }
    // 0x8006414C: sra         $t8, $v1, 3
    ctx->r24 = S32(SIGNED(ctx->r3) >> 3);
    // 0x80064150: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x80064154: sra         $t8, $at, 3
    ctx->r24 = S32(SIGNED(ctx->r1) >> 3);
L_80064158:
    // 0x80064158: sll         $t7, $t8, 2
    ctx->r15 = S32(ctx->r24 << 2);
    // 0x8006415C: addu        $t7, $t7, $t8
    ctx->r15 = ADD32(ctx->r15, ctx->r24);
    // 0x80064160: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80064164: addu        $v0, $t9, $t7
    ctx->r2 = ADD32(ctx->r25, ctx->r15);
    // 0x80064168: lw          $t2, 0x4($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X4);
    // 0x8006416C: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x80064170: mtc1        $t0, $f4
    ctx->f4.u32l = ctx->r8;
    // 0x80064174: subu        $t6, $t2, $t4
    ctx->r14 = SUB32(ctx->r10, ctx->r12);
    // 0x80064178: mtc1        $t6, $f10
    ctx->f10.u32l = ctx->r14;
    // 0x8006417C: bgez        $t6, L_80064198
    if (SIGNED(ctx->r14) >= 0) {
        // 0x80064180: cvt.d.w     $f18, $f10
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
            goto L_80064198;
    }
    // 0x80064180: cvt.d.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.d = CVT_D_W(ctx->f10.u32l);
    // 0x80064184: lui         $at, 0x41F0
    ctx->r1 = S32(0X41F0 << 16);
    // 0x80064188: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x8006418C: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x80064190: nop

    // 0x80064194: add.d       $f18, $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = ctx->f18.d + ctx->f16.d;
L_80064198:
    // 0x80064198: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x8006419C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800641A0: lwc1        $f11, 0x6E90($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, 0X6E90);
    // 0x800641A4: lwc1        $f10, 0x6E94($at)
    ctx->f10.u32l = MEM_W(ctx->r1, 0X6E94);
    // 0x800641A8: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800641AC: nop

    // 0x800641B0: div.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = DIV_D(ctx->f8.d, ctx->f10.d);
    // 0x800641B4: mul.d       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f16.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f16.d);
    // 0x800641B8: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800641BC: b           L_80064214
    // 0x800641C0: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
        goto L_80064214;
    // 0x800641C0: swc1        $f6, 0x1C($v0)
    MEM_W(0X1C, ctx->r2) = ctx->f6.u32l;
L_800641C4:
    // 0x800641C4: bgez        $v1, L_800641D4
    if (SIGNED(ctx->r3) >= 0) {
        // 0x800641C8: sra         $v0, $v1, 3
        ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
            goto L_800641D4;
    }
    // 0x800641C8: sra         $v0, $v1, 3
    ctx->r2 = S32(SIGNED(ctx->r3) >> 3);
    // 0x800641CC: addiu       $at, $v1, 0x7
    ctx->r1 = ADD32(ctx->r3, 0X7);
    // 0x800641D0: sra         $v0, $at, 3
    ctx->r2 = S32(SIGNED(ctx->r1) >> 3);
L_800641D4:
    // 0x800641D4: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x800641D8: lw          $t3, 0x20($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X20);
    // 0x800641DC: addu        $t5, $t5, $v0
    ctx->r13 = ADD32(ctx->r13, ctx->r2);
    // 0x800641E0: sll         $t5, $t5, 3
    ctx->r13 = S32(ctx->r13 << 3);
    // 0x800641E4: addu        $t1, $t3, $t5
    ctx->r9 = ADD32(ctx->r11, ctx->r13);
    // 0x800641E8: lw          $a1, 0x20($t1)
    ctx->r5 = MEM_W(ctx->r9, 0X20);
    // 0x800641EC: nop

    // 0x800641F0: beq         $a1, $zero, L_80064218
    if (ctx->r5 == 0) {
        // 0x800641F4: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80064218;
    }
    // 0x800641F4: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800641F8: sh          $t0, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r8;
    // 0x800641FC: lw          $t8, 0x20($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X20);
    // 0x80064200: nop

    // 0x80064204: addu        $t9, $t8, $t5
    ctx->r25 = ADD32(ctx->r24, ctx->r13);
    // 0x80064208: lw          $a0, 0x20($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X20);
    // 0x8006420C: jal         0x80064950
    // 0x80064210: nop

    init_lpfilter(rdram, ctx);
        goto after_0;
    // 0x80064210: nop

    after_0:
L_80064214:
    // 0x80064214: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80064218:
    // 0x80064218: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8006421C: jr          $ra
    // 0x80064220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x80064220: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void load_menu_with_level_background(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006DA28: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x8006DA2C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8006DA30: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x8006DA34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8006DA38: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006DA3C: jal         0x8006ECFC
    // 0x8006DA40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    alloc_displaylist_heap(rdram, ctx);
        goto after_0;
    // 0x8006DA40: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x8006DA44: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8006DA48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA4C: sw          $v0, 0x34EC($at)
    MEM_W(0X34EC, ctx->r1) = ctx->r2;
    // 0x8006DA50: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DA54: sw          $v0, 0x34F0($at)
    MEM_W(0X34F0, ctx->r1) = ctx->r2;
    // 0x8006DA58: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x8006DA5C: jal         0x80004A60
    // 0x8006DA60: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_1;
    // 0x8006DA60: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_1:
    // 0x8006DA64: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8006DA68: jal         0x80004A60
    // 0x8006DA6C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_2;
    // 0x8006DA6C: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_2:
    // 0x8006DA70: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    // 0x8006DA74: jal         0x80004A60
    // 0x8006DA78: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    sndp_set_group_volume(rdram, ctx);
        goto after_3;
    // 0x8006DA78: addiu       $a1, $zero, 0x7FFF
    ctx->r5 = ADD32(0, 0X7FFF);
    after_3:
    // 0x8006DA7C: jal         0x80065EA0
    // 0x8006DA80: nop

    cam_init(rdram, ctx);
        goto after_4;
    // 0x8006DA80: nop

    after_4:
    // 0x8006DA84: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8006DA88: addiu       $v0, $v0, 0x3514
    ctx->r2 = ADD32(ctx->r2, 0X3514);
    // 0x8006DA8C: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8006DA90: lw          $a0, 0x24($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X24);
    // 0x8006DA94: bne         $t6, $zero, L_8006DAC8
    if (ctx->r14 != 0) {
        // 0x8006DA98: nop
    
            goto L_8006DAC8;
    }
    // 0x8006DA98: nop

    // 0x8006DA9C: bgez        $a0, L_8006DAB0
    if (SIGNED(ctx->r4) >= 0) {
        // 0x8006DAA0: sb          $zero, 0x0($v0)
        MEM_B(0X0, ctx->r2) = 0;
            goto L_8006DAB0;
    }
    // 0x8006DAA0: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
    // 0x8006DAA4: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x8006DAA8: b           L_8006DAC8
    // 0x8006DAAC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
        goto L_8006DAC8;
    // 0x8006DAAC: sb          $t7, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r15;
L_8006DAB0:
    // 0x8006DAB0: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x8006DAB4: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x8006DAB8: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8006DABC: addiu       $a3, $zero, 0x2
    ctx->r7 = ADD32(0, 0X2);
    // 0x8006DAC0: jal         0x8006DB3C
    // 0x8006DAC4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    load_level_menu(rdram, ctx);
        goto after_5;
    // 0x8006DAC4: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    after_5:
L_8006DAC8:
    // 0x8006DAC8: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DACC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8006DAD0: beq         $a0, $at, L_8006DAE8
    if (ctx->r4 == ctx->r1) {
        // 0x8006DAD4: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_8006DAE8;
    }
    // 0x8006DAD4: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8006DAD8: beq         $a0, $at, L_8006DAE8
    if (ctx->r4 == ctx->r1) {
        // 0x8006DADC: nop
    
            goto L_8006DAE8;
    }
    // 0x8006DADC: nop

    // 0x8006DAE0: bne         $a0, $zero, L_8006DAF8
    if (ctx->r4 != 0) {
        // 0x8006DAE4: nop
    
            goto L_8006DAF8;
    }
    // 0x8006DAE4: nop

L_8006DAE8:
    // 0x8006DAE8: jal         0x800813C0
    // 0x8006DAEC: nop

    reset_title_logo_scale(rdram, ctx);
        goto after_6;
    // 0x8006DAEC: nop

    after_6:
    // 0x8006DAF0: lw          $a0, 0x20($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X20);
    // 0x8006DAF4: nop

L_8006DAF8:
    // 0x8006DAF8: jal         0x800813D0
    // 0x8006DAFC: nop

    menu_init(rdram, ctx);
        goto after_7;
    // 0x8006DAFC: nop

    after_7:
    // 0x8006DB00: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8006DB04: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8006DB08: sw          $zero, 0x3504($at)
    MEM_W(0X3504, ctx->r1) = 0;
    // 0x8006DB0C: jr          $ra
    // 0x8006DB10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x8006DB10: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void filename_compress(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80097744: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x80097748: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009774C: blez        $a1, L_800977C8
    if (SIGNED(ctx->r5) <= 0) {
        // 0x80097750: or          $a2, $zero, $zero
        ctx->r6 = 0 | 0;
            goto L_800977C8;
    }
    // 0x80097750: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x80097754: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x80097758: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x8009775C: lbu         $t3, 0xF6C($t2)
    ctx->r11 = MEM_BU(ctx->r10, 0XF6C);
    // 0x80097760: addiu       $t4, $t4, 0xF6C
    ctx->r12 = ADD32(ctx->r12, 0XF6C);
    // 0x80097764: or          $a3, $a0, $zero
    ctx->r7 = ctx->r4 | 0;
L_80097768:
    // 0x80097768: lbu         $a0, 0x0($a3)
    ctx->r4 = MEM_BU(ctx->r7, 0X0);
    // 0x8009776C: or          $t1, $zero, $zero
    ctx->r9 = 0 | 0;
    // 0x80097770: bne         $a0, $zero, L_8009777C
    if (ctx->r4 != 0) {
        // 0x80097774: sll         $t8, $v1, 5
        ctx->r24 = S32(ctx->r3 << 5);
            goto L_8009777C;
    }
    // 0x80097774: sll         $t8, $v1, 5
    ctx->r24 = S32(ctx->r3 << 5);
    // 0x80097778: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009777C:
    // 0x8009777C: bne         $v0, $zero, L_8009778C
    if (ctx->r2 != 0) {
        // 0x80097780: addiu       $a2, $a2, 0x1
        ctx->r6 = ADD32(ctx->r6, 0X1);
            goto L_8009778C;
    }
    // 0x80097780: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
    // 0x80097784: b           L_80097790
    // 0x80097788: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
        goto L_80097790;
    // 0x80097788: addiu       $t0, $zero, 0x20
    ctx->r8 = ADD32(0, 0X20);
L_8009778C:
    // 0x8009778C: andi        $t0, $a0, 0xFF
    ctx->r8 = ctx->r4 & 0XFF;
L_80097790:
    // 0x80097790: beq         $t0, $t3, L_800977B8
    if (ctx->r8 == ctx->r11) {
        // 0x80097794: or          $a0, $t0, $zero
        ctx->r4 = ctx->r8 | 0;
            goto L_800977B8;
    }
    // 0x80097794: or          $a0, $t0, $zero
    ctx->r4 = ctx->r8 | 0;
L_80097798:
    // 0x80097798: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x8009779C: slti        $at, $t1, 0x1F
    ctx->r1 = SIGNED(ctx->r9) < 0X1F ? 1 : 0;
    // 0x800977A0: beq         $at, $zero, L_800977B8
    if (ctx->r1 == 0) {
        // 0x800977A4: addu        $t6, $t4, $t1
        ctx->r14 = ADD32(ctx->r12, ctx->r9);
            goto L_800977B8;
    }
    // 0x800977A4: addu        $t6, $t4, $t1
    ctx->r14 = ADD32(ctx->r12, ctx->r9);
    // 0x800977A8: lbu         $t7, 0x0($t6)
    ctx->r15 = MEM_BU(ctx->r14, 0X0);
    // 0x800977AC: nop

    // 0x800977B0: bne         $a0, $t7, L_80097798
    if (ctx->r4 != ctx->r15) {
        // 0x800977B4: nop
    
            goto L_80097798;
    }
    // 0x800977B4: nop

L_800977B8:
    // 0x800977B8: andi        $t9, $t1, 0x1F
    ctx->r25 = ctx->r9 & 0X1F;
    // 0x800977BC: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800977C0: bne         $a2, $a1, L_80097768
    if (ctx->r6 != ctx->r5) {
        // 0x800977C4: or          $v1, $t8, $t9
        ctx->r3 = ctx->r24 | ctx->r25;
            goto L_80097768;
    }
    // 0x800977C4: or          $v1, $t8, $t9
    ctx->r3 = ctx->r24 | ctx->r25;
L_800977C8:
    // 0x800977C8: jr          $ra
    // 0x800977CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800977CC: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void menu_pause_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80094170: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x80094174: lw          $t6, 0x984($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X984);
    // 0x80094178: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8009417C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80094180: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x80094184: bne         $t6, $zero, L_8009419C
    if (ctx->r14 != 0) {
        // 0x80094188: sw          $a1, 0x1C($sp)
        MEM_W(0X1C, ctx->r29) = ctx->r5;
            goto L_8009419C;
    }
    // 0x80094188: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x8009418C: jal         0x80000968
    // 0x80094190: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_0;
    // 0x80094190: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_0:
    // 0x80094194: b           L_800945A0
    // 0x80094198: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_800945A0;
    // 0x80094198: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009419C:
    // 0x8009419C: jal         0x80000968
    // 0x800941A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sound_volume_change(rdram, ctx);
        goto after_1;
    // 0x800941A0: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800941A4: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800941A8: addiu       $v0, $v0, 0x63BC
    ctx->r2 = ADD32(ctx->r2, 0X63BC);
    // 0x800941AC: lw          $t7, 0x0($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X0);
    // 0x800941B0: lw          $t8, 0x1C($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X1C);
    // 0x800941B4: nop

    // 0x800941B8: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800941BC: andi        $t1, $t9, 0x3F
    ctx->r9 = ctx->r25 & 0X3F;
    // 0x800941C0: jal         0x8009BF20
    // 0x800941C4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    update_controller_sticks(rdram, ctx);
        goto after_2;
    // 0x800941C4: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
    after_2:
    // 0x800941C8: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800941CC: lw          $t2, 0x63C4($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X63C4);
    // 0x800941D0: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800941D4: bne         $t2, $zero, L_800941EC
    if (ctx->r10 != 0) {
        // 0x800941D8: lui         $a0, 0x800E
        ctx->r4 = S32(0X800E << 16);
            goto L_800941EC;
    }
    // 0x800941D8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800941DC: lw          $a0, 0x98C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X98C);
    // 0x800941E0: jal         0x8006A554
    // 0x800941E4: nop

    input_pressed(rdram, ctx);
        goto after_3;
    // 0x800941E4: nop

    after_3:
    // 0x800941E8: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800941EC:
    // 0x800941EC: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x800941F0: addiu       $a2, $a2, -0xB84
    ctx->r6 = ADD32(ctx->r6, -0XB84);
    // 0x800941F4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800941F8: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x800941FC: bne         $v0, $zero, L_800943E8
    if (ctx->r2 != 0) {
        // 0x80094200: addiu       $t5, $v0, 0x1
        ctx->r13 = ADD32(ctx->r2, 0X1);
            goto L_800943E8;
    }
    // 0x80094200: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x80094204: addiu       $t0, $t0, 0x988
    ctx->r8 = ADD32(ctx->r8, 0X988);
    // 0x80094208: lw          $v0, 0x0($t0)
    ctx->r2 = MEM_W(ctx->r8, 0X0);
    // 0x8009420C: andi        $t3, $v1, 0x9000
    ctx->r11 = ctx->r3 & 0X9000;
    // 0x80094210: beq         $v0, $zero, L_800942C4
    if (ctx->r2 == 0) {
        // 0x80094214: andi        $t1, $v1, 0x9000
        ctx->r9 = ctx->r3 & 0X9000;
            goto L_800942C4;
    }
    // 0x80094214: andi        $t1, $v1, 0x9000
    ctx->r9 = ctx->r3 & 0X9000;
    // 0x80094218: beq         $t3, $zero, L_80094258
    if (ctx->r11 == 0) {
        // 0x8009421C: andi        $t5, $v1, 0x4000
        ctx->r13 = ctx->r3 & 0X4000;
            goto L_80094258;
    }
    // 0x8009421C: andi        $t5, $v1, 0x4000
    ctx->r13 = ctx->r3 & 0X4000;
    // 0x80094220: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80094224: jal         0x80001D04
    // 0x80094228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x80094228: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8009422C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80094230: addiu       $t0, $t0, 0x988
    ctx->r8 = ADD32(ctx->r8, 0X988);
    // 0x80094234: lw          $t4, 0x0($t0)
    ctx->r12 = MEM_W(ctx->r8, 0X0);
    // 0x80094238: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009423C: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80094240: bne         $v0, $t4, L_80094250
    if (ctx->r2 != ctx->r12) {
        // 0x80094244: addiu       $a2, $a2, -0xB84
        ctx->r6 = ADD32(ctx->r6, -0XB84);
            goto L_80094250;
    }
    // 0x80094244: addiu       $a2, $a2, -0xB84
    ctx->r6 = ADD32(ctx->r6, -0XB84);
    // 0x80094248: b           L_80094588
    // 0x8009424C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80094588;
    // 0x8009424C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80094250:
    // 0x80094250: b           L_80094588
    // 0x80094254: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80094588;
    // 0x80094254: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_80094258:
    // 0x80094258: beq         $t5, $zero, L_8009427C
    if (ctx->r13 == 0) {
        // 0x8009425C: sll         $a1, $v0, 24
        ctx->r5 = S32(ctx->r2 << 24);
            goto L_8009427C;
    }
    // 0x8009425C: sll         $a1, $v0, 24
    ctx->r5 = S32(ctx->r2 << 24);
    // 0x80094260: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x80094264: jal         0x80001D04
    // 0x80094268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_5;
    // 0x80094268: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_5:
    // 0x8009426C: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80094270: addiu       $t0, $t0, 0x988
    ctx->r8 = ADD32(ctx->r8, 0X988);
    // 0x80094274: b           L_80094588
    // 0x80094278: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
        goto L_80094588;
    // 0x80094278: sw          $zero, 0x0($t0)
    MEM_W(0X0, ctx->r8) = 0;
L_8009427C:
    // 0x8009427C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094280: lw          $a0, 0x98C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X98C);
    // 0x80094284: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x80094288: addu        $t7, $t7, $a0
    ctx->r15 = ADD32(ctx->r15, ctx->r4);
    // 0x8009428C: lb          $t7, 0x6464($t7)
    ctx->r15 = MEM_B(ctx->r15, 0X6464);
    // 0x80094290: sra         $t6, $a1, 24
    ctx->r14 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80094294: beq         $t7, $zero, L_800942AC
    if (ctx->r15 == 0) {
        // 0x80094298: or          $a1, $t6, $zero
        ctx->r5 = ctx->r14 | 0;
            goto L_800942AC;
    }
    // 0x80094298: or          $a1, $t6, $zero
    ctx->r5 = ctx->r14 | 0;
    // 0x8009429C: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x800942A0: subu        $t9, $t8, $v0
    ctx->r25 = SUB32(ctx->r24, ctx->r2);
    // 0x800942A4: sw          $t9, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r25;
    // 0x800942A8: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_800942AC:
    // 0x800942AC: beq         $a1, $v0, L_80094588
    if (ctx->r5 == ctx->r2) {
        // 0x800942B0: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_80094588;
    }
    // 0x800942B0: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800942B4: jal         0x80001D04
    // 0x800942B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x800942B8: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x800942BC: b           L_8009458C
    // 0x800942C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_8009458C;
    // 0x800942C0: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800942C4:
    // 0x800942C4: beq         $t1, $zero, L_80094350
    if (ctx->r9 == 0) {
        // 0x800942C8: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80094350;
    }
    // 0x800942C8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800942CC: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x800942D0: jal         0x80001D04
    // 0x800942D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_7;
    // 0x800942D4: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_7:
    // 0x800942D8: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800942DC: addiu       $a3, $a3, 0x6A68
    ctx->r7 = ADD32(ctx->r7, 0X6A68);
    // 0x800942E0: lw          $t2, 0x0($a3)
    ctx->r10 = MEM_W(ctx->r7, 0X0);
    // 0x800942E4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800942E8: lw          $v1, -0xB60($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB60);
    // 0x800942EC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800942F0: sll         $t3, $t2, 2
    ctx->r11 = S32(ctx->r10 << 2);
    // 0x800942F4: addu        $v0, $v0, $t3
    ctx->r2 = ADD32(ctx->r2, ctx->r11);
    // 0x800942F8: lw          $v0, 0x6A40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A40);
    // 0x800942FC: lw          $t4, 0x20C($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X20C);
    // 0x80094300: lui         $a2, 0x800E
    ctx->r6 = S32(0X800E << 16);
    // 0x80094304: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80094308: addiu       $t0, $t0, 0x988
    ctx->r8 = ADD32(ctx->r8, 0X988);
    // 0x8009430C: beq         $v0, $t4, L_80094338
    if (ctx->r2 == ctx->r12) {
        // 0x80094310: addiu       $a2, $a2, -0xB84
        ctx->r6 = ADD32(ctx->r6, -0XB84);
            goto L_80094338;
    }
    // 0x80094310: addiu       $a2, $a2, -0xB84
    ctx->r6 = ADD32(ctx->r6, -0XB84);
    // 0x80094314: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094318: addiu       $a0, $a0, 0xFE8
    ctx->r4 = ADD32(ctx->r4, 0XFE8);
    // 0x8009431C: lw          $t5, 0x0($a0)
    ctx->r13 = MEM_W(ctx->r4, 0X0);
    // 0x80094320: nop

    // 0x80094324: beq         $t5, $zero, L_80094344
    if (ctx->r13 == 0) {
        // 0x80094328: nop
    
            goto L_80094344;
    }
    // 0x80094328: nop

    // 0x8009432C: lw          $t6, 0x204($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X204);
    // 0x80094330: nop

    // 0x80094334: bne         $v0, $t6, L_80094344
    if (ctx->r2 != ctx->r14) {
        // 0x80094338: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_80094344;
    }
L_80094338:
    // 0x80094338: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8009433C: b           L_80094588
    // 0x80094340: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
        goto L_80094588;
    // 0x80094340: sw          $t7, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r15;
L_80094344:
    // 0x80094344: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80094348: b           L_80094588
    // 0x8009434C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
        goto L_80094588;
    // 0x8009434C: sw          $v0, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r2;
L_80094350:
    // 0x80094350: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094354: lw          $a0, 0x98C($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X98C);
    // 0x80094358: addiu       $a3, $a3, 0x6A68
    ctx->r7 = ADD32(ctx->r7, 0X6A68);
    // 0x8009435C: lw          $v0, 0x0($a3)
    ctx->r2 = MEM_W(ctx->r7, 0X0);
    // 0x80094360: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80094364: addu        $v1, $v1, $a0
    ctx->r3 = ADD32(ctx->r3, ctx->r4);
    // 0x80094368: lb          $v1, 0x6464($v1)
    ctx->r3 = MEM_B(ctx->r3, 0X6464);
    // 0x8009436C: sll         $a1, $v0, 24
    ctx->r5 = S32(ctx->r2 << 24);
    // 0x80094370: sra         $t8, $a1, 24
    ctx->r24 = S32(SIGNED(ctx->r5) >> 24);
    // 0x80094374: bgez        $v1, L_80094388
    if (SIGNED(ctx->r3) >= 0) {
        // 0x80094378: or          $a1, $t8, $zero
        ctx->r5 = ctx->r24 | 0;
            goto L_80094388;
    }
    // 0x80094378: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8009437C: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x80094380: sw          $t9, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r25;
    // 0x80094384: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
L_80094388:
    // 0x80094388: blez        $v1, L_8009439C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8009438C: lui         $t4, 0x800E
        ctx->r12 = S32(0X800E << 16);
            goto L_8009439C;
    }
    // 0x8009438C: lui         $t4, 0x800E
    ctx->r12 = S32(0X800E << 16);
    // 0x80094390: addiu       $t1, $v0, -0x1
    ctx->r9 = ADD32(ctx->r2, -0X1);
    // 0x80094394: sw          $t1, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r9;
    // 0x80094398: or          $v0, $t1, $zero
    ctx->r2 = ctx->r9 | 0;
L_8009439C:
    // 0x8009439C: bgez        $v0, L_800943B4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x800943A0: lui         $t2, 0x800E
        ctx->r10 = S32(0X800E << 16);
            goto L_800943B4;
    }
    // 0x800943A0: lui         $t2, 0x800E
    ctx->r10 = S32(0X800E << 16);
    // 0x800943A4: lw          $t2, 0x984($t2)
    ctx->r10 = MEM_W(ctx->r10, 0X984);
    // 0x800943A8: nop

    // 0x800943AC: addiu       $v0, $t2, -0x1
    ctx->r2 = ADD32(ctx->r10, -0X1);
    // 0x800943B0: sw          $v0, 0x0($a3)
    MEM_W(0X0, ctx->r7) = ctx->r2;
L_800943B4:
    // 0x800943B4: lw          $t4, 0x984($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X984);
    // 0x800943B8: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x800943BC: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x800943C0: bne         $at, $zero, L_800943D0
    if (ctx->r1 != 0) {
        // 0x800943C4: nop
    
            goto L_800943D0;
    }
    // 0x800943C4: nop

    // 0x800943C8: sw          $zero, 0x0($a3)
    MEM_W(0X0, ctx->r7) = 0;
    // 0x800943CC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800943D0:
    // 0x800943D0: beq         $a1, $v0, L_80094588
    if (ctx->r5 == ctx->r2) {
        // 0x800943D4: nop
    
            goto L_80094588;
    }
    // 0x800943D4: nop

    // 0x800943D8: jal         0x80001D04
    // 0x800943DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x800943DC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x800943E0: b           L_8009458C
    // 0x800943E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
        goto L_8009458C;
    // 0x800943E4: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_800943E8:
    // 0x800943E8: slti        $at, $t5, 0x4
    ctx->r1 = SIGNED(ctx->r13) < 0X4 ? 1 : 0;
    // 0x800943EC: bne         $at, $zero, L_80094588
    if (ctx->r1 != 0) {
        // 0x800943F0: sw          $t5, 0x0($a2)
        MEM_W(0X0, ctx->r6) = ctx->r13;
            goto L_80094588;
    }
    // 0x800943F0: sw          $t5, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r13;
    // 0x800943F4: jal         0x800945B0
    // 0x800943F8: nop

    menu_dialogue_end(rdram, ctx);
        goto after_9;
    // 0x800943F8: nop

    after_9:
    // 0x800943FC: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x80094400: addiu       $t0, $t0, 0x988
    ctx->r8 = ADD32(ctx->r8, 0X988);
    // 0x80094404: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x80094408: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8009440C: bne         $v0, $t7, L_80094458
    if (ctx->r2 != ctx->r15) {
        // 0x80094410: lui         $a3, 0x8012
        ctx->r7 = S32(0X8012 << 16);
            goto L_80094458;
    }
    // 0x80094410: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x80094414: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x80094418: addiu       $a0, $a0, 0xFE8
    ctx->r4 = ADD32(ctx->r4, 0XFE8);
    // 0x8009441C: lw          $t8, 0x0($a0)
    ctx->r24 = MEM_W(ctx->r4, 0X0);
    // 0x80094420: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x80094424: beq         $t8, $zero, L_80094450
    if (ctx->r24 == 0) {
        // 0x80094428: nop
    
            goto L_80094450;
    }
    // 0x80094428: nop

    // 0x8009442C: sw          $zero, 0x0($a0)
    MEM_W(0X0, ctx->r4) = 0;
    // 0x80094430: lw          $t9, -0xB48($t9)
    ctx->r25 = MEM_W(ctx->r25, -0XB48);
    // 0x80094434: nop

    // 0x80094438: bne         $t9, $zero, L_80094448
    if (ctx->r25 != 0) {
        // 0x8009443C: nop
    
            goto L_80094448;
    }
    // 0x8009443C: nop

    // 0x80094440: b           L_800945A0
    // 0x80094444: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800945A0;
    // 0x80094444: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80094448:
    // 0x80094448: b           L_800945A0
    // 0x8009444C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800945A0;
    // 0x8009444C: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80094450:
    // 0x80094450: b           L_800945A0
    // 0x80094454: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
        goto L_800945A0;
    // 0x80094454: addiu       $v0, $zero, 0x4
    ctx->r2 = ADD32(0, 0X4);
L_80094458:
    // 0x80094458: addiu       $a3, $a3, 0x6A68
    ctx->r7 = ADD32(ctx->r7, 0X6A68);
    // 0x8009445C: lw          $t1, 0x0($a3)
    ctx->r9 = MEM_W(ctx->r7, 0X0);
    // 0x80094460: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80094464: lw          $v1, -0xB60($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB60);
    // 0x80094468: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8009446C: sll         $t2, $t1, 2
    ctx->r10 = S32(ctx->r9 << 2);
    // 0x80094470: addu        $v0, $v0, $t2
    ctx->r2 = ADD32(ctx->r2, ctx->r10);
    // 0x80094474: lw          $v0, 0x6A40($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X6A40);
    // 0x80094478: lw          $t3, 0x188($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X188);
    // 0x8009447C: nop

    // 0x80094480: bne         $v0, $t3, L_80094498
    if (ctx->r2 != ctx->r11) {
        // 0x80094484: nop
    
            goto L_80094498;
    }
    // 0x80094484: nop

    // 0x80094488: jal         0x80000968
    // 0x8009448C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_10;
    // 0x8009448C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_10:
    // 0x80094490: b           L_800945A0
    // 0x80094494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800945A0;
    // 0x80094494: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80094498:
    // 0x80094498: lw          $t4, 0x1F8($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X1F8);
    // 0x8009449C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800944A0: beq         $v0, $t4, L_800944B8
    if (ctx->r2 == ctx->r12) {
        // 0x800944A4: nop
    
            goto L_800944B8;
    }
    // 0x800944A4: nop

    // 0x800944A8: lw          $t5, 0x1FC($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X1FC);
    // 0x800944AC: nop

    // 0x800944B0: bne         $v0, $t5, L_80094518
    if (ctx->r2 != ctx->r13) {
        // 0x800944B4: nop
    
            goto L_80094518;
    }
    // 0x800944B4: nop

L_800944B8:
    // 0x800944B8: lw          $t6, -0xB48($t6)
    ctx->r14 = MEM_W(ctx->r14, -0XB48);
    // 0x800944BC: nop

    // 0x800944C0: bne         $t6, $zero, L_80094510
    if (ctx->r14 != 0) {
        // 0x800944C4: nop
    
            goto L_80094510;
    }
    // 0x800944C4: nop

    // 0x800944C8: jal         0x8006EB14
    // 0x800944CC: nop

    get_ingame_map_id(rdram, ctx);
        goto after_11;
    // 0x800944CC: nop

    after_11:
    // 0x800944D0: sll         $t7, $v0, 1
    ctx->r15 = S32(ctx->r2 << 1);
    // 0x800944D4: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800944D8: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x800944DC: lh          $t8, 0x758($t8)
    ctx->r24 = MEM_H(ctx->r24, 0X758);
    // 0x800944E0: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800944E4: beq         $t8, $at, L_80094510
    if (ctx->r24 == ctx->r1) {
        // 0x800944E8: nop
    
            goto L_80094510;
    }
    // 0x800944E8: nop

    // 0x800944EC: jal         0x8006EB14
    // 0x800944F0: nop

    get_ingame_map_id(rdram, ctx);
        goto after_12;
    // 0x800944F0: nop

    after_12:
    // 0x800944F4: sll         $t9, $v0, 1
    ctx->r25 = S32(ctx->r2 << 1);
    // 0x800944F8: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x800944FC: addu        $a0, $a0, $t9
    ctx->r4 = ADD32(ctx->r4, ctx->r25);
    // 0x80094500: lhu         $a0, 0x758($a0)
    ctx->r4 = MEM_HU(ctx->r4, 0X758);
    // 0x80094504: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x80094508: jal         0x80000FDC
    // 0x8009450C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    sound_play_delayed(rdram, ctx);
        goto after_13;
    // 0x8009450C: lui         $a2, 0x3F80
    ctx->r6 = S32(0X3F80 << 16);
    after_13:
L_80094510:
    // 0x80094510: b           L_800945A0
    // 0x80094514: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_800945A0;
    // 0x80094514: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80094518:
    // 0x80094518: lw          $t1, 0x64($v1)
    ctx->r9 = MEM_W(ctx->r3, 0X64);
    // 0x8009451C: nop

    // 0x80094520: bne         $v0, $t1, L_80094530
    if (ctx->r2 != ctx->r9) {
        // 0x80094524: nop
    
            goto L_80094530;
    }
    // 0x80094524: nop

    // 0x80094528: b           L_800945A0
    // 0x8009452C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_800945A0;
    // 0x8009452C: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80094530:
    // 0x80094530: lw          $t2, 0x60($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X60);
    // 0x80094534: nop

    // 0x80094538: bne         $v0, $t2, L_80094548
    if (ctx->r2 != ctx->r10) {
        // 0x8009453C: nop
    
            goto L_80094548;
    }
    // 0x8009453C: nop

    // 0x80094540: b           L_800945A0
    // 0x80094544: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_800945A0;
    // 0x80094544: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
L_80094548:
    // 0x80094548: lw          $t3, 0x68($v1)
    ctx->r11 = MEM_W(ctx->r3, 0X68);
    // 0x8009454C: nop

    // 0x80094550: bne         $v0, $t3, L_80094560
    if (ctx->r2 != ctx->r11) {
        // 0x80094554: nop
    
            goto L_80094560;
    }
    // 0x80094554: nop

    // 0x80094558: b           L_800945A0
    // 0x8009455C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
        goto L_800945A0;
    // 0x8009455C: addiu       $v0, $zero, 0xC
    ctx->r2 = ADD32(0, 0XC);
L_80094560:
    // 0x80094560: lw          $t4, 0x200($v1)
    ctx->r12 = MEM_W(ctx->r3, 0X200);
    // 0x80094564: nop

    // 0x80094568: bne         $v0, $t4, L_80094580
    if (ctx->r2 != ctx->r12) {
        // 0x8009456C: nop
    
            goto L_80094580;
    }
    // 0x8009456C: nop

    // 0x80094570: jal         0x80000968
    // 0x80094574: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sound_volume_change(rdram, ctx);
        goto after_14;
    // 0x80094574: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_14:
    // 0x80094578: b           L_800945A0
    // 0x8009457C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_800945A0;
    // 0x8009457C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80094580:
    // 0x80094580: b           L_800945A0
    // 0x80094584: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_800945A0;
    // 0x80094584: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80094588:
    // 0x80094588: lw          $a0, 0x1C($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X1C);
L_8009458C:
    // 0x8009458C: jal         0x80093D40
    // 0x80094590: nop

    pausemenu_render(rdram, ctx);
        goto after_15;
    // 0x80094590: nop

    after_15:
    // 0x80094594: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80094598: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
    // 0x8009459C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800945A0:
    // 0x800945A0: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x800945A4: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x800945A8: jr          $ra
    // 0x800945AC: nop

    return;
    // 0x800945AC: nop

;}
RECOMP_FUNC void music_channel_volume_set(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800011E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x800011EC: andi        $a3, $a0, 0xFF
    ctx->r7 = ctx->r4 & 0XFF;
    // 0x800011F0: slti        $at, $a3, 0x10
    ctx->r1 = SIGNED(ctx->r7) < 0X10 ? 1 : 0;
    // 0x800011F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800011F8: sw          $a0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r4;
    // 0x800011FC: sw          $a1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r5;
    // 0x80001200: beq         $at, $zero, L_80001218
    if (ctx->r1 == 0) {
        // 0x80001204: andi        $a2, $a1, 0xFF
        ctx->r6 = ctx->r5 & 0XFF;
            goto L_80001218;
    }
    // 0x80001204: andi        $a2, $a1, 0xFF
    ctx->r6 = ctx->r5 & 0XFF;
    // 0x80001208: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8000120C: lw          $a0, -0x39D0($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X39D0);
    // 0x80001210: jal         0x800C7940
    // 0x80001214: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    alCSPSetChlVol(rdram, ctx);
        goto after_0;
    // 0x80001214: andi        $a1, $a3, 0xFF
    ctx->r5 = ctx->r7 & 0XFF;
    after_0:
L_80001218:
    // 0x80001218: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8000121C: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x80001220: jr          $ra
    // 0x80001224: nop

    return;
    // 0x80001224: nop

;}
RECOMP_FUNC void mtxf_to_mtx(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F870: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x8006F874: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x8006F878: ori         $t0, $zero, 0x4
    ctx->r8 = 0 | 0X4;
L_8006F87C:
    // 0x8006F87C: lwc1        $f4, 0x0($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0X0);
    // 0x8006F880: lwc1        $f6, 0x4($a0)
    ctx->f6.u32l = MEM_W(ctx->r4, 0X4);
    // 0x8006F884: lwc1        $f8, 0x8($a0)
    ctx->f8.u32l = MEM_W(ctx->r4, 0X8);
    // 0x8006F888: mul.s       $f4, $f4, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = MUL_S(ctx->f4.fl, ctx->f12.fl);
    // 0x8006F88C: lwc1        $f10, 0xC($a0)
    ctx->f10.u32l = MEM_W(ctx->r4, 0XC);
    // 0x8006F890: addiu       $a0, $a0, 0x10
    ctx->r4 = ADD32(ctx->r4, 0X10);
    // 0x8006F894: mul.s       $f6, $f6, $f12
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f6.fl = MUL_S(ctx->f6.fl, ctx->f12.fl);
    // 0x8006F898: addiu       $a1, $a1, 0x8
    ctx->r5 = ADD32(ctx->r5, 0X8);
    // 0x8006F89C: addiu       $t0, $t0, -0x1
    ctx->r8 = ADD32(ctx->r8, -0X1);
    // 0x8006F8A0: mul.s       $f8, $f8, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f8.fl, ctx->f12.fl);
    // 0x8006F8A4: nop

    // 0x8006F8A8: mul.s       $f10, $f10, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f10.fl, ctx->f12.fl);
    // 0x8006F8AC: cvt.w.s     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.u32l = CVT_W_S(ctx->f4.fl);
    // 0x8006F8B0: cvt.w.s     $f6, $f6
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    ctx->f6.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8006F8B4: mfc1        $t1, $f4
    ctx->r9 = (int32_t)ctx->f4.u32l;
    // 0x8006F8B8: cvt.w.s     $f8, $f8
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    ctx->f8.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8006F8BC: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x8006F8C0: sh          $t1, 0x18($a1)
    MEM_H(0X18, ctx->r5) = ctx->r9;
    // 0x8006F8C4: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8006F8C8: mfc1        $t3, $f8
    ctx->r11 = (int32_t)ctx->f8.u32l;
    // 0x8006F8CC: sh          $t2, 0x1A($a1)
    MEM_H(0X1A, ctx->r5) = ctx->r10;
    // 0x8006F8D0: srl         $t1, $t1, 16
    ctx->r9 = S32(U32(ctx->r9) >> 16);
    // 0x8006F8D4: mfc1        $t4, $f10
    ctx->r12 = (int32_t)ctx->f10.u32l;
    // 0x8006F8D8: sh          $t3, 0x1C($a1)
    MEM_H(0X1C, ctx->r5) = ctx->r11;
    // 0x8006F8DC: srl         $t2, $t2, 16
    ctx->r10 = S32(U32(ctx->r10) >> 16);
    // 0x8006F8E0: sh          $t4, 0x1E($a1)
    MEM_H(0X1E, ctx->r5) = ctx->r12;
    // 0x8006F8E4: srl         $t3, $t3, 16
    ctx->r11 = S32(U32(ctx->r11) >> 16);
    // 0x8006F8E8: srl         $t4, $t4, 16
    ctx->r12 = S32(U32(ctx->r12) >> 16);
    // 0x8006F8EC: sh          $t1, -0x8($a1)
    MEM_H(-0X8, ctx->r5) = ctx->r9;
    // 0x8006F8F0: sh          $t2, -0x6($a1)
    MEM_H(-0X6, ctx->r5) = ctx->r10;
    // 0x8006F8F4: sh          $t3, -0x4($a1)
    MEM_H(-0X4, ctx->r5) = ctx->r11;
    // 0x8006F8F8: sh          $t4, -0x2($a1)
    MEM_H(-0X2, ctx->r5) = ctx->r12;
    // 0x8006F8FC: bnel        $t0, $zero, L_8006F87C
    if (ctx->r8 != 0) {
        // 0x8006F900: nop
    
            goto L_8006F87C;
    }
    goto skip_0;
    // 0x8006F900: nop

    skip_0:
    // 0x8006F904: jr          $ra
    // 0x8006F908: nop

    return;
    // 0x8006F908: nop

;}
RECOMP_FUNC void get_si_device_status(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    extern int dkr_virtual_pak_preferred_status(uint8_t*, recomp_context*); int dkr_pak_status = dkr_virtual_pak_preferred_status(rdram, ctx); if (dkr_pak_status >= 0) { ctx->r2 = dkr_pak_status; return; }
    // 0x800758DC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x800758E0: sw          $s4, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r20;
    // 0x800758E4: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x800758E8: addiu       $s4, $s4, 0x4010
    ctx->r20 = ADD32(ctx->r20, 0X4010);
    // 0x800758EC: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800758F0: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x800758F4: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800758F8: sw          $s5, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r21;
    // 0x800758FC: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80075900: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x80075904: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80075908: lw          $t6, 0x8($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X8);
    // 0x8007590C: or          $s5, $a0, $zero
    ctx->r21 = ctx->r4 | 0;
    // 0x80075910: bne         $t6, $zero, L_80075950
    if (ctx->r14 != 0) {
        // 0x80075914: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80075950;
    }
    // 0x80075914: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80075918: sll         $t7, $s5, 2
    ctx->r15 = S32(ctx->r21 << 2);
    // 0x8007591C: subu        $t7, $t7, $s5
    ctx->r15 = SUB32(ctx->r15, ctx->r21);
    // 0x80075920: sll         $t7, $t7, 2
    ctx->r15 = S32(ctx->r15 << 2);
    // 0x80075924: addu        $t7, $t7, $s5
    ctx->r15 = ADD32(ctx->r15, ctx->r21);
    // 0x80075928: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8007592C: addiu       $t8, $t8, 0x4018
    ctx->r24 = ADD32(ctx->r24, 0X4018);
    // 0x80075930: sll         $t7, $t7, 3
    ctx->r15 = S32(ctx->r15 << 3);
    // 0x80075934: addu        $a1, $t7, $t8
    ctx->r5 = ADD32(ctx->r15, ctx->r24);
    // 0x80075938: jal         0x800720DC
    // 0x8007593C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_0;
    // 0x8007593C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_0:
    // 0x80075940: bne         $v0, $zero, L_80075954
    if (ctx->r2 != 0) {
        // 0x80075944: sll         $t9, $s5, 2
        ctx->r25 = S32(ctx->r21 << 2);
            goto L_80075954;
    }
    // 0x80075944: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
    // 0x80075948: b           L_80075AC8
    // 0x8007594C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80075AC8;
    // 0x8007594C: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80075950:
    // 0x80075950: sll         $t9, $s5, 2
    ctx->r25 = S32(ctx->r21 << 2);
L_80075954:
    // 0x80075954: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80075958: subu        $t9, $t9, $s5
    ctx->r25 = SUB32(ctx->r25, ctx->r21);
    // 0x8007595C: sll         $t9, $t9, 2
    ctx->r25 = S32(ctx->r25 << 2);
    // 0x80075960: lw          $t1, 0x8($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X8);
    // 0x80075964: addu        $t9, $t9, $s5
    ctx->r25 = ADD32(ctx->r25, ctx->r21);
    // 0x80075968: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x8007596C: addiu       $t0, $t0, 0x4018
    ctx->r8 = ADD32(ctx->r8, 0X4018);
    // 0x80075970: sll         $t9, $t9, 3
    ctx->r25 = S32(ctx->r25 << 3);
    // 0x80075974: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80075978: beq         $t1, $zero, L_800759B4
    if (ctx->r9 == 0) {
        // 0x8007597C: addu        $s3, $t9, $t0
        ctx->r19 = ADD32(ctx->r25, ctx->r8);
            goto L_800759B4;
    }
    // 0x8007597C: addu        $s3, $t9, $t0
    ctx->r19 = ADD32(ctx->r25, ctx->r8);
    // 0x80075980: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x80075984: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_80075988:
    // 0x80075988: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    // 0x8007598C: jal         0x800C8BB0
    // 0x80075990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    osRecvMesg_recomp(rdram, ctx);
        goto after_1;
    // 0x80075990: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_1:
    // 0x80075994: lw          $s0, 0x0($s4)
    ctx->r16 = MEM_W(ctx->r20, 0X0);
    // 0x80075998: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8007599C: lw          $t2, 0x8($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X8);
    // 0x800759A0: nop

    // 0x800759A4: beq         $t2, $zero, L_800759B4
    if (ctx->r10 == 0) {
        // 0x800759A8: nop
    
            goto L_800759B4;
    }
    // 0x800759A8: nop

    // 0x800759AC: bne         $s1, $s2, L_80075988
    if (ctx->r17 != ctx->r18) {
        // 0x800759B0: or          $a0, $s0, $zero
        ctx->r4 = ctx->r16 | 0;
            goto L_80075988;
    }
    // 0x800759B0: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
L_800759B4:
    // 0x800759B4: addiu       $s2, $zero, 0xA
    ctx->r18 = ADD32(0, 0XA);
    // 0x800759B8: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x800759BC: addiu       $s0, $zero, 0x5
    ctx->r16 = ADD32(0, 0X5);
    // 0x800759C0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
L_800759C4:
    // 0x800759C4: jal         0x800CF3E0
    // 0x800759C8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    osPfsFreeBlocks_recomp(rdram, ctx);
        goto after_2;
    // 0x800759C8: addiu       $a1, $sp, 0x3C
    ctx->r5 = ADD32(ctx->r29, 0X3C);
    after_2:
    // 0x800759CC: bne         $v0, $s0, L_800759E8
    if (ctx->r2 != ctx->r16) {
        // 0x800759D0: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_800759E8;
    }
    // 0x800759D0: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x800759D4: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800759D8: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800759DC: jal         0x800CED20
    // 0x800759E0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_3;
    // 0x800759E0: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_3:
    // 0x800759E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_800759E8:
    // 0x800759E8: bne         $v0, $s2, L_80075A14
    if (ctx->r2 != ctx->r18) {
        // 0x800759EC: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80075A14;
    }
    // 0x800759EC: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x800759F0: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x800759F4: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    // 0x800759F8: jal         0x800720DC
    // 0x800759FC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    osMotorInit_recomp(rdram, ctx);
        goto after_4;
    // 0x800759FC: sw          $v1, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r3;
    after_4:
    // 0x80075A00: lw          $v1, 0x40($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X40);
    // 0x80075A04: bne         $v0, $zero, L_80075A18
    if (ctx->r2 != 0) {
        // 0x80075A08: addiu       $at, $zero, 0x2
        ctx->r1 = ADD32(0, 0X2);
            goto L_80075A18;
    }
    // 0x80075A08: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80075A0C: b           L_80075AC8
    // 0x80075A10: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80075AC8;
    // 0x80075A10: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80075A14:
    // 0x80075A14: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
L_80075A18:
    // 0x80075A18: bne         $v1, $at, L_80075A60
    if (ctx->r3 != ctx->r1) {
        // 0x80075A1C: addiu       $at, $zero, 0x1
        ctx->r1 = ADD32(0, 0X1);
            goto L_80075A60;
    }
    // 0x80075A1C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80075A20: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075A24: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075A28: jal         0x800CED20
    // 0x80075A2C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osPfsInit_recomp(rdram, ctx);
        goto after_5;
    // 0x80075A2C: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_5:
    // 0x80075A30: bne         $v0, $s2, L_80075A54
    if (ctx->r2 != ctx->r18) {
        // 0x80075A34: or          $a1, $s3, $zero
        ctx->r5 = ctx->r19 | 0;
            goto L_80075A54;
    }
    // 0x80075A34: or          $a1, $s3, $zero
    ctx->r5 = ctx->r19 | 0;
    // 0x80075A38: lw          $a0, 0x0($s4)
    ctx->r4 = MEM_W(ctx->r20, 0X0);
    // 0x80075A3C: jal         0x800720DC
    // 0x80075A40: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    osMotorInit_recomp(rdram, ctx);
        goto after_6;
    // 0x80075A40: or          $a2, $s5, $zero
    ctx->r6 = ctx->r21 | 0;
    after_6:
    // 0x80075A44: bne         $v0, $zero, L_80075A54
    if (ctx->r2 != 0) {
        // 0x80075A48: nop
    
            goto L_80075A54;
    }
    // 0x80075A48: nop

    // 0x80075A4C: b           L_80075AC8
    // 0x80075A50: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
        goto L_80075AC8;
    // 0x80075A50: addiu       $v0, $zero, 0x7
    ctx->r2 = ADD32(0, 0X7);
L_80075A54:
    // 0x80075A54: b           L_80075AC8
    // 0x80075A58: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
        goto L_80075AC8;
    // 0x80075A58: addiu       $v0, $zero, 0x5
    ctx->r2 = ADD32(0, 0X5);
    // 0x80075A5C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
L_80075A60:
    // 0x80075A60: beq         $v1, $at, L_80075A70
    if (ctx->r3 == ctx->r1) {
        // 0x80075A64: addiu       $at, $zero, 0xB
        ctx->r1 = ADD32(0, 0XB);
            goto L_80075A70;
    }
    // 0x80075A64: addiu       $at, $zero, 0xB
    ctx->r1 = ADD32(0, 0XB);
    // 0x80075A68: bne         $v1, $at, L_80075A78
    if (ctx->r3 != ctx->r1) {
        // 0x80075A6C: addiu       $s1, $s1, 0x1
        ctx->r17 = ADD32(ctx->r17, 0X1);
            goto L_80075A78;
    }
    // 0x80075A6C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
L_80075A70:
    // 0x80075A70: b           L_80075AC8
    // 0x80075A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
        goto L_80075AC8;
    // 0x80075A74: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075A78:
    // 0x80075A78: addiu       $at, $zero, 0x6
    ctx->r1 = ADD32(0, 0X6);
    // 0x80075A7C: bne         $v1, $at, L_80075A8C
    if (ctx->r3 != ctx->r1) {
        // 0x80075A80: nop
    
            goto L_80075A8C;
    }
    // 0x80075A80: nop

    // 0x80075A84: b           L_80075AC8
    // 0x80075A88: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
        goto L_80075AC8;
    // 0x80075A88: addiu       $v0, $zero, 0x9
    ctx->r2 = ADD32(0, 0X9);
L_80075A8C:
    // 0x80075A8C: bne         $v1, $s2, L_80075A9C
    if (ctx->r3 != ctx->r18) {
        // 0x80075A90: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_80075A9C;
    }
    // 0x80075A90: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80075A94: b           L_80075AC8
    // 0x80075A98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
        goto L_80075AC8;
    // 0x80075A98: addiu       $v0, $zero, 0x3
    ctx->r2 = ADD32(0, 0X3);
L_80075A9C:
    // 0x80075A9C: bne         $v1, $at, L_80075AAC
    if (ctx->r3 != ctx->r1) {
        // 0x80075AA0: nop
    
            goto L_80075AAC;
    }
    // 0x80075AA0: nop

    // 0x80075AA4: b           L_80075AC8
    // 0x80075AA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
        goto L_80075AC8;
    // 0x80075AA8: addiu       $v0, $zero, 0x2
    ctx->r2 = ADD32(0, 0X2);
L_80075AAC:
    // 0x80075AAC: bne         $v1, $zero, L_80075ABC
    if (ctx->r3 != 0) {
        // 0x80075AB0: nop
    
            goto L_80075ABC;
    }
    // 0x80075AB0: nop

    // 0x80075AB4: b           L_80075AC8
    // 0x80075AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_80075AC8;
    // 0x80075AB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80075ABC:
    // 0x80075ABC: bne         $s1, $s0, L_800759C4
    if (ctx->r17 != ctx->r16) {
        // 0x80075AC0: or          $a0, $s3, $zero
        ctx->r4 = ctx->r19 | 0;
            goto L_800759C4;
    }
    // 0x80075AC0: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    // 0x80075AC4: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80075AC8:
    // 0x80075AC8: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x80075ACC: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x80075AD0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x80075AD4: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x80075AD8: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x80075ADC: lw          $s4, 0x24($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X24);
    // 0x80075AE0: lw          $s5, 0x28($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X28);
    // 0x80075AE4: jr          $ra
    // 0x80075AE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    return;
    // 0x80075AE8: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
;}
RECOMP_FUNC void init_triangle_particle_model(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800AEE14: addiu       $t6, $zero, 0x3
    ctx->r14 = ADD32(0, 0X3);
    // 0x800AEE18: sh          $t6, 0x4($a0)
    MEM_H(0X4, ctx->r4) = ctx->r14;
    // 0x800AEE1C: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x800AEE20: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800AEE24: sw          $t7, 0x8($a0)
    MEM_W(0X8, ctx->r4) = ctx->r15;
    // 0x800AEE28: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x800AEE2C: addiu       $v1, $v1, 0x2E68
    ctx->r3 = ADD32(ctx->r3, 0X2E68);
    // 0x800AEE30: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800AEE34: addiu       $t0, $zero, 0xFF
    ctx->r8 = ADD32(0, 0XFF);
L_800AEE38:
    // 0x800AEE38: lh          $t8, 0x0($v1)
    ctx->r24 = MEM_H(ctx->r3, 0X0);
    // 0x800AEE3C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800AEE40: sh          $t8, 0x0($v0)
    MEM_H(0X0, ctx->r2) = ctx->r24;
    // 0x800AEE44: lh          $t9, 0x2($v1)
    ctx->r25 = MEM_H(ctx->r3, 0X2);
    // 0x800AEE48: sll         $t1, $a3, 16
    ctx->r9 = S32(ctx->r7 << 16);
    // 0x800AEE4C: sra         $a3, $t1, 16
    ctx->r7 = S32(SIGNED(ctx->r9) >> 16);
    // 0x800AEE50: slti        $at, $a3, 0x3
    ctx->r1 = SIGNED(ctx->r7) < 0X3 ? 1 : 0;
    // 0x800AEE54: addiu       $v1, $v1, 0x4
    ctx->r3 = ADD32(ctx->r3, 0X4);
    // 0x800AEE58: sh          $zero, 0x4($v0)
    MEM_H(0X4, ctx->r2) = 0;
    // 0x800AEE5C: sb          $t0, 0x6($v0)
    MEM_B(0X6, ctx->r2) = ctx->r8;
    // 0x800AEE60: sb          $t0, 0x7($v0)
    MEM_B(0X7, ctx->r2) = ctx->r8;
    // 0x800AEE64: sb          $t0, 0x8($v0)
    MEM_B(0X8, ctx->r2) = ctx->r8;
    // 0x800AEE68: sb          $t0, 0x9($v0)
    MEM_B(0X9, ctx->r2) = ctx->r8;
    // 0x800AEE6C: addiu       $v0, $v0, 0xA
    ctx->r2 = ADD32(ctx->r2, 0XA);
    // 0x800AEE70: bne         $at, $zero, L_800AEE38
    if (ctx->r1 != 0) {
        // 0x800AEE74: sh          $t9, -0x8($v0)
        MEM_H(-0X8, ctx->r2) = ctx->r25;
            goto L_800AEE38;
    }
    // 0x800AEE74: sh          $t9, -0x8($v0)
    MEM_H(-0X8, ctx->r2) = ctx->r25;
    // 0x800AEE78: sw          $v0, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r2;
    // 0x800AEE7C: addiu       $t3, $zero, 0x1
    ctx->r11 = ADD32(0, 0X1);
    // 0x800AEE80: sh          $t3, 0x6($a0)
    MEM_H(0X6, ctx->r4) = ctx->r11;
    // 0x800AEE84: lw          $t4, 0x0($a2)
    ctx->r12 = MEM_W(ctx->r6, 0X0);
    // 0x800AEE88: addiu       $t5, $zero, 0x40
    ctx->r13 = ADD32(0, 0X40);
    // 0x800AEE8C: sw          $t4, 0xC($a0)
    MEM_W(0XC, ctx->r4) = ctx->r12;
    // 0x800AEE90: lw          $v1, 0x0($a2)
    ctx->r3 = MEM_W(ctx->r6, 0X0);
    // 0x800AEE94: addiu       $t6, $zero, 0x2
    ctx->r14 = ADD32(0, 0X2);
    // 0x800AEE98: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
    // 0x800AEE9C: sb          $t5, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r13;
    // 0x800AEEA0: sb          $t6, 0x1($v1)
    MEM_B(0X1, ctx->r3) = ctx->r14;
    // 0x800AEEA4: sb          $t7, 0x2($v1)
    MEM_B(0X2, ctx->r3) = ctx->r15;
    // 0x800AEEA8: sb          $zero, 0x3($v1)
    MEM_B(0X3, ctx->r3) = 0;
    // 0x800AEEAC: addiu       $v1, $v1, 0x10
    ctx->r3 = ADD32(ctx->r3, 0X10);
    // 0x800AEEB0: jr          $ra
    // 0x800AEEB4: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    return;
    // 0x800AEEB4: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
;}
RECOMP_FUNC void get_fog_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80030750: sll         $t6, $a0, 3
    ctx->r14 = S32(ctx->r4 << 3);
    // 0x80030754: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80030758: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8003075C: addiu       $t7, $t7, -0x2C78
    ctx->r15 = ADD32(ctx->r15, -0X2C78);
    // 0x80030760: sll         $t6, $t6, 3
    ctx->r14 = S32(ctx->r14 << 3);
    // 0x80030764: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80030768: lw          $t8, 0xC($v0)
    ctx->r24 = MEM_W(ctx->r2, 0XC);
    // 0x8003076C: nop

    // 0x80030770: sra         $t9, $t8, 16
    ctx->r25 = S32(SIGNED(ctx->r24) >> 16);
    // 0x80030774: sh          $t9, 0x0($a1)
    MEM_H(0X0, ctx->r5) = ctx->r25;
    // 0x80030778: lw          $t0, 0x10($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X10);
    // 0x8003077C: nop

    // 0x80030780: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x80030784: sh          $t1, 0x0($a2)
    MEM_H(0X0, ctx->r6) = ctx->r9;
    // 0x80030788: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8003078C: nop

    // 0x80030790: sra         $t3, $t2, 16
    ctx->r11 = S32(SIGNED(ctx->r10) >> 16);
    // 0x80030794: sb          $t3, 0x0($a3)
    MEM_B(0X0, ctx->r7) = ctx->r11;
    // 0x80030798: lw          $t4, 0x4($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X4);
    // 0x8003079C: lw          $t6, 0x10($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X10);
    // 0x800307A0: sra         $t5, $t4, 16
    ctx->r13 = S32(SIGNED(ctx->r12) >> 16);
    // 0x800307A4: sb          $t5, 0x0($t6)
    MEM_B(0X0, ctx->r14) = ctx->r13;
    // 0x800307A8: lw          $t7, 0x8($v0)
    ctx->r15 = MEM_W(ctx->r2, 0X8);
    // 0x800307AC: lw          $t9, 0x14($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X14);
    // 0x800307B0: sra         $t8, $t7, 16
    ctx->r24 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800307B4: jr          $ra
    // 0x800307B8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
    return;
    // 0x800307B8: sb          $t8, 0x0($t9)
    MEM_B(0X0, ctx->r25) = ctx->r24;
;}
RECOMP_FUNC void hud_race_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A3CE4: addiu       $sp, $sp, -0x58
    ctx->r29 = ADD32(ctx->r29, -0X58);
    // 0x800A3CE8: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800A3CEC: sw          $a0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r4;
    // 0x800A3CF0: jal         0x8006EAA0
    // 0x800A3CF4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    is_game_paused(rdram, ctx);
        goto after_0;
    // 0x800A3CF4: sw          $a1, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r5;
    after_0:
    // 0x800A3CF8: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800A3CFC: bne         $v0, $zero, L_800A4144
    if (ctx->r2 != 0) {
        // 0x800A3D00: lui         $t7, 0x8012
        ctx->r15 = S32(0X8012 << 16);
            goto L_800A4144;
    }
    // 0x800A3D00: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x800A3D04: bne         $t1, $zero, L_800A3D28
    if (ctx->r9 != 0) {
        // 0x800A3D08: lui         $v1, 0x800E
        ctx->r3 = S32(0X800E << 16);
            goto L_800A3D28;
    }
    // 0x800A3D08: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800A3D0C: addiu       $v1, $v1, 0x2770
    ctx->r3 = ADD32(ctx->r3, 0X2770);
    // 0x800A3D10: lb          $t6, 0xC($v1)
    ctx->r14 = MEM_B(ctx->r3, 0XC);
    // 0x800A3D14: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x800A3D18: bne         $v0, $t6, L_800A3D28
    if (ctx->r2 != ctx->r14) {
        // 0x800A3D1C: nop
    
            goto L_800A3D28;
    }
    // 0x800A3D1C: nop

    // 0x800A3D20: sb          $v0, 0x3($v1)
    MEM_B(0X3, ctx->r3) = ctx->r2;
    // 0x800A3D24: sb          $v0, 0x13($v1)
    MEM_B(0X13, ctx->r3) = ctx->r2;
L_800A3D28:
    // 0x800A3D28: lw          $t7, 0x6D0C($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X6D0C);
    // 0x800A3D2C: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A3D30: bne         $t7, $at, L_800A3D48
    if (ctx->r15 != ctx->r1) {
        // 0x800A3D34: nop
    
            goto L_800A3D48;
    }
    // 0x800A3D34: nop

    // 0x800A3D38: jal         0x8007BF1C
    // 0x800A3D3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    sprite_opaque(rdram, ctx);
        goto after_1;
    // 0x800A3D3C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
    // 0x800A3D40: lw          $t1, 0x58($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X58);
    // 0x800A3D44: nop

L_800A3D48:
    // 0x800A3D48: blez        $t1, L_800A3F58
    if (SIGNED(ctx->r9) <= 0) {
        // 0x800A3D4C: lui         $t0, 0x8012
        ctx->r8 = S32(0X8012 << 16);
            goto L_800A3F58;
    }
    // 0x800A3D4C: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A3D50: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x800A3D54: lbu         $t8, 0x6D34($t8)
    ctx->r24 = MEM_BU(ctx->r24, 0X6D34);
    // 0x800A3D58: sll         $t3, $t1, 8
    ctx->r11 = S32(ctx->r9 << 8);
    // 0x800A3D5C: beq         $t8, $zero, L_800A3E1C
    if (ctx->r24 == 0) {
        // 0x800A3D60: subu        $t3, $t3, $t1
        ctx->r11 = SUB32(ctx->r11, ctx->r9);
            goto L_800A3E1C;
    }
    // 0x800A3D60: subu        $t3, $t3, $t1
    ctx->r11 = SUB32(ctx->r11, ctx->r9);
    // 0x800A3D64: addiu       $at, $zero, 0x28
    ctx->r1 = ADD32(0, 0X28);
    // 0x800A3D68: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x800A3D6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3D70: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3D74: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A3D78: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x800A3D7C: addiu       $t9, $v0, 0x8
    ctx->r25 = ADD32(ctx->r2, 0X8);
    // 0x800A3D80: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x800A3D84: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A3D88: lui         $t2, 0xFA00
    ctx->r10 = S32(0XFA00 << 16);
    // 0x800A3D8C: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A3D90: sw          $t2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r10;
    // 0x800A3D94: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3D98: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3D9C: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A3DA0: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A3DA4: mflo        $t4
    ctx->r12 = lo;
    // 0x800A3DA8: andi        $t5, $t4, 0xFF
    ctx->r13 = ctx->r12 & 0XFF;
    // 0x800A3DAC: or          $t6, $t5, $at
    ctx->r14 = ctx->r13 | ctx->r1;
    // 0x800A3DB0: sw          $t6, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r14;
    // 0x800A3DB4: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A3DB8: jal         0x800AA600
    // 0x800A3DBC: addiu       $a3, $a3, 0x1A0
    ctx->r7 = ADD32(ctx->r7, 0X1A0);
    hud_element_render(rdram, ctx);
        goto after_2;
    // 0x800A3DBC: addiu       $a3, $a3, 0x1A0
    ctx->r7 = ADD32(ctx->r7, 0X1A0);
    after_2:
    // 0x800A3DC0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3DC4: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3DC8: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A3DCC: lui         $t8, 0xFA00
    ctx->r24 = S32(0XFA00 << 16);
    // 0x800A3DD0: addiu       $t7, $v0, 0x8
    ctx->r15 = ADD32(ctx->r2, 0X8);
    // 0x800A3DD4: sw          $t7, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r15;
    // 0x800A3DD8: addiu       $t9, $zero, -0x1
    ctx->r25 = ADD32(0, -0X1);
    // 0x800A3DDC: lui         $t2, 0x8012
    ctx->r10 = S32(0X8012 << 16);
    // 0x800A3DE0: sw          $t9, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r25;
    // 0x800A3DE4: sw          $t8, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r24;
    // 0x800A3DE8: lb          $t2, 0x6CD4($t2)
    ctx->r10 = MEM_B(ctx->r10, 0X6CD4);
    // 0x800A3DEC: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A3DF0: bne         $t2, $at, L_800A3E1C
    if (ctx->r10 != ctx->r1) {
        // 0x800A3DF4: addiu       $a0, $zero, 0x18
        ctx->r4 = ADD32(0, 0X18);
            goto L_800A3E1C;
    }
    // 0x800A3DF4: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    // 0x800A3DF8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3DFC: jal         0x80001D04
    // 0x800A3E00: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    sound_play(rdram, ctx);
        goto after_3;
    // 0x800A3E00: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    after_3:
    // 0x800A3E04: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A3E08: addiu       $v0, $v0, 0x6CD4
    ctx->r2 = ADD32(ctx->r2, 0X6CD4);
    // 0x800A3E0C: lb          $t3, 0x0($v0)
    ctx->r11 = MEM_B(ctx->r2, 0X0);
    // 0x800A3E10: nop

    // 0x800A3E14: addiu       $t4, $t3, 0x1
    ctx->r12 = ADD32(ctx->r11, 0X1);
    // 0x800A3E18: sb          $t4, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r12;
L_800A3E1C:
    // 0x800A3E1C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A3E20: lw          $t5, 0x6D3C($t5)
    ctx->r13 = MEM_W(ctx->r13, 0X6D3C);
    // 0x800A3E24: nop

    // 0x800A3E28: bne         $t5, $zero, L_800A413C
    if (ctx->r13 != 0) {
        // 0x800A3E2C: nop
    
            goto L_800A413C;
    }
    // 0x800A3E2C: nop

    // 0x800A3E30: jal         0x80023568
    // 0x800A3E34: nop

    func_80023568(rdram, ctx);
        goto after_4;
    // 0x800A3E34: nop

    after_4:
    // 0x800A3E38: bne         $v0, $zero, L_800A413C
    if (ctx->r2 != 0) {
        // 0x800A3E3C: nop
    
            goto L_800A413C;
    }
    // 0x800A3E3C: nop

    // 0x800A3E40: jal         0x8001BA74
    // 0x800A3E44: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    get_racer_objects(rdram, ctx);
        goto after_5;
    // 0x800A3E44: addiu       $a0, $sp, 0x38
    ctx->r4 = ADD32(ctx->r29, 0X38);
    after_5:
    // 0x800A3E48: lw          $a1, 0x38($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X38);
    // 0x800A3E4C: sw          $v0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r2;
    // 0x800A3E50: jal         0x8006F94C
    // 0x800A3E54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rand_range(rdram, ctx);
        goto after_6;
    // 0x800A3E54: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_6:
    // 0x800A3E58: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800A3E5C: sll         $t7, $v0, 2
    ctx->r15 = S32(ctx->r2 << 2);
    // 0x800A3E60: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x800A3E64: lw          $t0, -0x4($t8)
    ctx->r8 = MEM_W(ctx->r24, -0X4);
    // 0x800A3E68: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A3E6C: lw          $v1, 0x64($t0)
    ctx->r3 = MEM_W(ctx->r8, 0X64);
    // 0x800A3E70: addiu       $a1, $zero, 0x64
    ctx->r5 = ADD32(0, 0X64);
    // 0x800A3E74: lb          $t9, 0x1D6($v1)
    ctx->r25 = MEM_B(ctx->r3, 0X1D6);
    // 0x800A3E78: nop

    // 0x800A3E7C: bne         $t9, $zero, L_800A413C
    if (ctx->r25 != 0) {
        // 0x800A3E80: nop
    
            goto L_800A413C;
    }
    // 0x800A3E80: nop

    // 0x800A3E84: jal         0x8006F94C
    // 0x800A3E88: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    rand_range(rdram, ctx);
        goto after_7;
    // 0x800A3E88: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_7:
    // 0x800A3E8C: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A3E90: slti        $at, $v0, 0x60
    ctx->r1 = SIGNED(ctx->r2) < 0X60 ? 1 : 0;
    // 0x800A3E94: bne         $at, $zero, L_800A413C
    if (ctx->r1 != 0) {
        // 0x800A3E98: or          $a0, $zero, $zero
        ctx->r4 = 0 | 0;
            goto L_800A413C;
    }
    // 0x800A3E98: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A3E9C: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800A3EA0: jal         0x8006F94C
    // 0x800A3EA4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    rand_range(rdram, ctx);
        goto after_8;
    // 0x800A3EA4: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    after_8:
    // 0x800A3EA8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800A3EAC: lui         $at, 0x3FE0
    ctx->r1 = S32(0X3FE0 << 16);
    // 0x800A3EB0: cvt.d.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.d = CVT_D_W(ctx->f4.u32l);
    // 0x800A3EB4: mtc1        $at, $f9
    ctx->f_odd[(9 - 1) * 2] = ctx->r1;
    // 0x800A3EB8: mtc1        $zero, $f8
    ctx->f8.u32l = 0;
    // 0x800A3EBC: lui         $at, 0x401C
    ctx->r1 = S32(0X401C << 16);
    // 0x800A3EC0: mul.d       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.d); NAN_CHECK(ctx->f8.d); 
    ctx->f10.d = MUL_D(ctx->f6.d, ctx->f8.d);
    // 0x800A3EC4: mtc1        $at, $f17
    ctx->f_odd[(17 - 1) * 2] = ctx->r1;
    // 0x800A3EC8: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800A3ECC: lui         $at, 0x3FF4
    ctx->r1 = S32(0X3FF4 << 16);
    // 0x800A3ED0: mtc1        $at, $f5
    ctx->f_odd[(5 - 1) * 2] = ctx->r1;
    // 0x800A3ED4: div.d       $f18, $f10, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f16.d); 
    ctx->f18.d = DIV_D(ctx->f10.d, ctx->f16.d);
    // 0x800A3ED8: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800A3EDC: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A3EE0: addiu       $a1, $zero, 0x7
    ctx->r5 = ADD32(0, 0X7);
    // 0x800A3EE4: sub.d       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f18.d); 
    ctx->f6.d = ctx->f4.d - ctx->f18.d;
    // 0x800A3EE8: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800A3EEC: jal         0x8006F94C
    // 0x800A3EF0: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    rand_range(rdram, ctx);
        goto after_9;
    // 0x800A3EF0: swc1        $f8, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->f8.u32l;
    after_9:
    // 0x800A3EF4: sll         $t3, $v0, 6
    ctx->r11 = S32(ctx->r2 << 6);
    // 0x800A3EF8: subu        $t3, $t3, $v0
    ctx->r11 = SUB32(ctx->r11, ctx->r2);
    // 0x800A3EFC: addiu       $at, $zero, 0x7
    ctx->r1 = ADD32(0, 0X7);
    // 0x800A3F00: div         $zero, $t3, $at
    lo = S32(S64(S32(ctx->r11)) / S64(S32(ctx->r1))); hi = S32(S64(S32(ctx->r11)) % S64(S32(ctx->r1)));
    // 0x800A3F04: lw          $t0, 0x40($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X40);
    // 0x800A3F08: lui         $at, 0x42C8
    ctx->r1 = S32(0X42C8 << 16);
    // 0x800A3F0C: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A3F10: lwc1        $f10, 0x4C($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0X4C);
    // 0x800A3F14: lw          $a1, 0xC($t0)
    ctx->r5 = MEM_W(ctx->r8, 0XC);
    // 0x800A3F18: lw          $a2, 0x10($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X10);
    // 0x800A3F1C: lw          $a3, 0x14($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X14);
    // 0x800A3F20: mul.s       $f4, $f10, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f16.fl);
    // 0x800A3F24: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A3F28: addiu       $t6, $t6, 0x6D3C
    ctx->r14 = ADD32(ctx->r14, 0X6D3C);
    // 0x800A3F2C: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x800A3F30: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    // 0x800A3F34: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x800A3F38: swc1        $f4, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f4.u32l;
    // 0x800A3F3C: addiu       $a0, $zero, 0x4C
    ctx->r4 = ADD32(0, 0X4C);
    // 0x800A3F40: mflo        $t4
    ctx->r12 = lo;
    // 0x800A3F44: addiu       $t5, $t4, 0x18
    ctx->r13 = ADD32(ctx->r12, 0X18);
    // 0x800A3F48: jal         0x800095E8
    // 0x800A3F4C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    audspat_play_sound_direct(rdram, ctx);
        goto after_10;
    // 0x800A3F4C: sw          $t5, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r13;
    after_10:
    // 0x800A3F50: b           L_800A413C
    // 0x800A3F54: nop

        goto L_800A413C;
    // 0x800A3F54: nop

L_800A3F58:
    // 0x800A3F58: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A3F5C: lw          $t7, 0x0($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X0);
    // 0x800A3F60: lui         $at, 0xC348
    ctx->r1 = S32(0XC348 << 16);
    // 0x800A3F64: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x800A3F68: lwc1        $f6, 0x18C($t7)
    ctx->f6.u32l = MEM_W(ctx->r15, 0X18C);
    // 0x800A3F6C: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3F70: c.lt.s      $f18, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f18.fl < ctx->f6.fl;
    // 0x800A3F74: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3F78: bc1f        L_800A413C
    if (!c1cs) {
        // 0x800A3F7C: lui         $t9, 0xFA00
        ctx->r25 = S32(0XFA00 << 16);
            goto L_800A413C;
    }
    // 0x800A3F7C: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x800A3F80: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A3F84: addiu       $t2, $zero, -0x60
    ctx->r10 = ADD32(0, -0X60);
    // 0x800A3F88: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800A3F8C: sw          $t8, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r24;
    // 0x800A3F90: sw          $t2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r10;
    // 0x800A3F94: sw          $t9, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r25;
    // 0x800A3F98: lw          $a3, 0x0($t0)
    ctx->r7 = MEM_W(ctx->r8, 0X0);
    // 0x800A3F9C: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A3FA0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A3FA4: addiu       $a2, $a2, 0x6D04
    ctx->r6 = ADD32(ctx->r6, 0X6D04);
    // 0x800A3FA8: addiu       $a1, $a1, 0x6D00
    ctx->r5 = ADD32(ctx->r5, 0X6D00);
    // 0x800A3FAC: jal         0x800AA600
    // 0x800A3FB0: addiu       $a3, $a3, 0x180
    ctx->r7 = ADD32(ctx->r7, 0X180);
    hud_element_render(rdram, ctx);
        goto after_11;
    // 0x800A3FB0: addiu       $a3, $a3, 0x180
    ctx->r7 = ADD32(ctx->r7, 0X180);
    after_11:
    // 0x800A3FB4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x800A3FB8: addiu       $a0, $a0, 0x6CFC
    ctx->r4 = ADD32(ctx->r4, 0X6CFC);
    // 0x800A3FBC: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x800A3FC0: lui         $t4, 0xFA00
    ctx->r12 = S32(0XFA00 << 16);
    // 0x800A3FC4: addiu       $t3, $v0, 0x8
    ctx->r11 = ADD32(ctx->r2, 0X8);
    // 0x800A3FC8: sw          $t3, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r11;
    // 0x800A3FCC: addiu       $t5, $zero, -0x1
    ctx->r13 = ADD32(0, -0X1);
    // 0x800A3FD0: lui         $a3, 0x8012
    ctx->r7 = S32(0X8012 << 16);
    // 0x800A3FD4: lui         $t0, 0x8012
    ctx->r8 = S32(0X8012 << 16);
    // 0x800A3FD8: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800A3FDC: sw          $t4, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r12;
    // 0x800A3FE0: addiu       $t0, $t0, 0x6CDC
    ctx->r8 = ADD32(ctx->r8, 0X6CDC);
    // 0x800A3FE4: addiu       $a3, $a3, 0x6D08
    ctx->r7 = ADD32(ctx->r7, 0X6D08);
    // 0x800A3FE8: lw          $t7, 0x0($a3)
    ctx->r15 = MEM_W(ctx->r7, 0X0);
    // 0x800A3FEC: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800A3FF0: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A3FF4: addu        $a1, $t6, $t7
    ctx->r5 = ADD32(ctx->r14, ctx->r15);
    // 0x800A3FF8: lb          $t8, 0x19A($a1)
    ctx->r24 = MEM_B(ctx->r5, 0X19A);
    // 0x800A3FFC: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A4000: addu        $t2, $t8, $t9
    ctx->r10 = ADD32(ctx->r24, ctx->r25);
    // 0x800A4004: sb          $t2, 0x19A($a1)
    MEM_B(0X19A, ctx->r5) = ctx->r10;
    // 0x800A4008: lw          $t3, 0x0($a3)
    ctx->r11 = MEM_W(ctx->r7, 0X0);
    // 0x800A400C: lw          $a2, 0x0($t0)
    ctx->r6 = MEM_W(ctx->r8, 0X0);
    // 0x800A4010: nop

    // 0x800A4014: addu        $t4, $a2, $t3
    ctx->r12 = ADD32(ctx->r6, ctx->r11);
    // 0x800A4018: lb          $t5, 0x19A($t4)
    ctx->r13 = MEM_B(ctx->r12, 0X19A);
    // 0x800A401C: nop

    // 0x800A4020: slti        $at, $t5, 0x3C
    ctx->r1 = SIGNED(ctx->r13) < 0X3C ? 1 : 0;
    // 0x800A4024: bne         $at, $zero, L_800A40BC
    if (ctx->r1 != 0) {
        // 0x800A4028: nop
    
            goto L_800A40BC;
    }
    // 0x800A4028: nop

    // 0x800A402C: lb          $t6, 0x6CD4($t6)
    ctx->r14 = MEM_B(ctx->r14, 0X6CD4);
    // 0x800A4030: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A4034: bne         $t6, $at, L_800A40A0
    if (ctx->r14 != ctx->r1) {
        // 0x800A4038: lw          $t9, 0x5C($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X5C);
            goto L_800A40A0;
    }
    // 0x800A4038: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
    // 0x800A403C: jal         0x80066210
    // 0x800A4040: nop

    cam_get_viewport_layout(rdram, ctx);
        goto after_12;
    // 0x800A4040: nop

    after_12:
    extern void dkr_restore_multiplayer_race_music(uint8_t*, recomp_context*); dkr_restore_multiplayer_race_music(rdram, ctx);
    // 0x800A4044: slti        $at, $v0, 0x2
    ctx->r1 = SIGNED(ctx->r2) < 0X2 ? 1 : 0;
    // 0x800A4048: bne         $at, $zero, L_800A4064
    if (ctx->r1 != 0) {
        // 0x800A404C: lui         $at, 0x3F80
        ctx->r1 = S32(0X3F80 << 16);
            goto L_800A4064;
    }
    // 0x800A404C: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x800A4050: jal         0x80000B34
    // 0x800A4054: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    music_play(rdram, ctx);
        goto after_13;
    // 0x800A4054: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_13:
    // 0x800A4058: b           L_800A4074
    // 0x800A405C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
        goto L_800A4074;
    // 0x800A405C: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
    // 0x800A4060: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
L_800A4064:
    // 0x800A4064: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800A4068: jal         0x8006BD10
    // 0x800A406C: nop

    level_music_start(rdram, ctx);
        goto after_14;
    // 0x800A406C: nop

    after_14:
    // 0x800A4070: addiu       $a0, $zero, 0x16
    ctx->r4 = ADD32(0, 0X16);
L_800A4074:
    // 0x800A4074: jal         0x80001D04
    // 0x800A4078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_15;
    // 0x800A4078: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_15:
    // 0x800A407C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800A4080: addiu       $v0, $v0, 0x6CD4
    ctx->r2 = ADD32(ctx->r2, 0X6CD4);
    // 0x800A4084: lb          $t7, 0x0($v0)
    ctx->r15 = MEM_B(ctx->r2, 0X0);
    // 0x800A4088: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A408C: addiu       $t8, $t7, 0x1
    ctx->r24 = ADD32(ctx->r15, 0X1);
    // 0x800A4090: sb          $t8, 0x0($v0)
    MEM_B(0X0, ctx->r2) = ctx->r24;
    // 0x800A4094: lw          $a2, 0x6CDC($a2)
    ctx->r6 = MEM_W(ctx->r6, 0X6CDC);
    // 0x800A4098: nop

    // 0x800A409C: lw          $t9, 0x5C($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X5C);
L_800A40A0:
    // 0x800A40A0: lwc1        $f8, 0x18C($a2)
    ctx->f8.u32l = MEM_W(ctx->r6, 0X18C);
    // 0x800A40A4: sll         $t2, $t9, 3
    ctx->r10 = S32(ctx->r25 << 3);
    // 0x800A40A8: mtc1        $t2, $f10
    ctx->f10.u32l = ctx->r10;
    // 0x800A40AC: nop

    // 0x800A40B0: cvt.s.w     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A40B4: sub.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f8.fl - ctx->f16.fl;
    // 0x800A40B8: swc1        $f4, 0x18C($a2)
    MEM_W(0X18C, ctx->r6) = ctx->f4.u32l;
L_800A40BC:
    // 0x800A40BC: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x800A40C0: lb          $t3, 0x6CD4($t3)
    ctx->r11 = MEM_B(ctx->r11, 0X6CD4);
    // 0x800A40C4: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x800A40C8: bne         $t3, $at, L_800A413C
    if (ctx->r11 != ctx->r1) {
        // 0x800A40CC: addiu       $a0, $zero, 0x19
        ctx->r4 = ADD32(0, 0X19);
            goto L_800A413C;
    }
    // 0x800A40CC: addiu       $a0, $zero, 0x19
    ctx->r4 = ADD32(0, 0X19);
    // 0x800A40D0: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800A40D4: jal         0x80001D04
    // 0x800A40D8: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    sound_play(rdram, ctx);
        goto after_16;
    // 0x800A40D8: addiu       $a1, $a1, 0x6D40
    ctx->r5 = ADD32(ctx->r5, 0X6D40);
    after_16:
    // 0x800A40DC: jal         0x8001B640
    // 0x800A40E0: nop

    timetrial_ghost_staff(rdram, ctx);
        goto after_17;
    // 0x800A40E0: nop

    after_17:
    // 0x800A40E4: beq         $v0, $zero, L_800A411C
    if (ctx->r2 == 0) {
        // 0x800A40E8: nop
    
            goto L_800A411C;
    }
    // 0x800A40E8: nop

    // 0x800A40EC: jal         0x8001B650
    // 0x800A40F0: nop

    timetrial_staff_unbeaten(rdram, ctx);
        goto after_18;
    // 0x800A40F0: nop

    after_18:
    // 0x800A40F4: bne         $v0, $zero, L_800A411C
    if (ctx->r2 != 0) {
        // 0x800A40F8: addiu       $a0, $zero, 0x24B
        ctx->r4 = ADD32(0, 0X24B);
            goto L_800A411C;
    }
    // 0x800A40F8: addiu       $a0, $zero, 0x24B
    ctx->r4 = ADD32(0, 0X24B);
    // 0x800A40FC: lui         $a1, 0x3FD9
    ctx->r5 = S32(0X3FD9 << 16);
    // 0x800A4100: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800A4104: jal         0x800A7484
    // 0x800A4108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    hud_sound_play_delayed(rdram, ctx);
        goto after_19;
    // 0x800A4108: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    after_19:
    // 0x800A410C: lui         $a1, 0x3FD9
    ctx->r5 = S32(0X3FD9 << 16);
    // 0x800A4110: ori         $a1, $a1, 0x999A
    ctx->r5 = ctx->r5 | 0X999A;
    // 0x800A4114: jal         0x800C3158
    // 0x800A4118: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    set_delayed_text(rdram, ctx);
        goto after_20;
    // 0x800A4118: addiu       $a0, $zero, 0x52
    ctx->r4 = ADD32(0, 0X52);
    after_20:
L_800A411C:
    // 0x800A411C: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x800A4120: lb          $t5, 0x6CD4($t5)
    ctx->r13 = MEM_B(ctx->r13, 0X6CD4);
    // 0x800A4124: addiu       $t4, $zero, 0x1
    ctx->r12 = ADD32(0, 0X1);
    // 0x800A4128: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A412C: sb          $t4, 0x6D70($at)
    MEM_B(0X6D70, ctx->r1) = ctx->r12;
    // 0x800A4130: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800A4134: addiu       $t6, $t5, 0x1
    ctx->r14 = ADD32(ctx->r13, 0X1);
    // 0x800A4138: sb          $t6, 0x6CD4($at)
    MEM_B(0X6CD4, ctx->r1) = ctx->r14;
L_800A413C:
    // 0x800A413C: jal         0x8007BF1C
    // 0x800A4140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    sprite_opaque(rdram, ctx);
        goto after_21;
    // 0x800A4140: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    after_21:
L_800A4144:
    // 0x800A4144: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800A4148: addiu       $sp, $sp, 0x58
    ctx->r29 = ADD32(ctx->r29, 0X58);
    // 0x800A414C: jr          $ra
    // 0x800A4150: nop

    return;
    // 0x800A4150: nop

;}
RECOMP_FUNC void alResamplePull(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800CC17C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x800CC180: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800CC184: sw          $a1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r5;
    // 0x800CC188: lw          $t1, 0x0($a0)
    ctx->r9 = MEM_W(ctx->r4, 0X0);
    // 0x800CC18C: addiu       $t6, $zero, 0x140
    ctx->r14 = ADD32(0, 0X140);
    // 0x800CC190: or          $t0, $a0, $zero
    ctx->r8 = ctx->r4 | 0;
    // 0x800CC194: or          $t2, $a2, $zero
    ctx->r10 = ctx->r6 | 0;
    // 0x800CC198: bne         $a2, $zero, L_800CC1A8
    if (ctx->r6 != 0) {
        // 0x800CC19C: sh          $t6, 0x46($sp)
        MEM_H(0X46, ctx->r29) = ctx->r14;
            goto L_800CC1A8;
    }
    // 0x800CC19C: sh          $t6, 0x46($sp)
    MEM_H(0X46, ctx->r29) = ctx->r14;
    // 0x800CC1A0: b           L_800CC374
    // 0x800CC1A4: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
        goto L_800CC374;
    // 0x800CC1A4: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
L_800CC1A8:
    // 0x800CC1A8: lw          $t7, 0x1C($t0)
    ctx->r15 = MEM_W(ctx->r8, 0X1C);
    // 0x800CC1AC: lw          $t8, 0x60($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X60);
    // 0x800CC1B0: beql        $t7, $zero, L_800CC21C
    if (ctx->r15 == 0) {
        // 0x800CC1B4: lwc1        $f2, 0x18($t0)
        ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
            goto L_800CC21C;
    }
    goto skip_0;
    // 0x800CC1B4: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    skip_0:
    // 0x800CC1B8: sw          $t8, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r24;
    // 0x800CC1BC: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800CC1C0: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800CC1C4: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CC1C8: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800CC1CC: jalr        $t9
    // 0x800CC1D0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_0;
    // 0x800CC1D0: or          $a2, $t2, $zero
    ctx->r6 = ctx->r10 | 0;
    after_0:
    // 0x800CC1D4: lh          $t3, 0x46($sp)
    ctx->r11 = MEM_H(ctx->r29, 0X46);
    // 0x800CC1D8: lui         $at, 0xFF
    ctx->r1 = S32(0XFF << 16);
    // 0x800CC1DC: ori         $at, $at, 0xFFFF
    ctx->r1 = ctx->r1 | 0XFFFF;
    // 0x800CC1E0: and         $t4, $t3, $at
    ctx->r12 = ctx->r11 & ctx->r1;
    // 0x800CC1E4: lui         $at, 0xA00
    ctx->r1 = S32(0XA00 << 16);
    // 0x800CC1E8: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CC1EC: or          $t5, $t4, $at
    ctx->r13 = ctx->r12 | ctx->r1;
    // 0x800CC1F0: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
    // 0x800CC1F4: lw          $t6, 0x54($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X54);
    // 0x800CC1F8: sll         $t3, $t2, 1
    ctx->r11 = S32(ctx->r10 << 1);
    // 0x800CC1FC: andi        $t4, $t3, 0xFFFF
    ctx->r12 = ctx->r11 & 0XFFFF;
    // 0x800CC200: lh          $t8, 0x0($t6)
    ctx->r24 = MEM_H(ctx->r14, 0X0);
    // 0x800CC204: addiu       $a1, $v0, 0x8
    ctx->r5 = ADD32(ctx->r2, 0X8);
    // 0x800CC208: sll         $t9, $t8, 16
    ctx->r25 = S32(ctx->r24 << 16);
    // 0x800CC20C: or          $t5, $t9, $t4
    ctx->r13 = ctx->r25 | ctx->r12;
    // 0x800CC210: b           L_800CC370
    // 0x800CC214: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
        goto L_800CC370;
    // 0x800CC214: sw          $t5, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r13;
    // 0x800CC218: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
L_800CC21C:
    // 0x800CC21C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CC220: ldc1        $f4, -0x69D8($at)
    CHECK_FR(ctx, 4);
    ctx->f4.u64 = LD(ctx->r1, -0X69D8);
    // 0x800CC224: cvt.d.s     $f6, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); 
    ctx->f6.d = CVT_D_S(ctx->f2.fl);
    // 0x800CC228: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800CC22C: c.lt.d      $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f4.d < ctx->f6.d;
    // 0x800CC230: nop

    // 0x800CC234: bc1fl       L_800CC24C
    if (!c1cs) {
        // 0x800CC238: lui         $at, 0x4700
        ctx->r1 = S32(0X4700 << 16);
            goto L_800CC24C;
    }
    goto skip_1;
    // 0x800CC238: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    skip_1:
    // 0x800CC23C: lwc1        $f8, -0x69D0($at)
    ctx->f8.u32l = MEM_W(ctx->r1, -0X69D0);
    // 0x800CC240: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800CC244: lwc1        $f2, 0x18($t0)
    ctx->f2.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC248: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
L_800CC24C:
    // 0x800CC24C: mtc1        $at, $f12
    ctx->f12.u32l = ctx->r1;
    // 0x800CC250: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800CC254: addiu       $a1, $sp, 0x46
    ctx->r5 = ADD32(ctx->r29, 0X46);
    // 0x800CC258: mul.s       $f10, $f2, $f12
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f10.fl = MUL_S(ctx->f2.fl, ctx->f12.fl);
    // 0x800CC25C: trunc.w.s   $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    ctx->f16.u32l = TRUNC_W_S(ctx->f10.fl);
    // 0x800CC260: mfc1        $t7, $f16
    ctx->r15 = (int32_t)ctx->f16.u32l;
    // 0x800CC264: mtc1        $t2, $f16
    ctx->f16.u32l = ctx->r10;
    // 0x800CC268: mtc1        $t7, $f18
    ctx->f18.u32l = ctx->r15;
    // 0x800CC26C: nop

    // 0x800CC270: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800CC274: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CC278: swc1        $f4, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f4.u32l;
    // 0x800CC27C: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC280: div.s       $f8, $f6, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = DIV_S(ctx->f6.fl, ctx->f12.fl);
    // 0x800CC284: lwc1        $f6, 0x20($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X20);
    // 0x800CC288: swc1        $f8, 0x18($t0)
    MEM_W(0X18, ctx->r8) = ctx->f8.u32l;
    // 0x800CC28C: lwc1        $f10, 0x18($t0)
    ctx->f10.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC290: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x800CC294: add.s       $f0, $f6, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800CC298: trunc.w.s   $f8, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    ctx->f8.u32l = TRUNC_W_S(ctx->f0.fl);
    // 0x800CC29C: mfc1        $a2, $f8
    ctx->r6 = (int32_t)ctx->f8.u32l;
    // 0x800CC2A0: nop

    // 0x800CC2A4: mtc1        $a2, $f16
    ctx->f16.u32l = ctx->r6;
    // 0x800CC2A8: nop

    // 0x800CC2AC: cvt.s.w     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    ctx->f10.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800CC2B0: sub.s       $f18, $f0, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f0.fl - ctx->f10.fl;
    // 0x800CC2B4: swc1        $f18, 0x20($t0)
    MEM_W(0X20, ctx->r8) = ctx->f18.u32l;
    // 0x800CC2B8: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800CC2BC: sw          $t2, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r10;
    // 0x800CC2C0: sw          $t0, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r8;
    // 0x800CC2C4: sw          $t3, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r11;
    // 0x800CC2C8: lw          $t9, 0x4($t1)
    ctx->r25 = MEM_W(ctx->r9, 0X4);
    // 0x800CC2CC: jalr        $t9
    // 0x800CC2D0: nop

    LOOKUP_FUNC(ctx->r25)(rdram, ctx);
        goto after_1;
    // 0x800CC2D0: nop

    after_1:
    // 0x800CC2D4: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800CC2D8: lh          $t5, 0x46($sp)
    ctx->r13 = MEM_H(ctx->r29, 0X46);
    // 0x800CC2DC: lui         $at, 0x4700
    ctx->r1 = S32(0X4700 << 16);
    // 0x800CC2E0: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800CC2E4: lwc1        $f6, 0x18($t0)
    ctx->f6.u32l = MEM_W(ctx->r8, 0X18);
    // 0x800CC2E8: lui         $at, 0x800
    ctx->r1 = S32(0X800 << 16);
    // 0x800CC2EC: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CC2F0: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x800CC2F4: or          $t7, $t6, $at
    ctx->r15 = ctx->r14 | ctx->r1;
    // 0x800CC2F8: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
    // 0x800CC2FC: lw          $t8, 0x54($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X54);
    // 0x800CC300: mul.s       $f8, $f6, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f8.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800CC304: sll         $t5, $t2, 1
    ctx->r13 = S32(ctx->r10 << 1);
    // 0x800CC308: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x800CC30C: andi        $t6, $t5, 0xFFFF
    ctx->r14 = ctx->r13 & 0XFFFF;
    // 0x800CC310: addiu       $t8, $v0, 0x8
    ctx->r24 = ADD32(ctx->r2, 0X8);
    // 0x800CC314: sll         $t4, $t9, 16
    ctx->r12 = S32(ctx->r25 << 16);
    // 0x800CC318: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800CC31C: trunc.w.s   $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.u32l = TRUNC_W_S(ctx->f8.fl);
    // 0x800CC320: sw          $t7, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r15;
    // 0x800CC324: sw          $t8, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r24;
    // 0x800CC328: lw          $t3, 0x24($t0)
    ctx->r11 = MEM_W(ctx->r8, 0X24);
    // 0x800CC32C: mfc1        $v1, $f16
    ctx->r3 = (int32_t)ctx->f16.u32l;
    // 0x800CC330: lui         $at, 0x500
    ctx->r1 = S32(0X500 << 16);
    // 0x800CC334: andi        $t9, $t3, 0xFF
    ctx->r25 = ctx->r11 & 0XFF;
    // 0x800CC338: sll         $t5, $t9, 16
    ctx->r13 = S32(ctx->r25 << 16);
    // 0x800CC33C: or          $t4, $t5, $at
    ctx->r12 = ctx->r13 | ctx->r1;
    // 0x800CC340: andi        $t6, $v1, 0xFFFF
    ctx->r14 = ctx->r3 & 0XFFFF;
    // 0x800CC344: or          $t7, $t4, $t6
    ctx->r15 = ctx->r12 | ctx->r14;
    // 0x800CC348: sw          $t7, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r15;
    // 0x800CC34C: addiu       $a1, $v0, 0x10
    ctx->r5 = ADD32(ctx->r2, 0X10);
    // 0x800CC350: lw          $a0, 0x14($t0)
    ctx->r4 = MEM_W(ctx->r8, 0X14);
    // 0x800CC354: jal         0x800C8CF0
    // 0x800CC358: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    osVirtualToPhysical_recomp(rdram, ctx);
        goto after_2;
    // 0x800CC358: sw          $a1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r5;
    after_2:
    // 0x800CC35C: lw          $t8, 0x28($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X28);
    // 0x800CC360: lw          $t0, 0x50($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X50);
    // 0x800CC364: lw          $a1, 0x48($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X48);
    // 0x800CC368: sw          $v0, 0x4($t8)
    MEM_W(0X4, ctx->r24) = ctx->r2;
    // 0x800CC36C: sw          $zero, 0x24($t0)
    MEM_W(0X24, ctx->r8) = 0;
L_800CC370:
    // 0x800CC370: or          $v0, $a1, $zero
    ctx->r2 = ctx->r5 | 0;
L_800CC374:
    // 0x800CC374: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800CC378: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    // 0x800CC37C: jr          $ra
    // 0x800CC380: nop

    return;
    // 0x800CC380: nop

;}
RECOMP_FUNC void populate_settings_from_save_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007306C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x80073070: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80073074: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x80073078: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8007307C: or          $s1, $a1, $zero
    ctx->r17 = ctx->r5 | 0;
    // 0x80073080: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x80073084: jal         0x8006E994
    // 0x80073088: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    clear_game_progress(rdram, ctx);
        goto after_0;
    // 0x80073088: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8007308C: addiu       $a0, $sp, 0x48
    ctx->r4 = ADD32(ctx->r29, 0X48);
    // 0x80073090: jal         0x8006B224
    // 0x80073094: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    level_count(rdram, ctx);
        goto after_1;
    // 0x80073094: addiu       $a1, $sp, 0x44
    ctx->r5 = ADD32(ctx->r29, 0X44);
    after_1:
    // 0x80073098: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8007309C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800730A0: sw          $s1, 0x41EC($at)
    MEM_W(0X41EC, ctx->r1) = ctx->r17;
    // 0x800730A4: addiu       $v0, $v0, 0x41F4
    ctx->r2 = ADD32(ctx->r2, 0X41F4);
    // 0x800730A8: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
    // 0x800730AC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800730B0: sw          $zero, 0x41F0($at)
    MEM_W(0X41F0, ctx->r1) = 0;
    // 0x800730B4: jal         0x80072C54
    // 0x800730B8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_2;
    // 0x800730B8: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_2:
    // 0x800730BC: addiu       $a0, $v0, -0x5
    ctx->r4 = ADD32(ctx->r2, -0X5);
    // 0x800730C0: sll         $t7, $a0, 16
    ctx->r15 = S32(ctx->r4 << 16);
    // 0x800730C4: sra         $a0, $t7, 16
    ctx->r4 = S32(SIGNED(ctx->r15) >> 16);
    // 0x800730C8: addiu       $s0, $zero, 0x2
    ctx->r16 = ADD32(0, 0X2);
    // 0x800730CC: addiu       $v1, $s1, 0x2
    ctx->r3 = ADD32(ctx->r17, 0X2);
L_800730D0:
    // 0x800730D0: lbu         $t9, 0x0($v1)
    ctx->r25 = MEM_BU(ctx->r3, 0X0);
    // 0x800730D4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800730D8: subu        $a0, $a0, $t9
    ctx->r4 = SUB32(ctx->r4, ctx->r25);
    // 0x800730DC: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x800730E0: sra         $t1, $t0, 16
    ctx->r9 = S32(SIGNED(ctx->r8) >> 16);
    // 0x800730E4: slti        $at, $s0, 0x28
    ctx->r1 = SIGNED(ctx->r16) < 0X28 ? 1 : 0;
    // 0x800730E8: or          $a0, $t1, $zero
    ctx->r4 = ctx->r9 | 0;
    // 0x800730EC: bne         $at, $zero, L_800730D0
    if (ctx->r1 != 0) {
        // 0x800730F0: addiu       $v1, $v1, 0x1
        ctx->r3 = ADD32(ctx->r3, 0X1);
            goto L_800730D0;
    }
    // 0x800730F0: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x800730F4: bne         $t1, $zero, L_800732D4
    if (ctx->r9 != 0) {
        // 0x800730F8: lw          $ra, 0x24($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X24);
            goto L_800732D4;
    }
    // 0x800730F8: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800730FC: lw          $t2, 0x48($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X48);
    // 0x80073100: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x80073104: blez        $t2, L_800731C0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80073108: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_800731C0;
    }
    // 0x80073108: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
L_8007310C:
    // 0x8007310C: jal         0x8006B14C
    // 0x80073110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_type(rdram, ctx);
        goto after_3;
    // 0x80073110: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80073114: beq         $v0, $zero, L_8007312C
    if (ctx->r2 == 0) {
        // 0x80073118: andi        $t3, $v0, 0x40
        ctx->r11 = ctx->r2 & 0X40;
            goto L_8007312C;
    }
    // 0x80073118: andi        $t3, $v0, 0x40
    ctx->r11 = ctx->r2 & 0X40;
    // 0x8007311C: bne         $t3, $zero, L_8007312C
    if (ctx->r11 != 0) {
        // 0x80073120: addiu       $at, $zero, 0x8
        ctx->r1 = ADD32(0, 0X8);
            goto L_8007312C;
    }
    // 0x80073120: addiu       $at, $zero, 0x8
    ctx->r1 = ADD32(0, 0X8);
    // 0x80073124: bne         $v0, $at, L_800731AC
    if (ctx->r2 != ctx->r1) {
        // 0x80073128: lw          $t6, 0x48($sp)
        ctx->r14 = MEM_W(ctx->r29, 0X48);
            goto L_800731AC;
    }
    // 0x80073128: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_8007312C:
    // 0x8007312C: jal         0x80072C54
    // 0x80073130: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    func_80072C54(rdram, ctx);
        goto after_4;
    // 0x80073130: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_4:
    // 0x80073134: andi        $v1, $v0, 0xFF
    ctx->r3 = ctx->r2 & 0XFF;
    // 0x80073138: blez        $v1, L_8007315C
    if (SIGNED(ctx->r3) <= 0) {
        // 0x8007313C: slti        $at, $v1, 0x2
        ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
            goto L_8007315C;
    }
    // 0x8007313C: slti        $at, $v1, 0x2
    ctx->r1 = SIGNED(ctx->r3) < 0X2 ? 1 : 0;
    // 0x80073140: lw          $t4, 0x4($s2)
    ctx->r12 = MEM_W(ctx->r18, 0X4);
    // 0x80073144: sll         $t5, $s0, 2
    ctx->r13 = S32(ctx->r16 << 2);
    // 0x80073148: addu        $v0, $t4, $t5
    ctx->r2 = ADD32(ctx->r12, ctx->r13);
    // 0x8007314C: lw          $t6, 0x0($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X0);
    // 0x80073150: nop

    // 0x80073154: ori         $t7, $t6, 0x1
    ctx->r15 = ctx->r14 | 0X1;
    // 0x80073158: sw          $t7, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r15;
L_8007315C:
    // 0x8007315C: bne         $at, $zero, L_80073180
    if (ctx->r1 != 0) {
        // 0x80073160: addiu       $s1, $s1, 0x2
        ctx->r17 = ADD32(ctx->r17, 0X2);
            goto L_80073180;
    }
    // 0x80073160: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x80073164: lw          $t8, 0x4($s2)
    ctx->r24 = MEM_W(ctx->r18, 0X4);
    // 0x80073168: sll         $t9, $s0, 2
    ctx->r25 = S32(ctx->r16 << 2);
    // 0x8007316C: addu        $v0, $t8, $t9
    ctx->r2 = ADD32(ctx->r24, ctx->r25);
    // 0x80073170: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x80073174: nop

    // 0x80073178: ori         $t1, $t0, 0x2
    ctx->r9 = ctx->r8 | 0X2;
    // 0x8007317C: sw          $t1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r9;
L_80073180:
    // 0x80073180: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x80073184: bne         $at, $zero, L_800731A8
    if (ctx->r1 != 0) {
        // 0x80073188: nop
    
            goto L_800731A8;
    }
    // 0x80073188: nop

    // 0x8007318C: lw          $t2, 0x4($s2)
    ctx->r10 = MEM_W(ctx->r18, 0X4);
    // 0x80073190: sll         $t3, $s0, 2
    ctx->r11 = S32(ctx->r16 << 2);
    // 0x80073194: addu        $v0, $t2, $t3
    ctx->r2 = ADD32(ctx->r10, ctx->r11);
    // 0x80073198: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8007319C: nop

    // 0x800731A0: ori         $t5, $t4, 0x4
    ctx->r13 = ctx->r12 | 0X4;
    // 0x800731A4: sw          $t5, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r13;
L_800731A8:
    // 0x800731A8: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
L_800731AC:
    // 0x800731AC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800731B0: slt         $at, $s0, $t6
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x800731B4: bne         $at, $zero, L_8007310C
    if (ctx->r1 != 0) {
        // 0x800731B8: nop
    
            goto L_8007310C;
    }
    // 0x800731B8: nop

    // 0x800731BC: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800731C0:
    // 0x800731C0: addiu       $t7, $zero, 0x44
    ctx->r15 = ADD32(0, 0X44);
    // 0x800731C4: jal         0x80072C54
    // 0x800731C8: subu        $a0, $t7, $s1
    ctx->r4 = SUB32(ctx->r15, ctx->r17);
    func_80072C54(rdram, ctx);
        goto after_5;
    // 0x800731C8: subu        $a0, $t7, $s1
    ctx->r4 = SUB32(ctx->r15, ctx->r17);
    after_5:
    // 0x800731CC: jal         0x80072C54
    // 0x800731D0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    func_80072C54(rdram, ctx);
        goto after_6;
    // 0x800731D0: addiu       $a0, $zero, 0x6
    ctx->r4 = ADD32(0, 0X6);
    after_6:
    // 0x800731D4: sh          $v0, 0x14($s2)
    MEM_H(0X14, ctx->r18) = ctx->r2;
    // 0x800731D8: jal         0x80072C54
    // 0x800731DC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    func_80072C54(rdram, ctx);
        goto after_7;
    // 0x800731DC: addiu       $a0, $zero, 0xA
    ctx->r4 = ADD32(0, 0XA);
    after_7:
    // 0x800731E0: sh          $v0, 0xE($s2)
    MEM_H(0XE, ctx->r18) = ctx->r2;
    // 0x800731E4: jal         0x80072C54
    // 0x800731E8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    func_80072C54(rdram, ctx);
        goto after_8;
    // 0x800731E8: addiu       $a0, $zero, 0xC
    ctx->r4 = ADD32(0, 0XC);
    after_8:
    // 0x800731EC: sh          $v0, 0xC($s2)
    MEM_H(0XC, ctx->r18) = ctx->r2;
    // 0x800731F0: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x800731F4: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800731F8: blez        $t8, L_80073234
    if (SIGNED(ctx->r24) <= 0) {
        // 0x800731FC: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80073234;
    }
    // 0x800731FC: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
L_80073200:
    // 0x80073200: jal         0x80072C54
    // 0x80073204: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    func_80072C54(rdram, ctx);
        goto after_9;
    // 0x80073204: sw          $v1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r3;
    after_9:
    // 0x80073208: lw          $v1, 0x2C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X2C);
    // 0x8007320C: lw          $t9, 0x0($s2)
    ctx->r25 = MEM_W(ctx->r18, 0X0);
    // 0x80073210: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80073214: addu        $t0, $t9, $v1
    ctx->r8 = ADD32(ctx->r25, ctx->r3);
    // 0x80073218: sh          $v0, 0x0($t0)
    MEM_H(0X0, ctx->r8) = ctx->r2;
    // 0x8007321C: lw          $t1, 0x44($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X44);
    // 0x80073220: addiu       $v1, $v1, 0x2
    ctx->r3 = ADD32(ctx->r3, 0X2);
    // 0x80073224: slt         $at, $s0, $t1
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r9) ? 1 : 0;
    // 0x80073228: bne         $at, $zero, L_80073200
    if (ctx->r1 != 0) {
        // 0x8007322C: addiu       $a0, $zero, 0x7
        ctx->r4 = ADD32(0, 0X7);
            goto L_80073200;
    }
    // 0x8007322C: addiu       $a0, $zero, 0x7
    ctx->r4 = ADD32(0, 0X7);
    // 0x80073230: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80073234:
    // 0x80073234: jal         0x80072C54
    // 0x80073238: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80072C54(rdram, ctx);
        goto after_10;
    // 0x80073238: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_10:
    // 0x8007323C: sb          $v0, 0x16($s2)
    MEM_B(0X16, ctx->r18) = ctx->r2;
    // 0x80073240: jal         0x80072C54
    // 0x80073244: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    func_80072C54(rdram, ctx);
        goto after_11;
    // 0x80073244: addiu       $a0, $zero, 0x3
    ctx->r4 = ADD32(0, 0X3);
    after_11:
    // 0x80073248: sb          $v0, 0x17($s2)
    MEM_B(0X17, ctx->r18) = ctx->r2;
    // 0x8007324C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x80073250: nop

    // 0x80073254: blez        $t2, L_800732A0
    if (SIGNED(ctx->r10) <= 0) {
        // 0x80073258: nop
    
            goto L_800732A0;
    }
    // 0x80073258: nop

L_8007325C:
    // 0x8007325C: jal         0x80072C54
    // 0x80073260: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_12;
    // 0x80073260: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_12:
    // 0x80073264: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x80073268: jal         0x8006B1D4
    // 0x8007326C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    level_world_id(rdram, ctx);
        goto after_13;
    // 0x8007326C: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_13:
    // 0x80073270: lw          $t3, 0x4($s2)
    ctx->r11 = MEM_W(ctx->r18, 0X4);
    // 0x80073274: sll         $t4, $v0, 2
    ctx->r12 = S32(ctx->r2 << 2);
    // 0x80073278: addu        $v1, $t3, $t4
    ctx->r3 = ADD32(ctx->r11, ctx->r12);
    // 0x8007327C: lw          $t5, 0x0($v1)
    ctx->r13 = MEM_W(ctx->r3, 0X0);
    // 0x80073280: sll         $t6, $s1, 16
    ctx->r14 = S32(ctx->r17 << 16);
    // 0x80073284: or          $t7, $t5, $t6
    ctx->r15 = ctx->r13 | ctx->r14;
    // 0x80073288: sw          $t7, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r15;
    // 0x8007328C: lw          $t8, 0x44($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X44);
    // 0x80073290: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80073294: slt         $at, $s0, $t8
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r24) ? 1 : 0;
    // 0x80073298: bne         $at, $zero, L_8007325C
    if (ctx->r1 != 0) {
        // 0x8007329C: nop
    
            goto L_8007325C;
    }
    // 0x8007329C: nop

L_800732A0:
    // 0x800732A0: jal         0x80072C54
    // 0x800732A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80072C54(rdram, ctx);
        goto after_14;
    // 0x800732A4: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_14:
    // 0x800732A8: sh          $v0, 0x8($s2)
    MEM_H(0X8, ctx->r18) = ctx->r2;
    // 0x800732AC: jal         0x80072C54
    // 0x800732B0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    func_80072C54(rdram, ctx);
        goto after_15;
    // 0x800732B0: addiu       $a0, $zero, 0x20
    ctx->r4 = ADD32(0, 0X20);
    after_15:
    // 0x800732B4: sw          $v0, 0x10($s2)
    MEM_W(0X10, ctx->r18) = ctx->r2;
    // 0x800732B8: jal         0x80072C54
    // 0x800732BC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    func_80072C54(rdram, ctx);
        goto after_16;
    // 0x800732BC: addiu       $a0, $zero, 0x10
    ctx->r4 = ADD32(0, 0X10);
    after_16:
    // 0x800732C0: sw          $v0, 0x50($s2)
    MEM_W(0X50, ctx->r18) = ctx->r2;
    // 0x800732C4: jal         0x80072C54
    // 0x800732C8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    func_80072C54(rdram, ctx);
        goto after_17;
    // 0x800732C8: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
    after_17:
    // 0x800732CC: sb          $zero, 0x4B($s2)
    MEM_B(0X4B, ctx->r18) = 0;
    // 0x800732D0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_800732D4:
    // 0x800732D4: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800732D8: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x800732DC: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x800732E0: jr          $ra
    // 0x800732E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x800732E4: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void free_all_objects(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000C604: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8000C608: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8000C60C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8000C610: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8000C614: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8000C618: jal         0x80059B4C
    // 0x8000C61C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    timetrial_free_staff_ghost(rdram, ctx);
        goto after_0;
    // 0x8000C61C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x8000C620: lui         $s0, 0x800E
    ctx->r16 = S32(0X800E << 16);
    // 0x8000C624: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8000C628: addiu       $s0, $s0, -0x38E4
    ctx->r16 = ADD32(ctx->r16, -0X38E4);
    // 0x8000C62C: sb          $zero, -0x38B8($at)
    MEM_B(-0X38B8, ctx->r1) = 0;
    // 0x8000C630: lb          $t6, 0x0($s0)
    ctx->r14 = MEM_B(ctx->r16, 0X0);
    // 0x8000C634: nop

    // 0x8000C638: beq         $t6, $zero, L_8000C648
    if (ctx->r14 == 0) {
        // 0x8000C63C: nop
    
            goto L_8000C648;
    }
    // 0x8000C63C: nop

    // 0x8000C640: jal         0x80072298
    // 0x8000C644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    rumble_init(rdram, ctx);
        goto after_1;
    // 0x8000C644: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_8000C648:
    // 0x8000C648: lui         $s1, 0x800E
    ctx->r17 = S32(0X800E << 16);
    // 0x8000C64C: addiu       $s1, $s1, -0x38BC
    ctx->r17 = ADD32(ctx->r17, -0X38BC);
    // 0x8000C650: lb          $t7, 0x0($s1)
    ctx->r15 = MEM_B(ctx->r17, 0X0);
    // 0x8000C654: sb          $zero, 0x0($s0)
    MEM_B(0X0, ctx->r16) = 0;
    // 0x8000C658: beq         $t7, $zero, L_8000C678
    if (ctx->r15 == 0) {
        // 0x8000C65C: nop
    
            goto L_8000C678;
    }
    // 0x8000C65C: nop

    // 0x8000C660: jal         0x8009EC80
    // 0x8000C664: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x8000C664: nop

    after_2:
    // 0x8000C668: beq         $v0, $zero, L_8000C678
    if (ctx->r2 == 0) {
        // 0x8000C66C: nop
    
            goto L_8000C678;
    }
    // 0x8000C66C: nop

    // 0x8000C670: jal         0x8006F398
    // 0x8000C674: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    swap_lead_player(rdram, ctx);
        goto after_3;
    // 0x8000C674: sb          $zero, 0x0($s1)
    MEM_B(0X0, ctx->r17) = 0;
    after_3:
L_8000C678:
    // 0x8000C678: jal         0x8001004C
    // 0x8000C67C: nop

    gParticlePtrList_flush(rdram, ctx);
        goto after_4;
    // 0x8000C67C: nop

    after_4:
    // 0x8000C680: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8000C684: lw          $s2, -0x51A4($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X51A4);
    // 0x8000C688: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8000C68C: blez        $s2, L_8000C6C0
    if (SIGNED(ctx->r18) <= 0) {
        // 0x8000C690: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8000C6C0;
    }
    // 0x8000C690: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8000C694: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x8000C698: addiu       $s3, $s3, -0x51A8
    ctx->r19 = ADD32(ctx->r19, -0X51A8);
L_8000C69C:
    // 0x8000C69C: lw          $t8, 0x0($s3)
    ctx->r24 = MEM_W(ctx->r19, 0X0);
    // 0x8000C6A0: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x8000C6A4: addu        $t9, $t8, $s1
    ctx->r25 = ADD32(ctx->r24, ctx->r17);
    // 0x8000C6A8: lw          $a0, 0x0($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X0);
    // 0x8000C6AC: jal         0x800101AC
    // 0x8000C6B0: nop

    obj_destroy(rdram, ctx);
        goto after_5;
    // 0x8000C6B0: nop

    after_5:
    // 0x8000C6B4: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8000C6B8: bne         $s0, $s2, L_8000C69C
    if (ctx->r16 != ctx->r18) {
        // 0x8000C6BC: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8000C69C;
    }
    // 0x8000C6BC: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8000C6C0:
    // 0x8000C6C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C6C4: sw          $zero, -0x5138($at)
    MEM_W(-0X5138, ctx->r1) = 0;
    // 0x8000C6C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C6CC: sw          $zero, -0x51A4($at)
    MEM_W(-0X51A4, ctx->r1) = 0;
    // 0x8000C6D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8000C6D4: jal         0x8000C460
    // 0x8000C6D8: sw          $zero, -0x51A0($at)
    MEM_W(-0X51A0, ctx->r1) = 0;
    clear_object_pointers(rdram, ctx);
        goto after_6;
    // 0x8000C6D8: sw          $zero, -0x51A0($at)
    MEM_W(-0X51A0, ctx->r1) = 0;
    after_6:
    // 0x8000C6DC: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8000C6E0: addiu       $s0, $s0, -0x5150
    ctx->r16 = ADD32(ctx->r16, -0X5150);
    // 0x8000C6E4: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8000C6E8: jal         0x80071140
    // 0x8000C6EC: nop

    mempool_free(rdram, ctx);
        goto after_7;
    // 0x8000C6EC: nop

    after_7:
    // 0x8000C6F0: lw          $a0, 0x4($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X4);
    // 0x8000C6F4: jal         0x80071140
    // 0x8000C6F8: nop

    mempool_free(rdram, ctx);
        goto after_8;
    // 0x8000C6F8: nop

    after_8:
    // 0x8000C6FC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8000C700: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8000C704: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8000C708: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8000C70C: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8000C710: jr          $ra
    // 0x8000C714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x8000C714: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void transition_fullscreen_start(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C0780: lbu         $t6, 0x0($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X0);
    // 0x800C0784: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0788: andi        $t7, $t6, 0x80
    ctx->r15 = ctx->r14 & 0X80;
    // 0x800C078C: beq         $t7, $zero, L_800C07E4
    if (ctx->r15 == 0) {
        // 0x800C0790: addiu       $t0, $zero, 0x1
        ctx->r8 = ADD32(0, 0X1);
            goto L_800C07E4;
    }
    // 0x800C0790: addiu       $t0, $zero, 0x1
    ctx->r8 = ADD32(0, 0X1);
    // 0x800C0794: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C0798: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x800C079C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x800C07A0: lhu         $t8, 0x31B0($t8)
    ctx->r24 = MEM_HU(ctx->r24, 0X31B0);
    // 0x800C07A4: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C07A8: swc1        $f4, -0x58B0($at)
    MEM_W(-0X58B0, ctx->r1) = ctx->f4.u32l;
    // 0x800C07AC: mtc1        $t8, $f8
    ctx->f8.u32l = ctx->r24;
    // 0x800C07B0: lui         $at, 0xC37F
    ctx->r1 = S32(0XC37F << 16);
    // 0x800C07B4: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800C07B8: bgez        $t8, L_800C07D0
    if (SIGNED(ctx->r24) >= 0) {
        // 0x800C07BC: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800C07D0;
    }
    // 0x800C07BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800C07C0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C07C4: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800C07C8: nop

    // 0x800C07CC: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800C07D0:
    // 0x800C07D0: nop

    // 0x800C07D4: div.s       $f18, $f6, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = DIV_S(ctx->f6.fl, ctx->f10.fl);
    // 0x800C07D8: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C07DC: b           L_800C0828
    // 0x800C07E0: swc1        $f18, -0x58AC($at)
    MEM_W(-0X58AC, ctx->r1) = ctx->f18.u32l;
        goto L_800C0828;
    // 0x800C07E0: swc1        $f18, -0x58AC($at)
    MEM_W(-0X58AC, ctx->r1) = ctx->f18.u32l;
L_800C07E4:
    // 0x800C07E4: mtc1        $zero, $f4
    ctx->f4.u32l = 0;
    // 0x800C07E8: lui         $t9, 0x800E
    ctx->r25 = S32(0X800E << 16);
    // 0x800C07EC: lhu         $t9, 0x31B0($t9)
    ctx->r25 = MEM_HU(ctx->r25, 0X31B0);
    // 0x800C07F0: swc1        $f4, -0x58B0($at)
    MEM_W(-0X58B0, ctx->r1) = ctx->f4.u32l;
    // 0x800C07F4: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800C07F8: lui         $at, 0x437F
    ctx->r1 = S32(0X437F << 16);
    // 0x800C07FC: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x800C0800: bgez        $t9, L_800C0818
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800C0804: cvt.s.w     $f6, $f16
        CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
            goto L_800C0818;
    }
    // 0x800C0804: cvt.s.w     $f6, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    ctx->f6.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800C0808: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800C080C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800C0810: nop

    // 0x800C0814: add.s       $f6, $f6, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f6.fl = ctx->f6.fl + ctx->f10.fl;
L_800C0818:
    // 0x800C0818: nop

    // 0x800C081C: div.s       $f18, $f8, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f18.fl = DIV_S(ctx->f8.fl, ctx->f6.fl);
    // 0x800C0820: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C0824: swc1        $f18, -0x58AC($at)
    MEM_W(-0X58AC, ctx->r1) = ctx->f18.u32l;
L_800C0828:
    // 0x800C0828: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C082C: jr          $ra
    // 0x800C0830: sw          $t0, 0x31AC($at)
    MEM_W(0X31AC, ctx->r1) = ctx->r8;
    return;
    // 0x800C0830: sw          $t0, 0x31AC($at)
    MEM_W(0X31AC, ctx->r1) = ctx->r8;
;}
RECOMP_FUNC void racer_sound_enable(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80007F78: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x80007F7C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80007F80: jr          $ra
    // 0x80007F84: sb          $t6, -0x3930($at)
    MEM_B(-0X3930, ctx->r1) = ctx->r14;
    return;
    // 0x80007F84: sb          $t6, -0x3930($at)
    MEM_B(-0X3930, ctx->r1) = ctx->r14;
;}
RECOMP_FUNC void menu_input(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008E4EC: addiu       $sp, $sp, -0x78
    ctx->r29 = ADD32(ctx->r29, -0X78);
    // 0x8008E4F0: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E4F4: lw          $t6, 0x63C4($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X63C4);
    // 0x8008E4F8: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8008E4FC: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8008E500: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8008E504: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8008E508: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8008E50C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8008E510: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8008E514: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8008E518: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8008E51C: bne         $t6, $zero, L_8008E6BC
    if (ctx->r14 != 0) {
        // 0x8008E520: sw          $s0, 0x18($sp)
        MEM_W(0X18, ctx->r29) = ctx->r16;
            goto L_8008E6BC;
    }
    // 0x8008E520: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8008E524: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008E528: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008E52C: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8008E530: addiu       $v0, $v0, 0x683A
    ctx->r2 = ADD32(ctx->r2, 0X683A);
    // 0x8008E534: addiu       $s1, $s1, 0x6830
    ctx->r17 = ADD32(ctx->r17, 0X6830);
    // 0x8008E538: addiu       $s2, $s2, 0x6818
    ctx->r18 = ADD32(ctx->r18, 0X6818);
    // 0x8008E53C: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
L_8008E540:
    // 0x8008E540: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8008E544: sltu        $at, $s1, $v0
    ctx->r1 = ctx->r17 < ctx->r2 ? 1 : 0;
    // 0x8008E548: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008E54C: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8008E550: sw          $zero, -0x4($s0)
    MEM_W(-0X4, ctx->r16) = 0;
    // 0x8008E554: sh          $zero, -0x2($s2)
    MEM_H(-0X2, ctx->r18) = 0;
    // 0x8008E558: bne         $at, $zero, L_8008E540
    if (ctx->r1 != 0) {
        // 0x8008E55C: sh          $zero, -0x2($s1)
        MEM_H(-0X2, ctx->r17) = 0;
            goto L_8008E540;
    }
    // 0x8008E55C: sh          $zero, -0x2($s1)
    MEM_H(-0X2, ctx->r17) = 0;
    // 0x8008E560: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8008E564: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8008E568: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8008E56C: lui         $s5, 0x8012
    ctx->r21 = S32(0X8012 << 16);
    // 0x8008E570: lui         $fp, 0x800E
    ctx->r30 = S32(0X800E << 16);
    // 0x8008E574: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008E578: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008E57C: addiu       $s6, $s6, 0x6818
    ctx->r22 = ADD32(ctx->r22, 0X6818);
    // 0x8008E580: addiu       $s7, $s7, 0x6830
    ctx->r23 = ADD32(ctx->r23, 0X6830);
    // 0x8008E584: addiu       $fp, $fp, -0xB44
    ctx->r30 = ADD32(ctx->r30, -0XB44);
    // 0x8008E588: addiu       $s5, $s5, 0x6464
    ctx->r21 = ADD32(ctx->r21, 0X6464);
    // 0x8008E58C: addiu       $s4, $s4, 0x645C
    ctx->r20 = ADD32(ctx->r20, 0X645C);
    // 0x8008E590: addiu       $s1, $s1, 0x6830
    ctx->r17 = ADD32(ctx->r17, 0X6830);
    // 0x8008E594: addiu       $s2, $s2, 0x6818
    ctx->r18 = ADD32(ctx->r18, 0X6818);
    // 0x8008E598: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8008E59C: addiu       $s0, $sp, 0x60
    ctx->r16 = ADD32(ctx->r29, 0X60);
L_8008E5A0:
    // 0x8008E5A0: jal         0x8006A528
    // 0x8008E5A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    input_held(rdram, ctx);
        goto after_0;
    // 0x8008E5A4: or          $a0, $s3, $zero
    ctx->r4 = ctx->r19 | 0;
    after_0:
    // 0x8008E5A8: lw          $t7, 0x0($fp)
    ctx->r15 = MEM_W(ctx->r30, 0X0);
    // 0x8008E5AC: lb          $v1, 0x0($s4)
    ctx->r3 = MEM_B(ctx->r20, 0X0);
    // 0x8008E5B0: lb          $a0, 0x0($s5)
    ctx->r4 = MEM_B(ctx->r21, 0X0);
    // 0x8008E5B4: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8008E5B8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x8008E5BC: sh          $v1, 0x0($s2)
    MEM_H(0X0, ctx->r18) = ctx->r3;
    // 0x8008E5C0: beq         $at, $zero, L_8008E5EC
    if (ctx->r1 == 0) {
        // 0x8008E5C4: sh          $a0, 0x0($s1)
        MEM_H(0X0, ctx->r17) = ctx->r4;
            goto L_8008E5EC;
    }
    // 0x8008E5C4: sh          $a0, 0x0($s1)
    MEM_H(0X0, ctx->r17) = ctx->r4;
    // 0x8008E5C8: lw          $t8, 0x70($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X70);
    // 0x8008E5CC: lh          $t2, 0x8($s6)
    ctx->r10 = MEM_H(ctx->r22, 0X8);
    // 0x8008E5D0: lh          $t4, 0x8($s7)
    ctx->r12 = MEM_H(ctx->r23, 0X8);
    // 0x8008E5D4: or          $t1, $t8, $v0
    ctx->r9 = ctx->r24 | ctx->r2;
    // 0x8008E5D8: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8008E5DC: addu        $t5, $t4, $a0
    ctx->r13 = ADD32(ctx->r12, ctx->r4);
    // 0x8008E5E0: sw          $t1, 0x70($sp)
    MEM_W(0X70, ctx->r29) = ctx->r9;
    // 0x8008E5E4: sh          $t3, 0x8($s6)
    MEM_H(0X8, ctx->r22) = ctx->r11;
    // 0x8008E5E8: sh          $t5, 0x8($s7)
    MEM_H(0X8, ctx->r23) = ctx->r13;
L_8008E5EC:
    // 0x8008E5EC: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8008E5F0: slti        $at, $s3, 0x4
    ctx->r1 = SIGNED(ctx->r19) < 0X4 ? 1 : 0;
    // 0x8008E5F4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x8008E5F8: addiu       $s2, $s2, 0x2
    ctx->r18 = ADD32(ctx->r18, 0X2);
    // 0x8008E5FC: addiu       $s1, $s1, 0x2
    ctx->r17 = ADD32(ctx->r17, 0X2);
    // 0x8008E600: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x8008E604: bne         $at, $zero, L_8008E5A0
    if (ctx->r1 != 0) {
        // 0x8008E608: addiu       $s5, $s5, 0x1
        ctx->r21 = ADD32(ctx->r21, 0X1);
            goto L_8008E5A0;
    }
    // 0x8008E608: addiu       $s5, $s5, 0x1
    ctx->r21 = ADD32(ctx->r21, 0X1);
    // 0x8008E60C: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008E610: lw          $t6, 0x67F0($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X67F0);
    // 0x8008E614: lw          $v0, 0x60($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X60);
    // 0x8008E618: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x8008E61C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E620: and         $t8, $t7, $v0
    ctx->r24 = ctx->r15 & ctx->r2;
    // 0x8008E624: sw          $t8, 0x67D8($at)
    MEM_W(0X67D8, ctx->r1) = ctx->r24;
    // 0x8008E628: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E62C: sw          $v0, 0x67F0($at)
    MEM_W(0X67F0, ctx->r1) = ctx->r2;
    // 0x8008E630: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008E634: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008E638: addiu       $t1, $t1, 0x67F0
    ctx->r9 = ADD32(ctx->r9, 0X67F0);
    // 0x8008E63C: sll         $a0, $s3, 2
    ctx->r4 = S32(ctx->r19 << 2);
    // 0x8008E640: addu        $v0, $a0, $t1
    ctx->r2 = ADD32(ctx->r4, ctx->r9);
    // 0x8008E644: lw          $t3, 0x0($v0)
    ctx->r11 = MEM_W(ctx->r2, 0X0);
    // 0x8008E648: addiu       $t2, $sp, 0x60
    ctx->r10 = ADD32(ctx->r29, 0X60);
    // 0x8008E64C: addu        $s0, $a0, $t2
    ctx->r16 = ADD32(ctx->r4, ctx->r10);
    // 0x8008E650: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8008E654: lw          $a1, 0x0($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X0);
    // 0x8008E658: addiu       $t9, $t9, 0x67D8
    ctx->r25 = ADD32(ctx->r25, 0X67D8);
    // 0x8008E65C: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8008E660: addu        $v1, $a0, $t9
    ctx->r3 = ADD32(ctx->r4, ctx->r25);
    // 0x8008E664: lw          $t9, 0x8($v0)
    ctx->r25 = MEM_W(ctx->r2, 0X8);
    // 0x8008E668: lw          $t3, 0xC($v0)
    ctx->r11 = MEM_W(ctx->r2, 0XC);
    // 0x8008E66C: lw          $t6, 0x4($v0)
    ctx->r14 = MEM_W(ctx->r2, 0X4);
    // 0x8008E670: and         $t5, $t4, $a1
    ctx->r13 = ctx->r12 & ctx->r5;
    // 0x8008E674: lw          $a2, 0x4($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X4);
    // 0x8008E678: lw          $a3, 0x8($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X8);
    // 0x8008E67C: lw          $t0, 0xC($s0)
    ctx->r8 = MEM_W(ctx->r16, 0XC);
    // 0x8008E680: sw          $t5, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r13;
    // 0x8008E684: nor         $t1, $t9, $zero
    ctx->r9 = ~(ctx->r25 | 0);
    // 0x8008E688: nor         $t4, $t3, $zero
    ctx->r12 = ~(ctx->r11 | 0);
    // 0x8008E68C: nor         $t7, $t6, $zero
    ctx->r15 = ~(ctx->r14 | 0);
    // 0x8008E690: and         $t8, $t7, $a2
    ctx->r24 = ctx->r15 & ctx->r6;
    // 0x8008E694: and         $t2, $t1, $a3
    ctx->r10 = ctx->r9 & ctx->r7;
    // 0x8008E698: and         $t5, $t4, $t0
    ctx->r13 = ctx->r12 & ctx->r8;
    // 0x8008E69C: sw          $t5, 0xC($v1)
    MEM_W(0XC, ctx->r3) = ctx->r13;
    // 0x8008E6A0: sw          $t2, 0x8($v1)
    MEM_W(0X8, ctx->r3) = ctx->r10;
    // 0x8008E6A4: sw          $t8, 0x4($v1)
    MEM_W(0X4, ctx->r3) = ctx->r24;
    // 0x8008E6A8: sw          $a1, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r5;
    // 0x8008E6AC: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8008E6B0: sw          $a3, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r7;
    // 0x8008E6B4: b           L_8008E760
    // 0x8008E6B8: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
        goto L_8008E760;
    // 0x8008E6B8: sw          $t0, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r8;
L_8008E6BC:
    // 0x8008E6BC: ori         $t6, $zero, 0xD000
    ctx->r14 = 0 | 0XD000;
    // 0x8008E6C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E6C4: sw          $t6, 0x67F0($at)
    MEM_W(0X67F0, ctx->r1) = ctx->r14;
    // 0x8008E6C8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E6CC: sw          $zero, 0x67D8($at)
    MEM_W(0X67D8, ctx->r1) = 0;
    // 0x8008E6D0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E6D4: sh          $zero, 0x6818($at)
    MEM_H(0X6818, ctx->r1) = 0;
    // 0x8008E6D8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008E6DC: sh          $zero, 0x6830($at)
    MEM_H(0X6830, ctx->r1) = 0;
    // 0x8008E6E0: addiu       $s3, $zero, 0x1
    ctx->r19 = ADD32(0, 0X1);
    // 0x8008E6E4: lui         $s6, 0x8012
    ctx->r22 = S32(0X8012 << 16);
    // 0x8008E6E8: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8008E6EC: sll         $a0, $s3, 2
    ctx->r4 = S32(ctx->r19 << 2);
    // 0x8008E6F0: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8008E6F4: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8008E6F8: sll         $a1, $s3, 1
    ctx->r5 = S32(ctx->r19 << 1);
    // 0x8008E6FC: addiu       $s7, $s7, 0x6830
    ctx->r23 = ADD32(ctx->r23, 0X6830);
    // 0x8008E700: addiu       $s6, $s6, 0x6818
    ctx->r22 = ADD32(ctx->r22, 0X6818);
    // 0x8008E704: addiu       $t7, $t7, 0x67F0
    ctx->r15 = ADD32(ctx->r15, 0X67F0);
    // 0x8008E708: addiu       $t8, $t8, 0x67D8
    ctx->r24 = ADD32(ctx->r24, 0X67D8);
    // 0x8008E70C: ori         $a2, $zero, 0xD000
    ctx->r6 = 0 | 0XD000;
    // 0x8008E710: addu        $v0, $a0, $t7
    ctx->r2 = ADD32(ctx->r4, ctx->r15);
    // 0x8008E714: addu        $v1, $a0, $t8
    ctx->r3 = ADD32(ctx->r4, ctx->r24);
    // 0x8008E718: addu        $s2, $s6, $a1
    ctx->r18 = ADD32(ctx->r22, ctx->r5);
    // 0x8008E71C: addu        $s1, $s7, $a1
    ctx->r17 = ADD32(ctx->r23, ctx->r5);
    // 0x8008E720: sh          $zero, 0x2($s1)
    MEM_H(0X2, ctx->r17) = 0;
    // 0x8008E724: sh          $zero, 0x4($s1)
    MEM_H(0X4, ctx->r17) = 0;
    // 0x8008E728: sh          $zero, 0x6($s1)
    MEM_H(0X6, ctx->r17) = 0;
    // 0x8008E72C: sh          $zero, 0x2($s2)
    MEM_H(0X2, ctx->r18) = 0;
    // 0x8008E730: sh          $zero, 0x4($s2)
    MEM_H(0X4, ctx->r18) = 0;
    // 0x8008E734: sh          $zero, 0x6($s2)
    MEM_H(0X6, ctx->r18) = 0;
    // 0x8008E738: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x8008E73C: sw          $zero, 0x8($v1)
    MEM_W(0X8, ctx->r3) = 0;
    // 0x8008E740: sw          $zero, 0xC($v1)
    MEM_W(0XC, ctx->r3) = 0;
    // 0x8008E744: sw          $a2, 0x4($v0)
    MEM_W(0X4, ctx->r2) = ctx->r6;
    // 0x8008E748: sw          $a2, 0x8($v0)
    MEM_W(0X8, ctx->r2) = ctx->r6;
    // 0x8008E74C: sw          $a2, 0xC($v0)
    MEM_W(0XC, ctx->r2) = ctx->r6;
    // 0x8008E750: sw          $a2, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r6;
    // 0x8008E754: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x8008E758: sh          $zero, 0x0($s2)
    MEM_H(0X0, ctx->r18) = 0;
    // 0x8008E75C: sh          $zero, 0x0($s1)
    MEM_H(0X0, ctx->r17) = 0;
L_8008E760:
    // 0x8008E760: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8008E764: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8008E768: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8008E76C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8008E770: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8008E774: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8008E778: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8008E77C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8008E780: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8008E784: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8008E788: jr          $ra
    // 0x8008E78C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
    return;
    // 0x8008E78C: addiu       $sp, $sp, 0x78
    ctx->r29 = ADD32(ctx->r29, 0X78);
;}
RECOMP_FUNC void gzip_inflate_dynamic(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800C69C4: addiu       $sp, $sp, -0x540
    ctx->r29 = ADD32(ctx->r29, -0X540);
    // 0x800C69C8: sw          $s3, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r19;
    // 0x800C69CC: lui         $s3, 0x8013
    ctx->r19 = S32(0X8013 << 16);
    // 0x800C69D0: lw          $s3, -0x552C($s3)
    ctx->r19 = MEM_W(ctx->r19, -0X552C);
    // 0x800C69D4: sw          $s4, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r20;
    // 0x800C69D8: sw          $s2, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r18;
    // 0x800C69DC: addiu       $t0, $zero, 0x5
    ctx->r8 = ADD32(0, 0X5);
    // 0x800C69E0: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x800C69E4: lui         $s2, 0x8013
    ctx->r18 = S32(0X8013 << 16);
    // 0x800C69E8: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C69EC: sw          $ra, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r31;
    // 0x800C69F0: sw          $s1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r17;
    // 0x800C69F4: sw          $s0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r16;
    // 0x800C69F8: lw          $s4, 0x3768($s4)
    ctx->r20 = MEM_W(ctx->r20, 0X3768);
    // 0x800C69FC: beq         $at, $zero, L_800C6A20
    if (ctx->r1 == 0) {
        // 0x800C6A00: lw          $s2, -0x5530($s2)
        ctx->r18 = MEM_W(ctx->r18, -0X5530);
            goto L_800C6A20;
    }
    // 0x800C6A00: lw          $s2, -0x5530($s2)
    ctx->r18 = MEM_W(ctx->r18, -0X5530);
L_800C6A04:
    // 0x800C6A04: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6A08: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6A0C: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6A10: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6A14: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6A18: bne         $at, $zero, L_800C6A04
    if (ctx->r1 != 0) {
        // 0x800C6A1C: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6A04;
    }
    // 0x800C6A1C: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_800C6A20:
    // 0x800C6A20: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6A24: andi        $s1, $s2, 0x1F
    ctx->r17 = ctx->r18 & 0X1F;
    // 0x800C6A28: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6A2C: addiu       $s1, $s1, 0x101
    ctx->r17 = ADD32(ctx->r17, 0X101);
    // 0x800C6A30: beq         $at, $zero, L_800C6A54
    if (ctx->r1 == 0) {
        // 0x800C6A34: srlv        $s2, $s2, $t0
        ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
            goto L_800C6A54;
    }
    // 0x800C6A34: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
L_800C6A38:
    // 0x800C6A38: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6A3C: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6A40: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6A44: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6A48: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6A4C: bne         $at, $zero, L_800C6A38
    if (ctx->r1 != 0) {
        // 0x800C6A50: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6A38;
    }
    // 0x800C6A50: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_800C6A54:
    // 0x800C6A54: andi        $s0, $s2, 0x1F
    ctx->r16 = ctx->r18 & 0X1F;
    // 0x800C6A58: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C6A5C: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6A60: addiu       $t0, $zero, 0x4
    ctx->r8 = ADD32(0, 0X4);
    // 0x800C6A64: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6A68: beq         $at, $zero, L_800C6A8C
    if (ctx->r1 == 0) {
        // 0x800C6A6C: addiu       $s0, $s0, 0x1
        ctx->r16 = ADD32(ctx->r16, 0X1);
            goto L_800C6A8C;
    }
    // 0x800C6A6C: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
L_800C6A70:
    // 0x800C6A70: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6A74: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6A78: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6A7C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6A80: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6A84: bne         $at, $zero, L_800C6A70
    if (ctx->r1 != 0) {
        // 0x800C6A88: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6A70;
    }
    // 0x800C6A88: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
L_800C6A8C:
    // 0x800C6A8C: andi        $t2, $s2, 0xF
    ctx->r10 = ctx->r18 & 0XF;
    // 0x800C6A90: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x800C6A94: lui         $t9, 0x800F
    ctx->r25 = S32(0X800F << 16);
    // 0x800C6A98: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C6A9C: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6AA0: or          $t1, $zero, $t2
    ctx->r9 = 0 | ctx->r10;
    // 0x800C6AA4: addiu       $t9, $t9, -0x6C40
    ctx->r25 = ADD32(ctx->r25, -0X6C40);
    // 0x800C6AA8: beq         $t2, $zero, L_800C6B10
    if (ctx->r10 == 0) {
        // 0x800C6AAC: addi        $t7, $sp, 0x44
        ctx->r15 = ADD32(ctx->r29, 0X44);
            goto L_800C6B10;
    }
    // 0x800C6AAC: addi        $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
L_800C6AB0:
    // 0x800C6AB0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    // 0x800C6AB4: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6AB8: beql        $at, $zero, L_800C6AE0
    if (ctx->r1 == 0) {
        // 0x800C6ABC: lbu         $v1, 0x0($t9)
        ctx->r3 = MEM_BU(ctx->r25, 0X0);
            goto L_800C6AE0;
    }
    goto skip_0;
    // 0x800C6ABC: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    skip_0:
L_800C6AC0:
    // 0x800C6AC0: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6AC4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6AC8: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6ACC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6AD0: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6AD4: bne         $at, $zero, L_800C6AC0
    if (ctx->r1 != 0) {
        // 0x800C6AD8: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6AC0;
    }
    // 0x800C6AD8: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C6ADC: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
L_800C6AE0:
    // 0x800C6AE0: andi        $v0, $s2, 0x7
    ctx->r2 = ctx->r18 & 0X7;
    // 0x800C6AE4: addiu       $t2, $t2, -0x1
    ctx->r10 = ADD32(ctx->r10, -0X1);
    // 0x800C6AE8: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C6AEC: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800C6AF0: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x800C6AF4: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C6AF8: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6AFC: bne         $t2, $zero, L_800C6AB0
    if (ctx->r10 != 0) {
        // 0x800C6B00: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_800C6AB0;
    }
    // 0x800C6B00: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800C6B04: sltiu       $at, $t1, 0x13
    ctx->r1 = ctx->r9 < 0X13 ? 1 : 0;
    // 0x800C6B08: beql        $at, $zero, L_800C6B34
    if (ctx->r1 == 0) {
        // 0x800C6B0C: addiu       $t5, $zero, 0x7
        ctx->r13 = ADD32(0, 0X7);
            goto L_800C6B34;
    }
    goto skip_1;
    // 0x800C6B0C: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
    skip_1:
L_800C6B10:
    // 0x800C6B10: lbu         $v1, 0x0($t9)
    ctx->r3 = MEM_BU(ctx->r25, 0X0);
    // 0x800C6B14: addiu       $t1, $t1, 0x1
    ctx->r9 = ADD32(ctx->r9, 0X1);
    // 0x800C6B18: slti        $at, $t1, 0x13
    ctx->r1 = SIGNED(ctx->r9) < 0X13 ? 1 : 0;
    // 0x800C6B1C: sll         $v1, $v1, 2
    ctx->r3 = S32(ctx->r3 << 2);
    // 0x800C6B20: addu        $v1, $v1, $t7
    ctx->r3 = ADD32(ctx->r3, ctx->r15);
    // 0x800C6B24: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
    // 0x800C6B28: bne         $at, $zero, L_800C6B10
    if (ctx->r1 != 0) {
        // 0x800C6B2C: addiu       $t9, $t9, 0x1
        ctx->r25 = ADD32(ctx->r25, 0X1);
            goto L_800C6B10;
    }
    // 0x800C6B2C: addiu       $t9, $t9, 0x1
    ctx->r25 = ADD32(ctx->r25, 0X1);
    // 0x800C6B30: addiu       $t5, $zero, 0x7
    ctx->r13 = ADD32(0, 0X7);
L_800C6B34:
    // 0x800C6B34: addi        $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800C6B38: addi        $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800C6B3C: sw          $t5, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r13;
    // 0x800C6B40: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C6B44: addiu       $a1, $zero, 0x13
    ctx->r5 = ADD32(0, 0X13);
    // 0x800C6B48: addiu       $a2, $zero, 0x13
    ctx->r6 = ADD32(0, 0X13);
    // 0x800C6B4C: addiu       $a3, $zero, 0x0
    ctx->r7 = ADD32(0, 0X0);
    // 0x800C6B50: sw          $zero, 0x10($sp)
    MEM_W(0X10, ctx->r29) = 0;
    // 0x800C6B54: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    // 0x800C6B58: jal         0x800C6274
    // 0x800C6B5C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    gzip_huft_build(rdram, ctx);
        goto after_0;
    // 0x800C6B5C: sw          $t1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r9;
    after_0:
    // 0x800C6B60: addi        $t1, $sp, 0x38
    ctx->r9 = ADD32(ctx->r29, 0X38);
    // 0x800C6B64: lw          $t5, 0x0($t1)
    ctx->r13 = MEM_W(ctx->r9, 0X0);
    // 0x800C6B68: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C6B6C: addiu       $v0, $v0, -0x6B74
    ctx->r2 = ADD32(ctx->r2, -0X6B74);
    // 0x800C6B70: sll         $v1, $t5, 1
    ctx->r3 = S32(ctx->r13 << 1);
    // 0x800C6B74: addi        $t0, $sp, 0x34
    ctx->r8 = ADD32(ctx->r29, 0X34);
    // 0x800C6B78: add         $v0, $v0, $v1
    ctx->r2 = ADD32(ctx->r2, ctx->r3);
    // 0x800C6B7C: lw          $t6, 0x0($t0)
    ctx->r14 = MEM_W(ctx->r8, 0X0);
    // 0x800C6B80: add         $t9, $s1, $s0
    ctx->r25 = ADD32(ctx->r17, ctx->r16);
    // 0x800C6B84: lh          $t8, 0x0($v0)
    ctx->r24 = MEM_H(ctx->r2, 0X0);
    // 0x800C6B88: addi        $t7, $sp, 0x44
    ctx->r15 = ADD32(ctx->r29, 0X44);
    // 0x800C6B8C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_800C6B90:
    // 0x800C6B90: beq         $t9, $zero, L_800C6D10
    if (ctx->r25 == 0) {
        // 0x800C6B94: sltu        $at, $s3, $t5
        ctx->r1 = ctx->r19 < ctx->r13 ? 1 : 0;
            goto L_800C6D10;
    }
    // 0x800C6B94: sltu        $at, $s3, $t5
    ctx->r1 = ctx->r19 < ctx->r13 ? 1 : 0;
    // 0x800C6B98: beql        $at, $zero, L_800C6BC0
    if (ctx->r1 == 0) {
        // 0x800C6B9C: and         $v0, $s2, $t8
        ctx->r2 = ctx->r18 & ctx->r24;
            goto L_800C6BC0;
    }
    goto skip_2;
    // 0x800C6B9C: and         $v0, $s2, $t8
    ctx->r2 = ctx->r18 & ctx->r24;
    skip_2:
L_800C6BA0:
    // 0x800C6BA0: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6BA4: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6BA8: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6BAC: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6BB0: slt         $at, $s3, $t5
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r13) ? 1 : 0;
    // 0x800C6BB4: bne         $at, $zero, L_800C6BA0
    if (ctx->r1 != 0) {
        // 0x800C6BB8: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6BA0;
    }
    // 0x800C6BB8: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C6BBC: and         $v0, $s2, $t8
    ctx->r2 = ctx->r18 & ctx->r24;
L_800C6BC0:
    // 0x800C6BC0: sll         $v0, $v0, 3
    ctx->r2 = S32(ctx->r2 << 3);
    // 0x800C6BC4: addu        $t1, $t6, $v0
    ctx->r9 = ADD32(ctx->r14, ctx->r2);
    // 0x800C6BC8: lhu         $t0, 0x4($t1)
    ctx->r8 = MEM_HU(ctx->r9, 0X4);
    // 0x800C6BCC: lbu         $v0, 0x1($t1)
    ctx->r2 = MEM_BU(ctx->r9, 0X1);
    // 0x800C6BD0: slti        $at, $t0, 0x10
    ctx->r1 = SIGNED(ctx->r8) < 0X10 ? 1 : 0;
    // 0x800C6BD4: srlv        $s2, $s2, $v0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r2 & 31));
    // 0x800C6BD8: bne         $at, $zero, L_800C6C4C
    if (ctx->r1 != 0) {
        // 0x800C6BDC: sub         $s3, $s3, $v0
        ctx->r19 = SUB32(ctx->r19, ctx->r2);
            goto L_800C6C4C;
    }
    // 0x800C6BDC: sub         $s3, $s3, $v0
    ctx->r19 = SUB32(ctx->r19, ctx->r2);
    // 0x800C6BE0: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800C6BE4: beq         $t0, $at, L_800C6C60
    if (ctx->r8 == ctx->r1) {
        // 0x800C6BE8: addiu       $at, $zero, 0x11
        ctx->r1 = ADD32(0, 0X11);
            goto L_800C6C60;
    }
    // 0x800C6BE8: addiu       $at, $zero, 0x11
    ctx->r1 = ADD32(0, 0X11);
    // 0x800C6BEC: beql        $t0, $at, L_800C6CBC
    if (ctx->r8 == ctx->r1) {
        // 0x800C6BF0: addiu       $t0, $zero, 0x3
        ctx->r8 = ADD32(0, 0X3);
            goto L_800C6CBC;
    }
    goto skip_3;
    // 0x800C6BF0: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
    skip_3:
    // 0x800C6BF4: addiu       $t0, $zero, 0x7
    ctx->r8 = ADD32(0, 0X7);
    // 0x800C6BF8: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6BFC: beql        $at, $zero, L_800C6C24
    if (ctx->r1 == 0) {
        // 0x800C6C00: andi        $t1, $s2, 0x7F
        ctx->r9 = ctx->r18 & 0X7F;
            goto L_800C6C24;
    }
    goto skip_4;
    // 0x800C6C00: andi        $t1, $s2, 0x7F
    ctx->r9 = ctx->r18 & 0X7F;
    skip_4:
L_800C6C04:
    // 0x800C6C04: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6C08: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6C0C: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6C10: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6C14: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6C18: bne         $at, $zero, L_800C6C04
    if (ctx->r1 != 0) {
        // 0x800C6C1C: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6C04;
    }
    // 0x800C6C1C: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C6C20: andi        $t1, $s2, 0x7F
    ctx->r9 = ctx->r18 & 0X7F;
L_800C6C24:
    // 0x800C6C24: addiu       $t1, $t1, 0xB
    ctx->r9 = ADD32(ctx->r9, 0XB);
    // 0x800C6C28: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C6C2C: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6C30: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_800C6C34:
    // 0x800C6C34: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C6C38: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800C6C3C: bne         $t1, $zero, L_800C6C34
    if (ctx->r9 != 0) {
        // 0x800C6C40: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_800C6C34;
    }
    // 0x800C6C40: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C6C44: j           L_800C6B90
    // 0x800C6C48: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
        goto L_800C6B90;
    // 0x800C6C48: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_800C6C4C:
    // 0x800C6C4C: sw          $t0, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r8;
    // 0x800C6C50: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C6C54: addiu       $t9, $t9, -0x1
    ctx->r25 = ADD32(ctx->r25, -0X1);
    // 0x800C6C58: j           L_800C6B90
    // 0x800C6C5C: or          $t2, $zero, $t0
    ctx->r10 = 0 | ctx->r8;
        goto L_800C6B90;
    // 0x800C6C5C: or          $t2, $zero, $t0
    ctx->r10 = 0 | ctx->r8;
L_800C6C60:
    // 0x800C6C60: addiu       $t0, $zero, 0x2
    ctx->r8 = ADD32(0, 0X2);
    // 0x800C6C64: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6C68: beql        $at, $zero, L_800C6C90
    if (ctx->r1 == 0) {
        // 0x800C6C6C: andi        $t1, $s2, 0x3
        ctx->r9 = ctx->r18 & 0X3;
            goto L_800C6C90;
    }
    goto skip_5;
    // 0x800C6C6C: andi        $t1, $s2, 0x3
    ctx->r9 = ctx->r18 & 0X3;
    skip_5:
L_800C6C70:
    // 0x800C6C70: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6C74: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6C78: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6C7C: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6C80: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6C84: bne         $at, $zero, L_800C6C70
    if (ctx->r1 != 0) {
        // 0x800C6C88: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6C70;
    }
    // 0x800C6C88: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C6C8C: andi        $t1, $s2, 0x3
    ctx->r9 = ctx->r18 & 0X3;
L_800C6C90:
    // 0x800C6C90: addi        $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x800C6C94: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C6C98: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6C9C: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_800C6CA0:
    // 0x800C6CA0: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C6CA4: sw          $t2, 0x0($t7)
    MEM_W(0X0, ctx->r15) = ctx->r10;
    // 0x800C6CA8: bne         $t1, $zero, L_800C6CA0
    if (ctx->r9 != 0) {
        // 0x800C6CAC: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_800C6CA0;
    }
    // 0x800C6CAC: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C6CB0: j           L_800C6B90
    // 0x800C6CB4: nop

        goto L_800C6B90;
    // 0x800C6CB4: nop

    // 0x800C6CB8: addiu       $t0, $zero, 0x3
    ctx->r8 = ADD32(0, 0X3);
L_800C6CBC:
    // 0x800C6CBC: sltu        $at, $s3, $t0
    ctx->r1 = ctx->r19 < ctx->r8 ? 1 : 0;
    // 0x800C6CC0: beql        $at, $zero, L_800C6CE8
    if (ctx->r1 == 0) {
        // 0x800C6CC4: andi        $t1, $s2, 0x7
        ctx->r9 = ctx->r18 & 0X7;
            goto L_800C6CE8;
    }
    goto skip_6;
    // 0x800C6CC4: andi        $t1, $s2, 0x7
    ctx->r9 = ctx->r18 & 0X7;
    skip_6:
L_800C6CC8:
    // 0x800C6CC8: lbu         $v0, 0x0($s4)
    ctx->r2 = MEM_BU(ctx->r20, 0X0);
    // 0x800C6CCC: addiu       $s4, $s4, 0x1
    ctx->r20 = ADD32(ctx->r20, 0X1);
    // 0x800C6CD0: sllv        $v0, $v0, $s3
    ctx->r2 = S32(ctx->r2 << (ctx->r19 & 31));
    // 0x800C6CD4: addiu       $s3, $s3, 0x8
    ctx->r19 = ADD32(ctx->r19, 0X8);
    // 0x800C6CD8: slt         $at, $s3, $t0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x800C6CDC: bne         $at, $zero, L_800C6CC8
    if (ctx->r1 != 0) {
        // 0x800C6CE0: or          $s2, $s2, $v0
        ctx->r18 = ctx->r18 | ctx->r2;
            goto L_800C6CC8;
    }
    // 0x800C6CE0: or          $s2, $s2, $v0
    ctx->r18 = ctx->r18 | ctx->r2;
    // 0x800C6CE4: andi        $t1, $s2, 0x7
    ctx->r9 = ctx->r18 & 0X7;
L_800C6CE8:
    // 0x800C6CE8: addi        $t1, $t1, 0x3
    ctx->r9 = ADD32(ctx->r9, 0X3);
    // 0x800C6CEC: srlv        $s2, $s2, $t0
    ctx->r18 = S32(U32(ctx->r18) >> (ctx->r8 & 31));
    // 0x800C6CF0: sub         $s3, $s3, $t0
    ctx->r19 = SUB32(ctx->r19, ctx->r8);
    // 0x800C6CF4: subu        $t9, $t9, $t1
    ctx->r25 = SUB32(ctx->r25, ctx->r9);
L_800C6CF8:
    // 0x800C6CF8: addiu       $t1, $t1, -0x1
    ctx->r9 = ADD32(ctx->r9, -0X1);
    // 0x800C6CFC: sw          $zero, 0x0($t7)
    MEM_W(0X0, ctx->r15) = 0;
    // 0x800C6D00: bne         $t1, $zero, L_800C6CF8
    if (ctx->r9 != 0) {
        // 0x800C6D04: addiu       $t7, $t7, 0x4
        ctx->r15 = ADD32(ctx->r15, 0X4);
            goto L_800C6CF8;
    }
    // 0x800C6D04: addiu       $t7, $t7, 0x4
    ctx->r15 = ADD32(ctx->r15, 0X4);
    // 0x800C6D08: j           L_800C6B90
    // 0x800C6D0C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
        goto L_800C6B90;
    // 0x800C6D0C: addiu       $t2, $zero, 0x0
    ctx->r10 = ADD32(0, 0X0);
L_800C6D10:
    // 0x800C6D10: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800C6D14: sw          $s4, 0x3768($at)
    MEM_W(0X3768, ctx->r1) = ctx->r20;
    // 0x800C6D18: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6D1C: addiu       $t0, $zero, 0x9
    ctx->r8 = ADD32(0, 0X9);
    // 0x800C6D20: sw          $s2, -0x5530($at)
    MEM_W(-0X5530, ctx->r1) = ctx->r18;
    // 0x800C6D24: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    // 0x800C6D28: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C6D2C: lui         $at, 0x8013
    ctx->r1 = S32(0X8013 << 16);
    // 0x800C6D30: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C6D34: addiu       $v0, $v0, -0x6BEE
    ctx->r2 = ADD32(ctx->r2, -0X6BEE);
    // 0x800C6D38: addi        $v1, $sp, 0x34
    ctx->r3 = ADD32(ctx->r29, 0X34);
    // 0x800C6D3C: addi        $t0, $sp, 0x38
    ctx->r8 = ADD32(ctx->r29, 0X38);
    // 0x800C6D40: sw          $s3, -0x552C($at)
    MEM_W(-0X552C, ctx->r1) = ctx->r19;
    // 0x800C6D44: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C6D48: or          $a1, $zero, $s1
    ctx->r5 = 0 | ctx->r17;
    // 0x800C6D4C: addiu       $a2, $zero, 0x101
    ctx->r6 = ADD32(0, 0X101);
    // 0x800C6D50: addiu       $a3, $a3, -0x6C2C
    ctx->r7 = ADD32(ctx->r7, -0X6C2C);
    // 0x800C6D54: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C6D58: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C6D5C: jal         0x800C6274
    // 0x800C6D60: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_1;
    // 0x800C6D60: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_1:
    // 0x800C6D64: addi        $a0, $sp, 0x44
    ctx->r4 = ADD32(ctx->r29, 0X44);
    // 0x800C6D68: sll         $v0, $s1, 2
    ctx->r2 = S32(ctx->r17 << 2);
    // 0x800C6D6C: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x800C6D70: addu        $a0, $a0, $v0
    ctx->r4 = ADD32(ctx->r4, ctx->r2);
    // 0x800C6D74: sw          $t0, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r8;
    // 0x800C6D78: lui         $v0, 0x800F
    ctx->r2 = S32(0X800F << 16);
    // 0x800C6D7C: lui         $a3, 0x800F
    ctx->r7 = S32(0X800F << 16);
    // 0x800C6D80: addiu       $v0, $v0, -0x6B92
    ctx->r2 = ADD32(ctx->r2, -0X6B92);
    // 0x800C6D84: addi        $v1, $sp, 0x3C
    ctx->r3 = ADD32(ctx->r29, 0X3C);
    // 0x800C6D88: addi        $t0, $sp, 0x40
    ctx->r8 = ADD32(ctx->r29, 0X40);
    // 0x800C6D8C: or          $a1, $zero, $s0
    ctx->r5 = 0 | ctx->r16;
    // 0x800C6D90: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800C6D94: addiu       $a3, $a3, -0x6BCE
    ctx->r7 = ADD32(ctx->r7, -0X6BCE);
    // 0x800C6D98: sw          $v0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r2;
    // 0x800C6D9C: sw          $v1, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r3;
    // 0x800C6DA0: jal         0x800C6274
    // 0x800C6DA4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    gzip_huft_build(rdram, ctx);
        goto after_2;
    // 0x800C6DA4: sw          $t0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r8;
    after_2:
    // 0x800C6DA8: lw          $a0, 0x34($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X34);
    // 0x800C6DAC: lw          $a1, 0x3C($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X3C);
    // 0x800C6DB0: lw          $a2, 0x38($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X38);
    // 0x800C6DB4: jal         0x800C7040
    // 0x800C6DB8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    gzip_inflate_codes(rdram, ctx);
        goto after_3;
    // 0x800C6DB8: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    after_3:
    // 0x800C6DBC: lw          $ra, 0x30($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X30);
    // 0x800C6DC0: lw          $s4, 0x2C($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X2C);
    // 0x800C6DC4: lw          $s3, 0x28($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X28);
    // 0x800C6DC8: lw          $s2, 0x24($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X24);
    // 0x800C6DCC: lw          $s1, 0x20($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X20);
    // 0x800C6DD0: lw          $s0, 0x1C($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X1C);
    // 0x800C6DD4: jr          $ra
    // 0x800C6DD8: addiu       $sp, $sp, 0x540
    ctx->r29 = ADD32(ctx->r29, 0X540);
    return;
    // 0x800C6DD8: addiu       $sp, $sp, 0x540
    ctx->r29 = ADD32(ctx->r29, 0X540);
;}
RECOMP_FUNC void caution_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008C4E8: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x8008C4EC: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008C4F0: jal         0x800C422C
    // 0x8008C4F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x8008C4F4: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x8008C4F8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8008C4FC: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008C500: jr          $ra
    // 0x8008C504: nop

    return;
    // 0x8008C504: nop

;}
RECOMP_FUNC void save_rng_seed(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006F918: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8006F91C: lw          $a0, -0x2BCC($a0)
    ctx->r4 = MEM_W(ctx->r4, -0X2BCC);
    // 0x8006F920: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8006F924: jr          $ra
    // 0x8006F928: sw          $a0, -0x2BC8($at)
    MEM_W(-0X2BC8, ctx->r1) = ctx->r4;
    return;
    // 0x8006F928: sw          $a0, -0x2BC8($at)
    MEM_W(-0X2BC8, ctx->r1) = ctx->r4;
;}
RECOMP_FUNC void setup_particle_velocity(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800B0010: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800B0014: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x800B0018: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x800B001C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x800B0020: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    // 0x800B0024: sw          $a2, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r6;
    // 0x800B0028: lw          $t6, 0x0($a3)
    ctx->r14 = MEM_W(ctx->r7, 0X0);
    // 0x800B002C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x800B0030: andi        $t7, $t6, 0x70
    ctx->r15 = ctx->r14 & 0X70;
    // 0x800B0034: beq         $t7, $zero, L_800B0060
    if (ctx->r15 == 0) {
        // 0x800B0038: or          $s1, $a3, $zero
        ctx->r17 = ctx->r7 | 0;
            goto L_800B0060;
    }
    // 0x800B0038: or          $s1, $a3, $zero
    ctx->r17 = ctx->r7 | 0;
    // 0x800B003C: lwc1        $f4, 0x30($a3)
    ctx->f4.u32l = MEM_W(ctx->r7, 0X30);
    // 0x800B0040: nop

    // 0x800B0044: swc1        $f4, 0x1C($a0)
    MEM_W(0X1C, ctx->r4) = ctx->f4.u32l;
    // 0x800B0048: lwc1        $f6, 0x34($a3)
    ctx->f6.u32l = MEM_W(ctx->r7, 0X34);
    // 0x800B004C: nop

    // 0x800B0050: swc1        $f6, 0x20($a0)
    MEM_W(0X20, ctx->r4) = ctx->f6.u32l;
    // 0x800B0054: lwc1        $f8, 0x38($a3)
    ctx->f8.u32l = MEM_W(ctx->r7, 0X38);
    // 0x800B0058: b           L_800B0078
    // 0x800B005C: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
        goto L_800B0078;
    // 0x800B005C: swc1        $f8, 0x24($a0)
    MEM_W(0X24, ctx->r4) = ctx->f8.u32l;
L_800B0060:
    // 0x800B0060: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x800B0064: mtc1        $zero, $f16
    ctx->f16.u32l = 0;
    // 0x800B0068: mtc1        $zero, $f18
    ctx->f18.u32l = 0;
    // 0x800B006C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800B0070: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x800B0074: swc1        $f18, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f18.u32l;
L_800B0078:
    // 0x800B0078: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B007C: nop

    // 0x800B0080: andi        $t8, $v1, 0x700
    ctx->r24 = ctx->r3 & 0X700;
    // 0x800B0084: beq         $t8, $zero, L_800B0178
    if (ctx->r24 == 0) {
        // 0x800B0088: or          $v1, $t8, $zero
        ctx->r3 = ctx->r24 | 0;
            goto L_800B0178;
    }
    // 0x800B0088: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
    // 0x800B008C: andi        $t9, $t8, 0x100
    ctx->r25 = ctx->r24 & 0X100;
    // 0x800B0090: beq         $t9, $zero, L_800B00E0
    if (ctx->r25 == 0) {
        // 0x800B0094: andi        $t0, $v1, 0x200
        ctx->r8 = ctx->r3 & 0X200;
            goto L_800B00E0;
    }
    // 0x800B0094: andi        $t0, $v1, 0x200
    ctx->r8 = ctx->r3 & 0X200;
    // 0x800B0098: lw          $a1, 0x74($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X74);
    // 0x800B009C: sw          $t8, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r24;
    // 0x800B00A0: jal         0x8006F94C
    // 0x800B00A4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_0;
    // 0x800B00A4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_0:
    // 0x800B00A8: mtc1        $v0, $f4
    ctx->f4.u32l = ctx->r2;
    // 0x800B00AC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B00B0: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800B00B4: lwc1        $f11, -0x7468($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X7468);
    // 0x800B00B8: lwc1        $f10, -0x7464($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X7464);
    // 0x800B00BC: cvt.d.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f8.d = CVT_D_S(ctx->f6.fl);
    // 0x800B00C0: mul.d       $f16, $f8, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f16.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B00C4: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B00C8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B00CC: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B00D0: add.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = ctx->f4.d + ctx->f16.d;
    // 0x800B00D4: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800B00D8: swc1        $f8, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f8.u32l;
    // 0x800B00DC: andi        $t0, $v1, 0x200
    ctx->r8 = ctx->r3 & 0X200;
L_800B00E0:
    // 0x800B00E0: beq         $t0, $zero, L_800B0130
    if (ctx->r8 == 0) {
        // 0x800B00E4: andi        $t1, $v1, 0x400
        ctx->r9 = ctx->r3 & 0X400;
            goto L_800B0130;
    }
    // 0x800B00E4: andi        $t1, $v1, 0x400
    ctx->r9 = ctx->r3 & 0X400;
    // 0x800B00E8: lw          $a1, 0x78($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X78);
    // 0x800B00EC: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B00F0: jal         0x8006F94C
    // 0x800B00F4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_1;
    // 0x800B00F4: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_1:
    // 0x800B00F8: mtc1        $v0, $f10
    ctx->f10.u32l = ctx->r2;
    // 0x800B00FC: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B0100: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800B0104: lwc1        $f17, -0x7460($at)
    ctx->f_odd[(17 - 1) * 2] = MEM_W(ctx->r1, -0X7460);
    // 0x800B0108: lwc1        $f16, -0x745C($at)
    ctx->f16.u32l = MEM_W(ctx->r1, -0X745C);
    // 0x800B010C: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800B0110: mul.d       $f6, $f4, $f16
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f16.d); 
    ctx->f6.d = MUL_D(ctx->f4.d, ctx->f16.d);
    // 0x800B0114: lwc1        $f8, 0x20($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B0118: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B011C: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B0120: add.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f10.d + ctx->f6.d;
    // 0x800B0124: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800B0128: swc1        $f4, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f4.u32l;
    // 0x800B012C: andi        $t1, $v1, 0x400
    ctx->r9 = ctx->r3 & 0X400;
L_800B0130:
    // 0x800B0130: beq         $t1, $zero, L_800B0178
    if (ctx->r9 == 0) {
        // 0x800B0134: nop
    
            goto L_800B0178;
    }
    // 0x800B0134: nop

    // 0x800B0138: lw          $a1, 0x7C($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X7C);
    // 0x800B013C: jal         0x8006F94C
    // 0x800B0140: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_2;
    // 0x800B0140: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_2:
    // 0x800B0144: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B0148: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B014C: cvt.s.w     $f8, $f16
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    ctx->f8.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B0150: lwc1        $f7, -0x7458($at)
    ctx->f_odd[(7 - 1) * 2] = MEM_W(ctx->r1, -0X7458);
    // 0x800B0154: lwc1        $f6, -0x7454($at)
    ctx->f6.u32l = MEM_W(ctx->r1, -0X7454);
    // 0x800B0158: cvt.d.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.fl); 
    ctx->f10.d = CVT_D_S(ctx->f8.fl);
    // 0x800B015C: mul.d       $f18, $f10, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = MUL_D(ctx->f10.d, ctx->f6.d);
    // 0x800B0160: lwc1        $f4, 0x24($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B0164: nop

    // 0x800B0168: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800B016C: add.d       $f8, $f16, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f18.d); 
    ctx->f8.d = ctx->f16.d + ctx->f18.d;
    // 0x800B0170: cvt.s.d     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f8.d); 
    ctx->f10.fl = CVT_S_D(ctx->f8.d);
    // 0x800B0174: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
L_800B0178:
    // 0x800B0178: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800B017C: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800B0180: andi        $v1, $v0, 0x70
    ctx->r3 = ctx->r2 & 0X70;
    // 0x800B0184: beq         $v1, $at, L_800B019C
    if (ctx->r3 == ctx->r1) {
        // 0x800B0188: addiu       $at, $zero, 0x40
        ctx->r1 = ADD32(0, 0X40);
            goto L_800B019C;
    }
    // 0x800B0188: addiu       $at, $zero, 0x40
    ctx->r1 = ADD32(0, 0X40);
    // 0x800B018C: beq         $v1, $at, L_800B01F8
    if (ctx->r3 == ctx->r1) {
        // 0x800B0190: lw          $t5, 0x44($sp)
        ctx->r13 = MEM_W(ctx->r29, 0X44);
            goto L_800B01F8;
    }
    // 0x800B0190: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
    // 0x800B0194: b           L_800B024C
    // 0x800B0198: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
        goto L_800B024C;
    // 0x800B0198: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
L_800B019C:
    // 0x800B019C: lw          $t2, 0x44($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X44);
    // 0x800B01A0: lwc1        $f6, 0x1C($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B01A4: lwc1        $f4, 0x1C($t2)
    ctx->f4.u32l = MEM_W(ctx->r10, 0X1C);
    // 0x800B01A8: lwc1        $f18, 0x20($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B01AC: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B01B0: lwc1        $f6, 0x24($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B01B4: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x800B01B8: lw          $t3, 0x44($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X44);
    // 0x800B01BC: nop

    // 0x800B01C0: lwc1        $f8, 0x20($t3)
    ctx->f8.u32l = MEM_W(ctx->r11, 0X20);
    // 0x800B01C4: nop

    // 0x800B01C8: add.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f18.fl + ctx->f8.fl;
    // 0x800B01CC: swc1        $f10, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f10.u32l;
    // 0x800B01D0: lw          $t4, 0x44($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X44);
    // 0x800B01D4: nop

    // 0x800B01D8: lwc1        $f4, 0x24($t4)
    ctx->f4.u32l = MEM_W(ctx->r12, 0X24);
    // 0x800B01DC: nop

    // 0x800B01E0: add.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f6.fl + ctx->f4.fl;
    // 0x800B01E4: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x800B01E8: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800B01EC: b           L_800B024C
    // 0x800B01F0: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
        goto L_800B024C;
    // 0x800B01F0: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
    // 0x800B01F4: lw          $t5, 0x44($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X44);
L_800B01F8:
    // 0x800B01F8: lwc1        $f18, 0x1C($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B01FC: lwc1        $f8, 0x1C($t5)
    ctx->f8.u32l = MEM_W(ctx->r13, 0X1C);
    // 0x800B0200: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B0204: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B0208: lwc1        $f18, 0x24($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B020C: swc1        $f10, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f10.u32l;
    // 0x800B0210: lw          $t6, 0x44($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X44);
    // 0x800B0214: nop

    // 0x800B0218: lwc1        $f4, 0x20($t6)
    ctx->f4.u32l = MEM_W(ctx->r14, 0X20);
    // 0x800B021C: nop

    // 0x800B0220: mul.s       $f16, $f6, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = MUL_S(ctx->f6.fl, ctx->f4.fl);
    // 0x800B0224: swc1        $f16, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f16.u32l;
    // 0x800B0228: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800B022C: nop

    // 0x800B0230: lwc1        $f8, 0x24($t7)
    ctx->f8.u32l = MEM_W(ctx->r15, 0X24);
    // 0x800B0234: nop

    // 0x800B0238: mul.s       $f10, $f18, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = MUL_S(ctx->f18.fl, ctx->f8.fl);
    // 0x800B023C: swc1        $f10, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f10.u32l;
    // 0x800B0240: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x800B0244: nop

    // 0x800B0248: andi        $t8, $v0, 0x4
    ctx->r24 = ctx->r2 & 0X4;
L_800B024C:
    // 0x800B024C: beq         $t8, $zero, L_800B03B0
    if (ctx->r24 == 0) {
        // 0x800B0250: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_800B03B0;
    }
    // 0x800B0250: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800B0254: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800B0258: nop

    // 0x800B025C: swc1        $f0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f0.u32l;
    // 0x800B0260: swc1        $f0, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f0.u32l;
    // 0x800B0264: lwc1        $f6, 0x3C($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0X3C);
    // 0x800B0268: nop

    // 0x800B026C: neg.s       $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = -ctx->f6.fl;
    // 0x800B0270: swc1        $f4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f4.u32l;
    // 0x800B0274: lw          $v1, 0x5C($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X5C);
    // 0x800B0278: nop

    // 0x800B027C: andi        $t9, $v1, 0x10
    ctx->r25 = ctx->r3 & 0X10;
    // 0x800B0280: beq         $t9, $zero, L_800B02D0
    if (ctx->r25 == 0) {
        // 0x800B0284: andi        $t0, $v1, 0x60
        ctx->r8 = ctx->r3 & 0X60;
            goto L_800B02D0;
    }
    // 0x800B0284: andi        $t0, $v1, 0x60
    ctx->r8 = ctx->r3 & 0X60;
    // 0x800B0288: lw          $a1, 0x70($s1)
    ctx->r5 = MEM_W(ctx->r17, 0X70);
    // 0x800B028C: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B0290: jal         0x8006F94C
    // 0x800B0294: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_3;
    // 0x800B0294: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_3:
    // 0x800B0298: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x800B029C: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800B02A0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800B02A4: lwc1        $f11, -0x7450($at)
    ctx->f_odd[(11 - 1) * 2] = MEM_W(ctx->r1, -0X7450);
    // 0x800B02A8: lwc1        $f10, -0x744C($at)
    ctx->f10.u32l = MEM_W(ctx->r1, -0X744C);
    // 0x800B02AC: cvt.d.s     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f8.d = CVT_D_S(ctx->f18.fl);
    // 0x800B02B0: mul.d       $f6, $f8, $f10
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f10.d); 
    ctx->f6.d = MUL_D(ctx->f8.d, ctx->f10.d);
    // 0x800B02B4: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B02B8: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B02BC: cvt.d.s     $f16, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f16.d = CVT_D_S(ctx->f4.fl);
    // 0x800B02C0: add.d       $f18, $f16, $f6
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f16.d); NAN_CHECK(ctx->f6.d); 
    ctx->f18.d = ctx->f16.d + ctx->f6.d;
    // 0x800B02C4: cvt.s.d     $f8, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f8.fl = CVT_S_D(ctx->f18.d);
    // 0x800B02C8: swc1        $f8, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f8.u32l;
    // 0x800B02CC: andi        $t0, $v1, 0x60
    ctx->r8 = ctx->r3 & 0X60;
L_800B02D0:
    // 0x800B02D0: beq         $t0, $zero, L_800B0358
    if (ctx->r8 == 0) {
        // 0x800B02D4: lw          $a0, 0x48($sp)
        ctx->r4 = MEM_W(ctx->r29, 0X48);
            goto L_800B0358;
    }
    // 0x800B02D4: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
    // 0x800B02D8: lw          $t1, 0x48($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X48);
    // 0x800B02DC: andi        $t3, $v1, 0x20
    ctx->r11 = ctx->r3 & 0X20;
    // 0x800B02E0: lh          $t2, 0x12($t1)
    ctx->r10 = MEM_H(ctx->r9, 0X12);
    // 0x800B02E4: beq         $t3, $zero, L_800B030C
    if (ctx->r11 == 0) {
        // 0x800B02E8: sh          $t2, 0x28($sp)
        MEM_H(0X28, ctx->r29) = ctx->r10;
            goto L_800B030C;
    }
    // 0x800B02E8: sh          $t2, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r10;
    // 0x800B02EC: lh          $a1, 0x6A($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6A);
    // 0x800B02F0: sw          $v1, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r3;
    // 0x800B02F4: jal         0x8006F94C
    // 0x800B02F8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_4;
    // 0x800B02F8: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_4:
    // 0x800B02FC: lh          $t4, 0x28($sp)
    ctx->r12 = MEM_H(ctx->r29, 0X28);
    // 0x800B0300: lw          $v1, 0x3C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X3C);
    // 0x800B0304: addu        $t5, $t4, $v0
    ctx->r13 = ADD32(ctx->r12, ctx->r2);
    // 0x800B0308: sh          $t5, 0x28($sp)
    MEM_H(0X28, ctx->r29) = ctx->r13;
L_800B030C:
    // 0x800B030C: lw          $t6, 0x48($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X48);
    // 0x800B0310: andi        $t8, $v1, 0x40
    ctx->r24 = ctx->r3 & 0X40;
    // 0x800B0314: lh          $t7, 0x14($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X14);
    // 0x800B0318: beq         $t8, $zero, L_800B033C
    if (ctx->r24 == 0) {
        // 0x800B031C: sh          $t7, 0x2A($sp)
        MEM_H(0X2A, ctx->r29) = ctx->r15;
            goto L_800B033C;
    }
    // 0x800B031C: sh          $t7, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r15;
    // 0x800B0320: lh          $a1, 0x6C($s1)
    ctx->r5 = MEM_H(ctx->r17, 0X6C);
    // 0x800B0324: jal         0x8006F94C
    // 0x800B0328: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    rand_range(rdram, ctx);
        goto after_5;
    // 0x800B0328: negu        $a0, $a1
    ctx->r4 = SUB32(0, ctx->r5);
    after_5:
    // 0x800B032C: lh          $t9, 0x2A($sp)
    ctx->r25 = MEM_H(ctx->r29, 0X2A);
    // 0x800B0330: nop

    // 0x800B0334: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x800B0338: sh          $t0, 0x2A($sp)
    MEM_H(0X2A, ctx->r29) = ctx->r8;
L_800B033C:
    // 0x800B033C: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x800B0340: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B0344: jal         0x80070490
    // 0x800B0348: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    vec3f_rotate_py(rdram, ctx);
        goto after_6;
    // 0x800B0348: addiu       $a0, $sp, 0x28
    ctx->r4 = ADD32(ctx->r29, 0X28);
    after_6:
    // 0x800B034C: b           L_800B036C
    // 0x800B0350: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
        goto L_800B036C;
    // 0x800B0350: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
    // 0x800B0354: lw          $a0, 0x48($sp)
    ctx->r4 = MEM_W(ctx->r29, 0X48);
L_800B0358:
    // 0x800B0358: addiu       $s1, $sp, 0x30
    ctx->r17 = ADD32(ctx->r29, 0X30);
    // 0x800B035C: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    // 0x800B0360: jal         0x80070490
    // 0x800B0364: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    vec3f_rotate_py(rdram, ctx);
        goto after_7;
    // 0x800B0364: addiu       $a0, $a0, 0x12
    ctx->r4 = ADD32(ctx->r4, 0X12);
    after_7:
    // 0x800B0368: lw          $a0, 0x3C($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X3C);
L_800B036C:
    // 0x800B036C: jal         0x80070320
    // 0x800B0370: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    vec3f_rotate(rdram, ctx);
        goto after_8;
    // 0x800B0370: or          $a1, $s1, $zero
    ctx->r5 = ctx->r17 | 0;
    after_8:
    // 0x800B0374: lwc1        $f10, 0x1C($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X1C);
    // 0x800B0378: lwc1        $f4, 0x30($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X30);
    // 0x800B037C: lwc1        $f6, 0x20($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X20);
    // 0x800B0380: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B0384: lwc1        $f10, 0x24($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X24);
    // 0x800B0388: swc1        $f16, 0x1C($s0)
    MEM_W(0X1C, ctx->r16) = ctx->f16.u32l;
    // 0x800B038C: lwc1        $f18, 0x34($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X34);
    // 0x800B0390: nop

    // 0x800B0394: add.s       $f8, $f6, $f18
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f18.fl;
    // 0x800B0398: swc1        $f8, 0x20($s0)
    MEM_W(0X20, ctx->r16) = ctx->f8.u32l;
    // 0x800B039C: lwc1        $f4, 0x38($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X38);
    // 0x800B03A0: nop

    // 0x800B03A4: add.s       $f16, $f10, $f4
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f16.fl = ctx->f10.fl + ctx->f4.fl;
    // 0x800B03A8: swc1        $f16, 0x24($s0)
    MEM_W(0X24, ctx->r16) = ctx->f16.u32l;
    // 0x800B03AC: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_800B03B0:
    // 0x800B03B0: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800B03B4: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800B03B8: jr          $ra
    // 0x800B03BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x800B03BC: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void get_taj_challenge_type(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80017E88: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80017E8C: lh          $v0, -0x5128($v0)
    ctx->r2 = MEM_H(ctx->r2, -0X5128);
    // 0x80017E90: jr          $ra
    // 0x80017E94: nop

    return;
    // 0x80017E94: nop

;}
RECOMP_FUNC void play_rocket_trailing_sound(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003F0F8: addiu       $sp, $sp, -0x70
    ctx->r29 = ADD32(ctx->r29, -0X70);
    // 0x8003F0FC: sw          $s2, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r18;
    // 0x8003F100: or          $s2, $a0, $zero
    ctx->r18 = ctx->r4 | 0;
    // 0x8003F104: sw          $ra, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r31;
    // 0x8003F108: sw          $s6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r22;
    // 0x8003F10C: sw          $s5, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r21;
    // 0x8003F110: sw          $s4, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r20;
    // 0x8003F114: or          $s5, $a1, $zero
    ctx->r21 = ctx->r5 | 0;
    // 0x8003F118: andi        $s6, $a2, 0xFFFF
    ctx->r22 = ctx->r6 & 0XFFFF;
    // 0x8003F11C: sw          $s3, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r19;
    // 0x8003F120: sw          $s1, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r17;
    // 0x8003F124: sw          $s0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r16;
    // 0x8003F128: swc1        $f21, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x8003F12C: swc1        $f20, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f20.u32l;
    // 0x8003F130: sw          $a2, 0x78($sp)
    MEM_W(0X78, ctx->r29) = ctx->r6;
    // 0x8003F134: or          $s4, $zero, $zero
    ctx->r20 = 0 | 0;
    // 0x8003F138: jal         0x8001BA90
    // 0x8003F13C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    get_racer_objects_by_port(rdram, ctx);
        goto after_0;
    // 0x8003F13C: addiu       $a0, $sp, 0x60
    ctx->r4 = ADD32(ctx->r29, 0X60);
    after_0:
    // 0x8003F140: lw          $t6, 0x60($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X60);
    // 0x8003F144: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8003F148: blez        $t6, L_8003F20C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x8003F14C: or          $s1, $v0, $zero
        ctx->r17 = ctx->r2 | 0;
            goto L_8003F20C;
    }
    // 0x8003F14C: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8003F150: addiu       $s3, $zero, -0x1
    ctx->r19 = ADD32(0, -0X1);
L_8003F154:
    // 0x8003F154: lw          $v0, 0x0($s1)
    ctx->r2 = MEM_W(ctx->r17, 0X0);
    // 0x8003F158: lw          $t7, 0x4($s5)
    ctx->r15 = MEM_W(ctx->r21, 0X4);
    // 0x8003F15C: nop

    // 0x8003F160: beq         $t7, $v0, L_8003F1FC
    if (ctx->r15 == ctx->r2) {
        // 0x8003F164: lw          $t0, 0x60($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X60);
            goto L_8003F1FC;
    }
    // 0x8003F164: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8003F168: lw          $t8, 0x64($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X64);
    // 0x8003F16C: nop

    // 0x8003F170: lh          $t9, 0x0($t8)
    ctx->r25 = MEM_H(ctx->r24, 0X0);
    // 0x8003F174: nop

    // 0x8003F178: beq         $s3, $t9, L_8003F1FC
    if (ctx->r19 == ctx->r25) {
        // 0x8003F17C: lw          $t0, 0x60($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X60);
            goto L_8003F1FC;
    }
    // 0x8003F17C: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8003F180: lwc1        $f4, 0xC($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0XC);
    // 0x8003F184: lwc1        $f6, 0xC($s2)
    ctx->f6.u32l = MEM_W(ctx->r18, 0XC);
    // 0x8003F188: lwc1        $f8, 0x10($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X10);
    // 0x8003F18C: sub.s       $f0, $f4, $f6
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f0.fl = ctx->f4.fl - ctx->f6.fl;
    // 0x8003F190: lwc1        $f10, 0x10($s2)
    ctx->f10.u32l = MEM_W(ctx->r18, 0X10);
    // 0x8003F194: mul.s       $f4, $f0, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f4.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x8003F198: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x8003F19C: lwc1        $f16, 0x14($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X14);
    // 0x8003F1A0: lwc1        $f18, 0x14($s2)
    ctx->f18.u32l = MEM_W(ctx->r18, 0X14);
    // 0x8003F1A4: mul.s       $f6, $f2, $f2
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f6.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x8003F1A8: sub.s       $f14, $f16, $f18
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f14.fl = ctx->f16.fl - ctx->f18.fl;
    // 0x8003F1AC: mul.s       $f10, $f14, $f14
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f10.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x8003F1B0: add.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = ctx->f4.fl + ctx->f6.fl;
    // 0x8003F1B4: jal         0x800C9AD0
    // 0x8003F1B8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x8003F1B8: add.s       $f12, $f8, $f10
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f12.fl = ctx->f8.fl + ctx->f10.fl;
    after_1:
    // 0x8003F1BC: mov.s       $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    ctx->f20.fl = ctx->f0.fl;
    // 0x8003F1C0: jal         0x80001CB8
    // 0x8003F1C4: andi        $a0, $s6, 0xFFFF
    ctx->r4 = ctx->r22 & 0XFFFF;
    sound_distance(rdram, ctx);
        goto after_2;
    // 0x8003F1C4: andi        $a0, $s6, 0xFFFF
    ctx->r4 = ctx->r22 & 0XFFFF;
    after_2:
    // 0x8003F1C8: mtc1        $v0, $f16
    ctx->f16.u32l = ctx->r2;
    // 0x8003F1CC: bgez        $v0, L_8003F1E4
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8003F1D0: cvt.s.w     $f18, $f16
        CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
            goto L_8003F1E4;
    }
    // 0x8003F1D0: cvt.s.w     $f18, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    ctx->f18.fl = CVT_S_W(ctx->f16.u32l);
    // 0x8003F1D4: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8003F1D8: mtc1        $at, $f4
    ctx->f4.u32l = ctx->r1;
    // 0x8003F1DC: nop

    // 0x8003F1E0: add.s       $f18, $f18, $f4
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f18.fl = ctx->f18.fl + ctx->f4.fl;
L_8003F1E4:
    // 0x8003F1E4: c.le.s      $f20, $f18
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 18);
    c1cs = ctx->f20.fl <= ctx->f18.fl;
    // 0x8003F1E8: nop

    // 0x8003F1EC: bc1f        L_8003F1FC
    if (!c1cs) {
        // 0x8003F1F0: lw          $t0, 0x60($sp)
        ctx->r8 = MEM_W(ctx->r29, 0X60);
            goto L_8003F1FC;
    }
    // 0x8003F1F0: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
    // 0x8003F1F4: addiu       $s4, $zero, 0x1
    ctx->r20 = ADD32(0, 0X1);
    // 0x8003F1F8: lw          $t0, 0x60($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X60);
L_8003F1FC:
    // 0x8003F1FC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8003F200: slt         $at, $s0, $t0
    ctx->r1 = SIGNED(ctx->r16) < SIGNED(ctx->r8) ? 1 : 0;
    // 0x8003F204: bne         $at, $zero, L_8003F154
    if (ctx->r1 != 0) {
        // 0x8003F208: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8003F154;
    }
    // 0x8003F208: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8003F20C:
    // 0x8003F20C: beq         $s4, $zero, L_8003F284
    if (ctx->r20 == 0) {
        // 0x8003F210: nop
    
            goto L_8003F284;
    }
    // 0x8003F210: nop

    // 0x8003F214: lw          $a0, 0x1C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X1C);
    // 0x8003F218: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8003F21C: bne         $a0, $zero, L_8003F268
    if (ctx->r4 != 0) {
        // 0x8003F220: addiu       $s0, $s0, -0x2B24
        ctx->r16 = ADD32(ctx->r16, -0X2B24);
            goto L_8003F268;
    }
    // 0x8003F220: addiu       $s0, $s0, -0x2B24
    ctx->r16 = ADD32(ctx->r16, -0X2B24);
    // 0x8003F224: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8003F228: andi        $a0, $s6, 0xFFFF
    ctx->r4 = ctx->r22 & 0XFFFF;
    // 0x8003F22C: slti        $at, $t1, 0x8
    ctx->r1 = SIGNED(ctx->r9) < 0X8 ? 1 : 0;
    // 0x8003F230: beq         $at, $zero, L_8003F2B8
    if (ctx->r1 == 0) {
        // 0x8003F234: addiu       $t2, $zero, 0x1
        ctx->r10 = ADD32(0, 0X1);
            goto L_8003F2B8;
    }
    // 0x8003F234: addiu       $t2, $zero, 0x1
    ctx->r10 = ADD32(0, 0X1);
    // 0x8003F238: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    // 0x8003F23C: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x8003F240: lw          $a3, 0x14($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X14);
    // 0x8003F244: addiu       $t3, $s5, 0x1C
    ctx->r11 = ADD32(ctx->r21, 0X1C);
    // 0x8003F248: sw          $t3, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r11;
    // 0x8003F24C: jal         0x80009558
    // 0x8003F250: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    audspat_play_sound_at_position(rdram, ctx);
        goto after_3;
    // 0x8003F250: sw          $t2, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r10;
    after_3:
    // 0x8003F254: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8003F258: nop

    // 0x8003F25C: addiu       $t5, $t4, 0x1
    ctx->r13 = ADD32(ctx->r12, 0X1);
    // 0x8003F260: b           L_8003F2B8
    // 0x8003F264: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
        goto L_8003F2B8;
    // 0x8003F264: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
L_8003F268:
    // 0x8003F268: lw          $a1, 0xC($s2)
    ctx->r5 = MEM_W(ctx->r18, 0XC);
    // 0x8003F26C: lw          $a2, 0x10($s2)
    ctx->r6 = MEM_W(ctx->r18, 0X10);
    // 0x8003F270: lw          $a3, 0x14($s2)
    ctx->r7 = MEM_W(ctx->r18, 0X14);
    // 0x8003F274: jal         0x800096D8
    // 0x8003F278: nop

    audspat_point_set_position(rdram, ctx);
        goto after_4;
    // 0x8003F278: nop

    after_4:
    // 0x8003F27C: b           L_8003F2BC
    // 0x8003F280: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
        goto L_8003F2BC;
    // 0x8003F280: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8003F284:
    // 0x8003F284: lw          $a0, 0x1C($s5)
    ctx->r4 = MEM_W(ctx->r21, 0X1C);
    // 0x8003F288: nop

    // 0x8003F28C: beq         $a0, $zero, L_8003F2BC
    if (ctx->r4 == 0) {
        // 0x8003F290: lw          $ra, 0x44($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X44);
            goto L_8003F2BC;
    }
    // 0x8003F290: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
    // 0x8003F294: jal         0x800096F8
    // 0x8003F298: nop

    audspat_point_stop(rdram, ctx);
        goto after_5;
    // 0x8003F298: nop

    after_5:
    // 0x8003F29C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8003F2A0: addiu       $s0, $s0, -0x2B24
    ctx->r16 = ADD32(ctx->r16, -0X2B24);
    // 0x8003F2A4: sw          $zero, 0x1C($s5)
    MEM_W(0X1C, ctx->r21) = 0;
    // 0x8003F2A8: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8003F2AC: nop

    // 0x8003F2B0: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8003F2B4: sw          $t7, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r15;
L_8003F2B8:
    // 0x8003F2B8: lw          $ra, 0x44($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X44);
L_8003F2BC:
    // 0x8003F2BC: lwc1        $f21, 0x20($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8003F2C0: lwc1        $f20, 0x24($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8003F2C4: lw          $s0, 0x28($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X28);
    // 0x8003F2C8: lw          $s1, 0x2C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X2C);
    // 0x8003F2CC: lw          $s2, 0x30($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X30);
    // 0x8003F2D0: lw          $s3, 0x34($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X34);
    // 0x8003F2D4: lw          $s4, 0x38($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X38);
    // 0x8003F2D8: lw          $s5, 0x3C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X3C);
    // 0x8003F2DC: lw          $s6, 0x40($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X40);
    // 0x8003F2E0: jr          $ra
    // 0x8003F2E4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
    return;
    // 0x8003F2E4: addiu       $sp, $sp, 0x70
    ctx->r29 = ADD32(ctx->r29, 0X70);
;}
RECOMP_FUNC void write_eeprom_settings(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007497C: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80074980: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80074984: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074988: jal         0x8006A100
    // 0x8007498C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x8007498C: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    after_0:
    // 0x80074990: jal         0x800CE210
    // 0x80074994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074994: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x80074998: bne         $v0, $zero, L_800749A8
    if (ctx->r2 != 0) {
        // 0x8007499C: addiu       $a2, $zero, 0x0
        ctx->r6 = ADD32(0, 0X0);
            goto L_800749A8;
    }
    // 0x8007499C: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800749A0: b           L_80074A3C
    // 0x800749A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_80074A3C;
    // 0x800749A4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_800749A8:
    // 0x800749A8: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x800749AC: lw          $a1, 0x4($s0)
    ctx->r5 = MEM_W(ctx->r16, 0X4);
    // 0x800749B0: jal         0x800CEB04
    // 0x800749B4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ll_lshift_recomp(rdram, ctx);
        goto after_2;
    // 0x800749B4: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_2:
    // 0x800749B8: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800749BC: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x800749C0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800749C4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    // 0x800749C8: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800749CC: jal         0x800CEA60
    // 0x800749D0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    __ull_rshift_recomp(rdram, ctx);
        goto after_3;
    // 0x800749D0: addiu       $a3, $zero, 0x8
    ctx->r7 = ADD32(0, 0X8);
    after_3:
    // 0x800749D4: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800749D8: sw          $v1, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r3;
    // 0x800749DC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800749E0: jal         0x8007480C
    // 0x800749E4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    calculate_eeprom_settings_checksum(rdram, ctx);
        goto after_4;
    // 0x800749E4: or          $a1, $v1, $zero
    ctx->r5 = ctx->r3 | 0;
    after_4:
    // 0x800749E8: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    // 0x800749EC: sra         $a0, $v0, 31
    ctx->r4 = S32(SIGNED(ctx->r2) >> 31);
    // 0x800749F0: addiu       $a2, $zero, 0x0
    ctx->r6 = ADD32(0, 0X0);
    // 0x800749F4: jal         0x800CEB04
    // 0x800749F8: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    __ll_lshift_recomp(rdram, ctx);
        goto after_5;
    // 0x800749F8: addiu       $a3, $zero, 0x38
    ctx->r7 = ADD32(0, 0X38);
    after_5:
    // 0x800749FC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x80074A00: lw          $t7, 0x4($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X4);
    // 0x80074A04: or          $t8, $t6, $v0
    ctx->r24 = ctx->r14 | ctx->r2;
    // 0x80074A08: or          $t9, $t7, $v1
    ctx->r25 = ctx->r15 | ctx->r3;
    // 0x80074A0C: sw          $t9, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r25;
    // 0x80074A10: jal         0x8006EAC0
    // 0x80074A14: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    is_reset_pressed(rdram, ctx);
        goto after_6;
    // 0x80074A14: sw          $t8, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r24;
    after_6:
    // 0x80074A18: bne         $v0, $zero, L_80074A3C
    if (ctx->r2 != 0) {
        // 0x80074A1C: addiu       $v0, $zero, 0x1
        ctx->r2 = ADD32(0, 0X1);
            goto L_80074A3C;
    }
    // 0x80074A1C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x80074A20: jal         0x8006A100
    // 0x80074A24: nop

    si_mesg(rdram, ctx);
        goto after_7;
    // 0x80074A24: nop

    after_7:
    // 0x80074A28: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80074A2C: addiu       $a1, $zero, 0xF
    ctx->r5 = ADD32(0, 0XF);
    // 0x80074A30: jal         0x800CE580
    // 0x80074A34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    osEepromWrite_recomp(rdram, ctx);
        goto after_8;
    // 0x80074A34: or          $a2, $s0, $zero
    ctx->r6 = ctx->r16 | 0;
    after_8:
    // 0x80074A38: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
L_80074A3C:
    // 0x80074A3C: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x80074A40: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x80074A44: jr          $ra
    // 0x80074A48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    return;
    // 0x80074A48: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
;}
RECOMP_FUNC void _collectPVoices(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800656BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x800656C0: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800656C4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x800656C8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800656CC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x800656D0: lw          $s0, 0x14($a0)
    ctx->r16 = MEM_W(ctx->r4, 0X14);
    // 0x800656D4: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x800656D8: beq         $s0, $zero, L_80065704
    if (ctx->r16 == 0) {
        // 0x800656DC: addiu       $s2, $a0, 0x4
        ctx->r18 = ADD32(ctx->r4, 0X4);
            goto L_80065704;
    }
    // 0x800656DC: addiu       $s2, $a0, 0x4
    ctx->r18 = ADD32(ctx->r4, 0X4);
L_800656E0:
    // 0x800656E0: jal         0x800C8760
    // 0x800656E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    alUnlink(rdram, ctx);
        goto after_0;
    // 0x800656E4: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_0:
    // 0x800656E8: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x800656EC: jal         0x800C8790
    // 0x800656F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    alLink(rdram, ctx);
        goto after_1;
    // 0x800656F0: or          $a1, $s2, $zero
    ctx->r5 = ctx->r18 | 0;
    after_1:
    // 0x800656F4: lw          $s0, 0x14($s1)
    ctx->r16 = MEM_W(ctx->r17, 0X14);
    // 0x800656F8: nop

    // 0x800656FC: bne         $s0, $zero, L_800656E0
    if (ctx->r16 != 0) {
        // 0x80065700: nop
    
            goto L_800656E0;
    }
    // 0x80065700: nop

L_80065704:
    // 0x80065704: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x80065708: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006570C: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80065710: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80065714: jr          $ra
    // 0x80065718: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80065718: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void tex_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8007B2BC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8007B2C0: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8007B2C4: beq         $a0, $zero, L_8007B364
    if (ctx->r4 == 0) {
        // 0x8007B2C8: or          $a2, $a0, $zero
        ctx->r6 = ctx->r4 | 0;
            goto L_8007B364;
    }
    // 0x8007B2C8: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8007B2CC: lbu         $t6, 0x5($a0)
    ctx->r14 = MEM_BU(ctx->r4, 0X5);
    // 0x8007B2D0: nop

    // 0x8007B2D4: addiu       $t7, $t6, -0x1
    ctx->r15 = ADD32(ctx->r14, -0X1);
    // 0x8007B2D8: andi        $t8, $t7, 0xFF
    ctx->r24 = ctx->r15 & 0XFF;
    // 0x8007B2DC: bgtz        $t8, L_8007B364
    if (SIGNED(ctx->r24) > 0) {
        // 0x8007B2E0: sb          $t7, 0x5($a0)
        MEM_B(0X5, ctx->r4) = ctx->r15;
            goto L_8007B364;
    }
    // 0x8007B2E0: sb          $t7, 0x5($a0)
    MEM_B(0X5, ctx->r4) = ctx->r15;
    // 0x8007B2E4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8007B2E8: lw          $a0, 0x6330($a0)
    ctx->r4 = MEM_W(ctx->r4, 0X6330);
    // 0x8007B2EC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8007B2F0: blez        $a0, L_8007B364
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8007B2F4: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8007B364;
    }
    // 0x8007B2F4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8007B2F8: lw          $a1, 0x6328($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X6328);
    // 0x8007B2FC: nop

    // 0x8007B300: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
L_8007B304:
    // 0x8007B304: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8007B308: lw          $t1, 0x4($t0)
    ctx->r9 = MEM_W(ctx->r8, 0X4);
    // 0x8007B30C: nop

    // 0x8007B310: bne         $a2, $t1, L_8007B358
    if (ctx->r6 != ctx->r9) {
        // 0x8007B314: addiu       $v0, $v0, 0x1
        ctx->r2 = ADD32(ctx->r2, 0X1);
            goto L_8007B358;
    }
    // 0x8007B314: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8007B318: or          $a0, $a2, $zero
    ctx->r4 = ctx->r6 | 0;
    // 0x8007B31C: jal         0x80071140
    // 0x8007B320: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    mempool_free(rdram, ctx);
        goto after_0;
    // 0x8007B320: sw          $t9, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r25;
    after_0:
    // 0x8007B324: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8007B328: addiu       $v0, $v0, 0x6328
    ctx->r2 = ADD32(ctx->r2, 0X6328);
    // 0x8007B32C: lw          $v1, 0x18($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X18);
    // 0x8007B330: lw          $t2, 0x0($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X0);
    // 0x8007B334: addiu       $a0, $zero, -0x1
    ctx->r4 = ADD32(0, -0X1);
    // 0x8007B338: addu        $t3, $t2, $v1
    ctx->r11 = ADD32(ctx->r10, ctx->r3);
    // 0x8007B33C: sw          $a0, 0x0($t3)
    MEM_W(0X0, ctx->r11) = ctx->r4;
    // 0x8007B340: lw          $t4, 0x0($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X0);
    // 0x8007B344: nop

    // 0x8007B348: addu        $t5, $t4, $v1
    ctx->r13 = ADD32(ctx->r12, ctx->r3);
    // 0x8007B34C: b           L_8007B364
    // 0x8007B350: sw          $a0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r4;
        goto L_8007B364;
    // 0x8007B350: sw          $a0, 0x4($t5)
    MEM_W(0X4, ctx->r13) = ctx->r4;
    // 0x8007B354: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
L_8007B358:
    // 0x8007B358: slt         $at, $v0, $a0
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8007B35C: bne         $at, $zero, L_8007B304
    if (ctx->r1 != 0) {
        // 0x8007B360: sll         $t9, $v0, 3
        ctx->r25 = S32(ctx->r2 << 3);
            goto L_8007B304;
    }
    // 0x8007B360: sll         $t9, $v0, 3
    ctx->r25 = S32(ctx->r2 << 3);
L_8007B364:
    // 0x8007B364: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x8007B368: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8007B36C: jr          $ra
    // 0x8007B370: nop

    return;
    // 0x8007B370: nop

;}
RECOMP_FUNC void light_distance_calc(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80033A14: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80033A18: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80033A1C: sw          $s0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r16;
    // 0x80033A20: swc1        $f21, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80033A24: swc1        $f20, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f20.u32l;
    // 0x80033A28: lw          $t6, 0x28($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X28);
    // 0x80033A2C: lbu         $t7, 0x3($a0)
    ctx->r15 = MEM_BU(ctx->r4, 0X3);
    // 0x80033A30: mtc1        $t6, $f4
    ctx->f4.u32l = ctx->r14;
    // 0x80033A34: lui         $at, 0x4780
    ctx->r1 = S32(0X4780 << 16);
    // 0x80033A38: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80033A3C: cvt.s.w     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.fl = CVT_S_W(ctx->f4.u32l);
    // 0x80033A40: addiu       $t8, $t7, -0x1
    ctx->r24 = ADD32(ctx->r15, -0X1);
    // 0x80033A44: sltiu       $at, $t8, 0x5
    ctx->r1 = ctx->r24 < 0X5 ? 1 : 0;
    // 0x80033A48: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80033A4C: beq         $at, $zero, L_80033BEC
    if (ctx->r1 == 0) {
        // 0x80033A50: div.s       $f20, $f6, $f8
        CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
            goto L_80033BEC;
    }
    // 0x80033A50: div.s       $f20, $f6, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = DIV_S(ctx->f6.fl, ctx->f8.fl);
    // 0x80033A54: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x80033A58: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80033A5C: addu        $at, $at, $t8
    gpr jr_addend_80033A68 = ctx->r24;
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x80033A60: lw          $t8, 0x5F80($at)
    ctx->r24 = ADD32(ctx->r1, 0X5F80);
    // 0x80033A64: nop

    // 0x80033A68: jr          $t8
    // 0x80033A6C: nop

    switch (jr_addend_80033A68 >> 2) {
        case 0: goto L_80033A70; break;
        case 1: goto L_80033AA4; break;
        case 2: goto L_80033AE4; break;
        case 3: goto L_80033B48; break;
        case 4: goto L_80033BB4; break;
        default: switch_error(__func__, 0x80033A68, 0x800E5F80);
    }
    // 0x80033A6C: nop

L_80033A70:
    // 0x80033A70: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033A74: lwc1        $f12, -0x2B40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B40);
    // 0x80033A78: jal         0x800C9AD0
    // 0x80033A7C: nop

    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80033A7C: nop

    after_0:
    // 0x80033A80: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033A84: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033A88: mul.s       $f18, $f0, $f16
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f18.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80033A8C: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033A90: nop

    // 0x80033A94: sub.s       $f2, $f10, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x80033A98: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80033A9C: b           L_80033BF0
    // 0x80033AA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80033BF0;
    // 0x80033AA0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033AA4:
    // 0x80033AA4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033AA8: lwc1        $f12, -0x2B40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B40);
    // 0x80033AAC: jal         0x800C9AD0
    // 0x80033AB0: nop

    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80033AB0: nop

    after_1:
    // 0x80033AB4: lwc1        $f4, 0x6C($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033AB8: nop

    // 0x80033ABC: mul.s       $f12, $f0, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = MUL_S(ctx->f0.fl, ctx->f4.fl);
    // 0x80033AC0: jal         0x800C9AD0
    // 0x80033AC4: nop

    sqrtf_recomp(rdram, ctx);
        goto after_2;
    // 0x80033AC4: nop

    after_2:
    // 0x80033AC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033ACC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80033AD0: nop

    // 0x80033AD4: sub.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl - ctx->f0.fl;
    // 0x80033AD8: mul.s       $f20, $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f8.fl);
    // 0x80033ADC: b           L_80033BF0
    // 0x80033AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80033BF0;
    // 0x80033AE0: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033AE4:
    // 0x80033AE4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033AE8: lwc1        $f12, -0x2B40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B40);
    // 0x80033AEC: jal         0x800C9AD0
    // 0x80033AF0: nop

    sqrtf_recomp(rdram, ctx);
        goto after_3;
    // 0x80033AF0: nop

    after_3:
    // 0x80033AF4: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033AF8: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80033AFC: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80033B00: mtc1        $at, $f18
    ctx->f18.u32l = ctx->r1;
    // 0x80033B04: nop

    // 0x80033B08: mul.s       $f4, $f10, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f4.fl = MUL_S(ctx->f10.fl, ctx->f18.fl);
    // 0x80033B0C: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x80033B10: nop

    // 0x80033B14: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x80033B18: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033B1C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033B20: nop

    // 0x80033B24: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80033B28: mfc1        $a0, $f6
    ctx->r4 = (int32_t)ctx->f6.u32l;
    // 0x80033B2C: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x80033B30: sll         $t0, $a0, 16
    ctx->r8 = S32(ctx->r4 << 16);
    // 0x80033B34: jal         0x800707F8
    // 0x80033B38: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    coss_f(rdram, ctx);
        goto after_4;
    // 0x80033B38: sra         $a0, $t0, 16
    ctx->r4 = S32(SIGNED(ctx->r8) >> 16);
    after_4:
    // 0x80033B3C: mul.s       $f20, $f20, $f0
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f0.fl);
    // 0x80033B40: b           L_80033BF0
    // 0x80033B44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
        goto L_80033BF0;
    // 0x80033B44: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033B48:
    // 0x80033B48: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033B4C: lwc1        $f12, -0x2B40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B40);
    // 0x80033B50: jal         0x800C9AD0
    // 0x80033B54: nop

    sqrtf_recomp(rdram, ctx);
        goto after_5;
    // 0x80033B54: nop

    after_5:
    // 0x80033B58: lwc1        $f8, 0x6C($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033B5C: lui         $at, 0x4680
    ctx->r1 = S32(0X4680 << 16);
    // 0x80033B60: mul.s       $f16, $f0, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = MUL_S(ctx->f0.fl, ctx->f8.fl);
    // 0x80033B64: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x80033B68: nop

    // 0x80033B6C: mul.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = MUL_S(ctx->f16.fl, ctx->f10.fl);
    // 0x80033B70: cfc1        $t2, $FpcCsr
    ctx->r10 = get_cop1_cs();
    // 0x80033B74: nop

    // 0x80033B78: ori         $at, $t2, 0x3
    ctx->r1 = ctx->r10 | 0X3;
    // 0x80033B7C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80033B80: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80033B84: nop

    // 0x80033B88: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x80033B8C: mfc1        $a0, $f4
    ctx->r4 = (int32_t)ctx->f4.u32l;
    // 0x80033B90: ctc1        $t2, $FpcCsr
    set_cop1_cs(ctx->r10);
    // 0x80033B94: sll         $t3, $a0, 16
    ctx->r11 = S32(ctx->r4 << 16);
    // 0x80033B98: jal         0x800707F8
    // 0x80033B9C: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    coss_f(rdram, ctx);
        goto after_6;
    // 0x80033B9C: sra         $a0, $t3, 16
    ctx->r4 = S32(SIGNED(ctx->r11) >> 16);
    after_6:
    // 0x80033BA0: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80033BA4: nop

    // 0x80033BA8: mul.s       $f20, $f20, $f6
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f6.fl);
    // 0x80033BAC: b           L_80033BEC
    // 0x80033BB0: nop

        goto L_80033BEC;
    // 0x80033BB0: nop

L_80033BB4:
    // 0x80033BB4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80033BB8: lwc1        $f12, -0x2B40($at)
    ctx->f12.u32l = MEM_W(ctx->r1, -0X2B40);
    // 0x80033BBC: jal         0x800C9AD0
    // 0x80033BC0: nop

    sqrtf_recomp(rdram, ctx);
        goto after_7;
    // 0x80033BC0: nop

    after_7:
    // 0x80033BC4: lwc1        $f16, 0x6C($s0)
    ctx->f16.u32l = MEM_W(ctx->r16, 0X6C);
    // 0x80033BC8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80033BCC: mul.s       $f10, $f0, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = MUL_S(ctx->f0.fl, ctx->f16.fl);
    // 0x80033BD0: mtc1        $at, $f8
    ctx->f8.u32l = ctx->r1;
    // 0x80033BD4: nop

    // 0x80033BD8: sub.s       $f2, $f8, $f10
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f2.fl = ctx->f8.fl - ctx->f10.fl;
    // 0x80033BDC: mul.s       $f2, $f2, $f2
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f2.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80033BE0: nop

    // 0x80033BE4: mul.s       $f20, $f20, $f2
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f20.fl = MUL_S(ctx->f20.fl, ctx->f2.fl);
    // 0x80033BE8: nop

L_80033BEC:
    // 0x80033BEC: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
L_80033BF0:
    // 0x80033BF0: mov.s       $f0, $f20
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 20);
    ctx->f0.fl = ctx->f20.fl;
    // 0x80033BF4: lwc1        $f20, 0x1C($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x80033BF8: lwc1        $f21, 0x18($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x80033BFC: lw          $s0, 0x20($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X20);
    // 0x80033C00: jr          $ra
    // 0x80033C04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x80033C04: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void sound_play_direct(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    { extern int dkr_legacy_character_play_sound(uint8_t*, recomp_context*, unsigned); if (dkr_legacy_character_play_sound(rdram, ctx, 1U)) return; }
    // 0x80001F14: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80001F18: andi        $t6, $a0, 0xFFFF
    ctx->r14 = ctx->r4 & 0XFFFF;
    // 0x80001F1C: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80001F20: sw          $a0, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r4;
    // 0x80001F24: blez        $t6, L_80001F4C
    if (SIGNED(ctx->r14) <= 0) {
        // 0x80001F28: or          $a2, $a1, $zero
        ctx->r6 = ctx->r5 | 0;
            goto L_80001F4C;
    }
    // 0x80001F28: or          $a2, $a1, $zero
    ctx->r6 = ctx->r5 | 0;
    // 0x80001F2C: sw          $t6, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r14;
    // 0x80001F30: jal         0x800020E8
    // 0x80001F34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    sound_count(rdram, ctx);
        goto after_0;
    // 0x80001F34: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    after_0:
    // 0x80001F38: lw          $v1, 0x1C($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X1C);
    // 0x80001F3C: lw          $a2, 0x24($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X24);
    // 0x80001F40: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x80001F44: beq         $at, $zero, L_80001F5C
    if (ctx->r1 == 0) {
        // 0x80001F48: nop
    
            goto L_80001F5C;
    }
    // 0x80001F48: nop

L_80001F4C:
    // 0x80001F4C: beq         $a2, $zero, L_80001FAC
    if (ctx->r6 == 0) {
        // 0x80001F50: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_80001FAC;
    }
    // 0x80001F50: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80001F54: b           L_80001FA8
    // 0x80001F58: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_80001FA8;
    // 0x80001F58: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_80001F5C:
    // 0x80001F5C: beq         $a2, $zero, L_80001F88
    if (ctx->r6 == 0) {
        // 0x80001F60: lui         $t9, 0x8011
        ctx->r25 = S32(0X8011 << 16);
            goto L_80001F88;
    }
    // 0x80001F60: lui         $t9, 0x8011
    ctx->r25 = S32(0X8011 << 16);
    // 0x80001F64: lui         $t7, 0x8011
    ctx->r15 = S32(0X8011 << 16);
    // 0x80001F68: lw          $t7, 0x5D14($t7)
    ctx->r15 = MEM_W(ctx->r15, 0X5D14);
    // 0x80001F6C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001F70: sra         $t8, $a1, 16
    ctx->r24 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001F74: lw          $a0, 0x4($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X4);
    // 0x80001F78: jal         0x80004638
    // 0x80001F7C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    sndp_play(rdram, ctx);
        goto after_1;
    // 0x80001F7C: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    after_1:
    // 0x80001F80: b           L_80001FAC
    // 0x80001F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
        goto L_80001FAC;
    // 0x80001F84: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001F88:
    // 0x80001F88: lw          $t9, 0x5D14($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X5D14);
    // 0x80001F8C: sll         $a1, $v1, 16
    ctx->r5 = S32(ctx->r3 << 16);
    // 0x80001F90: sra         $t0, $a1, 16
    ctx->r8 = S32(SIGNED(ctx->r5) >> 16);
    // 0x80001F94: lui         $a2, 0x8011
    ctx->r6 = S32(0X8011 << 16);
    // 0x80001F98: lw          $a0, 0x4($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X4);
    // 0x80001F9C: addiu       $a2, $a2, 0x5F88
    ctx->r6 = ADD32(ctx->r6, 0X5F88);
    // 0x80001FA0: jal         0x80004638
    // 0x80001FA4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    sndp_play(rdram, ctx);
        goto after_2;
    // 0x80001FA4: or          $a1, $t0, $zero
    ctx->r5 = ctx->r8 | 0;
    after_2:
L_80001FA8:
    // 0x80001FA8: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_80001FAC:
    // 0x80001FAC: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80001FB0: jr          $ra
    // 0x80001FB4: nop

    return;
    // 0x80001FB4: nop

;}
RECOMP_FUNC void write_eeprom_data(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800746F0: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x800746F4: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x800746F8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x800746FC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x80074700: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80074704: andi        $s1, $a1, 0xFF
    ctx->r17 = ctx->r5 & 0XFF;
    // 0x80074708: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8007470C: jal         0x8006A100
    // 0x80074710: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    si_mesg(rdram, ctx);
        goto after_0;
    // 0x80074710: sw          $a1, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r5;
    after_0:
    // 0x80074714: jal         0x800CE210
    // 0x80074718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromProbe_recomp(rdram, ctx);
        goto after_1;
    // 0x80074718: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_1:
    // 0x8007471C: bne         $v0, $zero, L_8007472C
    if (ctx->r2 != 0) {
        // 0x80074720: addiu       $a0, $zero, 0x200
        ctx->r4 = ADD32(0, 0X200);
            goto L_8007472C;
    }
    // 0x80074720: addiu       $a0, $zero, 0x200
    ctx->r4 = ADD32(0, 0X200);
    // 0x80074724: b           L_800747F4
    // 0x80074728: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
        goto L_800747F4;
    // 0x80074728: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8007472C:
    // 0x8007472C: jal         0x80070C9C
    // 0x80074730: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    mempool_alloc_safe(rdram, ctx);
        goto after_2;
    // 0x80074730: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    after_2:
    // 0x80074734: or          $s2, $v0, $zero
    ctx->r18 = ctx->r2 | 0;
    // 0x80074738: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8007473C: jal         0x800738A4
    // 0x80074740: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    func_800738A4(rdram, ctx);
        goto after_3;
    // 0x80074740: or          $a1, $v0, $zero
    ctx->r5 = ctx->r2 | 0;
    after_3:
    // 0x80074744: andi        $t7, $s1, 0x1
    ctx->r15 = ctx->r17 & 0X1;
    // 0x80074748: beq         $t7, $zero, L_80074790
    if (ctx->r15 == 0) {
        // 0x8007474C: sw          $s1, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r17;
            goto L_80074790;
    }
    // 0x8007474C: sw          $s1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r17;
    // 0x80074750: jal         0x8006EAC0
    // 0x80074754: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    is_reset_pressed(rdram, ctx);
        goto after_4;
    // 0x80074754: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    after_4:
    // 0x80074758: bne         $v0, $zero, L_80074790
    if (ctx->r2 != 0) {
        // 0x8007475C: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_80074790;
    }
    // 0x8007475C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_80074760:
    // 0x80074760: jal         0x8006A100
    // 0x80074764: nop

    si_mesg(rdram, ctx);
        goto after_5;
    // 0x80074764: nop

    after_5:
    // 0x80074768: addiu       $a1, $s0, 0x10
    ctx->r5 = ADD32(ctx->r16, 0X10);
    // 0x8007476C: andi        $t8, $a1, 0xFF
    ctx->r24 = ctx->r5 & 0XFF;
    // 0x80074770: sll         $t9, $s0, 3
    ctx->r25 = S32(ctx->r16 << 3);
    // 0x80074774: addu        $a2, $t9, $s2
    ctx->r6 = ADD32(ctx->r25, ctx->r18);
    // 0x80074778: or          $a1, $t8, $zero
    ctx->r5 = ctx->r24 | 0;
    // 0x8007477C: jal         0x800CE580
    // 0x80074780: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromWrite_recomp(rdram, ctx);
        goto after_6;
    // 0x80074780: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_6:
    // 0x80074784: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x80074788: bne         $s0, $s1, L_80074760
    if (ctx->r16 != ctx->r17) {
        // 0x8007478C: nop
    
            goto L_80074760;
    }
    // 0x8007478C: nop

L_80074790:
    // 0x80074790: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x80074794: nop

    // 0x80074798: andi        $t1, $t0, 0x2
    ctx->r9 = ctx->r8 & 0X2;
    // 0x8007479C: beq         $t1, $zero, L_800747E8
    if (ctx->r9 == 0) {
        // 0x800747A0: nop
    
            goto L_800747E8;
    }
    // 0x800747A0: nop

    // 0x800747A4: jal         0x8006EAC0
    // 0x800747A8: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    is_reset_pressed(rdram, ctx);
        goto after_7;
    // 0x800747A8: addiu       $s1, $zero, 0x18
    ctx->r17 = ADD32(0, 0X18);
    after_7:
    // 0x800747AC: bne         $v0, $zero, L_800747E8
    if (ctx->r2 != 0) {
        // 0x800747B0: or          $s0, $zero, $zero
        ctx->r16 = 0 | 0;
            goto L_800747E8;
    }
    // 0x800747B0: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
L_800747B4:
    // 0x800747B4: jal         0x8006A100
    // 0x800747B8: nop

    si_mesg(rdram, ctx);
        goto after_8;
    // 0x800747B8: nop

    after_8:
    // 0x800747BC: addiu       $a1, $s0, 0x28
    ctx->r5 = ADD32(ctx->r16, 0X28);
    // 0x800747C0: sll         $t3, $s0, 3
    ctx->r11 = S32(ctx->r16 << 3);
    // 0x800747C4: addu        $a2, $s2, $t3
    ctx->r6 = ADD32(ctx->r18, ctx->r11);
    // 0x800747C8: andi        $t2, $a1, 0xFF
    ctx->r10 = ctx->r5 & 0XFF;
    // 0x800747CC: or          $a1, $t2, $zero
    ctx->r5 = ctx->r10 | 0;
    // 0x800747D0: addiu       $a2, $a2, 0xC0
    ctx->r6 = ADD32(ctx->r6, 0XC0);
    // 0x800747D4: jal         0x800CE580
    // 0x800747D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    osEepromWrite_recomp(rdram, ctx);
        goto after_9;
    // 0x800747D8: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_9:
    // 0x800747DC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x800747E0: bne         $s0, $s1, L_800747B4
    if (ctx->r16 != ctx->r17) {
        // 0x800747E4: nop
    
            goto L_800747B4;
    }
    // 0x800747E4: nop

L_800747E8:
    // 0x800747E8: jal         0x80071140
    // 0x800747EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    mempool_free(rdram, ctx);
        goto after_10;
    // 0x800747EC: or          $a0, $s2, $zero
    ctx->r4 = ctx->r18 | 0;
    after_10:
    // 0x800747F0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_800747F4:
    // 0x800747F4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800747F8: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x800747FC: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x80074800: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x80074804: jr          $ra
    // 0x80074808: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x80074808: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void obj_loop_checkpoint(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8003AD28: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x8003AD2C: jr          $ra
    // 0x8003AD30: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
    return;
    // 0x8003AD30: sw          $a1, 0x4($sp)
    MEM_W(0X4, ctx->r29) = ctx->r5;
;}
RECOMP_FUNC void npc_dialogue_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009CFEC: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x8009CFF0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009CFF4: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009CFF8: addu        $at, $at, $a0
    ctx->r1 = ADD32(ctx->r1, ctx->r4);
    // 0x8009CFFC: sw          $a0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r4;
    // 0x8009D000: jal         0x800C3400
    // 0x8009D004: sb          $zero, -0xB1C($at)
    MEM_B(-0XB1C, ctx->r1) = 0;
    textbox_visible(rdram, ctx);
        goto after_0;
    // 0x8009D004: sb          $zero, -0xB1C($at)
    MEM_B(-0XB1C, ctx->r1) = 0;
    after_0:
    // 0x8009D008: beq         $v0, $zero, L_8009D028
    if (ctx->r2 == 0) {
        // 0x8009D00C: lui         $t8, 0x800E
        ctx->r24 = S32(0X800E << 16);
            goto L_8009D028;
    }
    // 0x8009D00C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x8009D010: lw          $t7, 0x28($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X28);
    // 0x8009D014: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D018: beq         $t7, $at, L_8009D028
    if (ctx->r15 == ctx->r1) {
        // 0x8009D01C: nop
    
            goto L_8009D028;
    }
    // 0x8009D01C: nop

    // 0x8009D020: b           L_8009D108
    // 0x8009D024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009D108;
    // 0x8009D024: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009D028:
    // 0x8009D028: lb          $t8, -0xB20($t8)
    ctx->r24 = MEM_B(ctx->r24, -0XB20);
    // 0x8009D02C: lw          $t9, 0x28($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X28);
    // 0x8009D030: beq         $t8, $zero, L_8009D040
    if (ctx->r24 == 0) {
        // 0x8009D034: addiu       $at, $zero, 0x3
        ctx->r1 = ADD32(0, 0X3);
            goto L_8009D040;
    }
    // 0x8009D034: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x8009D038: b           L_8009D108
    // 0x8009D03C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
        goto L_8009D108;
    // 0x8009D03C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009D040:
    // 0x8009D040: beq         $t9, $at, L_8009D050
    if (ctx->r25 == ctx->r1) {
        // 0x8009D044: nop
    
            goto L_8009D050;
    }
    // 0x8009D044: nop

    // 0x8009D048: jal         0x8006F388
    // 0x8009D04C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    set_pause_lockout_timer(rdram, ctx);
        goto after_1;
    // 0x8009D04C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_1:
L_8009D050:
    // 0x8009D050: jal         0x8009BF20
    // 0x8009D054: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    update_controller_sticks(rdram, ctx);
        goto after_2;
    // 0x8009D054: sw          $zero, 0x24($sp)
    MEM_W(0X24, ctx->r29) = 0;
    after_2:
    // 0x8009D058: jal         0x800C5494
    // 0x8009D05C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    dialogue_clear(rdram, ctx);
        goto after_3;
    // 0x8009D05C: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_3:
    // 0x8009D060: jal         0x800C55F4
    // 0x8009D064: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    open_dialogue_box(rdram, ctx);
        goto after_4;
    // 0x8009D064: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    after_4:
    // 0x8009D068: addiu       $t0, $zero, 0x80
    ctx->r8 = ADD32(0, 0X80);
    // 0x8009D06C: sw          $t0, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r8;
    // 0x8009D070: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x8009D074: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009D078: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009D07C: jal         0x800C4FBC
    // 0x8009D080: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    set_current_dialogue_background_colour(rdram, ctx);
        goto after_5;
    // 0x8009D080: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    after_5:
    // 0x8009D084: jal         0x8001F450
    // 0x8009D088: nop

    func_8001F450(rdram, ctx);
        goto after_6;
    // 0x8009D088: nop

    after_6:
    // 0x8009D08C: lw          $t1, 0x28($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X28);
    // 0x8009D090: lw          $v1, 0x24($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X24);
    // 0x8009D094: sltiu       $at, $t1, 0x6
    ctx->r1 = ctx->r9 < 0X6 ? 1 : 0;
    // 0x8009D098: beq         $at, $zero, L_8009D104
    if (ctx->r1 == 0) {
        // 0x8009D09C: sll         $t1, $t1, 2
        ctx->r9 = S32(ctx->r9 << 2);
            goto L_8009D104;
    }
    // 0x8009D09C: sll         $t1, $t1, 2
    ctx->r9 = S32(ctx->r9 << 2);
    // 0x8009D0A0: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x8009D0A4: addu        $at, $at, $t1
    gpr jr_addend_8009D0B0 = ctx->r9;
    ctx->r1 = ADD32(ctx->r1, ctx->r9);
    // 0x8009D0A8: lw          $t1, -0x7A78($at)
    ctx->r9 = ADD32(ctx->r1, -0X7A78);
    // 0x8009D0AC: nop

    // 0x8009D0B0: jr          $t1
    // 0x8009D0B4: nop

    switch (jr_addend_8009D0B0 >> 2) {
        case 0: goto L_8009D0B8; break;
        case 1: goto L_8009D104; break;
        case 2: goto L_8009D0C8; break;
        case 3: goto L_8009D0D8; break;
        case 4: goto L_8009D0E8; break;
        case 5: goto L_8009D0F8; break;
        default: switch_error(__func__, 0x8009D0B0, 0x800E8588);
    }
    // 0x8009D0B4: nop

L_8009D0B8:
    // 0x8009D0B8: jal         0x8009D360
    // 0x8009D0BC: nop

    taj_menu_loop(rdram, ctx);
        goto after_7;
    // 0x8009D0BC: nop

    after_7:
    // 0x8009D0C0: b           L_8009D104
    // 0x8009D0C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D104;
    // 0x8009D0C4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D0C8:
    // 0x8009D0C8: jal         0x8009DB3C
    // 0x8009D0CC: nop

    tt_menu_loop(rdram, ctx);
        goto after_8;
    // 0x8009D0CC: nop

    after_8:
    // 0x8009D0D0: b           L_8009D104
    // 0x8009D0D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D104;
    // 0x8009D0D4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D0D8:
    // 0x8009D0D8: jal         0x800C3564
    // 0x8009D0DC: nop

    dialogue_challenge_loop(rdram, ctx);
        goto after_9;
    // 0x8009D0DC: nop

    after_9:
    // 0x8009D0E0: b           L_8009D104
    // 0x8009D0E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D104;
    // 0x8009D0E4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D0E8:
    // 0x8009D0E8: jal         0x8009E7E8
    // 0x8009D0EC: nop

    trophy_race_cabinet_menu_loop(rdram, ctx);
        goto after_10;
    // 0x8009D0EC: nop

    after_10:
    // 0x8009D0F0: b           L_8009D104
    // 0x8009D0F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
        goto L_8009D104;
    // 0x8009D0F4: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D0F8:
    // 0x8009D0F8: jal         0x8009D9F4
    // 0x8009D0FC: nop

    dialogue_race_defeat(rdram, ctx);
        goto after_11;
    // 0x8009D0FC: nop

    after_11:
    // 0x8009D100: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
L_8009D104:
    // 0x8009D104: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
L_8009D108:
    // 0x8009D108: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009D10C: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    // 0x8009D110: jr          $ra
    // 0x8009D114: nop

    return;
    // 0x8009D114: nop

;}
RECOMP_FUNC void pi_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80076BA0: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80076BA4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x80076BA8: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076BAC: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076BB0: addiu       $a1, $a1, 0x4238
    ctx->r5 = ADD32(ctx->r5, 0X4238);
    // 0x80076BB4: addiu       $a0, $a0, 0x4278
    ctx->r4 = ADD32(ctx->r4, 0X4278);
    // 0x80076BB8: jal         0x800C8820
    // 0x80076BBC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_0;
    // 0x80076BBC: addiu       $a2, $zero, 0x10
    ctx->r6 = ADD32(0, 0X10);
    after_0:
    // 0x80076BC0: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x80076BC4: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076BC8: addiu       $a1, $a1, 0x4218
    ctx->r5 = ADD32(ctx->r5, 0X4218);
    // 0x80076BCC: addiu       $a0, $a0, 0x4220
    ctx->r4 = ADD32(ctx->r4, 0X4220);
    // 0x80076BD0: jal         0x800C8820
    // 0x80076BD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    osCreateMesgQueue_recomp(rdram, ctx);
        goto after_1;
    // 0x80076BD4: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_1:
    // 0x80076BD8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076BDC: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x80076BE0: addiu       $a2, $a2, 0x4238
    ctx->r6 = ADD32(ctx->r6, 0X4238);
    // 0x80076BE4: addiu       $a1, $a1, 0x4278
    ctx->r5 = ADD32(ctx->r5, 0X4278);
    // 0x80076BE8: addiu       $a0, $zero, 0x96
    ctx->r4 = ADD32(0, 0X96);
    // 0x80076BEC: jal         0x800C6000
    // 0x80076BF0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    osCreatePiManager_recomp(rdram, ctx);
        goto after_2;
    // 0x80076BF0: addiu       $a3, $zero, 0x10
    ctx->r7 = ADD32(0, 0X10);
    after_2:
    // 0x80076BF4: lui         $t6, 0xF
    ctx->r14 = S32(0XF << 16);
    // 0x80076BF8: lui         $t7, 0xF
    ctx->r15 = S32(0XF << 16);
    // 0x80076BFC: addiu       $t7, $t7, -0x34A0
    ctx->r15 = ADD32(ctx->r15, -0X34A0);
    // 0x80076C00: addiu       $t6, $t6, -0x33D0
    ctx->r14 = ADD32(ctx->r14, -0X33D0);
    // 0x80076C04: subu        $v0, $t6, $t7
    ctx->r2 = SUB32(ctx->r14, ctx->r15);
    // 0x80076C08: lui         $a1, 0x7F7F
    ctx->r5 = S32(0X7F7F << 16);
    // 0x80076C0C: ori         $a1, $a1, 0x7FFF
    ctx->r5 = ctx->r5 | 0X7FFF;
    // 0x80076C10: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x80076C14: jal         0x80070C9C
    // 0x80076C18: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    mempool_alloc_safe(rdram, ctx);
        goto after_3;
    // 0x80076C18: sw          $v0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r2;
    after_3:
    // 0x80076C1C: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80076C20: addiu       $v1, $v1, 0x4290
    ctx->r3 = ADD32(ctx->r3, 0X4290);
    // 0x80076C24: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
    // 0x80076C28: jal         0x80071478
    // 0x80076C2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    mempool_locked_set(rdram, ctx);
        goto after_4;
    // 0x80076C2C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80076C30: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x80076C34: lw          $a1, 0x4290($a1)
    ctx->r5 = MEM_W(ctx->r5, 0X4290);
    // 0x80076C38: lui         $a0, 0xF
    ctx->r4 = S32(0XF << 16);
    // 0x80076C3C: lw          $a2, 0x18($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X18);
    // 0x80076C40: jal         0x80076F78
    // 0x80076C44: addiu       $a0, $a0, -0x34A0
    ctx->r4 = ADD32(ctx->r4, -0X34A0);
    dmacopy(rdram, ctx);
        goto after_5;
    // 0x80076C44: addiu       $a0, $a0, -0x34A0
    ctx->r4 = ADD32(ctx->r4, -0X34A0);
    after_5:
    // 0x80076C48: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80076C4C: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x80076C50: jr          $ra
    // 0x80076C54: nop

    return;
    // 0x80076C54: nop

;}
RECOMP_FUNC void func_8000CC20(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8000CC20: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8000CC24: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
    // 0x8000CC28: addiu       $a1, $a1, -0x51F8
    ctx->r5 = ADD32(ctx->r5, -0X51F8);
    // 0x8000CC2C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8000CC30: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
L_8000CC34:
    // 0x8000CC34: addu        $t7, $a1, $t6
    ctx->r15 = ADD32(ctx->r5, ctx->r14);
    // 0x8000CC38: lw          $t8, 0x0($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X0);
    // 0x8000CC3C: nop

    // 0x8000CC40: bne         $t8, $zero, L_8000CC50
    if (ctx->r24 != 0) {
        // 0x8000CC44: nop
    
            goto L_8000CC50;
    }
    // 0x8000CC44: nop

    // 0x8000CC48: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8000CC4C: addiu       $v0, $zero, 0x10
    ctx->r2 = ADD32(0, 0X10);
L_8000CC50:
    // 0x8000CC50: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8000CC54: slti        $at, $v0, 0x10
    ctx->r1 = SIGNED(ctx->r2) < 0X10 ? 1 : 0;
    // 0x8000CC58: bne         $at, $zero, L_8000CC34
    if (ctx->r1 != 0) {
        // 0x8000CC5C: sll         $t6, $v0, 2
        ctx->r14 = S32(ctx->r2 << 2);
            goto L_8000CC34;
    }
    // 0x8000CC5C: sll         $t6, $v0, 2
    ctx->r14 = S32(ctx->r2 << 2);
    // 0x8000CC60: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8000CC64: beq         $v1, $at, L_8000CC74
    if (ctx->r3 == ctx->r1) {
        // 0x8000CC68: sll         $t9, $v1, 2
        ctx->r25 = S32(ctx->r3 << 2);
            goto L_8000CC74;
    }
    // 0x8000CC68: sll         $t9, $v1, 2
    ctx->r25 = S32(ctx->r3 << 2);
    // 0x8000CC6C: addu        $t0, $a1, $t9
    ctx->r8 = ADD32(ctx->r5, ctx->r25);
    // 0x8000CC70: sw          $a0, 0x0($t0)
    MEM_W(0X0, ctx->r8) = ctx->r4;
L_8000CC74:
    // 0x8000CC74: jr          $ra
    // 0x8000CC78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x8000CC78: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void alSynAllocFX(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80065860: addiu       $sp, $sp, -0x20
    ctx->r29 = ADD32(ctx->r29, -0X20);
    // 0x80065864: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x80065868: sw          $a2, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r6;
    // 0x8006586C: lh          $a2, 0x26($sp)
    ctx->r6 = MEM_H(ctx->r29, 0X26);
    // 0x80065870: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80065874: sll         $s1, $a2, 2
    ctx->r17 = S32(ctx->r6 << 2);
    // 0x80065878: addu        $s1, $s1, $a2
    ctx->r17 = ADD32(ctx->r17, ctx->r6);
    // 0x8006587C: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x80065880: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x80065884: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80065888: lw          $t6, 0x34($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X34);
    // 0x8006588C: subu        $s1, $s1, $a2
    ctx->r17 = SUB32(ctx->r17, ctx->r6);
    // 0x80065890: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80065894: sll         $s1, $s1, 2
    ctx->r17 = S32(ctx->r17 << 2);
    // 0x80065898: lw          $a1, 0x28($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X28);
    // 0x8006589C: addu        $a0, $t6, $s1
    ctx->r4 = ADD32(ctx->r14, ctx->r17);
    // 0x800658A0: jal         0x80064A08
    // 0x800658A4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    alFxNew(rdram, ctx);
        goto after_0;
    // 0x800658A4: addiu       $a0, $a0, 0x20
    ctx->r4 = ADD32(ctx->r4, 0X20);
    after_0:
    // 0x800658A8: lw          $t7, 0x34($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X34);
    // 0x800658AC: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    // 0x800658B0: addu        $a2, $t7, $s1
    ctx->r6 = ADD32(ctx->r15, ctx->r17);
    // 0x800658B4: jal         0x80063F94
    // 0x800658B8: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    alFxParam(rdram, ctx);
        goto after_1;
    // 0x800658B8: addiu       $a0, $a2, 0x20
    ctx->r4 = ADD32(ctx->r6, 0X20);
    after_1:
    // 0x800658BC: lw          $t8, 0x34($s0)
    ctx->r24 = MEM_W(ctx->r16, 0X34);
    // 0x800658C0: lw          $a0, 0x30($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X30);
    // 0x800658C4: addu        $a2, $t8, $s1
    ctx->r6 = ADD32(ctx->r24, ctx->r17);
    // 0x800658C8: addiu       $a2, $a2, 0x20
    ctx->r6 = ADD32(ctx->r6, 0X20);
    // 0x800658CC: jal         0x800CC390
    // 0x800658D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    alMainBusParam(rdram, ctx);
        goto after_2;
    // 0x800658D0: addiu       $a1, $zero, 0x2
    ctx->r5 = ADD32(0, 0X2);
    after_2:
    // 0x800658D4: lw          $t9, 0x34($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X34);
    // 0x800658D8: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x800658DC: addu        $v0, $t9, $s1
    ctx->r2 = ADD32(ctx->r25, ctx->r17);
    // 0x800658E0: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800658E4: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800658E8: addiu       $sp, $sp, 0x20
    ctx->r29 = ADD32(ctx->r29, 0X20);
    // 0x800658EC: jr          $ra
    // 0x800658F0: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
    return;
    // 0x800658F0: addiu       $v0, $v0, 0x20
    ctx->r2 = ADD32(ctx->r2, 0X20);
;}
RECOMP_FUNC void menu_ghost_data_loop(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009A7D4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009A7D8: addiu       $v1, $v1, 0x63BC
    ctx->r3 = ADD32(ctx->r3, 0X63BC);
    // 0x8009A7DC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009A7E0: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009A7E4: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
    // 0x8009A7E8: lw          $v0, 0x0($t1)
    ctx->r2 = MEM_W(ctx->r9, 0X0);
    // 0x8009A7EC: addiu       $sp, $sp, -0x48
    ctx->r29 = ADD32(ctx->r29, -0X48);
    // 0x8009A7F0: addu        $t7, $t6, $a0
    ctx->r15 = ADD32(ctx->r14, ctx->r4);
    // 0x8009A7F4: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8009A7F8: andi        $t8, $t7, 0x3F
    ctx->r24 = ctx->r15 & 0X3F;
    // 0x8009A7FC: slti        $at, $v0, -0x13
    ctx->r1 = SIGNED(ctx->r2) < -0X13 ? 1 : 0;
    // 0x8009A800: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x8009A804: sw          $ra, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r31;
    // 0x8009A808: bne         $at, $zero, L_8009A834
    if (ctx->r1 != 0) {
        // 0x8009A80C: sw          $t8, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r24;
            goto L_8009A834;
    }
    // 0x8009A80C: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
    // 0x8009A810: slti        $at, $v0, 0x14
    ctx->r1 = SIGNED(ctx->r2) < 0X14 ? 1 : 0;
    // 0x8009A814: beq         $at, $zero, L_8009A834
    if (ctx->r1 == 0) {
        // 0x8009A818: nop
    
            goto L_8009A834;
    }
    // 0x8009A818: nop

    // 0x8009A81C: jal         0x80099E8C
    // 0x8009A820: nop

    ghostmenu_render(rdram, ctx);
        goto after_0;
    // 0x8009A820: nop

    after_0:
    // 0x8009A824: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009A828: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009A82C: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8009A830: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_8009A834:
    // 0x8009A834: beq         $v0, $zero, L_8009A854
    if (ctx->r2 == 0) {
        // 0x8009A838: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_8009A854;
    }
    // 0x8009A838: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x8009A83C: bgez        $v0, L_8009A850
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009A840: addu        $t2, $v0, $s0
        ctx->r10 = ADD32(ctx->r2, ctx->r16);
            goto L_8009A850;
    }
    // 0x8009A840: addu        $t2, $v0, $s0
    ctx->r10 = ADD32(ctx->r2, ctx->r16);
    // 0x8009A844: subu        $t9, $v0, $s0
    ctx->r25 = SUB32(ctx->r2, ctx->r16);
    // 0x8009A848: b           L_8009A854
    // 0x8009A84C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
        goto L_8009A854;
    // 0x8009A84C: sw          $t9, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r25;
L_8009A850:
    // 0x8009A850: sw          $t2, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r10;
L_8009A854:
    // 0x8009A854: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8009A858: lw          $t3, 0x63C4($t3)
    ctx->r11 = MEM_W(ctx->r11, 0X63C4);
    // 0x8009A85C: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x8009A860: bne         $t3, $zero, L_8009A8E4
    if (ctx->r11 != 0) {
        // 0x8009A864: or          $t0, $zero, $zero
        ctx->r8 = 0 | 0;
            goto L_8009A8E4;
    }
    // 0x8009A864: or          $t0, $zero, $zero
    ctx->r8 = 0 | 0;
    // 0x8009A868: lw          $t4, 0x0($t1)
    ctx->r12 = MEM_W(ctx->r9, 0X0);
    // 0x8009A86C: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x8009A870: bne         $t4, $zero, L_8009A8E4
    if (ctx->r12 != 0) {
        // 0x8009A874: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009A8E4;
    }
    // 0x8009A874: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009A878: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009A87C: addiu       $a1, $a1, 0x6464
    ctx->r5 = ADD32(ctx->r5, 0X6464);
    // 0x8009A880: addiu       $v1, $v1, 0x645C
    ctx->r3 = ADD32(ctx->r3, 0X645C);
L_8009A884:
    // 0x8009A884: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x8009A888: sw          $v1, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r3;
    // 0x8009A88C: sw          $a1, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r5;
    // 0x8009A890: sw          $a2, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r6;
    // 0x8009A894: sw          $a3, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r7;
    // 0x8009A898: jal         0x8006A554
    // 0x8009A89C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    input_pressed(rdram, ctx);
        goto after_1;
    // 0x8009A89C: sw          $t0, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r8;
    after_1:
    // 0x8009A8A0: lw          $v1, 0x28($sp)
    ctx->r3 = MEM_W(ctx->r29, 0X28);
    // 0x8009A8A4: lw          $a1, 0x24($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X24);
    // 0x8009A8A8: lw          $a2, 0x3C($sp)
    ctx->r6 = MEM_W(ctx->r29, 0X3C);
    // 0x8009A8AC: lw          $a3, 0x40($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X40);
    // 0x8009A8B0: lw          $t0, 0x38($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X38);
    // 0x8009A8B4: lb          $t5, 0x0($v1)
    ctx->r13 = MEM_B(ctx->r3, 0X0);
    // 0x8009A8B8: lb          $t6, 0x0($a1)
    ctx->r14 = MEM_B(ctx->r5, 0X0);
    // 0x8009A8BC: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009A8C0: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x8009A8C4: addiu       $v1, $v1, 0x1
    ctx->r3 = ADD32(ctx->r3, 0X1);
    // 0x8009A8C8: addiu       $a1, $a1, 0x1
    ctx->r5 = ADD32(ctx->r5, 0X1);
    // 0x8009A8CC: or          $a3, $a3, $v0
    ctx->r7 = ctx->r7 | ctx->r2;
    // 0x8009A8D0: addu        $a2, $a2, $t5
    ctx->r6 = ADD32(ctx->r6, ctx->r13);
    // 0x8009A8D4: bne         $s0, $at, L_8009A884
    if (ctx->r16 != ctx->r1) {
        // 0x8009A8D8: addu        $t0, $t0, $t6
        ctx->r8 = ADD32(ctx->r8, ctx->r14);
            goto L_8009A884;
    }
    // 0x8009A8D8: addu        $t0, $t0, $t6
    ctx->r8 = ADD32(ctx->r8, ctx->r14);
    // 0x8009A8DC: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x8009A8E0: addiu       $t1, $t1, -0xB84
    ctx->r9 = ADD32(ctx->r9, -0XB84);
L_8009A8E4:
    // 0x8009A8E4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009A8E8: addiu       $a2, $a2, 0x63E0
    ctx->r6 = ADD32(ctx->r6, 0X63E0);
    // 0x8009A8EC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x8009A8F0: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009A8F4: beq         $v0, $zero, L_8009A920
    if (ctx->r2 == 0) {
        // 0x8009A8F8: nop
    
            goto L_8009A920;
    }
    // 0x8009A8F8: nop

    // 0x8009A8FC: beq         $v0, $v1, L_8009AA38
    if (ctx->r2 == ctx->r3) {
        // 0x8009A900: andi        $t3, $a3, 0x4000
        ctx->r11 = ctx->r7 & 0X4000;
            goto L_8009AA38;
    }
    // 0x8009A900: andi        $t3, $a3, 0x4000
    ctx->r11 = ctx->r7 & 0X4000;
    // 0x8009A904: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009A908: beq         $v0, $at, L_8009AB38
    if (ctx->r2 == ctx->r1) {
        // 0x8009A90C: andi        $t8, $a3, 0xD000
        ctx->r24 = ctx->r7 & 0XD000;
            goto L_8009AB38;
    }
    // 0x8009A90C: andi        $t8, $a3, 0xD000
    ctx->r24 = ctx->r7 & 0XD000;
    // 0x8009A910: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009A914: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8009A918: b           L_8009AB74
    // 0x8009A91C: nop

        goto L_8009AB74;
    // 0x8009A91C: nop

L_8009A920:
    // 0x8009A920: andi        $v0, $a3, 0x9000
    ctx->r2 = ctx->r7 & 0X9000;
    // 0x8009A924: beq         $v0, $zero, L_8009A954
    if (ctx->r2 == 0) {
        // 0x8009A928: lui         $a1, 0x8012
        ctx->r5 = S32(0X8012 << 16);
            goto L_8009A954;
    }
    // 0x8009A928: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009A92C: addiu       $a1, $a1, 0x64D4
    ctx->r5 = ADD32(ctx->r5, 0X64D4);
    // 0x8009A930: lw          $t7, 0x0($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X0);
    // 0x8009A934: addiu       $t8, $zero, 0x2
    ctx->r24 = ADD32(0, 0X2);
    // 0x8009A938: blez        $t7, L_8009A954
    if (SIGNED(ctx->r15) <= 0) {
        // 0x8009A93C: addiu       $a0, $zero, 0xEF
        ctx->r4 = ADD32(0, 0XEF);
            goto L_8009A954;
    }
    // 0x8009A93C: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009A940: sw          $t8, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r24;
    // 0x8009A944: jal         0x80001D04
    // 0x8009A948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_2;
    // 0x8009A948: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_2:
    // 0x8009A94C: b           L_8009AA28
    // 0x8009A950: nop

        goto L_8009AA28;
    // 0x8009A950: nop

L_8009A954:
    // 0x8009A954: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009A958: andi        $t9, $a3, 0x4000
    ctx->r25 = ctx->r7 & 0X4000;
    // 0x8009A95C: bne         $t9, $zero, L_8009A978
    if (ctx->r25 != 0) {
        // 0x8009A960: addiu       $a1, $a1, 0x64D4
        ctx->r5 = ADD32(ctx->r5, 0X64D4);
            goto L_8009A978;
    }
    // 0x8009A960: addiu       $a1, $a1, 0x64D4
    ctx->r5 = ADD32(ctx->r5, 0X64D4);
    // 0x8009A964: beq         $v0, $zero, L_8009A9A0
    if (ctx->r2 == 0) {
        // 0x8009A968: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8009A9A0;
    }
    // 0x8009A968: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009A96C: lw          $t2, 0x0($a1)
    ctx->r10 = MEM_W(ctx->r5, 0X0);
    // 0x8009A970: nop

    // 0x8009A974: bne         $t2, $zero, L_8009A9A0
    if (ctx->r10 != 0) {
        // 0x8009A978: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8009A9A0;
    }
L_8009A978:
    // 0x8009A978: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009A97C: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009A980: sw          $v1, 0x0($t1)
    MEM_W(0X0, ctx->r9) = ctx->r3;
    // 0x8009A984: jal         0x800C01D8
    // 0x8009A988: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_3;
    // 0x8009A988: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_3:
    // 0x8009A98C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009A990: jal         0x80001D04
    // 0x8009A994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_4;
    // 0x8009A994: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_4:
    // 0x8009A998: b           L_8009AA28
    // 0x8009A99C: nop

        goto L_8009AA28;
    // 0x8009A99C: nop

L_8009A9A0:
    // 0x8009A9A0: addiu       $s0, $s0, 0x6498
    ctx->r16 = ADD32(ctx->r16, 0X6498);
    // 0x8009A9A4: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009A9A8: bgez        $t0, L_8009A9EC
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009A9AC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_8009A9EC;
    }
    // 0x8009A9AC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x8009A9B0: lw          $t3, 0x0($a1)
    ctx->r11 = MEM_W(ctx->r5, 0X0);
    // 0x8009A9B4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009A9B8: addiu       $t4, $t3, -0x1
    ctx->r12 = ADD32(ctx->r11, -0X1);
    // 0x8009A9BC: slt         $at, $v0, $t4
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r12) ? 1 : 0;
    // 0x8009A9C0: beq         $at, $zero, L_8009A9EC
    if (ctx->r1 == 0) {
        // 0x8009A9C4: addiu       $v1, $v1, 0x63D8
        ctx->r3 = ADD32(ctx->r3, 0X63D8);
            goto L_8009A9EC;
    }
    // 0x8009A9C4: addiu       $v1, $v1, 0x63D8
    ctx->r3 = ADD32(ctx->r3, 0X63D8);
    // 0x8009A9C8: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009A9CC: addiu       $t5, $v0, 0x1
    ctx->r13 = ADD32(ctx->r2, 0X1);
    // 0x8009A9D0: addiu       $t7, $t6, 0x3
    ctx->r15 = ADD32(ctx->r14, 0X3);
    // 0x8009A9D4: slt         $at, $t5, $t7
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8009A9D8: sw          $t5, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r13;
    // 0x8009A9DC: bne         $at, $zero, L_8009A9EC
    if (ctx->r1 != 0) {
        // 0x8009A9E0: or          $v0, $t5, $zero
        ctx->r2 = ctx->r13 | 0;
            goto L_8009A9EC;
    }
    // 0x8009A9E0: or          $v0, $t5, $zero
    ctx->r2 = ctx->r13 | 0;
    // 0x8009A9E4: addiu       $t8, $t5, -0x2
    ctx->r24 = ADD32(ctx->r13, -0X2);
    // 0x8009A9E8: sw          $t8, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r24;
L_8009A9EC:
    // 0x8009A9EC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009A9F0: blez        $t0, L_8009AA18
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8009A9F4: addiu       $v1, $v1, 0x63D8
        ctx->r3 = ADD32(ctx->r3, 0X63D8);
            goto L_8009AA18;
    }
    // 0x8009A9F4: addiu       $v1, $v1, 0x63D8
    ctx->r3 = ADD32(ctx->r3, 0X63D8);
    // 0x8009A9F8: blez        $v0, L_8009AA18
    if (SIGNED(ctx->r2) <= 0) {
        // 0x8009A9FC: addiu       $t9, $v0, -0x1
        ctx->r25 = ADD32(ctx->r2, -0X1);
            goto L_8009AA18;
    }
    // 0x8009A9FC: addiu       $t9, $v0, -0x1
    ctx->r25 = ADD32(ctx->r2, -0X1);
    // 0x8009AA00: lw          $t2, 0x0($v1)
    ctx->r10 = MEM_W(ctx->r3, 0X0);
    // 0x8009AA04: sw          $t9, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r25;
    // 0x8009AA08: slt         $at, $t9, $t2
    ctx->r1 = SIGNED(ctx->r25) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x8009AA0C: beq         $at, $zero, L_8009AA18
    if (ctx->r1 == 0) {
        // 0x8009AA10: or          $v0, $t9, $zero
        ctx->r2 = ctx->r25 | 0;
            goto L_8009AA18;
    }
    // 0x8009AA10: or          $v0, $t9, $zero
    ctx->r2 = ctx->r25 | 0;
    // 0x8009AA14: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
L_8009AA18:
    // 0x8009AA18: beq         $a0, $v0, L_8009AA28
    if (ctx->r4 == ctx->r2) {
        // 0x8009AA1C: or          $a1, $zero, $zero
        ctx->r5 = 0 | 0;
            goto L_8009AA28;
    }
    // 0x8009AA1C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    // 0x8009AA20: jal         0x80001D04
    // 0x8009AA24: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    sound_play(rdram, ctx);
        goto after_5;
    // 0x8009AA24: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    after_5:
L_8009AA28:
    // 0x8009AA28: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009AA2C: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8009AA30: b           L_8009AB74
    // 0x8009AA34: nop

        goto L_8009AB74;
    // 0x8009AA34: nop

L_8009AA38:
    // 0x8009AA38: beq         $t3, $zero, L_8009AA58
    if (ctx->r11 == 0) {
        // 0x8009AA3C: andi        $t4, $a3, 0x9000
        ctx->r12 = ctx->r7 & 0X9000;
            goto L_8009AA58;
    }
    // 0x8009AA3C: andi        $t4, $a3, 0x9000
    ctx->r12 = ctx->r7 & 0X9000;
    // 0x8009AA40: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8009AA44: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009AA48: jal         0x80001D04
    // 0x8009AA4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_6;
    // 0x8009AA4C: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_6:
    // 0x8009AA50: b           L_8009AB28
    // 0x8009AA54: nop

        goto L_8009AB28;
    // 0x8009AA54: nop

L_8009AA58:
    // 0x8009AA58: beq         $t4, $zero, L_8009AB10
    if (ctx->r12 == 0) {
        // 0x8009AA5C: lui         $s0, 0x8012
        ctx->r16 = S32(0X8012 << 16);
            goto L_8009AB10;
    }
    // 0x8009AA5C: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8009AA60: addiu       $s0, $s0, 0x6498
    ctx->r16 = ADD32(ctx->r16, 0X6498);
    // 0x8009AA64: lw          $a0, 0x0($s0)
    ctx->r4 = MEM_W(ctx->r16, 0X0);
    // 0x8009AA68: jal         0x800998E0
    // 0x8009AA6C: nop

    ghostmenu_erase(rdram, ctx);
        goto after_7;
    // 0x8009AA6C: nop

    after_7:
    // 0x8009AA70: bne         $v0, $zero, L_8009AAE0
    if (ctx->r2 != 0) {
        // 0x8009AA74: addiu       $v1, $zero, 0x1
        ctx->r3 = ADD32(0, 0X1);
            goto L_8009AAE0;
    }
    // 0x8009AA74: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
    // 0x8009AA78: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8009AA7C: addiu       $a1, $a1, 0x64D4
    ctx->r5 = ADD32(ctx->r5, 0X64D4);
    // 0x8009AA80: lw          $v1, 0x0($a1)
    ctx->r3 = MEM_W(ctx->r5, 0X0);
    // 0x8009AA84: lw          $v0, 0x0($s0)
    ctx->r2 = MEM_W(ctx->r16, 0X0);
    // 0x8009AA88: addiu       $a0, $zero, 0xEF
    ctx->r4 = ADD32(0, 0XEF);
    // 0x8009AA8C: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8009AA90: bne         $at, $zero, L_8009AAA0
    if (ctx->r1 != 0) {
        // 0x8009AA94: nop
    
            goto L_8009AAA0;
    }
    // 0x8009AA94: nop

    // 0x8009AA98: addiu       $v0, $v1, -0x1
    ctx->r2 = ADD32(ctx->r3, -0X1);
    // 0x8009AA9C: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
L_8009AAA0:
    // 0x8009AAA0: bgez        $v0, L_8009AAB0
    if (SIGNED(ctx->r2) >= 0) {
        // 0x8009AAA4: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_8009AAB0;
    }
    // 0x8009AAA4: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8009AAA8: sw          $zero, 0x0($s0)
    MEM_W(0X0, ctx->r16) = 0;
    // 0x8009AAAC: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8009AAB0:
    // 0x8009AAB0: addiu       $v1, $v1, 0x63D8
    ctx->r3 = ADD32(ctx->r3, 0X63D8);
    // 0x8009AAB4: lw          $t6, 0x0($v1)
    ctx->r14 = MEM_W(ctx->r3, 0X0);
    // 0x8009AAB8: nop

    // 0x8009AABC: slt         $at, $v0, $t6
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8009AAC0: beq         $at, $zero, L_8009AACC
    if (ctx->r1 == 0) {
        // 0x8009AAC4: nop
    
            goto L_8009AACC;
    }
    // 0x8009AAC4: nop

    // 0x8009AAC8: sw          $v0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r2;
L_8009AACC:
    // 0x8009AACC: jal         0x80001D04
    // 0x8009AAD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_8;
    // 0x8009AAD0: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_8:
    // 0x8009AAD4: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009AAD8: b           L_8009AB08
    // 0x8009AADC: addiu       $a2, $a2, 0x63E0
    ctx->r6 = ADD32(ctx->r6, 0X63E0);
        goto L_8009AB08;
    // 0x8009AADC: addiu       $a2, $a2, 0x63E0
    ctx->r6 = ADD32(ctx->r6, 0X63E0);
L_8009AAE0:
    // 0x8009AAE0: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009AAE4: lui         $a0, 0x800E
    ctx->r4 = S32(0X800E << 16);
    // 0x8009AAE8: sw          $v1, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = ctx->r3;
    // 0x8009AAEC: jal         0x800C01D8
    // 0x8009AAF0: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    transition_begin(rdram, ctx);
        goto after_9;
    // 0x8009AAF0: addiu       $a0, $a0, -0x88C
    ctx->r4 = ADD32(ctx->r4, -0X88C);
    after_9:
    // 0x8009AAF4: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009AAF8: jal         0x80001D04
    // 0x8009AAFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_10;
    // 0x8009AAFC: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_10:
    // 0x8009AB00: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8009AB04: addiu       $a2, $a2, 0x63E0
    ctx->r6 = ADD32(ctx->r6, 0X63E0);
L_8009AB08:
    // 0x8009AB08: b           L_8009AB28
    // 0x8009AB0C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
        goto L_8009AB28;
    // 0x8009AB0C: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
L_8009AB10:
    // 0x8009AB10: bgez        $t0, L_8009AB28
    if (SIGNED(ctx->r8) >= 0) {
        // 0x8009AB14: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_8009AB28;
    }
    // 0x8009AB14: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x8009AB18: sw          $t7, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r15;
    // 0x8009AB1C: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8009AB20: jal         0x80001D04
    // 0x8009AB24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_11;
    // 0x8009AB24: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_11:
L_8009AB28:
    // 0x8009AB28: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009AB2C: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8009AB30: b           L_8009AB74
    // 0x8009AB34: nop

        goto L_8009AB74;
    // 0x8009AB34: nop

L_8009AB38:
    // 0x8009AB38: beq         $t8, $zero, L_8009AB54
    if (ctx->r24 == 0) {
        // 0x8009AB3C: addiu       $a0, $zero, 0x241
        ctx->r4 = ADD32(0, 0X241);
            goto L_8009AB54;
    }
    // 0x8009AB3C: addiu       $a0, $zero, 0x241
    ctx->r4 = ADD32(0, 0X241);
    // 0x8009AB40: sw          $zero, 0x0($a2)
    MEM_W(0X0, ctx->r6) = 0;
    // 0x8009AB44: jal         0x80001D04
    // 0x8009AB48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_12;
    // 0x8009AB48: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_12:
    // 0x8009AB4C: b           L_8009AB68
    // 0x8009AB50: nop

        goto L_8009AB68;
    // 0x8009AB50: nop

L_8009AB54:
    // 0x8009AB54: blez        $t0, L_8009AB68
    if (SIGNED(ctx->r8) <= 0) {
        // 0x8009AB58: addiu       $a0, $zero, 0xEB
        ctx->r4 = ADD32(0, 0XEB);
            goto L_8009AB68;
    }
    // 0x8009AB58: addiu       $a0, $zero, 0xEB
    ctx->r4 = ADD32(0, 0XEB);
    // 0x8009AB5C: sw          $v1, 0x0($a2)
    MEM_W(0X0, ctx->r6) = ctx->r3;
    // 0x8009AB60: jal         0x80001D04
    // 0x8009AB64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    sound_play(rdram, ctx);
        goto after_13;
    // 0x8009AB64: or          $a1, $zero, $zero
    ctx->r5 = 0 | 0;
    after_13:
L_8009AB68:
    // 0x8009AB68: lui         $v0, 0x800E
    ctx->r2 = S32(0X800E << 16);
    // 0x8009AB6C: lw          $v0, -0xB84($v0)
    ctx->r2 = MEM_W(ctx->r2, -0XB84);
    // 0x8009AB70: nop

L_8009AB74:
    // 0x8009AB74: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009AB78: sw          $zero, 0x63C4($at)
    MEM_W(0X63C4, ctx->r1) = 0;
    // 0x8009AB7C: slti        $at, $v0, 0x1F
    ctx->r1 = SIGNED(ctx->r2) < 0X1F ? 1 : 0;
    // 0x8009AB80: bne         $at, $zero, L_8009AB9C
    if (ctx->r1 != 0) {
        // 0x8009AB84: lw          $ra, 0x1C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X1C);
            goto L_8009AB9C;
    }
    // 0x8009AB84: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
    // 0x8009AB88: jal         0x8009ABAC
    // 0x8009AB8C: nop

    ghostmenu_free(rdram, ctx);
        goto after_14;
    // 0x8009AB8C: nop

    after_14:
    // 0x8009AB90: jal         0x800813D0
    // 0x8009AB94: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    menu_init(rdram, ctx);
        goto after_15;
    // 0x8009AB94: addiu       $a0, $zero, 0xE
    ctx->r4 = ADD32(0, 0XE);
    after_15:
    // 0x8009AB98: lw          $ra, 0x1C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X1C);
L_8009AB9C:
    // 0x8009AB9C: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8009ABA0: addiu       $sp, $sp, 0x48
    ctx->r29 = ADD32(ctx->r29, 0X48);
    // 0x8009ABA4: jr          $ra
    // 0x8009ABA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    return;
    // 0x8009ABA8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
;}
RECOMP_FUNC void wavegen_add(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800BF524: addiu       $sp, $sp, -0x30
    ctx->r29 = ADD32(ctx->r29, -0X30);
    // 0x800BF528: sw          $ra, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r31;
    // 0x800BF52C: lw          $v0, 0x3C($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X3C);
    // 0x800BF530: lui         $at, 0x3FB0
    ctx->r1 = S32(0X3FB0 << 16);
    // 0x800BF534: lbu         $t6, 0x10($v0)
    ctx->r14 = MEM_BU(ctx->r2, 0X10);
    // 0x800BF538: mtc1        $at, $f1
    ctx->f_odd[(1 - 1) * 2] = ctx->r1;
    // 0x800BF53C: beq         $t6, $zero, L_800BF548
    if (ctx->r14 == 0) {
        // 0x800BF540: or          $v1, $zero, $zero
        ctx->r3 = 0 | 0;
            goto L_800BF548;
    }
    // 0x800BF540: or          $v1, $zero, $zero
    ctx->r3 = 0 | 0;
    // 0x800BF544: addiu       $v1, $zero, 0x1
    ctx->r3 = ADD32(0, 0X1);
L_800BF548:
    // 0x800BF548: lbu         $t7, 0x11($v0)
    ctx->r15 = MEM_BU(ctx->r2, 0X11);
    // 0x800BF54C: mtc1        $zero, $f0
    ctx->f0.u32l = 0;
    // 0x800BF550: beq         $t7, $zero, L_800BF55C
    if (ctx->r15 == 0) {
        // 0x800BF554: ori         $t8, $v1, 0x2
        ctx->r24 = ctx->r3 | 0X2;
            goto L_800BF55C;
    }
    // 0x800BF554: ori         $t8, $v1, 0x2
    ctx->r24 = ctx->r3 | 0X2;
    // 0x800BF558: or          $v1, $t8, $zero
    ctx->r3 = ctx->r24 | 0;
L_800BF55C:
    // 0x800BF55C: lhu         $t9, 0xA($v0)
    ctx->r25 = MEM_HU(ctx->r2, 0XA);
    // 0x800BF560: lw          $a1, 0xC($a0)
    ctx->r5 = MEM_W(ctx->r4, 0XC);
    // 0x800BF564: mtc1        $t9, $f4
    ctx->f4.u32l = ctx->r25;
    // 0x800BF568: lw          $a2, 0x14($a0)
    ctx->r6 = MEM_W(ctx->r4, 0X14);
    // 0x800BF56C: bgez        $t9, L_800BF584
    if (SIGNED(ctx->r25) >= 0) {
        // 0x800BF570: cvt.s.w     $f4, $f4
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
            goto L_800BF584;
    }
    // 0x800BF570: cvt.s.w     $f4, $f4
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    ctx->f4.fl = CVT_S_W(ctx->f4.u32l);
    // 0x800BF574: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BF578: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BF57C: nop

    // 0x800BF580: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800BF584:
    // 0x800BF584: lbu         $t0, 0x9($v0)
    ctx->r8 = MEM_BU(ctx->r2, 0X9);
    // 0x800BF588: mfc1        $a3, $f4
    ctx->r7 = (int32_t)ctx->f4.u32l;
    // 0x800BF58C: sll         $t1, $t0, 8
    ctx->r9 = S32(ctx->r8 << 8);
    // 0x800BF590: sw          $t1, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r9;
    // 0x800BF594: lbu         $t2, 0x8($v0)
    ctx->r10 = MEM_BU(ctx->r2, 0X8);
    // 0x800BF598: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BF59C: mtc1        $t2, $f8
    ctx->f8.u32l = ctx->r10;
    // 0x800BF5A0: bgez        $t2, L_800BF5B4
    if (SIGNED(ctx->r10) >= 0) {
        // 0x800BF5A4: cvt.s.w     $f10, $f8
        CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BF5B4;
    }
    // 0x800BF5A4: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BF5A8: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800BF5AC: nop

    // 0x800BF5B0: add.s       $f10, $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f10.fl + ctx->f16.fl;
L_800BF5B4:
    // 0x800BF5B4: cvt.d.s     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.fl); 
    ctx->f18.d = CVT_D_S(ctx->f10.fl);
    // 0x800BF5B8: mul.d       $f4, $f18, $f0
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f18.d); NAN_CHECK(ctx->f0.d); 
    ctx->f4.d = MUL_D(ctx->f18.d, ctx->f0.d);
    // 0x800BF5BC: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BF5C0: cvt.s.d     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.d); 
    ctx->f6.fl = CVT_S_D(ctx->f4.d);
    // 0x800BF5C4: swc1        $f6, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f6.u32l;
    // 0x800BF5C8: lhu         $t3, 0xE($v0)
    ctx->r11 = MEM_HU(ctx->r2, 0XE);
    // 0x800BF5CC: nop

    // 0x800BF5D0: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800BF5D4: bgez        $t3, L_800BF5E8
    if (SIGNED(ctx->r11) >= 0) {
        // 0x800BF5D8: cvt.s.w     $f16, $f8
        CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
            goto L_800BF5E8;
    }
    // 0x800BF5D8: cvt.s.w     $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    ctx->f16.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800BF5DC: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x800BF5E0: nop

    // 0x800BF5E4: add.s       $f16, $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f10.fl;
L_800BF5E8:
    // 0x800BF5E8: swc1        $f16, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f16.u32l;
    // 0x800BF5EC: lhu         $t4, 0xC($v0)
    ctx->r12 = MEM_HU(ctx->r2, 0XC);
    // 0x800BF5F0: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x800BF5F4: mtc1        $t4, $f18
    ctx->f18.u32l = ctx->r12;
    // 0x800BF5F8: bgez        $t4, L_800BF60C
    if (SIGNED(ctx->r12) >= 0) {
        // 0x800BF5FC: cvt.s.w     $f4, $f18
        CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
            goto L_800BF60C;
    }
    // 0x800BF5FC: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x800BF600: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x800BF604: nop

    // 0x800BF608: add.s       $f4, $f4, $f6
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f4.fl = ctx->f4.fl + ctx->f6.fl;
L_800BF60C:
    // 0x800BF60C: cvt.d.s     $f8, $f4
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f4.fl); 
    ctx->f8.d = CVT_D_S(ctx->f4.fl);
    // 0x800BF610: mul.d       $f10, $f8, $f0
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f8.d); NAN_CHECK(ctx->f0.d); 
    ctx->f10.d = MUL_D(ctx->f8.d, ctx->f0.d);
    // 0x800BF614: sw          $v1, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r3;
    // 0x800BF618: cvt.s.d     $f16, $f10
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f10.d); 
    ctx->f16.fl = CVT_S_D(ctx->f10.d);
    // 0x800BF61C: jal         0x800BF634
    // 0x800BF620: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    wavegen_register(rdram, ctx);
        goto after_0;
    // 0x800BF620: swc1        $f16, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f16.u32l;
    after_0:
    // 0x800BF624: lw          $ra, 0x2C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X2C);
    // 0x800BF628: addiu       $sp, $sp, 0x30
    ctx->r29 = ADD32(ctx->r29, 0X30);
    // 0x800BF62C: jr          $ra
    // 0x800BF630: nop

    return;
    // 0x800BF630: nop

;}
RECOMP_FUNC void init_racer_headers(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006E5BC: addiu       $sp, $sp, -0x38
    ctx->r29 = ADD32(ctx->r29, -0X38);
    // 0x8006E5C0: sw          $ra, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r31;
    // 0x8006E5C4: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8006E5C8: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8006E5CC: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8006E5D0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8006E5D4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8006E5D8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8006E5DC: jal         0x8009C3C8
    // 0x8006E5E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    get_number_of_active_players(rdram, ctx);
        goto after_0;
    // 0x8006E5E0: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    after_0:
    // 0x8006E5E4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8006E5E8: addiu       $s0, $s0, 0x3510
    ctx->r16 = ADD32(ctx->r16, 0X3510);
    // 0x8006E5EC: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006E5F0: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8006E5F4: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8006E5F8: addiu       $s6, $zero, 0x7
    ctx->r22 = ADD32(0, 0X7);
    // 0x8006E5FC: addiu       $s5, $zero, 0x5
    ctx->r21 = ADD32(0, 0X5);
    // 0x8006E600: addiu       $s4, $zero, 0x8
    ctx->r20 = ADD32(0, 0X8);
    // 0x8006E604: addiu       $s2, $zero, 0x6
    ctx->r18 = ADD32(0, 0X6);
    // 0x8006E608: sb          $v0, 0x4A($t6)
    MEM_B(0X4A, ctx->r14) = ctx->r2;
L_8006E60C:
    // 0x8006E60C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006E610: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8006E614: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8006E618: jal         0x8009C228
    // 0x8006E61C: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    get_character_id_from_slot(rdram, ctx);
        goto after_1;
    // 0x8006E61C: sb          $zero, 0x58($t8)
    MEM_B(0X58, ctx->r24) = 0;
    after_1:
    // 0x8006E620: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006E624: nop

    // 0x8006E628: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x8006E62C: sb          $v0, 0x59($t0)
    MEM_B(0X59, ctx->r8) = ctx->r2;
    // 0x8006E630: lw          $v1, 0x0($s0)
    ctx->r3 = MEM_W(ctx->r16, 0X0);
    // 0x8006E634: nop

    // 0x8006E638: lbu         $t1, 0x4A($v1)
    ctx->r9 = MEM_BU(ctx->r3, 0X4A);
    // 0x8006E63C: addu        $t2, $v1, $s3
    ctx->r10 = ADD32(ctx->r3, ctx->r19);
    // 0x8006E640: slti        $at, $t1, 0x2
    ctx->r1 = SIGNED(ctx->r9) < 0X2 ? 1 : 0;
    // 0x8006E644: bne         $at, $zero, L_8006E654
    if (ctx->r1 != 0) {
        // 0x8006E648: nop
    
            goto L_8006E654;
    }
    // 0x8006E648: nop

    // 0x8006E64C: b           L_8006E688
    // 0x8006E650: sb          $s1, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = ctx->r17;
        goto L_8006E688;
    // 0x8006E650: sb          $s1, 0x5A($t2)
    MEM_B(0X5A, ctx->r10) = ctx->r17;
L_8006E654:
    // 0x8006E654: jal         0x8009EC80
    // 0x8006E658: nop

    is_in_two_player_adventure(rdram, ctx);
        goto after_2;
    // 0x8006E658: nop

    after_2:
    // 0x8006E65C: beq         $v0, $zero, L_8006E678
    if (ctx->r2 == 0) {
        // 0x8006E660: nop
    
            goto L_8006E678;
    }
    // 0x8006E660: nop

    // 0x8006E664: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006E668: subu        $t3, $s5, $s1
    ctx->r11 = SUB32(ctx->r21, ctx->r17);
    // 0x8006E66C: addu        $t5, $t4, $s3
    ctx->r13 = ADD32(ctx->r12, ctx->r19);
    // 0x8006E670: b           L_8006E688
    // 0x8006E674: sb          $t3, 0x5A($t5)
    MEM_B(0X5A, ctx->r13) = ctx->r11;
        goto L_8006E688;
    // 0x8006E674: sb          $t3, 0x5A($t5)
    MEM_B(0X5A, ctx->r13) = ctx->r11;
L_8006E678:
    // 0x8006E678: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006E67C: subu        $t6, $s6, $s1
    ctx->r14 = SUB32(ctx->r22, ctx->r17);
    // 0x8006E680: addu        $t8, $t7, $s3
    ctx->r24 = ADD32(ctx->r15, ctx->r19);
    // 0x8006E684: sb          $t6, 0x5A($t8)
    MEM_B(0X5A, ctx->r24) = ctx->r14;
L_8006E688:
    // 0x8006E688: lw          $t9, 0x0($s0)
    ctx->r25 = MEM_W(ctx->r16, 0X0);
    // 0x8006E68C: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006E690: addu        $t0, $t9, $s3
    ctx->r8 = ADD32(ctx->r25, ctx->r19);
    // 0x8006E694: sb          $zero, 0x5B($t0)
    MEM_B(0X5B, ctx->r8) = 0;
L_8006E698:
    // 0x8006E698: sll         $t2, $s1, 2
    ctx->r10 = S32(ctx->r17 << 2);
    // 0x8006E69C: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8006E6A0: subu        $t2, $t2, $s1
    ctx->r10 = SUB32(ctx->r10, ctx->r17);
    // 0x8006E6A4: sll         $t2, $t2, 3
    ctx->r10 = S32(ctx->r10 << 3);
    // 0x8006E6A8: addu        $t4, $t1, $t2
    ctx->r12 = ADD32(ctx->r9, ctx->r10);
    // 0x8006E6AC: addu        $t3, $t4, $v0
    ctx->r11 = ADD32(ctx->r12, ctx->r2);
    // 0x8006E6B0: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8006E6B4: slti        $at, $v0, 0x8
    ctx->r1 = SIGNED(ctx->r2) < 0X8 ? 1 : 0;
    // 0x8006E6B8: bne         $at, $zero, L_8006E698
    if (ctx->r1 != 0) {
        // 0x8006E6BC: sh          $zero, 0x5C($t3)
        MEM_H(0X5C, ctx->r11) = 0;
            goto L_8006E698;
    }
    // 0x8006E6BC: sh          $zero, 0x5C($t3)
    MEM_H(0X5C, ctx->r11) = 0;
    // 0x8006E6C0: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006E6C4: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
    // 0x8006E6C8: addu        $t7, $t5, $s3
    ctx->r15 = ADD32(ctx->r13, ctx->r19);
    // 0x8006E6CC: sh          $zero, 0x64($t7)
    MEM_H(0X64, ctx->r15) = 0;
L_8006E6D0:
    // 0x8006E6D0: sll         $t8, $s1, 2
    ctx->r24 = S32(ctx->r17 << 2);
    // 0x8006E6D4: lw          $t6, 0x0($s0)
    ctx->r14 = MEM_W(ctx->r16, 0X0);
    // 0x8006E6D8: subu        $t8, $t8, $s1
    ctx->r24 = SUB32(ctx->r24, ctx->r17);
    // 0x8006E6DC: sll         $t8, $t8, 3
    ctx->r24 = S32(ctx->r24 << 3);
    // 0x8006E6E0: addu        $t9, $t6, $t8
    ctx->r25 = ADD32(ctx->r14, ctx->r24);
    // 0x8006E6E4: addu        $t0, $t9, $v0
    ctx->r8 = ADD32(ctx->r25, ctx->r2);
    // 0x8006E6E8: addiu       $v0, $v0, 0x2
    ctx->r2 = ADD32(ctx->r2, 0X2);
    // 0x8006E6EC: bne         $v0, $s2, L_8006E6D0
    if (ctx->r2 != ctx->r18) {
        // 0x8006E6F0: sh          $zero, 0x66($t0)
        MEM_H(0X66, ctx->r8) = 0;
            goto L_8006E6D0;
    }
    // 0x8006E6F0: sh          $zero, 0x66($t0)
    MEM_H(0X66, ctx->r8) = 0;
    // 0x8006E6F4: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x8006E6F8: bne         $s1, $s4, L_8006E60C
    if (ctx->r17 != ctx->r20) {
        // 0x8006E6FC: addiu       $s3, $s3, 0x18
        ctx->r19 = ADD32(ctx->r19, 0X18);
            goto L_8006E60C;
    }
    // 0x8006E6FC: addiu       $s3, $s3, 0x18
    ctx->r19 = ADD32(ctx->r19, 0X18);
    // 0x8006E700: lw          $t1, 0x0($s0)
    ctx->r9 = MEM_W(ctx->r16, 0X0);
    // 0x8006E704: nop

    // 0x8006E708: sb          $zero, 0x114($t1)
    MEM_B(0X114, ctx->r9) = 0;
    // 0x8006E70C: lw          $t2, 0x0($s0)
    ctx->r10 = MEM_W(ctx->r16, 0X0);
    // 0x8006E710: nop

    // 0x8006E714: sb          $zero, 0x115($t2)
    MEM_B(0X115, ctx->r10) = 0;
    // 0x8006E718: lw          $t4, 0x0($s0)
    ctx->r12 = MEM_W(ctx->r16, 0X0);
    // 0x8006E71C: nop

    // 0x8006E720: sb          $zero, 0x116($t4)
    MEM_B(0X116, ctx->r12) = 0;
    // 0x8006E724: lw          $t3, 0x0($s0)
    ctx->r11 = MEM_W(ctx->r16, 0X0);
    // 0x8006E728: nop

    // 0x8006E72C: sb          $zero, 0x117($t3)
    MEM_B(0X117, ctx->r11) = 0;
    // 0x8006E730: lw          $t5, 0x0($s0)
    ctx->r13 = MEM_W(ctx->r16, 0X0);
    // 0x8006E734: nop

    // 0x8006E738: sb          $zero, 0x48($t5)
    MEM_B(0X48, ctx->r13) = 0;
    // 0x8006E73C: lw          $t7, 0x0($s0)
    ctx->r15 = MEM_W(ctx->r16, 0X0);
    // 0x8006E740: nop

    // 0x8006E744: sb          $zero, 0x49($t7)
    MEM_B(0X49, ctx->r15) = 0;
    // 0x8006E748: lw          $ra, 0x34($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X34);
    // 0x8006E74C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8006E750: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8006E754: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8006E758: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8006E75C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8006E760: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8006E764: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8006E768: jr          $ra
    // 0x8006E76C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
    return;
    // 0x8006E76C: addiu       $sp, $sp, 0x38
    ctx->r29 = ADD32(ctx->r29, 0X38);
;}
RECOMP_FUNC void optionscreen_free(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80084734: addiu       $sp, $sp, -0x18
    ctx->r29 = ADD32(ctx->r29, -0X18);
    // 0x80084738: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x8008473C: jal         0x800C422C
    // 0x80084740: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    unload_font(rdram, ctx);
        goto after_0;
    // 0x80084740: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_0:
    // 0x80084744: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
    // 0x80084748: addiu       $sp, $sp, 0x18
    ctx->r29 = ADD32(ctx->r29, 0X18);
    // 0x8008474C: jr          $ra
    // 0x80084750: nop

    return;
    // 0x80084750: nop

;}
RECOMP_FUNC void audspat_reverb_get_strength_at_point(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009D6C: addiu       $sp, $sp, -0x98
    ctx->r29 = ADD32(ctx->r29, -0X98);
    // 0x80009D70: swc1        $f24, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->f24.u32l;
    // 0x80009D74: sw          $ra, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r31;
    // 0x80009D78: sw          $s1, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r17;
    // 0x80009D7C: sw          $s0, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r16;
    // 0x80009D80: swc1        $f31, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->f_odd[(31 - 1) * 2];
    // 0x80009D84: swc1        $f30, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->f30.u32l;
    // 0x80009D88: swc1        $f29, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->f_odd[(29 - 1) * 2];
    // 0x80009D8C: swc1        $f28, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->f28.u32l;
    // 0x80009D90: swc1        $f27, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->f_odd[(27 - 1) * 2];
    // 0x80009D94: swc1        $f26, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->f26.u32l;
    // 0x80009D98: swc1        $f25, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f_odd[(25 - 1) * 2];
    // 0x80009D9C: swc1        $f23, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f_odd[(23 - 1) * 2];
    // 0x80009DA0: swc1        $f22, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f22.u32l;
    // 0x80009DA4: swc1        $f21, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->f_odd[(21 - 1) * 2];
    // 0x80009DA8: swc1        $f20, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->f20.u32l;
    // 0x80009DAC: sw          $a1, 0x9C($sp)
    MEM_W(0X9C, ctx->r29) = ctx->r5;
    // 0x80009DB0: sw          $a2, 0xA0($sp)
    MEM_W(0XA0, ctx->r29) = ctx->r6;
    // 0x80009DB4: sw          $a3, 0xA4($sp)
    MEM_W(0XA4, ctx->r29) = ctx->r7;
    // 0x80009DB8: mtc1        $zero, $f24
    ctx->f24.u32l = 0;
    // 0x80009DBC: lwc1        $f4, 0xBC($a0)
    ctx->f4.u32l = MEM_W(ctx->r4, 0XBC);
    // 0x80009DC0: or          $s1, $a0, $zero
    ctx->r17 = ctx->r4 | 0;
    // 0x80009DC4: c.eq.s      $f24, $f4
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f24.fl == ctx->f4.fl;
    // 0x80009DC8: nop

    // 0x80009DCC: bc1f        L_80009E70
    if (!c1cs) {
        // 0x80009DD0: addiu       $s0, $s1, 0x4
        ctx->r16 = ADD32(ctx->r17, 0X4);
            goto L_80009E70;
    }
    // 0x80009DD0: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
    // 0x80009DD4: lb          $t6, 0xB8($a0)
    ctx->r14 = MEM_B(ctx->r4, 0XB8);
    // 0x80009DD8: addiu       $s0, $a0, 0x4
    ctx->r16 = ADD32(ctx->r4, 0X4);
    // 0x80009DDC: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x80009DE0: mov.s       $f20, $f24
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 24);
    ctx->f20.fl = ctx->f24.fl;
    // 0x80009DE4: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x80009DE8: lui         $at, 0x3F80
    ctx->r1 = S32(0X3F80 << 16);
    // 0x80009DEC: c.lt.s      $f24, $f8
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f24.fl < ctx->f8.fl;
    // 0x80009DF0: nop

    // 0x80009DF4: bc1f        L_80009E6C
    if (!c1cs) {
        // 0x80009DF8: nop
    
            goto L_80009E6C;
    }
    // 0x80009DF8: nop

    // 0x80009DFC: mtc1        $at, $f22
    ctx->f22.u32l = ctx->r1;
    // 0x80009E00: nop

L_80009E04:
    // 0x80009E04: lwc1        $f10, 0xC($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80009E08: lwc1        $f4, 0x0($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80009E0C: lwc1        $f6, 0x10($s0)
    ctx->f6.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80009E10: lwc1        $f8, 0x4($s0)
    ctx->f8.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80009E14: sub.s       $f0, $f10, $f4
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f0.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80009E18: lwc1        $f4, 0x8($s0)
    ctx->f4.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80009E1C: sub.s       $f2, $f6, $f8
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f2.fl = ctx->f6.fl - ctx->f8.fl;
    // 0x80009E20: lwc1        $f10, 0x14($s0)
    ctx->f10.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80009E24: mul.s       $f6, $f0, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = MUL_S(ctx->f0.fl, ctx->f0.fl);
    // 0x80009E28: sub.s       $f14, $f10, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f10.fl - ctx->f4.fl;
    // 0x80009E2C: mul.s       $f8, $f2, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = MUL_S(ctx->f2.fl, ctx->f2.fl);
    // 0x80009E30: nop

    // 0x80009E34: mul.s       $f4, $f14, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = MUL_S(ctx->f14.fl, ctx->f14.fl);
    // 0x80009E38: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80009E3C: jal         0x800C9AD0
    // 0x80009E40: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_0;
    // 0x80009E40: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_0:
    // 0x80009E44: lb          $t7, 0xB8($s1)
    ctx->r15 = MEM_B(ctx->r17, 0XB8);
    // 0x80009E48: add.s       $f20, $f20, $f22
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f20.fl = ctx->f20.fl + ctx->f22.fl;
    // 0x80009E4C: mtc1        $t7, $f10
    ctx->f10.u32l = ctx->r15;
    // 0x80009E50: lwc1        $f6, 0xBC($s1)
    ctx->f6.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x80009E54: cvt.s.w     $f4, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 10);
    ctx->f4.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80009E58: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x80009E5C: c.lt.s      $f20, $f4
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 4);
    c1cs = ctx->f20.fl < ctx->f4.fl;
    // 0x80009E60: add.s       $f8, $f6, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f0.fl;
    // 0x80009E64: bc1t        L_80009E04
    if (c1cs) {
        // 0x80009E68: swc1        $f8, 0xBC($s1)
        MEM_W(0XBC, ctx->r17) = ctx->f8.u32l;
            goto L_80009E04;
    }
    // 0x80009E68: swc1        $f8, 0xBC($s1)
    MEM_W(0XBC, ctx->r17) = ctx->f8.u32l;
L_80009E6C:
    // 0x80009E6C: addiu       $s0, $s1, 0x4
    ctx->r16 = ADD32(ctx->r17, 0X4);
L_80009E70:
    // 0x80009E70: mov.s       $f16, $f24
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 24);
    ctx->f16.fl = ctx->f24.fl;
    // 0x80009E74: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_80009E78:
    // 0x80009E78: lwc1        $f22, 0x0($s0)
    ctx->f22.u32l = MEM_W(ctx->r16, 0X0);
    // 0x80009E7C: lwc1        $f20, 0xC($s0)
    ctx->f20.u32l = MEM_W(ctx->r16, 0XC);
    // 0x80009E80: lwc1        $f30, 0x4($s0)
    ctx->f30.u32l = MEM_W(ctx->r16, 0X4);
    // 0x80009E84: sub.s       $f24, $f20, $f22
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f20.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f24.fl = ctx->f20.fl - ctx->f22.fl;
    // 0x80009E88: lwc1        $f0, 0x10($s0)
    ctx->f0.u32l = MEM_W(ctx->r16, 0X10);
    // 0x80009E8C: mul.s       $f6, $f24, $f24
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f24.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f6.fl = MUL_S(ctx->f24.fl, ctx->f24.fl);
    // 0x80009E90: sub.s       $f26, $f0, $f30
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f26.fl = ctx->f0.fl - ctx->f30.fl;
    // 0x80009E94: lwc1        $f18, 0x8($s0)
    ctx->f18.u32l = MEM_W(ctx->r16, 0X8);
    // 0x80009E98: lwc1        $f2, 0x14($s0)
    ctx->f2.u32l = MEM_W(ctx->r16, 0X14);
    // 0x80009E9C: mul.s       $f8, $f26, $f26
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f26.fl);
    // 0x80009EA0: sub.s       $f28, $f2, $f18
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f28.fl = ctx->f2.fl - ctx->f18.fl;
    // 0x80009EA4: swc1        $f16, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->f16.u32l;
    // 0x80009EA8: sb          $v0, 0x57($sp)
    MEM_B(0X57, ctx->r29) = ctx->r2;
    // 0x80009EAC: mul.s       $f4, $f28, $f28
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f4.fl = MUL_S(ctx->f28.fl, ctx->f28.fl);
    // 0x80009EB0: add.s       $f10, $f6, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f10.fl = ctx->f6.fl + ctx->f8.fl;
    // 0x80009EB4: swc1        $f18, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->f18.u32l;
    // 0x80009EB8: jal         0x800C9AD0
    // 0x80009EBC: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    sqrtf_recomp(rdram, ctx);
        goto after_1;
    // 0x80009EBC: add.s       $f12, $f10, $f4
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f12.fl = ctx->f10.fl + ctx->f4.fl;
    after_1:
    // 0x80009EC0: lwc1        $f6, 0x9C($sp)
    ctx->f6.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80009EC4: lbu         $v0, 0x57($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X57);
    // 0x80009EC8: c.le.s      $f22, $f6
    CHECK_FR(ctx, 22);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f22.fl <= ctx->f6.fl;
    // 0x80009ECC: lwc1        $f16, 0x5C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X5C);
    // 0x80009ED0: lwc1        $f18, 0x7C($sp)
    ctx->f18.u32l = MEM_W(ctx->r29, 0X7C);
    // 0x80009ED4: bc1f        L_80009EEC
    if (!c1cs) {
        // 0x80009ED8: nop
    
            goto L_80009EEC;
    }
    // 0x80009ED8: nop

    // 0x80009EDC: c.le.s      $f6, $f20
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 20);
    c1cs = ctx->f6.fl <= ctx->f20.fl;
    // 0x80009EE0: nop

    // 0x80009EE4: bc1t        L_80009F14
    if (c1cs) {
        // 0x80009EE8: nop
    
            goto L_80009F14;
    }
    // 0x80009EE8: nop

L_80009EEC:
    // 0x80009EEC: lwc1        $f8, 0x9C($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80009EF0: nop

    // 0x80009EF4: c.le.s      $f20, $f8
    CHECK_FR(ctx, 20);
    CHECK_FR(ctx, 8);
    c1cs = ctx->f20.fl <= ctx->f8.fl;
    // 0x80009EF8: nop

    // 0x80009EFC: bc1f        L_8000A020
    if (!c1cs) {
        // 0x80009F00: nop
    
            goto L_8000A020;
    }
    // 0x80009F00: nop

    // 0x80009F04: c.le.s      $f8, $f22
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 22);
    c1cs = ctx->f8.fl <= ctx->f22.fl;
    // 0x80009F08: nop

    // 0x80009F0C: bc1f        L_8000A020
    if (!c1cs) {
        // 0x80009F10: nop
    
            goto L_8000A020;
    }
    // 0x80009F10: nop

L_80009F14:
    // 0x80009F14: mtc1        $zero, $f10
    ctx->f10.u32l = 0;
    // 0x80009F18: lwc1        $f4, 0x9C($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X9C);
    // 0x80009F1C: c.eq.s      $f24, $f10
    CHECK_FR(ctx, 24);
    CHECK_FR(ctx, 10);
    c1cs = ctx->f24.fl == ctx->f10.fl;
    // 0x80009F20: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009F24: bc1t        L_80009F38
    if (c1cs) {
        // 0x80009F28: nop
    
            goto L_80009F38;
    }
    // 0x80009F28: nop

    // 0x80009F2C: sub.s       $f6, $f4, $f22
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 22);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f22.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f22.fl;
    // 0x80009F30: b           L_80009F7C
    // 0x80009F34: div.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f24.fl);
        goto L_80009F7C;
    // 0x80009F34: div.s       $f12, $f6, $f24
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 24);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f24.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f24.fl);
L_80009F38:
    // 0x80009F38: mtc1        $zero, $f2
    ctx->f2.u32l = 0;
    // 0x80009F3C: lwc1        $f8, 0xA0($sp)
    ctx->f8.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80009F40: c.eq.s      $f26, $f2
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f26.fl == ctx->f2.fl;
    // 0x80009F44: nop

    // 0x80009F48: bc1t        L_80009F5C
    if (c1cs) {
        // 0x80009F4C: nop
    
            goto L_80009F5C;
    }
    // 0x80009F4C: nop

    // 0x80009F50: sub.s       $f10, $f8, $f30
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f10.fl = ctx->f8.fl - ctx->f30.fl;
    // 0x80009F54: b           L_80009F7C
    // 0x80009F58: div.s       $f12, $f10, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f26.fl);
        goto L_80009F7C;
    // 0x80009F58: div.s       $f12, $f10, $f26
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 26);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f26.fl); 
    ctx->f12.fl = DIV_S(ctx->f10.fl, ctx->f26.fl);
L_80009F5C:
    // 0x80009F5C: c.eq.s      $f28, $f2
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f28.fl == ctx->f2.fl;
    // 0x80009F60: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80009F64: bc1t        L_80009F78
    if (c1cs) {
        // 0x80009F68: nop
    
            goto L_80009F78;
    }
    // 0x80009F68: nop

    // 0x80009F6C: sub.s       $f6, $f4, $f18
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f6.fl = ctx->f4.fl - ctx->f18.fl;
    // 0x80009F70: b           L_80009F7C
    // 0x80009F74: div.s       $f12, $f6, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f28.fl);
        goto L_80009F7C;
    // 0x80009F74: div.s       $f12, $f6, $f28
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 28);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f28.fl); 
    ctx->f12.fl = DIV_S(ctx->f6.fl, ctx->f28.fl);
L_80009F78:
    // 0x80009F78: mov.s       $f12, $f2
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 2);
    ctx->f12.fl = ctx->f2.fl;
L_80009F7C:
    // 0x80009F7C: mul.s       $f8, $f26, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 26);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f26.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f26.fl, ctx->f12.fl);
    // 0x80009F80: lwc1        $f10, 0xA0($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80009F84: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80009F88: lwc1        $f4, 0xA0($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA0);
    // 0x80009F8C: add.s       $f2, $f8, $f30
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 30);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f30.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f30.fl;
    // 0x80009F90: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x80009F94: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x80009F98: nop

    // 0x80009F9C: bc1f        L_80009FAC
    if (!c1cs) {
        // 0x80009FA0: nop
    
            goto L_80009FAC;
    }
    // 0x80009FA0: nop

    // 0x80009FA4: b           L_80009FB4
    // 0x80009FA8: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
        goto L_80009FB4;
    // 0x80009FA8: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
L_80009FAC:
    // 0x80009FAC: sub.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80009FB0: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80009FB4:
    // 0x80009FB4: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80009FB8: nop

    // 0x80009FBC: bc1f        L_8000A018
    if (!c1cs) {
        // 0x80009FC0: nop
    
            goto L_8000A018;
    }
    // 0x80009FC0: nop

    // 0x80009FC4: mul.s       $f8, $f28, $f12
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 28);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f28.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f8.fl = MUL_S(ctx->f28.fl, ctx->f12.fl);
    // 0x80009FC8: lwc1        $f10, 0xA4($sp)
    ctx->f10.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80009FCC: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x80009FD0: lwc1        $f4, 0xA4($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0XA4);
    // 0x80009FD4: add.s       $f2, $f8, $f18
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f2.fl = ctx->f8.fl + ctx->f18.fl;
    // 0x80009FD8: c.le.s      $f10, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 2);
    c1cs = ctx->f10.fl <= ctx->f2.fl;
    // 0x80009FDC: nop

    // 0x80009FE0: bc1f        L_80009FF0
    if (!c1cs) {
        // 0x80009FE4: nop
    
            goto L_80009FF0;
    }
    // 0x80009FE4: nop

    // 0x80009FE8: b           L_80009FF8
    // 0x80009FEC: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
        goto L_80009FF8;
    // 0x80009FEC: sub.s       $f14, $f2, $f10
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f10.fl;
L_80009FF0:
    // 0x80009FF0: sub.s       $f14, $f2, $f4
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 2);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f2.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f14.fl = ctx->f2.fl - ctx->f4.fl;
    // 0x80009FF4: neg.s       $f14, $f14
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f14.fl); 
    ctx->f14.fl = -ctx->f14.fl;
L_80009FF8:
    // 0x80009FF8: c.lt.s      $f14, $f6
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 6);
    c1cs = ctx->f14.fl < ctx->f6.fl;
    // 0x80009FFC: nop

    // 0x8000A000: bc1f        L_8000A018
    if (!c1cs) {
        // 0x8000A004: nop
    
            goto L_8000A018;
    }
    // 0x8000A004: nop

    // 0x8000A008: mul.s       $f8, $f12, $f0
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f12.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f8.fl = MUL_S(ctx->f12.fl, ctx->f0.fl);
    // 0x8000A00C: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A010: b           L_8000A024
    // 0x8000A014: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
        goto L_8000A024;
    // 0x8000A014: add.s       $f16, $f16, $f8
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 8);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f8.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f8.fl;
L_8000A018:
    // 0x8000A018: b           L_8000A024
    // 0x8000A01C: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
        goto L_8000A024;
    // 0x8000A01C: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_8000A020:
    // 0x8000A020: add.s       $f16, $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f16.fl = ctx->f16.fl + ctx->f0.fl;
L_8000A024:
    // 0x8000A024: beq         $v0, $zero, L_80009E78
    if (ctx->r2 == 0) {
        // 0x8000A028: addiu       $s0, $s0, 0xC
        ctx->r16 = ADD32(ctx->r16, 0XC);
            goto L_80009E78;
    }
    // 0x8000A028: addiu       $s0, $s0, 0xC
    ctx->r16 = ADD32(ctx->r16, 0XC);
    // 0x8000A02C: lui         $at, 0x4000
    ctx->r1 = S32(0X4000 << 16);
    // 0x8000A030: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A034: lwc1        $f0, 0xBC($s1)
    ctx->f0.u32l = MEM_W(ctx->r17, 0XBC);
    // 0x8000A038: lw          $s0, 0x44($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X44);
    // 0x8000A03C: div.s       $f4, $f0, $f10
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f4.fl = DIV_S(ctx->f0.fl, ctx->f10.fl);
    // 0x8000A040: lw          $ra, 0x4C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X4C);
    // 0x8000A044: lui         $at, 0x4396
    ctx->r1 = S32(0X4396 << 16);
    // 0x8000A048: c.lt.s      $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    c1cs = ctx->f4.fl < ctx->f16.fl;
    // 0x8000A04C: nop

    // 0x8000A050: bc1f        L_8000A05C
    if (!c1cs) {
        // 0x8000A054: nop
    
            goto L_8000A05C;
    }
    // 0x8000A054: nop

    // 0x8000A058: sub.s       $f16, $f0, $f16
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f0.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f16.fl = ctx->f0.fl - ctx->f16.fl;
L_8000A05C:
    // 0x8000A05C: mtc1        $at, $f0
    ctx->f0.u32l = ctx->r1;
    // 0x8000A060: nop

    // 0x8000A064: c.lt.s      $f16, $f0
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 0);
    c1cs = ctx->f16.fl < ctx->f0.fl;
    // 0x8000A068: nop

    // 0x8000A06C: bc1f        L_8000A140
    if (!c1cs) {
        // 0x8000A070: nop
    
            goto L_8000A140;
    }
    // 0x8000A070: nop

    // 0x8000A074: lbu         $t8, 0x0($s1)
    ctx->r24 = MEM_BU(ctx->r17, 0X0);
    // 0x8000A078: lui         $at, 0x4F80
    ctx->r1 = S32(0X4F80 << 16);
    // 0x8000A07C: mtc1        $t8, $f6
    ctx->f6.u32l = ctx->r24;
    // 0x8000A080: bgez        $t8, L_8000A094
    if (SIGNED(ctx->r24) >= 0) {
        // 0x8000A084: cvt.s.w     $f8, $f6
        CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
            goto L_8000A094;
    }
    // 0x8000A084: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x8000A088: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A08C: nop

    // 0x8000A090: add.s       $f8, $f8, $f10
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f8.fl = ctx->f8.fl + ctx->f10.fl;
L_8000A094:
    // 0x8000A094: mul.s       $f4, $f8, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = MUL_S(ctx->f8.fl, ctx->f16.fl);
    // 0x8000A098: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A09C: lui         $at, 0x4F00
    ctx->r1 = S32(0X4F00 << 16);
    // 0x8000A0A0: div.s       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f0.fl); 
    ctx->f6.fl = DIV_S(ctx->f4.fl, ctx->f0.fl);
    // 0x8000A0A4: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8000A0A8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8000A0AC: nop

    // 0x8000A0B0: cvt.w.s     $f10, $f6
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    ctx->f10.u32l = CVT_W_S(ctx->f6.fl);
    // 0x8000A0B4: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8000A0B8: nop

    // 0x8000A0BC: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8000A0C0: beq         $v0, $zero, L_8000A124
    if (ctx->r2 == 0) {
        // 0x8000A0C4: nop
    
            goto L_8000A124;
    }
    // 0x8000A0C4: nop

    // 0x8000A0C8: mtc1        $at, $f10
    ctx->f10.u32l = ctx->r1;
    // 0x8000A0CC: addiu       $v0, $zero, 0x1
    ctx->r2 = ADD32(0, 0X1);
    // 0x8000A0D0: sub.s       $f10, $f6, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f10.fl = ctx->f6.fl - ctx->f10.fl;
    // 0x8000A0D4: lui         $at, 0x8000
    ctx->r1 = S32(0X8000 << 16);
    // 0x8000A0D8: ctc1        $v0, $FpcCsr
    set_cop1_cs(ctx->r2);
    // 0x8000A0DC: nop

    // 0x8000A0E0: cvt.w.s     $f10, $f10
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 10);
    ctx->f10.u32l = CVT_W_S(ctx->f10.fl);
    // 0x8000A0E4: cfc1        $v0, $FpcCsr
    ctx->r2 = get_cop1_cs();
    // 0x8000A0E8: nop

    // 0x8000A0EC: andi        $v0, $v0, 0x78
    ctx->r2 = ctx->r2 & 0X78;
    // 0x8000A0F0: bne         $v0, $zero, L_8000A114
    if (ctx->r2 != 0) {
        // 0x8000A0F4: addiu       $v0, $zero, -0x1
        ctx->r2 = ADD32(0, -0X1);
            goto L_8000A114;
    }
    // 0x8000A0F4: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
    // 0x8000A0F8: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8000A0FC: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A100: or          $v0, $v0, $at
    ctx->r2 = ctx->r2 | ctx->r1;
    // 0x8000A104: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8000A108: b           L_8000A148
    // 0x8000A10C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8000A148;
    // 0x8000A10C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8000A110:
    // 0x8000A110: addiu       $v0, $zero, -0x1
    ctx->r2 = ADD32(0, -0X1);
L_8000A114:
    // 0x8000A114: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8000A118: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A11C: b           L_8000A148
    // 0x8000A120: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8000A148;
    // 0x8000A120: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8000A124:
    // 0x8000A124: mfc1        $v0, $f10
    ctx->r2 = (int32_t)ctx->f10.u32l;
    // 0x8000A128: nop

    // 0x8000A12C: bltz        $v0, L_8000A110
    if (SIGNED(ctx->r2) < 0) {
        // 0x8000A130: andi        $t0, $v0, 0xFF
        ctx->r8 = ctx->r2 & 0XFF;
            goto L_8000A110;
    }
    // 0x8000A130: andi        $t0, $v0, 0xFF
    ctx->r8 = ctx->r2 & 0XFF;
    // 0x8000A134: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8000A138: b           L_8000A148
    // 0x8000A13C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
        goto L_8000A148;
    // 0x8000A13C: or          $v0, $t0, $zero
    ctx->r2 = ctx->r8 | 0;
L_8000A140:
    // 0x8000A140: lbu         $v0, 0x0($s1)
    ctx->r2 = MEM_BU(ctx->r17, 0X0);
    // 0x8000A144: nop

L_8000A148:
    // 0x8000A148: lwc1        $f21, 0x10($sp)
    ctx->f_odd[(21 - 1) * 2] = MEM_W(ctx->r29, 0X10);
    // 0x8000A14C: lwc1        $f20, 0x14($sp)
    ctx->f20.u32l = MEM_W(ctx->r29, 0X14);
    // 0x8000A150: lwc1        $f23, 0x18($sp)
    ctx->f_odd[(23 - 1) * 2] = MEM_W(ctx->r29, 0X18);
    // 0x8000A154: lwc1        $f22, 0x1C($sp)
    ctx->f22.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x8000A158: lwc1        $f25, 0x20($sp)
    ctx->f_odd[(25 - 1) * 2] = MEM_W(ctx->r29, 0X20);
    // 0x8000A15C: lwc1        $f24, 0x24($sp)
    ctx->f24.u32l = MEM_W(ctx->r29, 0X24);
    // 0x8000A160: lwc1        $f27, 0x28($sp)
    ctx->f_odd[(27 - 1) * 2] = MEM_W(ctx->r29, 0X28);
    // 0x8000A164: lwc1        $f26, 0x2C($sp)
    ctx->f26.u32l = MEM_W(ctx->r29, 0X2C);
    // 0x8000A168: lwc1        $f29, 0x30($sp)
    ctx->f_odd[(29 - 1) * 2] = MEM_W(ctx->r29, 0X30);
    // 0x8000A16C: lwc1        $f28, 0x34($sp)
    ctx->f28.u32l = MEM_W(ctx->r29, 0X34);
    // 0x8000A170: lwc1        $f31, 0x38($sp)
    ctx->f_odd[(31 - 1) * 2] = MEM_W(ctx->r29, 0X38);
    // 0x8000A174: lwc1        $f30, 0x3C($sp)
    ctx->f30.u32l = MEM_W(ctx->r29, 0X3C);
    // 0x8000A178: lw          $s1, 0x48($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X48);
    // 0x8000A17C: jr          $ra
    // 0x8000A180: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
    return;
    // 0x8000A180: addiu       $sp, $sp, 0x98
    ctx->r29 = ADD32(ctx->r29, 0X98);
;}
RECOMP_FUNC void dummy_80079808(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80079808: jr          $ra
    // 0x8007980C: nop

    return;
    // 0x8007980C: nop

;}
RECOMP_FUNC void func_800245B4(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800245B4: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800245B8: addiu       $v1, $v1, -0x3900
    ctx->r3 = ADD32(ctx->r3, -0X3900);
    // 0x800245BC: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x800245C0: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800245C4: sll         $t8, $v0, 1
    ctx->r24 = S32(ctx->r2 << 1);
    // 0x800245C8: addu        $at, $at, $t8
    ctx->r1 = ADD32(ctx->r1, ctx->r24);
    // 0x800245CC: sh          $a0, -0x53E0($at)
    MEM_H(-0X53E0, ctx->r1) = ctx->r4;
    // 0x800245D0: addiu       $t9, $v0, 0x1
    ctx->r25 = ADD32(ctx->r2, 0X1);
    // 0x800245D4: slti        $at, $t9, 0x80
    ctx->r1 = SIGNED(ctx->r25) < 0X80 ? 1 : 0;
    // 0x800245D8: sw          $a0, 0x0($sp)
    MEM_W(0X0, ctx->r29) = ctx->r4;
    // 0x800245DC: bne         $at, $zero, L_800245E8
    if (ctx->r1 != 0) {
        // 0x800245E0: sw          $t9, 0x0($v1)
        MEM_W(0X0, ctx->r3) = ctx->r25;
            goto L_800245E8;
    }
    // 0x800245E0: sw          $t9, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r25;
    // 0x800245E4: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_800245E8:
    // 0x800245E8: jr          $ra
    // 0x800245EC: nop

    return;
    // 0x800245EC: nop

;}
RECOMP_FUNC void cam_set_layout(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8006652C: bltz        $a0, L_80066548
    if (SIGNED(ctx->r4) < 0) {
        // 0x80066530: slti        $at, $a0, 0x4
        ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
            goto L_80066548;
    }
    // 0x80066530: slti        $at, $a0, 0x4
    ctx->r1 = SIGNED(ctx->r4) < 0X4 ? 1 : 0;
    // 0x80066534: beq         $at, $zero, L_80066548
    if (ctx->r1 == 0) {
        // 0x80066538: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80066548;
    }
    // 0x80066538: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006653C: addiu       $v1, $v1, 0xCE0
    ctx->r3 = ADD32(ctx->r3, 0XCE0);
    // 0x80066540: b           L_80066554
    // 0x80066544: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
        goto L_80066554;
    // 0x80066544: sw          $a0, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r4;
L_80066548:
    // 0x80066548: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8006654C: addiu       $v1, $v1, 0xCE0
    ctx->r3 = ADD32(ctx->r3, 0XCE0);
    // 0x80066550: sw          $zero, 0x0($v1)
    MEM_W(0X0, ctx->r3) = 0;
L_80066554:
    // 0x80066554: lw          $v0, 0x0($v1)
    ctx->r2 = MEM_W(ctx->r3, 0X0);
    // 0x80066558: addiu       $t6, $zero, 0x1
    ctx->r14 = ADD32(0, 0X1);
    // 0x8006655C: beq         $v0, $zero, L_80066590
    if (ctx->r2 == 0) {
        // 0x80066560: lui         $v1, 0x8012
        ctx->r3 = S32(0X8012 << 16);
            goto L_80066590;
    }
    // 0x80066560: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x80066564: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x80066568: beq         $v0, $at, L_8006659C
    if (ctx->r2 == ctx->r1) {
        // 0x8006656C: addiu       $t7, $zero, 0x2
        ctx->r15 = ADD32(0, 0X2);
            goto L_8006659C;
    }
    // 0x8006656C: addiu       $t7, $zero, 0x2
    ctx->r15 = ADD32(0, 0X2);
    // 0x80066570: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x80066574: beq         $v0, $at, L_800665A8
    if (ctx->r2 == ctx->r1) {
        // 0x80066578: addiu       $t8, $zero, 0x3
        ctx->r24 = ADD32(0, 0X3);
            goto L_800665A8;
    }
    // 0x80066578: addiu       $t8, $zero, 0x3
    ctx->r24 = ADD32(0, 0X3);
    // 0x8006657C: addiu       $at, $zero, 0x3
    ctx->r1 = ADD32(0, 0X3);
    // 0x80066580: beq         $v0, $at, L_800665B4
    if (ctx->r2 == ctx->r1) {
        // 0x80066584: addiu       $t9, $zero, 0x4
        ctx->r25 = ADD32(0, 0X4);
            goto L_800665B4;
    }
    // 0x80066584: addiu       $t9, $zero, 0x4
    ctx->r25 = ADD32(0, 0X4);
    // 0x80066588: b           L_800665BC
    // 0x8006658C: nop

        goto L_800665BC;
    // 0x8006658C: nop

L_80066590:
    // 0x80066590: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80066594: b           L_800665BC
    // 0x80066598: sw          $t6, 0xCE8($at)
    MEM_W(0XCE8, ctx->r1) = ctx->r14;
        goto L_800665BC;
    // 0x80066598: sw          $t6, 0xCE8($at)
    MEM_W(0XCE8, ctx->r1) = ctx->r14;
L_8006659C:
    // 0x8006659C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800665A0: b           L_800665BC
    // 0x800665A4: sw          $t7, 0xCE8($at)
    MEM_W(0XCE8, ctx->r1) = ctx->r15;
        goto L_800665BC;
    // 0x800665A4: sw          $t7, 0xCE8($at)
    MEM_W(0XCE8, ctx->r1) = ctx->r15;
L_800665A8:
    // 0x800665A8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800665AC: b           L_800665BC
    // 0x800665B0: sw          $t8, 0xCE8($at)
    MEM_W(0XCE8, ctx->r1) = ctx->r24;
        goto L_800665BC;
    // 0x800665B0: sw          $t8, 0xCE8($at)
    MEM_W(0XCE8, ctx->r1) = ctx->r24;
L_800665B4:
    // 0x800665B4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800665B8: sw          $t9, 0xCE8($at)
    MEM_W(0XCE8, ctx->r1) = ctx->r25;
L_800665BC:
    // 0x800665BC: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800665C0: addiu       $v0, $v0, 0xCE4
    ctx->r2 = ADD32(ctx->r2, 0XCE4);
    // 0x800665C4: lw          $t0, 0x0($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X0);
    // 0x800665C8: lw          $v1, 0xCE8($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XCE8);
    // 0x800665CC: nop

    // 0x800665D0: slt         $at, $t0, $v1
    ctx->r1 = SIGNED(ctx->r8) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x800665D4: bne         $at, $zero, L_800665E0
    if (ctx->r1 != 0) {
        // 0x800665D8: nop
    
            goto L_800665E0;
    }
    // 0x800665D8: nop

    // 0x800665DC: sw          $zero, 0x0($v0)
    MEM_W(0X0, ctx->r2) = 0;
L_800665E0:
    // 0x800665E0: jr          $ra
    // 0x800665E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
    return;
    // 0x800665E4: or          $v0, $v1, $zero
    ctx->r2 = ctx->r3 | 0;
;}
RECOMP_FUNC void trackmenu_render_names(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8008FF1C: addiu       $sp, $sp, -0x80
    ctx->r29 = ADD32(ctx->r29, -0X80);
    // 0x8008FF20: sw          $ra, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r31;
    // 0x8008FF24: sw          $fp, 0x50($sp)
    MEM_W(0X50, ctx->r29) = ctx->r30;
    // 0x8008FF28: sw          $s7, 0x4C($sp)
    MEM_W(0X4C, ctx->r29) = ctx->r23;
    // 0x8008FF2C: sw          $s6, 0x48($sp)
    MEM_W(0X48, ctx->r29) = ctx->r22;
    // 0x8008FF30: sw          $s5, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r21;
    // 0x8008FF34: sw          $s4, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r20;
    // 0x8008FF38: sw          $s3, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r19;
    // 0x8008FF3C: sw          $s2, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r18;
    // 0x8008FF40: sw          $s1, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r17;
    // 0x8008FF44: sw          $s0, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r16;
    // 0x8008FF48: jal         0x8006EA90
    // 0x8008FF4C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x8008FF4C: sw          $a0, 0x80($sp)
    MEM_W(0X80, ctx->r29) = ctx->r4;
    after_0:
    // 0x8008FF50: sw          $v0, 0x58($sp)
    MEM_W(0X58, ctx->r29) = ctx->r2;
    // 0x8008FF54: jal         0x8001E29C
    // 0x8008FF58: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x8008FF58: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_1:
    // 0x8008FF5C: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x8008FF60: lw          $v1, -0xB84($v1)
    ctx->r3 = MEM_W(ctx->r3, -0XB84);
    // 0x8008FF64: sw          $v0, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r2;
    // 0x8008FF68: slti        $at, $v1, -0x16
    ctx->r1 = SIGNED(ctx->r3) < -0X16 ? 1 : 0;
    // 0x8008FF6C: bne         $at, $zero, L_800904B8
    if (ctx->r1 != 0) {
        // 0x8008FF70: slti        $at, $v1, 0x17
        ctx->r1 = SIGNED(ctx->r3) < 0X17 ? 1 : 0;
            goto L_800904B8;
    }
    // 0x8008FF70: slti        $at, $v1, 0x17
    ctx->r1 = SIGNED(ctx->r3) < 0X17 ? 1 : 0;
    // 0x8008FF74: beq         $at, $zero, L_800904B8
    if (ctx->r1 == 0) {
        // 0x8008FF78: lui         $t6, 0x8012
        ctx->r14 = S32(0X8012 << 16);
            goto L_800904B8;
    }
    // 0x8008FF78: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8008FF7C: lh          $t6, 0x6918($t6)
    ctx->r14 = MEM_H(ctx->r14, 0X6918);
    // 0x8008FF80: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8008FF84: bne         $t6, $at, L_8008FF98
    if (ctx->r14 != ctx->r1) {
        // 0x8008FF88: addiu       $t8, $zero, 0x4
        ctx->r24 = ADD32(0, 0X4);
            goto L_8008FF98;
    }
    // 0x8008FF88: addiu       $t8, $zero, 0x4
    ctx->r24 = ADD32(0, 0X4);
    // 0x8008FF8C: addiu       $t7, $zero, 0x3
    ctx->r15 = ADD32(0, 0X3);
    // 0x8008FF90: b           L_8008FF9C
    // 0x8008FF94: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
        goto L_8008FF9C;
    // 0x8008FF94: sw          $t7, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r15;
L_8008FF98:
    // 0x8008FF98: sw          $t8, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r24;
L_8008FF9C:
    // 0x8008FF9C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008FFA0: lwc1        $f4, 0x69DC($at)
    ctx->f4.u32l = MEM_W(ctx->r1, 0X69DC);
    // 0x8008FFA4: lui         $at, 0x43A0
    ctx->r1 = S32(0X43A0 << 16);
    // 0x8008FFA8: mtc1        $at, $f6
    ctx->f6.u32l = ctx->r1;
    // 0x8008FFAC: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8008FFB0: div.s       $f8, $f4, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f4.fl); NAN_CHECK(ctx->f6.fl); 
    ctx->f8.fl = DIV_S(ctx->f4.fl, ctx->f6.fl);
    // 0x8008FFB4: lw          $t1, 0x6480($t1)
    ctx->r9 = MEM_W(ctx->r9, 0X6480);
    // 0x8008FFB8: addiu       $t4, $zero, -0x1
    ctx->r12 = ADD32(0, -0X1);
    // 0x8008FFBC: negu        $t2, $t1
    ctx->r10 = SUB32(0, ctx->r9);
    // 0x8008FFC0: mtc1        $t2, $f18
    ctx->f18.u32l = ctx->r10;
    // 0x8008FFC4: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x8008FFC8: addiu       $s0, $s0, 0x6930
    ctx->r16 = ADD32(ctx->r16, 0X6930);
    // 0x8008FFCC: sw          $t4, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r12;
    // 0x8008FFD0: addiu       $fp, $zero, 0x3
    ctx->r30 = ADD32(0, 0X3);
    // 0x8008FFD4: addiu       $s7, $zero, 0x4
    ctx->r23 = ADD32(0, 0X4);
    // 0x8008FFD8: cfc1        $t9, $FpcCsr
    ctx->r25 = get_cop1_cs();
    // 0x8008FFDC: nop

    // 0x8008FFE0: ori         $at, $t9, 0x3
    ctx->r1 = ctx->r25 | 0X3;
    // 0x8008FFE4: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8008FFE8: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x8008FFEC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8008FFF0: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x8008FFF4: lwc1        $f16, 0x69E4($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X69E4);
    // 0x8008FFF8: ctc1        $t9, $FpcCsr
    set_cop1_cs(ctx->r25);
    // 0x8008FFFC: mfc1        $t0, $f10
    ctx->r8 = (int32_t)ctx->f10.u32l;
    // 0x80090000: cvt.s.w     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.fl = CVT_S_W(ctx->f18.u32l);
    // 0x80090004: sw          $t0, 0x6C($sp)
    MEM_W(0X6C, ctx->r29) = ctx->r8;
    // 0x80090008: div.s       $f6, $f16, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 4);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f4.fl); 
    ctx->f6.fl = DIV_S(ctx->f16.fl, ctx->f4.fl);
    // 0x8009000C: cfc1        $t3, $FpcCsr
    ctx->r11 = get_cop1_cs();
    // 0x80090010: nop

    // 0x80090014: ori         $at, $t3, 0x3
    ctx->r1 = ctx->r11 | 0X3;
    // 0x80090018: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x8009001C: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090020: nop

    // 0x80090024: cvt.w.s     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.u32l = CVT_W_S(ctx->f6.fl);
    // 0x80090028: mfc1        $v0, $f8
    ctx->r2 = (int32_t)ctx->f8.u32l;
    // 0x8009002C: ctc1        $t3, $FpcCsr
    set_cop1_cs(ctx->r11);
    // 0x80090030: addiu       $s3, $v0, -0x1
    ctx->r19 = ADD32(ctx->r2, -0X1);
    // 0x80090034: nop

L_80090038:
    // 0x80090038: addiu       $s6, $zero, -0x1
    ctx->r22 = ADD32(0, -0X1);
L_8009003C:
    // 0x8009003C: bltz        $s3, L_80090068
    if (SIGNED(ctx->r19) < 0) {
        // 0x80090040: nop
    
            goto L_80090068;
    }
    // 0x80090040: nop

    // 0x80090044: lw          $t5, 0x60($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X60);
    // 0x80090048: lw          $t6, 0x6C($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X6C);
    // 0x8009004C: slt         $at, $t5, $s3
    ctx->r1 = SIGNED(ctx->r13) < SIGNED(ctx->r19) ? 1 : 0;
    // 0x80090050: bne         $at, $zero, L_80090068
    if (ctx->r1 != 0) {
        // 0x80090054: addu        $s2, $t6, $s6
        ctx->r18 = ADD32(ctx->r14, ctx->r22);
            goto L_80090068;
    }
    // 0x80090054: addu        $s2, $t6, $s6
    ctx->r18 = ADD32(ctx->r14, ctx->r22);
    // 0x80090058: bltz        $s2, L_80090068
    if (SIGNED(ctx->r18) < 0) {
        // 0x8009005C: slti        $at, $s2, 0x6
        ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
            goto L_80090068;
    }
    // 0x8009005C: slti        $at, $s2, 0x6
    ctx->r1 = SIGNED(ctx->r18) < 0X6 ? 1 : 0;
    // 0x80090060: bne         $at, $zero, L_80090070
    if (ctx->r1 != 0) {
        // 0x80090064: addiu       $t7, $zero, 0x1
        ctx->r15 = ADD32(0, 0X1);
            goto L_80090070;
    }
    // 0x80090064: addiu       $t7, $zero, 0x1
    ctx->r15 = ADD32(0, 0X1);
L_80090068:
    // 0x80090068: b           L_80090374
    // 0x8009006C: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
        goto L_80090374;
    // 0x8009006C: sb          $zero, 0xC($s0)
    MEM_B(0XC, ctx->r16) = 0;
L_80090070:
    // 0x80090070: sll         $t8, $s3, 2
    ctx->r24 = S32(ctx->r19 << 2);
    // 0x80090074: subu        $t8, $t8, $s3
    ctx->r24 = SUB32(ctx->r24, ctx->r19);
    // 0x80090078: sll         $t8, $t8, 2
    ctx->r24 = S32(ctx->r24 << 2);
    // 0x8009007C: sll         $s4, $s2, 2
    ctx->r20 = S32(ctx->r18 << 2);
    // 0x80090080: sll         $t9, $s2, 1
    ctx->r25 = S32(ctx->r18 << 1);
    // 0x80090084: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x80090088: addiu       $t1, $t1, 0x68E8
    ctx->r9 = ADD32(ctx->r9, 0X68E8);
    // 0x8009008C: addu        $t0, $t8, $t9
    ctx->r8 = ADD32(ctx->r24, ctx->r25);
    // 0x80090090: addu        $s4, $s4, $s2
    ctx->r20 = ADD32(ctx->r20, ctx->r18);
    // 0x80090094: sb          $t7, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r15;
    // 0x80090098: sll         $s4, $s4, 6
    ctx->r20 = S32(ctx->r20 << 6);
    // 0x8009009C: addu        $s1, $t0, $t1
    ctx->r17 = ADD32(ctx->r8, ctx->r9);
    // 0x800900A0: addiu       $a0, $s3, 0x1
    ctx->r4 = ADD32(ctx->r19, 0X1);
    // 0x800900A4: jal         0x8006B1D4
    // 0x800900A8: negu        $s5, $s3
    ctx->r21 = SUB32(0, ctx->r19);
    level_world_id(rdram, ctx);
        goto after_2;
    // 0x800900A8: negu        $s5, $s3
    ctx->r21 = SUB32(0, ctx->r19);
    after_2:
    // 0x800900AC: jal         0x8006BDDC
    // 0x800900B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    level_name(rdram, ctx);
        goto after_3;
    // 0x800900B0: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_3:
    // 0x800900B4: lh          $t2, 0x0($s1)
    ctx->r10 = MEM_H(ctx->r17, 0X0);
    // 0x800900B8: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x800900BC: beq         $t2, $at, L_80090148
    if (ctx->r10 == ctx->r1) {
        // 0x800900C0: sw          $v0, 0x0($s0)
        MEM_W(0X0, ctx->r16) = ctx->r2;
            goto L_80090148;
    }
    // 0x800900C0: sw          $v0, 0x0($s0)
    MEM_W(0X0, ctx->r16) = ctx->r2;
    // 0x800900C4: sll         $t3, $s3, 2
    ctx->r11 = S32(ctx->r19 << 2);
    // 0x800900C8: subu        $t3, $t3, $s3
    ctx->r11 = SUB32(ctx->r11, ctx->r19);
    // 0x800900CC: lw          $t5, 0x5C($sp)
    ctx->r13 = MEM_W(ctx->r29, 0X5C);
    // 0x800900D0: sll         $t3, $t3, 1
    ctx->r11 = S32(ctx->r11 << 1);
    // 0x800900D4: addu        $t4, $t3, $s2
    ctx->r12 = ADD32(ctx->r11, ctx->r18);
    // 0x800900D8: addu        $s1, $t4, $t5
    ctx->r17 = ADD32(ctx->r12, ctx->r13);
    // 0x800900DC: lb          $a0, 0x0($s1)
    ctx->r4 = MEM_B(ctx->r17, 0X0);
    // 0x800900E0: jal         0x8006BDDC
    // 0x800900E4: nop

    level_name(rdram, ctx);
        goto after_4;
    // 0x800900E4: nop

    after_4:
    // 0x800900E8: bne         $s2, $s7, L_80090118
    if (ctx->r18 != ctx->r23) {
        // 0x800900EC: sw          $v0, 0x4($s0)
        MEM_W(0X4, ctx->r16) = ctx->r2;
            goto L_80090118;
    }
    // 0x800900EC: sw          $v0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r2;
    // 0x800900F0: lw          $t6, 0x58($sp)
    ctx->r14 = MEM_W(ctx->r29, 0X58);
    // 0x800900F4: sll         $t8, $s3, 1
    ctx->r24 = S32(ctx->r19 << 1);
    // 0x800900F8: lhu         $t7, 0xE($t6)
    ctx->r15 = MEM_HU(ctx->r14, 0XE);
    // 0x800900FC: addiu       $t1, $zero, 0x2
    ctx->r9 = ADD32(0, 0X2);
    // 0x80090100: srav        $t9, $t7, $t8
    ctx->r25 = S32(SIGNED(ctx->r15) >> (ctx->r24 & 31));
    // 0x80090104: andi        $t0, $t9, 0x3
    ctx->r8 = ctx->r25 & 0X3;
    // 0x80090108: bne         $fp, $t0, L_80090158
    if (ctx->r30 != ctx->r8) {
        // 0x8009010C: nop
    
            goto L_80090158;
    }
    // 0x8009010C: nop

    // 0x80090110: b           L_80090158
    // 0x80090114: sb          $t1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r9;
        goto L_80090158;
    // 0x80090114: sb          $t1, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r9;
L_80090118:
    // 0x80090118: lw          $t2, 0x58($sp)
    ctx->r10 = MEM_W(ctx->r29, 0X58);
    // 0x8009011C: lb          $t4, 0x0($s1)
    ctx->r12 = MEM_B(ctx->r17, 0X0);
    // 0x80090120: lw          $t3, 0x4($t2)
    ctx->r11 = MEM_W(ctx->r10, 0X4);
    // 0x80090124: sll         $t5, $t4, 2
    ctx->r13 = S32(ctx->r12 << 2);
    // 0x80090128: addu        $t6, $t3, $t5
    ctx->r14 = ADD32(ctx->r11, ctx->r13);
    // 0x8009012C: lw          $t7, 0x0($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X0);
    // 0x80090130: addiu       $t9, $zero, 0x2
    ctx->r25 = ADD32(0, 0X2);
    // 0x80090134: andi        $t8, $t7, 0x2
    ctx->r24 = ctx->r15 & 0X2;
    // 0x80090138: beq         $t8, $zero, L_80090158
    if (ctx->r24 == 0) {
        // 0x8009013C: nop
    
            goto L_80090158;
    }
    // 0x8009013C: nop

    // 0x80090140: b           L_80090158
    // 0x80090144: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
        goto L_80090158;
    // 0x80090144: sb          $t9, 0xC($s0)
    MEM_B(0XC, ctx->r16) = ctx->r25;
L_80090148:
    // 0x80090148: lui         $t0, 0x800E
    ctx->r8 = S32(0X800E << 16);
    // 0x8009014C: lw          $t0, 0x978($t0)
    ctx->r8 = MEM_W(ctx->r8, 0X978);
    // 0x80090150: nop

    // 0x80090154: sw          $t0, 0x4($s0)
    MEM_W(0X4, ctx->r16) = ctx->r8;
L_80090158:
    // 0x80090158: mtc1        $s4, $f10
    ctx->f10.u32l = ctx->r20;
    // 0x8009015C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090160: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x80090164: lwc1        $f16, 0x69DC($at)
    ctx->f16.u32l = MEM_W(ctx->r1, 0X69DC);
    // 0x80090168: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8009016C: sub.s       $f4, $f18, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f16.fl;
    // 0x80090170: addiu       $t7, $zero, 0xFF
    ctx->r15 = ADD32(0, 0XFF);
    // 0x80090174: cfc1        $t1, $FpcCsr
    ctx->r9 = get_cop1_cs();
    // 0x80090178: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8009017C: ori         $at, $t1, 0x3
    ctx->r1 = ctx->r9 | 0X3;
    // 0x80090180: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x80090184: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x80090188: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8009018C: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x80090190: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x80090194: mfc1        $t2, $f6
    ctx->r10 = (int32_t)ctx->f6.u32l;
    // 0x80090198: ctc1        $t1, $FpcCsr
    set_cop1_cs(ctx->r9);
    // 0x8009019C: sh          $t2, 0x8($s0)
    MEM_H(0X8, ctx->r16) = ctx->r10;
    // 0x800901A0: lw          $t4, 0x6480($t4)
    ctx->r12 = MEM_W(ctx->r12, 0X6480);
    // 0x800901A4: lwc1        $f18, 0x69E4($at)
    ctx->f18.u32l = MEM_W(ctx->r1, 0X69E4);
    // 0x800901A8: multu       $s5, $t4
    result = U64(U32(ctx->r21)) * U64(U32(ctx->r12)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x800901AC: sb          $t7, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r15;
    // 0x800901B0: mflo        $t3
    ctx->r11 = lo;
    // 0x800901B4: mtc1        $t3, $f8
    ctx->f8.u32l = ctx->r11;
    // 0x800901B8: nop

    // 0x800901BC: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800901C0: sub.s       $f16, $f10, $f18
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f10.fl); NAN_CHECK(ctx->f18.fl); 
    ctx->f16.fl = ctx->f10.fl - ctx->f18.fl;
    // 0x800901C4: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800901C8: nop

    // 0x800901CC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800901D0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800901D4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800901D8: nop

    // 0x800901DC: cvt.w.s     $f4, $f16
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 16);
    ctx->f4.u32l = CVT_W_S(ctx->f16.fl);
    // 0x800901E0: mfc1        $t6, $f4
    ctx->r14 = (int32_t)ctx->f4.u32l;
    // 0x800901E4: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800901E8: sh          $t6, 0xA($s0)
    MEM_H(0XA, ctx->r16) = ctx->r14;
    // 0x800901EC: lw          $t8, 0x69F4($t8)
    ctx->r24 = MEM_W(ctx->r24, 0X69F4);
    // 0x800901F0: nop

    // 0x800901F4: bne         $s2, $t8, L_80090238
    if (ctx->r18 != ctx->r24) {
        // 0x800901F8: nop
    
            goto L_80090238;
    }
    // 0x800901F8: nop

    // 0x800901FC: lw          $t9, 0x69F8($t9)
    ctx->r25 = MEM_W(ctx->r25, 0X69F8);
    // 0x80090200: nop

    // 0x80090204: bne         $s3, $t9, L_80090238
    if (ctx->r19 != ctx->r25) {
        // 0x80090208: nop
    
            goto L_80090238;
    }
    // 0x80090208: nop

    // 0x8009020C: lbu         $t1, 0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XE);
    // 0x80090210: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x80090214: ori         $t2, $t1, 0x80
    ctx->r10 = ctx->r9 | 0X80;
    // 0x80090218: sb          $t2, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r10;
    // 0x8009021C: lw          $v0, 0x63D8($v0)
    ctx->r2 = MEM_W(ctx->r2, 0X63D8);
    // 0x80090220: nop

    // 0x80090224: slti        $at, $v0, 0x20
    ctx->r1 = SIGNED(ctx->r2) < 0X20 ? 1 : 0;
    // 0x80090228: beq         $at, $zero, L_80090248
    if (ctx->r1 == 0) {
        // 0x8009022C: sll         $t4, $v0, 3
        ctx->r12 = S32(ctx->r2 << 3);
            goto L_80090248;
    }
    // 0x8009022C: sll         $t4, $v0, 3
    ctx->r12 = S32(ctx->r2 << 3);
    // 0x80090230: b           L_80090248
    // 0x80090234: sb          $t4, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r12;
        goto L_80090248;
    // 0x80090234: sb          $t4, 0xD($s0)
    MEM_B(0XD, ctx->r16) = ctx->r12;
L_80090238:
    // 0x80090238: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x8009023C: nop

    // 0x80090240: andi        $t5, $t3, 0xFF7F
    ctx->r13 = ctx->r11 & 0XFF7F;
    // 0x80090244: sb          $t5, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r13;
L_80090248:
    // 0x80090248: lbu         $t6, 0xE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XE);
    // 0x8009024C: lui         $t8, 0x800E
    ctx->r24 = S32(0X800E << 16);
    // 0x80090250: andi        $t7, $t6, 0xFF80
    ctx->r15 = ctx->r14 & 0XFF80;
    // 0x80090254: sb          $t7, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r15;
    // 0x80090258: lw          $t8, -0xB84($t8)
    ctx->r24 = MEM_W(ctx->r24, -0XB84);
    // 0x8009025C: slti        $at, $s2, 0x5
    ctx->r1 = SIGNED(ctx->r18) < 0X5 ? 1 : 0;
    // 0x80090260: bne         $t8, $zero, L_80090348
    if (ctx->r24 != 0) {
        // 0x80090264: nop
    
            goto L_80090348;
    }
    // 0x80090264: nop

    // 0x80090268: blez        $s3, L_80090280
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8009026C: ori         $t0, $t7, 0x1
        ctx->r8 = ctx->r15 | 0X1;
            goto L_80090280;
    }
    // 0x8009026C: ori         $t0, $t7, 0x1
    ctx->r8 = ctx->r15 | 0X1;
    // 0x80090270: andi        $t1, $t0, 0x7F
    ctx->r9 = ctx->r8 & 0X7F;
    // 0x80090274: andi        $t2, $t7, 0xFF80
    ctx->r10 = ctx->r15 & 0XFF80;
    // 0x80090278: or          $t4, $t1, $t2
    ctx->r12 = ctx->r9 | ctx->r10;
    // 0x8009027C: sb          $t4, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r12;
L_80090280:
    // 0x80090280: beq         $at, $zero, L_800902A8
    if (ctx->r1 == 0) {
        // 0x80090284: lw          $t9, 0x60($sp)
        ctx->r25 = MEM_W(ctx->r29, 0X60);
            goto L_800902A8;
    }
    // 0x80090284: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
    // 0x80090288: lbu         $t3, 0xE($s0)
    ctx->r11 = MEM_BU(ctx->r16, 0XE);
    // 0x8009028C: nop

    // 0x80090290: ori         $t5, $t3, 0x2
    ctx->r13 = ctx->r11 | 0X2;
    // 0x80090294: andi        $t6, $t5, 0x7F
    ctx->r14 = ctx->r13 & 0X7F;
    // 0x80090298: andi        $t7, $t3, 0xFF80
    ctx->r15 = ctx->r11 & 0XFF80;
    // 0x8009029C: or          $t8, $t6, $t7
    ctx->r24 = ctx->r14 | ctx->r15;
    // 0x800902A0: sb          $t8, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r24;
    // 0x800902A4: lw          $t9, 0x60($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X60);
L_800902A8:
    // 0x800902A8: nop

    // 0x800902AC: slt         $at, $s3, $t9
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r25) ? 1 : 0;
    // 0x800902B0: beq         $at, $zero, L_800902D4
    if (ctx->r1 == 0) {
        // 0x800902B4: nop
    
            goto L_800902D4;
    }
    // 0x800902B4: nop

    // 0x800902B8: lbu         $t0, 0xE($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XE);
    // 0x800902BC: nop

    // 0x800902C0: ori         $t1, $t0, 0x4
    ctx->r9 = ctx->r8 | 0X4;
    // 0x800902C4: andi        $t2, $t1, 0x7F
    ctx->r10 = ctx->r9 & 0X7F;
    // 0x800902C8: andi        $t4, $t0, 0xFF80
    ctx->r12 = ctx->r8 & 0XFF80;
    // 0x800902CC: or          $t3, $t2, $t4
    ctx->r11 = ctx->r10 | ctx->r12;
    // 0x800902D0: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
L_800902D4:
    // 0x800902D4: blez        $s2, L_800902F8
    if (SIGNED(ctx->r18) <= 0) {
        // 0x800902D8: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_800902F8;
    }
    // 0x800902D8: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x800902DC: lbu         $t5, 0xE($s0)
    ctx->r13 = MEM_BU(ctx->r16, 0XE);
    // 0x800902E0: nop

    // 0x800902E4: ori         $t6, $t5, 0x8
    ctx->r14 = ctx->r13 | 0X8;
    // 0x800902E8: andi        $t7, $t6, 0x7F
    ctx->r15 = ctx->r14 & 0X7F;
    // 0x800902EC: andi        $t8, $t5, 0xFF80
    ctx->r24 = ctx->r13 & 0XFF80;
    // 0x800902F0: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x800902F4: sb          $t9, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r25;
L_800902F8:
    // 0x800902F8: bne         $s2, $s7, L_80090320
    if (ctx->r18 != ctx->r23) {
        // 0x800902FC: nop
    
            goto L_80090320;
    }
    // 0x800902FC: nop

    // 0x80090300: bne         $s3, $s7, L_80090320
    if (ctx->r19 != ctx->r23) {
        // 0x80090304: nop
    
            goto L_80090320;
    }
    // 0x80090304: nop

    // 0x80090308: lbu         $t1, 0xE($s0)
    ctx->r9 = MEM_BU(ctx->r16, 0XE);
    // 0x8009030C: nop

    // 0x80090310: andi        $t2, $t1, 0x7D
    ctx->r10 = ctx->r9 & 0X7D;
    // 0x80090314: andi        $t4, $t1, 0xFF80
    ctx->r12 = ctx->r9 & 0XFF80;
    // 0x80090318: or          $t3, $t2, $t4
    ctx->r11 = ctx->r10 | ctx->r12;
    // 0x8009031C: sb          $t3, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r11;
L_80090320:
    // 0x80090320: bne         $s2, $at, L_80090348
    if (ctx->r18 != ctx->r1) {
        // 0x80090324: nop
    
            goto L_80090348;
    }
    // 0x80090324: nop

    // 0x80090328: bne         $s3, $fp, L_80090348
    if (ctx->r19 != ctx->r30) {
        // 0x8009032C: nop
    
            goto L_80090348;
    }
    // 0x8009032C: nop

    // 0x80090330: lbu         $t6, 0xE($s0)
    ctx->r14 = MEM_BU(ctx->r16, 0XE);
    // 0x80090334: nop

    // 0x80090338: andi        $t7, $t6, 0x7B
    ctx->r15 = ctx->r14 & 0X7B;
    // 0x8009033C: andi        $t8, $t6, 0xFF80
    ctx->r24 = ctx->r14 & 0XFF80;
    // 0x80090340: or          $t9, $t7, $t8
    ctx->r25 = ctx->r15 | ctx->r24;
    // 0x80090344: sb          $t9, 0xE($s0)
    MEM_B(0XE, ctx->r16) = ctx->r25;
L_80090348:
    // 0x80090348: bne         $s2, $s7, L_8009035C
    if (ctx->r18 != ctx->r23) {
        // 0x8009034C: addiu       $at, $zero, 0x5
        ctx->r1 = ADD32(0, 0X5);
            goto L_8009035C;
    }
    // 0x8009034C: addiu       $at, $zero, 0x5
    ctx->r1 = ADD32(0, 0X5);
    // 0x80090350: addiu       $t0, $zero, 0x6
    ctx->r8 = ADD32(0, 0X6);
    // 0x80090354: b           L_80090374
    // 0x80090358: sb          $t0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r8;
        goto L_80090374;
    // 0x80090358: sb          $t0, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r8;
L_8009035C:
    // 0x8009035C: bne         $s2, $at, L_80090370
    if (ctx->r18 != ctx->r1) {
        // 0x80090360: addiu       $t2, $zero, 0x4
        ctx->r10 = ADD32(0, 0X4);
            goto L_80090370;
    }
    // 0x80090360: addiu       $t2, $zero, 0x4
    ctx->r10 = ADD32(0, 0X4);
    // 0x80090364: addiu       $t1, $zero, 0x5
    ctx->r9 = ADD32(0, 0X5);
    // 0x80090368: b           L_80090374
    // 0x8009036C: sb          $t1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r9;
        goto L_80090374;
    // 0x8009036C: sb          $t1, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r9;
L_80090370:
    // 0x80090370: sb          $t2, 0xF($s0)
    MEM_B(0XF, ctx->r16) = ctx->r10;
L_80090374:
    // 0x80090374: addiu       $s6, $s6, 0x1
    ctx->r22 = ADD32(ctx->r22, 0X1);
    // 0x80090378: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8009037C: bne         $s6, $at, L_8009003C
    if (ctx->r22 != ctx->r1) {
        // 0x80090380: addiu       $s0, $s0, 0x10
        ctx->r16 = ADD32(ctx->r16, 0X10);
            goto L_8009003C;
    }
    // 0x80090380: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80090384: lw          $t4, 0x7C($sp)
    ctx->r12 = MEM_W(ctx->r29, 0X7C);
    // 0x80090388: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8009038C: addiu       $t3, $t4, 0x1
    ctx->r11 = ADD32(ctx->r12, 0X1);
    // 0x80090390: slti        $at, $t3, 0x2
    ctx->r1 = SIGNED(ctx->r11) < 0X2 ? 1 : 0;
    // 0x80090394: bne         $at, $zero, L_80090038
    if (ctx->r1 != 0) {
        // 0x80090398: sw          $t3, 0x7C($sp)
        MEM_W(0X7C, ctx->r29) = ctx->r11;
            goto L_80090038;
    }
    // 0x80090398: sw          $t3, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = ctx->r11;
    // 0x8009039C: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    extern int dkr_legacy_track_menu(uint8_t*, recomp_context*, unsigned, const uint32_t*, unsigned); { static const uint32_t dkr_legacy_fields[] = {0x801269c8U, 0x801269ccU, 0x801269dcU, 0x801269e4U, 0x801269e8U, 0x801269ecU, 0x801269f4U, 0x801269f8U, 0x80126480U, 0x80126478U, 0x800df4c4U, 0x801263d0U, 0x801263d8U, 0x80126918U, 0x80126930U, 0x800df47cU, 0x801267d8U, 0x80126818U, 0x80126830U, 0x800df4c8U, 0x801268e8U, 0x800e0980U, 0x801267d0U, 0x800e097cU, 0x800df4d4U, 0x800e3770U, 0x800df488U}; dkr_legacy_track_menu(rdram, ctx, 4U, dkr_legacy_fields, 0U); }
    // 0x800903A0: jal         0x80066894
    // 0x800903A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    camDisableUserView(rdram, ctx);
        goto after_5;
    // 0x800903A4: addiu       $a1, $zero, 0x1
    ctx->r5 = ADD32(0, 0X1);
    after_5:
    // 0x800903A8: jal         0x8009BD5C
    // 0x800903AC: nop

    menu_camera_centre(rdram, ctx);
        goto after_6;
    // 0x800903AC: nop

    after_6:
    // 0x800903B0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x800903B4: addiu       $s1, $s1, 0x63A0
    ctx->r17 = ADD32(ctx->r17, 0X63A0);
    // 0x800903B8: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x800903BC: addiu       $a1, $a1, 0x63A8
    ctx->r5 = ADD32(ctx->r5, 0X63A8);
    // 0x800903C0: jal         0x80067F2C
    // 0x800903C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    mtx_ortho(rdram, ctx);
        goto after_7;
    // 0x800903C4: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_7:
    // 0x800903C8: jal         0x8007B3D0
    // 0x800903CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    rendermode_reset(rdram, ctx);
        goto after_8;
    // 0x800903CC: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    after_8:
    // 0x800903D0: lw          $v1, 0x0($s1)
    ctx->r3 = MEM_W(ctx->r17, 0X0);
    // 0x800903D4: lui         $t6, 0xE700
    ctx->r14 = S32(0XE700 << 16);
    // 0x800903D8: addiu       $t5, $v1, 0x8
    ctx->r13 = ADD32(ctx->r3, 0X8);
    // 0x800903DC: sw          $t5, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r13;
    // 0x800903E0: addiu       $t7, $zero, 0x40
    ctx->r15 = ADD32(0, 0X40);
    // 0x800903E4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800903E8: sw          $zero, 0x4($v1)
    MEM_W(0X4, ctx->r3) = 0;
    // 0x800903EC: sw          $t6, 0x0($v1)
    MEM_W(0X0, ctx->r3) = ctx->r14;
    // 0x800903F0: sw          $t7, 0x6928($at)
    MEM_W(0X6928, ctx->r1) = ctx->r15;
    // 0x800903F4: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x800903F8: addiu       $t8, $zero, 0x20
    ctx->r24 = ADD32(0, 0X20);
    // 0x800903FC: sw          $t8, 0x692C($at)
    MEM_W(0X692C, ctx->r1) = ctx->r24;
    // 0x80090400: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x80090404: lui         $s0, 0x8012
    ctx->r16 = S32(0X8012 << 16);
    // 0x80090408: lui         $s4, 0x800E
    ctx->r20 = S32(0X800E << 16);
    // 0x8009040C: lui         $s3, 0x8012
    ctx->r19 = S32(0X8012 << 16);
    // 0x80090410: lui         $s2, 0x800E
    ctx->r18 = S32(0X800E << 16);
    // 0x80090414: sw          $zero, 0x69F0($at)
    MEM_W(0X69F0, ctx->r1) = 0;
    // 0x80090418: addiu       $s2, $s2, 0x5D4
    ctx->r18 = ADD32(ctx->r18, 0X5D4);
    // 0x8009041C: addiu       $s3, $s3, 0x69C0
    ctx->r19 = ADD32(ctx->r19, 0X69C0);
    // 0x80090420: addiu       $s4, $s4, 0x5F4
    ctx->r20 = ADD32(ctx->r20, 0X5F4);
    // 0x80090424: addiu       $s0, $s0, 0x6930
    ctx->r16 = ADD32(ctx->r16, 0X6930);
    // 0x80090428: sw          $zero, 0x7C($sp)
    MEM_W(0X7C, ctx->r29) = 0;
    // 0x8009042C: addiu       $s1, $zero, 0x1
    ctx->r17 = ADD32(0, 0X1);
L_80090430:
    // 0x80090430: lbu         $v0, 0xC($s0)
    ctx->r2 = MEM_BU(ctx->r16, 0XC);
    // 0x80090434: nop

    // 0x80090438: beq         $v0, $zero, L_80090494
    if (ctx->r2 == 0) {
        // 0x8009043C: nop
    
            goto L_80090494;
    }
    // 0x8009043C: nop

    // 0x80090440: bne         $s1, $v0, L_80090454
    if (ctx->r17 != ctx->r2) {
        // 0x80090444: or          $v0, $s4, $zero
        ctx->r2 = ctx->r20 | 0;
            goto L_80090454;
    }
    // 0x80090444: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
    // 0x80090448: b           L_80090454
    // 0x8009044C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
        goto L_80090454;
    // 0x8009044C: or          $v0, $s2, $zero
    ctx->r2 = ctx->r18 | 0;
    // 0x80090450: or          $v0, $s4, $zero
    ctx->r2 = ctx->r20 | 0;
L_80090454:
    // 0x80090454: lhu         $t1, 0xE($s0)
    ctx->r9 = MEM_HU(ctx->r16, 0XE);
    // 0x80090458: lbu         $t4, 0xE($s0)
    ctx->r12 = MEM_BU(ctx->r16, 0XE);
    // 0x8009045C: lbu         $t9, 0xD($s0)
    ctx->r25 = MEM_BU(ctx->r16, 0XD);
    // 0x80090460: lbu         $t0, 0xF($s0)
    ctx->r8 = MEM_BU(ctx->r16, 0XF);
    // 0x80090464: lh          $a0, 0x8($s0)
    ctx->r4 = MEM_H(ctx->r16, 0X8);
    // 0x80090468: lh          $a1, 0xA($s0)
    ctx->r5 = MEM_H(ctx->r16, 0XA);
    // 0x8009046C: lw          $a2, 0x0($s0)
    ctx->r6 = MEM_W(ctx->r16, 0X0);
    // 0x80090470: lw          $a3, 0x4($s0)
    ctx->r7 = MEM_W(ctx->r16, 0X4);
    // 0x80090474: srl         $t2, $t1, 15
    ctx->r10 = S32(U32(ctx->r9) >> 15);
    // 0x80090478: andi        $t3, $t4, 0x7F
    ctx->r11 = ctx->r12 & 0X7F;
    // 0x8009047C: sw          $t3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r11;
    // 0x80090480: sw          $t2, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r10;
    // 0x80090484: sw          $v0, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r2;
    // 0x80090488: sw          $t9, 0x10($sp)
    MEM_W(0X10, ctx->r29) = ctx->r25;
    // 0x8009048C: jal         0x8008FA54
    // 0x80090490: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    trackmenu_render_2D(rdram, ctx);
        goto after_9;
    // 0x80090490: sw          $t0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r8;
    after_9:
L_80090494:
    // 0x80090494: addiu       $s0, $s0, 0x10
    ctx->r16 = ADD32(ctx->r16, 0X10);
    // 0x80090498: bne         $s0, $s3, L_80090430
    if (ctx->r16 != ctx->r19) {
        // 0x8009049C: nop
    
            goto L_80090430;
    }
    // 0x8009049C: nop

    // 0x800904A0: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x800904A4: addiu       $v0, $v0, 0x6924
    ctx->r2 = ADD32(ctx->r2, 0X6924);
    // 0x800904A8: lw          $t5, 0x0($v0)
    ctx->r13 = MEM_W(ctx->r2, 0X0);
    // 0x800904AC: nop

    // 0x800904B0: subu        $t6, $s1, $t5
    ctx->r14 = SUB32(ctx->r17, ctx->r13);
    // 0x800904B4: sw          $t6, 0x0($v0)
    MEM_W(0X0, ctx->r2) = ctx->r14;
L_800904B8:
    // 0x800904B8: lw          $ra, 0x54($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X54);
    // 0x800904BC: lw          $s0, 0x30($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X30);
    // 0x800904C0: lw          $s1, 0x34($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X34);
    // 0x800904C4: lw          $s2, 0x38($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X38);
    // 0x800904C8: lw          $s3, 0x3C($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X3C);
    // 0x800904CC: lw          $s4, 0x40($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X40);
    // 0x800904D0: lw          $s5, 0x44($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X44);
    // 0x800904D4: lw          $s6, 0x48($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X48);
    // 0x800904D8: lw          $s7, 0x4C($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X4C);
    // 0x800904DC: lw          $fp, 0x50($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X50);
    // 0x800904E0: jr          $ra
    // 0x800904E4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
    return;
    // 0x800904E4: addiu       $sp, $sp, 0x80
    ctx->r29 = ADD32(ctx->r29, 0X80);
;}
RECOMP_FUNC void menu_trophy_race_round_init(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8009826C: addiu       $sp, $sp, -0x28
    ctx->r29 = ADD32(ctx->r29, -0X28);
    // 0x80098270: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x80098274: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x80098278: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8009827C: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x80098280: jal         0x8006EA90
    // 0x80098284: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    get_settings(rdram, ctx);
        goto after_0;
    // 0x80098284: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    after_0:
    // 0x80098288: or          $s1, $v0, $zero
    ctx->r17 = ctx->r2 | 0;
    // 0x8009828C: jal         0x8001E29C
    // 0x80098290: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    get_misc_asset(rdram, ctx);
        goto after_1;
    // 0x80098290: addiu       $a0, $zero, 0x1A
    ctx->r4 = ADD32(0, 0X1A);
    after_1:
    // 0x80098294: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x80098298: lw          $v1, 0xFEC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XFEC);
    // 0x8009829C: lui         $t6, 0x800E
    ctx->r14 = S32(0X800E << 16);
    // 0x800982A0: bne         $v1, $zero, L_800982DC
    if (ctx->r3 != 0) {
        // 0x800982A4: lui         $s3, 0x800E
        ctx->r19 = S32(0X800E << 16);
            goto L_800982DC;
    }
    // 0x800982A4: lui         $s3, 0x800E
    ctx->r19 = S32(0X800E << 16);
    // 0x800982A8: or          $s0, $zero, $zero
    ctx->r16 = 0 | 0;
    // 0x800982AC: or          $v1, $s1, $zero
    ctx->r3 = ctx->r17 | 0;
    // 0x800982B0: addiu       $a0, $zero, 0x8
    ctx->r4 = ADD32(0, 0X8);
L_800982B4:
    // 0x800982B4: addiu       $s0, $s0, 0x4
    ctx->r16 = ADD32(ctx->r16, 0X4);
    // 0x800982B8: sw          $zero, 0x6C($v1)
    MEM_W(0X6C, ctx->r3) = 0;
    // 0x800982BC: sw          $zero, 0x84($v1)
    MEM_W(0X84, ctx->r3) = 0;
    // 0x800982C0: sw          $zero, 0x9C($v1)
    MEM_W(0X9C, ctx->r3) = 0;
    // 0x800982C4: addiu       $v1, $v1, 0x60
    ctx->r3 = ADD32(ctx->r3, 0X60);
    // 0x800982C8: bne         $s0, $a0, L_800982B4
    if (ctx->r16 != ctx->r4) {
        // 0x800982CC: sw          $zero, -0xC($v1)
        MEM_W(-0XC, ctx->r3) = 0;
            goto L_800982B4;
    }
    // 0x800982CC: sw          $zero, -0xC($v1)
    MEM_W(-0XC, ctx->r3) = 0;
    // 0x800982D0: lui         $v1, 0x800E
    ctx->r3 = S32(0X800E << 16);
    // 0x800982D4: lw          $v1, 0xFEC($v1)
    ctx->r3 = MEM_W(ctx->r3, 0XFEC);
    // 0x800982D8: nop

L_800982DC:
    // 0x800982DC: lw          $t6, 0xFE8($t6)
    ctx->r14 = MEM_W(ctx->r14, 0XFE8);
    // 0x800982E0: addiu       $s3, $s3, -0xB44
    ctx->r19 = ADD32(ctx->r19, -0XB44);
    // 0x800982E4: sll         $t7, $t6, 2
    ctx->r15 = S32(ctx->r14 << 2);
    // 0x800982E8: subu        $t7, $t7, $t6
    ctx->r15 = SUB32(ctx->r15, ctx->r14);
    // 0x800982EC: sll         $t7, $t7, 1
    ctx->r15 = S32(ctx->r15 << 1);
    // 0x800982F0: addu        $t8, $t7, $v1
    ctx->r24 = ADD32(ctx->r15, ctx->r3);
    // 0x800982F4: addu        $t9, $t8, $v0
    ctx->r25 = ADD32(ctx->r24, ctx->r2);
    // 0x800982F8: lb          $a0, -0x6($t9)
    ctx->r4 = MEM_B(ctx->r25, -0X6);
    // 0x800982FC: addiu       $v1, $zero, -0x1
    ctx->r3 = ADD32(0, -0X1);
L_80098300:
    // 0x80098300: bne         $a0, $v1, L_80098314
    if (ctx->r4 != ctx->r3) {
        // 0x80098304: or          $s0, $a0, $zero
        ctx->r16 = ctx->r4 | 0;
            goto L_80098314;
    }
    // 0x80098304: or          $s0, $a0, $zero
    ctx->r16 = ctx->r4 | 0;
    // 0x80098308: addiu       $s0, $s0, 0x1
    ctx->r16 = ADD32(ctx->r16, 0X1);
    // 0x8009830C: andi        $t0, $s0, 0x3
    ctx->r8 = ctx->r16 & 0X3;
    // 0x80098310: or          $s0, $t0, $zero
    ctx->r16 = ctx->r8 | 0;
L_80098314:
    // 0x80098314: beq         $s0, $v1, L_80098300
    if (ctx->r16 == ctx->r3) {
        // 0x80098318: nop
    
            goto L_80098300;
    }
    // 0x80098318: nop

    // 0x8009831C: lw          $t1, 0x0($s3)
    ctx->r9 = MEM_W(ctx->r19, 0X0);
    // 0x80098320: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x80098324: blez        $t1, L_80098350
    if (SIGNED(ctx->r9) <= 0) {
        // 0x80098328: lui         $s2, 0x8012
        ctx->r18 = S32(0X8012 << 16);
            goto L_80098350;
    }
    // 0x80098328: lui         $s2, 0x8012
    ctx->r18 = S32(0X8012 << 16);
    // 0x8009832C: addiu       $s2, $s2, 0x69C0
    ctx->r18 = ADD32(ctx->r18, 0X69C0);
L_80098330:
    // 0x80098330: jal         0x8006B0AC
    // 0x80098334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_vehicle_default(rdram, ctx);
        goto after_2;
    // 0x80098334: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_2:
    // 0x80098338: lw          $t2, 0x0($s3)
    ctx->r10 = MEM_W(ctx->r19, 0X0);
    // 0x8009833C: addiu       $s1, $s1, 0x1
    ctx->r17 = ADD32(ctx->r17, 0X1);
    // 0x80098340: slt         $at, $s1, $t2
    ctx->r1 = SIGNED(ctx->r17) < SIGNED(ctx->r10) ? 1 : 0;
    // 0x80098344: addiu       $s2, $s2, 0x1
    ctx->r18 = ADD32(ctx->r18, 0X1);
    // 0x80098348: bne         $at, $zero, L_80098330
    if (ctx->r1 != 0) {
        // 0x8009834C: sb          $v0, -0x1($s2)
        MEM_B(-0X1, ctx->r18) = ctx->r2;
            goto L_80098330;
    }
    // 0x8009834C: sb          $v0, -0x1($s2)
    MEM_B(-0X1, ctx->r18) = ctx->r2;
L_80098350:
    // 0x80098350: jal         0x8006B0AC
    // 0x80098354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    leveltable_vehicle_default(rdram, ctx);
        goto after_3;
    // 0x80098354: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    after_3:
    // 0x80098358: jal         0x8006DB14
    // 0x8009835C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    set_level_default_vehicle(rdram, ctx);
        goto after_4;
    // 0x8009835C: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    after_4:
    // 0x80098360: or          $a0, $s0, $zero
    ctx->r4 = ctx->r16 | 0;
    // 0x80098364: addiu       $a1, $zero, -0x1
    ctx->r5 = ADD32(0, -0X1);
    // 0x80098368: jal         0x8006E2E8
    // 0x8009836C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    load_level_for_menu(rdram, ctx);
        goto after_5;
    // 0x8009836C: addiu       $a2, $zero, 0x1
    ctx->r6 = ADD32(0, 0X1);
    after_5:
    // 0x80098370: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x80098374: sw          $zero, -0xB84($at)
    MEM_W(-0XB84, ctx->r1) = 0;
    // 0x80098378: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x8009837C: addiu       $t3, $zero, 0xA
    ctx->r11 = ADD32(0, 0XA);
    // 0x80098380: sw          $t3, 0x980($at)
    MEM_W(0X980, ctx->r1) = ctx->r11;
    // 0x80098384: jal         0x800C4170
    // 0x80098388: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    load_font(rdram, ctx);
        goto after_6;
    // 0x80098388: addiu       $a0, $zero, 0x2
    ctx->r4 = ADD32(0, 0X2);
    after_6:
    // 0x8009838C: jal         0x80000BE0
    // 0x80098390: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_voicelimit_set(rdram, ctx);
        goto after_7;
    // 0x80098390: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_7:
    // 0x80098394: jal         0x80000B34
    // 0x80098398: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    music_play(rdram, ctx);
        goto after_8;
    // 0x80098398: addiu       $a0, $zero, 0x18
    ctx->r4 = ADD32(0, 0X18);
    after_8:
    // 0x8009839C: jal         0x80000C98
    // 0x800983A0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    music_fade(rdram, ctx);
        goto after_9;
    // 0x800983A0: addiu       $a0, $zero, 0x100
    ctx->r4 = ADD32(0, 0X100);
    after_9:
    // 0x800983A4: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x800983A8: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x800983AC: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x800983B0: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x800983B4: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x800983B8: jr          $ra
    // 0x800983BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
    return;
    // 0x800983BC: addiu       $sp, $sp, 0x28
    ctx->r29 = ADD32(ctx->r29, 0X28);
;}
RECOMP_FUNC void camEnableUserView(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80066818: beq         $a1, $zero, L_80066854
    if (ctx->r5 == 0) {
        // 0x8006681C: sll         $t0, $a0, 2
        ctx->r8 = S32(ctx->r4 << 2);
            goto L_80066854;
    }
    // 0x8006681C: sll         $t0, $a0, 2
    ctx->r8 = S32(ctx->r4 << 2);
    // 0x80066820: sll         $t6, $a0, 2
    ctx->r14 = S32(ctx->r4 << 2);
    // 0x80066824: subu        $t6, $t6, $a0
    ctx->r14 = SUB32(ctx->r14, ctx->r4);
    // 0x80066828: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006682C: addu        $t6, $t6, $a0
    ctx->r14 = ADD32(ctx->r14, ctx->r4);
    // 0x80066830: lui         $t7, 0x800E
    ctx->r15 = S32(0X800E << 16);
    // 0x80066834: addiu       $t7, $t7, -0x2F9C
    ctx->r15 = ADD32(ctx->r15, -0X2F9C);
    // 0x80066838: sll         $t6, $t6, 2
    ctx->r14 = S32(ctx->r14 << 2);
    // 0x8006683C: addu        $v0, $t6, $t7
    ctx->r2 = ADD32(ctx->r14, ctx->r15);
    // 0x80066840: lw          $t8, 0x30($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X30);
    // 0x80066844: nop

    // 0x80066848: ori         $t9, $t8, 0x1
    ctx->r25 = ctx->r24 | 0X1;
    // 0x8006684C: b           L_80066880
    // 0x80066850: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
        goto L_80066880;
    // 0x80066850: sw          $t9, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r25;
L_80066854:
    // 0x80066854: subu        $t0, $t0, $a0
    ctx->r8 = SUB32(ctx->r8, ctx->r4);
    // 0x80066858: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8006685C: addu        $t0, $t0, $a0
    ctx->r8 = ADD32(ctx->r8, ctx->r4);
    // 0x80066860: lui         $t1, 0x800E
    ctx->r9 = S32(0X800E << 16);
    // 0x80066864: addiu       $t1, $t1, -0x2F9C
    ctx->r9 = ADD32(ctx->r9, -0X2F9C);
    // 0x80066868: sll         $t0, $t0, 2
    ctx->r8 = S32(ctx->r8 << 2);
    // 0x8006686C: addu        $v0, $t0, $t1
    ctx->r2 = ADD32(ctx->r8, ctx->r9);
    // 0x80066870: lw          $t2, 0x30($v0)
    ctx->r10 = MEM_W(ctx->r2, 0X30);
    // 0x80066874: nop

    // 0x80066878: ori         $t3, $t2, 0x2
    ctx->r11 = ctx->r10 | 0X2;
    // 0x8006687C: sw          $t3, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r11;
L_80066880:
    // 0x80066880: lw          $t4, 0x30($v0)
    ctx->r12 = MEM_W(ctx->r2, 0X30);
    // 0x80066884: addiu       $at, $zero, -0x5
    ctx->r1 = ADD32(0, -0X5);
    // 0x80066888: and         $t5, $t4, $at
    ctx->r13 = ctx->r12 & ctx->r1;
    // 0x8006688C: jr          $ra
    // 0x80066890: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
    return;
    // 0x80066890: sw          $t5, 0x30($v0)
    MEM_W(0X30, ctx->r2) = ctx->r13;
;}
RECOMP_FUNC void func_8001E93C(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8001E93C: addiu       $sp, $sp, -0x50
    ctx->r29 = ADD32(ctx->r29, -0X50);
    // 0x8001E940: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8001E944: lb          $t6, -0x5182($t6)
    ctx->r14 = MEM_B(ctx->r14, -0X5182);
    // 0x8001E948: sw          $ra, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r31;
    // 0x8001E94C: sw          $s3, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r19;
    // 0x8001E950: sw          $s2, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r18;
    // 0x8001E954: sw          $s1, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r17;
    // 0x8001E958: beq         $t6, $zero, L_8001E9E8
    if (ctx->r14 == 0) {
        // 0x8001E95C: sw          $s0, 0x14($sp)
        MEM_W(0X14, ctx->r29) = ctx->r16;
            goto L_8001E9E8;
    }
    // 0x8001E95C: sw          $s0, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r16;
    // 0x8001E960: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001E964: lh          $a0, -0x5188($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X5188);
    // 0x8001E968: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001E96C: blez        $a0, L_8001E9E8
    if (SIGNED(ctx->r4) <= 0) {
        // 0x8001E970: or          $s1, $zero, $zero
        ctx->r17 = 0 | 0;
            goto L_8001E9E8;
    }
    // 0x8001E970: or          $s1, $zero, $zero
    ctx->r17 = 0 | 0;
    // 0x8001E974: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001E978: addiu       $t5, $t5, -0x518C
    ctx->r13 = ADD32(ctx->r13, -0X518C);
    // 0x8001E97C: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
L_8001E980:
    // 0x8001E980: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001E984: nop

    // 0x8001E988: addu        $t8, $t7, $s1
    ctx->r24 = ADD32(ctx->r15, ctx->r17);
    // 0x8001E98C: lw          $v0, 0x0($t8)
    ctx->r2 = MEM_W(ctx->r24, 0X0);
    // 0x8001E990: nop

    // 0x8001E994: lw          $v1, 0x64($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X64);
    // 0x8001E998: lw          $t0, 0x3C($v0)
    ctx->r8 = MEM_W(ctx->r2, 0X3C);
    // 0x8001E99C: beq         $v1, $zero, L_8001E9D8
    if (ctx->r3 == 0) {
        // 0x8001E9A0: nop
    
            goto L_8001E9D8;
    }
    // 0x8001E9A0: nop

    // 0x8001E9A4: lb          $t9, 0x21($t0)
    ctx->r25 = MEM_B(ctx->r8, 0X21);
    // 0x8001E9A8: nop

    // 0x8001E9AC: beq         $s0, $t9, L_8001E9D8
    if (ctx->r16 == ctx->r25) {
        // 0x8001E9B0: nop
    
            goto L_8001E9D8;
    }
    // 0x8001E9B0: nop

    // 0x8001E9B4: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001E9B8: jal         0x8000FFB8
    // 0x8001E9BC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    free_object(rdram, ctx);
        goto after_0;
    // 0x8001E9BC: sw          $v0, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r2;
    after_0:
    // 0x8001E9C0: lw          $v0, 0x3C($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X3C);
    // 0x8001E9C4: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8001E9C8: sw          $zero, 0x64($v0)
    MEM_W(0X64, ctx->r2) = 0;
    // 0x8001E9CC: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001E9D0: lh          $a0, -0x5188($a0)
    ctx->r4 = MEM_H(ctx->r4, -0X5188);
    // 0x8001E9D4: addiu       $t5, $t5, -0x518C
    ctx->r13 = ADD32(ctx->r13, -0X518C);
L_8001E9D8:
    // 0x8001E9D8: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001E9DC: slt         $at, $s3, $a0
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r4) ? 1 : 0;
    // 0x8001E9E0: bne         $at, $zero, L_8001E980
    if (ctx->r1 != 0) {
        // 0x8001E9E4: addiu       $s1, $s1, 0x4
        ctx->r17 = ADD32(ctx->r17, 0X4);
            goto L_8001E980;
    }
    // 0x8001E9E4: addiu       $s1, $s1, 0x4
    ctx->r17 = ADD32(ctx->r17, 0X4);
L_8001E9E8:
    // 0x8001E9E8: lui         $v0, 0x8012
    ctx->r2 = S32(0X8012 << 16);
    // 0x8001E9EC: addiu       $v0, $v0, -0x52C2
    ctx->r2 = ADD32(ctx->r2, -0X52C2);
    // 0x8001E9F0: lb          $t6, 0x0($v0)
    ctx->r14 = MEM_B(ctx->r2, 0X0);
    // 0x8001E9F4: addiu       $s0, $zero, 0x14
    ctx->r16 = ADD32(0, 0X14);
    // 0x8001E9F8: slti        $at, $t6, 0x15
    ctx->r1 = SIGNED(ctx->r14) < 0X15 ? 1 : 0;
    // 0x8001E9FC: bne         $at, $zero, L_8001EA08
    if (ctx->r1 != 0) {
        // 0x8001EA00: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001EA08;
    }
    // 0x8001EA00: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001EA04: sb          $zero, 0x0($v0)
    MEM_B(0X0, ctx->r2) = 0;
L_8001EA08:
    // 0x8001EA08: jal         0x8001E4C4
    // 0x8001EA0C: nop

    func_8001E4C4(rdram, ctx);
        goto after_1;
    // 0x8001EA0C: nop

    after_1:
    // 0x8001EA10: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001EA14: lw          $a2, -0x51A4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X51A4);
    // 0x8001EA18: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    // 0x8001EA1C: blez        $a2, L_8001EAAC
    if (SIGNED(ctx->r6) <= 0) {
        // 0x8001EA20: addiu       $t5, $t5, -0x518C
        ctx->r13 = ADD32(ctx->r13, -0X518C);
            goto L_8001EAAC;
    }
    // 0x8001EA20: addiu       $t5, $t5, -0x518C
    ctx->r13 = ADD32(ctx->r13, -0X518C);
    // 0x8001EA24: lui         $a1, 0x8012
    ctx->r5 = S32(0X8012 << 16);
    // 0x8001EA28: lui         $t3, 0x8012
    ctx->r11 = S32(0X8012 << 16);
    // 0x8001EA2C: lui         $t1, 0x8012
    ctx->r9 = S32(0X8012 << 16);
    // 0x8001EA30: lw          $a1, -0x51A8($a1)
    ctx->r5 = MEM_W(ctx->r5, -0X51A8);
    // 0x8001EA34: addiu       $t1, $t1, -0x5186
    ctx->r9 = ADD32(ctx->r9, -0X5186);
    // 0x8001EA38: addiu       $t3, $t3, -0x5228
    ctx->r11 = ADD32(ctx->r11, -0X5228);
    // 0x8001EA3C: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
    // 0x8001EA40: sll         $a3, $a2, 2
    ctx->r7 = S32(ctx->r6 << 2);
    // 0x8001EA44: addiu       $t0, $zero, 0x53
    ctx->r8 = ADD32(0, 0X53);
L_8001EA48:
    // 0x8001EA48: lw          $v0, 0x0($a1)
    ctx->r2 = MEM_W(ctx->r5, 0X0);
    // 0x8001EA4C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001EA50: beq         $v0, $zero, L_8001EAA4
    if (ctx->r2 == 0) {
        // 0x8001EA54: slt         $at, $t2, $a3
        ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
            goto L_8001EAA4;
    }
    // 0x8001EA54: slt         $at, $t2, $a3
    ctx->r1 = SIGNED(ctx->r10) < SIGNED(ctx->r7) ? 1 : 0;
    // 0x8001EA58: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8001EA5C: nop

    // 0x8001EA60: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8001EA64: bne         $t8, $zero, L_8001EAA4
    if (ctx->r24 != 0) {
        // 0x8001EA68: nop
    
            goto L_8001EAA4;
    }
    // 0x8001EA68: nop

    // 0x8001EA6C: lh          $t9, 0x48($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X48);
    // 0x8001EA70: nop

    // 0x8001EA74: bne         $t0, $t9, L_8001EAA4
    if (ctx->r8 != ctx->r25) {
        // 0x8001EA78: nop
    
            goto L_8001EAA4;
    }
    // 0x8001EA78: nop

    // 0x8001EA7C: lw          $v1, 0x3C($v0)
    ctx->r3 = MEM_W(ctx->r2, 0X3C);
    // 0x8001EA80: lh          $t6, 0x0($t1)
    ctx->r14 = MEM_H(ctx->r9, 0X0);
    // 0x8001EA84: lb          $a0, 0x9($v1)
    ctx->r4 = MEM_B(ctx->r3, 0X9);
    // 0x8001EA88: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x8001EA8C: beq         $t6, $a0, L_8001EA9C
    if (ctx->r14 == ctx->r4) {
        // 0x8001EA90: addu        $t8, $t3, $t7
        ctx->r24 = ADD32(ctx->r11, ctx->r15);
            goto L_8001EA9C;
    }
    // 0x8001EA90: addu        $t8, $t3, $t7
    ctx->r24 = ADD32(ctx->r11, ctx->r15);
    // 0x8001EA94: bne         $s0, $a0, L_8001EAA4
    if (ctx->r16 != ctx->r4) {
        // 0x8001EA98: nop
    
            goto L_8001EAA4;
    }
    // 0x8001EA98: nop

L_8001EA9C:
    // 0x8001EA9C: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8001EAA0: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
L_8001EAA4:
    // 0x8001EAA4: bne         $at, $zero, L_8001EA48
    if (ctx->r1 != 0) {
        // 0x8001EAA8: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_8001EA48;
    }
    // 0x8001EAA8: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
L_8001EAAC:
    // 0x8001EAAC: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EAB0: sb          $s3, -0x5200($at)
    MEM_B(-0X5200, ctx->r1) = ctx->r19;
    // 0x8001EAB4: addiu       $s2, $zero, 0x1
    ctx->r18 = ADD32(0, 0X1);
    // 0x8001EAB8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EABC: sb          $s2, -0x51FF($at)
    MEM_B(-0X51FF, ctx->r1) = ctx->r18;
    // 0x8001EAC0: lui         $t4, 0x8012
    ctx->r12 = S32(0X8012 << 16);
    // 0x8001EAC4: lw          $t4, -0x51A0($t4)
    ctx->r12 = MEM_W(ctx->r12, -0X51A0);
    // 0x8001EAC8: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EACC: sh          $zero, -0x5188($at)
    MEM_H(-0X5188, ctx->r1) = 0;
    // 0x8001EAD0: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EAD4: beq         $at, $zero, L_8001EB50
    if (ctx->r1 == 0) {
        // 0x8001EAD8: or          $s3, $zero, $zero
        ctx->r19 = 0 | 0;
            goto L_8001EB50;
    }
    // 0x8001EAD8: or          $s3, $zero, $zero
    ctx->r19 = 0 | 0;
    // 0x8001EADC: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x8001EAE0: addiu       $v1, $v1, -0x51A8
    ctx->r3 = ADD32(ctx->r3, -0X51A8);
    // 0x8001EAE4: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8001EAE8: addiu       $a0, $zero, 0x31
    ctx->r4 = ADD32(0, 0X31);
L_8001EAEC:
    // 0x8001EAEC: lw          $t9, 0x0($v1)
    ctx->r25 = MEM_W(ctx->r3, 0X0);
    // 0x8001EAF0: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8001EAF4: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EAF8: lw          $v0, 0x0($t6)
    ctx->r2 = MEM_W(ctx->r14, 0X0);
    // 0x8001EAFC: nop

    // 0x8001EB00: beq         $v0, $zero, L_8001EB48
    if (ctx->r2 == 0) {
        // 0x8001EB04: slt         $at, $t4, $a2
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001EB48;
    }
    // 0x8001EB04: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB08: lh          $t7, 0x6($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X6);
    // 0x8001EB0C: nop

    // 0x8001EB10: andi        $t8, $t7, 0x8000
    ctx->r24 = ctx->r15 & 0X8000;
    // 0x8001EB14: bne         $t8, $zero, L_8001EB48
    if (ctx->r24 != 0) {
        // 0x8001EB18: slt         $at, $t4, $a2
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001EB48;
    }
    // 0x8001EB18: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB1C: lh          $t9, 0x48($v0)
    ctx->r25 = MEM_H(ctx->r2, 0X48);
    // 0x8001EB20: sll         $t7, $s3, 2
    ctx->r15 = S32(ctx->r19 << 2);
    // 0x8001EB24: bne         $a0, $t9, L_8001EB48
    if (ctx->r4 != ctx->r25) {
        // 0x8001EB28: slt         $at, $t4, $a2
        ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
            goto L_8001EB48;
    }
    // 0x8001EB28: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
    // 0x8001EB2C: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EB30: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x8001EB34: addu        $t8, $t6, $t7
    ctx->r24 = ADD32(ctx->r14, ctx->r15);
    // 0x8001EB38: sw          $v0, 0x0($t8)
    MEM_W(0X0, ctx->r24) = ctx->r2;
    // 0x8001EB3C: lw          $a2, -0x51A4($a2)
    ctx->r6 = MEM_W(ctx->r6, -0X51A4);
    // 0x8001EB40: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8001EB44: slt         $at, $t4, $a2
    ctx->r1 = SIGNED(ctx->r12) < SIGNED(ctx->r6) ? 1 : 0;
L_8001EB48:
    // 0x8001EB48: bne         $at, $zero, L_8001EAEC
    if (ctx->r1 != 0) {
        // 0x8001EB4C: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001EAEC;
    }
    // 0x8001EB4C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
L_8001EB50:
    // 0x8001EB50: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
    // 0x8001EB54: addiu       $ra, $s3, -0x1
    ctx->r31 = ADD32(ctx->r19, -0X1);
    // 0x8001EB58: addiu       $s1, $zero, 0x2
    ctx->r17 = ADD32(0, 0X2);
L_8001EB5C:
    // 0x8001EB5C: blez        $ra, L_8001EC64
    if (SIGNED(ctx->r31) <= 0) {
        // 0x8001EB60: or          $t3, $s2, $zero
        ctx->r11 = ctx->r18 | 0;
            goto L_8001EC64;
    }
    // 0x8001EB60: or          $t3, $s2, $zero
    ctx->r11 = ctx->r18 | 0;
    // 0x8001EB64: or          $t2, $zero, $zero
    ctx->r10 = 0 | 0;
L_8001EB68:
    // 0x8001EB68: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8001EB6C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8001EB70: addu        $a1, $t9, $t2
    ctx->r5 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EB74: lw          $a2, 0x0($a1)
    ctx->r6 = MEM_W(ctx->r5, 0X0);
    // 0x8001EB78: lw          $a3, 0x4($a1)
    ctx->r7 = MEM_W(ctx->r5, 0X4);
    // 0x8001EB7C: lw          $t1, 0x3C($a2)
    ctx->r9 = MEM_W(ctx->r6, 0X3C);
    // 0x8001EB80: lw          $a0, 0x3C($a3)
    ctx->r4 = MEM_W(ctx->r7, 0X3C);
    // 0x8001EB84: lb          $t6, 0x21($t1)
    ctx->r14 = MEM_B(ctx->r9, 0X21);
    // 0x8001EB88: lb          $v0, 0x10($t1)
    ctx->r2 = MEM_B(ctx->r9, 0X10);
    // 0x8001EB8C: lb          $v1, 0x10($a0)
    ctx->r3 = MEM_B(ctx->r4, 0X10);
    // 0x8001EB90: bne         $s0, $t6, L_8001EBA4
    if (ctx->r16 != ctx->r14) {
        // 0x8001EB94: nop
    
            goto L_8001EBA4;
    }
    // 0x8001EB94: nop

    // 0x8001EB98: addiu       $v0, $v0, -0x190
    ctx->r2 = ADD32(ctx->r2, -0X190);
    // 0x8001EB9C: sll         $t7, $v0, 16
    ctx->r15 = S32(ctx->r2 << 16);
    // 0x8001EBA0: sra         $v0, $t7, 16
    ctx->r2 = S32(SIGNED(ctx->r15) >> 16);
L_8001EBA4:
    // 0x8001EBA4: lb          $t9, 0x21($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X21);
    // 0x8001EBA8: nop

    // 0x8001EBAC: bne         $s0, $t9, L_8001EBC4
    if (ctx->r16 != ctx->r25) {
        // 0x8001EBB0: slt         $at, $v1, $v0
        ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
            goto L_8001EBC4;
    }
    // 0x8001EBB0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x8001EBB4: addiu       $v1, $v1, -0x190
    ctx->r3 = ADD32(ctx->r3, -0X190);
    // 0x8001EBB8: sll         $t6, $v1, 16
    ctx->r14 = S32(ctx->r3 << 16);
    // 0x8001EBBC: sra         $v1, $t6, 16
    ctx->r3 = S32(SIGNED(ctx->r14) >> 16);
    // 0x8001EBC0: slt         $at, $v1, $v0
    ctx->r1 = SIGNED(ctx->r3) < SIGNED(ctx->r2) ? 1 : 0;
L_8001EBC4:
    // 0x8001EBC4: beq         $at, $zero, L_8001EBE4
    if (ctx->r1 == 0) {
        // 0x8001EBC8: nop
    
            goto L_8001EBE4;
    }
    // 0x8001EBC8: nop

    // 0x8001EBCC: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8001EBD0: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001EBD4: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001EBD8: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001EBDC: b           L_8001EC58
    // 0x8001EBE0: sw          $a2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r6;
        goto L_8001EC58;
    // 0x8001EBE0: sw          $a2, 0x4($t9)
    MEM_W(0X4, ctx->r25) = ctx->r6;
L_8001EBE4:
    // 0x8001EBE4: bne         $v0, $v1, L_8001EC58
    if (ctx->r2 != ctx->r3) {
        // 0x8001EBE8: nop
    
            goto L_8001EC58;
    }
    // 0x8001EBE8: nop

    // 0x8001EBEC: lb          $v0, 0x11($a0)
    ctx->r2 = MEM_B(ctx->r4, 0X11);
    // 0x8001EBF0: lb          $v1, 0x11($t1)
    ctx->r3 = MEM_B(ctx->r9, 0X11);
    // 0x8001EBF4: nop

    // 0x8001EBF8: slt         $at, $v0, $v1
    ctx->r1 = SIGNED(ctx->r2) < SIGNED(ctx->r3) ? 1 : 0;
    // 0x8001EBFC: beq         $at, $zero, L_8001EC1C
    if (ctx->r1 == 0) {
        // 0x8001EC00: nop
    
            goto L_8001EC1C;
    }
    // 0x8001EC00: nop

    // 0x8001EC04: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8001EC08: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EC0C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001EC10: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001EC14: b           L_8001EC58
    // 0x8001EC18: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
        goto L_8001EC58;
    // 0x8001EC18: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
L_8001EC1C:
    // 0x8001EC1C: bne         $v0, $v1, L_8001EC58
    if (ctx->r2 != ctx->r3) {
        // 0x8001EC20: nop
    
            goto L_8001EC58;
    }
    // 0x8001EC20: nop

    // 0x8001EC24: lw          $t8, 0x78($a3)
    ctx->r24 = MEM_W(ctx->r7, 0X78);
    // 0x8001EC28: nop

    // 0x8001EC2C: beq         $s2, $t8, L_8001EC44
    if (ctx->r18 == ctx->r24) {
        // 0x8001EC30: nop
    
            goto L_8001EC44;
    }
    // 0x8001EC30: nop

    // 0x8001EC34: lw          $t9, 0x78($a2)
    ctx->r25 = MEM_W(ctx->r6, 0X78);
    // 0x8001EC38: nop

    // 0x8001EC3C: bne         $s1, $t9, L_8001EC58
    if (ctx->r17 != ctx->r25) {
        // 0x8001EC40: nop
    
            goto L_8001EC58;
    }
    // 0x8001EC40: nop

L_8001EC44:
    // 0x8001EC44: sw          $a3, 0x0($a1)
    MEM_W(0X0, ctx->r5) = ctx->r7;
    // 0x8001EC48: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EC4C: or          $t3, $zero, $zero
    ctx->r11 = 0 | 0;
    // 0x8001EC50: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001EC54: sw          $a2, 0x4($t7)
    MEM_W(0X4, ctx->r15) = ctx->r6;
L_8001EC58:
    // 0x8001EC58: bne         $t4, $ra, L_8001EB68
    if (ctx->r12 != ctx->r31) {
        // 0x8001EC5C: addiu       $t2, $t2, 0x4
        ctx->r10 = ADD32(ctx->r10, 0X4);
            goto L_8001EB68;
    }
    // 0x8001EC5C: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001EC60: or          $t4, $zero, $zero
    ctx->r12 = 0 | 0;
L_8001EC64:
    // 0x8001EC64: beq         $t3, $zero, L_8001EB5C
    if (ctx->r11 == 0) {
        // 0x8001EC68: nop
    
            goto L_8001EB5C;
    }
    // 0x8001EC68: nop

    // 0x8001EC6C: blez        $s3, L_8001EE34
    if (SIGNED(ctx->r19) <= 0) {
        // 0x8001EC70: addiu       $a0, $zero, -0x65
        ctx->r4 = ADD32(0, -0X65);
            goto L_8001EE34;
    }
    // 0x8001EC70: addiu       $a0, $zero, -0x65
    ctx->r4 = ADD32(0, -0X65);
    // 0x8001EC74: andi        $v0, $s3, 0x3
    ctx->r2 = ctx->r19 & 0X3;
    // 0x8001EC78: beq         $v0, $zero, L_8001ECE4
    if (ctx->r2 == 0) {
        // 0x8001EC7C: or          $v1, $v0, $zero
        ctx->r3 = ctx->r2 | 0;
            goto L_8001ECE4;
    }
    // 0x8001EC7C: or          $v1, $v0, $zero
    ctx->r3 = ctx->r2 | 0;
    // 0x8001EC80: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8001EC84: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
L_8001EC88:
    // 0x8001EC88: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001EC8C: addiu       $t4, $t4, 0x1
    ctx->r12 = ADD32(ctx->r12, 0X1);
    // 0x8001EC90: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001EC94: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8001EC98: nop

    // 0x8001EC9C: lw          $t1, 0x3C($t6)
    ctx->r9 = MEM_W(ctx->r14, 0X3C);
    // 0x8001ECA0: nop

    // 0x8001ECA4: lb          $t7, 0x10($t1)
    ctx->r15 = MEM_B(ctx->r9, 0X10);
    // 0x8001ECA8: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8001ECAC: beq         $a0, $t7, L_8001ECBC
    if (ctx->r4 == ctx->r15) {
        // 0x8001ECB0: nop
    
            goto L_8001ECBC;
    }
    // 0x8001ECB0: nop

    // 0x8001ECB4: lb          $a0, 0x10($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X10);
    // 0x8001ECB8: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ECBC:
    // 0x8001ECBC: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001ECC0: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001ECC4: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001ECC8: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001ECCC: lw          $t6, 0x0($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X0);
    // 0x8001ECD0: addiu       $t2, $t2, 0x4
    ctx->r10 = ADD32(ctx->r10, 0X4);
    // 0x8001ECD4: bne         $v1, $t4, L_8001EC88
    if (ctx->r3 != ctx->r12) {
        // 0x8001ECD8: sw          $zero, 0x78($t6)
        MEM_W(0X78, ctx->r14) = 0;
            goto L_8001EC88;
    }
    // 0x8001ECD8: sw          $zero, 0x78($t6)
    MEM_W(0X78, ctx->r14) = 0;
    // 0x8001ECDC: beq         $t4, $s3, L_8001EE34
    if (ctx->r12 == ctx->r19) {
        // 0x8001ECE0: sw          $v0, 0x28($sp)
        MEM_W(0X28, ctx->r29) = ctx->r2;
            goto L_8001EE34;
    }
    // 0x8001ECE0: sw          $v0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r2;
L_8001ECE4:
    // 0x8001ECE4: lw          $v0, 0x28($sp)
    ctx->r2 = MEM_W(ctx->r29, 0X28);
    // 0x8001ECE8: sll         $t2, $t4, 2
    ctx->r10 = S32(ctx->r12 << 2);
    // 0x8001ECEC: sll         $a1, $s3, 2
    ctx->r5 = S32(ctx->r19 << 2);
L_8001ECF0:
    // 0x8001ECF0: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001ECF4: nop

    // 0x8001ECF8: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8001ECFC: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001ED00: nop

    // 0x8001ED04: lw          $t1, 0x3C($t9)
    ctx->r9 = MEM_W(ctx->r25, 0X3C);
    // 0x8001ED08: nop

    // 0x8001ED0C: lb          $t6, 0x10($t1)
    ctx->r14 = MEM_B(ctx->r9, 0X10);
    // 0x8001ED10: or          $t0, $t1, $zero
    ctx->r8 = ctx->r9 | 0;
    // 0x8001ED14: beq         $a0, $t6, L_8001ED24
    if (ctx->r4 == ctx->r14) {
        // 0x8001ED18: nop
    
            goto L_8001ED24;
    }
    // 0x8001ED18: nop

    // 0x8001ED1C: lb          $a0, 0x10($t1)
    ctx->r4 = MEM_B(ctx->r9, 0X10);
    // 0x8001ED20: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ED24:
    // 0x8001ED24: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001ED28: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001ED2C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001ED30: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8001ED34: lw          $t9, 0x0($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X0);
    // 0x8001ED38: nop

    // 0x8001ED3C: sw          $zero, 0x78($t9)
    MEM_W(0X78, ctx->r25) = 0;
    // 0x8001ED40: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001ED44: nop

    // 0x8001ED48: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001ED4C: lw          $t8, 0x4($t7)
    ctx->r24 = MEM_W(ctx->r15, 0X4);
    // 0x8001ED50: nop

    // 0x8001ED54: lw          $t0, 0x3C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X3C);
    // 0x8001ED58: nop

    // 0x8001ED5C: lb          $v1, 0x10($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X10);
    // 0x8001ED60: nop

    // 0x8001ED64: beq         $a0, $v1, L_8001ED74
    if (ctx->r4 == ctx->r3) {
        // 0x8001ED68: nop
    
            goto L_8001ED74;
    }
    // 0x8001ED68: nop

    // 0x8001ED6C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001ED70: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001ED74:
    // 0x8001ED74: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001ED78: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8001ED7C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001ED80: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8001ED84: lw          $t7, 0x4($t6)
    ctx->r15 = MEM_W(ctx->r14, 0X4);
    // 0x8001ED88: nop

    // 0x8001ED8C: sw          $zero, 0x78($t7)
    MEM_W(0X78, ctx->r15) = 0;
    // 0x8001ED90: lw          $t8, 0x0($t5)
    ctx->r24 = MEM_W(ctx->r13, 0X0);
    // 0x8001ED94: nop

    // 0x8001ED98: addu        $t9, $t8, $t2
    ctx->r25 = ADD32(ctx->r24, ctx->r10);
    // 0x8001ED9C: lw          $t6, 0x8($t9)
    ctx->r14 = MEM_W(ctx->r25, 0X8);
    // 0x8001EDA0: nop

    // 0x8001EDA4: lw          $t0, 0x3C($t6)
    ctx->r8 = MEM_W(ctx->r14, 0X3C);
    // 0x8001EDA8: nop

    // 0x8001EDAC: lb          $v1, 0x10($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X10);
    // 0x8001EDB0: nop

    // 0x8001EDB4: beq         $a0, $v1, L_8001EDC4
    if (ctx->r4 == ctx->r3) {
        // 0x8001EDB8: nop
    
            goto L_8001EDC4;
    }
    // 0x8001EDB8: nop

    // 0x8001EDBC: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001EDC0: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001EDC4:
    // 0x8001EDC4: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001EDC8: lw          $t7, 0x0($t5)
    ctx->r15 = MEM_W(ctx->r13, 0X0);
    // 0x8001EDCC: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EDD0: addu        $t8, $t7, $t2
    ctx->r24 = ADD32(ctx->r15, ctx->r10);
    // 0x8001EDD4: lw          $t9, 0x8($t8)
    ctx->r25 = MEM_W(ctx->r24, 0X8);
    // 0x8001EDD8: nop

    // 0x8001EDDC: sw          $zero, 0x78($t9)
    MEM_W(0X78, ctx->r25) = 0;
    // 0x8001EDE0: lw          $t6, 0x0($t5)
    ctx->r14 = MEM_W(ctx->r13, 0X0);
    // 0x8001EDE4: nop

    // 0x8001EDE8: addu        $t7, $t6, $t2
    ctx->r15 = ADD32(ctx->r14, ctx->r10);
    // 0x8001EDEC: lw          $t8, 0xC($t7)
    ctx->r24 = MEM_W(ctx->r15, 0XC);
    // 0x8001EDF0: nop

    // 0x8001EDF4: lw          $t0, 0x3C($t8)
    ctx->r8 = MEM_W(ctx->r24, 0X3C);
    // 0x8001EDF8: nop

    // 0x8001EDFC: lb          $v1, 0x10($t0)
    ctx->r3 = MEM_B(ctx->r8, 0X10);
    // 0x8001EE00: nop

    // 0x8001EE04: beq         $a0, $v1, L_8001EE14
    if (ctx->r4 == ctx->r3) {
        // 0x8001EE08: nop
    
            goto L_8001EE14;
    }
    // 0x8001EE08: nop

    // 0x8001EE0C: or          $a0, $v1, $zero
    ctx->r4 = ctx->r3 | 0;
    // 0x8001EE10: or          $v0, $zero, $zero
    ctx->r2 = 0 | 0;
L_8001EE14:
    // 0x8001EE14: sb          $v0, 0x11($t0)
    MEM_B(0X11, ctx->r8) = ctx->r2;
    // 0x8001EE18: lw          $t9, 0x0($t5)
    ctx->r25 = MEM_W(ctx->r13, 0X0);
    // 0x8001EE1C: addiu       $v0, $v0, 0x1
    ctx->r2 = ADD32(ctx->r2, 0X1);
    // 0x8001EE20: addu        $t6, $t9, $t2
    ctx->r14 = ADD32(ctx->r25, ctx->r10);
    // 0x8001EE24: lw          $t7, 0xC($t6)
    ctx->r15 = MEM_W(ctx->r14, 0XC);
    // 0x8001EE28: addiu       $t2, $t2, 0x10
    ctx->r10 = ADD32(ctx->r10, 0X10);
    // 0x8001EE2C: bne         $t2, $a1, L_8001ECF0
    if (ctx->r10 != ctx->r5) {
        // 0x8001EE30: sw          $zero, 0x78($t7)
        MEM_W(0X78, ctx->r15) = 0;
            goto L_8001ECF0;
    }
    // 0x8001EE30: sw          $zero, 0x78($t7)
    MEM_W(0X78, ctx->r15) = 0;
L_8001EE34:
    // 0x8001EE34: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8001EE38: lb          $t8, -0x5182($t8)
    ctx->r24 = MEM_B(ctx->r24, -0X5182);
    // 0x8001EE3C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EE40: beq         $t8, $zero, L_8001EE50
    if (ctx->r24 == 0) {
        // 0x8001EE44: sh          $s3, -0x5188($at)
        MEM_H(-0X5188, ctx->r1) = ctx->r19;
            goto L_8001EE50;
    }
    // 0x8001EE44: sh          $s3, -0x5188($at)
    MEM_H(-0X5188, ctx->r1) = ctx->r19;
    // 0x8001EE48: jal         0x8001EE74
    // 0x8001EE4C: nop

    func_8001EE74(rdram, ctx);
        goto after_2;
    // 0x8001EE4C: nop

    after_2:
L_8001EE50:
    // 0x8001EE50: lw          $ra, 0x24($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X24);
    // 0x8001EE54: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8001EE58: lw          $s0, 0x14($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X14);
    // 0x8001EE5C: lw          $s1, 0x18($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X18);
    // 0x8001EE60: lw          $s2, 0x1C($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X1C);
    // 0x8001EE64: lw          $s3, 0x20($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X20);
    // 0x8001EE68: sb          $zero, -0x5182($at)
    MEM_B(-0X5182, ctx->r1) = 0;
    // 0x8001EE6C: jr          $ra
    // 0x8001EE70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
    return;
    // 0x8001EE70: addiu       $sp, $sp, 0x50
    ctx->r29 = ADD32(ctx->r29, 0X50);
;}
RECOMP_FUNC void hud_draw_eggs(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x800A14F0: addiu       $sp, $sp, -0x60
    ctx->r29 = ADD32(ctx->r29, -0X60);
    // 0x800A14F4: sw          $ra, 0x14($sp)
    MEM_W(0X14, ctx->r29) = ctx->r31;
    // 0x800A14F8: sw          $a0, 0x60($sp)
    MEM_W(0X60, ctx->r29) = ctx->r4;
    // 0x800A14FC: sw          $a1, 0x64($sp)
    MEM_W(0X64, ctx->r29) = ctx->r5;
    // 0x800A1500: jal         0x8001BA74
    // 0x800A1504: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    get_racer_objects(rdram, ctx);
        goto after_0;
    // 0x800A1504: addiu       $a0, $sp, 0x50
    ctx->r4 = ADD32(ctx->r29, 0X50);
    after_0:
    // 0x800A1508: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x800A150C: lbu         $t6, 0x6D37($t6)
    ctx->r14 = MEM_BU(ctx->r14, 0X6D37);
    // 0x800A1510: lw          $t3, 0x60($sp)
    ctx->r11 = MEM_W(ctx->r29, 0X60);
    // 0x800A1514: addiu       $t4, $zero, 0x2
    ctx->r12 = ADD32(0, 0X2);
    // 0x800A1518: bne         $t4, $t6, L_800A168C
    if (ctx->r12 != ctx->r14) {
        // 0x800A151C: or          $t2, $v0, $zero
        ctx->r10 = ctx->r2 | 0;
            goto L_800A168C;
    }
    // 0x800A151C: or          $t2, $v0, $zero
    ctx->r10 = ctx->r2 | 0;
    // 0x800A1520: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A1524: or          $a2, $zero, $zero
    ctx->r6 = 0 | 0;
    // 0x800A1528: blez        $t7, L_800A1684
    if (SIGNED(ctx->r15) <= 0) {
        // 0x800A152C: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800A1684;
    }
    // 0x800A152C: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A1530: andi        $v1, $t7, 0x3
    ctx->r3 = ctx->r15 & 0X3;
    // 0x800A1534: beq         $v1, $zero, L_800A1594
    if (ctx->r3 == 0) {
        // 0x800A1538: or          $t1, $v1, $zero
        ctx->r9 = ctx->r3 | 0;
            goto L_800A1594;
    }
    // 0x800A1538: or          $t1, $v1, $zero
    ctx->r9 = ctx->r3 | 0;
    // 0x800A153C: sll         $t8, $zero, 2
    ctx->r24 = S32(0 << 2);
    // 0x800A1540: addu        $a1, $v0, $t8
    ctx->r5 = ADD32(ctx->r2, ctx->r24);
    // 0x800A1544: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A1548:
    // 0x800A1548: lw          $t9, 0x0($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X0);
    // 0x800A154C: addiu       $a3, $a3, 0x1
    ctx->r7 = ADD32(ctx->r7, 0X1);
    // 0x800A1550: lw          $v1, 0x64($t9)
    ctx->r3 = MEM_W(ctx->r25, 0X64);
    // 0x800A1554: nop

    // 0x800A1558: lh          $t5, 0x0($v1)
    ctx->r13 = MEM_H(ctx->r3, 0X0);
    // 0x800A155C: nop

    // 0x800A1560: beq         $t0, $t5, L_800A157C
    if (ctx->r8 == ctx->r13) {
        // 0x800A1564: nop
    
            goto L_800A157C;
    }
    // 0x800A1564: nop

    // 0x800A1568: lb          $t6, 0x1D8($v1)
    ctx->r14 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A156C: nop

    // 0x800A1570: beq         $t6, $zero, L_800A157C
    if (ctx->r14 == 0) {
        // 0x800A1574: nop
    
            goto L_800A157C;
    }
    // 0x800A1574: nop

    // 0x800A1578: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A157C:
    // 0x800A157C: bne         $t1, $a3, L_800A1548
    if (ctx->r9 != ctx->r7) {
        // 0x800A1580: addiu       $a1, $a1, 0x4
        ctx->r5 = ADD32(ctx->r5, 0X4);
            goto L_800A1548;
    }
    // 0x800A1580: addiu       $a1, $a1, 0x4
    ctx->r5 = ADD32(ctx->r5, 0X4);
    // 0x800A1584: lw          $t7, 0x50($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X50);
    // 0x800A1588: nop

    // 0x800A158C: beq         $a3, $t7, L_800A1684
    if (ctx->r7 == ctx->r15) {
        // 0x800A1590: nop
    
            goto L_800A1684;
    }
    // 0x800A1590: nop

L_800A1594:
    // 0x800A1594: lw          $t8, 0x50($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X50);
    // 0x800A1598: sll         $t5, $a3, 2
    ctx->r13 = S32(ctx->r7 << 2);
    // 0x800A159C: sll         $t9, $t8, 2
    ctx->r25 = S32(ctx->r24 << 2);
    // 0x800A15A0: addu        $t1, $t9, $v0
    ctx->r9 = ADD32(ctx->r25, ctx->r2);
    // 0x800A15A4: addu        $a1, $v0, $t5
    ctx->r5 = ADD32(ctx->r2, ctx->r13);
    // 0x800A15A8: addiu       $t0, $zero, -0x1
    ctx->r8 = ADD32(0, -0X1);
L_800A15AC:
    // 0x800A15AC: lw          $t6, 0x0($a1)
    ctx->r14 = MEM_W(ctx->r5, 0X0);
    // 0x800A15B0: nop

    // 0x800A15B4: lw          $v1, 0x64($t6)
    ctx->r3 = MEM_W(ctx->r14, 0X64);
    // 0x800A15B8: nop

    // 0x800A15BC: lh          $t7, 0x0($v1)
    ctx->r15 = MEM_H(ctx->r3, 0X0);
    // 0x800A15C0: nop

    // 0x800A15C4: beq         $t0, $t7, L_800A15E0
    if (ctx->r8 == ctx->r15) {
        // 0x800A15C8: nop
    
            goto L_800A15E0;
    }
    // 0x800A15C8: nop

    // 0x800A15CC: lb          $t8, 0x1D8($v1)
    ctx->r24 = MEM_B(ctx->r3, 0X1D8);
    // 0x800A15D0: nop

    // 0x800A15D4: beq         $t8, $zero, L_800A15E0
    if (ctx->r24 == 0) {
        // 0x800A15D8: nop
    
            goto L_800A15E0;
    }
    // 0x800A15D8: nop

    // 0x800A15DC: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A15E0:
    // 0x800A15E0: lw          $t9, 0x4($a1)
    ctx->r25 = MEM_W(ctx->r5, 0X4);
    // 0x800A15E4: nop

    // 0x800A15E8: lw          $a0, 0x64($t9)
    ctx->r4 = MEM_W(ctx->r25, 0X64);
    // 0x800A15EC: nop

    // 0x800A15F0: lh          $t5, 0x0($a0)
    ctx->r13 = MEM_H(ctx->r4, 0X0);
    // 0x800A15F4: nop

    // 0x800A15F8: beq         $t0, $t5, L_800A1614
    if (ctx->r8 == ctx->r13) {
        // 0x800A15FC: nop
    
            goto L_800A1614;
    }
    // 0x800A15FC: nop

    // 0x800A1600: lb          $t6, 0x1D8($a0)
    ctx->r14 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A1604: nop

    // 0x800A1608: beq         $t6, $zero, L_800A1614
    if (ctx->r14 == 0) {
        // 0x800A160C: nop
    
            goto L_800A1614;
    }
    // 0x800A160C: nop

    // 0x800A1610: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1614:
    // 0x800A1614: lw          $t7, 0x8($a1)
    ctx->r15 = MEM_W(ctx->r5, 0X8);
    // 0x800A1618: nop

    // 0x800A161C: lw          $a0, 0x64($t7)
    ctx->r4 = MEM_W(ctx->r15, 0X64);
    // 0x800A1620: nop

    // 0x800A1624: lh          $t8, 0x0($a0)
    ctx->r24 = MEM_H(ctx->r4, 0X0);
    // 0x800A1628: nop

    // 0x800A162C: beq         $t0, $t8, L_800A1648
    if (ctx->r8 == ctx->r24) {
        // 0x800A1630: nop
    
            goto L_800A1648;
    }
    // 0x800A1630: nop

    // 0x800A1634: lb          $t9, 0x1D8($a0)
    ctx->r25 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A1638: nop

    // 0x800A163C: beq         $t9, $zero, L_800A1648
    if (ctx->r25 == 0) {
        // 0x800A1640: nop
    
            goto L_800A1648;
    }
    // 0x800A1640: nop

    // 0x800A1644: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A1648:
    // 0x800A1648: lw          $t5, 0xC($a1)
    ctx->r13 = MEM_W(ctx->r5, 0XC);
    // 0x800A164C: addiu       $a1, $a1, 0x10
    ctx->r5 = ADD32(ctx->r5, 0X10);
    // 0x800A1650: lw          $a0, 0x64($t5)
    ctx->r4 = MEM_W(ctx->r13, 0X64);
    // 0x800A1654: nop

    // 0x800A1658: lh          $t6, 0x0($a0)
    ctx->r14 = MEM_H(ctx->r4, 0X0);
    // 0x800A165C: nop

    // 0x800A1660: beq         $t0, $t6, L_800A167C
    if (ctx->r8 == ctx->r14) {
        // 0x800A1664: nop
    
            goto L_800A167C;
    }
    // 0x800A1664: nop

    // 0x800A1668: lb          $t7, 0x1D8($a0)
    ctx->r15 = MEM_B(ctx->r4, 0X1D8);
    // 0x800A166C: nop

    // 0x800A1670: beq         $t7, $zero, L_800A167C
    if (ctx->r15 == 0) {
        // 0x800A1674: nop
    
            goto L_800A167C;
    }
    // 0x800A1674: nop

    // 0x800A1678: addiu       $a2, $a2, 0x1
    ctx->r6 = ADD32(ctx->r6, 0X1);
L_800A167C:
    // 0x800A167C: bne         $a1, $t1, L_800A15AC
    if (ctx->r5 != ctx->r9) {
        // 0x800A1680: nop
    
            goto L_800A15AC;
    }
    // 0x800A1680: nop

L_800A1684:
    // 0x800A1684: beq         $a2, $t4, L_800A1998
    if (ctx->r6 == ctx->r12) {
        // 0x800A1688: lw          $ra, 0x14($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X14);
            goto L_800A1998;
    }
    // 0x800A1688: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A168C:
    // 0x800A168C: beq         $t3, $zero, L_800A16A0
    if (ctx->r11 == 0) {
        // 0x800A1690: addiu       $a0, $zero, 0x1
        ctx->r4 = ADD32(0, 0X1);
            goto L_800A16A0;
    }
    // 0x800A1690: addiu       $a0, $zero, 0x1
    ctx->r4 = ADD32(0, 0X1);
    // 0x800A1694: lw          $t1, 0x64($t3)
    ctx->r9 = MEM_W(ctx->r11, 0X64);
    // 0x800A1698: b           L_800A16B4
    // 0x800A169C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
        goto L_800A16B4;
    // 0x800A169C: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
L_800A16A0:
    // 0x800A16A0: lw          $t8, 0x0($v0)
    ctx->r24 = MEM_W(ctx->r2, 0X0);
    // 0x800A16A4: nop

    // 0x800A16A8: lw          $t1, 0x64($t8)
    ctx->r9 = MEM_W(ctx->r24, 0X64);
    // 0x800A16AC: nop

    // 0x800A16B0: lw          $t9, 0x50($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X50);
L_800A16B4:
    // 0x800A16B4: addiu       $at, $zero, 0x4
    ctx->r1 = ADD32(0, 0X4);
    // 0x800A16B8: bne         $t9, $at, L_800A1994
    if (ctx->r25 != ctx->r1) {
        // 0x800A16BC: or          $a3, $zero, $zero
        ctx->r7 = 0 | 0;
            goto L_800A1994;
    }
    // 0x800A16BC: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A16C0: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800A16C4: jal         0x80068508
    // 0x800A16C8: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_1;
    // 0x800A16C8: sw          $t2, 0x5C($sp)
    MEM_W(0X5C, ctx->r29) = ctx->r10;
    after_1:
    // 0x800A16CC: cfc1        $t5, $FpcCsr
    ctx->r13 = get_cop1_cs();
    // 0x800A16D0: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A16D4: addiu       $a2, $a2, 0x6CDC
    ctx->r6 = ADD32(ctx->r6, 0X6CDC);
    // 0x800A16D8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A16DC: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A16E0: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A16E4: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A16E8: lwc1        $f4, 0x64C($v0)
    ctx->f4.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A16EC: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800A16F0: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A16F4: lw          $t0, 0x5C($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X5C);
    // 0x800A16F8: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A16FC: mfc1        $t9, $f6
    ctx->r25 = (int32_t)ctx->f6.u32l;
    // 0x800A1700: or          $a3, $zero, $zero
    ctx->r7 = 0 | 0;
    // 0x800A1704: cfc1        $t7, $FpcCsr
    ctx->r15 = get_cop1_cs();
    // 0x800A1708: sw          $t9, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r25;
    // 0x800A170C: ori         $at, $t7, 0x3
    ctx->r1 = ctx->r15 | 0X3;
    // 0x800A1710: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1714: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A1718: lwc1        $f8, 0x650($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A171C: mtc1        $t9, $f16
    ctx->f16.u32l = ctx->r25;
    // 0x800A1720: cvt.w.s     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.u32l = CVT_W_S(ctx->f8.fl);
    // 0x800A1724: ori         $at, $t5, 0x3
    ctx->r1 = ctx->r13 | 0X3;
    // 0x800A1728: ctc1        $t7, $FpcCsr
    set_cop1_cs(ctx->r15);
    // 0x800A172C: mfc1        $t7, $f10
    ctx->r15 = (int32_t)ctx->f10.u32l;
    // 0x800A1730: cvt.s.w     $f14, $f16
    CHECK_FR(ctx, 14);
    CHECK_FR(ctx, 16);
    ctx->f14.fl = CVT_S_W(ctx->f16.u32l);
    // 0x800A1734: sw          $t7, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r15;
    // 0x800A1738: lwc1        $f18, 0x66C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X66C);
    // 0x800A173C: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1740: sub.s       $f4, $f18, $f14
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 14);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f14.fl); 
    ctx->f4.fl = ctx->f18.fl - ctx->f14.fl;
    // 0x800A1744: mtc1        $t7, $f8
    ctx->f8.u32l = ctx->r15;
    // 0x800A1748: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A174C: nop

    // 0x800A1750: cvt.w.s     $f6, $f4
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    ctx->f6.u32l = CVT_W_S(ctx->f4.fl);
    // 0x800A1754: ctc1        $t5, $FpcCsr
    set_cop1_cs(ctx->r13);
    // 0x800A1758: mfc1        $t6, $f6
    ctx->r14 = (int32_t)ctx->f6.u32l;
    // 0x800A175C: cvt.s.w     $f10, $f8
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    ctx->f10.fl = CVT_S_W(ctx->f8.u32l);
    // 0x800A1760: sw          $t6, 0x40($sp)
    MEM_W(0X40, ctx->r29) = ctx->r14;
    // 0x800A1764: mtc1        $t6, $f6
    ctx->f6.u32l = ctx->r14;
    // 0x800A1768: swc1        $f10, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->f10.u32l;
    // 0x800A176C: lwc1        $f16, 0x670($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A1770: nop

    // 0x800A1774: sub.s       $f18, $f16, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 10);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f10.fl); 
    ctx->f18.fl = ctx->f16.fl - ctx->f10.fl;
    // 0x800A1778: cfc1        $t8, $FpcCsr
    ctx->r24 = get_cop1_cs();
    // 0x800A177C: nop

    // 0x800A1780: ori         $at, $t8, 0x3
    ctx->r1 = ctx->r24 | 0X3;
    // 0x800A1784: xori        $at, $at, 0x2
    ctx->r1 = ctx->r1 ^ 0X2;
    // 0x800A1788: ctc1        $at, $FpcCsr
    set_cop1_cs(ctx->r1);
    // 0x800A178C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A1790: cvt.w.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    ctx->f4.u32l = CVT_W_S(ctx->f18.fl);
    // 0x800A1794: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A1798: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A179C: mfc1        $t9, $f4
    ctx->r25 = (int32_t)ctx->f4.u32l;
    // 0x800A17A0: ctc1        $t8, $FpcCsr
    set_cop1_cs(ctx->r24);
    // 0x800A17A4: lwc1        $f1, -0x78E0($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X78E0);
    // 0x800A17A8: lwc1        $f0, -0x78DC($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78DC);
    // 0x800A17AC: sw          $t9, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r25;
    // 0x800A17B0: cvt.s.w     $f12, $f6
    CHECK_FR(ctx, 12);
    CHECK_FR(ctx, 6);
    ctx->f12.fl = CVT_S_W(ctx->f6.u32l);
L_800A17B4:
    // 0x800A17B4: lw          $t5, 0x0($t0)
    ctx->r13 = MEM_W(ctx->r8, 0X0);
    // 0x800A17B8: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A17BC: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x800A17C0: lw          $v0, 0x64($t5)
    ctx->r2 = MEM_W(ctx->r13, 0X64);
    // 0x800A17C4: slti        $at, $v1, 0x3
    ctx->r1 = SIGNED(ctx->r3) < 0X3 ? 1 : 0;
    // 0x800A17C8: bne         $at, $zero, L_800A17E4
    if (ctx->r1 != 0) {
        // 0x800A17CC: or          $a0, $v0, $zero
        ctx->r4 = ctx->r2 | 0;
            goto L_800A17E4;
    }
    // 0x800A17CC: or          $a0, $v0, $zero
    ctx->r4 = ctx->r2 | 0;
    // 0x800A17D0: lh          $t7, 0x0($v0)
    ctx->r15 = MEM_H(ctx->r2, 0X0);
    // 0x800A17D4: lh          $t8, 0x0($t1)
    ctx->r24 = MEM_H(ctx->r9, 0X0);
    // 0x800A17D8: nop

    // 0x800A17DC: bne         $t7, $t8, L_800A183C
    if (ctx->r15 != ctx->r24) {
        // 0x800A17E0: addiu       $t9, $zero, -0x2
        ctx->r25 = ADD32(0, -0X2);
            goto L_800A183C;
    }
    // 0x800A17E0: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
L_800A17E4:
    // 0x800A17E4: lw          $a1, 0x64($sp)
    ctx->r5 = MEM_W(ctx->r29, 0X64);
    // 0x800A17E8: sw          $a3, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r7;
    // 0x800A17EC: sw          $t0, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r8;
    // 0x800A17F0: sw          $t1, 0x54($sp)
    MEM_W(0X54, ctx->r29) = ctx->r9;
    // 0x800A17F4: swc1        $f12, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->f12.u32l;
    // 0x800A17F8: jal         0x800A19A4
    // 0x800A17FC: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    hud_eggs_portrait(rdram, ctx);
        goto after_2;
    // 0x800A17FC: swc1        $f14, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->f14.u32l;
    after_2:
    // 0x800A1800: lui         $at, 0x800F
    ctx->r1 = S32(0X800F << 16);
    // 0x800A1804: lwc1        $f1, -0x78D8($at)
    ctx->f_odd[(1 - 1) * 2] = MEM_W(ctx->r1, -0X78D8);
    // 0x800A1808: lwc1        $f0, -0x78D4($at)
    ctx->f0.u32l = MEM_W(ctx->r1, -0X78D4);
    // 0x800A180C: lui         $at, 0x425C
    ctx->r1 = S32(0X425C << 16);
    // 0x800A1810: lui         $v1, 0x8012
    ctx->r3 = S32(0X8012 << 16);
    // 0x800A1814: lui         $a2, 0x8012
    ctx->r6 = S32(0X8012 << 16);
    // 0x800A1818: lbu         $v1, 0x6D37($v1)
    ctx->r3 = MEM_BU(ctx->r3, 0X6D37);
    // 0x800A181C: mtc1        $at, $f2
    ctx->f2.u32l = ctx->r1;
    // 0x800A1820: lw          $a3, 0x2C($sp)
    ctx->r7 = MEM_W(ctx->r29, 0X2C);
    // 0x800A1824: lw          $t0, 0x28($sp)
    ctx->r8 = MEM_W(ctx->r29, 0X28);
    // 0x800A1828: lw          $t1, 0x54($sp)
    ctx->r9 = MEM_W(ctx->r29, 0X54);
    // 0x800A182C: lwc1        $f12, 0x18($sp)
    ctx->f12.u32l = MEM_W(ctx->r29, 0X18);
    // 0x800A1830: lwc1        $f14, 0x20($sp)
    ctx->f14.u32l = MEM_W(ctx->r29, 0X20);
    // 0x800A1834: addiu       $a2, $a2, 0x6CDC
    ctx->r6 = ADD32(ctx->r6, 0X6CDC);
    // 0x800A1838: addiu       $t9, $zero, -0x2
    ctx->r25 = ADD32(0, -0X2);
L_800A183C:
    // 0x800A183C: lui         $at, 0x800E
    ctx->r1 = S32(0X800E << 16);
    // 0x800A1840: sw          $t9, 0x2834($at)
    MEM_W(0X2834, ctx->r1) = ctx->r25;
    // 0x800A1844: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1848: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x800A184C: bne         $v1, $at, L_800A1878
    if (ctx->r3 != ctx->r1) {
        // 0x800A1850: addiu       $a3, $a3, 0x4
        ctx->r7 = ADD32(ctx->r7, 0X4);
            goto L_800A1878;
    }
    // 0x800A1850: addiu       $a3, $a3, 0x4
    ctx->r7 = ADD32(ctx->r7, 0X4);
    // 0x800A1854: lui         $at, 0x4288
    ctx->r1 = S32(0X4288 << 16);
    // 0x800A1858: mtc1        $at, $f16
    ctx->f16.u32l = ctx->r1;
    // 0x800A185C: lwc1        $f8, 0x64C($v0)
    ctx->f8.u32l = MEM_W(ctx->r2, 0X64C);
    // 0x800A1860: nop

    // 0x800A1864: add.s       $f10, $f8, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f8.fl); NAN_CHECK(ctx->f16.fl); 
    ctx->f10.fl = ctx->f8.fl + ctx->f16.fl;
    // 0x800A1868: swc1        $f10, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f10.u32l;
    // 0x800A186C: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1870: b           L_800A1920
    // 0x800A1874: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
        goto L_800A1920;
    // 0x800A1874: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
L_800A1878:
    // 0x800A1878: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x800A187C: bne         $v1, $at, L_800A191C
    if (ctx->r3 != ctx->r1) {
        // 0x800A1880: lui         $t6, 0x8000
        ctx->r14 = S32(0X8000 << 16);
            goto L_800A191C;
    }
    // 0x800A1880: lui         $t6, 0x8000
    ctx->r14 = S32(0X8000 << 16);
    // 0x800A1884: swc1        $f14, 0x64C($v0)
    MEM_W(0X64C, ctx->r2) = ctx->f14.u32l;
    // 0x800A1888: lw          $t6, 0x300($t6)
    ctx->r14 = MEM_W(ctx->r14, 0X300);
    // 0x800A188C: nop

    // 0x800A1890: bne         $t6, $zero, L_800A18E4
    if (ctx->r14 != 0) {
        // 0x800A1894: nop
    
            goto L_800A18E4;
    }
    // 0x800A1894: nop

    // 0x800A1898: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A189C: nop

    // 0x800A18A0: lwc1        $f18, 0x650($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A18A4: nop

    // 0x800A18A8: cvt.d.s     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.fl); 
    ctx->f4.d = CVT_D_S(ctx->f18.fl);
    // 0x800A18AC: add.d       $f6, $f4, $f0
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f4.d); NAN_CHECK(ctx->f0.d); 
    ctx->f6.d = ctx->f4.d + ctx->f0.d;
    // 0x800A18B0: cvt.s.d     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    NAN_CHECK(ctx->f6.d); 
    ctx->f8.fl = CVT_S_D(ctx->f6.d);
    // 0x800A18B4: swc1        $f8, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f8.u32l;
    // 0x800A18B8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A18BC: nop

    // 0x800A18C0: lwc1        $f16, 0x670($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A18C4: nop

    // 0x800A18C8: cvt.d.s     $f10, $f16
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    NAN_CHECK(ctx->f16.fl); 
    ctx->f10.d = CVT_D_S(ctx->f16.fl);
    // 0x800A18CC: add.d       $f18, $f10, $f0
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 0);
    NAN_CHECK(ctx->f10.d); NAN_CHECK(ctx->f0.d); 
    ctx->f18.d = ctx->f10.d + ctx->f0.d;
    // 0x800A18D0: cvt.s.d     $f4, $f18
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    NAN_CHECK(ctx->f18.d); 
    ctx->f4.fl = CVT_S_D(ctx->f18.d);
    // 0x800A18D4: swc1        $f4, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f4.u32l;
    // 0x800A18D8: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A18DC: b           L_800A1920
    // 0x800A18E0: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
        goto L_800A1920;
    // 0x800A18E0: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
L_800A18E4:
    // 0x800A18E4: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A18E8: nop

    // 0x800A18EC: lwc1        $f6, 0x650($v0)
    ctx->f6.u32l = MEM_W(ctx->r2, 0X650);
    // 0x800A18F0: nop

    // 0x800A18F4: add.s       $f8, $f6, $f2
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f6.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f8.fl = ctx->f6.fl + ctx->f2.fl;
    // 0x800A18F8: swc1        $f8, 0x650($v0)
    MEM_W(0X650, ctx->r2) = ctx->f8.u32l;
    // 0x800A18FC: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1900: nop

    // 0x800A1904: lwc1        $f16, 0x670($v0)
    ctx->f16.u32l = MEM_W(ctx->r2, 0X670);
    // 0x800A1908: nop

    // 0x800A190C: add.s       $f10, $f16, $f2
    CHECK_FR(ctx, 10);
    CHECK_FR(ctx, 16);
    CHECK_FR(ctx, 2);
    NAN_CHECK(ctx->f16.fl); NAN_CHECK(ctx->f2.fl); 
    ctx->f10.fl = ctx->f16.fl + ctx->f2.fl;
    // 0x800A1910: swc1        $f10, 0x670($v0)
    MEM_W(0X670, ctx->r2) = ctx->f10.u32l;
    // 0x800A1914: lw          $v0, 0x0($a2)
    ctx->r2 = MEM_W(ctx->r6, 0X0);
    // 0x800A1918: nop

L_800A191C:
    // 0x800A191C: lwc1        $f18, 0x64C($v0)
    ctx->f18.u32l = MEM_W(ctx->r2, 0X64C);
L_800A1920:
    // 0x800A1920: addiu       $at, $zero, 0x10
    ctx->r1 = ADD32(0, 0X10);
    // 0x800A1924: add.s       $f4, $f18, $f12
    CHECK_FR(ctx, 4);
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 12);
    NAN_CHECK(ctx->f18.fl); NAN_CHECK(ctx->f12.fl); 
    ctx->f4.fl = ctx->f18.fl + ctx->f12.fl;
    // 0x800A1928: addiu       $t0, $t0, 0x4
    ctx->r8 = ADD32(ctx->r8, 0X4);
    // 0x800A192C: bne         $a3, $at, L_800A17B4
    if (ctx->r7 != ctx->r1) {
        // 0x800A1930: swc1        $f4, 0x66C($v0)
        MEM_W(0X66C, ctx->r2) = ctx->f4.u32l;
            goto L_800A17B4;
    }
    // 0x800A1930: swc1        $f4, 0x66C($v0)
    MEM_W(0X66C, ctx->r2) = ctx->f4.u32l;
    // 0x800A1934: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800A1938: or          $a0, $zero, $zero
    ctx->r4 = 0 | 0;
    // 0x800A193C: swc1        $f14, 0x64C($t5)
    MEM_W(0X64C, ctx->r13) = ctx->f14.u32l;
    // 0x800A1940: lw          $t8, 0x40($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X40);
    // 0x800A1944: lw          $t7, 0x44($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X44);
    // 0x800A1948: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800A194C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A1950: mtc1        $t9, $f6
    ctx->f6.u32l = ctx->r25;
    // 0x800A1954: nop

    // 0x800A1958: cvt.s.w     $f8, $f6
    CHECK_FR(ctx, 8);
    CHECK_FR(ctx, 6);
    ctx->f8.fl = CVT_S_W(ctx->f6.u32l);
    // 0x800A195C: swc1        $f8, 0x66C($t6)
    MEM_W(0X66C, ctx->r14) = ctx->f8.u32l;
    // 0x800A1960: lw          $t5, 0x0($a2)
    ctx->r13 = MEM_W(ctx->r6, 0X0);
    // 0x800A1964: lwc1        $f16, 0x1C($sp)
    ctx->f16.u32l = MEM_W(ctx->r29, 0X1C);
    // 0x800A1968: nop

    // 0x800A196C: swc1        $f16, 0x650($t5)
    MEM_W(0X650, ctx->r13) = ctx->f16.u32l;
    // 0x800A1970: lw          $t8, 0x38($sp)
    ctx->r24 = MEM_W(ctx->r29, 0X38);
    // 0x800A1974: lw          $t7, 0x3C($sp)
    ctx->r15 = MEM_W(ctx->r29, 0X3C);
    // 0x800A1978: lw          $t6, 0x0($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X0);
    // 0x800A197C: addu        $t9, $t7, $t8
    ctx->r25 = ADD32(ctx->r15, ctx->r24);
    // 0x800A1980: mtc1        $t9, $f10
    ctx->f10.u32l = ctx->r25;
    // 0x800A1984: nop

    // 0x800A1988: cvt.s.w     $f18, $f10
    CHECK_FR(ctx, 18);
    CHECK_FR(ctx, 10);
    ctx->f18.fl = CVT_S_W(ctx->f10.u32l);
    // 0x800A198C: jal         0x80068508
    // 0x800A1990: swc1        $f18, 0x670($t6)
    MEM_W(0X670, ctx->r14) = ctx->f18.u32l;
    cam_set_sprite_anim_mode(rdram, ctx);
        goto after_3;
    // 0x800A1990: swc1        $f18, 0x670($t6)
    MEM_W(0X670, ctx->r14) = ctx->f18.u32l;
    after_3:
L_800A1994:
    // 0x800A1994: lw          $ra, 0x14($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X14);
L_800A1998:
    // 0x800A1998: addiu       $sp, $sp, 0x60
    ctx->r29 = ADD32(ctx->r29, 0X60);
    // 0x800A199C: jr          $ra
    // 0x800A19A0: nop

    return;
    // 0x800A19A0: nop

;}
RECOMP_FUNC void shadow_render(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x8002D384: addiu       $sp, $sp, -0x40
    ctx->r29 = ADD32(ctx->r29, -0X40);
    // 0x8002D388: sw          $ra, 0x3C($sp)
    MEM_W(0X3C, ctx->r29) = ctx->r31;
    // 0x8002D38C: sw          $fp, 0x38($sp)
    MEM_W(0X38, ctx->r29) = ctx->r30;
    // 0x8002D390: sw          $s7, 0x34($sp)
    MEM_W(0X34, ctx->r29) = ctx->r23;
    // 0x8002D394: sw          $s6, 0x30($sp)
    MEM_W(0X30, ctx->r29) = ctx->r22;
    // 0x8002D398: sw          $s5, 0x2C($sp)
    MEM_W(0X2C, ctx->r29) = ctx->r21;
    // 0x8002D39C: sw          $s4, 0x28($sp)
    MEM_W(0X28, ctx->r29) = ctx->r20;
    // 0x8002D3A0: sw          $s3, 0x24($sp)
    MEM_W(0X24, ctx->r29) = ctx->r19;
    // 0x8002D3A4: sw          $s2, 0x20($sp)
    MEM_W(0X20, ctx->r29) = ctx->r18;
    // 0x8002D3A8: sw          $s1, 0x1C($sp)
    MEM_W(0X1C, ctx->r29) = ctx->r17;
    // 0x8002D3AC: sw          $s0, 0x18($sp)
    MEM_W(0X18, ctx->r29) = ctx->r16;
    // 0x8002D3B0: lw          $t6, 0x40($a0)
    ctx->r14 = MEM_W(ctx->r4, 0X40);
    // 0x8002D3B4: or          $a2, $a0, $zero
    ctx->r6 = ctx->r4 | 0;
    // 0x8002D3B8: lh          $t7, 0x32($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X32);
    // 0x8002D3BC: or          $a3, $a1, $zero
    ctx->r7 = ctx->r5 | 0;
    // 0x8002D3C0: beq         $t7, $zero, L_8002D644
    if (ctx->r15 == 0) {
        // 0x8002D3C4: lw          $ra, 0x3C($sp)
        ctx->r31 = MEM_W(ctx->r29, 0X3C);
            goto L_8002D644;
    }
    // 0x8002D3C4: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
    // 0x8002D3C8: lh          $t8, 0x8($a1)
    ctx->r24 = MEM_H(ctx->r5, 0X8);
    // 0x8002D3CC: addiu       $at, $zero, -0x1
    ctx->r1 = ADD32(0, -0X1);
    // 0x8002D3D0: beq         $t8, $at, L_8002D640
    if (ctx->r24 == ctx->r1) {
        // 0x8002D3D4: lui         $t9, 0x8012
        ctx->r25 = S32(0X8012 << 16);
            goto L_8002D640;
    }
    // 0x8002D3D4: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002D3D8: lw          $t9, -0x4F3C($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X4F3C);
    // 0x8002D3DC: lui         $a0, 0x8012
    ctx->r4 = S32(0X8012 << 16);
    // 0x8002D3E0: bne         $t9, $zero, L_8002D640
    if (ctx->r25 != 0) {
        // 0x8002D3E4: lui         $t5, 0x8012
        ctx->r13 = S32(0X8012 << 16);
            goto L_8002D640;
    }
    // 0x8002D3E4: lui         $t5, 0x8012
    ctx->r13 = S32(0X8012 << 16);
    extern void dkr_shadow_interpolation_begin(uint8_t*, recomp_context*); dkr_shadow_interpolation_begin(rdram, ctx);
    // 0x8002D3E8: lw          $t5, -0x4F38($t5)
    ctx->r13 = MEM_W(ctx->r13, -0X4F38);
    // 0x8002D3EC: addiu       $a0, $a0, -0x4F34
    ctx->r4 = ADD32(ctx->r4, -0X4F34);
    // 0x8002D3F0: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8002D3F4: lw          $t6, 0x40($a2)
    ctx->r14 = MEM_W(ctx->r6, 0X40);
    // 0x8002D3F8: addiu       $at, $zero, 0x1
    ctx->r1 = ADD32(0, 0X1);
    // 0x8002D3FC: lh          $t7, 0x32($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X32);
    // 0x8002D400: lui         $s4, 0x8012
    ctx->r20 = S32(0X8012 << 16);
    // 0x8002D404: bne         $t7, $at, L_8002D414
    if (ctx->r15 != ctx->r1) {
        // 0x8002D408: addiu       $s4, $s4, -0x2CA0
        ctx->r20 = ADD32(ctx->r20, -0X2CA0);
            goto L_8002D414;
    }
    // 0x8002D408: addiu       $s4, $s4, -0x2CA0
    ctx->r20 = ADD32(ctx->r20, -0X2CA0);
    // 0x8002D40C: addiu       $t9, $t5, 0x2
    ctx->r25 = ADD32(ctx->r13, 0X2);
    // 0x8002D410: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
L_8002D414:
    // 0x8002D414: lw          $v0, 0x0($a0)
    ctx->r2 = MEM_W(ctx->r4, 0X0);
    // 0x8002D418: lui         $t6, 0x8012
    ctx->r14 = S32(0X8012 << 16);
    // 0x8002D41C: sll         $t5, $v0, 2
    ctx->r13 = S32(ctx->r2 << 2);
    // 0x8002D420: addu        $t6, $t6, $t5
    ctx->r14 = ADD32(ctx->r14, ctx->r13);
    // 0x8002D424: lw          $t6, -0x2CB0($t6)
    ctx->r14 = MEM_W(ctx->r14, -0X2CB0);
    // 0x8002D428: lh          $s3, 0x8($a3)
    ctx->r19 = MEM_H(ctx->r7, 0X8);
    // 0x8002D42C: lui         $t7, 0x8012
    ctx->r15 = S32(0X8012 << 16);
    // 0x8002D430: addu        $t7, $t7, $t5
    ctx->r15 = ADD32(ctx->r15, ctx->r13);
    // 0x8002D434: sw          $t6, 0x0($s4)
    MEM_W(0X0, ctx->r20) = ctx->r14;
    // 0x8002D438: lw          $t7, -0x2CE0($t7)
    ctx->r15 = MEM_W(ctx->r15, -0X2CE0);
    // 0x8002D43C: lui         $at, 0x8012
    ctx->r1 = S32(0X8012 << 16);
    // 0x8002D440: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x8002D444: addu        $t8, $t8, $t5
    ctx->r24 = ADD32(ctx->r24, ctx->r13);
    // 0x8002D448: sw          $t7, -0x2CD0($at)
    MEM_W(-0X2CD0, ctx->r1) = ctx->r15;
    // 0x8002D44C: lw          $t8, -0x2CC8($t8)
    ctx->r24 = MEM_W(ctx->r24, -0X2CC8);
    // 0x8002D450: lw          $t9, 0x0($s4)
    ctx->r25 = MEM_W(ctx->r20, 0X0);
    // 0x8002D454: lui         $s7, 0x8012
    ctx->r23 = S32(0X8012 << 16);
    // 0x8002D458: addiu       $s7, $s7, -0x2CB8
    ctx->r23 = ADD32(ctx->r23, -0X2CB8);
    // 0x8002D45C: sll         $t5, $s3, 3
    ctx->r13 = S32(ctx->r19 << 3);
    // 0x8002D460: sw          $t8, 0x0($s7)
    MEM_W(0X0, ctx->r23) = ctx->r24;
    // 0x8002D464: addu        $t6, $t9, $t5
    ctx->r14 = ADD32(ctx->r25, ctx->r13);
    // 0x8002D468: lh          $t7, 0x6($t6)
    ctx->r15 = MEM_H(ctx->r14, 0X6);
    // 0x8002D46C: lw          $t9, 0x0($s7)
    ctx->r25 = MEM_W(ctx->r23, 0X0);
    // 0x8002D470: sll         $t8, $t7, 2
    ctx->r24 = S32(ctx->r15 << 2);
    // 0x8002D474: addu        $t8, $t8, $t7
    ctx->r24 = ADD32(ctx->r24, ctx->r15);
    // 0x8002D478: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8002D47C: addu        $t5, $t9, $t8
    ctx->r13 = ADD32(ctx->r25, ctx->r24);
    // 0x8002D480: lbu         $v1, 0x9($t5)
    ctx->r3 = MEM_BU(ctx->r13, 0X9);
    // 0x8002D484: addiu       $fp, $zero, 0xA
    ctx->r30 = ADD32(0, 0XA);
    // 0x8002D488: beq         $v1, $zero, L_8002D4A0
    if (ctx->r3 == 0) {
        // 0x8002D48C: lui         $s6, 0x500
        ctx->r22 = S32(0X500 << 16);
            goto L_8002D4A0;
    }
    // 0x8002D48C: lui         $s6, 0x500
    ctx->r22 = S32(0X500 << 16);
    // 0x8002D490: lbu         $a1, 0x39($a2)
    ctx->r5 = MEM_BU(ctx->r6, 0X39);
    // 0x8002D494: addiu       $v0, $zero, 0xFF
    ctx->r2 = ADD32(0, 0XFF);
    // 0x8002D498: bne         $a1, $zero, L_8002D4AC
    if (ctx->r5 != 0) {
        // 0x8002D49C: nop
    
            goto L_8002D4AC;
    }
    // 0x8002D49C: nop

L_8002D4A0:
    // 0x8002D4A0: lh          $s3, 0xA($a3)
    ctx->r19 = MEM_H(ctx->r7, 0XA);
    // 0x8002D4A4: b           L_8002D4FC
    // 0x8002D4A8: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
        goto L_8002D4FC;
    // 0x8002D4A8: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
L_8002D4AC:
    // 0x8002D4AC: bne         $v1, $v0, L_8002D4BC
    if (ctx->r3 != ctx->r2) {
        // 0x8002D4B0: nop
    
            goto L_8002D4BC;
    }
    // 0x8002D4B0: nop

    // 0x8002D4B4: beq         $v0, $a1, L_8002D4F8
    if (ctx->r2 == ctx->r5) {
        // 0x8002D4B8: nop
    
            goto L_8002D4F8;
    }
    // 0x8002D4B8: nop

L_8002D4BC:
    // 0x8002D4BC: multu       $a1, $v1
    result = U64(U32(ctx->r5)) * U64(U32(ctx->r3)); lo = S32(result >> 0); hi = S32(result >> 32);
    // 0x8002D4C0: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002D4C4: addiu       $s1, $s1, -0x4F60
    ctx->r17 = ADD32(ctx->r17, -0X4F60);
    // 0x8002D4C8: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D4CC: addiu       $at, $zero, -0x100
    ctx->r1 = ADD32(0, -0X100);
    // 0x8002D4D0: addiu       $t7, $a0, 0x8
    ctx->r15 = ADD32(ctx->r4, 0X8);
    // 0x8002D4D4: sw          $t7, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r15;
    // 0x8002D4D8: lui         $t9, 0xFA00
    ctx->r25 = S32(0XFA00 << 16);
    // 0x8002D4DC: addiu       $fp, $zero, 0xE
    ctx->r30 = ADD32(0, 0XE);
    // 0x8002D4E0: sw          $t9, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r25;
    // 0x8002D4E4: mflo        $v1
    ctx->r3 = lo;
    // 0x8002D4E8: sra         $t6, $v1, 8
    ctx->r14 = S32(SIGNED(ctx->r3) >> 8);
    // 0x8002D4EC: andi        $t8, $t6, 0xFF
    ctx->r24 = ctx->r14 & 0XFF;
    // 0x8002D4F0: or          $t5, $t8, $at
    ctx->r13 = ctx->r24 | ctx->r1;
    // 0x8002D4F4: sw          $t5, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r13;
L_8002D4F8:
    // 0x8002D4F8: lh          $t6, 0xA($a3)
    ctx->r14 = MEM_H(ctx->r7, 0XA);
L_8002D4FC:
    // 0x8002D4FC: lui         $s1, 0x8012
    ctx->r17 = S32(0X8012 << 16);
    // 0x8002D500: slt         $at, $s3, $t6
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r14) ? 1 : 0;
    // 0x8002D504: beq         $at, $zero, L_8002D61C
    if (ctx->r1 == 0) {
        // 0x8002D508: addiu       $s1, $s1, -0x4F60
        ctx->r17 = ADD32(ctx->r17, -0X4F60);
            goto L_8002D61C;
    }
    // 0x8002D508: addiu       $s1, $s1, -0x4F60
    ctx->r17 = ADD32(ctx->r17, -0X4F60);
    // 0x8002D50C: sll         $s0, $s3, 3
    ctx->r16 = S32(ctx->r19 << 3);
    // 0x8002D510: sw          $a3, 0x44($sp)
    MEM_W(0X44, ctx->r29) = ctx->r7;
    // 0x8002D514: lui         $s5, 0x400
    ctx->r21 = S32(0X400 << 16);
    // 0x8002D518: lui         $s2, 0x8000
    ctx->r18 = S32(0X8000 << 16);
L_8002D51C:
    // 0x8002D51C: lw          $t7, 0x0($s4)
    ctx->r15 = MEM_W(ctx->r20, 0X0);
    // 0x8002D520: or          $a0, $s1, $zero
    ctx->r4 = ctx->r17 | 0;
    // 0x8002D524: addu        $t9, $t7, $s0
    ctx->r25 = ADD32(ctx->r15, ctx->r16);
    // 0x8002D528: lw          $a1, 0x0($t9)
    ctx->r5 = MEM_W(ctx->r25, 0X0);
    // 0x8002D52C: jal         0x8007B4C8
    // 0x8002D530: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    material_set_no_tex_offset(rdram, ctx);
        goto after_0;
    // 0x8002D530: or          $a2, $fp, $zero
    ctx->r6 = ctx->r30 | 0;
    after_0:
    // 0x8002D534: lw          $t8, 0x0($s4)
    ctx->r24 = MEM_W(ctx->r20, 0X0);
    // 0x8002D538: lui         $t9, 0x8012
    ctx->r25 = S32(0X8012 << 16);
    // 0x8002D53C: addu        $v0, $t8, $s0
    ctx->r2 = ADD32(ctx->r24, ctx->r16);
    // 0x8002D540: lh          $a1, 0x4($v0)
    ctx->r5 = MEM_H(ctx->r2, 0X4);
    // 0x8002D544: lh          $a2, 0x6($v0)
    ctx->r6 = MEM_H(ctx->r2, 0X6);
    // 0x8002D548: lh          $t5, 0xC($v0)
    ctx->r13 = MEM_H(ctx->r2, 0XC);
    // 0x8002D54C: sll         $t8, $a2, 2
    ctx->r24 = S32(ctx->r6 << 2);
    // 0x8002D550: subu        $a3, $t5, $a1
    ctx->r7 = SUB32(ctx->r13, ctx->r5);
    // 0x8002D554: lh          $t6, 0xE($v0)
    ctx->r14 = MEM_H(ctx->r2, 0XE);
    // 0x8002D558: lw          $t9, -0x2CD0($t9)
    ctx->r25 = MEM_W(ctx->r25, -0X2CD0);
    // 0x8002D55C: lw          $t5, 0x0($s7)
    ctx->r13 = MEM_W(ctx->r23, 0X0);
    // 0x8002D560: addu        $t8, $t8, $a2
    ctx->r24 = ADD32(ctx->r24, ctx->r6);
    // 0x8002D564: sll         $t8, $t8, 1
    ctx->r24 = S32(ctx->r24 << 1);
    // 0x8002D568: sll         $t7, $a1, 4
    ctx->r15 = S32(ctx->r5 << 4);
    // 0x8002D56C: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D570: subu        $v1, $t6, $a2
    ctx->r3 = SUB32(ctx->r14, ctx->r6);
    // 0x8002D574: addu        $t3, $t7, $t9
    ctx->r11 = ADD32(ctx->r15, ctx->r25);
    // 0x8002D578: addu        $t4, $t8, $t5
    ctx->r12 = ADD32(ctx->r24, ctx->r13);
    // 0x8002D57C: addu        $t1, $t4, $s2
    ctx->r9 = ADD32(ctx->r12, ctx->r18);
    // 0x8002D580: addiu       $t7, $v1, -0x1
    ctx->r15 = ADD32(ctx->r3, -0X1);
    // 0x8002D584: sll         $t9, $t7, 3
    ctx->r25 = S32(ctx->r15 << 3);
    // 0x8002D588: andi        $t8, $t1, 0x6
    ctx->r24 = ctx->r9 & 0X6;
    // 0x8002D58C: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8002D590: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8002D594: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8002D598: andi        $t6, $t5, 0xFF
    ctx->r14 = ctx->r13 & 0XFF;
    // 0x8002D59C: sll         $t7, $t6, 16
    ctx->r15 = S32(ctx->r14 << 16);
    // 0x8002D5A0: sll         $t8, $v1, 3
    ctx->r24 = S32(ctx->r3 << 3);
    // 0x8002D5A4: addu        $t5, $t8, $v1
    ctx->r13 = ADD32(ctx->r24, ctx->r3);
    // 0x8002D5A8: sll         $t6, $t5, 1
    ctx->r14 = S32(ctx->r13 << 1);
    // 0x8002D5AC: or          $t9, $t7, $s5
    ctx->r25 = ctx->r15 | ctx->r21;
    // 0x8002D5B0: addiu       $t7, $t6, 0x8
    ctx->r15 = ADD32(ctx->r14, 0X8);
    // 0x8002D5B4: andi        $t8, $t7, 0xFFFF
    ctx->r24 = ctx->r15 & 0XFFFF;
    // 0x8002D5B8: or          $t5, $t9, $t8
    ctx->r13 = ctx->r25 | ctx->r24;
    // 0x8002D5BC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8002D5C0: sw          $t1, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r9;
    // 0x8002D5C4: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D5C8: addiu       $t7, $a3, -0x1
    ctx->r15 = ADD32(ctx->r7, -0X1);
    // 0x8002D5CC: sll         $t9, $t7, 4
    ctx->r25 = S32(ctx->r15 << 4);
    // 0x8002D5D0: ori         $t8, $t9, 0x1
    ctx->r24 = ctx->r25 | 0X1;
    // 0x8002D5D4: addiu       $t6, $a0, 0x8
    ctx->r14 = ADD32(ctx->r4, 0X8);
    // 0x8002D5D8: sw          $t6, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r14;
    // 0x8002D5DC: andi        $t5, $t8, 0xFF
    ctx->r13 = ctx->r24 & 0XFF;
    // 0x8002D5E0: sll         $t6, $t5, 16
    ctx->r14 = S32(ctx->r13 << 16);
    // 0x8002D5E4: or          $t7, $t6, $s6
    ctx->r15 = ctx->r14 | ctx->r22;
    // 0x8002D5E8: sll         $t9, $a3, 4
    ctx->r25 = S32(ctx->r7 << 4);
    // 0x8002D5EC: andi        $t8, $t9, 0xFFFF
    ctx->r24 = ctx->r25 & 0XFFFF;
    // 0x8002D5F0: or          $t5, $t7, $t8
    ctx->r13 = ctx->r15 | ctx->r24;
    // 0x8002D5F4: addu        $t6, $t3, $s2
    ctx->r14 = ADD32(ctx->r11, ctx->r18);
    // 0x8002D5F8: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8002D5FC: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
    // 0x8002D600: lw          $t9, 0x44($sp)
    ctx->r25 = MEM_W(ctx->r29, 0X44);
    // 0x8002D604: addiu       $s3, $s3, 0x1
    ctx->r19 = ADD32(ctx->r19, 0X1);
    // 0x8002D608: lh          $t7, 0xA($t9)
    ctx->r15 = MEM_H(ctx->r25, 0XA);
    // 0x8002D60C: addiu       $s0, $s0, 0x8
    ctx->r16 = ADD32(ctx->r16, 0X8);
    // 0x8002D610: slt         $at, $s3, $t7
    ctx->r1 = SIGNED(ctx->r19) < SIGNED(ctx->r15) ? 1 : 0;
    // 0x8002D614: bne         $at, $zero, L_8002D51C
    if (ctx->r1 != 0) {
        // 0x8002D618: nop
    
            goto L_8002D51C;
    }
    // 0x8002D618: nop

L_8002D61C:
    // 0x8002D61C: addiu       $at, $zero, 0x2
    ctx->r1 = ADD32(0, 0X2);
    // 0x8002D620: beq         $fp, $at, L_8002D640
    if (ctx->r30 == ctx->r1) {
        // 0x8002D624: lui         $t5, 0xFA00
        ctx->r13 = S32(0XFA00 << 16);
            goto L_8002D640;
    }
    // 0x8002D624: lui         $t5, 0xFA00
    ctx->r13 = S32(0XFA00 << 16);
    // 0x8002D628: lw          $a0, 0x0($s1)
    ctx->r4 = MEM_W(ctx->r17, 0X0);
    // 0x8002D62C: addiu       $t6, $zero, -0x1
    ctx->r14 = ADD32(0, -0X1);
    // 0x8002D630: addiu       $t8, $a0, 0x8
    ctx->r24 = ADD32(ctx->r4, 0X8);
    // 0x8002D634: sw          $t8, 0x0($s1)
    MEM_W(0X0, ctx->r17) = ctx->r24;
    // 0x8002D638: sw          $t6, 0x4($a0)
    MEM_W(0X4, ctx->r4) = ctx->r14;
    // 0x8002D63C: sw          $t5, 0x0($a0)
    MEM_W(0X0, ctx->r4) = ctx->r13;
L_8002D640:
    extern void dkr_shadow_interpolation_end(uint8_t*, recomp_context*); dkr_shadow_interpolation_end(rdram, ctx);
    // 0x8002D640: lw          $ra, 0x3C($sp)
    ctx->r31 = MEM_W(ctx->r29, 0X3C);
L_8002D644:
    // 0x8002D644: lw          $s0, 0x18($sp)
    ctx->r16 = MEM_W(ctx->r29, 0X18);
    // 0x8002D648: lw          $s1, 0x1C($sp)
    ctx->r17 = MEM_W(ctx->r29, 0X1C);
    // 0x8002D64C: lw          $s2, 0x20($sp)
    ctx->r18 = MEM_W(ctx->r29, 0X20);
    // 0x8002D650: lw          $s3, 0x24($sp)
    ctx->r19 = MEM_W(ctx->r29, 0X24);
    // 0x8002D654: lw          $s4, 0x28($sp)
    ctx->r20 = MEM_W(ctx->r29, 0X28);
    // 0x8002D658: lw          $s5, 0x2C($sp)
    ctx->r21 = MEM_W(ctx->r29, 0X2C);
    // 0x8002D65C: lw          $s6, 0x30($sp)
    ctx->r22 = MEM_W(ctx->r29, 0X30);
    // 0x8002D660: lw          $s7, 0x34($sp)
    ctx->r23 = MEM_W(ctx->r29, 0X34);
    // 0x8002D664: lw          $fp, 0x38($sp)
    ctx->r30 = MEM_W(ctx->r29, 0X38);
    // 0x8002D668: jr          $ra
    // 0x8002D66C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
    return;
    // 0x8002D66C: addiu       $sp, $sp, 0x40
    ctx->r29 = ADD32(ctx->r29, 0X40);
;}
RECOMP_FUNC void audspat_reverb_add_vertex(uint8_t* rdram, recomp_context* ctx) {
    uint64_t hi = 0, lo = 0, result = 0;
    int c1cs = 0;
    // 0x80009968: lbu         $a0, 0x13($sp)
    ctx->r4 = MEM_BU(ctx->r29, 0X13);
    // 0x8000996C: sw          $a2, 0x8($sp)
    MEM_W(0X8, ctx->r29) = ctx->r6;
    // 0x80009970: slti        $at, $a0, 0x7
    ctx->r1 = SIGNED(ctx->r4) < 0X7 ? 1 : 0;
    // 0x80009974: sw          $a3, 0xC($sp)
    MEM_W(0XC, ctx->r29) = ctx->r7;
    // 0x80009978: beq         $at, $zero, L_800099E4
    if (ctx->r1 == 0) {
        // 0x8000997C: andi        $t6, $a3, 0xFF
        ctx->r14 = ctx->r7 & 0XFF;
            goto L_800099E4;
    }
    // 0x8000997C: andi        $t6, $a3, 0xFF
    ctx->r14 = ctx->r7 & 0XFF;
    // 0x80009980: lbu         $v0, 0x17($sp)
    ctx->r2 = MEM_BU(ctx->r29, 0X17);
    // 0x80009984: sll         $t7, $a0, 2
    ctx->r15 = S32(ctx->r4 << 2);
    // 0x80009988: slti        $at, $v0, 0xF
    ctx->r1 = SIGNED(ctx->r2) < 0XF ? 1 : 0;
    // 0x8000998C: beq         $at, $zero, L_800099E4
    if (ctx->r1 == 0) {
        // 0x80009990: subu        $t7, $t7, $a0
        ctx->r15 = SUB32(ctx->r15, ctx->r4);
            goto L_800099E4;
    }
    // 0x80009990: subu        $t7, $t7, $a0
    ctx->r15 = SUB32(ctx->r15, ctx->r4);
    // 0x80009994: lui         $t8, 0x8012
    ctx->r24 = S32(0X8012 << 16);
    // 0x80009998: sll         $t9, $v0, 2
    ctx->r25 = S32(ctx->r2 << 2);
    // 0x8000999C: subu        $t9, $t9, $v0
    ctx->r25 = SUB32(ctx->r25, ctx->r2);
    // 0x800099A0: addiu       $t8, $t8, -0x5928
    ctx->r24 = ADD32(ctx->r24, -0X5928);
    // 0x800099A4: sll         $t7, $t7, 6
    ctx->r15 = S32(ctx->r15 << 6);
    // 0x800099A8: addu        $v1, $t7, $t8
    ctx->r3 = ADD32(ctx->r15, ctx->r24);
    // 0x800099AC: sll         $t0, $t9, 2
    ctx->r8 = S32(ctx->r25 << 2);
    // 0x800099B0: lwc1        $f4, 0x8($sp)
    ctx->f4.u32l = MEM_W(ctx->r29, 0X8);
    // 0x800099B4: addu        $a1, $v1, $t0
    ctx->r5 = ADD32(ctx->r3, ctx->r8);
    // 0x800099B8: swc1        $f12, 0x4($a1)
    MEM_W(0X4, ctx->r5) = ctx->f12.u32l;
    // 0x800099BC: swc1        $f14, 0x8($a1)
    MEM_W(0X8, ctx->r5) = ctx->f14.u32l;
    // 0x800099C0: bne         $v0, $zero, L_800099CC
    if (ctx->r2 != 0) {
        // 0x800099C4: swc1        $f4, 0xC($a1)
        MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
            goto L_800099CC;
    }
    // 0x800099C4: swc1        $f4, 0xC($a1)
    MEM_W(0XC, ctx->r5) = ctx->f4.u32l;
    // 0x800099C8: sb          $t6, 0x0($v1)
    MEM_B(0X0, ctx->r3) = ctx->r14;
L_800099CC:
    // 0x800099CC: lb          $t1, 0xB8($v1)
    ctx->r9 = MEM_B(ctx->r3, 0XB8);
    // 0x800099D0: nop

    // 0x800099D4: slt         $at, $t1, $v0
    ctx->r1 = SIGNED(ctx->r9) < SIGNED(ctx->r2) ? 1 : 0;
    // 0x800099D8: beq         $at, $zero, L_800099E4
    if (ctx->r1 == 0) {
        // 0x800099DC: nop
    
            goto L_800099E4;
    }
    // 0x800099DC: nop

    // 0x800099E0: sb          $v0, 0xB8($v1)
    MEM_B(0XB8, ctx->r3) = ctx->r2;
L_800099E4:
    // 0x800099E4: jr          $ra
    // 0x800099E8: nop

    return;
    // 0x800099E8: nop

;}
